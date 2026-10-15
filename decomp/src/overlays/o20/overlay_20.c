#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern f32 D_overlay_20_01400430;

void hitInitObjectHit(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, s32 arg11);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
s32 hitPlayer(f32 x, f32 y, f32 z, f32 r, s32 a4, void *out);
s32 objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 a1, s32 a2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void treeInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *spawn = (u8 *)arg1;
    u8 *model;
    f32 *out;
    f32 t;
    f32 scale;

    *(s16 *)(obj + 0x6) = (s16)(*(s16 *)(obj + 0x6) | 2);
    t = (f32)spawn[0xB];
    if (t < 10.0f) {
        t = 10.0f;
    }
    scale = t / 64.0f;
    model = *(u8 **)(obj + 0x40);
    *(f32 *)(obj + 0x8) = *(f32 *)model * scale;
    out = *(f32 **)(obj + 0x50);
    if (out != NULL) {
        *out = *(f32 *)(model + 0x54) * scale;
    }
    obj[0x3A] = spawn[0xA];
    *(s16 *)obj = (s16)(spawn[0xC] << 10);
    if (spawn[0xD] != 0) {
        hitInitObjectHit(obj, (u8)-1, 2, 1, 0, 0, 0, 20.0f, 10.0f, -1.0f, 1.0f, 0x11);
    }
    if ((s8)obj[0x3A] >= *(s8 *)(model + 0x1F)) {
        obj[0x3A] = 0;
    }
    *(s32 *)(obj + 0x88) = 0;
    *(s32 *)(obj + 0x8C) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o20/overlay_20/treeInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void treeControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *model;
    u8 *v1;
    s32 var_a2;
    s32 v2;

    model = *(u8 **)(obj + 0x4C);
    if (model == NULL) {
        return;
    }
    v1 = obj + 0x88;
    if (*(s16 *)(obj + 0x8C) > 0) {
        *(s16 *)(obj + 0x8C) = (s16)(*(s16 *)(obj + 0x8C) - arg1);
        model = *(u8 **)(obj + 0x4C);
    }
    if ((*(u16 *)(model + 0xA) & 2) && *(s16 *)(obj + 0x8C) <= 0) {
        amSndPlayXYZ(0, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        *(s32 *)(v1) = *(s32 *)(*(u8 **)(obj + 0x4C) + 0x3C);
        *(s16 *)(obj + 0x8E) = 0x71C;
        *(s16 *)(obj + 0x8C) = 10;
        v2 = *(s8 *)(*(u8 **)(obj + 0x40) + 0x22);
        if (v2 < 2) {
            var_a2 = 0;
        } else {
            var_a2 = mathRnd(0, v2 - 1);
        }
        *(s32 *)(obj + 0x84) = 1 << var_a2;
        partUpdateTriggers(obj, 2, var_a2);
    } else if (*(s16 *)(obj + 0x8C) <= 0) {
        *(s32 *)(v1) = 0;
    }
    *(s16 *)(obj + 0x4) = *(s16 *)(obj + 0x8E);
    *(s16 *)(obj + 0x8E) = (s16)((*(s16 *)(obj + 0x8E) * -0xC8) >> 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o20/overlay_20/treeControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireflyInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *spawn = (u8 *)arg1;
    s32 *flags = *(s32 **)(obj + 0x68);

    *(f32 *)(obj + 0x8) = *(f32 *)*(u8 **)(obj + 0x40) * (f32)spawn[0xB] * 0.015625f;
    if (*(f32 *)(obj + 0x8) < D_overlay_20_01400430) {
        *(f32 *)(obj + 0x8) = D_overlay_20_01400430;
    }
    *(s32 *)(obj + 0x88) = 0;
    *(s32 *)(obj + 0x8C) = 0;
    if (*(s16 *)(obj + 0x4A) == 0x1B2) {
        *(s32 *)(obj + 0x88) = 0x2D0;
        *(s16 *)(obj + 0x6) = (s16)(*(s16 *)(obj + 0x6) | 0x400);
    }
    if (*(s16 *)spawn == 0x1B2) {
        amSndPlayXYZ(0x1BD, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 1, flags);
        return;
    }
    *flags = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o20/overlay_20/fireflyInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireflyControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    s32 v0;
    s32 t;
    void *hitObj;

    v0 = *(s32 *)(obj + 0x88);
    if (v0 >= 0xB5 && *(s32 *)(obj + 0x8C) == 0) {
        v0 = 0xB4;
        *(s32 *)(obj + 0x88) = 0xB4;
    }
    if ((v0 == 0 || v0 >= 0xB5)
        && hitPlayer(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 600.0f, 0, &hitObj) != 0) {
        *(s32 *)(obj + 0x84) = 1;
    } else {
        *(s32 *)(obj + 0x84) = 0;
    }
    ((void (*)(void *, s32))partUpdateTriggers)(arg0, arg1); /* sig mismatch: asm passes 2 args */
    v0 = *(s32 *)(obj + 0x88);
    t = v0 - arg1;
    if (v0 != 0) {
        *(s32 *)(obj + 0x88) = t;
        if (t <= 0) {
            objFreeObject(arg0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o20/overlay_20/fireflyControl.s")
#endif
