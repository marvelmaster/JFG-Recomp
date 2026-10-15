// JFG-specific libultra entry points absent from the template runtime.
#include <array>
#include <cstdio>
#include <mutex>
#include <stdexcept>

#include <cstring>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#else
#include <sys/mman.h>
#endif

#include "recomp.h"
#include "librecomp/game.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/input.hpp"

extern "C" {
#include "n64_cic_nus_6105.h"
}

ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num);

extern "C" void jfg_on_init(uint8_t* rdram, recomp_context*) {
    // The runtime enters the game directly, so reproduce the IPL3 state JFG reads.
    constexpr gpr ram_base = UINT64_C(0xFFFFFFFF80000000);
    MEM_W(0x310, ram_base) = 6105; // osCicId for the original US cartridge.
    MEM_W(0x2FB1F4, ram_base) = 0xAD090010;
    MEM_W(0x2FE1C0, ram_base) = 0xAD170014;
    fprintf(stderr, "[JFG] CIC-6105 boot RAM initialized.\n");

    // Map the cartridge ROM for direct CPU reads through KSEG1 0xB0000000 (PI domain 1).
    // recomp.h (RECOMP_KSEG1_RDRAM) maps 0xB0000000+X to rdram offset 0x30000000+X, inside the
    // runtime's 4 GB reservation (committed PAGE_NOACCESS above the 512 MB of RAM).
    // Words are stored in host order like RDRAM, so MEM_W/MEM_H/MEM_B see the big-endian ROM.
    auto rom = recomp::get_rom();
    constexpr size_t cart_offset = 0x30000000;
    const size_t size = (rom.size() + 0xFFF) & ~size_t(0xFFF);
#ifdef _WIN32
    DWORD old_protect = 0;
    if (VirtualProtect(rdram + cart_offset, size, PAGE_READWRITE, &old_protect) == 0) {
        fprintf(stderr, "[JFG] Could not map the cartridge ROM for CPU reads.\n");
        return;
    }
#else
    if (mprotect(rdram + cart_offset, size, PROT_READ | PROT_WRITE) != 0) {
        fprintf(stderr, "[JFG] Could not map the cartridge ROM for CPU reads.\n");
        return;
    }
#endif
    for (size_t i = 0; i + 4 <= rom.size(); i += 4) {
        const uint32_t word = (uint32_t(rom[i]) << 24) | (uint32_t(rom[i + 1]) << 16) | (uint32_t(rom[i + 2]) << 8) | rom[i + 3];
        memcpy(rdram + cart_offset + i, &word, 4);
    }
    fprintf(stderr, "[JFG] Cartridge ROM mapped for CPU reads (%zu bytes).\n", rom.size());
}

extern "C" void __osSpSetStatus_recomp(uint8_t*, recomp_context* ctx) {
    // HLE tasks and completion events are managed by ultramodern, not SP registers.
    fprintf(stderr, "[JFG] Guest SP status write: %08X.\n", unsigned(ctx->r4));
}

extern "C" void __osSiGetAccess_recomp(uint8_t*, recomp_context*) {}
extern "C" void __osSiRelAccess_recomp(uint8_t*, recomp_context*) {}

// Controller Pak storage is unsupported by this runtime (JFG saves in Flash RAM).
extern "C" void __osPfsGetStatus_recomp(uint8_t*, recomp_context* ctx) { ctx->r2 = 1; }
extern "C" void __osGetId_recomp(uint8_t*, recomp_context* ctx) { ctx->r2 = 1; }
extern "C" void __osPfsSelectBank_recomp(uint8_t*, recomp_context* ctx) { ctx->r2 = 1; }
extern "C" void __osContRamWrite_recomp(uint8_t*, recomp_context* ctx) { ctx->r2 = 1; }
extern "C" void __osContRamRead_recomp(uint8_t*, recomp_context* ctx) { ctx->r2 = 1; }

extern "C" void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint8_t pattern = 0;
    for (int port = 0; port < 4; port++) {
        auto info = get_connected_device_info(port);
        if (info.connected_device != ultramodern::input::Device::None &&
            info.connected_pak != ultramodern::input::Pak::None) {
            pattern |= 1 << port;
        }
    }
    MEM_B(0, ctx->r5) = pattern;
    ctx->r2 = 0;
}

namespace {
    std::array<uint8_t, 64> pif_ram{};
    std::mutex pif_mutex;
}

extern "C" void __osSiRawStartDma_recomp(uint8_t* rdram, recomp_context* ctx) {
    {
        std::lock_guard lock{pif_mutex};
        const gpr buffer = ctx->r5;
        if (ctx->r4 == 1) { // OS_WRITE: upload the game's CIC request.
            for (size_t i = 0; i < pif_ram.size(); i++) {
                pif_ram[i] = static_cast<uint8_t>(MEM_BU(i, buffer));
            }
            if (!(pif_ram[0x3F] & 2)) {
                throw std::runtime_error("JFG: unsupported raw SI command (expected CIC-6105)");
            }
            char challenge[30], response[30];
            for (int i = 0; i < 15; i++) {
                challenge[2 * i] = pif_ram[0x30 + i] >> 4;
                challenge[2 * i + 1] = pif_ram[0x30 + i] & 15;
            }
            n64_cic_nus_6105(challenge, response, 30);
            for (int i = 0; i < 15; i++) {
                pif_ram[0x30 + i] = (response[2 * i] << 4) | response[2 * i + 1];
            }
            pif_ram[0x2E] = pif_ram[0x2F] = 0;
            pif_ram[0x3F] &= ~2;
        }
        else if (ctx->r4 == 0) { // OS_READ: return the completed response.
            for (size_t i = 0; i < pif_ram.size(); i++) {
                MEM_B(i, buffer) = pif_ram[i];
            }
        }
        else {
            ctx->r2 = -1;
            return;
        }
    }
    ctx->r2 = 0;
    ultramodern::send_si_message();
}
