# Resolve JFGRecompiled+offset frames of a stackdump.exe output with the linker map: resolve.py dump.txt [map]
import sys, re, bisect
mp = sys.argv[2] if len(sys.argv) > 2 else __import__("os").path.join(__import__("os").path.dirname(__file__), "..", "..", "build-cmake", "JFGRecompiled.map")
syms = []
for line in open(mp, errors="replace"):
    m = re.match(r"\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{16})\s", line)
    if m:
        syms.append((int(m.group(2), 16) - 0x140000000, m.group(1)))
syms.sort()
keys = [s[0] for s in syms]
for line in open(sys.argv[1], errors="replace"):
    m = re.match(r"\s+JFGRecompiled\+([0-9A-F]+)", line)
    if m:
        off = int(m.group(1), 16)
        i = bisect.bisect_right(keys, off) - 1
        name = syms[i][1] if i >= 0 else "?"
        print("  exe+%X %s+%X" % (off, name[:120], off - keys[i]))
    else:
        print(line.rstrip())
