# Jet Force Gemini: Recompiled (work in progress)

Native Windows port of Jet Force Gemini (N64, USA) via static recompilation:
[N64Recomp](https://github.com/N64Recomp/N64Recomp) + [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) + [RT64](https://github.com/rt64/rt64),
project structure based on [Banjo: Recompiled](https://github.com/BanjoRecomp/BanjoRecomp).

**No game data is included.** You need your own Jet Force Gemini (USA) ROM,
SHA-1 `493ced9008dbe932d6e91179b68e8630cf23a023`. The ROM and everything generated from it
(`RecompiledFuncs/`, `rsp/n_aspMain.cpp`, extracted microcode) are deliberately not in this repository.

## Status
See **[decomp/docs/RECOMP.md](decomp/docs/RECOMP.md)** - the "CURRENT STATUS" section at the top is the
authoritative summary (what works, open problems in priority order, tools); below it is the full log.
Short version: boots to title, menus, new game, Goldwood playable, saves, mouse aim, optional mouse camera.
Open: character models partly broken in side/front views, rare freeze in the Goldwood landing cutscene.

## Layout
| Path | Content |
|---|---|
| `src/`, `include/`, `CMakeLists.txt` | native project (game glue: `src/game/rom_decompression.cpp` overlays, `jfg_libultra.cpp`, `src/main/main.cpp` input/options) |
| `lib/` | submodules N64ModernRuntime, rt64, RecompFrontend at Banjo's pinned commits |
| `lib-patches/*.patch` | **our changes to those submodules** (apply after `git submodule update --init --recursive`, see below) |
| `decomp/` | snapshot of the JFG decompilation parts needed here: `recomp/jfg.us.toml` (N64Recomp config + hooks), `tools/recomp_gen.py` / `recomp_run.sh` (input generation), `src/` + `include/` (decompiled C: names and structures), `docs/` |
| `tools/` | test tools: `run_to_goldwood.ps1`, `run_capture.ps1`, `shot_window.ps1`, `send_keys.ps1`, `latency.py`, `stackdump/` |
| `build_jfg.bat`, `run_jfg.bat` | build / run on Windows |

## Build (Windows)
Requirements: Visual Studio 2022 with "C++ Clang Compiler for Windows", CMake, Ninja, Python 3; WSL (Ubuntu) for the recompiler step.
1. `git submodule update --init --recursive`
2. Apply our library changes:
   `git -C lib/N64ModernRuntime apply ../../lib-patches/N64ModernRuntime.patch`,
   `git -C lib/N64ModernRuntime/N64Recomp apply ../../../lib-patches/N64Recomp.patch`,
   `git -C lib/rt64 apply ../../lib-patches/rt64.patch`,
   `git -C lib/rt64/src/contrib/plume apply ../../../../lib-patches/plume.patch`,
   `git -C lib/RecompFrontend apply ../../lib-patches/RecompFrontend.patch`
3. Generate the recompiled code from your ROM (WSL, N64Recomp built in `~/N64Recomp`): see `decomp/tools/recomp_run.sh`
   and `decomp/docs/RECOMP.md`; copy the output to `RecompiledFuncs/`. Audio microcode: `tools/regenerate_audio_rsp.sh`.
4. `build_jfg.bat` (configure + build) - output `build-cmake/JFGRecompiled.exe`, then `run_jfg.bat`.

## Notes for contributors / AI assistants
- **[HANDOFF.md](HANDOFF.md)** is the message board between the ChatGPT planner and the Codex implementer (current task, last result, questions).
- Read `decomp/docs/RECOMP.md` first; keep its "CURRENT STATUS" up to date and add dated log entries.
- `decomp/` is a snapshot of the separate local decomp project (`F:\SelfmadeTools\JFG_Decomp`); the generator scripts
  there use that project's paths.
- Never commit ROMs or ROM-derived output.
