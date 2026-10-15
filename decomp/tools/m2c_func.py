#!/usr/bin/env python3
"""Windows-native m2c helper: produce a C draft for one asm function.

Usage: .venv/Scripts/python.exe tools/m2c_func.py <src/file.c> <func_name>

Builds a context from the given C file (preprocessed with zig's clang, so all
of its headers' types/prototypes are known to m2c), finds the matching asm in
asm/nonmatchings, and prints m2c's output to stdout.
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).parent))
from check_c import INCLUDES  # noqa: E402
from overlay_relocs import overlay_of, rewrite  # noqa: E402

DEFINES = ["_LANGUAGE_C", "F3DDKR_GBI", "_MIPS_SZLONG=32", "BUILD_VERSION=6", "TARGET_N64",
           "_FINALROM", "NDEBUG", "VERSION_us", "M2CTX", "__sgi", "RAREDIFFS", "JFGDIFFS"]
CTX_DIR = ROOT / "build" / "m2cctx"
TMP_DIR = ROOT / "build" / "m2ctmp"
DANGLING = re.compile(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/\s+jal\s+TrapDanglingJump")


def dangling_targets():
    """main-code VRAM of a `jal TrapDanglingJump` -> real overlay function name."""
    reloc = (ROOT / "assets" / "mainRelocTable.bin").read_bytes()
    ort = (ROOT / "assets" / "overlayRomTable.bin").read_bytes()
    names = {}
    for line in (ROOT / "ver" / "symbols" / "overlays.us.txt").read_text().splitlines():
        m = re.match(r"(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
        if m:
            names[int(m[2], 16)] = m[1]
    result = {}
    # 8-byte header (entry count), then entries: (text offset << 8 | flags, ORT index)
    for off in range(8, len(reloc) - 7, 8):
        info, idx = struct.unpack_from(">II", reloc, off)
        if (info >> 4) & 15 != 4:  # only JAL patches
            continue
        addr = info >> 8
        if idx * 4 + 4 > len(ort):
            continue
        entry = struct.unpack_from(">I", ort, idx * 4)[0]
        if entry >> 20 >= 0xFFC:
            continue
        name = names.get(entry)
        if name is None:
            hits = list((ROOT / "asm").rglob(f"func_overlay_{entry >> 20}_{entry:08X}_*.s"))
            name = hits[0].stem if hits else f"func_overlay_{entry >> 20}_{entry:08X}"
        result[0x80000450 + addr] = name
    return result


def resolve_dangling(asm_path):
    text = asm_path.read_text(encoding="utf-8")
    n = overlay_of(asm_path)
    if n is not None:  # overlay: apply the runtime relocations statically
        TMP_DIR.mkdir(parents=True, exist_ok=True)
        out = TMP_DIR / asm_path.name
        out.write_text(rewrite(n, text), encoding="utf-8")
        return out
    if "TrapDanglingJump" not in text and ".word func_0" not in text:
        return asm_path
    # splat sometimes pulls a zero padding word into a jump table
    text = re.sub(r"^.*\.word func_0[ \t]*\r?\n", "", text, flags=re.M)
    targets = dangling_targets()

    def repl(m):
        name = targets.get(int(m[1], 16))
        return m[0].replace("TrapDanglingJump", name) if name else m[0]
    TMP_DIR.mkdir(parents=True, exist_ok=True)
    out = TMP_DIR / asm_path.name
    out.write_text(DANGLING.sub(repl, text) if "TrapDanglingJump" in text else text, encoding="utf-8")
    return out


def context_for(c_file):
    c_file = Path(c_file).resolve()
    rel = c_file.relative_to(ROOT)
    out = CTX_DIR / (str(rel).replace("\\", "_").replace("/", "_") + ".ctx.c")
    if out.exists() and out.stat().st_mtime >= c_file.stat().st_mtime:
        return out
    CTX_DIR.mkdir(parents=True, exist_ok=True)
    cmd = [sys.executable, "-m", "ziglang", "clang", "-cc1", "-triple", "mips-unknown-unknown",
           "-E", "-P", "-nostdsysteminc", "-w"]
    cmd += [f"-I{i}" for i in INCLUDES if (ROOT / i).is_dir()]
    cmd += [f"-D{d}" for d in DEFINES]
    cmd.append(str(rel))
    text = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True).stdout
    out.write_text(text, encoding="utf-8")
    return out


def main():
    if len(sys.argv) != 3:
        print(__doc__)
        sys.exit(2)
    c_file, func = sys.argv[1], sys.argv[2]
    matches = list((ROOT / "asm" / "nonmatchings").rglob(f"{func}.s"))
    if not matches:
        sys.exit(f"asm for {func} not found")
    ctx = context_for(c_file)
    cmd = [sys.executable, "-m", "m2c.main", "--target", "mips-ido-c", "--pointer-style", "right",
           "--context", str(ctx), "-f", func, str(resolve_dangling(matches[0]))]
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        # retry without context if the context could not be parsed
        cmd = [c for c in cmd if c not in ("--context", str(ctx))]
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
        print("/* m2c: context failed, generated without context */")
    print(r.stdout)
    if r.stderr.strip():
        print(r.stderr, file=sys.stderr)


if __name__ == "__main__":
    main()
