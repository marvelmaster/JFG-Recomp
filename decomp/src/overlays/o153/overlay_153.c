#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00153;
s16 objTvTimes(s32 arg0);
void SquaddieLightAndAnimate(void *obj);
void bloodSpurtAdd(f32 x, f32 y, s32 z, f32 a, f32 b, f32 c, s32 d, s32 e, f32 f);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg);
void runlinkSetDestructTimer(s32 module, s32 a, s32 b, void *c);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void zombieFlobInit(void *arg0, void *arg1) {
    u8 *obj;
    u8 *setup;
    u8 *st;
    u8 *temp_v1;

    obj = (u8 *)arg0;
    setup = (u8 *)arg1;
    *(f32 *)(obj + 0x1C) = 0.0f;
    *(f32 *)(obj + 0x20) = 0.0f;
    *(f32 *)(obj + 0x24) = 0.0f;
    *(s16 *)obj = *(s16 *)(setup + 0xC);
    st = *(u8 **)(obj + 0x68);
    *(s16 *)(obj + 2) = *(s16 *)(setup + 0xE);
    *(s16 *)(obj + 4) = (s16) mathRnd(0, 0xFFFF);
    *(f32 *)(obj + 0x28) = 0.0f;
    hitInitObjectHit(obj, setup[0xA] << 8, 1, 2, 0, 0, 0, 16.0f, 16.0f, 1.0f, 0.75f, 0x11);
    *(s16 *)(st + 8) = objTvTimes(setup[0xB] * 6);
    st[0xA] = setup[0xA];
    *(s32 *)st = *(s32 *)(setup + 0x14);
    st[0xB] = (u8) mathRnd(-0x80, 0x7F);
    st[0xC] = 1;
    st[0xD] = setup[0x18];
    temp_v1 = *(u8 **)(obj + 0x7C);
    *temp_v1 &= 0xFFFD;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o153/overlay_153/zombieFlobInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void zombieFlobControl(void *arg0, s32 arg1) {
    u8 *obj;
    u8 *st;
    u8 *fl;
    u8 *tgt;
    u8 *temp_v1_2;
    u8 *temp_v0_2;
    u8 temp_v1_3;
    s32 temp_t0;
    s32 temp_t1;
    f32 temp_f0;
    f32 temp_f2;

    obj = (u8 *)arg0;
    st = *(u8 **)(obj + 0x68);
    fl = *(u8 **)(obj + 0x7C);
    runlinkSetDestructTimer(__MODULE00153, 2, 2, st);
    if ((*(s16 *)(st + 8) > 0) && !(fl[0] & 2)) {
        *(s16 *)(st + 8) = (s16) (*(s16 *)(st + 8) - arg1);
        temp_f0 = *(f32 *)(obj + 0x1C);
        temp_f2 = *(f32 *)(obj + 0x24);
        *(s16 *)obj = (s16) (Arctanf(*(f32 *)(obj + 0x1C), *(f32 *)(obj + 0x24)) - 0x8000);
        *(s16 *)(obj + 2) = (s16) Arctanf(*(f32 *)(obj + 0x20), sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)));
        *(s16 *)(obj + 4) = (s16) (*(s16 *)(obj + 4) + (*(s8 *)(st + 0xB) * 0xE));
        if (*(u8 *)(st + 0xC) != 0) {
            temp_v1_2 = *(u8 **)st;
            temp_v0_2 = *(u8 **)(*(u8 **)(temp_v1_2 + 0x6C) + (*(s8 *)(temp_v1_2 + 0x3A) * 4));
            *(s32 *)(obj + 0x84) = 0;
            if (temp_v0_2 != NULL) {
                if (*(s8 *)(temp_v0_2 + 0xA) != 0) {
                    SquaddieLightAndAnimate(temp_v1_2);
                }
                tgt = *(u8 **)(temp_v0_2 + 0x68) + (*(u8 *)(st + 0xD) * 0xC);
                *(f32 *)(obj + 0xC) = *(f32 *)(tgt + 0);
                *(f32 *)(obj + 0x10) = *(f32 *)(tgt + 4);
                *(f32 *)(obj + 0x14) = *(f32 *)(tgt + 8);
            }
        } else {
            if ((*(u16 *)(fl + 2) != 0) && !(fl[0] & 1)) {
                bloodSpurtAdd(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(s32 *)(obj + 0x14),
                              -*(f32 *)(fl + 4), -*(f32 *)(fl + 8), -*(f32 *)(fl + 0xC),
                              (s32) (**(f32 **)(obj + 0x54) * 255.0f), 1, 1.0f);
            }
            temp_t1 = fl[0] & 1;
            if ((temp_t1 == 0) && (*(f32 *)(fl + 0x14) > 2.0f)) {
                *(s32 *)(obj + 0x84) = 1;
                partUpdateTriggers(obj, arg1);
            } else if ((temp_t1 != 0) && ((*(f32 *)(fl + 0x10) - *(f32 *)(obj + 0x10)) > 10.0f)) {
                *(s32 *)(obj + 0x84) = 8;
                partUpdateTriggers(obj, arg1);
            } else {
                *(s32 *)(obj + 0x84) = 0;
            }
        }
    } else {
        temp_v1_3 = *(u8 *)(obj + 0x39);
        temp_t0 = arg1 * 4;
        if (temp_t0 < (s32) temp_v1_3) {
            *(u8 *)(obj + 0x39) = (u8) (temp_v1_3 - temp_t0);
        } else {
            objFreeObject(obj);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o153/overlay_153/zombieFlobControl.s")
#endif
