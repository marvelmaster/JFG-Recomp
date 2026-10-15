#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern u8 D_overlay_14_00E04440[];
extern u8 D_overlay_14_00E04460[];
extern s16 D_overlay_14_00E04894;
extern s16 D_overlay_14_00E04896;
extern s16 D_overlay_14_00E04898;
extern s32 D_overlay_14_00E04528;
extern s32 D_overlay_14_00E04890;
extern s32 D_overlay_14_00E0489C;
extern u8 D_80E044D8[];
extern u8 D_80E044E8[];
extern u8 D_80E04508[];
extern u8 D_80E04758[];
extern u8 D_80E041B0[];
extern u8 D_80E042A0[];
extern u8 D_80E04340[];
extern u8 D_80E04400[];
extern u8 D_80E03E70[];
extern u8 D_80E04168[];
extern u8 D_80E04190[];
extern u8 D_overlay_14_00E04630[];
extern u8 D_overlay_14_00E04644[];
extern u8 D_overlay_14_00E04678[];
extern u8 D_overlay_14_00E04798[];
extern u8 D_overlay_14_00E0452C[];
extern u8 D_overlay_14_00E047B0[];
extern u8 D_overlay_14_00E04830[];
extern u8 D_overlay_14_00E04838[];
extern u8 D_overlay_14_00E0483C[];
extern s32 D_800FF460;
extern s32 D_800FF464;
extern s16 D_800FF786;
extern f32 D_800FF788;
extern f32 D_800FF790;
extern f32 D_800FF79C;
extern f32 D_800FF80C;
extern f32 D_800FF810;
extern s16 D_800FF81C;
extern s32 D_800FF814;
extern u8 currentobjects[];
extern s32 frontendptrs[];
extern void *front_text;
extern Gfx *frontgfx;
extern s32 frontmtx;
extern void *frontvtx;
extern s32 objtrans;
extern u8 frB;
extern u8 frR;
extern u8 hideinstruments;
extern u8 gameInWindow;
extern s32 arcadeScreen;
void frontInitTarget(void);
void instInitHealthMeter(void);
void instInitMsgQueues(void);
void loadFrontEndList(void *arg0);
void setupFrontEndList(void *arg0);
void rcpSetBorderColour(s32 arg0, s32 arg1, s32 arg2);
void texDPTextureX(Gfx **dlist, s32 arg1, s32 arg2, s32 arg3);
void fxDrawLine(s16 x0, s16 y0, s16 x1, s16 y1, s32 colour);
void *fxDrawDigitalNumber(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void fxTinyPrint(s32 arg0, s32 arg1, void *text);
void fontPrintXY(Gfx **dlist, s32 xpos, s32 ypos, char *text, s32 alignment);
void fontColour(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void fontUseFont(s32 arg0);
void camStandardOrtho(Gfx **dlist, s32 *mtx);
void camCopyOrthoMatrix(void *mtx);
void matrixTranslate(f32 x, f32 y, f32 z, void *mtx);
void matrixScale(f32 x, f32 y, f32 z, void *mtx);
void mathMtxF2L(void *mtx, s32 dst);
void frontDrawObj(s32 arg0);
void viConvertXY(s32 *x, s32 *y);
void frontPlayerTarget(void *arg0, void *arg1, s32 arg2);
void instDrawHealth(void *arg0, s32 arg1, s16 arg2, s32 arg3);
void instMsgQueueTick(void *arg0, s32 arg1);
void instSpriteToScreenCoord(s32 *x, s32 *y);
void *mainGetGameCharacter(s8 arg0, s8 arg1);
s32 mainGetPauseMode(void);
void **objGetPlayerlist(s32 *count);
s16 objTvTimes(s32 arg0);
void amSndPlay(s32 soundId, s32 *handlePtr);
void amSndStop(s32 handle);
void loadFrontEndItem(s32 arg0);
void freeFrontEndItem(s32 arg0);
s32 camProjectPoint(f32 x, f32 y, f32 z, f32 *sx, f32 *sy, s32 arg5);
void func_overlay_14_00E010D8_1F0EA30(void);
void func_overlay_14_00E010F4_1F0EA4C(s32 arg0);
void func_overlay_14_00E0292C_1F10284(s32 arg0);
void func_overlay_14_00E02CF4_1F1064C(s32 arg0);
void func_overlay_14_00E019F4_1F0F34C(s32 arg0);
void func_overlay_14_00E03C68_1F115C0(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void *func_overlay_14_00E00220_1F0DB78(void *arg0, s32 arg1);
void func_overlay_14_00E00074_1F0D9CC(s16 *arg0, void *arg1, s32 arg2);
extern u8 D_overlay_14_00E04488[];
extern u8 D_overlay_14_00E0447C[];
extern s32 D_overlay_14_00E04820;
extern s32 D_overlay_14_00E04824;
extern s32 D_overlay_14_00E048A0;
extern s32 D_overlay_14_00E048A4;
extern s32 D_overlay_14_00E048A8;
extern s32 D_overlay_14_00E048AC;
extern s32 D_overlay_14_00E048B0;
extern u8 D_overlay_14_00E04814[];
extern char D_overlay_14_00E0484C[];
extern char D_overlay_14_00E04850[];
extern char D_overlay_14_00E04854[];
extern char D_overlay_14_00E04858[];
extern char D_overlay_14_00E0486C[];
extern char D_overlay_14_00E04870[];
extern char D_overlay_14_00E04878[];
extern char D_overlay_14_00E0487C[];
extern u8 D_800FF420[];
extern f32 D_800FF78C;
void fxDrawWindow(Gfx **dlist, s32 arg1, s32 x, s32 y, s32 w, s32 h, s32 alpha);
char *frontGetWorldName(s32 world);
void updateColourCycle(unkResetColourCycle *arg0, s32 arg1, s32 arg2); /* sig per asm (3 args) */
extern u8 *tribaltable;
void amTunePlay(u8 seqID);
void mainSaveGame(s8 arg0);
s32 mainGetGameFlag(s32 flag);
extern f32 D_800FF92C;
extern f32 D_800FF930;
extern f32 D_800FF938;
extern s32 D_overlay_14_00E04810;
extern s16 D_800FF7A6;
extern f32 D_800FF878;
extern f32 D_800FF8CC;
extern f32 D_800FF8D0;
s32 controlGetMaxCharge(u8 *base, s32 idx);
void frontDrawRectangles(Gfx **gfxp, s32 count, void *rects, s32 flag);
void frontPrintNum(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void instScreenToSpriteCoord(s32 *x, s32 *y);
void func_overlay_14_00E01984_1F0F2DC(void);
void func_overlay_14_00E01AD8_1F0F430(void *arg0, s32 arg1);
void func_overlay_14_00E03418_1F10D70(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern f32 D_800FF82C;
extern f32 D_800FF830;
extern f32 D_800FF834;
extern f32 D_800FF84C;
extern f32 D_800FF850;
extern s32 D_800FF46C;
extern u8 D_80E040B8[];
extern u8 D_80E04108[];
extern u8 D_80E04148[];
extern u8 D_80E03E80[];
extern u8 D_80E03F48[];
extern u8 D_80E03FA8[];
extern u8 D_80E04048[];
extern u8 D_80E04088[];
extern u8 D_overlay_14_00E040B8[];
extern s32 D_overlay_14_00E047F0[];
extern u8 D_overlay_14_00E04800[];
extern char D_overlay_14_00E04840[];
extern char D_overlay_14_00E04844[];
extern char D_overlay_14_00E04848[];
extern u8 msgQueues[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitInstruments(void) {
    frontInitTarget();
    rcpSetBorderColour(0, 0, 0);
    loadFrontEndList(D_overlay_14_00E04440);
    setupFrontEndList(D_overlay_14_00E04460);
    func_overlay_14_00E010D8_1F0EA30();
    instInitHealthMeter();
    instInitMsgQueues();
    D_overlay_14_00E04894 = 0;
    D_overlay_14_00E04896 = 0;
    D_overlay_14_00E04898 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/frontInitInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E00074_1F0D9CC(s16 *arg0, void *arg1, s32 arg2) {
    u8 *obj;
    u8 *addr;
    Gfx *gfx;
    s16 temp_t0;

    obj = (u8 *)arg1;
    D_overlay_14_00E04528 = D_overlay_14_00E04528 + arg2;
    if ((*(u32 *)(obj + 0x540) & 0xF) && (D_overlay_14_00E04528 & 0x10)) {
        temp_t0 = *arg0 - *(s16 *)(obj + 0x1CA);
        if (temp_t0 < -0xA00 || temp_t0 > 0xA00) {
            texDPInit(&frontgfx);
            texDPTextureX(&frontgfx, 0, 7, 0);
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w1 = -0x100;
            gfx->words.w0 = 0xFB000000;
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w1 = -0x80;
            gfx->words.w0 = 0xFA000000;
            if (temp_t0 < -0x800) {
                addr = D_80E044E8;
            } else {
                addr = D_80E04508;
            }
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w0 = (((((u32)addr & 6) | 0x18) & 0xFF) << 0x10) | 0x04000000 | 0x26;
            gfx->words.w1 = (u32)addr;
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w0 = 0x05000010;
            gfx->words.w1 = (u32)D_80E044D8;
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w1 = 0;
            gfx->words.w0 = 0xE7000000;
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w1 = -1;
            gfx->words.w0 = 0xFA000000;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E00074_1F0D9CC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_14_00E00220_1F0DB78(void *arg0, s32 arg1) {
    u8 *racer;
    u8 *entry;
    u8 *vtx;
    u8 *m50;
    u8 *v4c;
    Gfx *gfx;
    void *ret;
    f32 pt[3];
    f32 projX;
    f32 projY;
    f32 scl;
    s32 vpW;
    s32 vpH;
    s32 sx;
    s32 sy;
    s32 q;
    s32 i;
    s32 k;
    s32 tickTop;
    s32 scale;
    s32 tmp;
    s32 bearX;
    s32 n;
    s32 v0;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 vcount;
    s16 cx;
    s16 cy;
    s16 tx;
    s16 ty;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s16 val;
    u8 col;
    u8 a1b;
    u8 a2b;
    u8 a3b;

    racer = *(u8 **)((u8 *)arg0 + 0x68);
    cx = *(s16 *)(racer + 0x48);
    cy = *(s16 *)(racer + 0x4C);
    viGetCurrentSize(&vpW, &vpH);
    tx = ((u32)vpW >> 1) + cx;
    ty = ((u32)vpH >> 1) - cy;
    for (q = 0; q < 4; q++) {
        entry = D_overlay_14_00E04630;
        for (i = 0; i < 2; i++) {
            if (q & 1) {
                x0 = tx - *(s16 *)(entry + 0);
                x1 = tx - *(s16 *)(entry + 4);
            } else {
                x0 = tx + *(s16 *)(entry + 0);
                x1 = tx + *(s16 *)(entry + 4);
            }
            if (q & 2) {
                y0 = ty - *(s16 *)(entry + 2);
                y1 = ty - *(s16 *)(entry + 6);
            } else {
                y0 = ty + *(s16 *)(entry + 2);
                y1 = ty + *(s16 *)(entry + 6);
            }
            fxDrawLine(x0, y0, x1, y1, entry[8]);
            entry += 0xA;
        }
    }
    ret = NULL;
    if (arg1 != 0) {
        entry = D_overlay_14_00E0452C;
        for (k = 0; k < 0x1A; k++) {
            fxDrawLine(*(s16 *)(entry + 0), *(s16 *)(entry + 2), *(s16 *)(entry + 4), *(s16 *)(entry + 6), entry[8]);
            entry += 0xA;
        }
        sy = 0xC0;
        sx = 0x110;
        viConvertXY(&sx, &sy);
        entry = D_overlay_14_00E04678;
        for (k = 0; k < 0x16; k++) {
            fxDrawLine((s16)(*(s16 *)(entry + 0) + sx), (s16)(*(s16 *)(entry + 2) + sy),
                       (s16)(*(s16 *)(entry + 4) + sx), (s16)(*(s16 *)(entry + 6) + sy), entry[8]);
            entry += 0xA;
        }
        fxDrawLine(0x34, 0x1E, 0x10C, 0x1E, 0);
        tickTop = 0x18;
        bearX = 0x34;
        for (k = 0; k < 0x25; k++) {
            if (k == 0 || k == 0x12 || k == 0x24) {
                tickTop = 0x18;
            } else if (k == 9 || k == 0x1B) {
                tickTop = 0x1A;
            }
            fxDrawLine(bearX, tickTop, bearX, 0x1D, 0);
            bearX += 6;
        }
        fxTinyPrint(0x2D, 0x11, D_overlay_14_00E04830);
        fxTinyPrint(0x9F, 0x11, D_overlay_14_00E04838);
        fxTinyPrint(0x108, 0x11, D_overlay_14_00E0483C);
        tmp = (*(s32 *)arg0 * 0x6C) >> 0xF;
        sx = 0xA0 - tmp;
        fxDrawLine((s16)sx, 0x1F, (s16)sx, 0x24, 0);
        *(f32 *)(currentobjects + 0x18C) = 114.0f;
        *(f32 *)(currentobjects + 0x190) = -72.0f;
        *(s16 *)(currentobjects + 0x184) = (s16)-(*(s32 *)((u8 *)arg0 + 4) * 2);
        frB = 0;
        frR = 0;
        objtrans = 0xA0;
        frontDrawObj(0xC);
        frB = 0xFF;
        frR = 0xFF;
        objtrans = 0xFF;
        val = *(s16 *)(racer + 0x1C);
        k = 0;
        if (val < 0x64) {
            if (val & 4) {
                k = 1;
            }
        }
        ret = fxDrawDigitalNumber(0x20, 0xC0, val, 4, k);
    } else {
        texDPInit(&frontgfx);
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w1 = -1;
        gfx->words.w0 = 0xFA000000;
        texDPTextureX(&frontgfx, 0, 0x15, 0);
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = (((((s32)((u32)frontvtx + 0x80000000) & 6) | 0x60) & 0xFF) << 0x10) | 0x04000000 | 0x80;
        gfx->words.w1 = (u32)frontvtx + 0x80000000;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w1 = (u32)D_80E04758;
        gfx->words.w0 = 0x05300040;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w1 = 0;
        gfx->words.w0 = 0xE7000000;
        a0 = 0x40;
        if (*(void **)(racer + 0x50) != NULL) {
            col = racer[0x5D];
            if (col != 0) {
                a0 = 0xFF;
                a1 = 0x20;
                a2 = 0x10;
                a3 = 0xC0;
                t0 = -0xBF;
                t1 = 0xDF;
                t2 = 0x10;
                t3 = -0x40;
                scale = (s32)(col << 0x10) / 20;
            } else {
                a0 = 0x40;
                a1 = 0xFF;
                a2 = 0x20;
                a3 = 0x80;
                t0 = 0xBF;
                t1 = -0xDF;
                t2 = -0x10;
                t3 = 0x40;
                scale = (s32)(racer[0x5E] << 0x10) / 90;
            }
            a0 = ((s32)(t0 * scale) >> 0x10) + a0;
            a1b = (u8)(((s32)(t1 * scale) >> 0x10) + a1);
            a2b = (u8)(((s32)(t2 * scale) >> 0x10) + a2);
            a3b = (u8)(((s32)(t3 * scale) >> 0x10) + a3);
        } else {
            a1b = 0xFF;
            a2b = 0x20;
            a3b = 0x80;
        }
        vtx = (u8 *)frontvtx;
        vcount = 0;
        do {
            entry = D_overlay_14_00E04798 + (vcount * 2);
            vcount += 1;
            *(s16 *)(vtx + 0) = (s16)((s8)entry[0] + cx);
            *(s16 *)(vtx + 2) = (s16)((s8)entry[1] + cy);
            *(s16 *)(vtx + 4) = 0;
            vtx[6] = (u8)a0;
            vtx[7] = a1b;
            vtx[8] = a2b;
            vtx[9] = a3b;
            vtx += 0xA;
        } while (vcount < 0xC);
        frontvtx = vtx;
        n = 0;
        if (*(u32 *)(racer + 0x94) & 0x40000000) {
            entry = D_overlay_14_00E04644;
            do {
                col = entry[8];
                v0 = 0;
                if ((col & 0xF) == 0xD) {
                    v0 = -1;
                }
                fxDrawLine((s16)(tx + *(s16 *)(entry + 0)), (s16)(ty + *(s16 *)(entry + 2)),
                           (s16)(tx + *(s16 *)(entry + 4)), (s16)(ty + *(s16 *)(entry + 6)), col);
                fxDrawLine((s16)((tx - *(s16 *)(entry + 0)) + v0), (s16)(ty + *(s16 *)(entry + 2)),
                           (s16)((tx - *(s16 *)(entry + 4)) + v0), (s16)(ty + *(s16 *)(entry + 6)), col);
                n += 1;
                entry += 0xA;
            } while (n != 5);
        }
        m50 = *(u8 **)(racer + 0x50);
        if (m50 != NULL && *(s32 *)(racer + 0x54) != 0) {
            v4c = *(u8 **)(m50 + 0x4C);
            scl = *(f32 *)(m50 + 8);
            pt[0] = (f32)*(s16 *)(v4c + 0) * scl;
            pt[1] = (f32)*(s16 *)(v4c + 2) * scl;
            pt[2] = (f32)*(s16 *)(v4c + 4) * scl;
            pointListRPY(1, (s16 *)m50, (s32 *)pt, pt);
            pt[0] = pt[0] + *(f32 *)(m50 + 0xC);
            pt[1] = pt[1] + *(f32 *)(m50 + 0x10);
            pt[2] = pt[2] + *(f32 *)(m50 + 0x14);
            if (camProjectPoint(pt[0], pt[1], pt[2], &projX, &projY, 1)) {
                sx = (s32)projX;
                sy = (s32)projY;
                entry = D_overlay_14_00E047B0;
                scale = 0x21 - *(s32 *)(racer + 0x5C);
                for (k = 0xF; k != 0; k--) {
                    fxDrawLine((s16)(((s8)entry[0] * scale) + sx), (s16)(((s8)entry[1] * scale) + sy),
                               (s16)(((s8)entry[2] * scale) + sx), (s16)(((s8)entry[3] * scale) + sy), 0x10);
                    entry += 4;
                }
            }
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E00220_1F0DB78.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSingleInstruments(void *arg0, s32 arg1) {
    u8 *racer;
    u8 *chr;
    u8 *temp_a0;
    s32 sp68[16];
    s32 sp64;
    s32 sp60;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_f4;
    Gfx *gfx;
    u8 v2;
    s16 temp_v1;

    if (D_overlay_14_00E04896 != 0) {
        func_overlay_14_00E02CF4_1F1064C(arg1);
    } else if (arg0 != NULL) {
        if (mainGetPauseMode() == 0) {
            if (hideinstruments == 0 && gameInWindow == 0 && arcadeScreen == 0) {
                racer = *(u8 **)((u8 *)arg0 + 0x68);
                if (racer[0x568] == 5 || racer[0x568] == 0xB || *(s32 *)(racer + 0xFC) != 0) {
                    frontPlayerTarget(arg0, racer, arg1);
                }
                camStandardOrtho(&frontgfx, &frontmtx);
                temp_a0 = *(u8 **)(racer + 0x50C);
                if (temp_a0 != NULL) {
                    v2 = racer[0x10D];
                    if (v2 == 1 || (*(u32 *)(*(u8 **)(temp_a0 + 0x68) + 0x94) >> 0x1F) != 0) {
                        func_overlay_14_00E00220_1F0DB78(temp_a0, v2 & 1);
                    }
                }
                if (racer[0x10D] == 0 && racer[0x1F9] == 0) {
                    if (racer[0x568] != 5) {
                        func_overlay_14_00E00074_1F0D9CC(arg0, racer, arg1);
                    }
                    func_overlay_14_00E010F4_1F0EA4C(arg1);
                    func_overlay_14_00E0292C_1F10284(arg1);
                    temp_v1 = *(s16 *)(racer + 0x592);
                    if (temp_v1 > 0) {
                        *(s16 *)(racer + 0x592) = (s16)(temp_v1 - arg1);
                        D_overlay_14_00E04898 += arg1 * 2;
                        if (D_overlay_14_00E04898 >= 0x100) {
                            D_overlay_14_00E04898 = 0xFF;
                        }
                    }
                    if (D_overlay_14_00E04898 > 0) {
                        if (*(s16 *)(racer + 0x592) <= 0) {
                            D_overlay_14_00E04898 -= arg1 * 2;
                            if (D_overlay_14_00E04898 < 0) {
                                D_overlay_14_00E04898 = 0;
                            }
                        }
                        texDPInit(&frontgfx);
                        camCopyOrthoMatrix(sp68);
                        matrixTranslate(-50.0f, -80.0f, 0.0f, sp68);
                        mathMtxF2L(sp68, frontmtx);
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0x01000040;
                        gfx->words.w1 = frontmtx + 0x80000000;
                        frontmtx += 0x40;
                        texDPTextureX(&frontgfx, D_800FF460, 0, 0);
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = (D_overlay_14_00E04898 & 0xFF) | ~0xFF;
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = 0xFF;
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = (((((u32)D_80E041B0 & 6) | 0xC0) & 0xFF) << 0x10) | 0x04000000 | 0xF8;
                        gfx->words.w1 = (u32)D_80E041B0;
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w1 = (u32)D_80E042A0;
                        gfx->words.w0 = 0x059100A0;
                        texDPTextureX(&frontgfx, D_800FF464, 0, 0);
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0x05B100C0;
                        gfx->words.w1 = (u32)D_80E04340;
                        texDPInit(&frontgfx);
                        texDPTextureX(&frontgfx, 0, 4, 0);
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = (((s32)(D_overlay_14_00E04898 * 0x60) >> 8) & 0xFF) | 0x283200;
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w1 = (u32)D_80E04400;
                        gfx->words.w0 = 0x05310040;
                        gfx = frontgfx;
                        frontgfx = gfx + 1;
                        gfx->words.w1 = 0;
                        gfx->words.w0 = 0xE7000000;
                        texDPInit(&frontgfx);
                        func_overlay_14_00E03C68_1F115C0((s16)*(s32 *)(racer + 0x58C), 0xE10, -0x2D, -0x56, 0x42, -0x5C,
                                                         D_overlay_14_00E04898);
                        camStandardOrtho(&frontgfx, &frontmtx);
                        fontUseFont(2);
                        fontColour(0, 0xFF, 0xFF, 0xFF, D_overlay_14_00E04898);
                        sp64 = -0x32;
                        sp60 = -0x50;
                        instSpriteToScreenCoord(&sp64, &sp60);
                        temp_a1 = sp64 + 5;
                        temp_a2 = sp60 - 0xA;
                        sp64 = temp_a1;
                        sp60 = temp_a2;
                        fontPrintXY(&frontgfx, temp_a1, temp_a2, (char *)*(s32 *)((u8 *)front_text + 0x724), 0);
                        temp_f4 = (s32)(((f32)*(s32 *)(racer + 0x58C) * 100.0f) / 3600.0f);
                        fxDrawDigitalNumber(sp64 + 0x80, sp60 + 9, temp_f4, 3, temp_f4 < 0xA);
                    }
                    sprSetTextureFilter(0);
                    chr = mainGetGameCharacter(racer[0], racer[1]);
                    instDrawHealth(arg0, (*(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6)) >> 8, *(s16 *)(chr + 2), arg1);
                    sprSetTextureFilter(1);
                    instMsgQueueTick(racer, arg1);
                    func_overlay_14_00E019F4_1F0F34C(arg1);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/frontSingleInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E010D8_1F0EA30(void) {
    D_overlay_14_00E0489C = 0;
    D_overlay_14_00E04890 = 0;
    hideinstruments = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E010D8_1F0EA30.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E010F4_1F0EA4C(s32 arg0) {
    s32 count;
    void **plist;
    u8 *racer;
    u8 *chr;
    u32 bits;
    s32 varT6;
    s16 tv;
    f32 f;

    plist = objGetPlayerlist(&count);
    if (count > 0) {
        racer = *(u8 **)((u8 *)plist[0] + 0x68);
        chr = mainGetGameCharacter(racer[0], racer[1]);
        bits = (*(u32 *)(racer + 0x540) * 4) >> 0x1E;
        varT6 = bits & 2;
        if (bits & 1) {
            tv = objTvTimes(0xF0);
            D_800FF79C -= 27.0f;
            D_800FF81C = tv;
            if (D_overlay_14_00E04890 != 0) {
                amSndStop(D_overlay_14_00E04890);
            }
            amSndPlay(0x8B, &D_overlay_14_00E04890);
            varT6 = ((*(u32 *)(racer + 0x540) * 4) >> 0x1E) & 2;
        }
        if (varT6 != 0) {
            tv = objTvTimes(0xF0);
            D_800FF79C += 27.0f;
            D_800FF81C = tv;
            if (D_overlay_14_00E04890 != 0) {
                amSndStop(D_overlay_14_00E04890);
            }
            amSndPlay(0x8B, &D_overlay_14_00E04890);
        }
        D_800FF79C *= 0.875f;
        if (D_800FF81C != 0) {
            f = D_800FF810;
            if (f > -30.0f) {
                f -= (f32)(arg0 * 4);
            }
            D_800FF810 = f;
            if (f < -30.0f) {
                D_800FF810 = -30.0f;
            }
            tv = (s16)(D_800FF81C - arg0);
            D_800FF81C = tv;
            if (tv < 0) {
                D_800FF81C = 0;
            }
        } else if (D_800FF810 < 46.0f) {
            f = D_800FF810 + (f32)(arg0 * 4);
            D_800FF810 = f;
            if (f > 46.0f) {
                D_800FF810 = 46.0f;
            }
        }
        D_overlay_14_00E0489C = (s32)*(u8 *)(chr + 0x70);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E010F4_1F0EA4C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E01328_1F0EC80(s32 arg0) {
    s32 nPlayers;
    void **plist;
    u8 *racer;
    u8 *chr;
    f32 scale;
    s32 sp84[16];
    s16 sp70[16];
    s16 sp64[16];
    Gfx *gfx;
    f32 varF0;
    f32 varF02;
    s32 mask;
    s32 bit;
    s32 cnt;
    s32 idx;
    s32 temp8;
    s32 k;
    s8 sIdx;
    u8 temp_v1;
    s16 slot;

    plist = objGetPlayerlist(&nPlayers);
    if (nPlayers != 1) {
        return;
    }
    if (D_800FF810 >= 46.0f) {
        return;
    }
    racer = *(u8 **)((u8 *)plist[0] + 0x68);
    chr = mainGetGameCharacter(racer[0], racer[1]);
    scale = 46.0f - D_800FF810;
    camCopyOrthoMatrix(sp84);
    matrixTranslate(-121.0f, D_800FF810 + 2.0f, (f32)D_800FF814, sp84);
    matrixScale(1.0f, scale, 1.0f, sp84);
    mathMtxF2L(sp84, frontmtx);
    texDPInit(&frontgfx);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = -1;
    gfx->words.w0 = 0xFA000000;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0xFF;
    gfx->words.w0 = 0xFB000000;
    texDPTextureX(&frontgfx, 0, 0, 0);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFB000000;
    gfx->words.w1 = 0x283260;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0x1E5A00;
    gfx->words.w0 = 0xFA000000;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = (u32)D_80E03E70;
    gfx->words.w0 = 0x07020010;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x01000040;
    gfx->words.w1 = frontmtx + 0x80000000;
    gfx = frontgfx;
    frontmtx += 0x40;
    frontgfx = gfx + 1;
    gfx->words.w0 = (((((u32)D_80E04168 & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30;
    gfx->words.w1 = (u32)D_80E04168;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = (u32)D_80E04190;
    gfx->words.w0 = 0x05110020;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0;
    gfx->words.w0 = 0xE7000000;
    camStandardOrtho(&frontgfx, &frontmtx);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    cnt = 0;
    gfx->words.w0 = (((s32)(((D_800FF80C + 160.0f) - 16.0f) * 4.0f) & 0xFFF) << 0xC) | 0xED000000 | 0x120;
    gfx->words.w1 = (((s32)((D_800FF80C + 160.0f + 16.0f) * 4.0f) & 0xFFF) << 0xC)
                  | ((s32)((120.0f - D_800FF810) * 4.0f) & 0xFFF);
    temp_v1 = *(u8 *)(chr + 0x70);
    temp8 = (s32)((*(f32 *)(currentobjects + 0x90) + 30.0f) + (*(f32 *)(currentobjects + 0x1C) + 12.0f));
    varF0 = (f32)temp8;
    mask = (1 << temp_v1) & 0xFFFF;
    sIdx = (s8)temp_v1;
    if (varF0 > -46.0f) {
        do {
            bit = 1 << sIdx;
            if (*(u16 *)(chr + 0xA) & bit) {
                sp70[cnt] = (s16)varF0;
                mask = (mask | bit) & 0xFFFF;
                sp64[cnt] = (s16)sIdx;
                cnt += 1;
                varF0 -= 27.0f;
            }
            sIdx -= 1;
            if (sIdx == 0) {
                sIdx = 0xF;
            }
        } while (varF0 > -46.0f);
    }
    slot = (s16)(*(u8 *)(chr + 0x70) + 1);
    if (slot >= 0xF) {
        slot = 0;
    }
    varF02 = (f32)(temp8 + 0x1B);
    if (varF02 < 62.0f) {
        do {
            bit = 1 << slot;
            if (*(u16 *)(chr + 0xA) & bit) {
                sp70[cnt] = (s16)varF02;
                mask = (mask | bit) & 0xFFFF;
                sp64[cnt] = slot;
                cnt += 1;
                varF02 += 27.0f;
            }
            slot += 1;
            if (slot == 0xF) {
                slot = 0;
            }
        } while (varF02 < 62.0f);
    }
    for (idx = 0; idx < 0x10; idx++) {
        if (mask & (1 << idx)) {
            if (frontendptrs[idx + 0xA] == 0) {
                loadFrontEndItem(idx + 0xA);
            }
        } else if (frontendptrs[idx + 0xA] != 0) {
            freeFrontEndItem(idx + 0xA);
        }
    }
    D_800FF788 = 1.0f;
    sprSetTextureFilter(0);
    objtrans = 0xFF;
    k = 0;
    if (cnt > 0) {
        do {
            D_800FF790 = (f32)sp70[k];
            D_800FF786 = sp64[k] + 0xA;
            frontDrawObj(0);
            D_800FF788 = 0.75f;
            objtrans = 0xA0;
            sprSetTextureFilter(1);
            k += 1;
        } while (k != cnt);
        objtrans = 0xFF;
    }
    sprSetTextureFilter(0);
    camSetScissor(&frontgfx);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E01328_1F0EC80.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E01984_1F0F2DC(void) {
    s32 i;

    for (i = 0; i != 0x10; i++) {
        if (frontendptrs[i + 0xA] != 0) {
            freeFrontEndItem(i + 0xA);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E01984_1F0F2DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void instShowBearBar(void) {
    D_overlay_14_00E04894 = 0xF0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/instShowBearBar.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E019F4_1F0F34C(s32 arg0) {
    if (D_overlay_14_00E04894 != 0) {
        if (*(f32 *)(currentobjects + 0xCC) < 69.0f) {
            *(f32 *)(currentobjects + 0xCC) = *(f32 *)(currentobjects + 0xCC) + (f32)(arg0 * 8);
            if (*(f32 *)(currentobjects + 0xCC) > 69.0f) {
                *(f32 *)(currentobjects + 0xCC) = 69.0f;
            }
        }
        D_overlay_14_00E04894 -= arg0;
        if (D_overlay_14_00E04894 < 0) {
            D_overlay_14_00E04894 = 0;
        }
    } else if (*(f32 *)(currentobjects + 0xCC) > -91.0f) {
        *(f32 *)(currentobjects + 0xCC) = *(f32 *)(currentobjects + 0xCC) - (f32)(arg0 * 8);
        if (*(f32 *)(currentobjects + 0xCC) < -91.0f) {
            *(f32 *)(currentobjects + 0xCC) = -91.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E019F4_1F0F34C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E01AD8_1F0F430(void *arg0, s32 arg1) {
    Game *spD8;
    f32 sp120[16];
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    char *spF8;
    char spDC[0x1C];
    s32 spEC;
    s32 spE8;
    s32 spY;
    u8 *sp3C;
    u8 *sp38;
    u8 *sp34;
    Gfx *gfx;
    f32 temp_f0;
    s32 temp_f16;
    s32 var_v0;
    u8 *var_v1;
    s32 *var_a0;
    u8 *vtx;
    u8 temp_t7;

    spD8 = mainGetGame();
    sp11C = D_800FF82C - -78.0f;
    camCopyOrthoMatrix(sp120);
    matrixTranslate(-82.0f, D_800FF830, D_800FF834, sp120);
    matrixScale(sp11C, 1.0f, 1.0f, sp120);
    mathMtxF2L(sp120, frontmtx);
    texDPInit(&frontgfx);

    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0xFFFFFFFF;
    gfx->words.w0 = 0xFA000000;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFB000000;
    gfx->words.w1 = 0xFF;
    texDPTextureX(&frontgfx, D_800FF464, 0, 0);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x01000040;
    gfx->words.w1 = (u32)frontmtx + 0x80000000;
    frontmtx += 0x40;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = ((((((s32)D_80E040B8 & 6) | 0x40) & 0xFF) << 0x10) | 0x04000000) | 0x58;
    gfx->words.w1 = (u32)D_80E040B8;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x05310040;
    gfx->words.w1 = (u32)D_80E04108;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0;
    gfx->words.w0 = 0xE7000000;
    sp3C = D_80E04108;
    texDPTextureX(&frontgfx, 0, 0, 0);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFB000000;
    gfx->words.w1 = 0x283260;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = 0x1E5A00;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x07020010;
    sp38 = D_80E03E70;
    gfx->words.w1 = (u32)D_80E03E70;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x05110020;
    sp34 = D_80E04148;
    gfx->words.w1 = (u32)D_80E04148;

    if (D_800FF82C > -78.0f) {
        gfx = frontgfx;
        frontgfx = gfx + 1;
        spF8 = (char *)*(s32 *)((u8 *)front_text + *(s16 *)(msgQueues + *(s8 *)arg0 * 0x50 + 2) * 4);
        gfx->words.w1 = 0;
        gfx->words.w0 = 0xE7000000;
        fontUseFont(2);
        gfx = frontgfx;
        frontgfx = gfx + 1;
        sp118 = (D_800FF82C - 122.0f) + 90.0f;
        sp114 = 120.0f - D_800FF830;
        gfx->words.w0 = ((s32)((120.0f - (D_800FF830 + 8.0f)) * 4.0f) & 0xFFF) | 0xED148000;
        gfx->words.w1 = (((s32)((D_800FF82C + 160.0f) * 4.0f) & 0xFFF) << 0xC) | ((s32)((120.0f - (D_800FF830 - 8.0f)) * 4.0f) & 0xFFF);
        fontColour(0, 0, 0, 0xFF, 0xFF);
        fontPrintXY(&frontgfx, (s32)sp118, (s32)sp114, spF8, 8);
        fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
        fontPrintXY(&frontgfx, (s32)(sp118 + 1.0f), (s32)(sp114 + 1.0f), spF8, 8);
        camSetScissor(&frontgfx);
    }

    var_v0 = 0;
    if (D_800FF84C > -91.0f) {
        var_v0 = 1;
    }
    if (var_v0 != 0) {
        camCopyOrthoMatrix(sp120);
        sp11C = *(f32 *)(currentobjects + 0xCC) - -91.0f;
        matrixTranslate(-91.0f, *(f32 *)(currentobjects + 0xD0), *(f32 *)(currentobjects + 0xD4), sp120);
        mathMtxF2L(sp120, frontmtx);
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w1 = 0xFFFFFFFF;
        gfx->words.w0 = 0xFA000000;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = 0xFF;
        texDPTextureX(&frontgfx, D_800FF464, 0, 0);
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0x01000040;
        gfx->words.w1 = (u32)frontmtx + 0x80000000;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = ((((((u32)frontvtx + 0x80000000) & 6) | 0x40) & 0xFF) << 0x10) | 0x04000000 | 0x58;
        var_v1 = D_overlay_14_00E040B8;
        var_a0 = D_overlay_14_00E047F0;
        gfx->words.w1 = (u32)frontvtx + 0x80000000;
        frontmtx += 0x40;
        vtx = (u8 *)frontvtx;
        do {
            if ((u32)var_a0 < (u32)&D_overlay_14_00E04800) {
                *(s16 *)vtx = (s16)*var_a0;
            } else {
                *(s16 *)vtx = (s16)(s32)((f32)*var_a0 + sp11C);
            }
            var_a0++;
            *(s16 *)(vtx + 2) = *(s16 *)(var_v1 + 2);
            *(s16 *)(vtx + 4) = *(s16 *)(var_v1 + 4);
            temp_t7 = var_v1[6];
            var_v1 += 0xA;
            vtx[6] = temp_t7;
            vtx[7] = var_v1[-3];
            vtx[8] = var_v1[-2];
            vtx[9] = var_v1[-1];
            vtx += 0xA;
        } while ((u32)var_a0 < (u32)&D_overlay_14_00E04810);
        frontvtx = vtx;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        spEC = (s32)((D_800FF84C - 5.0f) + 160.0f);
        gfx->words.w0 = 0x05310040;
        gfx->words.w1 = (u32)sp3C;
        gfx = frontgfx;
        spE8 = (s32)((120.0f - D_800FF850) - 8.0f);
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xE7000000;
        gfx->words.w1 = 0;
        texDPTextureX(&frontgfx, 0, 0, 0);
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = 0x283260;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xFA000000;
        gfx->words.w1 = 0x1E5A00;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0x07020010;
        gfx->words.w1 = (u32)sp38;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0x05110020;
        gfx->words.w1 = (u32)sp34;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = (((s32)((f32)0x45 * 4.0f) & 0xFFF) << 0xC) | 0xED000000 | ((s32)((f32)spE8 * 4.0f) & 0xFFF);
        gfx->words.w1 = (((s32)((f32)spEC * 4.0f) & 0xFFF) << 0xC) | ((s32)((f32)(spE8 + 0x11) * 4.0f) & 0xFFF);
        camStandardOrtho(&frontgfx, &frontmtx);
        temp_f0 = (*(f32 *)(currentobjects + 0xCC) - -91.0f) + -251.0f + 20.0f;
        *(f32 *)(currentobjects + 0x1AC) = temp_f0;
        *(f32 *)(currentobjects + 0x1B0) = 62.0f;
        temp_f16 = (s32)(temp_f0 + 180.0f);
        *(f32 *)(currentobjects + 0x1B8) = 1.0f;
        frontDrawObj(0xD);
        D_800FF92C += 48.0f;
        D_800FF938 = 2.0f;
        frontDrawObj(0xD);
        D_800FF92C += 48.0f;
        D_800FF938 = 0.0f;
        frontDrawObj(0xD);
        fontUseFont(2);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        fontBackground(0, 0, 0, 0);
        sprintf(spDC, D_overlay_14_00E04840, spD8->pad[4]);
        spY = (s32)(117.0f - 62.0f);
        fontPrintXY(&frontgfx, temp_f16, spY, spDC, 0);
        sprintf(spDC, D_overlay_14_00E04844, spD8->pad[5]);
        fontPrintXY(&frontgfx, temp_f16 + 0x30, spY, spDC, 0);
        sprintf(spDC, D_overlay_14_00E04848, spD8->pad[6]);
        fontPrintXY(&frontgfx, temp_f16 + 0x30 + 0x30, spY, spDC, 0);
        objtrans = 0xFF;
        camSetScissor(&frontgfx);
    }
    camCopyOrthoMatrix(sp120);
    matrixTranslate(-141.0f, 107.0f, 0.0f, sp120);
    mathMtxF2L(sp120, frontmtx);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x01000040;
    gfx->words.w1 = (u32)frontmtx + 0x80000000;
    frontmtx += 0x40;
    texDPTextureX(&frontgfx, D_800FF460, 0, 0);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0xFFFFFFFF;
    gfx->words.w0 = 0xFA000000;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFB000000;
    gfx->words.w1 = 0xFF;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = ((((((s32)D_80E03E80 & 6) | 0xA0) & 0xFF) << 0x10) | 0x04000000) | 0xD0;
    gfx->words.w1 = (u32)D_80E03E80;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = (u32)D_80E03F48;
    gfx->words.w0 = 0x05510060;
    texDPTextureX(&frontgfx, D_800FF464, 0, 0);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x059100A0;
    gfx->words.w1 = (u32)D_80E03FA8;
    texDPTextureX(&frontgfx, D_800FF46C, 0, 0);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x05310040;
    gfx->words.w1 = (u32)D_80E04048;
    texDPTextureX(&frontgfx, 0, 0, 0);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0;
    gfx->words.w0 = 0xE7000000;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFB000000;
    gfx->words.w1 = 0x283260;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = 0x1E5A00;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x07020010;
    gfx->words.w1 = (u32)sp38;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = (u32)D_80E04088;
    gfx->words.w0 = 0x05200030;
    func_overlay_14_00E01328_1F0EC80(arg1);
    camStandardOrtho(&frontgfx, &frontmtx);
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0;
    gfx->words.w0 = 0xE7000000;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w1 = 0xFF;
    gfx->words.w0 = 0xFB000000;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = 0xFFFFFFFF;
    sprSetTextureFilter(1);
    frontDrawObj(4);
    frontDrawObj(5);
    frontDrawObj(6);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E01AD8_1F0F430.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E0292C_1F10284(s32 arg0) {
    s32 count;
    u8 *player;
    u8 *chr;
    u8 slot;
    u8 kind;
    u8 level;
    s32 colour;
    s32 maxCharge;
    s32 hi;
    s32 lo;
    s32 i;
    u8 *entry;
    f32 scale;
    s32 t1;
    s32 a0;
    s32 a1;

    player = *(u8 **)((u8 *)*objGetPlayerlist(&count) + 0x68);
    chr = mainGetGameCharacter((s8) player[0], (s8) player[1]);
    kind = chr[0x70];
    slot = kind + 0xA;
    if (D_overlay_14_00E04810 != kind) {
        D_overlay_14_00E04810 = kind;
        if (kind != 0xFB) {
            freeFrontEndItem(slot);
        }
    }
    D_800FF7A6 = slot;
    func_overlay_14_00E01AD8_1F0F430(player, arg0);
    if (frontendptrs[slot] == 0) {
        loadFrontEndItem(slot);
    }
    sprSetTextureFilter(0);
    frontDrawObj(1);

    kind = chr[0x70];
    t1 = 0xFF;
    if (kind == 0) {
        level = player[0x542];
    } else if (kind == 3 || kind == 6 || kind == 4) {
        s16 cur;

        maxCharge = controlGetMaxCharge(chr, kind);
        cur = *(s16 *)(player + 0x53E);
        if (chr[0x70] == 3) {
            maxCharge = maxCharge - 0x20;
            cur -= 0x20;
        }
        t1 = 0xFF;
        level = (u8) (0xFC - ((s32) (cur * 0xFC) / maxCharge));
    } else {
        t1 = 0x55;
    }

    entry = D_overlay_14_00E04488;
    for (i = 0; i < 5; i++) {
        if (level >= 0x2A) {
            a0 = 0xFF;
            a1 = 0;
            level -= 0x2A;
        } else {
            lo = level * 6;
            level = 0;
            a0 = lo;
            a1 = 0xFF - a0;
        }
        *(s32 *)(entry + 8) = (a0 << 0x18) | (a1 << 0x10) | t1;
        entry += 0xC;
    }
    frontDrawRectangles(&frontgfx, 7, D_overlay_14_00E0447C, 0);

    if (D_800FF810 < 46.0f) {
        scale = D_800FF878 - (D_800FF878 * 0.125f);
    } else {
        scale = D_800FF878 + ((1.0f - D_800FF878) * 0.125f);
    }
    D_800FF878 = scale;
    frontDrawObj(7);
    sprSetTextureFilter(1);

    colour = *(u16 *)(chr + chr[0x70] * 2 + 0x14);
    frontPrintNum(colour, (s32) *(f32 *)(currentobjects + 0x12C), (s32) *(f32 *)(currentobjects + 0x130), 8, 3, 0xFFFF00A0, 0xFFFF0040);
    colour = *(u16 *)(chr + chr[0x70] * 2 + 0x34);
    frontPrintNum(colour, (s32) D_800FF8CC, (s32) D_800FF8D0, 9, 3, -0x60, -0xC0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E0292C_1F10284.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupInstruments(void) {
    freeFrontEndList(D_overlay_14_00E04440);
    func_overlay_14_00E01984_1F0F2DC();
    instFreeHealthMeter();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/frontCleanupInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E02CF4_1F1064C(s32 arg0) {
    char buf[32];
    Game *game;
    s32 old;
    s32 t;
    f32 secs;
    f32 rem;
    f32 rem2;
    s32 h;
    s32 m;
    s32 s;

    game = mainGetGame();
    old = D_overlay_14_00E04820;
    if (D_overlay_14_00E04820 < 0x12C) {
        D_overlay_14_00E04820 += arg0;
    }
    if (old == 0 ||
        (old < 0x1E && D_overlay_14_00E04820 >= 0x1E) ||
        (old < 0x3C && D_overlay_14_00E04820 >= 0x3C && D_overlay_14_00E048A0 != -1) ||
        (old < 0x5A && D_overlay_14_00E04820 >= 0x5A && D_overlay_14_00E048A4 != -1) ||
        (old < 0x78 && D_overlay_14_00E04820 >= 0x78 && D_overlay_14_00E048A8 != -1) ||
        (old < 0x96 && D_overlay_14_00E04820 >= 0x96)) {
        amSndPlay(0x190, NULL);
    }
    frontDrawRectangles(&frontgfx, 1, D_overlay_14_00E04814, 0);
    fontUseFont(2);
    fontBackground(0, 0, 0, 0);
    fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
    fontPrintXY(&frontgfx, 0xA0, 0x21, (char *)*(s32 *)((u8 *)front_text + 0x7F4), 0xC);
    camStandardOrtho(&frontgfx, &frontmtx);
    sprSetTextureFilter(0);
    t = D_overlay_14_00E04824 - arg0;
    D_overlay_14_00E04824 = t;
    if (t < 0) {
        D_overlay_14_00E04824 = t + 0x5A;
    }
    if (D_overlay_14_00E04820 >= 0x1E) {
        fontPrintXY(&frontgfx, 0x19, 0x32, (char *)*(s32 *)((u8 *)front_text + 0x60C), 0);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        fontPrintXY(&frontgfx, 0x55, 0x46, (char *)*(s32 *)((u8 *)front_text + 0x7E4), 0);
        fontPrintXY(&frontgfx, 0x55, 0x5A, (char *)*(s32 *)((u8 *)front_text + 0x7E8), 0);
        fontPrintXY(&frontgfx, 0x55, 0x6E, (char *)*(s32 *)((u8 *)front_text + 0x7EC), 0);
        sprintf(buf, D_overlay_14_00E0484C, game->pad[4]);
        fontPrintXY(&frontgfx, 0x4E, 0x46, buf, 1);
        sprintf(buf, D_overlay_14_00E04850, game->pad[5]);
        fontPrintXY(&frontgfx, 0x4E, 0x5A, buf, 1);
        sprintf(buf, D_overlay_14_00E04854, game->pad[6]);
        fontPrintXY(&frontgfx, 0x4E, 0x6E, buf, 1);
        if (D_overlay_14_00E048AC != 0) {
            if (D_overlay_14_00E04824 >= 0x1F) {
                fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
                fontPrintXY(&frontgfx, 0x4E, 0x50, (char *)*(s32 *)((u8 *)front_text + 0x7F0), 0);
            }
        }
        h = 0x2D;
        m = 0x48;
        instScreenToSpriteCoord(&h, &m);
        D_800FF92C = (f32) h;
        D_800FF930 = (f32) m;
        D_800FF938 = 1.0f;
        frontDrawObj(0xD);
        D_800FF930 -= 20.0f;
        D_800FF938 = 2.0f;
        frontDrawObj(0xD);
        D_800FF930 -= 20.0f;
        D_800FF938 = 0.0f;
        frontDrawObj(0xD);
    }
    if (D_overlay_14_00E04820 >= 0x3C && D_overlay_14_00E048A0 != -1) {
        func_overlay_14_00E03418_1F10D70(0, D_overlay_14_00E048A0, 0x8C, 0x32);
    }
    if (D_overlay_14_00E04820 >= 0x5A && D_overlay_14_00E048A4 != -1) {
        func_overlay_14_00E03418_1F10D70(1, D_overlay_14_00E048A4, 0x8C, 0x6E);
    }
    if (D_overlay_14_00E04820 >= 0x78 && D_overlay_14_00E048A8 != -1) {
        func_overlay_14_00E03418_1F10D70(2, D_overlay_14_00E048A8, 0x8C, 0xAA);
    }
    if (D_overlay_14_00E04820 >= 0x96) {
        f32 total;
        u32 raw;

        fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
        fontPrintXY(&frontgfx, 0x19, 0x82, (char *)*(s32 *)((u8 *)front_text + 0x7F8), 0);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        raw = *(u32 *)((u8 *)game + 0x514);
        total = (f32) raw;
        secs = total / 60.0f;
        h = (s32) secs / 3600;
        rem = secs - ((f32) h * 3600.0f);
        m = (s32) rem / 60;
        rem2 = rem - ((f32) m * 60.0f);
        s = (s32) rem2;
        sprintf(buf, D_overlay_14_00E04858, h, m, s, (s32) ((rem2 - (f32) s) * 100.0f));
        fontPrintXY(&frontgfx, 0x19, 0x96, buf, 0);
        if (D_overlay_14_00E048B0 != 0 && D_overlay_14_00E04824 >= 0x1F) {
            fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, 0x19, 0x8C, (char *)*(s32 *)((u8 *)front_text + 0x7F0), 0);
        }
    }
    sprSetTextureFilter(1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E02CF4_1F1064C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E03418_1F10D70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char buf[32];
    Game *game;
    f32 savedX;
    f32 savedY;
    f32 pct;
    s32 sx;
    s32 sy;
    s32 labelX;
    s32 off;
    u32 total;

    game = mainGetGame();
    fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
    fontPrintXY(&frontgfx, arg2, arg3, *(char **)((u8 *)front_text + arg0 * 4 + 0x72C), 0);
    fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    switch (arg0) {
    case 0:
        labelX = arg2 + 0x28;
        fontPrintXY(&frontgfx, labelX, arg3 + 0x1E, *(char **)((u8 *)front_text + 0x538), 0);
        sprintf(buf, D_overlay_14_00E0486C, *(u16 *)((u8 *)game + arg1 * 2 + 0x4F4));
        fontPrintXY(&frontgfx, arg2 + 0x8C, arg3 + 0x1E, buf, 1);
        off = arg1 * 4;
        break;
    case 1:
        labelX = arg2 + 0x28;
        fontPrintXY(&frontgfx, labelX, arg3 + 0x1E, *(char **)((u8 *)front_text + 0x2C8), 0);
        off = arg1 * 4;
        total = *(u32 *)((u8 *)game + off + 0x474);
        if (total == 0) {
            pct = 0.0f;
        } else {
            pct = ((f32) *(s32 *)((u8 *)game + off + 0x4B4) / (f32) total) * 100.0f;
        }
        sprintf(buf, D_overlay_14_00E04870, &pct);
        fontPrintXY(&frontgfx, arg2 + 0x8C, arg3 + 0x1E, buf, 1);
        break;
    case 2:
        labelX = arg2 + 0x28;
        fontPrintXY(&frontgfx, labelX, arg3 + 0x1E, *(char **)((u8 *)front_text + 0x738), 0);
        off = arg1 * 4;
        sprintf(buf, D_overlay_14_00E04878, *(u32 *)((u8 *)game + off + 0x474));
        fontPrintXY(&frontgfx, arg2 + 0x8C, arg3 + 0x1E, buf, 1);
        break;
    default:
        off = arg1 * 4;
        labelX = arg2 + 0x28;
        break;
    }
    fontPrintXY(&frontgfx, labelX, arg3 + 0xD, *(char **)((u8 *)front_text + off + 0xE4), 0);
    if (*(s32 *)(D_800FF420 + off) == 0) {
        loadFrontEndItem(arg1 + 0xA);
    }
    *(f32 *)(currentobjects + 0x8) = 1.0f;
    objtrans = 0xFF;
    sx = arg2 + 0x12;
    sy = arg3 + 0x18;
    savedX = *(f32 *)(currentobjects + 0xC);
    savedY = *(f32 *)(currentobjects + 0x10);
    instScreenToSpriteCoord(&sx, &sy);
    D_800FF78C = (f32) sx;
    D_800FF790 = (f32) sy;
    D_800FF786 = arg1 + 0xA;
    frontDrawObj(0);
    D_800FF78C = savedX;
    D_800FF790 = savedY;
    objtrans = 0xFF;
    sprSetTextureFilter(0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E03418_1F10D70.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontShowRegionStats(void) {
    Game *game;
    u8 *lvl;
    u8 *stats;
    u8 *cell;
    s8 *tb;
    u32 total;
    u32 bestTotal;
    u32 hits;
    u32 raw;
    f32 ratio;
    f32 maxRatio;
    s32 bestPad;
    s32 sum;
    s32 i;
    s32 v0;
    s32 v1;
    s32 k;
    u16 pad4f4;
    u8 pad4;
    s32 changed;

    game = mainGetGame();
    lvl = (u8 *) levelGetLevel();
    D_overlay_14_00E04896 = 1;
    maxRatio = 0.0f;
    bestTotal = 0;
    bestPad = 0;
    D_overlay_14_00E048A0 = -1;
    D_overlay_14_00E048A4 = -1;
    D_overlay_14_00E048A8 = -1;
    sum = 0;
    for (i = 0; i < 0x10; i++) {
        total = *(u32 *)((u8 *) game + 0x474 + i * 4);
        if (bestTotal < total) {
            bestTotal = total;
            D_overlay_14_00E048A8 = i;
        }
        hits = *(u32 *)((u8 *) game + 0x4B4 + i * 4);
        if (hits != 0) {
            ratio = (f32) hits / (f32) total;
            if (maxRatio < ratio) {
                maxRatio = ratio;
                D_overlay_14_00E048A4 = i;
            }
        }
        pad4f4 = *(u16 *)((u8 *) game + 0x4F4 + i * 2);
        if (bestPad < (s32) pad4f4) {
            bestPad = pad4f4;
            D_overlay_14_00E048A0 = i;
        }
        sum += pad4f4;
    }

    changed = 0;
    stats = (u8 *) game + lvl[0x102] * 8 + 0x334;
    if ((s32) *(u16 *)(stats + 2) < sum) {
        *(s16 *)(stats + 2) = sum;
        changed = 1;
    }
    D_overlay_14_00E048AC = 0;
    D_overlay_14_00E048B0 = 0;
    pad4 = game->pad[4];
    if ((s32) stats[0] < (s32) pad4) {
        stats[0] = pad4;
        changed = 1;
        stats[1] = game->pad[5];
        *(u32 *)(stats + 4) = *(u32 *)((u8 *) game + 0x514);
        D_overlay_14_00E048AC = 1;

        v0 = (s8) tribaltable[0] + (s8) tribaltable[1] + (s8) tribaltable[2];
        v1 = game->pad[0x334] + game->pad[0x33C] + game->pad[0x344];
        tb = (s8 *) tribaltable + 3;
        cell = (u8 *) game + 0x18;
        for (k = 3; k != 0x1F; k += 4) {
            v0 += tb[0] + tb[1] + tb[2] + tb[3];
            v1 += cell[0x334] + cell[0x33C] + cell[0x344] + cell[0x34C];
            tb += 4;
            cell += 0x20;
        }
        if (v0 == v1) {
            if (mainGetGameFlag(0x58) == 0) {
                mainSetGameFlag(0x58, 1);
            }
        }
    } else {
        raw = *(u32 *)((u8 *) game + 0x514);
        if (raw < *(u32 *)(stats + 4) && (s32) game->pad[4] >= (s32) stats[0]) {
            *(u32 *)(stats + 4) = raw;
            D_overlay_14_00E048B0 = 1;
            changed = 1;
        }
    }
    if (changed != 0) {
        amTunePlay(0x2A);
        mainSaveGame((s8) game->pad[3]);
        return;
    }
    amTunePlay(0x2A);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/frontShowRegionStats.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontDisplayRegion(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char buf[32];
    char *name;
    s32 width;
    s32 w2;

    name = *(char **)((u8 *)front_text + arg1 * 4 + 0x65C);
    width = fontStringWidth(name, 2, 1) + 0x28;
    sprintf(buf, D_overlay_14_00E0487C, arg3, *(s32 *)((u8 *)front_text + 0x728));
    w2 = fontStringWidth(buf, 2, 1) + 0x28;
    if (width < w2) {
        width = w2;
    }
    fxDrawWindow(arg0, 0, 0xA0 - (width >> 1), 0x33, width, 0x2E, (s32) (arg4 * 0xA4) >> 8);
    fontUseFont(2);
    fontBackground(0, 0, 0, 0);
    fontColour(0, 0xC0, 0xC0, 0xFF, arg4);
    fontPrintXY(arg0, 0x9F, 0x3D, name, 0xC);
    fontPrintXY(arg0, 0x9F, 0x4A, frontGetWorldName(arg2), 0xC);
    fontColour(0xC0, 0xC0, 0xC0, 0xFF, arg4);
    fontPrintXY(arg0, 0x9F, 0x57, buf, 0xC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/frontDisplayRegion.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_14_00E03C68_1F115C0(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    unkResetColourCycle cc;
    /* asm: stack rect table (12-byte records, sized from the 0x380 frame) */
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        s32 unk8;
    } rects[64];
    s32 count;
    s32 width;
    s16 x;
    s16 left;
    s32 alpha;

    count = 0;
    if (arg1 != 0) {
        instSpriteToScreenCoord(&arg2, &arg3);
        instSpriteToScreenCoord(&arg4, &arg5);
        width = arg4 - arg2;
        x = arg2 + 4;
        if (x < arg4) {
            do {
                left = x - 2;
                if (x < (((width * ((s32) (arg0 << 0x10) / arg1)) >> 0x10) + arg2)) {
                    alpha = 0xFF;
                } else {
                    alpha = 0x30;
                }
                initColourCycle(&cc, 0x3B);
                updateColourCycle(&cc, (s32) (objTvTimes(0x3C) * (left - arg2)) / width, arg2);
                rects[count].unk0 = left;
                rects[count].unk4 = x;
                rects[count].unk2 = arg3;
                x += 4;
                rects[count].unk6 = arg5;
                rects[count].unk8 = (cc.unk8 << 0x18) | (cc.unk9 << 0x10) | (cc.unkA << 8) | ((s32) (alpha * arg6) >> 8);
                count += 1;
            } while (x < arg4);
        }
        frontDrawRectangles(&frontgfx, count, rects, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o14/overlay_14/func_overlay_14_00E03C68_1F115C0.s")
#endif
