#!/usr/bin/env python3
"""Windows-native syntax/type check for decompiled C (no IDO/WSL needed).

Uses clang from the `ziglang` pip package targeting MIPS big-endian with the
same include paths and defines as the Makefile's CC_CHECK. NON_MATCHING is
defined so that `#ifdef NON_MATCHING` C bodies are checked too.

Usage: .venv/Scripts/python.exe tools/check_c.py src/foo.c [src/bar.c ...]
       .venv/Scripts/python.exe tools/check_c.py --all
       --asm  checks WITHOUT NON_MATCHING (the original asm-fallback build)
Exit code 0 = all files OK.
"""
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
INCLUDES = [".", "include", "include/libc", "include/PR", "include/sys", "assets", "src",
            "libultra", "libultra/src/gu", "libultra/src/libc", "libultra/src/io",
            "libultra/src/sc", "libultra/src/os", "src/hasm/ido"]
DEFINES = ["_FINALROM", "NDEBUG", "TARGET_N64", "F3DDKR_GBI", "VERSION_us", "_MIPS_SZLONG=32",
           "RAREDIFFS", "JFGDIFFS", "_LANGUAGE_C", "NON_MATCHING", "BUILD_VERSION=6",
           "__sgi", "_MIPS_SIM=1"]
FLAGS = ["-cc1", "-triple", "mips-unknown-unknown", "-fsyntax-only", "-std=gnu89",
         "-fno-builtin", "-fno-signed-char", "-nostdsysteminc", "-w",
         "-Werror=implicit-function-declaration", "-Werror=incompatible-pointer-types",
         "-Wno-unknown-pragmas", "-Wno-error=int-conversion", "-ferror-limit", "30"]


def check(path, nonmatching=True):
    cmd = [sys.executable, "-m", "ziglang", "clang", *FLAGS]
    cmd += [f"-I{i}" for i in INCLUDES if (ROOT / i).is_dir()]
    cmd += [f"-D{d}" for d in DEFINES if nonmatching or d != "NON_MATCHING"]
    path = Path(path).resolve()
    cmd.append(str(path.relative_to(ROOT)) if path.is_relative_to(ROOT) else str(path))
    result = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    return result.returncode, (result.stdout + result.stderr).strip()


def main():
    args = sys.argv[1:]
    asm_only = "--asm" in args  # check the original (asm fallback) configuration
    args = [a for a in args if a != "--asm"]
    if args == ["--all"]:
        files = sorted(p for p in (ROOT / "src").rglob("*.c") if "kiosk" not in str(p))
    else:
        files = [Path(a) for a in args]
    failed = 0
    for f in files:
        rc, out = check(f, nonmatching=not asm_only)
        if rc:
            failed += 1
            print(f"FAIL {f}\n{out}\n")
        else:
            print(f"OK   {f}")
    print(f"\n{len(files) - failed}/{len(files)} OK")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
