#!/usr/bin/env python3
"""Give Rare's hand-written single-precision routines independent odd FPRs.

N64Recomp emits odd arithmetic through ctx->fN but odd loads through f_odd.
These routines need FR=1 while executing, as in dino-recomp's math hooks.
Always restore the caller's actual status, including nested native calls.
"""
import re
import sys
from pathlib import Path

NAMES = set('''mathRSMtx pointListRPY splinePos matrixScale matrixTranslate matrixRoll
matrixPitch matrixYaw Arctanf matrix_SCL_RPY_XYZ matrix_RPY_XYZ matrix_XYZ_YPR_SCL
matrix_XYZ_YPR matrixTransposeVectorMultiply conv_mult_matrix trackLightAsm
shadowBoxPolyOverlap shadowBoundingBox shadowYHeight shadowMakeYs
lightMakeJointPositions starfieldFastMove rainFastDraw'''.split())


def patch(directory):
    seen = set()
    for path in Path(directory).glob('funcs_*.c'):
        original = path.read_text()
        def replace(m):
            name, body = m[1], m[2]
            if name not in NAMES: return m[0]
            seen.add(name)
            if 'jfg_saved_fpu_status' in body: return m[0]
            assert not re.search(r'ctx->f\d+\.d|MUL_D|DIV_D|CVT_D', body), name
            assert re.search(r'^\s*return;', body, re.M), name
            body = re.sub(r'^(\s*)return;', r'\1cop0_status_write(ctx, jfg_saved_fpu_status);\n\1return;', body, flags=re.M)
            prefix = '\n    const gpr jfg_saved_fpu_status = cop0_status_read(ctx);\n    cop0_status_write(ctx, jfg_saved_fpu_status | 0x04000000);\n'
            return f'RECOMP_FUNC void {name}(uint8_t* rdram, recomp_context* ctx) {{' + prefix + body
        updated = re.sub(r'RECOMP_FUNC void (\w+)\(uint8_t\* rdram, recomp_context\* ctx\) \{(.*?)(?=RECOMP_FUNC|\Z)', replace, original, flags=re.S)
        if updated != original: path.write_text(updated)
    assert seen == NAMES, f'Missing Rare FPU functions: {NAMES - seen}'
    print(f'Rare FPU mode: {len(seen)} routines, caller status preserved')


if __name__ == '__main__': patch(sys.argv[1])
