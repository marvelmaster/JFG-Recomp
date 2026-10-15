#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct BTSBObj {
    /* 0x00 */ u8 pad0[0x0C];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[0x34];
    /* 0x4C */ struct BTSBObj *unk4C;
    /* 0x50 */ u8 pad50[0x18];
    /* 0x68 */ void *unk68;     /* per-type state */
    /* 0x6C */ u8 pad6C[0x34];
    /* 0xA0 */ u8 unkA0;
} BTSBObj;

typedef struct BTSBAntState {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u8 unk4;         /* bit 0: target already chosen / line of sight */
    /* 0x05 */ u8 unk5;         /* bit 0: fire flag */
    /* 0x06 */ u8 pad6[0x1E];
    /* 0x24 */ BTSBObj *unk24;  /* parent object (unk68 = BTSBStats) */
    /* 0x28 */ u8 pad28[0x3C];
    /* 0x64 */ BTSBObj *unk64;  /* current target */
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
} BTSBAntState;

typedef struct BTSBStats {
    /* 0x00 */ u8 pad0[0x1F];
    /* 0x1F */ u8 unk1F;        /* range radius (scaled by 0x1000) */
    /* 0x20 */ s8 unk20;        /* angle limit (scaled by 0x5B) */
    /* 0x21 */ u8 pad21[0x11];
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u8 pad34[0x46];
    /* 0x7A */ s16 unk7A;       /* region index */
} BTSBStats;

typedef struct BTSBSquadState {
    /* 0x00 */ u8 pad0[0x2C];
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u8 pad2E[0x58 - 0x2E];
    /* 0x58 */ BTSBObj *unk58;  /* first squad member */
} BTSBSquadState;

typedef struct BTSBMemberState {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ BTSBObj *unk28;  /* next squad member */
    /* 0x2C */ u8 pad2C[0xA6 - 0x2C];
    /* 0xA6 */ u16 unkA6;
} BTSBMemberState;

BTSBObj **squadsGetSquadronList(s32 *);
BTSBObj *squadsGetClosestPlayer(void);
s32 squadsIsTribal(u16);
f32 GetRangeSquared(f32, f32, f32, f32, f32, f32);
s32 IsPointInRegionIdx(f32, f32, s8);
s32 hitsCheckLineOfSight(void *, void *, f32, f32, f32, f32, f32, f32);
void BTSBStandardFire(void *);
void runlinkSetDestructTimer(s32, s32, s32);
extern f32 D_overlay_140_08C003C0;
extern s32 __MODULE00140;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBBlackAnt(void *arg0) {
    BTSBObj *obj = arg0;
    BTSBAntState *st;
    BTSBStats *stats;
    BTSBObj *player;
    BTSBObj *best;
    BTSBObj *squadObj;
    BTSBObj *member;
    BTSBObj *target;
    BTSBMemberState *mstate;
    BTSBObj **squadList;
    s32 spA8;
    f32 bestDist;
    f32 rangeSq;
    f32 d;
    f32 posX;
    f32 posY;
    f32 posZ;
    s16 angle;
    s16 absAngle;
    u8 radius;

    st = obj->unk68;
    bestDist = D_overlay_140_08C003C0;
    stats = (BTSBStats *) st->unk24->unk68;
    posX = st->unk68;
    posY = st->unk6C;
    posZ = st->unk70;
    squadList = squadsGetSquadronList(&spA8);
    best = NULL;
    rangeSq = -1.0f;
    player = squadsGetClosestPlayer();
    runlinkSetDestructTimer(__MODULE00140, 0xA, 5);

    spA8 -= 1;
    if (spA8 != 0) {
        do {
            squadObj = squadList[spA8];
            if (squadsIsTribal(((BTSBSquadState *) squadObj->unk68)->unk2C) != 0) {
                member = ((BTSBSquadState *) squadObj->unk68)->unk58;
                if (member != NULL) {
                    do {
                        mstate = (BTSBMemberState *) member->unk68;
                        if ((member->unkA0 == 0) && (mstate->unkA6 > 0)) {
                            d = GetRangeSquared(member->unkC, member->unk10, member->unk14, posX, posY, posZ);
                            if ((d < bestDist) && ((stats->unk32 != 0x11) || (IsPointInRegionIdx(member->unkC, member->unk14, (s8) stats->unk7A) != 0))) {
                                bestDist = d;
                                best = member;
                            }
                        }
                        member = mstate->unk28;
                    } while (member != NULL);
                }
            }
            spA8 -= 1;
        } while (spA8 != 0);
    }

    if (!(st->unk4 & 1)) {
        angle = (s16) Arctanf(posX - player->unkC, posZ - player->unk14);
        absAngle = angle;
        if (angle < 0) {
            absAngle = angle * -1;
        }
        rangeSq = GetRangeSquared(posX, posY, posZ, player->unkC, player->unk10, player->unk14);
        radius = stats->unk1F;
        if ((rangeSq < (f32) ((radius << 0xC) * radius)) && (absAngle < (stats->unk20 * 0x5B))) {
            target = player->unk4C;
            if (hitsCheckLineOfSight(arg0, player, posX, posY, posZ, target->unkC, target->unk10, target->unk14) == 0) {
                st->unk5 = (u8) (st->unk5 | 1);
            }
        }
    }
    if (st->unk4 & 1) {
        if (rangeSq == -1.0f) {
            rangeSq = GetRangeSquared(posX, posY, posZ, player->unkC, player->unk10, player->unk14);
        }
        if ((2.0f * rangeSq) < bestDist) {
            best = player;
        }
    }
    if (best != NULL) {
        st->unk64 = best;
    } else {
        st->unk64 = player;
    }
    BTSBStandardFire(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o140/overlay_140/BTSBBlackAnt.s")
#endif
