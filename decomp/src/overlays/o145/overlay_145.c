#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 DoesSquaddieWantToFire(f32 x, f32 y, s32 range);
s32 TryToSetMission(s32 a, s32 b, s32 c, s32 d, s32 e);
void squadsFireWeapon(s32 a, s32 b, s32 c);
void ClearMissionFields(s32 a, s32 b);
f32 Sinf(s16 angle);
void TryToSetAnim(s32 a, s32 b, s32 c, s32 d);
s32 TryToUpdateAnim(s32 a, s32 b);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBFloater(void *arg0) {
    u8 *temp_v0;
    u8 *parent;
    void *sp24;
    s32 sp20;

    temp_v0 = *(u8 **)((u8 *)arg0 + 0x68);
    parent = *(u8 **)(temp_v0 + 0x24);
    sp24 = *(void **)(parent + 0x68);
    if (*(u8 *)(temp_v0 + 0x1A) != 5) {
        if ((DoesSquaddieWantToFire(0.0f, 0.0f, 0x7FFF) != 0) && (TryToSetMission(4, 5, 0, 0, 0) != 0)) {
            sp20 = mathRnd(0, 0x32);
            if (*(u8 *)((u8 *)sp24 + 0xC) >= (mathRnd(0, 0x32) + sp20)) {
                squadsFireWeapon(0, 0, 0);
                squadsFireWeapon(1, 0, 0);
            }
            ClearMissionFields(1, 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o145/overlay_145/BTSBFloater.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FloaterMover(void *arg0) {
    f32 sp3C;
    f32 sp38;
    s16 sp36;
    f32 sp30;
    s16 *sp2C;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    s16 temp_v0;
    s16 temp_v0_2;
    s32 temp_t3;
    s32 temp_t7;
    u8 *temp_s0;
    u8 *temp_s1;
    u8 *temp_s2;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0x68);
    temp_s2 = *(u8 **)(temp_s1 + 0x24);
    temp_s0 = *(u8 **)(temp_s2 + 0x68);
    temp_f2 = (f32) (*(u8 *)(temp_s0 + 0x14) * 0x10);
    temp_f0 = *(f32 *)(temp_s2 + 0x10) + (f32) (*(s8 *)(temp_s0 + 0x11) * 0x10);
    sp3C = temp_f0 + temp_f2;
    sp38 = temp_f0 - temp_f2;
    if (!(*(s16 *)(temp_s1 + 0xA8) & 1)) {
        sp36 = mathRnd(0, 0xFFFF);
        temp_t3 = *(u8 *)(temp_s0 + 0x13) * 0x10;
        sp30 = (f32) mathRnd(-temp_t3, temp_t3);
        *(f32 *)(temp_s1 + 0x38) = (f32) ((Cosf(sp36) * sp30) + (*(f32 *)(temp_s2 + 0xC) + (f32) (*(s8 *)(temp_s0 + 0x10) * 0x10)));
        *(f32 *)(temp_s1 + 0x40) = (f32) ((Sinf(sp36) * sp30) + (*(f32 *)(temp_s2 + 0x14) + (f32) (*(s8 *)(temp_s0 + 0x12) * 0x10)));
        TryToSetAnim(0, 0x11, 0, 0);
        *(s16 *)(temp_s1 + 0xA8) = 1;
    }
    temp_f0_2 = *(f32 *)((u8 *)arg0 + 0x10);
    sp2C = (s16 *)(temp_s1 + 0xA8);
    if (sp3C <= temp_f0_2) {
        temp_v0 = *sp2C;
        if (!(temp_v0 & 2)) {
            *sp2C = (s16) (temp_v0 | 2);
            TryToSetAnim(0, 0x10, 0, 0);
        }
    } else if (temp_f0_2 <= sp38) {
        temp_v0_2 = *sp2C;
        if (temp_v0_2 & 2) {
            *sp2C = temp_v0_2 & 0xFFFD;
            TryToSetAnim(0, 0x11, 0, 0);
            sp36 = mathRnd(0, 0xFFFF);
            temp_t7 = *(u8 *)(temp_s0 + 0x13) * 0x10;
            sp30 = (f32) mathRnd(-temp_t7, temp_t7);
            *(f32 *)(temp_s1 + 0x38) = (f32) ((Cosf(sp36) * sp30) + (*(f32 *)(temp_s2 + 0xC) + (f32) (*(s8 *)(temp_s0 + 0x10) * 0x10)));
            *(f32 *)(temp_s1 + 0x40) = (f32) ((Sinf(sp36) * sp30) + (*(f32 *)(temp_s2 + 0x14) + (f32) (*(s8 *)(temp_s0 + 0x12) * 0x10)));
        }
    }
    if (*sp2C & 2) {
        *(f32 *)(temp_s1 + 0x3C) = (f32) (sp38 - 10.0f);
        *(s32 *)((u8 *)arg0 + 0x84) = 0;
    } else {
        *(f32 *)(temp_s1 + 0x3C) = (f32) (sp3C + 10.0f);
        *(s32 *)((u8 *)arg0 + 0x84) = 8;
    }
    TryToUpdateAnim(0, 0x3F800000);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o145/overlay_145/FloaterMover.s")
#endif
