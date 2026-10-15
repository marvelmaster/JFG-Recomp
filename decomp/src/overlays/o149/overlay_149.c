#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct Obj149 Obj149;

typedef struct Cfg149 {
    /* 0x00 */ u8 pad00[0x24];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[0x18];
    /* 0x40 */ u8 *unk40;       /* sub-object (flash parts), raw offsets used */
} Cfg149;

typedef struct BoltTrack149 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} BoltTrack149;

typedef struct ObjLink149 {
    /* 0x00 */ u8 pad00[0x50];
    /* 0x50 */ BoltTrack149 *unk50;
} ObjLink149;

struct Obj149 {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 pad06[0x2];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;   /* x */
    /* 0x10 */ f32 unk10;  /* y */
    /* 0x14 */ f32 unk14;  /* z */
    /* 0x18 */ u8 pad18[0x4];
    /* 0x1C */ f32 unk1C;  /* x velocity */
    /* 0x20 */ f32 unk20;  /* y velocity */
    /* 0x24 */ f32 unk24;  /* z velocity */
    /* 0x28 */ u8 pad28[0x6];
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ u8 pad30[0xC];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ ObjLink149 *unk40;
    /* 0x44 */ u8 pad44[0x8];
    /* 0x4C */ Cfg149 *unk4C;
    /* 0x50 */ u8 pad50[0x18];
    /* 0x68 */ void *unk68;     /* per-type state */
    /* 0x6C */ u8 pad6C[0x18];
    /* 0x84 */ s32 unk84;
};

typedef struct FlowerBoltState149 {
    /* 0x00 */ Obj149 *unk0;    /* owner object */
    /* 0x04 */ u8 pad04[0xC];
    /* 0x10 */ s16 unk10;       /* frame counter */
    /* 0x12 */ s16 unk12;       /* target x */
    /* 0x14 */ s16 unk14;       /* target y */
    /* 0x16 */ s16 unk16;       /* target z */
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;       /* smoothed x velocity */
    /* 0x28 */ f32 unk28;       /* smoothed z velocity */
    /* 0x2C */ f32 unk2C;       /* start to target distance */
    /* 0x30 */ f32 unk30;       /* start to target height delta */
} FlowerBoltState149;

typedef struct FlowerBoltSpawn149 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ Obj149 *unkC;
} FlowerBoltSpawn149;

typedef struct MaggotBombState149 {
    /* 0x00 */ u16 unk0;        /* 0 = armed, 1 = detonating */
    /* 0x02 */ u16 unk2;        /* timer */
} MaggotBombState149;

typedef struct SpawnSetup149 {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 z;
    /* 0x0A */ s16 yaw;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ u8 pad0E[0x2];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ s32 unk14;
} SpawnSetup149;

typedef struct SlugMoveNode149 {
    /* 0x00 */ u8 unk0;      /* set to 1 by BTSBSlugBoss on some phase changes */
    /* 0x01 */ u8 unk1;         /* 4 = special target set, 5 = damped */
    /* 0x02 */ u8 unk2;         /* hop counter, max 5 */
    /* 0x03 */ u8 pad03;
    /* 0x04 */ f32 unk4;        /* target x */
    /* 0x08 */ f32 unk8;        /* target y */
    /* 0x0C */ f32 unkC;        /* target z */
    /* 0x10 */ f32 unk10;       /* start x */
    /* 0x14 */ f32 unk14;       /* start y */
    /* 0x18 */ f32 unk18;       /* start z */
    /* 0x1C */ s32 unk1C;       /* phase (0 = pick a new target) */
    /* 0x20 */ u8 pad20[0x2];
    /* 0x22 */ s16 unk22;
} SlugMoveNode149;

typedef struct SlugBossState149 {
    /* 0x00 */ u8 pad00[0x5A];
    /* 0x5A */ u16 unk5A;       /* flags, bit 2 = active */
    /* 0x5C */ u8 pad5C[0x8];
    /* 0x64 */ Obj149 *unk64;   /* player object */
    /* 0x68 */ u8 pad68[0x3C];
    /* 0xA4 */ u16 unkA4;       /* phase-change flash/effect bits */
    /* 0xA6 */ u8 padA6[0x2];
    /* 0xA8 */ SlugMoveNode149 *unkA8;
} SlugBossState149;

