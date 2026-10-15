#!/usr/bin/env python3
"""Verify that the non-NON_MATCHING build is unchanged by the decomp work.

Preprocesses every US source file WITHOUT NON_MATCHING (so the asm fallbacks
are what gets built) and compares the set of active GLOBAL_ASM pragmas with
the same file from the original base project. Every original pragma must still
be active exactly once; new C may only appear inside NON_MATCHING blocks.

Usage: tools/check_integrity.py <path to original project root>
"""
import re
import subprocess
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).parent))
from check_c import INCLUDES  # noqa: E402

DEFINES = ["_LANGUAGE_C", "F3DDKR_GBI", "_MIPS_SZLONG=32", "BUILD_VERSION=6", "TARGET_N64",
           "_FINALROM", "NDEBUG", "VERSION_us", "__sgi", "RAREDIFFS", "JFGDIFFS"]
PRAGMA = re.compile(r'#pragma\s+GLOBAL_ASM\("([^"]+)"\)')


def active_pragmas(root, rel):
    cmd = [sys.executable, "-m", "ziglang", "clang", "-cc1", "-triple", "mips-unknown-unknown",
           "-E", "-P", "-nostdsysteminc", "-w"]
    cmd += [f"-I{i}" for i in INCLUDES if (root / i).is_dir()]
    cmd += [f"-D{d}" for d in DEFINES]
    cmd.append(rel)
    out = subprocess.run(cmd, cwd=root, capture_output=True, text=True).stdout
    return PRAGMA.findall(out)  # ordered: function order in the asm build matters


def main():
    orig = Path(sys.argv[1])
    bad = 0
    files = sorted(p for p in (ROOT / "src").rglob("*.c") if "kiosk" not in str(p))
    for p in files:
        rel = str(p.relative_to(ROOT)).replace("\\", "/")
        if not (orig / rel).exists():
            continue
        a, b = active_pragmas(orig, rel), active_pragmas(ROOT, rel)
        if a != b:
            bad += 1
            missing = Counter(a) - Counter(b)
            extra = Counter(b) - Counter(a)
            print(f"DIFF {rel}: missing {sorted(missing)[:5]} extra {sorted(extra)[:5]}")
    print(f"{len(files) - bad}/{len(files)} files keep the original asm build")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
