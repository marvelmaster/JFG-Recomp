#!/usr/bin/env python3
"""Resolve overlay relocations statically (mirrors ProcessRelocationEntry in src/runLink.c).

In ROM every external call/global access inside an overlay is a placeholder
(`jal 0`, `lui 0`/`addiu 0x..`); the runtime linker patches them from the
overlay's relocation table. This module computes the real targets and can
rewrite a splat function .s so m2c sees real symbol names.

  overlay_relocs.py <overlay_num>            -> dump resolved patches
  overlay_relocs.py <overlay_num> <func.s>   -> print rewritten asm
"""
import re
import struct
import sys
from functools import lru_cache
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OVERLAY_TABLE = 0x1ED2780
OVERLAY_DATA = 0x1ED3B20
ORT = 0x1ED0270
MAIN_CODE = 0x80000450
MAIN_DATA = 0x800A0660
MAIN_BSS = 0x800B0B50


@lru_cache(None)
def rom():
    return (ROOT / "baseroms" / "baserom.us.z64").read_bytes()


@lru_cache(None)
def symbols():
    names = {}
    for f in ("symbol_addrs.us.txt", "overlays.us.txt"):
        for line in (ROOT / "ver" / "symbols" / f).read_text(encoding="utf-8").splitlines():
            m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
            if m:
                names.setdefault(int(m[2], 16), m[1])
    return names


def name_for(addr, is_func):
    sym = symbols().get(addr)
    if sym:
        return sym
    if addr < 0x80000000:  # overlay address: splat names them func_overlay_N_VRAM_ROM
        n = addr >> 20
        hits = list((ROOT / "asm").rglob(f"func_overlay_{n}_{addr:08X}_*.s")) if is_func else []
        if hits:
            return hits[0].stem
        return f"{'func' if is_func else 'D'}_overlay_{n}_{addr:08X}"
    return f"{'func' if is_func else 'D'}_{addr:08X}"


def ort_target(index):
    entry = struct.unpack_from(">I", rom(), ORT + index * 4)[0]
    owner, off = entry >> 20, entry & 0xFFFFF
    if owner in (0xFFD, 0xFFE):
        return MAIN_DATA + off
    if owner == 0xFFF:
        return MAIN_BSS + off
    if owner == 0:
        return MAIN_CODE + off
    return (owner << 20) | off


@lru_cache(None)
def resolve(n):
    """text offset -> (kind, target address); kind in jal/hi/lo/word."""
    r = rom()
    _, rel, text, data, _, size1, size2, _, _ = struct.unpack_from(">iiiiiHHii", r, OVERLAY_TABLE + (n - 1) * 0x20)
    base = OVERLAY_DATA + rel
    start = base + text + data
    entries = [struct.unpack_from(">II", r, o) for o in range(start, start + size1 + size2, 8)]

    def word(off):
        return struct.unpack_from(">I", r, base + off)[0]

    out = {}
    i = 0
    while i < len(entries):
        sym, info = entries[i]
        rtype, flags_hi, off = info & 15, (info >> 4) & 15, info >> 8
        i += 1
        if rtype == 3 or off >= text:  # data-section patch: not visible in function asm
            continue
        if rtype == 0:
            target = ort_target(sym)
        elif rtype == 1:
            target = (n << 20) + sym
        elif rtype == 2:
            target = (n << 20) + ((word(off) & 0x3FFFFFF) << 2)
        else:
            continue
        if flags_hi == 4:
            out[off] = ("jal", target)
        elif flags_hi == 5 and i < len(entries):
            lo_off = entries[i][1] >> 8
            i += 1
            lo = word(lo_off) & 0xFFFF
            addend = ((word(off) & 0xFFFF) << 16) + (lo - 0x10000 if lo & 0x8000 else lo)
            out[off] = ("hi", target + addend)
            out[lo_off] = ("lo", target + addend)
        elif flags_hi == 6:
            lo = word(off) & 0xFFFF
            out[off] = ("lo", target + (lo - 0x10000 if lo & 0x8000 else lo))
        elif flags_hi == 2:
            out[off] = ("word", target)
    return out


LINE = re.compile(r"^(\s*/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/\s+)(\S+)(\s+)(.*)$")


