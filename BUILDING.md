# Building Jet Force Gemini: Recompiled on Windows

The current project is adapted from BanjoRecomp. The complete JFG development
status is in `F:\SelfmadeTools\JFG_Decomp\docs\RECOMP.md`; read that first.

## Requirements

- Visual Studio 2022 Community, Desktop development with C++ and clang-cl.
- CMake, Ninja and Python 3. The local `build_jfg.bat` uses the installed real
  CMake/Ninja binaries, avoiding their Python launchers.
- The checked-out runtime libraries in `lib/` and generated JFG code in
  `RecompiledFuncs/`.
- An original US `.z64` ROM, SHA-1
  `493ced9008dbe932d6e91179b68e8630cf23a023`. No decompression is needed.

The recompiler inputs and generated C are produced separately in WSL using
`JFG_Decomp/tools/recomp_run.sh`; `JFG_Decomp/build/tmp/rh.sh` refreshes the copy
in this Windows project. Do not modify the original ROM or the matching build.

## Build

From this project directory in PowerShell:

```powershell
.\build_jfg.bat configure
.\build_jfg.bat build
```

Calling `.\build_jfg.bat` without an argument runs both steps. The script returns
the failing command's exit code. See `configure.log` and `build.log` for details.
The output is `build-cmake\JFGRecompiled.exe`, with SDL2 and DXC DLLs alongside it.
The internal CMake target is currently still named `BanjoRecompiled`.

Two local workarounds are currently active:

- SDK 22621 lacks `D3D12_HEAP_TYPE_GPU_UPLOAD`. The build script supplies its
  enum value; remove that flag after installing SDK 26100 or newer.
- Native `file_to_c.exe` can hang before producing output. The default CMake
  option `JFG_PYTHON_FILE_TO_C=ON` uses `tools/file_to_c.py` for all shader,
  icon and embedded mod arrays. The native helper can be selected with `OFF`.

## Run

```powershell
.\run_jfg.bat
```

This sets the working directory so the application finds `assets/` and the
controller database. Import the original US ROM through the launcher.

The prepared local diagnostic environment can instead be started with:

```powershell
.\run_jfg.bat test
```

Use `.\run_jfg.bat test start` to start the imported ROM automatically. The
executable also accepts `--start-game`. `--test-start-button` additionally sends
two 500 ms START presses after 12 and 22 seconds of controller polling for transition tests.

It uses `build-cmake\run-jfg`, containing a portable marker, copied assets and
ROM, and separate settings/saves. This directory is a local test artifact.

## Verified status

On 2026-10-12, the Windows Release build and automatic game startup work. The new
F3DJFG RT64 adapter recognizes the verified microcode and displays game graphics,
including PRESS START. Rendering is still distorted; correct logo/title rendering
and gameplay are not verified. JFG's audio microcode is now statically translated
and builds successfully; runtime sound quality still needs verification.

To regenerate audio in WSL, run `bash tools/regenerate_audio_rsp.sh` from this
project. It uses `~/N64Recomp/build/RSPRecomp`, or the `RSP_RECOMP` override, and
the unmodified US ROM in the adjacent decomp workspace.

Regeneration now runs `recomp_anim.py` and `recomp_fpu.py` after N64Recomp. They
replace the three animation stubs with static native translations and fix the
FPU mode of 23 Rare assembly routines. Preserve the local RT64 and nested runtime
submodule changes. Detailed results and remaining issues are in the decomp
workspace's `docs/RECOMP.md`.
