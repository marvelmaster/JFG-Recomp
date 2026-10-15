#include "common.h"

#ifdef VERSION_kiosk
const char D_800AFDB0[] = "fragment killed squaddie\n";
#endif

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 D_801047E0_B1750;
extern s32 D_801047F0_B1760;
extern s32 D_80104804_B1774;
extern MemoryPoolSlot *D_801047E4_B1754;
extern MemoryPoolSlot *D_801047E8_B1758;
extern MemoryPoolSlot *D_801047EC_B175C;
extern MemoryPoolSlot *D_801047F4_B1764;
extern MemoryPoolSlot *D_801047F8_B1768;
extern MemoryPoolSlot *D_801047FC_B176C;
extern MemoryPoolSlot *D_80104800_B1770;
extern u8 D_80104C68_B1BD8[];
extern f32 *D_80104DF8_B1D68[];
extern u8 D_80104808_B1778[];
s32 trackCylinderIntersect(f32 *, f32 *, f32 *, f32 *, f32, f32 *, f32 *);
s32 trackSphereIntersect(f32 *, f32 *, f32 *, f32, f32 *, f32 *);
void matrixTransposeVectorMultiply(void *arg0, void *arg1, f32 *arg2);
void mathOneFloatRPY(void *angles, f32 *vec);
Object **objGetObjList(s32 *arg0, s32 *arg1);
s32 trackNearestIntersection(f32 arg0, f32 arg1, void *arg2, f32 *arg3, f32 *arg4, void *arg5, s32 arg6, s32 arg7);
s32 hitVectorCheck(s32 arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5);
void *trackBlockDim(f32, f32, s16, s32, s32);
s16 trackGetBlock(f32, f32, s16, f32);
void func_8007EA44(void *arg0, s32 arg1);
void func_8007EBEC(void *arg0);
extern u8 multiGameType;
extern u8 multiPlayer;
extern u8 multiPlayerGame;
void hitBridgeMoveY(s8 *arg0, s32 arg1, void *arg2, void *arg3);
void **objGetPlayerlist(s32 *);
void matrix_XYZ_YPR_SCL(s16 *arg0, void *arg1, void *arg2);
void matrix_SCL_RPY_XYZ(void *arg0, void *arg1);
void mathOneFloatPY(s16 *arg0, f32 *arg1);
void *mainGetGameCharacter(s8 arg0, s8 arg1);
void controlGetGunBarrelPos(void *obj, void *state, f32 *x, f32 *y, f32 *z);
void amSndPlay(u16 soundID, void *handlePtr);
s32 hitGetModCompareMask(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void GenerateSpitTexture(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
s32 trackClip3D(f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *);
void amDittyPlay(s32 id);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void objFreeObject(void *obj);
void explosionStart(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5);
void mainIncreaseWeaponKills(s32 arg0);
void mainIncreaseWeaponHits(s32 arg0);
void controlDecapitatePlayer(void *obj);
void controlAlterMood(void *obj, s32 arg1, s32 arg2, s32 arg3);
void ShirukenBounce(void *arg0, void *arg1);
void ShirukenBounce_1arg(void *arg0); /* NM link alias of ShirukenBounce (asm passes 1 arg) */
void *squadsDecapitateSquaddie(void *obj, s32 arg1, s32 arg2, s32 arg3);
void squadsSaveTribal(void *arg0, void *arg1);
void GetBaddyData(void *arg0, void *arg1, s32 arg2, s32 arg3);
void bloodHitSpriteAdd(void *arg0, void *arg1);
void instQueueMsg(f32 x, f32 y, f32 z, s32 scale, s32 sub);
void func_8007E2F0(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
f32 Sinf(s16 angle);
void *objGetPlayerNo(s32 arg0);
s16 mathDiffAngle(s16 arg0, u16 arg1);
s32 squadsElectrocuteSquaddie(void *arg0, void *arg1);
void squadsPlayerShootsSquaddie(void *arg0);
s32 hitPlayerKilledPlayer(void *arg0, void *arg1);
void mizarHitCallBack(void *arg0, void *arg1, void *arg2);
void sprintShipCollision(void *arg0, void *arg1, void *arg2);
void rockstormHitCallBack(f32 x, f32 y, s32 arg2, s32 arg3, s32 arg4);
void func_8007D660(void *arg0, void *arg1, void *arg2, void *arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitInit(void) {
    D_801047E4_B1754 = mmAlloc(0x140, 0xFFFFU);
    D_801047E8_B1758 = mmAlloc(0x400, 0xFFFFU);
    D_801047EC_B175C = mmAlloc(0x400, 0xFFFFU);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitReset(void) {
    LevelHeader *lvl;

    D_801047E0_B1750 = 0;
    lvl = levelGetLevel();
    D_80104800_B1770 = mmAlloc(*(s16 *)((u8 *)lvl + 0xF0) * 0x30, 0xFFFFU);
    D_801047F4_B1764 = mmAlloc(*(s16 *)((u8 *)lvl + 0xEE) * 4, 0xFFFFU);
    D_801047F8_B1768 = mmAlloc(*(s16 *)((u8 *)lvl + 0xEE) * 2, 0xFFFFU);
    D_801047FC_B176C = mmAlloc(*(s16 *)((u8 *)lvl + 0xEE) * 2, 0xFFFFU);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitReset.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitFree(void) {
    mmFree(D_80104800_B1770);
    mmFree(D_801047F4_B1764);
    mmFree(D_801047F8_B1768);
    mmFree(D_801047FC_B176C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11) {
    u8 *obj = (u8 *)arg0;
    u8 *hit = *(u8 **)(obj + 0x4C);
    u8 *ent;
    u8 *sub;
    u8 *src;
    u8 *lst;
    u8 *pp;
    u8 *tv;
    f32 rv[3];
    f32 vec[3];
    f32 r;
    s16 count;
    s32 n;

    if (hit == NULL) {
        return;
    }
    *(s16 *)(hit + 0x06) = arg1;
    hit[0x30] = (u8)arg2;
    hit[0x31] = 0;
    hit[0x09] = (u8)arg3;
    *(s16 *)(hit + 0x00) = arg4;
    *(s16 *)(hit + 0x02) = arg5;
    *(s16 *)(hit + 0x04) = arg6;
    *(f32 *)(hit + 0x18) = *(f32 *)(obj + 0x0C);
    *(f32 *)(hit + 0x1C) = *(f32 *)(obj + 0x10);
    *(f32 *)(hit + 0x20) = *(f32 *)(obj + 0x14);
    if ((arg4 | arg5 | arg6) != 0) {
        vec[0] = (f32)arg4;
        vec[1] = (f32)arg5;
        vec[2] = (f32)arg6;
        mathOneFloatRPY(obj, vec);
        *(f32 *)(hit + 0x18) = *(f32 *)(hit + 0x18) + vec[0] * *(f32 *)(obj + 0x08);
        *(f32 *)(hit + 0x1C) = *(f32 *)(hit + 0x1C) + vec[1] * *(f32 *)(obj + 0x08);
        *(f32 *)(hit + 0x20) = *(f32 *)(hit + 0x20) + vec[2] * *(f32 *)(obj + 0x08);
    }
    *(f32 *)(hit + 0x0C) = *(f32 *)(hit + 0x18);
    *(f32 *)(hit + 0x10) = *(f32 *)(hit + 0x1C);
    *(f32 *)(hit + 0x14) = *(f32 *)(hit + 0x20);
    *(f32 *)(hit + 0x24) = *(f32 *)(obj + 0x08) * arg7;
    *(f32 *)(hit + 0x28) = *(f32 *)(obj + 0x08) * arg8;
    *(f32 *)(hit + 0x34) = arg9;
    hit[0x2E] = 0x64;
    hit[0x2F] = 0x64;
    *(s16 *)(hit + 0x2C) = 0;
    hit[0x08] = (u8)((hit[0x08] | 0x80) & 0xBF);
    *(f32 *)(hit + 0x38) = arg10;
    count = *(s16 *)(hit + 0x32);
    *(u16 *)(hit + 0x0A) = arg11;

    if (count != 0 && *(s16 *)(obj + 0x4A) != 0xE6) {
        ent = *(u8 **)(hit + 0x40);
        sub = **(u8 ***)(obj + 0x6C);
        src = *(u8 **)(sub + 0x00);
        pp = *(u8 **)(sub + 0x70);
        lst = *(u8 **)(src + 0x38);
        n = count;
        do {
            if (*(s8 *)(src + 0x4E) != 0) {
                *(f32 *)(ent + 0x18) = *(f32 *)pp;
                pp += 0xC;
                *(f32 *)(ent + 0x1C) = *(f32 *)(pp - 8);
                *(f32 *)(ent + 0x20) = *(f32 *)(pp - 4);
            } else {
                tv = *(u8 **)(sub + 0x04) + *(u16 *)lst * 0xA;
                rv[0] = (f32)*(s16 *)(tv + 0);
                rv[1] = (f32)*(s16 *)(tv + 2);
                rv[2] = (f32)*(s16 *)(tv + 4);
                mathOneFloatRPY(obj, rv);
                *(f32 *)(ent + 0x18) = rv[0] + *(f32 *)(obj + 0x0C);
                *(f32 *)(ent + 0x1C) = rv[1] + *(f32 *)(obj + 0x10);
                *(f32 *)(ent + 0x20) = rv[2] + *(f32 *)(obj + 0x14);
            }
            n -= 1;
            r = *(f32 *)(lst + 0x08) * *(f32 *)(obj + 0x08);
            ent += 0x34;
            lst += 0xC;
            *(f32 *)(ent - 0x10) = r;
            *(f32 *)(ent - 0xC) = r;
        } while (n > 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitInitObjectHit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8007A638(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *hit = (u8 *)arg1;
    u8 *ent = *(u8 **)(hit + 0x40);
    u8 *sub = (*(u8 ***)(obj + 0x6C))[*(s8 *)(obj + 0x3A)];
    f32 *pts = *(f32 **)(sub + 0x70);
    u8 *cur;
    f32 *pv;
    f32 r0;
    f32 minX, maxX, minY, maxY, minZ, maxZ;
    f32 x, y, z, rx, ry;
    f32 cx, cy, cz, dx, dz, dy, len;
    s16 count;
    s32 a2;

    r0 = *(f32 *)(ent + 0x24);
    minX = pts[0] - r0;
    maxX = pts[0] + r0;
    minY = pts[1] - *(f32 *)(ent + 0x28);
    maxY = pts[1] + *(f32 *)(ent + 0x28);
    minZ = pts[2] - r0;
    maxZ = pts[2] + r0;

    count = *(s16 *)(hit + 0x32);
    cur = ent + 0x34;
    pv = pts + 3;
    a2 = 1;
    if (count >= 2) {
        do {
            x = pv[0];
            y = pv[1];
            z = pv[2];
            rx = *(f32 *)(cur + 0x24);
            ry = *(f32 *)(cur + 0x28);
            if (x - rx < minX) {
                minX = x - rx;
            }
            a2 += 1;
            pv += 3;
            if (y - ry < minY) {
                minY = y - ry;
            }
            if (z - rx < minZ) {
                minZ = z - rx;
            }
            if (maxX < x + rx) {
                maxX = x + rx;
            }
            if (maxY < y + ry) {
                maxY = y + ry;
            }
            if (maxZ < z + rx) {
                maxZ = z + rx;
            }
            cur += 0x34;
        } while (a2 < count);
    }

    cx = (minX + maxX) * 0.5f;
    cz = (minZ + maxZ) * 0.5f;
    dx = maxX - cx;
    dz = maxZ - cz;
    cy = (minY + maxY) * 0.5f;
    if (*(u8 *)(hit + 0x30) == 1) {
        dy = maxY - cy;
        len = sqrtf(dy * dy + (dx * dx + dz * dz));
        *(f32 *)(hit + 0x24) = len;
        *(f32 *)(hit + 0x28) = len;
    } else {
        *(f32 *)(hit + 0x24) = sqrtf(dx * dx + dz * dz);
        *(f32 *)(hit + 0x28) = maxY - cy;
    }
    *(f32 *)(hit + 0x0C) = cx;
    *(f32 *)(hit + 0x10) = cy;
    *(f32 *)(hit + 0x14) = cz;
    *(s16 *)(hit + 0x00) = (s16)(s32)(cx - *(f32 *)(obj + 0x0C));
    *(s16 *)(hit + 0x02) = (s16)(s32)(cy - *(f32 *)(obj + 0x10));
    *(s16 *)(hit + 0x04) = (s16)(s32)(cz - *(f32 *)(obj + 0x14));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007A638.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8007A944(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *hit = (u8 *)arg1;
    u8 *ent;
    u8 *sub;
    u8 *src;
    u8 *lst;
    u8 *pp;
    u8 *tv;
    f32 rv[3];
    f32 r;
    f32 v;
    s16 n;

    if (hit == NULL) {
        return;
    }
    if (*(s16 *)(hit + 0x32) != 0) {
        n = *(s16 *)(hit + 0x32);
        if (*(s16 *)(obj + 0x4A) != 0xE6) {
            ent = *(u8 **)(hit + 0x40);
            sub = **(u8 ***)(obj + 0x6C);
            src = *(u8 **)(sub + 0x00);
            pp = *(u8 **)(sub + 0x70);
            lst = *(u8 **)(src + 0x38);
            do {
                *(u16 *)(ent + 0x0A) = (u16)(*(u16 *)(ent + 0x0A) & ~0x60);
                *(f32 *)(ent + 0x18) = *(f32 *)(ent + 0x0C);
                *(f32 *)(ent + 0x1C) = *(f32 *)(ent + 0x10);
                *(f32 *)(ent + 0x20) = *(f32 *)(ent + 0x14);
                if (*(s8 *)(src + 0x4E) != 0) {
                    v = *(f32 *)pp;
                    pp += 0xC;
                    *(f32 *)(ent + 0x0C) = v;
                    *(f32 *)(ent + 0x10) = *(f32 *)(pp - 8);
                    *(f32 *)(ent + 0x14) = *(f32 *)(pp - 4);
                } else {
                    tv = *(u8 **)(sub + 0x04) + *(u16 *)lst * 0xA;
                    rv[0] = (f32)*(s16 *)(tv + 0);
                    rv[1] = (f32)*(s16 *)(tv + 2);
                    rv[2] = (f32)*(s16 *)(tv + 4);
                    mathOneFloatRPY(obj, rv);
                    *(f32 *)(ent + 0x0C) = rv[0] + *(f32 *)(obj + 0x0C);
                    *(f32 *)(ent + 0x10) = rv[1] + *(f32 *)(obj + 0x10);
                    *(f32 *)(ent + 0x14) = rv[2] + *(f32 *)(obj + 0x14);
                }
                n -= 1;
                if ((*(u32 *)(ent + 0x30) >> 31) != 0) {
                    r = *(f32 *)(lst + 0x08) * *(f32 *)(obj + 0x08);
                    *(f32 *)(ent + 0x24) = r;
                    *(f32 *)(ent + 0x28) = r;
                    ent[0x30] = (u8)(ent[0x30] & 0x7F);
                    *(f32 *)(ent + 0x18) = *(f32 *)(ent + 0x0C);
                    *(f32 *)(ent + 0x1C) = *(f32 *)(ent + 0x10);
                    *(f32 *)(ent + 0x20) = *(f32 *)(ent + 0x14);
                }
                ent += 0x34;
                lst += 0xC;
            } while (n > 0);
            if (*(s16 *)(obj + 0x48) == 1) {
                func_8007A638(arg0, arg1);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007A944.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-frame hit update. Layouts (raw offsets, cf. hitInitObjectHit / hitSquashCheck /
// func_8007D660 above):
//   Object: +0x00 s16 yaw, +0x08 f32 scale, +0x0C/+0x10/+0x14 f32 pos, +0x1C/+0x20/+0x24
//           f32 velocity, +0x2C s16 id, +0x40 aux (+0x2F u8 percent), +0x48 s16 type,
//           +0x4C hit record, +0x54 f32 *scale2, +0x5C sub (+0x118 pos, +0x124/+0x126/+0x128
//           rot, +0x12E flag), +0x68 state, +0x7C u8 *flags, +0x8C ptr.
//   Hit record: +0x00/+0x02/+0x04 s16 rot, +0x06 s16 hp, +0x08 u8 flags (0x10, 0x20, 0x0F),
//           +0x09 u8 list flags (0x2 pair test, 0x4 list 3, 0x8 sub copy, 0x13 list 2),
//           +0x0A u16 flags (bit0 active, 0x60 cleared), +0x0C/+0x10/+0x14 f32 pos,
//           +0x18/+0x1C/+0x20 f32 prev pos, +0x24/+0x28 f32 radius, +0x31 s8 index,
//           +0x3C owner, +0x40 entry list (0x34 stride: +0x2C s16 score, +0x2F u8 percent,
//           +0x30 u32 flags: 0x40000000 immune, 0x20000000 zero-out).
//   Pair entry (hitVectorCheck output, 0x1C stride): +0x00 object, +0x04 hit record,
//           +0x08 entry, +0x10/+0x14/+0x18 f32 contact point.
//   State: +0x00 ptr, +0x08 s16 / s8, +0x0C s32, +0x10 u8, +0x18/+0x1A/+0x1C s16,
//           +0x24 ptr, +0x28 u16 flags, +0x30 s32, +0x39 s8, +0x5C s32, +0x60 u8,
//           +0x64 ptr, +0x6C/+0x70 f32, +0x7C s8, +0x7A/+0x7C/+0x7E s16, +0x149 u8,
//           +0xA38 ptr, +0xA48/+0xA4C/+0xA50 f32, +0xA78 s16 (0x98), +0x6C4 ptr,
//           +0x6C8/+0x6CC/+0x6D0 f32 (0xAE).
//   Racer (type 0x18): +0x55 u8, +0xA6 s16.
void hitUpdate(void) {
    s32 objStart;
    s32 objEnd;
    u8 **objs;
    s32 i;
    s32 j;
    s32 cntB;
    s32 cntC;
    u8 *vents;
    s32 cnt;
    s32 endOff;
    s32 fp;
    f32 vec[3];

    objs = (u8 **)objGetObjList(&objStart, &objEnd);
    cntB = 0;
    cntC = 0;
    D_801047E0_B1750 = 0;

    for (i = objStart; i < objEnd; i++) {
        u8 *obj = objs[i];
        u8 *rec;
        u8 *st;
        s16 type = *(s16 *)(obj + 0x48);

        if (type == 0x18) {
            st = *(u8 **)(obj + 0x68);
            if (*(s16 *)(st + 0xA6) <= 0 || st[0x55] != 0) {
                continue;
            }
        }
        rec = *(u8 **)(obj + 0x4C);
        if (rec == NULL) {
            continue;
        }

        if (type == 0x98) {
            st = *(u8 **)(obj + 0x68);
            *(f32 *)(rec + 0x18) = *(f32 *)(obj + 0x0C);
            *(f32 *)(rec + 0x1C) = *(f32 *)(obj + 0x10);
            *(f32 *)(rec + 0x20) = *(f32 *)(obj + 0x14);
            *(f32 *)(rec + 0x0C) = *(f32 *)(st + 0xA48);
            *(f32 *)(rec + 0x10) = *(f32 *)(st + 0xA4C);
            *(f32 *)(rec + 0x14) = *(f32 *)(st + 0xA50);
        } else if (type == 0xAE) {
            st = *(u8 **)(obj + 0x68);
            *(f32 *)(rec + 0x18) = *(f32 *)(obj + 0x0C);
            *(f32 *)(rec + 0x1C) = *(f32 *)(obj + 0x10);
            *(f32 *)(rec + 0x20) = *(f32 *)(obj + 0x14);
            *(f32 *)(rec + 0x0C) = *(f32 *)(st + 0x6C8);
            *(f32 *)(rec + 0x10) = *(f32 *)(st + 0x6CC);
            *(f32 *)(rec + 0x14) = *(f32 *)(st + 0x6D0);
        } else {
            *(f32 *)(rec + 0x18) = *(f32 *)(rec + 0x0C);
            *(f32 *)(rec + 0x1C) = *(f32 *)(rec + 0x10);
            *(f32 *)(rec + 0x20) = *(f32 *)(rec + 0x14);
            if (type == 2) {
                st = *(u8 **)(obj + 0x68);
                *(f32 *)(rec + 0x0C) = *(f32 *)(st + 0x00);
                *(f32 *)(rec + 0x10) = *(f32 *)(st + 0x04);
                *(f32 *)(rec + 0x14) = *(f32 *)(st + 0x08);
            } else {
                *(f32 *)(rec + 0x0C) = *(f32 *)(obj + 0x0C);
                *(f32 *)(rec + 0x10) = *(f32 *)(obj + 0x10);
                *(f32 *)(rec + 0x14) = *(f32 *)(obj + 0x14);
            }
        }

        if ((*(s16 *)(rec + 0x00) | *(s16 *)(rec + 0x02) | *(s16 *)(rec + 0x04)) != 0) {
            vec[0] = (f32)*(s16 *)(rec + 0x00);
            vec[1] = (f32)*(s16 *)(rec + 0x02);
            vec[2] = (f32)*(s16 *)(rec + 0x04);
            pointListRPY(1, (s16 *)obj, (s32 *)vec, vec);
            *(f32 *)(rec + 0x0C) = *(f32 *)(rec + 0x0C) + vec[0] * *(f32 *)(obj + 0x08);
            *(f32 *)(rec + 0x10) = *(f32 *)(rec + 0x10) + vec[1] * *(f32 *)(obj + 0x08);
            *(f32 *)(rec + 0x14) = *(f32 *)(rec + 0x14) + vec[2] * *(f32 *)(obj + 0x08);
        }

        if ((*(u8 *)(rec + 0x09) & 8) && D_801047E0_B1750 < 0x50) {
            u8 *sub = *(u8 **)(obj + 0x5C);
            if (*(s16 *)(sub + 0x12E) == 0) {
                *(f32 *)(sub + 0x118) = *(f32 *)(obj + 0x0C);
                *(f32 *)(sub + 0x11C) = *(f32 *)(obj + 0x10);
                *(f32 *)(sub + 0x120) = *(f32 *)(obj + 0x14);
                *(s16 *)(sub + 0x128) = *(s16 *)(obj + 0x00);
                *(s16 *)(sub + 0x126) = *(s16 *)(obj + 0x02);
                *(s16 *)(sub + 0x124) = *(s16 *)(obj + 0x04);
                *(s16 *)(sub + 0x12E) = 1;
            }
            *(u8 **)((u8 *)D_801047E4_B1754 + D_801047E0_B1750 * 4) = obj;
            D_801047E0_B1750 += 1;
        }

        if (*(u16 *)(rec + 0x0A) & 1) {
            if ((*(u8 *)(rec + 0x09) & 4) && cntC < 0x100) {
                ((u8 **)D_801047EC_B175C)[cntC] = obj;
                cntC += 1;
            }
        }
        if (*(u16 *)(rec + 0x0A) & 1) {
            if ((*(u8 *)(rec + 0x09) & 0x13) && cntB < 0x100) {
                ((u8 **)D_801047E8_B1758)[cntB] = obj;
                cntB += 1;
                *(s32 *)(rec + 0x3C) = 0;
                *(u16 *)(rec + 0x0A) = (u16)(*(u16 *)(rec + 0x0A) & ~0x60);
                func_8007A944(obj, rec);
            }
        }
    }

    /* Pass 2: pairwise overlap resolution over list D_801047E8 (cntB). */
    for (i = 0; i < cntB; i++) {
        u8 *obj = (u8 *)((u8 **)D_801047E8_B1758)[i];
        u8 *rec = *(u8 **)(obj + 0x4C);

        if (*(u8 *)(rec + 0x09) & 2) {
            for (j = 0; j < cntB; j++) {
                if (i != j) {
                    u8 *oth = (u8 *)((u8 **)D_801047E8_B1758)[j];

                    if (*(s16 *)(obj + 0x48) != 0x18 || *(s16 *)(oth + 0x48) != 0x18 ||
                        squadsElectrocuteSquaddie(obj, oth) != 0) {
                        u8 *hO = *(u8 **)(oth + 0x4C);
                        f32 sumR = *(f32 *)(rec + 0x24) + *(f32 *)(hO + 0x24);
                        f32 dx = *(f32 *)(rec + 0x0C) - *(f32 *)(hO + 0x0C);
                        f32 dz = *(f32 *)(rec + 0x14) - *(f32 *)(hO + 0x14);

                        if (dx * dx + dz * dz < sumR * sumR) {
                            f32 hY = *(f32 *)(hO + 0x10);
                            f32 hR2 = *(f32 *)(hO + 0x28);
                            f32 rY = *(f32 *)(rec + 0x10);
                            f32 rR2 = *(f32 *)(rec + 0x28);

                            if (rY - rR2 <= hY + hR2 && hY - hR2 <= rY + rR2) {
                                /* sig mismatch: asm passes the two radii in f12/f14 before the pointers */
                                ((void (*)(f32, f32, void *, void *, void *, void *))func_8007D660)(
                                    hR2, rR2, obj, rec, oth, hO);
                            }
                        }
                    }
                }
            }
        }
    }

    /* Pass 3: damage / kill events for list D_801047EC (cntC). */
    for (i = 0; i < cntC; i++) {
        u8 *obj = (u8 *)((u8 **)D_801047EC_B175C)[i];
        s16 type = *(s16 *)(obj + 0x48);
        u8 *rec = *(u8 **)(obj + 0x4C);
        u8 *st = *(u8 **)(obj + 0x68);
        u8 *tgt;

        switch (type) {
        case 0x97: tgt = obj; break;
        case 0x98: tgt = *(u8 **)(st + 0xA38); break;
        case 0x99: tgt = *(u8 **)(st + 0x00); break;
        case 0x9E: tgt = *(u8 **)(st + 0x20); break;
        case 0x9F: tgt = *(u8 **)(st + 0x10); break;
        case 0xA0: tgt = *(u8 **)(st + 0x10); break;
        case 0xA2: tgt = *(u8 **)(st + 0x70); break;
        case 0xA3: tgt = *(u8 **)(st + 0x18); break;
        case 0xA4: tgt = *(u8 **)(obj + 0x8C); break;
        case 0xA5: tgt = *(u8 **)(obj + 0x8C); break;
        case 0xA8: tgt = *(u8 **)(st + 0x0C); break;
        case 0xAA: tgt = *(u8 **)(st + 0x00); break;
        case 0xAB: tgt = *(u8 **)(st + 0x10); break;
        case 0xAC: tgt = *(u8 **)(st + 0x00); break;
        case 0xAD: tgt = *(u8 **)(st + 0x00); break;
        case 0xAE: tgt = *(u8 **)(st + 0x6C4); break;
        case 0x2C: tgt = *(u8 **)(st + 0x00); break;
        default: tgt = NULL; break;
        }

        cnt = 0;
        if (type != 0x98 || *(s16 *)(st + 0xA78) != 0) {
            cnt = hitVectorCheck((s32)obj, rec, cntB, D_801047E8_B1758, &vents, tgt);
        }

        if (cnt > 0 && *(s16 *)(rec + 0x06) > 0) {
            endOff = cnt * 0x1C;
            fp = 0;
            do {
                u8 *vent = vents + fp;
                u8 *oth = *(u8 **)(vent + 0x00);
                u8 *hO = *(u8 **)(vent + 0x04);
                u8 *hent = *(u8 **)(vent + 0x08);
                s32 hpBefore;
                s32 hpAfter;
                s32 killed;
                s32 v1;
                s32 w;
                s32 pct;
                s32 atk;
                s32 hp;
                s16 typeO;

                hpBefore = *(s16 *)(hO + 0x06);
                if (*(s16 *)(oth + 0x48) == 0x18 && type == 0x98) {
                    squadsPlayerShootsSquaddie(oth);
                }

                if ((*(u32 *)(hent + 0x30) & 0x40000000) || *(u8 *)(hent + 0x2F) == 0 ||
                    *(s16 *)(hO + 0x06) < 0) {
                    if (type == 0xA2) {
                        if (*(s16 *)(hO + 0x06) >= 0) {
                            st[0x60] = 1;
                            *(s32 *)(st + 0x5C) = 0;
                            *(f32 *)(obj + 0x0C) = *(f32 *)(vent + 0x10);
                            *(f32 *)(obj + 0x10) = *(f32 *)(vent + 0x14);
                            *(f32 *)(obj + 0x14) = *(f32 *)(vent + 0x18);
                            break;
                        }
                        goto next_entry;
                    }
                    if (type == 0xA3) {
                        if (*(s16 *)(hO + 0x06) >= 0) {
                            st[0x10] = 1;
                            *(s32 *)(st + 0x0C) = 0;
                            *(f32 *)(obj + 0x0C) = *(f32 *)(vent + 0x10);
                            *(f32 *)(obj + 0x10) = *(f32 *)(vent + 0x14);
                            *(f32 *)(obj + 0x14) = *(f32 *)(vent + 0x18);
                            break;
                        }
                        goto next_entry;
                    }
                }

                /* block_97 */
                *(s8 *)(hO + 0x31) = (s8)(((s32)(hent - *(u8 **)(hO + 0x40))) / 0x34);
                hO[0x08] &= ~0x10;
                w = 0xF;

                if (*(u8 **)(oth + 0x7C) != NULL && type != 0x98) {
                    u8 *fl;

                    *(f32 *)(oth + 0x1C) = *(f32 *)(oth + 0x1C) + *(f32 *)(obj + 0x1C) * 0.2f;
                    *(f32 *)(oth + 0x20) = *(f32 *)(oth + 0x20) + *(f32 *)(obj + 0x20) * 0.2f;
                    *(f32 *)(oth + 0x24) = *(f32 *)(oth + 0x24) + *(f32 *)(obj + 0x24) * 0.2f;
                    if (*(s16 *)(oth + 0x48) == 0x40) {
                        *(s16 *)(*(u8 **)(oth + 0x68) + 0x18) = (s16)mathRnd(-0x1388, 0x1388);
                        *(s16 *)(*(u8 **)(oth + 0x68) + 0x1A) = (s16)mathRnd(-0x1388, 0x1388);
                        *(s16 *)(*(u8 **)(oth + 0x68) + 0x1C) = (s16)mathRnd(-0x1388, 0x1388);
                    } else if (*(s16 *)(oth + 0x48) == 0x99) {
                        *(s16 *)(*(u8 **)(oth + 0x68) + 0x7A) = (s16)mathRnd(-0x1388, 0x1388);
                        *(s16 *)(*(u8 **)(oth + 0x68) + 0x7C) = (s16)mathRnd(-0x1388, 0x1388);
                        *(s16 *)(*(u8 **)(oth + 0x68) + 0x7E) = (s16)mathRnd(-0x1388, 0x1388);
                        *(s32 *)(*(u8 **)(oth + 0x68) + 0x30) = 0;
                    }
                    fl = *(u8 **)(oth + 0x7C);
                    *fl &= 0xFD;
                }

                {
                    s16 d16;
                    s32 flag;

                    d16 = (s16)mathDiffAngle(*(s16 *)(oth + 0x00),
                                             Arctanf(*(f32 *)(obj + 0x0C) - *(f32 *)(rec + 0x18),
                                                     *(f32 *)(obj + 0x14) - *(f32 *)(rec + 0x20)));
                    flag = (d16 >= 0x4000);
                    if (!flag) {
                        flag = (d16 < -0x3FFF);
                    }
                    hO[0x08] = (u8)((hO[0x08] & 0xDF) | ((flag << 5) & 0x20));
                }

                switch (type) {
                case 0xA3: w = 3; break;
                case 0xA2: w = *(s8 *)(st + 0x7C); break;
                case 0xA4: w = 0xE; break;
                case 0x9E: w = *(s8 *)(st + 0x39); break;
                case 0x98: w = 4; break;
                case 0xA8: w = *(s8 *)(st + 0x08); break;
                }
                hO[0x08] = (u8)((w & 0xF) | (hO[0x08] & 0xF0));

                if (oth != NULL && *(s16 *)(oth + 0x48) == 0x18) {
                    u8 *st2 = *(u8 **)(oth + 0x68);

                    if (tgt != NULL) {
                        if (*(s16 *)(tgt + 0x48) == 0x18) {
                            u8 *tst = *(u8 **)(tgt + 0x68);
                            u8 *pobj = *(u8 **)(st2 + 0x24);

                            if (*(u8 **)(tst + 0x24) == pobj &&
                                (*(u16 *)(*(u8 **)(pobj + 0x68) + 0x28) & 0x2000) == 0) {
                                goto next_entry;
                            }
                            if (mathRnd(1, 0xA) < 4) {
                                *(u8 **)(st2 + 0x64) = tgt;
                            }
                        }
                        if (*(s16 *)(tgt + 0x48) == 1) {
                            bloodHitSpriteAdd(oth, tgt);
                            hO[0x08] |= 0x10;
                        }
                    }

                    /* block_124 */
                    if (type == 0xA3 || type == 0xA2 || type == 0x99) {
                        amSndPlayXYZ(0x98, *(f32 *)(oth + 0x0C), *(f32 *)(oth + 0x10),
                                     *(f32 *)(oth + 0x14), 4, NULL);
                    }
                    if (*(s16 *)(hO + 0x06) > 0 && !(*(u32 *)st2 & 8)) {
                        switch (type) {
                        case 0x99: mainIncreaseWeaponHits(9); break;
                        case 0x9E: mainIncreaseWeaponHits((s8)st[0x39]); break;
                        case 0xA2:
                            if (tgt != NULL && *(s16 *)(tgt + 0x48) == 1) {
                                mainIncreaseWeaponHits((s8)st[0x7C]);
                            }
                            break;
                        case 0xA3: mainIncreaseWeaponHits(3); break;
                        }
                    }
                }

                /* block_140 */
                hpAfter = *(s16 *)(hO + 0x06);
                typeO = *(s16 *)(oth + 0x48);
                if (typeO == 0x9B && hpAfter > 0) {
                    *(s16 *)(*(u8 **)(oth + 0x68) + 0x08) = 0;
                } else if (hent != hO && (*(u32 *)(hent + 0x30) & 0x20000000)) {
                    *(s16 *)(rec + 0x06) = 0;
                } else {
                    pct = *(u8 *)(hent + 0x2F);
                    if (pct == 0x64) {
                        v1 = *(s16 *)(rec + 0x06);
                    } else if (pct == 0xFF) {
                        v1 = hpAfter;
                    } else {
                        v1 = (s16)(s32)((f32)*(s16 *)(rec + 0x06) * 0.01f * (f32)pct);
                    }
                    *(s16 *)(hent + 0x2C) = (s16)(*(s16 *)(hent + 0x2C) + v1);

                    atk = *(s16 *)(rec + 0x06);
                    hp = *(s16 *)(hO + 0x06);
                    if (hp < atk) {
                        if (hp > 0) {
                            *(s16 *)(rec + 0x06) = (s16)(atk - hp);
                        }
                    } else {
                        *(s16 *)(rec + 0x06) = 0;
                    }
                    *(s16 *)(hO + 0x06) = (s16)(hp - v1);
                }

                /* B440: kill position copy */
                if (*(s16 *)(rec + 0x06) <= 0) {
                    if (type == 0x98) {
                        u8 *s4st = *(u8 **)(obj + 0x68);
                        *(f32 *)(s4st + 0xA48) = *(f32 *)(vent + 0x10);
                        *(f32 *)(s4st + 0xA4C) = *(f32 *)(vent + 0x14);
                        *(f32 *)(s4st + 0xA50) = *(f32 *)(vent + 0x18);
                    } else if (type == 0xAE) {
                        u8 *s4st = *(u8 **)(obj + 0x68);
                        *(f32 *)(s4st + 0x6C8) = *(f32 *)(vent + 0x10);
                        *(f32 *)(s4st + 0x6CC) = *(f32 *)(vent + 0x14);
                        *(f32 *)(s4st + 0x6D0) = *(f32 *)(vent + 0x18);
                    } else {
                        *(f32 *)(obj + 0x0C) = *(f32 *)(vent + 0x10);
                        *(f32 *)(obj + 0x10) = *(f32 *)(vent + 0x14);
                        *(f32 *)(obj + 0x14) = *(f32 *)(vent + 0x18);
                    }
                }

                /* B544: killed flag */
                if (typeO == 1) {
                    killed = (hpAfter >= 0x100 && *(s16 *)(hO + 0x06) < 0x100);
                } else {
                    killed = (hpAfter > 0 && *(s16 *)(hO + 0x06) <= 0);
                }

                if (killed) {
                    if (multiPlayerGame != 0) {
                        if (tgt != NULL) {
                            hitPlayerKilledPlayer(tgt, oth);
                        }
                    } else if (typeO == 0x18 && !(*(u32 *)(*(u8 **)(oth + 0x68)) & 8)) {
                        switch (type) {
                        case 0x98: mainIncreaseWeaponKills(4); break;
                        case 0x9E: mainIncreaseWeaponKills((s8)st[0x39]); break;
                        case 0xA2:
                            if (tgt != NULL && *(s16 *)(tgt + 0x48) == 1) {
                                mainIncreaseWeaponKills((s8)st[0x7C]);
                            }
                            break;
                        case 0xA3: mainIncreaseWeaponKills(3); break;
                        case 0xA4: mainIncreaseWeaponKills(0xE); break;
                        case 0xA8: mainIncreaseWeaponKills((s8)st[0x08]); break;
                        }
                    }
                }

                if (typeO == 1 && type == 0x2C) {
                    u8 *tst = *(u8 **)(tgt + 0x68);

                    if ((tst[0x13] >> 4) == 0) {
                        s16 ang;
                        u8 *pst;

                        tst[0x13] |= 0xF0;
                        ang = (s16)Arctanf(*(f32 *)(rec + 0x0C) - *(f32 *)(rec + 0x18),
                                           *(f32 *)(rec + 0x14) - *(f32 *)(rec + 0x20));
                        pst = *(u8 **)((u8 *)objGetPlayerNo(0) + 0x68);
                        pst[0x149] = 0x28;
                        *(f32 *)(pst + 0x6C) = Sinf(ang) * 10.0f;
                        *(f32 *)(pst + 0x70) = Cosf(ang) * 10.0f;
                    }
                }

                /* B77C/B780: contact hit callback */
                if (typeO == 0x18 && hpBefore != *(s16 *)(hO + 0x06) && type != 0x98) {
                    u8 *aux = *(u8 **)(oth + 0x40);
                    f32 *scl = *(f32 **)(oth + 0x54);
                    s32 a3 = 0xFF;

                    pct = *(u8 *)(aux + 0x2F);
                    if (scl != NULL) {
                        a3 = (s32)(*scl * 255.0f);
                    }
                    rockstormHitCallBack(*(f32 *)(vent + 0x10), *(f32 *)(vent + 0x14),
                                         *(s32 *)(vent + 0x18), a3, pct);
                }

                /* B814: control mood / mizar / sprint */
                if (tgt != NULL && *(u8 **)(oth + 0x4C) != NULL) {
                    if ((type == 0xA2 || type == 0x9E) && typeO == 0x18 && *(s16 *)(tgt + 0x48) == 1) {
                        if (*(s16 *)(oth + 0x2C) == 0xB7) {
                            /* sig mismatch: asm sets only a0/a1 */
                            ((void (*)(void *, s32))controlAlterMood)(tgt, killed ? 0xB : 0xA);
                        } else {
                            ((void (*)(void *, s32))controlAlterMood)(tgt, killed ? 8 : 6);
                        }
                    }
                }
                if (type == 0x97) {
                    mizarHitCallBack(oth, obj, vent);
                }
                if (typeO == 0x6C) {
                    sprintShipCollision(oth, obj, vent);
                }

            next_entry:
                fp += 0x1C;
            } while (fp < endOff && *(s16 *)(rec + 0x06) > 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hitsCheckLineOfSight(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 pos[3];
    f32 end[3];
    void *sp94;
    void *sp44;
    void *sp40;
    s32 start;
    s32 total;
    void **list;
    s32 count = 0;

    pos[0] = arg2;
    pos[1] = arg3;
    pos[2] = arg4;
    end[0] = arg5;
    end[1] = arg6;
    end[2] = arg7;
    if (trackNearestIntersection(arg2, arg3, NULL, pos, end, &sp94, 0x2000, 0) != 0) {
        return 1;
    }

    list = (void **)objGetObjList(&start, &total);
    if (start < total) {
        do {
            void *o = list[start];

            start += 1;
            if (o != arg0 && o != arg1) {
                if (*(void **)((u8 *)o + 0x4C) != NULL) {
                    u8 *p40 = *(u8 **)((u8 *)o + 0x40);

                    if (*(u16 *)(p40 + 0x14) & 0x40) {
                        ((void **)D_801047EC_B175C)[count] = o;
                        count += 1;
                    }
                }
            }
        } while (start < total);
    }
    if (count > 0) {
        count = hitVectorCheck(0, &sp44, count, (void **)D_801047EC_B175C, &sp40, arg0);
    }
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitsCheckLineOfSight.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hitVectorHitCheck(s32 arg0, void *arg1, void *arg2, f32 *arg3, s32 arg4, s32 arg5) {
    f32 *v1 = (f32 *)arg1;
    f32 dx, dy, dz;
    s32 start;
    s32 total;
    void **list;
    void *sp44;
    void *sp3C;
    s32 count = 0;

    (void)arg2;
    list = (void **)objGetObjList(&start, &total);
    if (start < total) {
        do {
            void *o = list[start];
            void *hitp;

            start += 1;
            hitp = *(void **)((u8 *)o + 0x4C);
            if (hitp != NULL) {
                u8 *p40 = *(u8 **)((u8 *)o + 0x40);

                if ((*(u16 *)(p40 + 0x14) & 0x40) && (((u8 *)hitp)[0x30] == 1 || ((u8 *)hitp)[0x30] == 2)) {
                    s16 id = *(s16 *)((u8 *)o + 0x48);

                    if (arg4 != id && arg5 != id) {
                        ((void **)D_801047EC_B175C)[count] = o;
                        count += 1;
                    }
                }
            }
        } while (start < total);
    }
    if (count > 0) {
        count = hitVectorCheck(0, &sp44, count, (void **)D_801047EC_B175C, &sp3C, arg0);
        if (count > 0 && arg3 != NULL) {
            dx = v1[0] - *(f32 *)((u8 *)sp3C + 0x10);
            dy = v1[1] - *(f32 *)((u8 *)sp3C + 0x14);
            dz = v1[2] - *(f32 *)((u8 *)sp3C + 0x18);
            *arg3 = sqrtf(dx * dx + dy * dy + dz * dz);
        }
    }
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitVectorHitCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hitPlayerAimCheck(void *arg0, f32 arg1, f32 *arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *racer = *(u8 **)(obj + 0x68);
    u8 *chr;
    s16 ang[3];
    f32 dir[3];
    f32 gun[3];
    f32 aimPt[3];  /* asm: gun + dir is stored, never read in this function */
    f32 hitBuf[3]; /* hitVectorCheck arg1: output buffer, not read here */
    f32 dx, dy, dz;
    void **list;
    void **cand;
    void *res;     /* hit result: +0x00 Object *, +0x04 hit *, +0x08 entry *, +0x10 pos */
    u8 *target;
    u8 *hitA;
    u8 *entB;
    u8 *sub;
    u8 *src;
    u8 *hitp;
    s32 start;
    s32 total;
    s32 count;
    s32 k;
    s32 flagA;
    s32 flag40;
    s32 flag20;
    u8 idx;

    chr = (u8 *)mainGetGameCharacter(*(s8 *)(racer + 0x00), *(s8 *)(racer + 0x01));
    count = 0;
    controlGetGunBarrelPos(obj, racer, &gun[0], &gun[1], &gun[2]);
    ang[0] = *(s16 *)(racer + 0x1C6);
    ang[2] = 0;
    dir[2] = -arg1;
    ang[1] = *(s16 *)(racer + 0x1C8);
    mathOneFloatPY(ang, dir);
    aimPt[0] = dir[0] + gun[0];
    aimPt[1] = dir[1] + gun[1];
    aimPt[2] = dir[2] + gun[2];

    list = (void **)objGetObjList(&start, &total);
    cand = (void **)D_801047EC_B175C;
    if (start < total) {
        do {
            void *o = list[start];

            start += 1;
            if (*(void **)((u8 *)o + 0x4C) != NULL) {
                if (*(u16 *)(*(u8 **)((u8 *)o + 0x40) + 0x14) & 0x40) {
                    cand[count] = o;
                    count += 1;
                }
            }
        } while (start < total);
    }

    if (count > 0) {
        count = hitVectorCheck(0, hitBuf, count, cand, &res, arg0);
        if (count > 0 && arg2 != NULL) {
            dx = gun[0] - *(f32 *)((u8 *)res + 0x10);
            dy = gun[1] - *(f32 *)((u8 *)res + 0x14);
            dz = gun[2] - *(f32 *)((u8 *)res + 0x18);
            *arg2 = sqrtf(dx * dx + dy * dy + dz * dz);
        }
    }
    if (count == 0) {
        return 0;
    }

    target = *(u8 **)res;
    if (chr[0x70] == 9) {
        s16 ty = *(s16 *)(target + 0x48);

        if (ty != 1 && ty != 0x5A && ty != 0x18) {
            return 0;
        }
    }
    if (*(s16 *)(target + 0x48) == 0x18 && *(s16 *)(target + 0x4A) == 0xE6) {
        return 0;
    }
    if (*(s16 *)(target + 0x48) == 1) {
        hitp = *(u8 **)(target + 0x4C);
        if (hitp != NULL && *(s16 *)(hitp + 0x06) < 0x100) {
            return 0;
        }
    }

    idx = 0xFF;
    hitA = *(u8 **)((u8 *)res + 0x04);
    entB = *(u8 **)((u8 *)res + 0x08);
    sub = ((u8 **)*(u8 **)(obj + 0x6C))[*(s8 *)(obj + 0x3A)];
    if (entB == hitA || (src = *(u8 **)sub) == NULL || src[0x2F] == 0) {
        flagA = hitA[0x2F];
        flag40 = (*(u32 *)(hitA + 0x08) & 0x40000000) != 0;
        flag20 = 0;
    } else {
        flagA = entB[0x2F];
        flag40 = (*(u32 *)(entB + 0x30) & 0x40000000) != 0;
        flag20 = (*(u32 *)(entB + 0x30) & 0x20000000) != 0;
        idx = (u8)(((u8 *)entB - *(u8 **)(hitA + 0x40)) / 0x34);
    }

    if (flag20 != 0) {
        return 0;
    }
    if (flagA == 0) {
        return 1;
    }

    if (flag40 == 0 && (chr[0x70] == 1 || chr[0x70] == 9)) {
        if (joyGetButtons(0) & 0x10) {
            /* asm: loop over the 6 target slots: pointer at racer+0x1A8+4k
             * (sub = racer+0x14 + 4*(k-5) so sub+0x1A8 is the slot), flag byte at racer+0x1C0+k */
            sub = racer + 0x14;
            k = 5;
            for (;;) {
                void *slot = *(void **)(sub + 0x1A8);

                if (slot == NULL ||
                    ((*(u16 *)(*(u8 **)(target + 0x40) + 0x14) & 0x4000) && (void *)target == slot &&
                     idx != racer[0x1C0 + k])) {
                    if (*(s32 *)(racer + 0xC4) == 0) {
                        /* sig mismatch: amSndPlay takes 2 args, asm passes 4 */
                        ((void (*)(s32, void *, void *, void *))amSndPlay)(0x1D, racer + 0xC4, sub, target);
                    }
                    *(void **)(sub + 0x1A8) = target;
                    racer[0x1C0 + k] = idx;
                    if (chr[0x70] == 9) {
                        u8 *tg = target + *(s8 *)racer;

                        tg[0x93] = 3;
                        tg[0x9B] = 1;
                        tg[0x97] = 0xFF;
                    } else {
                        u8 *tg = target + *(s8 *)racer;

                        tg[0x93] = 4;
                        tg[0x9B] = 1;
                        tg[0x97] = idx;
                    }
                    return 1;
                }
                if (slot == (void *)target) {
                    return 1;
                }
                sub -= 4;
                if (k == 0) {
                    return 1;
                }
                k -= 1;
            }
        }
    }

    /* asm: .L8007C190 - fallback single-target selection */
    if (*(void **)(racer + 0x1BC) == (void *)target) {
        return 1;
    }
    if (*(void **)(racer + 0x1BC) != NULL) {
        u8 *prev = *(u8 **)(racer + 0x1BC);

        prev[*(s8 *)racer + 0x93] = 0;
    }
    if (*(s32 *)(racer + 0xC4) == 0) {
        /* sig mismatch: amSndPlay takes 2 args, asm passes 4 (3rd = flag40) */
        ((void (*)(s32, void *, void *, void *))amSndPlay)(0x1D, racer + 0xC4, (void *)flag40, target);
    }
    *(void **)(racer + 0x1BC) = (void *)target;
    racer[0x1C5] = idx;

    if (chr[0x70] < 15) {
        switch (chr[0x70]) {
        case 0:
        case 2:
        case 3:
        case 5:
        case 7:
        case 8:
            target[*(s8 *)racer + 0x93] = 2;
            break;
        case 1:
            target[*(s8 *)racer + 0x93] = 4;
            break;
        case 4:
        case 6:
        case 11:
        case 12:
        case 14:
            target[*(s8 *)racer + 0x93] = 1;
            break;
        case 9:
            target[*(s8 *)racer + 0x93] = 3;
            break;
        case 10:
        case 13:
            target[*(s8 *)racer + 0x93] = 5;
            break;
        }
    }
    target[*(s8 *)racer + 0x97] = 0xFF;
    target[*(s8 *)racer + 0x9B] = 1;
    if (*(s16 *)(target + 0x48) == 0x6C || *(s16 *)(target + 0x48) == 0x82) {
        target[*(s8 *)racer + 0x97] = idx;
        racer[0x1C5] = idx;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitPlayerAimCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Ray segment vs. object-hit collision over the candidate list arg3 (arg2 entries).
// arg1 = ray: +0x18 origin, +0x0C end point, +0x24 radius XZ, +0x28 radius Y.
// arg0 != 0 tags the hit body (+0x3C = arg0, flags). arg4 receives the record array.
// arg5 is excluded from the list; arg5 type (+0x48) == 2 selects filter = 1, else -1.
// Candidate object: +0x48 s16 type, +0x4C hit body.
// Hit body: +0x0A u16 flags (0x40 / 0x20 when tagged), +0x0C centre, +0x24 radius XZ,
//   +0x28 radius Y, +0x30 u8 shape (1 = sphere, 2 = vertical cylinder), +0x32 s16 sub
//   count, +0x3C tag, +0x40 sub array (0x34-byte entries: +0x0C centre, +0x24 radius,
//   +0x30 word, bit 30 = skip).
// Hit record (0x1C bytes in D_80104808_B1778, max 0x28): +0x00 object, +0x04 hit body,
//   +0x08 hit body or sub entry, +0x0C t^2 (sort key), +0x10/+0x14/+0x18 hit point.
// Records are bubble-sorted ascending by the sort key. Returns the record count.
// Ray and hit tests mirror track.c trackCylinderIntersect / trackSphereIntersect usage.
s32 hitVectorCheck(s32 arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5) {
    u8 *ray = (u8 *)arg1;
    f32 *org = (f32 *)(ray + 0x18);
    f32 *dst = (f32 *)(ray + 0x0C);
    f32 radXZ = *(f32 *)(ray + 0x24);
    f32 radY = *(f32 *)(ray + 0x28);
    f32 dir[3];
    f32 rayMin[3];
    f32 rayMax[3];
    f32 tgtMin[3];
    f32 tgtMax[3];
    f32 axis[3] = { 0.0f, 1.0f, 0.0f };
    f32 base[3];
    f32 hp[3];
    f32 len;
    f32 lenSq;
    f32 radius;
    f32 tEnter;
    f32 tExit;
    f32 planeD;
    f32 planeN;
    f32 topY;
    f32 tmp;
    f32 dx;
    f32 dz;
    f32 fo;
    f32 fd;
    f32 *c;
    void **list = (void **)arg3;
    u8 *obj;
    u8 *hit;
    u8 *sub;
    u8 *rec;
    u32 word;
    s32 count = 0;
    s32 remain;
    s32 filter;
    s32 ok;
    s32 hitPlane;
    s32 noSwap;
    s32 type;
    s32 n;
    s32 j;
    s32 k;

    if (arg2 <= 0) {
        return 0;
    }
    for (k = 0; k < 3; k++) {
        dir[k] = dst[k] - org[k];
    }
    lenSq = (dir[2] * dir[2]) + ((dir[0] * dir[0]) + (dir[1] * dir[1]));
    if (!(lenSq > 0.0f)) {
        return 0;
    }
    len = sqrtf(lenSq);
    for (k = 0; k < 3; k++) {
        dir[k] /= len;
    }

    /* segment bbox (min/max per axis), expanded by the ray radius */
    for (k = 0; k < 3; k++) {
        rayMin[k] = org[k];
        rayMax[k] = dst[k];
        if (rayMax[k] < rayMin[k]) {
            tmp = rayMin[k];
            rayMin[k] = rayMax[k];
            rayMax[k] = tmp;
        }
    }
    rayMin[0] -= radXZ;
    rayMin[1] -= radY;
    rayMin[2] -= radXZ;
    rayMax[0] += radXZ;
    rayMax[1] += radY;
    rayMax[2] += radXZ;

    filter = -1;
    if (arg5 != NULL && *(s16 *)((u8 *)arg5 + 0x48) == 2) {
        filter = 1;
    }
    *(void **)arg4 = D_80104808_B1778;

    remain = arg2;
    do {
        obj = (u8 *)*list;
        list++;
        remain--;
        if (obj != (u8 *)arg5 && filter != *(s16 *)(obj + 0x48)) {
            hit = *(u8 **)(obj + 0x4C);
            c = (f32 *)(hit + 0x0C);
            tgtMin[0] = c[0] - *(f32 *)(hit + 0x24);
            tgtMin[1] = c[1] - *(f32 *)(hit + 0x28);
            tgtMin[2] = c[2] - *(f32 *)(hit + 0x24);
            tgtMax[0] = c[0] + *(f32 *)(hit + 0x24);
            tgtMax[1] = c[1] + *(f32 *)(hit + 0x28);
            tgtMax[2] = c[2] + *(f32 *)(hit + 0x24);

            /* AABB overlap of segment bbox and hit body bbox */
            ok = 1;
            for (k = 0; k < 3; k++) {
                if (rayMax[k] < tgtMin[k] || tgtMax[k] < rayMin[k]) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                type = *(u8 *)(hit + 0x30);
                radius = radXZ + *(f32 *)(hit + 0x24);
                ok = 0;
                if (type == 2) {
                    /* vertical cylinder: base / top from centre +/- radius Y */
                    base[0] = c[0];
                    base[1] = (c[1] - *(f32 *)(hit + 0x28)) - radY;
                    base[2] = c[2];
                    topY = (c[1] + *(f32 *)(hit + 0x28)) + radY;
                    if (base[1] <= org[1] && org[1] <= topY) {
                        /* origin already inside the vertical span */
                        dx = org[0] - c[0];
                        dz = org[2] - c[2];
                        if ((dx * dx) + (dz * dz) <= radius * radius) {
                            ok = 1;
                            hp[0] = org[0];
                            hp[1] = org[1];
                            hp[2] = org[2];
                            tEnter = 0.0f;
                        }
                    } else {
                        /* segment crosses the bottom or top cap plane */
                        hitPlane = 0;
                        if (org[1] <= base[1] && base[1] < dst[1]) {
                            planeD = base[1];
                            planeN = -1.0f;
                            hitPlane = 1;
                        } else if (topY <= org[1] && dst[1] < topY) {
                            planeD = -topY;
                            planeN = 1.0f;
                            hitPlane = 1;
                        }
                        if (hitPlane) {
                            fo = (org[1] * planeN) + planeD;
                            fd = (dst[1] * planeN) + planeD;
                            tEnter = (fo / (fo - fd)) * len;
                            for (k = 0; k < 3; k++) {
                                hp[k] = (dir[k] * tEnter) + org[k];
                            }
                            dx = hp[0] - c[0];
                            dz = hp[2] - c[2];
                            if ((dx * dx) + (dz * dz) <= radius * radius) {
                                ok = 1;
                            }
                        }
                    }
                    if (!ok && trackCylinderIntersect(org, dir, base, axis, radius, &tEnter, &tExit) != 0) {
                        for (k = 0; k < 3; k++) {
                            hp[k] = (dir[k] * tEnter) + org[k];
                        }
                        if (base[1] <= hp[1] && hp[1] <= topY && tEnter >= 0.0f && tEnter <= len) {
                            ok = 1;
                        }
                    }
                } else if (type == 1) {
                    /* sphere */
                    if (trackSphereIntersect(org, dir, c, radius, &tEnter, &tExit) != 0) {
                        for (k = 0; k < 3; k++) {
                            hp[k] = (dir[k] * tEnter) + org[k];
                        }
                        if ((tEnter >= 0.0f && tEnter <= len) || (tEnter < 0.0f && tExit > 0.0f)) {
                            ok = 1;
                        }
                    }
                }

                if (ok) {
                    if (*(s16 *)(hit + 0x32) == 0) {
                        /* single hit record for the object */
                        rec = D_80104808_B1778 + count * 0x1C;
                        *(void **)(rec + 0x00) = obj;
                        *(void **)(rec + 0x04) = hit;
                        *(void **)(rec + 0x08) = hit;
                        *(f32 *)(rec + 0x0C) = tEnter * tEnter;
                        *(f32 *)(rec + 0x10) = hp[0];
                        *(f32 *)(rec + 0x14) = hp[1];
                        *(f32 *)(rec + 0x18) = hp[2];
                        count += 1;
                        if (arg0 != 0) {
                            *(s32 *)(hit + 0x3C) = arg0;
                            *(u16 *)(hit + 0x0A) = (u16)(*(u16 *)(hit + 0x0A) | 0x40);
                        }
                    } else {
                        /* sub-object list: each sphere entry is tested separately */
                        n = *(s16 *)(hit + 0x32);
                        sub = *(u8 **)(hit + 0x40);
                        j = 0;
                        do {
                            word = *(u32 *)(sub + 0x30);
                            if (!(word & 0x40000000)) {
                                radius = radXZ + *(f32 *)(sub + 0x24);
                                if (trackSphereIntersect(org, dir, (f32 *)(sub + 0x0C), radius, &tEnter, &tExit) != 0
                                    && ((tEnter >= 0.0f && tEnter <= len) || (tEnter < 0.0f && tExit > 0.0f))) {
                                    for (k = 0; k < 3; k++) {
                                        hp[k] = (dir[k] * tEnter) + org[k];
                                    }
                                    rec = D_80104808_B1778 + count * 0x1C;
                                    *(void **)(rec + 0x00) = obj;
                                    *(void **)(rec + 0x04) = hit;
                                    *(void **)(rec + 0x08) = sub;
                                    *(f32 *)(rec + 0x0C) = tEnter * tEnter;
                                    *(f32 *)(rec + 0x10) = hp[0];
                                    *(f32 *)(rec + 0x14) = hp[1];
                                    *(f32 *)(rec + 0x18) = hp[2];
                                    count += 1;
                                    if (arg0 != 0) {
                                        *(u16 *)(sub + 0x0A) = (u16)(*(u16 *)(sub + 0x0A) | 0x40);
                                        *(s32 *)(hit + 0x3C) = arg0;
                                        *(u16 *)(hit + 0x0A) = (u16)(*(u16 *)(hit + 0x0A) | 0x20);
                                    }
                                }
                            }
                            j += 1;
                            sub += 0x34;
                        } while (j < n && count < 0x28);
                    }
                }
            }
        }
    } while (remain > 0 && count < 0x28);

    /* bubble sort records ascending by t^2 */
    n = count - 1;
    do {
        noSwap = 1;
        if (n > 0) {
            rec = D_80104808_B1778;
            j = 0;
            do {
                j += 1;
                if (*(f32 *)(rec + 0x28) < *(f32 *)(rec + 0x0C)) {
                    for (k = 0; k < 3; k++) {
                        word = ((u32 *)rec)[k];
                        ((u32 *)rec)[k] = ((u32 *)(rec + 0x1C))[k];
                        ((u32 *)(rec + 0x1C))[k] = word;
                    }
                    for (k = 3; k < 7; k++) {
                        tmp = ((f32 *)rec)[k];
                        ((f32 *)rec)[k] = ((f32 *)(rec + 0x1C))[k];
                        ((f32 *)(rec + 0x1C))[k] = tmp;
                    }
                    noSwap = 0;
                }
                rec += 0x1C;
            } while (j != n);
        }
    } while (noSwap == 0);
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitVectorCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8007D1E8(void *arg0, void *arg1, void *arg2, void *arg3) {
    u8 *racer = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *hitA = (u8 *)arg1;
    u8 *hitB = (u8 *)arg3;
    s16 type = *(s16 *)((u8 *)arg2 + 0x48);
    u8 flag = 0;
    s32 run = 0;
    u8 *e1;
    u8 *e3;
    s32 i;
    s32 j;

    if (type == 0x18) {
        if (!((*(u8 **)((u8 *)arg2 + 0x68))[2] & 1)) {
            flag = 0x80;
        }
        run = 1;
    } else if (type != 0x5A || racer[0x1F9] == 0) {
        run = 1;
    }

    if (run) {
        e1 = *(u8 **)(hitA + 0x40);
        for (i = 0; i < *(s16 *)(hitA + 0x32); i++) {
            e3 = *(u8 **)(hitB + 0x40);
            for (j = 0; j < *(s16 *)(hitB + 0x32); j++) {
                f32 dx = (*(f32 *)(e1 + 0x0C) + *(f32 *)(racer + 0x354)) - *(f32 *)(e3 + 0x0C);
                f32 dz = (*(f32 *)(e1 + 0x14) + *(f32 *)(racer + 0x35C)) - *(f32 *)(e3 + 0x14);
                f32 dy = *(f32 *)(e1 + 0x10) - *(f32 *)(e3 + 0x10);
                f32 r = *(f32 *)(e1 + 0x24) + *(f32 *)(e3 + 0x24);
                f32 d = sqrtf(dx * dx + dz * dz);

                if (-r < dy && dy < r && d < r) {
                    if (d != 0.0f) {
                        f32 k = (r - d) / d;

                        *(f32 *)(racer + 0x354) = *(f32 *)(racer + 0x354) + dx * k;
                        *(f32 *)(racer + 0x35C) = *(f32 *)(racer + 0x35C) + dz * k;
                    } else {
                        *(f32 *)(racer + 0x35C) = *(f32 *)(racer + 0x35C) - d;
                    }
                    racer[0x190] = (u8)(racer[0x190] | flag);
                }
                e3 += 0x34;
            }
            e1 += 0x34;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007D1E8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_8007D420(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3, void *arg4) {
    u8 *hit = (u8 *)arg4;
    u8 *e = *(u8 **)(hit + 0x40);
    s16 count = *(s16 *)(hit + 0x32);
    f32 x = *arg0;
    f32 y = *arg1;
    f32 z = *arg2;
    s16 ret = count;
    s16 rem = count - 1;

    if (count != 0) {
        do {
            f32 dx = x - *(f32 *)(e + 0x0C);
            f32 dy = y - *(f32 *)(e + 0x10);
            f32 dz = z - *(f32 *)(e + 0x14);
            f32 r = *(f32 *)(e + 0x24) + arg3;
            f32 d2 = dx * dx + dy * dy + dz * dz;

            ret = rem;
            if (d2 < r * r && d2 != 0.0f) {
                f32 d = sqrtf(d2);
                f32 k = (r - d) / d;

                x += dx * k;
                y += dy * k;
                z += dz * k;
            }
            e += 0x34;
            rem -= 1;
        } while (rem != 0);
    }
    *arg0 = x;
    *arg1 = y;
    *arg2 = z;
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007D420.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8007D5AC(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *hit = (u8 *)arg1;
    u8 *e = *(u8 **)(hit + 0x40);
    s16 count = *(s16 *)(hit + 0x32);
    s32 i;

    for (i = 0; i < count; i++) {
        f32 r = *(f32 *)(e + 0x24) + *(f32 *)(obj + 0x24);
        f32 dx = *(f32 *)(e + 0x0C) - *(f32 *)(obj + 0x0C);
        f32 dy = *(f32 *)(e + 0x10) - *(f32 *)(obj + 0x10);
        f32 dz = *(f32 *)(e + 0x14) - *(f32 *)(obj + 0x14);

        if (dx * dx + dy * dy + dz * dz < r * r) {
            return 1;
        }
        e += 0x34;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007D5AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Pairwise collision resolver for objects A (arg0) and B (arg2) with their hit
// records pA (arg1) and pB (arg3). Field layouts (raw offsets, cf. hitInitObjectHit
// and hitSquashCheck above):
//   Object: +0x0C/+0x10/+0x14 f32 pos, +0x39 u8, +0x40 aux (+0x14 u16 flags, +0x2F u8),
//           +0x48 s16 type (1 = racer), +0x4A s16 model id, +0x4C hit record,
//           +0x54 f32 *scale, +0x68 state, +0xA0 u8 skip flag.
//   Hit record: +0x0A u16 flags (0x20 = resolved), +0x0C/+0x10/+0x14 f32 pos,
//           +0x24 f32 radius, +0x30 u8 mode (2 = planar test), +0x32 s16 entry count,
//           +0x34 f32 weight, +0x3C owner object, +0x40 entry list.
//   State: +0x00 ptr/flags, +0x04 u32, +0x08 s16, +0x1 s8, +0x2 u8, +0x82 u8 flags,
//           +0x190 u8, +0xA0 ptr, +0x50C ptr.
void func_8007D660(void *arg0, void *arg1, void *arg2, void *arg3) {
    u8 *A = (u8 *)arg0;
    u8 *pA = (u8 *)arg1;
    u8 *B = (u8 *)arg2;
    u8 *pB = (u8 *)arg3;
    u8 *s0;
    u8 *oth;
    u8 *ss;
    u8 *hA;
    u8 *hO;
    u8 *ch;
    u8 *S;
    u8 *hs;
    s16 tA;
    s16 tB;
    s16 a1;
    s16 otype;
    f32 wA;
    f32 wB;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sumR;
    f32 len;
    f32 k;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 ex;
    f32 ey;
    f32 ez;
    u16 n;

    tA = *(s16 *)(A + 0x48);
    tB = *(s16 *)(B + 0x48);

    if (tA == 1 && tB == 1) {
        if ((*(s8 *)(*(u8 **)(A + 0x68) + 1) & 3) == 3 &&
            (*(s8 *)(*(u8 **)(B + 0x68) + 1) & 3) == 3) {
            squadsSaveTribal(A, B);
        }
        return;
    }

    if (tA < tB) {
        s0 = B;
        oth = A;
    } else {
        s0 = A;
        oth = B;
    }
    if (s0[0xA0] != 0) {
        return;
    }
    if (oth[0xA0] != 0) {
        return;
    }

    a1 = *(s16 *)(s0 + 0x48);
    switch (a1) {
    case 0x40:
    case 0x9A:
    case 0x9C:
    case 0xA1:
        if (*(u8 **)(*(u8 **)(s0 + 0x68)) == oth) {
            return;
        }
        goto block_31;
    case 0x9B:
        ss = *(u8 **)(*(u8 **)(s0 + 0x68));
        if (ss == NULL) {
            goto block_31;
        }
        if (ss == oth) {
            return;
        }
        if (*(s16 *)(ss + 0x48) != 1) {
            goto block_31;
        }
        if (*(u8 **)(*(u8 **)(ss + 0x68) + 0x50C) != oth) {
            goto block_31;
        }
        return;
    case 0xA6:
    case 0xA7:
        ss = *(u8 **)(*(u8 **)(s0 + 0x68) + 0xA0);
        if (ss == NULL) {
            goto block_31;
        }
        if (ss == oth) {
            return;
        }
        if (*(s16 *)(ss + 0x48) != 1) {
            goto block_31;
        }
        if (*(u8 **)(*(u8 **)(ss + 0x68) + 0x50C) != oth) {
            goto block_31;
        }
        return;
    case 0x99:
        ss = *(u8 **)(s0 + 0x68);
        if (*(u8 **)ss == oth) {
            goto block_31;
        }
        if (ss[0x82] & 0x20) {
            return;
        }
        goto block_31;
    default:
        goto block_31;
    }

block_31:
    if (*(s16 *)(oth + 0x48) == 1 && a1 == 0x99) {
        u8 *ost = *(u8 **)(oth + 0x68);
        ss = *(u8 **)(s0 + 0x68);
        ch = (u8 *)mainGetGameCharacter(*(s8 *)ost, *(s8 *)(ost + 1));
        if (*(u8 **)ss == oth) {
            if (!(ss[0x82] & 0x25)) {
                return;
            }
        } else if (!(ss[0x82] & 0x21)) {
            goto block_42;
        }
        /* kill counter on the character, clamped to the max at +0x46 */
        n = (u16)(*(u16 *)(ch + 0x26) + 1);
        *(u16 *)(ch + 0x26) = n;
        if (*(u16 *)(ch + 0x46) < n) {
            *(u16 *)(ch + 0x26) = *(u16 *)(ch + 0x46);
        }
        amDittyPlay(0xD);
        objFreeObject(s0);
        return;
    }

block_42:
    hA = *(u8 **)(s0 + 0x4C);
    hO = *(u8 **)(oth + 0x4C);
    if (*(void **)(hA + 0x40) == NULL && *(void **)(hO + 0x40) != NULL) {
        if (func_8007D5AC(hA, hO) == 0) {
            return;
        }
    }

    a1 = *(s16 *)(s0 + 0x48);
    otype = *(s16 *)(oth + 0x48);

    if (otype == 1) {
        if (a1 == 2) {
            /* case 2: move the owner by the displacement of its state position */
            S = *(u8 **)(s0 + 0x68);
            ox = *(f32 *)(S + 0x00);
            oy = *(f32 *)(S + 0x04);
            oz = *(f32 *)(S + 0x08);
            hO = *(u8 **)(oth + 0x4C);
            func_8007D420((f32 *)S, (f32 *)(S + 0x04), (f32 *)(S + 0x08), 12.0f, hO);
            ex = *(f32 *)(S + 0x00) - ox;
            ey = *(f32 *)(S + 0x04) - oy;
            ez = *(f32 *)(S + 0x08) - oz;
            *(f32 *)(s0 + 0x0C) = *(f32 *)(s0 + 0x0C) + ex;
            *(f32 *)(s0 + 0x10) = *(f32 *)(s0 + 0x10) + ey;
            *(f32 *)(s0 + 0x14) = *(f32 *)(s0 + 0x14) + ez;
            hs = *(u8 **)(s0 + 0x4C);
            *(f32 *)(hs + 0x0C) = *(f32 *)(hs + 0x0C) + ex;
            *(f32 *)(hs + 0x10) = *(f32 *)(hs + 0x10) + ey;
            *(f32 *)(hs + 0x14) = *(f32 *)(hs + 0x14) + ez;
            return;
        }
        if (a1 == 0x18) {
            /* case 0x18 */
            S = *(u8 **)(s0 + 0x68);
            if (*(u32 *)S & 8) {
                controlAlterMood(oth, 9, 0x18, 2);
                ShirukenBounce_1arg(s0); /* sig mismatch: asm passes only s0, see alias */
                return;
            }
            hs = *(u8 **)(s0 + 0x4C);
            if (*(s16 *)(s0 + 0x4A) == 0x2CE) {
                *(s16 *)(hs + 0x06) = -0x400;
                return;
            }
            if (*(void **)(hs + 0x40) == NULL) {
                if (!(S[2] & 1)) {
                    u8 *ost = *(u8 **)(oth + 0x68);
                    ost[0x190] = (u8)(ost[0x190] | 0x80);
                }
                return;
            }
            goto default_case;
        }
        if (a1 == 0x3D || a1 == 0x86) {
            return;
        }
    } else if (otype == 0x18 && a1 == 0x3D) {
        return;
    }

    switch (a1) {
    case 0x97:
        return;
    case 0x99:
        ss = *(u8 **)(s0 + 0x68);
        if (*(u16 *)(*(u8 **)(oth + 0x40) + 0x14) & 0x8000) {
            GetBaddyData(s0, ss, 0x18, 2);
            return;
        }
        if (otype == 0x57) {
            *(s16 *)(*(u8 **)(oth + 0x4C) + 0x06) = 0;
            ss[0x82] = (u8)(ss[0x82] | 4);
            *(u32 *)(ss + 0x04) = *(u32 *)(ss + 0x00);
            return;
        }
        if (otype == 0x18) {
            u8 *sp34 = *(u8 **)(oth + 0x68);
            u8 *v = (u8 *)squadsDecapitateSquaddie(oth, a1, 0x18, 2);
            if (!(ss[0x82] & 4)) {
                amSndPlayXYZ(0x9A, *(f32 *)(s0 + 0x0C), *(f32 *)(s0 + 0x10), *(f32 *)(s0 + 0x14), 4, 0);
            }
            if (v != NULL && (*(u32 *)(v + 0x24) & 8)) {
                ShirukenBounce(oth, s0);
                ss[0x82] = (u8)(ss[0x82] | 4);
                *(u32 *)(ss + 0x04) = *(u32 *)(ss + 0x00);
                if (!(*(u32 *)sp34 & 8)) {
                    mainIncreaseWeaponKills(9);
                    mainIncreaseWeaponHits(9);
                }
            } else {
                bloodHitSpriteAdd(s0, ss);
                if (!(*(u32 *)sp34 & 8)) {
                    mainIncreaseWeaponHits(9);
                }
            }
            return;
        }
        if (otype == 1) {
            amSndPlayXYZ(0x9A, *(f32 *)(s0 + 0x0C), *(f32 *)(s0 + 0x10), *(f32 *)(s0 + 0x14), 4, 0);
            ss[0x82] = (u8)(ss[0x82] | 4);
            *(u32 *)(ss + 0x04) = *(u32 *)(ss + 0x00);
            *(u8 **)(*(u8 **)(oth + 0x4C) + 0x3C) = s0;
            controlDecapitatePlayer(oth);
            mainIncreaseWeaponKills(9);
            mainIncreaseWeaponHits(9);
        }
        return;
    case 0x9A:
        amSndPlayXYZ(0x22, *(f32 *)(s0 + 0x0C), *(f32 *)(s0 + 0x10), *(f32 *)(s0 + 0x14), 4, 0);
        explosionStart(0x10, (s16)(s32)*(f32 *)(s0 + 0x0C), (s16)(s32)*(f32 *)(s0 + 0x10),
                       (s16)(s32)*(f32 *)(s0 + 0x14), 0x64, 0);
        objFreeObject(s0);
        return;
    case 0x9B:
        *(s16 *)(*(u8 **)(s0 + 0x68) + 0x08) = 0;
        return;
    case 0xA1:
        if (otype == 0x18 || otype == 1) {
            instQueueMsg(*(f32 *)(s0 + 0x0C), *(f32 *)(s0 + 0x10), *(f32 *)(s0 + 0x14),
                         (s32)(*(f32 *)*(u8 **)(s0 + 0x54) * 255.0f),
                         (s32)(*(u8 **)(oth + 0x40))[0x2F]);
        }
        explosionStart(0xE, (s16)(s32)*(f32 *)(s0 + 0x0C), (s16)(s32)*(f32 *)(s0 + 0x10),
                       (s16)(s32)*(f32 *)(s0 + 0x14), 0x64, 0);
        *(s16 *)(*(u8 **)(s0 + 0x68) + 0x08) = 0;
        s0[0x39] = 0;
        return;
    case 0xA6:
    case 0xA7:
        (*(u8 **)(s0 + 0x68))[1] = 5;
        return;
    default:
        goto default_case;
    }

default_case:
    {
        f32 pAw = *(f32 *)(pA + 0x34);
        f32 pBw = *(f32 *)(pB + 0x34);
        f32 pAx;
        f32 pAy;
        f32 pAz;
        f32 pBx;
        f32 pBy;
        f32 pBz;

        /* weights for splitting the overlap between A and B */
        if (pAw < 0.0f) {
            if (tA == 1 && pBw < 0.0f) {
                wA = 1.0f;
                wB = 0.0f;
            } else {
                wA = 0.0f;
                wB = 1.0f;
            }
        } else if (pBw < 0.0f) {
            if (tB == 1 && pAw < 0.0f) {
                wA = 0.0f;
                wB = 1.0f;
            } else {
                wA = 1.0f;
                wB = 0.0f;
            }
        } else {
            sumR = pAw + pBw;
            wB = pBw / sumR;
            wA = pAw / sumR;
        }

        dx = *(f32 *)(pB + 0x0C) - *(f32 *)(pA + 0x0C);
        dy = *(f32 *)(pB + 0x10) - *(f32 *)(pA + 0x10);
        dz = *(f32 *)(pB + 0x14) - *(f32 *)(pA + 0x14);
        sumR = *(f32 *)(pA + 0x24) + *(f32 *)(pB + 0x24);

        if (tA == 1 && *(void **)(pB + 0x40) != NULL) {
            func_8007D1E8(A, pA, B, pB);
        } else if (tB == 1 && *(void **)(pA + 0x40) != NULL) {
            func_8007D1E8(B, pB, A, pA);
        } else if (*(u8 *)(pA + 0x30) == 2 || *(u8 *)(pB + 0x30) == 2) {
            /* planar (XZ) separation */
            len = sqrtf(dx * dx + dz * dz);
            if (len != 0.0f) {
                k = (sumR / len) - 1.0f;
                dx *= k;
                dz *= k;
            }
            pAx = *(f32 *)(pA + 0x0C);
            pAy = *(f32 *)(pA + 0x10);
            pAz = *(f32 *)(pA + 0x14);
            if (0.0f < wA) {
                func_8007E2F0(A, pA, pAx, *(f32 *)(pA + 0x1C), pAz, pAx - dx * wA, pAy, pAz - dz * wA);
            }
            pBx = *(f32 *)(pB + 0x0C);
            pBy = *(f32 *)(pB + 0x10);
            pBz = *(f32 *)(pB + 0x14);
            if (0.0f < wB) {
                func_8007E2F0(B, pB, pBx, *(f32 *)(pB + 0x1C), pBz, pBx + dx * wB, pBy, pBz + dz * wB);
            }
        } else {
            /* full 3D separation */
            len = sqrtf(dx * dx + dy * dy + dz * dz);
            if (len != 0.0f) {
                k = (sumR / len) - 1.0f;
                dx *= k;
                dy *= k;
                dz *= k;
            }
            pAx = *(f32 *)(pA + 0x0C);
            pAy = *(f32 *)(pA + 0x10);
            pAz = *(f32 *)(pA + 0x14);
            if (0.0f < wA) {
                func_8007E2F0(A, pA, pAx, pAy, pAz, pAx - dx * wA, pAy - dy * wA, pAz - dz * wA);
            }
            pBx = *(f32 *)(pB + 0x0C);
            pBy = *(f32 *)(pB + 0x10);
            pBz = *(f32 *)(pB + 0x14);
            if (0.0f < wB) {
                func_8007E2F0(B, pB, pBx, pBy, pBz, pBx + dx * wB, pBy + dy * wB, pBz + dz * wB);
            }
        }

        *(u16 *)(pA + 0x0A) = (u16)(*(u16 *)(pA + 0x0A) | 0x20);
        *(void **)(pA + 0x3C) = B;
        *(u16 *)(pB + 0x0A) = (u16)(*(u16 *)(pB + 0x0A) | 0x20);
        *(void **)(pB + 0x3C) = A;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007D660.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8007E2F0(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    u8 *obj = (u8 *)arg0;
    u8 *pos = (u8 *)arg1;
    f32 oz;
    f32 dx1;
    f32 dy1;
    f32 dz1;
    f32 dx2;
    f32 dy2;
    f32 dz2;
    f32 *vec;
    s16 *box;
    s32 ix;
    s32 iy;
    s32 iz;
    s16 blk;

    oz = *(f32 *)(pos + 0x20);
    dx1 = arg2 - *(f32 *)(pos + 0x18);
    dy1 = arg3 - *(f32 *)(pos + 0x1C);
    dz1 = arg4 - oz;
    dx2 = arg5 - *(f32 *)(pos + 0x0C);
    dy2 = arg6 - *(f32 *)(pos + 0x10);
    dz2 = arg7 - *(f32 *)(pos + 0x14);
    *(f32 *)(pos + 0x18) += dx1;
    *(f32 *)(pos + 0x1C) += dy1;
    *(f32 *)(pos + 0x20) += dz1;
    *(f32 *)(pos + 0x0C) += dx2;
    *(f32 *)(pos + 0x10) += dy2;
    *(f32 *)(pos + 0x14) += dz2;

    if (*(s16 *)(obj + 0x48) == 2) {
        vec = *(f32 **)(obj + 0x68);
        vec[0] += dx2;
        vec[1] += dy2;
        vec[2] += dz2;
        vec[3] += dx1;
        vec[4] += dy1;
        vec[5] += dz1;
    }

    *(f32 *)(obj + 0x0C) += dx2;
    *(f32 *)(obj + 0x10) += dx2;
    *(f32 *)(obj + 0x14) += dx2;

    blk = *(s16 *)(obj + 0x2E);
    if (blk == -1) {
        blk = trackGetBlock(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), blk, *(f32 *)(obj + 0x14));
        *(s16 *)(obj + 0x2E) = blk;
    } else {
        ix = (s32)*(f32 *)(obj + 0x0C);
        iy = (s32)*(f32 *)(obj + 0x10);
        iz = (s32)*(f32 *)(obj + 0x14);
        box = trackBlockDim(oz, dx2, blk, iy, iz);
        if (box[3] < ix || ix < box[0] || box[4] < iy || iy < box[1] || box[5] < iz || iz < box[2]) {
            blk = trackGetBlock(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), (s16)iy, *(f32 *)(obj + 0x14));
            *(s16 *)(obj + 0x2E) = blk;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007E2F0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hitPlayer(f32 x, f32 y, f32 z, f32 radius, s32 ignoreY, void *outList) {
    f32 dists[8];
    void **out = (void **)outList;
    void **list;
    void *obj;
    s32 count;
    s32 n;
    s32 i;
    s32 a2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d2;
    f32 tmpf;
    void *tmpo;

    n = 0;
    list = objGetPlayerlist(&count);
    if (count > 0) {
        do {
            obj = *list;
            list++;
            if (*(s8 *)*(u8 **)((u8 *)obj + 0x68) >= 0 && *(s8 *)*(u8 **)((u8 *)obj + 0x68) < 4) {
                dx = *(f32 *)((u8 *)obj + 0x0C) - x;
                dz = *(f32 *)((u8 *)obj + 0x14) - z;
                d2 = (dx * dx) + (dz * dz);
                if (ignoreY == 0) {
                    dy = *(f32 *)((u8 *)obj + 0x10) - y;
                    d2 = d2 + (dy * dy);
                }
                if (d2 < (radius * radius)) {
                    dists[n] = sqrtf(d2);
                    out[n] = obj;
                    n++;
                }
            }
            count--;
        } while (count > 0);

        a2 = n - 1;
        if (a2 > 0) {
            do {
                for (i = 0; i < a2; i++) {
                    if (dists[i + 1] < dists[i]) {
                        tmpf = dists[i];
                        dists[i] = dists[i + 1];
                        dists[i + 1] = tmpf;
                        tmpo = out[i];
                        out[i] = out[i + 1];
                        out[i + 1] = tmpo;
                    }
                }
                a2--;
            } while (a2 != 0);
        }
    }
    return n;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hitPlayerKilledPlayer(void *arg0, void *arg1) {
    u8 *a = (u8 *)arg0;
    u8 *b = (u8 *)arg1;
    s8 *pa;
    s8 *pb;
    u8 *mp = (u8 *)&multiPlayer;

    if (multiPlayerGame != 0 && *(s16 *)(a + 0x48) == 1 && *(s16 *)(b + 0x48) == 1) {
        pa = *(s8 **)(a + 0x68);
        pb = *(s8 **)(b + 0x68);
        *(u16 *)(mp + (*pa * 0xA0) + (*pb * 2)) += 1;
        *(u16 *)(mp + (*pb * 0xA0) + (*pa * 2) + 8) += 1;
        if ((multiGameType & 0x30) == 0x30) {
            *(s8 *)(mp + (*pb * 0xA0) + 0x13) -= 1;
        }
        if (arg0 != arg1) {
            *(s16 *)(mp + (*pa * 0xA0) + 0x10) += 1;
        } else {
            *(s16 *)(mp + (*pa * 0xA0) + 0x10) -= 1;
        }
        hitBridgeMoveY(pa, 0x9F, &multiPlayer, arg0);
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitPlayerKilledPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
MemoryPoolSlot *hitGetHitModels(s32 *arg0) {
    *arg0 = D_801047E0_B1750;
    return D_801047E4_B1754;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitGetHitModels.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitModelInit(void *arg0) {
    u8 *model = (u8 *)arg0;
    u8 *sub = *(u8 **)(model + 0x5C);
    s8 mode = *(s8 *)(*(u8 **)(model + 0x40) + 0x71);

    if (mode >= 0) {
        *(s8 *)(sub + 0x133) = mode;
    } else {
        *(s8 *)(sub + 0x133) = *(s8 *)(model + 0x3A);
    }
    func_8007EA44(arg0, 1);
    func_8007EA44(arg0, 1);
    func_8007EBEC(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitModelInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitModelsTick(void) {
    s32 i;
    s32 off;
    u8 *model;
    u8 *sub;
    s8 mode;

    i = 0;
    if (D_801047E0_B1750 > 0) {
        off = 0;
        do {
            model = *(u8 **)((u8 *)D_801047E4_B1754 + off);
            sub = *(u8 **)(model + 0x5C);
            mode = *(s8 *)(*(u8 **)(model + 0x40) + 0x71);
            if (mode >= 0) {
                *(s8 *)(sub + 0x133) = mode;
            } else {
                *(s8 *)(sub + 0x133) = *(s8 *)(model + 0x3A);
            }
            func_8007EA44(model, 0);
            if (*(s16 *)(sub + 0x12C) != 0) {
                func_8007EBEC(model);
            }
            *(s16 *)(sub + 0x12E) = 0;
            *(s8 *)(sub + 0x132) = 0;
            *(s16 *)(sub + 0x130) = 0;
            *(s8 *)(sub + 0x12A) = 0;
            i++;
            off += 4;
        } while (i < D_801047E0_B1750);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitModelsTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8007EA44(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *sub = *(u8 **)(obj + 0x5C);
    u8 tr[0x18];
    s32 idx;

    if (*(f32 *)(sub + 0x118) == *(f32 *)(obj + 0x0C) &&
        *(f32 *)(sub + 0x11C) == *(f32 *)(obj + 0x10) &&
        *(f32 *)(sub + 0x120) == *(f32 *)(obj + 0x14) &&
        *(s16 *)(sub + 0x128) == *(s16 *)(obj + 0x00) &&
        *(s16 *)(sub + 0x126) == *(s16 *)(obj + 0x02) &&
        *(s16 *)(sub + 0x124) == *(s16 *)(obj + 0x04)) {
        *(s16 *)(sub + 0x12C) = 0;
    } else {
        *(s16 *)(sub + 0x12C) = 1;
    }

    if (*(s16 *)(sub + 0x12C) != 0 || arg1 != 0) {
        *(u8 *)(sub + 0x12B) ^= 1;
        *(s16 *)(obj + 0x00) = *(s16 *)(obj + 0x00) & 0xFFF0;
        *(s16 *)(obj + 0x02) = *(s16 *)(obj + 0x02) & 0xFFF0;
        *(s16 *)(obj + 0x04) = *(s16 *)(obj + 0x04) & 0xFFF0;

        *(f32 *)(tr + 0x0C) = -*(f32 *)(obj + 0x0C);
        *(f32 *)(tr + 0x10) = -*(f32 *)(obj + 0x10);
        *(f32 *)(tr + 0x14) = -*(f32 *)(obj + 0x14);
        *(f32 *)(tr + 0x08) = 1.0f / *(f32 *)(obj + 0x08);
        *(s16 *)(tr + 0x04) = -*(s16 *)(obj + 0x04);
        *(s16 *)(tr + 0x02) = -*(s16 *)(obj + 0x02);
        *(s16 *)(tr + 0x00) = -*(s16 *)(obj + 0x00);

        idx = *(u8 *)(sub + 0x12B);
        matrix_XYZ_YPR_SCL((s16 *)tr, sub + (idx << 6), arg0);
        idx = *(u8 *)(sub + 0x12B);
        matrix_SCL_RPY_XYZ(arg0, sub + (idx << 6) + 0x80);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007EA44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8007EBEC(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *sub = *(u8 **)(obj + 0x5C);
    u8 *cur = sub + ((*(u8 *)(sub + 0x12B)) << 6);
    u8 *model = *(u8 **)(*(u8 **)(obj + 0x6C) + ((*(u8 *)(sub + 0x133)) * 4));
    s16 lo[3];
    s16 hi[3];
    u8 *col;
    f32 f2;
    f32 f0;
    f32 f12;
    s32 i;
    s32 k;

    *(f32 *)(sub + 0x100) = *(f32 *)(cur + 0xB0);
    *(f32 *)(sub + 0x104) = *(f32 *)(cur + 0xB4);
    *(f32 *)(sub + 0x108) = *(f32 *)(cur + 0xB8);
    *(f32 *)(sub + 0x10C) = *(f32 *)(sub + 0x100);
    *(f32 *)(sub + 0x110) = *(f32 *)(sub + 0x104);
    *(f32 *)(sub + 0x114) = *(f32 *)(sub + 0x108);

    for (k = 0; k < 3; k++) {
        lo[k] = *(s16 *)(model + 0x8C + k * 2);
        hi[k] = *(s16 *)(model + 0x92 + k * 2);
    }

    for (i = 0; i < 3; i++) {
        col = cur + 0x80 + i * 4;
        for (k = 0; k < 3; k++) {
            f2 = *(f32 *)(col + k * 0x10);
            f0 = (f32)lo[k] * f2;
            f12 = (f32)hi[k] * f2;
            if (f0 < f12) {
                *(f32 *)(sub + 0x100 + i * 4) += f0;
                *(f32 *)(sub + 0x10C + i * 4) += f12;
            } else {
                *(f32 *)(sub + 0x100 + i * 4) += f12;
                *(f32 *)(sub + 0x10C + i * 4) += f0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/func_8007EBEC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitTransformBox(void *arg0, void *arg1, void *arg2) {
    f32 *mat = (f32 *)arg0;
    f32 *vmin = (f32 *)arg1;
    f32 *vmax = (f32 *)arg2;
    f32 lo[4];
    f32 hi[4];
    f32 f2;
    f32 a;
    f32 b;
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        lo[i] = 0.0f;
        hi[i] = 0.0f;
    }
    lo[3] = 1.0f;
    hi[3] = 1.0f;

    for (i = 0; i < 4; i++) {
        for (n = 0; n < 2; n++) {
            f2 = mat[i + n * 8];
            a = vmin[n * 2] * f2;
            b = vmax[n * 2] * f2;
            if (a < b) {
                lo[i] += a;
                hi[i] += b;
            } else {
                lo[i] += b;
                hi[i] += a;
            }
            f2 = mat[i + n * 8 + 4];
            a = vmin[n * 2 + 1] * f2;
            b = vmax[n * 2 + 1] * f2;
            if (a < b) {
                lo[i] += a;
                hi[i] += b;
            } else {
                lo[i] += b;
                hi[i] += a;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        vmin[i] = lo[i];
        vmax[i] = hi[i];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitTransformBox.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitMakePolylist(f32 *qmin, f32 *qmax, s32 arg2, s32 arg3, void *arg4) {
    /* qmin/qmax: query AABB corners (f32[3]).
       arg2 == -1: "no reject" mode (per-poly flag test, see below).
       arg3: keep mask; groups whose mask hits it are always considered.
       arg2 (otherwise): reject mask; groups hitting it are skipped unless arg3 matches.
       arg4: object to exclude (the caller). */
    LevelHeader *lvl;
    s32 noReject;
    s32 maxEntries;
    s32 nObj;
    s32 nCand;
    s32 i;
    s32 k;
    s32 s4;
    s32 g;
    s32 poly;
    s32 nGroups;
    s32 start;
    s32 end;
    s32 gmask;
    s32 pm;
    s32 ok;
    s32 skip;
    s32 inside;
    f32 lo;
    f32 hi;
    f32 bMin;
    f32 bMax;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 tmpD;
    u8 *tmpO;
    s32 candMask[16];
    f32 candDist[16];
    u8 *candObj[16];
    f32 minV[4];
    f32 maxV[4];
    u8 *obj;
    u8 *sub;
    u8 *mdl;
    u8 *hdr;
    u8 *ps;
    u8 *pbase;
    u8 *pflags;
    u32 *pmasks;
    u8 *grp;
    u8 *hit;

    lvl = levelGetLevel();
    maxEntries = *(s16 *)((u8 *)lvl + 0xEE);

    /* pass 1: collect up to 16 hit objects overlapping the query box, sorted by
       squared distance from their box corner (+0x100) to qmin */
    nCand = 0;
    nObj = D_801047E0_B1750;
    for (i = 0; i < nObj; i++) {
        obj = ((u8 **)D_801047E4_B1754)[i];
        if (obj == (u8 *)arg4) {
            continue;
        }
        hit = *(u8 **)(obj + 0x4C);
        if (!(*(u16 *)(hit + 0x0A) & 1)) {
            continue;
        }
        sub = *(u8 **)(obj + 0x5C);

        /* disjoint on any axis -> reject */
        inside = 1;
        for (k = 0; k < 3; k++) {
            lo = qmin[k];
            hi = qmax[k];
            bMin = *(f32 *)(sub + 0x100 + k * 4);
            bMax = *(f32 *)(sub + 0x10C + k * 4);
            if ((lo < bMin && hi < bMin) || (bMax < lo && bMax < hi)) {
                inside = 0;
                break;
            }
        }
        if (!inside || nCand >= 16) {
            continue;
        }

        dx = *(f32 *)(sub + 0x100) - qmin[0];
        dy = *(f32 *)(sub + 0x104) - qmin[1];
        dz = *(f32 *)(sub + 0x108) - qmin[2];
        candDist[nCand] = dx * dx + dy * dy + dz * dz;
        candObj[nCand] = obj;
        /* insertion sort, nearest first */
        for (k = nCand; k > 0 && candDist[k] < candDist[k - 1]; k--) {
            tmpD = candDist[k];
            candDist[k] = candDist[k - 1];
            candDist[k - 1] = tmpD;
            tmpO = candObj[k];
            candObj[k] = candObj[k - 1];
            candObj[k - 1] = tmpO;
        }
        nCand++;
        if (nCand >= 16) {
            break;
        }
    }

    /* pass 2: transform the query box into each candidate's local space and
       compute its 24-bit axis compare mask */
    for (s4 = 0; s4 < nCand; s4++) {
        obj = candObj[s4];
        sub = *(u8 **)(obj + 0x5C);
        mdl = *(u8 **)(*(u8 **)(obj + 0x6C) + (*(u8 *)(sub + 0x133) * 4));

        minV[0] = qmin[0];
        minV[1] = qmin[1];
        minV[2] = qmin[2];
        minV[3] = 1.0f;
        maxV[0] = qmax[0];
        maxV[1] = qmax[1];
        maxV[2] = qmax[2];
        maxV[3] = 1.0f;
        hitTransformBox(sub + (*(u8 *)(sub + 0x12B) << 6), minV, maxV);
        candMask[s4] = hitGetModCompareMask(mdl + 0x8C, (s32)minV[0], (s32)minV[1], (s32)minV[2],
                                            (s32)maxV[0], (s32)maxV[1], (s32)maxV[2]);
    }

    /* pass 3: emit the polylist: object header entries (bit 31 cleared) followed by
       per-poly entries (F4 = poly record ptr, F8 = group, FC = poly index) */
    noReject = (arg2 == -1);
    D_801047F0_B1760 = 0;
    for (s4 = 0; s4 < nCand; s4++) {
        obj = candObj[s4];
        sub = *(u8 **)(obj + 0x5C);
        mdl = *(u8 **)(*(u8 **)(obj + 0x6C) + (*(u8 *)(sub + 0x133) * 4));
        hdr = *(u8 **)mdl;
        ps = *(u8 **)(mdl + 0x0C);
        if (ps == NULL) {
            ps = *(u8 **)(hdr + 0x60);
        }
        pbase = *(u8 **)(ps + 0x00);
        pmasks = *(u32 **)(ps + 0x04);
        pflags = *(u8 **)(ps + 0x08);

        ((s32 *)D_801047F4_B1764)[D_801047F0_B1760] = (s32)obj & 0x7FFFFFFF;
        D_801047F0_B1760 += 1;

        nGroups = *(s16 *)(hdr + 0x16);
        for (g = 0; g < nGroups; g++) {
            grp = *(u8 **)(hdr + 0x24) + g * 0x10;
            gmask = *(s32 *)(grp + 0x0C);
            start = *(s16 *)(grp + 0x08);
            /* groups are 16 B, so +0x18 is the next group's start */
            end = *(s16 *)(grp + 0x18);

            skip = (!(gmask & arg3)) && !noReject && (gmask & arg2);
            if (skip || start >= end) {
                continue;
            }

            for (poly = start; poly < end; poly++) {
                pm = pmasks[poly] & candMask[s4];
                if (noReject) {
                    ok = (pflags[poly] & 0x38) && (pm & 0xFF) && (pm & 0xFF00);
                } else if (*(s16 *)(obj + 0x48) == 0x37) {
                    ok = (pm & 0xFF) && (pm & 0xFF00);
                } else {
                    ok = (pm & 0xFF) && (pm & 0xFF00) && (pm & 0xFF0000);
                }
                if (ok) {
                    ((s32 *)D_801047F4_B1764)[D_801047F0_B1760] = (s32)(pbase + poly * 0xE);
                    ((u16 *)D_801047F8_B1768)[D_801047F0_B1760] = (u16)g;
                    ((u16 *)D_801047FC_B176C)[D_801047F0_B1760] = (u16)poly;
                    D_801047F0_B1760 += 1;
                }
                /* list full: the original code leaves all three loops here */
                if (D_801047F0_B1760 >= maxEntries) {
                    return;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitMakePolylist.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hitPolyPlaneTest(void *arg0, f32 *arg1, f32 *arg2, void *arg3, f32 arg4, u16 arg5, f32 arg6) {
    s32 result;
    s32 count;
    s32 s7;
    s32 entry;
    u8 *hitRec;
    u8 *mdl;
    u8 *lastMdl; /* asm: s4 is seeded from stack slot 0x148, which the previous call left behind */
    u8 *pdat;
    u8 *geo;
    u8 *col;
    f32 (*mtx)[4];
    f32 scale;
    f32 pos[3];
    f32 plane[4];
    f32 seg[3];
    f32 wp[3];
    f32 ix;
    f32 iy;
    f32 iz;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 d;
    f32 dist;
    f32 dpos;
    f32 t;
    f32 px;
    f32 py;
    f32 pz;
    f32 negDist;
    f32 len;
    f32 cosv;
    f32 tt;
    f32 ed;
    f32 *ep;
    u8 *out;
    u8 *rec;
    u16 *poly;
    u16 e;
    s32 inside;
    s32 k;
    s32 flip;
    s32 idx;
    s16 t48;

    result = 0;
    count = D_801047F0_B1760;
    if (count > 0) {
        mdl = lastMdl;
        for (s7 = 0; s7 < count; s7++) {
            entry = ((s32 *)D_801047F4_B1764)[s7];
            if (entry > 0) {
                /* object record: entry is the address without its KSEG0 bit */
                hitRec = (u8 *)((u32)entry | 0x80000000U);
                mdl = *(u8 **)(hitRec + 0x5C);
                pdat = *(u8 **)(*(u8 **)(hitRec + 0x6C) + (mdl[0x133] * 4));
                geo = *(u8 **)pdat;
                col = *(u8 **)(pdat + 0x0C);
                if (col == NULL) {
                    col = *(u8 **)(geo + 0x60);
                }
                idx = mdl[0x12B];
                mtx = (f32 (*)[4])(mdl + (idx << 6));
                scale = *(f32 *)(hitRec + 0x08);
                arg6 = arg6 / scale;
                if (*(s16 *)(hitRec + 0x48) == 0x37) {
                    pos[0] = arg1[0];
                    pos[1] = arg1[1];
                    pos[2] = arg1[2];
                    hitBridgeMoveY((s8 *)hitRec, (s32)pos, &pos[1], &pos[2]);
                } else if (*(s16 *)(mdl + 0x12C) != 0) {
                    mathMtxXFMF((f32 (*)[4])(mdl + ((u8)(idx ^ 1) << 6)), arg1[0], arg1[1], arg1[2],
                                &seg[0], &seg[1], &seg[2]);
                    mathMtxXFMF((f32 (*)[4])(mdl + (idx << 6) + 0x80), seg[0], seg[1], seg[2],
                                &pos[0], &pos[1], &pos[2]);
                } else {
                    pos[0] = arg1[0];
                    pos[1] = arg1[1];
                    pos[2] = arg1[2];
                }
            } else if ((void *)hitRec != arg0) {
                /* polygon record: entry is a KSEG0 address with the high bit set */
                poly = (u16 *)(u32)entry;
                matrixTransposeVectorMultiply(mtx, *(u8 **)(col + 0x0C) + (poly[0] << 4), plane);
                nx = plane[0] * scale;
                ny = plane[1] * scale;
                nz = plane[2] * scale;
                d = (plane[3] * scale) - arg4;

                dist = ((nz * arg2[2]) + ((nx * arg2[0]) + (ny * arg2[1]))) + d;
                if (dist < 0.0f) {
                    dpos = ((pos[2] * nz) + ((nx * pos[0]) + (ny * pos[1]))) + d;
                    if (dpos >= 0.0f) {
                        /* segment pos -> arg2 crosses the plane */
                        t = dpos / (dpos - dist);
                        seg[0] = (arg2[0] - pos[0]) * t;
                        seg[1] = (arg2[1] - pos[1]) * t;
                        seg[2] = (arg2[2] - pos[2]) * t;
                        ix = (pos[0] + seg[0]) - (arg4 * nx);
                        iy = (pos[1] + seg[1]) - (arg4 * ny);
                        iz = (pos[2] + seg[2]) - (arg4 * nz);
                        mathMtxXFMF(mtx, ix, iy, iz, &wp[0], &wp[1], &wp[2]);

                        /* edge planes: poly[1..3], bit 15 flips the plane */
                        inside = 1;
                        k = 0;
                        do {
                            e = poly[k + 1];
                            flip = e & 0x8000;
                            ep = (f32 *)(*(u8 **)(col + 0x0C) + ((e ^ flip) << 4));
                            ed = ((ep[0] * wp[0]) + (ep[1] * wp[1])) + (ep[2] * wp[2]) + ep[3];
                            if (flip != 0) {
                                ed = -ed;
                            }
                            if (arg6 < ed) {
                                inside = 0;
                            }
                            k++;
                        } while ((k < 3) && (inside != 0));

                        if (inside != 0) {
                            out = (u8 *)arg3;
                            *(f32 *)(out + 0x1C) = ((seg[0] * seg[0]) + (seg[1] * seg[1])) + (seg[2] * seg[2]);
                            result = 1;

                            if ((arg5 & 0x81) != 0) {
                                if ((arg5 & 1) != 0) {
                                    arg4 = arg4 + 0.1f;
                                    arg2[0] = (arg4 * nx) + ix;
                                    arg2[1] = (arg4 * ny) + iy;
                                    arg2[2] = (arg4 * nz) + iz;
                                } else {
                                    tt = 0.1f - dist;
                                    arg2[0] = arg2[0] + (tt * nx);
                                    arg2[1] = arg2[1] + (tt * ny);
                                    arg2[2] = arg2[2] + (tt * nz);
                                }
                                *(f32 *)(out + 0x04) = nx;
                                *(f32 *)(out + 0x08) = ny;
                                *(f32 *)(out + 0x0C) = nz;
                                if (ny >= 0.707f) {
                                    out[0x25] = (u8)(out[0x25] | 0x10);
                                } else if (ny <= -0.866f) {
                                    out[0x25] = (u8)(out[0x25] | 0x40);
                                } else {
                                    out[0x25] = (u8)(out[0x25] | 0x20);
                                }
                            } else if (ny >= 0.707f) {
                                arg2[1] = (-(((nz * arg2[2]) + (nx * arg2[0])) + d) / ny) + 0.1f;
                                *(f32 *)(out + 0x04) = nx;
                                *(f32 *)(out + 0x08) = ny;
                                *(f32 *)(out + 0x0C) = nz;
                                out[0x25] = (u8)(out[0x25] | 0x10);
                            } else if (ny <= -0.866f) {
                                tt = 0.1f - dist;
                                arg2[0] = arg2[0] + (tt * nx);
                                arg2[1] = arg2[1] + (tt * ny);
                                arg2[2] = arg2[2] + (tt * nz);
                                out[0x25] = (u8)(out[0x25] | 0x40);
                            } else {
                                negDist = -dist;
                                px = arg2[0] + (negDist * nx);
                                py = arg2[1] + (negDist * ny);
                                pz = arg2[2] + (negDist * nz);
                                seg[0] = arg2[0] - px;
                                seg[1] = arg2[1] - py;
                                seg[2] = arg2[2] - pz;
                                len = sqrtf((seg[0] * seg[0]) + (seg[2] * seg[2]));
                                cosv = Cosf((s16)Arctanf(seg[1], len));
                                if (cosv != 0.0f) {
                                    tt = (negDist + 0.1f) / cosv;
                                    len = sqrtf((nx * nx) + (nz * nz));
                                    arg2[0] = arg2[0] + (tt * (nx / len));
                                    arg2[2] = arg2[2] + (tt * (nz / len));
                                } else {
                                    arg2[0] = px;
                                    arg2[1] = py;
                                    arg2[2] = pz;
                                }
                                out[0x25] = (u8)(out[0x25] | 0x20);
                            }

                            *(f32 *)(out + 0x10) = nx;
                            *(f32 *)(out + 0x14) = ny;
                            *(f32 *)(out + 0x18) = nz;
                            out[0x24] = 0;
                            *(s32 *)(out + 0x20) =
                                *(s32 *)(*(u8 **)(geo + 0x24) + (((s16 *)D_801047F8_B1768)[s7] << 4) + 0x0C);
                            if ((void *)hitRec != *(void **)out) {
                                *(void **)out = hitRec;
                                out[0x27] = (u8)((s8)out[0x27] + 1);
                            }

                            if (arg0 != NULL) {
                                if ((*(u8 **)(mdl + 0x134) != NULL) && ((out[0x25] & 0x10) != 0)) {
                                    if (mdl[0x132] < 0xA) {
                                        rec = *(u8 **)(mdl + 0x134) + (mdl[0x132] * 0x1C);
                                        mathMtxXFMF(mtx, arg2[0], arg2[1], arg2[2], (f32 *)rec,
                                                    (f32 *)(rec + 4), (f32 *)(rec + 8));
                                        *(f32 *)(rec + 0x0C) = *(f32 *)((u8 *)arg0 + 0x1C);
                                        *(f32 *)(rec + 0x10) = *(f32 *)((u8 *)arg0 + 0x20);
                                        *(f32 *)(rec + 0x14) = *(f32 *)((u8 *)arg0 + 0x24);
                                        rec[0x18] = (u8)arg5;
                                        mdl[0x132] = (u8)(mdl[0x132] + 1);
                                    }
                                }
                                t48 = *(s16 *)((u8 *)arg0 + 0x48);
                                if (t48 == 0xA4) {
                                    *(s16 *)(mdl + 0x130) = (s16)(*(s16 *)(mdl + 0x130) + 0x2D00);
                                } else if (t48 == 0xA5) {
                                    *(s16 *)(mdl + 0x130) = (s16)(*(s16 *)(mdl + 0x130) + 0x0F00);
                                } else if ((t48 == 0xAC) || (t48 == 0xAA)) {
                                    *(s16 *)(mdl + 0x130) = (s16)(*(s16 *)(mdl + 0x130) +
                                        *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6));
                                }
                                mdl[0x12A] = 1;
                            }
                            /* hit: stop scanning the list */
                            s7 = count;
                        }
                    }
                }
            }
        }
        lastMdl = mdl;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitPolyPlaneTest.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Tests the segment arg0 -> arg1 (radius arg3) against the edge records in
// D_80104800 (48 bytes each, layout as written by hitPolyEdgeBuffer: +0x00 end A,
// +0x0C end B, +0x18 unit axis, +0x24 length, +0x28 hitRec, +0x2C s16 geometry
// index, +0x2E s16 flag). Each record is a capsule: cylinder body plus two end spheres.
// Hit output (arg2): +0x00 hitRec, +0x04..0x0C normal, +0x10..0x18 normal copy,
// +0x1C t^2, +0x20 s32 from the geometry table, +0x24 byte, +0x25 flag bits,
// +0x26 s8, +0x27 hit counter.
s32 hitPolyEdgeTest(f32 *arg0, f32 *arg1, void *arg2, f32 arg3, s32 arg4) {
    s32 result;
    s32 i;
    u8 *lastHit;
    u8 *hitRec;
    u8 *rec;
    u8 *mdl;
    u8 *pdat;
    u8 *geo;
    u8 *out;
    f32 *ra;
    s32 idx;
    f32 pos[3];
    f32 dir[3];
    f32 tmp[3];
    f32 hit[3];
    f32 segLen;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 t;
    f32 unusedOut;
    f32 slotE0;
    f32 axisDot;
    f32 axisDen;
    f32 s;
    f32 hitDot;
    f32 endX;
    f32 endY;
    f32 endZ;
    f32 d;
    f32 tt;
    f32 negD;
    f32 px;
    f32 py;
    f32 pz;
    f32 cosv;
    f32 t20;
    f32 hl;
    f32 hdx;
    f32 hdz;

    result = 0;
    lastHit = NULL;
    if (D_80104804_B1774 > 0) {
        /* asm: f30 is seeded from stack slot 0xE0, left by the previous call */
        ny = slotE0;
        for (i = 0; i < D_80104804_B1774; i++) {
            rec = (u8 *)D_80104800_B1770 + (i * 0x30);
            ra = (f32 *)rec;
            hitRec = *(u8 **)(rec + 0x28);
            if (lastHit != hitRec) {
                /* new object: transform the start point and build the segment */
                lastHit = hitRec;
                mdl = *(u8 **)(hitRec + 0x5C);
                pdat = *(u8 **)(*(u8 **)(hitRec + 0x6C) + (mdl[0x133] * 4));
                geo = *(u8 **)pdat;
                idx = mdl[0x12B];
                if (*(s16 *)(hitRec + 0x48) == 0x37) {
                    pos[0] = arg0[0];
                    pos[1] = arg0[1];
                    pos[2] = arg0[2];
                    hitBridgeMoveY((s8 *)hitRec, (s32)pos, &pos[1], &pos[2]);
                } else if (*(s16 *)(mdl + 0x12C) != 0) {
                    mathMtxXFMF((f32 (*)[4])(mdl + (((idx ^ 1) & 0xFF) << 6)), arg0[0], arg0[1], arg0[2], &tmp[0], &tmp[1], &tmp[2]);
                    mathMtxXFMF((f32 (*)[4])(mdl + ((idx & 0xFF) << 6) + 0x80), tmp[0], tmp[1], tmp[2], &pos[0], &pos[1], &pos[2]);
                } else {
                    pos[0] = arg0[0];
                    pos[1] = arg0[1];
                    pos[2] = arg0[2];
                }
                tmp[0] = arg1[0] - pos[0];
                tmp[1] = arg1[1] - pos[1];
                tmp[2] = arg1[2] - pos[2];
                segLen = (tmp[0] * tmp[0]) + (tmp[1] * tmp[1]) + (tmp[2] * tmp[2]);
                if (segLen > 0.0f) {
                    segLen = sqrtf(segLen);
                    dir[0] = tmp[0] / segLen;
                    dir[1] = tmp[1] / segLen;
                    dir[2] = tmp[2] / segLen;
                }
            }

            if (segLen > 0.0f) {
                /* cylinder body of the capsule */
                if ((trackCylinderIntersect(pos, dir, (f32 *)rec, (f32 *)(rec + 0x18), arg3, &t, &unusedOut) != 0) && (t >= 0.0f) && (t <= segLen)) {
                    hit[0] = (dir[0] * t) + pos[0];
                    hit[1] = (dir[1] * t) + pos[1];
                    hit[2] = (dir[2] * t) + pos[2];
                    tmp[0] = hit[0] - ra[0];
                    tmp[1] = hit[1] - ra[1];
                    tmp[2] = hit[2] - ra[2];
                    axisDot = (tmp[0] * ra[6]) + (tmp[1] * ra[7]) + (tmp[2] * ra[8]);
                    axisDen = (ra[8] * ra[8]) + ((ra[6] * ra[6]) + (ra[7] * ra[7]));
                    s = axisDot / axisDen;
                    if ((s >= 0.0f) && (s <= ra[9])) {
                        result = 1;
                        tmp[0] = ra[0] + (ra[6] * s);
                        tmp[1] = ra[1] + (ra[7] * s);
                        tmp[2] = ra[2] + (ra[8] * s);
                        nx = hit[0] - tmp[0];
                        ny = hit[1] - tmp[1];
                        nz = hit[2] - tmp[2];
                    }
                }

                /* end sphere A */
                if ((result == 0) && (trackSphereIntersect(pos, dir, (f32 *)rec, arg3, &t, &unusedOut) != 0) && (t >= 0.0f) && (t <= segLen)) {
                    result = 1;
                    hit[0] = (dir[0] * t) + pos[0];
                    hit[1] = (dir[1] * t) + pos[1];
                    hit[2] = (dir[2] * t) + pos[2];
                    nx = hit[0] - ra[0];
                    ny = hit[1] - ra[1];
                    nz = hit[2] - ra[2];
                }

                /* end sphere B (rec + 0x0C) */
                if ((result == 0) && (trackSphereIntersect(pos, dir, (f32 *)(rec + 0x0C), arg3, &t, &unusedOut) != 0) && (t >= 0.0f) && (t <= segLen)) {
                    result = 1;
                    hit[0] = (dir[0] * t) + pos[0];
                    hit[1] = (dir[1] * t) + pos[1];
                    hit[2] = (dir[2] * t) + pos[2];
                    nx = hit[0] - ra[3];
                    ny = hit[1] - ra[4];
                    nz = hit[2] - ra[5];
                }

                if (result != 0) {
                    /* normal scaled by 1/radius; d = signed distance of the end point from the contact plane */
                    nx = nx / arg3;
                    ny = ny / arg3;
                    nz = nz / arg3;
                    endX = arg1[0];
                    endY = arg1[1];
                    endZ = arg1[2];
                    hitDot = (hit[0] * nx) + (hit[1] * ny) + (hit[2] * nz);
                    d = ((endX * nx) + (endY * ny) + (endZ * nz)) - hitDot;
                    out = (u8 *)arg2;
                    if ((arg4 & 0x81) != 0) {
                        if ((arg4 & 1) != 0) {
                            arg1[0] = hit[0];
                            arg1[1] = hit[1];
                            arg1[2] = hit[2];
                        } else {
                            tt = 0.1f - d;
                            arg1[0] = endX + (tt * nx);
                            arg1[1] = endY + (tt * ny);
                            arg1[2] = endZ + (tt * nz);
                        }
                        *(f32 *)(out + 0x04) = nx;
                        *(f32 *)(out + 0x08) = ny;
                        *(f32 *)(out + 0x0C) = nz;
                        if (ny >= 0.707f) {
                            out[0x25] = (u8)(out[0x25] | 0x10);
                        } else if (ny <= -0.866f) {
                            out[0x25] = (u8)(out[0x25] | 0x40);
                        } else {
                            out[0x25] = (u8)(out[0x25] | 0x20);
                        }
                    } else if (ny >= 0.707f) {
                        arg1[1] = (-((endZ * nz) + (endX * nx) - hitDot) / ny) + 0.1f;
                        *(f32 *)(out + 0x04) = nx;
                        *(f32 *)(out + 0x08) = ny;
                        *(f32 *)(out + 0x0C) = nz;
                        out[0x25] = (u8)(out[0x25] | 0x10);
                    } else if (ny <= -0.866f) {
                        tt = 0.1f - d;
                        arg1[0] = endX + (tt * nx);
                        arg1[1] = endY + (tt * ny);
                        arg1[2] = endZ + (tt * nz);
                        out[0x25] = (u8)(out[0x25] | 0x40);
                    } else {
                        negD = -d;
                        px = endX + (negD * nx);
                        py = endY + (negD * ny);
                        pz = endZ + (negD * nz);
                        tmp[0] = endX - px;
                        tmp[1] = arg1[1] - py;
                        tmp[2] = endZ - pz;
                        cosv = Cosf((s16)Arctanf(tmp[1], sqrtf((tmp[0] * tmp[0]) + (tmp[2] * tmp[2]))));
                        if (cosv != 0.0f) {
                            t20 = (negD + 0.1f) / cosv;
                            hl = sqrtf((nx * nx) + (nz * nz));
                            hdx = nx / hl;
                            hdz = nz / hl;
                            arg1[0] = endX + (t20 * hdx);
                            arg1[2] = endZ + (t20 * hdz);
                        } else {
                            arg1[0] = px;
                            arg1[1] = py;
                            arg1[2] = pz;
                        }
                        out[0x25] = (u8)(out[0x25] | 0x20);
                    }

                    *(f32 *)(out + 0x1C) = t * t;
                    *(f32 *)(out + 0x14) = ny;
                    *(f32 *)(out + 0x10) = nx;
                    *(f32 *)(out + 0x18) = nz;
                    out[0x24] = 0;
                    *(s32 *)(out + 0x20) = *(s32 *)(*(u8 **)(geo + 0x24) + (*(s16 *)(rec + 0x2C) << 4) + 0x0C);
                    out[0x26] = (u8)*(s16 *)(rec + 0x2E);
                    if (lastHit != *(u8 **)out) {
                        *(u8 **)out = lastHit;
                        out[0x27] = (u8)((s8)out[0x27] + 1);
                    }
                    /* hit: stop scanning the list */
                    break;
                }
            }
        }
        slotE0 = ny;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitPolyEdgeTest.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitPolyEdgeBuffer(void) {
    LevelHeader *lvl;
    u8 *obj = NULL;
    u8 *sub;
    u8 *model = NULL;
    u8 *hdr = NULL;
    u8 *pflag = NULL;
    f32 (*mtx)[4] = NULL;
    u8 *fb;
    u8 *recs;
    u8 *rec24;
    u8 *vbase;
    u8 *vA;
    u8 *vB;
    f32 *o;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;
    s32 count;
    s32 i;
    s32 savedI;
    s32 s2;
    s32 s3;
    s32 v1;
    s32 s5;

    lvl = levelGetLevel();
    D_80104804_B1774 = 0;
    count = D_801047F0_B1760;
    for (i = 0; i < count; i++) {
        s32 entry = ((s32 *)D_801047F4_B1764)[i];

        if (entry > 0) {
            /* entry is an object address without its KSEG0 bit */
            obj = (u8 *)((u32)entry | 0x80000000U);
            sub = *(u8 **)(obj + 0x5C);
            model = *(u8 **)(*(u8 **)(obj + 0x6C) + (sub[0x133] * 4));
            hdr = *(u8 **)model;
            pflag = *(u8 **)(model + 0x0C);
            if (pflag == NULL) {
                pflag = *(u8 **)(hdr + 0x60);
            }
            mtx = (f32 (*)[4])(sub + (sub[0x12B] << 6) + 0x80);
        } else {
            s5 = ((s16 *)D_801047FC_B176C)[i];
            recs = *(u8 **)(hdr + 0x20) + s5 * 0x10;
            rec24 = *(u8 **)(hdr + 0x24) + (((s16 *)D_801047F8_B1768)[i] * 0x10);
            vbase = *(u8 **)(model + 0x04) + (*(s16 *)(rec24 + 6) * 0xA);
            fb = *(u8 **)(pflag + 0x08);
            savedI = i;
            s2 = 0;
            do {
                s3 = 1 << s2;
                v1 = s2 + 1;
                if (v1 >= 3) {
                    v1 = 0;
                }
                if (fb[s5] & s3) {
                    o = (f32 *)((u8 *)D_80104800_B1770 + (D_80104804_B1774 * 0x30));
                    vA = vbase + (recs[s2 + 1] * 0xA);
                    vB = vbase + (recs[v1 + 1] * 0xA);
                    mathMtxXFMF(mtx, (f32)*(s16 *)vA, (f32)*(s16 *)(vA + 2), (f32)*(s16 *)(vA + 4), &o[0], &o[1], &o[2]);
                    mathMtxXFMF(mtx, (f32)*(s16 *)vB, (f32)*(s16 *)(vB + 2), (f32)*(s16 *)(vB + 4), &o[3], &o[4], &o[5]);

                    dx = o[3] - o[0];
                    dy = o[4] - o[1];
                    dz = o[5] - o[2];
                    len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                    o[9] = len;
                    if (len > 0.0f) {
                        o[6] = dx / len;
                        o[7] = dy / len;
                        o[8] = dz / len;
                        *(u8 **)((u8 *)o + 0x28) = obj;
                        *(s16 *)((u8 *)o + 0x2C) = ((s16 *)D_801047F8_B1768)[i];
                        *(s16 *)((u8 *)o + 0x2E) = 0;
                        if (recs[0] & (s3 * 4)) {
                            *(s16 *)((u8 *)o + 0x2E) = 1;
                        }
                        D_80104804_B1774 = D_80104804_B1774 + 1;
                        if (D_80104804_B1774 >= *(s16 *)((u8 *)lvl + 0xF0)) {
                            savedI = count;
                            break;
                        }
                    }
                }
                s2++;
            } while (s2 < 3);
            i = savedI;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitPolyEdgeBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Object-hit counterpart of trackNearestIntersection (track.c, same two-pass shape and the same
// insertion-sort / clip / edge-plane structure; cf. track.c trackNearestIntersection).
// Pass 1: each active object (+0x4C u16 +0x0A bit 0) has its start moved into sub-object space
// (sub +0x12C enables the two-matrix transform, sub[0x12B] is the matrix index; type 0x37 goes
// through GenerateSpitTexture instead) and the segment is clipped against the sub box
// (sub +0x100 / +0x10C) with trackClip3D. A hit keeps the object, clip entry t, the start point,
// and hitGetModCompareMask (model +0x8C) over the clipped segment box. Entries are insertion-sorted
// by t ascending; the list holds at most 0x10 entries.
// Pass 2: entries in that order. Groups (hdr +0x24, 0x10 stride: +0x08 first poly, +0x0C flags,
// +0x18 end poly) are skipped when their flags hit arg4. Each poly (plane list: +0x00 u16 record
// table, 0xE stride: plane index then three edge planes, bit 15 = negate; +0x04 u32 poly flags,
// ANDed with the pass-1 mask) is tested against the crossing of the segment with its plane. The
// crossing t = startD / (startD - endD) is kept when inside the three edge planes and nearer than
// the best so far. The scan stops after the first entry that produced a hit.
// Layouts as in hitSquashCheck / hitGetHeights / hitPolyPlaneTest above.
// arg0: caller object or NULL (sub +0x12A set, sub +0x130 running count, hit counters on the
// arg0 +0x68 chain). arg1 / arg2: world start / end. arg3: out record. arg4: group/poly mask.
// out: +0x00 hit object, +0x04 hit point (world), +0x10 normal (transposed plane, scaled by
// obj +0x08), +0x20 distance from start, +0x24 group flags, +0x28 = 0xFF. Returns 1 on hit.
s32 hitNearestIntersection(void *arg0, f32 *arg1, f32 *arg2, void *arg3, s32 arg4) {
    f32 tabT[0x10];
    s32 tabMask[0x10];
    void *tabObj[0x10];
    f32 *tabRec[0x10];
    f32 recs[0x10][3];
    f32 st[3];
    f32 tmp[3];
    f32 sA[3];
    f32 eA[3];
    f32 bestSub[3];
    f32 sx;
    f32 sy;
    f32 sz;
    f32 ex;
    f32 ey;
    f32 ez;
    f32 tEnter;
    f32 tExit;
    f32 bestT;
    f32 tt;
    f32 hx;
    f32 hy;
    f32 hz;
    f32 dX;
    f32 dY;
    f32 dZ;
    f32 startD;
    f32 endD;
    f32 pA;
    f32 pB;
    f32 pC;
    f32 pD;
    f32 d;
    f32 scale;
    f32 ox;
    f32 oy;
    f32 oz;
    s32 minV[3];
    s32 maxV[3];
    s32 count;
    s32 hitFound;
    s32 inside;
    s32 i;
    s32 j;
    s32 k;
    s32 g;
    s32 p;
    s32 e;
    u8 *bestPlane;
    u8 *hitObj;
    u8 *hitSub;
    u32 bestFlags;
    s32 type;

    count = 0;
    for (i = 0; i < D_801047E0_B1750; i++) {
        u8 *obj = ((u8 **)D_801047E4_B1754)[i];
        u8 *sub;
        u8 *model;
        u8 *mtxA;

        if ((*(u16 *)(*(u8 **)(obj + 0x4C) + 0x0A) & 1) == 0) {
            continue;
        }

        sub = *(u8 **)(obj + 0x5C);
        if (*(s16 *)(obj + 0x48) == 0x37) {
            st[0] = arg1[0];
            st[1] = arg1[1];
            st[2] = arg1[2];
            GenerateSpitTexture(obj, &st[0], &st[1], &st[2]);
        } else if (*(s16 *)(sub + 0x12C) != 0) {
            mathMtxXFMF((f32 (*)[4])(sub + ((sub[0x12B] ^ 1) << 6)), arg1[0], arg1[1], arg1[2],
                        &tmp[0], &tmp[1], &tmp[2]);
            mathMtxXFMF((f32 (*)[4])(sub + (sub[0x12B] << 6) + 0x80), tmp[0], tmp[1], tmp[2],
                        &st[0], &st[1], &st[2]);
        } else {
            st[0] = arg1[0];
            st[1] = arg1[1];
            st[2] = arg1[2];
        }

        sx = st[0];
        sy = st[1];
        sz = st[2];
        ex = arg2[0];
        ey = arg2[1];
        ez = arg2[2];
        if (trackClip3D(&sx, &sy, &sz, &ex, &ey, &ez, (f32 *)(sub + 0x100), (f32 *)(sub + 0x10C),
                        &tEnter, &tExit) == 0) {
            continue;
        }

        model = *(u8 **)(*(u8 **)(obj + 0x6C) + sub[0x133] * 4);
        mtxA = sub + (sub[0x12B] << 6);
        /* clipped start / end in sub-object space; min/max as truncated ints */
        mathMtxXFMF((f32 (*)[4])mtxA, sx, sy, sz, &sA[0], &sA[1], &sA[2]);
        mathMtxXFMF((f32 (*)[4])mtxA, ex, ey, ez, &eA[0], &eA[1], &eA[2]);
        for (k = 0; k < 3; k++) {
            s32 a = (s32)sA[k];
            s32 b = (s32)eA[k];

            if (b < a) {
                minV[k] = b;
                maxV[k] = a;
            } else {
                minV[k] = a;
                maxV[k] = b;
            }
        }

        tabMask[count] = hitGetModCompareMask(model + 0x8C, minV[0], minV[1], minV[2], maxV[0],
                                              maxV[1], maxV[2]);
        tabT[count] = tEnter;
        tabObj[count] = obj;
        recs[count][0] = st[0];
        recs[count][1] = st[1];
        recs[count][2] = st[2];
        tabRec[count] = &recs[count][0];

        /* insertion of entry count into the list sorted by t ascending */
        for (j = count; j > 0 && tabT[j] < tabT[j - 1]; j--) {
            f32 tf = tabT[j];
            s32 tm;
            void *to;
            f32 *tr;

            tabT[j] = tabT[j - 1];
            tabT[j - 1] = tf;

            tm = tabMask[j];
            tabMask[j] = tabMask[j - 1];
            tabMask[j - 1] = tm;

            to = tabObj[j];
            tabObj[j] = tabObj[j - 1];
            tabObj[j - 1] = to;

            tr = tabRec[j];
            tabRec[j] = tabRec[j - 1];
            tabRec[j - 1] = tr;
        }

        count++;
        if (count >= 0x10) {
            break;
        }
    }

    if (count == 0) {
        return 0;
    }

    bestT = 1.0f;
    bestPlane = NULL;
    hitObj = NULL;
    hitSub = NULL;
    bestFlags = 0;
    hitFound = 0;
    bestSub[0] = 0.0f;
    bestSub[1] = 0.0f;
    bestSub[2] = 0.0f;

    for (i = 0; i < count; i++) {
        u8 *obj = (u8 *)tabObj[i];
        u8 *sub = *(u8 **)(obj + 0x5C);
        u8 *model = *(u8 **)(*(u8 **)(obj + 0x6C) + sub[0x133] * 4);
        u8 *hdr = *(u8 **)model;
        u8 *pflag = *(u8 **)(model + 0x0C);
        u8 *mtxA = sub + (sub[0x12B] << 6);
        u8 *ptab;
        u8 *flagTab;
        u8 *planes;
        s32 grpCount;

        if (pflag == NULL) {
            pflag = *(u8 **)(hdr + 0x60);
        }
        ptab = *(u8 **)(pflag + 0x00);
        flagTab = *(u8 **)(pflag + 0x04);
        planes = *(u8 **)(pflag + 0x0C);

        mathMtxXFMF((f32 (*)[4])mtxA, tabRec[i][0], tabRec[i][1], tabRec[i][2], &sA[0], &sA[1],
                    &sA[2]);
        mathMtxXFMF((f32 (*)[4])mtxA, arg2[0], arg2[1], arg2[2], &eA[0], &eA[1], &eA[2]);
        dX = eA[0] - sA[0];
        dY = eA[1] - sA[1];
        dZ = eA[2] - sA[2];

        grpCount = *(s16 *)(hdr + 0x16);
        for (g = 0; g < grpCount; g++) {
            u8 *grp = *(u8 **)(hdr + 0x24) + g * 0x10;
            u32 gFlags = *(u32 *)(grp + 0x0C);
            s32 pStart = *(s16 *)(grp + 0x08);
            s32 pEnd = *(s16 *)(grp + 0x18);

            if ((gFlags & arg4) != 0) {
                pStart = pEnd;
            }

            for (p = pStart; p < pEnd; p++) {
                u32 pf = *(u32 *)(flagTab + p * 4) & (u32)tabMask[i];
                u16 *rec16 = (u16 *)(ptab + p * 0xE);
                u8 *plane;

                if (*(s16 *)(obj + 0x48) == 0x37) {
                    inside = ((pf & 0xFF) != 0) && ((pf & 0xFF00) != 0);
                } else {
                    inside = ((pf & 0xFF) != 0) && ((pf & 0xFF00) != 0) && ((pf & 0xFF0000) != 0);
                }
                if (!inside) {
                    continue;
                }

                plane = planes + rec16[0] * 0x10;
                pA = *(f32 *)(plane + 0x00);
                pB = *(f32 *)(plane + 0x04);
                pC = *(f32 *)(plane + 0x08);
                pD = *(f32 *)(plane + 0x0C);

                endD = (pA * eA[0]) + (pB * eA[1]) + (pC * eA[2]) + pD;
                if (endD < 0.0f) {
                    startD = (pA * sA[0]) + (pB * sA[1]) + (pC * sA[2]) + pD;
                    if (startD >= 0.0f) {
                        tt = startD / (startD - endD);
                        hx = (dX * tt) + sA[0];
                        hy = (dY * tt) + sA[1];
                        hz = (dZ * tt) + sA[2];

                        /* hit point must lie on the inner side of the three edge planes */
                        inside = 1;
                        for (e = 1; e < 4 && inside; e++) {
                            u32 raw = rec16[e];
                            u8 *ep = planes + (raw & 0x7FFF) * 0x10;

                            d = (*(f32 *)(ep + 0x00) * hx) + (*(f32 *)(ep + 0x04) * hy) +
                                (*(f32 *)(ep + 0x08) * hz) + *(f32 *)(ep + 0x0C);
                            if ((raw & 0x8000) != 0) {
                                d = -d;
                            }
                            if (d > 0.0f) {
                                inside = 0;
                            }
                        }

                        if (inside != 0 && tt < bestT) {
                            bestT = tt;
                            bestSub[0] = hx;
                            bestSub[1] = hy;
                            bestSub[2] = hz;
                            bestFlags = gFlags;
                            bestPlane = plane;
                            hitObj = obj;
                            hitSub = sub;
                            hitFound = 1;
                        }
                    }
                }
            }
        }

        if (hitFound != 0) {
            break;
        }
    }

    if (hitFound == 0) {
        return 0;
    }

    /* out record: hit object, world hit point, scaled plane normal, distance, group flags */
    *(void **)((u8 *)arg3 + 0x00) = hitObj;
    mathMtxXFMF((f32 (*)[4])(hitSub + (hitSub[0x12B] << 6) + 0x80), bestSub[0], bestSub[1],
                bestSub[2], (f32 *)((u8 *)arg3 + 0x04), (f32 *)((u8 *)arg3 + 0x08),
                (f32 *)((u8 *)arg3 + 0x0C));
    matrixTransposeVectorMultiply(hitSub + (hitSub[0x12B] << 6), bestPlane,
                                  (f32 *)((u8 *)arg3 + 0x10));
    scale = *(f32 *)(hitObj + 0x08);
    *(f32 *)((u8 *)arg3 + 0x10) = *(f32 *)((u8 *)arg3 + 0x10) * scale;
    *(f32 *)((u8 *)arg3 + 0x14) = *(f32 *)((u8 *)arg3 + 0x14) * scale;
    *(f32 *)((u8 *)arg3 + 0x18) = *(f32 *)((u8 *)arg3 + 0x18) * scale;
    *(f32 *)((u8 *)arg3 + 0x1C) = *(f32 *)((u8 *)arg3 + 0x1C) * scale;

    ox = *(f32 *)((u8 *)arg3 + 0x04) - arg1[0];
    oy = *(f32 *)((u8 *)arg3 + 0x08) - arg1[1];
    oz = *(f32 *)((u8 *)arg3 + 0x0C) - arg1[2];
    *(f32 *)((u8 *)arg3 + 0x20) = sqrtf((ox * ox) + (oy * oy) + (oz * oz));
    *(u32 *)((u8 *)arg3 + 0x24) = bestFlags;
    *(s32 *)((u8 *)arg3 + 0x28) = 0xFF;

    if (arg0 != NULL) {
        *(u8 *)(hitSub + 0x12A) = 1;
        type = *(s16 *)((u8 *)arg0 + 0x48);
        if (type == 0xA2 || type == 0x9E || type == 0xA3 || type == 0xA8) {
            if (multiPlayerGame != 0 && type == 0xA2 && *(s16 *)(hitObj + 0x48) == 0x78) {
                u8 *other = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x68) + 0x70);

                if (other != NULL && *(s16 *)(other + 0x48) == 0x76) {
                    s32 need = *(s16 *)(*(u8 **)(hitObj + 0x4C) + 0x06) - *(s16 *)(hitSub + 0x130);

                    if (need > 0 && *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x06) >= need) {
                        u8 *cnt = *(u8 **)(other + 0x68);

                        if (*(s16 *)(hitObj + 0x4A) == 0x245) {
                            *(u16 *)(cnt + 0x04) = (u16)(*(u16 *)(cnt + 0x04) + 1);
                        } else {
                            *(u16 *)(cnt + 0x06) = (u16)(*(u16 *)(cnt + 0x06) + 1);
                        }
                        *(s32 *)(cnt + 0x08) = (s32)(*(u16 *)(cnt + 0x06) - *(u16 *)(cnt + 0x04));
                    }
                }
            }
            *(s16 *)(hitSub + 0x130) = (s16)(*(s16 *)(hitSub + 0x130) +
                                             *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x06));
        }
    }

    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitNearestIntersection.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. track.c trackGetLedgeCrossed (same PL-list walk and wall test). Hit blocks differ:
// entry > 0 is an object whose segment a->b is first transformed into object space with the
// sub-object matrix (sub + sub[0x12B] * 64); the block/model/header/pflag are then carried to the
// following poly entries. Layout as in hitPolyEdgeBuffer: pflag +0x00 plane index table (u16,
// stride 0xE per poly), +0x08 edge flags, +0x0C plane records (0x10 each).
// On a hit: out[0..2] = edge start, out[3..5] = edge end, out[6] = edge param s,
// out[7] (0x1C) = plane record, *outBlk = hit block. Returns sign of N.D (+1/-1), or 0.
s32 hitGetLedgeCrossed(f32 *a, f32 *b, f32 *out, s32 *outBlk) {
    s32 result = 0;
    u8 *blk = NULL;   /* asm s4: carried from the last object entry (uninitialised if PL[0] <= 0) */
    u8 *model = NULL; /* asm sp140 */
    u8 *hdr = NULL;   /* asm sp144 / ra */
    u8 *pflag = NULL; /* asm s1 */
    f32 ax = 0.0f;    /* a in object space (asm sp124/sp128/sp12C) */
    f32 ay = 0.0f;
    f32 az = 0.0f;
    f32 dx = 0.0f;    /* b - a in object space (asm sp10C/sp110/sp114) */
    f32 dy = 0.0f;
    f32 dz = 0.0f;
    s32 i;

    for (i = 0; i < D_801047F0_B1760; i++) {
        s32 entry = ((s32 *)D_801047F4_B1764)[i];

        if (entry > 0) {
            u8 *sub;
            f32 (*mtx)[4];
            f32 bx;
            f32 by;
            f32 bz;

            /* entry is an object address without its KSEG0 bit */
            blk = (u8 *)((u32)entry | 0x80000000U);
            sub = *(u8 **)(blk + 0x5C);
            model = *(u8 **)(*(u8 **)(blk + 0x6C) + (sub[0x133] * 4));
            hdr = *(u8 **)model;
            pflag = *(u8 **)(model + 0x0C);
            if (pflag == NULL) {
                pflag = *(u8 **)(hdr + 0x60);
            }
            mtx = (f32 (*)[4])(sub + (sub[0x12B] << 6));
            mathMtxXFMF(mtx, a[0], a[1], a[2], &ax, &ay, &az);
            mathMtxXFMF(mtx, b[0], b[1], b[2], &bx, &by, &bz);
            dx = bx - ax;
            dy = by - ay;
            dz = bz - az;
        } else {
            s32 polyIdx = ((s16 *)D_801047FC_B176C)[i];
            s32 grpIdx = ((s16 *)D_801047F8_B1768)[i];
            u8 *tri = *(u8 **)(hdr + 0x20) + polyIdx * 0x10;
            u8 *grp = *(u8 **)(hdr + 0x24) + grpIdx * 0x10;
            u8 *verts = *(u8 **)(model + 0x04) + *(s16 *)(grp + 0x06) * 0xA;
            u8 *edgeTab = *(u8 **)(pflag + 0x08);
            u32 edgeBits = (edgeTab[polyIdx] >> 3) & 0xFF;
            s32 e;

            if (edgeBits & 7) {
                for (e = 0; e < 3; e++) {
                    if (edgeBits & (1 << e)) {
                        s32 e1 = (e + 1) % 3;
                        u8 *va = verts + tri[1 + e] * 0xA;
                        u8 *vb = verts + tri[1 + e1] * 0xA;
                        f32 x0 = (f32)*(s16 *)(va + 0);
                        f32 y0 = (f32)*(s16 *)(va + 2);
                        f32 z0 = (f32)*(s16 *)(va + 4);
                        f32 x1 = (f32)*(s16 *)(vb + 0);
                        f32 y1 = (f32)*(s16 *)(vb + 2);
                        f32 z1 = (f32)*(s16 *)(vb + 4);
                        f32 ex = x1 - x0;
                        f32 ey = y1 - y0;
                        f32 ez = z1 - z0;
                        // wall normal N = up x E with up = (0, 10, 0): (10*ez, 0, -10*ex)
                        f32 nx = 10.0f * ez;
                        f32 ny = 0.0f;
                        f32 nz = -(ex * 10.0f);
                        f32 denom = (nz * dz) + ((dx * nx) + (dy * ny));

                        if (denom != 0.0f) {
                            s32 sign = (denom < 0.0f) ? -1 : 1;
                            f32 cx = nx * (x0 - ax);
                            f32 cy = ny * (y0 - ay);
                            f32 cz = nz * (z0 - az);
                            f32 t = (cz + (cx + cy)) / denom;

                            if (t >= 0.0f && t <= 1.0f) {
                                f32 ix = (dx * t) + ax;
                                f32 iy = (dy * t) + ay;
                                f32 iz = (dz * t) + az;
                                f32 edgeLen2 = (ez * ez) + ((ex * ex) + (ey * ey));
                                f32 dotE = (ez * (iz - z0)) + ((ex * (ix - x0)) + (ey * (iy - y0)));
                                f32 s = dotE / edgeLen2;

                                if (s >= 0.0f && s <= 1.0f) {
                                    u8 *planeRec;

                                    result = sign;
                                    out[0] = x0;
                                    out[1] = y0;
                                    out[2] = z0;
                                    out[3] = x1;
                                    out[4] = y1;
                                    out[5] = z1;
                                    planeRec = *(u8 **)(pflag + 0x0C) +
                                               (*(u16 *)(*(u8 **)(pflag + 0x00) + polyIdx * 0xE)) * 0x10;
                                    out[6] = s;
                                    *(u8 **)((u8 *)out + 0x1C) = planeRec;
                                    *outBlk = (s32)blk;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (result != 0) {
            break;
        }
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitGetLedgeCrossed.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. track.c trackGetAdjacentLedge (same ledge-edge search over the PL list); hit blocks use
// a different layout (block -> mesh at +0x0, verts at +0x4, mesh tris +0x20 / groups +0x24).
// Block layout as in hitPolyEdgeBuffer above.
s32 hitGetAdjacentLedge(f32 *arg0, f32 *arg1) {
    s32 found = 0;
    s32 count;
    s32 i;
    s32 e;
    s32 qa[3]; /* arg0[0..2] truncated to int (asm: cvt.w.s, round toward zero) */
    s32 qb[3]; /* arg0[3..5] truncated to int */
    u8 *model = NULL; /* asm s3: carried from previous iteration (first iteration assumes a valid entry) */
    u8 *hdr = NULL;   /* asm s4 */
    u8 *pflag = NULL; /* asm s5 */

    qa[0] = (s32)arg0[0];
    qa[1] = (s32)arg0[1];
    qa[2] = (s32)arg0[2];
    qb[0] = (s32)arg0[3];
    qb[1] = (s32)arg0[4];
    qb[2] = (s32)arg0[5];

    count = D_801047F0_B1760;
    for (i = 0; i < count; i++) {
        s32 entry = ((s32 *)D_801047F4_B1764)[i];

        if (entry > 0) {
            /* entry is an object address without its KSEG0 bit */
            u8 *obj = (u8 *)((u32)entry | 0x80000000U);
            u8 *sub = *(u8 **)(obj + 0x5C);

            model = *(u8 **)(*(u8 **)(obj + 0x6C) + (sub[0x133] * 4));
            hdr = *(u8 **)model;
            pflag = *(u8 **)(model + 0x0C);
            if (pflag == NULL) {
                pflag = *(u8 **)(hdr + 0x60);
            }
        } else {
            s32 polyIdx = ((s16 *)D_801047FC_B176C)[i];
            s32 grpIdx = ((s16 *)D_801047F8_B1768)[i];
            u8 *tris = *(u8 **)(hdr + 0x20) + polyIdx * 0x10;
            u8 *grp = *(u8 **)(hdr + 0x24) + grpIdx * 0x10;
            u8 *verts = *(u8 **)(model + 0x04) + *(s16 *)(grp + 0x06) * 0xA;
            u8 *edgeFlags = *(u8 **)(pflag + 0x08);
            u32 edgeBits = (edgeFlags[polyIdx] >> 3) & 0xFF;

            if (edgeBits & 7) {
                for (e = 0; e < 3; e++) {
                    if (edgeBits & (1 << e)) {
                        /* tri vertex indices are bytes at +1..+3 of the 0x10-byte record */
                        u8 *va = verts + tris[e + 1] * 0xA;
                        s32 nextE = e + 1;
                        u8 *vb;
                        s32 match;

                        if (nextE >= 3) {
                            nextE = 0;
                        }
                        vb = verts + tris[nextE + 1] * 0xA;

                        if (arg0[6] < 0.5f) {
                            match = (qa[0] == *(s16 *)(vb + 0) && qa[1] == *(s16 *)(vb + 2) &&
                                     qa[2] == *(s16 *)(vb + 4));
                        } else {
                            match = (qb[0] == *(s16 *)(va + 0) && qb[1] == *(s16 *)(va + 2) &&
                                     qb[2] == *(s16 *)(va + 4));
                        }
                        if (match) {
                            found = 1;
                            arg1[0] = (f32)*(s16 *)(va + 0);
                            arg1[1] = (f32)*(s16 *)(va + 2);
                            arg1[2] = (f32)*(s16 *)(va + 4);
                            arg1[3] = (f32)*(s16 *)(vb + 0);
                            arg1[4] = (f32)*(s16 *)(vb + 2);
                            arg1[5] = (f32)*(s16 *)(vb + 4);
                        }
                    }
                }
            }
        }
        if (found) {
            break;
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitGetAdjacentLedge.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitCrateCheck(f32 *arg0, f32 *arg1, void *arg2) {
    s32 i;
    s32 k;
    s32 valid;

    for (i = 0; i < D_801047E0_B1750; i++) {
        u8 *obj = ((u8 **)D_801047E4_B1754)[i];
        u8 *crate = *(u8 **)(obj + 0x5C);

        if (*(s16 *)(obj + 0x48) != 0x5B) {
            continue;
        }
        if (obj == (u8 *)arg2) {
            continue;
        }
        if (*(s16 *)(crate + 0x12C) == 0) {
            continue;
        }
        if ((*(u16 *)(*(u8 **)(obj + 0x4C) + 0xA) & 1) == 0) {
            continue;
        }
        if (!((*(f32 *)(obj + 0x10) - *(f32 *)(crate + 0x11C)) < 0.0f)) {
            continue;
        }

        valid = 1;
        for (k = 0; k < 3 && valid; k++) {
            f32 p = arg0[k];
            f32 lo = *(f32 *)(crate + 0x100 + k * 4);
            f32 hi = *(f32 *)(crate + 0x10C + k * 4);

            if (p < lo && arg1[k] < lo) {
                valid = 0;
            } else if (hi < p && hi < arg1[k]) {
                valid = 0;
            }
        }

        if (valid) {
            u8 *t0 = *(u8 **)(obj + 0x68);

            *(s32 *)(t0 + 0x1C) = 1;
            *(s16 *)(t0 + 0x00) = -0x7D00;
            *(u16 *)(*(u8 **)(obj + 0x4C) + 0xA) &= ~1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitCrateCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Surface probe for a sphere of radius rad around pts (world space). Each active hit
// object (D_801047E4 list, D_801047E0 count, skipping excl) whose bbox overlaps the
// rad-box is mapped into model space with matrix +0x12B (0x40-byte matrices). Every
// triangle of the touched groups is then tested: (a) the point projected along the
// scaled plane normal lands inside the triangle prism -> height = projected Y;
// (b) the closest point of each triangle edge (or the nearest vertex) within rad ->
// height = that point through the second matrix (+0x80). The lowest height below
// *outY wins; the matching object is returned (NULL if none).
// rad arrives as raw f32 bits in $a1 (charControl.c passes it as s32).
// Layouts follow the hitGetHeights walk in this file:
// Hit object: +0x08 f32 scale, +0x48 s16 type (0x37 = always tested), +0x4C hit
//   (u16 +0x0A bit0 = active), +0x5C sub, +0x6C model table.
// Sub: +0x100/+0x10C bbox min/max (x,y,z), +0x12B u8 matrix index, +0x12C s16 enable,
//   +0x133 u8 model index.
// Model: +0x00 hdr, +0x04 vertex base (10-byte s16 xyz), +0x0C plane list (or hdr+0x60),
//   +0x8C mask input.
// Hdr: +0x16 s16 group count, +0x20 tri table (16 B, bytes +1..+3 = vertex indices),
//   +0x24 group table (0x10 stride: +0x06 s16 vbase, +0x08 s16 start, +0x0C u32 flags,
//   +0x18 s16 end).
// Plane list: +0x00 u16 record table (0xE stride: u16 plane index, then three u16 side
//   plane indices, bit 15 = negate), +0x04 u32 flags, +0x0C planes (16 B: A,B,C,D).
void *hitSquashCheck(f32 *pts, f32 rad, void *excl, f32 *outY) {
    void *result = NULL;
    s32 found = 0;
    s32 count = D_801047E0_B1750;
    s32 i;
    s32 k;
    f32 lo[3];
    f32 hi[3];

    for (k = 0; k < 3; k++) {
        lo[k] = pts[k] - rad;
        hi[k] = pts[k] + rad;
    }
    *outY = pts[1] + rad;

    for (i = 0; i < count && !found; i++) {
        u8 *obj = *(u8 **)((u8 *)D_801047E4_B1754 + i * 4);
        u8 *sub;
        u8 *model;
        u8 *hdr;
        u8 *pl;
        u8 *planes;
        u8 *mtx1;
        u8 *mtx2;
        f32 scale;
        f32 mx, my, mz;
        f32 rScaled;
        f32 radSq;
        s32 ix, iy, iz, ir;
        s32 mask;
        s32 valid;
        s32 groupCount;
        s32 g;

        if (obj == excl) {
            continue;
        }
        if ((*(u16 *)(*(u8 **)(obj + 0x4C) + 0x0A) & 1) == 0) {
            continue;
        }
        sub = *(u8 **)(obj + 0x5C);
        if (*(s16 *)(obj + 0x48) != 0x37 && *(s16 *)(sub + 0x12C) == 0) {
            continue;
        }

        valid = 1;
        for (k = 0; k < 3 && valid; k++) {
            f32 bmin = *(f32 *)(sub + 0x100 + k * 4);
            f32 bmax = *(f32 *)(sub + 0x10C + k * 4);

            if (lo[k] < bmin && hi[k] < bmin) {
                valid = 0;
            } else if (bmax < lo[k] && bmax < hi[k]) {
                valid = 0;
            }
        }
        if (!valid) {
            continue;
        }

        model = ((u8 **)*(u8 **)(obj + 0x6C))[*(u8 *)(sub + 0x133)];
        hdr = *(u8 **)model;
        pl = *(u8 **)(model + 0x0C);
        if (pl == NULL) {
            pl = *(u8 **)(hdr + 0x60);
        }
        planes = *(u8 **)(pl + 0x0C);
        mtx1 = sub + (*(u8 *)(sub + 0x12B) << 6);
        mtx2 = mtx1 + 0x80;
        scale = *(f32 *)(obj + 0x08);

        mathMtxXFMF((f32 (*)[4])mtx1, pts[0], pts[1], pts[2], &mx, &my, &mz);
        rScaled = scale * rad;
        radSq = rScaled * rScaled;
        ir = (s16)(s32)rScaled;
        ix = (s16)(s32)mx;
        iy = (s16)(s32)my;
        iz = (s16)(s32)mz;
        mask = hitGetModCompareMask(model + 0x8C, ix - ir, iy - ir, iz - ir,
                                    ix + ir, iy + ir, iz + ir);

        groupCount = *(s16 *)(hdr + 0x16);
        for (g = 0; g < groupCount; g++) {
            u8 *grp = *(u8 **)(hdr + 0x24) + g * 0x10;
            s32 start = *(s16 *)(grp + 0x08);
            s32 end = *(s16 *)(grp + 0x18);
            s32 idx;

            if (*(u32 *)(grp + 0x0C) & 0x880) {
                start = end;
            }

            for (idx = start; idx < end; idx++) {
                u8 *rec = *(u8 **)pl + idx * 0xE;
                u32 fl = *(u32 *)(*(u8 **)(pl + 0x04) + idx * 4) & (u32)mask;
                s32 ok;

                ok = (fl & 0xFF) != 0 && (fl & 0xFF00) != 0 &&
                     (*(s16 *)(obj + 0x48) == 0x37 || (fl & 0xFF0000) != 0);
                if (!ok) {
                    continue;
                }

                {
                    f32 nv[4];
                    f32 nx, ny, nz, nd;
                    f32 dd;

                    matrixTransposeVectorMultiply(mtx1, planes + (*(u16 *)rec) * 0x10, nv);
                    nx = nv[0] * scale;
                    ny = nv[1] * scale;
                    nz = nv[2] * scale;
                    nd = nv[3] * scale;

                    if (ny < -0.707f) {
                        dd = nx * pts[0] + ny * pts[1] + nz * pts[2] + nd;

                        /* (a) projected point inside the triangle prism */
                        if (-rad < dd && dd < rad) {
                            f32 qx = pts[0] - dd * nx;
                            f32 qy = pts[1] - dd * ny;
                            f32 qz = pts[2] - dd * nz;
                            f32 q[3];
                            s32 side;

                            mathMtxXFMF((f32 (*)[4])mtx1, qx, qy, qz, &q[0], &q[1], &q[2]);
                            valid = 1;
                            for (side = 0; side < 3 && valid; side++) {
                                u16 pi = *(u16 *)(rec + 2 + side * 2);
                                u8 *pln = planes + (pi & 0x7FFF) * 0x10;
                                f32 sv = *(f32 *)(pln + 0x00) * q[0] + *(f32 *)(pln + 0x04) * q[1] +
                                         *(f32 *)(pln + 0x08) * q[2] + *(f32 *)(pln + 0x0C);

                                if (pi & 0x8000) {
                                    sv = -sv;
                                }
                                if (sv > 0.0f) {
                                    valid = 0;
                                }
                            }
                            if (valid && qy < *outY) {
                                *outY = qy;
                                result = obj;
                                found = 1;
                            }
                        }

                        /* (b) closest point on each triangle edge / nearest vertex */
                        {
                            u8 *tri = *(u8 **)(hdr + 0x20) + idx * 0x10;
                            u8 *vb = *(u8 **)(model + 0x04) + (*(s16 *)(grp + 0x06)) * 10;
                            s32 e;

                            for (e = 0; e < 3; e++) {
                                s32 en = (e + 1 < 3) ? e + 1 : 0;
                                u8 *va = vb + tri[1 + e] * 10;
                                u8 *vq = vb + tri[1 + en] * 10;
                                f32 ax = (f32)*(s16 *)(va + 0);
                                f32 ay = (f32)*(s16 *)(va + 2);
                                f32 az = (f32)*(s16 *)(va + 4);
                                f32 bx = (f32)*(s16 *)(vq + 0);
                                f32 by = (f32)*(s16 *)(vq + 2);
                                f32 bz = (f32)*(s16 *)(vq + 4);
                                f32 ex = bx - ax;
                                f32 ey = by - ay;
                                f32 ez = bz - az;
                                f32 dxA = mx - ax;
                                f32 dyA = my - ay;
                                f32 dzA = mz - az;
                                f32 dot = ex * dxA + ey * dyA + ez * dzA;
                                f32 len2 = ex * ex + ey * ey + ez * ez;
                                f32 t = dot / len2;

                                if (0.0f <= t && t <= 1.0f) {
                                    f32 cX = ax + ex * t;
                                    f32 cY = ay + ey * t;
                                    f32 cZ = az + ez * t;
                                    f32 ddx = mx - cX;
                                    f32 ddy = my - cY;
                                    f32 ddz = mz - cZ;

                                    if (ddx * ddx + ddy * ddy + ddz * ddz < radSq) {
                                        f32 o[3];

                                        mathMtxXFMF((f32 (*)[4])mtx2, cX, cY, cZ, &o[0], &o[1], &o[2]);
                                        if (o[1] < *outY) {
                                            *outY = o[1];
                                            result = obj;
                                            found = 1;
                                        }
                                    }
                                } else if (dxA * dxA + dyA * dyA + dzA * dzA < radSq) {
                                    f32 o[3];

                                    mathMtxXFMF((f32 (*)[4])mtx2, ax, ay, az, &o[0], &o[1], &o[2]);
                                    if (o[1] < *outY) {
                                        *outY = o[1];
                                        result = obj;
                                        found = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitSquashCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. DKR tracks.c trackGetHeights: same 0x14-byte record / 0x14 cap / bubble-sort shape.
// Hit object: +0x4C hit (u16 +0x0A bit0 = active), +0x5C sub (bbox minX +0x100,
// minZ +0x108, maxX +0x10C, maxZ +0x114; u8 +0x12B = transform index, 0x40-byte
// matrices with a second one at +0x80; u8 +0x133 = model index), +0x6C model table,
// +0x08 f32 scale.
// Model: +0x00 hdr, +0x04 vertex base (10-byte s16 xyz), +0x0C plane list (or hdr+0x60).
// Plane list: +0x00 u16 plane index table (stride 0xE), +0x0C planes (16 B: A,B,C,D).
// Hdr: +0x16 group count, +0x20 tri table (16 B, bytes +1..+3 = vertex indices),
// +0x24 group table (16 B: +0x06 vbase, +0x08 gStart, +0x0C flags, +0x18 gEnd).
// Each hit is a 0x14-byte record in D_80104C68_B1BD8:
//   +0x00 f32 height, +0x04/+0x08/+0x0C f32 scaled plane normal (A,B,C), +0x10 hit object.
// Records are capped at 0x14 and sorted by height (descending) through pointers in
// D_80104DF8_B1D68, which is returned via *out. Returns the record count.
s32 hitGetHeights(f32 x, f32 z, s32 mask, f32 ***out) {
    u8 *hits[0x10];
    u8 *obj;
    u8 *sub;
    u8 *model;
    u8 *hdr;
    u8 *pflag;
    u8 *grp;
    u8 *tri;
    u8 *verts;
    u8 *vA;
    u8 *vB;
    u8 *vC;
    u8 *plane;
    u8 *rec;
    f32 (*mtxA)[4];
    f32 (*mtxB)[4];
    f32 plane4[4];
    f32 tA[3];
    f32 tB[3];
    f32 tC[3];
    f32 scale;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 dd;
    f32 *tmp;
    s32 nHits;
    s32 nRec;
    s32 count;
    s32 i;
    s32 j;
    s32 g;
    s32 p;
    s32 gStart;
    s32 gEnd;
    s32 vbase;
    s32 flags;
    s32 ti;
    s32 rem;
    s32 last;
    s32 swapped;
    s32 edge0;
    s32 edge1;
    s32 edge2;

    *out = NULL;
    nHits = 0;
    count = D_801047E0_B1750;
    for (i = 0; i < count; i++) {
        obj = ((u8 **)D_801047E4_B1754)[i];
        if (*(u16 *)(*(u8 **)(obj + 0x4C) + 0x0A) & 1) {
            sub = *(u8 **)(obj + 0x5C);
            if (*(f32 *)(sub + 0x100) <= x && x <= *(f32 *)(sub + 0x10C) &&
                *(f32 *)(sub + 0x108) <= z && z <= *(f32 *)(sub + 0x114)) {
                hits[nHits] = obj;
                nHits++;
                if (nHits >= 0x10) {
                    break;
                }
            }
        }
    }
    if (nHits == 0) {
        return 0;
    }

    mask |= 0x880;
    nRec = 0;
    for (i = 0; i < nHits; i++) {
        obj = hits[i];
        sub = *(u8 **)(obj + 0x5C);
        model = *(u8 **)(*(u8 **)(obj + 0x6C) + (sub[0x133] * 4));
        hdr = *(u8 **)model;
        pflag = *(u8 **)(model + 0x0C);
        if (pflag == NULL) {
            pflag = *(u8 **)(hdr + 0x60);
        }
        mtxA = (f32 (*)[4])(sub + (sub[0x12B] << 6));
        mtxB = (f32 (*)[4])(sub + (sub[0x12B] << 6) + 0x80);
        scale = *(f32 *)(obj + 0x08);

        count = *(s16 *)(hdr + 0x16);
        for (g = 0; g < count; g++) {
            grp = *(u8 **)(hdr + 0x24) + g * 0x10;
            vbase = *(s16 *)(grp + 0x06);
            gStart = *(s16 *)(grp + 0x08);
            gEnd = *(s16 *)(grp + 0x18);
            flags = *(u32 *)(grp + 0x0C);
            if (flags & mask) {
                gStart = gEnd;
            }

            for (p = gStart; p < gEnd; p++) {
                ti = *(u16 *)(*(u8 **)pflag + p * 0xE);
                plane = *(u8 **)(pflag + 0x0C) + ti * 0x10;
                matrixTransposeVectorMultiply(mtxA, plane, plane4);

                if (plane4[1] > 0.0f) {
                    tri = *(u8 **)(hdr + 0x20) + p * 0x10;
                    verts = *(u8 **)(model + 0x04);
                    vA = verts + (tri[1] + vbase) * 0xA;
                    vB = verts + (tri[2] + vbase) * 0xA;
                    vC = verts + (tri[3] + vbase) * 0xA;

                    mathMtxXFMF(mtxB, (f32)*(s16 *)vA, (f32)*(s16 *)(vA + 2), (f32)*(s16 *)(vA + 4),
                                &tA[0], &tA[1], &tA[2]);
                    mathMtxXFMF(mtxB, (f32)*(s16 *)vB, (f32)*(s16 *)(vB + 2), (f32)*(s16 *)(vB + 4),
                                &tB[0], &tB[1], &tB[2]);
                    mathMtxXFMF(mtxB, (f32)*(s16 *)vC, (f32)*(s16 *)(vC + 2), (f32)*(s16 *)(vC + 4),
                                &tC[0], &tC[1], &tC[2]);

                    /* 2D point-in-triangle on (x,z): three edge half-plane tests must agree */
                    edge0 = ((tC[0] - tB[0]) * (z - tB[2])) <= ((tC[2] - tB[2]) * (x - tB[0]));
                    edge1 = ((tB[0] - tA[0]) * (z - tA[2])) <= ((tB[2] - tA[2]) * (x - tA[0]));
                    edge2 = ((tA[0] - tC[0]) * (z - tC[2])) <= ((tA[2] - tC[2]) * (x - tC[0]));
                    if (edge0 == edge1 && edge1 == edge2) {
                        nx = plane4[0] * scale;
                        ny = plane4[1] * scale;
                        nz = plane4[2] * scale;
                        dd = plane4[3] * scale;
                        rec = D_80104C68_B1BD8 + nRec * 0x14;
                        *(f32 *)(rec + 0x00) = -(((nx * x) + (nz * z) + dd) / ny);
                        *(f32 *)(rec + 0x04) = nx;
                        *(f32 *)(rec + 0x08) = ny;
                        *(f32 *)(rec + 0x0C) = nz;
                        *(void **)(rec + 0x10) = obj;
                        nRec++;
                        if (nRec >= 0x14) {
                            goto done;
                        }
                    }
                }
            }
        }
    }

done:
    if (nRec > 0) {
        /* pointer table: (n & 3) entries first, then 4 at a time, as in the asm */
        rem = nRec & 3;
        for (i = 0; i != rem; i++) {
            D_80104DF8_B1D68[i] = (f32 *)(D_80104C68_B1BD8 + i * 0x14);
        }
        for (; i != nRec; i += 4) {
            rec = D_80104C68_B1BD8 + i * 0x14;
            D_80104DF8_B1D68[i] = (f32 *)rec;
            D_80104DF8_B1D68[i + 1] = (f32 *)(rec + 0x14);
            D_80104DF8_B1D68[i + 2] = (f32 *)(rec + 0x28);
            D_80104DF8_B1D68[i + 3] = (f32 *)(rec + 0x3C);
        }

        /* bubble sort, heights descending; each pass covers all n-1 pairs */
        last = nRec - 1;
        do {
            swapped = 1;
            if (last > 0) {
                rem = last & 3;
                for (j = 0; j != rem; j++) {
                    if (*D_80104DF8_B1D68[j] < *D_80104DF8_B1D68[j + 1]) {
                        tmp = D_80104DF8_B1D68[j];
                        D_80104DF8_B1D68[j] = D_80104DF8_B1D68[j + 1];
                        D_80104DF8_B1D68[j + 1] = tmp;
                        swapped = 0;
                    }
                }
                for (; j != last; j += 4) {
                    if (*D_80104DF8_B1D68[j] < *D_80104DF8_B1D68[j + 1]) {
                        tmp = D_80104DF8_B1D68[j];
                        D_80104DF8_B1D68[j] = D_80104DF8_B1D68[j + 1];
                        D_80104DF8_B1D68[j + 1] = tmp;
                        swapped = 0;
                    }
                    if (*D_80104DF8_B1D68[j + 1] < *D_80104DF8_B1D68[j + 2]) {
                        tmp = D_80104DF8_B1D68[j + 1];
                        D_80104DF8_B1D68[j + 1] = D_80104DF8_B1D68[j + 2];
                        D_80104DF8_B1D68[j + 2] = tmp;
                        swapped = 0;
                    }
                    if (*D_80104DF8_B1D68[j + 2] < *D_80104DF8_B1D68[j + 3]) {
                        tmp = D_80104DF8_B1D68[j + 2];
                        D_80104DF8_B1D68[j + 2] = D_80104DF8_B1D68[j + 3];
                        D_80104DF8_B1D68[j + 3] = tmp;
                        swapped = 0;
                    }
                    if (*D_80104DF8_B1D68[j + 3] < *D_80104DF8_B1D68[j + 4]) {
                        tmp = D_80104DF8_B1D68[j + 3];
                        D_80104DF8_B1D68[j + 3] = D_80104DF8_B1D68[j + 4];
                        D_80104DF8_B1D68[j + 4] = tmp;
                        swapped = 0;
                    }
                }
            }
        } while (swapped == 0);
    }

    *out = D_80104DF8_B1D68;
    return nRec;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitGetHeights.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hitGetModCompareMask(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 *box = (u8 *)arg0;
    s32 lo;
    s32 hi;
    s32 qlo;
    s32 qhi;
    s32 step;
    s32 cur;
    s32 base;
    s32 mask;
    s32 bit;
    s32 i;

    if (arg0 == NULL) {
        return 0;
    }

    mask = 0;
    bit = 1;

    /* bits 0-7: axis box+0x0 .. box+0x6, query arg1 .. arg4 (both clamped to the axis range) */
    lo = *(s16 *)(box + 0x0);
    hi = *(s16 *)(box + 0x6);
    qlo = arg1;
    qhi = arg4;
    if (qlo < lo) {
        qlo = lo;
    }
    if (qhi < lo) {
        qhi = lo;
    }
    if (qlo > hi) {
        qlo = hi;
    }
    if (qhi > hi) {
        qhi = hi;
    }
    step = (s16)(((hi - lo) >> 3) + 1);
    cur = lo + step;
    base = lo;
    for (i = 0; i < 8; i++) {
        if (cur >= qlo && base <= qhi) {
            mask |= bit;
        }
        cur = (s16)(cur + step);
        base = (s16)(base + step);
        bit <<= 1;
    }

    /* bits 8-15: axis box+0x4 .. box+0xA, query arg3 .. arg6 (both clamped to the axis range) */
    lo = *(s16 *)(box + 0x4);
    hi = *(s16 *)(box + 0xA);
    qlo = arg3;
    qhi = arg6;
    if (qlo < lo) {
        qlo = lo;
    }
    if (qhi < lo) {
        qhi = lo;
    }
    if (qlo > hi) {
        qlo = hi;
    }
    if (qhi > hi) {
        qhi = hi;
    }
    step = (s16)(((hi - lo) >> 3) + 1);
    cur = lo + step;
    base = lo;
    for (i = 0; i < 8; i++) {
        if (cur >= qlo && base <= qhi) {
            mask |= bit;
        }
        cur = (s16)(cur + step);
        base = (s16)(base + step);
        bit <<= 1;
    }

    /* bits 16-23: axis box+0x2 .. box+0x8, query arg2 .. arg5 (both clamped to the axis range) */
    lo = *(s16 *)(box + 0x2);
    hi = *(s16 *)(box + 0x8);
    qlo = arg2;
    qhi = arg5;
    if (qlo < lo) {
        qlo = lo;
    }
    if (qhi < lo) {
        qhi = lo;
    }
    if (qlo > hi) {
        qlo = hi;
    }
    if (qhi > hi) {
        qhi = hi;
    }
    step = (s16)(((hi - lo) >> 3) + 1);
    cur = lo + step;
    base = lo;
    for (i = 0; i < 8; i++) {
        if (cur >= qlo && base <= qhi) {
            mask |= bit;
        }
        cur = (s16)(cur + step);
        base = (s16)(base + step);
        bit <<= 1;
    }

    return mask;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitGetModCompareMask.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitGetInelasticVelocity(void *arg0, void *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 w0;
    f32 w1;
    f32 mass0;
    f32 mass1;

    if (arg0 != NULL && arg1 != NULL) {
        mass0 = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x34);
        mass1 = *(f32 *)(*(u8 **)((u8 *)arg1 + 0x4C) + 0x34);
        if (mass0 <= 0.0f) {
            if (mass1 <= 0.0f) {
                w0 = 0.5f;
                w1 = 0.5f;
            } else {
                w0 = 1.0f;
                w1 = 0.0f;
            }
        } else if (mass1 <= 0.0f) {
            w0 = 0.0f;
            w1 = 1.0f;
        } else {
            f32 sum = mass0 + mass1;

            w0 = mass0 / sum;
            w1 = mass1 / sum;
        }
        *arg2 = (*(f32 *)((u8 *)arg0 + 0x1C) * w0) + (*(f32 *)((u8 *)arg1 + 0x1C) * w1);
        *arg3 = (*(f32 *)((u8 *)arg0 + 0x20) * w0) + (*(f32 *)((u8 *)arg1 + 0x20) * w1);
        *arg4 = (*(f32 *)((u8 *)arg0 + 0x24) * w0) + (*(f32 *)((u8 *)arg1 + 0x24) * w1);
        return;
    }
    if (arg0 == NULL && arg1 == NULL) {
        *arg2 = 0.0f;
        *arg3 = 0.0f;
        *arg4 = 0.0f;
        return;
    }
    if (arg0 == NULL) {
        *arg2 = *(f32 *)((u8 *)arg1 + 0x1C);
        *arg3 = *(f32 *)((u8 *)arg1 + 0x20);
        *arg4 = *(f32 *)((u8 *)arg1 + 0x24);
        return;
    }
    *arg2 = *(f32 *)((u8 *)arg0 + 0x1C);
    *arg3 = *(f32 *)((u8 *)arg0 + 0x20);
    *arg4 = *(f32 *)((u8 *)arg0 + 0x24);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/hit/hitGetInelasticVelocity.s")
#endif
