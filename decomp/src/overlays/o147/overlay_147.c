#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 DoesSquaddieWantToFire(f32 arg0, f32 arg1, s16 arg2);
s32 TryToSetMission(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4);
void TryToSetAnim(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void *GetBaddyData(void *obj);
void *squadsGetClosestPlayer(void);
void squadsFireWeapon(s32 arg0, s32 arg1, s32 arg2, void *arg3);
void squadsGetFormationPosition(s32 arg0, u8 arg1, f32 *arg2, f32 *arg3, f32 *arg4);
void ClearMissionFields(s32 arg0, s32 arg1);
f32 GetRange(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
f32 Sinf(s16 angle);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBGalaxianCorkScrew(Object *obj) {
    u8 *racer;
    Object *child;
    u8 *childRacer;
    s32 rnd1;
    s32 rnd2;

    racer = (u8 *)obj->racer;
    child = *(Object **)(racer + 0x24);
    childRacer = (u8 *)child->racer;
    if (DoesSquaddieWantToFire(0.0f, 0.0f, 0x7FFF) != 0) {
        rnd1 = mathRnd(0, 0x32);
        rnd2 = mathRnd(0, 0x32);
        if ((rnd1 + rnd2) < (s32)childRacer[0xE]) {
            if ((racer[0x1A] != 0x12) && (TryToSetMission(5, 0x12, 0, 0, 0) != 0)) {
                TryToSetAnim(6, 0x12, 5, 0);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o147/overlay_147/BTSBGalaxianCorkScrew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CorkScrewAttackMover(Object *obj, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *racer;
    Object *player;
    void *baddy;
    s32 leader;
    s16 yaw;
    s16 sp34;
    f32 radius;
    u8 tmp;

    racer = (u8 *)obj->racer;
    player = squadsGetClosestPlayer();
    baddy = GetBaddyData(obj);
    leader = *(s32 *)(racer + 0x24);
    *(Object **)(racer + 0x64) = player;

    if (racer[0x52] != 0) {
        racer[0x52] = (u8)(racer[0x52] - 1);
        obj->segment.trans.z_rotation =
            (s16)(obj->segment.trans.z_rotation + (((s8)racer[0x53]) << 11));
    } else {
        racer[0x3] = (u8)(racer[0x3] & 0xFFDF);
    }

    switch (racer[0x1B]) {
    case 1:
        yaw = (s16)(mathRnd(-0x2000, 0x2000) + player->segment.trans.y_rotation);
        sp34 = (s16)mathRnd(0x226, 0x28A);
        radius = (f32)sp34;
        *(f32 *)(racer + 0x38) = player->segment.trans.x_position - Sinf(yaw) * radius;
        *(f32 *)(racer + 0x3C) = (f32)mathRnd(0x3C, 0xC8) + player->segment.trans.y_position;
        *(f32 *)(racer + 0x40) = player->segment.trans.z_position - Cosf(yaw) * radius;
        racer[0x1B] = 2;
        racer[0x52] = 0x20;
        *(s8 *)(racer + 0x53) = (s8)mathRnd(-2, 3);
        if (*(s8 *)(racer + 0x53) == 0) {
            *(s8 *)(racer + 0x53) = -3;
        }
        racer[0x3] = (u8)(racer[0x3] | 0x20);
        break;

    case 2:
        *arg1 = *(f32 *)(racer + 0x38);
        *arg2 = *(f32 *)(racer + 0x3C);
        *arg3 = *(f32 *)(racer + 0x40);
        if (GetRange(obj->segment.trans.x_position, obj->segment.trans.y_position,
                     obj->segment.trans.z_position, *arg1, *arg2, *arg3) < 200.0f) {
            racer[0x1B] = 3;
        }
        break;

    case 3:
        *arg1 = player->segment.trans.x_position;
        *arg2 = player->segment.trans.y_position + 80.0f;
        *arg3 = player->segment.trans.z_position;
        if (GetRange(obj->segment.trans.x_position, obj->segment.trans.y_position,
                     obj->segment.trans.z_position, *arg1, *arg2, *arg3) < 600.0f) {
            racer[0x1B] = 4;
            racer[0x50] = 6;
            racer[0x51] = 1;
        }
        break;

    case 4:
        *arg1 = player->segment.trans.x_position;
        *arg2 = player->segment.trans.y_position + 80.0f;
        *arg3 = player->segment.trans.z_position;
        tmp = (u8)(racer[0x51] - 1);
        racer[0x51] = tmp;
        if (tmp == 0) {
            squadsFireWeapon((*(u32 *)racer >> 6) & 1, 0, 0, baddy);
            if (*(u32 *)((u8 *)baddy + 0x24) & 0x40) {
                racer[0x3] = (u8)(((((((*(u32 *)racer >> 6) & 1) ^ 1) << 6) & 0x40)) |
                                  (racer[0x3] & 0xFFBF));
            }
            tmp = (u8)(racer[0x50] - 1);
            racer[0x51] = 2;
            racer[0x50] = tmp;
            if (tmp == 0) {
                yaw = (s16)(mathRnd(-0x2000, 0x2000) + player->segment.trans.y_rotation);
                radius = (f32)0x320;
                *(f32 *)(racer + 0x38) = player->segment.trans.x_position - Sinf(yaw) * radius;
                *(f32 *)(racer + 0x3C) = (f32)mathRnd(0x258, 0x28A) + player->segment.trans.y_position;
                *(f32 *)(racer + 0x40) = player->segment.trans.z_position - Cosf(yaw) * radius;
                racer[0x1B] = 6;
            }
        }
        break;

    case 6:
        *arg1 = *(f32 *)(racer + 0x38);
        *arg2 = *(f32 *)(racer + 0x3C);
        *arg3 = *(f32 *)(racer + 0x40);
        if (GetRange(obj->segment.trans.x_position, obj->segment.trans.y_position,
                     obj->segment.trans.z_position, *arg1, *arg2, *arg3) < 200.0f) {
            racer[0x1B] = 7;
        }
        break;

    case 7:
        squadsGetFormationPosition(leader, racer[0x15], arg1, arg2, arg3);
        if (GetRange(obj->segment.trans.x_position, obj->segment.trans.y_position,
                     obj->segment.trans.z_position, *arg1, *arg2, *arg3) < 200.0f) {
            ClearMissionFields(1, 0xC8);
        }
        break;

    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o147/overlay_147/CorkScrewAttackMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 CorkScrewAttackFacer(Object *obj, s32 arg1, s32 arg2, s32 arg3) {
    u8 *racer;

    racer = (u8 *)obj->racer;
    if (racer[0x1B] < 5) {
        return 2;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o147/overlay_147/CorkScrewAttackFacer.s")
#endif
