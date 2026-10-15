#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void mmFree(void *data);
void _bzero(void *ptr, s32 size);
s32 frontGet2PlayerSplit(s32 arg0);
void viConvertXY(s32 *arg0, s32 *arg1);
s32 objTvTimes(s32 arg0, void *arg1, s8 arg2); /* sig differs from other callers */
extern s8 hideinstruments;
extern s32 viFramesPerSecond;
extern u8 numberOfPlayers;
extern void *insthealthmetervtxs;
extern u8 msgQueues[];
extern u8 currentobjects[];
extern s16 playeroffsets[];
extern s16 twoplayercoordinates[];
extern s16 twoplayerwidecoordinates[];
extern s16 fourplayercoordinates[];
extern u8 D_overlay_6_00601B10[];
extern s16 D_overlay_6_00601B18[];
extern char D_overlay_6_00601AC0;
extern char D_overlay_6_00601AC4;
extern char D_overlay_6_00601AC8;
extern char D_overlay_6_00601ACC;
extern char D_overlay_6_00601AD0;
extern char D_overlay_6_00601AD4;
extern f64 D_overlay_6_00601AF8;
extern f64 D_overlay_6_00601B00;
extern char D_overlay_6_00601AD8;
extern char D_overlay_6_00601ADC;
extern char D_overlay_6_00601AE0;
extern char D_overlay_6_00601AE4;
extern char D_overlay_6_00601AE8;
extern char D_overlay_6_00601AEC;
extern char D_overlay_6_00601AF0;
extern s32 D_overlay_6_00601B20[];
extern s16 D_overlay_6_00601BE0[];
extern s16 D_overlay_6_00601BE8[];
extern u8 D_overlay_6_00601BF0[];
f32 Sinf(s32 angle);
extern Gfx *frontgfx;
extern s32 frontmtx;
extern s32 objtrans;
extern u8 insthealthmeterpolys[];
extern s32 D_800FF400;
extern f32 D_800FF7CC;
extern f32 D_800FF7D0;
extern f32 D_800FF7D8;
extern f32 D_overlay_6_00601AF4;
void instGetPos(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
void texDPTextureX(Gfx **dlist, s32 tex, s32 rtile, s32 tmem);
void camStandardOrtho(Gfx **dlist, s32 *mtx);
void camCopyOrthoMatrix(void *mtx);
void matrixTranslate(f32 x, f32 y, f32 z, void *mtx);
void matrixScale(f32 x, f32 y, f32 z, void *mtx);
void mathMtxF2L(void *mtx, s32 dst);
void frontDrawObj(s32 arg0);

#define INST_MSGQ(i) (msgQueues + (i) * 0x50)
#define INST_OBJ_AC (*(f32 *)(currentobjects + 0xAC))
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instDrawHealth(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 mtx[4][4];      /* asm: sp+0x98..0xD7; mtx[3][3] (sp+0xD4) is set to half the screen width */
    s32 width;
    s32 height;
    s32 posX;
    s32 posY;
    s32 count;
    s32 k;
    s32 fp;             /* poly slots left in the current group of 12 */
    s32 t1;
    s32 modRem;
    s32 rem;
    s32 rawArg1;
    s32 base;
    s32 cur;
    s32 val;
    s16 timer;
    s8 *idxp;
    u32 vtxAddr;
    u32 polyAddr;
    u32 c;
    Gfx *gfx;
    u8 *polyPtr;
    f32 f0;
    f32 fTgt;
    f32 fA;
    f32 fB;
    f32 fC;

    rawArg1 = arg1;     /* asm: objTvTimes receives the unclamped $a1 */
    if (arg1 < 0) {
        arg1 = 0;
    }
    /* arg0 + 0x68 points at the player index byte */
    idxp = *(s8 **)((u8 *)arg0 + 0x68);
    if (arg1 != D_overlay_6_00601BE8[*idxp]) {
        D_overlay_6_00601BE8[*idxp] = (s16) arg1;
        D_overlay_6_00601BE0[*idxp] = objTvTimes(0x384, (void *) rawArg1, arg2);
    }
    timer = D_overlay_6_00601BE0[*idxp];
    if (arg3 < timer) {
        D_overlay_6_00601BE0[*idxp] = timer - arg3;
        timer = D_overlay_6_00601BE0[*idxp];
        k = 0;
        if (timer >= 0x2BD) {
            /* fade the bar alpha towards 0xFF; asm unrolls by 4 with a Duff-style entry */
            if (arg3 > 0) {
                rem = arg3 & 3;
                if (rem != 0) {
                    do {
                        k += 1;
                        D_overlay_6_00601BF0[*idxp] += (s32) (0xFF - D_overlay_6_00601BF0[*idxp]) / 8;
                    } while (rem != k);
                    if (k != arg3) {
                        goto fade_in_unrolled;
                    }
                } else {
fade_in_unrolled:
                    do {
                        k += 4;
                        D_overlay_6_00601BF0[*idxp] += (s32) (0xFF - D_overlay_6_00601BF0[*idxp]) / 8;
                        D_overlay_6_00601BF0[*idxp] += (s32) (0xFF - D_overlay_6_00601BF0[*idxp]) / 8;
                        D_overlay_6_00601BF0[*idxp] += (s32) (0xFF - D_overlay_6_00601BF0[*idxp]) / 8;
                        D_overlay_6_00601BF0[*idxp] += (s32) (0xFF - D_overlay_6_00601BF0[*idxp]) / 8;
                    } while (k != arg3);
                }
            }
        } else if (timer < 0xC8) {
            /* fade the bar alpha towards 0 */
            if (arg3 > 0) {
                rem = arg3 & 3;
                if (rem != 0) {
                    do {
                        k += 1;
                        D_overlay_6_00601BF0[*idxp] -= (s32) D_overlay_6_00601BF0[*idxp] / 8;
                    } while (rem != k);
                    if (k != arg3) {
                        goto fade_out_unrolled;
                    }
                } else {
fade_out_unrolled:
                    do {
                        k += 4;
                        D_overlay_6_00601BF0[*idxp] -= (s32) D_overlay_6_00601BF0[*idxp] / 8;
                        D_overlay_6_00601BF0[*idxp] -= (s32) D_overlay_6_00601BF0[*idxp] / 8;
                        D_overlay_6_00601BF0[*idxp] -= (s32) D_overlay_6_00601BF0[*idxp] / 8;
                        D_overlay_6_00601BF0[*idxp] -= (s32) D_overlay_6_00601BF0[*idxp] / 8;
                    } while (k != arg3);
                }
            }
        }

        k = 0;
        polyPtr = insthealthmeterpolys;
        fp = 12;
        texDPInit(&frontgfx);
        camCopyOrthoMatrix(mtx);
        viGetCurrentSize(&width, &height);
        mtx[3][3] = (f32) ((u32) width >> 1);
        if (numberOfPlayers == 1) {
            matrixTranslate(D_800FF7CC + 1.0f, D_800FF7D0 - 2.0f, 0.0f, mtx);
        } else {
            instGetPos(0, *idxp, &posX, &posY);
            matrixTranslate((f32) posX, (f32) posY, 0.0f, mtx);
            matrixScale(D_overlay_6_00601AF4, D_overlay_6_00601AF4, 1.0f, mtx);
        }
        mathMtxF2L(mtx, frontmtx);

        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0x01000040;
        gfx->words.w1 = (u32) frontmtx + 0x80000000;
        gfx = frontgfx;
        frontmtx += 0x40;
        frontgfx = gfx + 1;
        vtxAddr = (u32) insthealthmetervtxs + 0x80000000;
        gfx->words.w0 = ((((vtxAddr & 6) | 0x70) & 0xFF) << 0x10) | 0x04000000 | 0x94;
        gfx->words.w1 = vtxAddr;

        if (numberOfPlayers != 1) {
            t1 = arg1;
            count = (arg2 * 5 + 4) / 5;
            if (count > 0) {
                do {
                    base = k << 0x11;
                    if (t1 < 5) {
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = ((((s32) (D_overlay_6_00601BF0[*idxp] * ((((s32) (t1 * 0x5C)) / 5) + 0x64))) >> 8) & 0xFF) | ~0xFF;
                        D_overlay_6_00601B20[*idxp * 12 + k] = (((s32) ((5 - t1) << 0x10)) / 5) + base;
                    } else {
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = ((((s32) (D_overlay_6_00601BF0[*idxp] * 0xC0)) >> 8) & 0xFF) | ~0xFF;
                    }
                    cur = D_overlay_6_00601B20[*idxp * 12 + k];
                    val = (((s32) (base - cur)) / 8) + cur;
                    D_overlay_6_00601B20[*idxp * 12 + k] = val;
                    if (t1 >= 6) {
                        t1 = t1 - 5;
                    } else {
                        t1 = 0;
                    }
                    texDPTextureX(&frontgfx, D_800FF400, 5, val);
                    gfx = frontgfx;
                    frontgfx = gfx + 1;
                    gfx->words.w0 = 0xE7000000;
                    gfx->words.w1 = 0;
                    gfx = frontgfx;
                    frontgfx = gfx + 1;
                    c = (val >> 8) & 0xFF;
                    gfx->words.w0 = 0xFB000000;
                    gfx->words.w1 = (c << 24) | (c << 16) | (c << 8) | c;
                    gfx = frontgfx;
                    frontgfx = gfx + 1;
                    polyAddr = (u32) polyPtr + 0x80000000;
                    fp -= 2;
                    polyPtr += 0x20;
                    gfx->words.w0 = 0x05110020;
                    gfx->words.w1 = polyAddr;
                    if (fp == 0 && count != k + 1) {
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = ((((((vtxAddr + 0x8C) & 6) | 0x70) & 0xFF) << 0x10) | 0x04000000 | 0x94);
                        polyPtr = insthealthmeterpolys;
                        fp = 12;
                        gfx->words.w1 = vtxAddr + 0x8C;
                    }
                    k += 1;
                } while (k < count);
            }
        } else {
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w0 = 0xFA000000;
            gfx->words.w1 = ((((s32) (D_overlay_6_00601BF0[*idxp] * 0xC0)) >> 8) & 0xFF) | ~0xFF;
            count = arg2 + 1;
            modRem = arg1 % count;
            if (arg2 > 0) {
                do {
                    base = k << 0x11;
                    val = base;
                    if (modRem <= 0) {
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        val = base + 0x10000;
                        gfx->words.w1 = ((((s32) (D_overlay_6_00601BF0[*idxp] << 7)) >> 8) & 0xFF) | ~0xFF;
                    }
                    cur = D_overlay_6_00601B20[*idxp * 12 + k];
                    D_overlay_6_00601B20[*idxp * 12 + k] = cur + (((s32) (val - cur)) >> 2);
                    cur = D_overlay_6_00601B20[*idxp * 12 + k];
                    texDPTextureX(&frontgfx, D_800FF400, 5, cur);
                    gfx = frontgfx;
                    frontgfx = gfx + 1;
                    gfx->words.w0 = 0xE7000000;
                    gfx->words.w1 = 0;
                    gfx = frontgfx;
                    frontgfx = gfx + 1;
                    c = (cur >> 8) & 0xFF;
                    gfx->words.w0 = 0xFB000000;
                    gfx->words.w1 = (c << 24) | (c << 16) | (c << 8) | c;
                    gfx = frontgfx;
                    frontgfx = gfx + 1;
                    polyAddr = (u32) polyPtr + 0x80000000;
                    fp -= 2;
                    polyPtr += 0x20;
                    gfx->words.w0 = 0x05110020;
                    gfx->words.w1 = polyAddr;
                    if (fp == 0) {
                        if (k != 0xB) {
                            gfx = frontgfx;
                            frontgfx = gfx + 1;
                            gfx->words.w0 = ((((((vtxAddr + 0x8C) & 6) | 0x70) & 0xFF) << 0x10) | 0x04000000 | 0x94);
                            polyPtr = insthealthmeterpolys;
                            fp = 12;
                            gfx->words.w1 = vtxAddr + 0x8C;
                        }
                    }
                    k += 1;
                    modRem -= 1;
                } while (k != arg2);
            }
            camStandardOrtho(&frontgfx, &frontmtx);
            if (D_800FF7D8 == -1000.0f) {
                f0 = (f32) (arg1 / count);
                goto health_store;
            }
            k = 0;
            rem = arg3 & 3;
            if (arg3 > 0) {
                if (rem != 0) {
                    f0 = D_800FF7D8;
                    do {
                        k += 1;
                        f0 += ((f32) (arg1 / count) - f0) * 0.125f;
                    } while (rem != k);
                    D_800FF7D8 = f0;
                    if (k != arg3) {
                        goto health_smooth_unrolled;
                    }
                } else {
health_smooth_unrolled:
                    f0 = D_800FF7D8;
                    fTgt = (f32) (arg1 / count);
                    do {
                        k += 4;
                        fA = f0 + ((fTgt - f0) * 0.125f);
                        fB = fA + ((fTgt - fA) * 0.125f);
                        fC = fB + ((fTgt - fB) * 0.125f);
                        f0 = fC + ((fTgt - fC) * 0.125f);
                    } while (k != arg3);
health_store:
                    D_800FF7D8 = f0;
                }
            }
            objtrans = ((s32) (D_overlay_6_00601BF0[*idxp] * 0xA4)) >> 8;
            frontDrawObj(2);
            objtrans = 0xFF;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instDrawHealth.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instInitHealthMeter(void) {
    u8 *p;
    u8 *q;
    s32 angle;
    s32 k;
    s32 i;
    s32 j;
    f32 radius;

    p = (u8 *) mmAlloc(0x118, -1U);
    insthealthmetervtxs = p;
    if (p != NULL) {
        angle = 0;
        if (numberOfPlayers == 1) {
            radius = 20.0f;
        } else {
            radius = 14.0f;
        }
        /* 14 iterations, each writing two 0xA-byte vertices (x, y, z, 4 colour bytes) */
        for (k = 0; k < 14; k++) {
            *(s16 *) (p + 0x0) = (s16) (s32) (Sinf(angle) * 38.0f);
            *(s16 *) (p + 0x2) = (s16) (s32) (Cosf(angle) * 38.0f);
            *(s16 *) (p + 0x4) = 0;
            p[0x6] = 0xFF;
            p[0x7] = 0xFF;
            p[0x8] = 0xFF;
            p[0x9] = 0xFF;
            q = p + 0xA;
            *(s16 *) (q + 0x0) = (s16) (s32) (Sinf(angle) * radius);
            *(s16 *) (q + 0x2) = (s16) (s32) (Cosf(angle) * radius);
            *(s16 *) (q + 0x4) = 0;
            q[0x6] = 0xFF;
            q[0x7] = 0xFF;
            q[0x8] = 0xFF;
            q[0x9] = 0xFF;
            p += 0x14;
            if (k != 6) {
                angle = (s16) (angle - 0x1555);
            }
        }

        /* four 0x30-byte tables of 12 words, a byte flag, and two s16 timers */
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 12; j++) {
                D_overlay_6_00601B20[i * 12 + j] = 0x10000 + (j * 0x20000);
            }
            D_overlay_6_00601BF0[i] = 0xFF;
            D_overlay_6_00601BE0[i] = objTvTimes(0x384, NULL, 0); /* asm: a1/a2 not set here, passes stale regs */
            D_overlay_6_00601BE8[i] = 0x3C;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instInitHealthMeter.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instFreeHealthMeter(void) {
    if (insthealthmetervtxs != NULL) {
        mmFree(insthealthmetervtxs);
        insthealthmetervtxs = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instFreeHealthMeter.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instGetPos(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s16 *po;
    s16 *tbl;
    s16 *pair;
    s32 offX;
    s32 offY;
    s32 baseX;
    s32 baseY;
    s32 mode;

    mode = viGetVideoMode();
    po = playeroffsets + arg1 * 2;
    arg0 = arg0 * 2;
    if (numberOfPlayers == 2) {
        if ((mode & 1) || (frontGet2PlayerSplit(arg1) != 0)) {
            baseX = po[4];
            baseY = po[5];
            tbl = twoplayerwidecoordinates;
        } else {
            baseX = po[0];
            baseY = po[1];
            tbl = twoplayercoordinates;
        }
    } else {
        baseX = po[8];
        baseY = po[9];
        tbl = fourplayercoordinates;
    }
    viConvertXY(&baseX, &baseY);
    pair = tbl + arg0;
    offX = pair[0];
    offY = pair[1];
    viConvertXY(&offX, &offY);
    *arg2 = offX + baseX;
    *arg3 = offY + baseY;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instGetPos.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instSpriteToScreenCoord(s32 *arg0, s32 *arg1) {
    s32 width;
    s32 height;

    viGetCurrentSize(&width, &height);
    *arg0 += (u32)width >> 1;
    *arg1 = ((u32)height >> 1) - *arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instSpriteToScreenCoord.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instScreenToSpriteCoord(s32 *arg0, s32 *arg1) {
    s32 width;
    s32 height;

    viGetCurrentSize(&width, &height);
    *arg0 -= (u32)width >> 1;
    *arg1 = ((u32)height >> 1) - *arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instScreenToSpriteCoord.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instInitMsgQueues(void) {
    u8 *q = msgQueues;
    u8 *b10 = D_overlay_6_00601B10;
    s16 *b18 = D_overlay_6_00601B18;
    s16 *end = D_overlay_6_00601B18 + 4;

    do {
        _bzero(q, 0x50);
        b18++;
        *(s16 *)(q + 2) = -1;
        b10++;
        *(b10 - 1) = 0x4B;
        q += 0x50;
        *(b18 - 1) = 0;
    } while (b18 != end);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instInitMsgQueues.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *instGetBarY(void) {
    return D_overlay_6_00601B10;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instGetBarY.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *instGetBarWidth(void) {
    return D_overlay_6_00601B18;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instGetBarWidth.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instQueueMsg(s8 *arg0, s32 arg1) {
    u8 *q;
    s32 rd;
    s32 next;

    q = INST_MSGQ(*arg0);
    if (q[4] == 5) {
        rd = q[6];
        next = rd + 1;
        q[6] = next;
        if ((next & 0xFF) >= 5) {
            q[6] = 0;
        }
        q[4] = q[4] - 1;
    }
    *(s16 *)(q + 8 + q[5] * 2) = arg1;
    next = q[5] + 1;
    q[5] = next;
    if ((u8) next >= 5) {
        q[5] = 0;
    }
    q[4] = q[4] + 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instQueueMsg.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instLockMsg(s8 *arg0, s32 arg1) {
    u8 *q = INST_MSGQ(*arg0);

    q[7] = 1;
    *(s16 *)(q + 2) = arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instLockMsg.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instUnlockMsg(s8 *arg0) {
    u8 *q = INST_MSGQ(*arg0);

    q[7] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instUnlockMsg.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instMsgQueueTick(s8 *arg0, s32 arg1) {
    s32 idx = *arg0;
    u8 *q = INST_MSGQ(idx);
    u8 rd;

    if (*(s16 *)q != 0 || q[4] != 0 || q[7] != 0) {
        if (numberOfPlayers == 1) {
            if (INST_OBJ_AC < 122.0f) {
                INST_OBJ_AC = INST_OBJ_AC + (f32)(arg1 * 8);
                if (INST_OBJ_AC > 122.0f) {
                    INST_OBJ_AC = 122.0f;
                }
            }
        } else {
            if (D_overlay_6_00601B10[idx] >= 0x1F) {
                D_overlay_6_00601B10[idx] = D_overlay_6_00601B10[idx] - arg1 * 2;
                if (D_overlay_6_00601B10[idx] < 0x1E) {
                    D_overlay_6_00601B10[idx] = 0x1E;
                }
            } else {
                D_overlay_6_00601B18[idx] += arg1 * 4;
                if (D_overlay_6_00601B18[idx] >= 0x57) {
                    D_overlay_6_00601B18[idx] = 0x56;
                }
            }
        }
        if (q[7] == 0) {
            if (numberOfPlayers == 1 || D_overlay_6_00601B10[idx] == 0x1E) {
                *(s16 *)q -= arg1;
            }
            if (*(s16 *)q < 0) {
                if (q[4] == 0) {
                    *(s16 *)q = 0;
                } else {
                    rd = q[6];
                    *(s16 *)q += objTvTimes(0x78, q, idx);
                    q[6] = rd + 1;
                    q[0x4E] = 0;
                    *(s16 *)(q + 2) = *(s16 *)(q + 8 + rd * 2);
                    if ((u8)(rd + 1) >= 5) {
                        q[6] = 0;
                    }
                    q[4] = q[4] - 1;
                }
            }
        }
    } else if (numberOfPlayers == 1) {
        INST_OBJ_AC = INST_OBJ_AC - (f32)(arg1 * 8);
        if (INST_OBJ_AC < -78.0f) {
            INST_OBJ_AC = -78.0f;
        }
    } else {
        D_overlay_6_00601B18[idx] -= arg1 * 4;
        if (D_overlay_6_00601B18[idx] < 0) {
            D_overlay_6_00601B18[idx] = 0;
            D_overlay_6_00601B10[idx] += arg1 * 2;
            if (D_overlay_6_00601B10[idx] >= 0x4C) {
                D_overlay_6_00601B10[idx] = 0x4B;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/instMsgQueueTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetInstrumentsHide(s32 arg0) {
    hideinstruments = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/frontSetInstrumentsHide.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontGetTime(s32 arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    s32 total = arg0;
    s32 hours;
    s32 mins;
    s32 secs;
    s32 hourSecs;

    if (viFramesPerSecond == 50) {
        total = (s32)((f64)(f32)total * D_overlay_6_00601AF8);
    }
    hours = total / 3600;
    if (hours < 10) {
        sprintf((char *)arg1, &D_overlay_6_00601AC0, hours);
    } else {
        sprintf((char *)arg1, &D_overlay_6_00601AC4, hours);
    }
    hourSecs = hours * 3600;
    mins = (total - hourSecs) / 60;
    if (mins < 10) {
        sprintf((char *)arg2, &D_overlay_6_00601AC8, mins, mins);
    } else {
        sprintf((char *)arg2, &D_overlay_6_00601ACC, mins, mins);
    }
    secs = (((total - mins * 60) - hourSecs) * 100) / 60;
    if (secs < 10) {
        sprintf((char *)arg3, &D_overlay_6_00601AD0, secs, mins);
    } else {
        sprintf((char *)arg3, &D_overlay_6_00601AD4, secs, mins);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/frontGetTime.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontGetHourTime(s32 arg0, s8 *arg1, s8 *arg2, s8 *arg3, s8 *arg4) {
    s32 frames;
    s32 hours;
    s32 hoursMod;
    s32 mins;
    s32 cs;

    frames = arg0;
    if (viFramesPerSecond == 0x32) {
        frames = (s32) ((f64) (f32) frames * D_overlay_6_00601B00);
    }
    hours = frames / 3600;
    hoursMod = hours % 60;
    if (hoursMod < 0xA) {
        sprintf((char *) arg2, &D_overlay_6_00601AD8, hoursMod);
    } else {
        sprintf((char *) arg2, &D_overlay_6_00601ADC, hoursMod);
    }
    mins = (frames - (hours * 0xE10)) / 60;
    if (mins < 0xA) {
        sprintf((char *) arg3, &D_overlay_6_00601AE0, mins, mins);
    } else {
        sprintf((char *) arg3, &D_overlay_6_00601AE4, mins, mins);
    }
    cs = (((frames - (mins * 0x3C)) - (hours * 0xE10)) * 0x64) / 60;
    if (cs < 0xA) {
        sprintf((char *) arg4, &D_overlay_6_00601AE8, cs, mins);
    } else {
        sprintf((char *) arg4, &D_overlay_6_00601AEC, cs, mins);
    }
    sprintf((char *) arg1, &D_overlay_6_00601AF0, hours / 60);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o6/overlay_6/frontGetHourTime.s")
#endif
