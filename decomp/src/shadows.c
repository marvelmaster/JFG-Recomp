#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 D_800A0E80_A1A80[4];
extern s32 D_800A0E90_A1A90[4];
extern s32 D_800A0EA0_A1AA0[4];
extern s32 D_800A0EC8_A1AC8;
extern s32 D_800F5B00_B3E80;
extern s32 D_800F5B04_B3E84;
extern s32 D_800F5B08_B3E88;
extern void *D_800F5B0C_B3E8C;
extern s32 D_800F5B10_B3E90;
extern f32 D_800F5B14_B3E94;
extern f32 D_800A0ED4_A1AD4[];
extern s16 D_800A0ECC_A1ACC[3];
extern s16 D_800A0ED0_A1AD0;
s32 getXZCompareMask(s32, s32, s32, s32, s32);
s32 mathXZInTri(s32, s32, void *, void *, void *);
void matrixTransposeVectorMultiply(void *, s32, f32 *, s32);
s32 shadowBoxPolyOverlap(f32, f32, f32, f32, s32, void *);
void shadowYHeight(void *, void *);
s32 func_8001F288(void *, s32, void *, s32, void *);
void func_8001E684(void *, void *, void *, s32);
void func_8001EBE8(void *, void *);
s32 func_8001F7C8(void *, void *, void *);
void shadowBoundingBox(s32, f32 *, f32 *, f32 *, f32 *, f32 *);
void shadowMakeYs(s32, u8 *, s32 *, u8 *);
s32 trackGetCubeBlockList(s32 *, s32, s32, s32, s16, s16, s16);
extern s32 D_800F35D8_B1958[];
extern u8 D_800F35E8_B1968[];
extern u8 D_800F33D8_B1758[];
extern u8 D_800F45F0_B2970[];
extern s32 D_800F45E8_B2968;
extern f32 D_800F5AF0_B3E70;
extern s32 D_800A0EFC_A1AFC;
extern s32 D_800F33D0_B1750;
extern s32 D_800F5AF8_B3E78;
extern s32 D_800F5AFC_B3E7C;
extern s32 D_800A0EB0_A1AB0;
extern s32 D_800A0EB4_A1AB4;
extern s32 D_800A0EB8_A1AB8;
extern s32 D_800A0EBC_A1ABC;
extern s32 D_800A0EC0_A1AC0;
extern s32 D_800A0EC4_A1AC4;
extern s32 D_800F5AF4_B3E74;
extern s16 D_800F48F0_B2C70[];
extern u8 D_800F52F0_B3670[];
s32 func_80020104(void *, s16 *, void *, f32, f32, f32, f32);
void *hitGetHitModels(s32 *);
f32 Sinf(s16);
f32 Powerf(f32);
f32 camDistance(f32, f32, f32);
s32 cloneBlobCreate(void *, s32, f32);
s32 cloneShadowCreate(void *);
s32 mizarLightUp(void *);
void **objGetObjList(s32 *, s32 *);
void func_8001DF5C(void *, void *, void *);
void func_8001FD20(void *);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shadowInitBuffers(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 strideA;
    s32 strideB;
    s32 strideC;

    D_800F5B0C_B3E8C = (void *) arg0;
    D_800F5B10_B3E90 = arg1;
    D_800F5B00_B3E80 = arg2;
    D_800F5B04_B3E84 = arg3;
    strideA = arg2 * 10;
    D_800F5B08_B3E88 = arg4;
    strideB = arg3 * 16;
    D_800A0E80_A1A80[0] = (s32) mmAlloc(strideA * 4, 0xFFFF00FFU);
    strideC = arg4 * 8;
    D_800A0E90_A1A90[0] = (s32) mmAlloc(strideB * 4, 0xFFFF00FFU);
    D_800A0EA0_A1AA0[0] = (s32) mmAlloc(strideC * 4, 0xFFFF00FFU);
    for (i = 1; i < 4; i++) {
        D_800A0E80_A1A80[i] = D_800A0E80_A1A80[i - 1] + strideA;
        D_800A0E90_A1A90[i] = D_800A0E90_A1A90[i - 1] + strideB;
        D_800A0EA0_A1AA0[i] = D_800A0EA0_A1AA0[i - 1] + strideC;
    }
    D_800A0EC8_A1AC8 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/shadowInitBuffers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shadowFreeBuffers(void) {
    if (D_800A0E80_A1A80[0] != 0) {
        mmFree((void *) D_800A0E80_A1A80[0]);
        D_800A0E80_A1A80[0] = 0;
    }
    if (D_800A0E90_A1A90[0] != 0) {
        mmFree((void *) D_800A0E90_A1A90[0]);
        D_800A0E90_A1A90[0] = 0;
    }
    if (D_800A0EA0_A1AA0[0] != 0) {
        mmFree((void *) D_800A0EA0_A1AA0[0]);
        D_800A0EA0_A1AA0[0] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/shadowFreeBuffers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shadowChangeBuffer(void) {
    D_800A0EC8_A1AC8 ^= 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/shadowChangeBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shadowGetBuffers(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 idx;

    idx = D_800A0EC8_A1AC8;
    if (arg0 & 2) {
        idx += 2;
    }
    *arg1 = D_800A0E80_A1A80[idx];
    *arg2 = D_800A0E90_A1A90[idx];
    *arg3 = D_800A0EA0_A1AA0[idx];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/shadowGetBuffers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Shadow pass over the object list for buffer set idx = (arg0 & 2) | toggle.
// arg0 = caster mask (tested against rec +0xC), arg1 = scale passed as float to
// cloneBlobCreate / cloneShadowCreate. Layouts follow func_8001DF5C in this file:
// rec = obj+0x50 (f32 extent +0, u8 flags +0xC, u8 max +0xD, u8 count +0xF, alt record ptr +0x1C),
// obj+0x40 = model (u16 flags +0x14, s16 hi +0x68, s16 lo +0x6A), obj+0x54 = direction list
// (s16 count +0xE, 0x20 B records from +0x20; f32 x/y/z at +0x10/+0x14/+0x18, u8 weight +0x25).
// Direction entries are 3 x s16: yaw, pitch, weight. The asm sort is an IDO 4x-unrolled
// bubble pass (descending by weight); it is written out below with the same compare order.
void shadowGenerate(s32 arg0, s32 arg1) {
    u8 *obj;
    u8 *rec;
    u8 *alt;
    u8 *model;
    u8 *lvl;
    u8 *dl;
    u8 *sub;
    void **list;
    /* asm: pointer table at sp+0xA4 and entry table at sp+0xB4 share stack space; capacity 8 here */
    s16 *ptrs[8];
    s16 dirs[8][3];
    s16 *tmp;
    s32 idx;
    s32 start;
    s32 total;
    s32 i;
    s32 j;
    s32 k;
    s32 rem;
    s32 n;
    s32 cnt;
    s32 hit;
    s32 blob;
    s32 hiI;
    s32 loI;
    f32 dist;
    f32 hi;
    f32 lo;
    f32 x;
    f32 y;
    f32 z;

    idx = (arg0 & 2) | D_800A0EC8_A1AC8;
    D_800A0EB0_A1AB0 = D_800A0E80_A1A80[idx];
    D_800A0EBC_A1ABC = 0;
    D_800A0EB4_A1AB4 = D_800A0E90_A1A90[idx];
    D_800A0EC0_A1AC0 = 0;
    D_800A0EB8_A1AB8 = D_800A0EA0_A1AA0[idx];
    D_800A0EC4_A1AC4 = 0;
    /* asm: idx is spilled into the slot later used as objGetObjList's total out-param */
    total = idx;
    D_800F5B14_B3E94 = 1.0f - Powerf(0.9f);
    lvl = (u8 *) levelGetLevel();
    D_800A0ECC_A1ACC[0] = *(s16 *) (lvl + 0xD4);
    D_800A0ECC_A1ACC[1] = *(s16 *) (lvl + 0xD6);
    D_800A0ECC_A1ACC[2] = lvl[0xDE];
    list = (void **) objGetObjList(&start, &total);
    for (i = start; i < total; i++) {
        obj = (u8 *) list[i];
        rec = *(u8 **) (obj + 0x50);
        if (rec != NULL) {
            hit = rec[0xC] & arg0;
            if (hit != 0) {
                dist = 0.0f;
                if (hit == 1) {
                    if (camGetMode() == 0) {
                        dist = camDistance(*(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10),
                                           *(f32 *) (obj + 0x14));
                    } else if (*(s16 *) (obj + 0x48) != 1 && *(s16 *) (obj + 0x4A) != 0x278) {
                        dist = 32768.0f;
                    }
                }

                alt = NULL;
                if (rec[0xC] & 0x18) {
                    sub = *(u8 **) (rec + 0x1C);
                    if (sub != NULL) {
                        alt = sub;
                        sub[0xF] = 0;
                    }
                }
                rec[0xF] = 0;

                model = *(u8 **) (obj + 0x40);
                if (*(f32 *) rec > 0.0f && !(*(s16 *) (obj + 0x6) & 0x400) &&
                    !(*(u16 *) (model + 0x14) & 1)) {
                    hiI = *(s16 *) (model + 0x68);
                    hi = (f32) hiI;
                    if (dist < hi) {
                        loI = *(s16 *) (model + 0x6A);
                        if ((f32) loI < dist) {
                            D_800F5AF0_B3E70 = (hi - dist) / (f32) (hiI - loI);
                        } else {
                            D_800F5AF0_B3E70 = 1.0f;
                        }

                        if (rec[0xC] & 4) {
                            blob = 0;
                            if (alt != NULL) {
                                if (alt[0xC] & 8) {
                                    blob = cloneBlobCreate(obj, 0, (f32) arg1);
                                } else if (alt[0xC] & 0x10) {
                                    blob = cloneShadowCreate(obj);
                                }
                            }
                            if (blob != 0) {
                                func_8001DF5C(obj, NULL, alt);
                            } else {
                                func_8001DF5C(obj, NULL, rec);
                            }
                        } else if (alt != NULL && (alt[0xC] & 8)) {
                            if (cloneBlobCreate(obj, 1, (f32) arg1) != 0) {
                                func_8001DF5C(obj, NULL, alt);
                            } else {
                                func_8001DF5C(obj, NULL, rec);
                            }
                        } else {
                            n = 0;
                            if (alt != NULL && (alt[0xC] & 0x10)) {
                                if (mizarLightUp(obj) != 0) {
                                    func_8001DF5C(obj, NULL, alt);
                                } else {
                                    func_8001DF5C(obj, NULL, rec);
                                }
                            } else if (D_800A0ED0_A1AD0 > 0) {
                                n = 1;
                                ptrs[0] = D_800A0ECC_A1ACC;
                            }

                            /* direction list: records with y > 0 get yaw/pitch/weight */
                            dl = *(u8 **) (obj + 0x54);
                            if (dl != NULL) {
                                cnt = *(s16 *) (dl + 0xE);
                                for (j = 1; j < cnt; j++) {
                                    sub = dl + 0x20 * j;
                                    if (*(f32 *) (sub + 0x14) > 0.0f) {
                                        x = *(f32 *) (sub + 0x10);
                                        y = *(f32 *) (sub + 0x14);
                                        z = *(f32 *) (sub + 0x18);
                                        ptrs[n] = dirs[n];
                                        ptrs[n][0] = (s16) Arctanf(-x, -z);
                                        ptrs[n][1] = (s16) Arctanf(y, sqrtf(x * x + z * z));
                                        ptrs[n][2] = (s16) sub[0x25];
                                        n++;
                                    }
                                }
                            }

                            /* sort by weight, descending: bubble passes k = n-1 .. 1 */
                            if (rec[0xD] < n && n > 1) {
                                for (k = n - 1; k > 0; k--) {
                                    rem = k & 3;
                                    for (j = 0; j < rem; j++) {
                                        if (ptrs[j][2] < ptrs[j + 1][2]) {
                                            tmp = ptrs[j];
                                            ptrs[j] = ptrs[j + 1];
                                            ptrs[j + 1] = tmp;
                                        }
                                    }
                                    for (j = rem; j != k; j += 4) {
                                        if (ptrs[j][2] < ptrs[j + 1][2]) {
                                            tmp = ptrs[j];
                                            ptrs[j] = ptrs[j + 1];
                                            ptrs[j + 1] = tmp;
                                        }
                                        if (ptrs[j + 1][2] < ptrs[j + 2][2]) {
                                            tmp = ptrs[j + 1];
                                            ptrs[j + 1] = ptrs[j + 2];
                                            ptrs[j + 2] = tmp;
                                        }
                                        if (ptrs[j + 2][2] < ptrs[j + 3][2]) {
                                            tmp = ptrs[j + 2];
                                            ptrs[j + 2] = ptrs[j + 3];
                                            ptrs[j + 3] = tmp;
                                        }
                                        if (ptrs[j + 3][2] < ptrs[j + 4][2]) {
                                            tmp = ptrs[j + 3];
                                            ptrs[j + 3] = ptrs[j + 4];
                                            ptrs[j + 4] = tmp;
                                        }
                                    }
                                }
                            }

                            if (rec[0xF] < rec[0xD] && n > 0) {
                                j = 0;
                                do {
                                    func_8001DF5C(obj, ptrs[j], rec);
                                    j++;
                                } while (rec[0xF] < rec[0xD] && j < n);
                            }
                        }
                    }
                }
                if (*(u8 **) (obj + 0x54) != NULL) {
                    func_8001FD20(obj);
                }
            }
        }
    }

    sub = (u8 *) D_800A0EB8_A1AB8 + D_800A0EC4_A1AC4 * 8;
    *(s16 *) (sub + 4) = (s16) D_800A0EC0_A1AC0;
    *(s16 *) (sub + 6) = (s16) D_800A0EBC_A1ABC;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/shadowGenerate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Shadow setup for caster arg0 (obj). arg1 = s16 angles (+0 yaw for the rotated footprint,
// +2 for the slope/extent factor), NULL = unrotated square. arg2 = shadow record: f32 extent at
// +0, u8 count at +0xF (entry index), s16 markers at +0x10 + 2n (start) and +0x16 + 2n (end).
// Local block cst (sp74) uses the layout of func_8001E684 / func_8001F7C8: +0 obj, +4 record
// tex ptr, +8 plane ptr, +0xC/+0xE s16 y lo/hi, +0x14 y base (2.0 + fade), +0x18 -32768,
// +0x1C height fade, +0x20 7 * fade, +0x24 144 / extent, +0x28 2 * ext * (ext + ext2),
// +0x2C/+0x30 ext, +0x34 ext2, +0x38..+0x44 box (min/max for shadowBoxPolyOverlap).
// pts = XZ corners of the footprint around obj (+0xC x, +0x14 z).
void func_8001DF5C(void *arg0, void *arg1, void *arg2) {
    u8 *obj;
    u8 *shd;
    u8 *model;
    u8 *rec;
    s16 *ang;
    u8 cst[0x48];
    f32 pts[8];
    /* stack space for the block list (sp DC..16C) */
    s32 blockList[36];
    f32 ext;
    f32 ext2;
    f32 sinA;
    f32 cosA;
    f32 cosB;
    f32 slope;
    f32 aS;
    f32 aC;
    f32 cS;
    f32 cC;
    f32 fade;
    f32 fadeIn;
    f32 fh;
    s32 yInt;
    s32 nBlk;
    s32 i;
    s32 p;
    s32 idx;
    s32 n;
    s32 ok;

    obj = (u8 *) arg0;
    shd = (u8 *) arg2;
    ang = (s16 *) arg1;

    /* start marker of this entry */
    n = shd[0xF];
    *(s16 *) (shd + 0x10 + n * 2) = (s16) D_800A0EC4_A1AC4;

    *(void **) cst = arg0;
    *(void **) (cst + 0x4) = *(void **) (shd + 0x4);
    yInt = (s32) *(f32 *) (obj + 0x10);
    model = *(u8 **) (obj + 0x40);
    *(s16 *) (cst + 0xC) = (s16) (*(s16 *) (model + 0x6C) + yInt);
    *(s16 *) (cst + 0xE) = (s16) (*(s16 *) (model + 0x6E) + yInt);

    /* y base: 2.0 plus obj->0x30 beyond 250 (clamped to 0..1024, scaled 0.01) */
    fade = 2.0f;
    if (*(s16 *) (obj + 0x48) != 1) {
        fadeIn = *(f32 *) (obj + 0x30);
        if (fadeIn < 0.0f) {
            fadeIn = -fadeIn;
        }
        fadeIn = fadeIn - 250.0f;
        if (fadeIn < 0.0f) {
            fadeIn = 0.0f;
        }
        if (fadeIn > 1024.0f) {
            fadeIn = 1024.0f;
        }
        fade = fade + fadeIn * 0.01f;
    }
    *(f32 *) (cst + 0x14) = fade;

    ext = *(f32 *) shd * 10.0f;
    ext2 = 1.0f;
    if (ang != NULL) {
        cosB = Cosf((s32) ang[1]);
        if (cosB > 0.0f) {
            sinA = Sinf(ang[1]);
            if (sinA != 0.0f) {
                slope = cosB / sinA;
                if (slope > 2.0f) {
                    slope = 2.0f;
                }
            } else {
                slope = 2.0f;
            }
            ext2 = ext2 + (0.25f * slope * (f32) shd[0xE]) / ext;
        }
    }
    ext2 = ext2 * ext;
    *(f32 *) (cst + 0x2C) = ext;
    *(f32 *) (cst + 0x30) = ext;
    *(f32 *) (cst + 0x34) = ext2;
    *(f32 *) (cst + 0x28) = 2.0f * ext * (ext + ext2);

    *(f32 *) (cst + 0x18) = -32768.0f;
    /* height fade = |model 0x6C| / 8, scaled by 7 */
    fh = (f32) *(s16 *) (model + 0x6C) * 0.125f;
    if (fh < 0.0f) {
        fh = -fh;
    }
    *(f32 *) (cst + 0x1C) = fh;
    *(f32 *) (cst + 0x20) = 7.0f * fh;
    *(f32 *) (cst + 0x24) = 144.0f / *(f32 *) shd;

    /* footprint corners (x, z) around obj */
    for (p = 0; p < 4; p++) {
        pts[p * 2] = *(f32 *) (obj + 0xC);
        pts[p * 2 + 1] = *(f32 *) (obj + 0x14);
    }
    if (ang != NULL) {
        sinA = Sinf(ang[0]);
        cosA = Cosf((s32) ang[0]);
        aS = ext * sinA;
        aC = ext * cosA;
        cS = ext2 * sinA;
        cC = ext2 * cosA;
        pts[0] += -aC - aS;
        pts[1] += aS - aC;
        pts[2] += aC - aS;
        pts[3] += -aC - aS;
        pts[4] += aC + cS;
        pts[5] += cC - aS;
        pts[6] += -aC + cS;
        pts[7] += cC + aS;
    } else {
        pts[0] += ext;
        pts[1] += ext;
        pts[2] -= ext;
        pts[3] += ext;
        pts[4] -= ext;
        pts[5] -= ext;
        pts[6] += ext;
        pts[7] -= ext;
    }

    shadowBoundingBox(4, pts, (f32 *) (cst + 0x38), (f32 *) (cst + 0x3C), (f32 *) (cst + 0x40),
                      (f32 *) (cst + 0x44));
    nBlk = trackGetCubeBlockList(blockList,
                                 (s16) (s32) *(f32 *) (cst + 0x38),
                                 *(s16 *) (cst + 0xC),
                                 (s16) (s32) *(f32 *) (cst + 0x3C),
                                 (s32) *(f32 *) (cst + 0x40),
                                 *(s16 *) (cst + 0xE),
                                 (s32) *(f32 *) (cst + 0x44));

    D_800F45E8_B2968 = 0;
    D_800F33D0_B1750 = 0;
    for (i = 0; i < 4; i++) {
        D_800F35D8_B1958[i] = 0;
    }
    D_800F5AF8_B3E78 = -1;
    D_800F5AFC_B3E7C = -1;
    D_800F5AF4_B3E74 = 0;
    D_800A0EFC_A1AFC = 0;
    if (*(s16 *) (obj + 0x4A) == 0x3F || *(s16 *) (obj + 0x4A) == 0x40 ||
        *(s16 *) (obj + 0x4A) == 0x41 || *(s16 *) (obj + 0x4A) == 0x42) {
        D_800A0EFC_A1AFC = 1;
    }

    /* per block: clip the matching shadow triangles of that block */
    rec = (u8 *) D_800F5B0C_B3E8C;
    for (i = 0; i < nBlk; i++) {
        idx = blockList[i];
        if (idx >= 0) {
            func_8001E684(cst, pts, *(u8 **) (rec + 0x4) + idx * 0x48,
                          getXZCompareMask((s32) (*(u8 **) (rec + 0x8) + idx * 0xC),
                                           (s32) *(f32 *) (cst + 0x38), (s32) *(f32 *) (cst + 0x3C),
                                           (s32) *(f32 *) (cst + 0x40), (s32) *(f32 *) (cst + 0x44)));
        }
    }

    func_8001EBE8(cst, pts);
    ok = 1;
    if (D_800F45E8_B2968 > 0) {
        shadowMakeYs(D_800F33D0_B1750, D_800F33D8_B1758, D_800F35D8_B1958, D_800F35E8_B1968);
        if (func_8001F7C8(cst, arg1, arg2) == 0) {
            ok = 0;
        }
    }

    /* end marker, and bump the entry count on success */
    n = shd[0xF];
    *(s16 *) (shd + 0x16 + n * 2) = (s16) D_800A0EC4_A1AC4;
    if (ok != 0) {
        shd[0xF] = shd[0xF] + 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/func_8001DF5C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-object shadow pass. arg0 caster: +0x8 receives the current plane pointer, +0xC/+0xE
// s16 y limits (lo/hi), +0x38..+0x44 box for shadowBoxPolyOverlap, +0x1C plane fade height.
// arg2 shadow mesh: +0x0 vertex base (10 B records), +0x4 triangle base (0x10 B), +0xC polys
// (0x10 B: s16 vbase +6, tri start +8, tri end +0x18, flags +0xC), +0x10 per-tri visibility
// masks (u32), +0x18 per-tri plane index (u16 at +0, 8 B records), +0x1C planes (0x10 B,
// f32 B at +4 = normal y), +0x28 poly count. arg1 = clip polygon for func_8001F288.
// Triangles that pass the tests are clipped, and the result is appended to the
// D_800F45F0 entry table (12 B: u8 count, u8 mask, u8 idx[8], s16 material at +0xA).
void func_8001E684(void *arg0, void *arg1, void *arg2, s32 arg3) {
    u8 *caster;
    u8 *shd;
    u8 *poly;
    u8 *polyVerts;
    u8 *tri;
    u8 *vtx;
    u8 *planeBase;
    u8 *ent;
    u8 *b;
    u8 buf[0x80];
    s32 p;
    s32 ra;
    s32 triEnd;
    s32 flags;
    s32 material;
    s32 pidx;
    s32 mask;
    s32 minY;
    s32 maxY;
    s32 y;
    s32 k;
    s32 v;
    s32 i;
    s32 tag;
    s32 nEnt;
    s32 nB;
    s32 bIdx;
    s32 found;
    s32 slot;

    caster = (u8 *) arg0;
    shd = (u8 *) arg2;

    for (p = 0; p < *(s16 *) (shd + 0x28); p++) {
        poly = *(u8 **) (shd + 0xC) + p * 0x10;
        flags = *(s32 *) (poly + 0xC);
        if (D_800A0EFC_A1AFC != 0) {
            if (!(flags & 0x400)) {
                continue;
            }
        } else if (flags & 0x3480) {
            continue;
        }

        polyVerts = *(u8 **) shd + *(s16 *) (poly + 0x6) * 10;
        material = (flags >> 22) & 7;
        triEnd = *(s16 *) (poly + 0x18);
        for (ra = *(s16 *) (poly + 0x8); ra < triEnd; ra++) {
            pidx = *(u16 *) (*(u8 **) (shd + 0x18) + ra * 8);
            planeBase = *(u8 **) (shd + 0x1C) + pidx * 0x10;
            mask = *(s32 *) (*(u8 **) (shd + 0x10) + ra * 4) & arg3;
            if ((mask & 0xFFFF) == 0 || ((u32) mask >> 16) == 0) {
                continue;
            }
            if (!(0.5f < *(f32 *) (planeBase + 0x4))) {
                continue;
            }

            tri = *(u8 **) (shd + 0x4) + ra * 0x10;
            /* y range of the three triangle vertices */
            vtx = polyVerts + tri[1] * 10;
            minY = *(s16 *) (vtx + 0x2);
            maxY = minY;
            for (k = 2; k < 4; k++) {
                y = *(s16 *) (polyVerts + tri[k] * 10 + 0x2);
                if (y < minY) {
                    minY = y;
                } else if (maxY < y) {
                    maxY = y;
                }
            }
            if (*(s16 *) (caster + 0xE) < minY) {
                continue;
            }
            if (maxY < *(s16 *) (caster + 0xC)) {
                continue;
            }

            /* triangle as a clip polygon: x, z and tag -1 per vertex */
            for (k = 0; k < 3; k++) {
                vtx = polyVerts + tri[k + 1] * 10;
                b = buf + k * 0x10;
                *(f32 *) (b + 0x0) = (f32) *(s16 *) (vtx + 0x0);
                *(f32 *) (b + 0x8) = (f32) *(s16 *) (vtx + 0x4);
                *(s16 *) (b + 0xE) = -1;
            }
            if (shadowBoxPolyOverlap(*(f32 *) (caster + 0x38), *(f32 *) (caster + 0x3C),
                                     *(f32 *) (caster + 0x40), *(f32 *) (caster + 0x44), 3, buf) == 0) {
                continue;
            }

            *(u8 **) (caster + 0x8) = planeBase;
            if (*(f32 *) (caster + 0x1C) > 0.0f) {
                shadowYHeight(caster, buf);
            }
            v = func_8001F288(caster, 3, buf, 4, arg1);
            if (v < 3) {
                continue;
            }

            /* append the clipped polygon as an entry */
            nEnt = D_800F45E8_B2968;
            ent = D_800F45F0_B2970 + nEnt * 12;
            ent[1] = 0;
            nB = D_800F33D0_B1750;
            for (i = 0; i < v; i++) {
                tag = *(s16 *) (buf + i * 0x10 + 0xE);
                if (tag >= 0) {
                    /* intersection from the cache table D_800F35E8 */
                    ent[1] = (u8) (ent[1] | (1 << i));
                    ent[2 + i] = (u8) tag;
                } else {
                    /* original vertex: find or add it in table D_800F33D8 */
                    found = -1;
                    nB = D_800F33D0_B1750;
                    for (bIdx = 0; bIdx < nB && found == -1; bIdx++) {
                        if (*(f32 *) (D_800F33D8_B1758 + bIdx * 0x10 + 0x0) == *(f32 *) (buf + i * 0x10 + 0x0) &&
                            *(f32 *) (D_800F33D8_B1758 + bIdx * 0x10 + 0x8) == *(f32 *) (buf + i * 0x10 + 0x8)) {
                            found = bIdx;
                        }
                    }
                    if (found == -1) {
                        slot = nB;
                        if (nB >= 0x20) {
                            D_800F33D0_B1750 = 0x1F;
                            slot = 0x1F;
                        }
                        b = D_800F33D8_B1758 + slot * 0x10;
                        *(f32 *) (b + 0x0) = *(f32 *) (buf + i * 0x10 + 0x0);
                        *(f32 *) (b + 0x8) = *(f32 *) (buf + i * 0x10 + 0x8);
                        *(u8 **) (b + 0xC) = *(u8 **) (caster + 0x8);
                        D_800F33D0_B1750 = slot + 1;
                        ent[2 + i] = (u8) slot;
                    } else {
                        ent[2 + i] = (u8) found;
                    }
                }
            }
            ent[0] = (u8) v;
            *(s16 *) (ent + 0xA) = (s16) material;
            D_800F45E8_B2968 = nEnt + 1;
            if (D_800F5AF8_B3E78 >= 0 && material != D_800F5AF8_B3E78) {
                D_800F5AFC_B3E7C = 0;
            }
            D_800F5AF8_B3E78 = material;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/func_8001E684.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Shadow pass for caster arg0 (clip polygon arg1, passed on to func_8001F288).
// Layouts as in func_8001E684. Hit model: +0x4C -> flags (u16 +0xA, bit 0 = shadow caster),
// +0x5C -> box (f32 minX +0x100, minZ +0x108, maxX +0x10C, maxZ +0x114), cf. src/hit.c.
// Stage 1: up to 15 hit models whose box overlaps the caster's +-20 square around obj (+0xC x,
// +0x14 z) are kept, sorted by the squared offset of the box half-size from obj (insertion sort;
// indices in candIdx, keys in candDist).
// Stage 2: for each kept model other than obj, func_80020104 writes its triangles as 0x14 B
// s16 records (D_800F48F0) and the matching planes (0x10 B, D_800F52F0 from index
// D_800F5AF4, which is advanced by the count). A triangle with plane normal y > 0.5 and a y
// range overlapping the caster is clipped by func_8001F288 and appended to the D_800F45F0
// entry table (vertex tags of -1 are looked up or added in D_800F33D8, 0x10 B each).
void func_8001EBE8(void *arg0, void *arg1) {
    u8 *caster;
    u8 *obj;
    u8 *hitObj;
    u8 *box;
    u8 **hitList;
    u8 *rec;
    u8 *plane;
    u8 *ent;
    u8 *tb;
    u8 buf[0x30];
    s32 candIdx[16];
    f32 candDist[16];
    f32 qMinX;
    f32 qMinZ;
    f32 qMaxX;
    f32 qMaxZ;
    f32 bMinX;
    f32 bMinZ;
    f32 bMaxX;
    f32 bMaxZ;
    f32 dx;
    f32 dz;
    f32 tf;
    s32 ti;
    s32 nHit;
    s32 nCand;
    s32 nTri;
    s32 nEnt;
    s32 nB;
    s32 slot;
    s32 found;
    s32 v;
    s32 tag;
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s32 b;
    s32 lo;
    s32 hi;
    s32 y;

    caster = (u8 *) arg0;
    obj = *(u8 **) caster;
    qMinX = *(f32 *) (obj + 0xC) - 20.0f;
    qMinZ = *(f32 *) (obj + 0x14) - 20.0f;
    qMaxX = *(f32 *) (obj + 0xC) + 20.0f;
    qMaxZ = *(f32 *) (obj + 0x14) + 20.0f;

    hitList = (u8 **) hitGetHitModels(&nHit);
    nCand = 0;
    for (i = 0; i < nHit; i++) {
        hitObj = hitList[i];
        if ((*(u16 *) (*(u8 **) (hitObj + 0x4C) + 0xA) & 1) == 0) {
            continue;
        }
        box = *(u8 **) (hitObj + 0x5C);
        if (box == NULL) {
            continue;
        }
        bMinX = *(f32 *) (box + 0x100);
        bMinZ = *(f32 *) (box + 0x108);
        bMaxX = *(f32 *) (box + 0x10C);
        bMaxZ = *(f32 *) (box + 0x114);
        if ((qMinX < bMinX && qMaxX < bMinX) || (bMaxX < qMinX && bMaxX < qMaxX)) {
            continue;
        }
        if ((qMinZ < bMinZ && qMaxZ < bMinZ) || (bMaxZ < qMinZ && bMaxZ < qMaxZ)) {
            continue;
        }

        dx = ((bMaxX - bMinX) * 0.5f) - *(f32 *) (obj + 0xC);
        dz = ((bMaxZ - bMinZ) * 0.5f) - *(f32 *) (obj + 0x14);
        candIdx[nCand] = i;
        candDist[nCand] = (dx * dx) + (dz * dz);
        /* insertion sort by distance, ascending */
        k = nCand;
        while (k > 0 && candDist[k] < candDist[k - 1]) {
            tf = candDist[k];
            candDist[k] = candDist[k - 1];
            candDist[k - 1] = tf;
            ti = candIdx[k];
            candIdx[k] = candIdx[k - 1];
            candIdx[k - 1] = ti;
            k--;
        }
        nCand++;
        if (nCand >= 15) {
            break;
        }
    }

    for (k = 0; k < nCand; k++) {
        hitObj = hitList[candIdx[k]];
        if (hitObj == obj) {
            continue;
        }
        nTri = func_80020104(hitObj, D_800F48F0_B2C70, D_800F52F0_B3670 + (D_800F5AF4_B3E74 * 0x10),
                             *(f32 *) (caster + 0x38), *(f32 *) (caster + 0x3C),
                             *(f32 *) (caster + 0x40), *(f32 *) (caster + 0x44));
        for (t = 0; t < nTri; t++) {
            rec = (u8 *) D_800F48F0_B2C70 + t * 0x14;
            plane = D_800F52F0_B3670 + (D_800F5AF4_B3E74 + t) * 0x10;

            /* y range of the three vertices (s16 y at +2, +8, +0xE) */
            lo = *(s16 *) (rec + 0x2);
            hi = lo;
            for (j = 1; j < 3; j++) {
                y = *(s16 *) (rec + j * 6 + 0x2);
                if (y < lo) {
                    lo = y;
                }
                if (hi < y) {
                    hi = y;
                }
            }
            if (*(s16 *) (caster + 0xE) < lo) {
                continue;
            }
            if (hi < *(s16 *) (caster + 0xC)) {
                continue;
            }

            /* triangle as a clip polygon: x @0, z @8, tag -1 */
            for (j = 0; j < 3; j++) {
                *(f32 *) (buf + j * 0x10 + 0x0) = (f32) *(s16 *) (rec + j * 6 + 0x0);
                *(f32 *) (buf + j * 0x10 + 0x8) = (f32) *(s16 *) (rec + j * 6 + 0x4);
                *(s16 *) (buf + j * 0x10 + 0xE) = -1;
            }

            *(u8 **) (caster + 0x8) = plane;
            if (*(f32 *) (plane + 0x4) > 0.5f) {
                if (*(f32 *) (caster + 0x1C) > 0.0f) {
                    shadowYHeight(caster, buf);
                }
                v = func_8001F288(caster, 3, buf, 4, arg1);
                if (v >= 3) {
                    /* append the clipped polygon as an entry */
                    nEnt = D_800F45E8_B2968;
                    ent = D_800F45F0_B2970 + nEnt * 12;
                    ent[1] = 0;
                    for (j = 0; j < v; j++) {
                        tag = *(s16 *) (buf + j * 0x10 + 0xE);
                        if (tag >= 0) {
                            /* intersection: cache index from func_8001F288 */
                            ent[1] = (u8) (ent[1] | (1 << j));
                            ent[2 + j] = (u8) tag;
                            continue;
                        }
                        /* original vertex: find or add it in table D_800F33D8 */
                        nB = D_800F33D0_B1750;
                        found = -1;
                        for (b = 0; b < nB && found == -1; b++) {
                            tb = D_800F33D8_B1758 + b * 0x10;
                            if (*(f32 *) (tb + 0x0) == *(f32 *) (buf + j * 0x10 + 0x0) &&
                                *(f32 *) (tb + 0x8) == *(f32 *) (buf + j * 0x10 + 0x8)) {
                                found = b;
                            }
                        }
                        if (found == -1) {
                            slot = (nB >= 0x20) ? 0x1F : nB;
                            tb = D_800F33D8_B1758 + slot * 0x10;
                            *(f32 *) (tb + 0x0) = *(f32 *) (buf + j * 0x10 + 0x0);
                            *(f32 *) (tb + 0x8) = *(f32 *) (buf + j * 0x10 + 0x8);
                            *(u8 **) (tb + 0xC) = *(u8 **) (caster + 0x8);
                            D_800F33D0_B1750 = slot + 1;
                            ent[2 + j] = (u8) slot;
                        } else {
                            ent[2 + j] = (u8) found;
                        }
                    }
                    ent[0] = (u8) v;
                    *(s16 *) (ent + 0xA) = 0;
                    D_800F45E8_B2968 = nEnt + 1;
                }
            }
        }
        D_800F5AF4_B3E74 += nTri;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/func_8001EBE8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Clips the polygon arg2 (arg1 verts, 0x10 B each: f32 x @0, f32 z @8, s16 tag @0xE)
// against the convex clip polygon arg4 (arg3 verts, 8 B each: f32 x @0, f32 z @4).
// Per clip edge the line is L(p) = A*p.z + B*p.x + C. Crossing points are cached per
// clip edge in D_800F35E8_B1968 (32 entries of 0x20 B per edge, count in
// D_800F35D8_B1958[edge]): entry +0x0 = intersection (x, z), +0x8 unused, +0xC = arg0+0x8,
// +0x10/+0x14 and +0x18/+0x1C = the two input endpoints. The output tag @0xE is the
// global cache index. Returns the new vert count (written back to arg2), 0 if fewer than
// 3 verts remain or the 8-vert output buffer overflows.
s32 func_8001F288(void *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4) {
    u8 outBuf[0x80];
    u8 *in;
    u8 *out;
    u8 *tmp;
    u8 *clip;
    u8 *ent;
    u8 *slot;
    f32 *vi;
    f32 *vn;
    f32 *sl;
    f32 *cur;
    f32 *nxt;
    f32 ca;
    f32 cb;
    f32 cc;
    f32 dI;
    f32 dN;
    f32 tt;
    f32 ix;
    f32 iz;
    s32 nIn;
    s32 nOut;
    s32 nClip;
    s32 edge;
    s32 nxtEdge;
    s32 i;
    s32 iNext;
    s32 cnt;
    s32 gidx;
    s32 found;
    s32 k;

    in = (u8 *) arg2;
    out = outBuf;
    clip = (u8 *) arg4;
    nIn = arg1;
    nClip = arg3;
    edge = 0;
    if (nClip > 0 && nIn >= 3) {
        do {
            nxtEdge = (edge + 1 < nClip) ? edge + 1 : 0;
            cur = (f32 *) (clip + edge * 8);
            nxt = (f32 *) (clip + nxtEdge * 8);
            ca = cur[0] - nxt[0];
            cb = nxt[1] - cur[1];
            if (cur[0] < nxt[0]) {
                cc = -((cur[1] * ca) + (cb * cur[0]));
            } else {
                cc = -((nxt[1] * ca) + (cb * nxt[0]));
            }
            nOut = 0;
            for (i = 0; i < nIn; i++) {
                iNext = (i + 1 < nIn) ? i + 1 : 0;
                vi = (f32 *) (in + i * 0x10);
                vn = (f32 *) (in + iNext * 0x10);
                dI = (vi[2] * ca) + (vi[0] * cb) + cc;
                dN = (vn[2] * ca) + (vn[0] * cb) + cc;

                if (((dI >= 0.0f) && (dN < 0.0f)) || ((dI < 0.0f) && (dN >= 0.0f))) {
                    /* crossing: look for a cached intersection of this input segment */
                    cnt = D_800F35D8_B1958[edge];
                    gidx = edge * 0x20;
                    ent = D_800F35E8_B1968 + edge * 0x400;
                    found = -1;
                    if (cnt > 0) {
                        do {
                            if (*(f32 *) (ent + 0x10) == vi[0] && *(f32 *) (ent + 0x14) == vi[2] &&
                                *(f32 *) (ent + 0x18) == vn[0] && *(f32 *) (ent + 0x1C) == vn[2]) {
                                found = gidx;
                                break;
                            }
                            cnt -= 1;
                            if (*(f32 *) (ent + 0x10) == vn[0] && *(f32 *) (ent + 0x14) == vn[2] &&
                                *(f32 *) (ent + 0x18) == vi[0] && *(f32 *) (ent + 0x1C) == vi[2]) {
                                found = gidx;
                                break;
                            }
                            ent += 0x20;
                            gidx += 1;
                        } while (cnt > 0);
                    }

                    slot = out + nOut * 0x10;
                    sl = (f32 *) slot;
                    if (found >= 0) {
                        *(s16 *) (slot + 0xE) = (s16) found;
                        sl[0] = *(f32 *) ent;
                        sl[2] = *(f32 *) (ent + 0x8);
                        nOut += 1;
                        if (nOut >= 8) {
                            return 0;
                        }
                    } else {
                        tt = dI / (dI - dN);
                        ix = vi[0] + (vn[0] - vi[0]) * tt;
                        iz = vi[2] + (vn[2] - vi[2]) * tt;
                        sl[0] = ix;
                        sl[2] = iz;
                        *(f32 *) ent = ix;
                        *(f32 *) (ent + 0x8) = iz;
                        *(s32 *) (ent + 0xC) = *(s32 *) ((u8 *) arg0 + 0x8);
                        *(f32 *) (ent + 0x10) = vi[0];
                        *(f32 *) (ent + 0x14) = vi[2];
                        *(f32 *) (ent + 0x18) = vn[0];
                        *(f32 *) (ent + 0x1C) = vn[2];
                        *(s16 *) (slot + 0xE) = (s16) gidx;
                        nOut += 1;
                        if (nOut >= 8) {
                            return 0;
                        }
                        D_800F35D8_B1958[edge] += 1;
                    }
                }

                if (dN <= 0.0f) {
                    slot = out + nOut * 0x10;
                    sl = (f32 *) slot;
                    sl[0] = vn[0];
                    sl[2] = vn[2];
                    *(s16 *) (slot + 0xE) = *(s16 *) (in + iNext * 0x10 + 0xE);
                    nOut += 1;
                    if (nOut >= 8) {
                        return 0;
                    }
                }
            }
            tmp = in;
            in = out;
            out = tmp;
            nIn = nOut;
            edge += 1;
        } while (edge < nClip && nIn >= 3);
    }

    if (nIn < 3) {
        return 0;
    }
    if (in != (u8 *) arg2) {
        for (k = 0; k < nIn; k++) {
            u8 *d = (u8 *) arg2 + k * 0x10;
            u8 *s = in + k * 0x10;

            *(f32 *) d = *(f32 *) s;
            *(f32 *) (d + 0x8) = *(f32 *) (s + 0x8);
            *(s16 *) (d + 0xE) = *(s16 *) (s + 0xE);
        }
    }
    return nIn;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/func_8001F288.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Builds shadow geometry for the caster arg0. Source entries are 12 B records in
// D_800F45F0 (u8 count, u8 table mask, u8 index[]): bit set = D_800F35E8 (0x20 B records),
// clear = D_800F33D8 (0x10 B records); both store f32 x, y, z at +0/+4/+8.
// Output vertices (0xA B: s16 x, y, z; u8 0xFF x3; u8 alpha) go to D_800A0EB0, triangles
// (0x10 B: u8 0, a, b, fan root; then three texcoord words) to D_800A0EB4, and groups
// (8 B: tex ptr, s16 tri start, s16 vtx start) to D_800A0EB8. Counters: D_800A0EBC/EC0/EC4.
// Returns 1, or 0 when a limit (D_800F5B00/04/08) is hit.
// arg0 caster: +0 obj ptr, +4 tex info ptr (u8 w, u8 h), +0x14 y base, +0x18/+0x1C/+0x20
//   height fade, +0x2C/+0x30/+0x34 uv params. arg1: optional s16 angle (+4 scales alpha).
//   arg2: flags, u8 +0xC bit 0x20 = no rotation.
// obj: s16 +0 yaw, f32 +0xC/+0x10/+0x14 position, +0x40 info ptr (f32 +0x58 scale).
s32 func_8001F7C8(void *arg0, void *arg1, void *arg2) {
    u8 *caster;
    u8 *obj;
    u8 *tex;
    u8 *ent;
    u8 *vtx;
    u8 *tri;
    u8 *grp;
    u32 tc[12];
    f32 sinA;
    f32 cosA;
    f32 alpha;
    f32 uScale;
    f32 vScale;
    f32 uOff;
    f32 vOff;
    f32 dy;
    f32 sc;
    f32 fx;
    f32 fy;
    f32 fz;
    f32 dx;
    f32 dz;
    f32 rx;
    f32 rz;
    s32 sVal;
    s32 nVert;
    s32 nTri;
    s32 nGrp;
    s32 grpLocal;
    s32 cnt;
    s32 mask;
    s32 j;
    s32 k;
    s32 idx;
    s32 tu;
    s32 tv;
    s32 v1;
    s32 a0;
    s32 a1;

    caster = (u8 *) arg0;
    obj = *(u8 **) caster;
    tex = *(u8 **) (caster + 0x4);
    if (*(u8 *) ((u8 *) arg2 + 0xC) & 0x20) {
        cosA = 1.0f;
        sinA = 0.0f;
    } else if (arg1 != NULL) {
        sinA = Sinf(*(s16 *) arg1);
        cosA = Cosf((s32) *(s16 *) arg1);
    } else {
        sinA = Sinf(*(s16 *) obj);
        cosA = Cosf((s32) *(s16 *) obj);
    }

    alpha = 255.0f;
    uScale = (f32) (tex[0] << 4) / *(f32 *) (caster + 0x2C);
    uOff = *(f32 *) (caster + 0x2C);
    vOff = *(f32 *) (caster + 0x30);
    vScale = (f32) (tex[1] << 5) / (vOff + *(f32 *) (caster + 0x34));

    if (*(f32 *) (caster + 0x1C) > 0.0f) {
        dy = *(f32 *) (obj + 0x10) - *(f32 *) (caster + 0x18);
        if (*(f32 *) (caster + 0x1C) < dy) {
            alpha = 255.0f * (1.0f - ((dy - *(f32 *) (caster + 0x1C)) / *(f32 *) (caster + 0x20)));
            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
        }
        if (dy > 0.0f) {
            sc = (dy / *(f32 *) (*(u8 **) (obj + 0x40) + 0x58)) + 1.0f;
            uScale *= sc;
            uOff /= sc;
            vScale *= sc;
            vOff /= sc;
        }
    }

    sVal = (s32) (alpha * D_800F5AF0_B3E70);
    if (arg1 != NULL) {
        sVal = (*(s16 *) ((u8 *) arg1 + 0x4) * sVal) >> 8;
    }

    nVert = D_800A0EBC_A1ABC;
    nTri = D_800A0EC0_A1AC0;
    nGrp = D_800A0EC4_A1AC4;
    grpLocal = 0x19;
    ent = D_800F45F0_B2970;

    for (k = 0; k < D_800F45E8_B2968; k++, ent += 0xC) {
        cnt = ent[0];
        mask = ent[1];
        if (cnt + grpLocal >= 0x18) {
            /* start a new group */
            grp = (u8 *) (D_800A0EB8_A1AB8 + nGrp * 8);
            *(s16 *) (grp + 0x6) = (s16) nVert;
            *(s16 *) (grp + 0x4) = (s16) nTri;
            nGrp += 1;
            *(u8 **) grp = tex;
            grpLocal = 0;
        }
        if (nGrp >= D_800F5B08_B3E88) {
            return 0;
        }

        for (j = 0; j < cnt; j++) {
            if (mask & 1) {
                idx = ent[2 + j];
                vtx = D_800F35E8_B1968 + idx * 0x20;
            } else {
                idx = ent[2 + j];
                vtx = D_800F33D8_B1758 + idx * 0x10;
            }
            fx = *(f32 *) (vtx + 0x0);
            fy = *(f32 *) (vtx + 0x4);
            fz = *(f32 *) (vtx + 0x8);
            mask >>= 1;

            /* output vertex */
            vtx = (u8 *) (D_800A0EB0_A1AB0 + nVert * 0xA);
            nVert += 1;
            *(s16 *) (vtx + 0x0) = (s16) fx;
            *(s16 *) (vtx + 0x2) = (s16) (*(f32 *) (caster + 0x14) + fy);
            *(s16 *) (vtx + 0x4) = (s16) fz;
            vtx[6] = 0xFF;
            vtx[7] = 0xFF;
            vtx[8] = 0xFF;
            vtx[9] = (u8) sVal;
            if (nVert >= D_800F5B00_B3E80) {
                return 0;
            }

            /* texcoords: rotate around the caster, scale and offset */
            dx = fx - *(f32 *) (obj + 0xC);
            dz = fz - *(f32 *) (obj + 0x14);
            rx = (dx * cosA) - (dz * sinA);
            rz = (dz * cosA) + (dx * sinA);
            tv = (s32) ((rz + vOff) * vScale);
            tu = (s32) (uScale * (rx + uOff));
            tc[j] = ((u32) tu << 16) | ((u32) tv & 0xFFFF);
        }

        if (cnt >= 3) {
            v1 = 1;
            do {
                a0 = grpLocal + v1;
                a1 = a0 + 1;
                tri = (u8 *) (D_800A0EB4_A1AB4 + nTri * 0x10);
                tri[0] = 0;
                tri[1] = (u8) a0;
                tri[2] = (u8) a1;
                tri[3] = (u8) grpLocal;
                *(u32 *) (tri + 0x4) = tc[v1];
                *(u32 *) (tri + 0x8) = tc[v1 + 1];
                *(u32 *) (tri + 0xC) = tc[0];
                nTri += 1;
                if (nTri >= D_800F5B04_B3E84) {
                    return 0;
                }
                v1 += 1;
            } while (v1 < cnt - 1);
        }
        grpLocal += cnt;
    }

    D_800A0EBC_A1ABC = nVert;
    D_800A0EC0_A1AC0 = nTri;
    D_800A0EC4_A1AC4 = nGrp;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/func_8001F7C8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8001FD20(void *arg0) {
    u8 *obj;
    u8 *info;
    u8 *mgr;
    u8 *sh;
    u8 *poly;
    u8 *tri;
    u8 *polyVerts;
    u8 *vA;
    u8 *vB;
    u8 *vC;
    f32 *alpha;
    f32 fx;
    f32 fz;
    f32 f0;
    s32 base;
    s32 yLo;
    s32 yHi;
    s32 shadowIdx;
    s32 mask;
    s32 polyIdx;
    s32 triIdx;
    s32 flags;
    s32 material;
    s32 done;
    s32 k;
    s16 minY;
    s16 maxY;
    s16 y;
    u32 m;

    obj = (u8 *) arg0;
    info = *(u8 **) (obj + 0x40);
    base = (s32) *(f32 *) (obj + 0x10);
    yHi = base + *(s16 *) (info + 0x6E);
    yLo = base + *(s16 *) (info + 0x6C);
    shadowIdx = *(s16 *) (obj + 0x2E);
    done = 0;
    if (shadowIdx != -1) {
        mgr = (u8 *) D_800F5B0C_B3E8C;
        fx = *(f32 *) (obj + 0xC);
        fz = *(f32 *) (obj + 0x14);
        mask = getXZCompareMask(*(s32 *) (mgr + 8) + shadowIdx * 0xC, (s32) (fx - 16.0f), (s32) (fz - 16.0f),
                                (s32) (fx + 16.0f), (s32) (fz + 16.0f));
        sh = *(u8 **) (mgr + 4) + shadowIdx * 0x48;
        for (polyIdx = 0; polyIdx < *(s16 *) (sh + 0x28) && !done; polyIdx++) {
            poly = *(u8 **) (sh + 0xC) + polyIdx * 0x10;
            flags = *(s32 *) (poly + 0xC);
            if (!(flags & 0x3480)) {
                material = (flags >> 22) & 7;
                polyVerts = *(u8 **) sh + *(s16 *) (poly + 6) * 10;
                for (triIdx = *(s16 *) (poly + 8); triIdx < *(s16 *) (poly + 0x18) && !done; triIdx++) {
                    m = *(u32 *) (*(u8 **) (sh + 0x10) + triIdx * 4) & mask;
                    if ((m & 0xFFFF) != 0 && (m >> 16) != 0) {
                        tri = *(u8 **) (sh + 4) + triIdx * 0x10;
                        vA = polyVerts + tri[1] * 10;
                        vB = polyVerts + tri[2] * 10;
                        vC = polyVerts + tri[3] * 10;
                        minY = *(s16 *) (vA + 2);
                        maxY = minY;
                        for (k = 2; k < 4; k++) {
                            y = *(s16 *) (polyVerts + tri[k] * 10 + 2);
                            if (y < minY) {
                                minY = y;
                            } else if (maxY < y) {
                                maxY = y;
                            }
                        }
                        if (maxY >= yLo && yHi >= minY) {
                            if (mathXZInTri((s32) *(f32 *) (obj + 0xC), (s32) *(f32 *) (obj + 0x14), vA, vB, vC)) {
                                alpha = *(f32 **) (obj + 0x54);
                                f0 = *alpha;
                                *alpha = f0 + (((1.0f - D_800A0ED4_A1AD4[material]) - f0) * D_800F5B14_B3E94);
                                done = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/func_8001FD20.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// For every polygon of the model selected by obj->0x5C->0x133 (EC table at obj+0x6C):
// transforms each triangle's 3 vertices (10 B records: s16 x, y, z) with the hit matrix
// (mtx+0x80) and box-tests them against arg3..arg6 via shadowBoxPolyOverlap.
// Each hit writes a 0x14-byte short record (9 coords) to arg1 and a 16-byte float
// record (vec4 * obj->scale) to arg2. Returns the hit count.
s32 func_80020104(void *arg0, s16 *arg1, void *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 *obj;
    u8 *hit;
    u8 *ec;
    u8 *model;
    u8 *xf;
    u8 *mtx;
    u8 *poly;
    u8 *ent;
    s16 *v;
    s16 *outS;
    f32 *outF;
    f32 vec[4];
    f32 pts[3][4];
    f32 scale;
    s32 xfBase;
    s32 xIdx;
    s32 count;
    s32 p;
    s32 s4;
    s32 end;
    s32 vbase;
    s32 j;

    obj = (u8 *) arg0;
    hit = *(u8 **) (obj + 0x5C);
    ec = ((u8 **) *(u8 **) (obj + 0x6C))[hit[0x133]];
    model = *(u8 **) ec;
    xf = *(u8 **) (ec + 0xC);
    if (xf == NULL) {
        xf = *(u8 **) (model + 0x60);
    }
    xfBase = *(s32 *) (xf + 0xC);
    mtx = hit + (hit[0x12B] << 6);
    scale = *(f32 *) (obj + 0x8);
    outS = arg1;
    outF = (f32 *) arg2;
    count = 0;

    for (p = 0; p < *(s16 *) (model + 0x16); p++) {
        poly = *(u8 **) (model + 0x24) + p * 0x10;
        if (!(*(s32 *) (poly + 0xC) & 0x1C80)) {
            vbase = *(s16 *) (poly + 0x6);
            end = *(s16 *) (poly + 0x18);
            for (s4 = *(s16 *) (poly + 0x8); s4 < end; s4++) {
                xIdx = *(u16 *) (*(u8 **) xf + s4 * 0xE);
                matrixTransposeVectorMultiply(mtx, (xIdx << 4) + xfBase, vec, xfBase);
                if ((vec[1] * scale) > 0.5f) {
                    ent = *(u8 **) (model + 0x20) + s4 * 0x10;
                    for (j = 0; j < 3; j++) {
                        v = (s16 *) (*(u8 **) (ec + 0x4) + (ent[j + 1] + vbase) * 0xA);
                        mathMtxXFMF((f32 (*)[4]) (mtx + 0x80), (f32) v[0], (f32) v[1], (f32) v[2],
                                    &pts[j][0], &pts[j][1], &pts[j][2]);
                    }
                    if (shadowBoxPolyOverlap(arg3, arg4, arg5, arg6, 3, pts) != 0) {
                        outS[0] = (s16) pts[0][0];
                        outS[1] = (s16) pts[0][1];
                        outS[2] = (s16) pts[0][2];
                        outS[3] = (s16) pts[1][0];
                        outS[4] = (s16) pts[1][1];
                        outS[5] = (s16) pts[1][2];
                        outS[6] = (s16) pts[2][0];
                        outS[7] = (s16) pts[2][1];
                        outS[8] = (s16) pts[2][2];
                        outS = (s16 *) ((u8 *) outS + 0x14);
                        outF[0] = vec[0] * scale;
                        outF[1] = vec[1] * scale;
                        outF[2] = vec[2] * scale;
                        outF[3] = vec[3] * scale;
                        outF += 4;
                        count += 1;
                    }
                }
            }
        }
    }
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/shadows/func_80020104.s")
#endif
