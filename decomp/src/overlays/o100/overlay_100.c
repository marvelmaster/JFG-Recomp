#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00100;
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
s32 hitPlayer(f32 x, f32 y, f32 z, f32 r, s32 a4, void **out);
s32 objTvTimes(s32 arg0);
void runlinkSetDestructTimer(s32 module, s32 a1, s32 a2);
/* end decomp: externs */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void refuelInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *rec = (u8 *) arg1;
    u8 *d = *(u8 **) (obj + 0x68);

    *(f32 *) (d + 0x0) = (f32) rec[0xA];
    *(f32 *) (d + 0x4) = *(f32 *) (obj + 0x10) + (f32) (s8) rec[0xB];
    *(s32 *) (d + 0xC) = 0;
    *(f32 *) (d + 0x8) = *(f32 *) (obj + 0x10) + (f32) (s8) rec[0xC];
    *(s16 *) (d + 0x10) = (s16) (s8) rec[0xE];
    if (*(s16 *) (d + 0x10) == 0) {
        *(s16 *) (d + 0x10) = -1;
    }
    *(s32 *) (d + 0x14) = 0;
    *(s16 *) (d + 0x12) = (s16) (rec[0xD] * 0x3C);
    *(s32 *) (d + 0x18) = 0;
    *(u8 *) (d + 0x1C) = 0;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
    *(s32 *) (obj + 0x88) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o100/overlay_100/refuelInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void refuelControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    void *hits[13];
    s32 prevHit;
    s32 timeAdd;
    s32 nHits;
    s32 i;

    runlinkSetDestructTimer(__MODULE00100, 2, 2);
    prevHit = *(s32 *) (d + 0xC);
    *(s32 *) (d + 0xC) = 0;
    timeAdd = objTvTimes(arg1 * 6);
    if (*(s16 *) (d + 0x10) != 0) {
        nHits = hitPlayer(*(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14), 300.0f, 1, hits);
        if (nHits > 0) {
            for (i = 0; i < nHits; i++) {
                u8 *hobj = (u8 *) hits[i];
                f32 dx, dz, hy;

                if ((*(s16 *) (d + 0x10) < 0) || (prevHit != (s32) hobj)) {
                    dx = *(f32 *) (hobj + 0xC) - *(f32 *) (obj + 0xC);
                    dz = *(f32 *) (hobj + 0x14) - *(f32 *) (obj + 0x14);
                    hy = *(f32 *) (hobj + 0x10);
                    if ((((dx * dx) + (dz * dz)) < (*(f32 *) (d + 0x0) * *(f32 *) (d + 0x0)))
                        && (hy < *(f32 *) (d + 0x8)) && (*(f32 *) (d + 0x4) < hy)) {
                        u8 *hd = *(u8 **) (hobj + 0x68);
                        s16 cur = *(s16 *) (hd + 0x58C);

                        if ((cur < *(s16 *) (d + 0x12)) && ((*(s8 *) (hd + 0x1) & 4) != 0)) {
                            *(s16 *) (hd + 0x58C) = (s16) (cur + timeAdd);
                            *(s16 *) (hd + 0x592) = 0x168;
                            if (*(s16 *) (d + 0x12) < *(s16 *) (hd + 0x58C)) {
                                *(s16 *) (hd + 0x58C) = *(s16 *) (d + 0x12);
                            }
                        }
                        *(s32 *) (d + 0xC) = (s32) hobj;
                        if (*(s16 *) (d + 0x10) > 0) {
                            *(s16 *) (d + 0x10) = (s16) (*(s16 *) (d + 0x10) - 1);
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o100/overlay_100/refuelControl.s")
#endif
