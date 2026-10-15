#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern void *PatrolNodes;
extern s32 MaxPatrolNodes;
extern u8 squadsBehaviour;
extern u8 *BaddyDataArray;
extern u8 *D_overlay_154_09A01A24;   /* squaddie state (obj->0x68) */
extern u8 *D_overlay_154_09A01A28;   /* baddy data entry, NULL when unset */
extern u8 *D_overlay_154_09A01A2C;   /* closest player object */
extern f32 D_overlay_154_09A01860;
extern f32 D_overlay_154_09A01864;
extern f32 D_overlay_154_09A01868;
extern f32 D_overlay_154_09A0186C;
extern u8 D_overlay_154_09A01890[];  /* 24 x 0x10 path queue entries */
extern u8 *D_overlay_154_09A01A10;   /* queue write cursor */
extern f32 D_overlay_154_09A01A14;   /* goal x */
extern f32 D_overlay_154_09A01A18;   /* goal z */
extern u8 D_overlay_154_09A01A1C;    /* goal node index */
extern s32 D_overlay_154_09A01A20;   /* best path cost bound, -1 when unset */

void **squadsGetSquadronList(s32 *);
u8 *squadsGetClosestPlayer(void);
void RemoveSquaddie(void *);
s32 TryToSetMission(s32, s32, u8, u8, u8);
s32 BaddyTypeToIndex(u16, void *);
f32 GetRange(f32, f32, f32, f32, f32, f32);
f32 GetRangeSquared(f32, f32, f32, f32, f32, f32);
f32 GetRange2D(f32, f32, void *, void *, f32, f32);