extern f32 D_overlay_149_09502200;
extern f32 D_overlay_149_09502204;
extern f32 D_overlay_149_09502208;
extern f32 D_overlay_149_0950220C;
extern f32 D_overlay_149_09502210;
extern f32 D_overlay_149_09502214;
extern f32 D_overlay_149_09502218;
extern f32 D_overlay_149_0950221C;
extern f32 D_overlay_149_09502220;
extern f64 D_overlay_149_09502228;
extern f64 D_overlay_149_09502230;
extern f32 D_overlay_149_09502238;
extern f32 D_overlay_149_0950223C;
extern f32 D_overlay_149_09502240;
extern f32 D_overlay_149_09502244;
extern f32 D_overlay_149_09502248;
extern s16 D_overlay_149_095021A0;
extern s32 D_overlay_149_09502284;
extern s32 D_overlay_149_09502288;
extern s32 D_overlay_149_0950227C;
extern Obj149 *D_overlay_149_09502280;
extern SlugMoveNode149 D_overlay_149_09502250;

Obj149 *objGetPlayerNo(s32 arg0);
Obj149 *squadsGetClosestPlayer(void);
void objSetFlashPartColour(s32 r, s32 g, s32 b, s32 mode);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void objAnimSetMove(void *obj, s32 arg1, s32 arg2);
void objAnimDframe(void *obj, s32 arg1, f32 arg2, s32 arg3);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg1);
s32 trackGetIntersect(void *a0, void *a1, void *a2, s32 a3, s32 a4, void *a5);
void trackMakePolylist(s32 a0, void *a1, void *a2, void *a3, s32 a4, s32 a5, s32 a6);
s32 trackNearestIntersection(void *obj, f32 *from, void *to, f32 *hit, s32 a4, s32 a5);
s16 trackGetBlock(f32 x, f32 y, f32 z, s32 frame);
Obj149 *objSetupObject(SpawnSetup149 *setup, s32 arg1, s32 arg2);
void amSndPlayXYZ(s32 sfx, f32 x, f32 y, f32 z, s32 arg4, s32 arg5);
void explosionAddBlast(f32 x, f32 y, f32 z, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7);
void TryToSetAnimByIndex(s32 a, s32 b);
f32 GetRange(f32, f32, f32, f32, f32, f32);
s16 mathDiffAngle(s16, s16);
f32 Sinf(s16 angle);
Obj149 **objGetObjList(s32 *start, s32 *end);
void objEnsureNotTargetted(void *obj);
s32 objTvTimes(s32 n);
void squadsChangeLevel(s32 arg0, s32 arg1);
s32 TryToSetMission(s32 a, s32 b, s32 c, s32 d, s32 e);

