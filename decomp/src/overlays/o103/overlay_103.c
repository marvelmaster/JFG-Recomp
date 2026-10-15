#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00103;
extern f32 D_overlay_103_06700250;
extern f32 D_overlay_103_06700254;
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
void objAnimDframe(void *obj, f32 rate, f32 frame);
void objCreateBonusItem(f32 x, f32 y, s32 a2, u8 a3);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg1);
void runlinkSetDestructTimer(s32 module, s32 a1, s32 a2);
/* end decomp: externs */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void grubInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *rec = (u8 *) arg1;
    f32 radius;

    *(f32 *) (obj + 0x8) = (f32) rec[0xA] * D_overlay_103_06700250;
    radius = *(f32 *) (obj + 0x8) * 20.0f;
    hitInitObjectHit(arg0, rec[0xB] << 8, 1, 1, 0, 0, 0, radius, radius, -1.0f, 1.0f, 0x11);
    *(f32 *) (obj + 0x88) = (f32) rec[0xD] * D_overlay_103_06700254;
    *(s16 *) (obj + 0x8C) = *(s16 *) (*(u8 **) (obj + 0x4C) + 0x6);
    *(u8 *) (obj + 0x8E) = 0;
    *(u8 *) (obj + 0x8F) = rec[0xC];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o103/overlay_103/grubInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void grubControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *rec = obj + 0x88;
    s16 var_v1;
    u32 rateBitsA = 0x3D889A02;
    u32 rateBitsB = 0x3C23D70A;

    runlinkSetDestructTimer(__MODULE00103, 2, 2);
    var_v1 = *(s16 *) (*(u8 **) (obj + 0x4C) + 0x6);
    if (var_v1 > 0) {
        if (var_v1 < *(s16 *) (rec + 0x4)) {
            *(s8 *) (rec + 0x6) = 0xF;
            var_v1 = *(s16 *) (*(u8 **) (obj + 0x4C) + 0x6);
        }
        *(s16 *) (rec + 0x4) = var_v1;
        if (*(s8 *) (rec + 0x6) > 0) {
            objAnimDframe(arg0, *(f32 *) &rateBitsA, (f32) arg1);
            *(s8 *) (rec + 0x6) = (s8) (*(s8 *) (rec + 0x6) - arg1);
            return;
        }
        objAnimDframe(arg0, *(f32 *) &rateBitsB, (f32) arg1);
        return;
    }
    objCreateBonusItem(*(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(s32 *) (obj + 0x14), *(u8 *) (obj + 0x8F));
    *(s32 *) (obj + 0x84) = 1;
    partUpdateTriggers(arg0, 2);
    objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o103/overlay_103/grubControl.s")
#endif
