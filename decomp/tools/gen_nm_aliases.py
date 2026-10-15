#!/usr/bin/env python3
"""Generate linker aliases for symbols the NON_MATCHING C references by a different name.

Run in WSL:  python3 tools/gen_nm_aliases.py <matching elf> <measure build dir> <out.txt>

- Collects every undefined symbol of the measure-build objects (mips-linux-gnu-nm -u).
- For each one that the matching ELF does not define, looks for a matching-ELF symbol
  at the address encoded in the name:
    D_800A2ED0           -> symbol at 0x800A2ED0 (main RAM)
    D_overlay_N_XXXXXXXX -> symbol at 0xXXXXXXXX (overlay N, vram N<<20 | offset)
    func_XXXXXXXX        -> same rule
- Writes `name = target;` lines. Names that cannot be resolved are written as comments
  (`/* UNRESOLVED name */`) so they can be fixed by hand.
"""
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

NM = "mips-linux-gnu-nm"


ABS = set()  # absolute symbols from the undefined_syms linker files; also present in the NM link


def nm_defined(elf):
    by_addr = defaultdict(list)
    names = set()
    for line in subprocess.run([NM, elf], capture_output=True, text=True).stdout.splitlines():
        parts = line.split()
        if len(parts) != 3:
            continue
        addr, typ, name = parts
        names.add(name)
        if typ in "aA":
            ABS.add(name)
        if name.endswith(".NON_MATCHING") or typ in "aA":
            continue
        by_addr[int(addr, 16)].append(name)
    return by_addr, names


def defined_in(build):
    objs = [str(p) for p in Path(build).rglob("*.o")]
    out = set()
    for i in range(0, len(objs), 200):
        r = subprocess.run([NM, "--defined-only"] + objs[i:i + 200], capture_output=True, text=True).stdout
        for line in r.splitlines():
            parts = line.split()
            if len(parts) == 3:
                out.add(parts[2])
    return out


def undefined(build):
    objs = [str(p) for p in Path(build).rglob("*.o")]
    out = set()
    for i in range(0, len(objs), 200):
        r = subprocess.run([NM, "-u"] + objs[i:i + 200], capture_output=True, text=True).stdout
        for line in r.splitlines():
            parts = line.split()
            if len(parts) == 2 and parts[0] == "U":
                out.add(parts[1])
    return out


ADDR = re.compile(r"^(?:D|func|jtbl)_(?:overlay_\d+_)?([0-9A-Fa-f]{8})(?:_[0-9A-Fa-f]+)?$")


def overlay_layout(by_addr):
    """overlay n -> (text_start, data_end_runtime, bss_vram) from the matching ELF section symbols."""
    sym = {}
    for a, ns in by_addr.items():
        for n in ns:
            sym[n] = a
    lay = {}
    for n in range(1, 200):
        t = sym.get(f"overlay_{n}_TEXT_START")
        if t is None:
            continue
        ts = sym[f"overlay_{n}_TEXT_SIZE"] if f"overlay_{n}_TEXT_SIZE" in sym else None
        lay[n] = sym
    return sym


def nearest(by_addr_sorted, keys, addr, lo, hi):
    """closest real symbol at or below addr inside [lo, hi)."""
    import bisect
    i = bisect.bisect_right(keys, addr) - 1
    while i >= 0 and keys[i] >= lo:
        k = keys[i]
        good = [n for n in by_addr_sorted[k] if not n.startswith("_binary_") and not n.startswith("overlay_")]
        if good and k < hi:
            return k, good[0]
        i -= 1
    return None


def main():
    elf, build, out = sys.argv[1:4]
    by_addr, names = nm_defined(elf)
    have = defined_in(build)
    # only alias to symbols that exist in the measure build (or are linker-script symbols)
    for a in list(by_addr):
        by_addr[a] = [n for n in by_addr[a] if n in have or n.startswith("overlay_")]
        if not by_addr[a]:
            del by_addr[a]
    abs_syms = {}
    for line in subprocess.run([NM, elf], capture_output=True, text=True).stdout.splitlines():
        parts = line.split()
        if len(parts) == 3:
            abs_syms[parts[2]] = int(parts[0], 16)
    keys = sorted(by_addr)
    undef = undefined(build)
    lines, unresolved = [], []
    for name in sorted(undef):
        if name in ABS or (name in names and (name in have or name.startswith("overlay_"))):
            continue
        m = ADDR.match(name)
        target = None
        expr = None
        if m:
            addr = int(m[1], 16)
            if 0x80400000 <= addr < 0x8A000000:  # overlay address seen through KSEG0
                addr -= 0x80000000
            cands = [n for n in by_addr.get(addr, []) if not n.startswith("_binary_")]
            pref = [n for n in cands if n.split("_")[0] == name.split("_")[0]]
            target = (pref or cands or [None])[0]
            ov = re.match(r"D_overlay_(\d+)_", name)
            if target is None and not ov and addr < 0x0A000000:
                ov = (None, str(addr >> 20))
            if target is None and ov:
                n = int(ov[1])
                base = n << 20
                tsz = abs_syms.get(f"overlay_{n}_TEXT_SIZE", 0)
                dsz = abs_syms.get(f"overlay_{n}_DATA_SIZE", 0)
                rel_sz = abs_syms.get(f"_binary_assets_overlays_o{n}_overlay_{n}_reloc_bin_size", 0)
                runtime_bss = base + tsz + dsz - rel_sz  # reloc table is not part of the runtime image
                bss_start = abs_syms.get(f"overlay_{n}_BSS_START")
                if addr >= runtime_bss and bss_start is not None:
                    expr = f"overlay_{n}_BSS_START + 0x{addr - runtime_bss:X}"
                else:
                    near = nearest(by_addr, keys, addr, base, base + 0x100000)
                    if near:
                        expr = f"{near[1]} + 0x{addr - near[0]:X}"
            elif target is None and addr >= 0x80000000:
                near = nearest(by_addr, keys, addr, addr - 0x1000, 0x80400000)
                if near:
                    expr = f"{near[1]} + 0x{addr - near[0]:X}"
        if target and target != name:
            lines.append(f"{name} = {target};")
        elif expr:
            lines.append(f"{name} = {expr};")
        else:
            unresolved.append(name)
    with open(out, "w") as f:
        f.write("/* generated by tools/gen_nm_aliases.py - do not edit */\n")
        f.write("\n".join(lines) + "\n")
        for n in unresolved:
            f.write(f"/* UNRESOLVED {n} */\n")
    print(f"{len(lines)} aliases, {len(unresolved)} unresolved -> {out}")


if __name__ == "__main__":
    main()
