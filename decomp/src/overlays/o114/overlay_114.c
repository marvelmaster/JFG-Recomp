#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_114_072005F0;
void hitInitObjectHit(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 a6, f32 a7, f32 a8, f32 a9, s32 a10);
void amSndPlay(s32 soundId, s32 handle, void *a2, void *a3); /* asm passes 4 args */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multitargetInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    u8 *d = *(u8 **) (obj + 0x68);

    *(s16 *) (obj + 0x00) = (s16) (src[0x0E] << 8);
    *(s16 *) (obj + 0x04) = (s16) (src[0x0F] << 8);
    *(s16 *) (d + 0x00) = (s16) (((s32) *(s16 *) (src + 0x0A) * 0x3C) / 100);
    *(s16 *) (d + 0x04) = 0;
    *(s16 *) (d + 0x02) = (s16) (((s32) *(s16 *) (src + 0x0C) * 0x3C) / 100);
    *(s16 *) (d + 0x06) = (s16) (src[0x10] << 8);
    *(s32 *) (obj + 0x88) = src[0x11] * 10;
    *(s16 *) (*(u8 **) (obj + 0x4C) + 0x06) = *(s16 *) (d + 0x06);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o114/overlay_114/multitargetInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multitargetControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    u8 *ctl = *(u8 **) (obj + 0x4C);
    s32 remain = arg1;
    s16 timer;

    if (*(s16 *) (d + 0x00) != 0) {
        *(s16 *) (ctl + 0x06) = *(s16 *) (d + 0x06);
    }
    if (*(s16 *) (ctl + 0x06) <= 0) {
        *(s16 *) (obj + 0x06) |= 0x400;
        return;
    }
    timer = *(s16 *) (d + 0x00);
    if (remain < timer) {
        *(s16 *) (d + 0x00) = (s16) (timer - remain);
        *(s16 *) (obj + 0x06) |= 0x400;
    } else if (timer > 0) {
        remain -= timer;
        *(s16 *) (d + 0x00) = 0;
    }
    if (*(s16 *) (d + 0x00) == 0) {
        s16 t1 = *(s16 *) (d + 0x02);

        if (remain < t1) {
            *(s16 *) (d + 0x02) = (s16) (t1 - remain);
            *(s16 *) (obj + 0x06) &= 0xFBFF;
            return;
        }
        *(s16 *) (d + 0x02) = 0;
        *(s16 *) (obj + 0x06) |= 0x400;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o114/overlay_114/multitargetControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiptargetInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    u8 *d = *(u8 **) (obj + 0x68);

    *(s16 *) (obj + 0x00) = (s16) (src[0x0E] << 8);
    *(s16 *) (obj + 0x04) = (s16) -0x4000;
    *(s16 *) (obj + 0x02) = (s16) (src[0x0F] << 8);
    *(f32 *) (obj + 0x08) = (f32) *(s16 *) (src + 0x12) * *(f32 *) *(u8 **) (obj + 0x40) * D_overlay_114_072005F0;
    *(s16 *) (d + 0x00) = (s16) (((s32) *(s16 *) (src + 0x0A) * 0x3C) / 100);
    *(s16 *) (d + 0x04) = 0;
    *(s16 *) (d + 0x02) = (s16) (((s32) *(s16 *) (src + 0x0C) * 0x3C) / 100);
    *(s16 *) (d + 0x06) = (s16) (src[0x10] << 8);
    *(s32 *) (obj + 0x88) = src[0x11] * 10;
    hitInitObjectHit(*(s16 *) (d + 0x06), 0, 8, 0, 0, 0, 20.0f, 20.0f, -1.0f, 1.0f, 0x11);
    *(u16 *) (*(u8 **) (obj + 0x4C) + 0x0A) &= 0xFFFE;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o114/overlay_114/multiptargetInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiptargetControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    u8 *ctl = *(u8 **) (obj + 0x4C);
    s32 remain = arg1;
    s32 v;

    if (*(s16 *) (d + 0x00) != 0) {
        *(s16 *) (ctl + 0x06) = *(s16 *) (d + 0x06);
        v = *(s16 *) (ctl + 0x06);
    } else {
        v = *(s16 *) (ctl + 0x06);
        if (v > 0) {
            *(s16 *) (ctl + 0x06) = (s16) (v - *(s16 *) (*(u8 **) (obj + 0x5C) + 0x130));
            v = *(s16 *) (ctl + 0x06);
            if (v <= 0) {
                amSndPlay(0x13, 0, d, arg0);
                v = *(s16 *) (ctl + 0x06);
            }
        }
    }

    if (v <= 0) {
        s16 t4 = *(s16 *) (d + 0x04);

        if (t4 > 0) {
            s32 t7;

            *(s16 *) (d + 0x04) = (s16) (t4 - (remain << 5));
            t4 = *(s16 *) (d + 0x04);
            t7 = t4 << 6;
            if (t4 < 0) {
                *(s16 *) (d + 0x04) = 0;
                t7 = *(s16 *) (d + 0x04) << 6;
            }
            *(s16 *) (obj + 0x04) = (s16) (t7 + 0xC000);
        } else {
            *(s16 *) (obj + 0x06) |= 0x400;
        }
        *(u16 *) (ctl + 0x0A) &= 0xFFFE;
    } else {
        s16 t5 = *(s16 *) (d + 0x00);

        if (remain < t5) {
            *(s16 *) (d + 0x00) = (s16) (t5 - remain);
            *(s16 *) (obj + 0x06) |= 0x400;
        } else if (t5 > 0) {
            remain -= t5;
            *(s16 *) (d + 0x00) = 0;
        }
        if (*(s16 *) (d + 0x00) == 0) {
            s16 t1 = *(s16 *) (d + 0x02);

            if (remain < t1) {
                s16 t4 = *(s16 *) (d + 0x04);

                if (t4 < 0x100) {
                    s32 t9;

                    *(s16 *) (d + 0x04) = (s16) (t4 + remain * 0x10);
                    t9 = *(s16 *) (d + 0x04) << 6;
                    if (*(s16 *) (d + 0x04) > 0x100) {
                        *(s16 *) (d + 0x04) = 0x100;
                        t9 = *(s16 *) (d + 0x04) << 6;
                    }
                    *(s16 *) (obj + 0x04) = (s16) (t9 + 0xC000);
                } else {
                    *(s16 *) (d + 0x02) = (s16) (t1 - remain);
                }
                *(s16 *) (obj + 0x06) &= 0xFBFF;
                *(u16 *) (ctl + 0x0A) |= 1;
            } else {
                s16 t8 = *(s16 *) (d + 0x04);

                if (t8 > 0) {
                    s32 t10;

                    *(s16 *) (d + 0x04) = (s16) (t8 - remain * 0x10);
                    t10 = *(s16 *) (d + 0x04) << 6;
                    if (*(s16 *) (d + 0x04) < 0) {
                        *(s16 *) (d + 0x04) = 0;
                        t10 = *(s16 *) (d + 0x04) << 6;
                    }
                    *(s16 *) (obj + 0x04) = (s16) (t10 + 0xC000);
                } else {
                    *(s16 *) (d + 0x02) = 0;
                    *(s16 *) (obj + 0x06) |= 0x400;
                    *(u16 *) (ctl + 0x0A) &= 0xFFFE;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o114/overlay_114/multiptargetControl.s")
#endif
