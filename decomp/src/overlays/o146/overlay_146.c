#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_overlay_146_09200D20[];
extern u8 D_overlay_146_09200D68[];
extern s32 D_overlay_146_09200E60;
extern s32 D_overlay_146_09200E64;
extern f32 D_overlay_146_09200DD4;
extern f32 D_overlay_146_09200DD8;
extern f32 D_overlay_146_09200E10;
extern f32 D_overlay_146_09200E14;
s32 NewFlopsyFunction(void *obj, s32 arg1);
f32 Sinf(s16 angle);
s32 IsPointInRegionIdx(f32 x, f32 z, s8 region);
s32 DoesLineCrossRegionIdx(f32 x0, f32 z0, f32 x1, f32 z1, s32 region, s32 a, s32 b, s32 c);
void TryToSetAnim(s32 a, s32 b, s32 c, s32 d);
s32 TryToUpdateAnim(s32 a, s32 b);
s32 squadsGetLoudestEvent(void *obj, f32 *out);
s32 squadsPrepareToProcessSquaddie(void *obj);
u8 *squadsGetClosestPlayer(void);
void *squadsGetClosestFood(s16 x, s16 z, s32 range, s32 region);
void **objGetObjList(s32 *start, s32 *end);
void objRemoveDependancy(void *obj);
void objRegisterDependancy(void *obj, void *target);
void objFreeObject(void *obj);
f32 GetRangeSquared2D(f32 x0, f32 z0, f32 x1, f32 z1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 NewFlopsyFunction(void *obj, s32 arg1) {
    u8 *state;
    u8 *regionData;
    s32 mode;
    s32 anim;
    s32 attempts;
    s16 angle;
    f32 dist;
    f32 newX;
    f32 newZ;
    f32 sp64;
    s32 ok;

    state = *(u8 **)((u8 *)obj + 0x68);
    mode = D_overlay_146_09200D20[arg1];
    regionData = *(u8 **)(*(u8 **)(state + 0x24) + 0x68);
    anim = 0;
    squadsPrepareToProcessSquaddie(obj);
    if (((1 << D_overlay_146_09200E60) & mode) == 0) {
        return 0;
    }
    D_overlay_146_09200E60 = arg1;
    state[0x1] &= 0xFD;
    switch (D_overlay_146_09200E60) {
    case 1:
        state[0x50] = mathRnd(0xA, 0x32);
        state[0x52] = mathRnd(0x64, 0xC8);
        state[0x53] = mathRnd(-0x32, 0x32);
        anim = 0xB;
        break;
    case 2:
        anim = 0xB;
        attempts = 9;
        do {
            angle = (s16)mathRnd(-0x8000, 0x7FFF);
            dist = (f32)mathRnd(0x64, 0xFA);
            newX = *(f32 *)((u8 *)obj + 0xC) - (Sinf(angle) * dist);
            newZ = *(f32 *)((u8 *)obj + 0x14) - (Cosf(angle) * dist);
            if (IsPointInRegionIdx(*(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x14), (s8)regionData[0x7A]) != 0) {
                ok = DoesLineCrossRegionIdx(*(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x14), newX, newZ,
                                            (s8)regionData[0x7A], 0, -1, 0xFF) == 0;
            } else {
                ok = IsPointInRegionIdx(newX, newZ, (s8)regionData[0x7A]);
            }
            if (ok != 0) {
                *(f32 *)(state + 0x38) = newX;
                *(f32 *)(state + 0x40) = newZ;
                break;
            }
        } while (attempts-- != 0); /* asm: counter decremented in bnez delay slot */
        break;
    case 3:
        state[0x50] = mathRnd(0xC8, 0xFA);
        state[0x51] = mathRnd(0, 1);
        anim = 0xE;
        break;
    case 4:
        state[0x50] = mathRnd(0x32, 0x46);
        anim = 0x36;
        break;
    case 5:
        state[0x50] = mathRnd(2, 5);
        anim = 0x26;
        break;
    case 6:
    case 7:
        anim = 0xD;
        break;
    case 8:
        state[0x50] = mathRnd(3, 5);
        anim = 0x36;
        break;
    case 9:
        anim = 0xE;
        state[0x1] |= 2;
        break;
    case 10:
        squadsGetLoudestEvent(obj, &sp64);
        if (sp64 <= 0.0f) {
            state[0x50] = mathRnd(0x14, 0x28);
            anim = 0x2A;
            break;
        }
        return NewFlopsyFunction(obj, 1);
    case 11:
        state[0x50] = 0x28;
        anim = 0x29;
        break;
    case 17:
        TryToSetAnim(0xB, 0x15, 0, 0);
        state[0x50] = mathRnd(0x96, 0xFA);
        return 1;
    default:
        break;
    }
    if (anim != 0) {
        TryToSetAnim(3, anim, 0, 0);
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o146/overlay_146/NewFlopsyFunction.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Mover state (state = obj->0x68): 0x1A flag, 0x20 anim speed bits, 0x24 parent (->0x68 region data),
// 0x38/0x40 move target X/Z, 0x50 countdown, 0x52 u8 radius, 0x53 s8 heading offset, 0x64 target obj.
void FlopsyDogMover(void *obj) {
    u8 *state;
    u8 *regionData;
    u8 *player;
    u8 *other;
    u8 *target;
    void **objList;
    void *food;
    s32 listStart;
    s32 listEnd;
    s32 i;
    s32 moving;
    s32 outside;
    s32 attempts;
    s32 prevMode;
    s32 roll;
    s32 v1;
    s16 angle;
    f32 minDist;
    f32 dist;
    f32 scale;
    f32 newX;
    f32 newZ;
    f32 sinv;
    f32 cosv;
    f32 speed;
    f32 loudest;

    state = *(u8 **)((u8 *)obj + 0x68);
    regionData = *(u8 **)(*(u8 **)(state + 0x24) + 0x68);
    squadsGetClosestPlayer();
    moving = 0;
    objList = objGetObjList(&listStart, &listEnd);
    squadsPrepareToProcessSquaddie(obj);
    player = squadsGetClosestPlayer();
    minDist = D_overlay_146_09200DD4;

    /* nearest live object of type 5 (distance squared) */
    i = listStart;
    if (listStart < listEnd) {
        do {
            other = (u8 *)objList[i];
            if (*(s16 *)(other + 0x48) == 5) {
                dist = GetRangeSquared2D(*(f32 *)(other + 0xC), *(f32 *)(other + 0x14),
                                         *(f32 *)(player + 0xC), *(f32 *)(player + 0x14));
                if (dist < minDist) {
                    minDist = dist;
                }
            }
            i++;
        } while (i < listEnd);
    }

    if (state[0x1A] != 0) {
        D_overlay_146_09200E60 = 0xC;
    } else {
        outside = 0;
        if (IsPointInRegionIdx(*(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x14), (s8)regionData[0x7A]) == 0) {
            outside = 1;
        }
        /* probe up to 7 random-ish headings (asm: bnez delay slot decrements after test) */
        attempts = 6;
        if (outside == 0) {
            do {
                v1 = attempts - 3;
                angle = (s16)(*(s16 *)obj + v1 * 0x1000);
                scale = *(f32 *)(*(u8 **)((u8 *)obj + 0x4C) + 0x24);
                dist = (3.0f - (f32)((v1 > 0) ? v1 : -v1)) * scale;
                newX = *(f32 *)((u8 *)obj + 0xC) - (Sinf(angle) * dist);
                newZ = *(f32 *)((u8 *)obj + 0x14) - (Cosf(angle) * dist);
                if (IsPointInRegionIdx(newX, newZ, (s8)regionData[0x7A]) == 0) {
                    outside = 1;
                    break;
                }
            } while (attempts-- != 0);
        }

        prevMode = D_overlay_146_09200E60;
        if (outside != 0 && NewFlopsyFunction(obj, 2) != 0) {
            D_overlay_146_09200E64 = prevMode;
        } else {
            food = squadsGetClosestFood((s16)(s32)*(f32 *)((u8 *)obj + 0xC),
                                        (s16)(s32)*(f32 *)((u8 *)obj + 0x14), 0x7D0, (s8)regionData[0x7A]);
            if (food != NULL && NewFlopsyFunction(obj, 7) != 0) {
                *(void **)(state + 0x64) = food;
                objRegisterDependancy(obj, food);
            } else if (minDist < D_overlay_146_09200DD8 && NewFlopsyFunction(obj, 9) != 0) {
                /* asm: empty branch, nothing further done */
            }
        }
    }

    switch (D_overlay_146_09200E60) {
    case 0:
        NewFlopsyFunction(obj, 1);
        break;
    case 1:
        angle = (s16)(*(s16 *)obj + (*(s8 *)(state + 0x53) << 5) - 0x8000);
        sinv = Sinf(angle);
        *(f32 *)(state + 0x38) = (sinv * (f32)state[0x52]) + *(f32 *)((u8 *)obj + 0xC);
        cosv = Cosf(angle);
        *(f32 *)(state + 0x40) = (cosv * (f32)state[0x52]) + *(f32 *)((u8 *)obj + 0x14);
        TryToUpdateAnim(3, *(s32 *)(state + 0x20));
        state[0x50]--;
        if (state[0x50] == 0) {
            roll = mathRnd(0, 0x64);
            if (roll >= 0x61) {
                NewFlopsyFunction(obj, 3);
            } else if (roll >= 0x5D) {
                NewFlopsyFunction(obj, 0xA);
            } else {
                NewFlopsyFunction(obj, 1);
            }
        }
        break;
    case 2:
        TryToUpdateAnim(3, *(s32 *)(state + 0x20));
        if (GetRangeSquared2D(*(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x14),
                              *(f32 *)(state + 0x38), *(f32 *)(state + 0x40)) < 600.0f) {
            D_overlay_146_09200E60 = 0;
            NewFlopsyFunction(obj, D_overlay_146_09200E64);
            D_overlay_146_09200E64 = 1;
        }
        break;
    case 3:
        moving = 1;
        TryToUpdateAnim(3, 0x3FC00000);
        state[0x50]--;
        if (state[0x50] == 0) {
            NewFlopsyFunction(obj, 4);
        }
        break;
    case 4:
        moving = 1;
        TryToUpdateAnim(3, 0x3F800000);
        state[0x50]--;
        if (state[0x50] == 0) {
            NewFlopsyFunction(obj, 1);
        }
        break;
    case 5:
        moving = 1;
        if (TryToUpdateAnim(3, 0x3F800000) != 0) {
            state[0x50]--;
            if (state[0x50] == 0) {
                NewFlopsyFunction(obj, 6);
            }
        }
        break;
    case 6:
        *(f32 *)(state + 0x38) = *(f32 *)(player + 0xC);
        TryToUpdateAnim(3, *(s32 *)(state + 0x20));
        *(f32 *)(state + 0x40) = *(f32 *)(player + 0x14);
        if (GetRangeSquared2D(*(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x14),
                              *(f32 *)(state + 0x38), *(f32 *)(state + 0x40)) < 2000.0f) {
            NewFlopsyFunction(obj, 1);
        }
        break;
    case 7:
        target = *(u8 **)(state + 0x64);
        *(f32 *)(state + 0x38) = *(f32 *)(target + 0xC);
        TryToUpdateAnim(3, *(s32 *)(state + 0x20));
        *(f32 *)(state + 0x40) = *(f32 *)(target + 0x14);
        if (GetRangeSquared2D(*(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x14),
                              *(f32 *)(state + 0x38), *(f32 *)(state + 0x40)) < 2000.0f) {
            NewFlopsyFunction(obj, 8);
        }
        break;
    case 8:
        moving = 1;
        if (TryToUpdateAnim(3, 0x3F800000) != 0) {
            state[0x50]--;
            if (state[0x50] == 0) {
                NewFlopsyFunction(obj, 1);
                objFreeObject(*(void **)(state + 0x64));
            }
        }
        break;
    case 9:
        *(f32 *)(state + 0x38) = *(f32 *)(player + 0xC);
        *(f32 *)(state + 0x40) = *(f32 *)(player + 0x14);
        speed = *(f32 *)(state + 0x20) * D_overlay_146_09200E10;
        TryToUpdateAnim(3, *(s32 *)&speed);
        if (D_overlay_146_09200E14 < minDist) {
            NewFlopsyFunction(obj, 1);
        }
        break;
    case 10:
        moving = 1;
        TryToUpdateAnim(3, *(s32 *)(state + 0x20));
        squadsGetLoudestEvent(obj, &loudest);
        if (loudest > 0.0f) {
            NewFlopsyFunction(obj, 0xB);
        }
        break;
    case 11:
        TryToUpdateAnim(3, 0x3F800000);
        state[0x50]--;
        if (state[0x50] == 0) {
            NewFlopsyFunction(obj, 1);
        }
        break;
    case 12:
        if (state[0x1A] == 0) {
            NewFlopsyFunction(obj, 1);
        }
        break;
    default:
        break;
    }

    if (moving != 0) {
        *(f32 *)(state + 0x38) = *(f32 *)((u8 *)obj + 0xC);
        *(f32 *)(state + 0x40) = *(f32 *)((u8 *)obj + 0x14);
        *(f32 *)((u8 *)obj + 0x1C) = 0.0f;
        *(f32 *)((u8 *)obj + 0x24) = 0.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o146/overlay_146/FlopsyDogMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 FlopsyDogFacer(void *obj, f32 arg1, f32 arg2) {
    u8 *state;
    u8 *target;
    s16 offset;

    state = *(u8 **)((u8 *)obj + 0x68);
    switch (D_overlay_146_09200E60) {
    case 3:
        offset = (state[0x51] != 0) ? 0x7724 : -0x7724;
        *(s16 *)(state + 0x10) = offset;
        state[0x6] = state[0x6] | 0x40;
        return (s16)(*(s16 *)obj + offset);
    case 5:
        target = *(u8 **)(state + 0x64);
        return (s16)Arctanf(*(f32 *)((u8 *)obj + 0xC) - *(f32 *)(target + 0xC),
                            *(f32 *)((u8 *)obj + 0x14) - *(f32 *)(target + 0x14));
    case 8:
    case 10:
    case 11:
    case 17:
        return *(s16 *)obj;
    default:
        return (s16)(Arctanf(arg1 - *(f32 *)((u8 *)obj + 0xC), arg2 - *(f32 *)((u8 *)obj + 0x14)) - 0x8000);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o146/overlay_146/FlopsyDogFacer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FlopsyDogSpotPlayer(void *obj) {
    u8 *state;

    state = *(u8 **)((u8 *)obj + 0x68);
    state[0] = state[0] & 0xFFDF;
    NewFlopsyFunction(obj, 5);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o146/overlay_146/FlopsyDogSpotPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FlopsyDogFoodGone(void *obj) {
    u8 *state;

    state = *(u8 **)((u8 *)obj + 0x68);
    squadsPrepareToProcessSquaddie(obj);
    if (D_overlay_146_09200E60 == 7 || D_overlay_146_09200E60 == 8) {
        objRemoveDependancy(obj);
        *(u8 **)(state + 0x64) = squadsGetClosestPlayer();
        NewFlopsyFunction(obj, 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o146/overlay_146/FlopsyDogFoodGone.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 FlopsyDogCheckPriority(s32 arg0) {
    u8 idx;
    s32 mask;

    idx = D_overlay_146_09200D68[arg0];
    mask = D_overlay_146_09200D20[idx];
    if (idx == 0) {
        return 0;
    }
    return (1 << D_overlay_146_09200E60) & mask;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o146/overlay_146/FlopsyDogCheckPriority.s")
#endif
