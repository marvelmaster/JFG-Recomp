#include "common.h"

/* decomp: externs */
extern u8 *D_overlay_3_0031A1D0;      /* overlay state struct */
extern u8 *D_overlay_3_0031A1D4;      /* object pointer */
extern u8 *D_overlay_3_0031A1D8;      /* config / object pointer */
extern u8 *D_overlay_3_0031A1E0;      /* config pointer */
extern u8 *D_overlay_3_0031A1E4;      /* target pointer, NULL when unset */
extern u8 *D_overlay_3_0031A1E8;      /* target pointer */
extern u8 *D_overlay_3_0031A1CC;      /* list cursor */
extern s16 D_overlay_3_0031A1DC;      /* index into D_overlay_3_00319278 */
extern s16 D_overlay_3_0031A148[];    /* tilt output list (s16 cmd/value pairs) */
void DragonflyTilt(u8 *, s16 **);
extern u8 D_overlay_3_0031A1F8[];     /* 0x10-byte entries */
extern u8 D_overlay_3_00319278[];     /* 4-byte entries */
extern u8 D_overlay_3_00317DB8[];     /* 8-byte entries */
extern u8 D_overlay_3_0031A390[];
extern void *D_overlay_3_0031AE90[];
extern s32 AnimPathNumbers[];
extern void *animpath[];
extern void *PathLists[];
extern void *D_800FF734;
extern f32 D_overlay_3_003199E8;
extern f32 D_overlay_3_003199EC;
extern f32 D_overlay_3_003199F0;
extern f32 D_overlay_3_003199F4;
extern f32 D_overlay_3_0031A1C8;
extern f32 D_overlay_3_003199F8;
extern u8 squadsBehaviour;
extern void *PatrolNodes;
extern s32 iDeltaTime;
extern f32 D_overlay_3_003199FC;
extern s32 D_overlay_3_0031976C[];    /* mission masks, 4-byte entries */
extern u16 D_overlay_3_003197D4[];    /* 2-byte entries */
extern f32 D_overlay_3_00319D50;
extern f32 D_overlay_3_00319D54;
extern f32 D_overlay_3_00319D58;
extern f32 D_overlay_3_00319D5C;
extern f32 D_overlay_3_00319D60;
extern f32 D_overlay_3_00319D64;
extern s32 D_overlay_3_0031A134;
extern s32 D_overlay_3_0031A13C;
extern void *D_overlay_3_00319678[];   /* AI facer jump table */
extern s32 D_overlay_3_003197F8;
extern u8 D_overlay_3_0031A12A;
extern s32 D_overlay_3_0031A120;
extern void *D_overlay_3_00319428;
extern void *D_overlay_3_0031A308[];
extern s32 D_overlay_3_0031A388;
extern s32 MaxPatrolNodes;
extern s32 D_overlay_3_0031A2F8;
extern s32 D_overlay_3_0031A2FC;
extern s32 D_overlay_3_0031A300;
extern u8 *D_overlay_3_0031AED0;      /* region node root */
extern u8 *D_overlay_3_0031AED4;      /* region edge array */
extern s32 D_overlay_3_0031AED8;
extern s32 D_overlay_3_0031AEDC;
extern s32 D_overlay_3_0031AEE0;
extern s32 D_overlay_3_0031AEE4;
extern s32 D_overlay_3_0031AEE8;
extern s32 D_overlay_3_0031AEEC;
extern f32 D_overlay_3_0031AEF0;
extern f32 D_overlay_3_0031AEF4;
extern f32 D_overlay_3_0031AEF8;
extern f32 D_overlay_3_0031AEFC;
extern s32 D_overlay_3_0031AF00;
extern s32 D_overlay_3_0031AF04;
extern s32 D_overlay_3_0031AF08;
extern u32 D_overlay_3_0031AF0C;
extern u8 D_overlay_3_0031AF10;
extern u8 D_overlay_3_0031AF11;
extern s32 D_overlay_3_00319448;
extern void *DisactivatedSquaddies;
extern u8 trackVisibleBlocks[];
extern u8 D_overlay_3_0031A128;
extern u8 D_overlay_3_0031A129;
extern void *D_overlay_3_003196E0[];  /* SquadronControl behaviour call table */
extern void *D_overlay_3_00319350[];  /* decomp: SquaddieControl fn table */
extern u8 D_overlay_3_00319460[];
extern void *D_overlay_3_00319610[];
extern s32 D_overlay_3_0031A140;
extern s32 D_overlay_3_0031A144;
void squadsChangeLevel(s32, s32);
void func_overlay_3_003142F0_1EE97D0(s32, s32);
void ReallyAddInterestingEvent(s32, s16, s16, s16, u8, u8, u8);
s32 IsPointInRegionIdx(f32, f32, s32);
extern f32 D_overlay_3_00319D84;
extern f32 D_overlay_3_00319DAC;
extern f32 D_overlay_3_00319DB0;
extern f32 D_overlay_3_00319DB4;
extern f32 D_overlay_3_00319E0C;
extern f32 D_overlay_3_00319E10;
extern f32 D_overlay_3_00319E14;
extern f32 D_overlay_3_00319E18;
void GalaxianBatsSoundsHandler(void *);
s32 squadsIsFoodAvailable(s8);
s32 mainGetTribalStatus(u8);
void squadsMakeFoodList(s32, s32);
void SetBlockedNodes(s32, s32);
void CreateBSPFromRegion(u8 *);
void PatrolPathsInit(void *, s32);
void animseqGetPathNumbers(f32, f32, s32, s16 *, s16 *);
void *func_overlay_3_00314694_1EE9B74(void);
void func_overlay_3_00313FE4_1EE94C4(s32);
s16 FlopsyDogFacer(u8 *, s32, s32, u8);
s16 SmartFacer(u8 *, s16, u16, u8);

f32 Sinf(s32);
f32 GetRangeSquared2D(f32, f32, s32, s32);
void TryToSetAnim();
s32 TryToUpdateAnim();
s32 TryToSetAnimByIndex();
void UpdateOrSetAnim();
void SquaddiePassesAway();
void NewFlopsyFunction();
void PerformNodeCommand(s32, void *, void *);
void squadsFireWeapon(s32, u32, s16);
void squadsKillSquaddie(void *);
void squadsGetFormationPosition(s32, u8, s32, s32, s32);
void mainSetTribalStatus(u8, s32);
void instShowBearBar();
void amSndPlayXYZ(u16, f32, f32, f32, u8, void *);
void killLight(s32);
void partUpdateTriggers(void *, s32);
void squadsPlayerShootsSquaddie(u8 *, s32);
void SlugBossMover(void *, f32);
void FatBobPhaseChange(void *, u16, s32, void *);
void SlugBossPhaseChange(void *, u16, s32, void *);
s32 levelObjectFlagSet(u8);
void *GetFirstDisactivatedSquaddie(s32);
void *objGetPlayerNo(s32);
void mathOneFloatPY(void *, f32 *);
void amSndSetPitchXYZ(SoundMask *, s32);
extern s32 SquaddieGrowlTimer;
extern s32 SquadsModuleFlags;
extern u8 D_overlay_3_00319466[];
extern f32 D_overlay_3_00319E1C;
extern f32 D_overlay_3_00319E20;
extern f32 D_overlay_3_00319F40;
void trackLightDelete(s32);
s32 trackPolyHeight(f32, f32, f32 *, s32);
s32 trackGetNearestPoly(f32, f32, f32, f32 *, s32, s32);
void objFreeObject(void *);
void **objGetObjList(s32 *, s32 *);
s32 objTvTimes(s32);
s16 mathDiffAngle(s16, s16, void *, void *);
void animseqInitPath(s32);
void animseqStartPath(s32);
s32 animseqGetFirstFreeIndex();
void *animseqWhichPathHasObject(void *);
s8 func_overlay_3_003061FC_1EDB6DC();
void func_overlay_3_00303CAC_1ED918C();
void ClearMissionFields();
void *GetLockObject(f32, f32, s32, s32, s32, s32);
s32 TryToSetMission(s32, s32, u8, u8, u8);
s32 FlopsyDogCheckPriority(s32);
s32 FallBackToSniperPoint(s32);
void SquadronControlSmart(void *);
s32 BaddyTypeToIndex(u16, void *);
void mathOneFloatRPY(void *, f32 *);
void *func_overlay_3_00301D3C_1ED721C(void *);
void func_overlay_3_00301EB8_1ED7398(void);
void func_overlay_3_003021C8_1ED76A8(void);
s32 EnsureValidNode();
s32 GetNextNodeNumber(u8, s32, s32);
f32 GetRange(f32, f32, f32, f32, f32, f32);
f32 GetRange2D(f32, f32, void *, f32, f32);
s32 ProcessNodeChange(s32);
s32 GetClosestPatrolNode(f32, f32, f32, s32);
s32 squadsPrepareToProcessSquaddie();
s32 mathSin(s16);
s32 mathCos(s16);
extern f32 D_overlay_3_00319A00;
extern f32 D_overlay_3_00319A04;
extern s32 D_overlay_3_00319434;
extern u8 *D_overlay_3_0031942C;
extern s32 FreeRAM;
f32 func_overlay_3_003044B4_1ED9994(void);
void func_overlay_3_003044F4_1ED99D4(void *);
s32 func_overlay_3_00304614_1ED9AF4(s32, s32);
s32 func_overlay_3_00304968_1ED9E48(s32, s32, s32);
void *func_overlay_3_0030527C_1EDA75C(f32, f32, f32);
void func_overlay_3_003053D4_1EDA8B4(void *);
f32 GetRangeSquared(f32, f32, f32, f32, f32, f32);
void *objSetupObject(void *, s32, void *);
void SquaddieLightAndAnimate(s32, void *, s32);
void objAnimSetMove(void *, s32, s32, s32);
s32 objAnimDframe(void *, f32, f32);
s32 GetBaddyData(void *);
void CopyStaticsToKernel(void *, void *);
void CopyStaticsToPatrolNodes(void *);
void **objGetPlayerlist(s32 *);
void BTSBBlackAnt();
extern s32 D_overlay_3_0031A124;
extern s32 D_overlay_3_0031944C;
extern f32 D_overlay_3_00319AA4;
extern f32 D_overlay_3_00319AA8;
extern f32 D_overlay_3_00319AAC;
s32 IsPointInRegion(f32, f32, void *);
s32 DoesLineCrossRegion(f32, f32, f32, f32, void *, void *, s32, s32);
void lightObject(s32, void *, s32, s32);
void modGenAnimMatrices(void *, void *, s32, f32, f32);
void objAnimTextures(s32, void *, void *, s8);
s32 trackLightAdd(f32, f32, s32, f32, f32, f32, s32, s32, s32);
void trackLightMove(void *, f32, f32, f32);
void **squadsGetSquadronList(s32 *);
void GetFormationInfo(s32, u8 *, u8 *, u8 *);
void SpiderMover(void *, void *);
void DragonflyMover(void *, void *);
void FlopsyDogMover(void *, void *);
void AntShipMover(void *, void *);
void GalaxianBatsMover(void *, void *);
void FloaterMover(void *, void *);
void SmartMover(void *, s32);
s32 amSndGetXYZVolume(u8, f32 *, f32 *, s16);
void *objGetClosestClass(s32, s32);
void *GetSquaddieFromIdentifiers(s16, u8);
s32 CheckLineOfSight(void *);
s32 DoesSquaddieWantToFire(f32, f32, s16, s32, s32);
s32 func_overlay_3_0030C1A0_1EE1680(void *, void *, s16 *, s16 *, f32 *, f32 *, f32 *, f32 *);
s32 squadsIsTribal(s32);
void mainIncreaseWeaponKills(s32);
void amSndStopXYZ(s32);
void trackMakePolylist();
s32 trackGetIntersect();
void objMoveXYZ(void *, f32, f32, f32);
void hitInitObjectHit();
void refractInit();
s32 hitsCheckLineOfSight(void *, void *, f32, f32, f32, f32, f32, f32);
void *objGetClosestControlType(f32, f32, s32, s32);
void *GetSquadronFromIdentifier(s16);
void FlopsyDogSpotPlayer();
void smartPlayerSeen();
extern u8 D_800F31E1[];
extern u8 *BaddyDataArray;
extern u8 D_overlay_3_00319430;
extern u8 D_overlay_3_0031A12B;
extern u8 D_overlay_3_0031A12C;
extern f32 D_overlay_3_00319D68;
extern f32 D_overlay_3_00319D6C;
extern f32 D_overlay_3_00319D70;
extern f32 D_overlay_3_00319D74;
extern f32 D_overlay_3_00319D78;
extern f32 D_overlay_3_00319D7C;
extern f32 D_overlay_3_00319D80;
extern f32 D_overlay_3_0031A1F0;
extern s16 D_overlay_3_0031A1F4;
extern s16 D_overlay_3_0031A1F6;
extern f32 D_overlay_3_0031A1EC;
extern f32 D_overlay_3_0031A130;
extern f32 D_overlay_3_0031A138;
extern f32 D_overlay_3_00319D3C;
extern f32 D_overlay_3_00319D40;
extern f32 D_overlay_3_00319D44;
extern f32 D_overlay_3_00319D48;
extern f32 D_overlay_3_00319D4C;
extern u8 D_overlay_3_00317A10[];
void doorUnlock(u8, s32, void *);
void *func_overlay_3_00307B38_1EDD018(void *);
void amSndUnlinkHandleXYZ(s32);
void explosionStart(s32, s16, s16, s16, s32, s32);
void objCreateBonusItem(f32, f32, s32, u8);
void bloodSpurtAdd(f32, f32, f32, f32, f32, f32, s32, s32, f32);
u8 *hitGetInelasticVelocity(s32, f32 *, f32 *, f32 *);
void mmFree(void *);
extern u8 D_overlay_3_003197F0[];    /* byte table indexed by arg0 (type 0x67 mask) */
extern s32 D_overlay_3_00319438[];   /* sound handle slots, 4-byte entries */
extern f32 D_overlay_3_00319D28;
extern f32 D_overlay_3_00319D2C;
extern f32 D_overlay_3_00319D30;
extern f32 D_overlay_3_00319D34;
extern f32 D_overlay_3_00319D38;
void objRegisterDependancy(void *, void *);

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void RecceNodeMover(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *state = D_overlay_3_0031A1D0;
    f32 *node = (f32 *)((u8 *)PatrolNodes + state[0x50] * 0x34);
    u8 *obj;
    u8 *data;

    if (state[0x1B] < 5) {
        *arg1 = node[0];
        *arg2 = node[1];
        *arg3 = node[2];
        return;
    }
    obj = *(u8 **)(state + 0x24);
    data = *(u8 **)(obj + 0x68);
    *arg1 = *(f32 *)(data + 0x48);
    *arg2 = *(f32 *)(data + 0x4C);
    *arg3 = *(f32 *)(data + 0x50);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/RecceNodeMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_003000D0_1ED55B0(void *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *target;
    f32 dist;
    s32 var_v1;
    u8 temp_v1;

    if (state[0x1B] == 4) {
        state[0x51] = (u8)(state[0x51] - 1);
        if (state[0x51] == 0) {
            state[0x1B] = 7;
        }
        target = *(u8 **)(D_overlay_3_0031A1D4 + 0x68);
        *arg1 = (s16)Arctanf(*(f32 *)(target + 0x48) - *(f32 *)(obj + 0xC),
                             *(f32 *)(target + 0x50) - *(f32 *)(obj + 0x14));
        var_v1 = -0x3E80;
        if (((s32)state[0x51] / 50) & 1) {
            var_v1 = 0x3E80;
        }
        *arg1 += var_v1;
        return 1;
    }
    dist = GetRangeSquared2D(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), arg2, arg3);
    temp_v1 = state[0x1B];
    if (temp_v1 == 3 && dist < 500.0f) {
        state[0x1B] = 4;
        state[0x51] = 0x96;
    } else if (temp_v1 == 7 && dist < 2000.0f) {
        ClearMissionFields(1, 0);
        (*(u8 **)(D_overlay_3_0031A1D4 + 0x68))[0x33] = 0;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003000D0_1ED55B0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00300258_1ED5738(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300258_1ED5738.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_overlay_3_0030027C_1ED575C(s16 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *state = D_overlay_3_0031A1D0;

    if (state[0x1B] == 1) {
        state[0x1B] = 4;
        state[0x4B] = 2;
        TryToSetAnim(2, state[0x50], state[0x51], state[0x52]);
    } else if (TryToUpdateAnim(2, 0x3F800000) != 0) {
        ClearMissionFields(1, 0);
        state[0x4B] = 0;
    }
    return *arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030027C_1ED575C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00300328_1ED5808(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    if (D_overlay_3_0031A1D0[0xA] != 5) {
        ClearMissionFields(1, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300328_1ED5808.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00300384_1ED5864(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *other;
    u8 *tbl;
    u8 *ent;
    u16 first;
    u16 count;
    s32 i;
    s16 ang;
    u8 temp_v0_3;
    f32 sp50 = 0.0f;
    f32 sp4C = 0.0f;
    f32 sp48;
    f32 sp44;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f14;
    f32 temp_f14_2;

    state[0x3] &= 0x7F;
    state[0x0] &= 0xFD;
    state[0x1] |= 0x04;
    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);

    if (state[0x1B] == 4) {
        state[0x50] = (u8)(state[0x50] - 1);
        if (state[0x50] == 0) {
            state[0x4B] = 0;
            *(s32 *)(obj + 0x84) = 0;
            obj[0x9F] = 0;
            ClearMissionFields(1, 0xA);
        }
        return;
    }

    other = *(u8 **)(obj + 0x4C);
    trackPolyHeight(*(f32 *)(other + 0xC), *(f32 *)(other + 0x14), &sp50, 0x2000);
    if (*(f32 *)(other + 0x10) < sp50 ||
        (state[0x4B] == 9 && TryToUpdateAnim(9, 0x3F800000) != 0)) {
        state[0x0] &= 0xBF;
        *(s32 *)(obj + 0x84) = 0;
        if (*(s32 *)(state + 0xC0) != 0) {
            trackLightDelete(*(s32 *)(state + 0xC0));
            *(s32 *)(state + 0xC0) = 0;
        }
        if (*(s32 *)(state + 0xC4) != 0) {
            killLight(*(s32 *)(state + 0xC4));
            *(s32 *)(state + 0xC4) = 0;
        }
        if (state[0x4B] == 9) {
            state[0x1B] = 4;
            state[0x50] = 0x19;
            *(s32 *)(obj + 0x84) = 2;
        } else {
            state[0x4B] = 0;
            ClearMissionFields(1, 0xA);
        }
        return;
    }

    if (state[0xA] != 0x33) {
        temp_f0 = *(f32 *)(other + 0x28);
        if ((*(f32 *)(other + 0x10) - temp_f0 * D_overlay_3_003199E8) < sp50 &&
            *(f32 *)(state + 0x3C) < temp_f0) {
            tbl = D_overlay_3_00319278 + D_overlay_3_0031A1DC * 4;
            first = *(u16 *)tbl;
            count = *(u16 *)(tbl + 2);
            ent = D_overlay_3_00317DB8 + first * 8;
            for (i = 0; i < (s32)count; i++, ent += 8) {
                if (*(u32 *)(ent + 4) & 0x04000000) {
                    if (TryToSetAnimByIndex(9, i, tbl, first) != 0) {
                        state[0xA] = 0x33;
                    }
                    break;
                }
            }
        }
    }

    if (*(u32 *)(state + 0x4) & 0x1000) {
        sp48 = (f32)mathRnd(-0x50, 0x50) + *(f32 *)(state + 0x38);
        temp_f14 = (f32)mathRnd(-0x50, 0x50) + *(f32 *)(state + 0x40);
        sp44 = temp_f14;
        trackPolyHeight(sp48, temp_f14, &sp50, 0x2000);
        trackGetNearestPoly(sp48, *(f32 *)(other + 0x10), sp44, &sp4C, 0, 0x2000);
        if (*(f32 *)(state + 0x3C) < (sp50 - sp4C)) {
            *(f32 *)(state + 0x38) = sp48;
            *(f32 *)(state + 0x3C) = sp50 - sp4C;
            *(f32 *)(state + 0x40) = sp44;
        }
        *arg1 = *(f32 *)(state + 0x38);
        *arg2 = sp4C;
        *arg3 = *(f32 *)(state + 0x40);
    } else {
        sp48 = (f32)mathRnd(-0x190, 0x190) + *(f32 *)(obj + 0xC);
        temp_f14_2 = (f32)mathRnd(-0x190, 0x190) + *(f32 *)(obj + 0x14);
        sp44 = temp_f14_2;
        trackPolyHeight(sp48, temp_f14_2, &sp50, 0x2000);
        trackGetNearestPoly(sp48, *(f32 *)(other + 0x10), sp44, &sp4C, 0, 0x2000);
        if (sp4C < sp50) {
            *(f32 *)(state + 0x38) = sp48;
            *(f32 *)(state + 0x3C) = sp50 - sp4C;
            *(f32 *)(state + 0x40) = sp44;
            state[0x6] |= 0x10;
        } else {
            temp_v0_3 = state[0x50];
            if (temp_v0_3 != 0) {
                state[0x50] = (u8)(temp_v0_3 - 1);
            } else {
                state[0x50] = (u8)mathRnd(0xA, 0x32);
                state[0x52] = (u8)mathRnd(0x64, 0xC8);
                state[0x53] = (u8)mathRnd(-0x80, 0x7F);
            }
            ang = (s16)((*(s16 *)obj + ((s8)state[0x53] << 5)) - 0x8000);
            temp_f0_2 = Sinf(ang);
            *(f32 *)(state + 0x38) = (temp_f0_2 * (f32)state[0x52]) + *(f32 *)(obj + 0xC);
            *(f32 *)(state + 0x3C) = sp4C;
            temp_f0_3 = Cosf(ang);
            *(f32 *)(state + 0x40) = (temp_f0_3 * (f32)state[0x52]) + *(f32 *)(obj + 0x14);
        }
        *arg1 = *(f32 *)(state + 0x38);
        *arg2 = *(f32 *)(state + 0x3C);
        *arg3 = *(f32 *)(state + 0x40);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300384_1ED5864.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003009C8_1ED5EA8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * D_overlay_3_003199EC;
    *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * D_overlay_3_003199EC;
    D_overlay_3_0031A1D0[0x50] = (u8)(D_overlay_3_0031A1D0[0x50] - 1);
    if (D_overlay_3_0031A1D0[0x50] == 0) {
        SquaddiePassesAway();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003009C8_1ED5EA8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00300A5C_1ED5F3C(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    *arg1 = *(f32 *)(D_overlay_3_0031A1D0 + 0x38);
    *arg2 = *(f32 *)(D_overlay_3_0031A1D0 + 0x3C);
    *arg3 = *(f32 *)(D_overlay_3_0031A1D0 + 0x40);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300A5C_1ED5F3C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00300AA0_1ED5F80(void *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;

    *arg1 = (s16)Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(D_overlay_3_0031A1D0 + 0x38),
                         *(f32 *)(obj + 0x14) - *(f32 *)(D_overlay_3_0031A1D0 + 0x40));
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300AA0_1ED5F80.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00300AF4_1ED5FD4(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    s32 temp_t8;
    u8 temp_a0;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    *(s32 *)(obj + 0x84) = 8;
    TryToSetAnim(3, 0x24, 0, 0);
    if (!(*(u32 *)state & 0x100000)) {
        amSndPlayXYZ(0xDB, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        instShowBearBar();
        state[0x1] |= 0x10;
    }
    TryToUpdateAnim(3, 0x3F800000);
    temp_a0 = state[0x55];
    temp_t8 = iDeltaTime * 4;
    if ((0xFF - temp_t8) < (s32)temp_a0) {
        mainSetTribalStatus(D_overlay_3_0031A1D8[0x64], 1);
        squadsKillSquaddie(arg0);
        return;
    }
    state[0x55] = (u8)(temp_a0 + temp_t8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300AF4_1ED5FD4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00300C20_1ED6100(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    squadsGetFormationPosition((s32)D_overlay_3_0031A1D4, D_overlay_3_0031A1D0[0x15], arg1, arg2, arg3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300C20_1ED6100.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00300C70_1ED6150(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    switch (state[0x1B]) {
    case 1:
        TryToSetAnim(3, 0x20, 0, 0);
        state[0x1B] = 4;
        state[0x0] &= 0xDF;
        return;
    case 4:
        if (state[0x4B] == 0) {
            TryToSetAnim(3, 0x20, 0, 0);
            return;
        }
        TryToUpdateAnim(3, 0x3F800000, 0);
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300C70_1ED6150.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00300D44_1ED6224(void *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *entry;
    u8 *cfg;
    u8 temp_a0;

    entry = D_overlay_3_0031A1F8 + (s8)state[0x54] * 0x10;
    if (D_overlay_3_0031A1D8[0x32] != 0xA) {
        UpdateOrSetAnim(3, 0x3F800000, 0x3B, &D_overlay_3_0031A1D0);
    }
    temp_a0 = state[0x4B];
    if (temp_a0 != 3) {
        TryToUpdateAnim(temp_a0, 0x3F800000);
    }
    if (state[0x1B] == 1) {
        state[0x53] = (u8)objTvTimes(mathRnd(0x32, 0x41));
        state[0x1B] = 4;
    } else {
        state[0x53] = (u8)((s8)state[0x53] - iDeltaTime);
    }
    cfg = D_overlay_3_0031A1D8;
    if ((s8)state[0x54] == -1 || entry[8] == 0 || (s8)state[0x53] < 0 ||
        (cfg[0x32] == 0x11 && (cfg[0x30] == 3 || cfg[0x30] == 4))) {
        ClearMissionFields(1, 0);
        *(s16 *)(state + 0x10) = 0;
        state[0x4B] = 0;
        return 0;
    }
    cfg = D_overlay_3_0031A1E0;
    if (cfg[0x34] == 0 && cfg[0x35] == 0 && cfg[0x36] == 0) {
        *arg1 = (s16)Arctanf(*(f32 *)(obj + 0xC) - (f32)*(s16 *)entry,
                             *(f32 *)(obj + 0x14) - (f32)*(s16 *)(entry + 4));
        return 1;
    }
    *arg1 = *(s16 *)obj;
    *(s16 *)(state + 0x10) = (s16)(Arctanf(*(f32 *)(obj + 0xC) - (f32)*(s16 *)entry,
                                           *(f32 *)(obj + 0x14) - (f32)*(s16 *)(entry + 4))
                                   - *(s16 *)obj);
    state[0x6] |= 0x40;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300D44_1ED6224.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00300FD0_1ED64B0(void *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *entry;
    u8 *cfg;
    u8 temp_v1;

    entry = D_overlay_3_0031A1F8 + (s8)state[0x54] * 0x10;
    TryToUpdateAnim(state[0x4B], 0x3F800000);
    if ((s8)state[0x54] == -1) {
        ClearMissionFields(1, 0);
        state[0x4B] = 0;
        *(s16 *)(state + 0x10) = 0;
        return 0;
    }
    switch (state[0x1B]) {
    case 1:
        state[0x53] = (u8)objTvTimes(mathRnd(0x1E, 0x28));
        state[0x1B] = 4;
        break;
    case 4:
        state[0x53] = (u8)((s8)state[0x53] - iDeltaTime);
        if ((s8)state[0x53] < 0) {
            ClearMissionFields(1, 0);
            state[0x4B] = 0;
            cfg = D_overlay_3_0031A1D8;
            temp_v1 = cfg[0x30];
            if (temp_v1 == 2 || temp_v1 == 3) {
                cfg[0x30] = 4;
            }
        }
        break;
    }
    *arg1 = *(s16 *)obj;
    *(s16 *)(state + 0x10) = (s16)(Arctanf(*(f32 *)(obj + 0xC) - (f32)*(s16 *)entry,
                                           *(f32 *)(obj + 0x14) - (f32)*(s16 *)(entry + 4))
                                   - *(s16 *)obj);
    state[0x6] |= 0x40;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00300FD0_1ED64B0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00301188_1ED6668(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *cfg;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    switch (state[0x1B]) {
    case 1:
        cfg = D_overlay_3_0031A1D8;
        if (cfg[0x30] == 2 && !(*(u16 *)(*(u8 **)(obj + 0x40) + 0x14) & 0x80)) {
            cfg[0x30] = 3;
        }
        if ((s32)cfg[0x0] < 2) {
            state[0x0] &= 0xDF;
            state[0x4B] = 0;
            ClearMissionFields(1, 0, 0);
            return;
        }
        state[0x1B] = 4;
        TryToSetAnim(3, 2, 0, 0);
        return;
    case 4:
        if (state[0x4B] != 3 || TryToUpdateAnim(3, 0x3F800000) != 0) {
            state[0x0] &= 0xDF;
            state[0x4B] = 0;
            ClearMissionFields(1, 0);
            TryToSetAnim(0, 5, 6, 1);
        }
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301188_1ED6668.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_003012E8_1ED67C8(void *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *target = D_overlay_3_0031A1E8;

    *arg1 = *(s16 *)obj;
    *(s16 *)(state + 0x10) = (s16)(Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(target + 0xC),
                                           *(f32 *)(obj + 0x14) - *(f32 *)(target + 0x14))
                                   - *(s16 *)obj);
    state[0x6] |= 0x40;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003012E8_1ED67C8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030136C_1ED684C(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *owner;
    f32 sp24;
    f32 temp_f6;
    f32 temp_f8;

    *(s16 *)obj = (s16)(0xC000 - (state[0x50] << 8));
    sp24 = Cosf(state[0x51] << 8);
    temp_f6 = Cosf(state[0x50] << 8) * sp24;
    *(f32 *)(obj + 0x1C) = temp_f6 * (f32)state[0x52];
    sp24 = Cosf(state[0x51] << 8);
    temp_f8 = Sinf(state[0x50] << 8) * sp24;
    *(f32 *)(obj + 0x24) = temp_f8 * (f32)state[0x52];
    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    switch (state[0x1B]) {
    case 1:
        *(f32 *)(obj + 0x20) = Sinf(state[0x51] << 8) * (f32)state[0x52];
        state[0x2] &= 0xF7;
        state[0x1B] = 4;
        *(f32 *)(state + 0x30) += 1.0f;
        *(f32 *)(obj + 0x10) += 1.0f;
        owner = *(u8 **)(obj + 0x4C);
        *(f32 *)(owner + 0x1C) += 1.0f;
        *(f32 *)(owner + 0x10) += 1.0f;
        TryToSetAnim(3, 0x14, 0, 0);
        break;
    case 4:
        D_overlay_3_0031A1D8[0x35] = 0;
        if (*(f32 *)(obj + 0x28) < 0.5f) {
            TryToUpdateAnim(3, 0x3F800000);
        }
        break;
    }
    func_overlay_3_00303CAC_1ED918C(obj);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030136C_1ED684C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00301608_1ED6AE8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 temp_a0;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    switch (state[0x1B]) {
    case 1:
        state[0x9] = 0;
        temp_a0 = state[0x50];
        if (iDeltaTime >= (s32)temp_a0) {
            state[0x1B] = 4;
            state[0x50] = 0x2D;
        } else {
            state[0x50] = (u8)(temp_a0 - iDeltaTime);
        }
        UpdateOrSetAnim(3, 0x3F800000, 0x3B);
        return;
    case 4:
        temp_a0 = state[0x50];
        if (iDeltaTime >= (s32)temp_a0) {
            state[0x1B] = 5;
            state[0x50] = 0x1E;
        } else {
            state[0x50] = (u8)(temp_a0 - iDeltaTime);
        }
        TryToUpdateAnim(3, 0x3F800000);
        return;
    case 5:
        state[0x9] = 3;
        temp_a0 = state[0x50];
        if (iDeltaTime >= (s32)temp_a0) {
            state[0x1A] = 0x10;
            state[0x1B] = 1;
            state[0x9] = 1;
        } else {
            state[0x50] = (u8)(temp_a0 - iDeltaTime);
        }
        TryToUpdateAnim(3, 0x3F800000);
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301608_1ED6AE8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00301764_1ED6C44(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *owner;
    f32 var_f0;
    s16 temp_v1;
    s32 temp_a0;
    u8 temp_v1_2;

    *arg1 = *(f32 *)(obj + 0xC);
    *arg2 = *(f32 *)(obj + 0x10);
    *arg3 = *(f32 *)(obj + 0x14);
    var_f0 = (f32)*(s16 *)(cfg + 0x2A) * D_overlay_3_003199F4;
    if (var_f0 < D_overlay_3_003199F0) {
        var_f0 = D_overlay_3_003199F0;
    }
    owner = *(u8 **)(obj + 0x4C);
    temp_v1 = *(s16 *)(owner + 0x6);
    *(s16 *)(owner + 0x6) = (s16)(s32)((f32)temp_v1 - (var_f0 * D_overlay_3_0031A1C8));
    if (*(s16 *)(owner + 0x6) <= 0 && temp_v1 > 0) {
        *(u16 *)(owner + 0x8) = (u16)((*(u16 *)(owner + 0x8) & 0xFFF0) | 4);
        SquaddiePassesAway(arg0);
    }
    temp_v1_2 = state[0x50];
    if ((s32)temp_v1_2 < iDeltaTime) {
        ClearMissionFields(1, 0);
        if (*(s16 *)(cfg + 0x2C) == 0x112) {
            state[0x4B] = 3;
            NewFlopsyFunction(arg0, 1);
        } else {
            state[0x4B] = 0;
        }
        state[0x8] &= 0xFB;
        temp_a0 = *(s32 *)(state + 0xC8);
        if (temp_a0 != 0) {
            objFreeObject((void *)temp_a0);
            *(s32 *)(state + 0xC8) = 0;
            temp_a0 = *(s32 *)(state + 0xC4);
            if (temp_a0 != 0) {
                killLight(temp_a0);
                *(s32 *)(state + 0xC4) = 0;
            }
            temp_a0 = *(s32 *)(state + 0xC0);
            if (temp_a0 != 0) {
                trackLightDelete(temp_a0);
                *(s32 *)(state + 0xC0) = 0;
            }
        }
    } else {
        state[0x50] = (u8)(temp_v1_2 - iDeltaTime);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301764_1ED6C44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00301974_1ED6E54(void *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *state = D_overlay_3_0031A1D0;
    u8 *target = D_overlay_3_0031A1E4;
    u16 temp_v0;

    if (target == NULL) {
        ClearMissionFields(1, 0, obj);
        return 0;
    }
    temp_v0 = Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(target + 0xC),
                      *(f32 *)(obj + 0x14) - *(f32 *)(target + 0x14));
    *arg1 = *(s16 *)obj;
    if (state[0x1B] != 4) {
        *(s16 *)(state + 0x10) = mathDiffAngle(*(s16 *)obj, (s16)temp_v0, obj, &D_overlay_3_0031A1D0);
    } else {
        *(s16 *)(state + 0x10) = 0;
    }
    state[0x6] |= 0x40;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301974_1ED6E54.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00301A50_1ED6F30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301A50_1ED6F30.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00301A68_1ED6F48(void *arg0, u16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *target = D_overlay_3_0031A1E4;

    if (target != NULL) {
        *arg1 = Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(target + 0xC),
                        *(f32 *)(obj + 0x14) - *(f32 *)(target + 0x14));
    } else {
        *arg1 = *(u16 *)obj;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301A68_1ED6F48.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00301ACC_1ED6FAC(s32 arg0, s16 *arg1, s32 arg2, s32 arg3) {
    *arg1 = *(s16 *)(D_overlay_3_0031A1D0 + 0x1C);
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301ACC_1ED6FAC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00301AF0_1ED6FD0(void *arg0, u16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *target = D_overlay_3_0031A1E8;

    *arg1 = Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(target + 0xC),
                    *(f32 *)(obj + 0x14) - *(f32 *)(target + 0x14));
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301AF0_1ED6FD0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00301B44_1ED7024(void *arg0, u16 *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *target = D_overlay_3_0031A1E4;
    u8 *cfg = D_overlay_3_0031A1D8;
    s16 temp_v0;
    s16 var_v1;

    if (target == NULL) {
        ClearMissionFields(1, mathRnd(cfg[0x60], cfg[0x61]));
        return 0;
    }
    *arg1 = Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(target + 0xC),
                    *(f32 *)(obj + 0x14) - *(f32 *)(target + 0x14));
    temp_v0 = mathDiffAngle((s16)*arg1, *(s16 *)obj, obj, arg1);
    var_v1 = temp_v0;
    if (temp_v0 < 0) {
        var_v1 = (s16)(temp_v0 * -1);
    }
    if (var_v1 < 0xB) {
        squadsFireWeapon(0, 0, 0);
        ClearMissionFields(1, mathRnd(cfg[0x60], cfg[0x61]));
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301B44_1ED7024.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00301C58_1ED7138(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 temp_v1 = obj[0x18];
    u8 temp_v1_2;

    if ((1 << temp_v1) & 0x208) {
        if (arg1 != 0) {
            return 0;
        }
    } else if (arg1 == 0) {
        return 0;
    }
    if (temp_v1 != 1 && cfg[0x35] == 0) {
        cfg[0x33] = 0x17;
        cfg[0x35] = 1;
        *(s16 *)(cfg + 0x2E) = (s16)*(f32 *)(obj + 0x1C);
        PerformNodeCommand((s32)D_overlay_3_0031A1D4, obj, obj);
        temp_v1_2 = obj[0x18];
        return (temp_v1_2 != 3) && (temp_v1_2 != 9);
    }
    cfg[0x35] = 0;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301C58_1ED7138.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_3_00301D3C_1ED721C(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 kind = obj[0x1E];
    void **list;
    void *result;
    s32 start;
    s32 end;
    s32 i;
    s32 k;
    s32 sum = 0;
    s32 roll;
    s32 idx = 0;
    u8 *group = NULL;
    u8 *node;
    void *cur;

    result = *(void **)(obj + 0x28);
    list = objGetObjList(&start, &end);
    if (kind == 0) {
        return result;
    }
    for (i = start; i < end; i++) {
        u8 *o = (u8 *)list[i];

        if (*(s32 *)(o + 0xA0) == 0 && *(s16 *)(o + 0x48) == 0x1B) {
            group = *(u8 **)(o + 0x68);
            if (kind == group[0x11]) {
                break;
            }
        }
    }
    for (k = 0; k < 3; k++) {
        sum += group[0xB - k];
    }
    if (sum > 0) {
        roll = mathRnd(1, sum);
        for (idx = 0;; idx++) {
            roll -= group[idx + 8];
            if (roll <= 0) {
                break;
            }
        }
    }
    node = (u8 *)animpath[group[idx * 2]];
    cur = *(void **)(node + 0x20);
    for (k = 1; k < group[idx + 0xC]; k++) {
        cur = *(void **)((u8 *)cur + 0x28);
    }
    return cur;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301D3C_1ED721C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00301EB8_1ED7398(void) {
    u8 *cfg = D_overlay_3_0031A1D8;
    s32 freeIdx;
    s32 slot;
    u8 *path;
    u8 *src;
    u8 *seq;
    u8 *dst;
    u8 *cur;
    s32 n;

    freeIdx = animseqGetFirstFreeIndex();
    cfg[0x78] = (u8)func_overlay_3_003061FC_1EDB6DC();
    if ((s8)cfg[0x78] == -1 || freeIdx == -1) {
        return;
    }
    slot = (s8)cfg[0x78];
    animpath[freeIdx] = mmAlloc(0x34, 0xFFFF00FF);
    AnimPathNumbers[slot] = freeIdx;
    src = (u8 *)animseqWhichPathHasObject(*(void **)(cfg + 0x54));
    if (src == NULL) {
        return;
    }
    path = (u8 *)animpath[freeIdx];
    path[0x0] = src[0x0];
    path[0x1] = src[0x1];
    path[0x2] = 0x53;
    *(s16 *)(path + 0x4) = *(s16 *)(src + 0x4);
    path[0x6] = src[0x6];
    path[0x7] = src[0x7];
    *(void **)(path + 0x8) = NULL;
    *(f32 *)(path + 0xC) = *(f32 *)(src + 0xC);
    *(f32 *)(path + 0x10) = *(f32 *)(src + 0x10);
    path[0x14] = src[0x14];
    path[0x15] = src[0x15];
    *(u16 *)(path + 0x16) = 0x80;
    path[0x17] = 4;
    seq = (u8 *)D_overlay_3_0031A390 + slot * 0xB0;
    *(u8 **)(path + 0x18) = seq;
    *(u8 **)(path + 0x20) = seq;
    *(f32 *)(path + 0x1C) = 0.0f;
    animseqInitPath(freeIdx & 0xFF);

    dst = seq;
    cur = *(u8 **)(src + 0x18);
    for (n = 3; n != 0; n--) {
        u8 *next = dst + 0x2C;

        *(s16 *)(dst + 0x0) = *(s16 *)(cur + 0x0);
        *(s16 *)(dst + 0x2) = *(s16 *)(cur + 0x2);
        dst[0x6] = (u8)freeIdx;
        *(s16 *)(dst + 0x4) = *(s16 *)(cur + 0x4);
        dst[0x7] = cur[0x7];
        *(f32 *)(dst + 0x8) = *(f32 *)(cur + 0x8);
        *(f32 *)(dst + 0xC) = *(f32 *)(cur + 0xC);
        *(f32 *)(dst + 0x10) = *(f32 *)(cur + 0x10);
        *(f32 *)(dst + 0x14) = *(f32 *)(cur + 0x14);
        *(s16 *)(dst + 0x18) = *(s16 *)(cur + 0x18);
        *(s16 *)(dst + 0x1A) = *(s16 *)(cur + 0x1A);
        *(s16 *)(dst + 0x1C) = *(s16 *)(cur + 0x1C);
        dst[0x1E] = cur[0x1E];
        *(f32 *)(dst + 0x20) = *(f32 *)(cur + 0x20);
        if (n == 3) {
            *(u8 **)(dst + 0x24) = seq + 0x84;
        } else {
            *(u8 **)(dst + 0x24) = dst - 0x2C;
        }
        *(u8 **)(dst + 0x28) = next;
        cur = (u8 *)func_overlay_3_00301D3C_1ED721C(cur);
        dst = next;
    }
    {
        u8 *fresh = *(u8 **)(path + 0x8);

        *(s16 *)(fresh + 0x6) = (s16)(*(s16 *)(fresh + 0x6) | 0x400);
    }
    D_overlay_3_0031AE90[slot] = cur;
    animseqStartPath(freeIdx & 0xFF);
    *(void **)(cfg + 0x54) = *(void **)(path + 0x8);
    cfg[0x79] = 1;
    *(void **)(path + 0x18) = *(void **)(*(u8 **)(path + 0x20) + 0x28);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00301EB8_1ED7398.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003021C8_1ED76A8(void) {
    u8 *cfg = D_overlay_3_0031A1D8;
    s32 slot = (s8)cfg[0x78];
    u8 *path = (u8 *)animpath[AnimPathNumbers[slot]];
    u8 *end = *(u8 **)(path + 0x18);
    u8 *cur = *(u8 **)(path + 0x20);
    s32 count = 0;

    if (cur != end) {
        do {
            cur = *(u8 **)(cur + 0x28);
            count++;
        } while (cur != end);
    }
    if (count != cfg[0x79]) {
        u8 *src = (u8 *)D_overlay_3_0031AE90[slot];
        u8 *dst = *(u8 **)(*(u8 **)(end + 0x24) + 0x24);

        D_overlay_3_0031AE90[slot] = func_overlay_3_00301D3C_1ED721C(src);
        *(s16 *)(dst + 0x0) = *(s16 *)(src + 0x0);
        *(s16 *)(dst + 0x2) = *(s16 *)(src + 0x2);
        *(s16 *)(dst + 0x4) = *(s16 *)(src + 0x4);
        dst[0x7] = src[0x7];
        *(f32 *)(dst + 0x8) = *(f32 *)(src + 0x8);
        *(f32 *)(dst + 0xC) = *(f32 *)(src + 0xC);
        *(f32 *)(dst + 0x10) = *(f32 *)(src + 0x10);
        *(f32 *)(dst + 0x14) = *(f32 *)(src + 0x14);
        *(s16 *)(dst + 0x18) = *(s16 *)(src + 0x18);
        *(s16 *)(dst + 0x1A) = *(s16 *)(src + 0x1A);
        *(s16 *)(dst + 0x1C) = *(s16 *)(src + 0x1C);
        dst[0x1E] = src[0x1E];
        *(f32 *)(dst + 0x20) = *(f32 *)(src + 0x20);
        cfg[0x79] = (u8)(cfg[0x79] + 1);
        if ((s8)cfg[0x79] >= 4) {
            cfg[0x79] = 0;
        }
    }
    {
        u8 *fresh = *(u8 **)(path + 0x8);

        *(s16 *)(fresh + 0x6) = (s16)(*(s16 *)(fresh + 0x6) | 0x400);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003021C8_1ED76A8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030237C_1ED785C(void) {
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *src = *(u8 **)(cfg + 0x54);
    u8 *entry;
    u8 *cur;
    void **pool;
    s32 span;
    s32 pidx;
    u8 n;

    if (src == NULL) {
        return;
    }
    if (cfg[0x31] != 1) {
        *(s16 *)(cfg + 0x40) = (s16)*(f32 *)(src + 0xC);
        *(s16 *)(cfg + 0x42) = (s16)*(f32 *)(src + 0x10);
        *(s16 *)(cfg + 0x44) = (s16)*(f32 *)(src + 0x14);
        return;
    }
    span = cfg[0x1E] * 2 * cfg[0x1];
    if ((s8)cfg[0x78] == -1) {
        func_overlay_3_00301EB8_1ED7398();
    } else {
        func_overlay_3_003021C8_1ED76A8();
    }
    if (cfg[0x77] == 0xFF) {
        n = 0xF;
        pool = (void **)&D_800FF734;
        while (*pool != NULL) {
            pool -= 4;
            n--;
            if (n == 0) {
                break;
            }
        }
        cfg[0x77] = n;
        cfg[0x36] = 0;
        *pool = mmAlloc(span * 0x14, 0xFFFF00FF);
    }
    entry = (u8 *)PathLists[cfg[0x77]] + cfg[0x36] * 0x14;
    *(f32 *)(entry + 0x0) = *(f32 *)(src + 0xC);
    *(f32 *)(entry + 0x4) = *(f32 *)(src + 0x10);
    *(f32 *)(entry + 0x8) = *(f32 *)(src + 0x14);
    *(s16 *)(entry + 0xC) = *(s16 *)(src + 0x0);
    *(s16 *)(entry + 0xE) = *(s16 *)(src + 0x2);
    *(s16 *)(entry + 0x10) = *(s16 *)(src + 0x4);

    cur = *(u8 **)(cfg + 0x58);
    D_overlay_3_0031A1CC = cur;
    if (cur != NULL) {
        do {
            u8 *obj = *(u8 **)(cur + 0x68);

            D_overlay_3_0031A1D0 = obj;
            if (*(s16 *)(obj + 0xA6) > 0) {
                pidx = cfg[0x36] - (obj[0x15] * (cfg[0x1E] * 2));
                if (pidx < 0) {
                    pidx += span;
                }
                *(f32 *)(cur + 0x1C) = 0.0f;
                *(f32 *)(cur + 0x20) = 0.0f;
                *(f32 *)(cur + 0x24) = 0.0f;
                entry = (u8 *)PathLists[cfg[0x77]] + pidx * 0x14;
                func_overlay_3_00303CAC_1ED918C(cur, cur);
                *(f32 *)(cur + 0xC) = *(f32 *)(entry + 0x0);
                *(f32 *)(cur + 0x10) = *(f32 *)(entry + 0x4);
                *(f32 *)(cur + 0x14) = *(f32 *)(entry + 0x8);
                *(s16 *)(cur + 0x0) = *(s16 *)(entry + 0xC);
                *(s16 *)(cur + 0x2) = *(s16 *)(entry + 0xE);
                *(s16 *)(cur + 0x4) = *(s16 *)(entry + 0x10);
            }
            cur = *(u8 **)(obj + 0x28);
            D_overlay_3_0031A1CC = cur;
        } while (cur != NULL);
    }
    cfg[0x36] = (u8)(cfg[0x36] + 1);
    if ((s32)cfg[0x36] >= span) {
        cfg[0x36] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030237C_1ED785C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_overlay_3_00302760_1ED7C40(void *arg0) {
    u8 *node = (u8 *)arg0;

    if (1.0f == *(f32 *)(D_overlay_3_0031A1D8 + 0x6C)) {
        return node[0x31] + 0x28;
    }
    return node[0x31];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00302760_1ED7C40.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003027A4_1ED7C84(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *obj;
    u8 *node;
    f32 range;
    s16 packed;

    if (EnsureValidNode() != 0) {
        obj = *(u8 **)(st + 0x58);
        node = (u8 *)PatrolNodes + (*(s16 *)(st + 0x3C) & 0xFF) * 0x34;
        if (!(*(u32 *)D_overlay_3_0031A1D0 & 0x800)) {
            if (*(f32 *)(st + 0x6C) == 1.0f) {
                range = GetRange(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14),
                                 *(f32 *)(node + 0x0), *(f32 *)(node + 0x4), *(f32 *)(node + 0x8));
                if (range < (f32)func_overlay_3_00302760_1ED7C40(node)) {
                    if (func_overlay_3_00301C58_1ED7138(node, 1) == 0) {
                        packed = *(s16 *)(st + 0x3C);
                        if (ProcessNodeChange(GetNextNodeNumber(st[0x30], packed & 0xFF,
                                                                (packed >> 8) & 0xFF) & 0xFF) != 0) {
                            func_overlay_3_00301C58_1ED7138(node, 0);
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003027A4_1ED7C84.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003028D4_1ED7DB4(void) {
    u8 *st = D_overlay_3_0031A1D8;
    s32 offX;
    s32 offZ;
    s32 rnd;
    s32 spread;

    *(s16 *)(st + 0x2E) = (s16)(*(s16 *)(st + 0x2E) - 1);
    if (*(s16 *)(st + 0x2E) == 0) {
        *(s16 *)(st + 0x3C) = (s16)(*(s16 *)(st + 0x3C) + 0x8C40);
        offX = (s32)(Sinf((s32)*(s16 *)(st + 0x3C)) * (f32)(st[0x13] * 0x10));
        offZ = (s32)(Cosf((s32)*(s16 *)(st + 0x3C)) * (f32)(st[0x13] * 0x10));
        spread = st[0x14] * 8;
        rnd = mathRnd(-spread, spread);
        *(s16 *)(st + 0x40) = (s16)((st[0x10] * 0x10) + offX);
        *(s16 *)(st + 0x42) = (s16)((st[0x11] * 0x10) + rnd);
        *(s16 *)(st + 0x44) = (s16)((st[0x12] * 0x10) + offZ);
        *(f32 *)(D_overlay_3_0031A1D4 + 0x1C) = 0.0f;
        *(f32 *)(D_overlay_3_0031A1D4 + 0x20) = 0.0f;
        *(f32 *)(D_overlay_3_0031A1D4 + 0x24) = 0.0f;
        st[0x33] = 0x14;
        squadsBehaviour = 0x14;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003028D4_1ED7DB4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00302A94_1ED7F74(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *tgt = D_overlay_3_0031A1E8;

    *(s16 *)(st + 0x40) = (s16)(s32)(*(f32 *)(tgt + 0xC) - (f32)(mathSin(*(s16 *)tgt) >> 7));
    *(s16 *)(st + 0x42) = (s16)(s32)(*(f32 *)(tgt + 0x10) + (f32)*(s16 *)(D_overlay_3_0031A1E0 + 0x24));
    *(s16 *)(st + 0x44) = (s16)(s32)(*(f32 *)(tgt + 0x14) - (f32)(mathCos(*(s16 *)tgt) >> 7));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00302A94_1ED7F74.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00302BBC_1ED809C(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *obj = D_overlay_3_0031A1D4;

    *(s16 *)(st + 0x40) = (s16)(s32)(*(f32 *)(obj + 0xC) + (f32)(st[0x10] * 0x10));
    *(s16 *)(st + 0x42) = (s16)(s32)(*(f32 *)(obj + 0x10) + (f32)(st[0x11] * 0x10));
    *(s16 *)(st + 0x44) = (s16)(s32)(*(f32 *)(obj + 0x14) + (f32)(st[0x12] * 0x10));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00302BBC_1ED809C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00302CA8_1ED8188(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *tgt = D_overlay_3_0031A1E8;

    *(s16 *)(st + 0x40) = (s16)(s32)*(f32 *)(tgt + 0xC);
    *(s16 *)(st + 0x42) = (s16)(s32)(*(f32 *)(tgt + 0x10) + (f32)*(s16 *)(D_overlay_3_0031A1E0 + 0x24));
    *(s16 *)(st + 0x44) = (s16)(s32)*(f32 *)(tgt + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00302CA8_1ED8188.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00302D58_1ED8238(void) {
    u8 *st = D_overlay_3_0031A1D8;
    s16 timer = *(s16 *)(st + 0x2E);

    if (timer != 0) {
        *(s16 *)(st + 0x2E) = (s16)(timer - 1);
        if (*(s16 *)(st + 0x2E) == 0) {
            st[0x33] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00302D58_1ED8238.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00302DA0_1ED8280(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *obj = D_overlay_3_0031A1D4;
    u16 wantAngle;
    u16 angle;
    s16 diff;
    s16 step;
    f32 dist;
    f32 invSteps;

    angle = Arctanf((f32)*(s16 *)(st + 0x40) - *(f32 *)(st + 0x48),
                    (f32)*(s16 *)(st + 0x44) - *(f32 *)(st + 0x50));
    wantAngle = angle;
    diff = mathDiffAngle(*(s16 *)obj, (s16)angle, 0, 0);
    step = diff;
    if (diff >= 0x191) {
        step = 0x190;
    } else if (diff < -0x190) {
        step = -0x190;
    }
    *(s16 *)obj = (s16)(*(s16 *)obj + step);
    if ((s16)wantAngle == *(s16 *)obj) {
        dist = GetRange((f32)*(s16 *)(st + 0x40), (f32)*(s16 *)(st + 0x42), (f32)*(s16 *)(st + 0x44),
                        *(f32 *)(st + 0x48), *(f32 *)(st + 0x4C), *(f32 *)(st + 0x50))
               / (f32)(*(s8 *)(st + 0x24) >> 1);
        *(s16 *)(st + 0x2E) = (s16)(s32)dist;
        invSteps = 1.0f / dist;
        if (*(f32 *)(st + 0x48) != (f32)*(s16 *)(st + 0x40)) {
            *(f32 *)(obj + 0x1C) = ((f32)*(s16 *)(st + 0x40) - *(f32 *)(st + 0x48)) * invSteps;
        } else {
            *(f32 *)(obj + 0x1C) = 0.0f;
        }
        if (*(f32 *)(st + 0x4C) != (f32)*(s16 *)(st + 0x42)) {
            *(f32 *)(obj + 0x20) = ((f32)*(s16 *)(st + 0x42) - *(f32 *)(st + 0x4C)) * invSteps;
        } else {
            *(f32 *)(obj + 0x20) = 0.0f;
        }
        if (*(f32 *)(st + 0x50) != (f32)*(s16 *)(st + 0x44)) {
            *(f32 *)(obj + 0x24) = ((f32)*(s16 *)(st + 0x44) - *(f32 *)(st + 0x50)) * invSteps;
        } else {
            *(f32 *)(obj + 0x24) = 0.0f;
        }
        st[0x33] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00302DA0_1ED8280.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030301C_1ED84FC(void *arg2, void *arg3) {
    u8 *st = D_overlay_3_0031A1D8;
    s16 diff;
    s16 step;

    diff = mathDiffAngle(*(s16 *)D_overlay_3_0031A1D4, *(s16 *)(st + 0x3E), arg2, arg3);
    step = diff;
    if (diff >= 0x191) {
        step = 0x190;
    } else if (diff < -0x190) {
        step = -0x190;
    }
    *(s16 *)D_overlay_3_0031A1D4 = (s16)(*(s16 *)D_overlay_3_0031A1D4 + step);
    if (*(s16 *)(st + 0x3E) == *(s16 *)D_overlay_3_0031A1D4) {
        st[0x33] = 0x16;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030301C_1ED84FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003030CC_1ED85AC(void) {
    u8 *st = D_overlay_3_0031A1D8;

    if (st[0x00] == 1) {
        st[0x33] = 0;
    }
    *(s16 *)(st + 0x2E) = (s16)(*(s16 *)(st + 0x2E) - 1);
    if (*(s16 *)(st + 0x2E) == 0) {
        st[0x33] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003030CC_1ED85AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030312C_1ED860C(void) {
    *(s16 *)(D_overlay_3_0031A1D8 + 0x2E) = (s16)(*(s16 *)(D_overlay_3_0031A1D8 + 0x2E) - 1);
    if (*(s16 *)(D_overlay_3_0031A1D8 + 0x2E) == 0) {
        D_overlay_3_0031A1D8[0x33] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030312C_1ED860C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00303170_1ED8650(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *cur;
    u8 *temp;
    s32 found = 1;

    cur = *(u8 **)(st + 0x58);
    *(u16 *)(st + 0x28) = (u16)(*(u16 *)(st + 0x28) & 0xEFFF);
    do {
        temp = *(u8 **)(cur + 0x68);
        if ((*(u32 *)temp & 0x1000) || (temp[0x1A] == 0xA)) {
            found = 0;
            break;
        }
        cur = *(u8 **)(temp + 0x28);
    } while (cur != NULL);

    if (found != 0) {
        st[0x33] = 9;
        *(s16 *)(st + 0x2E) = *(s16 *)((u8 *)PatrolNodes + (*(s16 *)(st + 0x3C) & 0xFF) * 0x34 + 0x1C);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00303170_1ED8650.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030322C_1ED870C(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *cur = *(u8 **)(st + 0x58);
    u8 *node = (u8 *)PatrolNodes + (*(s16 *)(st + 0x3C) & 0xFF) * 0x34;
    f32 dz;

    if (GetRange2D(*(f32 *)(cur + 0xC), *(f32 *)(cur + 0x14), cur,
                   *(f32 *)(node + 0x0), *(f32 *)(node + 0x8)) < (f32)node[0x19]) {
        st[0x33] = 0x1E;
        *(s16 *)(st + 0x3E) = 0xA;
        dz = *(f32 *)(node + 0x8) - *(f32 *)(cur + 0x14);
        *(f32 *)(cur + 0x1C) = (*(f32 *)(node + 0x0) - *(f32 *)(cur + 0xC)) * D_overlay_3_003199F8;
        *(f32 *)(cur + 0x20) = (*(f32 *)(node + 0x4) - *(f32 *)(cur + 0x10)) * D_overlay_3_003199F8;
        *(f32 *)(cur + 0x24) = dz * D_overlay_3_003199F8;
        func_overlay_3_00303CAC_1ED918C(dz, D_overlay_3_003199F8, cur);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030322C_1ED870C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030332C_1ED880C(void) {
    u8 *st = D_overlay_3_0031A1D8;
    s16 packed;

    *(s16 *)(st + 0x3E) = (s16)(*(s16 *)(st + 0x3E) - 1);
    if (*(s16 *)(st + 0x3E) <= 0) {
        st[0x33] = 0x1F;
        packed = *(s16 *)(st + 0x3C);
        ProcessNodeChange(GetNextNodeNumber(st[0x30], packed & 0xFF, (packed >> 8) & 0xFF) & 0xFF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030332C_1ED880C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsSetupFirstNodes(void) {
    u8 *st = D_overlay_3_0031A1D8;
    u8 *obj = D_overlay_3_0031A1D4;
    u8 *sp18;
    u8 *node;

    sp18 = D_overlay_3_0031A1CC;
    if (squadsPrepareToProcessSquaddie() != 0) {
        node = (u8 *)PatrolNodes + GetClosestPatrolNode(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10),
                                                        *(f32 *)(obj + 0x14), 0) * 0x34;
        *(s16 *)(st + 0x3C) = *(s16 *)(node + 0x16);
        ProcessNodeChange(GetNextNodeNumber(st[0x30], *(s16 *)(st + 0x3C) & 0xFF, 0) & 0xFF);
        st[0x33] = 0x1F;
    }
    squadsPrepareToProcessSquaddie(sp18);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsSetupFirstNodes.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsPlaceOnAnimObject(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *data = *(u8 **)(obj + 0x68);
    u8 *parent = *(u8 **)(data + 0x24);
    u8 *parentData;
    u8 *node;
    u8 *lock;
    f32 ofs[3];

    if (parent == NULL) {
        return;
    }
    parentData = *(u8 **)(parent + 0x68);
    if ((*(u16 *)(parentData + 0x3C) & 0xFF) == 0) {
        squadsSetupFirstNodes();
    }
    if ((*(u16 *)(parentData + 0x3C) >> 8) == 0) {
        *(f32 *)(obj + 0xC) = *(f32 *)(parent + 0xC) + (f32)(data[0x15] * 100);
        *(f32 *)(obj + 0x10) = *(f32 *)(parent + 0x10);
        *(f32 *)(obj + 0x14) = *(f32 *)(parent + 0x14);
        return;
    }
    node = (u8 *)PatrolNodes + (*(u16 *)(parentData + 0x3C) >> 8) * 0x34;
    lock = *(u8 **)(node + 0x10);
    if (lock == NULL) {
        lock = GetLockObject(*(f32 *)(node + 0x0), *(f32 *)(node + 0x4), *(s32 *)(node + 0x8),
                             node[0x17] >> 6, node[0x32], node[0x33]);
        if (lock != NULL) {
            *(u8 **)(node + 0x10) = lock;
        }
    }
    if (lock != NULL) {
        ofs[0] = *(f32 *)(data + 0x38);
        ofs[1] = *(f32 *)(data + 0x3C);
        ofs[2] = *(f32 *)(data + 0x40);
        mathOneFloatRPY(lock, ofs);
        *(f32 *)(obj + 0xC) = ofs[0] + *(f32 *)(lock + 0xC);
        *(f32 *)(obj + 0x10) = ofs[1] + *(f32 *)(lock + 0x10);
        *(f32 *)(obj + 0x14) = ofs[2] + *(f32 *)(lock + 0x14);
        *(s16 *)(obj + 0x0) = *(s16 *)(lock + 0x0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsPlaceOnAnimObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_overlay_3_00303628_1ED8B08(void) {
    u8 *obj = D_overlay_3_0031A1D8;
    u8 *node;
    u8 *cur;
    u8 *d;
    u8 *lock;
    f32 range;
    s32 count;
    s32 n;
    s32 idx;
    s32 ret;

    count = obj[0x0];
    idx = *(u16 *)(obj + 0x3C) >> 8;
    ret = idx;
    if (idx == 0) {
        squadsSetupFirstNodes();
        idx = *(u16 *)(obj + 0x3C) >> 8;
        ret = idx;
    }
    node = (u8 *)PatrolNodes + idx * 0x34;
    if (idx != 0) {
        if (*(u8 **)(node + 0x10) == NULL) {
            lock = GetLockObject(*(f32 *)(node + 0x0), *(f32 *)(node + 0x4), *(s32 *)(node + 0x8),
                                 node[0x17] >> 6, node[0x32], node[0x33]);
            ret = (s32)lock;
            if (lock != NULL) {
                *(u8 **)(node + 0x10) = lock;
            }
        }
        lock = *(u8 **)(node + 0x10);
        if (lock != NULL) {
            *(u8 **)(obj + 0x54) = lock;
            ret = count;
            if (count != 0) {
                n = count - 1;
                cur = *(u8 **)(obj + 0x58);
                do {
                    d = *(u8 **)(cur + 0x68);
                    if (!(*(u32 *)d & 0x10)) {
                        d[0x2] |= 2;
                        if (node[0x18] == 4 && TryToSetMission(2, 2, node[0x19], node[0x1A], node[0x1B])) {
                            d[0x4A] = node[0x1C];
                        }
                        squadsPlaceOnAnimObject(cur);
                        *(f32 *)(cur + 0x1C) = *(f32 *)(lock + 0x1C);
                        *(f32 *)(cur + 0x20) = *(f32 *)(lock + 0x20);
                        *(f32 *)(cur + 0x24) = *(f32 *)(lock + 0x24);
                        func_overlay_3_00303CAC_1ED918C(cur);
                    }
                    ret = n;
                    cur = *(u8 **)(d + 0x28);
                } while (n-- != 0);
            }
            cur = *(u8 **)(obj + 0x58);
            node = (u8 *)PatrolNodes + (*(u16 *)(obj + 0x3C) & 0xFF) * 0x34;
            range = GetRange2D(*(f32 *)(cur + 0xC), *(f32 *)(cur + 0x14), *(void **)(node + 0x0),
                               *(f32 *)(node + 0x8), 0.0f);
            if (range <= (f32)node[0x19]) {
                obj[0x33] = 0;
                ret = count;
                if (count != 0) {
                    n = count - 1;
                    cur = *(u8 **)(obj + 0x58);
                    do {
                        d = *(u8 **)(cur + 0x68);
                        d[0x2] &= 0xFD;
                        if (d[0xB] == 2) {
                            ClearMissionFields(2, 0);
                            d[0x4B] = 0;
                        }
                        ret = n;
                        cur = *(u8 **)(d + 0x28);
                    } while (n-- != 0);
                }
            }
        }
    }
    return (u8)ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00303628_1ED8B08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003038D4_1ED8DB4(void) {
    u8 *obj = D_overlay_3_0031A1D8;
    u8 *cur;
    u8 *node;
    f32 range;
    s32 idx = *(u16 *)(obj + 0x3C) >> 8;

    if (idx != 0) {
        cur = *(u8 **)(obj + 0x58);
        node = (u8 *)PatrolNodes + idx * 0x34;
        GetRange2D(*(f32 *)(cur + 0xC), *(f32 *)(cur + 0x14), *(void **)(node + 0x0),
                   *(f32 *)(node + 0x8), 0.0f);
        *(f32 *)(cur + 0xC) = *(f32 *)(node + 0x0);
        *(f32 *)(cur + 0x10) = *(f32 *)(node + 0x4);
        *(f32 *)(cur + 0x1C) = 0.0f;
        *(f32 *)(cur + 0x20) = 0.0f;
        *(f32 *)(cur + 0x24) = 0.0f;
        *(f32 *)(cur + 0x14) = *(f32 *)(node + 0x8);
        func_overlay_3_00303CAC_1ED918C(cur);

        node = (u8 *)PatrolNodes + (*(u16 *)(obj + 0x3C) & 0xFF) * 0x34;
        range = GetRange2D(*(f32 *)(cur + 0xC), *(f32 *)(cur + 0x14), *(void **)(node + 0x0),
                           *(f32 *)(node + 0x8), 0.0f);
        if (range <= (f32)node[0x19]) {
            obj[0x33] = 0;
        }
        if (range < (f32)node[0x19]) {
            obj[0x33] = 0x1E;
            *(s16 *)(obj + 0x3E) = 10;
            *(f32 *)(cur + 0x1C) = (*(f32 *)(node + 0x0) - *(f32 *)(cur + 0xC)) * D_overlay_3_003199FC;
            *(f32 *)(cur + 0x20) = (*(f32 *)(node + 0x4) - *(f32 *)(cur + 0x10)) * D_overlay_3_003199FC;
            *(f32 *)(cur + 0x24) = (*(f32 *)(node + 0x8) - *(f32 *)(cur + 0x14)) * D_overlay_3_003199FC;
            func_overlay_3_00303CAC_1ED918C(cur);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003038D4_1ED8DB4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00303AA8_1ED8F88(void) {
    u8 *obj = D_overlay_3_0031A1D8;
    u8 *st = D_overlay_3_0031A1D0;
    u8 *target = D_overlay_3_0031A1E8;
    u8 *cur;
    u8 *node;
    u8 idx;
    f32 dist;
    s32 r;

    if (EnsureValidNode() != 0) {
        idx = obj[0x3D];
        node = (u8 *)PatrolNodes + idx * 0x34;
        cur = *(u8 **)(obj + 0x58);
        if (*(u32 *)(node + 0x14) & 2) {
            obj[0x74] = idx;
        }
        if (*(f32 *)(obj + 0x6C) == 1.0f) {
            dist = GetRange(*(f32 *)(cur + 0xC), *(f32 *)(cur + 0x10), *(f32 *)(cur + 0x14),
                            *(f32 *)(node + 0x0), *(f32 *)(node + 0x4), *(f32 *)(node + 0x8));
            if (dist < (f32)func_overlay_3_00302760_1ED7C40(node)) {
                if (func_overlay_3_00301C58_1ED7138(node, 1) == 0) {
                    if (GetRange(*(f32 *)(cur + 0xC), *(f32 *)(cur + 0x10), *(f32 *)(cur + 0x14),
                                 *(f32 *)(target + 0xC), *(f32 *)(target + 0x10), *(f32 *)(target + 0x14)) < 700.0f
                        || !(*(u32 *)(node + 0x14) & 2)) {
                        r = FallBackToSniperPoint(idx);
                        if (r != idx) {
                            ProcessNodeChange(r & 0xFF);
                            st[0x1] |= 0x20;
                        } else {
                            func_overlay_3_00301C58_1ED7138(node, 0);
                        }
                    } else {
                        st[0x1] &= 0xDF;
                        func_overlay_3_00301C58_1ED7138(node, 0);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00303AA8_1ED8F88.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00303C84_1ED9164(void) {
    SquadronControlSmart(D_overlay_3_0031A1D4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00303C84_1ED9164.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00303CAC_1ED918C(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *d = *(u8 **)(obj + 0x68);
    f32 x = *(f32 *)(obj + 0x1C);
    f32 z = *(f32 *)(obj + 0x24);
    f32 y = *(f32 *)(obj + 0x20);
    f32 sumXZ = (x * x) + (z * z);

    *(u16 *)(d + 0x1C) = Arctanf(x, z);
    *(u16 *)(d + 0x1E) = Arctanf(y, sqrtf(sumXZ));
    *(f32 *)(d + 0x20) = sqrtf((y * y) + sumXZ);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00303CAC_1ED918C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00303D44_1ED9224(s16 arg0, f32 arg1) {
    u8 *cur = D_overlay_3_0031A1CC;
    u8 *st = D_overlay_3_0031A1D0;
    f32 x;
    f32 z;

    *(f32 *)(cur + 0x1C) = *(f32 *)(cur + 0x1C) - (Sinf((s32)arg0) * arg1);
    *(f32 *)(cur + 0x24) = *(f32 *)(cur + 0x24) - (Cosf((s32)arg0) * arg1);
    x = *(f32 *)(cur + 0x1C);
    z = *(f32 *)(cur + 0x24);
    *(u16 *)(st + 0x1C) = Arctanf(x, z);
    *(f32 *)(st + 0x20) = sqrtf((x * x) + (z * z));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00303D44_1ED9224.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 GetRange2D(f32 arg0, f32 arg1, void *arg2, f32 arg3, f32 arg4) {
    f32 dx = arg0 - *(f32 *)&arg2;
    f32 dz = arg1 - arg3;

    return sqrtf((dx * dx) + (dz * dz));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetRange2D.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 GetRangeSquared2D(f32 arg0, f32 arg1, s32 arg2, s32 arg3) {
    f32 dx = arg0 - *(f32 *)&arg2;
    f32 dz = arg1 - *(f32 *)&arg3;

    return (dx * dx) + (dz * dz);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetRangeSquared2D.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 DoLinesIntersect(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                     s16 *arg8, s16 *arg9) {
    s32 dx = arg3 - arg1;
    s32 dy = arg0 - arg2;
    s32 c1 = (arg2 * arg1) - (arg0 * arg3);
    s32 s1 = (dx * arg4) + (dy * arg5) + c1;
    s32 s2 = (dx * arg6) + (dy * arg7) + c1;
    s32 ex;
    s32 ey;
    s32 c2;
    s32 t4;
    s32 t5;
    s32 den;
    s32 half;
    s32 n1;
    s32 n2;
    s32 v;
    s32 w;

    if (s1 != 0 && s2 != 0 && (s1 ^ s2) >= 0) {
        return 0;
    }

    ex = arg4 - arg6;
    ey = arg7 - arg5;
    c2 = (arg6 * arg5) - (arg4 * arg7);
    t4 = (ey * arg0) + (ex * arg1) + c2;
    t5 = (ey * arg2) + (ex * arg3) + c2;
    if (t4 != 0 && t5 != 0 && (t4 ^ t5) >= 0) {
        return 0;
    }

    den = (dx * ex) - (ey * dy);
    if (den == 0) {
        return 2;
    }
    if (arg8 != NULL) {
        half = (den < 0) ? (-den / 2) : (den / 2);
        n1 = (dy * c2) - (ex * c1);
        v = n1 + half;
        if (n1 < 0) {
            v = n1 - half;
        }
        *arg8 = (s16)(v / den);

        n2 = (ey * c1) - (dx * c2);
        w = n2 + half;
        if (n2 < 0) {
            w = n2 - half;
        }
        *arg9 = (s16)(w / den);
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/DoLinesIntersect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003040FC_1ED95DC(s16 *arg0, s16 *arg1, s16 *arg2, f32 arg3) {
    f32 len = sqrtf((f32)((*arg2 * *arg2) + (*arg0 * *arg0) + (*arg1 * *arg1)));

    if (len != 0.0f && len < arg3) {
        *arg0 = (s16)(s32)(((f32)*arg0 / len) * arg3);
        *arg1 = (s16)(s32)(((f32)*arg1 / len) * arg3);
        *arg2 = (s16)(s32)(((f32)*arg2 / len) * arg3);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003040FC_1ED95DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 TryToSetMission(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    u8 *st = D_overlay_3_0031A1D0;
    s32 mask = D_overlay_3_0031976C[arg1];
    u8 cur;

    if (((1 << arg1) & 0x18000) && ((s32)D_overlay_3_0031A1E0[0x2B] >= 5)) {
        return 0;
    }
    if (D_overlay_3_0031A1DC == 0x31) {
        if (FlopsyDogCheckPriority(arg1) == 0) {
            return 0;
        }
    }
    cur = st[0x1A];
    if (arg1 != cur && ((1 << cur) & mask)) {
        st[0x0B] = (u8)arg0;
        st[0x1A] = (u8)arg1;
        st[0x1B] = 1;
        st[0x50] = arg2;
        st[0x51] = arg3;
        st[0x52] = arg4;
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/TryToSetMission.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void ClearMissionFields(s32 arg0, s32 arg1) {
    u8 *st = D_overlay_3_0031A1D0;

    if (arg0 == 1 || arg0 == (s8)st[0x0B]) {
        st[0x1A] = 0;
        st[0x1B] = 0;
        st[0x0B] = 0;
        st[0x4A] = (u8)arg1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/ClearMissionFields.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_003043FC_1ED98DC(s32 arg0) {
    u8 *st = D_overlay_3_0031A1D0;

    return (1 << st[0x4B]) & D_overlay_3_003197D4[arg0];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003043FC_1ED98DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *GetAnimData(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *parent;
    u8 *parentData;
    s32 typeIdx;

    if (d == NULL) {
        return NULL;
    }
    parent = *(u8 **)(d + 0x24);
    if (parent == NULL) {
        return D_overlay_3_00317DB8;
    }
    parentData = *(u8 **)(parent + 0x68);
    typeIdx = BaddyTypeToIndex(*(u16 *)(parentData + 0x2C), parent);
    return &D_overlay_3_00317DB8[(*(s32 *)(D_overlay_3_00319278 + typeIdx * 4) * 8) + (d[0x19] * 8)];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetAnimData.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 func_overlay_3_003044B4_1ED9994(void) {
    return (f32)*(s16 *)GetAnimData(D_overlay_3_0031A1CC) * D_overlay_3_00319A00;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003044B4_1ED9994.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003044F4_1ED99D4(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *data = *(u8 **)(obj + 0x68);
    u8 *cfg = D_overlay_3_0031A1E0;
    u8 idx = cfg[0x2F];
    u8 *entry = cfg + idx * 8;
    s32 bit = 1 << entry[0x40];
    u8 *sub = entry + 0x40;
    u16 mask = (u16)bit;
    u8 params[0x13];
    void *spawned;

    if (idx != 7) {
        if (!(*(u16 *)(data + 0x5A) & mask) && data[0x55] == 0) {
            *(u16 *)(data + 0x5A) = (u16)(*(u16 *)(data + 0x5A) | mask);
            data[0x06] = (u8)(data[0x06] | 8);
            SquaddieLightAndAnimate(idx, sub, bit);
            if (FreeRAM >= 0xC001) {
                *(s16 *)(params + 0x00) = 0x89;
                params[0x02] = 0x14;
                params[0x03] = 0;
                *(s16 *)(params + 0x04) = 0;
                *(s16 *)(params + 0x06) = 0;
                *(s16 *)(params + 0x08) = 0;
                *(u8 **)(params + 0x0C) = D_overlay_3_0031A1CC;
                params[0x10] = sub[4];
                params[0x11] = sub[5];
                params[0x12] = sub[2];
                spawned = objSetupObject(params, 1, sub);
                if (spawned != NULL) {
                    *(f32 *)((u8 *)spawned + 0x1C) = *(f32 *)((u8 *)spawned + 0x1C) + 0.0f;
                    *(f32 *)((u8 *)spawned + 0x20) = *(f32 *)((u8 *)spawned + 0x20) + 0.0f;
                    *(f32 *)((u8 *)spawned + 0x24) = *(f32 *)((u8 *)spawned + 0x24) + 0.0f;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003044F4_1ED99D4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00304614_1ED9AF4(s32 arg0, s32 arg1) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *tbl = D_overlay_3_00319278 + D_overlay_3_0031A1DC * 4;
    s32 base = *(u16 *)tbl * 8;
    s32 count = *(u16 *)(tbl + 2);
    u8 *ent = D_overlay_3_00317DB8 + base;
    u8 cand[0x20];
    s32 nCand = 0;
    s32 weightSum = 0;
    s32 sel = arg0;
    s32 forced = 0;
    s32 flags4;
    u32 objFlags;
    s32 i;
    s32 k;
    s32 roll;

    if (D_overlay_3_0031A1D8 == NULL) {
        return -1;
    }
    if (sel == 5 || sel == 6) {
        u16 f = *(u16 *)(D_overlay_3_0031A1D8 + 0x28);

        if ((f & 2) && (f & 0x8000)) {
            return -1;
        }
        if (f & 2) {
            sel = 6;
            forced = 1;
        }
        if (f & 0x8000) {
            sel = 5;
            forced = 1;
        }
    }
    flags4 = *(s32 *)(st + 4);
    objFlags = *(u32 *)(*(u8 **)(obj + 0x4C) + 8);
    if (sel == 5 && arg1 == 0) {
        if (((flags4 >> 6) & 1) && !(flags4 & 0x20)) {
            sel = 0xC;
        } else if (!((flags4 >> 6) & 1) && (flags4 & 0x20)) {
            sel = 0x34;
        }
    }
    for (i = 0; i < count; i++) {
        u8 *e = ent + i * 8;
        u32 w = *(u32 *)(e + 4);
        s32 fieldA = (w >> 22) & 7;
        s32 stBit = (flags4 >> 11) & 1;

        if ((sel == e[2] || (!forced && sel == e[3]))
            && ((stBit == 0 && fieldA != 2) || (stBit != 0 && fieldA != 1))
            && (e[3] != 0x3C || !(objFlags & 0x20000000))) {
            if (e[3] != 0x3D || (objFlags & 0x20000000)) {
                cand[nCand] = (u8)i;
                nCand++;
                weightSum += w >> 27;
            }
        }
    }
    switch (nCand) {
    case 0:
        return -1;
    case 1:
        if (arg1 == 0) {
            st[0x0A] = (u8)sel;
        }
        return cand[0];
    default:
        if (arg1 == 0) {
            st[0x0A] = (u8)sel;
        }
        roll = mathRnd(1, weightSum);
        for (k = nCand - 1; k > 0; k--) {
            roll -= *(u32 *)(ent + cand[k] * 8 + 4) >> 27;
            if (roll <= 0) {
                return cand[k];
            }
        }
        return cand[mathRnd(0, nCand - 1)];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00304614_1ED9AF4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00304968_1ED9E48(s32 arg0, s32 arg1, s32 arg2) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *d8 = D_overlay_3_0031A1D8;
    s32 cur = D_overlay_3_0031A1DC;
    s32 sel = arg0;
    u8 *ent;
    u32 entWord;

    if (cur == 0x13) {
        return arg0;
    }
    if (arg2 != 0) {
        u8 *o4c = *(u8 **)(obj + 0x4C);
        u32 fl = *(u32 *)(o4c + 8);
        s32 done = 0;

        if ((arg1 == 0x21 || arg1 == 0x25)
            && (cur == 1 || cur == 5 || cur == 0xD || cur == 0xE || cur == 0xF || cur == 0x16)) {
            u8 v31 = o4c[0x31];

            if ((fl & 0x20000000) || v31 == 0) {
                sel = 8;
            } else {
                sel = (v31 - 1) * 2;
            }
            done = 1;
        }
        if (!done && (arg1 == 0x16 || arg1 == 0x19)
            && (cur == 1 || cur == 5 || cur == 0xD || cur == 0x16)) {
            sel = (fl & 0x20000000) ? 0x17 : 0x1A;
            done = 1;
        }
        if (!done && cur == 6) {
            if (arg1 == 0x21) {
                s32 t8 = d8[0x34] & 3;

                sel = 2;
                if (t8 == 2 || (t8 == 3 && !(fl & 0x20000000))) {
                    sel = 0;
                }
            } else if (arg1 == 0x16 || arg1 == 0x19) {
                sel = (fl & 0x20000000) ? 0xF : 0x12;
            }
        }
    }
    if (arg1 == 1 && d8[0x30] == 3) {
        s32 r = func_overlay_3_00304614_1ED9AF4(0x3B, 1);

        if (r != -1) {
            sel = r;
        }
    }
    ent = D_overlay_3_00317DB8 + *(u16 *)(D_overlay_3_00319278 + cur * 4) * 8 + sel * 8;
    entWord = *(u32 *)(ent + 4);
    st[0x56] = (u8)((entWord >> 11) & 0xF);
    if (cur == 0x20) {
        void *p = *(void **)(st + 0xAC);

        if (p != NULL) {
            objFreeObject(p);
            *(void **)(st + 0xAC) = NULL;
        }
    }
    *(s32 *)(obj + 0x84) = 0;
    if (((entWord >> 22) & 7) == 3) {
        func_overlay_3_003044F4_1ED99D4(obj);
    }
    if (!(*(u16 *)(d8 + 0x28) & 0x8000)) {
        if (((entWord >> 22) & 7) == 4) {
            if (mathRnd(1, 3) == 1) {
                func_overlay_3_003044F4_1ED99D4(obj);
            }
        }
    }
    if (sel == -1) {
        return -1;
    }
    objAnimSetMove(obj, sel, 0, sel);
    *(f32 *)(st + 0x60) = 0.0f;
    st[0x19] = (u8)sel;
    return sel;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00304968_1ED9E48.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void TryToSetAnim(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 cands[3];
    s32 idx;
    s32 cur = -1;
    s32 kind = 0;
    u8 *st = D_overlay_3_0031A1D0;

    if (func_overlay_3_003043FC_1ED98DC(arg0) == 0) {
        return;
    }
    cands[0] = arg1;
    cands[1] = arg2;
    cands[2] = arg3;
    if (arg1 != 0) {
        for (idx = 0; idx < 3; idx++) {
            s32 c;

            if (idx > 0 && cands[idx] == 0) {
                break;
            }
            c = cands[idx];
            if ((D_overlay_3_0031A1E0[0x24] & 0x20) && c >= 0x16 && c < 0x20) {
                if (st[0x0A] >= 0x16 && st[0x0A] < 0x20) {
                    return;
                }
            }
            if (c == st[0x0A]) {
                return;
            }
            if (st[0x0A] == 0x21 || st[0x0A] == 0x25) {
                return;
            }
            cur = func_overlay_3_00304614_1ED9AF4(c, 0);
            kind = c;
            if (idx < 2 && cur == -1) {
                continue;
            }
            break;
        }
    }
    if (func_overlay_3_00304968_1ED9E48(cur, kind, 1) != -1) {
        st[0x4B] = (u8)arg0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/TryToSetAnim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 TryToSetAnimByIndex(s32 arg0, s32 arg1) {
    u8 *st = D_overlay_3_0031A1D0;
    s32 kind = D_overlay_3_00317DB8[*(u16 *)(D_overlay_3_00319278 + D_overlay_3_0031A1DC * 4) * 8 + arg1 * 8 + 2];
    s32 res;

    if (func_overlay_3_003043FC_1ED98DC(arg0) == 0) {
        return -1;
    }
    if (st[0x0A] == 0x21 || st[0x0A] == 0x25) {
        return -1;
    }
    res = func_overlay_3_00304968_1ED9E48(arg1, kind, 0);
    if (res != -1) {
        st[0x4B] = (u8)arg0;
    }
    return res;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/TryToSetAnimByIndex.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 TryToUpdateAnim(s32 arg0, s32 arg1) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *d8 = D_overlay_3_0031A1D8;
    f32 scale = *(f32 *)&arg1;
    u8 *anim;
    s32 var_a1 = 0;

    if (arg0 == st[0x4B]) {
        anim = GetAnimData(obj);
        *(f32 *)(st + 0x60) = *(f32 *)(obj + 0x28);
        var_a1 = objAnimDframe(obj, func_overlay_3_003044B4_1ED9994() * scale, D_overlay_3_0031A1C8);
        if (var_a1 != 0) {
            if (*(u16 *)(d8 + 0x2C) == 0xBD) {
                void *p;

                *(s32 *)(obj + 0x84) = 0;
                p = *(void **)(st + 0xA8);
                if (p != NULL) {
                    objFreeObject(p);
                    *(void **)(st + 0xA8) = NULL;
                }
            }
            if (*(s16 *)(st + 0xA6) > 0) {
                if (((*(u32 *)(anim + 4) >> 11) & 0xF) != 0) {
                    s32 t = (s8)st[0x56];

                    if (t != 0) {
                        if (t != 0xF) {
                            st[0x56] = (u8)(t - 1);
                        }
                        return 0;
                    }
                }
                if (anim[0x0A] == 0x35 && st[0x4B] != 9) {
                    st[0x19] = (u8)(st[0x19] + 1);
                    func_overlay_3_00304968_1ED9E48(st[0x19], 0x35, 1);
                    return 0;
                }
            } else if (st[0x55] == 0) {
                st[0x55] = 1;
            }
        }
    }
    return var_a1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/TryToUpdateAnim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void UpdateOrSetAnim(s32 arg0, s32 arg1, s32 arg2) {
    u8 *st = D_overlay_3_0031A1D0;
    s32 idx;
    u8 *ent;

    if (func_overlay_3_003043FC_1ED98DC(arg0) == 0) {
        return;
    }
    if (arg0 == st[0x4B] && arg2 == st[0x0A] && TryToUpdateAnim(st[0x4B], arg1) == 0) {
        return;
    }
    if (D_overlay_3_00319434 != -1) {
        st[0x0A] = (u8)arg2;
        idx = D_overlay_3_00319434;
    } else {
        idx = func_overlay_3_00304614_1ED9AF4(arg2, 0);
    }
    if (idx == -1) {
        return;
    }
    ent = D_overlay_3_00317DB8 + idx * 8;
    if (((*(u32 *)(ent + 4) >> 11) & 0xF) != 0) {
        st[0x56] = (u8)(ent[3] & 0x7F);
    }
    if (idx != st[0x19]) {
        func_overlay_3_00304968_1ED9E48(idx, arg2, 1);
    }
    st[0x4B] = (u8)arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/UpdateOrSetAnim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_3_0030527C_1EDA75C(f32 arg0, f32 arg1, f32 arg2) {
    s32 count;
    s32 i;
    f32 best = D_overlay_3_00319A04;
    void *bestObj = NULL;
    void **players = objGetPlayerlist(&count);

    for (i = 0; i < count - 1; i++) {
        u8 *p = (u8 *)players[i];
        u8 *data = *(u8 **)(p + 0x68);
        f32 d;

        d = GetRangeSquared(*(f32 *)(p + 0xC), *(f32 *)(p + 0x10), *(f32 *)(p + 0x14), arg0, arg1, arg2);
        if (d < best) {
            best = d;
            bestObj = p;
        }
        if (data[0x10D] != 0) {
            u8 *sub = *(u8 **)(data + 0x50C);

            d = GetRangeSquared(*(f32 *)(sub + 0xC), *(f32 *)(sub + 0x10), *(f32 *)(sub + 0x14), arg0, arg1, arg2);
            if (d < best) {
                best = d;
                bestObj = sub;
            }
        }
    }
    return bestObj;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030527C_1EDA75C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *squadsGetClosestPlayer(void) {
    return D_overlay_3_0031A1E8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsGetClosestPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003053D4_1EDA8B4(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *data = *(u8 **)(obj + 0x68);

    if (*(void **)(data + 0x64) == NULL) {
        if (*(s16 *)(obj + 0x4A) == 0x8D) {
            BTSBBlackAnt();
        } else if (D_overlay_3_0031A1D8[0x91] & 1) {
            *(u8 **)(data + 0x64) = D_overlay_3_0031A1E8;
        } else {
            *(void **)(data + 0x64) = NULL;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003053D4_1EDA8B4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 squadsPrepareToProcessSquaddie(u8 *arg0) {
    D_overlay_3_0031A1D0 = NULL;
    D_overlay_3_0031A1D4 = NULL;
    D_overlay_3_0031A1D8 = NULL;
    D_overlay_3_0031A1CC = arg0;
    if (arg0 == NULL) {
        return 0;
    }
    D_overlay_3_0031A1D0 = *(u8 **)(arg0 + 0x68);
    if ((s8)D_overlay_3_0031A1D0[0x07] < 0) {
        return 0;
    }
    D_overlay_3_0031A1D4 = *(u8 **)(D_overlay_3_0031A1D0 + 0x24);
    if (D_overlay_3_0031A1D4 == NULL) {
        return 0;
    }
    D_overlay_3_0031A1D8 = *(u8 **)(D_overlay_3_0031A1D4 + 0x68);
    D_overlay_3_0031A1E8 = (u8 *)func_overlay_3_0030527C_1EDA75C(*(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10),
                                                              *(f32 *)(arg0 + 0x14));
    func_overlay_3_003053D4_1EDA8B4(D_overlay_3_0031A1CC);
    D_overlay_3_0031A1E4 = *(u8 **)(D_overlay_3_0031A1D0 + 0x64);
    CopyStaticsToKernel(D_overlay_3_0031A1CC, D_overlay_3_0031A1D4);
    CopyStaticsToPatrolNodes(D_overlay_3_0031A1D4);
    return GetBaddyData(D_overlay_3_0031A1CC) != 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsPrepareToProcessSquaddie.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030556C_1EDAA4C(u8 *arg0) {
    u8 *cur;
    void *found;

    D_overlay_3_0031A1D4 = arg0;
    D_overlay_3_0031A1D8 = *(u8 **)(arg0 + 0x68);
    cur = *(u8 **)(D_overlay_3_0031A1D8 + 0x58);
    D_overlay_3_0031A1CC = cur;
    if (cur != NULL) {
        D_overlay_3_0031A1D0 = *(u8 **)(cur + 0x68);
        D_overlay_3_0031A1E4 = *(u8 **)(D_overlay_3_0031A1D0 + 0x64);
        found = func_overlay_3_0030527C_1EDA75C(*(f32 *)(cur + 0xC), *(f32 *)(cur + 0x10), *(f32 *)(cur + 0x14));
    } else {
        D_overlay_3_0031A1D0 = NULL;
        D_overlay_3_0031A1E4 = NULL;
        found = func_overlay_3_0030527C_1EDA75C(*(f32 *)(D_overlay_3_0031A1D4 + 0xC),
                                                *(f32 *)(D_overlay_3_0031A1D4 + 0x10),
                                                *(f32 *)(D_overlay_3_0031A1D4 + 0x14));
    }
    D_overlay_3_0031A1E8 = found;
    CopyStaticsToKernel(D_overlay_3_0031A1CC, D_overlay_3_0031A1D4);
    CopyStaticsToPatrolNodes(D_overlay_3_0031A1D4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030556C_1EDAA4C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00305650_1EDAB30(u8 *arg0, s32 arg1, s8 *arg2, s8 *arg3) {
    s32 t = arg1 & 0xFF;

    *arg2 = (s8)(t - 1);
    *arg3 = (s8)(t + 1);
    if (t == 0) {
        *arg2 = (s8)(arg0[4] - 1);
        return;
    }
    if (arg0[4] == t + 1) {
        *arg3 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00305650_1EDAB30.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *GetRegion(s32 arg0) {
    u8 *ret = NULL;

    if (D_overlay_3_0031942C == NULL) {
        return ret;
    }
    ret = D_overlay_3_0031942C + arg0 * 0x2C;
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetRegion.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 GetRegionIndex(s32 arg0) {
    return (arg0 - (s32)D_overlay_3_0031942C) / 0x2C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetRegionIndex.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 WhichRegionIsPointIn(s16 arg0, s16 arg1) {
    s32 count = D_overlay_3_0031A124 - 1;
    u8 *region = D_overlay_3_0031942C + 0x2C;

    while (count > 0) {
        if (*(s32 *)(region + 0x18) != 0 && IsPointInRegion((f32)arg0, (f32)arg1, region) != 0) {
            return ((s32)(region - D_overlay_3_0031942C)) / 0x2C;
        }
        count--;
        region += 0x2C;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/WhichRegionIsPointIn.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 IsPointInSibling(f32 arg0, f32 arg1) {
    f32 radius = *(f32 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x24);
    f32 radiusSq = radius * radius;
    u8 *obj = *(u8 **)(D_overlay_3_0031A1D8 + 0x58);

    while (obj != NULL) {
        u8 *racer = *(u8 **)(obj + 0x68);
        if (obj != D_overlay_3_0031A1CC &&
            GetRangeSquared2D(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), *(s32 *)&arg0, *(s32 *)&arg1) <= radiusSq) {
            return 1;
        }
        obj = *(u8 **)(racer + 0x28);
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/IsPointInSibling.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquaddieLightAndAnimate(s32 arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *sq = *(u8 **)(obj + 0x68);
    u8 *light;
    u8 *anim;
    u8 *mdl;
    u8 *tgt;
    f32 px, py, pz, v;
    s32 id;

    if (*(u8 *)(*(u8 **)(obj + 0x40) + 0x1E) == 4) {
        return;
    }

    light = *(u8 **)(*(u8 **)(obj + 0x6C) + *(u8 *)(obj + 0x3A) * 4);
    if (light[0x0A] != 0) {
        anim = *(u8 **)light;
        if (anim[0x4E] != 0) {
            modGenAnimMatrices(light, anim, arg0, 1.0f, 0.0f);
        } else if (*(s8 *)(anim + 0x11) != 0) {
            light[0x0B] = (u8)(1 - *(s8 *)(light + 0x0B));
        }
        lightObject(arg0, light, *(s32 *)(obj + 0x54), *(s32 *)(light + light[0x0B] * 4 + 0x10));
        if (*(s8 *)(anim + 0x11) > 0) {
            objAnimTextures(arg0, anim, light, light[0x0A]);
        }
        light[0x0A] = 0;
    }

    tgt = *(u8 **)(sq + 0x24);
    if (tgt != NULL && *(u16 *)(*(u8 **)(tgt + 0x68) + 0x2C) == 0x70) {
        u8 *lpos = *(u8 **)(light + 0x68);
        px = *(f32 *)(lpos + 0x0);
        py = *(f32 *)(lpos + 0x4);
        pz = *(f32 *)(lpos + 0x8);
        mdl = *(u8 **)(sq + 0xA8);

        if (*(u32 *)(sq + 0x4) & 0x800) {
            if (mdl != NULL) {
                objFreeObject(mdl);
                *(u8 **)(sq + 0xA8) = NULL;
            }
            id = *(s32 *)(sq + 0xC0);
            if (id != 0 && !(*(u32 *)(sq + 0x4) & 0x400)) {
                trackLightDelete(id);
                *(s32 *)(sq + 0xC0) = 0;
            }
            id = *(s32 *)(sq + 0xC4);
            if (id != 0 && !(*(u32 *)(sq + 0x4) & 0x400)) {
                killLight(id);
                *(s32 *)(sq + 0xC4) = 0;
            }
        } else {
            if (mdl != NULL) {
                *(f32 *)(mdl + 0xC) = px;
                *(f32 *)(mdl + 0x10) = py;
                *(f32 *)(mdl + 0x14) = pz;
            } else {
                u8 spawn[0x14];
                u8 *created;
                *(s16 *)(spawn + 0x0) = 0x76;
                spawn[0x2] = 0x0E;
                spawn[0x3] = 0;
                *(s16 *)(spawn + 0x4) = (s16)px;
                *(s16 *)(spawn + 0x6) = (s16)py;
                *(s16 *)(spawn + 0x8) = (s16)pz;
                spawn[0xA] = 0x28;
                spawn[0xB] = 0x08;
                spawn[0xC] = 0;
                created = objSetupObject(spawn, 1, NULL);
                if (created != NULL) {
                    *(s32 *)(created + 0x3C) = 0;
                    *(u8 **)(sq + 0xA8) = created;
                }
            }

            id = *(s32 *)(sq + 0xC0);
            if (id != 0) {
                trackLightMove((void *)id, px, py, pz);
            } else {
                id = trackLightAdd(px, py, 0, pz, 150.0f, 100.0f, 0xFF, 0xE0, 0);
                *(s32 *)(sq + 0xC0) = id;
                if (id != 0) {
                    trackLightMove((void *)id, px, py, pz);
                }
            }

            if (*(s32 *)(sq + 0xC4) == 0) {
                u8 lp[0x18];
                lp[0] = 1;
                lp[1] = 3;
                lp[2] = 0x71;
                lp[3] = 0;
                lp[4] = 0;
                *(s16 *)(lp + 0x6) = (s16)px;
                *(s16 *)(lp + 0x8) = (s16)py;
                *(s16 *)(lp + 0xA) = (s16)pz;
                *(s16 *)(lp + 0xC) = 0xA0;
                *(s16 *)(lp + 0xE) = 0xA0;
                lp[0x10] = 0xFF;
                lp[0x11] = 0xFF;
                lp[0x12] = 0;
                lp[0x13] = 0xFF;
                *(s16 *)(lp + 0x14) = -1;
                lp[0x16] = 0;
                lp[0x17] = 0;
                *(s32 *)(sq + 0xC4) = addObjectLight((Object *)obj, (ObjectHeader48 *)lp);
            }
        }
    }

    if (*(u32 *)sq & 0x40000000) {
        v = *(f32 *)(*(u8 **)(obj + 0x4C) + 0xC);
        id = *(s32 *)(sq + 0xC0);
        if (id != 0) {
            trackLightMove((void *)id, v, v, v);
        } else {
            id = trackLightAdd(v, v, 0, v, 250.0f, 125.0f, 0xFF, 0xC0, 0);
            *(s32 *)(sq + 0xC0) = id;
            if (id != 0) {
                trackLightMove((void *)id, v, v, v);
            }
        }
        if (*(s32 *)(sq + 0xC4) == 0) {
            u8 lp[0x18];
            lp[0] = 1;
            lp[1] = 3;
            lp[2] = 0x71;
            lp[3] = 0;
            lp[4] = 0;
            *(s16 *)(lp + 0x6) = (s16)v;
            *(s16 *)(lp + 0x8) = (s16)v;
            *(s16 *)(lp + 0xA) = (s16)v;
            *(s16 *)(lp + 0xC) = 0xA0;
            *(s16 *)(lp + 0xE) = 0xA0;
            lp[0x10] = 0xFF;
            lp[0x11] = 0xD2;
            lp[0x12] = 0x96;
            lp[0x13] = 0xFF;
            *(s16 *)(lp + 0x14) = -1;
            lp[0x16] = 0;
            lp[0x17] = 0;
            *(s32 *)(sq + 0xC4) = addObjectLight((Object *)obj, (ObjectHeader48 *)lp);
        }
        sq[0x6] |= 4;
    } else if (*(u32 *)(sq + 0x8) & 0x04000000) {
        v = *(f32 *)(*(u8 **)(obj + 0x4C) + 0xC);
        sq[0x8] |= 3;
        if (D_overlay_3_0031944C != 0) {
            id = *(s32 *)(sq + 0xC0);
            if (id != 0) {
                trackLightMove((void *)id, v, v, v);
            } else {
                id = trackLightAdd(v, v, 0, v, 250.0f, 125.0f, 0, 0xD4, 0xFF);
                *(s32 *)(sq + 0xC0) = id;
                if (id != 0) {
                    trackLightMove((void *)id, v, v, v);
                }
            }
        } else {
            id = *(s32 *)(sq + 0xC0);
            if (id != 0) {
                trackLightDelete(id);
            }
            *(s32 *)(sq + 0xC0) = 0;
        }
        id = *(s32 *)(sq + 0xC4);
        if (id == 0) {
            u8 lp[0x18];
            lp[0] = 1;
            lp[1] = 3;
            lp[2] = 0x71;
            lp[3] = 0;
            lp[4] = 0;
            *(s16 *)(lp + 0x6) = (s16)v;
            *(s16 *)(lp + 0x8) = (s16)v;
            *(s16 *)(lp + 0xA) = (s16)v;
            *(s16 *)(lp + 0xC) = 0xA0;
            *(s16 *)(lp + 0xE) = 0xA0;
            lp[0x10] = 0;
            lp[0x11] = 0xD4;
            lp[0x12] = 0xFF;
            lp[0x13] = 0xFF;
            *(s16 *)(lp + 0x14) = -1;
            lp[0x16] = 0;
            lp[0x17] = 0;
            id = addObjectLight((Object *)obj, (ObjectHeader48 *)lp);
            *(s32 *)(sq + 0xC4) = id;
        }
        if (D_overlay_3_0031944C != 0) {
            if (id != 0) {
                turnLightOn((UnkLight *)id);
            }
        } else if (id != 0) {
            turnLightOff((UnkLight *)id);
        }
        sq[0x6] |= 4;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddieLightAndAnimate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsGetChildPolyPosition(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *self = D_overlay_3_0031A1CC;
    u8 *light = *(u8 **)(*(u8 **)(self + 0x6C) + *(u8 *)(self + 0x3A) * 4);

    if (light != NULL) {
        u8 *tbl;
        if (light[0x0A] != 0) {
            SquaddieLightAndAnimate((s32)self, arg1, (s32)arg2);
        }
        if (arg0 < *(s8 *)(*(u8 **)light + 0x2D)) {
            tbl = *(u8 **)(light + 0x68);
            if (tbl != NULL) {
                *arg1 = *(f32 *)(tbl + arg0 * 0xC);
                *arg2 = (f32)*(s32 *)(tbl + arg0 * 0xC + 0x4);
                *arg3 = (f32)*(s32 *)(tbl + arg0 * 0xC + 0x8);
            }
            return;
        }
    }

    *arg1 = *(f32 *)(*(u8 **)(self + 0x4C) + 0xC);
    *arg2 = *(f32 *)(*(u8 **)(self + 0x4C) + 0x10);
    *arg3 = *(f32 *)(*(u8 **)(self + 0x4C) + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsGetChildPolyPosition.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s8 func_overlay_3_003061FC_1EDB6DC(void) {
    s32 count;
    void **list = squadsGetSquadronList(&count);
    u32 used = 0;
    s32 i;

    for (i = 0; i < count; i++) {
        used |= 1 << *(u8 *)(*(u8 **)((u8 *)list[i] + 0x68) + 0x78);
    }
    for (i = 0; i < 0x20; i++) {
        if (!((used >> i) & 1)) {
            return (s8)i;
        }
    }
    return -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003061FC_1EDB6DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *func_overlay_3_003062A0_1EDB780(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *ctl = D_overlay_3_0031A1D8;
    u8 *best = NULL;
    u8 *e = D_overlay_3_0031A1F8;
    u32 bestDist = (u32)-1;
    s32 bestGroup = 0;
    s32 bestPriority = -1;
    s32 i;

    for (i = 0xF; i != 0; i--, e += 0x10) {
        u8 *grp;
        u8 type;
        s32 s2;
        s16 absAng;
        u32 dist;
        f32 fx, fz, src[3], lis[3];
        s16 ang;

        if (*(s32 *)(e + 0x8) == 0) {
            continue;
        }
        grp = (u8 *)(*(u32 *)(e + 0xC) & ~3u);
        if (grp != NULL && *(s32 *)(grp + 0xA0) != 0) {
            *(s32 *)(e + 0x8) = 0;
            continue;
        }
        type = e[0x7];
        if ((ctl[0x30] == 4 && type == 9) ||
            ((type == 9 || type == 8) && !(*(u32 *)st & 8)) ||
            (ctl[0x32] == 0x11 && type == 1)) {
            continue;
        }

        fx = (f32)*(s16 *)(e + 0x0);
        fz = (f32)*(s16 *)(e + 0x4);
        dist = (u32)GetRangeSquared2D(*(f32 *)(st + 0x68), *(f32 *)(st + 0x70), *(s32 *)&fx, *(s32 *)&fz);

        ang = (s16)Arctanf(*(f32 *)(st + 0x68) - (f32)*(s16 *)(e + 0x0),
                           *(f32 *)(st + 0x70) - (f32)*(s16 *)(e + 0x4));
        ang = mathDiffAngle(ang, *(s16 *)(st + 0x9C), 0, 0);
        absAng = (ang < 0) ? -ang : ang;

        s2 = 0;
        if (e[0x6] & 1) {
            s32 vol = 0x40;
            src[0] = (f32)*(s16 *)(e + 0x0);
            src[1] = (f32)*(s16 *)(e + 0x2);
            src[2] = (f32)*(s16 *)(e + 0x4);
            lis[0] = *(f32 *)(st + 0x68);
            lis[1] = *(f32 *)(st + 0x6C);
            lis[2] = *(f32 *)(st + 0x70);
            if (e[0x9] != 0) {
                vol = amSndGetXYZVolume(e[0x9], src, lis, absAng);
            }
            s2 = (vol >= (s8)ctl[0x21]);
        }
        if (s2 == 0 && (e[0x6] & 4)) {
            u32 r = (u32)(ctl[0x1F] << 6);
            s2 = (dist < r * r);
            if (s2) {
                s2 = (absAng < ctl[0x20] * 0x5B);
            }
        }
        if (s2 == 0 && (e[0x6] & 2)) {
            u32 r = (u32)(ctl[0x22] * 0x10);
            s2 = (dist < r * r);
            if (s2) {
                s2 = (absAng < ctl[0x23] * 0x5B);
            }
        }

        type = e[0x7];
        if (type == 8 || type == 2 || type == 9) {
            dist >>= 2;
        }
        if (s2 != 0 && bestDist >= dist) {
            if (grp != NULL && (s32)grp == bestGroup) {
                if (bestPriority < type) {
                    bestDist = dist;
                    best = e;
                    bestPriority = type;
                }
            } else {
                bestDist = dist;
                best = e;
                bestPriority = type;
                bestGroup = (s32)grp;
            }
        }
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003062A0_1EDB780.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *squadsGetLoudestEvent(void *arg0, f32 *arg1) {
    u8 *st = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *best = NULL;
    u8 *e = D_overlay_3_0031A1F8;
    u32 bestDist = (u32)-1;
    s32 i;

    *arg1 = 0.0f;
    for (i = 0xF; i != 0; i--, e += 0x10) {
        u8 *grp;
        s32 vol;
        u32 dist;
        f32 fx, fz, src[3], lis[3];

        if (*(s32 *)(e + 0x8) == 0) {
            continue;
        }
        grp = (u8 *)(*(u32 *)(e + 0xC) & ~3u);
        if (grp != NULL && *(s32 *)(grp + 0xA0) != 0) {
            *(s32 *)(e + 0x8) = 0;
            continue;
        }
        if (!(e[0x6] & 1)) {
            continue;
        }
        src[0] = (f32)*(s16 *)(e + 0x0);
        src[1] = (f32)*(s16 *)(e + 0x2);
        src[2] = (f32)*(s16 *)(e + 0x4);
        lis[0] = *(f32 *)(st + 0x68);
        lis[1] = *(f32 *)(st + 0x6C);
        lis[2] = *(f32 *)(st + 0x70);
        /* a3 (angle) is not set by the asm before this call; passed as 0 */
        vol = amSndGetXYZVolume(e[0x9], src, lis, 0);
        if (vol < (s8)D_overlay_3_0031A1D8[0x21]) {
            continue;
        }
        fx = (f32)*(s16 *)(e + 0x0);
        fz = (f32)*(s16 *)(e + 0x4);
        dist = (u32)GetRangeSquared2D(*(f32 *)(st + 0x68), *(f32 *)(st + 0x70), *(s32 *)&fx, *(s32 *)&fz);
        if (bestDist >= dist) {
            best = e;
            bestDist = dist;
            *arg1 = (f32)vol;
        }
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsGetLoudestEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003069B0_1EDBE90(void) {
    u8 *obj = D_overlay_3_0031A1CC;
    s32 found = 0;
    u8 *region;
    s32 s2;

    if (squadsPrepareToProcessSquaddie(obj) == 0) {
        return;
    }
    region = GetRegion(*(s8 *)(D_overlay_3_0031A1D8 + 0x7A));

    for (s2 = 6; s2 != 0; s2--) {
        s32 k = s2 - 3;
        s32 absK = (k > 0) ? k : -k;
        s16 yaw = (s16)(*(s16 *)D_overlay_3_0031A1CC + (k << 12));
        f32 scale = (5.0f - (f32)absK) * *(f32 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x24);
        f32 x = *(f32 *)(D_overlay_3_0031A1CC + 0xC) - (Sinf((s32)yaw) * scale);
        f32 z = *(f32 *)(D_overlay_3_0031A1CC + 0x14) - (Cosf((s32)yaw) * scale);

        if (IsPointInRegion(x, z, region) != 0 && IsPointInSibling(x, z) == 0) {
            found = 1;
            break;
        }
    }

    if (GetRangeSquared2D(*(f32 *)(D_overlay_3_0031A1CC + 0xC), *(f32 *)(D_overlay_3_0031A1CC + 0x14),
                          *(s32 *)(D_overlay_3_0031A1D0 + 0x38), *(s32 *)(D_overlay_3_0031A1D0 + 0x40)) < 600.0f) {
        found = 1;
        D_overlay_3_0031A1D0[0x2] &= 0xDF;
    }

    if (found != 0) {
        if (!(*(u32 *)D_overlay_3_0031A1D0 & 0x2000)) {
            for (s2 = 4; s2 != 0; s2--) {
                f32 cx = *(f32 *)(D_overlay_3_0031A1CC + 0xC);
                f32 cz = *(f32 *)(D_overlay_3_0031A1CC + 0x14);
                f32 tx, tz, dist;
                s32 angle;

                if (s2 == 4 && IsPointInRegion(*(f32 *)(D_overlay_3_0031A1E8 + 0xC),
                                               *(f32 *)(D_overlay_3_0031A1E8 + 0x14), region) != 0) {
                    s16 toTarget = (s16)Arctanf(cx - *(f32 *)(D_overlay_3_0031A1E8 + 0xC),
                                                cz - *(f32 *)(D_overlay_3_0031A1E8 + 0x14));
                    angle = mathRnd(-0x1770, 0x1770) + toTarget;
                } else {
                    angle = mathRnd(-0x8000, 0x7FFF);
                }
                dist = (f32)mathRnd(0xC8, 0x3E8);
                tx = cx - (Sinf(angle) * dist);
                tz = cz - (Cosf(angle) * dist);

                if (DoesLineCrossRegion(cx, cz, tx, tz, region, 0, -1, 0xFF) == 0) {
                    *(f32 *)(D_overlay_3_0031A1D0 + 0x38) = tx;
                    *(f32 *)(D_overlay_3_0031A1D0 + 0x40) = tz;
                    D_overlay_3_0031A1D0[0x2] |= 0x20;
                    squadsPrepareToProcessSquaddie(obj);
                    return;
                }
            }
            *(f32 *)(D_overlay_3_0031A1D0 + 0x38) = *(f32 *)(D_overlay_3_0031A1CC + 0xC);
            *(f32 *)(D_overlay_3_0031A1D0 + 0x40) = *(f32 *)(D_overlay_3_0031A1CC + 0x14);
        }
    } else {
        D_overlay_3_0031A1D0[0x2] &= 0xDF;
    }
    squadsPrepareToProcessSquaddie(obj);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003069B0_1EDBE90.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsGetFormationPosition(s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *racer = *(u8 **)(obj + 0x68);
    u8 *member = *(u8 **)(racer + 0x58);
    u8 *mrac = NULL;
    u8 *next;
    s32 sinY = mathSin(*(s16 *)obj) >> 8;
    s32 cosY = mathCos(*(s16 *)obj) >> 8;
    u8 formKind, spacing, subType;
    f32 *out2 = (f32 *)arg2;
    f32 *out3 = (f32 *)arg3;
    f32 *out4 = (f32 *)arg4;
    s32 n;
    s32 cnt;

    GetFormationInfo(arg0, &formKind, &spacing, &subType);

    if (member != NULL) {
        mrac = *(u8 **)(member + 0x68);
    }
    if (member != NULL && (*(u32 *)mrac & 0x10000000) == 0) {
        n = racer[0] - 1;
        cnt = n - 1;
        if (n != 0) {
            for (;;) {
                if (arg1 == mrac[0x15]) {
                    break;
                }
                next = *(u8 **)(mrac + 0x28);
                if (next == NULL) {
                    return;
                }
                member = next;
                mrac = *(u8 **)(member + 0x68);
                cnt--;
                if (cnt == 0) {
                    break;
                }
            }
        }

        /* block_6: member found (or last visited) */
        mrac[3] &= 0x7F;
        if (*(s8 *)(mrac + 0x4B) >= 9) {
            *out2 = *(f32 *)(member + 0xC);
            *out3 = *(f32 *)(member + 0x10);
            *out4 = *(f32 *)(member + 0x14);
            mrac[3] |= 0x80;
            *(f32 *)(D_overlay_3_0031A1CC + 0x1C) = 0.0f;
            *(f32 *)(D_overlay_3_0031A1CC + 0x24) = 0.0f;
            return;
        }

        switch (subType) {
        case 9:
        case 10:
        case 11:
        case 14:
        case 15:
        case 33:
            *out2 = *(f32 *)(member + 0xC);
            *out3 = *(f32 *)(member + 0x10);
            *out4 = *(f32 *)(member + 0x14);
            mrac[3] |= 0x80;
            return;
        case 6:
        case 7:
            *out2 = *(f32 *)(D_overlay_3_0031A1E4 + 0xC);
            *out3 = *(f32 *)(D_overlay_3_0031A1E4 + 0x10);
            *out4 = *(f32 *)(D_overlay_3_0031A1E4 + 0x14);
            return;
        case 8: {
            f32 t;
            t = *(f32 *)(member + 0xC);
            *out2 = t - (*(f32 *)(D_overlay_3_0031A1E4 + 0xC) - t);
            t = *(f32 *)(member + 0x10);
            *out3 = t - (*(f32 *)(D_overlay_3_0031A1E4 + 0x10) - t);
            t = *(f32 *)(member + 0x14);
            *out4 = t - (*(f32 *)(D_overlay_3_0031A1E4 + 0x14) - t);
            if (!(mrac[1] & 0x80)) {
                mrac[1] = (u8)(mrac[1] | 4);
                mrac[1] = (u8)(mrac[1] | 0x80);
                mrac[0x17] = 0;
            }
            return;
        }
        case 13:
            func_overlay_3_003069B0_1EDBE90();
            *out2 = (f32)*(s32 *)(mrac + 0x38);
            *out3 = (f32)*(s32 *)(mrac + 0x3C);
            *out4 = (f32)*(s32 *)(mrac + 0x40);
            return;
        case 16:
            switch (*(u16 *)(racer + 0x2C)) {
            case 0xE1:
                SpiderMover(member, racer);
                break;
            case 0xF2:
                DragonflyMover(member, racer);
                break;
            case 0x112:
                FlopsyDogMover(member, racer);
                break;
            case 0x6D:
                AntShipMover(member, racer);
                break;
            case 0x2CE:
                GalaxianBatsMover(member, racer);
                break;
            }
            *out2 = (f32)*(s32 *)(mrac + 0x38);
            *out3 = (f32)*(s32 *)(mrac + 0x3C);
            *out4 = (f32)*(s32 *)(mrac + 0x40);
            return;
        case 18:
            FloaterMover(member, racer);
            *out2 = (f32)*(s32 *)(mrac + 0x38);
            *out3 = (f32)*(s32 *)(mrac + 0x3C);
            *out4 = (f32)*(s32 *)(mrac + 0x40);
            return;
        case 17:
            SmartMover(member, 0);
            *out2 = (f32)*(s32 *)(mrac + 0x38);
            *out3 = (f32)*(s32 *)(mrac + 0x3C);
            *out4 = (f32)*(s32 *)(mrac + 0x40);
            return;
        }
        return;
    }

    *out2 = 0.0f;
    *out3 = 0.0f;
    *out4 = 0.0f;
    switch (formKind) {
    case 1:
        *out2 = (f32)((s32)(spacing * sinY * arg1) >> 8);
        *out4 = (f32)((s32)(spacing * cosY * arg1) >> 8);
        break;
    case 2: {
        s32 r = (s32)sqrtf((f32)racer[1]);
        if (r != 0) {
            s32 lo = (s32)arg1 / r;
            s32 sgn = (lo & 1) ? 1 : -1;
            s32 lo2 = sgn * ((lo + 1) >> 1);
            s32 hi = (s32)arg1 % r;
            *out2 = (f32)(((s32)(spacing * cosY * lo2) >> 8) + ((s32)(sinY * spacing * hi) >> 7));
            *out4 = (f32)(((s32)(-sinY * spacing * lo2) >> 8) + ((s32)(cosY * spacing * hi) >> 7));
        }
        break;
    }
    case 3: {
        s32 sgn = (arg1 & 1) ? 1 : -1;
        s32 lo = sgn * ((arg1 + 1) >> 1);
        *out2 = (f32)((s32)(spacing * cosY * lo) >> 8);
        *out4 = (f32)((s32)(-sinY * spacing * lo) >> 8);
        break;
    }
    case 4: {
        s32 sgn = (arg1 & 1) ? 1 : -1;
        s32 lo = sgn * ((arg1 + 1) >> 1);
        *out2 = (f32)(((s32)(spacing * cosY * lo) >> 8) + ((s32)(sinY * spacing * arg1) >> 0xA));
        *out4 = (f32)(((s32)(-sinY * spacing * lo) >> 8) + ((s32)(cosY * spacing * arg1) >> 0xA));
        break;
    }
    case 5: {
        s32 a = (0xFFFF / (s32)racer[1]) * arg1;
        *out2 = (f32)(Sinf(a) * (f32)(spacing * 4));
        *out4 = (f32)(Cosf(a) * (f32)(spacing * 4));
        break;
    }
    case 6:
    case 7: {
        s32 n6 = racer[0];
        f32 spd = (f32)(n6 * spacing) / D_overlay_3_00319AA4;
        s32 a;
        if (spd < 80.0f) {
            spd = 80.0f;
        }
        a = (0x10000 / n6) * arg1;
        *out2 = (f32)(Sinf(a) * spd);
        *out4 = (f32)(Cosf(a) * spd);
        break;
    }
    case 10: {
        s32 n10 = racer[0] - 1;
        f32 spd = (f32)(n10 * spacing) / D_overlay_3_00319AA8;
        s32 a;
        if (spd < 80.0f) {
            spd = 80.0f;
        }
        a = (0x10000 / n10) * arg1;
        *out2 = (f32)(Sinf(a) * spd);
        *out4 = (f32)(Cosf(a) * spd);
        break;
    }
    case 8: {
        s32 r = (s32)sqrtf((f32)racer[1]);
        if (r != 0) {
            s32 lo = (s32)arg1 / r;
            s32 sgn = (lo & 1) ? 1 : -1;
            s32 lo2 = sgn * ((lo + 1) >> 1);
            *out2 = (f32)((s32)(spacing * cosY * lo2) >> 8);
            *out3 = (f32)(spacing * ((s32)arg1 % r));
            *out4 = (f32)((s32)(-sinY * spacing * lo2) >> 8);
        }
        break;
    }
    case 9:
        *out3 = (f32)(spacing * arg1);
        break;
    }
    *out2 = *out2 + *(f32 *)(racer + 0x48);
    *out3 = *out3 + *(f32 *)(racer + 0x4C);
    *out4 = *out4 + *(f32 *)(racer + 0x50);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsGetFormationPosition.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 func_overlay_3_00307980_1EDCE60(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 var_f2 = ((arg1 - arg0) * D_overlay_3_00319AAC) - arg2;
    f32 limit = -arg3;

    if (arg3 < var_f2) {
        var_f2 = arg3;
    }
    if (var_f2 < limit) {
        var_f2 = limit;
    }
    return var_f2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00307980_1EDCE60.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 GetSmoothAcceleration(s32 arg0, f32 arg1, f32 arg2) {
    s32 neg = (arg0 < 0);
    s32 dist = arg0;
    f32 vel = arg1;
    f32 sum = 0.0f;
    f32 accel = 0.0f;
    f32 out;

    if (neg) {
        dist = -dist;
        vel = -vel;
    }
    if (vel < 0.0f) {
        return neg ? -arg2 : arg2;
    }
    do {
        accel += arg2;
        sum += accel;
    } while ((sum + accel) < (f32)dist);

    if (((f32)dist <= arg2) && (vel <= arg2) &&
        (((dist >= 0) && (vel >= 0.0f)) || ((dist <= 0) && (vel <= 0.0f)))) {
        out = 0.0f;
    } else {
        f32 t0 = accel - arg2;
        f32 t1 = vel + arg2;
        if (t1 <= t0) {
            out = t1;
        } else {
            f32 t2 = vel - arg2;
            if (t2 < accel) {
                out = t0;
                if (accel == arg2) {
                    out = arg2;
                }
            } else {
                out = t2;
                if (t2 == 0.0f) {
                    out = arg2;
                }
            }
        }
    }
    if (neg) {
        out = -out;
        vel = -vel;
    }
    return out - vel;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetSmoothAcceleration.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_3_00307B38_1EDD018(void *arg0) {
    u8 *racer = *(u8 **)((u8 *)arg0 + 0x68);
    u8 idx = racer[0];
    u8 *member = *(u8 **)(racer + 0x58);
    s32 remaining;

    if (member == NULL) {
        return NULL;
    }
    remaining = idx - 1;
    if (idx != 0) {
        for (;;) {
            u8 *mrac = *(u8 **)(member + 0x68);
            u8 *next;

            if (idx == mrac[0x15]) {
                return member;
            }
            next = *(u8 **)(mrac + 0x28);
            if (next == NULL) {
                return member;
            }
            member = next;
            remaining--;
            if (remaining == 0) {
                return member;
            }
        }
    }
    return member;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00307B38_1EDD018.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *GetLockObject(f32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    switch (arg3) {
    case 1:
        return objGetClosestClass(arg2, 8);
    case 2:
        return GetSquaddieFromIdentifiers((s16)((u8)arg4 + 1), (u8)arg5);
    default:
        return NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetLockObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 GetThrowElevation(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    f32 dx = arg0 - arg3;
    f32 dz = arg2 - arg5;
    f32 horiz = sqrtf((dx * dx) + (dz * dz));
    f32 dy = (arg4 - arg1) - 50.0f;
    f32 b = (dy * arg7) + (arg6 * arg6);
    f32 b2 = b * b;
    f32 dy2 = dy * dy;
    f32 disc = (arg7 * arg7) * ((horiz * horiz) + dy2);
    s16 angles[2];
    s32 count = 0;

    if (disc <= b2) {
        f32 root = sqrtf(b2 - disc);
        f32 a = 2.0f * ((dy2 / (horiz * horiz)) + 1.0f);
        s32 pass;

        for (pass = 1; pass >= 0; pass--) {
            f32 signedRoot = (pass != 0) ? root : -root;
            f32 t = (signedRoot + b) / a;

            if (t >= 0.0f) {
                f32 r = sqrtf(t);
                if (horiz < 0.0f) {
                    r = -r;
                }
                angles[count] = (s16)Arctanf(((dy / horiz) * r) - ((arg7 * horiz) / (2.0f * r)), r);
                count++;
            }
        }
    }

    if (count == 1) {
        return angles[0];
    }
    if (count == 2) {
        if (angles[0] < angles[1]) {
            return (arg8 != 0) ? angles[1] : angles[0];
        }
        return (arg8 != 0) ? angles[0] : angles[1];
    }
    return 0x2000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetThrowElevation.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Enemy squaddie weapon fire. Layout notes:
//   state = D_overlay_3_0031A1D0 (overlay state: +0x5A mask, +0xA8 held projectile,
//           +0xAC player-object list entry, +0xB4 unkB4 object)
//   cfg   = D_overlay_3_0031A1D8 (squaddie data: +0x0F spread, +0x27 counter, +0x2C type)
//   tgt   = D_overlay_3_0031A1E4 (target object: +0x18..+0x24 velocity/position, +0x48 type)
//   ac    = D_overlay_3_0031A1CC (current shot owner / dependant object)
// Spawn parameter blocks are byte buffers at the asm stack offsets (blkNNN = sp NNN).
void squadsFireWeapon(s32 arg0, u32 arg1, s16 arg2) {
    u8 blk180[0x24];   /* sp180: projectile spawn block (case 0/13) */
    u8 blk174[0x0C];   /* sp174: unkB4 creation block */
    u8 blk158[0x1A];   /* sp158: case 18 */
    u8 blk144[0x0A];   /* sp144: case 2 */
    u8 blk128[0x10];   /* sp128: case 4/5 */
    u8 blk110[0x18];   /* sp110: case 6 */
    u8 blkE8[0x28];    /* spE8: case 10 */
    u8 blkC0[0x28];    /* spC0: case 12 */
    u8 blkA8[0x18];    /* spA8: case 14 */
    u8 blk90[0x18];    /* sp90: case 15 */
    u8 blk74[0x1C];    /* sp74: case 19 */
    u8 blk50[0x1C];    /* sp50: case 17 */
    u8 *sp1EC;         /* spawn block handed to the common tail (uninitialised on the default path, as in asm) */
    /* decomp: objSetupObject is called with 2 args (romdef, flags); the header prototype takes 3 */
    void *(*objSetup2)(void *, s32) = (void *(*)(void *, s32))objSetupObject;
    u8 *state;
    u8 *cfg;
    u8 *tgt;
    u8 *ac;
    u8 *obj;
    u8 *st;
    u8 *ftbl;
    u8 *slotp;
    s32 *handle;
    u8 *old;
    u8 *p;
    f32 ox, oy, oz;      /* shooter position (sp1DC, sp1D8, sp1D4) */
    f32 tx, ty, tz;      /* target position (sp1BC, sp1B8, sp1B4) */
    f32 dx, dy, dz;      /* sp1D0, sp1CC, sp1C8 */
    f32 dist, speed, lead;
    s16 spread;          /* sp1E6 */
    s16 aim_yaw;         /* sp1E4 */
    s16 aim_pitch;       /* sp1E2 */
    s16 elev;
    s16 ix, iy, iz;      /* integer shooter position (sp184.. / sp148..) */
    u16 type;
    u16 snd;             /* sp1C2 */
    s32 slot_idx;        /* var_v0 */

    state = D_overlay_3_0031A1D0;
    cfg = D_overlay_3_0031A1D8;
    tgt = D_overlay_3_0031A1E4;
    ac = D_overlay_3_0031A1CC;

    spread = (s16)(cfg[0x0F] * 0x10);
    if (tgt == NULL) {
        return;
    }

    /* target position: tgt->68->68.. for type 0x8D with tgt->48 == 0x18, else tgt->4C->18.. */
    type = *(u16 *)(cfg + 0x2C);
    if (type == 0x8D && *(s16 *)(tgt + 0x48) == 0x18) {
        p = *(u8 **)(tgt + 0x68);
        tx = *(f32 *)(p + 0x68);
        ty = *(f32 *)(p + 0x6C);
        tz = *(f32 *)(p + 0x70);
    } else {
        p = *(u8 **)(tgt + 0x4C);
        tx = *(f32 *)(p + 0x18);
        ty = *(f32 *)(p + 0x1C);
        tz = *(f32 *)(p + 0x20);
    }

    ftbl = NULL;
    if (type == 0x67) {
        ftbl = D_overlay_3_003197F0;
    }
    if (ftbl != NULL && ((1 << ftbl[arg0]) & *(u16 *)(state + 0x5A))) {
        return;
    }

    squadsGetChildPolyPosition(arg0, &ox, &oy, &oz);
    dist = GetRange(ox, oy, oz, tx, ty, tz);

    /* lead speed, per weapon type (arg1) */
    switch (arg1) {
    case 0:
        speed = 35.0f;
        break;
    case 13:
        speed = 70.0f;
        break;
    case 1:
        speed = dist / 60.0f;
        if (speed < 4.0f) {
            speed = 4.0f;
        }
        if (speed > 12.0f) {
            speed = 12.0f;
        }
        break;
    case 6:
        speed = dist / 90.0f;
        if (speed < 3.0f) {
            speed = 3.0f;
        }
        if (speed > 5.0f) {
            speed = 5.0f;
        }
        break;
    case 12:
        speed = 10.0f;
        break;
    case 14:
        speed = 60.0f;
        break;
    case 15:
        speed = 40.0f;
        break;
    case 16:
    case 17:
        speed = dist / 60.0f;
        if (speed < 9.0f) {
            speed = 9.0f;
        }
        if (speed > 12.0f) {
            speed = 12.0f;
        }
        break;
    default:
        speed = 0.0f;
        break;
    }

    if (speed != 0.0f) {
        lead = dist / (speed * D_overlay_3_0031A1C8);
        tx += lead * *(f32 *)(tgt + 0x1C);
        ty += lead * *(f32 *)(tgt + 0x20);
        tz += lead * *(f32 *)(tgt + 0x24);
    }

    dx = tx - ox;
    dz = tz - oz;
    dy = (ty - oy) + (f32)arg2;

    aim_yaw = (s16)(Arctanf(dx, dz) + 0x8000);
    aim_yaw = (s16)(aim_yaw + mathRnd(-spread, spread));
    aim_pitch = (s16)mathRnd((-spread) >> 1, spread >> 1);

    ix = (s16)(s32)ox;
    iy = (s16)(s32)oy;
    iz = (s16)(s32)oz;

    /* projectile spawn type table (arg1 switch 2) */
    switch (arg1) {
    case 0:
    case 13:
        /* asm: sp180 spawn, then the common sound/unkB4 setup */
        sp1EC = blk180;
        *(s16 *)(blk180 + 0x00) = 0x50;
        blk180[0x02] = 0x24;
        blk180[0x03] = 0;
        *(s16 *)(blk180 + 0x04) = ix;
        *(s16 *)(blk180 + 0x06) = iy;
        *(s16 *)(blk180 + 0x08) = iz;
        blk180[0x0A] = (u8)(cfg[0x27] + 1);
        blk180[0x0B] = 0x3C;
        *(s16 *)(blk180 + 0x0C) = aim_yaw;
        *(s16 *)(blk180 + 0x0E) = (s16)(Arctanf(dy, sqrtf((dx * dx) + (dz * dz))) + aim_pitch);
        blk180[0x10] = 0;
        blk180[0x11] = 0;
        blk180[0x12] = 0x64;
        blk180[0x13] = 0xFF;
        *(f32 *)(blk180 + 0x14) = speed;
        *(u8 **)(blk180 + 0x18) = ac;
        *(s32 *)(blk180 + 0x1C) = 0;
        *(s32 *)(blk180 + 0x20) = 0;

        /* sound type: snd / slot from the target type (asm lines 363-471) */
        switch (type) {
        case 0x2D:
        case 0x12F:
        case 0x150:
        case 0x151:
        case 0x152:
        case 0x1E5:
            snd = 0xC5;
            slot_idx = 1;
            break;
        case 0x99:
        case 0x9C:
        case 0xBD:
        case 0xEE:
        case 0xEF:
        case 0xF5:
        case 0xF6:
        case 0x122:
        case 0x269:
            snd = 0x115;
            slot_idx = 2;
            break;
        case 0x54:
        case 0x5F:
        case 0x6D:
        case 0x8C:
            snd = 0x1D7;
            slot_idx = 2;
            break;
        case 0x29:
        case 0x2A:
        case 0x83:
        case 0x8D:
        case 0xDF:
        case 0xF2:
        case 0x153:
        case 0x166:
        case 0xBE:
        case 0x2CE:
            snd = 0xC4;
            slot_idx = 0;
            break;
        default:
            snd = 0xC;
            slot_idx = 3;
            break;
        }

        slotp = (u8 *)&D_overlay_3_00319448 + slot_idx;
        if (*slotp == 0) {
            handle = &D_overlay_3_00319438[slot_idx];
            if (*handle != 0) {
                amSndStopXYZ(*handle);
            }
            amSndPlayXYZ(snd, (f32)ix, (f32)iy, (f32)iz, 4, handle);
            *slotp = 1;
        }

        if (*(u8 **)(state + 0xB4) == NULL) {
            *(s16 *)(blk174 + 0x00) = 0xAC;
            blk174[0x02] = 0x0C;
            blk174[0x03] = 0;
            *(s16 *)(blk174 + 0x04) = 0;
            *(s16 *)(blk174 + 0x06) = 0;
            *(s16 *)(blk174 + 0x08) = 0;
            blk174[0x0A] = (u8)arg0;
            blk174[0x0B] = 0;
            *(u8 **)(state + 0xB4) = (u8 *)objSetup2(blk174, 1);
            obj = *(u8 **)(state + 0xB4);
            *(u8 **)(obj + 0x88) = ac;
            *(s32 *)(obj + 0x3C) = 0;
            *(f32 *)(obj + 0x0C) = *(f32 *)(ac + 0x0C);
            *(f32 *)(obj + 0x10) = *(f32 *)(ac + 0x10);
            *(f32 *)(obj + 0x14) = *(f32 *)(ac + 0x14);
            *(s16 *)(obj + 0x2E) = *(s16 *)(ac + 0x2E);
        }
        goto tail;

    case 18:
        if (FreeRAM >= 0xC000) {
            sp1EC = blk158;
            *(s16 *)(blk158 + 0x00) = 0x72;
            blk158[0x02] = 0x1C;
            blk158[0x03] = 0;
            *(s16 *)(blk158 + 0x04) = ix;
            *(s16 *)(blk158 + 0x06) = iy;
            *(s16 *)(blk158 + 0x08) = iz;
            blk158[0x0A] = (u8)(cfg[0x27] + 0x0A);
            blk158[0x0B] = 0x1E;
            *(s16 *)(blk158 + 0x0C) = 0;
            *(s16 *)(blk158 + 0x0E) = 0;
            *(f32 *)(blk158 + 0x10) = 0.0f;
            *(u8 **)(blk158 + 0x14) = ac;
            blk158[0x18] = 1;
            blk158[0x19] = (u8)arg0;
            goto tail;
        }
        break;

    case 1:
        st = *(u8 **)(state + 0xA8);
        if (st != NULL) {
            p = *(u8 **)(st + 0x68);
            p[0x0D] = 0;
            *(f32 *)(st + 0x1C) = 0.0f;
            *(f32 *)(st + 0x20) = 0.0f;
            *(f32 *)(st + 0x24) = -speed;
            *(s16 *)(st + 0x00) = aim_yaw;
            *(s16 *)(st + 0x02) = GetThrowElevation(ox, oy, oz, tx, ty, tz, speed, D_overlay_3_00319D28, 0);
            *(s16 *)(st + 0x04) = (s16)mathRnd(0, 0xFFFF);
            mathOneFloatPY(st, (f32 *)(st + 0x1C));
            amSndPlayXYZ(0x2F, *(f32 *)(st + 0x0C), *(f32 *)(st + 0x10), *(f32 *)(st + 0x14), 4, NULL);
        }
        break;

    case 2:
        *(s32 *)(ac + 0x84) = *(s32 *)(ac + 0x84) | (arg0 + 4);
        *(s16 *)(blk144 + 0x00) = 0x15;
        blk144[0x02] = 0x0A;
        blk144[0x03] = 0;
        *(s16 *)(blk144 + 0x04) = ix;
        *(s16 *)(blk144 + 0x06) = iy;
        *(s16 *)(blk144 + 0x08) = iz;
        obj = (u8 *)objSetup2(blk144, 1);
        if (obj != NULL) {
            *(s32 *)(obj + 0x3C) = 0;
            *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) | 0x400);
            *(u8 **)(*(u8 **)(obj + 0x68)) = ac;
            old = *(u8 **)(state + 0xA8);
            if (old != NULL) {
                objFreeObject(old);
            }
            *(u8 **)(state + 0xA8) = obj;
            /* decomp: file prototype is unprototyped; call through the real signature so the floats stay f32 */
            ((void (*)(void *, s16, s8, s8, s16, s16, s16, f32, f32, f32, f32, u16))hitInitObjectHit)(
                obj, 4, 1, 4, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 0x11);
        }
        break;

    case 3:
        old = *(u8 **)(state + 0xA8);
        if (old != NULL) {
            objFreeObject(old);
            *(u8 **)(state + 0xA8) = NULL;
        }
        *(s32 *)(ac + 0x84) = *(s32 *)(ac + 0x84) & ~(arg0 + 4);
        break;

    case 5:
        if (*(u8 *)(*(u8 **)(state + 0xA8)) == 0) {
            break;
        }
        goto case4;

    case 4:
    case4:
        /* asm: sp128 spawn with sound 0x20F, then the common tail */
        sp1EC = blk128;
        *(s16 *)(blk128 + 0x00) = 0x38;
        blk128[0x02] = 0x10;
        blk128[0x03] = 0;
        *(s16 *)(blk128 + 0x04) = ix;
        *(s16 *)(blk128 + 0x06) = iy;
        *(s16 *)(blk128 + 0x08) = iz;
        *(u8 **)(blk128 + 0x0C) = ac;
        amSndPlayXYZ(0x20F, (f32)ix, (f32)iy, (f32)iz, 4, NULL);
        goto tail;

    case 6:
        elev = GetThrowElevation(ox, oy, oz, tx, ty, tz, speed, D_overlay_3_00319D2C, 0);
        sp1EC = blk110;
        *(s16 *)(blk110 + 0x00) = 0xE2;
        blk110[0x02] = 0x18;
        blk110[0x03] = 0;
        *(s16 *)(blk110 + 0x04) = ix;
        *(s16 *)(blk110 + 0x06) = iy;
        *(s16 *)(blk110 + 0x08) = iz;
        blk110[0x0A] = (u8)(cfg[0x27] + 1);
        blk110[0x0B] = 0x1E;
        *(s16 *)(blk110 + 0x0C) = aim_yaw;
        *(s16 *)(blk110 + 0x0E) = elev;
        *(f32 *)(blk110 + 0x10) = speed;
        *(u8 **)(blk110 + 0x14) = ac;
        amSndPlayXYZ(0x2F, (f32)ix, (f32)iy, (f32)iz, 4, NULL);
        goto tail;

    case 10:
        if (FreeRAM >= 0xC000 && *(u8 **)(state + 0xAC) == NULL) {
            sp1EC = blkE8;
            *(s16 *)(blkE8 + 0x00) = 0xF4;
            blkE8[0x02] = 0x28;
            blkE8[0x03] = 0;
            *(s16 *)(blkE8 + 0x04) = ix;
            *(s16 *)(blkE8 + 0x06) = iy;
            *(s16 *)(blkE8 + 0x08) = iz;
            *(f32 *)(blkE8 + 0x0C) = tx;
            *(f32 *)(blkE8 + 0x10) = ty;
            *(f32 *)(blkE8 + 0x14) = tz;
            blkE8[0x18] = (u8)(cfg[0x27] + 1);
            *(u8 **)(blkE8 + 0x1C) = ac;
            *(s32 *)(blkE8 + 0x20) = 0;
            *(s32 *)(blkE8 + 0x24) = 0;
            obj = (u8 *)objSetup2(blkE8, 1);
            if (obj != NULL) {
                *(s32 *)(obj + 0x3C) = 0;
                *(u8 **)(state + 0xAC) = obj;
            }
        }
        break;

    case 12:
        if (FreeRAM >= 0xC000) {
            sp1EC = blkC0;
            *(s16 *)(blkC0 + 0x00) = 0xA4;
            blkC0[0x02] = 0x28;
            blkC0[0x03] = 0;
            *(s16 *)(blkC0 + 0x04) = ix;
            *(s16 *)(blkC0 + 0x06) = iy;
            *(s16 *)(blkC0 + 0x08) = iz;
            blkC0[0x0A] = (u8)(cfg[0x27] + 1);
            blkC0[0x0B] = 0x64;
            *(f32 *)(blkC0 + 0x0C) = speed;
            *(u8 **)(blkC0 + 0x10) = ac;
            *(u8 **)(blkC0 + 0x14) = tgt;
            *(s16 *)(blkC0 + 0x20) = 0;
            blkC0[0x24] = 1;
            blkC0[0x25] = 0xFF;
            blkC0[0x26] = 1;
            *(s16 *)(blkC0 + 0x1E) = *(s16 *)(ac + 0x00);
            *(s16 *)(blkC0 + 0x1E) = *(s16 *)(ac + 0x00);
            amSndPlayXYZ(0x95, (f32)ix, (f32)iy, (f32)iz, 4, NULL);
            goto tail;
        }
        break;

    case 14:
        if (FreeRAM >= 0xC000) {
            sp1EC = blkA8;
            *(s16 *)(blkA8 + 0x00) = 0x233;
            blkA8[0x02] = 0x18;
            blkA8[0x03] = 0;
            *(s16 *)(blkA8 + 0x04) = ix;
            *(s16 *)(blkA8 + 0x06) = iy;
            *(s16 *)(blkA8 + 0x08) = iz;
            *(s16 *)(blkA8 + 0x0C) = (s16)(s32)((tx - ox) / 10.0f);
            *(s16 *)(blkA8 + 0x0E) = (s16)(s32)((ty - oy) / 10.0f);
            *(s16 *)(blkA8 + 0x10) = (s16)(s32)((tz - oz) / 10.0f);
            blkA8[0x0A] = (u8)(cfg[0x27] + 1);
            blkA8[0x0B] = 0x64;
            *(u8 **)(blkA8 + 0x14) = ac;
            amSndPlayXYZ(0x95, (f32)ix, (f32)iy, (f32)iz, 4, NULL);
            func_overlay_3_003040FC_1ED95DC((s16 *)(blkA8 + 0x0C), (s16 *)(blkA8 + 0x0E), (s16 *)(blkA8 + 0x10), 60.0f);
            goto tail;
        }
        break;

    case 15:
        if (FreeRAM >= 0xC000) {
            sp1EC = blk90;
            *(s16 *)(blk90 + 0x00) = 0x234;
            blk90[0x02] = 0x18;
            blk90[0x03] = 0;
            *(s16 *)(blk90 + 0x04) = ix;
            *(s16 *)(blk90 + 0x06) = iy;
            *(s16 *)(blk90 + 0x08) = iz;
            *(s16 *)(blk90 + 0x0C) = (s16)(s32)((tx - ox) / 10.0f);
            *(s16 *)(blk90 + 0x0E) = (s16)(s32)((ty - oy) / 10.0f);
            *(s16 *)(blk90 + 0x10) = (s16)(s32)((tz - oz) / 10.0f);
            blk90[0x0A] = (u8)(cfg[0x27] + 1);
            blk90[0x0B] = 0x64;
            *(u8 **)(blk90 + 0x14) = ac;
            amSndPlayXYZ(0x95, (f32)ix, (f32)iy, (f32)iz, 4, NULL);
            func_overlay_3_003040FC_1ED95DC((s16 *)(blk90 + 0x0C), (s16 *)(blk90 + 0x0E), (s16 *)(blk90 + 0x10), 40.0f);
            goto tail;
        }
        break;

    case 19:
        if (FreeRAM >= 0xC000) {
            sp1EC = blk74;
            *(s16 *)(blk74 + 0x00) = 0x235;
            blk74[0x02] = 0x1C;
            blk74[0x03] = 0;
            *(s16 *)(blk74 + 0x04) = ix;
            *(s16 *)(blk74 + 0x06) = iy;
            *(s16 *)(blk74 + 0x08) = iz;
            blk74[0x0A] = (u8)(cfg[0x27] + 0x0A);
            blk74[0x0B] = 0x1E;
            *(s16 *)(blk74 + 0x0C) = 0;
            *(s16 *)(blk74 + 0x0E) = 0;
            *(f32 *)(blk74 + 0x10) = 0.0f;
            *(u8 **)(blk74 + 0x14) = ac;
            blk74[0x18] = (u8)arg0;
            goto tail;
        }
        break;

    case 16:
        st = *(u8 **)(state + 0xA8);
        if (st != NULL) {
            p = *(u8 **)(st + 0x68);
            p[0x0C] = 0;
            *(f32 *)(st + 0x1C) = 0.0f;
            *(f32 *)(st + 0x20) = 0.0f;
            *(f32 *)(st + 0x24) = -speed;
            *(s16 *)(st + 0x00) = aim_yaw;
            *(s16 *)(st + 0x02) = GetThrowElevation(ox, oy, oz, tx, ty, tz, speed, D_overlay_3_00319D30, 0);
            *(s16 *)(st + 0x04) = (s16)mathRnd(0, 0xFFFF);
            mathOneFloatPY(st, (f32 *)(st + 0x1C));
            amSndPlayXYZ(0x2F, *(f32 *)(st + 0x0C), *(f32 *)(st + 0x10), *(f32 *)(st + 0x14), 4, NULL);
        }
        break;

    case 17:
        if (FreeRAM >= 0xC000) {
            *(s16 *)(blk50 + 0x00) = (arg1 == 0x10) ? 0x235 : 0x236;
            blk50[0x02] = 0x1C;
            blk50[0x03] = 0;
            *(s16 *)(blk50 + 0x04) = ix;
            *(s16 *)(blk50 + 0x06) = iy;
            *(s16 *)(blk50 + 0x08) = iz;
            blk50[0x0A] = (u8)(cfg[0x27] + 1);
            blk50[0x0B] = 0x1E;
            *(s16 *)(blk50 + 0x0C) = aim_yaw;
            elev = GetThrowElevation(ox, oy, oz, tx, ty + 20.0f, tz, speed, D_overlay_3_00319D34, 0);
            *(s16 *)(blk50 + 0x0E) = elev;
            *(f32 *)(blk50 + 0x10) = speed;
            *(u8 **)(blk50 + 0x14) = ac;
            blk50[0x18] = (u8)arg0;
            amSndPlayXYZ(0x2F, (f32)ix, (f32)iy, (f32)iz, 4, NULL);
            obj = (u8 *)objSetup2(blk50, 1);
            if (obj != NULL) {
                *(s32 *)(obj + 0x3C) = 0;
                p = *(u8 **)(obj + 0x68);
                p[0x0C] = 0;
                *(f32 *)(obj + 0x1C) = 0.0f;
                *(f32 *)(obj + 0x20) = 0.0f;
                *(f32 *)(obj + 0x24) = -speed;
                *(s16 *)(obj + 0x00) = aim_yaw;
                *(s16 *)(obj + 0x02) = GetThrowElevation(ox, oy, oz, tx, ty, tz, speed, D_overlay_3_00319D38, 0);
                *(s16 *)(obj + 0x04) = (s16)mathRnd(0, 0xFFFF);
                mathOneFloatPY(obj, (f32 *)(obj + 0x1C));
            }
        }
        break;

    default:
        /* asm: jump-table default (arg1 7, 8, 9, 11 and >= 0x14) goes to the common tail
         * with sp1EC never written on this path */
        goto tail;
    }
    return;

tail:
    /* common spawn tail: objSetupObject(sp1EC, 1), then dependency for 0x9B/0xA1 */
    obj = (u8 *)objSetup2(sp1EC, 1);
    if (obj != NULL) {
        *(s32 *)(obj + 0x3C) = 0;
        if (*(s16 *)(obj + 0x48) == 0x9B || *(s16 *)(obj + 0x48) == 0xA1) {
            *(u8 **)(state + 0xA8) = obj;
            objRegisterDependancy(obj, ac);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsFireWeapon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00309680_1EDEB60(void) {
    u8 *state = D_overlay_3_0031A1D0;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *anim = GetAnimData(D_overlay_3_0031A1CC);
    s16 fp = 0;
    s32 i = 3;
    u32 idx = 0;
    u32 typeIdx;

    if (!(*(u32 *)state & 0x100000) && (cfg[0x28] & 0x80)) {
        fp = 0x28;
        state[0x1] |= 0x10;
    }
    typeIdx = (*(u32 *)(anim + 0x4) << 10) >> 25;
    if (typeIdx != 0x7F) {
        do {
            u32 src = *(u32 *)(state + 0x4);

            switch (i) {
            case 0:
                idx = src >> 29;
                break;
            case 1:
                idx = (src * 8) >> 29;
                break;
            case 2:
                idx = (src << 6) >> 29;
                break;
            case 3:
                idx = (src << 9) >> 29;
                break;
            }
            if (idx != 7) {
                u8 *e = D_overlay_3_00317A10 + typeIdx * 0x18 + idx;
                squadsFireWeapon(*(s32 *)(e + 0x10), *(u32 *)(e + 0x14), fp);
            }
            i -= 1;
        } while (i != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00309680_1EDEB60.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00309840_1EDED20(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 temp = obj[0x75];

    *(s32 *)(obj + 0x30) = 7;
    if (temp != 0 && !(*(u16 *)(obj + 0x28) & 8)) {
        doorUnlock(temp, arg1 & 0xFFFF, obj);
        *(u16 *)(obj + 0x28) = (u16)(*(u16 *)(obj + 0x28) | 8);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00309840_1EDED20.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void TidyLinkedList(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *parent;
    u8 *a2;
    u8 *cur;
    u8 t3;
    u8 c;
    s32 n;

    if (!(*(u32 *)d & 0x4000)) {
        parent = *(u8 **)(d + 0x24);
        if (parent != NULL) {
            a2 = *(u8 **)(parent + 0x68);
            t3 = (u8)(a2[0] - 1);
            a2[0] = t3;
            if (t3 == 0 && a2[1] == a2[0x63]) {
                if ((*(u16 *)(a2 + 0x28) & 4) || *(s32 *)(a2 + 0x30) == 9) {
                    *(s32 *)(a2 + 0x30) = 5;
                    *(s16 *)(a2 + 0x2E) = 0x3C;
                    a2[0x63] = 0;
                } else {
                    func_overlay_3_00309840_1EDED20(a2, 0x10);
                }
            }
            if (*(u16 *)(a2 + 0x28) & 1) {
                u8 *x = (u8 *)func_overlay_3_00307B38_1EDD018(parent);
                u8 *xd = *(u8 **)(x + 0x68);
                xd[0x15] = d[0x15];
            }
            cur = *(u8 **)(a2 + 0x58);
            if (cur == obj) {
                *(u8 **)(a2 + 0x58) = *(u8 **)(d + 0x28);
            } else {
                c = a2[0];
                n = (s32)c - 1;
                if (c != 0) {
                    do {
                        u8 *td = *(u8 **)(cur + 0x68);
                        cur = *(u8 **)(td + 0x28);
                        if (cur == obj) {
                            *(u8 **)(td + 0x28) = *(u8 **)(d + 0x28);
                            break;
                        }
                        n -= 1;
                    } while (n != 0);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/TidyLinkedList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void RemoveSquaddie(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *parent;
    u8 *pd;
    s32 start;
    s32 end;
    s32 nSq;
    s32 sndHandle;
    s32 i;
    void **list;
    void **squads;

    list = objGetObjList(&start, &end);
    squads = squadsGetSquadronList(&nSq);

    d[0x7] = (u8)(d[0x7] | 0x80);
    parent = *(u8 **)(d + 0x24);
    if (parent != NULL) {
        pd = *(u8 **)(parent + 0x68);
        if (pd[0] == 1 && pd[1] == pd[0x63]) {
            if (pd[0x77] != 0xFF) {
                mmFree(PathLists[pd[0x77]]);
                PathLists[pd[0x77]] = NULL;
            }
            pd[0x77] = 0xFF;
        }
    }

    sndHandle = *(s32 *)(d + 0xBC);
    if (sndHandle != 0) {
        amSndUnlinkHandleXYZ(sndHandle);
    }

    for (i = start; i < end; i++) {
        u8 *o = (u8 *)list[i];

        if (o[0x48] == 0x18) {
            u8 *od = *(u8 **)(o + 0x68);

            if (arg0 == *(void **)(od + 0x64)) {
                *(void **)(od + 0x64) = NULL;
            }
        }
    }

    if (nSq != 0) {
        s32 k = nSq - 1;
        void **pp = &squads[k];

        do {
            u8 *sq = (u8 *)*pp;
            u8 *sd = *(u8 **)(sq + 0x68);
            u8 *cur2;

            pp -= 1;
            if (arg0 == *(void **)(sd + 0x54)) {
                cur2 = *(u8 **)(sd + 0x58);
                *(void **)(sd + 0x54) = NULL;
                sd[0x33] = 0;
                while (cur2 != NULL) {
                    u8 *td = *(u8 **)(cur2 + 0x68);
                    u8 t1 = td[0x2];

                    cur2 = *(u8 **)(td + 0x28);
                    td[0x2] = (u8)(t1 & 0xFD);
                }
            }
            k -= 1;
        } while (k != 0);
    }
    objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/RemoveSquaddie.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *func_overlay_3_00309CE4_1EDF1C4(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *cfg;
    u8 *ent;
    u8 *ret;
    f32 *pf;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 f20;
    s32 fp = 0xFF;
    s32 s0;
    s32 k;
    s32 idx;

    ret = hitGetInelasticVelocity(*(s32 *)(*(u8 **)(obj + 0x4C) + 0x3C), &vx, &vy, &vz);
    if (d[0x55] == 0) {
        pf = *(f32 **)(obj + 0x54);
        if (pf != NULL) {
            fp = (s32)(*pf * 255.0f);
        }
        f20 = D_overlay_3_00319D3C;
        for (s0 = 0x1F; s0 != 0; s0 -= 1) {
            s32 rx = mathRnd(-0x14, 0x14);
            s32 ry = mathRnd(-0x14, 0x14);
            s32 rz = mathRnd(-0x14, 0x14);
            s32 rvx = mathRnd(-0x1F4, 0x1F4);
            s32 rvy = mathRnd(0, 0x1F4);
            s32 rvz = mathRnd(-0x1F4, 0x1F4);

            bloodSpurtAdd((f32)rx + *(f32 *)(obj + 0xC), (f32)ry + *(f32 *)(obj + 0x10),
                          (f32)rz + *(f32 *)(obj + 0x14), (f32)rvx * f20, (f32)rvy * f20,
                          (f32)rvz * f20, fp, (s32)(*(u8 **)(obj + 0x40))[0x2F], 1.0f);
        }

        cfg = D_overlay_3_0031A1E0;
        ret = cfg;
        if ((s32)cfg[0x29] > 0) {
            k = 0;
            idx = 0;
            ent = cfg;
            do {
                u16 a1 = *(u16 *)(d + 0x5A);
                s32 t5 = (1 << ent[0x40]) & 0xFFFF;
                u8 *sub = ent + 0x40;

                if (!(a1 & t5)) {
                    *(u16 *)(d + 0x5A) = (u16)(a1 | t5);
                    if (FreeRAM >= 0xC001) {
                        s32 params[5];
                        u8 *p = (u8 *)params;
                        u8 *spawned;

                        *(s16 *)(p + 0x0) = 0x89;
                        p[0x2] = 0x14;
                        p[0x3] = 0;
                        *(s16 *)(p + 0x4) = 0;
                        *(s16 *)(p + 0x6) = 0;
                        *(s16 *)(p + 0x8) = 0;
                        *(u8 **)(p + 0xC) = D_overlay_3_0031A1CC;
                        p[0x10] = sub[0x4];
                        p[0x11] = sub[0x5];
                        p[0x12] = sub[0x2];

                        /* a2 not recovered from the asm draft, passing NULL */
                        spawned = (u8 *)objSetupObject(p, 1, NULL);
                        if (spawned != NULL) {
                            *(f32 *)(spawned + 0x1C) = *(f32 *)(spawned + 0x1C) + vx;
                            *(f32 *)(spawned + 0x20) = *(f32 *)(spawned + 0x20) + vy;
                            *(f32 *)(spawned + 0x24) = *(f32 *)(spawned + 0x24) + vz;
                        }
                    }
                }
                k += 1;
                idx += 8;
                ent = cfg + idx;
            } while (k < (s32)cfg[0x29]);
            ret = ent;
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00309CE4_1EDF1C4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsKillSquaddie(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *d = D_overlay_3_0031A1D8;

    if (d[0] == 1 && d[1] == d[0x63]) {
        objCreateBonusItem(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10) + 10.0f,
                           *(f32 *)(obj + 0x14), d[0x7B]);
    }
    if (*(u16 *)(d + 0x2C) == 0x2CE) {
        u8 *p = *(u8 **)(D_overlay_3_0031A1CC + 0x4C);

        explosionStart(0x10, (s16)(s32)*(f32 *)(p + 0x18), (s16)(s32)*(f32 *)(p + 0x1C),
                       (s16)(s32)*(f32 *)(p + 0x20), 0x64, 0);
    }
    RemoveSquaddie(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsKillSquaddie.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void AIPointControl(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *st = D_overlay_3_0031A1D0;
    void **sq;
    s32 n;

    sq = squadsGetSquadronList(&n);
    n -= 1;
    if (n != 0) {
        do {
            u8 typ = d[1];
            u8 *sqd = *(u8 **)((u8 *)sq[n] + 0x68);

            if (typ == 0xFF || sqd[0x64] == typ) {
                switch (d[0]) {
                case 3: {
                    u8 *s0 = *(u8 **)(sqd + 0x58);

                    while (s0 != NULL) {
                        u8 *s3 = *(u8 **)(s0 + 0x68);
                        /* sig mismatch: asm passes 5 args, 5th is stack arg 0x10 (not recovered) */
                        f32 r = ((f32 (*)(f32, f32, f32, f32, f32))GetRange2D)(
                            *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14),
                            *(f32 *)(s0 + 0xC), *(f32 *)(s0 + 0x14), 0.0f);
                        f32 dy = *(f32 *)(obj + 0x10) - *(f32 *)(s0 + 0x10);

                        if (dy < 0.0f) {
                            dy = -dy;
                        }
                        if (r < (f32)(d[3] * 8) && dy < (f32)(d[4] * 4) &&
                            squadsPrepareToProcessSquaddie(s0) != 0 &&
                            !(*(u32 *)st & 0x04000000)) {
                            if (!(st[0x1A] == 0xD &&
                                  *(f32 *)(obj + 0xC) == *(f32 *)(st + 0x38) &&
                                  *(f32 *)(obj + 0x10) == *(f32 *)(st + 0x3C) &&
                                  *(f32 *)(obj + 0x14) == *(f32 *)(st + 0x40))) {
                                if (TryToSetMission(0xB, 0xD, 0U, 0U, 0U) != 0) {
                                    *(f32 *)(st + 0x38) = *(f32 *)(obj + 0xC);
                                    *(f32 *)(st + 0x3C) = *(f32 *)(obj + 0x10);
                                    *(f32 *)(st + 0x40) = *(f32 *)(obj + 0x14);
                                }
                            }
                        }
                        s0 = *(u8 **)(s3 + 0x28);
                    }
                    break;
                }
                case 4: {
                    u8 *s0 = *(u8 **)(sqd + 0x58);

                    while (s0 != NULL) {
                        u8 *s3 = *(u8 **)(s0 + 0x68);
                        /* sig mismatch: asm passes 5 args, 5th is stack arg 0x10 (not recovered) */
                        f32 r = ((f32 (*)(f32, f32, f32, f32, f32))GetRange2D)(
                            *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14),
                            *(f32 *)(s0 + 0xC), *(f32 *)(s0 + 0x14), 0.0f);
                        f32 dy = *(f32 *)(obj + 0x10) - *(f32 *)(s0 + 0x10);

                        if (dy < 0.0f) {
                            dy = -dy;
                        }
                        if (r < (f32)(d[3] * 8) && dy < (f32)(d[4] * 4) &&
                            squadsPrepareToProcessSquaddie(s0) != 0 && st[0x1A] != 0x13) {
                            TryToSetMission(2, 0x13, d[8], d[9], (u8)d[0xA]);
                        }
                        s0 = *(u8 **)(s3 + 0x28);
                    }
                    break;
                }
                case 2: {
                    u8 *s0 = *(u8 **)(sqd + 0x58);

                    while (s0 != NULL) {
                        u8 *s3 = *(u8 **)(s0 + 0x68);
                        /* sig mismatch: asm passes 5 args, 5th is stack arg 0x10 (not recovered) */
                        f32 r = ((f32 (*)(f32, f32, f32, f32, f32))GetRange2D)(
                            *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14),
                            *(f32 *)(s0 + 0xC), *(f32 *)(s0 + 0x14), 0.0f);
                        f32 dy = *(f32 *)(obj + 0x10) - *(f32 *)(s0 + 0x10);

                        if (dy < 0.0f) {
                            dy = -dy;
                        }
                        if (r < (f32)(d[3] * 8) && dy < (f32)(d[4] * 4) &&
                            squadsPrepareToProcessSquaddie(s0) != 0) {
                            RemoveSquaddie(s0);
                        }
                        s0 = *(u8 **)(s3 + 0x28);
                    }
                    break;
                }
                }
            }
            n -= 1;
        } while (n != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/AIPointControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030A564_1EDFA44(void *arg2, void *arg3) {
    s16 temp = mathDiffAngle(*(s16 *)D_overlay_3_0031A1CC, D_overlay_3_0031A1F6, arg2, arg3);
    s16 v = temp;

    if (temp < -0x3E8) {
        v = -0x3E8;
    } else if (temp >= 0x3E9) {
        v = 0x3E8;
    }
    *(s16 *)D_overlay_3_0031A1CC = (s16)(*(s16 *)D_overlay_3_0031A1CC + v);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030A564_1EDFA44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030A5EC_1EDFACC(void *arg2, void *arg3) {
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *st = D_overlay_3_0031A1D0;
    s16 step = D_overlay_3_0031A1E0[0x28];
    s16 target;
    s32 a1 = 0;
    s32 v1 = 0;
    s32 neg;
    s16 cur;

    target = mathDiffAngle(*(s16 *)obj, D_overlay_3_0031A1F6, arg2, arg3);
    if ((*(u32 *)(GetAnimData(obj) + 0x4) & 0x02000000) && D_overlay_3_0031A1EC == 0.0f) {
        *(s16 *)(st + 0x4C) = 0;
        D_overlay_3_0031A1F6 = *(s16 *)obj;
        return;
    }
    if (target >= 0) {
        do {
            a1 += step;
            v1 += a1;
        } while ((s16)(v1 + a1) < target);
    } else {
        do {
            a1 -= step;
            v1 += a1;
        } while (target < (s16)(v1 + a1));
    }

    neg = -(s32)step;
    cur = *(s16 *)(st + 0x4C);
    if (step >= target && target >= neg && !(step < cur) && cur >= neg &&
        ((target >= 0 && cur >= 0) || (target <= 0 && cur <= 0))) {
        *(s16 *)(st + 0x4C) = (s16)(D_overlay_3_0031A1F6 - *(s16 *)obj);
    } else {
        s16 lo = (s16)(a1 - step);
        s16 hi = (s16)(cur + step);

        if (lo >= hi) {
            *(s16 *)(st + 0x4C) = hi;
        } else {
            s16 t = (s16)(cur - step);

            *(s16 *)(st + 0x4C) = (t < a1) ? lo : t;
        }
    }
    if (*(s16 *)(st + 0x4C) == 0) {
        s16 neg16 = (s16)-step;

        if (step < target) {
            *(s16 *)(st + 0x4C) = step;
        } else if (target < neg16) {
            *(s16 *)(st + 0x4C) = neg16;
        }
    }
    *(s16 *)obj = (s16)(*(s16 *)obj + *(s16 *)(st + 0x4C));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030A5EC_1EDFACC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030A850_1EDFD30(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *cfg = D_overlay_3_0031A1D8;
    f32 a;
    f32 b;
    u32 flags;

    if (*(s16 *)(st + 0xA) == 0x14) {
        D_overlay_3_0031A130 = 0.0f;
        return;
    }
    a = D_overlay_3_0031A1EC * D_overlay_3_0031A1EC * D_overlay_3_00319D40;
    b = (f32)cfg[0x26] * D_overlay_3_00319D44;
    if (b < a) {
        D_overlay_3_0031A130 = b;
    } else {
        D_overlay_3_0031A130 = a;
    }
    flags = *(u32 *)st;
    if (flags & 0x1000) {
        D_overlay_3_0031A130 *= 2.0f;
        return;
    }
    if ((flags & 0x20000) || (flags & 0x40000000)) {
        D_overlay_3_0031A130 *= 5.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030A850_1EDFD30.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030A948_1EDFE28(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *cfg = D_overlay_3_0031A1D8;
    f32 v = (f32)cfg[0x26];

    D_overlay_3_0031A130 = GetSmoothAcceleration((s32)(D_overlay_3_0031A1EC * 10.0f),
                                                 *(f32 *)(st + 0x20) * 10.0f, v)
                           * D_overlay_3_00319D48;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030A948_1EDFE28.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030A9E8_1EDFEC8(s32 arg0) {
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *obj = D_overlay_3_0031A1CC;
    f32 v = (f32)cfg[0x26];
    f32 dist = ((f32)arg0 + D_overlay_3_0031A138 - *(f32 *)(obj + 0x10)) * 10.0f;
    f32 accel;

    /* sig mismatch: GetSmoothAcceleration takes 3 args, asm passes a 4th */
    accel = ((f32 (*)(s32, f32, f32, s32))GetSmoothAcceleration)((s32)dist,
                                                                  *(f32 *)(obj + 0x20) * 10.0f,
                                                                  v, arg0);
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + accel * D_overlay_3_00319D4C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030A9E8_1EDFEC8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030AABC_1EDFF9C(f32 arg0, f32 arg1) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    s16 ang = (s16)(*(s16 *)(st + 0x1C) - *(s16 *)obj);
    f32 x = Sinf((s32)ang) * *(f32 *)(st + 0x20) * arg0;
    f32 z = Cosf((s32)ang) * *(f32 *)(st + 0x20) * arg1;

    *(s16 *)(st + 0x1C) = (s16)(Arctanf(x, z) + *(s16 *)obj);
    *(f32 *)(st + 0x20) = sqrtf((x * x) + (z * z));
    *(f32 *)(obj + 0x1C) = (f32)(Sinf((s32)*(s16 *)(st + 0x1C)) * *(f32 *)(st + 0x20));
    *(f32 *)(obj + 0x24) = (f32)(Cosf((s32)*(s16 *)(st + 0x1C)) * *(f32 *)(st + 0x20));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030AABC_1EDFF9C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030ABF4_1EE00D4(void *arg2, void *arg3) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    s16 temp = mathDiffAngle(*(s16 *)obj, D_overlay_3_0031A1F4, arg2, arg3);
    s16 absAng = (temp < 0) ? (s16)-temp : temp;
    s16 t2 = (s16)(absAng - 0x1000);
    s16 v1 = t2;
    f32 f2;

    if (t2 < 0) {
        v1 = 0;
    }
    f2 = (f32)(0x2000 - v1) * 0.00012207031f;
    if (f2 > 1.0f) {
        f2 = 1.0f;
    }
    if (f2 < 0.0f) {
        f2 = 0.0f;
    }
    *(f32 *)(st + 0x20) = *(f32 *)(st + 0x20) * f2;
    *(f32 *)(obj + 0x1C) = (f32)(Sinf((s32)*(s16 *)(st + 0x1C)) * *(f32 *)(st + 0x20));
    *(f32 *)(obj + 0x24) = (f32)(Cosf((s32)*(s16 *)(st + 0x1C)) * *(f32 *)(st + 0x20));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030ABF4_1EE00D4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030AD38_1EE0218(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *config = D_overlay_3_0031A1E0;
    f32 lo = (f32)(s8)cfg[0x24];
    f32 hi = (f32)cfg[0x25];

    if (*(f32 *)(config + 0x10) > 0.0f || D_overlay_3_0031A1EC > 20.0f) {
        *(f32 *)(st + 0x20) *= D_overlay_3_00319D50;
    }
    if (lo < *(f32 *)(st + 0x20)) {
        *(f32 *)(st + 0x20) = lo;
    }
    if (*(f32 *)(st + 0x20) < hi) {
        *(f32 *)(st + 0x20) = hi;
    }
    *(f32 *)(obj + 0x1C) = (f32)(Sinf((s32)*(s16 *)(st + 0x1C)) * *(f32 *)(st + 0x20));
    *(f32 *)(obj + 0x24) = (f32)(Cosf((s32)*(s16 *)(st + 0x1C)) * *(f32 *)(st + 0x20));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030AD38_1EE0218.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030AE80_1EE0360(f32 arg0) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    f32 vx;
    f32 vz;

    *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * arg0;
    *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * arg0;
    vx = *(f32 *)(obj + 0x1C);
    vz = *(f32 *)(obj + 0x24);
    *(s16 *)(st + 0x1C) = (s16)Arctanf(vx, vz);
    *(f32 *)(st + 0x20) = sqrtf((vx * vx) + (vz * vz));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030AE80_1EE0360.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030AF34_1EE0414(void) {
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *config = D_overlay_3_0031A1E0;
    f32 limit;

    if (obj == *(u8 **)(cfg + 0x58)) {
        limit = 0.0f;
    } else {
        limit = *(f32 *)(config + 0x10);
    }
    if (D_overlay_3_0031A1EC < limit) {
        /* sig mismatch: AE80 takes 1 arg, asm passes &D_overlay_3_0031A130 as a 2nd (unused) */
        ((void (*)(f32, f32 *))func_overlay_3_0030AE80_1EE0360)(D_overlay_3_00319D54, &D_overlay_3_0031A130);
        return;
    }
    func_overlay_3_00303D44_1ED9224(*(s16 *)obj, D_overlay_3_0031A130);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030AF34_1EE0414.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030AFC4_1EE04A4(void) {
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *config = D_overlay_3_0031A1E0;
    f32 limit;

    if (obj == *(u8 **)(cfg + 0x58)) {
        limit = 0.0f;
    } else {
        limit = *(f32 *)(config + 0x10);
    }
    if (limit < D_overlay_3_0031A1EC) {
        func_overlay_3_00303D44_1ED9224(D_overlay_3_0031A1F4, D_overlay_3_0031A130);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030AFC4_1EE04A4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_overlay_3_0030B040_1EE0520(f32 arg0, f32 arg1, s32 arg2) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    s16 sp4E = 0;
    u32 flags;
    u16 cfgFlags;
    u8 cfgType;
    u8 t33;
    u8 t31;
    u8 facing;
    u8 *node;
    u8 *p;
    s32 idx;
    s32 r;

    if (st[0x4B] >= 9) {
        return *(s16 *)obj;
    }
    if (st[0x1A] != 0) {
        r = ((s32 (*)(u8 *, s16 *, f32, s32))D_overlay_3_00319678[st[0x1A]])(obj, &sp4E, arg1, arg2);
        if (r != 0) {
            if (r == 1) {
                return sp4E;
            }
            goto block_49;
        }
    }

    t33 = cfg[0x33];
    if (t33 != 0x19) {
        flags = *(u32 *)st;
        if (!(flags & 0x400000)) {
            cfgType = cfg[0x32];
            if (cfgType != 0xB && cfgType != 0x12) {
                cfgFlags = *(u16 *)(cfg + 0x28);
                if (cfgType == 0xC && !(flags & 0x200000) && !(cfgFlags & 0x1000)) {
                    goto block_49;
                }
                if (t33 == 0x21) {
                    p = D_overlay_3_0031A1F8 + cfg[0x65] * 0x10;
                    return Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(p + 0),
                                   *(f32 *)(obj + 0x14) - *(f32 *)(p + 4));
                }
                if ((flags & 0x10000000) && st[0x17] != 0) {
                    if (!(flags & 0x80000)) {
                        s16 t4 = (s16)(0xC000 - (cfg[0x1B] << 8));
                        *(s16 *)(st + 0x1C) = t4;
                        *(s16 *)obj = t4;
                    }
                    return *(s16 *)obj;
                }
                facing = cfg[0x30];
                if (!(cfgFlags & 0x400) && (facing != 3 || (s8)st[0x3] >= 0)) {
                    if (cfgType == 0x11) {
                        return SmartFacer(obj, D_overlay_3_0031A1F6, cfgFlags, facing);
                    }
                    if (!(flags & 4)) {
                        if (*(u16 *)(cfg + 0x2C) == 0x112) {
                            return FlopsyDogFacer(obj, D_overlay_3_0031A134, D_overlay_3_0031A13C, facing);
                        }
                        if (arg0 < *(f32 *)(D_overlay_3_0031A1E0 + 0x14) && !(cfgFlags & 0x1000)) {
                            if (cfgType == 9 && facing != 3 && facing != 4) {
                                if (flags & 0x80000) {
                                    node = *(u8 **)(obj + 0x3C);
                                    if (node != NULL) {
                                        return (s16)(*(u8 *)(node + 0xD) << 8);
                                    }
                                }
                                return (s16)(0xC000 - (cfg[0x1B] << 8));
                            }
                            t31 = cfg[0x31];
                            if (t31 != 5) {
                                if (t31 == 7 || t31 == 0xA) {
                                    return (s16)(Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(cfg + 0x48),
                                                         *(f32 *)(obj + 0x14) - *(f32 *)(cfg + 0x50)) - 0x8000);
                                }
                                return *(s16 *)D_overlay_3_0031A1D4;
                            }
                            goto block_49;
                        }
                        if (t33 == 0x1D) {
                            idx = *(u16 *)(cfg + 0x3C) & 0xFF;
                            if (idx != 0) {
                                p = (u8 *)PatrolNodes + idx * 0x34;
                                return Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(p + 0),
                                               *(f32 *)(obj + 0x14) - *(f32 *)(p + 8));
                            }
                            return 0;
                        }
                        return D_overlay_3_0031A1F4;
                    }
                }
            }
        }
    }
block_49:
    node = *(u8 **)(st + 0x64);
    if (node != NULL) {
        return Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(node + 0xC),
                       *(f32 *)(obj + 0x14) - *(f32 *)(node + 0x14));
    }
    return *(s16 *)obj;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030B040_1EE0520.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030B468_1EE0948(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    f32 rate = (f32)cfg[0x26] * D_overlay_3_00319D58;

    if (*(u32 *)st & 0x1000) {
        rate *= 2.0f;
    }
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20)
                           + func_overlay_3_00307980_1EDCE60(*(f32 *)(obj + 0x10), D_overlay_3_0031A138,
                                                             *(f32 *)(obj + 0x20), rate);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030B468_1EE0948.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 func_overlay_3_0030B50C_1EE09EC(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    u16 w;
    s32 idx;
    s32 idx2;
    u8 *n1;
    u8 *n2;
    f32 dx;
    f32 dz;
    f32 ex;
    f32 ez;
    f32 dist;
    f32 cosv;
    f32 t2;
    f32 t12;
    f32 n2x;
    f32 n2z;
    s32 ang1;

    if (cfg[0x32] == 2 || cfg[0x32] == 0x13 || cfg[0x32] == 0xC) {
        w = *(u16 *)(cfg + 0x3C);
        idx = w & 0xFF;
        if (idx != 0) {
            n1 = (u8 *)PatrolNodes + idx * 0x34;
            if (*(u8 *)(n1 + 0x18) == 8 || (st[0x1A] == 0x13 && st[0x1B] == 4)) {
                return *(f32 *)(n1 + 4);
            }
            idx2 = w >> 8;
            n2 = NULL;
            if (idx2 != 0) {
                n2 = (u8 *)PatrolNodes + idx2 * 0x34;
            }
            if (n2 == NULL) {
                return *(f32 *)(n1 + 4);
            }
            if (*(f32 *)(n1 + 4) == *(f32 *)(n2 + 4)) {
                return *(f32 *)(n1 + 4);
            }
            n2x = *(f32 *)(n2 + 0);
            n2z = *(f32 *)(n2 + 8);
            ex = n2x - *(f32 *)(n1 + 0);
            ez = n2z - *(f32 *)(n1 + 8);
            dx = *(f32 *)(obj + 0xC) - n2x;
            dz = *(f32 *)(obj + 0x14) - n2z;
            dist = sqrtf((ex * ex) + (ez * ez));
            ang1 = Arctanf(dx, dz);
            cosv = Cosf(ang1 - (s32)Arctanf(ex, ez));
            t2 = sqrtf((dx * dx) + (dz * dz)) * cosv;
            t12 = *(f32 *)(n2 + 4);
            return (-(t2 / dist) * (*(f32 *)(n1 + 4) - t12)) + t12;
        }
    }
    return *(f32 *)(cfg + 0x4C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030B50C_1EE09EC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030B70C_1EE0BEC(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *config = D_overlay_3_0031A1E0;
    u32 flags;
    f32 dist;
    f32 cur;
    f32 sum;

    if (*(u16 *)(cfg + 0x28) & 0x30) {
        return;
    }
    flags = *(u32 *)st;
    if ((flags & 0x40000) || !(*(u16 *)(config + 0x24) & 0x400)) {
        return;
    }
    dist = func_overlay_3_0030B50C_1EE09EC();
    cur = *(f32 *)(obj + 0x20);
    if ((flags & 0x800) && cur > 0.0f) {
        *(f32 *)(obj + 0x20) = cur - 1.0f;
        return;
    }
    if (dist < *(f32 *)(obj + 0x10)) {
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) - 1.0f;
        *(u32 *)st |= 4;
    } else {
        *(f32 *)(obj + 0x20) = 0.0f;
        st[0x1E] = 0;
        *(u32 *)st &= ~0x4u;
        st[0x2] &= 0xF7;
        if (st[0x1A] == 0x13 && st[0x1B] == 4) {
            st[0x4B] = 0;
            ClearMissionFields(2, 0);
        }
    }
    cur = *(f32 *)(obj + 0x20);
    sum = *(f32 *)(obj + 0x10) + cur;
    if (sum < dist) {
        if ((dist - 12.0f) < sum) {
            *(f32 *)(obj + 0x20) = 0.0f;
            st[0x1E] = 0;
        } else {
            *(f32 *)(obj + 0x20) = cur * D_overlay_3_00319D5C;
        }
        *(f32 *)(obj + 0x10) = dist;
        *(u32 *)st &= ~0x4u;
        st[0x2] &= 0xF7;
        if (st[0x1A] == 0x13 && st[0x1B] == 4) {
            st[0x4B] = 0;
            ClearMissionFields(2, 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030B70C_1EE0BEC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030B9A0_1EE0E80(void) {
    ((void (*)(void))func_overlay_3_0030A564_1EDFA44)();
    func_overlay_3_0030A850_1EDFD30();
    func_overlay_3_0030AFC4_1EE04A4();
    func_overlay_3_0030B468_1EE0948();
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030B9A0_1EE0E80.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030B9E0_1EE0EC0(void) {
    ((void (*)(void))func_overlay_3_0030A5EC_1EDFACC)();
    func_overlay_3_0030A850_1EDFD30();
    func_overlay_3_0030AFC4_1EE04A4();
    func_overlay_3_0030B468_1EE0948();
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030B9E0_1EE0EC0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030BA20_1EE0F00(void) {
    u8 *cfg = D_overlay_3_0031A1D8;

    ((void (*)(void))func_overlay_3_0030A564_1EDFA44)();
    D_overlay_3_0031A130 = (f32)(cfg[0x26] * 5);
    func_overlay_3_0030AF34_1EE0414();
    func_overlay_3_0030B468_1EE0948();
    func_overlay_3_0030AABC_1EDFF9C(0.0f, 1.0f);
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030BA20_1EE0F00.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030BA94_1EE0F74(void) {
    ((void (*)(void))func_overlay_3_0030A564_1EDFA44)();
    func_overlay_3_0030A948_1EDFE28();
    func_overlay_3_0030AFC4_1EE04A4();
    func_overlay_3_0030A9E8_1EDFEC8(0);
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030BA94_1EE0F74.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030BAD4_1EE0FB4(void) {
    u8 *cfg = D_overlay_3_0031A1D8;

    ((void (*)(void))func_overlay_3_0030A5EC_1EDFACC)();
    D_overlay_3_0031A130 = (f32)cfg[0x26];
    func_overlay_3_0030AF34_1EE0414();
    func_overlay_3_0030A9E8_1EDFEC8(0);
    func_overlay_3_0030AABC_1EDFF9C(0.0f, 1.0f);
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030BAD4_1EE0FB4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030BB50_1EE1030(void) {
    u8 *obj = D_overlay_3_0031A1CC;

    ((void (*)(void))func_overlay_3_0030A5EC_1EDFACC)();
    func_overlay_3_0030A948_1EDFE28();
    func_overlay_3_0030AFC4_1EE04A4();
    func_overlay_3_0030A9E8_1EDFEC8(0);
    if (*(f32 *)(obj + 0x20) < 0.0f) {
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) * D_overlay_3_00319D60;
    }
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030BB50_1EE1030.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030BBC4_1EE10A4(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1D8;
    u8 *config = D_overlay_3_0031A1E0;
    u8 *anim;
    u8 aiType;
    f32 speed;
    f32 mag;
    f32 vz;
    s16 ang;
    s8 cap;

    anim = GetAnimData(obj);
    if (cfg[0x32] == 0x11 && ((aiType = st[0x1A]) == 0 || aiType == 0xD || aiType == 5)) {
        if (((*(u32 *)(anim + 4) & 0x02000000) && D_overlay_3_0031A1EC == 0.0f)
            || *(s16 *)(st + 0xA) == 5 || *(s16 *)(st + 0xA) == 6 || *(s16 *)(st + 0xA) == 7
            || (s8)st[0x3] < 0) {
            D_overlay_3_0031A1F6 = *(s16 *)obj;
            *(f32 *)(obj + 0x1C) = 0.0f;
            *(f32 *)(obj + 0x24) = 0.0f;
            func_overlay_3_00303CAC_1ED918C(obj);
            return;
        }
        if (*(u16 *)(config + 0x24) & 0x10) {
            /* sig mismatch: A5EC takes 2 args; asm passes aiType and two global addresses */
            ((void (*)(u8, s16 *, u8 **))func_overlay_3_0030A5EC_1EDFACC)(aiType, &D_overlay_3_0031A1F6, &D_overlay_3_0031A1CC);
            func_overlay_3_0030A850_1EDFD30();
            func_overlay_3_0030AF34_1EE0414();
            ((void (*)(void))func_overlay_3_0030ABF4_1EE00D4)();
            func_overlay_3_0030AABC_1EDFF9C(0.5f, 1.0f);
            func_overlay_3_0030B70C_1EE0BEC();
            func_overlay_3_0030AD38_1EE0218();
            return;
        }
        /* a3 is unset in the asm, passed as 0 */
        *(s16 *)(st + 0xC) = (s16)(*(s16 *)(st + 0xC)
                                   - mathDiffAngle(*(s16 *)obj, D_overlay_3_0031A1F6, &D_overlay_3_0031A1CC, 0));
        ang = *(s16 *)(st + 0xC);
        if (ang >= 0x6979) {
            *(s16 *)(st + 0xC) = 0x6978;
        } else if (ang < -0x6978) {
            *(s16 *)(st + 0xC) = -0x6978;
        }
        *(s16 *)obj = D_overlay_3_0031A1F6;
        cap = (s8)cfg[0x24];
        if (D_overlay_3_0031A1EC < (f32)cap) {
            speed = -D_overlay_3_0031A1EC;
        } else {
            speed = (f32)-cap;
        }
        *(f32 *)(obj + 0x1C) = (f32)(Sinf((s32)*(s16 *)obj) * speed);
        *(f32 *)(obj + 0x24) = (f32)(Cosf((s32)*(s16 *)obj) * speed);
        *(s16 *)(st + 0x1C) = (s16)Arctanf(*(f32 *)(obj + 0x1C), *(f32 *)(obj + 0x24));
        mag = *(f32 *)(obj + 0x1C);
        vz = *(f32 *)(obj + 0x24);
        *(f32 *)(st + 0x20) = sqrtf((mag * mag) + (vz * vz));
        *(s16 *)(st + 0x4C) = 0;
        ((void (*)(void))func_overlay_3_0030ABF4_1EE00D4)();
        func_overlay_3_0030AABC_1EDFF9C(D_overlay_3_00319D64, 1.0f);
        func_overlay_3_0030B70C_1EE0BEC();
        return;
    }
    if (((*(u32 *)(anim + 4) & 0x02000000) && D_overlay_3_0031A1EC == 0.0f)
        || *(s16 *)(st + 0xA) == 5 || *(s16 *)(st + 0xA) == 6 || *(s16 *)(st + 0xA) == 7) {
        D_overlay_3_0031A1F6 = *(s16 *)obj;
        *(f32 *)(obj + 0x1C) = 0.0f;
        *(f32 *)(obj + 0x24) = 0.0f;
        func_overlay_3_00303CAC_1ED918C(obj);
        return;
    }
    ((void (*)(void))func_overlay_3_0030A5EC_1EDFACC)();
    func_overlay_3_0030A850_1EDFD30();
    func_overlay_3_0030AF34_1EE0414();
    ((void (*)(void))func_overlay_3_0030ABF4_1EE00D4)();
    func_overlay_3_0030AABC_1EDFF9C(0.5f, 1.0f);
    func_overlay_3_0030B70C_1EE0BEC();
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030BBC4_1EE10A4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030BFC4_1EE14A4(void) {
    f32 temp_f0;

    ((void (*)(void))func_overlay_3_0030A5EC_1EDFACC)();
    func_overlay_3_0030A948_1EDFE28();
    func_overlay_3_0030AFC4_1EE04A4();
    func_overlay_3_0030A9E8_1EDFEC8(0);
    temp_f0 = *(f32 *)(D_overlay_3_0031A1CC + 0x20);
    if (temp_f0 < 0.0f) {
        *(f32 *)(D_overlay_3_0031A1CC + 0x20) = temp_f0 * D_overlay_3_00319D68;
    }
    func_overlay_3_0030AD38_1EE0218();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030BFC4_1EE14A4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquaddiePassesAway(void *arg0) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0x4C);

    if (*(s16 *)(state + 0x6) > 0) {
        *(s16 *)(state + 0x6) = 0;
    }
    /* asm: bit 28 of the word at +8 is shifted to bit 31, so the compare
       against 0xF is always true and the call is always made */
    if (((*(u32 *)(state + 0x8) << 3) >> 31) != 0xF) {
        mainIncreaseWeaponKills(state[0x8] & 0xF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddiePassesAway.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquaddieBodyPartHit(void *arg0, u8 arg1) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0x4C);
    u8 *hit = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *cfg = D_overlay_3_0031A1E0;
    u8 *part = NULL;
    u8 *cur;
    s32 count;
    s32 i = 0;
    u8 id = arg1;
    u16 bit;

    if (state != NULL) {
        count = cfg[0x29];
        if (count > 0) {
            id = state[0x31];
            cur = cfg;
            do {
                i++;
                if (id == cur[0x41]) {
                    part = cur + 0x40;
                    break;
                }
                cur += 8;
            } while (i < count);
        }
        if (part != NULL) {
            bit = (1 << part[0]) & 0xFFFF;
            if (!(*(u16 *)(hit + 0x5A) & bit)) {
                if (part[6] == 0xF) {
                    *(u16 *)(hit + 0xA0) = (u16)(*(u16 *)(hit + 0xA0) | bit);
                } else {
                    *(u16 *)(hit + 0xA2) = (u16)(*(u16 *)(hit + 0xA2) | bit);
                }
            }
            if (part[2] == 2 && *(s16 *)(state + 0x6) > 0) {
                SquaddiePassesAway(arg0);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddieBodyPartHit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_0030C1A0_1EE1680(void *arg0, void *arg1, s16 *arg2, s16 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    u8 *obj = (u8 *)arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *tgt;
    u8 *alt;
    f32 sx, sy, sz;
    f32 x, y, z;

    sx = *(f32 *)(st + 0x68);
    sy = *(f32 *)(st + 0x6C);
    sz = *(f32 *)(st + 0x70);
    if (arg2 != NULL) {
        *arg2 = *(s16 *)obj;
    }
    if (arg3 != NULL) {
        *arg3 = 0;
    }
    if (arg4 != NULL) {
        *arg4 = 0.0f;
    }
    if (arg1 == NULL) {
        return 0;
    }
    tgt = (u8 *)arg1;
    if (*(s16 *)(*(u8 **)(tgt + 0x40) + 0x1E) != 0) {
        x = *(f32 *)(tgt + 0xC);
        y = *(f32 *)(tgt + 0x10);
        z = *(f32 *)(tgt + 0x14);
    } else {
        alt = *(u8 **)(tgt + 0x4C);
        x = *(f32 *)(alt + 0xC);
        y = *(f32 *)(alt + 0x10);
        z = *(f32 *)(alt + 0x14);
    }
    if (arg2 != NULL) {
        *arg2 = (s16)Arctanf(sx - x, sz - z);
    }
    if (arg4 != NULL) {
        *arg4 = GetRange(sx, sy, sz, x, y, z);
    }
    if (arg5 != NULL) {
        *arg5 = x;
        *arg6 = y;
        *arg7 = z;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030C1A0_1EE1680.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 CheckLineOfSight(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *sq = *(u8 **)(*(u8 **)(st + 0x24) + 0x68);
    u8 *target;
    u8 *node;
    s16 angle;
    s32 roll;
    f32 dist, tx, ty, tz;
    f32 sx, sy, sz;
    u8 *cls;

    sx = *(f32 *)(st + 0x68);
    sy = *(f32 *)(st + 0x6C);
    sz = *(f32 *)(st + 0x70);
    if (D_overlay_3_00319430 != 0) {
        return 0;
    }
    if (*(s32 *)st & 2) {
        return *(s32 *)st & 1;
    }
    st[3] |= 2;
    if (((u8 *)D_800F31E1)[*(s16 *)(obj + 0x2E)] == 0) {
        return 0;
    }
    target = *(u8 **)(st + 0x64);
    if (target == NULL) {
        target = (u8 *)func_overlay_3_0030527C_1EDA75C(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
    }
    if (target == NULL) {
        return 0;
    }
    if (func_overlay_3_0030C1A0_1EE1680(obj, target, &angle, NULL, &dist, &tx, &ty, &tz) == 0) {
        return 0;
    }
    angle = angle - *(s16 *)(st + 0x9C);
    if (angle < 0) {
        angle = -angle;
    }
    if (((f32)(sq[0x1F] << 6) < dist) || ((sq[0x20] * 0x5B) < angle)) {
        return 0;
    }
    if (hitsCheckLineOfSight(obj, target, tx, ty, tz, sx, sy, sz) != 0) {
        return 0;
    }
    if (PlayersDisguise == 0) {
        sq[0x90] = 1;
        if (!(sq[0x91] & 1)) {
            if (*(s32 *)st & 8) {
                sq[0x91] = 2;
            } else {
                sq[0x91] = 3;
            }
        }
    } else if (sq[0x90] == 0) {
        if (PlayersDisguise == 1) {
            sq[0x90] = 2;
            if (*(s32 *)st & 8) {
                sq[0x91] = 1;
            } else {
                sq[0x91] = 2;
            }
        } else {
            sq[0x90] = 3;
            sq[0x91] = 2;
        }
    }
    if (D_overlay_3_0031A12B != 0 && sq[0x91] != 3) {
        if (*(s32 *)st & 8) {
            if (D_overlay_3_0031A12C == 1) {
                *(u8 **)(st + 0x64) = target;
                sq[0x91] = 3;
            } else if (D_overlay_3_0031A12C == 2) {
                *(u8 **)(st + 0x64) = target;
                sq[0x91] = 2;
            }
        } else if (D_overlay_3_0031A12C == 2 || D_overlay_3_0031A12C == 3) {
            *(u8 **)(st + 0x64) = target;
            sq[0x91] = 3;
        }
    }
    if (*(u8 **)(st + 0x64) == NULL) {
        return 0;
    }
    st[3] |= 1;
    if (D_overlay_3_0031A1E0[0x2B] == 5 && sq[0x30] == 2) {
        sq[0x30] = 3;
    }
    node = *(u8 **)(st + 0x64);
    if (*(s16 *)(node + 0x48) == 1 || *(s16 *)(node + 0x48) == 2) {
        if (sq[0x30] == 1) {
            if (!(*(u16 *)(sq + 0x28) & 0x40)) {
                *(u16 *)(sq + 0x28) = (u16)(*(u16 *)(sq + 0x28) | 0x40);
            }
        }
        smartPlayerSeen((s16)*(f32 *)(node + 0xC), (s16)*(f32 *)(node + 0x14));
        if (!(st[4] & 1) && D_overlay_3_0031A1E0[0x2B] != 5) {
            if ((*(s32 *)st & 8) && sq[0x30] == 2) {
                sq[0x30] = 3;
            }
            if (*(u16 *)(sq + 0x2C) == 0x112) {
                FlopsyDogSpotPlayer(obj);
            } else if (D_overlay_3_0031A1F0 < 300.0f
                       && ((roll = mathRnd(0, 0x32)), (((s32)sq[0xD] - 0xA) < (mathRnd(0, 0x32) + roll)))
                       && (sq[0x91] & 1)
                       && func_overlay_3_00304614_1ED9AF4(0x20, 1) != -1) {
                TryToSetMission(0x11, 0x17, 0U, 0U, 0U);
                *(s32 *)st |= 0x20;
            } else if (D_overlay_3_00319D6C < D_overlay_3_0031A1F0
                       && (*(u32 *)(st + 8) >> 28) == 0
                       && ((roll = mathRnd(0, 0x32)), ((s32)sq[0xC] < (mathRnd(0, 0x32) + roll)))
                       && *(f32 *)(obj + 0x1C) == 0.0f
                       && *(f32 *)(obj + 0x24) == 0.0f) {
                TryToSetMission(0x11, 0x15, 0x2DU, 0U, 0U);
                *(s32 *)st |= 0x20;
            } else if (D_overlay_3_0031A1F0 > 1200.0f) {
                TryToSetMission(0x11, 0x10, 0U, 0U, 0U);
                *(s32 *)st |= 0x20;
            }
            if (sq[0x30] == 2) {
                sq[0x30] = 3;
            }
            st[5] |= 1;
            node = *(u8 **)(sq + 0x58);
            if (node != NULL) {
                do {
                    if (node != obj) {
                        u8 *ns = *(u8 **)(node + 0x68);
                        ns[5] |= 1;
                    }
                    node = *(u8 **)(*(u8 **)(node + 0x68) + 0x28);
                } while (node != NULL);
            }
            cls = *(u8 **)(obj + 0x40);
            if (cls[0x14] & 0x80) {
                if (sq[0x30] == 4) {
                    sq[0x30] = 3;
                }
            }
        }
    } else {
        sq[0x30] = 3;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/CheckLineOfSight.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 DoesSquaddieWantToFire(f32 arg0, f32 arg1, s16 arg2, s32 arg3, s32 arg4) {
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *st = D_overlay_3_0031A1D0;
    u8 *cfg = D_overlay_3_0031A1E0;
    u8 *sqd = D_overlay_3_0031A1D8;
    u8 *tgt = *(u8 **)(st + 0x64);
    s16 angle;
    s16 absAngle;
    u32 flags4;
    u32 flags0;
    u32 *b0;
    s32 tv;
    s32 want;

    /* arg3 and arg4 are passed by BTSBStandardFire but never read here */
    if (tgt == NULL) {
        return 0;
    }
    /* sig mismatch: header declares 4 args, asm passes 2 */
    angle = ((s16 (*)(s16, s16))mathDiffAngle)(*(s16 *)obj,
            (s16)Arctanf(*(f32 *)(obj + 0xC) - *(f32 *)(tgt + 0xC), *(f32 *)(obj + 0x14) - *(f32 *)(tgt + 0x14)));
    absAngle = angle;
    if (absAngle < 0) {
        absAngle = -absAngle;
    }
    flags4 = *(u32 *)(st + 4);
    if ((*(u32 *)(cfg + 0x24) & 0x800) && (flags4 & 4) && !(*(u32 *)(st + 8) & 0x08000000)) {
        if (!(flags4 & 0x40) && !(flags4 & 0x20)) {
            return 0;
        }
    } else if (arg2 < absAngle) {
        return 0;
    }
    if (CheckLineOfSight(obj) != 0
        && sqd[0x30] != 2
        && !(D_overlay_3_0031A1F0 <= arg0)
        && (!(arg1 > 0.0f) || !(arg1 < D_overlay_3_0031A1F0))
        && *(s16 *)(st + 0x4A) == 0
        && !(*(u32 *)(sqd + 0x28) & 0x1000)
        && (flags0 = *(u32 *)st, !(flags0 & 0x40000000))
        && !(flags0 & 0x200000)) {
        b0 = *(u32 **)(st + 0xB0);
        tv = (s32)(flags0 * 4);
        if (b0 != NULL && !(*b0 & 4)) {
            if (!squadsIsTribal(*(s16 *)(tgt + 0x4A))) {
                return 0;
            }
        }
        if (tv < 0) {
            return 0;
        }
        want = sqd[0x30] == 3;
        if (!want) {
            want = squadsBehaviour == 7;
            if (!want) {
                want = squadsBehaviour == 0xC;
                if (!want) {
                    want = squadsBehaviour == 9;
                }
            }
        }
        return want;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/DoesSquaddieWantToFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBStandardFire(s32 arg0) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *sqd = D_overlay_3_0031A1D8;
    u8 *saved;
    u8 *tgt;
    s32 var_t0;
    s32 var_a3 = 0;
    s32 i;
    u8 *p;
    f32 f12;
    f32 f14;

    var_t0 = func_overlay_3_00304614_1ED9AF4(5, 1);
    if (!(*(u16 *)(st + 4) & 1)) {
        saved = *(u8 **)(st + 0x64);
        *(u8 **)(st + 0x64) = D_overlay_3_0031A1E8;
        /* asm: the return value of CheckLineOfSight is not used here */
        CheckLineOfSight((void *)arg0);
        tgt = *(u8 **)(st + 0x64);
        if (tgt == NULL || (*(s16 *)(tgt + 0x48) == 1 && !(sqd[0x91] & 1))) {
            *(u8 **)(st + 0x64) = saved;
        }
    }
    if (var_t0 != -1) {
        i = 3;
        p = D_overlay_3_00317A10 + ((((*(u32 *)(D_overlay_3_00317DB8
                + ((*(s32 *)(D_overlay_3_00319278 + D_overlay_3_0031A1DC * 4)) * 8 + var_t0 * 8) * 8 + 4)) << 10) >> 25) * 0x18) + 3;
        do {
            p -= 1;
            if (p[0x14] == 1) {
                var_a3 = 1;
                break;
            }
            i -= 1;
        } while (i != 0);
    }
    if (var_a3 != 0) {
        f12 = D_overlay_3_00319D70;
        f14 = 1200.0f;
    } else {
        f14 = 0.0f;
        f12 = 0.0f;
    }
    if (DoesSquaddieWantToFire(f12, f14, 1, 0x2000, var_a3) != 0) {
        if (var_t0 == -1) {
            TryToSetMission(4, 0x11, 0U, 0U, 0U);
            return;
        }
        if (*(s16 *)(st + 0x1A) != 5) {
            if (TryToSetMission(4, 5, 0U, 0U, 0U) != 0) {
                D_overlay_3_00319434 = var_t0;
                UpdateOrSetAnim(6, 0x3F800000, 5);
                D_overlay_3_00319434 = -1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/BTSBStandardFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030CF40_1EE2420(void *arg0) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *saved;

    saved = *(u8 **)(st + 0x64);
    if (!(*(u16 *)(st + 4) & 1)) {
        *(u8 **)(st + 0x64) = D_overlay_3_0031A1E8;
        /* asm: CheckLineOfSight is called with a0 passed through from entry */
        CheckLineOfSight(arg0);
        if (*(u8 **)(st + 0x64) == NULL) {
            *(u8 **)(st + 0x64) = saved;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030CF40_1EE2420.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SetSquaddieOnFire(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *s;
    u8 *st = D_overlay_3_0031A1D0;
    u8 *cfg = D_overlay_3_0031A1E0;
    u8 *sqd = D_overlay_3_0031A1D8;
    s32 snd;

    if (squadsPrepareToProcessSquaddie(arg0) != 0) {
        if (*(u16 *)(sqd + 0x2C) != 0x112) {
            if (cfg[0x2B] == 5 || (*(s32 *)(cfg + 0x24) & 0x10)) {
                s = *(u8 **)(obj + 0x4C);
                s[8] = (u8)((s[8] & 0xF0) | 6);
                SquaddiePassesAway(arg0);
            } else {
                if (!(*(s32 *)st & 8) && !(*(s32 *)st & 0x40000000)) {
                    snd = *(s32 *)(st + 0xBC);
                    if (snd != 0) {
                        amSndStopXYZ(snd);
                    }
                    amSndPlayXYZ((mathRnd(0, 1) + 0x191) & 0xFFFF, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10),
                                 *(f32 *)(obj + 0x14), 4U, st + 0xBC);
                }
                func_overlay_3_003044F4_1ED99D4(arg0);
                TryToSetAnim(8, 0xF, 0xD, 0);
                TryToSetMission(9, 0xB, 0U, 0U, 0U);
            }
            *(s32 *)st |= 0x40;
            st[6] = (u8)(st[6] & 0xEF);
            *(f32 *)(st + 0x3C) = 0.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SetSquaddieOnFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsElectrocuteSquaddie(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *st = D_overlay_3_0031A1D0;
    u8 *sqd = D_overlay_3_0031A1D8;
    u8 setup[0x14];
    u8 *temp_v0;

    if (squadsPrepareToProcessSquaddie(arg0) != 0) {
        if (!(*(s32 *)(st + 8) & 0x04000000) && *(u16 *)(sqd + 0x2C) != 0xE6) {
            if (TryToSetMission(0x12, 0x19, objTvTimes(mathRnd(0x78, 0x8C)) & 0xFF, 0U, 0U) != 0) {
                TryToSetAnim(0xB, 0x15, 0, 0);
            }
            /* asm: byte at +0xB of the word at +8 */
            st[0xB] = (u8)(st[0xB] | 4);
            st[0xB] = (u8)(st[0xB] | 3);
            *(s16 *)(setup + 0x0) = 0x29A;
            setup[0x2] = 0x10;
            setup[0x3] = 0;
            *(s16 *)(setup + 0x4) = (s16)(s32)*(f32 *)(obj + 0xC);
            *(s16 *)(setup + 0x6) = (s16)(s32)*(f32 *)(obj + 0x10);
            *(u8 **)(setup + 0xC) = obj;
            *(s16 *)(setup + 0x8) = (s16)(s32)*(f32 *)(obj + 0x14);
            temp_v0 = objSetupObject(setup, 1, NULL); /* asm: $a2 not set by caller */
            *(u8 **)(st + 0xC8) = temp_v0;
            if (temp_v0 != NULL) {
                *(s32 *)(temp_v0 + 0x3C) = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsElectrocuteSquaddie.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 GetBaddyData(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *temp_v0;
    s32 idx;

    temp_v0 = *(u8 **)(*(u8 **)(obj + 0x68) + 0x24);
    if (*(s16 *)(obj + 0x48) != 0x18 || temp_v0 == NULL) {
        return 0;
    }
    /* asm: $a1 is not set by the caller */
    idx = BaddyTypeToIndex(*(u16 *)(*(u8 **)(temp_v0 + 0x68) + 0x2C), NULL);
    D_overlay_3_0031A1DC = (s16)idx;
    if (idx != -1) {
        D_overlay_3_0031A1E0 = BaddyDataArray + (idx << 7);
    } else {
        D_overlay_3_0031A1E0 = NULL;
    }
    return (s32)D_overlay_3_0031A1E0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetBaddyData.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030D360_1EE2840(void *arg0) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *sqd = D_overlay_3_0031A1D8;
    u8 *cfg = D_overlay_3_0031A1E0;
    s32 maxIdx;
    u8 *node;
    u8 *nstate;
    u8 *hcls;
    u8 *tmp;
    u8 t4;

    if (*(s32 *)st & 1) {
        return;
    }
    *(s32 *)(st + 0x54) = -1;
    *(f32 *)(st + 0x68) = *(f32 *)(obj + 0xC);
    *(f32 *)(st + 0x6C) = *(f32 *)(obj + 0x10);
    *(f32 *)(st + 0x70) = *(f32 *)(obj + 0x14);
    *(s16 *)(st + 0x9C) = *(s16 *)obj;
    *(f32 *)(st + 0x2C) = *(f32 *)(obj + 0xC);
    *(f32 *)(st + 0x30) = *(f32 *)(obj + 0x10);
    *(f32 *)(st + 0x34) = *(f32 *)(obj + 0x14);
    maxIdx = 0;
    st[3] = (u8)(((squadsIsTribal(*(u16 *)(sqd + 0x2C)) * 8) & 8) | (st[3] & 0xF7));
    if (arg0 == NULL) {
        return;
    }
    *(s32 *)(st + 0xA8) = 0;
    if (*(u16 *)(sqd + 0x2C) == 0xE6) {
        refractInit();
    }
    tmp = *(u8 **)(sqd + 0x58);
    if (tmp != NULL) {
        nstate = *(u8 **)(tmp + 0x68);
        maxIdx = 1;
        node = *(u8 **)(nstate + 0x28);
        if (node != NULL) {
            do {
                t4 = nstate[0x15];
                if ((s32)t4 >= maxIdx) {
                    maxIdx = t4 + 1;
                }
                nstate = *(u8 **)(node + 0x68);
                node = *(u8 **)(nstate + 0x28);
            } while (node != NULL);
        }
        t4 = nstate[0x15];
        if ((s32)t4 >= maxIdx) {
            maxIdx = t4 + 1;
        }
        *(u8 **)(nstate + 0x28) = obj;
        *(s32 *)(st + 0x28) = 0;
    } else {
        *(u8 **)(sqd + 0x58) = obj;
    }
    st[0x15] = (u8)maxIdx;
    *(s32 *)sqd += 1;
    sqd[0x63] = (u8)(sqd[0x63] + 1);
    *(s16 *)(st + 0xA6) = *(s16 *)(sqd + 0x2A);
    *(u8 **)(st + 0x24) = (u8 *)arg0;
    st[0x14] = sqd[0x64];
    if ((sqd[0x1A] & 0xF) == 4 || (sqd[0x1A] & 0xF) == 5) {
        *(s16 *)obj = *(s16 *)(st + 0x1C);
        *(s16 *)(st + 0x46) = (s16)mathRnd(-0xBB8, 0xBB8);
    }
    if (sqd[0x1D] != 0) {
        st[0x17] = 0xA;
        *(s32 *)st |= 0x10;
    }
    *(s16 *)(st + 0x4E) = (s16)mathRnd(0, 0x7FFF);
    if (*(s32 *)st & 0x80000) {
        obj[0x3A] = sqd[0x62];
    }
    GetBaddyData(obj);
    if (D_overlay_3_0031A1E0 != NULL) {
        TryToSetAnim(0, 0x3B, 1, 3);
    }
    if (cfg[0x2B] == 5) {
        st[7] = (u8)(st[7] | 1);
    }
    if (sqd[0x2] != 0) {
        *(f32 *)(obj + 8) = (f32)sqd[0x2] * D_overlay_3_00319D74;
    } else {
        *(f32 *)(obj + 8) = 1.0f;
    }
    hcls = *(u8 **)(obj + 0x40);
    /* asm: class fields read as halfword/byte per the hit init call */
    hitInitObjectHit(obj, *(s16 *)(sqd + 0x2A), hcls[0xBA], 0x10, (s32)*(s16 *)(hcls + 0xB4),
                     (s32)*(s16 *)(hcls + 0xB6), (s32)*(s16 *)(hcls + 0xB8), *(f32 *)(hcls + 0xBC),
                     *(f32 *)(hcls + 0xC0), -1.0f, 1.0f, 0x11);
    *(f32 *)(obj + 0x34) = *(f32 *)(*(u8 **)(obj + 0x40) + 0xBC) * *(f32 *)(obj + 8);
    *(s32 *)st |= 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030D360_1EE2840.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *func_overlay_3_0030D810_1EE2CF0(void) {
    u8 setup[0x12];
    u8 sp4B;
    u8 sp4A;
    u8 *sq4 = D_overlay_3_0031A1D4;
    u8 *sqd;
    u8 *st;
    u8 *obj;
    u8 *node;
    f32 sp44;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    s16 sp52;
    u8 temp_v1;

    GetFormationInfo((s32)sq4, &sp4B, &sp4B, &sp4A);
    temp_v1 = D_overlay_3_0031A1D8[0x1A];
    if (((temp_v1 & 0xF) == 1) && (sp4A == 9 || sp4A == 8)) {
        D_overlay_3_0031A1D8[0x1A] = (u8)((temp_v1 & 0xF0) | 2);
        *(s32 *)(*(u8 **)(sq4 + 0x3C) + 0x24) = 2;
        GetFormationInfo((s32)sq4, &sp4B, &sp4B, &sp4A);
    }
    sqd = *(u8 **)(sq4 + 0x68);
    D_overlay_3_0031A1D8 = sqd;
    /* setup block: type id, flag byte, zeroed s16s, sq4 +0 position, pad */
    *(u16 *)(setup + 0x0) = *(u16 *)(sqd + 0x2C);
    setup[0x2] = 0x12;
    *(s16 *)(setup + 0x4) = 0;
    *(s16 *)(setup + 0x6) = 0;
    *(s16 *)(setup + 0x8) = 0;
    *(s16 *)(setup + 0xA) = 0;
    *(s16 *)(setup + 0xC) = 0;
    *(s16 *)(setup + 0xE) = *(s16 *)sq4;
    setup[0x10] = 0;
    obj = objSetupObject(setup, 1, NULL); /* asm: $a2 not set by caller */
    D_overlay_3_0031A1CC = obj;
    if (obj != NULL) {
        *(s32 *)(obj + 0x3C) = 0;
        st = *(u8 **)(obj + 0x68);
        D_overlay_3_0031A1D0 = st;
        if (sqd[0x1D] != 0) {
            sp44 = Cosf(sqd[0x1C] << 8);
            *(f32 *)(obj + 0x1C) = Cosf(sqd[0x1B] << 8) * sp44 * (f32)sqd[0x1D];
            *(f32 *)(obj + 0x20) = Sinf(sqd[0x1C] << 8) * (f32)sqd[0x1D];
            sp44 = Cosf(sqd[0x1C] << 8);
            *(f32 *)(obj + 0x24) = Sinf(sqd[0x1B] << 8) * sp44 * (f32)sqd[0x1D];
            if (sqd[0x76] != 0) {
                *(f32 *)(obj + 0x1C) += (f32)mathRnd(-(s32)sqd[0x76], (s32)sqd[0x76]);
                *(f32 *)(obj + 0x20) += (f32)mathRnd(-(s32)sqd[0x76], (s32)sqd[0x76]);
                *(f32 *)(obj + 0x24) += (f32)mathRnd(-(s32)sqd[0x76], (s32)sqd[0x76]);
            }
            *(s16 *)(st + 0x1C) = (s16)(Arctanf(*(f32 *)(obj + 0x1C), *(f32 *)(obj + 0x24)) - 0x8000);
        } else {
            *(f32 *)(obj + 0x1C) = 0.0f;
            *(f32 *)(obj + 0x20) = 0.0f;
            *(f32 *)(obj + 0x24) = 0.0f;
            *(s16 *)(st + 0x1C) = (s16)(0xC000 - (sqd[0x1B] << 8));
        }
        sp68 = *(f32 *)(obj + 0x1C) * *(f32 *)(obj + 0x1C);
        if ((sqd[0x1A] >> 4) == 2 || D_overlay_3_0031A1E0[0x2C] == 1) {
            *(s16 *)(st + 0x1E) = 0;
        } else {
            *(s16 *)(st + 0x1E) = (s16)(Arctanf(sqrtf(sp68), *(f32 *)(obj + 0x20)) - 0x8000);
        }
        *(f32 *)(st + 0x20) = sqrtf(*(f32 *)(obj + 0x20) * *(f32 *)(obj + 0x20) + sp68);
        *(s16 *)obj = *(s16 *)(st + 0x1C);
        *(s16 *)(obj + 0x2) = *(s16 *)(st + 0x1E);
        *(s16 *)(obj + 0x4) = 0;
        switch (sqd[0x1A] & 0xF) {
        case 1:
            sp68 = *(f32 *)(sqd + 0x48);
            sp64 = *(f32 *)(sqd + 0x4C);
            sp60 = *(f32 *)(sqd + 0x50);
            sp52 = *(s16 *)sq4;
            GetFormationInfo((s32)sq4, &sp4B, &sp4B, &sp4A);
            if (sp4A == 5) {
                *(f32 *)(sqd + 0x48) = *(f32 *)(sq4 + 0xC) + (f32)(sqd[0x10] * 0x10);
                *(f32 *)(sqd + 0x4C) = *(f32 *)(sq4 + 0x10) + (f32)(sqd[0x11] * 0x10);
                *(f32 *)(sqd + 0x50) = *(f32 *)(sq4 + 0x14) + (f32)(sqd[0x12] * 0x10);
                *(s16 *)sq4 = Arctanf(*(f32 *)(sqd + 0x48) - *(f32 *)(D_overlay_3_0031A1E8 + 0xC),
                                      *(f32 *)(sqd + 0x50) - *(f32 *)(D_overlay_3_0031A1E8 + 0x14));
                *(f32 *)(obj + 0x1C) = 0.0f;
                *(f32 *)(obj + 0x20) = 0.0f;
                *(f32 *)(obj + 0x24) = 0.0f;
                *(s16 *)obj = *(s16 *)sq4;
            } else {
                *(f32 *)(sqd + 0x48) = *(f32 *)(sq4 + 0xC);
                *(f32 *)(sqd + 0x4C) = *(f32 *)(sq4 + 0x10);
                *(f32 *)(sqd + 0x50) = *(f32 *)(sq4 + 0x14);
            }
            squadsGetFormationPosition((s32)sq4, st[0x15], (s32)&sp5C, (s32)&sp58, (s32)&sp54);
            *(f32 *)(sqd + 0x48) = sp68;
            *(f32 *)(sqd + 0x4C) = sp64;
            *(f32 *)(sqd + 0x50) = sp60;
            *(s16 *)sq4 = sp52;
            *(f32 *)(obj + 0xC) = sp5C;
            *(f32 *)(obj + 0x10) = sp58;
            *(f32 *)(obj + 0x14) = sp54;
            break;
        case 6:
            node = (u8 *)PatrolNodes + GetClosestPatrolNode(*(f32 *)(sq4 + 0xC), *(f32 *)(sq4 + 0x10),
                                                              *(f32 *)(sq4 + 0x14), 0) * 0x34;
            if (node != NULL) {
                *(f32 *)(obj + 0xC) = *(f32 *)node;
                *(f32 *)(obj + 0x10) = *(f32 *)(node + 4);
                *(f32 *)(obj + 0x14) = *(f32 *)(node + 8);
            } else {
                *(f32 *)(obj + 0xC) = *(f32 *)(sq4 + 0xC);
                *(f32 *)(obj + 0x10) = *(f32 *)(sq4 + 0x10);
                *(f32 *)(obj + 0x14) = *(f32 *)(sq4 + 0x14);
            }
            break;
        default:
            *(f32 *)(obj + 0xC) = *(f32 *)(sq4 + 0xC);
            *(f32 *)(obj + 0x10) = *(f32 *)(sq4 + 0x10);
            *(f32 *)(obj + 0x14) = *(f32 *)(sq4 + 0x14);
            break;
        }
        *(f32 *)(st + 0x2C) = *(f32 *)(obj + 0xC);
        *(f32 *)(st + 0x30) = *(f32 *)(obj + 0x10);
        *(f32 *)(st + 0x34) = *(f32 *)(obj + 0x14);
        return obj;
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030D810_1EE2CF0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquaddieInitFromRomdef(u8 *arg0, void *arg1) {
    u8 *romdef = (u8 *)arg1;
    u8 *obj = arg0;
    u8 *st;
    u8 *sqd;
    u8 temp_v1;

    D_overlay_3_0031A1CC = arg0;
    D_overlay_3_0031A1D0 = *(u8 **)(obj + 0x68);
    st = D_overlay_3_0031A1D0;
    if (*(s16 *)(romdef + 4) != 0 || *(s16 *)(romdef + 6) != 0 || *(s16 *)(romdef + 8) != 0) {
        st[1] = (u8)(st[1] | 8);
        temp_v1 = romdef[0x11];
        if (temp_v1 != 0) {
            D_overlay_3_0031A1D4 = GetSquadronFromIdentifier((s16)temp_v1);
            *(f32 *)(st + 0x38) = (f32)*(s16 *)(romdef + 0x12);
            *(f32 *)(st + 0x3C) = (f32)*(s16 *)(romdef + 0x14);
            *(f32 *)(st + 0x40) = (f32)*(s16 *)(romdef + 0x16);
        } else {
            D_overlay_3_0031A1D4 = objGetClosestControlType(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10),
                                                           *(s32 *)(obj + 0x14), 0x17);
            if (D_overlay_3_0031A1D4 != NULL) {
                D_overlay_3_0031A1D8 = *(u8 **)(D_overlay_3_0031A1D4 + 0x68);
                st[0x14] = D_overlay_3_0031A1D8[0x64];
                romdef[0x11] = D_overlay_3_0031A1D8[0x64];
            }
        }
        if (D_overlay_3_0031A1D4 != NULL) {
            *(u8 **)(st + 0x24) = D_overlay_3_0031A1D4;
            D_overlay_3_0031A1D8 = *(u8 **)(D_overlay_3_0031A1D4 + 0x68);
            obj[0x3A] = romdef[0x10];
        }
    } else {
        st[1] = (u8)(st[1] & 0xF7);
    }
    sqd = D_overlay_3_0031A1D8;
    if (D_overlay_3_0031A1D4 != NULL && sqd[0x33] == 0x1F && !(*(s32 *)st & 0x10)) {
        *(f32 *)(obj + 0x1C) = 0.0f;
        *(f32 *)(obj + 0x20) = 0.0f;
        *(f32 *)(obj + 0x24) = 0.0f;
        squadsPlaceOnAnimObject(obj);
    } else {
        *(f32 *)(obj + 0xC) = (f32)*(s16 *)(romdef + 4);
        *(f32 *)(obj + 0x10) = (f32)*(s16 *)(romdef + 6);
        *(f32 *)(obj + 0x14) = (f32)*(s16 *)(romdef + 8);
        *(f32 *)(obj + 0x1C) = Cosf(romdef[0xA] << 8) * Cosf(romdef[0xB] << 8) * (f32)romdef[0xC];
        *(f32 *)(obj + 0x20) = Sinf(romdef[0xB] << 8) * (f32)romdef[0xC];
        *(f32 *)(obj + 0x24) = Sinf(romdef[0xA] << 8) * Cosf(romdef[0xB] << 8) * (f32)romdef[0xC];
        func_overlay_3_00303CAC_1ED918C(obj);
        *(s16 *)obj = (s16)(romdef[0xD] << 8);
        *(s16 *)(obj + 0x2) = (s16)(romdef[0xE] << 8);
        *(s16 *)(obj + 0x4) = (s16)(romdef[0xF] << 8);
    }
    if (*(s32 *)st & 0x80000) {
        st[0x57] = romdef[0x18];
    } else {
        st[0x57] = sqd[0x8C];
        *(s32 *)(sqd + 0x8C) = *(s32 *)(sqd + 0x8C) + 1;
    }
    func_overlay_3_0030D360_1EE2840(D_overlay_3_0031A1D4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddieInitFromRomdef.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030E3CC_1EE38AC(void) {
    u8 *st = D_overlay_3_0031A1D0;
    u8 *obj = D_overlay_3_0031A1CC;
    u8 *cfg = D_overlay_3_0031A1E0;
    u8 *cls;
    u8 *trk;
    f32 nrmBuf[4];   /* intersect output: poly data at +0x48, normal at +0x4C..+0x54 */
    f32 *nrm = &nrmBuf[1];
    s32 hit;
    f32 spd;
    f32 var_f16;
    f32 vx, vy, vz;
    f32 dot;
    f32 f2;
    f32 snd_vol;
    SoundMask *snd;
    f32 sp40;

    if (*(s32 *)st & 0x02000000) {
        return;
    }
    cls = *(u8 **)(obj + 0x40);
    trk = *(u8 **)(cls + 0x50);
    *(f32 *)(st + 0x30) = *(f32 *)(st + 0x30) + *(f32 *)(trk + 0xC);
    *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) + *(f32 *)(trk + 0xC);
    trackMakePolylist(1, st + 0x2C, obj + 0xC, trk + 0xC, 0xCE002000, 0, 0);
    hit = trackGetIntersect(obj, st + 0x2C, obj + 0xC, *(s32 *)(trk + 0xC), *(s32 *)(trk + 0x10), nrmBuf);
    *(f32 *)(st + 0x30) = *(f32 *)(st + 0x30) - *(f32 *)(trk + 0xC);
    *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) - *(f32 *)(trk + 0xC);
    /* asm: the byte at +0x18 is set from a value not computed in this function (sp6D) */
    if (hit != 0) {
        if (*(u16 *)(st + 0x1A) == 0x13) {
            if (*(s32 *)st & 0x800) {
                st[0x4B] = 0;
                ClearMissionFields(2, 0);
                *(s32 *)st &= ~0x4;
                st[2] = (u8)(st[2] & 0xF7);
            }
        } else {
            *(s32 *)st &= ~0x4;
        }
    } else {
        *(s32 *)st |= 4;
        if (*(u16 *)(st + 0x1A) == 0x13) {
            st[2] = (u8)(st[2] | 8);
        }
    }
    *(f32 *)(st + 0x2C) = *(f32 *)(obj + 0xC);
    *(f32 *)(st + 0x30) = *(f32 *)(obj + 0x10);
    *(f32 *)(st + 0x34) = *(f32 *)(obj + 0x14);
    if (hit != 0) {
        vx = *(f32 *)(obj + 0x1C);
        vy = *(f32 *)(obj + 0x20);
        vz = *(f32 *)(obj + 0x24);
        spd = sqrtf(vx * vx + vy * vy + vz * vz);
        var_f16 = spd;
        if ((s8)cfg[0x27] < 0) {
            if (spd != 0.0f) {
                *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) / -spd;
                *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) / -spd;
                *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) / -spd;
            }
            vx = *(f32 *)(obj + 0x1C);
            var_f16 = spd * D_overlay_3_00319D78;
            dot = 2.0f * (nrm[2] * *(f32 *)(obj + 0x24) + (nrm[0] * vx + nrm[1] * *(f32 *)(obj + 0x20)));
            *(f32 *)(obj + 0x1C) = (nrm[0] * dot - *(f32 *)(obj + 0x1C)) * var_f16;
            *(f32 *)(obj + 0x20) = (nrm[1] * dot - *(f32 *)(obj + 0x20)) * var_f16;
            *(f32 *)(obj + 0x24) = (nrm[2] * dot - *(f32 *)(obj + 0x24)) * var_f16;
        } else {
            if (st[0x18] & 0x12) {
                *(f32 *)(obj + 0x20) = 0.0f;
            } else {
                *(f32 *)(obj + 0x20) = -*(f32 *)(obj + 0x20) * 0.5f;
            }
            *(s32 *)st &= ~0x4;
        }
        if (((*(u32 *)(st + 4) << 0xC) >> 0x1D) == 0) {
            sp40 = var_f16;
            amSndPlayXYZ(0x47U, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4U, st + 0xB8);
            snd = *(SoundMask **)(st + 0xB8);
            if (snd != NULL) {
                f2 = var_f16 * D_overlay_3_00319D7C;
                if (f2 > 1.0f) {
                    f2 = 1.0f;
                }
                snd_vol = 127.0f * f2;
                amSndSetVolXYZ(snd, (u8)(s32)snd_vol);
            }
        }
        st[5] = (u8)(st[5] | 0xE);
    }
    if ((*(s32 *)(cfg + 0x24) & 0x400) && !(*(s32 *)st & 0x1000)) {
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) - 1.0f;
    }
    *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * D_overlay_3_00319D80;
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) * D_overlay_3_00319D80;
    *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * D_overlay_3_00319D80;
    objMoveXYZ(obj, *(f32 *)(obj + 0x1C), *(f32 *)(obj + 0x20), *(f32 *)(obj + 0x24));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030E3CC_1EE38AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0030E9F0_1EE3ED0(u8 *arg0) {
    s32 flags;
    u8 *temp_v0_2;

    flags = *(s32 *)D_overlay_3_0031A1D0;
    if (!(flags & 0x200) || (flags & 0x10)) {
        if (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) == 0x67) {
            SlugBossMover(arg0, D_overlay_3_0031A1C8);
        } else {
            if ((*(u16 *)(D_overlay_3_0031A1D8 + 0x28) & 0x30) || (flags & 0x40000)) {
                ((void (*)(f32 *))func_overlay_3_0030E3CC_1EE38AC)(&D_overlay_3_0031A1C8); /* sig mismatch */
                func_overlay_3_00303CAC_1ED918C(arg0);
            } else {
                *(f32 *)(D_overlay_3_0031A1D0 + 0x2C) = *(f32 *)(arg0 + 0xC);
                *(f32 *)(D_overlay_3_0031A1D0 + 0x30) = *(f32 *)(arg0 + 0x10);
                *(f32 *)(D_overlay_3_0031A1D0 + 0x34) = *(f32 *)(arg0 + 0x14);
                objMoveXYZ(arg0, *(f32 *)(arg0 + 0x1C), *(f32 *)(arg0 + 0x20), *(f32 *)(arg0 + 0x24));
            }
            temp_v0_2 = *(u8 **)(D_overlay_3_0031A1D0 + 0xB4);
            if (temp_v0_2 != NULL) {
                *(f32 *)(temp_v0_2 + 0xC) = *(f32 *)(arg0 + 0xC);
                *(f32 *)(temp_v0_2 + 0x10) = *(f32 *)(arg0 + 0x10);
                *(f32 *)(temp_v0_2 + 0x14) = *(f32 *)(arg0 + 0x14);
                *(s16 *)(temp_v0_2 + 0x2E) = *(s16 *)(arg0 + 0x2E);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0030E9F0_1EE3ED0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Output is a list of s16 words written through a cursor (asm stack 0x88).
// Every store is "*cur++ = v". Helpers mathDiffAngle / GetSmoothAcceleration
// are called with the argument registers the asm sets; unset a2/a3 are 0.
s16 *SquaddieGetTiltList(u8 *arg0) {
    s16 *cur;
    s16 *list;
    u8 *anim;      /* sp64 */
    u8 *st;        /* D_overlay_3_0031A1D0 (overlay state) */
    u8 *cfg;       /* D_overlay_3_0031A1E0 (config) */
    u8 *X;
    u8 *Y;
    f32 speed;     /* sp60 */
    f32 scale;     /* sp78 */
    f32 magA;      /* sp80 */
    f32 extra;     /* sp6C */
    f32 dx, dy, dist, inv, mag, tmpf, fa2, fa3, sp2C;
    s32 special;
    s32 flagB;
    s32 sum, vv, vs;
    s32 ang, d, hi, lo, a1v, a2v, bits, i, j, found, base;
    s16 sp40, sp44;

    list = D_overlay_3_0031A148;
    cur = list;
    magA = 0.0f;
    scale = 0.0f;
    extra = 0.0f;
    D_overlay_3_0031A1CC = arg0;
    D_overlay_3_0031A1D0 = *(u8 **)(arg0 + 0x68);

    if ((D_overlay_3_0031A1D0[6] & 3) < 2) {
        goto fallback;
    }
    if (GetBaddyData(arg0) == 0) {
        goto fallback;
    }
    anim = GetAnimData(arg0);
    if (anim == NULL) {
        goto fallback;
    }

    speed = (f32)(s32)((u32)D_overlay_3_0031A1E0[0x28] << D_overlay_3_0031A1D0[9]);

    switch (D_overlay_3_0031A1DC) {
    case 0x21:
        *cur++ = 0x22;
        *cur++ = *(s16 *)(D_overlay_3_0031A1D0 + 0xA8);
        /* fallthrough */
    case 0x22:
        *cur++ = 2;
        *cur++ = -*(s16 *)arg0;
        *cur++ = 8;
        *cur++ = *(s16 *)arg0;
        break;
    case 0x17:
        DragonflyTilt(arg0, &cur);
        break;
    }

    st = D_overlay_3_0031A1D0;
    cfg = D_overlay_3_0031A1E0;

    special = (anim[3] == 0x3E);
    if (!special) {
        special = (st[0x19] == 5);
    }
    if (anim[3] == 0x3F) {
        *(s16 *)(st + 0x10) = 0;
    }

    sum = ((s32)cfg[0x37] + cfg[0x38] + cfg[0x39]) << 7;
    if (sum != 0) {
        vs = *(s16 *)(st + 0x0C);
        if (vs != 0) {
            vv = sum;
            mag = (f32)vs;
            if (special) {
                vv = sum + 0x2F80;
            }
            tmpf = (f32)vv;
            if (tmpf < mag) {
                mag = tmpf;
            } else {
                tmpf = (f32)(-vv);
                if (mag < tmpf) {
                    mag = tmpf;
                }
            }
            inv = 1.0f / (f32)(vv >> 7);
            scale = (f32)cfg[0x37] * inv;
            fa2 = (f32)cfg[0x38] * inv;
            fa3 = (f32)cfg[0x39] * inv;
            if (special) {
                extra = 95.0f * inv;
            }
            *cur++ = cfg[0x34] * 6 + 2;
            *cur++ = (s16)(mag * scale);
            *cur++ = cfg[0x35] * 6 + 2;
            *cur++ = (s16)(mag * fa2);
            *cur++ = cfg[0x36] * 6 + 2;
            *cur++ = (s16)(mag * fa3);
            magA = mag;
            if (special) {
                *cur++ = 0x2074;
                *cur++ = (s16)(mag * extra);
                magA = mag;
            }
        }
    }

    /* config word +0x24 bit 11 gates the state-flag update */
    flagB = (*(u32 *)(cfg + 0x24) >> 11) & 1;
    if (flagB != 0) {
        st[7] &= 0xBF;
        st[7] &= 0xDF;
        st[7] &= 0xEF;
        st[7] &= 0xF7;
        if ((((*(u32 *)(anim + 4)) >> 9) & 3) == 0) {
            st[7] &= 0xFB;
        } else {
            st[7] |= 4;
        }
        flagB = (*(u32 *)(cfg + 0x24) >> 11) & 1;
    }

    X = *(u8 **)(st + 0x64);
    bits = 0;
    if (flagB != 0 && X != NULL && (*(u16 *)(st + 0x04) & 1) != 0 &&
        (bits = ((*(u32 *)(anim + 4)) >> 9) & 3) != 0) {
        Y = *(u8 **)(X + 0x4C);
        if (bits & 1) {
            if (cfg[0x3A] != 0) {
                /* block A: obj-relative tilt from state 0x74/0x7C */
                dx = *(f32 *)(st + 0x74) - *(f32 *)(Y + 0x0C);
                dy = *(f32 *)(st + 0x7C) - *(f32 *)(Y + 0x14);
                sp2C = magA * scale;
                dist = sqrtf((dx * dx) + (dy * dy));
                sp40 = (s16)((sp2C + (f32)*(s16 *)D_overlay_3_0031A1CC) - 16384.0f);
                ang = mathDiffAngle(sp40, (s16)(-Arctanf(dy, dx)), 0, 0);
                hi = (s16)(cfg[0x3B] << 7);
                lo = (s16)((s32)cfg[0x3C] * -0x80);
                if (ang < hi && lo < ang) {
                    st[7] |= 0x10;
                }
                d = mathDiffAngle(*(s16 *)(st + 0x8C), (s16)ang, 0, 0);
                if (d < 0x200 && d >= -0x1FF) {
                    st[7] |= 0x40;
                }
                a1v = ang;
                if (hi < a1v) {
                    a1v = hi;
                    if (hi < lo) {
                        a1v = lo;
                    }
                } else if (a1v < lo) {
                    a1v = lo;
                }
                d = mathDiffAngle(*(s16 *)(st + 0x8C), (s16)a1v, 0, 0);
                *(s16 *)(st + 0x8E) = (s16)((f32)*(s16 *)(st + 0x8E) +
                    GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x8E), speed));
                *(s16 *)(st + 0x8C) = (s16)((f32)*(s16 *)(st + 0x8C) +
                    ((f32)(s32)(*(s16 *)(st + 0x8E) * iDeltaTime) * 0.5f));
                *cur++ = cfg[0x3A] * 6 + 2;
                *cur++ = *(s16 *)(st + 0x8C);

                sp44 = (s16)(-Arctanf(*(f32 *)(st + 0x78) - *(f32 *)(Y + 0x10), dist));
                d = mathDiffAngle(*(s16 *)(st + 0x90), sp44, 0, 0);
                a2v = sp44;
                if (d >= 0x200 || d < -0x1FF) {
                    st[7] &= 0xBF;
                }
                if (a2v > 0x2000) {
                    a2v = 0x2000;
                }
                if (a2v < -0x1000) {
                    a2v = -0x1000;
                }
                d = mathDiffAngle(*(s16 *)(st + 0x90), (s16)a2v, 0, 0);
                *(s16 *)(st + 0x92) = (s16)((f32)*(s16 *)(st + 0x92) +
                    GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x92), speed));
                *(s16 *)(st + 0x90) = (s16)((f32)*(s16 *)(st + 0x90) +
                    ((f32)(s32)(*(s16 *)(st + 0x92) * iDeltaTime) * 0.5f));
                *cur++ = cfg[0x3A] * 6;
                *cur++ = *(s16 *)(st + 0x90);
            }
            bits = ((*(u32 *)(anim + 4)) >> 9) & 3;
        }
        if ((bits & 2) != 0 && cfg[0x3D] != 0) {
            /* block B: obj-relative tilt from state 0x80/0x88 */
            dx = *(f32 *)(st + 0x80) - *(f32 *)(Y + 0x0C);
            dy = *(f32 *)(st + 0x88) - *(f32 *)(Y + 0x14);
            sp2C = magA * scale;
            dist = sqrtf((dx * dx) + (dy * dy));
            sp40 = (s16)((sp2C + (f32)*(s16 *)D_overlay_3_0031A1CC) - 16384.0f);
            ang = mathDiffAngle(sp40, (s16)(-Arctanf(dy, dx)), 0, 0);
            hi = (s16)(cfg[0x3E] << 7);
            lo = (s16)((s32)cfg[0x3F] * -0x80);
            if (ang < hi && lo < ang) {
                st[7] |= 0x08;
            }
            d = mathDiffAngle(*(s16 *)(st + 0x94), (s16)ang, 0, 0);
            if (d < 0x200 && d >= -0x1FF) {
                st[7] |= 0x20;
            }
            a1v = ang;
            if (hi < a1v) {
                a1v = hi;
                if (hi < lo) {
                    a1v = lo;
                }
            } else if (a1v < lo) {
                a1v = lo;
            }
            d = mathDiffAngle(*(s16 *)(st + 0x94), (s16)a1v, 0, 0);
            *(s16 *)(st + 0x96) = (s16)((f32)*(s16 *)(st + 0x96) +
                GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x96), speed));
            *(s16 *)(st + 0x94) = (s16)((f32)*(s16 *)(st + 0x94) +
                ((f32)(s32)(*(s16 *)(st + 0x96) * iDeltaTime) * 0.5f));
            *cur++ = cfg[0x3D] * 6 + 2;
            *cur++ = *(s16 *)(st + 0x94);

            sp44 = (s16)(-Arctanf(*(f32 *)(st + 0x84) - *(f32 *)(Y + 0x10), dist));
            d = mathDiffAngle(*(s16 *)(st + 0x98), sp44, 0, 0);
            a2v = sp44;
            if (d >= 0x200 || d < -0x1FF) {
                st[7] &= 0xDF;
            }
            if (a2v > 0x2000) {
                a2v = 0x2000;
            }
            if (a2v < -0x1000) {
                a2v = -0x1000;
            }
            d = mathDiffAngle(*(s16 *)(st + 0x98), (s16)a2v, 0, 0);
            *(s16 *)(st + 0x9A) = (s16)((f32)*(s16 *)(st + 0x9A) +
                GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x9A), speed));
            *(s16 *)(st + 0x98) = (s16)((f32)*(s16 *)(st + 0x98) +
                ((f32)(s32)(*(s16 *)(st + 0x9A) * iDeltaTime) * 0.5f));
            *cur++ = cfg[0x3D] * 6;
            *cur++ = *(s16 *)(st + 0x98);
        }
    } else {
        /* no-target path (asm 0x30FAB8): a1 for the second call is left over
           from the previous GetSmoothAcceleration in the asm; passed as 0 */
        if (cfg[0x3A] != 0) {
            d = mathDiffAngle(*(s16 *)(st + 0x8C), 0, 0, 0);
            *(s16 *)(st + 0x8E) = (s16)((f32)*(s16 *)(st + 0x8E) +
                GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x8E), speed));
            *(s16 *)(st + 0x8C) = (s16)((f32)*(s16 *)(st + 0x8C) +
                ((f32)(s32)(*(s16 *)(st + 0x8E) * iDeltaTime) * 0.5f));
            *cur++ = cfg[0x3A] * 6 + 2;
            *cur++ = *(s16 *)(st + 0x8C);
            d = mathDiffAngle(*(s16 *)(st + 0x90), 0, 0, 0);
            *(s16 *)(st + 0x92) = (s16)((f32)*(s16 *)(st + 0x92) +
                GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x92), speed));
            *(s16 *)(st + 0x90) = (s16)((f32)*(s16 *)(st + 0x90) +
                ((f32)(s32)(*(s16 *)(st + 0x92) * iDeltaTime) * 0.5f));
            *cur++ = cfg[0x3A] * 6 + 2;
            *cur++ = *(s16 *)(st + 0x8C);
        }
        if (cfg[0x3D] != 0) {
            d = mathDiffAngle(*(s16 *)(st + 0x94), 0, 0, 0);
            *(s16 *)(st + 0x96) = (s16)((f32)*(s16 *)(st + 0x96) +
                GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x96), speed));
            *(s16 *)(st + 0x94) = (s16)((f32)*(s16 *)(st + 0x94) +
                ((f32)(s32)(*(s16 *)(st + 0x96) * iDeltaTime) * 0.5f));
            *cur++ = cfg[0x3D] * 6 + 2;
            *cur++ = *(s16 *)(st + 0x94);
            d = mathDiffAngle(*(s16 *)(st + 0x98), 0, 0, 0);
            *(s16 *)(st + 0x9A) = (s16)((f32)*(s16 *)(st + 0x9A) +
                GetSmoothAcceleration(d, (f32)*(s16 *)(st + 0x9A), speed));
            *(s16 *)(st + 0x98) = (s16)((f32)*(s16 *)(st + 0x98) +
                ((f32)(s32)(*(s16 *)(st + 0x9A) * iDeltaTime) * 0.5f));
            *cur++ = cfg[0x3D] * 6 + 2;
            *cur++ = *(s16 *)(st + 0x94);
        }
    }

    if (*(u16 *)(st + 0x5A) == 0) {
        *cur = 0x1000;
        return list;
    }

    /* per-bit list: for each set bit i in state 0x5A, emit three 0x4000|idx*6 entries */
    for (i = 0; i != 0xF; i++) {
        if ((*(u16 *)(st + 0x5A) & (1 << i)) != 0) {
            found = -1;
            /* records at cfg + 8*j: key at +0x40, value at +0x43; scan j = count-1 .. 0 */
            for (j = (s32)cfg[0x29] - 1; j >= 0; j--) {
                if (cfg[0x40 + j * 8] == i) {
                    found = cfg[0x43 + j * 8];
                }
            }
            if (found != -1) {
                base = found * 6;
                *cur++ = (s16)(base | 0x4000);
                *cur++ = 0x20;
                *cur++ = (s16)((base + 2) | 0x4000);
                *cur++ = 0x20;
                *cur++ = (s16)((base + 4) | 0x4000);
                *cur++ = 0x20;
            }
        }
    }
    *cur = 0x1000;
    return list;

fallback:
    *cur = 0x1000;
    return list;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddieGetTiltList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsDecapitateSquaddie(u8 *arg0, u8 *arg1) {
    s32 *sp1C;
    u8 temp_v0;

    sp1C = *(s32 **)(arg1 + 0x68);
    *(u8 *)(*(u8 **)(arg0 + 0x4C) + 0x6) = 0;
    *(u8 **)(*(u8 **)(arg0 + 0x4C) + 0x3C) = arg1;
    GetBaddyData(arg0);
    squadsPlayerShootsSquaddie(arg0, *sp1C);
    temp_v0 = *(u8 *)(D_overlay_3_0031A1E0 + 0x2D);
    if (temp_v0 != 0x1F) {
        *(u8 *)(*(u8 **)(arg0 + 0x4C) + 0x31) = temp_v0;
        ((void (*)(void *))SquaddieBodyPartHit)(arg0); /* sig mismatch: asm passes only arg0 */
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsDecapitateSquaddie.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00310160_1EE5640(void) {
    u8 *anim;
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_cond;
    s32 temp_v0;
    s32 var_a3;
    s32 var_a0;
    s32 var_v0;
    u32 temp_t8;
    u8 *var_a2;

    anim = GetAnimData(D_overlay_3_0031A1CC);
    temp_f0 = *(f32 *)(D_overlay_3_0031A1CC + 0x28);
    *(u8 *)(D_overlay_3_0031A1D0 + 0x4) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x4) | 0xE0);
    *(u8 *)(D_overlay_3_0031A1D0 + 0x4) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x4) | 0x1C);
    var_a3 = 0;
    *(u16 *)(D_overlay_3_0031A1D0 + 0x4) = (u16)(*(u16 *)(D_overlay_3_0031A1D0 + 0x4) | 0x380);
    var_a0 = 3;
    *(u8 *)(D_overlay_3_0031A1D0 + 0x5) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x5) | 0x70);
    temp_t8 = (u32)((s32)*(s16 *)(anim + 0x4) << 0xA) >> 0x19;
    var_v0 = (s32)anim;
    if (temp_t8 != 0x7F) {
        var_a2 = D_overlay_3_00317A10 + (temp_t8 * 0x18) + 0xC;
        do {
            temp_f0_2 = *(f32 *)var_a2;
            temp_cond = *(f32 *)(D_overlay_3_0031A1CC + 0x28) <= temp_f0_2;
            var_a2 -= 4;
            if ((temp_cond && (temp_f0_2 <= (temp_f0 + (temp_f0 - *(f32 *)(D_overlay_3_0031A1D0 + 0x60))))) ||
                ((var_v0 = var_a0, (*(f32 *)(D_overlay_3_0031A1D0 + 0x60) == 0.0f)) &&
                 (var_v0 = var_a0, (temp_f0_2 == 0.0f)))) {
                temp_v0 = var_a3;
                *(u8 *)(D_overlay_3_0031A1D0 + 0x2) = (u8)((*(u8 *)(D_overlay_3_0031A1D0 + 0x2) & 0xFFFB) | 4);
                var_a3 += 1;
                if (var_a3 != 0) {
                    switch (temp_v0) {
                    case 1:
                        *(u8 *)(D_overlay_3_0031A1D0 + 0x4) = (u8)((((s32)var_a0 * 4) & 0x1C) | (*(u8 *)(D_overlay_3_0031A1D0 + 0x4) & 0xFFE3));
                        break;
                    case 2:
                        *(s16 *)(D_overlay_3_0031A1D0 + 0x4) = (s16)((((s32)var_a0 << 7) & 0x380) | ((u16)*(s16 *)(D_overlay_3_0031A1D0 + 0x4) & 0xFC7F));
                        break;
                    case 3:
                        *(u8 *)(D_overlay_3_0031A1D0 + 0x5) = (u8)((((s32)var_a0 * 0x10) & 0x70) | (*(u8 *)(D_overlay_3_0031A1D0 + 0x5) & 0xFF8F));
                        break;
                    }
                } else {
                    *(u8 *)(D_overlay_3_0031A1D0 + 0x4) = (u8)(((s32)var_a0 << 5) | (*(u8 *)(D_overlay_3_0031A1D0 + 0x4) & 0xFF1F));
                }
                var_v0 = var_a0;
            }
            var_a0 -= 1;
        } while (var_a0 != 0);
    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00310160_1EE5640.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00310354_1EE5834(void) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s16 sp26;
    f32 var_f0;
    s16 temp_v0;

    if ((*(s32 *)D_overlay_3_0031A1D0 & 0x40000000) || (*(s16 *)(D_overlay_3_0031A1D0 + 0xA) == 0x33)) {
        sp34 = *(f32 *)(D_overlay_3_0031A1CC + 0xC);
        sp30 = *(f32 *)(D_overlay_3_0031A1CC + 0x10);
        sp2C = *(f32 *)(D_overlay_3_0031A1CC + 0x14);
        sp28 = (f32)mathRnd(0, *(s32 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x24));
        temp_v0 = mathRnd(-0x8000, 0x7FFF);
        sp26 = temp_v0;
        *(f32 *)(D_overlay_3_0031A1CC + 0xC) = *(f32 *)(D_overlay_3_0031A1CC + 0xC) + (Sinf((s32)temp_v0) * sp28);
        if (*(s16 *)(D_overlay_3_0031A1D0 + 0xA) == 0x33) {
            var_f0 = 0.0f;
        } else {
            var_f0 = (f32)mathRnd(0, (s32)(2.0f * *(f32 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x28)));
        }
        *(f32 *)(D_overlay_3_0031A1CC + 0x10) = *(f32 *)(D_overlay_3_0031A1CC + 0x10) + var_f0;
        *(f32 *)(D_overlay_3_0031A1CC + 0x14) = *(f32 *)(D_overlay_3_0031A1CC + 0x14) + (Cosf((s32)sp26) * sp28);
        partUpdateTriggers(D_overlay_3_0031A1CC, iDeltaTime);
        *(f32 *)(D_overlay_3_0031A1CC + 0xC) = sp34;
        *(f32 *)(D_overlay_3_0031A1CC + 0x10) = sp30;
        *(f32 *)(D_overlay_3_0031A1CC + 0x14) = sp2C;
        return;
    }
    partUpdateTriggers(D_overlay_3_0031A1CC, iDeltaTime);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00310354_1EE5834.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsPlayerShootsSquaddie(u8 *arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = *(u8 **)(arg0 + 0x68);
    if (*(s16 *)(arg0 + 0x4A) != 0x112) {
        if (*(s32 *)temp_v0 & 8) {
            D_overlay_3_0031A12C = 1;
            D_overlay_3_0031A12B = 0xA;
        } else if (PlayersDisguise == 1) {
            D_overlay_3_0031A12C = 2;
            D_overlay_3_0031A12B = 0xA;
        }
        *(s32 *)(temp_v0 + 0x64) = arg1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsPlayerShootsSquaddie.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003105B8_1EE5A98(s32 arg0) {
    u8 *temp_v1;
    u8 *var_v0;

    var_v0 = *(u8 **)(D_overlay_3_0031A1D8 + 0x58);
    if (var_v0 != NULL) {
        do {
            temp_v1 = *(u8 **)(var_v0 + 0x68);
            var_v0 = *(u8 **)(temp_v1 + 0x28);
            *(s32 *)(temp_v1 + 0x64) = arg0;
        } while (var_v0 != NULL);
    }
    *(u8 *)(D_overlay_3_0031A1D8 + 0x30) = 3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003105B8_1EE5A98.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Raw offsets into the overlay globals: cur = D_overlay_3_0031A1CC (squaddie),
   D_overlay_3_0031A1D0 (state), D_overlay_3_0031A1D8 (config/object),
   D_overlay_3_0031A1E0 (config table). Loops with a decrement in the branch
   delay slot are written as the asm runs them (count iterations, index 0 included). */
void SquaddieControl(void *arg0, s32 arg1) {
    s16 sp166;
    s16 sp164;
    s16 sp160;
    s16 sp15E;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    u8 *sp138;
    f32 sp12C;
    s32 sp128;
    s32 sp124;
    f32 spFC[3];         /* out vector from trackGetIntersect; asm reads 0x104 = spFC[2] */
    s8 spF4;
    s8 spF3;
    s8 spF2;
    s16 spF0;
    s16 spEE;
    s16 spEC;
    s8 spEB;
    s8 spEA;
    s16 spE8;
    s32 spE0;
    void *spC4;
    f32 spC0;
    u8 spBF;
    u8 spBE;
    s16 spBC;
    s16 spBA;
    s16 spB8;
    s8 spB7;
    s8 spB6;
    s16 spB4;
    u8 spAE;
    u8 spAD;
    u8 spAC;
    u8 *spA8;
    s16 spA4;
    s16 spA2;
    s16 spA0;
    s8 sp9F;
    s8 sp9E;
    s16 sp9C;
    void *sp94;
    f32 sp90;
    s8 sp83;
    s16 sp80;
    s16 sp7E;
    s16 sp7C;
    s16 sp78;
    s16 sp72;
    s32 sp44;
    f32 var_f2 = 0.0f;

    sp144 = ((f32 *)arg0)[0x1C / 4];
    sp140 = ((f32 *)arg0)[0x24 / 4];
    if (squadsPrepareToProcessSquaddie(arg0) != 0) {
        iDeltaTime = arg1;
        D_overlay_3_0031A1C8 = (f32)arg1;
        D_overlay_3_0031A140 = -1;
        *(u8 *)(D_overlay_3_0031A1D0 + 0x3) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x3) & 0xFE);
        *(u8 *)(D_overlay_3_0031A1D0 + 0x3) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x3) & 0xFD);
        if (*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 9) {
            if (!(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x80000)) {
                *(s32 *)(D_overlay_3_0031A1D8 + 0x8C) -= 1;
            }
            RemoveSquaddie(D_overlay_3_0031A1CC);
        } else {
            sp15E = *(s16 *)(D_overlay_3_0031A1CC + 0x0);
            if (D_overlay_3_0031A1E4 != NULL) {
                if (*(u8 *)(D_overlay_3_0031A1E4 + 0x48) == 2) {
                    sp138 = *(u8 **)(*(u8 **)(D_overlay_3_0031A1E4 + 0x68) + 0x24);
                    if (*(u8 *)(*(u8 **)(sp138 + 0x68) + 0x10D) == 0) {
                        D_overlay_3_0031A1E4 = sp138;
                        *(u8 **)(D_overlay_3_0031A1D0 + 0x64) = D_overlay_3_0031A1E4;
                    }
                } else if (*(u8 *)(D_overlay_3_0031A1E4 + 0x48) == 1) {
                    u8 *tgtObj = *(u8 **)(D_overlay_3_0031A1E4 + 0x68);
                    u8 *next = *(u8 **)(tgtObj + 0x50C);
                    if ((*(u8 *)(tgtObj + 0x10D) != 0) && (next != NULL)) {
                        D_overlay_3_0031A1E4 = next;
                        *(u8 **)(D_overlay_3_0031A1D0 + 0x64) = D_overlay_3_0031A1E4;
                    }
                }
            }
            *(u16 *)(D_overlay_3_0031A1D0 + 0x4E) = (u16)(*(u16 *)(D_overlay_3_0031A1D0 + 0x4E) + 1);
            if (*(u8 *)(D_overlay_3_0031A1D0 + 0x4A) != 0) {
                *(u8 *)(D_overlay_3_0031A1D0 + 0x4A) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x4A) - 1);
            }
            {
                u32 cnt = (u32)(*(u32 *)(D_overlay_3_0031A1D0 + 0x4) << 0xC) >> 0x1D;
                if (cnt != 0) {
                    *(u8 *)(D_overlay_3_0031A1D0 + 0x5) = (u8)((((cnt - 1) * 2) & 0xE) | (*(u8 *)(D_overlay_3_0031A1D0 + 0x5) & 0xF1));
                }
            }
            {
                u8 nib = *(u8 *)(D_overlay_3_0031A1D0 + 0x13);
                u32 cnt = nib >> 4;
                if (cnt != 0) {
                    *(u8 *)(D_overlay_3_0031A1D0 + 0x13) = (u8)(((cnt - 1) * 0x10) | (nib & 0x0F));
                }
            }
            if (*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x40000000) {
                *(s32 *)(D_overlay_3_0031A1CC + 0x84) = 1;
                {
                    u8 *sub = *(u8 **)(D_overlay_3_0031A1CC + 0x4C);
                    s16 hp = *(s16 *)(sub + 0x6);
                    if (hp > 0) {
                        f32 dmg = (f32)*(s16 *)(D_overlay_3_0031A1D8 + 0x2A) * D_overlay_3_00319D84;
                        if (dmg < 1.0f) {
                            dmg = 1.0f;
                        }
                        *(s16 *)(sub + 0x6) = (s16)(s32)((f32)hp - (dmg * D_overlay_3_0031A1C8));
                        sub = *(u8 **)(D_overlay_3_0031A1CC + 0x4C);
                        if ((*(s16 *)(sub + 0x6) <= 0) && !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 8)) {
                            *(u16 *)(sub + 0x8) = (u16)((*(u16 *)(sub + 0x8) & 0xFFF0) | 6);
                            SquaddiePassesAway(D_overlay_3_0031A1CC);
                        }
                    }
                }
            }
            if (*(u8 **)(D_overlay_3_0031A1D0 + 0xB4) != NULL) {
                objFreeObject(*(u8 **)(D_overlay_3_0031A1D0 + 0xB4));
                *(u8 **)(D_overlay_3_0031A1D0 + 0xB4) = NULL;
            }
            if ((*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 3) && (*(u8 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x40) + 0x14) & 0x80)) {
                u8 *tgt = *(u8 **)(D_overlay_3_0031A1D0 + 0x64);
                if ((tgt != NULL) && ((*(u8 *)(tgt + 0x48) == 1) || (*(u8 *)(tgt + 0x48) == 2))) {
                    CheckLineOfSight(D_overlay_3_0031A1CC);
                }
            }
            if (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) == 0x8D) {
                ReallyAddInterestingEvent((s32)(D_overlay_3_0031A1CC + 1), (s16)*(f32 *)(D_overlay_3_0031A1CC + 0xC), (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x10), (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x14), 1, 8, 0);
                ReallyAddInterestingEvent((s32)D_overlay_3_0031A1CC, (s16)*(f32 *)(D_overlay_3_0031A1CC + 0xC), (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x10), (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x14), 4, 9, 0);
            }
            if ((*(u16 *)(D_overlay_3_0031A1D8 + 0x28) & 0x800) && (*(u8 *)(D_overlay_3_0031A1D8 + 0x75) == 0) && !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 8)) {
                if (D_800F31E1[*(u16 *)(D_overlay_3_0031A1CC + 0x2E)] != 0) {
                    *(u8 *)(D_overlay_3_0031A1D0 + 0x1) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x1) | 1);
                    *(u8 *)(D_overlay_3_0031A1D0 + 0x2) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x2) & 0x7F);
                    *(u16 *)(D_overlay_3_0031A1D0 + 0x58) = 0x96;
                } else if (*(u16 *)(D_overlay_3_0031A1D0 + 0x0) & 1) {
                    *(u16 *)(D_overlay_3_0031A1D0 + 0x58) = (u16)(*(u16 *)(D_overlay_3_0031A1D0 + 0x58) - 1);
                    if (*(u16 *)(D_overlay_3_0031A1D0 + 0x58) == 0) {
                        *(u8 *)(D_overlay_3_0031A1D0 + 0x2) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x2) | 0x80);
                    }
                }
            }
            if (*(u16 *)(D_overlay_3_0031A1D0 + 0x1A) != 7) {
                u8 *entry = (u8 *)func_overlay_3_003062A0_1EDB780();
                sp138 = entry;
                if (entry != NULL) {
                    u8 *t5 = (u8 *)(*(u32 *)(entry + 0xC) & ~3);
loop_48:
                    switch (*(u8 *)(entry + 0x7)) {         /* switch 1: cases 1..9 */
                    case 1:
                        if ((t5 != NULL) && (*(u8 *)(t5 + 0x48) == 1) && (*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 2) && (*(u8 *)(D_overlay_3_0031A1D8 + 0x91) & 1)) {
                            ((void (*)(void *, s32, s32, void *))func_overlay_3_003105B8_1EE5A98)(t5, 4, 0x21, D_overlay_3_0031A1D8); /* sig mismatch */
                            goto block_84;
                        }
                        if ((*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 2) && (*(u8 *)(D_overlay_3_0031A1D8 + 0x32) != 0x21) && (*(u16 *)(D_overlay_3_0031A1D0 + 0x1A) != 0xF)) {
                            if ((t5 == NULL) || (*(u8 *)(t5 + 0x48) != 1) || !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 8) || !(*(u16 *)(D_overlay_3_0031A1D0 + 0x4) & 1)) {
                                if ((s16)(((s32)(entry - D_overlay_3_0031A1F8)) >> 4) != *(s8 *)(D_overlay_3_0031A1D0 + 0x54)) {
                                    u32 cnt = ((*(u8 *)(D_overlay_3_0031A1D0 + 0x8) >> 4) + 1) & 0xF;
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x8) = (u8)((cnt * 0x10) | (*(u8 *)(D_overlay_3_0031A1D0 + 0x8) & 0x0F));
                                    if (cnt >= 6) {
                                        *(u8 *)(entry + 0x7) = 4;
                                        goto loop_48;
                                    }
                                    goto block_66;
                                }
block_66:
                                TryToSetMission(0xE, 0xF, 0U, 0U, 0U);
block_84:
                                ;
                            }
                        }
                        break;
                    case 2:
                    case 8:
                        if (((*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 2) || (*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 3)) &&
                            ((*(u8 *)(D_overlay_3_0031A1D8 + 0x32) == 0xE) || (*(u8 *)(D_overlay_3_0031A1D8 + 0x32) == 0xF) ||
                             (*(u8 *)(D_overlay_3_0031A1D8 + 0x32) == 9) || (*(u8 *)(D_overlay_3_0031A1D8 + 0x32) == 0xA) ||
                             (*(u8 *)(D_overlay_3_0031A1D8 + 0x32) == 0xB))) {
                            if ((s16)(((s32)(entry - D_overlay_3_0031A1F8)) >> 4) != *(s8 *)(D_overlay_3_0031A1D0 + 0x54)) {
                                u32 cnt = ((*(u8 *)(D_overlay_3_0031A1D0 + 0x8) >> 4) + 1) & 0xF;
                                *(u8 *)(D_overlay_3_0031A1D0 + 0x8) = (u8)((cnt * 0x10) | (*(u8 *)(D_overlay_3_0031A1D0 + 0x8) & 0x0F));
                                if (cnt >= 6) {
                                    *(u8 *)(entry + 0x7) = 4;
                                    goto loop_48;
                                }
                            }
                            *(u8 *)(D_overlay_3_0031A1D0 + 0x4A) = 0U;
                            TryToSetMission(0xE, 0xF, 0U, 0U, 0U);
                            goto block_84;
                        }
                        break;
                    case 4:
                        if (*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 2) {
                            if (!(*(u16 *)(D_overlay_3_0031A1D0 + 0x4) & 1)) {
                                *(u8 *)(D_overlay_3_0031A1D8 + 0x30) = 3U;
                            }
                        }
                        break;
                    case 5:
                        *(u8 *)(D_overlay_3_0031A1D8 + 0x30) = 4U;
                        break;
                    case 7:
                        *(u8 *)(D_overlay_3_0031A1D8 + 0x33) = 0x21;
                        *(u16 *)(D_overlay_3_0031A1D8 + 0x2E) = 0x32;
                        break;
                    case 9:
                        func_overlay_3_003044F4_1ED99D4(D_overlay_3_0031A1CC);
                        *(u8 **)(D_overlay_3_0031A1D0 + 0x64) = t5;
                        TryToSetMission(0xE, 0x18, 0U, 0U, 0U);
                        goto block_84;
                    }
                    *(s8 *)(D_overlay_3_0031A1D0 + 0x54) = (s8)((s32)(sp138 - D_overlay_3_0031A1F8) >> 4);
                } else {
                    *(s8 *)(D_overlay_3_0031A1D0 + 0x54) = -1;
                }
            }
            /* asm: a1/a2 are not set on this path; passed as 0 */
            SquaddieLightAndAnimate((s32)D_overlay_3_0031A1CC, NULL, 0);
            {
                u16 mask = *(u16 *)(D_overlay_3_0031A1D0 + 0xA0);
                if (mask != 0) {
                    s32 k = *(u8 *)(D_overlay_3_0031A1E0 + 0x29);
                    if (k != 0) {
                        s32 t2;
                        k -= 1;
                        t2 = k * 8;
                        for (;;) {
                            u8 *ent = D_overlay_3_0031A1E0 + t2;
                            u8 *sub = ent + 0x40;
                            if (((1 << ent[0x40]) & mask) && (sub != NULL)) {
                                u8 rec[0x14];
                                *(s16 *)(rec + 0x0) = 0x36;
                                rec[0x2] = 0x14;
                                rec[0x3] = 0;
                                *(s16 *)(rec + 0x4) = 0;
                                *(s16 *)(rec + 0x6) = 0;
                                *(s16 *)(rec + 0x8) = 0;
                                rec[0xA] = sub[0x4];
                                rec[0xB] = sub[0x5];
                                *(f32 *)(rec + 0xC) = *(f32 *)(D_overlay_3_0031A1CC + 0x10);
                                *(u8 **)(rec + 0x10) = D_overlay_3_0031A1CC;
                                {
                                    u8 *spawned = ((void *(*)(void *, s32))objSetupObject)(rec, 1); /* sig mismatch: asm passes 2 args */
                                    if (spawned != NULL) {
                                        *(s32 *)(spawned + 0x3C) = 0;
                                    }
                                }
                            }
                            mask = *(u16 *)(D_overlay_3_0031A1D0 + 0xA0);
                            if (k == 0) {
                                break;
                            }
                            k -= 1;
                            t2 -= 8;
                        }
                    }
                    *(u16 *)(D_overlay_3_0031A1D0 + 0x5A) = (u16)(*(u16 *)(D_overlay_3_0031A1D0 + 0x5A) | mask);
                    *(u16 *)(D_overlay_3_0031A1D0 + 0xA0) = 0U;
                }
            }
            {
                u16 mask = *(u16 *)(D_overlay_3_0031A1D0 + 0xA2);
                if (mask != 0) {
                    s32 k = *(u8 *)(D_overlay_3_0031A1E0 + 0x29);
                    if ((FreeRAM >= 0xC001) && (k != 0)) {
                        s32 t2;
                        k -= 1;
                        t2 = k * 8;
                        for (;;) {
                            u8 *ent = D_overlay_3_0031A1E0 + t2;
                            if ((1 << ent[0x40]) & mask) {
                                u8 *pp = *(u8 **)(D_overlay_3_0031A1CC + 0x6C);
                                u8 *p2 = *(u8 **)pp;
                                u8 *p3 = *(u8 **)p2;
                                if (p3[0x2F] == 0) {
                                    return; /* asm: beqz to function epilogue */
                                }
                                {
                                    u8 *vec = *(u8 **)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x3C);
                                    f32 f12 = 3.0f;
                                    u8 *ent2 = ent + 0x40;
                                    if (vec != NULL) {
                                        f32 vx = *(f32 *)(vec + 0x1C);
                                        f32 vy = *(f32 *)(vec + 0x20);
                                        f32 vz = *(f32 *)(vec + 0x24);
                                        f12 = 3.0f / sqrtf((vx * vx) + (vy * vy) + (vz * vz));
                                        if (f12 > 1000.0f) {
                                            f12 = 1000.0f;
                                        }
                                    }
                                    if (ent2 != NULL) {
                                        s16 t0_2 = ent2[0x6];
                                        if (t0_2 == 0xE) {
                                            u8 rec[0x14];
                                            u8 *rv;
                                            *(s16 *)(rec + 0x0) = 0x89;
                                            rec[0x2] = 0x14;
                                            rec[0x3] = 0;
                                            *(s16 *)(rec + 0x4) = 0;
                                            *(s16 *)(rec + 0x6) = 0;
                                            *(s16 *)(rec + 0x8) = 0;
                                            rec[0xA] = ent2[0x4];
                                            rec[0xB] = ent2[0x5];
                                            *(f32 *)(rec + 0xC) = *(f32 *)(D_overlay_3_0031A1CC + 0x10);
                                            *(u8 **)(rec + 0x10) = D_overlay_3_0031A1CC;
                                            rv = ((u8 *(*)(void *, s32))objSetupObject)(rec, 1); /* sig mismatch: asm passes 2 args */
                                            if ((rv != NULL) && (vec != NULL)) {
                                                *(f32 *)(rv + 0x1C) = *(f32 *)(vec + 0x1C) * f12;
                                                *(f32 *)(rv + 0x20) = *(f32 *)(vec + 0x20) * f12;
                                                *(f32 *)(rv + 0x24) = *(f32 *)(vec + 0x24) * f12;
                                            }
                                        } else {
                                            partModelObjEmitModelPart(f12, arg0, *(f32 *)(vec + 0x1C) * f12, *(f32 *)(vec + 0x20) * f12, *(f32 *)(vec + 0x24) * f12, t0_2);
                                        }
                                    }
                                    D_overlay_3_0031A140 = k;
                                    D_overlay_3_0031A144 = mathRnd(2, 4);
                                }
                            }
                            mask = *(u16 *)(D_overlay_3_0031A1D0 + 0xA2);
                            if (FreeRAM < 0xC001) {
                                break;
                            }
                            if (k == 0) {
                                break;
                            }
                            k -= 1;
                            t2 -= 8;
                        }
                    }
                    *(u16 *)(D_overlay_3_0031A1D0 + 0x5A) = (u16)(*(u16 *)(D_overlay_3_0031A1D0 + 0x5A) | mask);
                    *(u16 *)(D_overlay_3_0031A1D0 + 0xA2) = 0U;
                }
            }
            /* block_119: no unkA0/unkA2 bits left to process */
            {
                s16 a0v = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                s16 v1v;
                *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6) = *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6);
                v1v = *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6);
                if (a0v < v1v) {
                    *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6) = a0v;
                    a0v = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                    v1v = *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6);
                }
                if (v1v != a0v) {
                    *(u8 *)(D_overlay_3_0031A1D0 + 0x8) = (u8)((*(u8 *)(D_overlay_3_0031A1D0 + 0x8) & 0x0F) | 0x50);
                    if (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) == 0xE6) {
                        *(u16 *)(D_overlay_3_0031A1D0 + 0xA4) = (u16)(*(u16 *)(D_overlay_3_0031A1D0 + 0xA4) | (1 << *(u8 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x31)));
                    } else {
                        s32 t1 = *(u8 *)(D_overlay_3_0031A1E0 + 0x29);
                        if (t1 != 0) {
                            s32 k = t1 - 1;
                            u8 *ent = D_overlay_3_0031A1E0 + k * 8;
                            for (;;) {
                                if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x31) == ent[0x41]) {
                                    *(u16 *)(D_overlay_3_0031A1D0 + 0xA4) = (u16)(*(u16 *)(D_overlay_3_0031A1D0 + 0xA4) | (1 << ent[0x47]));
                                    break;
                                }
                                if (k == 0) {
                                    break;
                                }
                                k -= 1;
                                ent -= 8;
                            }
                        }
                    }
                    if (*(u8 *)(D_overlay_3_0031A1D8 + 0x30) == 2) {
                        *(u8 *)(D_overlay_3_0031A1D8 + 0x30) = 3U;
                        *(s32 *)(D_overlay_3_0031A1D0 + 0x10) = 0;
                    }
                    *(s16 *)(D_overlay_3_0031A1D0 + 0xA6) = *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6);
                    a0v = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                    if (a0v <= 0) {
                        u8 *tab = D_overlay_3_00319460 + D_overlay_3_0031A1DC * 8;
                        u16 snd = *(u16 *)(tab + 0x2);
                        if (snd != 0) {
                            u8 *old = *(u8 **)(D_overlay_3_0031A1D0 + 0xBC);
                            u8 range = tab[0x5];
                            if (old != NULL) {
                                amSndStopXYZ((s32)old);
                            }
                            amSndPlayXYZ((u16)((mathRnd(0, range - 1) + snd) & 0xFFFF), *(f32 *)(D_overlay_3_0031A1CC + 0xC), *(f32 *)(D_overlay_3_0031A1CC + 0x10), *(f32 *)(D_overlay_3_0031A1CC + 0x14), 4U, D_overlay_3_0031A1D0 + 0xBC);
                        }
                        if (*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 8) {
                            mainSetTribalStatus(*(u8 *)(D_overlay_3_0031A1D8 + 0x64), 2);
                            instShowBearBar();
                        }
                        if (!(*(u16 *)(D_overlay_3_0031A1D8 + 0x28) & 4) && (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) != 0x2CE)) {
                            levelSetObjectFlag(*(u8 *)(D_overlay_3_0031A1D0 + 0x57));
                        }
                        a0v = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                    } else if (!(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x40000000)) {
                        u8 *tab = D_overlay_3_00319460 + D_overlay_3_0031A1DC * 8;
                        u16 snd = *(u16 *)(tab + 0x0);
                        if (snd != 0) {
                            u8 *old = *(u8 **)(D_overlay_3_0031A1D0 + 0xBC);
                            u8 range = tab[0x4];
                            if (old != NULL) {
                                amSndStopXYZ((s32)old);
                            }
                            amSndPlayXYZ((u16)((mathRnd(0, range - 1) + snd) & 0xFFFF), *(f32 *)(D_overlay_3_0031A1CC + 0xC), *(f32 *)(D_overlay_3_0031A1CC + 0x10), *(f32 *)(D_overlay_3_0031A1CC + 0x14), 4U, D_overlay_3_0031A1D0 + 0xBC);
                            a0v = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                        }
                    }
                    {
                        s16 v14 = *(s16 *)(D_overlay_3_0031A1D8 + 0x2A);
                        s32 a1s = v14 >> 3;
                        s16 v1s = (s16)a1s;
                        s16 a2s;
                        s32 at, at2, at3;
                        if ((s16)a1s >= 0xA01) {
                            v1s = 0xA00;
                        }
                        if (v1s < 0x100) {
                            v1s = 0x100;
                            if (v14 == 0x100) {
                                v1s = -0x8000;
                            }
                        }
                        a2s = (s16)(a1s * -1);
                        at = a2s < -0x1FF;
                        if (a2s < -0xA00) {
                            a2s = -0xA00;
                            at = -0xA00 < -0x1FF;
                        }
                        at2 = a2s < a0v;
                        if (at == 0) {
                            a2s = -0x200;
                            at2 = a0v > -0x200;
                        }
                        if ((at2 != 0) && (v1s >= a0v) && ((*(u8 *)(D_overlay_3_0031A1E0 + 0x24) & 0x10) || (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) == 0x112)) && !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x40000000)) {
                            *(s16 *)(D_overlay_3_0031A1D0 + 0xA6) = (s16)(v1s + 1);
                            *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6) = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                            a0v = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                        }
                        if (a0v <= 0) {
                            u16 id = *(u16 *)(D_overlay_3_0031A1D8 + 0x2C);
                            s32 s0 = 0;
                            if (id != 0x67) {
                                if (id == 0x144) {
                                    s0 = 0x178;
                                }
                            } else {
                                s0 = 0x172;
                            }
                            at3 = a2s < a0v;
                            if (s0 != 0) {
                                sp166 = v1s;
                                sp164 = a2s;
                                squadsChangeLevel(s0, objTvTimes(0x1E));
                                a0v = *(s16 *)(D_overlay_3_0031A1D0 + 0xA6);
                                at3 = a2s < a0v;
                            }
                        } else {
                            at3 = a2s < a0v;
                        }
                        if ((at3 == 0) && (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) != 0x144)) {
                            func_overlay_3_00309CE4_1EDF1C4(D_overlay_3_0031A1CC);
                            squadsKillSquaddie(D_overlay_3_0031A1CC);
                        } else {
                            if (a0v <= 0) {
                                u32 a2_3;
                                *(s8 *)(D_overlay_3_0031A1CC + 0x9F) = 3;
                                a2_3 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                if (!(a2_3 & 0x40000000)) {
                                    if (!(*(u32 *)(D_overlay_3_0031A1D0 + 0x8) & 0x04000000)) {
                                        ((void (*)(void *))SquaddieBodyPartHit)(D_overlay_3_0031A1CC); /* sig mismatch */
                                        a2_3 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                    }
                                }
                                if ((a2_3 << 0x13) & 0x80000000) {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x2) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x2) & 0xEF);
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x1) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x1) | 4);
                                    *(u32 *)(D_overlay_3_0031A1D0 + 0x0) |= 4;
                                }
                                {
                                    u8 temp_t6 = *(u8 *)(D_overlay_3_0031A1D8 + 0x34) & 3;
                                    if (temp_t6 != 0) {
                                        s16 a0x = *(s16 *)(D_overlay_3_0031A1CC + 0x0);
                                        if ((temp_t6 == 2) || ((temp_t6 == 3) && !(*(u32 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x8) & 0x20000000))) {
                                            a0x -= 0x8000;
                                        }
                                        ((void (*)(s16, f32, s32))func_overlay_3_00303D44_1ED9224)(a0x, 10.0f, a2_3); /* sig mismatch */
                                        *(f32 *)(D_overlay_3_0031A1CC + 0x20) = *(f32 *)(D_overlay_3_0031A1CC + 0x20) + 5.0f;
                                        func_overlay_3_00303CAC_1ED918C(D_overlay_3_0031A1CC);
                                        *(u8 *)(D_overlay_3_0031A1D0 + 0x1) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x1) | 4);
                                        *(u32 *)(D_overlay_3_0031A1D0 + 0x0) |= 4;
                                    }
                                }
                                *(u8 *)(D_overlay_3_0031A1D0 + 0x1B) = 0;
                                TryToSetAnim(0xC, 0x21, 0, 0);
                                if (*(u8 *)(D_overlay_3_0031A1D0 + 0x4B) == 0xD) {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x4B) = 0xCU;
                                }
                                switch (*(u8 *)(D_overlay_3_0031A1E0 + 0x2A)) {  /* switch 2: irregular, cases 1 and 5 */
                                case 1:
                                    *(f32 *)(D_overlay_3_0031A1CC + 0x20) = *(f32 *)(D_overlay_3_0031A1CC + 0x20) + 14.0f;
                                    if (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) == 0x150) {
                                        *(s16 *)(D_overlay_3_0031A1D0 + 0x44) = (s16)mathRnd(-0xBB8, 0xBB8);
                                        *(s16 *)(D_overlay_3_0031A1D0 + 0x46) = (s16)mathRnd(-0x15E, 0x15E);
                                        *(s16 *)(D_overlay_3_0031A1D0 + 0x48) = 0;
                                    } else {
                                        *(s16 *)(D_overlay_3_0031A1D0 + 0x44) = (s16)mathRnd(-0xBB8, 0xBB8);
                                        *(s16 *)(D_overlay_3_0031A1D0 + 0x46) = (s16)mathRnd(-0xBB8, 0xBB8);
                                        *(s16 *)(D_overlay_3_0031A1D0 + 0x48) = (s16)mathRnd(-0xBB8, 0xBB8);
                                    }
                                    *(s32 *)(D_overlay_3_0031A1CC + 0x84) = (*(s32 *)(D_overlay_3_0031A1CC + 0x84) | 2);
                                    break;
                                case 5:
                                    ((void (*)(void *, s32))squadsElectrocuteSquaddie)(D_overlay_3_0031A1CC, 5); /* sig mismatch */
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x52) = (u8)objTvTimes(mathRnd(0x3C, 0x5A));
                                    break;
                                }
                            } else if ((v1s >= a0v) && (func_overlay_3_00304614_1ED9AF4(0x25, 1) != -1)) {
                                *(s8 *)(D_overlay_3_0031A1CC + 0x9F) = 3;
                                if (!(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x40000000) && !(*(u32 *)(D_overlay_3_0031A1D0 + 0x8) & 0x04000000)) {
                                    ((void (*)(void *))SquaddieBodyPartHit)(D_overlay_3_0031A1CC); /* sig mismatch */
                                }
                                if (TryToSetMission(0xA, 0xC, 0U, 0U, 0U) != 0) {
                                    if (arg1 < 4) {
                                        u8 rec[0x14];
                                        u8 *spawned;
                                        *(s16 *)(rec + 0x0) = 0x1B2;
                                        *(s16 *)(rec + 0x4) = (s16)*(f32 *)(D_overlay_3_0031A1CC + 0xC);
                                        *(s16 *)(rec + 0x6) = (s16)(*(f32 *)(D_overlay_3_0031A1CC + 0x10) + 50.0f);
                                        rec[0xB] = 0x40;
                                        *(s16 *)(rec + 0x8) = (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x14);
                                        spawned = ((u8 *(*)(void *, s32))objSetupObject)(rec, 1); /* sig mismatch: asm passes 2 args */
                                        if (spawned != NULL) {
                                            *(s32 *)(spawned + 0x3C) = 0;
                                            *(u8 **)(spawned + 0x8C) = D_overlay_3_0031A1CC;
                                        }
                                    }
                                    TryToSetAnim(0xD, 0x25, 0, 0);
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x2) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x2) | 1);
                                }
                            } else {
                                s32 v0_2 = 0;
                                s32 cnt = *(u8 *)(D_overlay_3_0031A1E0 + 0x29);
                                if (cnt > 0) {
                                    u8 *ent = D_overlay_3_0031A1E0;
                                    for (;;) {
                                        if (*(u8 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x31) == ent[0x41]) {
                                            D_overlay_3_0031A140 = v0_2;
                                            D_overlay_3_0031A144 = 1;
                                            break;
                                        }
                                        v0_2 += 1;
                                        ent += 8;
                                        if (v0_2 >= cnt) {
                                            break;
                                        }
                                    }
                                }
                                {
                                    u8 *sub = *(u8 **)(D_overlay_3_0031A1CC + 0x4C);
                                    if ((*(u32 *)(sub + 0x8) & 0x10000000) || !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 8)) {
                                        u8 v31 = *(u8 *)(sub + 0x31);
                                        if ((s32)v31 < 0xA) {
                                            TryToSetAnim(0xA, v31 + 0x16, 0x16, 0);
                                        }
                                    }
                                }
                            }
                        }
                        goto block_217;
                    }
                } else {
block_217:
                    if (*(u32 *)(D_overlay_3_0031A1D0 + 0x8) & 0x04000000) {
                        *(s8 *)(D_overlay_3_0031A1CC + 0x9F) = 2;
                    }
                    if (*(s16 *)(D_overlay_3_0031A1D0 + 0xA6) <= 0) {
                        u8 a1v;
                        TryToUpdateAnim(0xC, 1.0f);
                        a1v = *(u8 *)(D_overlay_3_0031A1E0 + 0x2A);
                        switch (a1v) {     /* switch 3: irregular, cases 0,1,4,5 */
                        case 0:
                            squadsKillSquaddie(D_overlay_3_0031A1CC);
                            break;
                        case 1:
                            *(f32 *)(D_overlay_3_0031A1CC + 0x1C) = *(f32 *)(D_overlay_3_0031A1CC + 0x1C) * D_overlay_3_00319DAC;
                            *(f32 *)(D_overlay_3_0031A1CC + 0x20) = *(f32 *)(D_overlay_3_0031A1CC + 0x20) - 1.0f;
                            *(f32 *)(D_overlay_3_0031A1CC + 0x24) = *(f32 *)(D_overlay_3_0031A1CC + 0x24) * D_overlay_3_00319DAC;
                            *(s16 *)(D_overlay_3_0031A1CC + 0x0) = (s16)(*(s16 *)(D_overlay_3_0031A1CC + 0x0) + *(s16 *)(D_overlay_3_0031A1D0 + 0x44));
                            *(s16 *)(D_overlay_3_0031A1CC + 0x2) = (s16)(*(s16 *)(D_overlay_3_0031A1CC + 0x2) + *(s16 *)(D_overlay_3_0031A1D0 + 0x46));
                            *(s16 *)(D_overlay_3_0031A1CC + 0x4) = (s16)(*(s16 *)(D_overlay_3_0031A1CC + 0x4) + *(s16 *)(D_overlay_3_0031A1D0 + 0x48));
                            *(s32 *)(D_overlay_3_0031A1CC + 0x84) = (*(s32 *)(D_overlay_3_0031A1CC + 0x84) | 2);
                            ((void (*)(void *, s32))func_overlay_3_0030E9F0_1EE3ED0)(D_overlay_3_0031A1CC, a1v); /* sig mismatch */
                            {
                                u8 *sp128p = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x40) + 0x50);
                                sp128 = (s32)*(u8 **)(sp128p + 0xC);
                                trackMakePolylist(1, D_overlay_3_0031A1D0 + 0x2C, D_overlay_3_0031A1CC + 0xC, &sp128, 0xCE000000, 0, 0);
                                if (trackGetIntersect(arg0, D_overlay_3_0031A1D0 + 0x2C, D_overlay_3_0031A1CC + 0xC, sp128, *(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x40) + 0x50) + 0x10), spFC) != 0) {
                                                                        u8 rec[0x14];
                                    void *spawned;
                                    *(s16 *)(rec + 0x0) = (D_overlay_3_00319DB0 < spFC[2]) ? 0x10B : 0x17F;
                                    rec[0x2] = 0xE;
                                    rec[0x3] = 0;
                                    *(s16 *)(rec + 0x4) = (s16)*(f32 *)(D_overlay_3_0031A1CC + 0xC);
                                    *(s16 *)(rec + 0x6) = (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x10);
                                    rec[0xA] = 0xF;
                                    rec[0xB] = 0x80;
                                    *(s16 *)(rec + 0x8) = (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x14);
                                    spawned = ((void *(*)(void *, s32))objSetupObject)(rec, 1); /* sig mismatch: asm passes 2 args */
                                    if (spawned != NULL) {
                                        *(s32 *)((u8 *)spawned + 0x3C) = 0;
                                    }
                                    explosionAddBlast(*(f32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 0x10), *(f32 *)((u8 *)arg0 + 0x14), 0x42700000, 80.0f, 0.5f, 0x64, 0);
                                    squadsKillSquaddie(D_overlay_3_0031A1CC);
                                    amSndPlayXYZ(0x22U, *(f32 *)(D_overlay_3_0031A1CC + 0xC), *(f32 *)(D_overlay_3_0031A1CC + 0x10), *(f32 *)(D_overlay_3_0031A1CC + 0x14), 4U, NULL);
                                }
                            }
                            break;
                        case 4:
                            if ((*(s16 *)(D_overlay_3_0031A1D0 + 0xA6) <= 0) && (*(u8 *)(D_overlay_3_0031A1D0 + 0x55) == 0) && (*(u16 *)(GetAnimData(D_overlay_3_0031A1CC) + 0x2) == 0x35)) {
                                *(u8 *)(D_overlay_3_0031A1D0 + 0x55) = 1U;
                            }
                            {
                                u8 v55 = *(u8 *)(D_overlay_3_0031A1D0 + 0x55);
                                if (v55 != 0) {
                                    s32 t4 = iDeltaTime * 2;
                                    if ((0xFF - t4) < (s32)v55) {
                                        squadsKillSquaddie(D_overlay_3_0031A1CC);
                                    } else {
                                        *(u8 *)(D_overlay_3_0031A1D0 + 0x55) = (u8)(v55 + t4);
                                    }
                                }
                            }
                            if (((*(u8 *)(D_overlay_3_0031A1D8 + 0x34) & 3) || (*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x04000000)) && !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x02000000)) {
                                ((void (*)(void *, s32))func_overlay_3_0030E9F0_1EE3ED0)(D_overlay_3_0031A1CC, a1v); /* sig mismatch */
                            }
                            break;
                        case 5:
                            {
                                u8 v52 = *(u8 *)(D_overlay_3_0031A1D0 + 0x52);
                                if ((s32)v52 < iDeltaTime) {
                                    *(s16 *)(*(u8 **)(D_overlay_3_0031A1CC + 0x4C) + 0x6) = -0x3E8;
                                    explosionStart(2, (s16)*(f32 *)(D_overlay_3_0031A1CC + 0xC), (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x10), (s16)*(f32 *)(D_overlay_3_0031A1CC + 0x14), 0x64, 0);
                                } else {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x52) = (u8)(v52 - iDeltaTime);
                                }
                            }
                            break;
                        }
                        func_overlay_3_00310354_1EE5834();
                    } else {
                        u8 *sq = D_overlay_3_0031A1D8;
                        if ((*(u8 *)(sq + 0x30) == 8) || ((*(u8 *)(sq + 0x92) != 0) && ((f32)*(u8 *)(sq + 0x92) < GetRange2D(*(f32 *)(D_overlay_3_0031A1E8 + 0xC), *(f32 *)(D_overlay_3_0031A1E8 + 0x14), D_overlay_3_0031A1CC + 0xC, *(f32 *)(D_overlay_3_0031A1CC + 0x14), 0.0f)))) {
                            ((void (*)(s32, f32, s32, void *))UpdateOrSetAnim)(0, 1.0f, 1, sq); /* sig mismatch */
                        } else {
                            if (*(u8 *)(sq + 0x33) == 0x19) {
                                *(f32 *)&D_overlay_3_0031A134 = *(f32 *)(D_overlay_3_0031A1CC + 0xC);
                                D_overlay_3_0031A138 = *(f32 *)(D_overlay_3_0031A1CC + 0x10);
                                *(f32 *)&D_overlay_3_0031A13C = *(f32 *)(D_overlay_3_0031A1CC + 0x14);
                            } else {
                                u8 v1A = *(u8 *)(D_overlay_3_0031A1D0 + 0x1A);
                                if ((v1A != 0) && (D_overlay_3_00319610[v1A] != NULL)) {
                                    ((void (*)(void *, void *, void *, void *))D_overlay_3_00319610[v1A])(D_overlay_3_0031A1CC, &D_overlay_3_0031A134, &D_overlay_3_0031A138, &D_overlay_3_0031A13C);
                                    GetFormationInfo((s32)D_overlay_3_0031A1D4, &D_overlay_3_0031A128, &D_overlay_3_0031A129, &squadsBehaviour);
                                } else {
                                    squadsGetFormationPosition((s32)D_overlay_3_0031A1D4, *(u8 *)(D_overlay_3_0031A1D0 + 0x15), (s32)&D_overlay_3_0031A134, (s32)&D_overlay_3_0031A138, (s32)&D_overlay_3_0031A13C);
                                }
                            }
                            *(u8 *)(D_overlay_3_0031A1D0 + 0x3) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x3) & 0xFB);
                            if ((*(u16 *)(D_overlay_3_0031A1D8 + 0x32) == 6) && (((s32 (*)(f32, f32, s8, void *))IsPointInRegionIdx)(*(f32 *)(D_overlay_3_0031A1E4 + 0xC), *(f32 *)(D_overlay_3_0031A1E4 + 0x14), *(s8 *)(D_overlay_3_0031A1D8 + 0x7A), D_overlay_3_0031A1D8) == 0) /* sig mismatch */) {
                                *(f32 *)&D_overlay_3_0031A134 = *(f32 *)(D_overlay_3_0031A1CC + 0xC);
                                D_overlay_3_0031A138 = *(f32 *)(D_overlay_3_0031A1CC + 0x10);
                                *(f32 *)&D_overlay_3_0031A13C = *(f32 *)(D_overlay_3_0031A1CC + 0x14);
                                *(u8 *)(D_overlay_3_0031A1D0 + 0x3) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x3) | 4);
                            }
                            D_overlay_3_0031A1EC = GetRangeSquared2D(*(f32 *)&D_overlay_3_0031A134, *(f32 *)&D_overlay_3_0031A13C, *(f32 *)(D_overlay_3_0031A1CC + 0xC), *(f32 *)(D_overlay_3_0031A1CC + 0x14));
                            if ((D_overlay_3_0031A1EC >= 50.0f) || (*(u16 *)(D_overlay_3_0031A1D0 + 0x4) & 1)) {
                                D_overlay_3_0031A1F4 = Arctanf(*(f32 *)&D_overlay_3_0031A134 - *(f32 *)(D_overlay_3_0031A1CC + 0xC), *(f32 *)&D_overlay_3_0031A13C - *(f32 *)(D_overlay_3_0031A1CC + 0x14)) - 0x8000;
                            } else {
                                D_overlay_3_0031A1F4 = *(s16 *)(D_overlay_3_0031A1CC + 0x0);
                            }
                            D_overlay_3_0031A1F6 = D_overlay_3_0031A1F4;
                            if (D_overlay_3_0031A1E4 != NULL) {
                                D_overlay_3_0031A1F0 = GetRange2D(*(f32 *)(D_overlay_3_0031A1E4 + 0xC), *(f32 *)(D_overlay_3_0031A1E4 + 0x14), D_overlay_3_0031A1CC + 0xC, *(f32 *)(D_overlay_3_0031A1CC + 0x14), 0.0f); /* asm: stack arg 0x10 unresolved */
                            } else {
                                D_overlay_3_0031A1F0 = 0.0f;
                            }
                            if (*(u16 *)(D_overlay_3_0031A1D0 + 0x1A) == 0x13) {
                                D_overlay_3_0031A1F6 = (s16)(*(s16 *)(D_overlay_3_0031A1D0 + 0x1C) - 0x8000);
                                *(s16 *)(D_overlay_3_0031A1CC + 0x0) = D_overlay_3_0031A1F6;
                            } else {
                                *(u8 *)(D_overlay_3_0031A1D0 + 0x6) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x6) & 0xBF);
                                D_overlay_3_0031A1F6 = func_overlay_3_0030B040_1EE0520(D_overlay_3_0031A1EC * D_overlay_3_00319DB4, *(f32 *)&D_overlay_3_0031A134, *(f32 *)&D_overlay_3_0031A13C);
                                if (!(*(u16 *)(D_overlay_3_0031A1D0 + 0x4) & 0x4000)) {
                                    if (*(u8 *)(sq + 0x30) == 3) {
                                        if (CheckLineOfSight(D_overlay_3_0031A1CC) == 0) {
                                            goto block_276;
                                        }
                                        goto block_280;
                                    }
block_276:
                                    if (((*(u16 *)(sq + 0x32) == 0x11) && !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 8)) || ((s32)*(u8 *)(D_overlay_3_0031A1D0 + 0xA) < 5) == 0 && ((s32)*(u8 *)(D_overlay_3_0031A1D0 + 0xA) < 8)) {
block_280:
                                        func_overlay_3_0030C1A0_1EE1680(D_overlay_3_0031A1CC, *(u8 **)(D_overlay_3_0031A1D0 + 0x64), &sp72, NULL, NULL, NULL, NULL, NULL);
                                    } else {
                                        sp72 = D_overlay_3_0031A1F6;
                                    }
                                    *(s16 *)(D_overlay_3_0031A1D0 + 0x10) = mathDiffAngle(*(s16 *)(D_overlay_3_0031A1CC + 0x0), sp72, NULL, NULL);
                                }
                            }
                            D_overlay_3_0031A1EC = sqrtf(D_overlay_3_0031A1EC);
                            runlinkEnsureJumpIsValid(&D_overlay_3_00319350[D_overlay_3_0031A1DC]);
                            if (*(u16 *)(sq + 0x32) != 0xB) {
                                void (*fn)(void *) = (void (*)(void *))D_overlay_3_00319350[D_overlay_3_0031A1DC];
                                if (fn != NULL) {
                                    fn(D_overlay_3_0031A1CC);
                                }
                            }
                            {
                                s32 a2 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                if (a2 & 0x800) {
                                    ((void (*)(void))func_overlay_3_0030A5EC_1EDFACC)(); /* sig mismatch: asm passes no args here */
                                    func_overlay_3_0030B70C_1EE0BEC();
                                } else if (((a2 & 0x04000000) && (!(*(u16 *)(D_overlay_3_0031A1E0 + 0x24) & 0x200) || (*(s16 *)(D_overlay_3_0031A1D0 + 0xA6) <= 0))) || (a2 & 0x10000000)) {
                                    func_overlay_3_0030B70C_1EE0BEC();
                                } else {
                                    switch (*(u8 *)(D_overlay_3_0031A1E0 + 0x2B)) {  /* switch 4: cases 0,1,4,5,6 */
                                    case 0:
                                        func_overlay_3_0030B9A0_1EE0E80();
                                        break;
                                    case 1:
                                        func_overlay_3_0030BBC4_1EE10A4();
                                        break;
                                    case 4:
                                        func_overlay_3_0030B9E0_1EE0EC0();
                                        break;
                                    case 5:
                                        func_overlay_3_0030BA94_1EE0F74();
                                        break;
                                    case 6:
                                        switch (D_overlay_3_0031A1DC) {  /* switch 5: irregular, cases 0x32,0x17,0x26,0x35 */
                                        case 0x32:
                                            func_overlay_3_0030BA20_1EE0F00();
                                            break;
                                        case 0x17:
                                            func_overlay_3_0030BFC4_1EE14A4();
                                            break;
                                        case 0x26:
                                            func_overlay_3_0030BB50_1EE1030();
                                            break;
                                        case 0x35:
                                            func_overlay_3_0030BAD4_1EE0FB4();
                                            break;
                                        }
                                        break;
                                    }
                                }
                            }
                            if ((*(s16 *)(D_overlay_3_0031A1D0 + 0xA6) <= 0) || (*(u8 *)(D_overlay_3_0031A1D0 + 0x1A) == 0xC)) {
                                *(s16 *)(D_overlay_3_0031A1D0 + 0x10) = 0;
                            }
                            {
                                s32 v0_3 = *(s16 *)(D_overlay_3_0031A1D0 + 0x10);
                                if (v0_3 >= 0x6979) {
                                    *(s16 *)(D_overlay_3_0031A1D0 + 0x10) = 0x6978;
                                    v0_3 = *(s16 *)(D_overlay_3_0031A1D0 + 0x10);
                                } else if (v0_3 < -0x6978) {
                                    *(s16 *)(D_overlay_3_0031A1D0 + 0x10) = -0x6978;
                                    v0_3 = *(s16 *)(D_overlay_3_0031A1D0 + 0x10);
                                }
                                if (v0_3 != *(s16 *)(D_overlay_3_0031A1D0 + 0xC)) {
                                    *(s16 *)(D_overlay_3_0031A1D0 + 0xE) = (s16)(s32)((f32)*(s16 *)(D_overlay_3_0031A1D0 + 0xE) + GetSmoothAcceleration(v0_3 - *(s16 *)(D_overlay_3_0031A1D0 + 0xC), (2.0f * (f32)*(s16 *)(D_overlay_3_0031A1D0 + 0xE)) + *(f32 *)(D_overlay_3_0031A1D0 + 0x4C), (f32)(*(u8 *)(D_overlay_3_0031A1E0 + 0x28) << *(u8 *)(D_overlay_3_0031A1D0 + 0x9))));
                                    *(s16 *)(D_overlay_3_0031A1D0 + 0xC) = (s16)(s32)((f32)*(s16 *)(D_overlay_3_0031A1D0 + 0xC) + ((f32)*(s16 *)(D_overlay_3_0031A1D0 + 0xE) * D_overlay_3_0031A1C8 * 0.5f));
                                }
                            }
                            {
                                u8 *tgt = *(u8 **)(D_overlay_3_0031A1D0 + 0x64);
                                if (tgt != NULL) {
                                    sp160 = mathDiffAngle(*(s16 *)(D_overlay_3_0031A1CC + 0x0), Arctanf(*(f32 *)(D_overlay_3_0031A1CC + 0xC) - *(f32 *)(tgt + 0xC), *(f32 *)(D_overlay_3_0031A1CC + 0x14) - *(f32 *)(tgt + 0x14)), NULL, NULL);
                                } else {
                                    sp160 = 0;
                                }
                            }
                            switch (*(u8 *)(D_overlay_3_0031A1D0 + 0x4B)) {  /* switch 6: cases 0,1,5,6,8,10,11,13 */
                            case 1:
                                var_f2 = (f32)mathDiffAngle(*(s16 *)(D_overlay_3_0031A1CC + 0x0), sp15E, NULL, NULL) * D_overlay_3_00319E0C;
                                if (var_f2 < 7.0f) {
                                    var_f2 = 7.0f;
                                }
                                if ((((s32 (*)(s32, s32, f32))TryToUpdateAnim)(0x40E00000, 1, var_f2) /* sig mismatch */ != 0) && (sp160 >= -0x18FF) && (sp160 < 0x1900)) {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x4B) = 0U;
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x8) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x8) & 0xF7);
                                }
                                break;
                            case 8:
                                {
                                    f32 f20 = *(f32 *)(D_overlay_3_0031A1D0 + 0x20);
                                    TryToUpdateAnim(8, (f20 > 1.0f) ? f20 : 1.0f);
                                }
                                break;
                            case 11:
                                TryToUpdateAnim(0xB, (f32)mathRnd(0, 0xC8) * D_overlay_3_00319E10);
                                break;
                            case 10:
                                if (TryToUpdateAnim(0xA, 1.0f) != 0) {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x4B) = 0U;
                                    if (!(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x40000000) && (*(u16 *)(D_overlay_3_0031A1E0 + 0x24) & 0x20)) {
                                        ClearMissionFields(1, 0);
                                        *(u32 *)(D_overlay_3_0031A1D0 + 0x0) &= 0xFFDF;
                                        *(u8 *)(D_overlay_3_0031A1D0 + 0x5) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x5) | 1);
                                    }
                                }
                                break;
                            case 13:
                                TryToUpdateAnim(0xD, 1.0f);
                                break;
                            case 5:
                                if (TryToUpdateAnim(5, 1.0f) != 0) {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x4B) = 0U;
                                }
                                break;
                            case 6:
                                if (TryToUpdateAnim(6, 1.0f) != 0) {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x4B) = 0U;
                                    if (*(u16 *)(D_overlay_3_0031A1D0 + 0x1A) == 5) {
                                        ClearMissionFields(1, mathRnd((s32)*(u8 *)(sq + 0x60), (s32)*(u8 *)(sq + 0x61)));
                                        if (!(*(u16 *)(sq + 0x28) & 0x4000) && (mathRnd(1, 3) == 1) && ((sp160 < -0x1900) || (sp160 >= 0x1901))) {
                                            *(u8 *)(D_overlay_3_0031A1D0 + 0x8) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x8) | 8);
                                        }
                                    }
                                }
                                break;
                            case 0: {
                                f32 sp12c_val = 1.0f;
                                s32 a2_4 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                sp12C = sp12c_val;
                                a2_4 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                if ((a2_4 & 0x04000000) && !(*(u16 *)(D_overlay_3_0031A1E0 + 0x24) & 0x200)) {
                                    s32 t8 = (*(u32 *)(D_overlay_3_0031A1D0 + 0x10) & 0xF);
                                    if (t8 < 0xA) {
                                        *(u8 *)(D_overlay_3_0031A1D0 + 0x13) = (u8)(((t8 + 1) & 0xF) | (*(u8 *)(D_overlay_3_0031A1D0 + 0x13) & 0xF0));
                                        a2_4 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                        goto block_354;
                                    }
                                } else {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x13) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x13) & 0xF0);
                                    a2_4 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
block_354:;
                                }
                                {
                                    s32 s0v = 0;
                                    s32 t6 = a2_4 << 0x13;
                                    s32 t5v;
                                    s32 t7v;
                                    if (t6 < 0) {
                                        s0v = 0x11;
                                    } else {
                                        t5v = a2_4 << 0x16;
                                        if (a2_4 & 0x04000000) {
                                            if ((*(u16 *)(D_overlay_3_0031A1D0 + 0x10) & 0xF) == 0xA) {
                                                t5v = a2_4 << 0x16;
                                                if (!(*(u16 *)(D_overlay_3_0031A1E0 + 0x24) & 0x200)) {
                                                    s0v = 0x14;
                                                    goto block_363_done;
                                                }
                                                goto block_363;
                                            } else {
                                                t5v = a2_4 << 0x16;
                                                goto block_363;
                                            }
                                        } else {
block_363:
                                            if (t5v < 0) {
                                                t7v = a2_4 << 0x1D;
                                                if (!(a2_4 & 0x10)) {
                                                    s0v = 1;
                                                    goto block_363_done;
                                                }
                                                goto block_367;
                                            } else {
                                                t7v = a2_4 << 0x1D;
block_367:
                                                if (t7v < 0) {
                                                    s0v = 0x26;
                                                } else {
                                                    u8 *a3s = D_overlay_3_0031A1D8;
                                                    u8 v1_15 = *(u8 *)(a3s + 0x32);
                                                    if (v1_15 == 0xA) {
                                                        s0v = 0x22;
                                                    } else if (v1_15 == 0xE) {
                                                        s0v = 0x28;
                                                    } else if (v1_15 == 0xF) {
                                                        s0v = 0x27;
                                                    } else if (*(u16 *)(D_overlay_3_0031A1D0 + 0x1A) == 0xF) {
                                                        s0v = 3;
                                                    } else if (v1_15 == 0xB) {
                                                        s0v = 0x20;
                                                    } else {
                                                        if (*(f32 *)(D_overlay_3_0031A1D0 + 0x20) < 1.0f) {
                                                            if (*(u16 *)(a3s + 0x2C) == 0x97) {
                                                                s0v = 0xB;
                                                            } else if ((a2_4 & 8) && (*(u8 *)(a3s + 0x91) == 2) && (CheckLineOfSight(D_overlay_3_0031A1CC) != 0)) {
                                                                if (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) != 0x70) {
                                                                    func_overlay_3_003044F4_1ED99D4(D_overlay_3_0031A1CC);
                                                                }
                                                                s0v = 8;
                                                            } else {
                                                                s0v = 1;
                                                            }
                                                            if ((*(u8 *)(a3s + 0x30) == 3) && (func_overlay_3_00304614_1ED9AF4(0x2A, 1) != -1) && (*(u8 *)(D_overlay_3_0031A1D8 + 0x32) == 0x11) && (*(u16 *)(D_overlay_3_0031A1D0 + 0x1A) != 0xD)) {
                                                                s0v = 0x2A;
                                                                *(f32 *)(D_overlay_3_0031A1CC + 0x1C) = 0.0f;
                                                                *(f32 *)(D_overlay_3_0031A1CC + 0x24) = 0.0f;
                                                                func_overlay_3_00303CAC_1ED918C(D_overlay_3_0031A1CC);
                                                            }
                                                            if (!(*(u16 *)(D_overlay_3_0031A1D8 + 0x28) & 0x4000) && (*(u8 **)(D_overlay_3_0031A1D0 + 0x64) != NULL) && (*(u16 *)(D_overlay_3_0031A1D0 + 0x4) & 1)) {
                                                                s32 v1_4 = 0;
                                                                if (*(u8 *)(D_overlay_3_0031A1D8 + 0x32) != 0x11) {
                                                                    if (*(u16 *)(D_overlay_3_0031A1E0 + 0x24) & 0x800) {
                                                                        s32 t4v = *(u16 *)(D_overlay_3_0031A1D0 + 0x4);
                                                                        if (((t4v & 4) && !(t4v & 0x10) && !(t4v & 8)) || (*(u32 *)(D_overlay_3_0031A1D0 + 0x8) & 0x08000000)) {
                                                                            v1_4 = 1;
                                                                        }
                                                                    } else if ((sp160 < -0x1900) || (sp160 >= 0x1901)) {
                                                                        v1_4 = 1;
                                                                    }
                                                                }
                                                                if ((v1_4 != 0) && (*(u32 *)(GetAnimData(D_overlay_3_0031A1CC) + 0x4) & 0x02000000)) {
                                                                    s32 var_a1v = 0xA;
                                                                    if (sp160 > 0) {
                                                                        var_a1v = 9;
                                                                    }
                                                                    TryToSetAnim(1, var_a1v, 0xB, 0xD);
                                                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x8) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x8) & 0xF7);
                                                                }
                                                            }
                                                        } else {
                                                            u8 a0_8 = *(u8 *)(a3s + 0x30);
                                                            s32 t6_2;
                                                            sp12C = *(f32 *)(D_overlay_3_0031A1D0 + 0x20); /* var_f0_2 = unk20 */
                                                            t6_2 = a2_4 * 2;
                                                            if ((a0_8 == 3) || (a0_8 == 4) || ((t6_2 = a2_4 * 2, (a0_8 == 1)) && (t6_2 = a2_4 * 2, ((*(u8 *)(a3s + 0x28) & 0x40) != 0)))) {
                                                                if (*(u16 *)(a3s + 0x2C) == 0x121) {
                                                                    s0v = 0xB;
                                                                } else if (func_overlay_3_00304614_1ED9AF4(0xE, 1) == -1) {
                                                                    s0v = 0xD;
                                                                    sp12C = *(f32 *)(D_overlay_3_0031A1D0 + 0x20);
                                                                } else {
                                                                    s0v = 0xE;
                                                                    sp12C = *(f32 *)(D_overlay_3_0031A1D0 + 0x20);
                                                                }
                                                            } else if ((t6_2 < 0) || (v1_15 == 8)) {
                                                                s0v = 0xF;
                                                            } else {
                                                                s0v = 0xB;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
block_363_done:
                                    UpdateOrSetAnim(0, sp12C, s0v);
                                }
                                break;
                            }
                            }
                            func_overlay_3_00310160_1EE5640();
                            sp158 = *(f32 *)(D_overlay_3_0031A1CC + 0xC);
                            sp154 = *(f32 *)(D_overlay_3_0031A1CC + 0x10);
                            sp150 = *(f32 *)(D_overlay_3_0031A1CC + 0x14);
                            ((void (*)(void *))func_overlay_3_0030E9F0_1EE3ED0)(D_overlay_3_0031A1CC); /* sig mismatch: asm passes 1 arg */
                            {
                                f32 dx = sp158 - *(f32 *)(D_overlay_3_0031A1CC + 0xC);
                                f32 dy = sp154 - *(f32 *)(D_overlay_3_0031A1CC + 0x10);
                                f32 dz = sp150 - *(f32 *)(D_overlay_3_0031A1CC + 0x14);
                                sp158 = dx;
                                sp154 = dy;
                                sp150 = dz;
                                if (squadsBehaviour == 8) {
                                    if ((dx < D_overlay_3_00319E14) && (D_overlay_3_00319E18 < dx) && (dy < 1.0f) && (dy > -1.0f) && (dz < D_overlay_3_00319E14) && (D_overlay_3_00319E18 < dz)) {
                                        *(u8 *)(D_overlay_3_0031A1D0 + 0x17) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x17) + 1);
                                        if (*(u8 *)(D_overlay_3_0031A1D0 + 0x17) == 0x32) {
                                            *(u8 *)(D_overlay_3_0031A1D0 + 0x1) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x1) | 0x40);
                                        }
                                    } else {
                                        *(u8 *)(D_overlay_3_0031A1D0 + 0x17) = 0U;
                                    }
                                }
                            }
                            sp160 = *(s16 *)(D_overlay_3_0031A1CC + 0x4);
                            {
                                u32 a2_5 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                s32 t6_3;
                                if (!(a2_5 & 0x200) || (a2_5 & 0x10)) {
                                    switch (*(u8 *)(D_overlay_3_0031A1E0 + 0x2C)) {  /* switch 7: cases 0,1 */
                                    case 0: {
                                        f32 t0f = sp144 - *(f32 *)(D_overlay_3_0031A1CC + 0x1C);
                                        f32 t4f = t0f * t0f * *(f32 *)(D_overlay_3_0031A1E0 + 0x18);
                                        f32 t2f = sp140 - *(f32 *)(D_overlay_3_0031A1CC + 0x24);
                                        s16 v24;
                                        s16 v16;
                                        sp158 = t4f;
                                        sp150 = t2f * t2f * *(f32 *)(D_overlay_3_0031A1E0 + 0x18);
                                        if (sp144 < *(f32 *)(D_overlay_3_0031A1CC + 0x1C)) {
                                            sp158 = -t4f;
                                        }
                                        if (sp140 < *(f32 *)(D_overlay_3_0031A1CC + 0x24)) {
                                            sp150 = -sp150;
                                        }
                                        {
                                            f32 lim = *(f32 *)(D_overlay_3_0031A1E0 + 0x1C);
                                            if (lim < sp158) {
                                                sp158 = lim;
                                            } else {
                                                f32 nlim = -lim;
                                                if (sp158 < nlim) {
                                                    sp158 = nlim;
                                                }
                                            }
                                            if (*(f32 *)(D_overlay_3_0031A1E0 + 0x1C) < sp150) {
                                                sp150 = *(f32 *)(D_overlay_3_0031A1E0 + 0x1C);
                                            } else {
                                                f32 nlim2 = -*(f32 *)(D_overlay_3_0031A1E0 + 0x1C);
                                                if (sp150 < nlim2) {
                                                    sp150 = nlim2;
                                                }
                                            }
                                        }
                                        sp148 = Sinf((s32)*(s16 *)(D_overlay_3_0031A1CC + 0x0));
                                        {
                                            f32 cs = Cosf((s32)*(s16 *)(D_overlay_3_0031A1CC + 0x0));
                                            v24 = *(s16 *)(D_overlay_3_0031A1CC + 0x2);
                                            *(s16 *)(D_overlay_3_0031A1CC + 0x2) = (s16)(v24 + ((s32)((s16)(s32)(((-sp148 * sp158) - (cs * sp150)) * *(f32 *)(D_overlay_3_0031A1E0 + 0x20))) - v24) >> 3);
                                            v16 = *(s16 *)(D_overlay_3_0031A1CC + 0x4);
                                            *(s16 *)(D_overlay_3_0031A1CC + 0x4) = (s16)(v16 + ((s32)((s16)(s32)(((cs * sp158) - (sp148 * sp150)) * *(f32 *)(D_overlay_3_0031A1E0 + 0x20))) - v16) >> 3);
                                        }
                                        a2_5 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                        t6_3 = a2_5 << 0x1A;
                                        goto block_469_pre;
                                    }
                                    case 1:
                                        t6_3 = a2_5 << 0x1A;
                                        if (*(s16 *)(D_overlay_3_0031A1D0 + 0xA6) != 0) {
                                            *(s16 *)(D_overlay_3_0031A1CC + 0x2) = (s16)(s32)(*(f32 *)(D_overlay_3_0031A1D0 + 0x20) * *(f32 *)(D_overlay_3_0031A1E0 + 0x20));
                                            *(s16 *)(D_overlay_3_0031A1CC + 0x4) = 0;
                                            a2_5 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                            goto block_469;
                                        }
                                        break;
                                    }
                                } else {
block_469:
                                    t6_3 = a2_5 << 0x1A;
                                }
block_469_pre:
                                {
                                    s32 v0_4 = a2_5 * 8;
                                    if (t6_3 < 0) {
                                        *(s16 *)(D_overlay_3_0031A1CC + 0x4) = sp160;
                                        a2_5 = *(u32 *)(D_overlay_3_0031A1D0 + 0x0);
                                        v0_4 = a2_5 * 8;
                                    }
                                    if (((v0_4 < 0) && (*(u8 *)(D_overlay_3_0031A1D0 + 0x17) != 0)) || (a2_5 & 0x800)) {
                                        if (v0_4 < 0) {
                                            *(u8 *)(D_overlay_3_0031A1D0 + 0x17) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x17) - 1);
                                            if (*(u8 *)(D_overlay_3_0031A1D0 + 0x17) == 0) {
                                                *(u32 *)(D_overlay_3_0031A1D0 + 0x0) &= 0xFFEF;
                                            }
                                        }
                                        if (*(u8 *)(D_overlay_3_0031A1E0 + 0x2C) != 1) {
                                            f32 t0g = *(f32 *)(D_overlay_3_0031A1CC + 0x1C);
                                            f32 t2g = *(f32 *)(D_overlay_3_0031A1CC + 0x24);
                                            *(s16 *)(D_overlay_3_0031A1CC + 0x2) = (s16)Arctanf(*(f32 *)(D_overlay_3_0031A1CC + 0x20), sqrtf((t0g * t0g) + (t2g * t2g)));
                                        }
                                    }
                                }
                            }
                            if ((D_overlay_3_0031A140 != -1) && !(*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x40000000) && !(*(u8 *)(D_overlay_3_0031A1D0 + 0x8) & 3)) {
                                func_overlay_3_003142F0_1EE97D0(D_overlay_3_0031A140, D_overlay_3_0031A144);
                            }
                            if (!(*(u32 *)(D_overlay_3_0031A1D0 + 0x8) & 0x04000000)) {
                                u8 v8 = *(u8 *)(D_overlay_3_0031A1D0 + 0x8);
                                u8 v1_17 = v8 & 3;
                                if (v1_17 != 0) {
                                    *(u8 *)(D_overlay_3_0031A1D0 + 0x8) = (u8)(((v1_17 - 1) & 3) | (v8 & 0xFC));
                                }
                            }
                            func_overlay_3_00310354_1EE5834();
                            if (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) == 0xBD) {
                                u8 *child = *(u8 **)(D_overlay_3_0031A1D0 + 0xA8);
                                if (*(u8 **)(D_overlay_3_0031A1D0 + 0xA8) != NULL) {
                                    squadsGetChildPolyPosition(0, &sp158, &sp154, &sp150);
                                    *(f32 *)(child + 0xC) = sp158;
                                    *(f32 *)(child + 0x10) = sp154;
                                    *(f32 *)(child + 0x14) = sp150;
                                }
                            }
                            if (*(u32 *)(D_overlay_3_0031A1D0 + 0x0) & 0x400) {
                                func_overlay_3_00309680_1EDEB60();
                                *(u8 *)(D_overlay_3_0031A1D0 + 0x2) = (u8)(*(u8 *)(D_overlay_3_0031A1D0 + 0x2) & 0xFB);
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddieControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_0031398C_1EE8E6C(void) {
    u8 *var_s0;
    u8 *var_s1;
    u8 *temp_v1;
    u8 *temp_a0;
    u16 var_a0;
    u16 snd_id;
    f32 var_f2;
    f32 temp_f0;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 sp2C;
    f32 var_f2_2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    s32 temp_f8;
    s32 var_a1;

    var_a0 = *(u16 *)(D_overlay_3_0031A1D8 + 0x2C);
    var_f2 = D_overlay_3_00319E1C;
    var_s1 = NULL;
    if ((var_a0 == 0x2B) || (var_a0 == 0x2D) || (var_a0 == 0x54) || (var_a0 == 0x6D) || (var_a0 == 0x83) || (var_a0 == 0x150) || (var_a0 == 0x152)) {
        var_s0 = *(u8 **)(D_overlay_3_0031A1D8 + 0x58);
        if (var_s0 != NULL) {
            do {
                temp_v1 = *(u8 **)(var_s0 + 0x68);
                if (*(s16 *)(temp_v1 + 0xA6) > 0) {
                    temp_f0 = GetRangeSquared(*(f32 *)(var_s0 + 0xC), *(f32 *)(var_s0 + 0x10), *(f32 *)(var_s0 + 0x14),
                                              *(f32 *)(D_overlay_3_0031A1E8 + 0xC), *(f32 *)(D_overlay_3_0031A1E8 + 0x10), *(f32 *)(D_overlay_3_0031A1E8 + 0x14));
                    if (temp_f0 < var_f2) {
                        var_f2 = temp_f0;
                        var_s1 = var_s0;
                    }
                }
                var_s0 = *(u8 **)(temp_v1 + 0x28);
            } while (var_s0 != NULL);
        }
        if (var_s1 != NULL) {
            snd_id = *(u16 *)(D_overlay_3_00319466 + (BaddyTypeToIndex(var_a0, (void *)0 /* asm: $a1 not set here */) * 8));
            if (snd_id != 0) {
                temp_a0 = *(u8 **)(D_overlay_3_0031A1D8 + 0x84);
                if (temp_a0 == NULL) {
                    amSndPlayXYZ(snd_id, *(f32 *)(var_s1 + 0xC), *(f32 *)(var_s1 + 0x10), *(f32 *)(var_s1 + 0x14), 1U, D_overlay_3_0031A1D8 + 0x84);
                } else {
                    amSndSetXYZ((SoundMask *)temp_a0, *(f32 *)(var_s1 + 0xC), *(f32 *)(var_s1 + 0x10), *(f32 *)(var_s1 + 0x14));
                }
                if (*(u8 **)(D_overlay_3_0031A1D8 + 0x84) != NULL) {
                    dx = *(f32 *)(var_s1 + 0xC) - *(f32 *)(D_overlay_3_0031A1E8 + 0xC);
                    dy = *(f32 *)(var_s1 + 0x10) - *(f32 *)(D_overlay_3_0031A1E8 + 0x10);
                    dz = *(f32 *)(var_s1 + 0x14) - *(f32 *)(D_overlay_3_0031A1E8 + 0x14);
                    dist = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                    sp2C = dist;
                    var_f2_2 = (*(f32 *)(D_overlay_3_0031A1D8 + 0x7C) - dist) / D_overlay_3_0031A1C8;
                    if (var_f2_2 > 15.0f) {
                        var_f2_2 = 15.0f;
                    } else if (var_f2_2 < -15.0f) {
                        var_f2_2 = -15.0f;
                    }
                    temp_f8 = (s32)(((10.0f + var_f2_2) / (10.0f - var_f2_2)) * 165.0f);
                    alCents2Ratio(temp_f8);
                    temp_f2_2 = *(f32 *)(D_overlay_3_0031A1D8 + 0x80);
                    *(f32 *)(D_overlay_3_0031A1D8 + 0x80) = temp_f2_2 + ((alCents2Ratio(temp_f8) - temp_f2_2) * 0.5f);
                    temp_f2_3 = *(f32 *)(D_overlay_3_0031A1D8 + 0x80);
                    if (temp_f2_3 > 2.0f) {
                        *(f32 *)(D_overlay_3_0031A1D8 + 0x80) = 2.0f;
                    } else if (temp_f2_3 < D_overlay_3_00319E20) {
                        *(f32 *)(D_overlay_3_0031A1D8 + 0x80) = D_overlay_3_00319E20;
                    }
                    *(f32 *)(D_overlay_3_0031A1D8 + 0x7C) = sp2C;
                    var_a1 = (s32)(*(f32 *)(D_overlay_3_0031A1D8 + 0x80) * 100.0f);
                    if (var_a1 < 0) {
                        var_a1 = -1;
                    }
                    ((void (*)(s32, SoundMask *, s32))amSndSetPitchXYZ)(0x40000000, (SoundMask *)*(u8 **)(D_overlay_3_0031A1D8 + 0x84), var_a1 & 0xFF); /* sig mismatch */
                }
            }
        } else {
            temp_a0 = *(u8 **)(D_overlay_3_0031A1D8 + 0x84);
            if (temp_a0 != NULL) {
                amSndStopXYZ(temp_a0);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_0031398C_1EE8E6C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquaddieAnimEventHandler(u8 *arg0, u16 arg1) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 var_v1;
    s32 var_a2;
    s32 play;

    var_v1 = -1;
    var_a2 = 0;
    play = 1;
    if (squadsPrepareToProcessSquaddie(arg0) != 0) {
        if ((arg1 == 4) && (*D_overlay_3_0031A1D0 & 8)) {
            *(s32 *)(arg0 + 0x84) = 4;
        } else {
            switch ((s32)*(u16 *)(D_overlay_3_0031A1D8 + 0x2C)) {
            case 0x66:
                switch (arg1) {
                case 1:
                    *(s32 *)(arg0 + 0x84) = 0x10;
                    break;
                case 2:
                    *(s32 *)(arg0 + 0x84) = 0x20;
                    var_v1 = 0xF;
                    var_a2 = 2;
                    break;
                case 3:
                    *(s32 *)(arg0 + 0x84) = 0;
                    break;
                }
                break;
            case 0x97:
                squadsGetChildPolyPosition(0, &sp34, &sp30, &sp2C);
                ((void (*)(f32, f32, f32, s32))objCreateBonusItem)(sp34, sp30, sp2C, 0x14); /* sig mismatch */
                play = 0;
                break;
            case 0x11C:
                var_v1 = 0xD2;
                break;
            case 0x90:
                var_v1 = 0xF;
                if (arg1 == 1) {
                    var_v1 = 0xD2;
                } else {
                    var_a2 = 2;
                }
                break;
            case 0xA5:
                break;
            case 0xE1:
                var_v1 = arg1 + 0xFE;
                break;
            case 0x5F:
            case 0x78:
            case 0x8C:
            case 0x8D:
            case 0x99:
            case 0x9C:
            case 0x121:
            case 0x12F:
                var_v1 = 0x155;
                var_a2 = 9;
                break;
            case 0x144:
                FatBobPhaseChange(arg0, arg1, var_a2, arg0);
                play = 0;
                break;
            case 0x67:
                SlugBossPhaseChange(arg0, arg1, var_a2, arg0);
                play = 0;
                break;
            default:
                break;
            }
            if (play && (var_v1 != -1)) {
                if (var_a2 != 0) {
                    var_v1 += mathRnd(0, var_a2);
                }
                amSndPlayXYZ(var_v1 & 0xFFFF, *(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x14), 4U, NULL);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddieAnimEventHandler.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_00313FE4_1EE94C4(s32 arg0) {
    s32 count;
    s32 idx;
    void **list;
    u8 *player;
    u8 *node;
    u8 *temp_s5;
    u8 *temp_s1;
    u8 *var_s0;
    u8 *var_s6;
    u8 *var_s7;
    u8 *temp_s0;
    s32 var_s2;
    s32 var_s4;
    s32 sp80;
    s32 var_v0;
    u16 temp_v1;
    f32 range;

    list = squadsGetSquadronList(&count);
    if (SquaddieGrowlTimer < arg0) {
        SquaddieGrowlTimer = mathRnd(0xF0, 0x168);
        var_s2 = mathRnd(0, 5);
        var_s7 = NULL;
        var_s6 = NULL;
        player = (u8 *)objGetPlayerNo(0);
        var_s4 = 0;
        range = D_overlay_3_00319F40;
        if (count != 0) {
            for (idx = count - 1; idx >= 0; idx--) {
                node = (u8 *)list[idx];
                temp_s5 = *(u8 **)(node + 0x68);
                var_s0 = *(u8 **)(temp_s5 + 0x58);
                if ((var_s0 != NULL) && (var_s4 == 0)) {
                    do {
                        temp_s1 = *(u8 **)(var_s0 + 0x68);
                        if ((*(u8 *)(var_s0 + 0xA0) == 0) &&
                            (GetRangeSquared(*(f32 *)(player + 0xC), *(f32 *)(player + 0x10), *(f32 *)(player + 0x14),
                                             *(f32 *)(var_s0 + 0xC), *(f32 *)(var_s0 + 0x10), *(f32 *)(var_s0 + 0x14)) < range)) {
                            var_s7 = var_s0;
                            var_s6 = temp_s5;
                            if (var_s2 == 0) {
                                var_s4 = 1;
                            } else {
                                var_s2 -= 1;
                            }
                        }
                        var_s0 = *(u8 **)(temp_s1 + 0x28);
                    } while ((var_s0 != NULL) && (var_s4 == 0));
                }
                if (var_s4 != 0) {
                    break;
                }
            }
        }
        if (var_s7 != NULL) {
            temp_s0 = *(u8 **)(var_s7 + 0x68);
            if ((*(s32 *)(temp_s0 + 0xBC) == 0) && (*(s16 *)(temp_s0 + 0xA6) > 0)) {
                temp_v1 = *(u16 *)(var_s6 + 0x2C);
                var_v0 = 0;
                switch ((s32)temp_v1) {
                case 0x5F:
                case 0x78:
                case 0x83:
                case 0x8C:
                case 0x99:
                case 0x9C:
                case 0xEE:
                case 0xEF:
                case 0x121:
                case 0x122:
                case 0x12F:
                case 0x143:
                case 0xBD:
                case 0xBE:
                case 0xF3:
                case 0x269:
                    sp80 = 0x186;
                    var_v0 = 8;
                    break;
                default:
                    var_v0 = 0;
                    break;
                }
                if (var_v0 != 0) {
                    amSndPlayXYZ((mathRnd(0, var_v0 - 1) + sp80) & 0xFFFF, *(f32 *)(var_s7 + 0xC), *(f32 *)(var_s7 + 0x10), *(f32 *)(var_s7 + 0x14), 4U, temp_s0 + 0xBC);
                }
            }
        }
    } else {
        SquaddieGrowlTimer -= arg0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00313FE4_1EE94C4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003142F0_1EE97D0(s32 arg0, s32 arg1) {
    s16 rot[2];
    f32 vec[3];
    f32 pos[3];
    f32 (*mtx)[4];
    u8 *cur;
    u8 *part;
    u8 *node;
    u8 *sub;
    u8 *base;
    f32 *tv;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 scale;
    s32 var_s7;
    s32 var_s2;

    cur = D_overlay_3_0031A1CC;
    part = *(u8 **)(*(u8 **)(cur + 0x6C) + (*(u8 *)(cur + 0x3A) * 4));
    node = *(u8 **)part;
    var_s7 = 0xFF;
    tv = *(f32 **)(cur + 0x54);
    if (tv != NULL) {
        var_s7 = (s32)(*tv * 255.0f);
    }
    var_s2 = 0;
    if (arg1 > 0) {
        for (;;) {
            rot[0] = (s16)(mathRnd(0, 0xA000) - 0x5000);
            rot[1] = 0;
            vec[0] = 0.0f;
            vec[1] = 0.0f;
            vec[2] = -2.0f;
            mathOneFloatPY(rot, vec);
            if (*(u8 *)(part + 0xA) == 0) {
                if ((s32)*(u8 *)(node + 0x2D) <= 0) {
                    break;
                }
                base = *(u8 **)(part + (*(u8 *)(part + 0xB) * 4) + 0x10);
                base += (*(u8 *)(*(u8 **)(node + 0x30) + 0x2)) << 6;
                mtx = (f32 (*)[4])base;
                mathMtxXFMF(mtx, vec[0], vec[1], vec[2], &vec[0], &vec[1], &vec[2]);
                dx = vec[0] - mtx[3][0];
                dy = vec[1] - mtx[3][1];
                dz = vec[2] - mtx[3][2];
                dist = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                scale = (dist == 0.0f) ? 2.0f : (2.0f / dist);
                sub = *(u8 **)(part + 0x68);
                if (sub != NULL) {
                    pos[0] = *(f32 *)(sub + 0x0);
                    pos[1] = *(f32 *)(sub + 0x4);
                    pos[2] = *(f32 *)(sub + 0x8);
                    if (*(u8 *)(node + 0x4E) == 0) {
                        pos[0] *= *(f32 *)(cur + 0x8);
                        pos[1] *= *(f32 *)(cur + 0x8);
                        pos[2] *= *(f32 *)(cur + 0x8);
                        pointListRPY(1, (s16 *)cur, (s32 *)pos, pos);
                        pos[0] += *(f32 *)(cur + 0xC);
                        pos[1] += *(f32 *)(cur + 0x10);
                        pos[2] += *(f32 *)(cur + 0x14);
                    }
                } else {
                    pos[0] = *(f32 *)(cur + 0xC);
                    pos[1] = *(f32 *)(cur + 0x10);
                    pos[2] = *(f32 *)(cur + 0x14);
                }
                bloodSpurtAdd(pos[0], pos[1], pos[2], dx * scale, dy * scale, dz * scale, var_s7,
                              (s32)*(u8 *)(*(u8 **)(cur + 0x40) + 0x2F), 1.0f);
            }
            var_s2 += 1;
            if (var_s2 == arg1) {
                break;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003142F0_1EE97D0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_3_00314694_1EE9B74(void) {
    u8 *temp_v0_2;
    u8 *temp_v0;

    temp_v0_2 = GetFirstDisactivatedSquaddie(*(s32 *)(D_overlay_3_0031A1D8 + 0x64));
    if (temp_v0_2 != NULL) {
        if (levelObjectFlagSet(*(u8 *)(temp_v0_2 + 0x18)) != 0) {
            *(u8 *)(D_overlay_3_0031A1D8 + 0x63) = (u8)(*(u8 *)(D_overlay_3_0031A1D8 + 0x63) + 1);
            return NULL;
        }
        temp_v0 = objSetupObject(temp_v0_2, 1, (void *)0 /* asm: $a2 not set in this function */);
        SquaddieInitFromRomdef(temp_v0, temp_v0_2);
        return temp_v0;
    }
    if (levelObjectFlagSet((u8)*(s32 *)(D_overlay_3_0031A1D8 + 0x8C)) != 0) {
        *(u8 *)(D_overlay_3_0031A1D8 + 0x63) = (u8)(*(u8 *)(D_overlay_3_0031A1D8 + 0x63) + 1);
        *(s32 *)(D_overlay_3_0031A1D8 + 0x8C) = *(s32 *)(D_overlay_3_0031A1D8 + 0x8C) + 1;
        return NULL;
    }
    return func_overlay_3_0030D810_1EE2CF0();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00314694_1EE9B74.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquaddieInit(void) {
    if (!(SquadsModuleFlags & 1)) {
        if (!(SquadsModuleFlags & 8)) {
            ((void (*)(void))SquaddieInitFromRomdef)(); /* sig mismatch: asm calls with no args */
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquaddieInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsAddToActiveSquaddies(u8 *arg0) {
    func_overlay_3_0030556C_1EDAA4C(GetSquadronFromIdentifier((s16)*(u8 *)(arg0 + 0x11)));
    if (levelObjectFlagSet(*(u8 *)(arg0 + 0x18)) != 0) {
        *(u8 *)(D_overlay_3_0031A1D8 + 0x63) = (u8)(*(u8 *)(D_overlay_3_0031A1D8 + 0x63) + 1);
        if ((s32)*(u8 *)(D_overlay_3_0031A1D8 + 0x63) >= (s32)*(u8 *)(D_overlay_3_0031A1D8 + 0x1)) {
            if (*(u8 *)D_overlay_3_0031A1D8 == 0) {
                func_overlay_3_00309840_1EDED20(D_overlay_3_0031A1D8, 0);
            } else if (*(u16 *)(D_overlay_3_0031A1D8 + 0x28) & 0x40) {
                func_overlay_3_003105B8_1EE5A98((s32)objGetPlayerNo(0));
            } else if ((*(u16 *)(D_overlay_3_0031A1D8 + 0x1A) >> 0xC) == 2) {
                *(u8 *)(D_overlay_3_0031A1D8 + 0x30) = 8;
            } else {
                *(u8 *)(D_overlay_3_0031A1D8 + 0x30) = 2;
            }
        }
    } else {
        objSetupObject(arg0, 1, (void *)0 /* asm: $a2 not set in this function */);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsAddToActiveSquaddies.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_003148C0_1EE9DA0(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *target = NULL;
    s32 sp34; /* asm: stack slot 0x34, only written by case 6 */
    s32 flag;
    s32 kind;

    if (squadsIsTribal((s32)*(u16 *)(d + 0x2C)) != 0 && mainGetTribalStatus(d[0x64]) != 0) {
        return 2;
    }

    kind = *(u16 *)(d + 0x1A) >> 12;
    switch (kind) {
    case 1:
        target = D_overlay_3_0031A1E8;
        break;
    case 5:
        target = (u8 *)((void *(*)(f32, f32, s32, s32))objGetClosestClass)(
            *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(s32 *)(obj + 0x14), 8); /* sig mismatch */
        break;
    case 6:
        sp34 = squadsIsFoodAvailable((s8)d[0x7A]);
        target = NULL;
        break;
    default:
        target = NULL;
        break;
    }

    if (target != NULL) {
        f32 dist2 = ((f32 (*)(f32, f32, f32, f32))GetRangeSquared2D)(
            *(f32 *)(target + 0xC), *(f32 *)(target + 0x14),
            *(f32 *)(obj + 0xC) + (f32)(d[0x15] * 0x10),
            *(f32 *)(obj + 0x14) + (f32)(d[0x17] * 0x10)); /* sig mismatch */
        s32 rad = d[0x18] * 0x10;
        f32 zc = *(f32 *)(obj + 0x10) + (f32)(d[0x16] * 0x10);
        f32 tz = *(f32 *)(target + 0x10);
        f32 halfz = (f32)(d[0x19] * 0x10);

        flag = 0;
        if ((s32)dist2 < rad * rad) {
            if ((zc - halfz) < tz) {
                if (tz < (zc + halfz)) {
                    flag = 1;
                }
            }
        }
    } else {
        flag = sp34;
    }

    if (d[0x30] == 8) {
        if (flag != 0) {
            if (arg1 != 0) {
                if (*(u16 *)(d + 0x28) & 0x40) {
                    func_overlay_3_003105B8_1EE5A98((s32)objGetPlayerNo(0));
                    return 1;
                }
                d[0x30] = 2;
            }
            return 1;
        }
        return 2;
    }

    kind = *(u16 *)(d + 0x1A) >> 12;
    if (kind == 3 || flag != 0) {
        if (arg1 == 0) {
            return 1;
        }
        if (kind == 5) {
            *(u8 **)(d + 0x54) = target;
        }
        *(f32 *)(d + 0x48) = *(f32 *)(obj + 0xC) + (f32)(d[0x10] * 0x10);
        *(f32 *)(d + 0x4C) = *(f32 *)(obj + 0x10) + (f32)(d[0x11] * 0x10);
        *(f32 *)(d + 0x50) = *(f32 *)(obj + 0x14) + (f32)(d[0x12] * 0x10);
        d[0x32] = 0x18;
        d[0x31] = d[0x3];
        *(s16 *)obj = (s16)(0xC000 - (d[0x1B] << 8));
        if (*(s32 *)(d + 0x58) == 0) {
            *(void **)(d + 0x58) = func_overlay_3_00314694_1EE9B74(); /* asm args unused by callee */
        }
        if (d[0x1E] != 0) {
            if ((s32)d[0x63] < (s32)d[0x1]) {
                *(s16 *)(d + 0x3C) = (s16)(d[0x1] - d[0x63]);
                *(s16 *)(d + 0x3E) = (s16)(d[0x1E] * 2);
                d[0x30] = 1;
                return 2;
            }
            if (d[0x0] == 0) {
                func_overlay_3_00309840_1EDED20(d, 0);
                return 2;
            }
            if (*(u16 *)(d + 0x28) & 0x40) {
                func_overlay_3_003105B8_1EE5A98((s32)objGetPlayerNo(0));
                return 2;
            }
            d[0x30] = 2;
            return 2;
        }
        if ((s32)d[0x63] < (s32)d[0x1]) {
            do {
                func_overlay_3_00314694_1EE9B74();
            } while ((s32)d[0x63] < (s32)d[0x1]);
        }
        if (d[0x0] == 0) {
            func_overlay_3_00309840_1EDED20(d, 0);
        } else if (*(u16 *)(d + 0x28) & 0x40) {
            func_overlay_3_003105B8_1EE5A98((s32)objGetPlayerNo(0));
        } else if ((*(u16 *)(d + 0x1A) >> 12) == 2) {
            d[0x30] = 8;
        } else {
            d[0x30] = 2;
        }
        return 2;
    }
    return 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003148C0_1EE9DA0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Squadron AI driver. Squaddie record = D_overlay_3_0031A1D8, member record =
// D_overlay_3_0031A1D0, list entries hang off squaddie+0x58 (entry+0x68 = member,
// member+0x28 = next entry). Offsets follow the other overlay_3 decomps.
void SquadronControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *sq;
    u8 *cur;
    u8 *head;
    u8 *mem;
    u8 *sub;
    u8 *node;
    s32 mode;
    s32 sel;
    s32 var;
    s32 a0s;
    f32 f40;
    f32 f44;
    f32 r1;
    f32 sinHalf;
    f32 ratio;
    f32 r2;
    f32 d2;
    f32 rad;
    f32 hgt;
    f32 cy;
    f32 px;
    f32 pz;
    f32 tgtY;
    void (*fn)(void);

    func_overlay_3_0030556C_1EDAA4C(obj);
    D_overlay_3_0031A1C8 = (f32)arg1;
    iDeltaTime = arg1;
    if (*(u16 *)(D_overlay_3_0031A1D8 + 0x2C) == 0x2CE) {
        GalaxianBatsSoundsHandler(D_overlay_3_0031A1D8);
    } else {
        func_overlay_3_0031398C_1EE8E6C();
    }

    sq = D_overlay_3_0031A1D8;
    if ((*(u16 *)(sq + 0x1A) >> 12) == 4) {
        return;
    }
    mode = sq[0x30];
    if (mode == 7) {
        return;
    }
    if (mode == 9) {
        *(s16 *)(sq + 0x2E) -= 1;
        if (*(s16 *)(D_overlay_3_0031A1D8 + 0x2E) == 0) {
            D_overlay_3_0031A1D8[0x30] = 0;
            D_overlay_3_0031A1D8[0x63] = 0;
        }
    }

    sq = D_overlay_3_0031A1D8;
    if (sq[0x33] != 0) {
        sq[0x34] = (u8)((sq[0x33] << 2) | (sq[0x34] & 0xFF03));
    }

    sq = D_overlay_3_0031A1D8;
    if (sq[0x30] == 5) {
        if ((*(u16 *)(sq + 0x1A) >> 12) == 1) {
            /* range test: squared radius (0x18*16) vs distance to target,
               then Y band (0x16 +/- 0x19*16) against target Y */
            rad = (f32)((s32)sq[0x18] * 16);
            hgt = (f32)((s32)sq[0x19] * 16);
            px = *(f32 *)(obj + 0xC) + (f32)((s32)*(s8 *)(sq + 0x15) * 16);
            pz = *(f32 *)(obj + 0x14) + (f32)((s32)*(s8 *)(sq + 0x17) * 16);
            cy = *(f32 *)(obj + 0x10) + (f32)((s32)*(s8 *)(sq + 0x16) * 16);
            d2 = GetRangeSquared2D(*(f32 *)(D_overlay_3_0031A1E8 + 0xC),
                                   *(f32 *)(D_overlay_3_0031A1E8 + 0x14),
                                   *(s32 *)&px, *(s32 *)&pz);
            if ((rad * rad) < d2) {
                D_overlay_3_0031A1D8[0x30] = 6;
            } else {
                tgtY = *(f32 *)(D_overlay_3_0031A1E8 + 0x10);
                if (tgtY < (cy - hgt) || (cy + hgt) < tgtY) {
                    D_overlay_3_0031A1D8[0x30] = 6;
                }
            }
        } else {
            D_overlay_3_0031A1D8[0x30] = 6;
        }
    }

    mode = D_overlay_3_0031A1D8[0x30];
    if (mode == 6) {
        *(s16 *)(D_overlay_3_0031A1D8 + 0x2E) -= 1;
        if (*(s16 *)(D_overlay_3_0031A1D8 + 0x2E) <= 0) {
            D_overlay_3_0031A1D8[0x30] = 0;
            D_overlay_3_0031A1D8[0x63] = 0;
        }
        return;
    }
    if ((mode == 0 || mode == 8) &&
        (func_overlay_3_003148C0_1EE9DA0(D_overlay_3_0031A1D4, 1) & 2)) {
        return;
    }

    sq = D_overlay_3_0031A1D8;
    if (sq[0x30] == 1) {
        *(s16 *)(sq + 0x3E) -= 1;
        sq = D_overlay_3_0031A1D8;
        if (*(s16 *)(sq + 0x3E) >= 0) {
            if ((*(u16 *)(sq + 0x1A) >> 12) != 5) {
                return;
            }
        } else if (sq[0x63] < sq[0x1]) {
            func_overlay_3_00314694_1EE9B74();
            sq = D_overlay_3_0031A1D8;
            *(s16 *)(sq + 0x3E) = (s16)(sq[0x1E] * 2);
            if ((*(u16 *)(sq + 0x1A) >> 12) != 5) {
                return;
            }
        } else {
            if (sq[0x0] == 0) {
                func_overlay_3_00309840_1EDED20(sq, 0);
            } else if (*(u16 *)(sq + 0x28) & 0x40) {
                func_overlay_3_003105B8_1EE5A98((s32)objGetPlayerNo(0));
            } else if ((*(u16 *)(sq + 0x1A) >> 12) == 2) {
                sq[0x30] = 8;
            } else {
                sq[0x30] = 2;
            }
        }
    }

    sq = D_overlay_3_0031A1D8;
    if (sq[0x33] == 0x19) {
        *(s16 *)(sq + 0x2E) -= 1;
        if (*(s16 *)(D_overlay_3_0031A1D8 + 0x2E) == 0) {
            D_overlay_3_0031A1D8[0x33] = 0;
        }
    }

    /* list walk: first entry whose member has s16 at +0x2 >= 0 */
    head = *(u8 **)(D_overlay_3_0031A1D8 + 0x58);
    if (head == NULL) {
        return;
    }
    cur = head;
    for (;;) {
        mem = *(u8 **)(cur + 0x68);
        if (*(s16 *)(mem + 0x2) >= 0) {
            break;
        }
        cur = *(u8 **)(mem + 0x28);
        if (cur == NULL) {
            D_overlay_3_0031A1D8[0x30] = 9;
            *(s16 *)(D_overlay_3_0031A1D8 + 0x2E) = 10;
            return;
        }
    }
    GetBaddyData(head);
    GetFormationInfo((s32)obj, &D_overlay_3_0031A128, &D_overlay_3_0031A129, &squadsBehaviour);
    fn = (void (*)(void))D_overlay_3_003196E0[squadsBehaviour];
    if (fn != NULL) {
        fn();
    }

    if (D_overlay_3_0031A128 == 5) {
        *(s16 *)(D_overlay_3_0031A1D8 + 0x40) = (s16)(s32)*(f32 *)(D_overlay_3_0031A1E8 + 0xC);
        *(s16 *)(D_overlay_3_0031A1D8 + 0x42) =
            (s16)(s32)(*(f32 *)(D_overlay_3_0031A1E8 + 0x10) +
                       (f32)*(s16 *)(D_overlay_3_0031A1E0 + 0x24));
        *(s16 *)(D_overlay_3_0031A1D8 + 0x44) = (s16)(s32)*(f32 *)(D_overlay_3_0031A1E8 + 0x14);
    }

    /* switch 1: aim, on squadsBehaviour (cases 1..28) */
    sel = squadsBehaviour;
    sq = D_overlay_3_0031A1D8;
    switch (sel) {
    case 1:
        cur = *(u8 **)(sq + 0x54);
        if (cur != NULL) {
            *(s16 *)obj = *(s16 *)cur;
        }
        break;
    case 2:
    case 12:
    case 19:
        *(s16 *)obj = (s16)Arctanf(*(f32 *)(sq + 0x48) - (f32)*(s16 *)(sq + 0x40),
                                   *(f32 *)(sq + 0x50) - (f32)*(s16 *)(sq + 0x44));
        break;
    case 3:
    case 8:
        *(s16 *)obj = (s16)Arctanf(-*(f32 *)(obj + 0x1C), -*(f32 *)(obj + 0x24));
        break;
    case 5:
        if (!(*(u16 *)(sq + 0x28) & 0x4000)) {
            *(s16 *)obj = (s16)Arctanf(*(f32 *)(sq + 0x48) - *(f32 *)(D_overlay_3_0031A1E8 + 0xC),
                                       *(f32 *)(sq + 0x50) - *(f32 *)(D_overlay_3_0031A1E8 + 0x14));
        }
        break;
    case 4:
    case 7:
    case 9:
    case 24:
    case 28:
        *(s16 *)obj = (s16)Arctanf(*(f32 *)(sq + 0x48) - *(f32 *)(D_overlay_3_0031A1E8 + 0xC),
                                   *(f32 *)(sq + 0x50) - *(f32 *)(D_overlay_3_0031A1E8 + 0x14));
        break;
    default:
        break;
    }

    /* switch 2: position update, on squadsBehaviour - 1 (cases 0..27) */
    var = sel - 1;
    sq = D_overlay_3_0031A1D8;
    switch (var) {
    case 2:
        *(f32 *)(sq + 0x48) = *(f32 *)(sq + 0x48) + *(f32 *)(obj + 0x1C);
        *(f32 *)(sq + 0x4C) = *(f32 *)(sq + 0x4C) + *(f32 *)(obj + 0x20);
        *(f32 *)(sq + 0x50) = *(f32 *)(sq + 0x50) + *(f32 *)(obj + 0x24);
        break;
    case 1:
    case 11:
    case 18:
        head = *(u8 **)(sq + 0x58);
        sub = *(u8 **)(head + 0x68);
        if ((*(u32 *)sub & 0x800) != 0) {
            *(f32 *)(sq + 0x6C) = 1.0f;
        }
        a0s = *(s16 *)(sq + 0x66);
        if (a0s == 0 && *(s16 *)(sq + 0x6A) == 0) {
            *(f32 *)(sq + 0x48) = (f32)*(s16 *)(sq + 0x40);
            *(f32 *)(sq + 0x4C) = (f32)*(s16 *)(sq + 0x42);
            *(f32 *)(sq + 0x50) = (f32)*(s16 *)(sq + 0x44);
        } else {
            *(f32 *)(sq + 0x48) = (f32)a0s +
                ((f32)((s32)*(s16 *)(sq + 0x40) - a0s) * *(f32 *)(sq + 0x6C));
            *(f32 *)(sq + 0x4C) = (f32)*(s16 *)(sq + 0x68) +
                ((f32)((s32)*(s16 *)(sq + 0x42) - *(s16 *)(sq + 0x68)) * *(f32 *)(sq + 0x6C));
            *(f32 *)(sq + 0x50) = (f32)*(s16 *)(sq + 0x6A) +
                ((f32)((s32)*(s16 *)(sq + 0x44) - *(s16 *)(sq + 0x6A)) * *(f32 *)(sq + 0x6C));
        }
        *(f32 *)(sq + 0x6C) = *(f32 *)(sq + 0x6C) + *(f32 *)(sq + 0x70);
        if (*(f32 *)(sq + 0x6C) >= 1.0f) {
            *(f32 *)(sq + 0x6C) = 1.0f;
            *(f32 *)(sq + 0x70) = 0.0f;
        }
        break;
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
        *(f32 *)(sq + 0x48) = (f32)*(s16 *)(sq + 0x40);
        *(f32 *)(sq + 0x4C) = (f32)*(s16 *)(sq + 0x42);
        *(f32 *)(sq + 0x50) = (f32)*(s16 *)(sq + 0x44);
        break;
    case 27:
        node = (u8 *)PatrolNodes + ((*(s16 *)(sq + 0x3C) & 0xFF) * 0x34);
        *(f32 *)(sq + 0x48) = *(f32 *)(node + 0x0);
        *(f32 *)(sq + 0x4C) = *(f32 *)(node + 0x4);
        *(f32 *)(sq + 0x50) = *(f32 *)(node + 0x8);
        break;
    default:
        break;
    }

    /* optional range check against the target, then a sine wobble on Y */
    sq = D_overlay_3_0031A1D8;
    if (*(u16 *)(sq + 0x28) & 0x1000) {
        f40 = (f32)*(s16 *)(sq + 0x40);
        f44 = (f32)*(s16 *)(sq + 0x44);
        r1 = GetRange2D((f32)*(s16 *)(sq + 0x66), (f32)*(s16 *)(sq + 0x6A),
                          *(void **)&f40, f44, 0.0f); /* asm: 5th arg never set */
        sq = D_overlay_3_0031A1D8;
        r2 = GetRange2D((f32)*(s16 *)(sq + 0x66), (f32)*(s16 *)(sq + 0x6A),
                        *(void **)(sq + 0x48), *(f32 *)(sq + 0x50), 0.0f); /* asm: 5th arg never set */
        if (!(r1 < 1.0f) && !(r1 < r2)) {
            ratio = r2 / r1;
            sinHalf = Sinf((s32)(ratio * 32768.0f));
            sq = D_overlay_3_0031A1D8;
            *(f32 *)(sq + 0x4C) = (f32)((f64)*(f32 *)(sq + 0x4C) +
                ((((f64)Sinf((s32)(ratio * 98304.0f))) + ((f64)sinHalf * 0.5)) * 16.0));
        }
    }

    /* mode 3/4: walk the list until an entry has a sub-record at +0x64 */
    sq = D_overlay_3_0031A1D8;
    head = *(u8 **)(sq + 0x58);
    if (head == NULL) {
        return;
    }
    mode = sq[0x30];
    if (mode == 3 || mode == 4) {
        D_overlay_3_0031A1CC = head;
        cur = head;
        for (;;) {
            D_overlay_3_0031A1D0 = *(u8 **)(cur + 0x68);
            func_overlay_3_003053D4_1EDA8B4(cur);
            if (*(u8 **)(D_overlay_3_0031A1D0 + 0x64) != NULL) {
                break;
            }
            cur = *(u8 **)(D_overlay_3_0031A1D0 + 0x28);
            D_overlay_3_0031A1CC = cur;
            if (cur == NULL) {
                D_overlay_3_0031A1D8[0x30] = 2;
                if (D_overlay_3_0031A1D8[0x91] != 3) {
                    D_overlay_3_0031A1D0[0x5] = (u8)(D_overlay_3_0031A1D0[0x5] & 0xFFFE);
                }
                return;
            }
        }
    }

    mode = D_overlay_3_0031A1D8[0x30];
    if (mode == 2) {
        cur = *(u8 **)(D_overlay_3_0031A1D8 + 0x58);
        D_overlay_3_0031A1CC = cur;
        if (cur != NULL) {
            do {
                D_overlay_3_0031A1D0 = *(u8 **)(cur + 0x68);
                CheckLineOfSight(cur);
                cur = *(u8 **)(D_overlay_3_0031A1D0 + 0x28);
                D_overlay_3_0031A1CC = cur;
            } while (cur != NULL);
        }
    }

    sq = D_overlay_3_0031A1D8;
    if (sq[0x30] == 4) {
        return;
    }
    if (*(u16 *)(sq + 0x2C) == 0xE1 && squadsIsFoodAvailable(*(s8 *)(sq + 0x7A)) == 0) {
        sq[0x30] = 4;
    }

    sq = D_overlay_3_0031A1D8;
    if ((((f32)sq[0x0] / (f32)sq[0x1]) * 100.0f) < (f32)(0x64 - sq[0xD])) {
        sq[0x30] = 4;
        *(u16 *)(sq + 0x28) = (u16)(*(u16 *)(sq + 0x28) | 0x10);
    }

    sq = D_overlay_3_0031A1D8;
    if (squadsIsTribal((s32)*(u16 *)(sq + 0x2C)) != 0) {
        cur = *(u8 **)(D_overlay_3_0031A1D8 + 0x58);
        if (cur == NULL) {
            return;
        }
        a0s = *(s16 *)(D_overlay_3_0031A1D8 + 0x2A);
        for (;;) {
            mem = *(u8 **)(cur + 0x68);
            if (*(s16 *)(mem + 0xA6) < a0s) {
                D_overlay_3_0031A1D8[0x30] = 4;
                return;
            }
            sub = *(u8 **)(mem + 0x64);
            if (sub != NULL) {
                if (*(s16 *)(sub + 0x48) != 1 || D_overlay_3_0031A1D8[0x91] == 1 ||
                    D_overlay_3_0031A1D8[0x91] == 3) {
                    D_overlay_3_0031A1D8[0x30] = 4;
                    return;
                }
            }
            cur = *(u8 **)(mem + 0x28);
            if (cur == NULL) {
                break;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/SquadronControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *GetAttachObject(f32 arg0, f32 arg1, f32 arg2) {
    s32 first;
    s32 last;
    void **list;
    void *best = NULL;
    u32 bestDist = 0xFFFFFFFFU;
    s32 i;

    list = objGetObjList(&first, &last);
    i = first;
    if (first < last) {
        do {
            u8 *obj = (u8 *)list[i];
            if (*(s16 *)(obj + 0xA0) == 0) {
                s16 id = *(s16 *)(obj + 0x4A);
                if (id == 0xA8 || id == 0x87 || id == 0x4A || id == 0xAE || id == 0x2C3 ||
                    id == 0x168 || id == 0x135 || id == 0x171 || id == 0x23A || id == 0x1E3 ||
                    id == 0x1E4 || id == 0x85 || id == 0x86 || id == 0x1A8 || id == 0x16F) {
                    f32 range = GetRangeSquared(arg0, arg1, arg2, *(f32 *)(obj + 0xC),
                                                *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
                    s32 dist;
                    /* asm: float->int conversion, out-of-range/negative results map to -1 */
                    if (range < 2147483648.0f) {
                        dist = (s32)range;
                        if (dist < 0) {
                            dist = -1;
                        }
                    } else {
                        dist = -1;
                    }
                    if ((u32)dist < bestDist) {
                        bestDist = (u32)dist;
                        best = obj;
                    }
                }
            }
            i++;
        } while (i < last);
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/GetAttachObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BindRegionsToObjects(void) {
    s32 n = D_overlay_3_0031A124 - 1;
    s32 i;
    u8 *region = D_overlay_3_0031942C + 0x2C;

    for (i = 0; i < n; i++, region += 0x2C) {
        if (*(s32 *)(region + 0x14) & 0x20) {
            *(void **)(region + 0x20) = GetAttachObject((f32)*(s16 *)(region + 0x20),
                                                        (f32)*(s16 *)(region + 0x22),
                                                        (f32)*(s16 *)(region + 0x24));
        } else {
            *(s32 *)(region + 0x20) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/BindRegionsToObjects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsInitAIArrays(void *arg0, s32 arg1) {
    u8 *rec = (u8 *)arg0;
    s32 cur = 0;
    s32 sz;
    u8 *regions;
    u8 *r;
    u8 *v;
    s32 n;
    s32 k;
    s32 t0;
    s32 i;
    s32 a1;
    s32 flag;
    s32 cont;
    s16 *a2p;
    s16 *v0p;
    s16 *v1p;
    s16 ta0;
    s16 t7;

    MaxPatrolNodes = 0;
    D_overlay_3_0031A120 = 0;
    D_overlay_3_0031A124 = 0;
    D_overlay_3_0031A12B = 0;

    /* stage 1: locate the 0x61 record, or restart the scan */
    if (arg1 > 0) {
loop_2:
        if (rec[0] == 0x61) {
            rec = (u8 *)arg0;
            cur = 0;
            PatrolPathsInit(rec, arg1);
            cur = 0;
        } else {
            sz = rec[2];
            cur += sz;
            rec += sz;
            if (cur >= arg1) {
                rec = (u8 *)arg0;
                cur = 0;
            } else {
                goto loop_2;
            }
        }
    }

    /* stage 2: count region records and find the largest region index */
    if (arg1 > 0) {
        do {
            if (rec[0] == 5) {
                D_overlay_3_0031A120 += 1;
                t0 = rec[0xA] + 1;
                if (D_overlay_3_0031A124 < t0) {
                    D_overlay_3_0031A124 = t0;
                }
            }
            sz = rec[2];
            cur += sz;
            rec += sz;
        } while (cur < arg1);
    }

    if (D_overlay_3_0031A124 != 0) {
        /* stage 3: (re)allocate region table and index table */
        if (D_overlay_3_0031942C != NULL) {
            mmFree(D_overlay_3_0031942C);
        }
        if (D_overlay_3_00319428 != NULL) {
            mmFree(D_overlay_3_00319428);
        }
        D_overlay_3_0031942C = (u8 *)mmAlloc(D_overlay_3_0031A124 * 0x2C, 0xFFFF00FFU);
        D_overlay_3_00319428 = mmAlloc(D_overlay_3_0031A120 * 4, 0xFFFF00FFU);

        /* stage 4a: clear region fields */
        n = D_overlay_3_0031A124 - 1;
        v = D_overlay_3_0031942C;
        v += n * 0x2C;
        do {
            *(u32 *)(v + 0x0) = 0;
            *(u32 *)(v + 0x4) = 0;
            *(u16 *)(v + 0x8) = 0;
            *(u16 *)(v + 0xA) = 0;
            *(u32 *)(v + 0xC) = 0;
            *(u32 *)(v + 0x10) = 0;
            *(u32 *)(v + 0x14) = 0;
            *(u32 *)(v + 0x18) = 0;
            *(u32 *)(v + 0x1C) = 0;
            v -= 0x2C;
            n -= 1;
        } while (n != 0);

        /* stage 4b: per-region counts from 0x05 records */
        rec = (u8 *)arg0;
        cur = 0;
        if (arg1 > 0) {
            do {
                if (rec[0] == 5) {
                    u8 *reg = D_overlay_3_0031942C + rec[0xA] * 0x2C;
                    *(s32 *)(reg + 0x4) = *(s32 *)(reg + 0x4) + 1;
                }
                sz = rec[2];
                cur += sz;
                rec += sz;
            } while (cur < arg1);
            rec = (u8 *)arg0;
            cur = 0;
        }

        /* stage 4c: point each region at its slice of the index table */
        t0 = 0;
        i = 0;
        r = D_overlay_3_0031942C;
        if (D_overlay_3_0031A124 > 0) {
            do {
                *(u8 **)(r + 0x0) = (u8 *)D_overlay_3_00319428 + t0 * 4;
                t7 = *(s32 *)(r + 0x4);
                i += 1;
                r += 0x2C;
                t0 += t7;
            } while (i < D_overlay_3_0031A124);
        }

        /* stage 4d: fill index table entries from 0x05 records */
        if (arg1 > 0) {
            do {
                if (rec[0] == 5) {
                    u8 *reg = D_overlay_3_0031942C + rec[0xA] * 0x2C;
                    s16 *ent = (s16 *)(*(u8 **)(reg + 0x0) + rec[0xB] * 4);
                    ent[0] = *(s16 *)(rec + 0x4);
                    ent[1] = *(s16 *)(rec + 0x8);
                    if (*(s16 *)(rec + 0x6) < *(s16 *)(reg + 0x8)) {
                        *(s16 *)(reg + 0x8) = *(s16 *)(rec + 0x6);
                    }
                    if (*(s16 *)(reg + 0xA) < *(s16 *)(rec + 0x6)) {
                        *(s16 *)(reg + 0xA) = *(s16 *)(rec + 0x6);
                    }
                }
                sz = rec[2];
                cur += sz;
                rec += sz;
            } while (cur < arg1);
            cur = 0;
        }

        /* stage 5: make the first s16 of each region's entries unique */
        regions = D_overlay_3_0031942C;
        n = D_overlay_3_0031A124 - 1;
        k = n - 1;
        r = regions + 0x2C;
        if (n > 0) {
            do {
loop_38:
                a1 = *(s32 *)(r + 0x4);
                a2p = *(s16 **)(r + 0x0);
                flag = 0;
                t0 = a1 - 1;
                if (a1 >= 2) {
                    do {
                        v1p = a2p + 2;
                        if (t0 != 0) {
                            v0p = v1p;
                        } else {
                            v0p = *(s16 **)(r + 0x0);
                            v1p = a2p + 2;
                        }
                        ta0 = *v0p;
                        t7 = *a2p;
                        a2p = v1p;
                        if (ta0 == t7) {
                            *v0p = ta0 + 1;
                            flag = 1;
                        }
                        t0 -= 1;
                    } while (t0 >= 2);
                }
                if (flag != 0) {
                    goto loop_38;
                }
                cont = k > 0;
                k -= 1;
                r += 0x2C;
            } while (cont);
        }

        /* stage 6: object/link records (0x69) */
        rec = (u8 *)arg0;
        cur = 0;
        if (arg1 > 0) {
            do {
                if (rec[0] == 0x69) {
                    u8 *s = D_overlay_3_0031942C + rec[0xA] * 0x2C;
                    u8 idx = rec[0xC];

                    *(s32 *)(s + 0x14) = rec[0xB];
                    s[0x28] = rec[0xE];
                    s[0x29] = rec[0xF];
                    s[0x2A] = rec[0x10];
                    if (idx != 0) {
                        u8 *last = D_overlay_3_0031942C + idx * 0x2C;
                        u8 *nxt = *(u8 **)(last + 0x10);
                        while (nxt != NULL) {
                            last = nxt;
                            nxt = *(u8 **)(last + 0x10);
                        }
                        if (last == s) {
                            ((s32 (*)(void *, u8, u8 *))GetRegionIndex)(last, idx, D_overlay_3_0031942C); /* sig mismatch */
                        } else {
                            *(u8 **)(last + 0x10) = s;
                            *(u8 **)(s + 0xC) = last;
                        }
                    }
                    if (rec[0xD] != 0) {
                        *(s32 *)(s + 0x14) = *(s32 *)(s + 0x14) | 0x20;
                        *(s16 *)(s + 0x20) = *(s16 *)(rec + 0x4);
                        *(s16 *)(s + 0x22) = *(s16 *)(rec + 0x6);
                        *(s16 *)(s + 0x24) = *(s16 *)(rec + 0x8);
                    } else {
                        *(s32 *)(s + 0x20) = 0;
                        *(s32 *)(s + 0x14) = *(s32 *)(s + 0x14) & ~0x20;
                    }
                }
                sz = rec[2];
                cur += sz;
                rec += sz;
            } while (cur < arg1);
        }

        /* stage 7: build BSP for regions that need it */
        n = D_overlay_3_0031A124 - 1;
        k = n - 1;
        r = D_overlay_3_0031942C + 0x2C;
        if (n > 0) {
            do {
                if (*(void **)(r + 0xC) == NULL || (*(s32 *)(r + 0x14) & 0x12) != 0) {
                    CreateBSPFromRegion(r);
                }
                cont = k > 0;
                k -= 1;
                r += 0x2C;
            } while (cont);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsInitAIArrays.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsFreePatrolRegions(void) {
    if (D_overlay_3_0031A124 != 0) {
        u8 *regions = D_overlay_3_0031942C;
        s32 n = D_overlay_3_0031A124 - 1;
        s32 i;
        u8 *region = regions + 0x2C;

        for (i = 0; i < n; i++, region += 0x2C) {
            if (*(void **)(region + 0x18) != NULL) {
                mmFree(*(void **)(region + 0x18));
            }
        }
        mmFree(regions);
        mmFree(D_overlay_3_00319428);
        D_overlay_3_0031942C = NULL;
        D_overlay_3_00319428 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsFreePatrolRegions.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00003(void) {
    s32 count;
    void **list;
    void **p;
    s32 i;

    list = squadsGetSquadronList(&count);
    if (PatrolNodes != NULL) {
        mmFree(PatrolNodes);
        PatrolNodes = NULL;
    }
    if (DisactivatedSquaddies != NULL) {
        mmFree(DisactivatedSquaddies);
        DisactivatedSquaddies = NULL;
    }
    if (list != NULL) {
        mmFree(list);
    }
    /* asm: walks backwards through the pointer table starting at D_800FF734 */
    p = (void **)&D_800FF734;
    for (i = 0xF; i != 0; i--) {
        if (*p != NULL) {
            mmFree(*p);
            p = &PathLists[i];
        }
        *p = NULL;
        p--;
    }
    squadsFreePatrolRegions();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/_AutoExit00003.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 DoSquaddiesCollide(void *arg0, void *arg1) {
    u8 *temp_a2 = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x68) + 0x24);
    u8 *temp_a3 = *(u8 **)(*(u8 **)((u8 *)arg1 + 0x68) + 0x24);
    u8 *var_v0 = NULL;
    u8 *var_v1 = NULL;

    if (temp_a2 != NULL) {
        var_v0 = *(u8 **)(temp_a2 + 0x68);
    }
    if (temp_a3 != NULL) {
        var_v1 = *(u8 **)(temp_a3 + 0x68);
    }
    if (temp_a2 == temp_a3 && var_v0 != NULL && !(*(u16 *)(var_v0 + 0x28) & 0x2000)) {
        return 0;
    }
    if ((var_v0 != NULL && arg1 == *(void **)(var_v0 + 0x54)) ||
        (var_v1 != NULL && arg0 == *(void **)(var_v1 + 0x54))) {
        return 0;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/DoSquaddiesCollide.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsTidyEventList(s32 arg0) {
    u8 *ev = D_overlay_3_0031A1F8;
    s32 i = 0xF;

    do {
        if (ev[0x8] != 0 && (*(s32 *)(ev + 0xC) & ~3) == arg0) {
            ev[0x8] = 0;
        }
        ev += 0x10;
        i--;
    } while (i != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsTidyEventList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void ReallyAddInterestingEvent(s32 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6) {
    u8 *ev = D_overlay_3_0031A1F8;
    s32 found = 0;
    s32 i = 0xF;

    if (arg0 != 0) {
        do {
            if (ev[0x8] != 0 && arg0 == *(s32 *)(ev + 0xC)) {
                found = 1;
                break;
            }
            ev += 0x10;
            i--;
        } while (i != 0);
    }
    if (found) {
        ev[0x8] = 0xA;
    } else {
        s32 idx = D_overlay_3_003197F8 * 0x10;
        D_overlay_3_003197F8 = D_overlay_3_003197F8 + 1;
        ev = D_overlay_3_0031A1F8 + idx;
        if (D_overlay_3_003197F8 >= 0x10) {
            D_overlay_3_003197F8 = 0;
        }
        ev[0x8] = (u8)(mathRnd(0x1E, 0x28) * iDeltaTime);
    }
    *(s16 *)(ev + 0x0) = arg1;
    *(s16 *)(ev + 0x2) = arg2;
    *(s16 *)(ev + 0x4) = arg3;
    ev[0x6] = arg4;
    *(s32 *)(ev + 0xC) = arg0;
    ev[0x7] = arg5;
    ev[0x9] = arg6;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/ReallyAddInterestingEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsMakeTargetList(void) {
    s32 first;
    s32 last;
    void **list;
    s32 i;

    list = objGetObjList(&first, &last);
    D_overlay_3_0031A388 = 0;
    i = first;
    if (first < last) {
        do {
            u8 *obj = (u8 *)list[i];
            if (*(s16 *)(obj + 0xA0) == 0 && *(s16 *)(obj + 0x48) == 0x9B) {
                D_overlay_3_0031A308[D_overlay_3_0031A388] = obj;
                D_overlay_3_0031A388 = D_overlay_3_0031A388 + 1;
                if (D_overlay_3_0031A388 >= 0x20) {
                    break;
                }
            }
            i++;
        } while (i != last);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsMakeTargetList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsModuleTick(s32 arg0) {
    void *player = objGetPlayerNo(0);
    u8 *ev = D_overlay_3_0031A1F8;
    u8 *p;
    s32 i;
    s32 a0_2;
    s32 t4;

    for (p = (u8 *)&D_overlay_3_00319448; p < (u8 *)&D_overlay_3_0031944C; p++) {
        *p = 0;
    }
    if (D_overlay_3_0031A300 != 0) {
        if (iDeltaTime >= D_overlay_3_0031A2F8) {
            mainChangeLevel(D_overlay_3_0031A2FC,
                            (s32)*(u8 *)(*(u8 **)(D_overlay_3_0031A1E8 + 0x68) + 1), 0, 0x10, 1, 0);
            D_overlay_3_0031A300 = 0;
        } else {
            D_overlay_3_0031A2F8 -= iDeltaTime;
        }
    }
    D_overlay_3_0031944C ^= 1;
    if (D_overlay_3_0031A12B != 0) {
        u8 t5 = D_overlay_3_0031A12B - 1;
        D_overlay_3_0031A12B = t5;
        if (t5 == 0) {
            D_overlay_3_0031A12C = 0;
        }
    }
    if (player != NULL) {
        s8 v = *(s8 *)(*(u8 **)((u8 *)player + 0x68) + 0x189);
        if (PlayersDisguise != v) {
            PlayersDisguise = (s32)v;
        }
    }
    for (i = 0xF; i != 0; i--, ev += 0x10) {
        if (ev[0x8] != 0) {
            ev[0x8] = (u8)(ev[0x8] - 1);
        }
    }
    if (D_overlay_3_0031A12A < 0xA) {
        D_overlay_3_0031A12A += 1;
    }
    if (D_overlay_3_00319430 != 0) {
        D_overlay_3_00319430 -= 1;
    }
    if (MaxPatrolNodes != 0) {
        SetBlockedNodes(0, MaxPatrolNodes);
    }
    a0_2 = MaxPatrolNodes - 1;
    if (MaxPatrolNodes != 0) {
        p = (u8 *)PatrolNodes + 0x34;
        a0_2 -= 1;
        if (a0_2 != 0) {
            do {
                if (p != NULL) {
                    u8 *src = *(u8 **)(p + 0x10);
                    if (src != NULL) {
                        *(f32 *)(p + 0x0) = *(f32 *)(src + 0xC);
                        *(f32 *)(p + 0x4) = *(f32 *)(src + 0x10);
                        *(f32 *)(p + 0x8) = *(f32 *)(src + 0x14);
                    }
                }
                p += 0x34;
                a0_2 -= 1;
            } while (a0_2 != 0);
        }
    }
    t4 = SquadsModuleFlags & 0x10;
    if (SquadsModuleFlags & 4) {
        squadsMakeFoodList(a0_2, MaxPatrolNodes);
        t4 = SquadsModuleFlags & 0x10;
    }
    if (t4 != 0) {
        squadsMakeTargetList(); /* asm passes arg0 in $a0; callee ignores it */
    }
    func_overlay_3_00313FE4_1EE94C4(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsModuleTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsSaveTribal(void) {
    u8 *sp24 = D_overlay_3_0031A1CC;

    if (squadsPrepareToProcessSquaddie((u8 *)0 /* asm: $a0 not set in this function */) != 0 && *(u16 *)(D_overlay_3_0031A1D0 + 0x1A) != 0xE) {
        TryToSetMission(0xC, 0xE, 0, 0, 0);
        D_overlay_3_0031A1D0[0x1] = (u8)(D_overlay_3_0031A1D0[0x1] & 0xEF);
    }
    if (PlayersDisguise != 0) {
        D_overlay_3_0031A12C = 3;
        D_overlay_3_0031A12B = 0xA;
    }
    squadsPrepareToProcessSquaddie(sp24);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsSaveTribal.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void AIJunctionControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *data = *(u8 **)(obj + 0x68);
    u8 *src = *(u8 **)(obj + 0x3C);
    s16 pathB[4];
    s16 pathA[4];
    s32 j;

    if (!(data[0x10] & 1)) {
        animseqGetPathNumbers(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(s32 *)(obj + 0x14),
                              pathB, pathA);
        for (j = 0; j < 4; j++) {
            data[0xB - j] = src[0xF - j];
            *(s16 *)(data + 6 - 2 * j) = pathB[3 - j];
            data[0xF - j] = (u8)pathA[3 - j];
        }
        data[0x10] = (u8)(data[0x10] | 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/AIJunctionControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsLowMemoryPanic(void) {
    s32 count;
    void **list = squadsGetSquadronList(&count);

    if (D_overlay_3_0031A12A >= 0xA) {
        count -= 1;
        if (count != 0) {
            do {
                u8 *sq = (u8 *)list[count];
                u8 *d = *(u8 **)(sq + 0x68);
                u8 st = d[0x30];

                if (st >= 2 && st < 5) {
                    u8 *cur = *(u8 **)(d + 0x58);
                    s32 clear = 1;

                    while (cur != NULL) {
                        u8 *cd = *(u8 **)(cur + 0x68);
                        u32 fl = *(u32 *)cd;
                        if (*(u8 *)(cur + 0xA0) == 0 &&
                            (d[0x75] != 0 || trackVisibleBlocks[*(s16 *)(cur + 0x2E) + 1] != 0 ||
                             ((fl & 2) && (fl & 1)) || (fl & 8))) {
                            clear = 0;
                            break;
                        }
                        cur = *(u8 **)(cd + 0x28);
                    }
                    if (clear && !(func_overlay_3_003148C0_1EE9DA0(sq, 0) & 1)) {
                        d[0x30] = 9;
                        *(s16 *)(d + 0x2E) = 0xA;
                    }
                }
                count -= 1;
            } while (count != 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsLowMemoryPanic.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CopyStaticsToSquads(u8 *arg0, u8 *arg1) {
    D_overlay_3_0031A1CC = arg0;
    if (arg0 != NULL) {
        D_overlay_3_0031A1D0 = *(u8 **)(arg0 + 0x68);
    } else {
        D_overlay_3_0031A1D0 = NULL;
    }
    D_overlay_3_0031A1D4 = arg1;
    if (arg1 != NULL) {
        D_overlay_3_0031A1D8 = *(u8 **)(arg1 + 0x68);
        return;
    }
    D_overlay_3_0031A1D8 = NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/CopyStaticsToSquads.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 IsPointInRegion(f32 arg0, f32 arg1, void *arg2) {
    u8 *node;
    u8 *edge;
    u16 count;
    s32 i;
    s16 angA;
    s16 angB;

    node = *(u8 **)((u8 *) arg2 + 0x18);
    if (((u32) arg2 < (u32) D_overlay_3_0031942C) ||
        (D_overlay_3_0031A124 < (s32) (((u8 *) arg2 - D_overlay_3_0031942C) / 44)) ||
        (*(u32 *) ((u8 *) arg2 + 0x4) < 3U)) {
        return 0;
    }
    if (*(u8 *) (node + 0x10) == 0) {
        do {
            if (arg1 < (*(f32 *) (node + 0x8) * arg0) + *(f32 *) (node + 0xC)) {
                node = *(u8 **) node;
            } else {
                node = *(u8 **) (node + 0x4);
            }
        } while (*(u8 *) (node + 0x10) == 0);
    }
    count = *(u16 *) (node + 0x2);
    edge = *(u8 **) ((u8 *) arg2 + 0x1C) + *(u16 *) node * 0x14;
    /* asm: pairwise angle test over count-1 neighbouring edges */
    for (i = 1; i < count; i++) {
        angA = Arctanf(*(f32 *) (edge + 0x4) - arg1, *(f32 *) (edge + 0x0) - arg0);
        edge += 0x14;
        angB = Arctanf(*(f32 *) (edge + 0xC) - arg1, *(f32 *) (edge + 0x8) - arg0);
        /* asm: a2/a3 are not set by the caller */
        if (mathDiffAngle(angA, angB, NULL, NULL) < 0) {
            return 0;
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/IsPointInRegion.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_3_003170D0_1EEC5B0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5) {
    f32 slope;
    f32 icpt;

    if (arg0 == arg2) {
        *arg4 = arg0;
        *arg5 = (D_overlay_3_0031AEF8 * arg0) + D_overlay_3_0031AEFC;
        return;
    }
    slope = (arg3 - arg1) / (arg2 - arg0);
    icpt = arg1 - (slope * arg0);
    *arg4 = (D_overlay_3_0031AEFC - icpt) / (slope - D_overlay_3_0031AEF8);
    *arg5 = (*arg4 * slope) + icpt;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_003170D0_1EEC5B0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_3_00317174_1EEC654(f32 arg0, f32 arg1, f32 arg2, f32 arg3, void *arg4) {
    u8 *node = (u8 *) arg4;
    u8 *edge;
    s16 ix;
    s16 iz;
    s32 i;
    s32 found;
    s32 side0;
    s32 side1;
    u16 count;
    u32 d2;
    s32 dx;
    s32 dz;
    s32 r1;
    s32 r2;
    u8 *child;

    if (*(u8 *) (node + 0x10) == 1) {
        /* asm: edges are read as raw integers here */
        count = *(u16 *) (node + 0x2);
        edge = D_overlay_3_0031AED4 + *(u16 *) node * 0x14;
        found = 0;
        for (i = 0; i < count; i++, edge += 0x14) {
            if (DoLinesIntersect(D_overlay_3_0031AED8, D_overlay_3_0031AEDC, D_overlay_3_0031AEE0,
                                 D_overlay_3_0031AEE4, *(s32 *) (edge + 0x0), *(s32 *) (edge + 0x4),
                                 *(s32 *) (edge + 0x8), *(s32 *) (edge + 0xC), &ix, &iz) != 0) {
                dx = D_overlay_3_0031AED8 - ix;
                dz = D_overlay_3_0031AEDC - iz;
                d2 = (u32) (dx * dx) + (u32) (dz * dz);
                if ((d2 != 0) && (d2 < D_overlay_3_0031AF0C)) {
                    D_overlay_3_0031AF0C = d2;
                    D_overlay_3_0031AF04 = ix;
                    D_overlay_3_0031AF08 = iz;
                    D_overlay_3_0031AF10 = edge[0x10];
                    D_overlay_3_0031AF11 = edge[0x11];
                }
                if (D_overlay_3_0031AF00 != 0) {
                    found = 1;
                } else {
                    return 1;
                }
            }
        }
        if (D_overlay_3_0031AF00 != 0) {
            return found;
        }
        return 0;
    }

    side0 = (arg1 < (*(f32 *) (node + 0x8) * arg0) + *(f32 *) (node + 0xC)) ? 1 : 0;
    D_overlay_3_0031AEE8 = side0;
    side1 = (arg3 < (*(f32 *) (node + 0x8) * arg2) + *(f32 *) (node + 0xC)) ? 1 : 0;
    D_overlay_3_0031AEEC = side1;
    if (side1 == side0) {
        child = (side0 != 0) ? *(u8 **) node : *(u8 **) (node + 0x4);
        /* asm: recursion keeps the same segment */
        return func_overlay_3_00317174_1EEC654(arg0, arg1, arg2, arg3, child);
    }

    D_overlay_3_0031AEFC = *(f32 *) (node + 0xC);
    D_overlay_3_0031AEF8 = *(f32 *) (node + 0x8);
    func_overlay_3_003170D0_1EEC5B0(arg0, arg1, arg2, arg3, &D_overlay_3_0031AEF0, &D_overlay_3_0031AEF4);
    if (side0 != 0) {
        if (D_overlay_3_0031AF00 != 0) {
            r1 = func_overlay_3_00317174_1EEC654(arg0, arg1, D_overlay_3_0031AEF0, D_overlay_3_0031AEF4,
                                                 *(u8 **) node);
            r2 = func_overlay_3_00317174_1EEC654(D_overlay_3_0031AEF0, D_overlay_3_0031AEF4, arg2, arg3,
                                                 *(u8 **) (node + 0x4));
            return r2 | r1;
        }
        r1 = func_overlay_3_00317174_1EEC654(arg0, arg1, D_overlay_3_0031AEF0, D_overlay_3_0031AEF4,
                                             *(u8 **) node);
        if (r1 != 0) {
            return 1;
        }
        return func_overlay_3_00317174_1EEC654(D_overlay_3_0031AEF0, D_overlay_3_0031AEF4, arg2, arg3,
                                               *(u8 **) (node + 0x4)) != 0;
    }
    if (D_overlay_3_0031AF00 != 0) {
        r1 = func_overlay_3_00317174_1EEC654(arg0, arg1, D_overlay_3_0031AEF0, D_overlay_3_0031AEF4,
                                             *(u8 **) (node + 0x4));
        r2 = func_overlay_3_00317174_1EEC654(D_overlay_3_0031AEF0, D_overlay_3_0031AEF4, arg2, arg3,
                                             *(u8 **) node);
        return r2 | r1;
    }
    r1 = func_overlay_3_00317174_1EEC654(arg0, arg1, D_overlay_3_0031AEF0, D_overlay_3_0031AEF4,
                                         *(u8 **) (node + 0x4));
    if (r1 != 0) {
        return 1;
    }
    return func_overlay_3_00317174_1EEC654(D_overlay_3_0031AEF0, D_overlay_3_0031AEF4, arg2, arg3,
                                           *(u8 **) node) != 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/func_overlay_3_00317174_1EEC654.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 DoesLineCrossRegion(f32 arg0, f32 arg1, f32 arg2, f32 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7) {
    u8 *regionA;
    u8 *regionB;
    u8 *out;
    u8 *entry;
    u8 v;

    regionA = GetRegion((u8) arg7);
    if (((u32) arg4 < (u32) D_overlay_3_0031942C) ||
        (D_overlay_3_0031A124 < (s32) (((u8 *) arg4 - D_overlay_3_0031942C) / 44)) ||
        (*(u32 *) ((u8 *) arg4 + 0x4) < 3U)) {
        return 0;
    }
    D_overlay_3_0031AED0 = *(u8 **) ((u8 *) arg4 + 0x18);
    D_overlay_3_0031AED4 = *(u8 **) ((u8 *) arg4 + 0x1C);
    D_overlay_3_0031AED8 = (s32) arg0;
    D_overlay_3_0031AEDC = (s32) arg1;
    D_overlay_3_0031AEE0 = (s32) arg2;
    D_overlay_3_0031AEE4 = (s32) arg3;
    D_overlay_3_0031AF0C = (u32) -1;
    D_overlay_3_0031AF00 = (s32) (uintptr_t) arg5;
    func_overlay_3_00317174_1EEC654(arg0, arg1, arg2, arg3, D_overlay_3_0031AED0);
    if (D_overlay_3_0031AF0C == (u32) -1) {
        return 0;
    }
    if (arg5 != NULL) {
        out = (u8 *) arg5;
        *(s16 *) (out + 0x0) = (s16) D_overlay_3_0031AF04;
        *(s16 *) (out + 0x2) = (s16) D_overlay_3_0031AF08;
        out[0x4] = D_overlay_3_0031AF10;
        out[0x7] = D_overlay_3_0031AF11;
        regionB = GetRegion(D_overlay_3_0031AF11);
        func_overlay_3_00305650_1EDAB30(regionB, out[0x4], (s8 *) (out + 0x5), (s8 *) (out + 0x6));
        if (arg6 != -1) {
            entry = *(u8 **) regionA + (arg6 * 4);
            if ((D_overlay_3_0031AED8 == *(s16 *) (entry + 0x0)) &&
                (D_overlay_3_0031AEDC == *(s16 *) (entry + 0x2)) &&
                (IsPointInRegion((f32) (((s32) (D_overlay_3_0031AF04 - D_overlay_3_0031AED8) >> 1) + D_overlay_3_0031AED8),
                                 (f32) (((s32) (D_overlay_3_0031AF08 - D_overlay_3_0031AEDC) >> 1) + D_overlay_3_0031AEDC),
                                 arg4) == 0)) {
                *(s16 *) (out + 0x0) = *(s16 *) (entry + 0x0);
                out[0x4] = (u8) arg6;
                *(s16 *) (out + 0x2) = *(s16 *) (entry + 0x2);
                out[0x7] = (u8) arg7;
                func_overlay_3_00305650_1EDAB30(regionA, arg6 & 0xFF, (s8 *) (out + 0x5), (s8 *) (out + 0x6));
                out[0x8] = 0;
                return 1;
            }
        }
        /* block_13 */
        v = out[0x4];
        entry = *(u8 **) regionB + (v * 4);
        if ((D_overlay_3_0031AF04 == *(s16 *) (entry + 0x0)) && (D_overlay_3_0031AF08 == *(s16 *) (entry + 0x2))) {
            out[0x8] = 1;
        } else {
            out[0x5] = v;
            out[0x4] = 0xFF;
            out[0x8] = 0;
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/DoesLineCrossRegion.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 IsPointInRegionIdx(f32 arg0, f32 arg1, s32 arg2) {
    return IsPointInRegion(arg0, arg1, D_overlay_3_0031942C + (arg2 * 0x2C));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/IsPointInRegionIdx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 DoesLineCrossRegionIdx(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7) {
    return DoesLineCrossRegion(arg0, arg1, arg2, arg3, D_overlay_3_0031942C + (arg4 * 0x2C), (void *) arg5, arg6,
                               (s32) arg7);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/DoesLineCrossRegionIdx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsChangeLevel(s32 arg0, s32 arg1) {
    if (D_overlay_3_0031A300 == 0) {
        D_overlay_3_0031A2F8 = arg1;
        D_overlay_3_0031A2FC = arg0;
        D_overlay_3_0031A300 = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/squadsChangeLevel.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoInit00003(void) {
    squadsInitAIArrays(GlobalStartOfRomdefList, GlobalSizeOfRomdefList);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o3/overlay_3/_AutoInit00003.s")
#endif
