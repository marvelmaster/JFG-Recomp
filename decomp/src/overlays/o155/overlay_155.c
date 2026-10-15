#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct OvlPoint {
    s16 x;
    s16 y;
} OvlPoint;

/* A region (from GetRegion) and the entries of its list share this layout. */
typedef struct OvlRegion {
    OvlPoint *points;            /* 0x00 */
    s32 numPoints;               /* 0x04 */
    u8 pad08[0x08];
    union {
        struct OvlRegion *entries; /* 0x10: region -> first entry */
        struct OvlRegion *next;    /* 0x10: entry -> next entry */
    };
    s32 flags;                   /* 0x14 */
    u8 pad18[0x08];
    Object *obj;                 /* 0x20 */
} OvlRegion;

typedef struct OvlPathNode {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u32 unk8;                    /* score */
    s32 unkC;
    s32 unk10;
} OvlPathNode;

typedef struct OvlCacheEntry {
    Object *owner;               /* 0x00 */
    s16 x;                       /* 0x04 */
    s16 y;                       /* 0x06 */
    void *buf;                   /* 0x08 */
    u8 timer;                    /* 0x0C */
    s8 regionFlag;               /* 0x0D */
    s8 count;                    /* 0x0E */
} OvlCacheEntry;

typedef struct OvlCostEntry {
    s16 x;
    s16 y;
    u32 cost;
} OvlCostEntry;

typedef struct OvlPathState {
    s16 xs[20];                  /* 0x00 */
    s16 ys[20];                  /* 0x28 */
    s8 unk50[20];                /* 0x50 */
    u8 unk64[20];                /* 0x64 */
    u8 count;                    /* 0x78 */
    u8 flags;                    /* 0x79 */
    u8 pad7A[0x2];
    f32 length;                  /* 0x7C */
    s32 unk80;                   /* 0x80 */
} OvlPathState;

typedef struct OvlSlot {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 size;                    /* 0x04 */
    s16 flags;                   /* 0x08 */
    s16 prevIndex;               /* 0x0A */
    s16 nextIndex;               /* 0x0C */
    s16 index;                   /* 0x0E */
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u8 pad1A[0x6];
} OvlSlot;

/* Out-parameter of DoesLineCrossRegion: hit point plus the edge/region indices. */
typedef struct OvlLineHit {
    s16 x;                       /* 0x00 */
    s16 y;                       /* 0x02 */
    u8 segIdx;                   /* 0x04 */
    u8 ptA;                      /* 0x05 */
    u8 ptB;                      /* 0x06 */
    u8 regionIdx;                /* 0x07 */
    u8 flag;                     /* 0x08 */
} OvlLineHit;

extern s16 D_overlay_155_09B04F64;
extern s16 D_overlay_155_09B04F66;
extern s16 D_overlay_155_09B04F68;
extern s16 D_overlay_155_09B04F6A;
extern Object *D_overlay_155_09B04F6C;
extern void *D_overlay_155_09B04F70;
extern void *D_overlay_155_09B04F74;
extern void *D_overlay_155_09B04F78;
extern OvlSlot *D_overlay_155_09B04F7C;
extern OvlRegion *D_overlay_155_09B04F80;
extern OvlPathNode *D_overlay_155_09B04F84;
extern s32 D_overlay_155_09B04F88;
extern s32 D_overlay_155_09B04F8C;
extern s16 D_overlay_155_09B04F90;
extern s32 D_overlay_155_09B04F94;
extern s32 D_overlay_155_09B04F60;
extern s32 D_overlay_155_09B04FD8;
extern s32 D_overlay_155_09B03C70;
extern OvlPathNode *D_overlay_155_09B04D50;
extern u32 D_overlay_155_09B04D58;
extern s32 D_overlay_155_09B04D5C;
extern u8 D_overlay_155_09B03CD0[];
extern OvlCostEntry D_overlay_155_09B04D60[64];
extern s16 D_overlay_155_09B04D54;
extern s16 D_overlay_155_09B04D56;
extern OvlCacheEntry D_overlay_155_09B04F98[3];
extern f32 D_overlay_155_09B03CC8;
extern s32 iDeltaTime;

f32 Sinf(s16 angle);
s16 mathDiffAngle(s16 angle1, s16 angle2);
OvlRegion *GetRegion(s32 index);
s32 GetRegionIndex(void *region);
s32 GetBaddyData(Object *obj);
s32 WhichRegionIsPointIn(s16 x, s16 z);
s32 IsPointInRegion(f32 x, f32 z, void *region);
s32 DoesLineCrossRegion(f32 x0, f32 z0, f32 x1, f32 z1, void *region, s32 a, s32 b, s32 c);
s32 DoLinesIntersect(s16 x0, s16 z0, s32 x1, s32 z1, s32 x2, s32 z2, s32 x3, s32 z3, s16 *outX, s16 *outZ);
void **squadsGetSquadronList(s32 *count);
void *objGetPlayerNo(s32 player);
f32 GetRangeSquared2D(f32 x0, f32 z0, f32 x1, f32 z1);
s32 DoesSquaddieWantToFire(f32 x, f32 y, s32 range);
s32 TryToSetMission(s32 a, s32 b, u8 c, u8 d, u8 e);

