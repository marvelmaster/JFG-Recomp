#include "common.h"


/* decomp: externs */
#ifdef NON_MATCHING
void splinecamFree(void);
f32 splinePos(f32 arg0, f32 arg1, s32 arg2, s32 arg3, f32 arg4);
s32 splinecamSplineHead(s32 arg0, s32 arg1);
extern s32 D_overlay_11_00B01C70[8][0x1F];
extern f32 D_overlay_11_00B01C60;
extern f32 D_overlay_11_00B01C64;
Object **objGetObjList(s32 *arg0, s32 *arg1);
void splinecamPlayerPos(void *arg0, s32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5);
s32 func_overlay_11_00B01BD0_1F09128(s32 arg0, s32 *arg1, s32 arg2, Object **arg3, void **arg4);
void *func_overlay_11_00B0080C_1F07D64(void *arg0, s32 arg1);
void *func_overlay_11_00B00920_1F07E78(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5);
void func_overlay_11_00B00A84_1F07FDC(void **arg0, s32 arg1, f32 *arg2, f32 arg3);
void func_overlay_11_00B00C34_1F0818C(void *arg0, f32 arg1, f32 arg2, f32 arg3);
void lobbycamGetFocalPoint(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splinecamSetup(void) {
    splinecamFree();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamSetup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splinecamFree(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 0x1F; j++) {
            D_overlay_11_00B01C70[i][j] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 splinecamSplineHead(s32 arg0, s32 arg1) {
    if ((arg0 < 0) || (arg0 >= 8)) {
        return 0;
    }
    if ((arg1 < 0) || (arg1 >= 0x1F)) {
        return 0;
    }
    return D_overlay_11_00B01C70[arg0][arg1];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamSplineHead.s")
#endif

/*
 * Spline node layout (as used here): id byte at +0x2C, +0x38, +0x44 with
 * 0xC-byte records; per record: +0 id, +1 flag (0x2D), +2 flag (0x2E),
 * +4 fwd link, +8 bwd link. Stage-1 links are node ids, stage-2 are pointers.
 */
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splinecamMakeSpline(s32 arg0) {
    s32 startIdx;
    s32 count;
    s32 idx;
    void *node;
    Object **objList;
    void **lut;
    s32 *row;
    s32 maxId;
    s32 i;
    s32 k;
    s32 r;
    u8 *rc;
    void *target;
    u8 *src;

    objList = objGetObjList(&startIdx, &count);
    lut = (void **)mmAlloc(0x400, 0x7F7F7FFFU);
    for (i = 0; i < 0x40; i++) {
        s32 *e = (s32 *)lut + i * 4;

        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
    }

    maxId = -1;
    idx = startIdx;
    while (func_overlay_11_00B01BD0_1F09128(arg0, &idx, count, objList, &node) != 0) {
        u8 nodeId = *((u8 *)node + 1);

        if ((nodeId != 0xFF) && (lut[nodeId] == NULL)) {
            src = *(u8 **)((u8 *)objList[idx - 1] + 0x3C);
            *(s32 *)((u8 *)node + 0x30) = src[0x10];
            *(s32 *)((u8 *)node + 0x34) = src[0x11];
            *(s32 *)((u8 *)node + 0x3C) = src[0x13];
            *(s32 *)((u8 *)node + 0x40) = src[0x14];
            *(s32 *)((u8 *)node + 0x48) = src[0x16];
            *(s32 *)((u8 *)node + 0x4C) = src[0x17];
            lut[nodeId] = node;
            if (maxId < (s32)nodeId) {
                maxId = nodeId;
            }
        } else {
            *((u8 *)node + 0x2C) = 0xFF;
            *((u8 *)node + 0x38) = 0xFF;
            *((u8 *)node + 0x44) = 0xFF;
        }
    }

    row = D_overlay_11_00B01C70[arg0];
    for (k = 0; k < 0x1F; k++) {
        row[k] = 0;
    }

    if (maxId >= 0) {
        for (k = 0; k <= maxId; k++) {
            node = lut[k];
            if (node == NULL) {
                continue;
            }
            for (r = 0; r < 3; r++) {
                rc = (u8 *)node + 0x2C + r * 0xC;
                if (rc[0] != 0xFF) {
                    target = lut[*(s32 *)(rc + 4)];
                    *(void **)(rc + 4) = target;
                    if ((target == NULL)
                        || ((((u8 *)target)[0x2C] != rc[0]) && (((u8 *)target)[0x38] != rc[0])
                            && (((u8 *)target)[0x44] != rc[0]))) {
                        *(s32 *)(rc + 4) = (s32)node;
                    }

                    target = lut[*(s32 *)(rc + 8)];
                    *(void **)(rc + 8) = target;
                    if ((target == NULL)
                        || ((((u8 *)target)[0x2C] != rc[0]) && (((u8 *)target)[0x38] != rc[0])
                            && (((u8 *)target)[0x44] != rc[0]))) {
                        *(s32 *)(rc + 8) = (s32)node;
                    }

                    if (row[rc[0]] == 0) {
                        row[rc[0]] = (s32)node;
                    }
                    if (rc[1] != 0) {
                        s32 fwd = *(s32 *)(rc + 4);

                        if (fwd != 0) {
                            row[rc[0]] = fwd;
                        }
                    }
                }
            }
        }
    }

    mmFree(lut);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamMakeSpline.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 splinecamGetNearestNode(f32 arg1, f32 arg2, f32 arg3, void **arg4, f32 *arg5) {
    s32 start;
    s32 end;
    s32 i;
    s32 fp;
    s32 t;
    Object **list;
    u8 *best = NULL;
    f32 bestDist = 0.0f;
    u8 bestId = 0xFF;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    if (splinecamSplineHead(0, 0) == 0) {
        *arg4 = NULL;
        *arg5 = 0.0f;
        return bestId;
    }

    list = objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        Object *obj = list[i];

        if (*(s16 *)((u8 *)obj + 0x48) == 0x12) {
            u8 *cand = *(u8 **)((u8 *)obj + 0x68);

            dx = arg1 - *(f32 *)(cand + 0x08);
            dy = arg2 - *(f32 *)(cand + 0x0C);
            dz = arg3 - *(f32 *)(cand + 0x10);
            d = (dx * dx) + (dy * dy) + (dz * dz);
            if ((best == NULL) || (d < bestDist)) {
                best = cand;
                bestDist = d;
            }
        }
    }

    bestDist = 0.0f;
    *arg5 = -1.0f;
    for (fp = 0; fp != 6; fp++) {
        u8 *rc = best + 0x2C + (fp >> 1) * 0xC;
        u8 id = rc[0];
        void *s0;
        void *v1;

        if (fp & 1) {
            s0 = *(void **)(rc + 4);
            v1 = best;
        } else {
            s0 = best;
            v1 = *(void **)(rc + 8);
        }

        if ((id != 0xFF) && (s0 != NULL) && (s0 != v1)) {
            for (t = 0; t < 0x10; t++) {
                f32 px;
                f32 py;
                f32 pz;

                splinecamPlayerPos(s0, id, (f32)t / 16.0f, &px, &py, &pz);
                dx = px - arg1;
                dy = py - arg2;
                dz = pz - arg3;
                d = (dx * dx) + (dy * dy) + (dz * dz);
                if ((*arg5 < 0.0f) || (d < bestDist)) {
                    *arg4 = s0;
                    bestDist = d;
                    bestId = id;
                    *arg5 = (f32)t / 16.0f;
                }
            }
        }
    }

    return bestId;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamGetNearestNode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_11_00B007B0_1F07D08(void *arg0, s32 arg1) {
    u8 *n = (u8 *)arg0;

    if (arg1 == n[0x2C]) {
        return *(void **)(n + 0x30);
    }
    if (arg1 == n[0x38]) {
        return *(void **)(n + 0x3C);
    }
    if (arg1 == n[0x44]) {
        return *(void **)(n + 0x48);
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B007B0_1F07D08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_11_00B0080C_1F07D64(void *arg0, s32 arg1) {
    u8 *n = (u8 *)arg0;

    if (arg1 == n[0x2C]) {
        return *(void **)(n + 0x34);
    }
    if (arg1 == n[0x38]) {
        return *(void **)(n + 0x40);
    }
    if (arg1 == n[0x44]) {
        return *(void **)(n + 0x4C);
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B0080C_1F07D64.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_overlay_11_00B00868_1F07DC0(void *arg0, s32 arg1) {
    u8 *n = (u8 *)arg0;

    if (arg1 == n[0x2C]) {
        return n[0x2D];
    }
    if (arg1 == n[0x38]) {
        return n[0x39];
    }
    if (arg1 == n[0x44]) {
        return n[0x45];
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B00868_1F07DC0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_overlay_11_00B008C4_1F07E1C(void *arg0, s32 arg1) {
    u8 *n = (u8 *)arg0;

    if (arg1 == n[0x2C]) {
        return n[0x2E];
    }
    if (arg1 == n[0x38]) {
        return n[0x3A];
    }
    if (arg1 == n[0x44]) {
        return n[0x46];
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B008C4_1F07E1C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Finds the node on the chain (via 0x80C links, max 2 steps) closest to (x, y, z)
 * within its radius (u16 at +2); writes dist / radius to *arg5. */
void *func_overlay_11_00B00920_1F07E78(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5) {
    void *cur = arg0;
    void *best = NULL;
    f32 bestDist = -1.0f;
    f32 radius = 0.0f;
    s32 steps = 0;

    if (arg0 != NULL) {
        do {
            s16 r = *(s16 *)((u8 *)cur + 2);

            if (r != 0) {
                f32 dx = arg2 - *(f32 *)((u8 *)cur + 0x08);
                f32 dy = arg3 - *(f32 *)((u8 *)cur + 0x0C);
                f32 dz = arg4 - *(f32 *)((u8 *)cur + 0x10);
                f32 d = (dx * dx) + (dy * dy) + (dz * dz);

                if ((d < ((f32)r * (f32)r)) && ((best == NULL) || (d < bestDist))) {
                    best = cur;
                    bestDist = d;
                    radius = (f32)r;
                }
            }
            cur = func_overlay_11_00B0080C_1F07D64(cur, arg1);
            steps++;
        } while ((cur != NULL) && (steps != 2));
    }

    if (best != NULL) {
        *arg5 = sqrtf(bestDist) / radius;
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B00920_1F07E78.s")
#endif

/*
 * Search state (0x38 bytes): +0 node A, +4 t A, +8 pos A, +0x14 dist A,
 * +0x18 node B, +0x1C t B, +0x20 pos B, +0x2C dist B, +0x30 step, +0x34 id.
 */
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Advances parameter *arg2 (t) by arg3 along the spline, hopping to the neighbour node on overflow. */
void func_overlay_11_00B00A84_1F07FDC(void **arg0, s32 arg1, f32 *arg2, f32 arg3) {
    void *next;
    void *prev;

    *arg2 += arg3;
    if (*arg2 > 1.0f) {
        next = func_overlay_11_00B0080C_1F07D64(*arg0, arg1);
        if (next != func_overlay_11_00B0080C_1F07D64(next, arg1)) {
            if (func_overlay_11_00B008C4_1F07E1C(next, arg1) == 0) {
                *arg2 -= 1.0f;
                *arg0 = next;
                return;
            }
        }
        *arg2 = 1.0f;
    } else if (*arg2 < 0.0f) {
        prev = func_overlay_11_00B007B0_1F07D08(*arg0, arg1);
        if ((prev == *arg0) || (func_overlay_11_00B00868_1F07DC0(*arg0, arg1) != 0)) {
            *arg2 = 0.0f;
        } else {
            *arg2 += 1.0f;
            *arg0 = prev;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B00A84_1F07FDC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Returns squared distance from (cx, cy, cz) to the spline point (node, id, t); also outputs the point. */
f32 func_overlay_11_00B00BB8_1F08110(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                                     f32 *arg6, f32 *arg7, f32 *arg8) {
    f32 dx;
    f32 dy;
    f32 dz;

    splinecamPlayerPos(arg0, arg1, arg2, arg6, arg7, arg8);
    dx = *arg6 - arg3;
    dy = *arg7 - arg4;
    dz = *arg8 - arg5;
    return (dx * dx) + (dy * dy) + (dz * dz);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B00BB8_1F08110.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Refines the two search points of a search state toward (px, py, pz) by halving steps. */
void func_overlay_11_00B00C34_1F0818C(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 *s = (u8 *)arg0;
    f32 minStep = D_overlay_11_00B01C60;
    void *tryNode;
    f32 tryT;
    f32 tryX;
    f32 tryY;
    f32 tryZ;
    f32 tryDist;

    *(f32 *)(s + 0x14) = func_overlay_11_00B00BB8_1F08110(*(void **)(s + 0x00), *(s32 *)(s + 0x34),
        *(f32 *)(s + 0x04), arg1, arg2, arg3, (f32 *)(s + 0x08), (f32 *)(s + 0x0C), (f32 *)(s + 0x10));
    *(f32 *)(s + 0x2C) = func_overlay_11_00B00BB8_1F08110(*(void **)(s + 0x18), *(s32 *)(s + 0x34),
        *(f32 *)(s + 0x1C), arg1, arg2, arg3, (f32 *)(s + 0x20), (f32 *)(s + 0x24), (f32 *)(s + 0x28));

    if (minStep < *(f32 *)(s + 0x30)) {
        do {
            *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) * 0.5f;
            tryNode = *(void **)(s + 0x00);
            tryT = *(f32 *)(s + 0x04);
            func_overlay_11_00B00A84_1F07FDC(&tryNode, *(s32 *)(s + 0x34), &tryT, *(f32 *)(s + 0x30));
            tryDist = func_overlay_11_00B00BB8_1F08110(tryNode, *(s32 *)(s + 0x34), tryT, arg1, arg2, arg3,
                &tryX, &tryY, &tryZ);

            if (*(f32 *)(s + 0x14) < *(f32 *)(s + 0x2C)) {
                *(void **)(s + 0x18) = tryNode;
                *(f32 *)(s + 0x1C) = tryT;
                *(f32 *)(s + 0x20) = tryX;
                *(f32 *)(s + 0x24) = tryY;
                *(f32 *)(s + 0x2C) = tryDist;
                *(f32 *)(s + 0x28) = tryZ;
            } else {
                *(void **)(s + 0x00) = tryNode;
                *(f32 *)(s + 0x04) = tryT;
                *(f32 *)(s + 0x08) = tryX;
                *(f32 *)(s + 0x0C) = tryY;
                *(f32 *)(s + 0x14) = tryDist;
                *(f32 *)(s + 0x10) = tryZ;
            }
        } while (minStep < *(f32 *)(s + 0x30));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B00C34_1F0818C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Candidate search for a mover: up to 4 candidate search states (0x38 bytes each),
 * sorted by best distance; writes the best to arg0 and the runner-up to arg1. */
void splinecamMovementCheck(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4) {
    u8 *mv = (u8 *)arg0;
    u8 cand[4 * 0x38];
    u8 *cp[4];
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s16 moverId = *(s16 *)(mv + 2);
    u8 *c0 = cand;
    u8 *near;

    *(void **)(c0 + 0x00) = *(void **)(mv + 0x04);
    *(f32 *)(c0 + 0x04) = *(f32 *)(mv + 0x08);
    func_overlay_11_00B00A84_1F07FDC((void **)(c0 + 0x00), moverId, (f32 *)(c0 + 0x04), -0.08f);
    *(void **)(c0 + 0x18) = *(void **)(c0 + 0x00);
    *(f32 *)(c0 + 0x1C) = *(f32 *)(c0 + 0x04);
    func_overlay_11_00B00A84_1F07FDC((void **)(c0 + 0x18), moverId, (f32 *)(c0 + 0x1C), D_overlay_11_00B01C64);
    *(f32 *)(c0 + 0x30) = D_overlay_11_00B01C64;
    *(s32 *)(c0 + 0x34) = moverId;
    func_overlay_11_00B00C34_1F0818C(c0, arg2, arg3, arg4);
    n = 1;

    near = func_overlay_11_00B00920_1F07E78(*(void **)(mv + 0x04), moverId, *(f32 *)(mv + 0x0C),
        *(f32 *)(mv + 0x10), *(f32 *)(mv + 0x14), (f32 *)(mv + 0x1C));
    if (near != NULL) {
        for (k = 0; k < 3; k++) {
            u8 *rc = near + 0x2C + k * 0xC;

            if ((rc[0] != 0xFF) && (rc[0] != moverId)) {
                u8 *c = cand + n * 0x38;

                *(void **)(c + 0x00) = near;
                *(f32 *)(c + 0x04) = 0.0f;
                func_overlay_11_00B00A84_1F07FDC((void **)(c + 0x00), rc[0], (f32 *)(c + 0x04), -0.75f);
                *(void **)(c + 0x18) = near;
                *(f32 *)(c + 0x1C) = 0.0f;
                func_overlay_11_00B00A84_1F07FDC((void **)(c + 0x18), rc[0], (f32 *)(c + 0x1C), 0.75f);
                *(f32 *)(c + 0x30) = 1.5f;
                *(s32 *)(c + 0x34) = rc[0];
                func_overlay_11_00B00C34_1F0818C(c, arg2, arg3, arg4);
                n++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        cp[i] = cand + i * 0x38;
    }
    /* sort ascending by min(dist A, dist B) */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            f32 a = *(f32 *)(cp[j] + 0x14);
            f32 b = *(f32 *)(cp[j] + 0x2C);
            f32 costA;
            f32 costB;
            u8 *tmp;

            costA = (b < a) ? b : a;
            a = *(f32 *)(cp[j + 1] + 0x14);
            b = *(f32 *)(cp[j + 1] + 0x2C);
            costB = (b < a) ? b : a;
            if (costB < costA) {
                tmp = cp[j];
                cp[j] = cp[j + 1];
                cp[j + 1] = tmp;
            }
        }
    }

    *(s16 *)((u8 *)arg1 + 2) = 0xFF;
    if (n > 0) {
        u8 *dst = mv;

        for (i = 0; (i < n) && (i < 2); i++) {
            u8 *c = cp[i];
            u8 *v = c;

            *(s16 *)(dst + 2) = (s16)*(s32 *)(c + 0x34);
            if (*(f32 *)(c + 0x2C) < *(f32 *)(c + 0x14)) {
                v = c + 0x18;
            }
            *(void **)(dst + 0x04) = *(void **)(v + 0x00);
            *(f32 *)(dst + 0x08) = *(f32 *)(v + 0x04);
            *(f32 *)(dst + 0x0C) = *(f32 *)(v + 0x08);
            *(f32 *)(dst + 0x10) = *(f32 *)(v + 0x0C);
            *(f32 *)(dst + 0x14) = *(f32 *)(v + 0x10);
            *(f32 *)(dst + 0x18) = *(f32 *)(v + 0x14);
            dst = (u8 *)arg1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamMovementCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Unwraps four consecutive angles (wrapping at 0x10000) into arg4[0..3]. */
void func_overlay_11_00B01288_1F087E0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4) {
    s32 i;
    s32 j;

    arg4[0] = arg0;
    arg4[1] = arg1;
    arg4[2] = arg2;
    arg4[3] = arg3;
    for (i = 0; i < 3; i++) {
        f32 diff = arg4[i + 1] - arg4[i];

        if (diff >= 32768.0f) {
            for (j = i + 1; j < 4; j++) {
                arg4[j] -= 65536.0f;
            }
        } else if (diff < -32768.0f) {
            for (j = i + 1; j < 4; j++) {
                arg4[j] += 65536.0f;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B01288_1F087E0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Looks up the spline record for arg1 in node arg0 and its neighbour; returns 1 if all links are set. */
s32 func_overlay_11_00B01424_1F0897C(void *arg0, s32 arg1, void **arg2, void **arg3, void **arg4, void **arg5) {
    u8 *n = (u8 *)arg0;
    s32 k;
    s32 ok = 0;

    *arg2 = NULL;
    *arg3 = arg0;
    *arg4 = NULL;
    *arg5 = NULL;
    for (k = 0; k < 3; k++) {
        u8 *rc = n + 0x2C + k * 0xC;

        if (arg1 == rc[0]) {
            *arg2 = *(void **)(rc + 4);
            *arg4 = *(void **)(rc + 8);
        }
    }
    if (*arg4 != NULL) {
        for (k = 0; k < 3; k++) {
            u8 *rc = (u8 *)*arg4 + 0x2C + k * 0xC;

            if (arg1 == rc[0]) {
                *arg5 = *(void **)(rc + 8);
            }
        }
    }
    if ((*arg2 != NULL) && (*arg3 != NULL) && (*arg4 != NULL) && (*arg5 != NULL)) {
        ok = 1;
    }
    return ok;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B01424_1F0897C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splinecamPlayerPos(void *arg0, s32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    void *sp2C;
    void *sp28;
    void *sp24;
    void *sp20;

    if (func_overlay_11_00B01424_1F0897C(arg0, arg1, &sp2C, &sp28, &sp24, &sp20) != 0) {
        *arg3 = splinePos(*(f32 *)((u8 *)sp2C + 0x8), *(f32 *)((u8 *)sp28 + 0x8), *(s32 *)((u8 *)sp24 + 0x8), *(s32 *)((u8 *)sp20 + 0x8), arg2);
        *arg4 = splinePos(*(f32 *)((u8 *)sp2C + 0xC), *(f32 *)((u8 *)sp28 + 0xC), *(s32 *)((u8 *)sp24 + 0xC), *(s32 *)((u8 *)sp20 + 0xC), arg2);
        *arg5 = splinePos(*(f32 *)((u8 *)sp2C + 0x10), *(f32 *)((u8 *)sp28 + 0x10), *(s32 *)((u8 *)sp24 + 0x10), *(s32 *)((u8 *)sp20 + 0x10), arg2);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamPlayerPos.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splinecamCameraPos(void *arg0, void *arg1, void *arg2, f32 *arg3, f32 *arg4, f32 *arg5, s16 *arg6, u16 *arg7, s16 *arg8) {
    void *sp84;
    void *sp80;
    void *sp7C;
    void *sp78;
    f32 sp88[4];
    f32 spC0[2];   /* X per valid entry */
    f32 spB8[2];   /* Y per valid entry */
    f32 spB0[2];   /* Z per valid entry */
    f32 spA8[2];   /* X focal per entry */
    f32 spA0[2];   /* Y focal per entry */
    f32 sp98[2];   /* Z focal per entry */
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spCC;
    f32 spC8;
    f32 f2;
    f32 f20;
    f32 f22;
    f32 fTmp;
    void *s0;
    void *obj4;
    void *v0;
    s32 s5;
    s32 s7;
    s32 fp;
    s32 a1;

    s7 = 0;
    fp = 0;
    for (s5 = 0; s5 < 2; s5++) {
        s0 = (s5 == 0) ? arg0 : arg1;
        a1 = *(s16 *)((u8 *)s0 + 2);
        if (a1 == 0xFF) {
            continue;
        }
        if (func_overlay_11_00B01424_1F0897C(*(void **)((u8 *)s0 + 4), a1, &sp84, &sp80, &sp7C, &sp78) == 0) {
            continue;
        }

        spC0[s7] = splinePos(*(f32 *)((u8 *)sp84 + 0x14), *(f32 *)((u8 *)sp80 + 0x14), *(s32 *)((u8 *)sp7C + 0x14), *(s32 *)((u8 *)sp78 + 0x14), *(f32 *)((u8 *)s0 + 0x8));
        spB8[s7] = splinePos(*(f32 *)((u8 *)sp84 + 0x18), *(f32 *)((u8 *)sp80 + 0x18), *(s32 *)((u8 *)sp7C + 0x18), *(s32 *)((u8 *)sp78 + 0x18), *(f32 *)((u8 *)s0 + 0x8));
        spB0[s7] = splinePos(*(f32 *)((u8 *)sp84 + 0x1C), *(f32 *)((u8 *)sp80 + 0x1C), *(s32 *)((u8 *)sp7C + 0x1C), *(s32 *)((u8 *)sp78 + 0x1C), *(f32 *)((u8 *)s0 + 0x8));

        obj4 = *(void **)((u8 *)s0 + 4);
        f20 = *(f32 *)((u8 *)obj4 + 4);
        v0 = func_overlay_11_00B0080C_1F07D64(obj4, a1);
        if (v0 != NULL) {
            f20 += (*(f32 *)((u8 *)v0 + 4) - f20) * *(f32 *)((u8 *)s0 + 0x8);
        }
        if (f20 > 0.0f) {
            f22 = *(f32 *)((u8 *)s0 + 0x18);
            spE0 = *(f32 *)((u8 *)arg2 + 0x8) - *(f32 *)((u8 *)s0 + 0xC);
            spDC = *(f32 *)((u8 *)arg2 + 0xC) - *(f32 *)((u8 *)s0 + 0x10);
            spD8 = *(f32 *)((u8 *)arg2 + 0x10) - *(f32 *)((u8 *)s0 + 0x14);
            if ((f20 * f20) < f22) {
                f2 = f20 / sqrtf(f22);
                spE0 *= f2;
                spDC *= f2;
                spD8 *= f2;
            }
            spC0[s7] += spE0;
            spB8[s7] += spDC;
            spB0[s7] += spD8;
        }
        s7 += 1;

        if (*(s16 *)((u8 *)arg2 + 0x6) >= 2) {
            func_overlay_11_00B01288_1F087E0(*(f32 *)((u8 *)sp84 + 0x20), *(f32 *)((u8 *)sp80 + 0x20), *(f32 *)((u8 *)sp7C + 0x20), *(f32 *)((u8 *)sp78 + 0x20), sp88);
            spA8[fp] = splinePos(sp88[0], sp88[1], *(s32 *)&sp88[2], *(s32 *)&sp88[3], *(f32 *)((u8 *)s0 + 0x8));
            func_overlay_11_00B01288_1F087E0(*(f32 *)((u8 *)sp84 + 0x24), *(f32 *)((u8 *)sp80 + 0x24), *(f32 *)((u8 *)sp7C + 0x24), *(f32 *)((u8 *)sp78 + 0x24), sp88);
            spA0[fp] = splinePos(sp88[0], sp88[1], *(s32 *)&sp88[2], *(s32 *)&sp88[3], *(f32 *)((u8 *)s0 + 0x8));
            func_overlay_11_00B01288_1F087E0(*(f32 *)((u8 *)sp84 + 0x28), *(f32 *)((u8 *)sp80 + 0x28), *(f32 *)((u8 *)sp7C + 0x28), *(f32 *)((u8 *)sp78 + 0x28), sp88);
            sp98[fp] = splinePos(sp88[0], sp88[1], *(s32 *)&sp88[2], *(s32 *)&sp88[3], *(f32 *)((u8 *)s0 + 0x8));
            fp += 1;
        }
    }

    if (s7 > 0) {
        if (s7 >= 2) {
            spCC = 1.0f - *(f32 *)((u8 *)arg0 + 0x1C);
            fTmp = 1.0f + spCC;
            spC8 = 1.0f / fTmp;
            spC0[0] = ((spC0[1] * spCC) + spC0[0]) * spC8;
            spB8[0] = ((spB8[1] * spCC) + spB8[0]) * spC8;
            spB0[0] = ((spB0[1] * spCC) + spB0[0]) * spC8;
        }
        *arg3 = spC0[0];
        *arg4 = spB8[0];
        *arg5 = spB0[0];
        if (fp > 0) {
            if (fp >= 2) {
                spA8[0] = ((spA8[1] * spCC) + spA8[0]) * spC8;
                spA0[0] = ((spA0[1] * spCC) + spA0[0]) * spC8;
                sp98[0] = ((sp98[1] * spCC) + sp98[0]) * spC8;
            }
            *arg6 = (s16)spA8[0];
            *arg7 = (u16)spA0[0];
            *arg8 = (s16)sp98[0];
            return;
        }
        lobbycamGetFocalPoint(arg2, &spE0, &spDC, &spD8);
        spE0 = *arg3 - spE0;
        spDC = *arg4 - spDC;
        spD8 = *arg5 - spD8;
        f22 = sqrtf((spE0 * spE0) + (spD8 * spD8));
        *arg6 = (s16)(0x8000 - Arctanf(spE0, spD8));
        *arg7 = Arctanf(spDC, f22);
        *arg8 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/splinecamCameraPos.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_11_00B01BD0_1F09128(s32 arg0, s32 *arg1, s32 arg2, Object **arg3, void **arg4) {
    s32 var_a0;
    s32 var_t3;
    Object *var_v1;
    Object *temp_t0;
    Object_Racer *temp_v0;

    var_a0 = *arg1;
    var_v1 = NULL;
    if (var_a0 < arg2) {
        do {
            temp_t0 = arg3[var_a0];
            var_t3 = var_a0 + 1;
            if (temp_t0->behaviorId == 0x12) {
                temp_v0 = temp_t0->racer;
                if (arg0 == temp_v0->pad00[0]) {
                    *arg4 = temp_v0;
                    var_v1 = temp_t0;
                    var_t3 = *arg1 + 1;
                }
            }
            *arg1 = var_t3;
            if (var_v1 != NULL) {
                break;
            }
            var_a0 = var_t3;
        } while (var_t3 < arg2);
    }
    return (s32)var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o11/overlay_11/func_overlay_11_00B01BD0_1F09128.s")
#endif
