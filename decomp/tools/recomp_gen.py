#!/usr/bin/env python3
"""Generate the N64Recomp inputs for Jet Force Gemini (US) from the ROM's own overlay tables.

  python3 tools/recomp_gen.py <elf with section-relative symbols> <baserom.z64> <out dir>

Writes <out>/jfg.us.syms.toml (sections, functions, relocs) and <out>/jfg.us.recomp.z64
(a copy of the ROM that is only used as *recompiler input*: every Rare relocation is applied
statically with each overlay based at its link address N << 20).

JFG overlays are loaded anywhere in RAM by src/runLink.c and patched from a per-overlay table
(see docs/NONMATCHING_BUILD.md "Step 3 design"). Mapping to N64Recomp:
  * reference to the main code/data/bss (ORT owner 0/FFD/FFE/FFF): constant, patched statically
  * reference inside the same overlay (type 1/2): N64Recomp reloc -> RELOC_HI16/LO16 at runtime
  * call into another overlay (type 0, jal): `jal TrapDanglingJump` - exactly what the game does
    while the target is not loaded; the trap loads the overlay and jumps there (LOOKUP_FUNC)
  * data reference to another overlay (hi/lo): not expressible in a symbol file; patched to
    gUnresolvedSymbolAddr like the game does for an unloaded overlay, and counted in the report
Data-section patches are applied to the input ROM too (jump tables must hold link addresses).
"""
import re
import struct
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

OVERLAY_TABLE = 0x1ED2780
OVERLAY_DATA = 0x1ED3B20
ORT = 0x1ED0270
MAIN_CODE = 0x80000450
MAIN_DATA = 0x800A0660
MAIN_BSS = 0x800B0B50
# Overlay code calls the main code with plain `jal 0x800xxxxx` (no relocation: a jal only keeps the low 28
# bits and the overlays always run in KSEG0). N64Recomp resolves a jal inside the section's own 256 MB region,
# so the overlays get recompile-time addresses in KSEG0 too: 0x81000000 + (N << 20), clear of main (< 0x80106000).
OVL_BASE = 0x81000000


def sx16(v):
    return v - 0x10000 if v & 0x8000 else v


def elf_symbols(elf):
    secs = {}
    out = subprocess.run(["mips-linux-gnu-readelf", "-SW", elf], capture_output=True, text=True).stdout
    for m in re.finditer(r"\[\s*(\d+)\]\s+(\S+)\s+(PROGBITS|NOBITS)\s+([0-9a-f]{8})\s+([0-9a-f]+)\s+([0-9a-f]+)", out):
        secs[int(m[1])] = (m[2], int(m[4], 16), int(m[6], 16))
    funcs = defaultdict(dict)   # section name -> vram -> (name, size)
    syms = {}
    out = subprocess.run(["mips-linux-gnu-readelf", "-sW", elf], capture_output=True, text=True).stdout
    for line in out.splitlines():
        p = line.split()
        if len(p) < 8 or not p[0].endswith(":"):
            continue
        try:
            val, size = int(p[1], 16), int(p[2], 0)
        except ValueError:
            continue
        typ, ndx, name = p[3], p[6], p[7]
        if typ in ("FUNC", "OBJECT", "NOTYPE") and not name.startswith("."):
            syms.setdefault(name, val)
        if typ == "FUNC" and ndx.isdigit() and int(ndx) in secs:
            sec = secs[int(ndx)][0]
            old = funcs[sec].get(val)
            # prefer real names over splat placeholders when two symbols share an address
            better_name = old is not None and old[0].startswith("func_") and not name.startswith("func_")
            # aliases (nonmatching_manual: X_1arg = X) have size 0: a sized symbol always wins
            if old is None or (size and not old[1]) or (better_name and (size or not old[1])):
                funcs[sec][val] = (name, size)
    return secs, funcs, syms


def infer_function_sizes(funcs, text_ranges):
    """IDO leaves local FUNC symbols unsized; retain these thread/callback entries.

    Interior aliases (Sinf = Cosf + 4, etc.) end with their containing function.
    Separate unsized functions end at the next entry or the actual text boundary,
    never extending into an overlay's data/relocation table.
    """
    inferred = 0
    for sec, fs in funcs.items():
        if sec not in text_ranges:
            continue
        text_start, text_end = text_ranges[sec]
        entries = sorted(v for v in fs if text_start <= v < text_end)
        spans = sorted((v, min(v + size, text_end)) for v, (_, size) in fs.items() if size)
        for index, v in enumerate(entries):
            name, size = fs[v]
            if size:
                continue
            end = next((e for a, e in spans if a < v < e), None)
            if end is not None and name.startswith(("func_", "D_")):
                # Asm alabels can be typed FUNC too; these are internal branch
                # labels, not separately callable functions (notably animation asm).
                continue
            if end is None:
                end = entries[index + 1] if index + 1 < len(entries) else text_end
            if end > v:
                fs[v] = (name, end - v)
                inferred += 1
    return inferred


