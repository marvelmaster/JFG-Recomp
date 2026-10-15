#!/usr/bin/env python3
"""Statically lift JFG's intertwined animation assembly from the recompiler input.

Unlike the general recompiler, this small, fail-closed lifter treats the three
entries as one control-flow region. Computed jumps dispatch to native C labels;
there is no runtime instruction fetch/decode. Input symbols determine all bounds.
Usage: recomp_anim.py <jfg.us.syms.toml> <jfg.us.recomp.z64> <RecompiledFuncs>
"""
import re
import struct
import sys
import tomllib
from pathlib import Path

NAMES = ('gen_anim_data', 'func_80074A68', 'func_80074B50')


def generate(symbols, rom, output):
    main = next(s for s in symbols['section'] if s['name'] == '.main')
    entries = sorted((f for f in main['functions'] if f['name'] in NAMES), key=lambda f: f['vram'])
    assert len(entries) == 3
    for a, b in zip(entries, entries[1:]):
        assert a['vram'] + a['size'] == b['vram'], 'Animation region must be contiguous'
    start, end = entries[0]['vram'], entries[-1]['vram'] + entries[-1]['size']
    words = {pc: struct.unpack_from('>I', rom, main['rom'] + pc - main['vram'])[0]
             for pc in range(start, end, 4)}
    r = lambda n: f'ctx->r{n}' if n else '0'
    fu = lambda n: f'(*jfg_fpr(ctx, {n}))'
    ff = lambda n: f'jfg_float({fu(n)})'
    label = lambda pc: f'L_{pc:08X}'
    def target(pc):
        assert pc in words, f'Branch leaves animation region: {pc:08X}'
        return f'goto {label(pc)};'
    def put(n, value):
        return f'{r(n)} = {value};' if n else ';'
    def normal(pc):
        w = words[pc]
        op, rs, rt, rd, sa, fn = w >> 26, w >> 21 & 31, w >> 16 & 31, w >> 11 & 31, w >> 6 & 31, w & 63
        imm = (w & 65535) - (65536 if w & 32768 else 0)
        if op == 0:
            if fn in (0, 2, 3):
                expr = {0:f'U32({r(rt)}) << {sa}', 2:f'U32({r(rt)}) >> {sa}', 3:f'S32({r(rt)}) >> {sa}'}[fn]
                return put(rd, f'S32({expr})')
            if fn in (20, 22):
                return put(rd, f'U64({r(rt)}) {"<<" if fn == 20 else ">>"} ({r(rs)} & 63)')
            if fn in (32, 33, 34, 35):
                return put(rd, f'{"ADD32" if fn < 34 else "SUB32"}({r(rs)}, {r(rt)})')
            if fn in (36, 37, 38):
                return put(rd, f'{r(rs)} { {36:"&",37:"|",38:"^"}[fn]} {r(rt)}')
            if fn == 24:
                return f'product = (int64_t)S32({r(rs)}) * S32({r(rt)}); lo = S32(product); hi = S32((uint64_t)product >> 32);'
            if fn == 18: return put(rd, 'lo')
            if fn == 16: return put(rd, 'hi')
        if op in (8, 9): return put(rt, f'ADD32({r(rs)}, {imm})')
        if op == 10: return put(rt, f'S64({r(rs)}) < {imm}')
        if op == 12: return put(rt, f'{r(rs)} & {w & 65535}')
        if op == 13: return put(rt, f'{r(rs)} | {w & 65535}')
        if op == 15: return put(rt, f'S32(0x{(w & 65535) << 16:08X}U)')
        if op in (32, 33, 35, 36, 37):
            mem = {32:'MEM_B',33:'MEM_H',35:'MEM_W',36:'MEM_BU',37:'MEM_HU'}[op]
            return put(rt, f'{mem}({imm}, {r(rs)})')
        if op in (40, 41, 43):
            mem = {40:'MEM_B',41:'MEM_H',43:'MEM_W'}[op]
            return f'{mem}({imm}, {r(rs)}) = {r(rt)};'
        if op in (26, 27): return put(rt, f'do_{"ldl" if op == 26 else "ldr"}(rdram, {r(rt)}, {imm}, {r(rs)})')
        if op == 49: return f'{fu(rt)} = MEM_W({imm}, {r(rs)});'
        if op == 57: return f'MEM_W({imm}, {r(rs)}) = {fu(rt)};'
        if op == 17:
            if rs == 0: return put(rt, f'S32({fu(rd)})')
            if rs == 4: return f'{fu(rd)} = U32({r(rt)});'
            if rs == 16:
                if fn in (0, 1, 2, 3):
                    return f'{fu(sa)} = jfg_bits({ff(rd)} {"+-*/"[fn]} {ff(rt)});'
                if fn == 6: return f'{fu(sa)} = {fu(rd)};'
                if fn == 15: return f'{fu(sa)} = (int32_t)floorf({ff(rd)});'
                if fn == 36: return f'{fu(sa)} = CVT_W_S({ff(rd)});'
                if fn == 52: return f'condition = {ff(rd)} < {ff(rt)};'
            if rs == 20 and fn == 32: return f'{fu(sa)} = jfg_bits((float)S32({fu(rd)}));'
        raise ValueError(f'Unsupported animation instruction {w:08X} at {pc:08X}')

    body = []
    for pc, w in words.items():
        op, rs, rt, fn = w >> 26, w >> 21 & 31, w >> 16 & 31, w & 63
        imm = (w & 65535) - (65536 if w & 32768 else 0)
        body.append(f'{label(pc)}: /* {w:08X} */')
        if op in (2, 3):
            if op == 3: body.append(put(31, f'S32(0x{pc + 8:08X}U)'))
            body += [normal(pc + 4), target(((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))]
        elif op == 0 and fn == 8:
            body += [f'jump = U32({r(rs)});', normal(pc + 4), 'goto dispatch;']
        elif op in (1, 4, 5, 6, 7, 20, 21) or (op == 17 and rs == 8):
            if op == 1:
                assert rt in (0, 1)
                cond = f'S64({r(rs)}) {"<" if rt == 0 else ">="} 0'
            elif op in (4, 20): cond = f'{r(rs)} == {r(rt)}'
            elif op in (5, 21): cond = f'{r(rs)} != {r(rt)}'
            elif op == 6: cond = f'S64({r(rs)}) <= 0'
            elif op == 7: cond = f'S64({r(rs)}) > 0'
            else:
                assert rt in (0, 1)
                cond = 'condition' if rt == 1 else '!condition'
            branch = target(pc + 4 + imm * 4)
            if op in (20, 21):
                body += [f'if ({cond}) {{ {normal(pc + 4)} {branch} }}', target(pc + 8)]
            else:
                body += [f'take_branch = {cond};', normal(pc + 4), f'if (take_branch) {{ {branch} }}', target(pc + 8)]
        else:
            body.append(normal(pc))
    header = '''// Generated by tools/recomp_anim.py from the verified recompiler input.
#include "recomp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static uint32_t *jfg_fpr(recomp_context *ctx, unsigned n) {
    return (n & 1) ? &ctx->f_odd[(n - 1) * 2] : &ctx->f0.u32l + n * 2;
}
static float jfg_float(uint32_t v) { float f; memcpy(&f, &v, 4); return f; }
static uint32_t jfg_bits(float f) { uint32_t v; memcpy(&v, &f, 4); return v; }
static void jfg_animation_region(uint8_t *rdram, recomp_context *ctx, uint32_t jump) {
    uint64_t hi = 0, lo = 0;
    int64_t product = 0;
    int condition = 0, take_branch = 0;
    const gpr caller_ra = ctx->r31;
    ctx->r31 = (gpr)(int32_t)0xFFFFFFFC;
dispatch:
    if (jump == 0xFFFFFFFC) { ctx->r31 = caller_ra; return; }
    switch (jump) {
'''
    dispatch = '\n'.join(f'    case 0x{pc:08X}: goto {label(pc)};' for pc in words)
    dispatch += '\n    default: fprintf(stderr, "Invalid JFG animation target %08X\\n", jump); abort();\n    }\n'
    result = header + dispatch + '\n'.join(body) + '\n    abort();\n}\n'
    for f in entries:
        result += f'void jfg_native_{f["name"]}(uint8_t *rdram, recomp_context *ctx) {{ jfg_animation_region(rdram, ctx, 0x{f["vram"]:08X}); }}\n'
    output.mkdir(parents=True, exist_ok=True)
    (output / 'jfg_animation.c').write_text(result)
    for name in NAMES:
        matches = 0
        for path in output.glob('funcs_*.c'):
            text = path.read_text()
            pattern = rf'RECOMP_FUNC void {name}\(uint8_t\* rdram, recomp_context\* ctx\) \{{[^}}]*\}}'
            replacement = f'RECOMP_FUNC void {name}(uint8_t* rdram, recomp_context* ctx) {{\n    extern void jfg_native_{name}(uint8_t*, recomp_context*);\n    jfg_native_{name}(rdram, ctx);\n}}'
            updated, count = re.subn(pattern, lambda _: replacement, text)
            if count: path.write_text(updated)
            matches += count
        assert matches == 1, f'Expected one wrapper for {name}, got {matches}'
    print(f'Animation: {len(words)} instructions statically translated, {len(entries)} native entry points')


if __name__ == '__main__':
    generate(tomllib.loads(Path(sys.argv[1]).read_text()), Path(sys.argv[2]).read_bytes(), Path(sys.argv[3]))
