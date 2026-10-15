#!/usr/bin/env python3
"""Find a C file that breaks the NON_MATCHING ROM (run in WSL, project root = ~/jfg_nm).

  python3 tools/nm_bisect.py <candidates.txt> <always_asm.txt>

candidates.txt: files that are suspects (one per line). Only a subset of them is built from C
in each step; everything else (and all files in always_asm.txt) stays on asm.
A ROM is "good" when mainGameMode reaches the original value (6) within 6 seconds
(tools/nm_test.sh). Prints the culprit file(s).
"""
import subprocess
import sys


def files(p):
    return [l.strip() for l in open(p) if l.strip()]


def test(c_files, all_cands, always_asm, tag):
    asm = [f for f in all_cands if f not in c_files] + always_asm
    out = subprocess.run(["bash", "tools/nm_test.sh", tag] + asm, capture_output=True, text=True).stdout.strip()
    print(f"  [{len(c_files)} C] {out}", flush=True)
    grew = "main_ROM_END=000b1750" not in out
    return "result=GOOD" in out, grew


def main():
    cands, always = files(sys.argv[1]), files(sys.argv[2])
    sus = list(cands)
    step = 0
    while len(sus) > 1:
        half = sus[: len(sus) // 2]
        step += 1
        print(f"step {step}: testing {len(half)} of {len(sus)} suspects in C", flush=True)
        good, grew = test(half, cands, always, f"bis{step}a")
        if grew:
            print("  WARNING: main code grew, ROM layout shifted - result unreliable", flush=True)
        if not good:
            sus = half
        else:
            rest = sus[len(sus) // 2:]
            good2, _ = test(rest, cands, always, f"bis{step}b")
            if good2:
                print("  both halves fine alone -> interaction between files; stopping", flush=True)
                break
            sus = rest
    print("SUSPECTS:", " ".join(sus))


if __name__ == "__main__":
    main()