def main():
    elf, rom_path, out_dir = sys.argv[1], sys.argv[2], Path(sys.argv[3])
    rom = bytearray(Path(rom_path).read_bytes())
    orig = bytes(rom)
    secs, funcs, syms = elf_symbols(elf)
    text_ranges = {".main": (0x80000400, MAIN_DATA)}
    n_ovl = (OVERLAY_DATA - OVERLAY_TABLE) // 0x20
    for n in range(1, n_ovl + 1):
        text_size = struct.unpack_from(">I", orig, OVERLAY_TABLE + (n - 1) * 0x20 + 8)[0]
        text_ranges[f".overlay_{n}"] = (n << 20, (n << 20) + text_size)
    inferred_sizes = infer_function_sizes(funcs, text_ranges)
    trap = syms["TrapDanglingJump"]
    unresolved = syms.get("gUnresolvedSymbolAddr")
    by_name = {v[0]: v for v in secs.values()}

    def w(off):
        return struct.unpack_from(">I", orig, off)[0]

    def put(off, val):
        struct.pack_into(">I", rom, off, val & 0xFFFFFFFF)

    def ort(index):
        e = w(ORT + index * 4)
        owner, off = e >> 20, e & 0xFFFFF
        if owner in (0xFFD, 0xFFE):
            return 0, MAIN_DATA + off
        if owner == 0xFFF:
            return 0, MAIN_BSS + off
        if owner == 0:
            return 0, MAIN_CODE + off
        return owner, (owner << 20) | off

    stats = defaultdict(int)
    stats["inferred zero-size functions"] = inferred_sizes
    # N64Recomp does not maintain $ra, but TrapDanglingJump finds its call site (and from it the target) through
    # ra - 8. Every `jal TrapDanglingJump` therefore gets a hook that loads the right return address first.
    hooks = []

    def func_at(fs, addr):
        return next((n for v, (n, s) in fs.items() if s and v <= addr < v + s and not n.startswith("D_")), None)

    main_name, main_vram, main_size = by_name[".main"]
    jal_trap = 0x0C000000 | ((trap >> 2) & 0x3FFFFFF)
    for v, (fname, fsize) in sorted(funcs[".main"].items()):
        for a in range(v, v + fsize, 4):
            # (__rmon*: libultra debug monitor, dropped by N64Recomp; the word match there is coincidental)
            if w(0x1000 + a - 0x80000400) == jal_trap and func_at(funcs[".main"], a) == fname and not fname.startswith("__rmon"):
                hooks.append((fname, a, f"ctx->r31 = (gpr)(int32_t)0x{a + 8:08X};"))
    stats["main -> overlay trap calls"] = len(hooks)

    toml = []

    # main code: one static section
    name, vram, size = by_name[".main"]
    toml.append(section_toml(".main", 0x1000 + (vram - 0x80000400), vram, size, funcs[".main"], None))

    for n in range(1, n_ovl + 1):
        _, rel, text, data, bss, size1, size2, _, _ = struct.unpack_from(">iiiiiHHii", orig, OVERLAY_TABLE + (n - 1) * 0x20)
        sec = f".overlay_{n}"
        if text <= 0 or sec not in by_name:
            continue
        base_rom = OVERLAY_DATA + rel
        link = n << 20            # address in the decomp ELF / splat symbols
        base = OVL_BASE + link    # address used for recompilation (see OVL_BASE)
        start = base_rom + text + data
        entries = [struct.unpack_from(">II", orig, o) for o in range(start, start + size1 + size2, 8)]
        relocs = []
        fn = {v - link + base: f for v, f in funcs[sec].items()}
        sec_index = len(toml)     # main is section 0, overlays follow in this order

        def resolve(sym, rtype, off):
            """-> (owner, address) ; owner None = own overlay"""
            if rtype in (0, 3):
                owner, addr = ort(sym)
                if owner == n:
                    return None, addr - link + base
                return owner, addr
            if rtype == 1:
                return None, base + sym
            if rtype == 2:
                return None, base + ((w(base_rom + off) & 0x3FFFFFF) << 2)
            return "?", 0

        i = 0
        while i < len(entries):
            sym, info = entries[i]
            rtype, flag, off = info & 15, (info >> 4) & 15, info >> 8
            i += 1
            in_text = off < text
            if rtype == 3:               # patch location is relative to the data section
                off += text
                in_text = False
            owner, tgt = resolve(sym, rtype, off)
            if owner == "?":
                stats["unknown reloc type"] += 1
                continue
            loc = base_rom + off
            word = w(loc)
            if flag == 4:                # jal / j
                if owner is None:
                    put(loc, (word & 0xFC000000) | ((tgt >> 2) & 0x3FFFFFF))
                    if in_text:
                        relocs.append((base + off, tgt, "R_MIPS_26"))
                elif owner == 0:
                    put(loc, (word & 0xFC000000) | ((tgt >> 2) & 0x3FFFFFF))
                else:
                    put(loc, (word & 0xFC000000) | ((trap >> 2) & 0x3FFFFFF))
                    stats["cross-overlay calls -> TrapDanglingJump"] += 1
                    owner_fn = func_at(fn, base + off)
                    if owner_fn:
                        hooks.append((owner_fn, base + off, f"ctx->r31 = (gpr)(int32_t)(section_addresses[{sec_index}] + 0x{off + 8:X});"))
                    else:
                        stats["trap call outside any function"] += 1
            elif flag == 5 and i < len(entries):
                lo_off = entries[i][1] >> 8
                i += 1
                lo_loc = base_rom + lo_off
                lo_word = w(lo_loc)
                # 32-bit wrap is intended: e.g. overlay 1 folds K0_TO_PHYS (+0x80000000) into the addend
                addr = (tgt + ((word & 0xFFFF) << 16) + sx16(lo_word & 0xFFFF)) & 0xFFFFFFFF
                if owner not in (None, 0):
                    stats["cross-overlay data refs (unresolved)"] += 1
                    addr = unresolved if unresolved else 0
                put(loc, (word & 0xFFFF0000) | (((addr >> 16) + (1 if addr & 0x8000 else 0)) & 0xFFFF))
                put(lo_loc, (lo_word & 0xFFFF0000) | (addr & 0xFFFF))
                if owner is None and in_text:
                    relocs.append((base + off, addr, "R_MIPS_HI16"))
                    relocs.append((base + lo_off, addr, "R_MIPS_LO16"))
            elif flag == 6:
                addr = (tgt + (word & 0xFFFF)) & 0xFFFFFFFF
                if owner not in (None, 0):
                    stats["cross-overlay data refs (unresolved)"] += 1
                    addr = unresolved if unresolved else 0
                put(loc, (word & 0xFFFF0000) | (addr & 0xFFFF))
                if owner is None and in_text:
                    relocs.append((base + off, addr, "R_MIPS_LO16"))
                    stats["orphan LO16 relocs"] += 1
            elif flag == 2:              # 32-bit word (jump tables, pointers)
                addr = (tgt + (word if rtype == 1 else 0)) & 0xFFFFFFFF
                if owner not in (None, 0):
                    addr = trap
                put(loc, addr)
            else:
                stats[f"unhandled flag {flag}"] += 1
        stats["relocs"] += len(relocs)
        stats["overlays"] += 1
        fn = {v - link + base: f for v, f in funcs[sec].items()}
        toml.append(section_toml(sec, base_rom, base, text + data, fn, sorted(relocs)))

    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "jfg.us.syms.toml").write_text("\n".join(toml))
    (out_dir / "jfg.us.recomp.z64").write_bytes(rom)
    (out_dir / "jfg.us.hooks.toml").write_text("".join(
        f'\n[[patches.hook]]\nfunc = "{f}"\nbefore_vram = 0x{a:08X}\ntext = "{t}"\n' for f, a, t in hooks))
    stats["ra hooks"] = len(hooks)
    print(f"functions: main {len(funcs['.main'])}, overlays {sum(len(v) for k, v in funcs.items() if k.startswith('.overlay_'))}")
    for k, v in sorted(stats.items()):
        print(f"{k}: {v}")


def section_toml(name, rom, vram, size, funcs, relocs):
    out = ["[[section]]", f'name = "{name}"', f"rom = 0x{rom:08X}", f"vram = 0x{vram:08X}", f"size = 0x{size:X}", "", "functions = ["]
    for v in sorted(funcs):
        fn, sz = funcs[v]
        if sz:
            out.append(f'    {{ name = "{fn}", vram = 0x{v:08X}, size = 0x{sz:X} }},')
    out.append("]")
    if relocs is not None:
        out += ["", "relocs = ["]
        out += [f'    {{ type = "{t}", vram = 0x{a:08X}, target_vram = 0x{tv:08X} }},' for a, tv, t in relocs]
        out.append("]")
    out.append("")
    return "\n".join(out)


if __name__ == "__main__":
    main()
