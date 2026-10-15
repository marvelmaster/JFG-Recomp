#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void loadFrontEndList(void *list);
void setupFrontEndList(void *list);
void freeFrontEndList(void *list);
void amTunePlay(s32 arg0, void *arg1, void *arg2, void *arg3);
void amSndPlay(s32 sndId, s32 arg1, s32 arg2, s32 arg3);
void amTuneSetFade(f32 fade, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void fontPrintXY(Gfx **gfx, s32 x, s32 y, char *text, s32 flags);
void mainChangeCameras(s32 arg0);
void mainRefreshMultiPlayer(void);
void mainSetAnimGroup(s32 arg0);
void mainSetMode(s32 arg0);
extern u8 *front_text;
extern Gfx *frontgfx;
extern s32 D_overlay_62_03E027D0[];
extern s32 D_overlay_62_03E027D8[];
extern s32 D_overlay_62_03E027E4[];
extern u8 D_overlay_62_03E02878[];
extern s32 D_overlay_62_03E027F8;
extern u8 D_overlay_62_03E02804[];
extern s16 D_overlay_62_03E029A4;
extern f32 D_overlay_62_03E029A8;
extern s32 D_overlay_62_03E029AC;
extern s32 D_overlay_62_03E029B0;
extern s32 D_overlay_62_03E029B4;
extern s32 D_overlay_62_03E029B8;
extern s32 D_overlay_62_03E029C0;
extern s32 D_overlay_62_03E029C8;
extern s32 D_overlay_62_03E029CC;
extern s32 D_overlay_62_03E029E4;
extern s32 D_overlay_62_03E029E8;
extern s32 D_overlay_62_03E029EC;
extern s32 D_overlay_62_03E029F0[];
extern s32 D_overlay_62_03E02A00[];
extern s32 D_overlay_62_03E02A10[];
extern s32 D_overlay_62_03E02A30[];
extern s32 D_overlay_62_03E02A40[];
extern s32 D_overlay_62_03E02A48[];
extern s32 D_overlay_62_03E02A58[];
extern s32 D_overlay_62_03E02A60[];
extern s32 D_overlay_62_03E02A68[];
extern s16 D_overlay_62_03E02890[];
extern char D_overlay_62_03E02940[];
extern char D_overlay_62_03E02948[];
extern s8 clayPigeonAmmo;
extern s8 clayPigeonAmmoChoice;
extern s8 clayPigeonCursor;
extern s8 clayPigeonLevel;
extern s32 currentGameTime;
extern s16 gameoverFade;
extern s8 multiFinished;
extern s32 multiGameTime;
extern s8 multiGameType;
extern s16 multiLevelChoice;
extern s8 okayed;
extern s16 D_800FF1BA;
extern s16 D_800FF1BC;
extern s16 D_800FF1BE;
extern u8 D_800FF383;
extern u8 D_800FF382;
extern s8 D_800FED62;
extern s8 D_800FEE02;
extern s8 D_800FEEA2;
extern s8 D_800FEF42;
extern s8 numberOfAI;
extern u8 numberOfPlayers;
extern s8 raceGameLevel;
extern s8 raceGameType;
extern s8 raceGameLaps;
extern s8 raceGameTime;
extern s8 raceGamePickups;
extern s8 raceGameStartBoost;
extern u8 raceGameSingleScreen;
extern u8 D_overlay_62_03E0285C[];
extern s8 D_overlay_62_03E0281C[];
extern s8 D_overlay_62_03E02824[];
extern s16 D_overlay_62_03E02874[];
extern s16 D_overlay_62_03E028C8;
extern char D_overlay_62_03E02920[];
extern char D_overlay_62_03E02928[];
extern char D_overlay_62_03E02930[];
extern char D_overlay_62_03E02938[];
extern s8 deathMatchType;
extern s8 deathMatchTime;
extern s8 deathMatchLife;
extern s8 deathMatchKills;
extern s8 deathMatchLevel;
extern s8 deathMatchObjectList;
extern s8 multiGameLife;
extern s16 multiGameTarget;
extern s8 multiObjectList;
extern u8 radarMode;
extern u8 D_overlay_62_03E02828[];
extern s32 D_overlay_62_03E02850[];
extern s8 D_overlay_62_03E02820[];
extern s16 D_overlay_62_03E02848[];
extern s16 D_overlay_62_03E028AE;
extern char D_overlay_62_03E028F0[];
extern char D_overlay_62_03E028F8[];
extern char D_overlay_62_03E02900[];
extern char D_overlay_62_03E02908[];
extern char D_overlay_62_03E02910[];
extern char D_overlay_62_03E02918[];
extern s8 D_overlay_62_03E027EC[];
extern s8 D_overlay_62_03E027FC[];
extern s8 D_overlay_62_03E02814[];
extern s16 D_overlay_62_03E028AC[];
extern s16 D_overlay_62_03E028DC;
extern f32 D_overlay_62_03E02950;
extern f32 D_overlay_62_03E02954;
extern f32 D_overlay_62_03E02958;
extern f32 D_overlay_62_03E0295C;
extern f32 D_overlay_62_03E02960;
extern s32 D_overlay_62_03E029C4;
extern s32 D_overlay_62_03E029D0;
extern s32 D_overlay_62_03E029D4;
extern s32 D_overlay_62_03E029D8;
extern s32 D_overlay_62_03E029DC;
extern s32 D_overlay_62_03E029E0;
extern u8 D_83E027C0[];
extern void *D_800FF5FC;
extern void *frontmtx;
extern s8 frontJoyDx[];
extern s8 frontJoyDy[];
extern s32 frontJoyHeld[];
extern s32 frontJoyPressed[];
extern u8 currentobjects[];
extern u8 gameType;
void fontUseFont(s32 font);
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void pauseClearScreen(void);
void camSetNo(s32 arg0);
void camOverrideProjScales(f32 arg0, f32 arg1);
void camSetFOV(f32 fov, s32 force);
void camSetView(Gfx **dlist, void **mtxp);
void camStandardPersp(Gfx **dlist, void **mtxp);
void frontDrawObj(s32 arg0);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
void rcpClearScreen(Gfx **dlist, void **mtxp, s32 arg2);
void mainTitlePageInit(void);
f32 Sinf(s16 angle);
void objAnimDframe(void *obj, f32 rate, f32 frame);
void func_overlay_62_03E01158_1F80E38(s32 arg0, s32 arg2);
void func_overlay_62_03E01A48_1F81728(s32 arg0, s32 arg3);
void func_overlay_62_03E0228C_1F81F6C(s32 arg0);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitMultiModeSelect(void) {
    loadFrontEndList(D_overlay_62_03E027E4);
    setupFrontEndList(D_overlay_62_03E027D8);
    loadFrontEndList(D_overlay_62_03E027D0);

    D_overlay_62_03E029F0[0] = *(s32 *)(front_text + 0x5A0);
    D_overlay_62_03E029F0[1] = *(s32 *)(front_text + 0x5A4);
    D_overlay_62_03E029F0[2] = *(s32 *)(front_text + 0x5A8);
    D_overlay_62_03E02A00[0] = *(s32 *)(front_text + 0x504);
    D_overlay_62_03E02A00[1] = *(s32 *)(front_text + 0x508);
    D_overlay_62_03E02A00[2] = *(s32 *)(front_text + 0x50C);
    D_overlay_62_03E02A10[0] = *(s32 *)(front_text + 0x5AC);
    D_overlay_62_03E02A10[1] = *(s32 *)(front_text + 0x5B0);
    D_overlay_62_03E02A10[2] = *(s32 *)(front_text + 0x5B4);
    D_overlay_62_03E02A10[3] = *(s32 *)(front_text + 0x6FC);
    D_overlay_62_03E02A10[4] = *(s32 *)(front_text + 0x5B8);
    D_overlay_62_03E02A10[5] = *(s32 *)(front_text + 0x5BC);
    D_overlay_62_03E02A10[6] = *(s32 *)(front_text + 0x6F8);
    D_overlay_62_03E02A10[7] = *(s32 *)(front_text + 0x6F4);
    D_overlay_62_03E02A30[0] = *(s32 *)(front_text + 0x518);
    D_overlay_62_03E02A30[1] = *(s32 *)(front_text + 0x51C);
    D_overlay_62_03E02A30[2] = *(s32 *)(front_text + 0x520);
    D_overlay_62_03E02A40[0] = *(s32 *)(front_text + 0x544);
    D_overlay_62_03E02A40[1] = *(s32 *)(front_text + 0x548);
    D_overlay_62_03E02A48[0] = *(s32 *)(front_text + 0x54C);
    D_overlay_62_03E02A48[1] = *(s32 *)(front_text + 0x550);
    D_overlay_62_03E02A48[2] = *(s32 *)(front_text + 0x82C);
    D_overlay_62_03E02A48[3] = *(s32 *)(front_text + 0x830);
    D_overlay_62_03E02A58[0] = *(s32 *)(front_text + 0x554);
    D_overlay_62_03E02A58[1] = *(s32 *)(front_text + 0x504);
    D_overlay_62_03E02A60[0] = *(s32 *)(front_text + 0x280);
    D_overlay_62_03E02A60[1] = *(s32 *)(front_text + 0x5AC);
    D_overlay_62_03E02A68[0] = *(s32 *)(front_text + 0x544);
    D_overlay_62_03E02A68[1] = *(s32 *)(front_text + 0x598);
    D_overlay_62_03E02A68[2] = *(s32 *)(front_text + 0x59C);

    D_overlay_62_03E029AC = 0;
    D_overlay_62_03E029B0 = -1;
    D_overlay_62_03E029A4 = 0x36;
    D_overlay_62_03E029A8 = 7.0f;
    D_overlay_62_03E029EC = 0;
    amTunePlay(0x10, D_overlay_62_03E02A48, D_overlay_62_03E029F0, D_overlay_62_03E02A00);
    D_overlay_62_03E029B8 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o62/overlay_62/frontInitMultiModeSelect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Multiplayer mode-select menu, one frame: camera/object setup, joystick accumulation,
// 8-slot record updates, option-row navigation (mode 8 / mode 0), label drawing, then
// dispatch to the per-game-type option selector (0 = 1158, 1 = 1A48, 2 = 228C).
// Byte/word offsets without a struct type are kept raw (asm-proven). Table index for option
// labels is gameType*8 + row (s16 entries), text = front_text word at index*4.
// cf. func_overlay_62_03E01158_1F80E38 (same globals and mode numbering).
void frontMultiModeSelect(s32 arg0) {
    u8 *obj;
    u8 *s0;
    u8 *t0;
    u8 *rec;
    u8 *vtx;
    u8 *ent;
    s16 *out;
    Gfx *gp;
    f32 target;
    f32 sinv;
    s32 yc;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 cnt;
    s32 t1;
    s32 idx;
    s32 a1;
    s32 v;
    s32 v1;
    s32 sel;
    s32 n;
    s32 start;
    s32 end;
    s32 phaseStep;
    s32 pl;

    if (D_overlay_62_03E029B8 < 0x1E) {
        D_overlay_62_03E029B8 += arg0;
    }
    target = (f32)D_overlay_62_03E027EC[D_overlay_62_03E027F8];
    t1 = 0;
    if (arg0 > 0) {
        n = arg0 & 3;
        if (n != 0) {
            do {
                t1 += 1;
                D_overlay_62_03E029A8 += (target - D_overlay_62_03E029A8) * 0.25f;
            } while (n != t1);
            if (t1 != arg0) {
                goto block_7;
            }
        } else {
block_7:
            do {
                t1 += 4;
                D_overlay_62_03E029A8 += (target - D_overlay_62_03E029A8) * 0.25f;
                D_overlay_62_03E029A8 += (target - D_overlay_62_03E029A8) * 0.25f;
                D_overlay_62_03E029A8 += (target - D_overlay_62_03E029A8) * 0.25f;
                D_overlay_62_03E029A8 += (target - D_overlay_62_03E029A8) * 0.25f;
            } while (t1 != arg0);
        }
    }

    viGetCurrentSize(&D_overlay_62_03E029C0, &D_overlay_62_03E029C4);
    D_overlay_62_03E029C0 = (s32)((u32)D_overlay_62_03E029C0 >> 1);
    D_overlay_62_03E029C4 = (s32)((u32)D_overlay_62_03E029C4 >> 1);
    rcpClearScreen(&frontgfx, &frontmtx, 0);
    texDPInit(&frontgfx);
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w1 = -1U;
    gp->words.w0 = 0xF8000000;
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w1 = 0x64009867;
    gp->words.w0 = 0xBC000008;
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w1 = 0;
    gp->words.w0 = 0xE7000000;
    pauseClearScreen();
    camSetNo(0);
    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camSetView(&frontgfx, 0);

    yc = (s32)D_overlay_62_03E029A8;
    x0 = D_overlay_62_03E029C0 - D_overlay_62_03E029A4;
    y0 = D_overlay_62_03E029C4 - yc;
    x1 = D_overlay_62_03E029A4 + D_overlay_62_03E029C0;
    y1 = yc + D_overlay_62_03E029C4;

    obj = (u8 *)D_800FF5FC;
    s0 = *(u8 **)(*(u8 **)(obj + 0x6C));
    t0 = *(u8 **)s0;
    s0[0xA] = (s8)arg0;
    ((void (*)(void *, f32, f32, s16))objAnimDframe)(obj, 0.01f, (f32)arg0, D_overlay_62_03E029A4); /* sig mismatch: asm passes a3 */

    D_overlay_62_03E029E8 = 0;
    D_overlay_62_03E029E4 = 0;
    D_overlay_62_03E029E0 = 0;
    D_overlay_62_03E029DC = 0;
    D_overlay_62_03E029D8 = 0;
    D_overlay_62_03E029D4 = 0;
    D_overlay_62_03E029CC = 0;
    D_overlay_62_03E029C8 = D_overlay_62_03E029CC;
    if (okayed == 0) {
        if (*(f32 *)(obj + 0x28) >= 1.0f) {
            if ((s32)numberOfPlayers > 0) {
                pl = 0;
                do {
                    v = frontJoyPressed[pl];
                    D_overlay_62_03E029C8 |= v & 0x9000;
                    D_overlay_62_03E029CC |= v & 0x4000;
                    v = frontJoyHeld[pl];
                    D_overlay_62_03E029D4 += v & 8;
                    D_overlay_62_03E029D8 += v & 4;
                    a1 = frontJoyDy[pl];
                    D_overlay_62_03E029DC += a1 > 0;
                    D_overlay_62_03E029E0 += a1 < 0;
                    a1 = frontJoyDx[pl];
                    D_overlay_62_03E029E8 += a1 > 0;
                    D_overlay_62_03E029E4 += a1 < 0;
                    pl += 1;
                } while (pl < (s32)numberOfPlayers);
            }
        }
    }
    if (*(f32 *)(obj + 0x28) < D_overlay_62_03E02950) {
        D_overlay_62_03E02804[6] = 0;
        D_overlay_62_03E02804[7] = 0;
        if (*(f32 *)(obj + 0x28) < D_overlay_62_03E02954) {
            D_overlay_62_03E02804[4] = 0;
            D_overlay_62_03E02804[5] = 0;
            if (*(f32 *)(obj + 0x28) < D_overlay_62_03E02958) {
                D_overlay_62_03E02804[2] = 0;
                D_overlay_62_03E02804[3] = 0;
                if (*(f32 *)(obj + 0x28) < D_overlay_62_03E0295C) {
                    D_overlay_62_03E02804[0] = 0;
                    D_overlay_62_03E02804[1] = 0;
                }
            }
        }
    }

    /* 8 channels: per-vertex-group colour/index pairs into s0->0x78 output table */
    t1 = 0;
    do {
        rec = *(u8 **)(s0 + 0x74);
        out = *(s16 **)(s0 + (s32)(s8)s0[0xB] * 4 + 0x78);
        idx = 0;
        if ((s32)t0[0x2C] > 0) {
            do {
                v = *(u32 *)(rec + 4) & 0xFF;
                ent = *(u8 **)(*(u8 **)(t0 + 0x18) + v * 8);
                if (v == (s8)D_overlay_62_03E027FC[t1]) {
                    *(s16 *)rec = (s16)((s8)D_overlay_62_03E02804[t1] << 8);
                }
                *out++ = (s16)((*(s16 *)rec >> 8) * *(s16 *)(ent + 0x16));
                if (*(s16 *)(rec + 2) >= 0) {
                    *out++ = (s16)((*(s16 *)(rec + 2) >> 8) * *(s16 *)(ent + 0x16));
                }
                idx += 1;
                rec += 8;
            } while (idx < (s32)t0[0x2C]);
        }
        t1 += 1;
    } while (t1 != 8);

    /* 16-byte option records: vertex colour fill for non-hidden entries */
    rec = *(u8 **)(t0 + 0x24);
    if (*(s16 *)(t0 + 0x16) > 0) {
        t1 = 0;
        do {
            v = (s8)rec[1];
            a1 = 0x60;
            if (v == (s8)D_overlay_62_03E02814[D_overlay_62_03E029AC]) {
                phaseStep = arg0 << 10;
                sinv = ((f32 (*)(s16, s32))Sinf)(D_overlay_62_03E028DC, 0x60); /* sig mismatch: asm passes a1 */
                a1 = (s32)((sinv * 55.0f) + 200.0f);
                D_overlay_62_03E028DC = (s16)(D_overlay_62_03E028DC + phaseStep);
            }
            if (v != 6 && v != 1) {
                start = *(s16 *)(rec + 6);
                end = *(s16 *)(rec + 0x16); /* asm: +0x16 (next record's start) */
                vtx = *(u8 **)(s0 + (s32)(s8)s0[0xB] * 4 + 0x18) + start * 10;
                cnt = end - start;
                if (cnt != 0) {
                    n = cnt - 1;
                    do {
                        vtx[6] = (s8)a1;
                        vtx[7] = (s8)a1;
                        vtx[8] = (s8)a1;
                        vtx += 10;
                        n -= 1;
                    } while (n != 0);
                }
            }
            t1 += 1;
            rec += 0x10;
        } while (t1 < *(s16 *)(t0 + 0x16));
    }

    camStandardPersp(&frontgfx, &frontmtx);
    *(f32 *)(currentobjects + 0x510) = -D_overlay_62_03E029A8;
    *(f32 *)(currentobjects + 0x4F0) = D_overlay_62_03E029A8;
    frontDrawObj(0x2D);
    frontDrawObj(0x1F);
    frontDrawObj(0x27);
    frontDrawObj(0x28);
    texDPTextureX(&frontgfx, 0, 0, 0);
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w1 = 0xA0;
    gp->words.w0 = 0xFB000000;
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w0 = 0xFA000000;
    gp->words.w1 = 0x28282800;
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w1 = (u32)D_83E027C0;
    gp->words.w0 = 0x07020010;
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w0 = ((x1 & 0x3FF) << 0xE) | 0xF6000000 | ((y1 & 0x3FF) * 4);
    gp->words.w1 = ((x0 & 0x3FF) << 0xE) | ((y0 & 0x3FF) * 4);
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w0 = (((s32)((f32)x0 * 4.0f) & 0xFFF) << 0xC) | 0xED000000 | ((s32)((f32)y0 * 4.0f) & 0xFFF);
    gp->words.w1 = (((s32)((f32)x1 * 4.0f) & 0xFFF) << 0xC) | ((s32)((f32)y1 * 4.0f) & 0xFFF);

    D_overlay_62_03E029B4 = (D_overlay_62_03E029C4 - (s32)D_overlay_62_03E029A8) + 3;
    fontUseFont(2);
    fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
    gp = frontgfx;
    frontgfx = gp + 1;
    gp->words.w0 = 0xE7000000;
    gp->words.w1 = 0;
    fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                (char *)*(s32 *)(front_text + D_overlay_62_03E028AC[gameType * 8 + D_overlay_62_03E029AC] * 4), 4);
    D_overlay_62_03E029B4 += 0xF;

    if (D_overlay_62_03E027F8 == 8) {
        if (D_overlay_62_03E029C8 != 0) {
            D_overlay_62_03E027F8 = D_overlay_62_03E029AC;
            amSndPlay(0x16D, 0, 0, 0);
            if (D_overlay_62_03E029AC != 7) {
                D_overlay_62_03E029C8 = 0;
            }
        } else if (D_overlay_62_03E029CC != 0 && D_overlay_62_03E029EC == 0 && D_overlay_62_03E029B8 >= 0x1E) {
            amSndPlay(0x16D, 0, 0, 0);
            mainTitlePageInit();
            D_overlay_62_03E029EC = 1;
        } else {
            sel = D_overlay_62_03E029AC;
            D_overlay_62_03E029D0 = sel;
            if (D_overlay_62_03E029E0 != 0) {
                if (sel == 6) {
                    sel = 1;
                    D_overlay_62_03E029AC = 1;
                } else {
                    D_overlay_62_03E029AC = sel + 2;
                    sel = sel + 2;
                }
            }
            if (D_overlay_62_03E029DC != 0) {
                if (sel == 1) {
                    D_overlay_62_03E029AC = 6;
                    sel = 6;
                } else {
                    D_overlay_62_03E029AC = sel - 2;
                    sel = sel - 2;
                }
            }
            v1 = sel - 1;
            if (D_overlay_62_03E029E4 != 0) {
                D_overlay_62_03E029AC = v1;
                sel = v1;
            }
            if (D_overlay_62_03E029E8 != 0) {
                v1 = sel + 1;
                D_overlay_62_03E029AC = v1;
                sel = v1;
            }
            if (sel < 0) {
                sel = 7;
                D_overlay_62_03E029AC = 7;
            } else if (sel >= 8) {
                sel = 0;
                D_overlay_62_03E029AC = 0;
            }
            v1 = D_overlay_62_03E028AC[gameType * 8 + sel];
            if (v1 == -1) {
                do {
                    if (D_overlay_62_03E029DC != 0) {
                        if (sel == 1) {
                            D_overlay_62_03E029AC = 6;
                        } else {
                            D_overlay_62_03E029AC = sel - 2;
                        }
                        sel = D_overlay_62_03E029AC;
                        v1 = D_overlay_62_03E028AC[gameType * 8 + sel];
                    } else if (D_overlay_62_03E029E0 != 0) {
                        if (sel == 6) {
                            D_overlay_62_03E029AC = 1;
                        } else {
                            D_overlay_62_03E029AC = sel + 2;
                        }
                        sel = D_overlay_62_03E029AC;
                        v1 = D_overlay_62_03E028AC[gameType * 8 + sel];
                    } else {
                        n = sel - 1;
                        if (D_overlay_62_03E029E4 != 0) {
                            v1 = D_overlay_62_03E028AC[gameType * 8 + n];
                            D_overlay_62_03E029AC = n;
                            sel = n;
                        } else {
                            n = sel + 1;
                            if (D_overlay_62_03E029E8 != 0) {
                                v1 = D_overlay_62_03E028AC[gameType * 8 + n];
                                D_overlay_62_03E029AC = n;
                                sel = n;
                            }
                        }
                    }
                } while (v1 == -1);
            }
            if (sel != D_overlay_62_03E029D0) {
                amSndPlay(0x16B, 0, D_overlay_62_03E029E8, D_overlay_62_03E029E4);
            }
        }
    } else if (D_overlay_62_03E027F8 == 0) {
        if (D_overlay_62_03E029E4 != 0) {
            if (gameType == 0) {
                if (*(u8 *)((u8 *)&globalflags + 0x6B) != 0) {
                    gameType = 2;
                    amSndPlay(0x16C, 0, 0, 0);
                } else if (*(u8 *)((u8 *)&globalflags + 0x6A) != 0) {
                    gameType = 1;
                    amSndPlay(0x16C, 0, 0, 0);
                }
            } else if (gameType == 1) {
                gameType = 0;
                amSndPlay(0x16C, 0, 0, 0);
            } else if (D_800FF382 != 0) { /* = globalflags+0x6A */
                gameType = 1;
                amSndPlay(0x16C, 0, 0, 0);
            } else {
                gameType = 0;
                amSndPlay(0x16C, 0, 0, 0);
            }
        }
        if (D_overlay_62_03E029E8 != 0) {
            if (gameType == 0) {
                if (*(u8 *)((u8 *)&globalflags + 0x6A) != 0) {
                    gameType = 1;
                    amSndPlay(0x16C, 0, 0, 0);
                } else if (*(u8 *)((u8 *)&globalflags + 0x6B) != 0) {
                    gameType = 2;
                    amSndPlay(0x16C, 0, 0, 0);
                }
            } else if (gameType == 2) {
                gameType = 0;
                amSndPlay(0x16C, 0, 0, 0);
            } else if (*(u8 *)((u8 *)&globalflags + 0x6B) != 0) {
                gameType = 2;
                amSndPlay(0x16C, 0, 0, 0);
            } else {
                gameType = 0;
                amSndPlay(0x16C, 0, 0, 0);
            }
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4, (char *)D_overlay_62_03E029F0[gameType], 4);
        if (D_overlay_62_03E029CC != 0) {
            D_overlay_62_03E027F8 = 8;
        }
    }

    if (D_overlay_62_03E02960 <= *(f32 *)(obj + 0x28)) {
        D_overlay_62_03E02804[0] = gameType;
    }
    switch (gameType) {
    case 0:
        func_overlay_62_03E01158_1F80E38(arg0, 0); /* asm: a1 not set */
        break;
    case 1:
        func_overlay_62_03E01A48_1F81728(arg0, 0); /* asm: a1 not set */
        break;
    case 2:
        func_overlay_62_03E0228C_1F81F6C(arg0);
        break;
    }
    camSetScissor(&frontgfx);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o62/overlay_62/frontMultiModeSelect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Multiplayer deathmatch option selector (level / type / time / kills / life / object list / radar / start).
// cf. func_overlay_62_03E01A48_1F81728 (race-option selector), same overall shape.
// D_overlay_62_03E02828 = 4-byte level entries (u16 flags @0 masked by globalflags+0x68, s16 multiLevelChoice @2).
// The asm passes a2/a3 to amSndPlay / amTuneSetFade without setting them on most paths; 0 is passed instead.
void func_overlay_62_03E01158_1F80E38(s32 arg0, s32 arg2) {
    char sp38[0x100];
    u8 *entry;
    u16 mask;
    s8 nxt;
    s8 prevLevel;
    s8 v1;
    s8 val;
    u8 v0;

    mask = *(u16 *)((u8 *)&globalflags + 0x68);

    entry = D_overlay_62_03E02828 + deathMatchLevel * 4;
    if (*(u16 *)entry != 0 && !(*(u16 *)entry & mask)) {
        nxt = deathMatchLevel + 1;
        do {
            deathMatchLevel = nxt;
            if (deathMatchLevel >= 8) {
                deathMatchLevel = 0;
            }
            entry = D_overlay_62_03E02828 + deathMatchLevel * 4;
            nxt = deathMatchLevel + 1;
        } while (*(u16 *)entry != 0 && !(*(u16 *)entry & mask));
    }
    multiLevelChoice = *(s16 *)(entry + 2);

    switch (D_overlay_62_03E027F8) {
    case 2:
        if (D_overlay_62_03E029E4 != 0 && deathMatchType > 0) {
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            deathMatchType -= 1;
        }
        v1 = deathMatchType;
        if (D_overlay_62_03E029E8 != 0 && v1 < 2) {
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            v1 = deathMatchType + 1;
            deathMatchType = v1;
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *)D_overlay_62_03E02A00[v1], 4);
        break;
    case 4:
        prevLevel = deathMatchLevel;
        if (D_overlay_62_03E029E4 != 0) {
            nxt = deathMatchLevel - 1;
            do {
                deathMatchLevel = nxt;
                if (deathMatchLevel < 0) {
                    deathMatchLevel = 7;
                }
                entry = D_overlay_62_03E02828 + deathMatchLevel * 4;
                nxt = deathMatchLevel - 1;
            } while (*(u16 *)entry != 0 && !(*(u16 *)entry & mask));
        } else {
            nxt = deathMatchLevel + 1;
            if (D_overlay_62_03E029E8 != 0) {
                do {
                    deathMatchLevel = nxt;
                    if (deathMatchLevel >= 8) {
                        deathMatchLevel = 0;
                    }
                    entry = D_overlay_62_03E02828 + deathMatchLevel * 4;
                    nxt = deathMatchLevel + 1;
                } while (*(u16 *)entry != 0 && !(*(u16 *)entry & mask));
            }
        }
        if (prevLevel != deathMatchLevel) {
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        entry = D_overlay_62_03E02828 + deathMatchLevel * 4;
        multiLevelChoice = *(s16 *)(entry + 2);
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *)D_overlay_62_03E02A10[deathMatchLevel], 4);
        break;
    case 6:
        if (D_overlay_62_03E029E4 != 0 && deathMatchObjectList > 0) {
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            deathMatchObjectList -= 1;
        }
        v1 = deathMatchObjectList;
        if (D_overlay_62_03E029E8 != 0 && v1 < 2) {
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            deathMatchObjectList += 1;
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *)D_overlay_62_03E02A30[deathMatchObjectList], 4);
        break;
    case 1:
        switch (deathMatchType) {
        case 0:
            if (D_overlay_62_03E029E4 != 0 && deathMatchTime >= 2) {
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
                deathMatchTime -= 1;
            }
            val = deathMatchTime;
            if (D_overlay_62_03E029E8 != 0 && val < 0x1D) {
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
                deathMatchTime = val + 1;
                val = deathMatchTime;
            }
            if (val == 1) {
                sprintf(sp38, D_overlay_62_03E028F0, val, *(s32 *)(front_text + 0x52C));
            } else {
                sprintf(sp38, D_overlay_62_03E028F8, val, *(s32 *)(front_text + 0x528));
            }
            break;
        case 1:
            if (D_overlay_62_03E029E4 != 0 && deathMatchKills >= 2) {
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
                deathMatchKills -= 1;
            }
            val = deathMatchKills;
            if (D_overlay_62_03E029E8 != 0 && val < 0x14) {
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
                deathMatchKills = val + 1;
                val = deathMatchKills;
            }
            if (val == 1) {
                sprintf(sp38, D_overlay_62_03E02900, val, *(s32 *)(front_text + 0x53C));
            } else {
                sprintf(sp38, D_overlay_62_03E02908, val, *(s32 *)(front_text + 0x538));
            }
            break;
        case 2:
            if (D_overlay_62_03E029E4 != 0 && deathMatchLife >= 2) {
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
                deathMatchLife -= 1;
            }
            val = deathMatchLife;
            if (D_overlay_62_03E029E8 != 0 && val < 9) {
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
                deathMatchLife = val + 1;
                val = deathMatchLife;
            }
            if (val == 1) {
                sprintf(sp38, D_overlay_62_03E02910, val, *(s32 *)(front_text + 0x534));
            } else {
                sprintf(sp38, D_overlay_62_03E02918, val, *(s32 *)(front_text + 0x530));
            }
            break;
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4, sp38, 4);
        break;
    case 3:
        if (D_overlay_62_03E029E4 != 0 && (s32)radarMode > 0) {
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            radarMode -= 1;
        }
        v0 = radarMode;
        if (D_overlay_62_03E029E8 != 0) {
            if ((s32)v0 <= 0) {
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
                radarMode = radarMode + 1;
                v0 = radarMode;
            }
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *)D_overlay_62_03E02A40[v0], 4);
        break;
    case 7:
        if (D_overlay_62_03E029C8 != 0) {
            okayed = 1;
            amTuneSetFade(0.5f, 0, 0, 0, 0); /* asm: only a0/a1 set here */
            gameoverFade = 0;
            D_800FF1BA = 0;
            D_800FF1BC = 0;
            D_800FF1BE = 0;
            currentGameTime = 0;
            multiFinished = 0;
            mainRefreshMultiPlayer();
            mainChangeCameras(numberOfPlayers);
            mainChangeLevel((s32)multiLevelChoice, 0, 0, 0x10, 1, 0);
            mainSetMode(0);
        }
        break;
    }

    multiGameType = (s8)D_overlay_62_03E02850[deathMatchType];
    multiGameTime = deathMatchTime * 0xE10;
    multiGameLife = deathMatchLife;
    multiGameTarget = deathMatchKills;
    multiObjectList = deathMatchObjectList;
    D_overlay_62_03E028AE = D_overlay_62_03E02848[deathMatchType];
    D_overlay_62_03E02804[2] = (u8)(deathMatchType + 1);
    D_overlay_62_03E02804[4] = 1;
    D_overlay_62_03E02804[6] = (u8)(deathMatchObjectList + 1);
    D_overlay_62_03E02804[5] = 0;
    D_overlay_62_03E02804[3] = 1;
    D_overlay_62_03E02804[1] = (u8)D_overlay_62_03E02820[deathMatchType];
    if ((D_overlay_62_03E029CC != 0) || (D_overlay_62_03E029C8 != 0)) {
        amSndPlay(0x16D, 0, 0, 0); /* asm: a2/a3 not set here */
        D_overlay_62_03E027F8 = 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o62/overlay_62/func_overlay_62_03E01158_1F80E38.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Multiplayer race-option selector (level / type / laps / time / pickups / start boost).
// Named from relocated asm: raceGame* globals, D_overlay_62_03E0285C = 6-byte level table
// (u16 flags @0 & D_800FF382, s16 multiLevelChoice @2, u8 raceGameSingleScreen @4).
// asm passes a2 = 6 and a3 = 3 (level-wrap constant) / incoming a3 only on some paths;
// amSndPlay/amTuneSetFade calls below pad the registers the asm does not set.
void func_overlay_62_03E01A48_1F81728(s32 arg0, s32 arg3) {
    char sp30[0x100];
    s32 var_a3;
    s8 level;
    s8 nxt;
    s8 type;
    u8 *entry;

    var_a3 = arg3;
    level = raceGameLevel;
    entry = D_overlay_62_03E0285C + level * 6;
    if (!(*(u16 *)entry & D_800FF382)) {
        nxt = level + 1;
        do {
            raceGameLevel = nxt;
            if (raceGameLevel >= 4) {
                raceGameLevel = 0;
            }
            entry = D_overlay_62_03E0285C + raceGameLevel * 6;
            nxt = raceGameLevel + 1;
        } while (!(*(u16 *)entry & D_800FF382));
    }
    multiLevelChoice = *(s16 *)(entry + 2);
    raceGameSingleScreen = entry[4];

    switch (D_overlay_62_03E027F8) {
    case 2:
        if (D_overlay_62_03E029E4 != 0) {
            var_a3 = 3;
            nxt = level - 1;
            do {
                raceGameLevel = nxt;
                if (raceGameLevel < 0) {
                    raceGameLevel = 3;
                }
                entry = D_overlay_62_03E0285C + raceGameLevel * 6;
                nxt = raceGameLevel - 1;
            } while (!(*(u16 *)entry & D_800FF382));
        } else {
            nxt = level + 1;
            if (D_overlay_62_03E029E8 != 0) {
                do {
                    raceGameLevel = nxt;
                    if (raceGameLevel >= 4) {
                        raceGameLevel = 0;
                    }
                    entry = D_overlay_62_03E0285C + raceGameLevel * 6;
                    nxt = raceGameLevel + 1;
                } while (!(*(u16 *)entry & D_800FF382));
            }
        }
        if (level != raceGameLevel) {
            amSndPlay(0x16C, 0, 6, var_a3);
            entry = D_overlay_62_03E0285C + raceGameLevel * 6;
        }
        multiLevelChoice = *(s16 *)(entry + 2);
        raceGameSingleScreen = entry[4];
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *)D_overlay_62_03E02A48[raceGameLevel], 4);
        break;
    case 4:
        if (D_overlay_62_03E029E4 != 0) {
            raceGameType -= 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        if (D_overlay_62_03E029E8 != 0) {
            raceGameType += 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        type = raceGameType;
        if (type < 0) {
            raceGameType = 1;
            type = 1;
        }
        if (type >= 2) {
            raceGameType = 0;
            type = 0;
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *)D_overlay_62_03E02A58[type], 4);
        break;
    case 6:
        switch (raceGameType) {
        case 0:
            if (D_overlay_62_03E029E4 != 0) {
                raceGameLaps -= 1;
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            }
            if (D_overlay_62_03E029E8 != 0) {
                raceGameLaps += 1;
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            }
            if (raceGameLaps <= 0) {
                raceGameLaps = 0x32;
            }
            if (raceGameLaps >= 0x33) {
                raceGameLaps = 1;
            }
            sprintf(sp30, D_overlay_62_03E02920, *(s32 *)(front_text + 0x554), raceGameLaps);
            break;
        case 1:
            if (D_overlay_62_03E029E4 != 0) {
                raceGameTime -= 1;
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            }
            if (D_overlay_62_03E029E8 != 0) {
                raceGameTime += 1;
                amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
            }
            if (raceGameTime <= 0) {
                raceGameTime = 0x3C;
            }
            if (raceGameTime >= 0x3D) {
                raceGameTime = 1;
            }
            if (raceGameTime == 1) {
                sprintf(sp30, D_overlay_62_03E02928, raceGameTime, *(s32 *)(front_text + 0x52C));
            } else {
                sprintf(sp30, D_overlay_62_03E02930, raceGameTime, *(s32 *)(front_text + 0x528));
            }
            break;
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4, sp30, 4);
        break;
    case 1:
        if (D_overlay_62_03E029E4 != 0) {
            raceGamePickups -= 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        if (D_overlay_62_03E029E8 != 0) {
            raceGamePickups += 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        if (raceGamePickups < 0) {
            raceGamePickups = 7;
        }
        if (raceGamePickups >= 8) {
            raceGamePickups = 0;
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *)*(s32 *)(front_text + 0x55C + raceGamePickups * 4), 4);
        break;
    case 3:
        if (D_overlay_62_03E029E4 != 0) {
            raceGameStartBoost -= 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        if (D_overlay_62_03E029E8 != 0) {
            raceGameStartBoost += 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        if (raceGameStartBoost < 0) {
            raceGameStartBoost = 0xA;
        }
        if (raceGameStartBoost >= 0xB) {
            raceGameStartBoost = 0;
        }
        sprintf(sp30, D_overlay_62_03E02938, *(s32 *)(front_text + 0x560), raceGameStartBoost);
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4, sp30, 4);
        break;
    case 7:
        if (D_overlay_62_03E029C8 != 0) {
            mainRefreshMultiPlayer();
            okayed = 1;
            amTuneSetFade(0.5f, 0, 0, 0, 0); /* asm: only a0/a1 set here */
            gameoverFade = 0;
            D_800FED62 = 3;
            D_800FF1BA = 0;
            D_800FEE02 = 3;
            D_800FF1BC = 0;
            D_800FEEA2 = 3;
            D_800FF1BE = 0;
            D_800FEF42 = 3;
            currentGameTime = 0;
            multiGameType = 4;
            multiFinished = 0;
            if (raceGameSingleScreen != 0) {
                mainChangeCameras(1);
            } else {
                mainChangeCameras(numberOfPlayers);
            }
            numberOfAI = 0;
            mainChangeLevel((s32)multiLevelChoice, 0, 0, 0x10, 1, 0);
            mainSetAnimGroup(0);
            mainSetMode(0);
        }
        break;
    }

    D_overlay_62_03E028C8 = D_overlay_62_03E02874[raceGameType];
    D_overlay_62_03E02804[4] = (u8)(raceGameType + 2);
    D_overlay_62_03E02804[2] = (u8)D_overlay_62_03E0281C[raceGameLevel];
    D_overlay_62_03E02804[1] = 5;
    D_overlay_62_03E02804[3] = 2;
    D_overlay_62_03E02804[5] = 0;
    D_overlay_62_03E02804[6] = (u8)D_overlay_62_03E02824[raceGameType];
    if ((D_overlay_62_03E029CC != 0) || (D_overlay_62_03E029C8 != 0)) {
        amSndPlay(0x16D, 0, 0, 0); /* asm: a2/a3 not set here */
        D_overlay_62_03E027F8 = 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o62/overlay_62/func_overlay_62_03E01A48_1F81728.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_62_03E0228C_1F81F6C(s32 arg0) {
    char sp30[0x100];
    s32 temp;
    s32 next;
    u8 *entry;

    temp = clayPigeonLevel;
    entry = D_overlay_62_03E02878 + temp * 8;
    if (!(*(u16 *)entry & D_800FF383)) {
        next = temp + 1;
        do {
            clayPigeonLevel = next;
            if (clayPigeonLevel >= 3) {
                clayPigeonLevel = 0;
            }
            entry = D_overlay_62_03E02878 + clayPigeonLevel * 8;
            next = clayPigeonLevel + 1;
        } while (!(*(u16 *)entry & D_800FF383));
    }
    multiLevelChoice = *(s16 *)(entry + 2);
    multiGameTime = *(s32 *)(entry + 4);

    switch (D_overlay_62_03E027F8) {
    case 2:
        if (D_overlay_62_03E029E4 != 0) {
            next = temp - 1;
            do {
                clayPigeonLevel = next;
                if (clayPigeonLevel < 0) {
                    clayPigeonLevel = 2;
                }
                entry = D_overlay_62_03E02878 + clayPigeonLevel * 8;
                next = clayPigeonLevel - 1;
            } while (!(*(u16 *)entry & D_800FF383));
        } else if (D_overlay_62_03E029E8 != 0) {
            next = temp + 1;
            do {
                clayPigeonLevel = next;
                if (clayPigeonLevel >= 3) {
                    clayPigeonLevel = 0;
                }
                entry = D_overlay_62_03E02878 + clayPigeonLevel * 8;
                next = clayPigeonLevel + 1;
            } while (!(*(u16 *)entry & D_800FF383));
        }
        if (temp != clayPigeonLevel) {
            amSndPlay(0x16C, 0, temp, 2);
            entry = D_overlay_62_03E02878 + clayPigeonLevel * 8;
        }
        multiLevelChoice = *(s16 *)(entry + 2);
        multiGameTime = *(s32 *)(entry + 4);
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *) D_overlay_62_03E02A60[clayPigeonLevel], 4);
        break;
    case 4:
        if (D_overlay_62_03E029E4 != 0) {
            clayPigeonAmmoChoice -= 1;
            amSndPlay(0x16C, 0, D_overlay_62_03E027F8, 2);
        }
        if (D_overlay_62_03E029E8 != 0) {
            clayPigeonAmmoChoice += 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        if (clayPigeonAmmoChoice < 0) {
            clayPigeonAmmoChoice = 4;
        }
        if (clayPigeonAmmoChoice >= 5) {
            clayPigeonAmmoChoice = 0;
        }
        clayPigeonAmmo = (s8) D_overlay_62_03E02890[clayPigeonAmmoChoice];
        if (clayPigeonAmmoChoice == 0) {
            sprintf(sp30, D_overlay_62_03E02940, *(s32 *)(front_text + 0x580), *(s32 *)(front_text + 0x584));
        } else {
            sprintf(sp30, D_overlay_62_03E02948, clayPigeonAmmo, *(s32 *)(front_text + 0x584));
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4, sp30, 4);
        break;
    case 6:
        if (D_overlay_62_03E029E4 != 0) {
            clayPigeonCursor -= 1;
            amSndPlay(0x16C, 0, D_overlay_62_03E027F8, 2);
        }
        if (D_overlay_62_03E029E8 != 0) {
            clayPigeonCursor += 1;
            amSndPlay(0x16C, 0, 0, 0); /* asm: a2/a3 not set here */
        }
        if (clayPigeonCursor < 0) {
            clayPigeonCursor = 2;
        }
        if (clayPigeonCursor >= 3) {
            clayPigeonCursor = 0;
        }
        fontPrintXY(&frontgfx, D_overlay_62_03E029C0, D_overlay_62_03E029B4,
                    (char *) D_overlay_62_03E02A68[clayPigeonCursor], 4);
        break;
    case 7:
        if (D_overlay_62_03E029C8 != 0) {
            okayed = 1;
            amTuneSetFade(0.5f, D_800FF383, 0, D_overlay_62_03E027F8, 2);
            gameoverFade = 0;
            D_800FF1BA = 0;
            D_800FF1BC = 0;
            D_800FF1BE = 0;
            currentGameTime = 0;
            multiGameType = 6;
            multiFinished = 0;
            mainRefreshMultiPlayer();
            mainChangeCameras(1);
            mainChangeLevel((s32) multiLevelChoice, 0, 0, 0x10, 1, 0);
            mainSetAnimGroup(0);
            mainSetMode(0);
        }
        break;
    }

    D_overlay_62_03E02804[2] = 6;
    D_overlay_62_03E02804[4] = 4;
    D_overlay_62_03E02804[6] = 7;
    D_overlay_62_03E02804[1] = 0;
    D_overlay_62_03E02804[3] = 0;
    D_overlay_62_03E02804[5] = 0;
    if ((D_overlay_62_03E029CC != 0) || (D_overlay_62_03E029C8 != 0)) {
        amSndPlay(0x16D, 0, 0, 0); /* asm: a2/a3 not set here */
        D_overlay_62_03E027F8 = 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o62/overlay_62/func_overlay_62_03E0228C_1F81F6C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupMultiModeSelect(void) {
    freeFrontEndList(D_overlay_62_03E027E4);
    freeFrontEndList(D_overlay_62_03E027D0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o62/overlay_62/frontCleanupMultiModeSelect.s")
#endif
