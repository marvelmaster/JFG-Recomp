#include "common.h"
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} ShadowPoly;

#ifdef NON_MATCHING
s32 shadowBoxPolyOverlap(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, ShadowPoly *arg5) {
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f1;
    f32 var_f2;
    f32 var_f3;
    s32 var_a0;
    s32 var_v0;
    
    var_f0 = arg5->unk0;
    var_f2 = arg5->unk8;
    var_a0 = arg4;
    var_f1 = var_f0;
    var_f3 = var_f2;
    var_v0 = 0;
loop_1:
    var_a0 -= 1;
    if (var_a0 != 0) {
        arg5 += 1;
        temp_f4 = arg5->unk0;
        temp_f5 = arg5->unk8;
        if (temp_f4 < var_f0) {
            var_f0 = temp_f4;
        } else if (!(temp_f4 <= var_f1)) {
            var_f1 = temp_f4;
        }
        if (temp_f5 < var_f2) {
            var_f2 = temp_f5;
        } else if (!(temp_f5 <= var_f3)) {
            var_f3 = temp_f5;
        }
        goto loop_1;
    }
    if ((arg0 <= var_f1) && (arg1 <= var_f3) && !(arg2 < var_f0) && !(arg3 < var_f2)) {
        var_v0 = 1;
    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows_214A0/shadowBoxPolyOverlap.s")
#endif

#ifdef NON_MATCHING
void shadowBoundingBox(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f1;
    f32 var_f2;
    f32 var_f3;
    var_f0 = arg1[0];
    var_f2 = arg1[1];
    var_f1 = var_f0;
    var_f3 = var_f2;
loop_1:
    arg0 -= 1;
    if (arg0 != 0) {
        arg1 += 2;
        temp_f4 = arg1[0];
        temp_f5 = arg1[1];
        if (temp_f4 < var_f0) {
            var_f0 = temp_f4;
        } else if (!(temp_f4 <= var_f1)) {
            var_f1 = temp_f4;
        }
        if (temp_f5 < var_f2) {
            var_f2 = temp_f5;
        } else if (!(temp_f5 <= var_f3)) {
            var_f3 = temp_f5;
        }
        goto loop_1;
    }
    *arg2 = var_f0;
    *arg3 = var_f2;
    *arg4 = var_f1;
    *arg5 = var_f3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows_214A0/shadowBoundingBox.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shadowYHeight(void *arg0, void *arg1) {
    u8 *sh = (u8 *)arg0;
    u8 *poly = (u8 *)arg1;
    u8 *plane;
    u8 *plane2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_y;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t1;

    plane = *(u8 **)(sh + 0x0);
    temp_f2 = *(f32 *)(poly + 0x0);
    temp_f3 = *(f32 *)(poly + 0x8);
    temp_f4 = *(f32 *)(poly + 0x10);
    temp_f5 = *(f32 *)(poly + 0x18);
    temp_f6 = *(f32 *)(poly + 0x20);
    temp_f7 = *(f32 *)(poly + 0x28);
    temp_f0 = *(f32 *)(plane + 0xC);
    temp_f1 = *(f32 *)(plane + 0x14);

    var_t0 = 0;
    if (!((((temp_f0 - temp_f2) * (temp_f5 - temp_f3)) - ((temp_f4 - temp_f2) * (temp_f1 - temp_f3))) < 0.0f)) {
        var_t0 = 1;
    }
    var_t1 = 0;
    if (!((((temp_f0 - temp_f4) * (temp_f7 - temp_f5)) - ((temp_f6 - temp_f4) * (temp_f1 - temp_f5))) < 0.0f)) {
        var_t1 = 1;
    }
    if (var_t0 == var_t1) {
        plane2 = *(u8 **)(sh + 0x8);
        var_t0_2 = 0;
        if (!((((temp_f0 - temp_f6) * (temp_f3 - temp_f7)) - ((temp_f2 - temp_f6) * (temp_f1 - temp_f7))) < 0.0f)) {
            var_t0_2 = 1;
        }
        if (var_t0_2 == var_t1) {
            temp_y = -((*(f32 *)(plane2 + 0x0) * temp_f0) + (*(f32 *)(plane2 + 0x8) * temp_f1)
                       + *(f32 *)(plane2 + 0xC)) / *(f32 *)(plane2 + 0x4);
            if (!(temp_y < *(f32 *)(sh + 0x18))) {
                *(f32 *)(sh + 0x18) = temp_y;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows_214A0/shadowYHeight.s")
#endif

#ifdef NON_MATCHING
// Vertex record used by shadowMakeYs: x, y (output), z, and the plane it lies on.
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    ShadowPoly *unkC;
} ShadowVert;

// Solves the plane equation A*x + B*y + C*z + D = 0 for y.
static void shadowVertSolveY(ShadowVert *v) {
    ShadowPoly *p = v->unkC;

    v->unk4 = -(v->unk0 * p->unk0 + p->unkC + v->unk8 * p->unk8) / p->unk4;
}

// decomp: m2c + cleanup, non-matching
void shadowMakeYs(s32 count, ShadowVert *verts, s32 *groupCounts, u8 *groups) {
    s32 i;
    s32 j;
    s32 n;

    for (i = 0; i < count; i++) {
        shadowVertSolveY(&verts[i]);
    }
    for (i = 0; i < 4; i++) {
        n = groupCounts[i];
        for (j = 0; j < n; j++) {
            // records in a group are 0x20 bytes apart; groups are 0x400 bytes apart
            shadowVertSolveY(&((ShadowVert *) (groups + i * 0x400))[j * 2]);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows_214A0/shadowMakeYs.s")
#endif
