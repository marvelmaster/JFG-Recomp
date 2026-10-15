#!/usr/bin/env python3
"""Compare every function of a NON_MATCHING build against the matching build.

Both builds produce one .o per C file. In the matching build the function is the
original asm (via asm-processor); in the NON_MATCHING build it is our C compiled
with IDO. Words that carry a relocation in either object are compared by opcode
only (their immediate/target is filled in by the linker).

Usage: match_report.py <matching build dir> <non-matching build dir> [--json out.json]
"""
import json
import struct
import sys
from pathlib import Path


def sections(data):
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
    secs = []
    for i in range(shnum):
        secs.append(struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize))
    strtab = secs[shstrndx]
    def name(off):
        s = strtab[4] + off
        return data[s:data.index(b"\0", s)].decode()
    return [(name(s[0]),) + s for s in secs]


def load(path):
    data = path.read_bytes()
    secs = sections(data)
    text_idx = [i for i, s in enumerate(secs) if s[0] == ".text"]
    if not text_idx:
        return {}
    ti = text_idx[0]
    text = data[secs[ti][5]:secs[ti][5] + secs[ti][6]]
    # symbols
    funcs = {}
    for s in secs:
        if s[2] != 2:  # SHT_SYMTAB
            continue
        strsec = secs[s[7]]
        for off in range(s[5], s[5] + s[6], 16):
            st_name, value, size, info, other, shndx = struct.unpack_from(">IIIBBH", data, off)
            if shndx != ti or (info & 0xF) != 2:  # STT_FUNC
                continue
            n0 = strsec[5] + st_name
            nm = data[n0:data.index(b"\0", n0)].decode()
            funcs[nm] = (value, size)
    # relocated offsets in .text
    rel = set()
    for s in secs:
        if s[2] in (9, 4) and s[8] == ti:  # SHT_REL / SHT_RELA for .text
            ent = 8 if s[2] == 9 else 12
            for off in range(s[5], s[5] + s[6], ent):
                r_off, = struct.unpack_from(">I", data, off)
                rel.add(r_off)
    out = {}
    for nm, (value, size) in funcs.items():
        words = [struct.unpack_from(">I", text, value + i)[0] for i in range(0, size, 4)]
        relw = {(o - value) // 4 for o in rel if value <= o < value + size}
        out[nm] = (words, relw)
    return out


def same(a, b):
    wa, ra = a
    wb, rb = b
    # trailing nop padding differs between asm and C objects
    while wa and wa[-1] == 0:
        wa = wa[:-1]
    while wb and wb[-1] == 0:
        wb = wb[:-1]
    if len(wa) != len(wb):
        return False
    for i, (x, y) in enumerate(zip(wa, wb)):
        if x == y:
            continue
        if i in ra or i in rb:
            if (x >> 26) == (y >> 26) and ((x >> 26) in (2, 3) or (x >> 16) == (y >> 16)):
                continue
        return False
    return True


def main():
    ref_dir, nm_dir = Path(sys.argv[1]), Path(sys.argv[2])
    out_json = sys.argv[sys.argv.index("--json") + 1] if "--json" in sys.argv else None
    total = match = 0
    per_file = {}
    for ref in sorted(ref_dir.rglob("*.c.o")):
        nmo = nm_dir / ref.relative_to(ref_dir)
        if not nmo.exists():
            continue
        a, b = load(ref), load(nmo)
        res = {}
        for name in b:
            if name in a:
                res[name] = same(a[name], b[name])
        if res:
            per_file[str(ref.relative_to(ref_dir))] = res
            total += len(res)
            match += sum(res.values())
    print(f"{match}/{total} functions match ({100 * match / max(total, 1):.1f}%)")
    if out_json:
        Path(out_json).write_text(json.dumps(per_file, indent=1))


if __name__ == "__main__":
    main()
