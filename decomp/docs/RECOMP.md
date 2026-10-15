# Static recompilation (Windows build track)

## CURRENT STATUS (2026-10-15 evening) - read this first
Everything below this section is the chronological log (oldest first); the newest entries are at the end.

**Menu-free Goldwood start works (2026-10-15 evening, opt-in, default off, entry "evening, Norton off"):**
`--jfg-test-start goldwood` replaces the automatic title request (0x15D) with the game's own new-game state
(mainSetDefaultGame, mainSetMode(0)) and the character-select request (0x16D, char 1 = Juno, mode 0x10). The game then
plays 0x16D -> 0x5D -> 0x5C by itself; 0x5C is active at about 50 s, the player is controllable within about 0.5 s of
that load. `--jfg-test-start goldwood-landing` requests 0x5C directly (about 17 s); the game struct at the 0x5C load is
byte-identical to the full sequence (globals outside it not compared). No menu input, no save read or written.
tools/test_menu_free_start.ps1: 10 goldwood runs (see log), 5 landing runs, 2 normal starts, all PASS with RUN_VALID=1.
Still open: intro/cutscene skip flags (refused), exact first controllable frame, state outside the game struct for the
landing variant, Magnus welcome dialogue of a fresh game waits for A (normal game behaviour).

**Process / Norton (2026-10-15 evening):** with Norton disabled by the user, three runs of a freshly linked exe each
showed exactly one process (RUN_VALID=1, max_instances_seen=1, watcher: one PID). The earlier double start and restart
belong to the Norton path (user observation). Runs before 19:00 remain unreliable; the measurements were repeated.

**0x16D resolved:** caller frontCharSelect (module 58); 0x16D is char 1's default start level (ROM table 0x800A3314).
The earlier "intermediate target" at 0x803434EC is frontCharBadge (module 41 +0x8B4). Overlay numbers in the
trampoline's ROM table entry equal "Module N" in jfg_us_syms_full.txt (all offsets matched exactly).

**Legacy:** `--jfg-level goldwood` (scripted menus, redirect of 0x16D to 0x5D) still works (PASS, RUN_VALID=1).
The 60 Hz validation is paused (see HANDOFF.md Backlog).

**Works (verified with screenshots, scripted input):** native Windows exe boots, intro logos, title, menus,
Select Game / name entry, new game, intro cutscene, Goldwood level playable (move, jump, fire, aim), HUD,
savegames (Flash RAM, survive restart), mouse aim (RMB aim / LMB fire, hook on controlGetManualAim),
optional free mouse camera (General tab "Mouse Camera", default off), JFG texts in the Controls tab.
Not yet tried by a human with real mouse/keyboard; audio never listened to.

**Open problems (priority order)**
1. Character models from side/front views: some poses broken (legs like stacked slices, folded knees/shoulder).
   Triangle-count decoding bug in the RT64 JFG adapter is fixed (back view correct). CPU reconstruction from the
   game's joint data is correct from all 8 views, so the remaining bug is in how RT64 reads the matrices at draw
   time (wrong one of the two matrix buffers = one frame off, or fixed-point decoding). Next: dump the decoded
   matrices for Juno and compare with the CPU values of the same frame. See entries 10:15 and 10:40.
2. Rare freeze during the Goldwood landing cutscene (~84-99 s after start, process alive, frame frozen);
   0/9 and 1/5 runs with recent builds. Tool ready: tools\stackdump\hang_watch.ps1. See entry 03:52.
3. Input lag: ~33-50 ms is the original game loop (input read -> shown next game frame at 20-30 fps); the port adds
   3-6 ms. Real reduction only by running the game logic faster (planned: optional 60 Hz logic, see below).
4. Nothing is committed to git; changes span the main project and the RT64 / N64ModernRuntime / N64Recomp submodules.

**In progress: 60 Hz validation is NOT complete (experimental checkbox, default OFF, stays experimental).**
- Measured on Goldwood (scripted 128 s, tools/test_60hz_gameplay.ps1, afternoon entry): 30 Hz 2995 updates (23.4/s,
  delta 2-3); 60 Hz 3055 (committed HEAD) and 3117 (current WIP) updates (about 24/s, delta mostly 2-3). One further
  60 Hz run gave 1751 (13.7/s, delta 4-6) that was not reproduced; cause unknown.
- So **60 updates/s was not reached stably** on these runs and the mode gives no update-rate gain over 30 Hz here.
  The earlier "delta=1 / ~16.7 ms" claim (12:19) was not reproduced. The game timer runs at the same speed in both
  modes (about 7640 VI ticks per 128 s).
- This is NOT yet a hardware limit. Loop timing (JFG_TRACE_LOOP, "late afternoon" entry): OFF and ON show the same loop
  period in each state; viFrameSync's final wait (B) is quantised to whole VI periods; the game plus display-list part
  (A) is about one VI in the fast state. Fast and slow states occur with the same binary; their cause is unknown.
  Still not separated: game CPU vs blocking inside A, and RT64 processDisplayLists / present waits.
- Fixed in WIP: adaptive VI minimum now restored exactly on disable (was a fixed 2); mode changes only at viFrameSync.
  OFF<->ON toggling, scene and pause changes are not yet tested.
- Not validated: XYZ speed, jump, animation, timers, camera, particles, cutscenes, audio (not listened to), enemy AI,
  input latency, long-run stability.
RT64 decoded Juno matrices match CPU for 252 captured loads; remaining model issue is downstream. See 12:17 and later entries.

**Where things are**
- Native project: F:\SelfmadeTools\JFG_Recomp\JFGRecomp - `build_jfg.bat [configure|build]`, exe build-cmake\JFGRecompiled.exe,
  portable test dir build-cmake\run-jfg (ROM, saves, configs), `run_jfg.bat`.
- Test tools (JFGRecomp\tools): run_to_goldwood.ps1, test_mouse_aim.ps1, run_capture.ps1 (-ScriptTime), shot_window.ps1
  (DPI-aware window screenshots, works while covered), send_keys.ps1 (real key presses), latency.py, stackdump\.
  Scripted input: env JFG_INPUT_SCRIPT / JFG_INPUT_REPEAT; trace log build-cmake\run-jfg\jfg_trace.log; JFG_TRACE_* switches.
- Recompiler inputs (decomp project): recomp/jfg.us.toml (stubs, renames, [[patches.hook]]), tools/recomp_gen.py,
  tools/recomp_run.sh (WSL), build/tmp/rh.sh (regenerate + copy RecompiledFuncs).
- Key JFG specifics: overlays loaded by the game's own linker (runLink) -> load/unload hooks; $ra hooks for every
  `jal TrapDanglingJump`; ROM read via osRomBase 0xB0000000 -> KSEG1 mapping + ROM copy (recomp.h, jfg_on_init);
  watchdog hook in __scHandleRetrace; audio = RSPRecomp of JFG's n_aspMain; RT64 JFG GBI adapter rt64_gbi_f3djfg.cpp.

---


