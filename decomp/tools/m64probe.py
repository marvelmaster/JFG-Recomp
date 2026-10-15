#!/usr/bin/env python3
"""Headless mupen64plus probe: run a ROM for N seconds, then report CPU state and RAM values.

Run in WSL (mupen64plus extracted to ~/m64/root, see docs/NONMATCHING_BUILD.md):
  python3 tools/m64probe.py <rom.z64> [seconds] [sym=0xADDR ...]
Prints the PC every second and at the end the requested 32-bit RAM words, so two ROMs can
be compared (original vs NON_MATCHING) without a screen.
"""
import ctypes as C
import os
import sys
import threading
import time

R = os.path.expanduser("~/m64/root")
LIB = f"{R}/usr/lib/x86_64-linux-gnu"
PLUG = f"{LIB}/mupen64plus"

M64CMD_ROM_OPEN, M64CMD_ROM_CLOSE, M64CMD_EXECUTE, M64CMD_STOP, M64CMD_PAUSE = 1, 2, 5, 6, 7
M64PLUGIN_RSP = 1
M64P_DBG_PTR_RDRAM = 1
M64P_CPU_PC = 1

DBGCB = C.CFUNCTYPE(None, C.c_void_p, C.c_int, C.c_char_p)
STATECB = C.CFUNCTYPE(None, C.c_void_p, C.c_int, C.c_int)
_msgs = []


def dbg(ctx, level, msg):
    m = msg.decode(errors="replace")
    if level <= 2 or "xception" in m or "rror" in m:
        _msgs.append(m)


def main():
    rom_path = sys.argv[1]
    secs = float(sys.argv[2]) if len(sys.argv) > 2 else 20
    watches = [(a.split("=")[0], int(a.split("=")[1], 0)) for a in sys.argv[3:]]
    os.environ.setdefault("SDL_VIDEODRIVER", "dummy")
    os.environ.setdefault("SDL_AUDIODRIVER", "dummy")
    core = C.CDLL(f"{LIB}/libmupen64plus.so.2", mode=C.RTLD_GLOBAL)
    cb = DBGCB(dbg)
    scb = STATECB(lambda c, p, v: None)
    cfgdir = os.path.expanduser("~/m64/cfg")
    os.makedirs(cfgdir, exist_ok=True)
    print("startup", flush=True)
    assert core.CoreStartup(0x020001, cfgdir.encode(), f"{R}/usr/share/games/mupen64plus".encode(), None, cb, None, scb) == 0
    sec = C.c_void_p()
    core.ConfigOpenSection(b"Core", C.byref(sec))
    emu = C.c_int(int(os.environ.get("M64_EMUMODE", "0")))  # 0 = pure interpreter: exact PC
    core.ConfigSetParameter(sec, b"R4300Emulator", 1, C.byref(emu))
    rom = open(rom_path, "rb").read()
    buf = C.create_string_buffer(rom, len(rom))
    assert core.CoreDoCommand(M64CMD_ROM_OPEN, len(rom), buf) == 0, "rom open failed"
    print("rom open ok", flush=True)
    rsp = C.CDLL(f"{PLUG}/mupen64plus-rsp-hle.so")
    rsp.PluginStartup(C.c_void_p(core._handle), None, cb)
    core.CoreAttachPlugin(M64PLUGIN_RSP, C.c_void_p(rsp._handle))

    print("plugins ok", flush=True)
    t = threading.Thread(target=lambda: core.CoreDoCommand(M64CMD_EXECUTE, 0, None), daemon=True)
    t.start()
    core.DebugGetCPUDataPtr.restype = C.c_void_p
    core.DebugMemGetPointer.restype = C.c_void_p
    print("running", flush=True)
    time.sleep(0.4)  # let the core initialise before touching debugger pointers
    pcs = []
    start = time.time()
    while time.time() - start < secs:
        time.sleep(float(os.environ.get("M64_STEP", "1")))
        p = core.DebugGetCPUDataPtr(M64P_CPU_PC)
        gp0 = core.DebugGetCPUDataPtr(2)
        ra = C.c_uint64.from_address(gp0 + 8 * 31).value & 0xFFFFFFFF if gp0 else 0
        sp = C.c_uint64.from_address(gp0 + 8 * 29).value & 0xFFFFFFFF if gp0 else 0
        pcs.append(C.c_uint32.from_address(p).value if p else 0)
        if os.environ.get("M64_STEP"):
            ramp = core.DebugMemGetPointer(M64P_DBG_PTR_RDRAM)
            ws = " ".join(f"{n}={C.c_uint32.from_address(ramp + ((a & 0x7FFFFF) & ~3)).value:08X}" for n, a in watches) if ramp else ""
            print(f"t={time.time() - start:5.2f} pc={pcs[-1]:08X} ra={ra:08X} sp={sp:08X} {ws}", flush=True)
    core.CoreDoCommand(M64CMD_PAUSE, 0, None)
    time.sleep(0.3)
    ram = core.DebugMemGetPointer(M64P_DBG_PTR_RDRAM)
    print("PC per second:", " ".join(f"{x:08X}" for x in pcs))
    c0 = core.DebugGetCPUDataPtr(5)  # M64P_CPU_REG_COP0 (u32[32])
    gp = core.DebugGetCPUDataPtr(2)  # M64P_CPU_REG_REG (s64[32])
    if c0:
        r = lambda i: C.c_uint32.from_address(c0 + 4 * i).value
        print(f"COP0 EPC={r(14):08X} Cause={r(13):08X} BadVAddr={r(8):08X} Status={r(12):08X}")
    if gp:
        g = lambda i: C.c_uint64.from_address(gp + 8 * i).value & 0xFFFFFFFF
        print("GPR ra=%08X sp=%08X a0=%08X a1=%08X v0=%08X" % (g(31), g(29), g(4), g(5), g(2)))
    for name, addr in watches:
        v = C.c_uint32.from_address(ram + ((addr & 0x7FFFFF) & ~3)).value if ram else None
        print(f"{name} @{addr:08X} = {v:08X}" if v is not None else f"{name}: no ram")
    optr = os.environ.get("M64_OVL_PTR")
    if optr and ram:
        rd = lambda a: C.c_uint32.from_address(ram + ((a & 0x7FFFFF) & ~3)).value
        tab = rd(int(optr, 0))
        loaded = [n for n in range(1, 160) if rd(tab + n * 0x20)]
        print("loaded overlays:", " ".join(map(str, loaded)))
    for m in _msgs[-15:]:
        print("MSG:", m)
    os._exit(0)


if __name__ == "__main__":
    main()