void _AutoInit00155(void);
s32 _AutoExit00155(void);
void func_overlay_155_09B000C8_1FE6548(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5);
s32 func_overlay_155_09B001B4_1FE6634(f32 arg0, f32 arg1, OvlRegion *arg2);
s32 func_overlay_155_09B00268_1FE66E8(f32 arg0, f32 arg1, Object *arg2, s32 arg3);
void func_overlay_155_09B00644_1FE6AC4(s16 arg0, s16 arg1, OvlRegion *arg2);
void func_overlay_155_09B00FC4_1FE7444(s16 arg0, s16 arg1, void *arg2);
void func_overlay_155_09B01274_1FE76F4(Object *arg0);
s32 func_overlay_155_09B01584_1FE7A04(Object *arg0, s32 arg1);
s32 func_overlay_155_09B018C4_1FE7D44(void *arg0);
void *func_overlay_155_09B01900_1FE7D80(void);
void *func_overlay_155_09B019A4_1FE7E24(s32 *arg0);
s32 func_overlay_155_09B01A00_1FE7E80(s16 arg0, s16 arg1, f32 arg2);
void func_overlay_155_09B01BE0_1FE8060(OvlPathState *arg0, s16 arg1, s16 arg2, s8 arg3, u8 arg4);
void func_overlay_155_09B01D9C_1FE821C(s16 *arg0, s16 *arg1, u8 arg2, s32 arg3);
void _bzero(void *ptr, s32 size);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoInit00155(void) {
    Object *player = (Object *) objGetPlayerNo(0);

    D_overlay_155_09B04F64 = (s16) (s32) player->segment.trans.x_position;
    D_overlay_155_09B04F66 = (s16) (s32) player->segment.trans.z_position;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/_AutoInit00155.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 _AutoExit00155(void) {
    OvlCacheEntry *entry = D_overlay_155_09B04F98;
    s32 i;
    s32 ret = 0;

    for (i = 3; i != 0; i--, entry++) {
        ret = i;
        if (entry->buf != NULL) {
            mmFree(entry->buf);
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/_AutoExit00155.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B000C8_1FE6548(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5) {
    OvlPathNode *node;
    OvlPathNode *cur;
    s32 i;
    u32 bestScore = 0;

    if (D_overlay_155_09B03C70 < 0x40) {
        node = &D_overlay_155_09B04D50[D_overlay_155_09B03C70];
        D_overlay_155_09B03C70 += 1;
    } else {
        /* Pick the entry with the highest score (first entry is the default). */
        node = D_overlay_155_09B04D50;
        cur = D_overlay_155_09B04D50;
        for (i = 0; i < 0x40; i++, cur++) {
            if (cur->unk8 > bestScore) {
                bestScore = cur->unk8;
                node = cur;
            }
        }
    }
    node->unk0 = arg0;
    node->unk2 = arg1;
    node->unk4 = arg2;
    node->unk6 = arg3;
    node->unk8 = arg5;
    node->unk10 = 0;
    node->unkC = arg4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B000C8_1FE6548.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_155_09B001B4_1FE6634(f32 arg0, f32 arg1, OvlRegion *arg2) {
    OvlRegion *entry;

    if (IsPointInRegion(arg0, arg1, arg2) == 0) {
        return 0;
    }
    entry = arg2->entries;
    while (entry != NULL) {
        if ((entry->flags & 0x10) && (IsPointInRegion(arg0, arg1, entry) != 0)) {
            return 0;
        }
        entry = entry->next;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B001B4_1FE6634.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_155_09B00268_1FE66E8(f32 arg0, f32 arg1, Object *arg2, s32 arg3) {
    u8 *veh = *(u8 **) ((u8 *) arg2 + 0x5C);
    f32 f0 = *(f32 *) (veh + 0x10C);
    f32 f2 = *(f32 *) (veh + 0x100);
    f32 f18 = *(f32 *) (veh + 0x108);
    f32 f16 = *(f32 *) (veh + 0x114);
    f32 midX = (f0 + f2) * 0.5f;
    f32 midZ = (f16 + f18) * 0.5f;
    f32 dX = f2 - f0;
    f32 dZ = f18 - f16;
    f32 radius = *(f32 *) (*(u8 **) ((u8 *) D_overlay_155_09B04F6C + 0x4C) + 0x24) + 10.0f;
    f32 len = sqrtf((dZ * dZ) + (dX * dX));
    s16 angle = (s16) (Arctanf(arg0 - midX, arg1 - midZ) - 0x8000);
    f32 dist = (len * 0.5f) + radius;
    s16 baseX = (s16) (s32) ((Sinf(angle) * dist) + midX);
    s16 baseZ = (s16) (s32) ((Cosf((s32) angle) * dist) + midZ);
    f32 bx = (f32) baseX;
    f32 bz = (f32) baseZ;
    s32 ret = 2;
    s16 candX = 0;
    s16 candZ = 0;
    s32 side;
    s32 distSq;
    f32 dx;
    f32 dz;

    if (func_overlay_155_09B001B4_1FE6634(bx, bz, D_overlay_155_09B04F80) == 0) {
        return ret;
    }

    side = 1;
    for (;;) {
        s16 testAngle = (s16) (((side != 0) ? -0x4000 : 0x4000) + angle);
        s32 diff;
        s32 absDiff;

        candX = (s16) (s32) ((Sinf(testAngle) * len) + bx);
        candZ = (s16) (s32) ((Cosf((s32) testAngle) * len) + bz);
        if (D_overlay_155_09B04F8C == 0) {
            break;
        }
        diff = mathDiffAngle(D_overlay_155_09B04F90,
                             (s16) (Arctanf(D_overlay_155_09B04F6C->segment.trans.z_position - bz,
                                            D_overlay_155_09B04F6C->segment.trans.x_position - bx) - 0x8000));
        absDiff = (diff >= 0) ? diff : -diff;
        if (absDiff >= 0x2000) {
            break;
        }
        ret = side;
        side -= 1;
        if (side == 0) {
            return ret;
        }
    }

    dx = bx - arg0;
    dz = bz - arg1;
    distSq = (s32) ((dx * dx) + (dz * dz));
    if (distSq < 0) {
        distSq = -1;
    }
    /* Sixth argument of func_overlay_155_09B000C8_1FE6548 is not set by this asm path. */
    func_overlay_155_09B000C8_1FE6548((s16) baseX, (s16) baseZ, candX, candZ, distSq, 0);
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B00268_1FE66E8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B00644_1FE6AC4(s16 arg0, s16 arg1, OvlRegion *arg2) {
    s32 regionIndex = GetRegionIndex(arg2);
    s32 edge = arg2->numPoints - 1;
    OvlPoint *a;

    if (arg2->numPoints == 0) {
        return;
    }
    a = arg2->points;
    do {
        OvlPoint *b = (edge != 0) ? (a + 1) : arg2->points;
        s16 angA = (s16) (Arctanf((f32) (arg1 - a->y), (f32) (arg0 - a->x)) - 0x8000);
        s16 angB = (s16) (Arctanf((f32) (arg1 - b->y), (f32) (arg0 - b->x)) - 0x8000);
        s32 dAx = a->x - arg0;
        s32 dAz = a->y - arg1;
        s32 dBx = b->x - arg0;
        s32 dBz = b->y - arg1;
        s32 distA = (dAx * dAx) + (dAz * dAz);
        s32 distB = (dBx * dBx) + (dBz * dBz);

        if (mathDiffAngle(angA, angB) < -0x200) {
            OvlPoint *near;
            OvlPoint *far;
            s16 nearAng;
            s32 nearIsA;
            u32 minDist;
            s16 angleBetween;
            s32 halfDiff;
            f32 radius = *(f32 *) (*(u8 **) ((u8 *) D_overlay_155_09B04F6C + 0x4C) + 0x24) + 10.0f;
            f32 offset;
            f32 farDist;
            s16 ang;
            s16 px;
            s16 pz;
            s32 key = (regionIndex << 0x10) + edge;

            if (distA < distB) {
                near = a;
                far = b;
                minDist = distA;
                nearAng = angA;
                nearIsA = 1;
            } else {
                near = b;
                far = a;
                minDist = distB;
                nearAng = angB;
                nearIsA = 0;
            }
            angleBetween = (s16) (Arctanf((f32) (near->y - far->y), (f32) (near->x - far->x)) - 0x8000);
            halfDiff = mathDiffAngle(angleBetween, nearAng) >> 1;
            offset = radius / Sinf((s16) halfDiff);
            if (nearIsA == 0) {
                ang = (s16) ((halfDiff + angleBetween) - 0x8000);
            } else {
                ang = (s16) (halfDiff + angleBetween);
            }
            farDist = offset + radius;

            px = (s16) (s32) ((Cosf((s32) ang) * farDist) + (f32) near->x);
            pz = (s16) (s32) ((Sinf(ang) * farDist) + (f32) near->y);
            if (func_overlay_155_09B001B4_1FE6634((f32) px, (f32) pz, D_overlay_155_09B04F80) != 0) {
                s16 cx = (s16) (s32) ((Cosf((s32) ang) * offset) + (f32) near->x);
                s16 cz = (s16) (s32) ((Sinf(ang) * offset) + (f32) near->y);
                s16 tAng = (s16) (nearAng - mathDiffAngle(nearAng, ang));
                s16 ex = (s16) (s32) ((Cosf((s32) tAng) * offset) + (f32) near->x);
                s16 ez = (s16) (s32) ((Sinf(tAng) * offset) + (f32) near->y);
                s32 bad;

                /* Reject: segment crosses the region, end point outside, or facing check fails. */
                bad = (DoesLineCrossRegion((f32) cx, (f32) cz, (f32) ex, (f32) ez, D_overlay_155_09B04F80, 0, -1, 0xFF) != 0) ||
                      (func_overlay_155_09B001B4_1FE6634((f32) ex, (f32) ez, D_overlay_155_09B04F80) == 0);
                if (!bad && (D_overlay_155_09B04F8C != 0)) {
                    s32 diff = mathDiffAngle(D_overlay_155_09B04F90,
                                             (s16) (Arctanf(D_overlay_155_09B04F6C->segment.trans.z_position - (f32) cz,
                                                            D_overlay_155_09B04F6C->segment.trans.x_position - (f32) cx) - 0x8000));
                    s32 absDiff = (diff >= 0) ? diff : -diff;
                    if (absDiff < 0x2000) {
                        bad = 1;
                    }
                }

                if (!bad) {
                    func_overlay_155_09B000C8_1FE6548(cx, cz, ex, ez, key, minDist);
                } else {
                    /* Second candidate: mirrored about the near point. */
                    s16 mAng = (nearIsA == 0) ? (s16) (-0x8000 - angleBetween) : (s16) (angleBetween * -1);
                    s16 mx = (s16) (s32) ((Sinf(mAng) * radius) + (f32) near->x);
                    f32 mz = (Cosf((s32) mAng) * radius) + (f32) near->y;
                    s16 rx = (s16) (cx + ((mx - cx) * 2));
                    s32 mzi = (s32) mz;
                    s16 rz = (s16) (cz + ((mzi - cz) * 2));
                    s32 dX;
                    s32 dZ;
                    s16 ang2;
                    f32 len2;
                    f32 far2;
                    s16 ex2;
                    s16 ez2;

                    DoLinesIntersect(arg0, arg1, near->x + ((near->x - arg0) * 4), near->y + ((near->y - arg1) * 4),
                                     cx, cz, rx, rz, &rx, &rz);
                    dX = rx - cx;
                    dZ = rz - cz;
                    ang2 = (s16) Arctanf((f32) dX, (f32) dZ);
                    len2 = sqrtf((f32) ((dX * dX) + (dZ * dZ)));
                    far2 = len2 + radius;
                    ex2 = (s16) (s32) ((Sinf(ang2) * far2) + (f32) cx);
                    ez2 = (s16) (s32) ((Cosf((s32) ang2) * far2) + (f32) cz);

                    bad = (DoesLineCrossRegion((f32) cx, (f32) cz, (f32) ex2, (f32) ez2, D_overlay_155_09B04F80, 0, -1, 0xFF) != 0) ||
                          (func_overlay_155_09B001B4_1FE6634((f32) ex2, (f32) ez2, D_overlay_155_09B04F80) == 0);
                    if (!bad && (D_overlay_155_09B04F8C != 0)) {
                        s32 diff = mathDiffAngle(D_overlay_155_09B04F90,
                                                 (s16) (Arctanf(D_overlay_155_09B04F6C->segment.trans.z_position - (f32) cz,
                                                                D_overlay_155_09B04F6C->segment.trans.x_position - (f32) cx) - 0x8000));
                        s32 absDiff = (diff >= 0) ? diff : -diff;
                        if (absDiff < 0x2000) {
                            bad = 1;
                        }
                    }
                    if (!bad) {
                        func_overlay_155_09B000C8_1FE6548(cx, cz, ex2, ez2, key, minDist);
                    }
                }
            }
        }
        a = b;
        edge -= 1;
    } while (edge != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B00644_1FE6AC4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B00FC4_1FE7444(s16 arg0, s16 arg1, void *arg2) {
    OvlRegion *region;
    OvlRegion *entry;
    void **list;
    s32 count;

    D_overlay_155_09B03C70 = 0;
    region = GetRegion(*(s16 *) ((u8 *) D_overlay_155_09B04F78 + 0x7A));
    D_overlay_155_09B04F80 = region;
    func_overlay_155_09B00644_1FE6AC4(arg0, arg1, region);

    entry = region->entries;
    while (entry != NULL) {
        s32 flags = entry->flags;

        if ((flags & 1) && !(flags & 4)) {
            Object *obj = entry->obj;

            if (obj == NULL) {
                func_overlay_155_09B00644_1FE6AC4(arg0, arg1, entry);
            } else if ((obj->behaviorId != 0x5B) || (*((u8 *) obj + 0x3A) < 2)) {
                if (flags & 8) {
                    func_overlay_155_09B00268_1FE66E8((f32) arg0, (f32) arg1, obj, GetRegionIndex(entry));
                } else {
                    func_overlay_155_09B00644_1FE6AC4(arg0, arg1, entry);
                }
            }
        }
        entry = entry->next;
    }

    list = squadsGetSquadronList(&count);
    count -= 1;
    if (count != 0) {
        do {
            void *squad = list[count];
            void *sqRacer = *(void **) ((u8 *) squad + 0x68);
            void *node = *(void **) ((u8 *) sqRacer + 0x58);

            while (node != NULL) {
                void *member = *(void **) ((u8 *) node + 0x68);

                if ((*(s32 *) ((u8 *) node + 0xA0) == 0) &&
                    (arg2 == *(void **) ((u8 *) member + 0x64))) {
                    OvlPathNode *nodes = D_overlay_155_09B04D50;
                    OvlSlot *slot = *(OvlSlot **) ((u8 *) member + 0xB0);
                    s32 i;

                    for (i = 0; i < D_overlay_155_09B03C70; i++) {
                        if ((slot != NULL) && (nodes[i].unkC == slot->size)) {
                            nodes[i].unk10 = (s32) ((*(s16 *) ((u8 *) sqRacer + 0x64) << 0x10) +
                                                     *((u8 *) member + 0x15) + 1);
                            break;
                        }
                    }
                }
                node = *(void **) ((u8 *) member + 0x28);
            }
            count -= 1;
        } while (count != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B00FC4_1FE7444.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B01274_1FE76F4(Object *arg0) {
    OvlCacheEntry *entry;
    s32 i;

    if ((arg0->behaviorId == 0x18) && (*(u32 *) arg0->racer & 8)) {
        D_overlay_155_09B04D50 = NULL;
        D_overlay_155_09B03C70 = 0;
        return;
    }

    entry = D_overlay_155_09B04F98;
    for (i = 0; i < 3; i++, entry++) {
        if (arg0 == entry->owner) {
            D_overlay_155_09B04D50 = (OvlPathNode *) entry->buf;
            entry->x = (s16) (s32) arg0->segment.trans.x_position;
            entry->y = (s16) (s32) arg0->segment.trans.z_position;
            if ((*(u8 *) ((u8 *) D_overlay_155_09B04F78 + 0x38) == 4) ||
                (*(u8 *) ((u8 *) D_overlay_155_09B04F78 + 0x39) == 4)) {
                D_overlay_155_09B04F8C = 1;
            } else {
                D_overlay_155_09B04F8C = 0;
            }
            entry->regionFlag = (s8) D_overlay_155_09B04F8C;
            func_overlay_155_09B00FC4_1FE7444(entry->x, entry->y, arg0);
            entry->count = (s8) D_overlay_155_09B03C70;
            return;
        }
    }

    entry = D_overlay_155_09B04F98;
    for (i = 0; i < 3; i++, entry++) {
        if (entry->owner == NULL) {
            OvlPathNode *buf = (OvlPathNode *) entry->buf;

            entry->owner = arg0;
            entry->timer = 0x1E;
            if (buf == NULL) {
                buf = (OvlPathNode *) mmAlloc(0x500, -1U);
                entry->buf = buf;
            }
            D_overlay_155_09B04D50 = buf;
            if (buf != NULL) {
                entry->x = (s16) (s32) arg0->segment.trans.x_position;
                entry->y = (s16) (s32) arg0->segment.trans.z_position;
                if ((*(u8 *) ((u8 *) D_overlay_155_09B04F78 + 0x38) == 4) ||
                    (*(u8 *) ((u8 *) D_overlay_155_09B04F78 + 0x39) == 4)) {
                    D_overlay_155_09B04F8C = 1;
                } else {
                    D_overlay_155_09B04F8C = 0;
                }
                entry->regionFlag = (s8) D_overlay_155_09B04F8C;
                func_overlay_155_09B00FC4_1FE7444(entry->x, entry->y, arg0);
                entry->count = (s8) D_overlay_155_09B03C70;
            }
            return;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B01274_1FE76F4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_155_09B01584_1FE7A04(Object *arg0, s32 arg1) {
    s32 savedCount = D_overlay_155_09B03C70;
    OvlPathNode *cur = D_overlay_155_09B04D50;
    void *racer;
    void *track;
    void *target;
    s32 i;

    D_overlay_155_09B04F6C = arg0;
    racer = arg0->racer;
    D_overlay_155_09B04F70 = racer;
    track = *(void **) ((u8 *) racer + 0x24);
    D_overlay_155_09B04F74 = track;
    D_overlay_155_09B04F78 = *(void **) ((u8 *) track + 0x68);
    D_overlay_155_09B04F88 = (*(s16 *) ((u8 *) D_overlay_155_09B04F78 + 0x64) << 0x10) +
                             *((u8 *) racer + 0x15) + 1;
    D_overlay_155_09B04F80 = GetRegion(*(s16 *) ((u8 *) D_overlay_155_09B04F78 + 0x7A));

    D_overlay_155_09B04FD8 = GetBaddyData(arg0);
    if (D_overlay_155_09B04FD8 == 0) {
        return 0;
    }

    target = *(void **) ((u8 *) racer + 0x64);
    if (target != NULL) {
        D_overlay_155_09B04F90 = (s16) (Arctanf(D_overlay_155_09B04F6C->segment.trans.z_position -
                                                ((Object *) target)->segment.trans.z_position,
                                                D_overlay_155_09B04F6C->segment.trans.x_position -
                                                ((Object *) target)->segment.trans.x_position) - 0x8000);
    }
    D_overlay_155_09B04F94 = 0;
    D_overlay_155_09B04F84 = NULL;

    D_overlay_155_09B04F7C = *(OvlSlot **) ((u8 *) racer + 0xB0);
    if (D_overlay_155_09B04F7C == NULL) {
        s16 v = (s16) (s32) D_overlay_155_09B04F6C->segment.trans.x_position;
        s16 w = (s16) (s32) D_overlay_155_09B04F6C->segment.trans.z_position;

        D_overlay_155_09B04F7C = (OvlSlot *) mmAlloc(0x20, 0xFFFF);
        *(OvlSlot **) ((u8 *) racer + 0xB0) = D_overlay_155_09B04F7C;
        D_overlay_155_09B04F7C->unk10 = v;
        D_overlay_155_09B04F7C->unk14 = v;
        D_overlay_155_09B04F7C->nextIndex = v;
        D_overlay_155_09B04F7C->flags = v;
        D_overlay_155_09B04F7C->index = w;
        D_overlay_155_09B04F7C->unk12 = w;
        D_overlay_155_09B04F7C->unk16 = w;
        D_overlay_155_09B04F7C->prevIndex = w;
        D_overlay_155_09B04F7C->unk3 = (u8) (D_overlay_155_09B04F7C->unk3 | 2);
        D_overlay_155_09B04F7C->unk3 = (u8) (D_overlay_155_09B04F7C->unk3 & 0xFFFB);
        D_overlay_155_09B04F7C->unk1 = 0;
        D_overlay_155_09B04F7C->unk18 = -1;
        D_overlay_155_09B04F7C->size = 0;
    }
    if (arg1 == 0) {
        return 1;
    }

    target = *(void **) ((u8 *) D_overlay_155_09B04F70 + 0x64);
    if (target == NULL) {
        D_overlay_155_09B04F84 = NULL;
        return 1;
    }
    func_overlay_155_09B01274_1FE76F4((Object *) target);

    if (WhichRegionIsPointIn(D_overlay_155_09B04F64, D_overlay_155_09B04F66) != 0) {
        D_overlay_155_09B04F68 = D_overlay_155_09B04F64;
        D_overlay_155_09B04F6A = D_overlay_155_09B04F66;
    }

    for (i = 0; i < savedCount; i++, cur++) {
        if (D_overlay_155_09B04F7C->size == cur->unkC) {
            D_overlay_155_09B04F84 = cur;
            break;
        }
    }
    if (D_overlay_155_09B04F84 == NULL) {
        D_overlay_155_09B04F7C->unk3 = (u8) (D_overlay_155_09B04F7C->unk3 | 2);
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B01584_1FE7A04.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_155_09B018C4_1FE7D44(void *arg0) {
    s32 key = *(s32 *) ((u8 *) arg0 + 0x10);

    if (D_overlay_155_09B04F88 == key) {
        return 2;
    }
    if (key == 0) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B018C4_1FE7D44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_155_09B01900_1FE7D80(void) {
    u32 start = D_overlay_155_09B04D58;
    u32 next = start + 0x84;
    u32 cand;

    for (;;) {
        D_overlay_155_09B04D58 = next;
        cand = next;
        if (next >= (u32) &D_overlay_155_09B04D50) {
            D_overlay_155_09B04D58 = (u32) D_overlay_155_09B03CD0;
            cand = (u32) D_overlay_155_09B03CD0;
        }
        if (start == cand) {
            D_overlay_155_09B04F60 = 1;
            return NULL;
        }
        next = cand + 0x84;
        if ((D_overlay_155_09B04D5C != (*(u8 *) (cand + 0x79) >> 2)) ||
            ((*(u8 *) (cand + 0x78) & 1) != 0)) {
            *(u8 *) (start + 0x79) = (u8) ((D_overlay_155_09B04D5C * 4) | (*(u8 *) (start + 0x79) & 0xFF03));
            return (void *) start;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B01900_1FE7D80.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_155_09B019A4_1FE7E24(s32 *arg0) {
    void *dst = func_overlay_155_09B01900_1FE7D80();
    s32 i;

    if (dst == NULL) {
        return NULL;
    }
    for (i = 0; i < 0x20; i++) {
        ((s32 *) dst)[i] = arg0[i];
    }
    return dst;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B019A4_1FE7E24.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_155_09B01A00_1FE7E80(s16 arg0, s16 arg1, f32 arg2) {
    OvlCostEntry *e;
    s32 i;

    for (i = 0, e = D_overlay_155_09B04D60; i < 0x40; i++, e++) {
        if ((e->cost != 0) && (arg0 == e->x) && (arg1 == e->y)) {
            if (arg2 < (f32) e->cost) {
                e->cost = (u32) (s32) arg2;
                return 1;
            }
            return 0;
        }
    }
    for (i = 0, e = D_overlay_155_09B04D60; i < 0x40; i++, e++) {
        if (e->cost == 0) {
            e->x = arg0;
            e->y = arg1;
            e->cost = (u32) (s32) arg2;
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B01A00_1FE7E80.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B01BE0_1FE8060(OvlPathState *arg0, s16 arg1, s16 arg2, s8 arg3, u8 arg4) {
    u8 prev = arg0->count;
    s16 dx;
    s16 dz;
    s16 dxCenter;
    s16 dzCenter;

    arg0->count = (u8) (prev + 1);
    arg0->xs[arg0->count] = arg1;
    dx = (s16) (arg1 - arg0->xs[prev]);
    dz = (s16) (arg2 - arg0->ys[prev]);
    arg0->ys[arg0->count] = arg2;
    arg0->unk50[arg0->count] = arg3;
    arg0->unk64[arg0->count] = arg4;
    arg0->length = (f32) (arg0->length + sqrtf((f32) ((dx * dx) + (dz * dz))));
    arg0->flags = (u8) ((arg0->flags & 0xFFFC) | 1);

    if ((s32) arg0->count >= 2 && func_overlay_155_09B01A00_1FE7E80(arg1, arg2, arg0->length) == 0) {
        arg0->flags = (u8) (arg0->flags & 0xFFFC);
        return;
    }

    dxCenter = (s16) (arg1 - D_overlay_155_09B04D54);
    if ((arg1 == D_overlay_155_09B04D54) && (arg2 == D_overlay_155_09B04D56)) {
        arg0->unk80 = 0;
        return;
    }
    dzCenter = (s16) (arg2 - D_overlay_155_09B04D56);
    arg0->unk80 = (s32) ((dxCenter * dxCenter) + (dzCenter * dzCenter));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B01BE0_1FE8060.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B01D9C_1FE821C(s16 *arg0, s16 *arg1, u8 arg2, s32 arg3) {
    OvlRegion *region = GetRegion(arg3 & 0xFF);
    OvlPoint *pts = region->points;
    OvlPoint *cur = &pts[arg2];
    OvlPoint *prev;
    OvlPoint *next;
    s16 angPrev;
    s16 angNext;
    s16 bisector;
    f32 radius;

    if (arg2 != 0) {
        prev = &pts[arg2 - 1];
    } else {
        prev = &pts[region->numPoints - 1];
    }
    if (arg2 >= region->numPoints) {
        next = &pts[0];
    } else {
        next = &pts[arg2 + 1];
    }

    angPrev = (s16) (Arctanf((f32) (cur->y - prev->y), (f32) (cur->x - prev->x)) - 0x8000);
    angNext = (s16) (Arctanf((f32) (cur->y - next->y), (f32) (cur->x - next->x)) - 0x8000);
    bisector = (s16) ((mathDiffAngle(angPrev, angNext) >> 1) + angPrev);

    radius = *(f32 *) (*(u8 **) ((u8 *) D_overlay_155_09B04F6C + 0x4C) + 0x24) + 15.0f;
    *arg0 = (s16) (s32) ((f32) *arg0 - (Cosf((s32) bisector) * radius));
    *arg1 = (s16) (s32) ((f32) *arg1 - (Sinf(bisector) * radius));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B01D9C_1FE821C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_155_09B01F9C_1FE841C(OvlPathState *arg0) {
    OvlLineHit hit;
    OvlRegion *region;
    u8 count;
    s16 curX;
    s16 curY;
    s32 found;

    count = arg0->count;
    curX = arg0->xs[count];
    curY = arg0->ys[count];
    arg0->flags = (arg0->flags & 1) | (arg0->flags & 0xFC);
    if ((D_overlay_155_09B04F60 != 0) || (count >= 0x14)) {
        return 0;
    }
    found = DoesLineCrossRegion((f32) curX, (f32) curY, (f32) D_overlay_155_09B04D54, (f32) D_overlay_155_09B04D56,
                                D_overlay_155_09B04F80, (s32) &hit, (u8) arg0->unk50[count], (u8) arg0->unk64[count]);
    if ((found == 0) || ((hit.x == D_overlay_155_09B04D54) && (hit.y == D_overlay_155_09B04D56))) {
        func_overlay_155_09B01BE0_1FE8060(arg0, D_overlay_155_09B04D54, D_overlay_155_09B04D56, -1, 0);
    } else {
        region = GetRegion(hit.regionIdx);
        if ((curX != hit.x) || (curY != hit.y)) {
            func_overlay_155_09B01BE0_1FE8060(arg0, hit.x, hit.y, (s8) hit.segIdx, hit.regionIdx);
            if (hit.flag != 0) {
                arg0->flags = ((arg0->flags | 2) & 3) | (arg0->flags & 0xFC);
            }
        }
        if ((hit.ptA != hit.segIdx) && (D_overlay_155_09B04F60 == 0)) {
            OvlPathState *node = (OvlPathState *) func_overlay_155_09B019A4_1FE7E24((s32 *) arg0);

            if (node != NULL) {
                OvlPoint *pt = &region->points[hit.ptA];

                func_overlay_155_09B01BE0_1FE8060(node, pt->x, pt->y, (s8) hit.ptA, hit.regionIdx);
                node->flags = ((node->flags | 2) & 3) | (node->flags & 0xFC);
            }
        }
        if ((hit.ptB != hit.segIdx) && (D_overlay_155_09B04F60 == 0)) {
            OvlPathState *node = (OvlPathState *) func_overlay_155_09B019A4_1FE7E24((s32 *) arg0);

            if (node != NULL) {
                OvlPoint *pt = &region->points[hit.ptB];

                func_overlay_155_09B01BE0_1FE8060(node, pt->x, pt->y, (s8) hit.ptB, hit.regionIdx);
                node->flags = ((node->flags | 2) & 3) | (node->flags & 0xFC);
            }
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B01F9C_1FE841C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
OvlPathState *func_overlay_155_09B02248_1FE86C8(void) {
    OvlPathState *entry = (OvlPathState *) D_overlay_155_09B03CD0;
    OvlPathState *best = NULL;
    u32 bestScore = 0xFFFFFFFF;
    s32 n = 0x1F;

    do {
        if (D_overlay_155_09B04D5C == (s32) (entry->flags >> 2)) {
            u32 score = (u32) entry->unk80;

            if ((score == 0) || (((entry->flags & 3) == 3) && (score < bestScore))) {
                bestScore = score;
                best = entry;
            }
        }
        entry++;
        n--;
    } while (n != 0);
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B02248_1FE86C8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
OvlPathState *func_overlay_155_09B022C8_1FE8748(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    OvlPathState *p;
    OvlPathState *best;
    f32 dist;
    s32 score;

    p = (OvlPathState *) func_overlay_155_09B01900_1FE7D80();
    if (p == NULL) {
        return func_overlay_155_09B02248_1FE86C8();
    }
    p->xs[0] = arg0;
    p->ys[0] = arg1;
    p->unk50[0] = -1;
    p->unk64[0] = 0;
    dist = sqrtf((f32) (((arg2 - arg0) * (arg2 - arg0)) + ((arg3 - arg1) * (arg3 - arg1))));
    /* asm: float -> s32 with an overflow path that sets bit 31, -1 when out of range */
    if (dist >= 2147483648.0f) {
        if ((dist - 2147483648.0f) >= 2147483648.0f) {
            score = -1;
        } else {
            score = ((s32) (dist - 2147483648.0f)) | 0x80000000;
        }
    } else {
        score = (s32) dist;
    }
    p->unk80 = score;
    p->flags |= 3;
    D_overlay_155_09B04D54 = arg2;
    D_overlay_155_09B04D56 = arg3;
    if (func_overlay_155_09B01F9C_1FE841C(p) == 0) {
        return p;
    }
    for (;;) {
        best = func_overlay_155_09B02248_1FE86C8();
        if (best == NULL) {
            return NULL;
        }
        if (best->unk80 == 0) {
            return best;
        }
        if (func_overlay_155_09B01F9C_1FE841C(best) == 0) {
            return best;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B022C8_1FE8748.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FindBestPathInRegion(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    OvlPathState *path;
    s16 hitX;
    s32 count;
    s32 idx;
    s16 *seg;
    u8 kind;

    _bzero(D_overlay_155_09B03CD0, 0x1080);
    _bzero(D_overlay_155_09B04D60, 0x200);
    D_overlay_155_09B04D58 = (u32) D_overlay_155_09B03CD0;
    D_overlay_155_09B04D5C = 0x3F;
    D_overlay_155_09B04F60 = 0;
    path = func_overlay_155_09B022C8_1FE8748(arg1, arg2, arg3, arg4);
    if (path == NULL) {
        *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x38) = (f32) arg1;
        *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x3C) = *(f32 *) ((u8 *) arg0 + 0x10);
        *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x40) = (f32) arg2;
        return;
    }
    D_overlay_155_09B04D5C -= 1;
    count = path->count;
    idx = 2;
    if (count >= 3) {
        for (idx = 2; idx < count; idx++) {
            if (DoesLineCrossRegion((f32) arg1, (f32) arg2, (f32) path->xs[idx], (f32) path->ys[idx],
                                    D_overlay_155_09B04F80, (s32) &hitX, -1, 0xFF) != 0) {
                /* asm: break unless (hitX - ys) * (hitX - xs) * 2 < 0x11 */
                if (!((u32) (((hitX - path->ys[idx]) * (hitX - path->xs[idx])) * 2) < 0x11U)) {
                    break;
                }
            }
        }
    }
    seg = (s16 *) ((u8 *) path + idx * 2);
    kind = *((u8 *) path + idx + 0x4F);
    if (kind != 0xFF) {
        func_overlay_155_09B01D9C_1FE821C(seg - 1, (s16 *) ((u8 *) seg + 0x26), kind, *((u8 *) path + idx + 0x63));
    }
    D_overlay_155_09B04F7C->unk14 = seg[-1];
    D_overlay_155_09B04F7C->unk16 = *(s16 *) ((u8 *) seg + 0x26);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/FindBestPathInRegion.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B026D8_1FE8B58(OvlPathNode *arg0, s16 arg1, s16 arg2, s16 *arg3, s16 *arg4) {
    if (arg0 != NULL) {
        arg0->unk10 = D_overlay_155_09B04F88;
        D_overlay_155_09B04F7C->size = arg0->unkC;
        *arg3 = arg0->unk0;
        *arg4 = arg0->unk2;
        return;
    }
    *arg3 = arg1;
    *arg4 = arg2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B026D8_1FE8B58.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_155_09B02748_1FE8BC8(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3) {
    OvlPathNode *node;
    OvlPathNode *best;
    u32 bestDist;
    u32 dist;
    s32 dx;
    s32 dz;
    s16 px;
    s16 pz;
    s32 i;

    node = D_overlay_155_09B04D50;
    best = NULL;
    bestDist = 0xFFFFFFFF;
    px = (s16) (s32) D_overlay_155_09B04F6C->segment.trans.x_position;
    pz = (s16) (s32) D_overlay_155_09B04F6C->segment.trans.z_position;
    for (i = 0; i < D_overlay_155_09B03C70; i++) {
        dx = px - node->unk0;
        dz = pz - node->unk2;
        dist = (dx * dx) + (dz * dz);
        if (dist < bestDist && func_overlay_155_09B018C4_1FE7D44(node) != 0) {
            bestDist = dist;
            best = node;
        }
        node++;
    }
    func_overlay_155_09B026D8_1FE8B58(best, arg0, arg1, arg2, arg3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B02748_1FE8BC8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
OvlPathNode *func_overlay_155_09B0289C_1FE8D1C(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3) {
    OvlPathNode *best;
    OvlPathNode *node;
    OvlPathNode *cur;
    s32 px;
    s32 pz;
    u32 bestDist;
    u32 limit;
    u32 dist;
    s32 dx;
    s32 dz;
    s32 i;
    s16 angA;
    s16 angB;

    best = NULL;
    node = D_overlay_155_09B04D50;
    px = (s32) D_overlay_155_09B04F6C->segment.trans.x_position;
    bestDist = 0xFFFFFFFF;
    pz = (s32) D_overlay_155_09B04F6C->segment.trans.z_position;
    if (D_overlay_155_09B04F84 != NULL) {
        limit = D_overlay_155_09B04F84->unk8;
    }
    /* asm: when D_overlay_155_09B04F84 is NULL the limit comes from an uninitialised stack slot (0x54) */
    for (i = 0; i < D_overlay_155_09B03C70; i++) {
        cur = node;
        if (cur != D_overlay_155_09B04F84 && cur->unk8 < limit) {
            dx = px - cur->unk0;
            dz = pz - cur->unk2;
            dist = (dx * dx) + (dz * dz);
            if (dist < bestDist && func_overlay_155_09B018C4_1FE7D44(cur) != 0) {
                angA = (s16) Arctanf((f32) (pz - D_overlay_155_09B04F6A), (f32) (px - D_overlay_155_09B04F68));
                angB = mathDiffAngle(angA, (s16) Arctanf((f32) (cur->unk2 - D_overlay_155_09B04F6A), (f32) (cur->unk0 - D_overlay_155_09B04F68)));
                /* asm: branch accepts for any diff (diff < 0x4E20 || diff >= -0x4E1F) */
                if (angB < 0x4E20 || !(angB < -0x4E1F)) {
                    limit = cur->unk8;
                    bestDist = dist;
                    best = cur;
                }
            }
        }
        node++;
    }
    func_overlay_155_09B026D8_1FE8B58(best, arg0, arg1, arg2, arg3);
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B0289C_1FE8D1C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
OvlPathNode *func_overlay_155_09B02AEC_1FE8F6C(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3) {
    OvlPathNode *node;
    OvlPathNode *best;
    u32 bestScore;
    s32 i;

    node = D_overlay_155_09B04D50;
    best = NULL;
    bestScore = 0;
    for (i = 0; i < D_overlay_155_09B03C70; i++) {
        if (bestScore < node->unk8 && func_overlay_155_09B018C4_1FE7D44(node) != 0) {
            bestScore = node->unk8;
            best = node;
        }
        node++;
    }
    func_overlay_155_09B026D8_1FE8B58(best, arg0, arg1, arg2, arg3);
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/func_overlay_155_09B02AEC_1FE8F6C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquadronControlSmart(void *arg0) {
    u8 *sq;
    u8 *baddy;
    u8 *cur;
    u8 *racer;
    u8 *cb;
    u8 *node;
    s32 active;
    s32 side;
    s32 anyFlag;
    s32 needBlock49;
    u16 t;

    sq = *(u8 **) ((u8 *) arg0 + 0x68);
    active = 1;
    baddy = NULL;
    if (sq[0x37] != 0) {
        sq[0x37] -= 1;
        return;
    }
    node = *(u8 **) (sq + 0x58);
    if (node != NULL) {
        baddy = (u8 *) GetBaddyData((Object *) node);
    }
    if (node != NULL) {
        do {
            func_overlay_155_09B01584_1FE7A04((Object *) node, 0);
            if (!(*(u32 *) D_overlay_155_09B04F7C & 4) && *((u8 *) D_overlay_155_09B04F70 + 0x1A) == 0) {
                active = 0;
                break;
            }
            node = *(u8 **) ((u8 *) D_overlay_155_09B04F70 + 0x28);
        } while (node != NULL);
    }

    cur = (u8 *) D_overlay_155_09B04F70;
    if (*(u32 *) cur & 8) {
        if (active != 0) {
            cb = *(u8 **) (cur + 0xB0);
            cb[3] |= 2;
            cb = *(u8 **) (cur + 0xB0);
            cb[3] &= 0xFB;
        }
        racer = *(u8 **) (cur + 0x64);
        if (racer == NULL) {
            goto block_49;
        }
        if (*(s16 *) (racer + 0x48) != 1) {
            sq[0x38] = 4;
            return;
        }
        if (!(*(u16 *) (cur + 0x4) & 1)) {
            goto block_49;
        }
        sq[0x38] = 5;
        return;
    }
    if (*(u32 *) (baddy + 0x24) & 0x10) {
        if (active != 0) {
            cb = *(u8 **) (cur + 0xB0);
            cb[3] |= 2;
            cb = *(u8 **) (cur + 0xB0);
            cb[3] &= 0xFB;
        }
        racer = *(u8 **) (cur + 0x64);
        if (racer == NULL || !(*(u16 *) (cur + 0x4) & 1)) {
            goto block_49;
        }
        sq[0x38] = 5;
        return;
    }
    if (*(u16 *) (sq + 0x2C) == 0x8D) {
        node = *(u8 **) (sq + 0x58);
        anyFlag = 0;
        needBlock49 = 1;
        if (node != NULL) {
            do {
                racer = *(u8 **) (node + 0x68);
                cb = *(u8 **) (racer + 0x64);
                if (cb != NULL) {
                    needBlock49 = 0;
                    if (*(s16 *) (cb + 0x48) == 0x18) {
                        cb = *(u8 **) (racer + 0xB0);
                        anyFlag = 1;
                        if (*(u32 *) cb & 4) {
                            cb[3] |= 2;
                            cb = *(u8 **) (racer + 0xB0);
                            cb[3] &= 0xFB;
                        }
                    }
                }
                node = *(u8 **) (racer + 0x28);
            } while (node != NULL);
        }
        if (anyFlag != 0) {
            sq[0x38] = 5;
            sq[0x39] = 5;
            return;
        }
        if (needBlock49 != 0) {
            goto block_49;
        }
        goto block_37;
    }

block_37:
    if (active != 0) {
        t = *(u16 *) (sq + 0x28) ^ 0x100;
        *(u16 *) (sq + 0x28) = t;
        if (t & 0x100) {
            side = 0;
            sq[0x38] = 3;
            sq[0x39] = 2;
        } else {
            side = 1;
            sq[0x39] = 3;
            sq[0x38] = 2;
        }
        node = *(u8 **) (sq + 0x58);
        if (node != NULL) {
            do {
                racer = *(u8 **) (node + 0x68);
                if (side == (*(u8 *) (racer + 0x15) & 1)) {
                    cb = *(u8 **) (racer + 0xB0);
                    cb[3] |= 2;
                    cb = *(u8 **) (racer + 0xB0);
                    cb[1] = (u8) objTvTimes(mathRnd(0xA, 0x19));
                }
                cb = *(u8 **) (racer + 0xB0);
                cb[3] &= 0xFB;
                node = *(u8 **) (racer + 0x28);
            } while (node != NULL);
        }
        if (baddy != NULL) {
            sq[0x37] = baddy[0x2E];
        } else {
            sq[0x37] = 0x32;
        }
    }
    return;

block_49:
    cb = *(u8 **) (cur + 0xB0);
    cb[3] &= 0xFD;
    cb = *(u8 **) (cur + 0xB0);
    cb[3] |= 4;
    sq[0x38] = 8;
    sq[0x39] = 8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/SquadronControlSmart.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Raw offsets follow the asm: D_overlay_155_09B04F70 is the mover state (0x00 flags,
 * 0x15/0x18/0x1A bytes, 0x38/0x40 position, 0x64 target), D_overlay_155_09B04F78 holds the
 * mode bytes at 0x38/0x39. Slot flag bits are read from the low byte (unk3) of the word at 0. */
void SmartMover(Object *obj, s32 mode) {
    f32 x;
    f32 z;
    f32 range;
    f32 g;
    s16 tx;
    s16 tz;
    s32 best;
    u8 timer;
    Object *target;
    OvlRegion *var_s0;

    x = obj->segment.trans.x_position;
    z = obj->segment.trans.z_position;

    if (func_overlay_155_09B01584_1FE7A04(obj, 1) == 0) {
        return;
    }
    if (!(*(u32 *) D_overlay_155_09B04F70 & 0x04000000) ||
        (*(u32 *) ((u8 *) D_overlay_155_09B04FD8 + 0x24) & 0x200) ||
        (*(u32 *) D_overlay_155_09B04F70 & 0x800)) {
        target = *(Object **) ((u8 *) D_overlay_155_09B04F70 + 0x64);
        if (target != NULL) {
            tx = (s16) (s32) target->segment.trans.x_position;
            tz = (s16) (s32) target->segment.trans.z_position;
        } else {
            tx = (s16) (s32) obj->segment.trans.x_position;
            tz = (s16) (s32) obj->segment.trans.z_position;
        }
        if (mode == 0) {
            if (!(*(u8 *) ((u8 *) D_overlay_155_09B04F70 + 0x15) & 1)) {
                mode = *(u8 *) ((u8 *) D_overlay_155_09B04F78 + 0x38);
            } else {
                mode = *(u8 *) ((u8 *) D_overlay_155_09B04F78 + 0x39);
            }
        }
        D_overlay_155_09B04F7C->unk0 = (u8) mode;

        if (func_overlay_155_09B001B4_1FE6634(x, z, D_overlay_155_09B04F80) != 0) {
            D_overlay_155_09B04F7C->flags = (s16) (s32) x;
            D_overlay_155_09B04F7C->prevIndex = (s16) (s32) z;
        } else {
            x = (f32) D_overlay_155_09B04F7C->flags;
            z = (f32) D_overlay_155_09B04F7C->prevIndex;
        }
        func_overlay_155_09B001B4_1FE6634(x, z, D_overlay_155_09B04F80);

        switch (mode) {
        case 2:
            if (D_overlay_155_09B04F84 != NULL) {
                tx = D_overlay_155_09B04F84->unk4;
                tz = D_overlay_155_09B04F84->unk6;
            } else {
                tx = (s16) (s32) obj->segment.trans.x_position;
                tz = (s16) (s32) obj->segment.trans.z_position;
            }
            *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18) = 0;
            break;
        case 3:
            if ((D_overlay_155_09B04F7C->unk3 & 2) &&
                (func_overlay_155_09B0289C_1FE8D1C((s16) (s32) x, (s16) (s32) z,
                                                   &D_overlay_155_09B04F7C->unk10,
                                                   &D_overlay_155_09B04F7C->unk12) != NULL)) {
                *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18) = 0xFFFFFFFF;
                tx = D_overlay_155_09B04F7C->unk10;
                tz = D_overlay_155_09B04F7C->unk12;
            } else {
                goto case_1;
            }
            break;
        case 1:
        case_1:
            if (D_overlay_155_09B04F7C->unk3 & 2) {
                func_overlay_155_09B02748_1FE8BC8((s16) (s32) x, (s16) (s32) z,
                                                  &D_overlay_155_09B04F7C->unk10,
                                                  &D_overlay_155_09B04F7C->unk12);
                *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18) = 0xFFFFFFFF;
            }
            tx = D_overlay_155_09B04F7C->unk10;
            tz = D_overlay_155_09B04F7C->unk12;
            break;
        case 4:
            if (D_overlay_155_09B04F7C->unk3 & 2) {
                func_overlay_155_09B02AEC_1FE8F6C((s16) (s32) x, (s16) (s32) z,
                                                  &D_overlay_155_09B04F7C->unk10,
                                                  &D_overlay_155_09B04F7C->unk12);
                *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18) = 0xFFFFFFFF;
            }
            tx = D_overlay_155_09B04F7C->unk10;
            tz = D_overlay_155_09B04F7C->unk12;
            break;
        case 5:
            target = *(Object **) ((u8 *) D_overlay_155_09B04F70 + 0x64);
            if (target == NULL) {
                goto case_8;
            }
            if (DoesSquaddieWantToFire(0.0f, 0.0f, 0x2000) != 0) {
                tx = (s16) (s32) obj->segment.trans.x_position;
                tz = (s16) (s32) obj->segment.trans.z_position;
            } else {
                target = *(Object **) ((u8 *) D_overlay_155_09B04F70 + 0x64);
                if (D_overlay_155_09B03CC8 <
                    GetRangeSquared2D(obj->segment.trans.x_position, obj->segment.trans.z_position,
                                      target->segment.trans.x_position, target->segment.trans.z_position)) {
                    target = *(Object **) ((u8 *) D_overlay_155_09B04F70 + 0x64);
                    tx = (s16) (s32) target->segment.trans.x_position;
                    tz = (s16) (s32) target->segment.trans.z_position;
                } else {
                    tx = (s16) (s32) obj->segment.trans.x_position;
                    tz = (s16) (s32) obj->segment.trans.z_position;
                }
            }
            break;
        case 8:
        case_8:
            tx = (s16) (s32) obj->segment.trans.x_position;
            tz = (s16) (s32) obj->segment.trans.z_position;
            *(u8 *) ((u8 *) D_overlay_155_09B04F70 + 0x7) |= 1;
            break;
        }

        for (var_s0 = D_overlay_155_09B04F80->entries; var_s0 != NULL; var_s0 = var_s0->next) {
            if ((var_s0->flags & 2) &&
                (IsPointInRegion(obj->segment.trans.x_position, obj->segment.trans.z_position, var_s0) != 0) &&
                (*(u8 *) ((u8 *) D_overlay_155_09B04F70 + 0x1A) != 0x13)) {
                TryToSetMission(2, 0x13, *(u8 *) ((u8 *) var_s0 + 0x28), *(u8 *) ((u8 *) var_s0 + 0x29),
                                *(u8 *) ((u8 *) var_s0 + 0x2A));
            }
        }

        if (*(u8 *) ((u8 *) D_overlay_155_09B04F70 + 0x18) & 4) {
            D_overlay_155_09B04F7C->unk2 += 1;
            if (D_overlay_155_09B04F7C->unk2 >= 6) {
                tx = (s16) (s32) obj->segment.trans.x_position;
                tz = (s16) (s32) obj->segment.trans.z_position;
                D_overlay_155_09B04F7C->unk3 |= 4;
            }
        } else {
            D_overlay_155_09B04F7C->unk2 = 0;
        }

        if (func_overlay_155_09B001B4_1FE6634((f32) tx, (f32) tz, D_overlay_155_09B04F80) != 0) {
            D_overlay_155_09B04F7C->nextIndex = tx;
            D_overlay_155_09B04F7C->index = tz;
        } else {
            tx = D_overlay_155_09B04F7C->nextIndex;
            tz = D_overlay_155_09B04F7C->index;
        }

        range = GetRangeSquared2D(x, z, (f32) D_overlay_155_09B04F7C->unk14, (f32) D_overlay_155_09B04F7C->unk16);
        /* asm: cvt.w.s truncation; out-of-range (overflow) goes through (f - 2^31) | 0x80000000,
         * anything still out of range becomes -1; a negative truncated value becomes -1. */
        if (range >= -2147483648.0f && range < 2147483648.0f) {
            best = (s32) range;
            if (best < 0) {
                best = -1;
            }
        } else {
            g = range - 2147483648.0f;
            if (g >= -2147483648.0f && g < 2147483648.0f) {
                best = (s32) ((u32) (s32) g | 0x80000000U);
            } else {
                best = -1;
            }
        }

        if ((mode != 8) &&
            (((D_overlay_155_09B04F7C->unk3 & 2) != 0) ||
             ((u32) best >= *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18)) ||
             (*(u8 *) ((u8 *) D_overlay_155_09B04F70 + 0x18) & 4))) {
            D_overlay_155_09B04F7C->unk14 = tx;
            D_overlay_155_09B04F7C->unk16 = tz;
            FindBestPathInRegion(obj, (s16) (s32) x, (s16) (s32) z, D_overlay_155_09B04F7C->unk14,
                                 D_overlay_155_09B04F7C->unk16);
            *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18) = 0xFFFFFFFF;
            D_overlay_155_09B04F7C->unk3 &= 0xFD;
        }
        *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18) = (u32) best;

        timer = D_overlay_155_09B04F7C->unk1;
        if (timer != 0) {
            if ((s32) timer < iDeltaTime) {
                D_overlay_155_09B04F7C->unk1 = 0;
            } else {
                D_overlay_155_09B04F7C->unk1 = (u8) (timer - iDeltaTime);
            }
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x38) = x;
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x40) = z;
            *(u32 *) ((u8 *) D_overlay_155_09B04F7C + 0x18) = 0xFFFFFFFF;
        } else if (D_overlay_155_09B04F7C->unk3 & 4) {
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x38) = x;
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x40) = z;
        } else if (GetRangeSquared2D(x, z, (f32) tx, (f32) tz) < 200.0f) {
            D_overlay_155_09B04F7C->unk3 |= 4;
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x38) = x;
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x40) = z;
        } else {
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x38) = (f32) D_overlay_155_09B04F7C->unk14;
            *(f32 *) ((u8 *) D_overlay_155_09B04F70 + 0x40) = (f32) D_overlay_155_09B04F7C->unk16;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/SmartMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* arg2 and arg3 are not read by the asm. */
s16 SmartFacer(u8 *arg0, s16 arg1, u16 arg2, u8 arg3) {
    Object *obj;
    void *racer;
    Object *target;

    obj = (Object *) arg0;
    func_overlay_155_09B01584_1FE7A04(obj, 0);
    if ((D_overlay_155_09B04F7C->unk3 & 4) || (D_overlay_155_09B04F7C->unk1 != 0)) {
        racer = D_overlay_155_09B04F70;
        target = *(Object **) ((u8 *) racer + 0x64);
        if ((target != NULL) && (*(u8 *) ((u8 *) racer + 0x1A) != 0xB)) {
            return (s16) (-0x4000 - Arctanf(target->segment.trans.z_position - obj->segment.trans.z_position,
                                            target->segment.trans.x_position - obj->segment.trans.x_position));
        }
    }
    return arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/SmartFacer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void smartPlayerSeen(s16 arg0, s16 arg1) {
    D_overlay_155_09B04F64 = arg0;
    D_overlay_155_09B04F66 = arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o155/overlay_155/smartPlayerSeen.s")
#endif
