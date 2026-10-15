#!/usr/bin/env python3
"""Count decompilation progress for the US version.

A function counts as
  - "c"           : no GLOBAL_ASM pragma for it any more (plain C, original state)
  - "nonmatching" : GLOBAL_ASM pragma sits in the #else branch of #ifdef NON_MATCHING
  - "asm"         : bare GLOBAL_ASM pragma (not yet decompiled)

Usage: tools/decomp_progress.py [--files] [--json out.json]
"""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PRAGMA = re.compile(r'#pragma\s+GLOBAL_ASM\("([^"]+)"\)')


def scan_file(path):
    asm, nonmatching = [], []
    stack = []  # entries: [is_nonmatching_block, in_else]
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        s = line.strip()
        if s.startswith("#if"):
            stack.append([bool(re.match(r"#ifdef\s+NON_MATCHING\b|#if\s+defined\(NON_MATCHING\)", s)), False])
        elif s.startswith("#else") and stack:
            stack[-1][1] = True
        elif s.startswith("#endif") and stack:
            stack.pop()
        m = PRAGMA.search(s)
        if m and (ROOT / m[1]).exists():  # pragmas without asm are other-version only
            name = Path(m[1]).stem
            if any(nm and el for nm, el in stack):
                nonmatching.append(name)
            else:
                asm.append(name)
    return asm, nonmatching


def scan():
    result = {}
    for p in sorted((ROOT / "src").rglob("*.c")):
        if "kiosk" in str(p.relative_to(ROOT)):
            continue
        asm, nm = scan_file(p)
        if asm or nm:
            result[str(p.relative_to(ROOT)).replace("\\", "/")] = {"asm": asm, "nonmatching": nm}
    return result


def main():
    data = scan()
    asm = sum(len(v["asm"]) for v in data.values())
    nm = sum(len(v["nonmatching"]) for v in data.values())
    total = asm + nm
    if "--files" in sys.argv:
        for f, v in sorted(data.items(), key=lambda kv: -len(kv[1]["asm"])):
            if v["asm"]:
                print(f"{len(v['asm']):4d} asm  {len(v['nonmatching']):4d} nm  {f}")
    print(f"remaining asm: {asm}   decompiled (non-matching C): {nm}   "
          f"=> {100 * nm / total if total else 0:.1f}% of {total} formerly-asm functions")
    if "--json" in sys.argv:
        Path(sys.argv[sys.argv.index("--json") + 1]).write_text(json.dumps(data, indent=1))


if __name__ == "__main__":
    main()
