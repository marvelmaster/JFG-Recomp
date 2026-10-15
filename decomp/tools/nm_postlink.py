#!/usr/bin/env python3
"""Post-link fixups for a NON_MATCHING build where the main code comes from C (NM_SCOPE=main).

Run in WSL after `make DECOMP_MEASURE=1 NM_SCOPE=main` (link with --emit-relocs):
  python3 tools/nm_postlink.py <matching.elf> <nm.elf> <nm.z64> [manual_map.txt]

What it does (see docs/NONMATCHING_BUILD.md, step 2):
1. Main -> overlay calls: every `jal` in the main code whose target is an overlay symbol is
   turned back into `jal TrapDanglingJump`; a new mainRelocTable is written that maps the
   call site (text offset) to the ORT index of the target (overlays are unchanged, so the
   original ORT entry for that overlay address is reused).
2. ORT entries that point into the main code / data / bss (used by the overlays) are rewritten
   with the new offsets, matched by symbol name between the matching and the NM ELF.
3. Both tables are written into the ROM image at the position of the original assets, and the
   N64 CRC is fixed by the caller (tools/n64crc).
Everything it cannot map is printed as a problem list.
"""
import struct
import sys
from collections import defaultdict

R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 2, 4, 5, 6
CODE_BASE_SYM = "__CODE_SECTION_START"


class Elf:
    def __init__(self, path):
        d = self.d = open(path, "rb").read()
        (self.shoff,) = struct.unpack_from(">I", d, 0x20)
        (self.phoff,) = struct.unpack_from(">I", d, 0x1C)
        self.phentsize, self.phnum, shentsize, shnum, shstrndx = struct.unpack_from(">HHHHH", d, 0x2A)
        self.secs = [struct.unpack_from(">IIIIIIIIII", d, self.shoff + i * shentsize) for i in range(shnum)]
        strsec = self.secs[shstrndx]
        self.names = [self._str(strsec[4], s[0]) for s in self.secs]
        self.phdrs = [struct.unpack_from(">IIIIIIII", d, self.phoff + i * self.phentsize) for i in range(self.phnum)]
        self.syms, self.by_name, self.by_addr = [], {}, defaultdict(list)
        for i, s in enumerate(self.secs):
            if s[1] == 2:  # SYMTAB
                strtab = self.secs[s[6]][4]
                for off in range(s[4], s[4] + s[5], 16):
                    nm, val, size, info, other, shndx = struct.unpack_from(">IIIBBH", d, off)
                    name = self._str(strtab, nm)
                    self.syms.append((name, val, size, info, shndx))
                    if name and shndx != 0:
                        self.by_name.setdefault(name, val)
                        if shndx != 0xFFF1:
                            self.by_addr[val].append(name)

    def _str(self, base, off):
        e = self.d.index(b"\0", base + off)
        return self.d[base + off:e].decode("latin1")

    def relocs(self):
        """yield (r_offset vaddr, type, symbol index, target section name)"""
        for i, s in enumerate(self.secs):
            if s[1] == 9:  # SHT_REL
                target = self.names[s[7]]
                for off in range(s[4], s[4] + s[5], 8):
                    r_off, info = struct.unpack_from(">II", self.d, off)
                    yield r_off, info & 0xFF, info >> 8, target

    def lma(self, vaddr):
        for p in self.phdrs:
            ptype, poff, pv, pp, pfs, pms = p[:6]
            if ptype == 1 and pv <= vaddr < pv + pms:
                return pp + (vaddr - pv)
        return None


def is_overlay(addr):
    return 0x100000 <= addr < 0x0A000000


