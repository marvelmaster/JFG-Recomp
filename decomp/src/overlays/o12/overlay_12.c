#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct FrontTexSave {
    u8 *data;   /* 0x00 */
    s32 size;   /* 0x04 */
} FrontTexSave;

void freeFrontEndList(s16 *arg0);
void loadFrontEndList(s16 *arg0);
void amSndPlay(u16 soundID, void *handlePtr);
void amTuneSetFadeScaled(f32 scale, s32 time);
void mainPauseDisable(s32 n);
void mainChangeCameras(s32 arg0);
void mainTitlePageInit(void);
void mainSetPauseMode(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void rainSetDraw(s32 arg0);
void camSetNo(s32 arg0);
f32 camGetFOV(void);
void camSetFOV(f32 fov, s32 force);
void camSetView(Gfx **dlist, s32 arg1);
void camResetView(Gfx **dlist);
void camStandardPersp(Gfx **dlist, MatrixS **mtxp);
void instSpriteToScreenCoord(s32 *x, s32 *y);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
s32 texFrame(void *arg0, s32 arg1);
u8 *texGetTextureNum(s32 arg0);
void texFreeTexture(s32 arg0);
void texLoadTextureAddr(s32 arg0, s32 arg1);
void mmFlushFreeStack(void);
void runlinkSuspendCode(u8 arg0);
void mmFree(void *data);
void runlinkResumeAll(void);
void modResumeModelTextures(void);
void modSuspendModelTextures(void *arg0);
void objSetObjRegionOverflow(s8 arg0);
s32 levelGetType(void);
s32 frontGet2PlayerSplit();
void *trackGetTrack(void);
void func_overlay_12_00C01880_1F0AC28(void);
void func_overlay_12_00C008A8_1F09C50(void);
void func_overlay_12_00C009A4_1F09D4C();
void func_overlay_12_00C01018_1F0A3C0(void);
void func_overlay_12_00C01444_1F0A7EC(s32 arg0, s32 arg1, s16 arg2, s16 arg3);

extern s16 D_overlay_12_00C01B80;
extern u8 D_overlay_12_00C01B9C;
extern s32 D_overlay_12_00C01BA0;
extern f32 D_overlay_12_00C01BD0;
extern f32 D_overlay_12_00C01BD4;
extern f32 D_overlay_12_00C01BD8;
extern f32 D_overlay_12_00C01BDC;
extern s32 D_overlay_12_00C01BE0;   /* front menu flags */
extern s32 D_overlay_12_00C01BE4;
extern s32 D_overlay_12_00C01BE8;
extern s32 D_overlay_12_00C01BEC;
extern s32 D_overlay_12_00C01BF0;
extern s16 D_overlay_12_00C01BF4;
extern f32 D_overlay_12_00C01BF8;
extern s16 D_overlay_12_00C01C08;
extern u8 D_overlay_12_00C01C0A;
extern u8 D_overlay_12_00C01C0B;
extern u8 D_overlay_12_00C01C0C;
extern s8 D_overlay_12_00C01C0D;
extern u8 D_overlay_12_00C01C0E;
extern s32 D_overlay_12_00C01C10;
extern s32 D_overlay_12_00C01C14;
extern s32 D_overlay_12_00C01C18;
extern s32 D_overlay_12_00C01C1C;
extern s32 D_overlay_12_00C01C20;
extern s32 D_overlay_12_00C01C28;
extern s32 D_overlay_12_00C01C2C;
extern FrontTexSave *D_overlay_12_00C01C30;
extern u8 D_overlay_12_00C01B8C;
extern s16 D_overlay_12_00C01920;
extern s32 D_overlay_12_00C01B18;
extern s32 D_80C01B60;
extern s32 D_80C01B70;
extern s32 D_80C01998;
extern s32 D_80C01A38;
extern s32 D_80C01A58;
extern s32 D_80C01A98;
extern s32 D_80C01AB8;
extern s32 D_80C01AF8;
extern void *D_800FF4C8;
extern void *D_800FF4CC;
extern void *D_800FF4D0;
extern void *D_800FF4D4;
extern void *D_800FF4D8;
extern Gfx *frontgfx;
extern MatrixS *frontmtx;
extern Vtx *frontvtx;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitMenuFrame(void) {
    s32 *p;

    if (D_overlay_12_00C01B9C != 0) {
        freeFrontEndList(&D_overlay_12_00C01B80);
    }
    D_overlay_12_00C01B9C = 1;
    p = &D_overlay_12_00C01BE0;
    p[1] = 0xA;
    p[2] = 0;
    *(s16 *)((u8 *)p + 0x28) = 0;
    *((u8 *)p + 0x2B) = 0;
    *((u8 *)p + 0x2A) = 0;
    *((u8 *)p + 0x2C) = 1;
    *((u8 *)p + 0x2D) = 4;
    *(f32 *)((u8 *)p + 0x18) = 230.0f;
    loadFrontEndList(&D_overlay_12_00C01B80);
    D_overlay_12_00C01C28 = 1;
    D_overlay_12_00C01C14 = -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontInitMenuFrame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontFreeMenuFrame(void) {
    if (D_overlay_12_00C01B9C != 0) {
        if (D_overlay_12_00C01C0C == 0) {
            func_overlay_12_00C009A4_1F09D4C();
        }
        freeFrontEndList(&D_overlay_12_00C01B80);
    }
    D_overlay_12_00C01B9C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontFreeMenuFrame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetMenuFrame(s32 arg0, s32 arg1) {
    s32 *p = &D_overlay_12_00C01BE0;

    p[3] = arg0;
    p[4] = arg1;
    p[0] = p[0] | 5;
    *(u8 *)((u8 *)p + 0x2E) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontSetMenuFrame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontClearMenuFrame(s32 arg0) {
    s32 flags;

    amSndPlay(0x172, 0);
    flags = D_overlay_12_00C01BE0;
    D_overlay_12_00C01BE0 = (flags & ~1) | arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontClearMenuFrame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetMenuFrameFade(s32 arg0) {
    D_overlay_12_00C01C0D = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontSetMenuFrameFade.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMenuFrameSetEnable(s32 arg0) {
    D_overlay_12_00C01C28 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontMenuFrameSetEnable.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMenuFrameTick(s32 arg0) {
    f32 var_f2;
    s32 var_a3 = 0;
    s32 temp_lo;
    s32 temp_a2;
    s32 temp_lo_2;
    s32 temp_t3;
    s32 n;
    s32 rem;
    f32 f;
    f32 k;

    if (D_overlay_12_00C01C28 == 0) {
        return;
    }
    if (!(D_overlay_12_00C01BE0 & 4)) {
        return;
    }

    temp_lo = (s32)D_overlay_12_00C01C0D * arg0;
    temp_a2 = arg0 * 8;

    if (D_overlay_12_00C01BE0 & 1) {
        /* opening */
        s32 temp_v0 = D_overlay_12_00C01C08 + temp_a2;
        D_overlay_12_00C01C08 = (s16)temp_v0;
        if (temp_v0 >= 0xA1) {
            D_overlay_12_00C01C08 = 0xA0;
        }
        var_f2 = D_overlay_12_00C01BF8;
        if (var_f2 < 8.0f) {
            s16 var_v0 = D_overlay_12_00C01BF4;
            s16 var_v0_2;
            s32 temp_t2;
            s32 temp_t4;
            if (var_v0 > 0) {
                var_v0 -= 0x8000;
            }
            var_v0_2 = (s16)(var_v0 + (arg0 * 0x320));
            if (var_v0_2 > 0) {
                var_v0_2 = 0;
            }
            D_overlay_12_00C01BF4 = var_v0_2;
            if (var_v0_2 == 0) {
                if (D_overlay_12_00C01C0E == 0) {
                    amSndPlay(0x171, 0);
                    D_overlay_12_00C01C0E = 1;
                    var_f2 = D_overlay_12_00C01BF8;
                }
                var_a3 = 3;
            } else {
                var_a3 = 0;
            }
            if (D_overlay_12_00C01BF0 == D_overlay_12_00C01BE8) {
                temp_t2 = D_overlay_12_00C01BE4 + temp_a2;
                D_overlay_12_00C01BE4 = temp_t2;
                if (D_overlay_12_00C01BEC < temp_t2) {
                    temp_t4 = (D_overlay_12_00C01C0B + arg0) * 2;
                    if (temp_t4 >= 0x100) {
                        D_overlay_12_00C01C0B = 0xFF;
                    } else {
                        D_overlay_12_00C01C0B = (u8)temp_t4;
                    }
                    D_overlay_12_00C01BE4 = D_overlay_12_00C01BEC;
                }
            }
        } else {
            D_overlay_12_00C01BF4 += arg0 * 0x320;
            var_a3 = 0;
        }

        /* decay var_f2 toward 0 (BD0 for the first arg0&3 steps, BD4 for groups of 4) */
        if (arg0 > 0) {
            f = var_f2;
            n = 0;
            rem = arg0 & 3;
            while (n < rem) {
                n += 1;
                f -= f * D_overlay_12_00C01BD0;
            }
            k = D_overlay_12_00C01BD4;
            while (n != arg0) {
                n += 4;
                f = f - (f * k);
                f = f - (f * k);
                f = f - (f * k);
                f = f - (f * k);
            }
            D_overlay_12_00C01BF8 = f;
        }

        if (D_overlay_12_00C01BE8 > 0) {
            if (temp_lo > 0) {
                if ((s32)D_overlay_12_00C01C0A < (0xFF - temp_lo)) {
                    D_overlay_12_00C01C0A += temp_lo;
                } else {
                    D_overlay_12_00C01C0A = 0xFF;
                }
            } else if (-temp_lo < (s32)D_overlay_12_00C01C0A) {
                D_overlay_12_00C01C0A += temp_lo;
            } else {
                D_overlay_12_00C01C0A = 0;
            }
        }

        if ((D_overlay_12_00C01BEC == D_overlay_12_00C01BE4) && (D_overlay_12_00C01C0C != 0)) {
            func_overlay_12_00C008A8_1F09C50();
        }
    } else {
        /* closing */
        s32 var_a1;
        s32 var_t2;
        s32 temp_v0_2;
        s32 temp_v1;
        f32 temp_f16;

        if (D_overlay_12_00C01C0C == 0) {
            func_overlay_12_00C009A4_1F09D4C(D_overlay_12_00C01BE0, temp_a2);
            if (runlinkIsModuleLoaded(0x13) != 0) {
                runlinkFreeCode(0x13);
            }
            if (D_overlay_12_00C01C14 == 1) {
                if (runlinkIsModuleLoaded(5) != 0) {
                    rainSetDraw(1);
                }
                joyResetMap();
                mainPauseDisable(0x1E);
                mainChangeCameras(1);
                if (D_overlay_12_00C01C20 == 3) {
                    ((void (*)(s32 *))mainTitlePageInit)(&D_overlay_12_00C01C14); /* sig mismatch */
                } else {
                    mainChangeLevel(D_overlay_12_00C01C14, D_overlay_12_00C01C18, 0, D_overlay_12_00C01C20, 1, 0);
                }
            } else if (D_overlay_12_00C01C14 != -1) {
                if (runlinkIsModuleLoaded(5) != 0) {
                    rainSetDraw(1);
                }
                mainChangeCameras(1);
                if (D_overlay_12_00C01C20 == 3) {
                    ((void (*)(s32 *))mainTitlePageInit)(&D_overlay_12_00C01C14); /* sig mismatch */
                } else {
                    mainChangeLevel(D_overlay_12_00C01C14, D_overlay_12_00C01C18, D_overlay_12_00C01C1C, D_overlay_12_00C01C20, 1, 0);
                }
            }
        }

        var_a1 = D_overlay_12_00C01BE0;
        if (temp_a2 < D_overlay_12_00C01C08) {
            D_overlay_12_00C01C08 -= temp_a2;
        } else {
            D_overlay_12_00C01C08 = 0;
        }

        temp_v0_2 = arg0 * 0x10;
        if (temp_v0_2 < (s32)D_overlay_12_00C01C0B) {
            D_overlay_12_00C01BEC = 0xA;
            D_overlay_12_00C01C0B -= temp_v0_2;
            var_a3 = 0;
        } else {
            D_overlay_12_00C01C0B = 0;
            var_t2 = D_overlay_12_00C01BE4 - temp_a2;
            if (var_t2 < 0xA) {
                var_t2 = 0xA;
            }
            D_overlay_12_00C01BEC = 0xA;
            D_overlay_12_00C01BE4 = var_t2;
            var_a3 = 0;
            if ((0xA - var_t2) >= -4) {
                var_a3 = -3;
                D_overlay_12_00C01BF0 = 0;
            }
            if (D_overlay_12_00C01BE8 == 0) {
                D_overlay_12_00C01BF4 += arg0 * 0x320;
                if (arg0 > 0) {
                    f = D_overlay_12_00C01BF8;
                    n = 0;
                    rem = arg0 & 3;
                    while (n < rem) {
                        n += 1;
                        f += (230.0f - f) * D_overlay_12_00C01BD8;
                    }
                    k = D_overlay_12_00C01BDC;
                    while (n != arg0) {
                        n += 4;
                        f = f + ((230.0f - f) * k);
                        f = f + ((230.0f - f) * k);
                        f = f + ((230.0f - f) * k);
                        f = f + ((230.0f - f) * k);
                    }
                    D_overlay_12_00C01BF8 = f;
                }
            }

            temp_v1 = arg0 * 4;
            temp_f16 = 230.0f - D_overlay_12_00C01BF8;
            if (temp_v1 < (s32)D_overlay_12_00C01C0A) {
                D_overlay_12_00C01C0A -= temp_v1;
            } else {
                D_overlay_12_00C01C0A = 0;
            }
            if (temp_f16 < 3.0f) {
                if (var_a1 & 2) {
                    mainSetPauseMode(230.0f, 0, var_a1, temp_a2, var_a3);
                    amTuneSetFadeScaled(0.5f, 0x7F);
                    var_a1 = D_overlay_12_00C01BE0 & ~2;
                }
                D_overlay_12_00C01BE0 = var_a1 & ~4;
                if (runlinkIsModuleLoaded(5) != 0) {
                    rainSetDraw(1);
                }
            }
        }
    }

    temp_lo_2 = var_a3 * arg0;
    temp_t3 = D_overlay_12_00C01BE8 + (temp_lo_2 * arg0);
    D_overlay_12_00C01BE8 = temp_t3;
    if (((temp_lo_2 > 0) && (D_overlay_12_00C01BF0 < temp_t3)) ||
        ((temp_lo_2 < 0) && (D_overlay_12_00C01BE8 < D_overlay_12_00C01BF0))) {
        D_overlay_12_00C01BE8 = D_overlay_12_00C01BF0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontMenuFrameTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_12_00C008A8_1F09C50(void) {
    void *track;
    s16 count;
    FrontTexSave *saved;
    u8 *list;
    s32 i;

    track = trackGetTrack();
    count = *(s16 *)((u8 *)track + 0x18);
    list = *(u8 **)((u8 *)track + 0x00);
    D_overlay_12_00C01C2C = count;
    saved = (FrontTexSave *)mmAlloc(count * 8, -1U);
    D_overlay_12_00C01C30 = saved;
    for (i = 0; i < count; i++) {
        s32 texId = *(s32 *)(list + (i * 8));
        saved[i].data = texGetTextureNum(texId);
        saved[i].size = texId;
        texFreeTexture(texId);
    }
    modSuspendModelTextures(&D_overlay_12_00C01BA0);
    D_overlay_12_00C01C0C = 0;
    func_overlay_12_00C01880_1F0AC28();
    objSetObjRegionOverflow(1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/func_overlay_12_00C008A8_1F09C50.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_12_00C009A4_1F09D4C(void) {
    FrontTexSave *saved = D_overlay_12_00C01C30;
    s32 i;

    mmFlushFreeStack();
    runlinkResumeAll();
    for (i = 0; i < D_overlay_12_00C01C2C; i++) {
        texLoadTextureAddr((s32)saved[i].data, saved[i].size);
    }
    mmFree(D_overlay_12_00C01C30);
    modResumeModelTextures();
    D_overlay_12_00C01C0C = 1;
    objSetObjRegionOverflow(0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/func_overlay_12_00C009A4_1F09D4C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMenuFrameDraw(void) {
    f32 savedFov;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 halfX;
    s32 halfY;
    s32 tmp;
    u32 *temp_t1;
    s16 texH;

    if (D_overlay_12_00C01C28 == 0) {
        return;
    }
    if (!(D_overlay_12_00C01BE0 & 4)) {
        return;
    }

    camSetNo(0);
    savedFov = camGetFOV();
    camSetFOV(45.0f, 1);
    camSetView(&frontgfx, 0);
    camResetView(&frontgfx);
    camStandardPersp(&frontgfx, &frontmtx);
    D_overlay_12_00C01C10 = (s32)frontvtx;
    func_overlay_12_00C01018_1F0A3C0();

    func_overlay_12_00C01444_1F0A7EC((s32)D_overlay_12_00C01BF8, (s32)D_overlay_12_00C01BE8 >> 1, D_overlay_12_00C01BF4, 1);
    func_overlay_12_00C01444_1F0A7EC((s32)D_overlay_12_00C01BF8, (s32)D_overlay_12_00C01BE8 >> 1, (s16)(D_overlay_12_00C01BF4 + 0x8000), 1);
    func_overlay_12_00C01444_1F0A7EC((s32)D_overlay_12_00C01BF8, -((s32)D_overlay_12_00C01BE8 >> 1), D_overlay_12_00C01BF4, 0);
    func_overlay_12_00C01444_1F0A7EC((s32)D_overlay_12_00C01BF8, -((s32)D_overlay_12_00C01BE8 >> 1), (s16)(D_overlay_12_00C01BF4 + 0x8000), 0);

    halfX = (s32)D_overlay_12_00C01BE4 >> 1;
    halfY = (s32)D_overlay_12_00C01BE8 >> 1;
    x0 = -halfX;
    y0 = -halfY;
    y1 = halfY;
    x1 = halfX;
    instSpriteToScreenCoord(&x0, &y1);
    instSpriteToScreenCoord(&x1, &y0);
    y0 += 1;
    tmp = y1 - 1;
    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 >= 0x140) {
        x1 = 0x13F;
    }
    if (tmp < 0) {
        tmp = 0;
    }
    y1 = tmp;
    if (tmp >= 0xF0) {
        y1 = 0xEF;
    }

    if (D_overlay_12_00C01BE8 > 0) {
        if ((s32)D_overlay_12_00C01C0A > 0) {
            texDPTextureX(&frontgfx, 0, 0, 0);
            frontgfx->words.w0 = 0xFB000000;
            frontgfx->words.w1 = D_overlay_12_00C01C0A | 0x283200;
            frontgfx++;
            frontgfx->words.w0 = 0xFA000000;
            frontgfx->words.w1 = 0x51400;
            frontgfx++;
            frontgfx->words.w1 = (u32)&D_80C01B70;
            frontgfx->words.w0 = 0x07020010;
            frontgfx++;
            frontgfx->words.w0 = ((x1 & 0x3FF) << 0xE) | 0xF6000000 | ((y0 & 0x3FF) * 4);
            frontgfx->words.w1 = ((x0 & 0x3FF) << 0xE) | ((y1 & 0x3FF) * 4);
            frontgfx++;
        }

        if (D_overlay_12_00C01BE4 < 0x97) {
            y1 *= 4;
            x0 *= 4;
            x1 *= 4;
            y0 *= 4;

            frontgfx->words.w0 = 0xE7000000;
            frontgfx->words.w1 = 0;
            frontgfx++;
            frontgfx->words.w0 = 0xFA000000;
            frontgfx->words.w1 = ((0xFF - ((s32)(D_overlay_12_00C01BE4 * 0xFF) / 150)) & 0xFF) | ~0xFF;
            frontgfx++;
            frontgfx->words.w1 = (u32)&D_overlay_12_00C01B18;
            frontgfx->words.w0 = 0x06000000;
            frontgfx++;
            frontgfx->words.w1 = (u32)&D_80C01B60;
            frontgfx->words.w0 = 0x07020010;
            frontgfx++;

            /* texture frame DL: texture header at D_800FF4C8, word at +0xC is the DL source */
            temp_t1 = *(u32 **)((u8 *)D_800FF4C8 + 0xC);
            texH = *(s16 *)((u8 *)D_800FF4C8 + 0xA);
            frontgfx->words.w0 = *temp_t1;
            frontgfx->words.w1 = (u32)texFrame(D_800FF4C8, 0) + 0x80000000;
            frontgfx++;
            frontgfx->words.w1 = (u32)temp_t1 + 8 + 0x80000000;
            frontgfx->words.w0 = (((texH - 1) & 0xFF) << 0x10) | 0x07000000 | (((texH - 1) * 8) & 0xFFFF);
            frontgfx++;

            frontgfx->words.w0 = ((y0 & 0xFFF) << 0xC) | 0xE5000000 | (x1 & 0xFFF);
            frontgfx->words.w1 = ((x0 & 0xFFF) << 0xC) | (y1 & 0xFFF);
            frontgfx++;
            frontgfx->words.w0 = 0xB3000000;
            frontgfx->words.w1 = 0;
            frontgfx++;
            frontgfx->words.w0 = 0xB2000000;
            frontgfx->words.w1 = ((s32)((16.0f / (f32)D_overlay_12_00C01BE4) * 1024.0f) & 0xFFFF) | 0xFC000000;
            frontgfx++;
        }
    }

    texDPInit(&frontgfx);
    camSetFOV(savedFov, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontMenuFrameDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_12_00C01018_1F0A3C0(void) {
    s16 *src = &D_overlay_12_00C01920;
    s32 varT0;
    s32 varA1;
    s32 i;
    s32 n;
    s32 doScale = 0;
    s32 temp;
    u8 *vtx;

    varT0 = D_overlay_12_00C01BE4 - 0x58;
    if (varT0 < 0) {
        varT0 = 0;
        varA1 = 0;
    } else {
        varA1 = ((s32)D_overlay_12_00C01BE4 >> 1) - 0x2C;
    }

    D_overlay_12_00C01C10 = (s32)frontvtx;
    vtx = (u8 *)frontvtx;
    for (i = 0; i < 0x14; i++) {
        if (i == 0xA) {
            varA1 -= varT0;
        } else if (i == 0x10) {
            varA1 += varT0;
        } else if (i == 0x13) {
            varA1 -= varT0;
        }
        *(s16 *)(vtx + 0x0) = (s16)(src[0] - varA1);
        *(s16 *)(vtx + 0x2) = src[1];
        *(s16 *)(vtx + 0x4) = src[2];
        vtx[6] = 0xFF;
        vtx[7] = 0xFF;
        vtx[8] = 0xFF;
        vtx[9] = 0xFF;
        vtx += 0xA;
        src += 3;
    }

    if (viGetVideoMode() & 1) {
        temp = levelGetType();
        if ((temp != 1) && ((temp & 0xFF) != 2)) {
            doScale = 1;
        }
    } else if (camGetMode() == 1) {
        if (frontGet2PlayerSplit() != 0) {
            doScale = 1;
        }
    }

    if (doScale) {
        s16 t;
        vtx = (u8 *)D_overlay_12_00C01C10;
        n = 0;
        do {
            n += 4;
            t = *(s16 *)vtx;
            *(s16 *)vtx = (s16)(t + (t / 3));
            vtx += 0xA;
            t = *(s16 *)(vtx + 0xA);
            *(s16 *)(vtx + 0xA) = (s16)(t + (t / 3));
            vtx += 0xA;
            t = *(s16 *)(vtx + 0xA);
            *(s16 *)(vtx + 0xA) = (s16)(t + (t / 3));
            vtx += 0xA;
            t = *(s16 *)(vtx + 0xA);
            *(s16 *)(vtx + 0xA) = (s16)(t + (t / 3));
            vtx += 0xA;
        } while (n != 0x14);
    }
    frontvtx = (Vtx *)vtx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/func_overlay_12_00C01018_1F0A3C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_12_00C01444_1F0A7EC(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    ObjectTransform trans;
    s32 varS0 = arg1;
    s32 sp64 = 0;
    s32 temp;

    if (viGetVideoMode() & 1) {
        temp = levelGetType();
        if ((temp == 1) || ((temp & 0xFF) == 2)) {
            varS0 -= varS0 >> 2;
        }
    } else if (camGetMode() == 1) {
        if (frontGet2PlayerSplit() != 0) {
            varS0 += varS0 / 3;
        }
    }

    trans.y_rotation = arg2;
    trans.x_rotation = 0;
    trans.z_rotation = 0;
    trans.unk6 = 0;
    trans.scale = 1.0f;
    trans.x_position = (f32)arg0;
    trans.y_position = (f32)varS0;
    trans.z_position = 0.0f;

    if (D_overlay_12_00C01C0C != 0) {
        sp64 = 1;
    }
    if (arg3 != 0) {
        camPushModelMtx(&frontgfx, &frontmtx, &trans, 1.0f, 0.0f);
    } else {
        camPushModelMtx(&frontgfx, &frontmtx, &trans, -1.0f, 0.0f);
        frontgfx->words.w1 = 0x2000;
        frontgfx->words.w0 = 0xB6000000;
        frontgfx++;
        frontgfx->words.w1 = 0x1000;
        frontgfx->words.w0 = 0xB7000000;
        frontgfx++;
    }

    texDPInit(&frontgfx);
    frontgfx->words.w1 = -1U;
    frontgfx->words.w0 = 0xFA000000;
    frontgfx++;
    frontgfx->words.w0 = ((((((u32)D_overlay_12_00C01C10 + 0x80000000) & 6) | 0xA0) & 0xFF) << 0x10) | 0x04000000 | 0xD0;
    frontgfx->words.w1 = (u32)D_overlay_12_00C01C10 + 0x80000000;
    frontgfx++;

    texDPTextureX(&frontgfx, D_800FF4CC, sp64, 0);
    if (arg2 == 0) {
        frontgfx->words.w0 = 0x059100A0;
        frontgfx->words.w1 = (u32)&D_80C01998;
        frontgfx++;
    } else {
        frontgfx->words.w1 = (u32)&D_80C01998;
        frontgfx->words.w0 = 0x05710080;
        frontgfx++;
    }

    if (arg3 != 0) {
        texDPTextureX(&frontgfx, D_800FF4D4, sp64, 0);
        frontgfx->words.w0 = 0x05110020;
        frontgfx->words.w1 = (u32)&D_80C01A38;
        frontgfx++;
        texDPTextureX(&frontgfx, D_800FF4D0, sp64, 0);
        frontgfx->words.w0 = 0x05310040;
        frontgfx->words.w1 = (u32)&D_80C01A58;
        frontgfx++;
        texDPTextureX(&frontgfx, D_800FF4D8, sp64, 0);
        frontgfx->words.w0 = 0x05110020;
        frontgfx->words.w1 = (u32)&D_80C01A98;
        frontgfx++;
    } else {
        texDPTextureX(&frontgfx, D_800FF4D0, sp64, 0);
        frontgfx->words.w0 = 0x05310040;
        frontgfx->words.w1 = (u32)&D_80C01AB8;
        frontgfx++;
        texDPTextureX(&frontgfx, D_800FF4D8, sp64, 0);
        frontgfx->words.w0 = 0x05110020;
        frontgfx->words.w1 = (u32)&D_80C01AF8;
        frontgfx++;
    }

    if (arg3 == 0) {
        frontgfx->words.w1 = 0x1000;
        frontgfx->words.w0 = 0xB6000000;
        frontgfx++;
        frontgfx->words.w1 = 0x2000;
        frontgfx->words.w0 = 0xB7000000;
        frontgfx++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/func_overlay_12_00C01444_1F0A7EC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 frontGetMenuFrameAlpha(void) {
    return D_overlay_12_00C01C0A;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontGetMenuFrameAlpha.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetMenuFullyOpen(void) {
    s32 *p = &D_overlay_12_00C01BE0;
    s32 varV0;

    varV0 = (p[1] == p[3]) && (p[2] == p[4]);
    return varV0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontGetMenuFullyOpen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 frontMenuFrameTrackDrawingOn(void) {
    return D_overlay_12_00C01C0C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/frontMenuFrameTrackDrawingOn.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_12_00C01880_1F0AC28(void) {
    u8 *var_s0;
    u8 var_a0;
    s32 end;

    end = 0xFF;
    var_s0 = &D_overlay_12_00C01B8C;
    if (*var_s0 != end) {
        var_a0 = D_overlay_12_00C01B8C;
        do {
            if (runlinkIsModuleLoaded((s32)var_a0) != 0) {
                runlinkSuspendCode(*var_s0);
            }
            var_a0 = var_s0[1];
            var_s0 += 1;
        } while (var_a0 != end);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/func_overlay_12_00C01880_1F0AC28.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuFrameChangeLevel(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_overlay_12_00C01C14 = arg0;
    D_overlay_12_00C01C18 = arg1;
    D_overlay_12_00C01C1C = arg2;
    D_overlay_12_00C01C20 = arg3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o12/overlay_12/menuFrameChangeLevel.s")
#endif