static void SlugMoveRandomTarget(SlugMoveNode149 *node) {
    node->unk4 = (f32) mathRnd(-0x2FC, 0x272);
    node->unk8 = (f32) mathRnd(0x4F, 0x177);
    node->unkC = (f32) mathRnd(-0xEF, 0x47E);
}
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBSlugBoss(Obj149 *arg0) {
    SlugBossState149 *state;
    SlugMoveNode149 *node;
    Obj149 *player;
    Obj149 **list;
    u8 *st;
    u8 *ownerState;
    u8 *part;
    s32 start;
    s32 end;
    s32 i;
    s32 count;
    s32 a1;
    s32 a2;
    s32 v;

    state = arg0->unk68;
    st = (u8 *) state;
    /* owner object (state+0x24) -> its state (unk68): s16 +0x2A, u8 +0x30 */
    ownerState = ((Obj149 *) *(Obj149 **) (st + 0x24))->unk68;
    player = squadsGetClosestPlayer();
    node = state->unkA8;
    if (node == NULL) {
        list = objGetObjList(&start, &end);
        D_overlay_149_09502288 = 0;
        D_overlay_149_09502284 = 0;
        node = &D_overlay_149_09502250;
        state->unkA8 = node;
        node->unk1 = 0x81;
        node->unk2 = 0;
        node->unk22 = 0x140;

        /* clear the 0x20 flag of every part entry (cfg+0x32 = count, 0x34 byte stride) */
        count = *(s16 *) ((u8 *) arg0->unk4C + 0x32);
        if (count != 0) {
            for (i = count - 1; i >= 0; i--) {
                part = arg0->unk4C->unk40 + i * 0x34;
                part[0x2F] = 0;
                part[0x30] = (u8) ((part[0x30] & 0xFFDF) | 0x20);
            }
        }

        /* find the boss object (type 0x61, s16 at +0x48) in the object list */
        if (start < end) {
            i = start;
            do {
                if (*(s16 *) ((u8 *) list[i] + 0x48) == 0x61) {
                    D_overlay_149_09502280 = list[i];
                    break;
                }
                i++;
            } while (i != end);
        }
    }

    state->unk64 = player;
    *(s16 *) (st + 0x10) = (s16) (Arctanf(arg0->unkC - player->unkC, arg0->unk14 - player->unk14) - arg0->unk0);
    *(s16 *) (st + 0xC) = *(s16 *) (st + 0x10);
    arg0->unk0 = -0x8000;
    *(s16 *) ((u8 *) arg0->unk4C + 0x6) = *(s16 *) (ownerState + 0x2A);

    switch (node->unk1 & 7) {
    case 1:
        part = arg0->unk4C->unk40;
        if (!(state->unk5A & 0x20) && *(s16 *) (part + 0x130) >= 0xA01) {
            *(u16 *) (st + 0xA0) |= 0x20;
            part[0x134] |= 0x40;
            objEnsureNotTargetted(arg0);
        }
        if (!(state->unk5A & 0x10) && *(s16 *) (part + 0xFC) >= 0xA01) {
            *(u16 *) (st + 0xA0) |= 0x10;
            part[0x100] |= 0x40;
            objEnsureNotTargetted(arg0);
        }
        break;
    case 2:
        part = arg0->unk4C->unk40;
        if (!(state->unk5A & 4) && *(s16 *) (part + 0x200) >= 0x1801) {
            objEnsureNotTargetted(arg0);
            part[0x204] |= 0x40;
            part[0x203] = 0;
            *(u16 *) (st + 0xA0) |= 4;
            st[0x4B] = 0;
            st[0x2] |= 0x10;
            TryToSetAnimByIndex(0, 6);
        }
        break;
    case 3:
        part = arg0->unk4C->unk40;
        if (!(state->unk5A & 0x80) && *(s16 *) (part + 0xC8) >= 0x401) {
            *(u16 *) (st + 0xA0) |= 0x80;
            part[0xCC] |= 0x40;
        }
        if (!(state->unk5A & 0x100) && *(s16 *) (part + 0x60) >= 0x401) {
            *(u16 *) (st + 0xA0) |= 0x100;
            part[0x64] |= 0x40;
        }
        if (!(state->unk5A & 0x200) && *(s16 *) (part + 0x94) >= 0x401) {
            *(u16 *) (st + 0xA0) |= 0x200;
            part[0x98] |= 0x40;
        }
        if (!(state->unk5A & 0x400) && *(s16 *) (part + 0x2C) >= 0x401) {
            *(u16 *) (st + 0xA0) |= 0x400;
            part[0x30] |= 0x40;
        }
        break;
    case 4:
        part = arg0->unk4C->unk40;
        if (!(state->unk5A & 0x40) && *(s16 *) (part + 0x198) >= 0x701) {
            *(u16 *) (st + 0xA0) |= 0x40;
            part[0x19C] |= 0x40;
            node->unk1 = 5;
            squadsChangeLevel(0x172, objTvTimes(0x1E));
        }
        break;
    default:
        break;
    }

    /* all four bits 0x80/0x100/0x200/0x400 set: clear the flash flag on the parts */
    if ((state->unk5A & 0x80) && (state->unk5A & 0x100) && (state->unk5A & 0x200) && (state->unk5A & 0x400)) {
        part = arg0->unk4C->unk40;
        if (*(s32 *) (part + 0x168) & 0x20000000) {
            part[0x168] &= 0xDF;
            part[0x167] = 0x64;
            part[0x19C] &= 0xDF;
            part[0x19B] = 0x64;
            state->unkA4 |= 2;
            objSetFlashPartColour(0xFF, 0xFF, 0xFF, 1);
        }
    }

    if (arg0->unk84 & 1) {
        if (state->unk5A & 0x10) {
            arg0->unk84 &= ~1;
        }
    }
    if (arg0->unk84 & 2) {
        if (state->unk5A & 0x20) {
            arg0->unk84 &= ~2;
        }
    }

    if (ownerState[0x30] == 3 && st[0x4A] == 0 && st[0x1A] != 5) {
        if (node->unk1 != 4 && TryToSetMission(0x10, 5, 0, 0, 0) != 0) {
            v = node->unk1;
            a1 = 6;
            a2 = v;
            if (v & 0x80) {
                a1 = 7;
            } else {
                node->unk0 = 0;
                switch (v) {
                case 1:
                    if ((state->unk5A & 0x10) && (state->unk5A & 0x20)) {
                        node->unk1 = 2;
                        a2 = 2;
                    }
                    break;
                case 2:
                    if (state->unk5A & 4) {
                        node->unk1 = 3;
                        a2 = 3;
                    }
                    break;
                case 3:
                    if ((state->unk5A & 0x400) && (state->unk5A & 0x200) && (state->unk5A & 0x100) && (state->unk5A & 0x80)) {
                        node->unk1 = 4;
                        a2 = 4;
                    }
                    break;
                default:
                    break;
                }

                if (a2 == 1) {
                    if (node->unk2 >= 6) {
                        node->unk2 = 0;
                    }
                    /* jump table at D_overlay_149_095021B0: 0x898, 0x8C4, 0x890, 0x8BC, 0x8F0, 0x8E8 */
                    switch (node->unk2) {
                    case 0:
                        a1 = (state->unk5A & 0x20) ? 1 : 2;
                        break;
                    case 1:
                        a1 = (state->unk5A & 0x10) ? 2 : 1;
                        break;
                    case 2:
                        node->unk0 = 1;
                        a1 = (state->unk5A & 0x20) ? 1 : 2;
                        break;
                    case 3:
                        node->unk0 = 1;
                        a1 = (state->unk5A & 0x10) ? 2 : 1;
                        break;
                    case 4:
                        a1 = (state->unk5A & 0x10) ? 2 : ((state->unk5A & 0x20) ? 1 : 3);
                        break;
                    case 5:
                        node->unk0 = 1;
                        a1 = (state->unk5A & 0x10) ? 2 : ((state->unk5A & 0x20) ? 1 : 3);
                        break;
                    }
                } else if (a2 == 2 || a2 == 3) {
                    if (D_overlay_149_0950227C != 0) {
                        a1 = ((state->unk5A & 0x80) && (state->unk5A & 0x200)) ? 4 : 5;
                    } else {
                        a1 = ((state->unk5A & 0x100) && (state->unk5A & 0x400)) ? 5 : 4;
                    }
                } else if (a2 == 5) {
                    a1 = 9;
                }
            }
            ((void (*)(s32, s32, s32)) TryToSetAnimByIndex)(6, a1, a2); /* sig mismatch: 3 args */
            st[0xA] = 5;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o149/overlay_149/BTSBSlugBoss.s")
#endif
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SlugBossPhaseChange(Obj149 *arg0, s32 arg1) {
    SlugBossState149 *state;
    SlugMoveNode149 *node;
    Obj149 *player;
    SpawnSetup149 setup;
    Obj149 *spawned;
    u8 *part;
    s32 lo;
    s32 hi;
    s32 shift;
    s32 count;

    state = arg0->unk68;
    node = state->unkA8;
    player = squadsGetClosestPlayer();
    switch (arg1) {
    case 3:
        /* asm: delay-slot decrement, the body runs for count 4,3,2,1,0 (5 spawns) */
        count = 4;
        do {
            setup.id = 0x30A;
            setup.unk02 = 0xA;
            setup.unk03 = 0;
            lo = (s32) (player->unkC - 60.0f);
            hi = (s32) (player->unkC + 60.0f);
            shift = (s32) ((D_overlay_149_09502280->unkC - 205.0f) - (f32) lo);
            if (shift > 0) {
                lo += shift;
                hi += shift;
            }
            shift = (s32) ((f32) hi - (D_overlay_149_09502280->unkC + 205.0f));
            if (shift > 0) {
                lo -= shift;
                hi -= shift;
            }
            setup.x = (s16) (s32) ((f32) mathRnd(lo, hi) + D_overlay_149_09502280->unkC);
            setup.y = (s16) (s32) ((f32) mathRnd(0xFA, 0x122) + D_overlay_149_09502280->unk10);
            setup.z = (s16) (s32) ((f32) mathRnd(-0x78, 0x2D) + D_overlay_149_09502280->unk14);
            spawned = objSetupObject(&setup, 1, 0); /* asm: $a2 not set by caller */
            if (spawned != NULL) {
                spawned->unk3C = 0;
            }
        } while (count-- != 0);
        D_overlay_149_0950227C ^= 1;
        switch (node->unk1) {
        case 1:
            if ((state->unk5A & 0x10) && (state->unk5A & 0x20)) {
                node->unk1 = 2;
            }
            break;
        case 2:
            if (state->unk5A & 4) {
                node->unk1 = 3;
            }
            break;
        case 3:
            if ((state->unk5A & 0x400) && (state->unk5A & 0x200) && (state->unk5A & 0x100) && (state->unk5A & 0x80)) {
                node->unk1 = 4;
            }
            break;
        case 4:
            break;
        }
        break;
    case 4:
        node->unk1 &= 0x7F;
        break;
    case 5:
        arg0->unk84 |= 1;
        part = arg0->unk4C->unk40;
        part[0x100] &= 0xDF;
        part[0xFF] = 0x64;
        state->unkA4 |= 0x40;
        objSetFlashPartColour(0xFF, 0xFF, 0xFF, 1);
        break;
    case 6:
        part = arg0->unk4C->unk40;
        part[0x100] |= 0x20;
        part[0xFF] = 0;
        node->unk1 |= 0x80;
        node->unk2 = (u8) (node->unk2 + 1);
        break;
    case 7:
        arg0->unk84 |= 2;
        part = arg0->unk4C->unk40;
        part[0x134] &= 0xDF;
        part[0x133] = 0x64;
        state->unkA4 |= 0x80;
        objSetFlashPartColour(0xFF, 0xFF, 0xFF, 1);
        break;
    case 8:
        part = arg0->unk4C->unk40;
        part[0x134] |= 0x20;
        part[0x133] = 0;
        node->unk1 |= 0x80;
        node->unk2 = (u8) (node->unk2 + 1);
        break;
    case 9:
        arg0->unk84 |= 3;
        part = arg0->unk4C->unk40;
        part[0x134] &= 0xDF;
        part[0x133] = 0x64;
        part[0x100] &= 0xDF;
        part[0xFF] = 0x64;
        state->unkA4 |= 0xC0;
        objSetFlashPartColour(0xFF, 0xFF, 0xFF, 2);
        break;
    case 10:
        part = arg0->unk4C->unk40;
        part[0x134] |= 0x20;
        part[0x133] = 0;
        part[0x100] |= 0x20;
        part[0xFF] = 0;
        node->unk1 |= 0x80;
        if (node->unk2 < 5) {
            node->unk2 = (u8) (node->unk2 + 1);
        }
        break;
    case 11:
        if (node->unk1 == 2) {
            part = arg0->unk4C->unk40;
            part[0x204] &= 0xDF;
            part[0x203] = 0x64;
            state->unkA4 |= 0x100;
            objSetFlashPartColour(0xFF, 0xFF, 0xFF, 1);
        } else {
            part = arg0->unk4C->unk40;
            if (*(s32 *) (part + 0x30) & 0x20000000) {
                part[0x30] &= 0xDF;
                part[0x2F] = 0x64;
                part[0x64] &= 0xDF;
                part[0x63] = 0x64;
                state->unkA4 |= 0xC;
                objSetFlashPartColour(0xFF, 0xFF, 0xFF, 2);
            }
        }
        break;
    case 13:
        if (node->unk1 == 2) {
            part = arg0->unk4C->unk40;
            part[0x204] &= 0xDF;
            part[0x203] = 0x64;
            state->unkA4 |= 0x100;
            objSetFlashPartColour(0xFF, 0xFF, 0xFF, 1);
        } else {
            part = arg0->unk4C->unk40;
            if (*(s32 *) (part + 0x98) & 0x20000000) {
                part[0x98] &= 0xDF;
                part[0x97] = 0x64;
                part[0xCC] &= 0xDF;
                part[0xCB] = 0x64;
                state->unkA4 |= 0x30;
                objSetFlashPartColour(0xFF, 0xFF, 0xFF, 2);
            }
        }
        break;
    case 12:
        if (node->unk1 == 2) {
            part = arg0->unk4C->unk40;
            part[0x204] |= 0x20;
            part[0x203] = 0;
        }
        node->unk1 |= 0x80;
        break;
    case 14:
        if (node->unk1 == 2) {
            part = arg0->unk4C->unk40;
            part[0x204] |= 0x20;
            part[0x203] = 0;
        }
        node->unk1 |= 0x80;
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o149/overlay_149/SlugBossPhaseChange.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FlowerBoltInit(Obj149 *arg0, FlowerBoltSpawn149 *arg1) {
    FlowerBoltState149 *state;
    Obj149 *player;
    f32 dx;
    f32 dz;
    s32 count;

    state = arg0->unk68;
    player = objGetPlayerNo(0);
    arg1->unkC->unk84 = 0;
    state->unk0 = arg1->unkC;
    state->unk12 = (s16) ((f32) mathRnd(-0x28, 0x28) + player->unkC);
    state->unk14 = (s16) player->unk10;
    state->unk16 = (s16) player->unk14;
    state->unk18 = arg0->unkC;
    state->unk1C = arg0->unk10;
    state->unk10 = 0;
    state->unk20 = arg0->unk14;
    dx = arg0->unkC - (f32) state->unk12;
    dz = arg0->unk14 - (f32) state->unk16;
    state->unk2C = sqrtf((dx * dx) + (dz * dz));
    state->unk30 = arg0->unk10 - (f32) state->unk14;
    count = D_overlay_149_09502284 + 1;
    D_overlay_149_09502284 = count;
    if ((count == 1) || (count == 2) || (count == 7) || (count == 8)) {
        arg0->unk1C = 0.0f;
    } else if (count & 1) {
        arg0->unk1C = -8.0f;
    } else {
        arg0->unk1C = 8.0f;
    }
    arg0->unk20 = 0.0f;
    arg0->unk24 = 8.0f;
    hitInitObjectHit(arg0, 0xA, 1, 1, 0, 0, 0, 16.0f, 16.0f, 1.0f, 0.75f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o149/overlay_149/FlowerBoltInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FlowerBoltControl(Obj149 *arg0, s32 arg1) {
    FlowerBoltState149 *state;
    f32 dt;
    f32 hitInfo[4];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 range;
    f32 speedScale;
    f32 velX;
    f32 velZ;
    f32 steerZ;
    f32 newVelX;
    f32 newVelZ;
    f32 speed;
    f32 dx2;
    f32 dz2;
    u16 headingA;
    u16 headingB;
    s16 turn;
    s16 angle;

    state = arg0->unk68;
    state->unk10 = (s16) (state->unk10 + 1);
    dt = (f32) arg1;
    trackMakePolylist(1, &state->unk18, &arg0->unkC, arg0->unk40->unk50, 0xCE000000, 0, 0);
    if (trackGetIntersect(arg0, &state->unk18, &arg0->unkC, arg0->unk40->unk50->unkC,
                          arg0->unk40->unk50->unk10, hitInfo) != 0) {
        objFreeObject(arg0);
        return;
    }
    state->unk18 = arg0->unkC;
    state->unk1C = arg0->unk10;
    state->unk20 = arg0->unk14;
    objMoveXYZ(arg0, arg0->unk1C * dt, arg0->unk20 * dt, arg0->unk24 * dt);

    dx = (f32) state->unk12 - arg0->unkC;
    dy = (f32) state->unk14 - arg0->unk10;
    dz = (f32) state->unk16 - arg0->unk14;
    range = GetRange(arg0->unkC, arg0->unk10, arg0->unk14,
                     (f32) state->unk12, (f32) state->unk14, (f32) state->unk16);
    if (range != 0.0f) {
        dx /= range;
        dy /= range;
        dz /= range;
    }

    if ((state->unk10 < 0xA) || (((arg0->unk1C * dx) + (dy * arg0->unk20) + (dz * arg0->unk24)) >= 0.0f)) {
        speedScale = 200.0f / range;
        velX = arg0->unk1C;
        velZ = arg0->unk24;
        if (speedScale < D_overlay_149_09502200) {
            speedScale = D_overlay_149_09502200;
        }
        if (speedScale > 1.0f) {
            speedScale = 1.0f;
        }
        steerZ = ((dz * 7.5f) - velZ) * speedScale;
        state->unk24 = state->unk24 + ((((dx * 7.5f) - velX) * speedScale) - state->unk24) * D_overlay_149_09502204;
        state->unk28 = state->unk28 + ((steerZ - state->unk28) * D_overlay_149_09502208);

        headingA = Arctanf(arg0->unk1C, arg0->unk24);
        newVelX = arg0->unk1C + state->unk24;
        newVelZ = arg0->unk24 + state->unk28;
        headingB = Arctanf(newVelX, newVelZ);
        speed = sqrtf((newVelX * newVelX) + (newVelZ * newVelZ));
        turn = mathDiffAngle((s16) headingA, (s16) headingB);
        if (turn >= 0xBB9) {
            turn = 0xBB8;
        } else if (turn < -0xBB8) {
            turn = -0xBB8;
        }
        angle = (s16) headingA + turn;
        arg0->unk1C = Sinf(angle) * speed;
        arg0->unk24 = Cosf((s32) angle) * speed;

        dx2 = arg0->unkC - (f32) state->unk12;
        dz2 = arg0->unk14 - (f32) state->unk16;
        arg0->unk84 = 1;
        arg0->unk20 = ((((f32) state->unk14) + (state->unk30 * (sqrtf((dx2 * dx2) + (dz2 * dz2)) / state->unk2C))) - arg0->unk10) / dt;
        partUpdateTriggers(arg0, arg1);
        return;
    }
    objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o149/overlay_149/FlowerBoltControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void MaggotBombInit(Obj149 *arg0, void *arg1) {
    MaggotBombState149 *state;
    Cfg149 *cfg;

    state = arg0->unk68;
    state->unk0 = 0;
    state->unk2 = (u16) mathRnd(0x96, 0xFA);
    arg0->unk8 = (f32) ((Sinf((s16) (sqrtf((f32) state->unk2 * 1600.0f) * 600.0f)) * D_overlay_149_0950220C) + D_overlay_149_09502210);
    arg0->unk1C = 0.0f;
    arg0->unk20 = 0.0f;
    arg0->unk24 = 0.0f;
    arg0->unk0 = (s16) mathRnd(-0x8000, 0x7FFF);
    arg0->unk2 = 0;
    arg0->unk4 = 0;
    arg0->unk3C = 0;
    cfg = arg0->unk4C;
    hitInitObjectHit(arg0, 1, 1, 2, 0, 0, 0, cfg->unk24, cfg->unk24, -1.0f, 1.0f, 1);
    objAnimSetMove(arg0, 1, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o149/overlay_149/MaggotBombInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void MaggotBombControl(Obj149 *arg0, s32 arg1) {
    MaggotBombState149 *state;
    SpawnSetup149 setup;
    f32 from[3];
    f32 hit[4];
    Obj149 *spawned;
    s32 i;

    state = arg0->unk68;
    if (state->unk0 == 0) {
        from[0] = arg0->unkC;
        from[1] = arg0->unk10;
        from[2] = arg0->unk14;
        for (i = arg1; i != 0; i--) {
            arg0->unk20 = arg0->unk20 - D_overlay_149_09502214;
            arg0->unkC = arg0->unkC + arg0->unk1C;
            arg0->unk10 = arg0->unk10 + arg0->unk20;
            arg0->unk14 = arg0->unk14 + arg0->unk24;
        }
        arg0->unk2E = trackGetBlock(arg0->unkC, arg0->unk10, arg0->unk14, arg1);
        if (trackNearestIntersection(arg0, from, &arg0->unkC, hit, 0x2000, 0) != 0) {
            objMoveXYZ(arg0, hit[1] - arg0->unkC, hit[2] - arg0->unk10, hit[3] - arg0->unk14);
            state->unk0 = 1;
            amSndPlayXYZ(mathRnd(0xAA, 0xAD) & 0xFFFF, arg0->unkC, arg0->unk10, arg0->unk14, 4, 0);
        }
    } else {
        if (arg1 >= (s32) state->unk2) {
            setup.id = 0x13C;
            setup.x = (s16) arg0->unkC;
            setup.y = (s16) arg0->unk10;
            setup.z = (s16) arg0->unk14;
            setup.yaw = arg0->unk0;
            setup.unk0C = arg0->unk2;
            setup.unk10 = 2;
            setup.unk11 = 0x64;
            setup.unk12 = 0;
            setup.unk13 = 1;
            setup.unk14 = 0;
            spawned = objSetupObject(&setup, 1, arg1);
            if (spawned != NULL) {
                spawned->unk3C = 0;
            }
            explosionAddBlast(arg0->unkC, arg0->unk10, arg0->unk14, 160.0f, 80.0f, 0.5f, 0x64, 0);
            amSndPlayXYZ(0x22, arg0->unkC, arg0->unk10, arg0->unk14, 4, 0);
            objFreeObject(arg0);
        } else {
            state->unk2 = (u16) (state->unk2 - arg1);
            arg0->unk8 = (f32) ((Sinf((s16) (sqrtf((f32) state->unk2 * 1600.0f) * 600.0f)) * D_overlay_149_09502218) + D_overlay_149_0950221C);
            objAnimDframe(arg0, 0x3C88CE70, (f32) arg1, arg1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o149/overlay_149/MaggotBombControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SlugBossMover(Obj149 *arg0, f32 arg1) {
    SlugBossState149 *state;
    SlugMoveNode149 *node;
    f32 playerX;
    f32 startX;
    f32 startY;
    f32 startZ;
    f32 t;
    f32 targetY;
    f32 targetZ;
    s32 phase;
    s32 jitter;

    state = arg0->unk68;
    node = state->unkA8;
    if ((node != NULL) && (state->unk5A & 4)) {
        if (node->unk1 == 5) {
            arg0->unk1C = arg0->unk1C * D_overlay_149_09502220;
            arg0->unk24 = arg0->unk24 * D_overlay_149_09502220;
            arg0->unk20 = arg0->unk20 * D_overlay_149_09502220;
            objMoveXYZ(arg0, arg0->unk1C * arg1, arg0->unk20 * arg1, arg0->unk24 * arg1);
        } else if (node->unk1C == 0) {
            if (node->unk22 < 0x400) {
                node->unk22 = (s16) (node->unk22 + 2);
            }
            jitter = mathRnd(-0x32, 0x32);
            D_overlay_149_095021A0 = (s16) (mathRnd(-0x14, 0x14) + node->unk22 + jitter);
            if (node->unk1 == 4) {
                playerX = state->unk64->unkC;
                if ((D_overlay_149_09502228 < (f64) playerX) && ((f64) playerX < D_overlay_149_09502230)) {
                    if ((D_overlay_149_09502288 != 0) || (mathRnd(1, 4) == 1)) {
                        node->unk4 = playerX;
                        node->unk8 = D_overlay_149_09502238;
                        node->unkC = D_overlay_149_0950223C;
                        TryToSetAnimByIndex(6, 8);
                        D_overlay_149_095021A0 = 0x18D;
                        D_overlay_149_09502288 ^= 1;
                    } else {
                        SlugMoveRandomTarget(node);
                    }
                } else {
                    SlugMoveRandomTarget(node);
                }
            } else if (mathRnd(1, 6) == 1) {
                node->unk4 = D_overlay_149_09502240;
                node->unk8 = D_overlay_149_09502244;
                node->unkC = D_overlay_149_09502248;
            } else {
                SlugMoveRandomTarget(node);
            }
            node->unk10 = arg0->unkC;
            node->unk14 = arg0->unk10;
            node->unk18 = arg0->unk14;
            node->unk1C = (s32) ((f32) D_overlay_149_095021A0 * arg1);
        } else {
            startX = node->unk10;
            startY = node->unk14;
            startZ = node->unk18;
            t = (Cosf(node->unk1C + 0x8000) + 1.0f) * 0.5f;
            targetY = startY + ((node->unk8 - startY) * t);
            targetZ = startZ + ((node->unkC - startZ) * t);
            arg0->unk1C = (((startX + ((node->unk4 - startX) * t)) - arg0->unkC) / arg1);
            arg0->unk20 = ((targetY - arg0->unk10) / arg1);
            arg0->unk24 = ((targetZ - arg0->unk14) / arg1);
            phase = (s32) ((f32) node->unk1C + ((f32) D_overlay_149_095021A0 * arg1));
            node->unk1C = phase;
            if (phase >= 0x8001) {
                node->unk1C = 0;
            }
            objMoveXYZ(arg0, arg0->unk1C * arg1, arg0->unk20 * arg1, arg0->unk24 * arg1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o149/overlay_149/SlugBossMover.s")
#endif