def main():
    m_elf, n_elf, rom_path = sys.argv[1:4]
    manual = {}
    if len(sys.argv) > 4:
        for line in open(sys.argv[4]):
            line = line.split("#")[0].split()
            if len(line) == 2:
                manual[line[0]] = int(line[1], 0)
    M, N = Elf(m_elf), Elf(n_elf)
    rom = bytearray(open(rom_path, "rb").read())
    orig_reloc = open("assets/mainRelocTable.bin", "rb").read()
    orig_ort = bytearray(open("assets/overlayRomTable.bin", "rb").read())
    problems = []

    ort_by_entry = {}
    for i in range(len(orig_ort) // 4):
        ort_by_entry.setdefault(struct.unpack_from(">I", orig_ort, i * 4)[0], i)

    code0 = N.by_name.get("__CODE_SECTION_START", 0x80000450)
    trap = N.by_name["TrapDanglingJump"]
    ntext_lo, ntext_hi = code0, N.by_name.get("__DATA_SECTION_START", 0x800A0660)

    # ---- 1. main -> overlay calls
    new_entries = []
    for r_off, rtype, symi, target in N.relocs():
        if not (ntext_lo <= r_off < ntext_hi):
            continue
        name, val, shndx = N.syms[symi][0], N.syms[symi][1], N.syms[symi][4]
        in_ovl = 0 < shndx < len(N.names) and N.names[shndx].startswith(".overlay_")
        if not (in_ovl and is_overlay(val)) and name not in manual:
            continue
        if rtype != R_MIPS_26:
            problems.append(f"main {r_off:08X}: reloc type {rtype} to overlay symbol {name}")
            continue
        idx = manual.get(name, ort_by_entry.get(val))
        if idx is None:
            problems.append(f"main {r_off:08X}: no ORT entry for {name} ({val:08X})")
            continue
        fo = N.lma(r_off)
        ins = struct.unpack_from(">I", rom, fo)[0]
        struct.pack_into(">I", rom, fo, (ins & 0xFC000000) | ((trap >> 2) & 0x3FFFFFF))
        new_entries.append((((r_off - code0) << 8) | 0x40, idx))
    # ---- 1b. original entries inside functions that are byte-identical in both builds
    #          (asm functions, or C that matched) -> move them with their function
    def funcs(E):
        out = []
        for name, val, size, info, shndx in E.syms:
            if (info & 0xF) == 2 and size and 0x80000000 <= val < 0x80400000 and not name.endswith(".NON_MATCHING"):
                out.append((val, size, name))
        out.sort()
        return out
    import bisect
    mf = funcs(M)
    mkeys = [f[0] for f in mf]
    nfunc = {name: (val, size) for val, size, name in funcs(N)}
    mrom = open(sys.argv[1].replace(".elf", ".z64"), "rb").read()
    have_sites = {e[0] >> 8 for e in new_entries}
    kept = 0
    for off in range(8, len(orig_reloc) - 7, 8):
        info, idx = struct.unpack_from(">II", orig_reloc, off)
        if (info & 0xFF) != 0x40:
            continue
        site = 0x80000450 + (info >> 8)
        i = bisect.bisect_right(mkeys, site) - 1
        if i < 0 or not (mf[i][0] <= site < mf[i][0] + mf[i][1]):
            problems.append(f"orig entry {site:08X}: not inside a function")
            continue
        fval, fsize, fname = mf[i]
        if fname not in nfunc:
            continue
        nval, nsize = nfunc[fname]
        if nsize != fsize:
            continue  # function was rebuilt from C; its calls are covered by step 1
        a = mrom[M.lma(fval):M.lma(fval) + fsize]
        b = rom[N.lma(nval):N.lma(nval) + nsize]
        diff = sum(1 for k in range(0, fsize, 4) if a[k:k + 4] != b[k:k + 4])
        if diff and fname not in ("TrapDanglingJump",):
            # identical size but different code: jal targets differ legitimately; check the site itself
            ins = struct.unpack_from(">I", b, site - fval)[0]
            if (ins >> 26) != 3 or ((ins & 0x3FFFFFF) << 2) != (trap & 0x0FFFFFFF):
                continue
        nsite = nval + (site - fval)
        if ((nsite - code0)) in have_sites:
            continue
        new_entries.append((((nsite - code0) << 8) | 0x40, idx))
        kept += 1
    print(f"original entries carried over from unchanged functions: {kept}")
    new_entries.sort()

    # ---- 2. ORT entries into main code / data / bss
    m_code, m_data, m_bss = 0x80000450, M.by_name.get("__DATA_SECTION_START", 0x800A0660), M.by_name.get("__BSS_SECTION_START", 0x800B0B50)
    n_data, n_bss = N.by_name.get("__DATA_SECTION_START"), N.by_name.get("__BSS_SECTION_START")
    fixed = 0
    for i in range(len(orig_ort) // 4):
        e = struct.unpack_from(">I", orig_ort, i * 4)[0]
        owner, off = e >> 20, e & 0xFFFFF
        if owner == 0:
            old, nbase, obase = m_code + off, code0, m_code
        elif owner in (0xFFD, 0xFFE):
            old, nbase, obase = m_data + off, n_data, m_data
        elif owner == 0xFFF:
            old, nbase, obase = m_bss + off, n_bss, m_bss
        else:
            continue
        names = [n for n in M.by_addr.get(old, []) if not n.endswith(".NON_MATCHING")]
        new = None
        for n in names:
            if n in N.by_name:
                new = N.by_name[n]
                break
        if new is None:
            problems.append(f"ORT[{i}] owner {owner:X} {old:08X} {names[:2]}: not found in NM elf")
            continue
        noff = new - nbase
        if not 0 <= noff < 0x100000:
            problems.append(f"ORT[{i}] {names[0]}: offset {noff:X} out of range")
            continue
        struct.pack_into(">I", orig_ort, i * 4, (owner << 20) | noff)
        fixed += 1

    # ---- 3. write tables into the ROM
    (old_count, hdr2) = struct.unpack_from(">II", orig_reloc, 0)
    if len(new_entries) + 8 > (len(orig_reloc) - 8) // 8:
        problems.append(f"mainRelocTable grows: {len(new_entries)} > {(len(orig_reloc) - 8) // 8}")
    else:
        # the original keeps its few non-JAL entries (and a zero terminator) after the sorted
        # JAL entries; they are only ever looked up by address, so they are copied verbatim
        tail = []
        for off in range(8, len(orig_reloc) - 7, 8):
            info, idx = struct.unpack_from(">II", orig_reloc, off)
            if (info & 0xFF) != 0x40:
                tail.append((info, idx))
        # original order: JAL + HI/LO entries sorted by address, then the type-3 data entries,
        # then the zero terminator
        hilo = [r for r in tail if (r[0] & 0xF0) in (0x50, 0x60)]
        rest = [r for r in tail if r not in hilo]
        rows = sorted(new_entries + hilo) + [r for r in rest if r[0]] + [r for r in rest if not r[0]]
        tab = bytearray(len(orig_reloc))
        struct.pack_into(">II", tab, 0, len(new_entries) + sum(1 for i, _ in tail if i), hdr2)
        for k, (info, idx) in enumerate(rows):
            struct.pack_into(">II", tab, 8 + 8 * k, info, idx)
        fo = N.by_name["mainRelocTable_ROM_START"]  # absolute ROM offset (asset VMAs are ambiguous)
        rom[fo:fo + len(tab)] = tab
    fo = N.by_name["overlayRomTable_ROM_START"]
    rom[fo:fo + len(orig_ort)] = orig_ort
    open(rom_path, "wb").write(rom)

    print(f"main->overlay calls: {len(new_entries)} (original table: {old_count} entries, header {hdr2})")
    print(f"ORT main/data/bss entries rewritten: {fixed}")
    print(f"problems: {len(problems)}")
    for p in problems[:60]:
        print("  " + p)


if __name__ == "__main__":
    main()
