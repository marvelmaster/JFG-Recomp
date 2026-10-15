// JFG: the code in the ROM is not compressed, so there is no decompression step (file name kept from the
// Banjo template). This file holds the JFG specific runtime glue instead: overlay load/unload tracking.
//
// The game's own linker (src/runLink.c in the decomp) loads an overlay with mmAlloc + romCopy and patches it.
// The recompiled code needs to know where each overlay section currently lives (RELOC_HI16/LO16, LOOKUP_FUNC).
// Hooks (recomp/jfg.us.toml, [[patches.hook]]):
//   runlinkDownloadCode, before `jal osInvalICache`: s8 = OverlayHeader*  -> jfg_overlay_loaded
//   mmFree(ptr), function entry                                           -> jfg_mm_free
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <mutex>
#include <unordered_map>

#include "recomp.h"
#include "librecomp/overlays.hpp"
#include "librecomp/game.hpp"

extern "C" void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern "C" void unload_overlays(int32_t ram_addr, uint32_t size);

extern "C" void jfg_front_mode(uint8_t*, recomp_context* ctx) {
    static const bool trace = std::getenv("JFG_TRACE_INPUT") != nullptr;
    if (trace) fprintf(stderr, "[JFG] Front mode requested: %u.\n", unsigned(ctx->r4));
}

extern "C" void jfg_rsp_done(uint8_t* rdram, recomp_context* ctx) {
    static const bool trace = std::getenv("JFG_TRACE_INPUT") != nullptr;
    static unsigned count = 0;
    const uint32_t task = uint32_t(MEM_W(0x2F4, ctx->r4));
    if ((trace && count++ < 8) || task == 0) {
        fprintf(stderr, "[JFG] Scheduler SP done: sc=%08X task=%08X.\n",
            unsigned(ctx->r4), task);
    }
}

// Diagnostic log that does not depend on the process stderr (which was observed to stop delivering
// output to a redirected file after some seconds). Writes to runlogs-independent "jfg_trace.log" in
// the working directory and also to stderr.
#include <cstdarg>
extern "C" uint32_t jfgAppCalls = 0;
extern "C" void jfg_logf(const char* fmt, ...);
// JFG_TRACE_LATENCY: steady-clock timestamps (us) of input sampling (I), display list submission (D) and swap
// chain presents (P), for estimating input-to-display latency offline (tools\latency.py).
extern "C" void jfg_latency_event(char kind) {
    static const bool enabled = std::getenv("JFG_TRACE_LATENCY") != nullptr;
    static std::atomic<uint32_t> count{0};
    if (!enabled || count++ > 6000) return;
    jfg_logf("LAT %c %lld\n", kind, (long long)std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count());
}

