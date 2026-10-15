#!/usr/bin/env python3
"""Find likely decomp bugs: memory accesses whose width/type differ from the original.

For every function present in both the matching build (original asm) and the measure build
(our C, same flags), collect the load/store instructions that do NOT use $sp, keyed by the
immediate offset: e.g. {0x64: {'lbu'}}. A function is reported when an offset is accessed
with a different *kind* (byte/half/word, signed/unsigned, int/float) in our C than in the
original and the original never uses that kind there. Typical hits: `*(s32 *)(p + 0x64)`
where the game reads a byte, `(f32) *(s32 *)` where the game copies a float (lwc1).

Usage (WSL): python3 access_check.py <matching build> <measure build> [--json out.json]
"""
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import match_report as m  # noqa: E402
import rabbitizer  # noqa: E402

KIND = {
    "lb": "s8", "lbu": "u8", "sb": "8",
    "lh": "s16", "lhu": "u16", "sh": "16",
    "lw": "w", "sw": "w",
    "lwc1": "f32", "swc1": "f32", "ldc1": "f64", "sdc1": "f64",
}


LOADS = {"lb", "lbu", "lh", "lhu", "lw", "lwc1", "ldc1"}


def accesses(fw, only=None):
    words, rel = fw
    out = defaultdict(set)
    for i, w in enumerate(words):
        if i in rel:  # %lo(global): immediate is a relocation, not a struct offset
            continue
        ins = rabbitizer.Instruction(w)
        name = ins.getOpcodeName()
        if name not in KIND or (only and name not in only):
            continue
        if "$sp" in ins.disassemble().split(",")[-1]:  # $sp: locals/spills, layout differs legitimately
            continue
        imm = ins.getProcessedImmediate()
        out[imm].add(KIND[name])
    return out


def compatible(a, b):
    # stores do not tell signedness; treat 8 vs s8/u8 etc. as the same width
    norm = lambda k: {"s8": "8", "u8": "8", "s16": "16", "u16": "16"}.get(k, k)
    return {norm(x) for x in a} & {norm(x) for x in b} or not a or not b


def main():
    ref_dir, nm_dir = Path(sys.argv[1]), Path(sys.argv[2])
    report = {}
    for ref in sorted(ref_dir.rglob("*.c.o")):
        nmo = nm_dir / ref.relative_to(ref_dir)
        if not nmo.exists():
            continue
        a, b = m.load(ref), m.load(nmo)
        for fn in b:
            if fn not in a or m.same(a[fn], b[fn]):
                continue
            oa, ob = accesses(a[fn]), accesses(b[fn])
            la, lb = accesses(a[fn], LOADS), accesses(b[fn], LOADS)
            issues = []
            for off in sorted(set(oa) | set(ob)):
                ka, kb = oa.get(off, set()), ob.get(off, set())
                if ka and kb and ka != kb:
                    sig = lambda s: {x for x in s if x in ("s8", "u8", "s16", "u16")}
                    width_diff = not compatible(ka, kb)
                    sign_diff = sig(ka) and sig(kb) and sig(ka) != sig(kb)
                    float_diff = ("f32" in ka) != ("f32" in kb)
                    if width_diff or sign_diff or float_diff:
                        issues.append(f"0x{off:X}: orig {'/'.join(sorted(ka))} vs C {'/'.join(sorted(kb))}")
            # loads only: `(f32) *(s32 *)` (lw + cvt) where the game copies a float (lwc1) and vice versa
            for off in sorted(set(la) & set(lb)):
                fa, fb = "f32" in la[off], "f32" in lb[off]
                if fa != fb and not any(i.startswith(f"0x{off:X}:") for i in issues):
                    issues.append(f"0x{off:X}: load orig {'/'.join(sorted(la[off]))} vs C {'/'.join(sorted(lb[off]))}")
            if issues:
                report.setdefault(str(ref.relative_to(ref_dir))[:-2], {})[fn] = issues
    n = sum(len(v) for v in report.values())
    print(f"{n} functions with access-type differences in {len(report)} files")
    for f, fns in sorted(report.items(), key=lambda x: -len(x[1]))[:40]:
        print(f"  {f}: {len(fns)}")
    if "--json" in sys.argv:
        Path(sys.argv[sys.argv.index("--json") + 1]).write_text(json.dumps(report, indent=1))


if __name__ == "__main__":
    main()
