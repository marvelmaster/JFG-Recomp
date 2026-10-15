#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 iDeltaTime;
extern f32 D_overlay_141_08D003B0;
s32 DoesSquaddieWantToFire(f32 arg0, f32 arg1, s32 arg2);
s32 TryToSetMission(s32 a, s32 b, s32 c, s32 d, s32 e);
void UpdateOrSetAnim(s32 a, s32 b, s32 c);
void TryToSetAnim(f32 y, s32 a, s32 b, s32 c, s32 d);
void TryToUpdateAnim(s32 a, s32 b);
f32 Sinf(s16 angle);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBDragonfly(void *arg0) {
    u8 *st;

    st = *(u8 **) ((u8 *) arg0 + 0x68);
    if (st[0x1A] != 0x14) {
        if (DoesSquaddieWantToFire(0.0f, 0.0f, 0x7FFF) != 0) {
            if (st[0x1A] != 5 && TryToSetMission(4, 5, 0, 0, 0) != 0) {
                UpdateOrSetAnim(6, 0x3F800000, 5);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o141/overlay_141/BTSBDragonfly.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void DragonflyMover(void *arg0) {
    u8 *obj;
    u8 *st;
    u8 *par;
    u8 *ps;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 f0;
    f32 f2;
    f32 y;
    s16 sp2E;
    s16 v;
    s32 t;

    obj = (u8 *) arg0;
    st = *(u8 **) (obj + 0x68);
    par = *(u8 **) (st + 0x24);
    ps = *(u8 **) (par + 0x68);
    f0 = *(f32 *) (par + 0x10) + (f32) ((s8) ps[0x11] * 16);
    f2 = (f32) (ps[0x14] * 16);
    sp34 = f0 + f2;
    sp30 = f0 - f2;
    y = *(f32 *) (obj + 0x10);

    if (sp34 <= y) {
        v = *(s16 *) (st + 0xA8);
        if (!(v & 1)) {
            *(s16 *) (st + 0xA8) = (s16) (v | 1);
            TryToSetAnim(y, 0, 0x10, 0, 0);
        }
    } else if (y <= sp30) {
        v = *(s16 *) (st + 0xA8);
        if (v & 1) {
            *(s16 *) (st + 0xA8) = (s16) (v & 0xFFFE);
            TryToSetAnim(y, 0, 0x11, 0, 0);
            sp2E = mathRnd(0, 0xFFFF);
            t = ps[0x13] * 0x10;
            sp28 = (f32) mathRnd(-t, t);
            *(f32 *) (st + 0x38) = Cosf((s32) sp2E) * sp28 + (*(f32 *) (par + 0x0C) + (f32) ((s8) ps[0x10] * 16));
            *(f32 *) (st + 0x40) = Sinf(sp2E) * sp28 + (*(f32 *) (par + 0x14) + (f32) ((s8) ps[0x12] * 16));
        }
    }

    if (*(s16 *) (st + 0xA8) & 1) {
        *(f32 *) (st + 0x3C) = sp30 - 10.0f;
        *(s32 *) (obj + 0x84) = 0;
    } else {
        *(f32 *) (st + 0x3C) = sp34 + 10.0f;
        *(s32 *) (obj + 0x84) = 8;
    }
    TryToUpdateAnim(0, 0x3F800000);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o141/overlay_141/DragonflyMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void DragonflyTilt(void *arg0, void **arg1) {
    u8 *st;
    s16 *out;

    st = *(u8 **) ((u8 *) arg0 + 0x68);
    out = (s16 *) *arg1;
    if (!(*(u32 *) st & 0x04000000)) {
        out[0] = 0x28;
        out[1] = mathRnd(-0x2BC, 0x2BC);
        out[2] = 0x2E;
        out[3] = mathRnd(-0x2BC, 0x2BC);
        out += 4;
    } else {
        out[0] = 0x28;
        out[1] = *(s16 *) (st + 0xA8);
        out[2] = 0x2E;
        out[3] = -*(s16 *) (st + 0xA8);
        *(s16 *) (st + 0xAA) = (s16) (*(s16 *) (st + 0xAA) + iDeltaTime * 0x450D);
        out += 4;
        *(s16 *) (st + 0xA8) = (s16) (s32) (Sinf(*(s16 *) (st + 0xAA)) * D_overlay_141_08D003B0);
    }
    *arg1 = out;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o141/overlay_141/DragonflyTilt.s")
#endif