def rewrite(n, text_in):
    relocs = resolve(n)
    out = []
    for line in text_in.splitlines():
        m = LINE.match(line)
        if m:
            off = int(m[2], 16) - (n << 20)
            hit = relocs.get(off)
            if hit:
                kind, addr = hit
                op, args = m[3], m[5]
                if kind == "jal" and op in ("jal", "j"):
                    args = name_for(addr, True)
                elif kind == "hi" and op == "lui":
                    args = re.sub(r",\s*.*$", f", %hi({name_for(addr, False)})", args)
                elif kind == "lo":
                    sym = f"%lo({name_for(addr, False)})"
                    mem = re.search(r"\((\$\w+)\)\s*$", args)
                    if mem:  # load/store: "rt, <anything>($base)"
                        args = f"{args.split(',', 1)[0]}, {sym}({mem[1]})"
                    else:    # addiu/ori: "rt, rs, <imm>"
                        parts = args.split(",")
                        args = ", ".join(p.strip() for p in parts[:2]) + f", {sym}"
                line = f"{m[1]}{op}{m[4]}{args}"
        out.append(line)
    return add_jump_tables(n, out)


def add_jump_tables(n, lines):
    """Overlay jump tables live in the overlay's data, so splat does not emit
    them with the function. Rebuild them (entries are overlay-relative offsets
    patched by local relocations) so m2c can turn `jr $reg` into a switch."""
    r = rom()
    _, rel, text, _, _, _, _, _, _ = struct.unpack_from(">iiiiiHHii", r, OVERLAY_TABLE + (n - 1) * 0x20)
    base = OVERLAY_DATA + rel
    by_name = {name_for(a, False): a for k, a in resolve(n).values() if k == "lo"}
    tables = []
    for i, line in enumerate(lines):
        m = re.search(r"\blw\s+(\$\w+),\s*%lo\((\w+)\)\(\$\w+\)", line)
        if not m or m[2] not in by_name:
            continue
        reg, sym = m[1], m[2]
        follow = [l for l in lines[i + 1:i + 4] if not re.search(r"\bnop\b", l)]
        if not follow or not re.search(r"\bjr\s+\$" + reg[1:] + r"\b", follow[0]):
            continue
        addr = by_name[sym]
        count = None
        for back in reversed(lines[max(0, i - 12):i]):
            mm = re.search(r"sltiu\s+\$at,\s*\$\w+,\s*(0x[0-9A-Fa-f]+|\d+)", back)
            if mm:
                count = int(mm[1], 0)
                break
        entries = []
        off = addr - (n << 20)
        while (count is None or len(entries) < count) and len(entries) < 512:
            e = struct.unpack_from(">I", r, base + off + 4 * len(entries))[0]
            if not 0 < e < text:
                break
            entries.append((n << 20) + e)
        if entries:
            tables.append((sym, f"jtbl_{addr:08X}", entries))
    if not tables:
        return "\n".join(lines) + "\n"
    labels = {t: f".Ljt_{t:08X}" for _, _, entries in tables for t in entries}
    out = []
    for line in lines:
        m = LINE.match(line)
        if m and int(m[2], 16) in labels:
            out.append(f"{labels[int(m[2], 16)]}:")
        for sym, jt, _ in tables:
            line = line.replace(f"%hi({sym})", f"%hi({jt})").replace(f"%lo({sym})", f"%lo({jt})")
        out.append(line)
    out += ["", ".section .late_rodata"]
    for _, jt, entries in tables:
        out.append(f"dlabel {jt}")
        out += [f"    .word {labels[t]}" for t in entries]
    return "\n".join(out) + "\n"


def overlay_of(asm_path):
    m = re.search(r"[\\/]o(\d+)[\\/]", str(asm_path))
    return int(m[1]) if m and "overlays" in str(asm_path) else None


def main():
    n = int(sys.argv[1])
    if len(sys.argv) > 2:
        print(rewrite(n, Path(sys.argv[2]).read_text(encoding="utf-8")))
    else:
        for off, (kind, addr) in sorted(resolve(n).items()):
            print(f"{(n << 20) + off:08X} {kind:4s} {addr:08X} {name_for(addr, kind == 'jal')}")


if __name__ == "__main__":
    main()