Goal: a native Windows build of Jet Force Gemini via [N64Recomp](https://github.com/N64Recomp/N64Recomp)
(the Zelda64Recomp approach). It translates the original ROM's machine code to C, so it does not depend on
the decomp being bug-free; the decomp supplies names, structure knowledge and later the hooks for mods.

## Status (2026-10-10)
- `~/N64Recomp` cloned and built in WSL (`build/N64Recomp`).
- `tools/recomp_gen.py` generates the recompiler inputs from the ROM's own overlay tables;
  `tools/recomp_run.sh` runs everything. **Result: the whole game (main code + all 155 overlays,
  2952 functions) recompiles to C: `~/jfg_rc/RecompiledFuncs` (59 files, 36 MB).**
- Config: `recomp/jfg.us.toml`.

## How the overlays are mapped
JFG overlays are loaded anywhere in RAM by `src/runLink.c` and patched from a per-overlay table
(format in docs/NONMATCHING_BUILD.md, "Step 3 design"). N64Recomp gets them as relocatable sections:
| reference | handling |
|---|---|
| to main code/data/bss (ORT owner 0/FFD/FFE/FFF) | constant, patched into the recompiler-input ROM |
| plain `jal 0x800xxxxx` to main (no reloc in ROM) | works because overlays get recompile-time addresses in KSEG0: `0x81000000 + (N << 20)` |
| inside the same overlay (type 1/2) | N64Recomp reloc -> `RELOC_HI16/LO16(section, offset)` at runtime (14428 relocs) |
| call into another overlay (515 sites) | `jal TrapDanglingJump` - the game's own lazy-load trampoline, ends in `LOOKUP_FUNC` |
| data ref to another overlay (29 sites) | **open**: patched to `gUnresolvedSymbolAddr`; needs per-site handling |
| data-section words (jump tables, pointers) | patched in the input ROM to link addresses; at runtime the game's own linker patches RDRAM |
Special cases found: 32-bit wrap in addends is intended (overlay 1 folds K0_TO_PHYS into a reloc);
`Sinf`/`mathSin`/`mathSinInterp` are entry points at `Cosf+4` etc. (size-0 symbols -> own functions);
alias symbols (`X_1arg`) have size 0 and must not hide the real symbol.

## Stubbed for now (recomp/jfg.us.toml)
- `gen_anim_data`, `func_80074A68`, `func_80074B50` (src/hasm/gen_anim_data.s): hand-written asm that branches
  between the three; merged-function attempt -> "Failed to analyze". Needs a native C implementation
  (it builds the animation matrices - without it models will not animate).
- `D_8009DA10_9E610`, `D_8009F250_9FE50`, `D_8009F3D0_9FFD0`: unnamed libultra internals (timer/exception).
  TODO: name the remaining libultra functions so N64Recomp maps them to the runtime (check symbol_lists.cpp).

## Next steps
1. Runtime project on Windows (VS 2022 + cmake + ninja are installed): N64ModernRuntime (librecomp +
   ultramodern) + RT64, modelled on Zelda64Recomp / the N64Recomp project template.
2. Game glue: ROM hash/entry, save type (EEPROM 16K), controller mapping (later: mouse aim),
   overlay notification: hook `runlinkDownloadCode` (after `romCopy`) and the unload path so the runtime
   knows section N is at address X (librecomp `load_overlays(rom, ram, size)` keys sections by ROM address).
   `TrapDanglingJump` computes the call site from `ra`: check what N64Recomp puts into r31 for relocatable code.
3. `gen_anim_data` in C; the 29 cross-overlay data refs; RSP microcode (audio: RSPRecomp or HLE).
4. Then: mods (WASD + mouse aim, direct level start) on top of the working build.

## Windows project (started 2026-10-10 evening)
Folder `F:\SelfmadeTools\JFG_Recomp`:
- `JFGRecomp/` - working copy, cloned from BanjoRecomp (smallest current template: ~3000 lines in src/, uses the
  libs N64ModernRuntime, rt64, RecompFrontend as submodules). To be renamed/adapted for JFG.
- `ref_BanjoRecomp/`, `ref_dino-recomp/`, `ref_Zelda64Recomp/` - references (read-only).
Toolchain on this PC: VS 2022 Community with clang-cl (`VC\Tools\Llvm\x64\bin`), cmake + ninja (Python Scripts dir).
Missing: `make` (only needed for the `patches/` MIPS code - skip patches at first).
Build (from BUILDING.md): `cmake -S . -B build-cmake -G Ninja -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=Release`.

What to take from where:
- Game registration (`src/main/main.cpp` in Banjo): `recomp::GameEntry` { rom_hash, internal_name "JET FORCE GEMINI",
  game_id, save_type Eep16k (PJ64 RDB + osEeprom use), entrypoint_address 0x80000400, entrypoint = recomp_entrypoint };
  JFG code is NOT compressed in ROM -> no decompression_routine, has_compressed_code = false.
- Overlay registration: `src/main/register_overlays.cpp` includes `RecompiledFuncs/recomp_overlays.inl` (generated).
- **Overlay load notification = dino-recomp `src/recomp_api/dll.cpp`:** runtime API `load_overlay_by_id(id, ram_addr)` /
  `unload_overlay_by_id(id)`. For JFG call them from `runlinkDownloadCode` (after `overlay->VramBase = mmAlloc(...)`)
  and from `runlinkFreeCode`/`runlinkUnloadOverlay`. Can be done without the MIPS patch toolchain via
  `[[patches.hook]]` (func, before_vram, text = C snippet) in jfg.us.toml. Check how recomp_overlays.inl numbers the
  sections (overlay N -> id) before wiring it.
- dino.toml also hooks `mathMtxCatF`, `mathMtxCat4x3F`, ... to set/clear the FR bit (cop0 status 0x04000000) around
  them: same Rare math routines exist in JFG (hand-written, 64-bit FPU mode) -> check JFG's versions for the same need.
- Mouse aim reference: DK64 Rekongpiled (repo not located yet), Zelda mod "ZeldaMouseCamera".
- Checked: in symbol-file mode `overlay_sections_by_index` is `{-1}` (no id table), so use the ROM-address API instead:
  `load_overlays(rom = 0x1ED3B20 + overlay->RomAddress, ram = overlay->VramBase, size = TextSize + DataSize)` and
  `unload_overlays(ram, size)` (librecomp/src/overlays.cpp). section_table entries are generated with exactly these
  rom addresses/sizes (e.g. overlay 1: rom 0x01ED3B20, size 0xC70).
- Libraries fetched into `JFGRecomp/lib` (N64ModernRuntime, rt64, RecompFrontend) at Banjo's pinned versions.

## 2026-10-11: first Windows build attempt
Changes in `F:\SelfmadeTools\JFG_Recomp\JFGRecomp` (Banjo template, names `banjo::`/`BanjoRecompiled` still to rename):
- `build_jfg.bat [configure|build]` - vcvars64 + clang-cl + Ninja, logs to configure.log / build.log. Configure works.
- `src/main/main.cpp` GameEntry: rom_hash 0x44830C263C2DE108 (XXH3 of baserom.us.z64), "JET FORCE GEMINI", game_id jfg.n64.us.1.0,
  **save type Flashram** (JFG uses osFlash*, not EEPROM), no decompression, no on_init (librecomp loads 1 MB at the entrypoint itself).
- `src/game/rom_decompression.cpp` now = JFG glue: `jfg_overlay_loaded` (reads OverlayHeader at s8 -> `load_overlays(rom, ram, text+data)`),
  `jfg_mm_free` (unloads when a tracked overlay address is freed). Hooked from jfg.us.toml.
- Patches removed: `RecompiledPatches/` holds empty placeholders, `src/main/register_patches.cpp` registers nothing, CMake patch steps deleted.
- `rsp/n_aspMain.cpp` = stub (no sound yet). TODO: RSPRecomp toml for JFG's n_aspMain.
- `RecompiledFuncs/` = copy of ~/jfg_rc/RecompiledFuncs (refresh with build/tmp/rh.sh after tools/recomp_run.sh).
Findings:
- **N64Recomp does not maintain $ra**; `TrapDanglingJump` needs it (ra - 8 = call site -> reloc table -> target).
  tools/recomp_gen.py now emits a `[[patches.hook]]` per `jal TrapDanglingJump` (jfg.us.hooks.toml, 1027 sites):
  main: `ctx->r31 = site + 8`; overlays: `ctx->r31 = section_addresses[idx] + off + 8`. recomp_run.sh concatenates base toml + hooks.
- Game function `_itoa` collides with the Windows CRT -> `renamed = ["_itoa"]`. Expect more of these (check build.log).
- Open: calls through function pointers that still hold `TrapDanglingJump` (flag-2 words to unloaded overlays) arrive without a valid ra.
- Build status 2026-10-11 15:15: the generated game code (RecompiledFuncs) compiles with clang-cl. Open build problems:
  1. RT64 `plume_d3d12.cpp` needs Windows SDK >= 10.0.26100 (`D3D12_HEAP_TYPE_GPU_UPLOAD`); installed: 22621. Workaround in
     build_jfg.bat: `-DCMAKE_CXX_FLAGS=/DWIN32 /D_WINDOWS /GR /EHsc /DD3D12_HEAP_TYPE_GPU_UPLOAD=((D3D12_HEAP_TYPE)5)`
     (CMAKE_CXX_FLAGS replaces the defaults, so /EHsc etc. must be repeated). Clean fix: install the Win11 24H2 SDK via VS Installer.
  2. After the last reconfigure the build stalls at "[54/862] Generating": `build-cmake/file_to_c.exe` (rt64 tool) never returns -
     even started by hand without arguments, and it blocks the launching shell. It worked in the two builds before.
     Suspects: zombie file_to_c/ninja processes from the killed build, or Defender holding the fresh exe. Next: reboot,
     `taskkill /F /IM file_to_c.exe`, delete build-cmake/file_to_c.exe + rt64/src/tools, run `build_jfg.bat build` again;
     if it still hangs, build without the CXX_FLAGS override after installing the newer SDK.
  Do not paste build.ninja lines into the session (single lines are >10 KB).

## 2026-10-11: Windows build continuation
- Read this document and NONMATCHING_BUILD.md first. Original US ROM verified read-only:
  SHA-1 `493ced9008dbe932d6e91179b68e8630cf23a023`. Matching build and reference projects untouched.
- Removed the old `build-cmake/file_to_c.exe` and rebuilt it. The native helper still stalls,
  including a copy launched under another filename without arguments. Multiple instances reported
  zero CPU time. Therefore a rebuild alone does not fix this; the underlying Windows cause is unconfirmed.
- Sandboxed CMake's Python launcher fails while resolving `cmake-gui.exe` with WinError 5.
  Direct tool binaries avoid the launcher, but configuration also stalled in the sandbox and completed
  outside it. `build_jfg.bat` now uses real CMake/Ninja executables and propagates failing exit codes.
- Added `JFGRecomp/tools/file_to_c.py`, selected by CMake option `JFG_PYTHON_FILE_TO_C=ON` (default).
  RT64's shader embedding rules accept the alternate command/dependency. The Python converter preserves
  Windows signed-char array values, lengths, C symbols and header linkage; native mode remains selectable.
  This is a build workaround, not a claimed fix of the stuck Windows processes.
- Verified all 115 embedded binary arrays (SPIR-V, DXIL, preprocessed shader text and icon)
  against their original binary inputs byte-for-byte; SDL2/DXIL/DXCompiler DLLs are present.
  With the Python converter the build passed the previous stall and continued through RT64 and the frontend.
- CMake project/output name is now `JFGRecompiled`; the internal target name is still `BanjoRecompiled`.
  SDK 22621 is still installed; the existing GPU_UPLOAD enum workaround remains necessary.
- **Windows Release build succeeded:** `build_jfg.bat` exits 0; output
  `JFGRecomp/build-cmake/JFGRecompiled.exe` (15,974,400 bytes at this stage).
  Link initially failed for ten libultra exports; `src/game/jfg_libultra.cpp` supplies them:
  SP status is handled by HLE, unsupported Controller Pak operations report NOPACK, Pak presence uses
  actual runtime controller assignments, raw SI handles CIC-6105 requests and sends SI completion events.
  CIC algorithm/source license preserved from the official Mupen64Plus source:
  https://github.com/mupen64plus/mupen64plus-core/blob/master/src/device/pif/n64_cic_nus_6105.c
  Single-player device reporting now exposes port 1 only; window title updated to JFG.
- Runtime test workspace: `build-cmake/run-jfg` (portable marker, copied assets/controller database and
  unmodified ROM copy `jfg.n64.us.1.0.z64`, stdout/stderr logs). Runtime success still under test.
- **Runtime test blocked before any observable game output:** shell launch of the new executable stalled;
  the JFG process reported 0 CPU time, no targetable window, and empty stdout/stderr files. A native
  converter copy on drive C also stalled. The system last booted at 18:48 on 2026-10-11, so the older
  document's pre-reboot-process theory alone is insufficient. No JFG/file_to_c Application or CodeIntegrity
  event was found in the filtered recent event logs. Exact loader/process cause remains unknown.
- Computer Use launcher returned `Computer Use app approval timed out`; its subsequent window listing
  still showed no JFG window. This is an additional automation limitation, not evidence of a game-code crash.
  **Rare logo, title and gameplay are NOT verified.** Do not report this build as playable.
- Manual launch entry point: `JFGRecomp/run_jfg.bat` (project assets, normal config path) or
  `run_jfg.bat test` (prepared portable `build-cmake/run-jfg`, isolated settings/saves, ROM already copied).
  Both use `--show-console`. Next required check: launch outside the Codex tool process, confirm whether
  Windows creates a window, then diagnose the actual runtime. No reboot/security-setting changes performed.
- Remaining converter processes exposed one thread each in state `Initialized`; Stop-Process was
  attempted, but process cleanup is not claimed as verified. Temporary renamed probe binaries removed.
- `JFGRecomp/BUILDING.md` now documents the actual JFG build and run steps instead of Banjo ROM
  decompression/patch steps. RT64 has a local CMake change inside its submodule; preserve that change
  when updating submodules until an upstream alternate-converter interface is available.
- User's manual `run_jfg.bat test` also showed only an empty Windows Terminal/cmd window.
  JFG PID 44780 had no main window, zero CPU time and one thread in state `Initialized`.
  Thus the manual attempt did not reach the launcher either.
- Minimal independent native control: `build-cmake/native-probe/startup.c` is a C `puts`/return program,
  compiled with clang-cl `/MT` (static CRT, no game/RT64/C++ dependencies). It also stalled without
  output. This points to the native process start path, not a demonstrated JFG game-code failure.
- A running `Denuvo Anti-Cheat` kernel driver was observed while ARC Raiders was open.
  Causality is unconfirmed; user was asked to close the game normally as a comparison. No driver,
  anti-cheat or Windows security setting was changed by the agent.
- Second user screenshot still showed only the empty cmd window. At the subsequent system check,
  `PioneerGame.exe` (ARC Raiders) and the Denuvo driver were still running; the requested comparison
  with the game closed has not been established. Native startup remains the current external blocker.

## 2026-10-12: native startup control tests
- User confirmed ARC Raiders was closed and JFG still only opened a blank console.
  System check confirmed no PioneerGame process and `Denuvo Anti-Cheat` in `Stopped` state.
  JFG PID 8980 still had zero CPU time and one thread in `Initialized` state. Closing the game
  did not resolve the issue; do not attribute the failure to an actively running Denuvo driver.
- Re-ran the independent C `/MT` startup probe with the driver stopped: still stalled without output.
- Additional controls in `build-cmake/native-probe/build_compare.bat`:
  (1) same `puts`/return program compiled and linked with Microsoft `cl`/`link`;
  (2) same program compiled with clang-cl and linked with Microsoft `link`.
  Both built successfully and both stalled without output when launched. Thus the stall is not
  specific to the JFG code, RT64, C++ runtime DLLs or LLVM's linker. Exact Windows cause is unknown.
- Own hanging tool-launch sessions were interrupted. No security policy, driver, service or
  Windows setting was changed. System boot time remains 2026-10-11 18:48:56.
- Next controlled check: a full Windows restart, then first run the minimal native probe and only
  afterwards `run_jfg.bat test`. Build artifacts and the isolated test ROM are ready; a restart
  must be performed by the user to avoid interrupting unrelated applications without consent.
  Logo/title/gameplay are still unverified. Continue from this section after the restart.
- User resumed after reboot; confirmed new boot time `2026-10-12 00:17:01`.
  The Microsoft C minimal probe initially exceeded the tool's 10-second yield, then completed
  successfully with `JFG native Windows startup probe OK` and exit 0. Unlike previous attempts,
  native startup is now possible; allow for a delayed first launch after reboot.
  File ACLs permit ReadAndExecute; no matching recent CodeIntegrity/AppLocker/Defender event was found.
  JFG runtime testing resumes with its existing Release executable.
- **Launcher verified after reboot:** visible native JFG window, ROM recognized, Start Game available.
  The launcher still uses Banjo template artwork. The first Start Game test crashed (c0000005).
  Added `/MAP:.../JFGRecompiled.map` and unbuffered startup/runtime logs for fault diagnosis.
- Reproduced native RVA `0x2D5028`: map + disassembly locate it precisely in
  `osBootRamTest1_6105` (guest load at 0x800841A8 from uncached RAM 0xA02FB1F4).
  Existing memory helpers subtract KSEG0 only, producing host offset 0x202FB1F4 outside protected RAM.
  This is an actual game-start fault; the earlier pre-reboot process stalls were a separate issue.
- Added opt-in `RECOMP_KSEG1_RDRAM` support in the runtime's N64Recomp `recomp.h`, enabled only for
  RecompiledFuncs: cached/uncached RAM aliases share storage for byte/halfword/word and SD/LD operations.
  Other targets retain the legacy mapping. This is another local nested-submodule change to preserve.
- GameEntry now calls `jfg_on_init`: sets osCicId (0x80000310) to 6105 and IPL3 markers
  0xAD090010 at cached 0x802FB1F4, 0xAD170014 at 0x802FE1C0. The original boot tests then read and
  clear these markers normally. The runtime does not execute IPL3 and previously left these values zero.
- Native memory control tests passed: legacy cached/endian/SD/LD behavior; KSEG0/KSEG1 aliasing for
  all widths; actual generated JFG boot functions return 1, clear their markers, then return 0 on repeat.
  Harness/artifacts: `build-cmake/native-probe/build_memory_tests.bat`. Windows build exits 0.
  Next: run this build and check progress beyond the two boot RAM tests; logo/title still unverified.
- Boot RAM checks passed in the game; next error was `Failed to find function at 0x8004F978`.
  This is `__scMain`. ELF has it as a LOCAL FUNC with size 0, so the symbol generator omitted it.
- `tools/recomp_gen.py` now infers zero-size function extents from enclosing functions or subsequent
  entries, bounded by real main/overlay text ranges. Internal asm `alabel` entries named func_/D_
  inside a sized function remain excluded (the first broad attempt incorrectly included animation
  branch labels and failed analysis; no such partial output was copied to Windows).
- Regeneration succeeded: 59 files / 36 MB, 9 inferred zero-size extents, unchanged 1027 return-address
  hooks and 14428 overlay relocations. __scMain is now emitted and registered at the original address.
  Updated Windows generated files without deleting the output directory; native rebuild/test follows.
- Scheduler rebuild succeeded. Actual game startup now loads/unloads multiple overlays, confirming
  progress past boot checks and thread entry lookup. Graphics then reports:
  `Unable to find a matching GBI in the current database. This game is not supported in HLE.`
- Current RT64 pin: `6f1c2d99a4ea571c139f449c326fd176ba8f3496`. Its supported GBI enum lacks F3DJFG/F3DDKR;
  upstream main also lacks these families. GLideN64's primary implementation identifies JFG as F3DJFG,
  a DKR-derived GBI with custom DMA matrix/vertex/triangle/list/offset commands and a different vertex count.
  Sources consulted:
  https://github.com/gonetz/GLideN64/blob/master/src/uCodes/F3DDKR.cpp
  https://github.com/gonetz/GLideN64/blob/master/src/uCodes/F3DDKR.h
  https://github.com/gonetz/GLideN64/blob/master/src/GBI.cpp
  https://github.com/rt64/rt64/blob/main/src/gbi/rt64_gbi.cpp
  No graphics-family adapter or forced microcode fallback has been implemented yet.
- **Paused at the user's request (2026-10-12).** Resume by checking the actual loaded graphics microcode
  and implementing verified F3DJFG support in RT64 (or selecting an existing compatible implementation).
  Build and launcher are verified; Rare logo/title/gameplay remain unverified. Animation/audio stubs remain.

## 2026-10-12: resumed, native graphics and animation bring-up
- Added `--start-game` to the native executable: validates the imported ROM and starts
  from the launcher update callback. `run_jfg.bat test start` exposes this for repeatable
  tests without UI clicks. Computer Use is limited to occasional visual checks.
- Captured actual graphics microcode: RAM text 0x9F3D0, data 0xB0350; 4096-byte
  word-swapped text CRC32 BDE9D1FB matches GLideN64's F3DJFG entry exactly. XXH3 text
  A3A9584ECD0D87E7. New RT64 adapter accepts that exact text hash, not arbitrary unknown GBIs.
- Implemented initial F3DJFG DMA matrix/vertex/triangle/texture-offset/counted-list handling
  in local RT64 changes. Build succeeds. `PRESS START` and its animated button are visible.
  **Rendering remains incorrect**: after FPU fixes, 3D appears but is badly distorted.
  Decoder review is in progress; do not describe this as playable or correct title rendering.
- `tools/recomp_anim.py` statically translates all 1012 instructions in the contiguous
  animation assembly region (three entries) to native C, with computed-jump dispatch,
  branch delay slots and branch-likely annulment. Replaces the former generated stubs.
  `tools/recomp_run.sh` now invokes this postprocessor after successful N64Recomp output.
- `tools/recomp_fpu.py` gives 23 explicit Rare single-precision assembly routines temporary
  FR=1 mode, preserving/restoring caller status. N64Recomp otherwise writes odd loads to
  f_odd but arithmetic to the independent odd register, producing inconsistent results.
- Native tests passed: real matrixTranslate on an identity-plus-translation matrix and
  actual animation quaternion helper at zero rotation, both in incoming FR=0 and FR=1;
  caller status and return address checked. Harness: JFGRecomp/build-cmake/native-probe/
  jfg_math_test.c and build_math_tests.bat. Stronger animation review is pending.
- User authorized GPT-6.1-sol helper agents: focused RT64 decoder review and read-only
  animation-lifter/FPU review, with native builds/runtime tests kept on the main agent.
- Added opt-in `--test-start-button` for a 500ms START signal after 12 seconds of controller
  polling, to test transitions without relying on desktop focus or injected key timing.
  This test path has not yet been built/run at this checkpoint. Audio remains a stub.
- Re-ran complete WSL pipeline successfully: 60 generated files / 36 MB including animation;
  every file equals the tested Windows output after newline normalization.
- Expanded actual-code math tests: six positive/negative/edge/quantized angle triples in
  FR0/FR1 against independent sin/cos products. Original 1025-entry sine table matches
  sin(i*pi/2048) within 3.39e-8. Tests pass; permanent runner `test_jfg_math.bat`, source
  `tests/jfg_math_test.c`, extraction/build `tools/test_jfg_math.py` in native project.
- RT64 review corrected combined-matrix handling to identity projection + complete model
  transform; added loaded-vertex validation and bounded unknown-opcode diagnostics.
  Identity-projection change alone did not resolve the visible distortion.
- Found concrete DMA bug: generic `fromSegmentedMasked` clears low 3 address bits, but JFG
  uses packed 10-byte vertices. `src/camera.c:926-928` and `src/explosion.c:563-564` preserve
  the original vertex address. JFG adapter now preserves low address bits for all its DMA
  commands, with range validation and one log of an unaligned vertex DMA. Build succeeds;
  runtime validation of this last fix is in progress.
- Fixed independently confirmed controller issues: presence bitmask now accumulates all
  ports; librecomp always copies each pad's error status and neutralizes disconnected pads;
  JFG input callback rejects ports declared absent rather than mirroring port0 to all four.
  These are not yet claimed as the cause of the missing menu transition.

## 2026-10-13: audio implementation and targeted runtime diagnosis
- Confirmed packed vertex DMA low bits occur in the real game (0x0026A44E).
  Preserving them is required, but alone does not fix the distorted 3D title scene.
- Bounded JFG_TRACE_DMA diagnostics now separate model-slot matrices and 3D vertex
  batches from intro sprites; first camera matrices are finite and plausible.
- Replaced silent audio stub with static RSPRecomp output for JFG's own microcode:
  ROM 0x9E610, initial size 0xF80 at IMEM 0x1080, overlays at 0x1238 from offsets
  0x1B8/0xF80 with sizes 0xDC8/0x8B8. All 16 DMEM dispatch targets verified.
  Native project n_aspMain.us.rev0.toml + tools/regenerate_audio_rsp.sh reproduce it.
  Generator twice produced identical SHA256 8A7760D65667FEB1C45D639C5C1FC2323536CEFACA8C1A2908561E07FB7B52EB;
  isolated syntax check and Windows build pass. Runtime/audio quality remains under test.
- Title code uses its own edges from raw joyGetButtons. joySecurity therefore does
  not directly explain the title START behavior. State0/1 can consume a first press
  before state2 needs another edge. Opt-in --test-start-button now pulses at 12 and
  22 seconds. This is a diagnostic action, not an automatic normal-launch behavior.
- JFG_TRACE_AUDIO=1 reports the first nonzero PCM buffer to verify actual synthesis
  without claiming a listening test. Current runtime test pending.
- Audio runtime currently stalls after the first intro frame; no nonzero PCM was
  observed yet. Added opt-in JFG_TRACE_AUDIO generated diagnostics (entry/exit,
  DMA/overlay and per-task label budget) to identify the exact offending PC.
- RT64 review found projective world matrices can be corrupted by generic matrix
  decomposition/recomposition during interpolation. JFG reset now uses existing
  matrixId IGNORE and SKIP components so exact matrices bypass transform matching
  and interpolation; global RT64 math is untouched. Built, visual validation pending.
- Added opt-in JFG_TRACE_INPUT frontSetMode logging, persisted in recomp config;
  complete regeneration still succeeds (60 files, 1012 animation instructions,
  23 FPU routines, unchanged overlay/relocation counts).
- Correction after instrumented run: the first audio task completes normally
  (Broke, 7803 labels); no audio loop was observed. WER identifies a native access
  violation at __scHandleRSP while reading the current task, consistent with a
  cleared/null scheduler task. Investigating the game's >10-VI SP/DP watchdog:
  __scHandleRetrace clears tasks after issuing a hardware halt, while native HLE
  tasks can complete later. No workaround has yet been validated.
- Confirmed watchdog failure in combined trace: guest SP halt 0x00AAAA82 occurs
  before audio task1 completes; scheduler subsequently receives a completion with
  curRSPTask=0 and crashes. JFG-only __scHandleRetrace entry hook now resets the two
  hardware watchdog counters, preserving native job ownership until real SP/DP
  completion. No null-pointer bypass, no original game source edits; native task
  errors still terminate through the existing runtime. Build/runtime test follows.
- Actual RT64 math regression test independently confirms projective corruption:
  W column (0,0,1,1) becomes (-2,0,1,-3); JFG preservation policy retains coefficients.
  Permanent native tests/jfg_projective_matrix_test.cpp and test_jfg_projective_matrix.bat pass.

## 2026-10-15: state check (Claude)
- Test tooling (native project): `tools\run_capture.ps1 -Seconds 45 -Shots "8,16,26,36,44" [-ExtraArgs "--test-start-button"] [-Env "K=V;..."]`
  starts the portable build with --start-game and saves screenshots of the game window via `tools\shot_window.ps1`
  (PrintWindow + PW_RENDERFULLCONTENT, works while the window is covered). Plain desktop capture only sees the front window.
  Output in `JFGRecomp\runlogs\`. The redirected stdout only gets "[JFG] Native startup reached." - with --show-console the
  game writes the rest to its own console, so JFG_TRACE_* output is not captured this way yet.
- Exe of 2026-10-13 01:05 is current (no newer sources). Observed (screenshots runlogs/shot_1015_*):
  - runs > 3 minutes without crash (the __scHandleRetrace watchdog hook works)
  - 8 s: dark, 16 s: black, from ~26 s the textured 3D ship-corridor title scene - heavily distorted (stretched geometry,
    hard vertical cut at x~213 of 813), practically the same picture at 44 s and after 3 min; the JET FORCE GEMINI logo
    overlay of the original (mupen frame 2400) is missing
  - --test-start-button (START at 12 s and 22 s): no change to the menu
  - audio: not verifiable here (no listening test, trace output not captured)

## 2026-10-15 02:46: title scene fixed - root cause was a direct cartridge ROM read (Claude)
- **Screenshot tool bug first:** `tools/shot_window.ps1` was not DPI aware; at 150 % display scaling it captured
  only the top-left 2/3 of the window and scaled it up. That produced the "hard vertical cut at x~213" and much of
  the "stretched" look in all earlier screenshots. Fixed with `SetProcessDPIAware()` (shots are now 1622x956).
  `run_capture.ps1` got `-NoConsole` (drops --show-console so stderr traces land in runlogs\run_*.log) and retries
  the launch when the first start after a rebuild is refused ("Zugriff verweigert").
- With correct shots the RT64 F3DJFG adapter output was plausible; per-task triangle stats (JFG_TRACE_TRI) showed the
  game simply submitted only ~150 corridor triangles and no character. Game-state trace (JFG_TRACE_OBJ, read from
  RDRAM in the retrace hook) showed: camera stuck at the default (200,200,200), objects never moving, animseq
  `playing=1` but its command pointer never advancing and `animcamera[0]` NULL.
- Cause: `animseqProcessCommandList` (0x80077ABC) starts with `if (animseqUpdatePath(osRomBase) != 0)`, i.e. it passes
  `*(u32*)0x80000308 = 0xB0000000` to overlay 47's animseqUpdatePath, which dereferences it (reads the ROM header via
  PI domain 1). The runtime's KSEG1 aliasing folded 0xB0000000 onto RDRAM offset 0x10000000 (zeros in the recomp
  heap) -> returned 0 -> the whole cutscene/command system (camera paths, object animation, title flow) never ran.
- Fix (runtime, no game-code change):
  - `lib/N64ModernRuntime/N64Recomp/include/recomp.h` (RECOMP_KSEG1_RDRAM variant): only 0xA0000000-0xAFFFFFFF are
    folded onto KSEG0; 0xB0000000+X maps to rdram offset 0x30000000+X.
  - `src/game/jfg_libultra.cpp` jfg_on_init: VirtualProtect that range (inside librecomp's 4 GB reservation) and copy
    the ROM there word-swapped like RDRAM.
- Verified (screenshots runlogs\shot_1015_024447_*.png, copy title_fixed_30.png): intro, Nintendo logo, then the
  title corridor with Juno running, camera moving and the JET FORCE GEMINI logo / START alternating, matching the
  mupen64plus reference. Game speed ~15 display lists/s at the title (same as before).
- Also added (opt-in diagnostics): JFG_TRACE_TRI (per-task triangle stats), JFG_DUMP_DL=N (dump N-th display list),
  JFG_TRACE_APPDL (DL counter with time), JFG_TRACE_VI (VI regs), JFG_TRACE_OBJ (objects/camera/animseq state),
  JFG_TRACE_PATCH=N (main code/data words patched by runLink in RDRAM), JFG_WATCHDOG (samples thread RIPs when the
  retrace hook stalls 3 s; resolve with build-cmake\JFGRecompiled.map), JFG_CULL=1/2 (cull override, debug only).
- Open: some runs stall in the intro (DLs stop around 4-10 s); not yet reproduced with the watchdog enabled.

## 2026-10-15 03:06: title -> menu -> new game -> Goldwood playable (Claude)
- Added opt-in scripted pad-1 input in `src/main/main.cpp`: `JFG_INPUT_SCRIPT="ms:KEYS[:hold_ms],..."` (KEYS joined
  by '+': A B Z START L R CU CD CL CR DU DD DL DR, stick UP DOWN LEFT RIGHT; ',' or ';' separate steps; times from
  the first pad poll) and `JFG_INPUT_REPEAT="period:KEYS[:hold]@from-to"`. Steps are logged to
  `build-cmake\run-jfg\jfg_trace.log` via `jfg_logf` (file + stderr). `--test-start-button` still exists.
- `tools\run_to_goldwood.ps1` runs the whole verified sequence: title START x2 (PLAY), A (Game 1 New Game),
  A (types "1"), 4x stick down to END, A, START x2 (skips the intro cutscene), A x3 (Juno briefing) -> Goldwood
  at ~105 s, then walks up the ramp, jumps, turns right into the water, fires (ammo 100 -> 98).
- Verified by screenshots: menus (runlogs\shot_1015_024928_*/025552_*), name entry, intro cutscene
  (shot_1015_025835_*), Goldwood gameplay with HUD and movement (goldwood_109.png, shot_1015_030426_*).
  Frame rate from the heartbeat: title ~15 display lists/s, Goldwood ~20/s at 60 retraces/s.
- Front mode trace for this path: 0 -> 2 -> 3 -> 24 -> 5 -> 16.
- Still open / not verified: audio (no listening test); the occasional early stall (game stops submitting
  display lists and retraces around 4-13 s in some runs, seen ~5 times before the ROM-mapping fix, not seen in
  ~12 runs since, never with JFG_WATCHDOG=1 active); stderr redirected to a file sometimes stops receiving
  output - use jfg_trace.log. Widescreen "Expand" shows stretched geometry outside the 4:3 vignette on the title.

## 2026-10-15 03:34: keyboard + mouse aim (Claude)
- **Keyboard:** recompinput already ships a default keyboard profile (`lib/RecompFrontend/recompinput/src/input_mapping.cpp`):
  stick = WASD, A = Space, B = Left Shift, Z = Q, R = R, L = E, START = Enter, C = arrow keys, D-pad = IJKL, Escape = menu.
  Rebindable in the Controls tab. Left unchanged (not separately tested with real key presses; scripted input bypasses it).
- **How JFG aims (decomp):** hold R = aim mode. Overlay player states (o15/o16/o17/o50) call
  `controlGetManualAim(obj, state, ...)` (0x8003AABC) every frame: stick within +-40 offsets the crosshair, beyond 45 it
  turns the aim yaw (state+0x11C) / pitch (state+0x1E2) at a table rate; callers clamp the pitch to [-0xA80, 0x1555].
  In aim mode C-left/C-right strafe (ControlModeNormal: Z fire, CU/CD, A, B, CL/CR, A/B zoom). `controlUpdatePlayerAim` is
  only the auto-aim target picker, not the input path.
- **Chosen approach: hook, not stick emulation.** Feeding mouse motion into the stick would give a crosshair that snaps
  back and a rate-controlled turn (bad mouse feel). Instead a `[[patches.hook]]` at the entry of controlGetManualAim
  (`recomp/jfg.us.toml`) calls native `jfg_mouse_aim` (`JFGRecomp/src/main/main.cpp`), which adds the mouse motion
  since the last frame directly to yaw/pitch (12 angle units = 0.066 deg per count at 100 %); the game's own clamps run
  after it. Motion is collected in a poll_input wrapper (`jfg_poll_inputs`) and dropped while the hook is not being
  called (not aiming). Regenerated with tools/recomp_run.sh; only `RecompiledFuncs/funcs_9.c` changed (one hook line;
  the other files differed only in CRLF and were not copied).
- **Buttons:** left mouse = Z (fire), right mouse = R (aim). While the right button aims, the stick (WASD) is turned into
  C buttons (A/D = C-left/right strafe, W/S = C-up/down) and zeroed, so WASD does not move the crosshair.
- **Option:** General tab "Mouse Sensitivity" (librecomp option, now enabled for JFG, default 100 %, JFG description);
  0 = mouse aim off (also no cursor capture). recompui got two optional GeneralTabOptions fields
  (`mouse_sensitivity_default`, `mouse_sensitivity_description`). With it > 0 the library captures the cursor
  (SDL relative mode) while the game runs and no recomp menu is open. Env `JFG_MOUSE_OFF=1` hides the option (A/B tests).
- **Test:** `JFGRecomp/tools/test_mouse_aim.ps1` (same route as run_to_goldwood.ps1, `-Tail` replaces the gameplay part;
  new script keys LMB RMB MLEFT MRIGHT MUP MDOWN, 10 counts per poll; `JFG_TRACE_INPUT` logs "[JFG] Mouse aim" lines).
  Verified by screenshots in Goldwood: R shows the crosshair (runlogs\shot_1015_031800_113), R + mouse right turns the
  view right (…_116, yaw -120 per frame in the trace), RMB alone enters aim mode, RMB + stick LEFT strafes left (…_121),
  RMB + LMB fires (ammo 100 -> 98, …_123). Pitch sign was inverted in the first build (mouse up looked down,
  shot_1015_032303_114); fixed and re-verified: mouse up looks up (shot_1015_033234_114 vs _111).
  Not tested: real mouse/keyboard hardware events, cursor capture behaviour, W/S (C-up/down) effect in aim mode,
  sensitivity slider in the UI.
- **Stall:** the intermittent stall during the Goldwood landing cutscene (heartbeat and all logging stop at ~84-99 s,
  even the JFG_WATCHDOG thread prints nothing) hit 4 of 8 runs in this session, including a control run with
  `JFG_MOUSE_OFF=1` (runlogs\run_1015_032839), so it is not caused by the mouse code. Still open; worth a real debugger
  attach next time it hangs.
- Open: control descriptions in the Controls tab are still Banjo's text (src/game/config.cpp set_control_descriptions).

## 2026-10-15 03:52: Goldwood landing-cutscene stall - not reproduced with the current build (Claude)
- No cdb/procdump/WinDbg on this PC (Windows Kits Debuggers\x64 only has dbghelp/dbgcore), and the exe has no PDB.
  Added a small native stack dumper instead: `JFGRecomp\tools\stackdump\stackdump.exe <pid>` (source stackdump.cpp,
  dbghelp StackWalk64 over all threads, module+offset + export names), `resolve.py dump.txt` (resolves exe frames with
  build-cmake\JFGRecompiled.map) and `hang_watch.ps1 [-Tag x]` (run in parallel with run_to_goldwood.ps1; when
  jfg_trace.log stops changing for 5 s it dumps all thread stacks twice to tools\stackdump\hang_<Tag>*_r.txt).
  Verified on a live, healthy process (92 threads; game threads resolve to e.g. trackDraw / wait_for_external_message).
- 7 runs of run_to_goldwood.ps1 with the current exe (built 03:28:38) from 03:37 to 03:51, 112-150 s each, 2 of them
  with 32 busy-loop processes loading all cores: **no stall** (runlogs\run_1015_033705 ... 034946; heartbeat runs to
  the end, e.g. retrace 8820 at 149 s). Together with the 2 clean runs at 03:30/03:32 that is 0 of 9 with this build.
- The 4 stalled runs (031531, 032050, 032532, 032839) all used earlier mouse-aim builds from 03:15-03:28; runs
  030028-030659 (before the mouse work) show no clear stall. So either (a) something in the pre-03:28 mouse builds
  caused it (JFG_MOUSE_OFF=1 only hides the option; the controlGetManualAim hook and the poll_input wrapper were still
  active in run 032839), or (b) it is a rare race that depended on machine load at that time (other agents/builds).
  Not decided - no stack of a hung process was obtained. The stall screenshot (shot_1015_032839_110) shows the
  process alive with a frozen frame (Goldwood landing, ship over the pad).
- Note: jfg_logf holds a mutex while writing to both jfg_trace.log and stderr; if the stall really silences even the
  JFG_WATCHDOG thread, a thread blocked inside jfg_logf (or the process being stuck in exit) is a candidate - check the
  stack dump for jfg_logf / vfprintf / exit frames.
- No code changes in the game this time; build untouched.
- Next time it hangs: start `tools\stackdump\hang_watch.ps1` alongside the run (or run stackdump.exe on the PID by
  hand) and read hang_*_r.txt: look for game threads not in wait_for_external_message/pause_self, RT64 threads in a
  fence wait, or several threads waiting on the same SRW lock.

## 2026-10-15 08:46: torn character models fixed - F3DJFG triangle count (Claude)
- Symptom (user screenshot, also visible in older shots e.g. runlogs\shot_1015_033234_111): Juno's limbs drawn as
  separate pieces with gaps/holes at hips, knees, shoulders; head and level fine.
- Cause: the RT64 F3DJFG adapter read the DMA-triangle count from bits 20..23 of w0 (`p0(20,4)+1`). The game
  (makeModelGfx, src/models.c:1390, and fx.c/objects.c/particles.c) writes `((count-1)*16 | hasTex) << 16` there,
  i.e. only the low 4 bits of count-1, and the real count in the low halfword as a byte length (`count*16`).
  Every model group with more than 16 triangles (most character limb groups, which also hold the triangles that
  stitch two joints together via the group's matrix splits) was drawn with only `(count-1)%16+1` triangles.
  The joint matrices (gen_anim_data lifter) and vertex/matrix-slot handling were reviewed and are consistent with
  the decomp and JFG Forge (rigid joint per vertex via group matrix_ids/matrix_splits) - they were not the problem.
- Fix: `lib/rt64/src/gbi/rt64_gbi_f3djfg.cpp` triangles(): `count = p0(4, 12)` (= GLideN64's `_SHIFTR(w0,4,12)`).
- Verified (built + run_to_goldwood.ps1 screenshots): runlogs\shot_1015_085406_111 (standing) and _116 (running on
  the bridge), crops crop_111.png / crop_116.png: limbs connected, knees/hips closed; the HUD health bar (red
  segments, bottom left) now also appears, it was missing before for the same reason. Not compared pixel-by-pixel
  with the original (mupen rom_shots.sh failed: "Failed to open video device" in WSL this time).
- Seen once in this session (run 085127, before the hang watcher was attached): the landing-cutscene stall at ~84 s
  (heartbeat stops). The next 4 runs did not stall. Still open.

## 2026-10-15 09:05: Space = jump (Claude)
- JFG Normal control mode (ControlModeNormal, asm/data/charControl.data.s): entry +0xC = 0x8000 (A) is the jump
  button (o15 checks it with controlCeiling before jumping); +0x0 = Z fire. The Expert mode table uses C-Up there.
- The default keyboard profile already maps Space -> A (recompinput input_mapping.cpp), so Space jumps in the
  default control mode. Verified with REAL key events: new `tools\send_keys.ps1` (SendInput scan codes, focuses the
  game window) + new opt-in trace `JFG_TRACE_BUTTONS=1` (logs pad-1 button changes): Space -> "Pad buttons 8000"
  for the hold time; W walks Juno forward (runlogs\cmp_085828.png). The jump itself was not caught on a screenshot
  with the real key (timing of the landing cutscene varies per run); scripted A jumps were verified before.
- Controls tab descriptions were still Banjo's text; replaced with JFG ones (src/game/config.cpp
  set_control_descriptions; A says "Jump (default key: Space)"). Bindings stay rebindable.

## 2026-10-15 09:10: savegames (Flash RAM) work (Claude)
- Path: JFG's saves.c (packSaveGameEprom etc., flashROMWrite/Read) calls osFlashSectorErase/WriteBuffer/WriteArray/
  ReadArray, which the recompiled code routes to librecomp's `_recomp` implementations (flash.cpp); the save buffer
  is written by librecomp's saving thread to `build-cmake\run-jfg\saves\jfg.n64.us.1.0.bin` (portable run dir,
  128 KiB). Game slot n = one 16 KiB flash sector (11 data pages + checksum page at +0x7F), global flags at page 0x380.
- Test: scripted menu run created a new Game 2 (RIGHT, A, name "1", END): file rewritten at 09:08:39, new pages at
  0x4000-0x4500 + checksum 0x7F80 (run_1015_090758). After a restart the Select Game screen shows "Game 2 / 1 /
  Game Time 00:00" (runlogs\shot_1015_090853_30.png) and Game 1 (created 02:59) as before (shot_1015_090656_27,
  "Play Game 1" option). So write -> file -> restart -> load works; the game's own checksums accept the data.
- Not tested: an in-game progress save (JFG saves at specific events; not reached by the scripts). Note: librecomp
  erases one 128-byte page per osFlashSectorErase (real flash: 16 KiB sector); harmless for JFG because it always
  rewrites the same pages of a slot. No code change. The test save file was restored to its 09:07 backup afterwards.

## 2026-10-15 09:15: input lag - measured, mostly inherent to the game loop (Claude)
- New opt-in trace `JFG_TRACE_LATENCY=1`: steady-clock timestamps of pad-1 input sampling (I, jfg_get_input =
  osContGetReadData), display-list submission to RT64 (D, Application::processDisplayLists) and swap-chain presents
  (P, PresentQueue before present). Analysis: `python tools\latency.py [log] [from_s]` (native project).
- Measured on the title/intro (30 game fps; display 156 Hz, rr_option Display = RT64 interpolation on, D3D12,
  PresentEarly, present-wait with max frame latency 1): input samples 30/s, DLs 30/s, presents 156/s;
  input -> next DL 0.6 ms (median; that DL is the PREVIOUS frame's), input -> 2nd DL 34 ms (the frame built with this
  input), DL -> next present 3.3 ms median (max 21 ms).
- Cause of the lag, from the decomp (src/main.c ~599-625): every loop iteration first submits the display list built
  in the previous iteration (rcpFast3d), then reads the pad (joyRead), runs the game logic and builds the next display
  list, which is only submitted at the top of the next iteration. So input reaches the screen ~1 game frame after it
  is read (33 ms at 30 fps, 50 ms at Goldwood's 20 fps) plus on average half a frame until the next read. This is the
  original game's pipeline and is the same on N64. The port adds: RT64 render+present ~3-6 ms and, with frame
  interpolation (rr_option Display), up to ~1 VI (the newest frame is blended in over the next display frames).
  Input is already sampled late: SDL key state is live (SDL_GetKeyboardState pointer, events pumped every 1 ms on the
  main thread), get_n64_input runs inside osContGetReadData at the moment the game reads the pad; mouse deltas are
  taken at osContStartReadData right before the game logic consumes them.
- RT64 is already in its lowest-latency setup (PresentEarly presents as soon as the frame is rendered instead of at the
  VI swap; present wait with frame latency 1). No runtime setting change made - nothing measured justified one.
  For the lowest latency a player can set Graphics > Frame Rate to "Original" (no interpolation, saves up to ~1 VI,
  at the cost of 20 fps motion). A real reduction would need submitting the display list right after it is built
  (reordering the game loop / scheduler) - not done, risky for timing.
- Note: only ~20 s of the 50 s run were in the trace (4339 events, below the 6000 cap); the analysed window is 15 s.

## 2026-10-15 09:55: optional mouse camera (Claude)
- How JFG's normal camera works (decomp charControl.c func_8002CF78 = vram 0x8002CF6C, the follow camera chosen by
  func_8002B378): target = player + (sin(az)*d, h, -cos(az)*d) with the orbit azimuth az in state+0x104. While the
  player is not braking/walking back, az is re-derived from the current camera position (lazy camera); otherwise it
  blends behind the player. View yaw/pitch (controlcam+0x0/+0x2) are smoothed toward the look-at angles. Player
  movement is ALREADY camera relative: o16 boyControl uses `Arctanf(stickX, -stickY) - *controlcam` as heading.
- Implementation (opt-in): two [[patches.hook]] in recomp/jfg.us.toml - entry of func_8002CF78 -> `jfg_mouse_camera`
  (mouse X rotates the current camera position around the player and adds the same angle to az and the view yaw;
  removes last frame's Y offset first) and func_8002B378 at 0x8002B814 (right after `jal func_8002CF78` returns, also
  the join point of the other camera modes) -> `jfg_mouse_camera_post` (only if the follow camera ran this frame:
  adds a height offset h from mouse Y (clamped -40..160) plus the matching extra pitch; removed again at the next
  entry so the game's smoothing state never sees it). Code in JFGRecomp/src/main/main.cpp; mouse motion goes to a
  separate accumulator (dropped while aiming or when the follow camera is not running, e.g. cutscenes/aim mode).
  12 angle units per mouse count (same as mouse aim), 0.5 world units height per count.
- Option: General tab "Mouse Camera" Off/On (src/game/config.cpp, key jfg_mouse_camera), default Off; needs Mouse
  Sensitivity > 0. Env JFG_MOUSE_CAMERA=1 forces it on for tests. Regenerated (only RecompiledFuncs/funcs_7.c changed).
- Verified with scripted mouse (test_mouse_aim.ps1 -Tail, -Env JFG_MOUSE_CAMERA=1): mouse right turns the view right
  (runlogs\cmp_093109.png; the first build had the sign inverted, cmp_092454), W afterwards runs away from the camera
  in the new view direction (cmp_093109 third frame); mouse down raises the camera / looks down, mouse up lowers it /
  looks up, RMB + mouse still aims (cmp_093519.png). Not tested: real mouse hardware, the option in the UI, long play.
- Test tooling: run_capture.ps1 -ScriptTime (used by test_mouse_aim.ps1) times screenshots from the first pad poll
  (= JFG_INPUT_SCRIPT time base, found via jfg_trace.log); the launch -> first poll delay varied by up to ~27 s, which
  made earlier wall-clock shot timings miss gameplay.
- Found while testing: when the camera is far around a standing Juno (her turn-in-place / looking pose) her legs and
  torso render as rotated "slices" (runlogs\crop_092454_134.png, cmp_094012.png). Same with RT64 interpolation off
  (rr_option Original, cmp_094421) and the per-joint scale/tilt inputs of gen_anim_data are neutral (new debug trace
  JFG_TRACE_SCALE=<joint count>, hook after gen_anim_data in modGenAnimMatrices at 0x8003D908; Juno = 27 joints,
  tilt list empty) -> the joint rotations themselves (animation decode in gen_anim_data, or the anim blend path) are
  suspected. Under investigation, see next entry.

## 2026-10-15 10:15: remaining character-model artifacts - narrowed down, still open (Claude)
- After the triangle-count fix, Juno is connected and looks right from behind (gameplay camera) and mostly right from
  the front (title), but some joints still look folded/jagged (knees, a flap at the shoulder; title crops
  runlogs\crop_100048.png, crop_100353.png) and, seen from the side/front-side with the mouse camera, the idle pose
  shows the legs as stacked "slices" (crop_092454_134.png, cmp_094012.png). Not yet decided whether this is a remaining
  bug or partly the original low-poly look (no original-game comparison: mupen in WSL failed with "Failed to open
  video device" this session).
- Verified correct (so NOT the cause):
  - Animation decode: new opt-in dump `JFG_TRACE_SCALE=27 JFG_DUMP_ANIM_AT=<script ms>` (hook after gen_anim_data
    in modGenAnimMatrices, 0x8003D908; dumps model instance, transform records, anim control/frames, the decoded
    rotation/scale tables and the joint matrices to jfg_trace.log; copy runlogs\anim_dump_095257.log) checked with
    scratchpad script anim_check.py: all 78 decoded angle scalars equal an independent re-implementation of
    func_80074B50 (JFG Forge's documented algorithm); per-joint scale 1.0; tilt list empty.
  - Joint matrices: every joint's float world matrix equals local(rotation in A/C/B order, rest offset) x parent
    exactly as JFG Forge builds them (max error 1e-4) - the lifted gen_anim_data (FPU, ldl/ldr bit reader) is right.
  - conv_mult_matrix only converts these float matrices to s15.16 in place (camTick, before the next DL submit).
  - RT64 adapter: matrix load/multiply/slot and matrix-index moveword match GLideN64's F3DDKR/F3DJFG handling;
    no vertex load uses a destination >= 32 (JFG_TRACE_VTXCMD=1 logs any); culling off (JFG_CULL=1), billboard off
    (JFG_NO_BILLBOARD=1, debug), forced depth test (JFG_FORCE_Z=1, debug) and RT64 interpolation off (rr Original)
    all leave the artifacts unchanged.
- Next step suggestions: compare with the original (fix mupen in WSL or use another emulator with GLideN64 at high
  resolution, same title frame); CPU-render the model from the dumped matrices with the game's chunk/matrix rule
  (Forge rigid_matrix_assignments) to see the expected silhouette; disassemble the F3DJFG vertex DMA handler in
  build-cmake\run-jfg\jfg-ucode-text.bin to check how the DMA address low bits / vertexOffset are combined.
- All switches above are opt-in debug env vars; default behaviour unchanged.

## 2026-10-15 10:40: model artifacts - further narrowed (Claude, stopped on usage budget)
- Correction to the 10:15 entry: the 27-joint model analysed there is HintGremlin (prop 143), not Juno. Juno is
  Boy (prop 220, 21 joints). Repeated for Boy (runlogs\anim_dump21.log, anim_dump21b.log): animation decode and all
  joint matrices again match the JFG Forge formulas exactly.
- CPU reference render (scratchpad cpu_render.py: ROM Boy vertices x dumped joint matrices, Forge's rigid
  group/split rule; runlogs\cpu_render_juno.png) shows a normal standing Juno from all 8 directions, while the game
  frame of the same moment (runlogs\crop_101046.png) shows the "sliced" legs -> the remaining bug is after the CPU
  matrices.
- Also verified correct: every Juno vertex load uses exactly the expected joint matrix id (new opt-in RT64 trace
  JFG_TRACE_VTXID_VOFF=<hex vertex base> / JFG_TRACE_VTXID=<dl>, runlogs\vtxid_juno.log: 0 mismatches over 12 DLs,
  model + reflection); the per-instance vertex copy (0xBF vertex base = inst+0x04) has the same positions as the ROM
  (0/638 differ); no joint matrix has out-of-range rotation values (JFG_TRACE_MTXRANGE=1).
- Remaining suspects (not tested): the matrix BUFFER read at draw time (0xBF matrix base = inst+0x10+idx*4 vs. the
  buffer gen_anim_data/conv_mult_matrix filled for that frame - a one-frame/other-buffer mismatch would give joints
  from different animation frames), conv_mult_matrix's s15.16 packing as read by RT64 FixedMatrix, and RT64's
  combination with matrix slot 0 (mul(m, M0)). Next step: in the RT64 matrix handler dump the decoded 4x4 for
  Juno's ids and compare with the dumped float world matrices of the same frame.
- Debug-only env switches added today (all default off): JFG_TRACE_BUTTONS, JFG_TRACE_LATENCY, JFG_TRACE_SCALE,
  JFG_DUMP_ANIM_AT, JFG_TRACE_VTXCMD, JFG_TRACE_MTXRANGE, JFG_TRACE_VTXID(_VOFF), JFG_NO_BILLBOARD, JFG_FORCE_Z.
  jfg.us.toml also has the debug hook at modGenAnimMatrices 0x8003D908 (jfg_trace_anim_scale; returns at once
  when JFG_TRACE_SCALE is unset). Project builds (build exit=0); default run to Goldwood verified at 10:24.

## 2026-10-15 12:12: optional 60 Hz investigation and first implementation (Codex)
- Source + generated US instructions confirm two independent limits: scheduler frameCount >=2
  (__scHandleRetrace 0x800506E4, __scTaskComplete 0x80050A54), and viFrameSync's adaptive
  minimum of 2/3 retraces (src/gameVi.c). viFrameSync already supports a minimum of 1;
  its returned delta counts elapsed retraces and the final swap wait remains necessary.
- main loop passes delayDat to objects, animation sequences, particles, camera, subtitles,
  timers and player control. boyControl passes integer/float delta to movement states and
  decrements timers by delta. This supports 60 Hz, but is not a full audit of every overlay.
- Confirmed frame-based exception: trackUpdateTextureScroll adds dx/dy each call, without
  a timestep. Visual scrolling may accelerate. Other physics/cutscene/audio effects unverified.
- Added persisted bool checkbox '60 Hz Gameplay', default false, explicitly Experimental.
  Hooks lower both scheduler gates to one actual retrace and the adaptive VI minimum to 1;
  do not double the VI counter or force the measured delta. Turning off restores VI minimum 2.
  JFG_60HZ_GAMEPLAY=0/1 overrides for tests; JFG_TRACE_GAMEPLAY logs delta/time/player position.
- Regeneration/build and runtime comparison pending at this checkpoint. No 60 Hz success claimed.

## 2026-10-15 12:17: first runtime comparison and matrix pairing (Codex)
- Two builds succeeded. Off baseline reaches Goldwood (shot_1015_121044_*); first on run
  reaches Goldwood (shot_1015_121419_*), but remains ~30 updates/s, delta=2, ~60 game ticks/s.
  Important correction: a >=1 scheduler completion gate plus viFrameSync's final wait costs
  TWO retraces. Revised opt-in hooks release completed tasks immediately; viFrameSync alone
  retains the mandatory retrace/swap pacing. Revised hooks regenerated, build/test pending.
- First position trace mistakenly compared behaviourId to model prop 220 and collected no
  player positions. Corrected to the actual US objGetPlayerNo globals (0x800F2D0C/0x800F2D10).
  The initial off run is therefore only screenshot/timing evidence; repeat position comparison.
- Added JFG_TRACE_MATRIX_PAIR_AT=<script ms>: capture six 21-joint CPU generations, keyed by
  buffer address; RT64 logs decoded matrices and closest captured generation (bounded 252 loads).
  First pairs at 108 s agree within 7.63e-6 (half one s15.16 LSB). This is evidence against
  a general fixed-point decoding error; full captured sequence analysis still pending.
- hang_watch.ps1 ran beside the on test; no stall observed before normal scripted termination.

## 2026-10-15 12:19: one-retrace pacing achieved; decoded matrices verified (Codex)
- Revised build passes, initial runtime now reports delta=1 and ~16.7 ms/update. Completion
  gate is bypassed only while enabled, with original viFrameSync swap + final retrace wait intact.
  This avoids two serial retrace waits. Actual Goldwood A/B comparison remains in progress.
- Matrix analysis of runlogs/gameplay_on_first.log: 252/252 loads within 7.62939453e-6
  max coefficient error, exactly the expected s15.16 rounding bound. CPU buffers alternate
  802FC088/802FC5C8. RT64 task groups 3152/3153 match CPU serial 1, 3154/3155 serial 2,
  3156/3157 serial 3. No mixed generations in these groups. Tasks include multiple render passes.
  Thus fixed-point decoding and buffer selection are correct for this captured idle-pose sample.
  Still open: downstream vertex/triangle processing, combined camera transform, GPU rendering;
  this is not a visual model fix or proof for all poses.

## 2026-10-15 (afternoon): VI-minimum restore and mode latch; 60 Hz update rate NOT reached (Codex)
- Audit against generated code (RecompiledFuncs/funcs_16.c, funcs_17.c, not only the decomp C):
  - __scHandleRetrace 0x800506E8: `sltiu $at` on the frame count, then `bne $at` (funcs_16.c:7040). The hook writes
    ctx->r1 (= $at) right before that branch, so the register is correct.
  - __scTaskComplete 0x80050A58: `sltiu $at` on the frame count, then `beq $at` (funcs_16.c:7688). Same register,
    same effect: the forced value means "count >= 2", i.e. the count gate is bypassed while enabled.
  - viFrameSync hook 0x80055104: reads the adaptive minimum through s1 = ctx->r17 = 0x800FECAC
    (D_800FECAC_B189C). The hook writes that same byte (funcs_17.c:8686).
- Adaptive VI state (gameVi.c viFrameSync): minimum 1/2/3 (3 once stable), short-frame counter (B189B 0x800FECAB),
  "no stable frame yet" flag (B189D 0x800FECAD). The previous disable path wrote a fixed 2, which is not an exact
  restore.
- Changed (src/main/main.cpp, jfg_gameplay_tick / jfg_frame_sync_limit): joyRead now only writes the requested
  mode (jfg_60hz_requested). The active mode used by the scheduler hooks changes only in jfg_frame_sync_limit.
  Enabling saves the three bytes, disabling restores them. OFF path: no writes (unchanged from before).
- NOT verified: OFF -> ON and ON -> OFF toggling at runtime, pause/menu/scene changes, and exact restore values.
- Runs: tools/test_60hz_gameplay.ps1, Goldwood route, 128 s script time, same input. Traces in runlogs/
  (gitignored, local only). Game timer = VI ticks (sum of delta) at the end of the run:

  | Run | Updates | Updates/s | Delta distribution | Game timer |
  |---|---|---|---|---|
  | 30 Hz (new build) | 2995 | 23.4 | d2 1445, d3 1504 | 7644 |
  | 60 Hz committed (HEAD) | 3055 | 23.9 | d2 1698, d3 1248 | 7625 |
  | 60 Hz new build | 3117 | 24.4 | d2 1854, d3 1163 | 7649 |
  | 60 Hz new build, first run | 1751 | 13.7 | d4 1390, d6 343 | 7640 |

  The 1751 run was not reproduced (repeat gave 3117) and its cause is unknown. Treat it as run-to-run variance.
- Conclusions:
  - The 60 Hz target (about 60 updates/s, delta=1) is NOT reached on this machine. 60 Hz and 30 Hz run at the same
    rate (about 24 updates/s, delta 2-3), so the bottleneck is render/present, not the scheduler. The "delta=1,
    about 16.7 ms" result of 12:19 was not reproduced in these runs.
  - The in-game timer advances about 7640 VI ticks in 128 s in both modes, so no speed drift is visible in this
    one comparison. XYZ-based speed, jump, animation, camera, and cutscene tests have NOT been run.
  - Option stays Experimental, default OFF.
- Open: profile CPU/GPU frame time at 60 Hz; verify OFF <-> ON toggles; remaining audit items (animation, physics,
  camera, particles, cutscenes, audio, enemy AI); input-latency test (TEST 10); long-run tests (TEST 11).

## 2026-10-15 (late afternoon): loop timing, first per-iteration budget (Codex)
- New, env-gated: JFG_TRACE_LOOP=1 (src/main/main.cpp). Per loop iteration, steady clock, microseconds:
  A = joyRead entry -> viFrameSync entry (game logic + display list build + anything that blocks in between),
  B = viFrameSync entry -> next joyRead (sync, swap, retrace waits, short loop tail: main.c:729-738 clamps delayDat to 6).
  tools/test_60hz_gameplay.ps1 now sets JFG_TRACE_LOOP=1. No RT64 or libultra instrumentation yet.
- Five runs, Goldwood route, 128 s script time. Logs: runlogs/loop_off_{1,2,3}_trace.log, runlogs/loop_on_{1,2}_trace.log
  (runlogs/ is git-ignored). Medians/p95 in ms:

  | Run | Mode flag | Iterations | A med / p95 | B med / p95 | Delta counts |
  |---|---|---|---|---|---|
  | OFF 1 | on=0 | 3475 | 17.0 / 34.0 | 16.5 / 18.0 | d2 2770, d3 691 |
  | OFF 2 | on=0 | 1770 | 33.6 / 67.2 | 33.3 / 34.4 | d4 1439, d6 322 |
  | OFF 3 | on=0 | 1770 | 33.6 / 67.0 | 33.3 / 34.3 | d4 1439, d6 323 |
  | ON 1 | on=1 (1769 of 1770) | 1770 | 33.6 / 67.1 | 33.3 / 34.4 | d4 1438, d6 322 |
  | ON 2 | on=1 (1769 of 1770) | 1770 | 33.5 / 67.1 | 33.4 / 34.5 | d4 1438, d6 323 |

- Findings (facts from these runs):
  - The 60 Hz flag IS active in ON runs (on=1), but the loop period is the same as in the OFF runs of the same state.
    The 60 Hz mode does not change the loop timing in these runs.
  - Two states occur with the same binary: a fast state (OFF 1: about 33 ms per iteration, delta mostly 2) and a slow
    state (OFF 2/3, ON 1/2: about 67 ms, delta mostly 4). The earlier 1751-update run was in the slow state. The cause of
    the switch is NOT known. It is not explained by the mode flag or by the build (OFF 1 and OFF 2 used the same exe).
  - B is quantised to whole VI periods: about 16.5 ms (one VI) in the fast state, about 33 ms (two VI) in the slow state.
    So viFrameSync's final wait is paced by a VI-locked event, not by game logic.
  - A median is already about one VI (17 ms) in the fast state. For 60 Hz the iteration needs A < 16.7 ms, and A has not
    been split yet into game CPU time versus blocking (osRecvMesg / RT64 submission / present). That split is the open part.
- Interpretation NOT yet made. Not a hardware limit, and not yet a scheduler-only problem. The next step is to instrument
  the blocking time inside osRecvMesg (lib/N64ModernRuntime/ultramodern/src/mesgqueue.cpp, a submodule file, so the change
  goes through lib-patches) and the RT64 processDisplayLists / present waits (lib/rt64/src/hle/rt64_application.cpp:469),
  then repeat OFF and ON in both states.
- Mode switch timing and the OFF<->ON toggle are still untested; the fast/slow switch needs a cause before any 60 Hz claim.

## 2026-10-15 (late): debug quick start, level redirect verified once (Codex)
- Route-verified level sequence (default run_to_goldwood.ps1, JFG_TRACE_LEVEL=1, mainChangeLevel args):
  0x0, 0x15D, 0x7F, 0x16D char 1 (x5), 0x5D char 1, 0x5C char 1. Names from build/tmp/level_names.txt (decomp project):
  0x15 "Forest First", 0x5C "Forest Day Landing", 0x5D "Forest Day Sequence", 0x16D "Boy Select Sq".
  0x142 (new game / ship intro in the older notes) is NEVER called on this route, so it cannot be the trigger.
- Added: `--jfg-level goldwood` (main.cpp main(); unknown names exit with an error, no fallback), `jfg_change_level`
  hooked at mainChangeLevel entry 0x8004665C (jfg.us.toml). Redirect: first 0x16D -> level 0x5D, char 1.
  Without the option the hook does nothing. `--jfg-skip-intro` and `--jfg-skip-cutscenes` print "not implemented".
- Local derived RecompiledFuncs/funcs_12.c got the hook line by hand (not committed); regeneration from jfg.us.toml
  must produce the same line. Regeneration was NOT run.
- Runs (portable test folder build-cmake\run-jfg, saves stay there):
  - runlogs/debug_start_goldwood_1.stderr.log: redirect at script ms 63334; 0x5C follows; HUD + player at 116 s
    (runlogs/shot_1015_150803_116.png); game still running at script end (run_capture then stops it).
  - runlogs/default_start_regression.stderr.log: no redirect, 18 script steps; Goldwood at 116 s (shot_1015_151401_116.png).
- Not done: menu-free start (title and new game still scripted), intro skip, cutscene skip, 10 repeats, time to first
  controllable frame, spawn/camera/state comparison, OFF->ON toggle tests, determinism analysis (RNG, timers).
- Open risks: the redirect fires at character select, so the game's own new-game state setup before it still runs; char
  id 1 = Juno is an inference from the "Boy Select" overlay name, not verified by screenshot.

## 2026-10-15 (phase 2 review): reproducibility, error refusals, stricter test, blocker (Codex)
- Hook regeneration: `decomp/recomp/jfg.us.toml` (repo copy = JFG_Decomp toml + the mainChangeLevel hook, only diff)
  was run through the regular generator (recomp_gen.py, N64Recomp, recomp_anim.py, recomp_fpu.py) in WSL.
  Output: 60 files. After stripping CR line endings all 60 files are identical to the Windows RecompiledFuncs/ copy,
  including funcs_12.c (hook at 0x8004665C). So the earlier hand edit equals the generated result. Not committed.
- Build: build_jfg.bat build exit 0 on the final source (15:26 exe).
- Flags: --jfg-skip-intro, --jfg-skip-cutscenes and --jfg-test-start now exit with "not implemented yet. Nothing started."
  (return 2). Unknown --jfg-level names: error, no fallback. The refusal path was checked by reading stderr; the
  PowerShell exit code was not captured reliably.
- tools/test_debug_start.ps1 (replaced): fresh process; PASS needs the redirect line, level 0x5D char 1 in the trace,
  player positions after 100 s, walk distance >= 0.5, unchanged save hashes (SHA-256 of build-cmake\run-jfg\saves),
  screenshot. Exit 0 = PASS, 1 = FAIL. A running process alone is not a pass.
  - Result, final build: PASS. redirect at script ms 63370, first player position at 96866 ms, walk distance 594.2,
    0 save files changed. runlogs/debug_start_goldwood_1.stderr.log, .trace.log, shot_*_118.png.
  - Note: the earlier PASS at 63373 ms ran on the build before the flag refusal edit; only the flag handling differs.
- Init chain before 0x16D (task step 2): NOT reconstructed. Known from the trace only: mainChangeLevel calls on the
  verified route are 0x0, 0x15D, 0x7F, 0x16D (char 1, x5), 0x5D (char 1), 0x5C (char 1). The callers and the game-state
  writes (save/progress, character, spawn) between these calls are not yet identified.
- BLOCKER for a menu-free start (task steps 3-4): no proven initialisation path yet. Earlier notes (NONMATCHING_BUILD.md:158)
  say a direct level start from mainThread hung. Without the callers of 0x16D/0x5D and the progress state, a direct call
  would be a guess. The landing cutscene 0x5C is still played; no cutscene skip exists.
- Not done: menu-free start, intro/cutscene skip, 10 repeats, 2 normal starts with this final build, invalid-name run,
  30/60-Hz smoke test, time comparison with the old path beyond the one redirect measurement.

## 2026-10-15 (step 1, call graph): mainChangeLevel callers and transitions (Codex)
Labels: [Code] = read in decomp source or generated code; [Trace] = measured in a run; [Vermutung] = not proven.

Audio blocker (environment, not game code): since 17:02 every launch stopped at a modal box
"No audio device could be found ... WASAPI can't initialize audio client" (src/main/main.cpp reset_audio). Test-only
escape hatch added: JFG_NO_AUDIO=1 continues without audio (default off, normal start unchanged). Audio is then not played.

Table (addresses are the entry of mainChangeLevel = 0x8004665C unless noted):

| Transition | Caller (measured) | Condition in code | Game state read/written | Needed before | Evidence |
|---|---|---|---|---|---|
| mainChangeLevel itself | many, see below | none | writes D_800A3250 (level), D_800A3AB0 (char), D_800A3264 (mode), D_800A3268 (region), D_800A3294 (fade countdown). Does NOT load the level | later loader in the main loop reads these [Vermutung, loader not yet found] | [Code] main.c:1174-1230 |
| 0x7F (mode 5) | overlay index 41 = decomp o42 (ROM 0x01F5F0C8, runtime base 0x8027BFA0, off 0x1E8) | overlay_42.c:600-619: after a button press, copies save slot F5E (0x538 bytes) into the game struct, sets cooperativeGame from F5F, then calls mainChangeLevel(0x7F,0,0,5,1,0) | writes game struct (mainGetGame), cooperativeGame; reads SAVE_SLOT(F5E), F5F | valid save slot | [Code] + [Trace] (once, at about 60 s). Function-level mapping of off 0x1E8 NOT verified |
| 0x142 (new game) | not called on the verified route | overlay_42.c:985-998: mainSetDefaultGame(game), name copied to game+0x51C, mainSaveGame(F5E), mainChangeLevel(0x142,0,0,0,1,0) | writes default game, name, save slot | - | [Code] + [Trace] (never called) |
| 0x16D (char 1, mode 16) | overlay index 57 (ROM 0x01F782B0, runtime base 0x803432C0, off 0x234); 4 calls with the same caller | not literal in code. Candidate: frontCharSelect (overlay_58.c:150-180) computes level = (game + char*0x76 + 0x15C + 0x74) >> 5 and calls mainChangeLevel(level, char, ..., 0x10, 1, 0) | reads character record in game struct | a valid game struct | [Trace] caller overlay; [Code] candidate in o58. CONFLICT: index 57 maps to decomp o59 (frontCredits by name), not to o58. Unresolved |
| 0x5D (char 1, mode 16) | ra 0x80077B14 in animseqProcessCommandList (funcs_25.c), reached after jal 0x80054530 | none found yet | unknown | cutscene command list running | [Trace] ra inside animseqProcessCommandList. [Vermutung] the animseq command list triggers the level change; the wrapper 0x80054530 was not analysed |
| 0x5C (char 1, mode 16) | not yet analysed | - | - | - | [Trace] only (after 0x5D) |

Why return addresses are not enough (checked in generated code):
- ra = 0x800451BC (main loop, funcs_12.c:1881-1889) and 0x80077B14 (funcs_25.c:48-53) both follow `jal 0x80054530`, not a
  jal to mainChangeLevel. So the call chain is not a direct jal; a helper or a tail jump sits in between.
- Overlay addresses are runtime-allocated and reused (rom_decompression.cpp unloads and reloads at the same RAM). The
  trace now logs the overlay that is loaded at call time (ROM address, base, offset). Runtime offset to generated link
  address does not match in the cases checked (overlay 41: link base 0x83A00000, no jal at off 0x1E0), so function names
  for overlay callers are NOT proven.

New, env-gated trace (default off): JFG_TRACE_LEVEL=1 logs every mainChangeLevel call with ra and, if ra is inside a
loaded overlay, that overlay's ROM address, base and offset (src/game/rom_decompression.cpp jfg_overlay_at).

Minimal chain for a menu-free start: NOT established. Still missing: (1) the loader that acts on D_800A3250 after the
fade countdown; (2) the state set by the save-slot load path (0x7F) and the character select (0x16D, frontCharSelect
candidate); (3) what must exist before 0x5D/0x5C; (4) the wrapper 0x80054530. No direct mainChangeLevel call from the
main thread has been shown to work (NONMATCHING_BUILD.md:158 says it hung).

Next concrete steps: decode the jal word at ra-8 in RDRAM at call time to get the exact call target (no guessing of
functions); identify 0x80054530 (funcs_17.c) and what calls it; find the loader that reads D_800A3250 (grep the generated
main loop for D_800A3250 / 0xA3250 reads); verify overlay 57 identity by comparing the ROM bytes with the loaded RAM.

## 2026-10-15 (level dispatcher review): trampoline, loader, callers (Codex)
Labels: [Code] decomp source or generated code; [Trace] measured in a run (JFG_TRACE_LEVEL=1, JFG_TRACE_TRAP=1, JFG_NO_AUDIO=1,
default route); [Vermutung] not proven.

### 1. 0x80054530 = TrapDanglingJump (overlay trampoline)  [Code]
- Symbol: jfg_us_syms_full.txt:692 "80054530 TrapDanglingJump"; source src/hasm/ido/trapDanglingJump.s (LEAF(TrapDanglingJump)).
- Arguments: a0-a3 and f12-f15 are saved and restored unchanged. Input: ra (t5 = ra-8 = the JAL that called it).
- Behaviour (file header): finds the relocation entry for that JAL, loads the overlay if needed (runlinkDownloadCode),
  computes the target inside the loaded overlay, restores arguments and TAIL-CALLS the target. It does not return on success.
- Consequence: ra is not changed by the trampoline. The target sees ra = the original caller of the trampoline. That is why
  a trace at mainChangeLevel shows the return address of the code that called the trampoline, not of the real caller chain.
- Two kinds of call sites: (a) static "jal 0x80054530" in code (e.g. frontUpdate, animseqProcessCommandList, main loop);
  (b) runtime stubs: callwords at ra-8 point into RAM (0x802B1970, 0x8039D014 seen), so runlink rewrote some call sites.

### 2. Trace proof of the trampoline path (JFG_TRAP pairing, adjacency + same ra)  [Trace]
- 0x5D and 0x5C: JFG_TRAP ra=0x80077B14 jal=0x80077B0C (animseqProcessCommandList) directly followed by mainChangeLevel
  with the same ra. Proven for both (2054 trap lines with this site in the run).
- 0x15D and 0x0 (a3=24): JFG_TRAP ra=0x80058B30 jal=0x80058B28 and ra=0x80058B40 jal=0x80058B38 (frontUpdate) directly before.
- 0x0 (a3=2) with ra=0x800451BC: NOT proven. The trampoline line for jal 0x800451B4 (func_80044938) was not adjacent.
- 0x7F: NOT via trampoline. The word at ra-8 is "jal 0x802B1970" (a RAM stub), not "jal 0x8004665C".
- 0x16D: NOT directly. Trampoline JFG_TRAP ra=0x803434F4 jal=0x803434EC (overlay index 57, off 0x22C) with a0=0, a1=0,
  a2=3, a3=0x800FB438 (symbol "pol", a polygon buffer). The following mainChangeLevel call has level 0x16D, char 1. So the
  trampoline target X changes the arguments and then tail-calls mainChangeLevel. X is NOT identified (Vermutung: a level/
  character chooser; relocation table not decoded).

### 3. Callers table (what is proven)
| Level | Caller (trace) | Proof level |
|---|---|---|
| 0x0 (boot) / 0x15D / 0x0 (mode 24) | frontUpdate (funcs_18) via trampoline, jal 0x80058B28 / 0x80058B38 | Trace, adjacent trap |
| 0x0 (mode 2) | func_80044938 main loop, jal 0x800451B4 | Trace only as ra; trampoline not adjacent |
| 0x7F (mode 5) | overlay index 41 (decomp o42), ROM 0x01F5F0C8, base 0x8027BFA0, off 0x1E8 | Code: generated overlay code at link 0x83A01248 = a0 0x7F, a3 5, jal mainChangeLevel. This matches overlay_42.c:618 exactly. The runtime-to-link offset mapping is NOT verified (0x1E8 vs link 0x124C). Runtime call goes through a RAM stub |
| 0x16D (mode 16, char 1) | overlay index 57, off 0x22C -> trampoline X | Trace (see 2). Overlay 57 is decomp o59 by section name, which is credits code. Conflict: generated link 0x84B0022C is an addu, not a call. Unresolved |
| 0x5D (mode 16, char 1) | animseqProcessCommandList, command 0x7A | Code: anim.c:1847-1874 (argB = cmd[2] & 0xFFF, argF = mainGetNextCharacter, argC, argA = frontGetMode or 0x17, then mainChangeLevel(argB, argF, argC, argA, 1, 0)). Trace: trampoline proven (section 2) |
| 0x5C (mode 16, char 1) | same site, same command 0x7A, next level value | Trace: same ra and same trampoline jal as 0x5D |
So the Goldwood landing sequence changes level through two executions of the same cutscene command 0x7A in the animation
script (first 0x5D, then 0x5C). The landing is not a separate code path.

### 4. Level loader (who acts on the request)  [Code]
- mainChangeLevel (main.c:1174) only writes D_800A3250 (level), D_800A3AB0 (char), D_800A3264 (mode), D_800A3268 (region),
  and D_800A3294 = 0x1E when the fade starts.
- func_80046070(delayDat) (main.c:1259), called from func_80044938 (main.c:736) and once with 0x1E (main.c:398):
  1. Fade countdown: D_800A3294 -= delta; return while > 0 (main.c:1293-1297).
  2. On expiry: level type, world (mainSetLevelWorld), region record into the character's record (gameplay+(char&3)*0x76+0x15C).
  3. Frees: mmFlushFreeStack, runlink module frees, levelFreeAll (if D_800A3298 set).
  4. Current level := requested: D_800A323C = D_800A3250 (main.c:1453-1456), then viChangeMode/viChangeBuffers.
  5. levelInit(D_800A323C, D_800A3244, D_800A3240, D_800A3248) (main.c:1530; level.c:1): level header from ROM (piRomLoadSection),
     lights, colour cycle, squadsInitialise, objSetAnimGroup, refractInit, animseqSetupGroup, track fog, camSetNo (level.c:387-390).
  6. Object list and players: overlay 24 trackInit (overlays/o24/overlay_24.c:47-63): objLoadObjList x2, animseqLoadLevelData,
     objSetupPlayers(arg2) (player setup), shadows, sky. No C caller of trackInit in the decomp; how the overlay is started is
     [Vermutung] (runlink/overlay init path).
  7. Completion: D_800A3294 = 0, D_800A3298 = 1, D_800A32C4 = 1 (main.c:1537-1539). The main loop reads D_800A32C4 and calls
     viFrameRateReset with delayDat = 2 (main.c:~730). D_800A32C4 is cleared at the start of the next func_80046070 call.
- Player control gate: not identified yet (joyRead/controlPlayer conditions not traced).

### 5. Audio test mode (JFG_NO_AUDIO=1) made safe  [Code, src/main/main.cpp]
- reset_audio: after a failed SDL_OpenAudioDevice with JFG_NO_AUDIO set, audio_device stays 0 and SDL_PauseAudioDevice is not
  called for device 0.
- queue_samples returns at once when audio_device == 0. get_frames_remaining uses 0 queued bytes for device 0 (what SDL
  returned anyway). The normal path (device != 0) is unchanged.
- Build verified (exit 0). Route run with JFG_NO_AUDIO=1 reached 0x5D and 0x5C and ran to the end of the time window.
  Normal start WITH audio was not re-run: in this environment it stops at the audio modal box (see "Audio blocker" in the
  previous entry). Environment issue: check the default audio endpoint on the PC.

### Open points (not guessed)
- Trampoline target X for 0x16D (decode the overlay relocation entry at 0x803434EC, or hook the entry of X by its name).
- Runtime-to-link mapping for overlays (0x7F: 0x1E8 vs 0x124C; 0x16D: no matching call in generated code at 0x22C).
- Who starts overlay 24 (trackInit) and where the player control gate is set.
- Condition of cutscene command 0x7A (script timing) and where 0x5C is decided.
- Call of 0x0 (mode 2) from func_80044938 (ra 0x800451BC): trampoline pairing missing.

## 2026-10-15 (process investigation): double launch, harness fix, what is and is not proven (Codex)
Labels: [Measured] = observed with PID/time; [Code] = read in the scripts; [Not proven] = could not be shown.

### Facts from the Windows event log  [Measured]
- Two JFGRecompiled.exe processes started at 17:29:09 and crashed:
  - PID 0xBE8C (48780), start 17:29:09.571, crash (Application Error 1000, exception 0xC0000005) at 17:29:36.
  - PID 0x7DA0 (32160), start 17:29:09.895, crash at 17:29:30.
  - Both: same module, same fault offset 0x7E69 = RVA of jfg_change_level (link map: 0x140007DF0 + 0x79).
  - Both used the exe with PE link time 0x6AD0F144 = 15.10.2026 17:29:08. The current exe was linked at 17:31:37.
- Plausible cause of the crash (not separately reproduced): the trace read of the word at ra-8 in jfg_change_level for
  the first mainChangeLevel call, where ra = 0. That read faults. The first call is at about 20 s, which matches. Fixed
  later with the guard "ra >= 0x80000008" (commit 022d1de adds the guard path; the trace is env-gated).

### Single launch vs. harness launch  [Measured]
- Direct start (Start-Process of the exe, no cmd, no test script): 1 instance (PID 28256, parent = PowerShell). Save
  hash unchanged.
- Harness launch (run_capture.ps1, old version): 1 instance in one run; launch probe: 3 of 3 runs one instance,
  visible after 0.13-0.20 s, retry branch NOT taken.
- So under normal conditions the old harness did not start a second instance by itself. A second instance can only be
  started by a second launch while the first is alive.

### What was wrong in the harness  [Code]
1. No check for a running instance: a second launch was not refused.
2. All runs share build-cmake\run-jfg (jfg_trace.log, saves, mods.json). Two instances write the same files.
3. Stop-Process -Name stopped all instances, not the tested PID.
4. shot_window.ps1 took the first JFGRecompiled window, not the tested PID.
5. The run log was taken as "newest run_*.log", not the log that run_capture printed.
6. -ScriptTime could match an old jfg_trace.log.
7. The launch retry starts a second instance when the first is not visible after 2 s.

### Changes (tools/run_capture.ps1, tools/shot_window.ps1, tools/test_debug_start.ps1)  [Code]
- Refuses to start (exit 3) when any JFGRecompiled.exe is running. Binds to the PID of its own game process (child of its
  cmd.exe). Removes the old trace before start. Samples the instance count during the run. Stops only its own PID.
  Output: RUN_PID=, max_instances_seen=, RUN_VALID=1 / RUN_VALID=0 (...). Exit 5 when another instance was seen.
- shot_window.ps1 takes -ProcessId. test_debug_start.ps1 takes the log path and PID from run_capture's output and fails
  runs without RUN_VALID=1.
- Verified: (A) harness with one instance already running: "REFUSED: 1 ... pid 47788", exit 3. (B) normal run: RUN_PID
  matched, max_instances_seen=1, RUN_VALID=1, exit 0, no instance left.
- Bug found while testing the fix: a PowerShell function returning one CIM object is unrolled, so .Count was empty and the
  check never fired. Fixed with @().

### Norton  [Measured, limited]
- NortonSvc and NortonUI are running. SecurityCenter logs only status updates (SECURITY_PRODUCT_STATE_ON).
- No event in the Application log shows Norton blocking, quarantining or killing JFGRecompiled.exe.
- Security audit log (4688 process creation) is not enabled or not readable here, so the parent of the 17:29 pair
  is unknown. Norton's own activity log was NOT checked and Norton was NOT disabled.
- Conclusion: no evidence that Norton caused the double start; also not excluded that it delays launches.

### Which process wrote what  [Code + Measured]
- Logs: run_capture writes runlogs\run_<stamp>.log for the process it started (stdout/stderr redirect). Since the fix,
  the log path and PID are printed as "log:" and "RUN_PID=".
- jfg_trace.log, saves, mods.json: written by the game into build-cmake\run-jfg. These are shared by all instances,
  so any run in which two instances overlapped mixes them. The 17:29 run log contains only one start sequence.
- Screenshots: shot_<stamp>_<s>.png, taken from the PID passed to shot_window.ps1 (after the fix).

### Consequences for earlier results  [Not proven, flagged]
- Every run before 19:00 (this session) was made with the old harness. Overlap cannot be excluded for them, except the
  checked 17:29 case. Timing, reproducibility, 60 Hz, and debug-start PASS results from earlier runs are NOT reliable
  until repeated with the new harness.
- The debug-start PASS of 15:xx/17:xx runs is therefore not evidence for reproducibility.

### Not done
- No new timing or reproducibility measurement is accepted until repeated with run_capture RUN_VALID=1.
- Norton activity log not inspected (user action needed if Norton is suspected).
- Who started the second process at 17:29:09.57 is not identified (no process creation audit).

## 2026-10-15 (evening, Norton off): clean baseline, 0x16D resolved, menu-free start (Claude)
Labels: [Code] decomp source / generated code / ROM bytes; [Trace] measured in a run with RUN_VALID=1 and
max_instances_seen=1; [Vermutung] not proven. All runs: exe built 19:58:35 (forced relink) or later, Norton disabled
by the user for about one hour (not configured by us).

### 1. Norton-free baseline (harness tools/run_capture.ps1 plus an extra 250 ms process watcher)  [Trace]
| Run | Exe | Env | RUN_PID / parent cmd | max_instances_seen | Distinct PIDs (watcher) | RUN_VALID |
|---|---|---|---|---|---|---|
| A 19:58:52 | fresh link 19:58:35 (first start of this exe) | JFG_NO_AUDIO=1 | 6416 / 42784 | 1 | 1 | 1 |
| B 19:59:45 | same exe | default audio | 42780 / 13372 | 1 | 1 | 1 |
| C 20:00:46 | same exe | test_debug_start (130 s) | 21780 / 39268 | 1 | 1 | 1 |
- No second process, no restart, process stable for the whole window in all three runs. The first start of a freshly
  linked exe behaved like the second one. With Norton off the double start/restart does not occur. The user observed
  the stop-and-restart with Norton on, so the earlier double starts are attributed to the Norton path (user observation +
  these runs; Norton itself was not inspected).
- Default audio works again in this environment (run B: no WASAPI modal box, heartbeat to the end, title screen at 30 s).

### 2. Repeated measurements with the PID harness  [Trace]
- `--jfg-level goldwood` diagnostic (tools/test_debug_start.ps1, run C): PASS. Redirect at script ms 63369, level 0x5D
  char 1, first player position 96863 ms, walk 563.1 units, 0 save files changed, runlogs/debug_start_goldwood_1.*.
- Default route with traces (JFG_TRACE_LEVEL/TRAP/GAMEPLAY, no redirect, run 20:03:33, PID 25784): RUN_VALID=1. Level
  requests 0x0 (a3 0), 0x0 (a3 2), 0x15D (a3 3), 0x0 (a3 24), 0x7F (a3 5), 0x16D x3 (char 1, a3 16), 0x5D, 0x5C (char 1,
  a3 16). Save hashes before/after identical. Trace: runlogs/route_traptgt.trace.log (not committed).

### 3. Trampoline target trace (new, JFG_TRACE_TRAP=1)  [Code]
- Hook before `jr $t8` at 0x800546AC in TrapDanglingJump (decomp/recomp/jfg.us.toml; the line is also inserted by hand
  in the local RecompiledFuncs/funcs_17.c, regeneration NOT run). Logs t5 (jal site), t7 (index into overlayRomTable),
  t9 = overlayRomTable[t7] = (overlay << 20) | offset, t8 (target), and the overlay header (base, ROM address).
- Overlay number in t9 = "Module N" in jfg_us_syms_full.txt. Proof: every offset seen matches a module symbol EXACTLY,
  e.g. 26+0x2F8 partInitLib, 35+0 fontInit, 57+0xC0 frontRarepage, 63+0x140 frontStartScreen, 42+0x178 frontKeyboard,
  42+0x2C80 frontKeyboardGetTiltList, 47+0x206C animseqInitCaptions, 12+0x1870 frontMenuFrameTrackDrawingOn,
  12+0xA64 frontMenuFrameDraw, 58+0x134 frontCharSelect, 58+0x618 frontTeleporterTick, 41+0x8B4 frontCharBadge.
- Correction of the previous entry: ROM 0x01F782B0 is overlay 58 (not 57) and ROM 0x01F5F0C8 is overlay 42 (not 41).
  The earlier index was off by one. With the ROM table entry the mapping no longer depends on RAM addresses.

### 4. 0x16D resolved  [Trace + Code + ROM]
- Trace sequence before every 0x16D request: frontUpdate jal 0x80058B68 -> 58+0x134 frontCharSelect; inside it
  jal 0x803434EC (58+0x22C) -> 41+0x8B4 frontCharBadge(0, 0, 6) (overlay_58.c:141 `frontCharBadge(0, 0, arg0)`);
  then 58+0x618 frontTeleporterTick; then mainChangeLevel(0x16D, 1, 0, 0x10). So the "intermediate target" at
  0x803434EC is frontCharBadge (a badge draw/update) and does NOT change the level.
- The level request itself is the end of frontCharSelect (overlay_58.c:161-179): mainSetMode(0), region check,
  mainValidateRestart, mainChangeLevel(record+0x74 >> 5, char, record+0x74 & 0x1F, 0x10, 1, 0), record =
  game + char*0x76 + 0x15C. Mode 0x10 and char 1 match the trace.
- Where 0x16D comes from: mainSetDefaultCharacter writes the start level of each character from the s16 table at
  0x800A3314 (ROM 0xA3F14) into record+0x74 (main.c:1825). ROM bytes: 0x42, 0x16D, 0x3D, 0x42 for chars 0-3. So 0x16D
  "Boy Select Sq" is char 1's default start level. Char 1 = Juno (screenshot: "Welcome, Juno!" in Goldwood).
- Reads/writes: frontCharSelect reads the character record (level/region at +0x74, char type at +4) of the game struct
  and writes them back after mainValidateRestart (no change for 0x16D); sets mainGameMode = 0 (mainSetMode).
- The stale ra in the level trace (ra = 0x803434F4 for 0x16D) is explained: generated code does not write ra for direct
  calls, so ctx->r31 still holds the trampoline's return address. Return addresses in traces are therefore only
  meaningful right after a trampoline call.

### 5. trackInit and player setup  [Trace + Code]
- levelInit (0x80043E3C) calls the trampoline at 0x8004406C (generated funcs_11.c); objSetupPlayers is entered with
  ra = 0x80044074 = that call + 8. trackInit (module 24, overlay_24.c:47) calls objSetupPlayers(arg2). So the chain is
  func_80046070 -> levelInit -> (trampoline) trackInit -> objSetupPlayers(spawn). Spawn id was 0 for 0x16D, 0x5D, 0x5C.
- New entry traces (JFG_TRACE_LEVEL=1): JFG_LEVELINIT (level, a1, char, anim group, requested region/mode) and
  JFG_SETUPPLAYERS (spawn id). Hooks in jfg.us.toml + by hand in funcs_11.c / funcs_1.c (regeneration NOT run).
- Camera/HUD init order inside trackInit: camSetMode(numCameras-1) before objLoadObjList; HUD not traced. [Code]

### 6. Command 0x7A (0x5D -> 0x5C)  [Code + Trace]
- anim.c:1847-1874: level = cmd[2] & 0xFFF (0xFFF = game byte 1), region = cmd[2] >> 12, char = (cmdWord >> 4 & 0xF) - 1
  or the current char, anim group = cmdWord & 0xF, mode = frontGetMode() (0x17 for level 0x168). So the next level is a
  literal in the level's cutscene script: the script of 0x16D contains 0x7A -> 0x5D, the script of 0x5D 0x7A -> 0x5C.
  Trace: anim group 0, region 0, mode 16 for both. Before each 0x7A level change the trampoline calls module 111 +0
  (jal 0x80077B0C; the module's only symbol name, osCartTest3_6105, is not meaningful).
- Not done: the script offset / sequence id of the command and the condition that runs it (command list source).

### 7. Menu-free start `--jfg-test-start goldwood` / `goldwood-landing` (opt-in, default off)  [Code + Trace]
- Implementation (src/main/main.cpp jfg_change_level, hook at mainChangeLevel entry): trigger = the first request of
  level 0x15D (title page, mode 3). It is made by the Rare logo page without any input (trace: 57+0xC0 frontRarepage).
  At that call the hook runs the game's own functions on the game struct (mainGetGame):
  mainSetDefaultGame(game) (default game, char records with start levels from 0x800A3314), mainSetMode(0) (as
  frontCharSelect), and replaces the request with the frontCharSelect request: (record+0x74 >> 5 = 0x16D, char 1,
  region 0, mode 0x10; stack args 1, 0 are the same in both calls). The title page is never loaded. No save is read or
  written; mainSaveGame is not called. The registers are restored after the helper calls (only memory effects remain).
- `goldwood-landing`: same, but requests 0x5C directly with the arguments of command 0x7A in 0x5D (region 0, mode 0x10;
  anim group 0, which mainChangeLevel sets itself, main.c:1199). This skips the cutscene levels 0x16D and 0x5D.
- Refusals: unknown name -> exit 1; `--jfg-test-start` together with `--jfg-level` -> exit 1. `--jfg-skip-intro` and
  `--jfg-skip-cutscenes` are still refused (not implemented).
- New test: tools/test_menu_free_start.ps1 (PID-bound via run_capture.ps1). Checks RUN_VALID=1 and
  max_instances_seen=1, the start line, the ACTIVE level sequence from levelInit (not the request), char 1 for 0x5C,
  objSetupPlayers after the 0x5C load, player moved after the 0x5C load (first frame > 1 unit horizontally; input is
  UP 0.4 s every second from 30 s to 69 s, no menu input), save folder: created / deleted / changed files (names + SHA256),
  screenshot of this PID. -Normal checks the default start (title 0x15D reached, no 0x16D, no test start).

Results (all RUN_VALID=1, max_instances_seen=1, saves_created=0 deleted=0 changed=0):
| Variant | Runs | Levels (levelInit) | 0x5C active at (script ms) | first move (ms) |
|---|---|---|---|---|
| goldwood | 1 (100 s, earlier input) + 5 + 1 (dump) + 3 (75 s) = 10 PASS | 0x0,(0x0),0x16D,0x5D,0x5C | 49530-50175 | 50052-50299 (0.09-0.56 s after the load; UP every 1 s) |
| goldwood-landing | 1 (75 s, dump) + 4 (45 s) = 5 PASS | 0x0,(0x0),0x5C | 16441-16942 | 30051-30181 (bounded by the input script, UP starts at 30 s) |
| normal (no flag) | 2 (40 s) PASS | 0x0,0x0,0x15D | - | - |
- Script ms counts from the first pad poll (JFG_INPUT_SCRIPT time base); the process starts about 1.5 s earlier.
  The default scripted route needs about 90 s to 0x5C (trace 0x5C request at line 90136 of the route trace, earlier
  measurements 105-112 s to gameplay). Menu-free: 0x5C at about 50 s (goldwood) and 17 s (goldwood-landing).
- Player control: in the goldwood runs the player moves in the first UP window after the 0x5C load (50.0-50.3 s). In the
  first 100 s run (UP at 50 s, 60 s, ...) the player walked from z=199 to z=1176 and then stood at Magnus, whose welcome
  dialogue ("Welcome, Juno!") waits for A. That dialogue is triggered by walking to him; it is normal new-game behaviour
  of 0x5C (the save-slot route does not show it [Vermutung: progress flag in that save]). So the first controllable frame
  is within about 0.5 s of the 0x5C load; the exact frame was not measured with finer input.
- State comparison (JFG_DUMP_GAME=1, new): the game struct (0x538 bytes, the size the save path copies) at the 0x5C load
  is byte-identical in goldwood-landing and in goldwood (full 0x16D -> 0x5D -> 0x5C sequence): 0 bytes differ. So the two
  cutscene levels do not change the game struct before 0x5C. NOT compared: globals outside the game struct (global flags,
  animseq state, object and camera state). The landing variant is therefore marked "goldwood struct-identical", not
  "proven identical".
- goldwood-landing at 20 s (runlogs/shot_1015_202407831_20.png): HUD (weapon, ammo 100, health), camera behind Juno,
  Goldwood start pool. Three landing runs gave the same walk distance 921.3 (same input) -> deterministic start.
- Screenshots (not committed): runlogs/shot_1015_200706620_75.png (Magnus dialogue, char 1 = Juno),
  runlogs/shot_1015_202109467_70.png (landing variant, same scene). The dump trace of the first landing run was
  overwritten by the repeat series (same tag); the diff result above was taken before.

### 8. Open points (not guessed)
- Intro skip (`--jfg-skip-intro`) and cutscene skip (`--jfg-skip-cutscenes`): still refused. The menu-free start replaces
  the title at about 16 s (Rare logo page runs first); an earlier trigger (first 0x0 request) was not tried.
- Exact first controllable frame: only bounded (UP every 1 s -> movement within 0.09-0.56 s after the 0x5C load).
  The input gate variable itself was not identified.
- goldwood-landing: compare state outside the game struct (global flags, animseq/object/camera state) with the full
  sequence before calling it proven equivalent.
- Command 0x7A: script offset, sequence id and the condition that runs it (command list source) not traced.
- Module 111 +0 is called through the trampoline before each 0x7A level change; its role is not analysed.
- Hooks for jfg_trap_target, levelInit and objSetupPlayers are in jfg.us.toml and were inserted BY HAND into the local
  RecompiledFuncs (funcs_17.c, funcs_11.c, funcs_1.c). A regular regeneration must reproduce them (not run).

### 9. First controllable frame (goldwood-landing, UP held from 15 s, run 20:33:00 PID 25752, RUN_VALID=1)  [Trace]
- 0x5C levelInit at script ms 16443 (last gameplay update before it: frame 492). First player sample frame 493 at spawn
  (19.0, -90.0, 199.0); first horizontal movement frame 495 (16486 ms): 3 gameplay updates / 43 ms after levelInit.
  So in 0x5C there is no further input gate after the load: input moves the player from the second update with a
  player. Saves unchanged. Trace runlogs/first_control_landing.trace.log (not committed).
- Game flags (mainGetGameFlag) live in the game struct (game->pad[0x30 + flag/8], main.c:1952), so they are covered by
  the byte-identical game struct comparison of section 7. mainSaveGlobalFlags only sets a save request bit
  (load_save_flags |= 0x02000000, main.c:2219); no save file changed in any run.

### 10. Experiment: early trigger (JFG_TESTSTART_EARLY=1, test only, default off)  [Code + Trace]
- Trigger at the main loop's level-0 request with mode 2 (the second mainChangeLevel call, about 0.5 s after the first
  pad poll) instead of the title request 0x15D. Its stack arguments are not known, so the hook sets them to 1, 0.
- Why it is plausible: in the route trace all library inits reached through the trampoline run BEFORE the first level
  request: modules 36+0, 25+0x308 amInit, 34+0, 33+0, 45+0/0xC8/0x11C, 26+0x2F8 partInitLib, 35+0 fontInit,
  47+0x206C animseqInitCaptions. Between the first and the second level-0 request only the menu frame code of module 12
  runs. So the early trigger skips the logo/title pages only. [Vermutung: no other boot state is set by the logo pages.]
- Run 20:34:24 (PID 30860, RUN_VALID=1, goldwood-landing + early): 0x5C levelInit at script ms 543, objSetupPlayers at
  556; with UP held from 5 s the player walked to Magnus (z 199 -> 1188) and his dialogue text rendered correctly.
  Repeats (tools/test_menu_free_start.ps1 -Start goldwood-landing -EnvExtra JFG_TESTSTART_EARLY=1): 2/2 PASS, 0x5C at
  770/766 ms, saves unchanged, RUN_VALID=1. goldwood regression on the same build: PASS (0x5C at 50324 ms).
