#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern f32 D_overlay_92_05C00340;
extern f32 D_overlay_92_05C00344;
extern s32 __MODULE00092;
void mathOneFloatPY(void *arg0, void *arg1);
s32 trackGetIntersect(s32 a, f32 *from, f32 *to, f32 radius, s32 mask, void *hitOut);
void trackMakePolylist(s32 a, f32 *from, f32 *to, f32 *radius, s32 b, s32 c, s32 d);
void runlinkSetDestructTimer(s32 module, s32 a, s32 b, void *obj);
void objFreeObject(void *obj);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fishfoodInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *params = (u8 *)arg1;
    u8 *state = *(u8 **)(obj + 0x68);
    f32 start[3];
    f32 end[3];
    f32 radius = 10.0f;
    f32 hitNormal[4];

    *(s16 *)(state + 0xC) = (s16)(*(s16 *)(params + 0xE) << 8);
    *(f32 *)(obj + 0x24) = -1.0f;
    *(f32 *)(obj + 0x8) = (f32)*(s16 *)(params + 0xE) * D_overlay_92_05C00340;
    mathOneFloatPY(params + 0xA, obj + 0x1C);

    /* 20.0f was stored to the radius slot first in the asm, but it is overwritten before use */
    start[0] = *(f32 *)(obj + 0xC) - *(f32 *)(obj + 0x1C) * 20.0f;
    start[1] = *(f32 *)(obj + 0x10) - *(f32 *)(obj + 0x20) * 20.0f;
    start[2] = *(f32 *)(obj + 0x14) - *(f32 *)(obj + 0x24) * 20.0f;
    end[0] = *(f32 *)(obj + 0xC) + *(f32 *)(obj + 0x1C) * 20.0f;
    end[1] = *(f32 *)(obj + 0x10) + *(f32 *)(obj + 0x20) * 20.0f;
    end[2] = *(f32 *)(obj + 0x14) + *(f32 *)(obj + 0x24) * 20.0f;

    trackMakePolylist(1, start, end, &radius, 0, 0, 0);
    if (trackGetIntersect(0, start, end, radius, 1, hitNormal) != 0) {
        *(f32 *)(obj + 0xC) = end[0];
        *(f32 *)(obj + 0x10) = end[1];
        *(f32 *)(obj + 0x14) = end[2];
    }
    *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * *(f32 *)(params + 0x10);
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) * *(f32 *)(params + 0x10);
    *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * *(f32 *)(params + 0x10);

    *(f32 *)(state + 0x0) = *(f32 *)(obj + 0xC);
    *(f32 *)(state + 0x4) = *(f32 *)(obj + 0x10);
    state[0xE] = 0;
    state[0xF] = 0;
    *(f32 *)(state + 0x8) = *(f32 *)(obj + 0x14);
    *(s32 *)(obj + 0x8C) = 0;
    *(s32 *)(obj + 0x88) = *(s16 *)(state + 0xC);
    *(u8 *)(*(u8 **)(obj + 0x7C)) &= 0xFD;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o92/overlay_92/fishfoodInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fishfoodControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *flags;

    runlinkSetDestructTimer(__MODULE00092, 2, 2, arg0);
    *(s16 *)(state + 0xC) = (s16)*(s32 *)(obj + 0x88);
    *(s16 *)(state + 0xC) = (s16)(*(s16 *)(state + 0xC) - arg1);

    if (*(s16 *)(state + 0xC) <= 0) {
        *(s32 *)(obj + 0x88) = 0;
        *(f32 *)(obj + 0x8) = 0.0f;
        objFreeObject(arg0);
        return;
    }

    *(f32 *)(obj + 0x8) = (f32)*(s16 *)(state + 0xC) * D_overlay_92_05C00344;
    *(s32 *)(obj + 0x88) = *(s16 *)(state + 0xC);

    flags = *(u8 **)(obj + 0x7C);
    if (*flags & 2) {
        *(s32 *)(obj + 0x8C) = 1;
    } else {
        *(s32 *)(obj + 0x8C) = 0;
    }

    if (*flags & 1) {
        *(s16 *)(obj + 0x6) = (s16)((*(s16 *)(obj + 0x6) & 0xFFFB) | 0x8);
        state[0xE] = 1;
        return;
    }
    *(s16 *)(obj + 0x6) = (s16)((*(s16 *)(obj + 0x6) & 0xFFF7) | 0x4);
    state[0xE] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o92/overlay_92/fishfoodControl.s")
#endif
