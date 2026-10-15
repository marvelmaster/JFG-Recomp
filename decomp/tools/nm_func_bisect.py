#!/usr/bin/env python3
"""Find the function inside one C file that breaks the NON_MATCHING ROM (WSL, cwd ~/jfg_nm).

  python3 tools/nm_func_bisect.py <src/file.c> <other files kept on asm ...>

Only functions in a subset use their `#ifdef NON_MATCHING` C; the others are switched to the
asm fallback by rewriting that line to `#if 0` in the ~/jfg_nm working copy (restored at the
end). Uses tools/nm_test.sh (mainGameMode must reach 6).
"""
import re
import subprocess
import sys
from pathlib import Path


def blocks(lines):
    out = []
    for i, l in enumerate(lines):
        if l.strip().startswith("#pragma GLOBAL_ASM") and i and lines[i - 1].strip() == "#else":
            # find the matching #ifdef NON_MATCHING above
            depth = 0
            for j in range(i - 2, -1, -1):
                s = lines[j].strip()
                if s.startswith("#endif"):
                    depth += 1
                elif s.startswith("#if"):
                    if depth == 0:
                        if re.match(r"#ifdef\s+NON_MATCHING", s):
                            out.append((j, re.search(r'/(\w+)\.s"', l)[1]))
                        break
                    depth -= 1
    return out


def main():
    path, others = sys.argv[1], sys.argv[2:]
    orig = Path(path).read_text()
    lines = orig.splitlines(keepends=True)
    bl = blocks(lines)
    print(f"{len(bl)} NON_MATCHING functions in {path}", flush=True)

    def test(keep, tag):
        new = list(lines)
        for j, name in bl:
            if name not in keep:
                new[j] = "#if 0 /* nm_func_bisect */\n"
        Path(path).write_text("".join(new))
        r = subprocess.run(["bash", "tools/nm_test.sh", tag] + others, capture_output=True, text=True).stdout.strip()
        print(f"  [{len(keep)} C] {r}", flush=True)
        return "result=GOOD" in r

    sus = [n for _, n in bl]
    fixed = set()  # functions that must stay C (other half of an interaction)
    found = []
    try:
        while sus:
            while len(sus) > 1:
                a, b = sus[: len(sus) // 2], sus[len(sus) // 2:]
                if not test(fixed | set(a), "fb"):
                    sus = a
                elif not test(fixed | set(b), "fb"):
                    sus = b
                else:
                    # interaction: one culprit in each half -> keep b in C, search a; then the other way
                    print("both halves fine -> interaction, searching first half with second half in C", flush=True)
                    fixed |= set(b)
                    sus = a
            found += sus
            if not fixed or len(found) > 1 or not test(set(found), "fb"):
                break
            # culprit of the first half found; now search the second half with it in C
            sus = sorted(fixed, key=[n for _, n in bl].index)
            fixed = set(found)
    finally:
        Path(path).write_text(orig)
    print("SUSPECT FUNCTIONS:", " ".join(found))


if __name__ == "__main__":
    main()
