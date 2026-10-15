#!/usr/bin/env python3
"""Make the absolute linker-script symbols shift-safe for a NON_MATCHING build.

The splat symbol files (undefined_syms*.txt, undefined_funcs_auto.*.txt) pin names to fixed
addresses (`name = 0x800AEE92;`). In ld such an assignment even overrides an object's own
definition, and addresses inside main code/data/bss stay fixed when code/data move.
For every assignment whose address lies inside the main segment this script writes instead
  - nothing, if an object defines the name globally (the object wins), or
  - `name = <nearest real symbol> + 0xOFF;` (relative to a symbol at or below the address in
    the matching ELF that also exists in the NM objects).
Other addresses (hardware registers, overlays, ROM offsets) are kept as they are.

Usage (WSL): nm_filter_syms.py <matching.elf> <build dir> <out dir> <in.txt> [...]
"""
import bisect
import re
import subprocess
import sys
from pathlib import Path

MAIN_LO, MAIN_HI = 0x80000400, 0x80400000


def nm(args):
    return subprocess.run(["mips-linux-gnu-nm"] + args, capture_output=True, text=True).stdout


def main():
    elf, build, outdir = sys.argv[1:4]
    objs = [str(p) for p in Path(build).rglob("*.o")]
    glob_def = set()
    for i in range(0, len(objs), 200):
        for line in nm(["--defined-only"] + objs[i:i + 200]).splitlines():
            p = line.split()
            if len(p) == 3 and p[1].isupper() and p[1] not in "A":
                glob_def.add(p[2])
    anchors = []
    for line in nm(["-n", elf]).splitlines():
        p = line.split()
        if len(p) == 3 and p[1] not in "aA" and p[2] in glob_def and not p[2].endswith(".NON_MATCHING"):
            a = int(p[0], 16)
            if MAIN_LO <= a < MAIN_HI:
                anchors.append((a, p[2]))
    anchors.sort()
    # ROM offsets that coincide with a segment start -> express them through that segment symbol
    rom_seg = {}
    for line in nm(["-n", elf]).splitlines():
        p = line.split()
        if len(p) == 3 and p[2].endswith("_ROM_START") and not p[2].startswith("overlayCode"):
            rom_seg.setdefault(int(p[0], 16), p[2])
    keys = [a for a, _ in anchors]
    Path(outdir).mkdir(parents=True, exist_ok=True)
    for src in sys.argv[4:]:
        kept = dropped = rel = 0
        lines = []
        for line in open(src):
            m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
            if not m:
                lines.append(line)
                continue
            name, addr = m[1], int(m[2], 16)
            if name in glob_def:
                dropped += 1
                lines.append(f"/* defined by an object: {line.strip()} */\n")
                continue
            if addr < 0x04000000 and addr in rom_seg and addr > 0x1000:
                lines.append(f"{name} = {rom_seg[addr]}; /* was 0x{addr:08X} (ROM) */\n")
                rel += 1
                continue
            if MAIN_LO <= addr < MAIN_HI:
                i = bisect.bisect_right(keys, addr) - 1
                if i >= 0 and addr - keys[i] < 0x10000:
                    base, bname = anchors[i]
                    lines.append(f"{name} = {bname} + 0x{addr - base:X}; /* was 0x{addr:08X} */\n")
                    rel += 1
                    continue
            kept += 1
            lines.append(line)
        out = Path(outdir) / Path(src).name
        out.write_text("".join(lines))
        print(f"{src}: kept {kept}, object-defined {dropped}, made relative {rel} -> {out}")


if __name__ == "__main__":
    main()
