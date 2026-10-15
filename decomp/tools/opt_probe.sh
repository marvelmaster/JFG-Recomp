#!/bin/bash
# Probe which IDO optimisation flags make the decompiled C of src/libultra match.
# Run inside WSL: bash /mnt/f/SelfmadeTools/JFG_Decomp/tools/opt_probe.sh "-O2 -g3"
# Prints, per file, how many functions match with the given OPT_FLAGS.
set -u
FLAGS="$1"
cd ~/jfg_nm
objs=""
for f in src/libultra/*.c; do objs="$objs build/$f.o"; done
rm -f $objs
make -s -k DECOMP_MEASURE=1 CC_CHECK=true OPT_FLAGS="$FLAGS" $objs > /dev/null 2>&1
cd ~/jfg
.venv/bin/python3 - "$FLAGS" <<'EOF'
import sys, glob
sys.path.insert(0, "tools")
import match_report as m
from pathlib import Path
tot = ok = 0
for f in sorted(glob.glob("src/libultra/*.c")):
    o = "build/" + f + ".o"
    p = Path("/home/" + __import__("os").environ["USER"] + "/jfg_nm/" + o)
    if not p.exists() or not Path(o).exists():
        continue
    a, b = m.load(Path(o)), m.load(p)
    names = [k for k in b if k in a]
    if not names:
        continue
    good = [k for k in names if m.same(a[k], b[k])]
    tot += len(names); ok += len(good)
    print(f"{Path(f).name:28} {len(good)}/{len(names)}")
print(f"TOTAL {sys.argv[1]}: {ok}/{tot}")
EOF