extern "C" void jfg_logf(const char* fmt, ...) {
    static std::mutex log_mutex;
    static FILE* f = nullptr;
    std::lock_guard lock{ log_mutex };
    if (f == nullptr) f = fopen("jfg_trace.log", "w");
    va_list args;
    va_start(args, fmt);
    if (f) { vfprintf(f, fmt, args); fflush(f); }
    va_end(args);
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

// JFG_WATCHDOG=1 diagnostic (Windows): if the scheduler retrace hook stops for 3 s, sample the
// instruction pointer of every thread several times and print image-relative offsets
// (resolve them with build-cmake/JFGRecompiled.map). Helps to find guest busy-wait loops.
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <tlhelp32.h>
#include <atomic>
#include <thread>
#include <chrono>
static std::atomic<uint32_t> jfg_retrace_ticks{0};
static void jfg_watchdog_dump() {
    const uintptr_t base = (uintptr_t)GetModuleHandleW(nullptr);
    const DWORD self = GetCurrentThreadId();
    for (int sample = 0; sample < 4; sample++) {
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
        THREADENTRY32 te{}; te.dwSize = sizeof(te);
        for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
            if (te.th32OwnerProcessID != GetCurrentProcessId() || te.th32ThreadID == self) continue;
            HANDLE th = OpenThread(THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT | THREAD_QUERY_INFORMATION, FALSE, te.th32ThreadID);
            if (!th) continue;
            uint64_t rip = 0, rets[12] = {}; int found = 0; bool got = false;
            if (SuspendThread(th) != (DWORD)-1) {
                CONTEXT c{}; c.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
                if (GetThreadContext(th, &c)) {
                    // No allocation/locking while the thread is suspended (it may hold the CRT locks).
                    got = true;
                    rip = c.Rip - base;
                    const uintptr_t* sp = (const uintptr_t*)c.Rsp;
                    for (int i = 0; i < 512 && found < 12; i++) {
                        uintptr_t v = sp[i];
                        if (v > base + 0x1000 && v < base + 0x8000000) rets[found++] = v - base;
                    }
                }
                ResumeThread(th);
            }
            if (got) {
                char line[512]; int n = snprintf(line, sizeof(line), "JFG_WD s%d tid=%lu rip=+%llX", sample, te.th32ThreadID, (unsigned long long)rip);
                for (int i = 0; i < found && n < 480; i++) n += snprintf(line + n, sizeof(line) - n, " +%llX", (unsigned long long)rets[i]);
                jfg_logf("%s\n", line);
            }
            CloseHandle(th);
        }
        CloseHandle(snap);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
static void jfg_watchdog_start() {
    static bool started = false;
    if (started || std::getenv("JFG_WATCHDOG") == nullptr) return;
    started = true;
    std::thread([] {
        uint32_t last = 0; int stalled = 0, dumps = 0;
        while (dumps < 2) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            const uint32_t now = jfg_retrace_ticks.load();
            stalled = (now == last) ? stalled + 1 : 0;
            last = now;
            if (stalled == 3) { jfg_logf("JFG_WD stall at retrace tick %u\n", now); jfg_watchdog_dump(); dumps++; stalled = -10; }
        }
    }).detach();
}
#else
static void jfg_watchdog_start() {}
#endif

extern "C" void jfg_native_scheduler_tick(uint8_t* rdram, recomp_context*) {
#ifdef _WIN32
    jfg_retrace_ticks++;
#endif
    jfg_watchdog_start();
    {
        static const bool heartbeat = std::getenv("JFG_HEARTBEAT") != nullptr;
        static uint32_t hb = 0;
        if (heartbeat && (++hb % 60) == 0) jfg_logf("JFG_HB retrace=%u dl=%u t=%ld\n", hb, jfgAppCalls, long(clock()));
    }
    // The original watchdog halts N64 hardware and discards its task after 11
    // retraces. HLE jobs cannot be cancelled by that register write. Keep their
    // scheduler ownership until SP/DP completion; native errors remain fatal in
    // the runtime. This changes only the recompiled game's hardware watchdog.
    constexpr gpr counters = UINT64_C(0xFFFFFFFF800A38C0);
    MEM_W(0, counters) = 0;
    MEM_W(4, counters) = 0;

    // Optional JFG_TRACE_PATCH diagnostic: list main code/data words that the game's own
    // dynamic linker (runLink) patched in RDRAM; the static recompiled code does not see them.
    static const char* trace_patch = std::getenv("JFG_TRACE_PATCH");
    static uint32_t patch_ticks = 0;
    if (trace_patch && ++patch_ticks == (uint32_t)std::atoi(trace_patch)) {
        auto rom = recomp::get_rom();
        int printed = 0;
        for (uint32_t vram = 0x80000450; vram < 0x800B0B50 && printed < 800; vram += 4) {
            const uint32_t off = vram - 0x80000400 + 0x1000;
            if (off + 4 > rom.size()) break;
            const uint32_t rw = (uint32_t(rom[off]) << 24) | (uint32_t(rom[off + 1]) << 16) | (uint32_t(rom[off + 2]) << 8) | rom[off + 3];
            const uint32_t mw = (uint32_t)MEM_W(0, (gpr)(int32_t)vram);
            if (rw != mw) { fprintf(stderr, "JFG_PATCH %08X rom=%08X ram=%08X\n", vram, rw, mw); printed++; }
        }
        fprintf(stderr, "JFG_PATCH done (%d)\n", printed);
    }

    // Optional JFG_TRACE_OBJ diagnostic: object list and camera state every 60 retraces.
    static const bool trace_obj = std::getenv("JFG_TRACE_OBJ") != nullptr;
    static uint32_t ticks = 0;
    if (trace_obj && (++ticks % 60) == 0) {
        auto rd_f = [&](gpr addr) { uint32_t w = (uint32_t)MEM_W(0, addr); float f; memcpy(&f, &w, 4); return f; };
        const gpr list = (gpr)(int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800F2CA4));
        const int32_t count = (int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800F2CA8));
        const gpr cam = UINT64_C(0xFFFFFFFF800FA4D0);
        jfg_logf("JFG_STATE tick=%u Time=%d pauseB=%d D_800A3328=%d gameMode=%d\n", ticks,
            (int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800FD748)), (int)(int8_t)MEM_B(0, UINT64_C(0xFFFFFFFF800FD7BD)),
            (int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800A3328)), (int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800FD7C4)));
        {
            const gpr acam = (gpr)(int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF801045B8));
            jfg_logf("JFG_ANIMSEQ seq=%08X playing=%d cmd=%08X time=%d lockons=%d animcam0=%08X",
                (uint32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800A74BC)), (int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800A74D4)),
                (uint32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800A74CC)), (int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800A74D8)),
                (int32_t)MEM_W(0, UINT64_C(0xFFFFFFFF800A74E0)), (uint32_t)acam);
            if (acam != 0) {
                auto rf = [&](gpr a) { uint32_t w = (uint32_t)MEM_W(0, a); float f; memcpy(&f, &w, 4); return f; };
                fprintf(stderr, " pos=(%.1f,%.1f,%.1f)", rf(acam + 0xC), rf(acam + 0x10), rf(acam + 0x14));
            }
            fprintf(stderr, "\n");
        }
        fprintf(stderr, "JFG_OBJ tick=%u count=%d cam=(%.1f,%.1f,%.1f rot %d,%d,%d)", ticks, count,
            rd_f(cam + 0xC), rd_f(cam + 0x10), rd_f(cam + 0x14), (int)(int16_t)MEM_H(0, cam), (int)(int16_t)MEM_H(2, cam), (int)(int16_t)MEM_H(4, cam));
        for (int32_t i = 0; list != 0 && i < count && i < 16; i++) {
            const gpr obj = (gpr)(int32_t)MEM_W(i * 4, list);
            if (obj == 0) { fprintf(stderr, " [null]"); continue; }
            fprintf(stderr, " [%08X b=%d p=(%.1f,%.1f,%.1f)]", (uint32_t)obj, (int)(int16_t)MEM_H(0x48, obj),
                rd_f(obj + 0xC), rd_f(obj + 0x10), rd_f(obj + 0x14));
        }
        fprintf(stderr, "\n");
    }
}

