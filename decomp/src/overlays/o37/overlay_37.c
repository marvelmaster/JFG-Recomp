#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void loadFrontEndList(void *list);
void setupFrontEndList(void *list);
void freeFrontEndList(void *list);
void updateColourCycle(unkResetColourCycle *arg0, s32 arg1);
void camStandardOrtho(void **arg0, void **arg1);
void frontDrawObj(s32 arg0);
void instScreenToSpriteCoord(s32 *arg0, s32 *arg1);
void instSpriteToScreenCoord(s32 *arg0, s32 *arg1);
s32 objTvTimes(s32 timer);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
extern u8 D_overlay_37_02501EE0[];
extern u8 D_overlay_37_02501EEC[];
extern u8 D_overlay_37_02501EF4[];
extern f32 D_overlay_37_02501FC0;
extern s32 D_overlay_37_02501FF0[4];
extern s32 D_overlay_37_02502000[2];
extern s32 D_overlay_37_02502008[4];
extern s32 D_overlay_37_02502018[2];
extern s32 D_overlay_37_02502020;
extern s16 D_overlay_37_02502028;
extern s16 D_overlay_37_0250202A;
extern f32 D_overlay_37_0250202C;
extern s32 D_overlay_37_02502030;
extern s32 D_overlay_37_02502034;
extern s32 D_overlay_37_02502038;
extern s32 D_overlay_37_0250203C;
extern s32 D_overlay_37_02502040;
extern s32 D_overlay_37_02502044;
extern s32 D_overlay_37_02502048;
extern f32 D_overlay_37_0250204C;
extern f32 D_overlay_37_02502050;
extern u8 D_overlay_37_02501F4C[];
extern s32 barcolours[];
extern f32 D_800FFCD0;
extern u8 D_82501EC0[];
extern u8 *front_text;
extern s8 frontJoyDxRepeat[4];
extern Gfx *frontgfx;
extern MatrixS *frontmtx;
extern s8 D_overlay_37_02501F08[];
extern s8 D_overlay_37_02501F10[];
extern s8 D_overlay_37_02501F18[];
extern s8 D_overlay_37_02501F1C[];
extern s8 D_overlay_37_02501F20[];
extern s8 D_overlay_37_02501F28[];
extern char *D_overlay_37_02501ED0[];
extern char D_overlay_37_02501F00[];
extern char D_overlay_37_02501F04[];
extern s32 D_overlay_37_02501F34;
extern s16 D_overlay_37_02501F38;
extern s16 D_overlay_37_02501F3C;
extern s32 D_overlay_37_02501F54[];
extern s32 D_overlay_37_02502024;
extern u8 D_82501EB0[];
extern u8 bugHeadCheats;
extern u8 rainbowblood;
extern u8 deformedchars;
extern u8 antsasmrpants;
extern s32 numberOfJoypads;
extern s32 viNoZbufferRealloc;
extern u8 currentobjects[];
extern void *D_800FF5EC;
extern s8 frontJoyDx[4];
extern s8 frontJoyDy[4];
extern s32 frontJoyPressed[4];
extern s32 frontJoyHeld[4];
s32 frontGetScreenMode(void);
void frontSetScreenMode(s32 arg0);
s32 frontGetWideAdjust(void);
void frontSetWideAdjust(s32 arg0);
s32 frontGetStereoMode(void);
void frontSetStereoMode(s32 arg0);
s32 frontGetSfxVolume(void);
void frontSetSfxVolume(s32 arg0);
s32 frontGetBgmVolume(void);
void frontSetBgmVolume(s32 arg0);
s32 frontGet2PlayerSplit(void);
void frontSet2PlayerSplit(s32 arg0);
s32 frontGetTargetControl(s32 arg0);
void frontSetTargetControl(s32 arg0, s32 arg1);
void amSndPlay(s32 sndId, s32 arg1, s32 arg2, s32 arg3);
void fontUseFont(s32 font);
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void fontPrintXY(Gfx **displayList, s32 xpos, s32 ypos, char *text, s32 alignmentFlags);
void rcpClearScreen(Gfx **dlist, void **mtxp, s32 arg2);
void camSetNo(s32 arg0);
void camOverrideProjScales(f32 arg0, f32 arg1);
void camSetFOV(f32 fov, s32 force);
void camSetView(Gfx **dlist, s32 arg1);
void camStandardPersp(void **arg0, void **arg1, s32 arg2); /* asm passes 3 args */
void objAnimDframe(void *obj, s32 arg1, f32 arg2, s32 arg3); /* asm: 4-arg call */
void pauseClearScreen(void);
void pauseSetScreen(s32 arg0);
void pauseSetNewLevel(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void mainTitlePageInit(void);
void mainSaveGlobalFlags(void);
void mainSaveGame(s8 arg0);
void viNoClear(void);
void viChangeMode(s32 arg0);
f32 Sinf(s16 angle);
s32 func_overlay_37_02501ACC_1F57D9C(s32 arg0, s32 arg1, s32 arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitOptionsPage(s32 arg0) {
    loadFrontEndList(D_overlay_37_02501EE0);
    setupFrontEndList(D_overlay_37_02501EF4);
    if (arg0 == 0) {
        loadFrontEndList(D_overlay_37_02501EEC);
    }
    D_overlay_37_0250204C = D_overlay_37_02501FC0;
    D_overlay_37_02502030 = 0;
    D_overlay_37_02502044 = 1;
    D_overlay_37_02502040 = 0;
    D_overlay_37_02502034 = -1;
    D_overlay_37_02502028 = 0x36;
    D_overlay_37_0250202C = 7.0f;
    D_overlay_37_02502038 = 0;
    D_overlay_37_02501FF0[0] = *(s32 *) (front_text + 0x0);
    D_overlay_37_02501FF0[1] = *(s32 *) (front_text + 0x4);
    D_overlay_37_02501FF0[2] = *(s32 *) (front_text + 0x8);
    D_overlay_37_02501FF0[3] = *(s32 *) (front_text + 0xC);
    D_overlay_37_02502000[0] = *(s32 *) (front_text + 0x4BC);
    D_overlay_37_02502000[1] = *(s32 *) (front_text + 0x4C0);
    D_overlay_37_02502008[0] = *(s32 *) (front_text + 0x264);
    D_overlay_37_02502008[1] = *(s32 *) (front_text + 0x268);
    D_overlay_37_02502008[2] = *(s32 *) (front_text + 0x264);
    D_overlay_37_02502008[3] = *(s32 *) (front_text + 0x268);
    D_overlay_37_02502018[0] = *(s32 *) (front_text + 0x274);
    D_overlay_37_02502018[1] = *(s32 *) (front_text + 0x278);
    D_overlay_37_0250203C = arg0;
    D_overlay_37_02502020 = 0;
    D_overlay_37_0250202A = 0xA;
    D_overlay_37_02502050 = 0.0f;
    D_overlay_37_02502048 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o37/overlay_37/frontInitOptionsPage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupOptionsPage(void) {
    freeFrontEndList(D_overlay_37_02501EE0);
    if (D_overlay_37_0250203C == 0) {
        freeFrontEndList(D_overlay_37_02501EEC);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o37/overlay_37/frontCleanupOptionsPage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontOptionsPage(s32 arg0) {
    s32 spBC;
    s32 spB8;
    s32 spE0;
    s32 spDC;
    s32 spD8;
    s32 spD4;
    s32 tempC;
    s32 btnConfirm;
    s32 btnBack;
    s32 held8;
    s32 held4;
    s32 stickUp;
    s32 stickDown;
    s32 stickRight;
    s32 stickLeft;
    s32 rowY;
    s32 rowY2;
    s32 rowY3;
    s32 cursor;
    s32 prevCursor;
    s32 var_a2;
    s32 var_a1;
    s32 lightIdx;
    s32 texIdx;
    s32 segIdx;
    s32 cnt;
    s32 a3v;
    s32 idx;
    s32 nextIdx;
    s32 textIdx;
    s32 stereo;
    s32 wide;
    s32 wideNew;
    s32 screenMode;
    s32 ctl;
    s32 k;
    s16 *colp;
    u8 *t3;
    u8 *t0;
    u8 *v1;
    u8 *rec;
    u8 *recp;
    u8 *dst;
    f32 f12;
    s8 s1;
    Gfx *g;
    u8 cheatOn[5];
    s32 cheatText[5];

    if (D_overlay_37_02502038 == 0) {
        if (D_overlay_37_02502048 < 0x1E) {
            D_overlay_37_02502048 += arg0;
        }
        if ((D_overlay_37_02501F34 == 6) && !(frontGetScreenMode() & 1)) {
            f12 = 16.0f;
        } else if ((D_overlay_37_02501F34 == 7) || (D_overlay_37_02501F34 == 9)) {
            f12 = 26.0f;
        } else {
            f12 = (f32) D_overlay_37_02501F28[D_overlay_37_02501F34];
        }

        /* smoothing of the camera Y offset: first (arg0 & 3) steps, then 4x unrolled */
        segIdx = 0;
        if (arg0 > 0) {
            if ((arg0 & 3) != 0) {
                do {
                    segIdx += 1;
                    D_overlay_37_0250202C += (f12 - D_overlay_37_0250202C) * 0.25f;
                } while (segIdx != (arg0 & 3));
            }
            if (segIdx != arg0) {
                do {
                    segIdx += 4;
                    D_overlay_37_0250202C += (f12 - D_overlay_37_0250202C) * 0.25f;
                    D_overlay_37_0250202C += (f12 - D_overlay_37_0250202C) * 0.25f;
                    D_overlay_37_0250202C += (f12 - D_overlay_37_0250202C) * 0.25f;
                    D_overlay_37_0250202C += (f12 - D_overlay_37_0250202C) * 0.25f;
                } while (segIdx != arg0);
            }
            segIdx = 0;
        }

        viGetCurrentSize(&spBC, &spB8);
        spBC = (s32) ((u32) spBC >> 1);
        spB8 = (s32) ((u32) spB8 >> 1);

        if (D_overlay_37_02502050 == 0.0f) {
            btnConfirm = frontJoyPressed[0] & 0x9000;
            btnBack = frontJoyPressed[0] & 0x4000;
            held8 = frontJoyHeld[0] & 8;
            held4 = frontJoyHeld[0] & 4;
            stickUp = frontJoyDy[0] > 0;
            stickDown = frontJoyDy[0] < 0;
            stickRight = frontJoyDx[0] > 0;
            stickLeft = frontJoyDx[0] < 0;
        } else {
            btnConfirm = 0;
            btnBack = 0;
            held8 = 0;
            held4 = 0;
            stickUp = 0;
            stickDown = 0;
            stickRight = 0;
            stickLeft = 0;
        }

        /* ---- display list setup ---- */
        rcpClearScreen(&frontgfx, (void **) &frontmtx, 0);
        texDPInit(&frontgfx);
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = -1;
        g->words.w0 = 0xF8000000;
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = 0x64009867;
        g->words.w0 = 0xBC000008;
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = 0;
        g->words.w0 = 0xE7000000;

        pauseClearScreen();
        camSetNo(0);
        camOverrideProjScales(1.0f, 1.0f);
        camSetFOV(52.0f, 1);
        camSetView(&frontgfx, 0);

        tempC = (s32) D_overlay_37_0250202C;
        spE0 = spBC - D_overlay_37_02502028;
        spDC = spB8 - tempC;
        spD8 = D_overlay_37_02502028 + spBC;
        spD4 = tempC + spB8;

        /* D_800FF5EC -> +0x6C -> t3 (per-model block), t0 = t3->unk0 (model header) */
        t3 = *(u8 **) (*(u8 **) ((u8 *) D_800FF5EC + 0x6C));
        t0 = *(u8 **) t3;
        *(s8 *) (t3 + 0xA) = (s8) arg0;
        objAnimDframe(D_800FF5EC, *(s32 *) &D_overlay_37_0250204C, (f32) arg0, arg0); /* asm: raw word in a1 */

        if (frontGetScreenMode() & 1) {
            D_overlay_37_02501F10[6] = 1;
            D_overlay_37_02501F10[3] = 2;
        } else {
            D_overlay_37_02501F10[6] = 0;
            D_overlay_37_02501F10[3] = D_overlay_37_02501F1C[frontGet2PlayerSplit()];
        }
        D_overlay_37_02501F10[0] = D_overlay_37_02501F18[frontGetStereoMode()];

        /* ---- 8 passes: per-vertex colour from texture records ---- */
        for (lightIdx = 0; lightIdx != 8; lightIdx++) {
            v1 = *(u8 **) (t3 + 0x74);
            colp = *(s16 **) (t3 + 0x78 + *(s8 *) (t3 + 0xB) * 4);
            var_a2 = 0;
            if (*(u8 *) (t0 + 0x2C) > 0) {
                do {
                    texIdx = *(s32 *) (v1 + 4) & 0xFF;
                    rec = *(u8 **) (*(u8 **) (t0 + 0x18) + texIdx * 8);
                    if (texIdx == D_overlay_37_02501F08[lightIdx]) {
                        *(s16 *) v1 = (s16) (D_overlay_37_02501F10[lightIdx] << 8);
                    }
                    *colp = (s16) ((*(s16 *) v1 >> 8) * *(s16 *) (rec + 0x16));
                    colp += 1;
                    if (*(s16 *) (v1 + 2) >= 0) {
                        *colp = (s16) ((*(s16 *) (v1 + 2) >> 8) * *(s16 *) (rec + 0x16));
                        colp += 1;
                    }
                    var_a2 += 1;
                    v1 += 8;
                } while (var_a2 < *(u8 *) (t0 + 0x2C));
            }
        }

        /* ---- record pass (16-byte records) ---- */
        recp = *(u8 **) (t0 + 0x24);
        segIdx = 0;
        if (*(s16 *) (t0 + 0x16) > 0) {
            do {
                s1 = *(s8 *) (recp + 1);
                if (s1 == D_overlay_37_02501F20[D_overlay_37_02502030]) {
                    var_a2 = 0xFF;
                    var_a1 = (u8) (s32) ((Sinf(D_overlay_37_02501F38) * 55.0f) + 200.0f);
                    D_overlay_37_02501F38 = (s16) (D_overlay_37_02501F38 + (arg0 << 10));
                } else {
                    var_a1 = 0x60;
                    var_a2 = 0xFF;
                    if ((frontGetScreenMode() & 1) && (D_overlay_37_02502030 == 3)) {
                        var_a2 = 0x70;
                    }
                }
                if ((s1 != 6) && (s1 != 1)) {
                    a3v = *(s16 *) (recp + 6);
                    cnt = *(s16 *) (recp + 0x16) - a3v;
                    dst = *(u8 **) (t3 + *(s8 *) (t3 + 0xB) * 4 + 0x18) + a3v * 0xA;
                    if (cnt != 0) {
                        k = cnt - 1;
                        do {
                            dst[6] = (u8) var_a1;
                            dst[7] = (u8) var_a1;
                            dst[8] = (u8) var_a1;
                            dst[9] = (u8) var_a2;
                            dst += 0xA;
                        } while (k-- != 0);
                    }
                }
                segIdx += 1;
                recp += 0x10;
            } while (segIdx < *(s16 *) (t0 + 0x16));
        }

        camStandardPersp((void **) &frontgfx, (void **) &frontmtx, var_a2);
        frontDrawObj(0x29);
        frontDrawObj(0x1F);
        *(f32 *) (currentobjects + 0x510) = -D_overlay_37_0250202C;
        *(f32 *) (currentobjects + 0x4F0) = D_overlay_37_0250202C;
        frontDrawObj(0x27);
        frontDrawObj(0x28);
        texDPTextureX(&frontgfx, NULL, 0, 0);

        /* ---- header bar ---- */
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = 0xA0;
        g->words.w0 = 0xFB000000;
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w0 = 0xFA000000;
        g->words.w1 = 0x28282800;
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = (u32) D_82501EB0;
        g->words.w0 = 0x07020010;
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w0 = ((spD8 & 0x3FF) << 0xE) | 0xF6000000 | ((spD4 & 0x3FF) * 4);
        g->words.w1 = ((spE0 & 0x3FF) << 0xE) | ((spDC & 0x3FF) * 4);
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w0 = (((s32) ((f32) spE0 * 4.0f) & 0xFFF) << 0xC) | 0xED000000 | ((s32) ((f32) spDC * 4.0f) & 0xFFF);
        g->words.w1 = (((s32) ((f32) spD8 * 4.0f) & 0xFFF) << 0xC) | ((s32) ((f32) spD4 * 4.0f) & 0xFFF);

        rowY = (spB8 - tempC) + 3;
        fontUseFont(2);
        fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = 0;
        g->words.w0 = 0xE7000000;
        fontPrintXY(&frontgfx, spBC, rowY, (char *) *(s32 *) (front_text + D_overlay_37_02502030 * 4 + 0x4D0), 4);
        rowY += 0xF;

        /* ---- per-page controls ---- */
        switch (D_overlay_37_02501F34) {
        case 8:
            if (btnConfirm != 0) {
                D_overlay_37_02501F34 = D_overlay_37_02502030;
                amSndPlay(0x16D, 0, 0, 0); /* asm: a2/a3 stale, passed as 0 */
            } else if (btnBack != 0) {
                if ((D_overlay_37_0250203C == 0) && (D_overlay_37_02502048 >= 0x1E)) {
                    amSndPlay(0x16D, 0, 0, 0);
                    mainTitlePageInit();
                    mainSaveGlobalFlags();
                    D_overlay_37_02502050 = 1.0f;
                } else if (D_overlay_37_0250203C == 1) {
                    pauseSetScreen(1);
                    mainSaveGlobalFlags();
                    D_overlay_37_02502050 = 1.0f;
                }
            } else {
                prevCursor = D_overlay_37_02502030;
                cursor = prevCursor;
                if (stickDown != 0) {
                    if (cursor == 6) {
                        cursor = 1;
                        D_overlay_37_02502030 = 1;
                    } else {
                        cursor += 2;
                        D_overlay_37_02502030 = cursor;
                    }
                }
                if (stickUp != 0) {
                    if (cursor == 1) {
                        cursor = 6;
                        D_overlay_37_02502030 = 6;
                    } else {
                        cursor -= 2;
                        D_overlay_37_02502030 = cursor;
                    }
                }
                if (stickLeft != 0) {
                    cursor -= 1;
                    D_overlay_37_02502030 = cursor;
                }
                if (stickRight != 0) {
                    cursor += 1;
                    D_overlay_37_02502030 = cursor;
                }
                if (cursor < 0) {
                    D_overlay_37_02502030 = 7;
                } else if (cursor >= 8) {
                    D_overlay_37_02502030 = 0;
                }
                if ((frontGetScreenMode() & 1) && (D_overlay_37_02502030 == 3)) {
                    if (stickDown != 0) {
                        D_overlay_37_02502030 = 5;
                    } else if (stickUp != 0) {
                        D_overlay_37_02502030 = 1;
                    } else if (stickRight != 0) {
                        D_overlay_37_02502030 = 4;
                    } else {
                        D_overlay_37_02502030 = 2;
                    }
                }
                if (prevCursor != D_overlay_37_02502030) {
                    amSndPlay(0x16B, 0, 0, 0);
                }
            }
            break;
        case 0:
            stereo = frontGetStereoMode();
            if (stickLeft != 0) {
                amSndPlay(0x16C, 0, 0, 0);
                stereo -= 1;
                if (stereo < 0) {
                    stereo = 3;
                }
            }
            if (stickRight != 0) {
                amSndPlay(0x16C, 0, 0, 0);
                stereo += 1;
                if (stereo >= 4) {
                    stereo = 0;
                }
            }
            frontSetStereoMode(stereo);
            fontPrintXY(&frontgfx, spBC, rowY, (char *) D_overlay_37_02501FF0[frontGetStereoMode()], 4);
            if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            break;
        case 1:
            if (stickUp != 0) {
                if (D_overlay_37_02502040 > 0) {
                    amSndPlay(0x16C, 0, 0, 0);
                    D_overlay_37_02502040 -= 1;
                } else {
                    amSndPlay(0x16E, 0, 0, 0);
                }
            }
            if (stickDown != 0) {
                if (D_overlay_37_02502040 < (numberOfJoypads - 1)) {
                    amSndPlay(0x16C, 0, 0, 0);
                    D_overlay_37_02502040 += 1;
                } else {
                    amSndPlay(0x16E, 0, 0, 0);
                }
            }
            if (D_overlay_37_02502040 < 0) {
                D_overlay_37_02502040 = 0;
            }
            if (D_overlay_37_02502040 >= numberOfJoypads) {
                D_overlay_37_02502040 = numberOfJoypads - 1;
            }
            if ((stickLeft != 0) || (stickRight != 0)) {
                amSndPlay(0x16C, 0, 0, 0);
                frontSetTargetControl(D_overlay_37_02502040, (frontGetTargetControl(D_overlay_37_02502040) ^ 1) & 1);
            }
            rowY += 4;
            for (ctl = 0; ctl != 4; ctl++) {
                if (ctl == D_overlay_37_02502040) {
                    fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                }
                if (ctl >= numberOfJoypads) {
                    fontColour(0, 0xFF, 0xFF, 0xFF, 0x62);
                }
                fontPrintXY(&frontgfx, spBC - 0x20, rowY, D_overlay_37_02501ED0[ctl], 1);
                fontPrintXY(&frontgfx, spBC - 0x20, rowY, (char *) D_overlay_37_02502000[frontGetTargetControl(ctl)], 0);
                fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
                rowY += 0xF;
            }
            if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            break;
        case 2:
            frontSetBgmVolume(func_overlay_37_02501ACC_1F57D9C(frontGetBgmVolume(), 0xA0, rowY));
            if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            break;
        case 3:
            if ((stickLeft != 0) || (stickRight != 0)) {
                amSndPlay(0x16C, 0, 0, 0);
                if (frontGet2PlayerSplit() != 0) {
                    frontSet2PlayerSplit(0);
                } else {
                    frontSet2PlayerSplit(1);
                }
            }
            fontPrintXY(&frontgfx, spBC, rowY, (char *) D_overlay_37_02502018[frontGet2PlayerSplit()], 4);
            if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            break;
        case 4:
            frontSetSfxVolume(func_overlay_37_02501ACC_1F57D9C(frontGetSfxVolume(), 0xA0, rowY));
            if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            break;
        case 5:
            /* bug head / cheat toggles: copy the flag bytes and the name words to the stack */
            cheatOn[0] = D_overlay_37_02501F4C[0];
            cheatOn[1] = D_overlay_37_02501F4C[1];
            cheatOn[2] = D_overlay_37_02501F4C[2];
            cheatOn[3] = D_overlay_37_02501F4C[3];
            cheatOn[4] = D_overlay_37_02501F4C[4];
            cheatText[0] = D_overlay_37_02501F54[0];
            cheatText[1] = D_overlay_37_02501F54[1];
            cheatText[2] = D_overlay_37_02501F54[2];
            cheatText[3] = D_overlay_37_02501F54[3];
            cheatText[4] = D_overlay_37_02501F54[4];

            if (bugHeadCheats != 0) {
                idx = 1;
                if (cheatOn[1] != 0) {
                    do {
                        if (idx == D_overlay_37_02502044) {
                            if (stickUp != 0) {
                                nextIdx = idx - 1;
                                if (cheatOn[nextIdx] != 0) {
                                    do {
                                        if (cheatOn[nextIdx] & bugHeadCheats) {
                                            D_overlay_37_02502044 = nextIdx;
                                            stickUp = 0;
                                            amSndPlay(0x16C, 0, 0, 0);
                                            break;
                                        }
                                        nextIdx -= 1;
                                    } while (cheatOn[nextIdx] != 0);
                                }
                            } else if (stickDown != 0) {
                                nextIdx = idx + 1;
                                if (cheatOn[nextIdx] != 0) {
                                    do {
                                        if (cheatOn[nextIdx] & bugHeadCheats) {
                                            D_overlay_37_02502044 = nextIdx;
                                            stickDown = 0;
                                            amSndPlay(0x16C, 0, 0, 0);
                                            break;
                                        }
                                        nextIdx += 1;
                                    } while (cheatOn[nextIdx] != 0);
                                }
                            } else if ((stickLeft != 0) || (stickRight != 0)) {
                                if (D_overlay_37_02502044 == 1) {
                                    rainbowblood = (rainbowblood + 1) & 1;
                                }
                                if (D_overlay_37_02502044 == 2) {
                                    deformedchars = (deformedchars + 1) & 1;
                                }
                                if (D_overlay_37_02502044 == 3) {
                                    antsasmrpants = (antsasmrpants + 1) & 1;
                                }
                                amSndPlay(0x16C, 0, 0, 0);
                            }
                            fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                        } else {
                            fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
                        }
                        textIdx = 0x13E;
                        if (cheatOn[idx] & bugHeadCheats) {
                            if (((idx == 1) && (rainbowblood != 0)) || ((idx == 2) && (deformedchars != 0))
                                || ((idx == 3) && (antsasmrpants != 0))) {
                                textIdx = 0x13D;
                            }
                            fontPrintXY(&frontgfx, spBC - 0x32, rowY, (char *) cheatText[idx], 0);
                            fontPrintXY(&frontgfx, spBC + 0x32, rowY, (char *) *(s32 *) (front_text + textIdx * 4), 1);
                            rowY += 0xF;
                        }
                        idx += 1;
                    } while (cheatOn[idx] != 0);
                }
            }
            if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            break;
        case 6:
            screenMode = frontGetScreenMode();
            if ((stickLeft != 0) || (stickRight != 0)) {
                screenMode ^= 1;
                viNoClear();
                viNoZbufferRealloc = 1;
                viChangeMode(screenMode);
                amSndPlay(0x16C, 0, 0, 0);
            }
            frontSetScreenMode(screenMode);
            wide = frontGetWideAdjust();
            wideNew = wide;
            if (held8 != 0) {
                wideNew = wide - 1;
            }
            if (held4 != 0) {
                wideNew += 1;
            }
            frontSetWideAdjust(wideNew);
            fontPrintXY(&frontgfx, spBC, rowY, (char *) D_overlay_37_02502008[frontGetScreenMode() & 3], 4);
            rowY2 = rowY + 0xF;
            fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, spBC - 0x2D, rowY2, D_overlay_37_02501F00, 4);
            fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, spBC, rowY2, (char *) *(s32 *) (front_text + 0x4C8), 4);
            rowY3 = rowY2 + 0xF;
            fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, spBC - 0x2D, rowY3, D_overlay_37_02501F04, 4);
            fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, spBC, rowY3, (char *) *(s32 *) (front_text + 0x4CC), 4);
            if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            break;
        case 7:
            if (btnConfirm != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                if (D_overlay_37_02502020 == 0) {
                    D_overlay_37_02501F34 = 8;
                } else if (D_overlay_37_0250203C == 1) {
                    D_overlay_37_02502024 = 0;
                    D_overlay_37_02501F34 = 9;
                } else {
                    D_overlay_37_02501F34 = 0xA;
                    mainTitlePageInit();
                }
            } else if (btnBack != 0) {
                D_overlay_37_02502020 = 0;
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            if ((stickLeft != 0) || (stickRight != 0)) {
                D_overlay_37_02502020 ^= 1;
                amSndPlay(0x16C, 0, 0, 0);
            }
            D_overlay_37_02501F3C += arg0 * D_overlay_37_0250202A;
            if (D_overlay_37_02501F3C >= 0x100) {
                D_overlay_37_02501F3C = 0x1FE - D_overlay_37_02501F3C;
                D_overlay_37_0250202A = -D_overlay_37_0250202A;
            } else if (D_overlay_37_02501F3C < 0) {
                D_overlay_37_02501F3C = -D_overlay_37_02501F3C;
                D_overlay_37_0250202A = -D_overlay_37_0250202A;
            }
            fontPrintXY(&frontgfx, spBC, rowY, (char *) *(s32 *) (front_text + 0x4F0), 4);
            rowY += 0xF;
            if (D_overlay_37_02502020 == 0) {
                fontColour(0, D_overlay_37_02501F3C, 0xFF, 0xFF, 0xFF);
            }
            fontPrintXY(&frontgfx, spBC + 0x19, rowY, (char *) *(s32 *) (front_text + 0x4F8), 4);
            if (D_overlay_37_02502020 == 1) {
                fontColour(0, D_overlay_37_02501F3C, 0xFF, 0xFF, 0xFF);
            } else {
                fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            fontPrintXY(&frontgfx, spBC - 0x19, rowY, (char *) *(s32 *) (front_text + 0x4F4), 4);
            break;
        case 9:
            if (btnConfirm != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                if (D_overlay_37_02502024 == 0) {
                    amSndPlay(0x16D, 0, 0, 0);
                    amSndPlay(0x16D, 0, 0, 0);
                    mainSaveGlobalFlags();
                    mainSaveGame(*(s8 *) ((u8 *) mainGetGame() + 3));
                }
                pauseSetNewLevel(0, 0, 0, 3);
                D_overlay_37_02501F34 = 0xA;
            } else if (btnBack != 0) {
                amSndPlay(0x16D, 0, 0, 0);
                D_overlay_37_02501F34 = 8;
            }
            if ((stickLeft != 0) || (stickRight != 0)) {
                D_overlay_37_02502024 ^= 1;
                amSndPlay(0x16C, 0, 0, 0);
            }
            D_overlay_37_02501F3C += arg0 * D_overlay_37_0250202A;
            if (D_overlay_37_02501F3C >= 0x100) {
                D_overlay_37_02501F3C = 0x1FE - D_overlay_37_02501F3C;
                D_overlay_37_0250202A = -D_overlay_37_0250202A;
            } else if (D_overlay_37_02501F3C < 0) {
                D_overlay_37_02501F3C = -D_overlay_37_02501F3C;
                D_overlay_37_0250202A = -D_overlay_37_0250202A;
            }
            fontPrintXY(&frontgfx, spBC, rowY, (char *) *(s32 *) (front_text + 0x844), 4);
            rowY += 0xF;
            if (D_overlay_37_02502024 == 1) {
                fontColour(0, D_overlay_37_02501F3C, 0xFF, 0xFF, 0xFF);
            }
            fontPrintXY(&frontgfx, spBC + 0x19, rowY, (char *) *(s32 *) (front_text + 0x4F8), 4);
            if (D_overlay_37_02502024 == 0) {
                fontColour(0, D_overlay_37_02501F3C, 0xFF, 0xFF, 0xFF);
            } else {
                fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            fontPrintXY(&frontgfx, spBC - 0x19, rowY, (char *) *(s32 *) (front_text + 0x4F4), 4);
            break;
        }
        camSetScissor(&frontgfx);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o37/overlay_37/frontOptionsPage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_37_02501ACC_1F57D9C(s32 arg0, s32 arg1, s32 arg2) {
    s32 sx;
    s32 sy;
    unkResetColourCycle cycle;
    f32 scaleF;
    s32 segs;
    s32 i;
    s32 barLen;
    s32 yEnd;
    u8 *colPtr;
    Gfx *g;
    s32 var_s7;

    var_s7 = arg0;
    sy = arg2;
    sx = 0xA0;
    if (frontJoyDxRepeat[0] < 0) {
        var_s7 = arg0 - 8;
        if (var_s7 < 0) {
            var_s7 = 0;
        }
    }
    if (frontJoyDxRepeat[0] > 0) {
        var_s7 += 8;
        if (var_s7 >= 0x101) {
            var_s7 = 0x100;
        }
    }
    instScreenToSpriteCoord(&sx, &sy);
    D_800FFCD0 = (f32) (sy - 0x17);
    camStandardOrtho((void **) &frontgfx, (void **) &frontmtx);
    frontDrawObj(0x2A);
    scaleF = (f32) var_s7;
    segs = (s32) (scaleF * 38.0f * 0.00390625f);
    texDPTextureX(&frontgfx, NULL, 0, 0);
    g = frontgfx;
    frontgfx = g + 1;
    g->words.w0 = 0x07020010;
    g->words.w1 = (u32) &D_82501EC0;
    sx -= 0x12;
    sy -= 0x19;
    instSpriteToScreenCoord(&sx, &sy);
    i = 0;
    if (segs > 0) {
        do {
            initColourCycle(&cycle, 0x39);
            updateColourCycle(&cycle, (s32) (objTvTimes(0x3C) * i) / 38);
            g = frontgfx;
            i += 3;
            frontgfx = g + 1;
            g->words.w0 = 0xFA000000;
            g->words.w1 = (cycle.unk8 << 0x18) | (cycle.unk9 << 0x10) | (cycle.unkA << 8) | 0xFF;
            g = frontgfx;
            frontgfx = g + 1;
            g->words.w0 = (((sx + 1) & 0x3FF) << 0xE) | 0xF6000000 | (((sy - 3) & 0x3FF) * 4);
            g->words.w1 = (((sx & 0x3FF) << 0xE) | (((sy - 8) & 0x3FF) * 4));
            sx += 3;
        } while (i < segs);
    }
    sx = 0xB2;
    sy += 0x10;
    barLen = (s32) (scaleF * 21.0f * 0.00390625f);
    if (barLen > 0) {
        colPtr = (u8 *) barcolours;
        do {
            g = frontgfx;
            frontgfx = g + 1;
            g->words.w0 = 0xFA000000;
            g->words.w1 = *(s32 *) colPtr;
            if (barLen >= 8) {
                yEnd = sy - 7;
            } else {
                yEnd = sy - barLen;
            }
            g = frontgfx;
            frontgfx = g + 1;
            g->words.w0 = (((sx + 2) & 0x3FF) << 0xE) | 0xF6000000 | ((sy & 0x3FF) * 4);
            g->words.w1 = (((sx + 1) & 0x3FF) << 0xE) | ((yEnd & 0x3FF) * 4);
            colPtr += 4;
            barLen -= 7;
            sx += 4;
        } while ((u32) colPtr < (u32) D_overlay_37_02501F4C && barLen > 0);
    }
    return var_s7;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o37/overlay_37/func_overlay_37_02501ACC_1F57D9C.s")
#endif
