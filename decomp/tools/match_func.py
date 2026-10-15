#!/usr/bin/env python3
"""Check whether one decompiled function matches the original (runs the build in WSL).

Usage (from Windows, project root):
  .venv/Scripts/python.exe tools/match_func.py src/overlays/o3/overlay_3.c SquadronControl
  .venv/Scripts/python.exe tools/match_func.py <file> <func> --opt "-O2 -g3"   (try other IDO flags)

What it does:
  1. copies the C file into ~/jfg_nm (LF line endings),
  2. compiles that one object in measure mode (NON_MATCHING C, matching flags),
  3. compares the function with the matching build in ~/jfg (original asm) and
     prints MATCH or a side-by-side diff of the differing instructions.
Requires: ~/jfg built once (`make`), ~/jfg_nm prepared (see docs/PROJECT_STATUS.md).
"""
import subprocess
import sys

DIFF = r'''
import sys
sys.path.insert(0, "/home/$USER/jfg/tools")
import match_report as m, rabbitizer
from pathlib import Path
obj, func = sys.argv[1], sys.argv[2]
a = m.load(Path("/home/$USER/jfg/build") / obj).get(func)
b = m.load(Path("/home/$USER/jfg_nm/build") / obj).get(func)
if a is None or b is None:
    print("FUNCTION NOT FOUND in", "original" if a is None else "decomp", "object"); sys.exit(2)
if m.same(a, b):
    print("MATCH"); sys.exit(0)
wa, ra = a; wb, rb = b
print(f"NO MATCH: original {len(wa)} instructions, decomp {len(wb)} instructions")
print(f"{'#':>4}  {'original':40} | decomp")
shown = 0
for i in range(max(len(wa), len(wb))):
    x = wa[i] if i < len(wa) else None
    y = wb[i] if i < len(wb) else None
    if x == y:
        continue
    if x is not None and y is not None and (i in ra or i in rb) and (x >> 26) == (y >> 26):
        continue
    dx = rabbitizer.Instruction(x).disassemble() if x is not None else "-"
    dy = rabbitizer.Instruction(y).disassemble() if y is not None else "-"
    print(f"{i:4}  {dx:40} | {dy}")
    shown += 1
    if shown >= 40:
        print("... (more differences)"); break
sys.exit(1)
'''


def main():
    args = sys.argv[1:]
    opt = ""
    if "--opt" in args:
        i = args.index("--opt")
        opt = f"OPT_FLAGS='{args[i + 1]}'"
        del args[i:i + 2]
    if len(args) != 2:
        print(__doc__)
        sys.exit(2)
    src, func = args[0].replace("\\", "/"), args[1]
    obj = src + ".o"
    script = (
        "set -e; "
        f"cp /mnt/f/SelfmadeTools/JFG_Decomp/{src} ~/jfg_nm/{src}; sed -i 's/\\r$//' ~/jfg_nm/{src}; "
        f"cd ~/jfg_nm && rm -f build/{obj}; make -s DECOMP_MEASURE=1 CC_CHECK=true {opt} build/{obj} > /tmp/mf_$$.log 2>&1 "
        f"|| {{ grep -E 'cfe: Error|Error|error' /tmp/mf_$$.log | head -20; echo COMPILE FAILED; exit 3; }}; "
        f"~/jfg/.venv/bin/python3 - {obj} {func} <<'PYEOF'\n{DIFF}\nPYEOF"
    )
    r = subprocess.run(["wsl", "-d", "Ubuntu", "--", "bash", "-c", script])
    sys.exit(r.returncode)


if __name__ == "__main__":
    main()