void SetBlockedNodes(void);
s32 GetClosestPatrolNode(f32, f32, f32, s32);
s32 GetFurthestPatrolNode(f32, f32, f32, s32);
u8 *func_overlay_154_09A00410_1FE4A08(void);
s32 func_overlay_154_09A004B0_1FE4AA8(u8 *);
s32 func_overlay_154_09A00720_1FE4D18(void);
void func_overlay_154_09A00810_1FE4E08(u8);
s32 func_overlay_154_09A00920_1FE4F18(s32, s32);
s32 FallBackToSniperPoint(s32);
u8 func_overlay_154_09A00D68_1FE5360(s32, s32);
s32 GetNextNodeNumber(u8, s32, s32);
void PerformNodeCommand(s16 *, u8 *);
s32 EnsureValidNode(void);
s32 PatrolPathsInit(void *, s32);
void CopyStaticsToPatrolNodes(void *);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SetBlockedNodes(void) {
    s32 count;
    void **list;
    s32 i;

    list = squadsGetSquadronList(&count);
    for (i = 0; i < MaxPatrolNodes; i++) {
        ((u8 *)PatrolNodes + i * 0x34)[0x2F] = 0;
    }
    for (i = count - 1; i != 0; i--) {
        u8 *obj = (u8 *)list[i];
        u8 *st = *(u8 **)(obj + 0x68);
        u8 type = st[0x32];

        if ((s32)st[0x30] < 6 && (type == 2 || type == 0xC)) {
            u16 packed = *(u16 *)(st + 0x3C);
            u8 a = packed & 0xFF;
            u8 b = (packed >> 8) & 0xFF;

            if (a != 0) {
                ((u8 *)PatrolNodes + a * 0x34)[0x2F] = st[0x64];
            }
            if (b != 0) {
                ((u8 *)PatrolNodes + b * 0x34)[0x2F] = st[0x64];
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/SetBlockedNodes.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 GetClosestPatrolNode(f32 x, f32 y, f32 z, s32 group) {
    f32 bestDist = D_overlay_154_09A01860;
    s32 best = 0;
    s32 i;

    for (i = 1; i < MaxPatrolNodes - 1; i++) {
        u8 *node = (u8 *)PatrolNodes + i * 0x34;

        if (group == 0 || group == node[0x30]) {
            f32 d = GetRangeSquared(x, y, z, *(f32 *)(node + 0x0), *(f32 *)(node + 0x4),
                                    *(f32 *)(node + 0x8));
            if (d < bestDist) {
                bestDist = d;
                best = i;
            }
        }
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/GetClosestPatrolNode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 GetFurthestPatrolNode(f32 x, f32 y, f32 z, s32 group) {
    f32 bestDist = 0.0f;
    s32 best = 0;
    s32 i;

    for (i = 1; i < MaxPatrolNodes - 1; i++) {
        u8 *node = (u8 *)PatrolNodes + i * 0x34;

        if (group == 0 || group == node[0x30]) {
            f32 d = GetRangeSquared(x, y, z, *(f32 *)(node + 0x0), *(f32 *)(node + 0x4),
                                    *(f32 *)(node + 0x8));
            if (bestDist < d) {
                bestDist = d;
                best = i;
            }
        }
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/GetFurthestPatrolNode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *func_overlay_154_09A00410_1FE4A08(void) {
    u8 *best = NULL;
    f32 bestCost = D_overlay_154_09A01864;
    u8 *e = D_overlay_154_09A01890;
    u8 *end = D_overlay_154_09A01890 + 0x180;

    while (e != end && e[0xF] != 0) {
        if (e[0xF] == 1 && *(u16 *)(e + 0x4) < (u32)D_overlay_154_09A01A20 && e[0xE] < 7) {
            f32 c = *(f32 *)(e + 0x0);
            if (c < bestCost) {
                bestCost = c;
                best = e;
            }
        }
        e += 0x10;
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/func_overlay_154_09A00410_1FE4A08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_154_09A004B0_1FE4AA8(u8 *arg0) {
    u8 *node;
    s32 k;

    arg0[0xF] = 2;
    node = (u8 *)PatrolNodes + arg0[6 + arg0[0xE]] * 0x34;

    for (k = 0; k < 6 && node[0x1D + k] != 0; k++) {
        u8 next = node[0x1D + k];
        u8 *cand = (u8 *)PatrolNodes + next * 0x34;
        u16 newCost;
        u8 *queueLast = D_overlay_154_09A01890 + 0x170;
        u8 *slot;
        s32 tries;
        s32 n;

        if (cand[0x2F] != 0 && D_overlay_154_09A01A24[0x64] != cand[0x2F]) {
            continue;
        }

        newCost = (u16)(node[0x29 + k] + *(u16 *)(arg0 + 4));
        if (newCost >= *(u16 *)(cand + 0x14)) {
            continue;
        }
        *(u16 *)(cand + 0x14) = newCost;

        /* find a free (or recyclable) queue slot, ring-buffer style */
        slot = D_overlay_154_09A01A10 + 0x10;
        tries = 0;
        for (;;) {
            D_overlay_154_09A01A10 = slot;
            if (D_overlay_154_09A01A10 > queueLast) {
                D_overlay_154_09A01A10 = D_overlay_154_09A01890;
            }
            tries++;
            if (tries >= 0x18) {
                return 1;
            }
            if (D_overlay_154_09A01A10[0xF] == 0 || D_overlay_154_09A01A10[0xF] == 3) {
                break;
            }
            slot = D_overlay_154_09A01A10 + 0x10;
        }

        /* copy parent path, append the neighbour */
        for (n = 0; n <= arg0[0xE]; n++) {
            D_overlay_154_09A01A10[6 + n] = arg0[6 + n];
        }
        D_overlay_154_09A01A10[6 + arg0[0xE] + 1] = next;
        *(u16 *)(D_overlay_154_09A01A10 + 0x4) = newCost;
        D_overlay_154_09A01A10[0xE] = arg0[0xE] + 1;
        D_overlay_154_09A01A10[0xF] = 1;
        *(f32 *)(D_overlay_154_09A01A10 + 0x0) =
            GetRange2D(*(f32 *)(cand + 0x0), *(f32 *)(cand + 0x8), cand, node + k,
                       D_overlay_154_09A01A14, D_overlay_154_09A01A18);

        if (D_overlay_154_09A01A1C == D_overlay_154_09A01A10[6 + D_overlay_154_09A01A10[0xE]]) {
            D_overlay_154_09A01A20 = *(u16 *)(D_overlay_154_09A01A10 + 0x4);
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/func_overlay_154_09A004B0_1FE4AA8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_154_09A00720_1FE4D18(void) {
    u8 *e = D_overlay_154_09A01890;
    u8 *best = NULL;
    f32 bestCost = D_overlay_154_09A01868;
    u8 *end = D_overlay_154_09A01890 + 0x180;
    s32 k;

    for (k = 0; k < 23; k++, e += 0x10) {
        if (D_overlay_154_09A01A1C == e[6 + e[0xE]] && e[0xF] != 3) {
            return (e[7] | 0x100) & 0xFFFF;
        }
    }

    e = D_overlay_154_09A01890;
    while (e != end && e[0xF] != 0) {
        if (e[0xF] == 2) {
            f32 c = *(f32 *)(e + 0x0);
            if (c < bestCost) {
                bestCost = c;
                best = e;
            }
        }
        e += 0x10;
    }

    if (best == NULL) {
        return 0;
    }
    if (best[7] != 0) {
        return best[7];
    }
    return best[6];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/func_overlay_154_09A00720_1FE4D18.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_154_09A00810_1FE4E08(u8 arg0) {
    f32 *q = (f32 *)D_overlay_154_09A01890;
    u8 *node;
    u8 *last;
    s32 i;

    for (i = 0; i < 0x5F; i++) {
        q[i] = 0.0f;
    }
    D_overlay_154_09A01A10 = D_overlay_154_09A01890;

    for (i = 0; i < MaxPatrolNodes - 1; i++) {
        *(u16 *)((u8 *)PatrolNodes + i * 0x34 + 0x14) = 0xFFFF;
    }
    last = (u8 *)PatrolNodes + ((MaxPatrolNodes > 0) ? MaxPatrolNodes - 1 : 0) * 0x34;

    D_overlay_154_09A01A20 = -1;
    node = (u8 *)PatrolNodes + arg0 * 0x34;
    *(u16 *)(node + 0x14) = 0;

    D_overlay_154_09A01A10[6] = arg0;
    D_overlay_154_09A01A10[0xF] = 1;
    *(f32 *)(D_overlay_154_09A01A10 + 0x0) =
        GetRange2D(*(f32 *)(node + 0x0), *(f32 *)(node + 0x8), last, PatrolNodes,
                   D_overlay_154_09A01A14, D_overlay_154_09A01A18);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/func_overlay_154_09A00810_1FE4E08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_154_09A00920_1FE4F18(s32 arg0, s32 arg1) {
    u8 from = arg0 & 0xFF;
    u8 to = arg1 & 0xFF;
    u8 *goal;
    u8 *entry;
    s32 status;

    if (to == from) {
        return from;
    }

    goal = (u8 *)PatrolNodes + to * 0x34;
    D_overlay_154_09A01A14 = *(f32 *)(goal + 0x0);
    D_overlay_154_09A01A18 = *(f32 *)(goal + 0x8);
    D_overlay_154_09A01A1C = to;

    func_overlay_154_09A00810_1FE4E08(from);
    status = func_overlay_154_09A004B0_1FE4AA8(D_overlay_154_09A01A10);
    while (status != 1) {
        entry = func_overlay_154_09A00410_1FE4A08();
        if (entry == NULL) {
            break;
        }
        status = func_overlay_154_09A004B0_1FE4AA8(entry);
    }
    return func_overlay_154_09A00720_1FE4D18() & 0xFFFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/func_overlay_154_09A00920_1FE4F18.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 FallBackToSniperPoint(s32 arg0) {
    u8 *st = D_overlay_154_09A01A24;
    u8 *obj = *(u8 **)(st + 0x58);
    u8 *player = D_overlay_154_09A01A2C;
    u8 from = arg0 & 0xFF;
    u16 cand[3];
    f32 candDist[3];
    s32 i, j, k;

    for (j = 0; j < 3; j++) {
        cand[j] = 0;
        candDist[j] = D_overlay_154_09A0186C;
    }

    for (i = MaxPatrolNodes - 1; i >= 0; i--) {
        u8 *node = (u8 *)PatrolNodes + i * 0x34;

        if (st[0x74] != node[0x16] && node[0x16] != 0 && (*(u16 *)(node + 0x14) & 2)) {
            if (GetRange(*(f32 *)(player + 0xC), *(f32 *)(player + 0x10), *(f32 *)(player + 0x14),
                         *(f32 *)(node + 0x0), *(f32 *)(node + 0x4), *(f32 *)(node + 0x8)) > 700.0f) {
                f32 dObj = GetRange(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14),
                                    *(f32 *)(node + 0x0), *(f32 *)(node + 0x4), *(f32 *)(node + 0x8));
                s32 worst = 0;

                for (j = 1; j < 3; j++) {
                    if (candDist[j] > candDist[worst]) {
                        worst = j;
                    }
                }
                if (dObj < candDist[worst]) {
                    candDist[worst] = dObj;
                    cand[worst] = (u16)i;
                }
            }
        }
    }

    /* try the kept candidates nearest-first */
    for (k = 0; k < 3; k++) {
        s32 bestSlot = -1;
        f32 bestD = 0.0f;

        for (j = 0; j < 3; j++) {
            if (cand[j] != 0 && (bestSlot == -1 || candDist[j] < bestD)) {
                bestSlot = j;
                bestD = candDist[j];
            }
        }
        if (bestSlot == -1) {
            break;
        }
        {
            s32 r = func_overlay_154_09A00920_1FE4F18(from, cand[bestSlot]);
            if (r & 0x100) {
                return r & 0xFF;
            }
        }
        cand[bestSlot] = 0;
    }
    return func_overlay_154_09A00920_1FE4F18(from, 0) & 0xFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/FallBackToSniperPoint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_overlay_154_09A00D68_1FE5360(s32 arg0, s32 arg1) {
    u8 node = arg0 & 0xFF;
    u8 *cur;

    if ((arg1 & 0xFF) == node) {
        return 0xFF;
    }
    if (node == 0) {
        return 0xFE;
    }
    cur = (u8 *)PatrolNodes + node * 0x34;
    if ((*(u16 *)(cur + 0x14) & 4) && !(*(u16 *)(D_overlay_154_09A01A28 + 0x24) & 0x200)) {
        return 0xFD;
    }
    return cur[0x2F];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/func_overlay_154_09A00D68_1FE5360.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 GetNextNodeNumber(u8 mode, s32 node, s32 avoid) {
    u8 *st = D_overlay_154_09A01A24;
    u8 *player = D_overlay_154_09A01A2C;
    u8 *cur;
    u8 group = 0;
    u8 target;
    s32 weightSum = 0;
    s32 countOk = 0;
    s32 blocked = 0;
    s32 roll;
    s32 acc;
    s32 k;

    if (player == NULL) {
        return 0;
    }
    *(u16 *)(st + 0x28) &= 0xFBFF;

    cur = (u8 *)PatrolNodes + node * 0x34;
    if (node != 0) {
        group = cur[0x30];
    }

    if (st[0x32] == 0x13) {
        target = func_overlay_154_09A00920_1FE4F18(
                     node, GetFurthestPatrolNode(*(f32 *)(player + 0xC), *(f32 *)(player + 0x10),
                                                 *(f32 *)(player + 0x14), group)) & 0xFF;
        if (node == target) {
            *(u16 *)(st + 0x28) |= 0x400;
        }
        return target;
    }

    if (mode == 3) {
        target = func_overlay_154_09A00920_1FE4F18(
                     node, GetClosestPatrolNode(*(f32 *)(player + 0xC), *(f32 *)(player + 0x10),
                                                *(f32 *)(player + 0x14), group)) & 0xFF;
        if (node == target) {
            *(u16 *)(st + 0x28) |= 0x400;
        }
        return target;
    }

    /* first pass: count usable neighbours and their total weight */
    for (k = 5; k != 0; k--) {
        u8 v = func_overlay_154_09A00D68_1FE5360(cur[0x1D + k], avoid);
        if (v == 0) {
            countOk++;
            weightSum += cur[0x23 + k] & 0x1F;
        } else if (v >= 2) {
            blocked = 1;
        }
    }

    if (countOk == 0) {
        if (blocked) {
            return node & 0xFF;
        }
        if (avoid != 0) {
            return avoid & 0xFF;
        }
        return node & 0xFF;
    }

    /* second pass: weighted pick */
    roll = mathRnd(1, weightSum) & 0xFF;
    acc = 0;
    for (k = 5; k != 0; k--) {
        u8 nb = cur[0x1D + k];

        if (func_overlay_154_09A00D68_1FE5360(nb, avoid) == 0) {
            u8 flags = cur[0x23 + k];

            acc += flags & 0x1F;
            if (acc >= roll) {
                if (flags & 0x20) {
                    *(u16 *)(st + 0x28) |= 0x20;
                } else {
                    *(u16 *)(st + 0x28) &= 0xFFDF;
                }
                return nb;
            }
        }
    }
    return avoid & 0xFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/GetNextNodeNumber.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void PerformNodeCommand(s16 *arg0, u8 *node) {
    u8 *st = D_overlay_154_09A01A24;
    u8 *cur = *(u8 **)(st + 0x58);
    u8 *sq = *(u8 **)(cur + 0x68);

    switch (node[0x18]) {
    case 2:
        squadsBehaviour = node[0x19];
        st[0x07] = node[0x19];
        st[0x04] = node[0x19];
        *(s16 *)(st + 0x3C) = 0;
        *(s16 *)(st + 0x3E) = 0;
        break;
    case 3:
    case 9:
        TryToSetMission(2, 0x13, node[0x19], node[0x1A], node[0x1B]);
        break;
    case 4:
        if (TryToSetMission(2, 2, node[0x19], node[0x1A], node[0x1B]) != 0) {
            sq[0x4A] = node[0x1C];
        }
        break;
    case 7: {
        s32 remaining = st[0x00] - 1;
        u8 *next;

        if (st[0x00] != 0) {
            for (;;) {
                next = *(u8 **)(sq + 0x28);
                RemoveSquaddie(cur);
                cur = next;
                if (next == NULL) {
                    break;
                }
                sq = *(u8 **)(next + 0x68);
                remaining--;
                if (remaining == 0) {
                    break;
                }
            }
        }
        break;
    }
    case 8:
        st[0x33] = 0x22;
        *arg0 = (s16)(node[0x1A] << 8);
        *(s16 *)(st + 0x3E) = 0;
        break;
    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/PerformNodeCommand.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 EnsureValidNode(void) {
    u8 *st = D_overlay_154_09A01A24;
    u8 *cur;

    if ((*(s16 *)(st + 0x3C) & 0xFF) != 0) {
        return 1;
    }

    *(s16 *)(st + 0x3C) = (s16)GetClosestPatrolNode(*(f32 *)(st + 0x48), *(f32 *)(st + 0x4C),
                                                    *(f32 *)(st + 0x50), 0);
    cur = (u8 *)PatrolNodes + (*(s16 *)(st + 0x3C) & 0xFF) * 0x34;
    *(s16 *)(st + 0x40) = (s16)*(f32 *)(cur + 0x0);
    *(s16 *)(st + 0x42) = (s16)*(f32 *)(cur + 0x4);
    *(s16 *)(st + 0x44) = (s16)*(f32 *)(cur + 0x8);

    if (*(s16 *)(st + 0x3C) == 0) {
        squadsBehaviour = 3;
        return 0;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/EnsureValidNode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 PatrolPathsInit(void *arg0, s32 arg1) {
    u8 *rec;
    u8 *base;
    s32 total;
    s32 i, j, k;
    s32 gid;
    s32 changed;

    MaxPatrolNodes = 1;
    total = 0;
    rec = (u8 *)arg0;
    if (arg1 > 0) {
        do {
            if (*(u16 *)rec == 0x61) {
                MaxPatrolNodes += 1;
            }
            total += rec[2];
            rec += rec[2];
        } while (total < arg1);
    }

    if (MaxPatrolNodes >= 2) {
        PatrolNodes = mmAlloc(MaxPatrolNodes * 0x34, 0xFFFF00FFU);
    } else {
        MaxPatrolNodes = 0;
        PatrolNodes = NULL;
    }
    if (MaxPatrolNodes == 0) {
        return 0;
    }
    base = (u8 *)PatrolNodes;

    /* fill each node record, then gather its neighbour links */
    total = 0;
    rec = (u8 *)arg0;
    if (arg1 > 0) {
        do {
            if (*(u16 *)rec == 0x61) {
                u8 *node = base + rec[0xF] * 0x34;
                s32 t3 = 0;
                u8 *lk;
                s32 ltot = 0;

                *(f32 *)(node + 0x0) = (f32)*(s16 *)(rec + 4);
                *(f32 *)(node + 0x4) = (f32)*(s16 *)(rec + 6);
                *(f32 *)(node + 0x8) = (f32)*(s16 *)(rec + 8);
                node[0x16] = rec[0xF];
                node[0x17] = (u8)((rec[0x15] << 6) | (node[0x17] & 0x3F));
                node[0x17] = (u8)((rec[0x10] & 0x3F) | (node[0x17] & 0xC0));
                node[0x18] = rec[0xA];
                node[0x19] = rec[0xB];
                node[0x1A] = rec[0xC];
                node[0x1B] = rec[0xD];
                node[0x1C] = rec[0xE];
                *(u16 *)(node + 0x10) = 0;
                node[0x30] = 0;
                node[0x31] = rec[0x14];
                node[0x32] = rec[0x11];
                node[0x33] = rec[0x12];

                lk = (u8 *)arg0;
                do {
                    if (*(u16 *)lk == 0x60 && (node[0x16] == lk[0xA] || node[0x16] == lk[0xB])) {
                        u8 t1;

                        if (node[0x16] == lk[0xA]) {
                            t1 = (lk[0xF] & 0x40) ? lk[0xB] : 0xFF;
                        } else {
                            t1 = 0xFF;
                            if (lk[0xF] & 0x80) {
                                t1 = lk[0xA];
                            }
                        }
                        if (t1 != 0xFF && t3 < 6) {
                            node[0x1D + t3] = t1;
                            node[0x23 + t3] = (lk[0xC] & 0x1F) | (lk[0xF] & 0xE0);
                            node[0x29 + t3] = lk[0xD];
                            t3++;
                        }
                    }
                    ltot += lk[2];
                    lk += lk[2];
                } while (ltot < arg1);
                for (; t3 < 6; t3++) {
                    node[0x1D + t3] = 0;
                    node[0x23 + t3] = 0;
                    node[0x29 + t3] = 0;
                }
            }
            total += rec[2];
            rec += rec[2];
        } while (total < arg1);
    }

    /* label connected groups of nodes */
    gid = 1;
    for (i = 1; i < MaxPatrolNodes - 1; i++) {
        if (base[i * 0x34 + 0x30] != 0) {
            continue;
        }
        base[i * 0x34 + 0x30] = (u8)gid;
        do {
            changed = 0;
            for (j = 1; j < MaxPatrolNodes - 1; j++) {
                u8 *cn = base + j * 0x34;

                if (cn[0x30] == gid) {
                    for (k = 0; k < 6 && cn[0x1D + k] != 0; k++) {
                        u8 *nn = base + cn[0x1D + k] * 0x34;

                        if (nn[0x30] == 0) {
                            nn[0x30] = (u8)gid;
                            changed = 1;
                        }
                    }
                }
            }
        } while (changed);
        gid++;
    }
    return MaxPatrolNodes;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/PatrolPathsInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CopyStaticsToPatrolNodes(void *arg0) {
    u8 *st = *(u8 **)((u8 *)arg0 + 0x68);
    s32 idx;

    D_overlay_154_09A01A24 = st;
    idx = BaddyTypeToIndex(*(u16 *)(st + 0x2C), arg0);
    D_overlay_154_09A01A2C = squadsGetClosestPlayer();

    if (idx != -1) {
        D_overlay_154_09A01A28 = BaddyDataArray + (idx << 7);
        return;
    }
    D_overlay_154_09A01A28 = NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o154/overlay_154/CopyStaticsToPatrolNodes.s")
#endif