namespace {
    std::mutex overlay_mutex;
    std::unordered_map<uint32_t, uint32_t> loaded_overlays; // ram address -> size
    constexpr bool log_overlays = true;
}

extern "C" void jfg_overlay_loaded(uint8_t* rdram, recomp_context* ctx) {
    // OverlayHeader: +0 VramBase, +4 RomAddress, +8 TextSize, +0xC DataSize
    gpr header = ctx->r30;
    uint32_t ram = (uint32_t)MEM_W(0x0, header);
    uint32_t rom = (uint32_t)MEM_W(0x4, header);
    uint32_t size = (uint32_t)MEM_W(0x8, header) + (uint32_t)MEM_W(0xC, header);

    std::lock_guard lock{ overlay_mutex };
    load_overlays(rom, (int32_t)ram, size);
    loaded_overlays[ram] = size;
    if (log_overlays) {
        printf("[JFG] overlay rom 0x%08X loaded at 0x%08X (0x%X bytes)\n", rom, ram, size);
    }
}

extern "C" void jfg_mm_free(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    uint32_t ptr = (uint32_t)ctx->r4;
    std::lock_guard lock{ overlay_mutex };
    auto it = loaded_overlays.find(ptr);
    if (it != loaded_overlays.end()) {
        unload_overlays((int32_t)ptr, it->second);
        if (log_overlays) {
            printf("[JFG] overlay at 0x%08X unloaded\n", ptr);
        }
        loaded_overlays.erase(it);
    }
}
