#!/usr/bin/env python3
"""addr2func.py <elf> <addr> [...]  -> containing function (mips-linux-gnu-nm based)"""
import bisect, subprocess, sys
out = subprocess.run(["mips-linux-gnu-nm", "-S", "-n", sys.argv[1]], capture_output=True, text=True).stdout
fs = []
for l in out.splitlines():
    p = l.split()
    if len(p) == 4 and p[2] in "Tt" and not p[3].endswith(".NON_MATCHING"):
        fs.append((int(p[0], 16), int(p[1], 16), p[3]))
fs.sort(); keys = [f[0] for f in fs]
for a in sys.argv[2:]:
    x = int(a, 16); i = bisect.bisect_right(keys, x) - 1
    f = fs[i] if i >= 0 else None
    print(f"{x:08X} {f[2]}+0x{x - f[0]:X}" if f and x < f[0] + max(f[1], 4) else f"{x:08X} ?")
