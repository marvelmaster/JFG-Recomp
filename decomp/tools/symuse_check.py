#!/usr/bin/env python3
"""Find globals whose C declaration kind (array vs pointer variable) differs from the original.

For every function present in both the matching build (original asm) and the measure build
(our C), collect the opcodes that carry the %lo(sym) relocation of each named symbol.
Report symbols that the original only *loads* (lw: a pointer variable) while our C takes
their *address* (addiu: declared as an array/struct) - e.g. `extern u32 RomTab[];` where the
game has `u32 *RomTab;`. That compiles silently and indexes the pointer's own storage.

Usage (WSL): python3 symuse_check.py <matching build> <measure build>
"""
import struct
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import match_report as m  # noqa: E402

OPS = {0x09: "addiu", 0x23: "lw", 0x21: "lh", 0x25: "lhu", 0x20: "lb", 0x24: "lbu",
       0x2B: "sw", 0x29: "sh", 0x28: "sb", 0x31: "lwc1", 0x39: "swc1", 0x35: "ldc1", 0x3D: "sdc1"}


def uses(path):
    data = path.read_bytes()
    secs = m.sections(data)
    ti = next((i for i, s in enumerate(secs) if s[0] == ".text"), None)
    if ti is None:
        return {}
    text_off = secs[ti][5]
    symtab = next(s for s in secs if s[2] == 2)
    strsec = secs[symtab[7]]
    syms, funcs = [], []
    for off in range(symtab[5], symtab[5] + symtab[6], 16):
        st_name, value, size, info, other, shndx = struct.unpack_from(">IIIBBH", data, off)
        n0 = strsec[5] + st_name
        nm = data[n0:data.index(b"\0", n0)].decode()
        syms.append(nm)
        if shndx == ti and (info & 0xF) == 2:
            funcs.append((value, size, nm))
    out = defaultdict(lambda: defaultdict(set))
    for s in secs:
        if s[2] in (9, 4) and s[8] == ti:
            ent = 8 if s[2] == 9 else 12
            for off in range(s[5], s[5] + s[6], ent):
                r_off, r_info = struct.unpack_from(">II", data, off)
                if (r_info & 0xFF) != 6:  # R_MIPS_LO16
                    continue
                sym = syms[r_info >> 8]
                if not sym or sym.startswith("."):
                    continue
                w, = struct.unpack_from(">I", data, text_off + r_off)
                op = OPS.get(w >> 26)
                fn = next((n for v, sz, n in funcs if v <= r_off < v + sz), None)
                if op and fn:
                    out[fn][sym].add(op)
    return out


def main():
    ref_dir, nm_dir = Path(sys.argv[1]), Path(sys.argv[2])
    hits = 0
    for ref in sorted(ref_dir.rglob("*.c.o")):
        nmo = nm_dir / ref.relative_to(ref_dir)
        if not nmo.exists():
            continue
        a, b = uses(ref), uses(nmo)
        for fn in sorted(b):
            if fn not in a:
                continue
            for sym, cops in sorted(b[fn].items()):
                oops = a[fn].get(sym)
                if not oops:
                    continue
                if "addiu" in cops and "addiu" not in oops and "lw" in oops:
                    hits += 1
                    print(f"{ref.relative_to(ref_dir)}: {fn}: {sym}: orig {sorted(oops)} vs C {sorted(cops)}")
    print(f"{hits} suspicious symbol uses")


if __name__ == "__main__":
    main()
