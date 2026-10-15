#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 iDeltaTime;
s32 DoesSquaddieWantToFire(f32 x, f32 y, s32 range);
s32 TryToSetMission(s32 a, s32 b, s32 c, s32 d, s32 e);
void squadsFireWeapon(s32 a, s32 b, s32 c);
void ClearMissionFields(s32 a, s32 b);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBGunTurret(void *arg0) {
    u8 *sp24;

    sp24 = *(u8 **)((u8 *)arg0 + 0x68);
    if (DoesSquaddieWantToFire(0.0f, 0.0f, 0x2000) != 0) {
        if (*(u8 *)(sp24 + 0x1A) != 0x16) {
            TryToSetMission(4, 0x16, 0, 0, 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o148/overlay_148/BTSBGunTurret.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void TurretFireMover(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *v;
    s16 *var_v1;
    s16 var_a0;
    u8 temp_t5;
    u8 temp_t8;

    v = *(u8 **)((u8 *)arg0 + 0x68);
    *arg1 = *(f32 *)(v + 0x38);
    *arg2 = *(f32 *)(v + 0x3C);
    *arg3 = *(f32 *)(v + 0x40);
    switch (*(u8 *)(v + 0x1B)) {
    default:
        var_v1 = (s16 *)(v + 0xA8);
        var_a0 = var_v1[1];
        break;
    case 1:
        var_v1 = (s16 *)(v + 0xA8);
        var_v1[1] = (s16) (var_v1[1] + (iDeltaTime * 0x7B));
        var_a0 = var_v1[1];
        if (var_a0 >= 0x2619) {
            var_v1[1] = 0x2619;
            *(u8 *)(v + 0x50) = 0x18;
            *(u8 *)(v + 0x51) = 2;
            *(u8 *)(v + 0x1B) = 4;
            var_a0 = var_v1[1];
        }
        break;
    case 4:
        temp_t5 = (u8) (*(u8 *)(v + 0x51) - 1);
        *(u8 *)(v + 0x51) = temp_t5;
        if (!temp_t5) {
            squadsFireWeapon(0, 0, 0);
            temp_t8 = (u8) (*(u8 *)(v + 0x50) - 1);
            *(u8 *)(v + 0x3) = (u8) ((((((*(u32 *)v << 25) >> 31) ^ 1) << 6) & 0x40) | (*(u8 *)(v + 0x3) & 0xFFBF));
            *(u8 *)(v + 0x51) = 2;
            *(u8 *)(v + 0x50) = temp_t8;
            if (!temp_t8) {
                *(u8 *)(v + 0x1B) = 5;
            }
        }
        var_v1 = (s16 *)(v + 0xA8);
        var_a0 = var_v1[1];
        break;
    case 5:
        var_v1 = (s16 *)(v + 0xA8);
        var_v1[1] = (s16) (var_v1[1] - (iDeltaTime * 0x7B));
        var_a0 = var_v1[1];
        if (var_a0 <= 0) {
            ClearMissionFields(1, 0);
            var_v1[1] = 0;
            var_a0 = var_v1[1];
        }
        break;
    }
    *var_v1 += var_a0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o148/overlay_148/TurretFireMover.s")
#endif
