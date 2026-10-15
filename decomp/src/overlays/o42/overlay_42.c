#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_overlay_42_02A02CB0;            /* init done flag */
extern s16 D_overlay_42_02A02CA0[];          /* front end list (freeFrontEndList arg) */
extern s16 D_overlay_42_02A02CA8[];          /* front end list (setupFrontEndList arg) */
extern u8 D_overlay_42_02A02CBC[];           /* float table, zeroed in init */
extern u8 D_overlay_42_02A02E04[];           /* end of float table */
extern s32 D_overlay_42_02A02F10;
extern s8 D_overlay_42_02A02F40;
extern s8 *D_overlay_42_02A02F58;
extern s16 D_overlay_42_02A02F5C;
extern s8 D_overlay_42_02A02F5E;
extern s8 D_overlay_42_02A02F5F;
extern s8 D_overlay_42_02A02F60;
extern s8 D_overlay_42_02A02FA0;
extern f32 D_overlay_42_02A02FA4;
extern u8 D_overlay_42_02A02FA8[];           /* mainLoadAllGames target */
extern s16 D_overlay_42_02A04EF8;
extern s8 D_overlay_42_02A04F00[];           /* 8+ byte tilt entry table */
extern u8 D_overlay_42_02A02F18[];           /* tilt list */
extern u8 currentobjects[];
void amTunePlay(u8 seqID);
void loadFrontEndList(s16 *arg0);
void freeFrontEndList(s16 *arg0);
void setupFrontEndList(s16 *arg0);
/* asm passes 2 args; main.c definition takes 1 */
void mainLoadAllGames(void *arg0, s32 arg1);
/* frontKeyboard: extra globals, prototypes and helper macros (decomp: externs) */
extern s32 D_overlay_42_02A02CB4;
extern s32 D_overlay_42_02A02CB8;
extern s16 D_overlay_42_02A02E0C;
extern s8 D_overlay_42_02A02E10;
extern char D_overlay_42_02A02E50[];           /* name-entry format strings */
extern char D_overlay_42_02A02E58[];
extern char D_overlay_42_02A02E68[];
extern char D_overlay_42_02A02E70[];
extern char D_overlay_42_02A02E78[];
extern char D_overlay_42_02A02E80[];
extern char D_overlay_42_02A02E88[];
extern char D_overlay_42_02A02E90[];
extern char D_overlay_42_02A02E98[];
extern char D_overlay_42_02A02EA0[];
extern char D_overlay_42_02A02EA4[];
extern char D_overlay_42_02A02EA8[];
extern f32 D_overlay_42_02A02ED0;
extern f32 D_overlay_42_02A02ED4;
extern f32 D_overlay_42_02A02ED8;
extern f32 D_overlay_42_02A02EDC;
extern f32 D_overlay_42_02A02EE0;
extern u8 *D_overlay_42_02A02F38;
extern s32 D_overlay_42_02A02F68;
extern s32 D_overlay_42_02A02F6C;
extern s32 D_overlay_42_02A02F70[];
extern s32 D_overlay_42_02A02F84;
extern s32 D_overlay_42_02A02F9C;
extern s8 D_overlay_42_02A02FA1;
extern s8 D_overlay_42_02A02FA2;
extern s8 D_overlay_42_02A02FA3;
extern void *front_text;
extern Gfx *frontgfx;
extern s32 frontmtx;
extern s8 frontJoyDx[4];
extern s8 frontJoyDy[4];
extern void *D_800FF64C;
extern void *D_800FF650;
extern u8 D_800FB109;
extern s16 D_800FFE00;
extern s16 D_800FFE02;
extern f32 D_800FFE08;
extern f32 D_800FFE0C;
extern f32 D_800FFE10;
extern f32 D_800FFE14;
extern u8 cooperativeGame;
extern s32 objtrans;
extern s32 numberOfJoypads;
void pauseClearScreen(void);
void fontUseFont(s32 font);
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void fontPrintXY(Gfx **displayList, s32 xpos, s32 ypos, char *text, s32 alignmentFlags);
void camSetNo(s32 arg0);
void camSetView(Gfx **dlist, s32 arg1);
void camSetFOV(f32 fov, s32 force);
void camStandardPersp(Gfx **dlist, void *mtx, s32 arg2, s32 arg3);
void camOverrideProjScales(f32 arg0, f32 arg1);
void frontDrawObj(s32 arg0);
void modGenAnimMatrices(void *arg0, s32 arg1, void *arg2, f32 arg3, f32 arg4);
void matrixID(f32 (*)[4]);
void matrixPitch(s16 arg0, f32 (*)[4]);
s32 mainGetGameFlagGamePtr(void *game, s32 flag);
void mainDeleteGame(s32 arg0);
void mainSaveGame(s32 arg0);
void mainSetDefaultGame(Game *game);
void mainTitlePageInit(void);
void frontCharSelectSetQuitMode(s32 arg0);
void amSndPlay(u16 soundID, void *handlePtr);
f32 Sinf(s16 angle);
void func_overlay_42_02A02C8C_1F61D54(s32 arg0);
/* FRONT_GFX_PUT: write one Gfx (w0, w1) at frontgfx and step it by one Gfx (8 bytes) */
#define FRONT_GFX_PUT(w0v, w1v) do { frontgfx->words.w0 = (w0v); frontgfx->words.w1 = (w1v); frontgfx++; } while (0)
/* FRONT_TEXT_PTR: pointer stored in the front_text string table at byte offset off */
#define FRONT_TEXT_PTR(off) (*(char **) ((u8 *) front_text + (off)))
/* SAVE_SLOT: save slot k (0x538 bytes each) inside D_overlay_42_02A02FA8 */
#define SAVE_SLOT(k) (D_overlay_42_02A02FA8 + (k) * 0x538)
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontKeyboardInit(void) {
    u8 *p;
    s8 *tbl;

    if (D_overlay_42_02A02CB0 == 0) {
        D_overlay_42_02A02CB0 = 1;
        loadFrontEndList(D_overlay_42_02A02CA0);
        setupFrontEndList(D_overlay_42_02A02CA8);
        *(s16 *) (currentobjects + 0x3E6) = 0x97;
        *(s16 *) (currentobjects + 0x660) = -0x8000;
        D_overlay_42_02A02F5C = 0x7FF0;
        *(s16 *) (currentobjects + 0x680) = -0x8000;

        p = D_overlay_42_02A02CBC;
        do {
            p += 8;
            *(f32 *) (p - 4) = 0.0f;
        } while ((u32) p < (u32) D_overlay_42_02A02E04);

        D_overlay_42_02A02F58 = &D_overlay_42_02A02F40;
        D_overlay_42_02A02F40 = 0;
        D_overlay_42_02A02FA0 = 0;
        D_overlay_42_02A02FA4 = -20.0f;
        D_overlay_42_02A02F5E = 0;
        D_overlay_42_02A02F5F = 0;
        D_overlay_42_02A02F60 = 0;
        D_overlay_42_02A04EF8 = 0;
        mainLoadAllGames(D_overlay_42_02A02FA8, -0x8000);

        /* 4 entries of (-1, 0) pairs; entry 2 is written at byte offset 4 */
        tbl = D_overlay_42_02A04F00;
        tbl[0] = -1;
        tbl[1] = 0;
        tbl[2] = -1;
        tbl[3] = 0;
        tbl[4] = -1;
        tbl[5] = 0;
        tbl[6] = -1;
        tbl[7] = 0;
        tbl[8] = -1;
        tbl[9] = 0;
        tbl[10] = -1;
        tbl[11] = 0;

        amTunePlay(2);
        D_overlay_42_02A02F10 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o42/overlay_42/frontKeyboardInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontKeyboardCleanup(void) {
    freeFrontEndList(D_overlay_42_02A02CA0);
    D_overlay_42_02A02CB0 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o42/overlay_42/frontKeyboardCleanup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* frontKeyboard (overlay 42): on-screen name-entry keyboard.
 * Draft built from m2c output, rewritten and verified section by section against the asm.
 * Jump table 1 (FA0 dispatch, states 0..8): 0->0x510 1->0x2060 2->0x1E68 3->0xA28
 *   4->0xB7C 5->0x17AC 6->0x1D48 7->0x169C 8->0x1408; states >= 9 fall through (no-op).
 * Jump table 2 (FA0 dispatch at the end): 0->0x2B78 1,2->0x2B14 3,6,7->none 4->0x2BA4
 *   5->0x2BFC 8->0x2BD0; the rest falls through.
 * Gfx pointer step is one Gfx (8 bytes).
 */
void frontKeyboard(s32 arg0) {
    s32 dxRight;      /* sp1A8: stick X >= 0x21 */
    s32 dxLeft;       /* sp1AC: stick X < -0x20 */
    s32 sndFlag;      /* sp110: play move sound at the end */
    s32 dyNeg;        /* var_s7: stick Y < -0x20 */
    s32 dyPos;        /* var_s6: stick Y >= 0x21 */
    s32 countFree;    /* var_s0: save slots with unk3 == -1 */
    s32 n, i, tmp, w, a0v, sp18C, ch, t1;
    f32 f2, sp124, sp128, sp12C, oldObj688;
    f32 sp130[4][4];
    char spE4[0x2C];
    u8 *anim;         /* sp178 */
    void *sp17C;
    u8 *entry, *obj, *tv, *dst, *dst2, *src, *game;
    s8 *tbl;
    s32 tempS2;

    sndFlag = 0;
    if (D_overlay_42_02A02CB0 != 0) {
        if (D_overlay_42_02A02F10 < 0x1E) {
            D_overlay_42_02A02F10 += arg0;
        }
        pauseClearScreen();
        fontUseFont(2);
        fontColour(0, 0, 0xFF, 0xFF, D_overlay_42_02A04EF8);
        texDPInit(&frontgfx);
        FRONT_GFX_PUT(0xBC000002, 0);
        FRONT_GFX_PUT(0xB6000000, 0x1001);
        FRONT_GFX_PUT(0xF8000000, -1U);
        FRONT_GFX_PUT(0xBC000008, 0x64009867);
        FRONT_GFX_PUT(0xE7000000, 0);
        camSetNo(0);
        camSetView(&frontgfx, 0);
        camSetFOV(52.0f, 1);

        /* tilt list at D_overlay_42_02A02F18: 0x2006, F5C, 0x1000 */
        D_overlay_42_02A02F38 = D_overlay_42_02A02F18;
        *(s16 *) D_overlay_42_02A02F38 = 0x2006;
        D_overlay_42_02A02F38 += 2;
        *(s16 *) D_overlay_42_02A02F38 = D_overlay_42_02A02F5C;
        D_overlay_42_02A02F38 += 2;
        *(s16 *) D_overlay_42_02A02F38 = 0x1000;
        D_overlay_42_02A02F38 += 2;

        /* stick for the current player */
        dxRight = 0;
        dxLeft = 0;
        dyNeg = 0;
        dyPos = 0;
        if (frontJoyDx[D_overlay_42_02A02CB4] < -0x20) {
            dxLeft = 1;
        } else if (frontJoyDx[D_overlay_42_02A02CB4] >= 0x21) {
            dxRight = 1;
        }
        if (frontJoyDy[D_overlay_42_02A02CB4] < -0x20) {
            dyNeg = 1;
        } else if (frontJoyDy[D_overlay_42_02A02CB4] >= 0x21) {
            dyPos = 1;
        }

        camStandardPersp(&frontgfx, &frontmtx, dxRight, dxLeft);
        camOverrideProjScales(1.0f, 1.0f);
        camSetFOV(52.0f, 1);
        camStandardPersp(&frontgfx, &frontmtx, 0, 0); /* asm: a2/a3 stale, passed as 0 */
        frontDrawObj(0x1F);

        /* anim = *(*(D_800FF64C + 0x6C)); anim->unk0 is the first word */
        anim = *(u8 **) (*(u8 **) ((u8 *) D_800FF64C + 0x6C));
        anim[0xA] = (u8) arg0;
        modGenAnimMatrices(anim, *(s32 *) anim, D_800FF64C, 1.0f, 0.0f);
        anim[0xA] = 0;
        frontDrawObj(0x33);

        /* bounce of the highlight alpha, step in E10 */
        D_overlay_42_02A02E0C += D_overlay_42_02A02E10 * arg0;
        if (D_overlay_42_02A02E0C >= 0x100) {
            D_overlay_42_02A02E0C = 0x1FE - D_overlay_42_02A02E0C;
            D_overlay_42_02A02E10 = -D_overlay_42_02A02E10;
        } else if (D_overlay_42_02A02E0C < 0) {
            D_overlay_42_02A02E0C = -D_overlay_42_02A02E0C;
            D_overlay_42_02A02E10 = -D_overlay_42_02A02E10;
        }

        /* save slots: 6 entries of 0x538 bytes, count the empty ones (unk3 == -1) */
        countFree = 0;
        for (i = 0; i < 6; i++) {
            if ((s8) SAVE_SLOT(i)[3] == -1) {
                countFree += 1;
            }
        }

        switch (D_overlay_42_02A02FA0) {
        case 0:
            /* F5C eases toward 0x8000, arg0 frames (unrolled x4) */
            n = 0;
            if (arg0 > 0) {
                tmp = arg0 & 3;
                if (tmp != 0) {
                    do {
                        n += 1;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                    } while (tmp != n);
                    if (n != arg0) {
                        goto c0_f5c_unrolled;
                    }
                } else {
c0_f5c_unrolled:
                    do {
                        n += 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                    } while (n != arg0);
                }
            }
            if (D_overlay_42_02A02F5C >= 0x7A01) {
                D_overlay_42_02A04EF8 += arg0 * 4;
                if (D_overlay_42_02A04EF8 >= 0x100) {
                    D_overlay_42_02A04EF8 = 0xFF;
                }
                /* char/flag pairs for the 6 name slots: 0x2C + i, flag 1 */
                for (i = 0; i < 6; i++) {
                    D_overlay_42_02A04F00[i * 2] = i + 0x2C;
                    D_overlay_42_02A04F00[i * 2 + 1] = 1;
                }
                if (dxRight != 0) {
                    D_overlay_42_02A02F5F += 1;
                    if (D_overlay_42_02A02F5F >= 6) {
                        D_overlay_42_02A02F5F = 0;
                    }
                    sndFlag = 1;
                }
                if (dxLeft != 0) {
                    D_overlay_42_02A02F5F -= 1;
                    sndFlag = 1;
                    if (D_overlay_42_02A02F5F < 0) {
                        D_overlay_42_02A02F5F = 5;
                    }
                }
                if (joyGetPressed(D_overlay_42_02A02CB4) & 0x8000) {
                    D_overlay_42_02A02FA0 = 3;
                    amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    D_overlay_42_02A02F6C = -0x1000;
                    D_overlay_42_02A02F68 = 0;
                    w = -0x2000;
                    for (i = 0; i < 12; i++) {
                        D_overlay_42_02A02F70[i] = w;
                        w -= 0x1000;
                    }
                }
                /* FA4 eases toward 22.0, arg0 frames (unrolled x4) */
                n = 0;
                if (arg0 > 0) {
                    tmp = arg0 & 3;
                    if (tmp != 0) {
                        do {
                            n += 1;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (tmp != n);
                        if (n != arg0) {
                            goto c0_fa4_unrolled;
                        }
                    } else {
c0_fa4_unrolled:
                        do {
                            n += 4;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (n != arg0);
                    }
                }
                FRONT_GFX_PUT(0xE7000000, 0);
                D_overlay_42_02A02F5E = D_overlay_42_02A02F5F;
                sprintf(spE4, (char *) D_overlay_42_02A02E50, FRONT_TEXT_PTR(0x700), D_overlay_42_02A02F5E + 1);
                fontPrintXY(&frontgfx, 0xA0, 0x68, spE4, 4);
                if ((s8) SAVE_SLOT(D_overlay_42_02A02F5E)[3] == -1) {
                    fontPrintXY(&frontgfx, 0xA0, 0x77, FRONT_TEXT_PTR(0x704), 4);
                } else {
                    fontPrintXY(&frontgfx, 0xA0, 0x77, SAVE_SLOT(D_overlay_42_02A02F5E) + 0x51C, 4);
                    /* playtime of the slot: u32 seconds -> h / m */
                    {
                        f32 tf = (f32) (u32) *(s32 *) (SAVE_SLOT(D_overlay_42_02A02F5E) + 0x518) / 60.0f;
                        s32 hh = (s32) tf / 3600;
                        s32 mm = (s32) (tf - ((f32) hh * 3600.0f)) / 60;
                        if (hh >= 0x3E8) {
                            hh = 0x3E7;
                            mm = 0x3B;
                        }
                        sprintf(spE4, (char *) D_overlay_42_02A02E58, FRONT_TEXT_PTR(0x720), hh, mm);
                        fontPrintXY(&frontgfx, 0xA0, 0x86, spE4, 4);
                    }
                }
                if ((joyGetPressed(D_overlay_42_02A02CB4) & 0x4000) && (D_overlay_42_02A02F10 >= 0x1E)) {
                    amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    mainTitlePageInit();
                    D_overlay_42_02A02FA0 = 9;
                }
            }
            func_overlay_42_02A02C8C_1F61D54(arg0);
            break;

        case 3:
            /* FA4 eases toward -20.0 */
            n = 0;
            if (arg0 > 0) {
                tmp = arg0 & 3;
                if (tmp != 0) {
                    do {
                        n += 1;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                    } while (tmp != n);
                    if (n != arg0) {
                        goto c3_fa4_unrolled;
                    }
                } else {
c3_fa4_unrolled:
                    do {
                        n += 4;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                    } while (n != arg0);
                }
            }
            if (D_overlay_42_02A02FA4 < D_overlay_42_02A02ED0) {
                if ((s8) SAVE_SLOT(D_overlay_42_02A02F5E)[3] == -1) {
                    D_overlay_42_02A02FA0 = 2;
                    D_overlay_42_02A02FA1 = 0;
                } else {
                    D_overlay_42_02A02FA0 = 4;
                    D_overlay_42_02A02F5F = 0;
                }
            }
            break;

        case 4:
            /* F5C eases toward 0x8000 (same as state 0) */
            n = 0;
            if (arg0 > 0) {
                tmp = arg0 & 3;
                if (tmp != 0) {
                    do {
                        n += 1;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                    } while (tmp != n);
                    if (n != arg0) {
                        goto c4_f5c_unrolled;
                    }
                } else {
c4_f5c_unrolled:
                    do {
                        n += 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x8000 - D_overlay_42_02A02F5C) >> 4;
                    } while (n != arg0);
                }
            }
            if (D_overlay_42_02A02F5C >= 0x7A01) {
                /* FA4 eases toward 22.0 */
                n = 0;
                if (arg0 > 0) {
                    tmp = arg0 & 3;
                    if (tmp != 0) {
                        do {
                            n += 1;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (tmp != n);
                        if (n != arg0) {
                            goto c4_fa4_unrolled_a;
                        }
                    } else {
c4_fa4_unrolled_a:
                        do {
                            n += 4;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (n != arg0);
                    }
                }
                D_overlay_42_02A04EF8 += arg0 * 4;
                if (D_overlay_42_02A04EF8 >= 0x100) {
                    D_overlay_42_02A04EF8 = 0xFF;
                }
                tbl = D_overlay_42_02A04F00;
                tbl[0] = 0x29;
                tbl[2] = 0x2A;
                tbl[4] = 0x2B;
                tbl[6] = -1;
                tbl[8] = -1;
                tbl[10] = -1;
                tbl[1] = 1;
                tbl[5] = 1;
                if (mainGetGameFlagGamePtr(SAVE_SLOT(D_overlay_42_02A02F5E), 3) != 0 && numberOfJoypads >= 2) {
                    tbl[6] = 0x32;
                    tbl[7] = 1;
                }
                tbl[3] = (countFree == 0) ? 0 : 1;
                if (mainGetGameFlagGamePtr(SAVE_SLOT(D_overlay_42_02A02F5E), 3) != 0 && D_800FB109 != 0) {
                    if (dxRight != 0) {
                        switch (D_overlay_42_02A02F5F) {
                        case 0:
                            D_overlay_42_02A02F5F = 3;
                            break;
                        case 3:
                            D_overlay_42_02A02F5F = 1;
                            break;
                        default:
                            D_overlay_42_02A02F5F += 1;
                            if (D_overlay_42_02A02F5F >= 3) {
                                D_overlay_42_02A02F5F = 0;
                            }
                            break;
                        }
                        if (D_overlay_42_02A02F5F == 1 && countFree == 0) {
                            D_overlay_42_02A02F5F = 2;
                        }
                        sndFlag = 1;
                    }
                    if (dxLeft != 0) {
                        sndFlag = 1;
                        if (D_overlay_42_02A02F5F != 0) {
                            if (D_overlay_42_02A02F5F != 1) {
                                if (D_overlay_42_02A02F5F != 2) {
                                    if (D_overlay_42_02A02F5F == 3) {
                                        D_overlay_42_02A02F5F = 0;
                                    }
                                } else if (countFree == 0) {
                                    D_overlay_42_02A02F5F = 3;
                                } else {
                                    D_overlay_42_02A02F5F = 1;
                                }
                            } else {
                                D_overlay_42_02A02F5F = 3;
                            }
                        } else {
                            D_overlay_42_02A02F5F = 2;
                        }
                    }
                } else {
                    if (D_overlay_42_02A02F5F == 3) {
                        D_overlay_42_02A02F5F = 0;
                    }
                    if (dxRight != 0) {
                        D_overlay_42_02A02F5F += 1;
                        if (D_overlay_42_02A02F5F >= 3) {
                            D_overlay_42_02A02F5F = 0;
                        }
                        if (D_overlay_42_02A02F5F == 1 && countFree == 0) {
                            D_overlay_42_02A02F5F = 2;
                        }
                        sndFlag = 1;
                    }
                    if (dxLeft != 0) {
                        D_overlay_42_02A02F5F -= 1;
                        sndFlag = 1;
                        if (D_overlay_42_02A02F5F < 0) {
                            D_overlay_42_02A02F5F = 2;
                        }
                        if (D_overlay_42_02A02F5F == 1 && countFree == 0) {
                            D_overlay_42_02A02F5F = 0;
                        }
                    }
                }
                switch (D_overlay_42_02A02F5F) {
                case 0:
                    sprintf(spE4, (char *) D_overlay_42_02A02E68, FRONT_TEXT_PTR(0x804), D_overlay_42_02A02F5E + 1);
                    break;
                case 1:
                    sprintf(spE4, (char *) D_overlay_42_02A02E70, FRONT_TEXT_PTR(0x70C), D_overlay_42_02A02F5E + 1);
                    break;
                case 2:
                    sprintf(spE4, (char *) D_overlay_42_02A02E78, FRONT_TEXT_PTR(0x708), D_overlay_42_02A02F5E + 1);
                    break;
                case 3:
                    sprintf(spE4, (char *) D_overlay_42_02A02E80, FRONT_TEXT_PTR(0x808), D_overlay_42_02A02F5E + 1);
                    break;
                }
                fontPrintXY(&frontgfx, 0xA0, 0x68, spE4, 4);
                fontPrintXY(&frontgfx, 0xA0, 0x77, SAVE_SLOT(D_overlay_42_02A02F5E) + 0x51C, 4);
                if (joyGetPressed(D_overlay_42_02A02CB4) & 0x8000) {
                    amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    if (D_overlay_42_02A02F5F != 0) {
                        if (D_overlay_42_02A02F5F != 1) {
                            if (D_overlay_42_02A02F5F != 2) {
                                if (D_overlay_42_02A02F5F == 3) {
                                    goto c4_copy_to_game;
                                }
                            } else {
                                D_overlay_42_02A02FA2 = 0;
                                D_overlay_42_02A02FA0 = 8;
                            }
                        } else {
                            D_overlay_42_02A02F5F = 0;
                            D_overlay_42_02A02F60 = D_overlay_42_02A02F5E;
                            t1 = D_overlay_42_02A02F5F + 1;
                            if ((s8) SAVE_SLOT(D_overlay_42_02A02F5F)[3] != -1) {
                                do {
                                    D_overlay_42_02A02F5F = t1;
                                    if (D_overlay_42_02A02F5F >= 6) {
                                        D_overlay_42_02A02F5F = 0;
                                    }
                                    t1 = D_overlay_42_02A02F5F + 1;
                                } while ((s8) SAVE_SLOT(D_overlay_42_02A02F5F)[3] != -1);
                            }
                            D_overlay_42_02A02FA0 = 5;
                        }
                    } else {
c4_copy_to_game:
                        amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                        /* copy save slot F5E (0x538 bytes) into the game struct */
                        game = (u8 *) mainGetGame();
                        src = SAVE_SLOT(D_overlay_42_02A02F5E);
                        dst = game;
                        n = 0x538;
                        do {
                            n -= 4;
                            dst[0] = src[0];
                            dst[1] = src[1];
                            dst[2] = src[2];
                            dst[3] = src[3];
                            dst += 4;
                            src += 4;
                        } while (n != 0);
                        if (D_overlay_42_02A02F5F == 0) {
                            cooperativeGame = 0;
                        } else {
                            cooperativeGame = 1;
                        }
                        mainChangeLevel(0x7F, 0, 0, 5, 1, 0);
                        frontCharSelectSetQuitMode(1);
                        D_overlay_42_02A02FA0 = 9;
                    }
                }
                if (joyGetPressed(D_overlay_42_02A02CB4) & 0x4000) {
                    amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    D_overlay_42_02A02FA0 = 7;
                }
                if (D_overlay_42_02A02F5C >= 0x7A01) {
                    n = 0;
                    if (arg0 > 0) {
                        tmp = arg0 & 3;
                        if (tmp != 0) {
                            do {
                                n += 1;
                                D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            } while (tmp != n);
                            if (n != arg0) {
                                goto c4_fa4_unrolled_b;
                            }
                        } else {
c4_fa4_unrolled_b:
                            do {
                                n += 4;
                                D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                                D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                                D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                                D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            } while (n != arg0);
                        }
                    }
                }
            }
            break;

        case 8:
            D_overlay_42_02A04EF8 += arg0 * 4;
            if (D_overlay_42_02A04EF8 >= 0x100) {
                D_overlay_42_02A04EF8 = 0xFF;
            }
            sprintf(spE4, (char *) D_overlay_42_02A02E88, FRONT_TEXT_PTR(0x708), D_overlay_42_02A02F5E + 1);
            fontPrintXY(&frontgfx, 0xA0, 0x68, spE4, 4);
            fontPrintXY(&frontgfx, 0xA0, 0x77, SAVE_SLOT(D_overlay_42_02A02F5E) + 0x51C, 4);
            if (D_overlay_42_02A02FA2 != 0) {
                fontColour(0, 0, 0xFF, 0xFF, (s32) (D_overlay_42_02A02E0C * D_overlay_42_02A04EF8) >> 8);
            } else {
                fontColour(0, 0, 0xFF, 0xFF, D_overlay_42_02A04EF8);
            }
            fontPrintXY(&frontgfx, 0x7D, 0x86, FRONT_TEXT_PTR(0xAC), 4);
            if (D_overlay_42_02A02FA2 == 0) {
                fontColour(0, 0, 0xFF, 0xFF, (s32) (D_overlay_42_02A02E0C * D_overlay_42_02A04EF8) >> 8);
            } else {
                fontColour(0, 0, 0xFF, 0xFF, D_overlay_42_02A04EF8);
            }
            fontPrintXY(&frontgfx, 0xC3, 0x86, FRONT_TEXT_PTR(0x8C), 4);
            if (dxLeft != 0 || dxRight != 0) {
                D_overlay_42_02A02FA2 ^= 1;
            }
            if (joyGetPressed(D_overlay_42_02A02CB4) & 0x8000) {
                amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                if (D_overlay_42_02A02FA2 != 0) {
                    mainDeleteGame(D_overlay_42_02A02F5E);
                    SAVE_SLOT(D_overlay_42_02A02F5E)[3] = -1;
                }
                D_overlay_42_02A02FA0 = 7;
            }
            if (joyGetPressed(D_overlay_42_02A02CB4) & 0x4000) {
                amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                D_overlay_42_02A02FA0 = 7;
            }
            break;

        case 7:
            /* FA4 eases toward -20.0 */
            n = 0;
            if (arg0 > 0) {
                tmp = arg0 & 3;
                if (tmp != 0) {
                    do {
                        n += 1;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                    } while (tmp != n);
                    if (n != arg0) {
                        goto c7_fa4_unrolled;
                    }
                } else {
c7_fa4_unrolled:
                    do {
                        n += 4;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                    } while (n != arg0);
                }
            }
            if (D_overlay_42_02A02FA4 < D_overlay_42_02A02ED4) {
                D_overlay_42_02A02F5F = D_overlay_42_02A02F5E;
                D_overlay_42_02A02FA0 = 0;
            }
            break;

        case 5:
            D_overlay_42_02A04EF8 += arg0 * 4;
            if (D_overlay_42_02A04EF8 >= 0x100) {
                D_overlay_42_02A04EF8 = 0xFF;
            }
            if (D_overlay_42_02A04F00[0] != 0x2C) {
                /* FA4 eases toward -20.0 */
                n = 0;
                if (arg0 > 0) {
                    tmp = arg0 & 3;
                    if (tmp != 0) {
                        do {
                            n += 1;
                            D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (tmp != n);
                        if (n != arg0) {
                            goto c5_fa4_unrolled;
                        }
                    } else {
c5_fa4_unrolled:
                        do {
                            n += 4;
                            D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (n != arg0);
                    }
                }
                if (D_overlay_42_02A02FA4 < D_overlay_42_02A02ED8) {
                    tbl = D_overlay_42_02A04F00;
                    tbl[0] = 0x2C;
                    tbl[1] = ((s8) D_overlay_42_02A02FA8[0x003] == -1) ? 1 : 0;
                    tbl[2] = 0x2D;
                    tbl[3] = ((s8) D_overlay_42_02A02FA8[0x53B] == -1) ? 1 : 0;
                    tbl[4] = 0x2E;
                    tbl[5] = ((s8) D_overlay_42_02A02FA8[0xA73] == -1) ? 1 : 0;
                    tbl[6] = 0x2F;
                    tbl[7] = ((s8) D_overlay_42_02A02FA8[0xFAB] == -1) ? 1 : 0;
                    tbl[8] = 0x30;
                    tbl[9] = ((s8) D_overlay_42_02A02FA8[0x14E3] == -1) ? 1 : 0;
                    tbl[10] = 0x31;
                    tbl[11] = ((s8) D_overlay_42_02A02FA8[0x1A1B] == -1) ? 1 : 0;
                }
            } else {
                /* FA4 eases toward 22.0 */
                n = 0;
                if (arg0 > 0) {
                    tmp = arg0 & 3;
                    if (tmp != 0) {
                        do {
                            n += 1;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (tmp != n);
                        if (n != arg0) {
                            goto c5_fa4_unrolled_b;
                        }
                    } else {
c5_fa4_unrolled_b:
                        do {
                            n += 4;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                            D_overlay_42_02A02FA4 += (22.0f - D_overlay_42_02A02FA4) * 0.25f;
                        } while (n != arg0);
                    }
                }
                sprintf(spE4, (char *) D_overlay_42_02A02E90, FRONT_TEXT_PTR(0x70C), D_overlay_42_02A02F60 + 1);
                fontPrintXY(&frontgfx, 0xA0, 0x68, spE4, 4);
                fontPrintXY(&frontgfx, 0xA0, 0x77, SAVE_SLOT(D_overlay_42_02A02F5E) + 0x51C, 4);
                sprintf(spE4, (char *) D_overlay_42_02A02E98, FRONT_TEXT_PTR(0x710), D_overlay_42_02A02F5F + 1);
                fontPrintXY(&frontgfx, 0xA0, 0x86, spE4, 4);
                if (dxRight != 0) {
                    D_overlay_42_02A02F5F += 1;
                    if (D_overlay_42_02A02F5F >= 6) {
                        D_overlay_42_02A02F5F = 0;
                    }
                    t1 = D_overlay_42_02A02F5F + 1;
                    if ((s8) SAVE_SLOT(D_overlay_42_02A02F5F)[3] != -1) {
                        do {
                            D_overlay_42_02A02F5F = t1;
                            if (D_overlay_42_02A02F5F >= 6) {
                                D_overlay_42_02A02F5F = 0;
                            }
                            t1 = D_overlay_42_02A02F5F + 1;
                        } while ((s8) SAVE_SLOT(D_overlay_42_02A02F5F)[3] != -1);
                    }
                    sndFlag = 1;
                }
                if (dxLeft != 0) {
                    D_overlay_42_02A02F5F -= 1;
                    sndFlag = 1;
                    if (D_overlay_42_02A02F5F < 0) {
                        D_overlay_42_02A02F5F = 5;
                    }
                    t1 = D_overlay_42_02A02F5F - 1;
                    if ((s8) SAVE_SLOT(D_overlay_42_02A02F5F)[3] != -1) {
                        do {
                            D_overlay_42_02A02F5F = t1;
                            if (D_overlay_42_02A02F5F < 0) {
                                D_overlay_42_02A02F5F = 5;
                            }
                            t1 = D_overlay_42_02A02F5F - 1;
                        } while ((s8) SAVE_SLOT(D_overlay_42_02A02F5F)[3] != -1);
                    }
                }
                if (joyGetPressed(D_overlay_42_02A02CB4) & 0x8000) {
                    amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    D_overlay_42_02A02FA0 = 2;
                    D_overlay_42_02A02FA1 = 1;
                } else if (joyGetPressed(D_overlay_42_02A02CB4) & 0x4000) {
                    amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    D_overlay_42_02A02FA0 = 6;
                }
            }
            break;

        case 6:
            /* FA4 eases toward -20.0 */
            n = 0;
            if (arg0 > 0) {
                tmp = arg0 & 3;
                if (tmp != 0) {
                    do {
                        n += 1;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                    } while (tmp != n);
                    if (n != arg0) {
                        goto c6_fa4_unrolled;
                    }
                } else {
c6_fa4_unrolled:
                    do {
                        n += 4;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                        D_overlay_42_02A02FA4 += (-20.0f - D_overlay_42_02A02FA4) * 0.25f;
                    } while (n != arg0);
                }
            }
            if (D_overlay_42_02A02FA4 < D_overlay_42_02A02EDC) {
                if (countFree > 0) {
                    D_overlay_42_02A02FA0 = 4;
                } else {
                    D_overlay_42_02A02FA0 = 0;
                }
                D_overlay_42_02A02F5F = 0;
            }
            break;

        case 2:
            D_overlay_42_02A04EF8 = 0;
            D_overlay_42_02A02FA3 = 1;
            tbl = D_overlay_42_02A04F00;
            for (i = 0; i < 6; i++) {
                tbl[i * 2] = -1;
            }
            /* F5C eases toward 0x1800, arg0 frames (unrolled x4) */
            n = 0;
            if (arg0 > 0) {
                tmp = arg0 & 3;
                if (tmp != 0) {
                    do {
                        n += 1;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                    } while (tmp != n);
                    if (n != arg0) {
                        goto c2_f5c_unrolled;
                    }
                } else {
c2_f5c_unrolled:
                    do {
                        n += 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                    } while (n != arg0);
                }
            }
            w = arg0 << 0xB;
            D_overlay_42_02A02F68 += w;
            if (D_overlay_42_02A02F68 >= 0x1C001) {
                D_overlay_42_02A02F68 = 0x1C000;
            }
            D_overlay_42_02A02F6C += w;
            if (D_overlay_42_02A02F6C >= 0x1C001) {
                D_overlay_42_02A02F6C = 0x1C000;
            }
            for (i = 0; i < 12; i++) {
                D_overlay_42_02A02F70[i] += w;
                if (D_overlay_42_02A02F70[i] >= 0x1C001) {
                    D_overlay_42_02A02F70[i] = 0x1C000;
                }
            }
            if (D_overlay_42_02A02F9C == 0x1C000) {
                D_overlay_42_02A02F58 = &D_overlay_42_02A02F40;
                D_overlay_42_02A02F40 = 0;
                D_overlay_42_02A02FA0 = 1;
            }
            break;

        case 1:
            if (dxLeft != 0) {
                D_overlay_42_02A02CB8 -= 1;
                if (D_overlay_42_02A02CB8 < 0) {
                    D_overlay_42_02A02CB8 += 0x29;
                }
                sndFlag = 1;
            }
            if (dxRight != 0) {
                D_overlay_42_02A02CB8 += 1;
                sndFlag = 1;
                if (D_overlay_42_02A02CB8 >= 0x29) {
                    D_overlay_42_02A02CB8 -= 0x29;
                }
            }
            if (dyPos != 0) {
                sndFlag = 1;
                switch (D_overlay_42_02A02CB8) {
                case 4:
                case 5:
                    D_overlay_42_02A02CB8 = 0x28;
                    break;
                case 40:
                    D_overlay_42_02A02CB8 = 0x23;
                    break;
                default:
                    D_overlay_42_02A02CB8 -= 0xA;
                    if (D_overlay_42_02A02CB8 < 0) {
                        D_overlay_42_02A02CB8 += 0x28;
                    }
                    break;
                }
            }
            if (dyNeg != 0) {
                sndFlag = 1;
                switch (D_overlay_42_02A02CB8) {
                case 34:
                case 35:
                    D_overlay_42_02A02CB8 = 0x28;
                    break;
                case 40:
                    D_overlay_42_02A02CB8 = 4;
                    break;
                default:
                    D_overlay_42_02A02CB8 += 0xA;
                    if (D_overlay_42_02A02CB8 >= 0x29) {
                        D_overlay_42_02A02CB8 -= 0x28;
                    }
                    break;
                }
            }
            tempS2 = (s32) D_overlay_42_02A02F58 - (s32) &D_overlay_42_02A02F40;
            if (joyGetPressed(D_overlay_42_02A02CB4) & 0x8000) {
                D_overlay_42_02A02FA3 = 0;
                entry = (u8 *) D_overlay_42_02A02CBC + D_overlay_42_02A02CB8 * 8;
                *(f32 *) (entry + 4) = 0.0f;
                switch (entry[2]) {
                case 1:
                    if (tempS2 > 0) {
                        D_overlay_42_02A02F58 -= 1;
                        *D_overlay_42_02A02F58 = 0;
                        amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    } else {
                        amSndPlay(0x16E, 0); /* asm: a1 stale, passed as 0 */
                    }
                    break;
                case 2:
                    if (D_overlay_42_02A02FA1 == 0) {
                        game = (u8 *) mainGetGame();
                        mainSetDefaultGame((Game *) game);
                        sprintf((char *) (game + 0x51C), (char *) D_overlay_42_02A02EA0, (char *) &D_overlay_42_02A02F40);
                        mainSaveGame(D_overlay_42_02A02F5E);
                        amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                        mainChangeLevel(0x142, 0, 0, 0, 1, 0);
                        D_overlay_42_02A02FA0 = 9;
                    } else {
                        game = (u8 *) mainGetGame();
                        dst = SAVE_SLOT(D_overlay_42_02A02F5F);
                        dst2 = game;
                        src = SAVE_SLOT(D_overlay_42_02A02F60);
                        n = 0x538;
                        do {
                            n -= 4;
                            dst[0] = src[0];
                            dst2[0] = src[0];
                            dst[1] = src[1];
                            dst2[1] = src[1];
                            dst[2] = src[2];
                            dst2[2] = src[2];
                            dst[3] = src[3];
                            dst2[3] = src[3];
                            dst += 4;
                            dst2 += 4;
                            src += 4;
                        } while (n != 0);
                        sprintf((char *) (SAVE_SLOT(D_overlay_42_02A02F5F) + 0x51C), (char *) D_overlay_42_02A02EA4, (char *) &D_overlay_42_02A02F40);
                        sprintf((char *) (game + 0x51C), (char *) D_overlay_42_02A02EA8, (char *) &D_overlay_42_02A02F40);
                        SAVE_SLOT(D_overlay_42_02A02F5F)[3] = (u8) D_overlay_42_02A02F5F;
                        game[3] = (u8) D_overlay_42_02A02F5F;
                        mainSaveGame(D_overlay_42_02A02F5F);
                        D_overlay_42_02A02F5F = D_overlay_42_02A02F60;
                        D_overlay_42_02A02FA0 = 0;
                    }
                    break;
                default:
                    if (tempS2 < 0x10) {
                        *D_overlay_42_02A02F58 = (s8) entry[2];
                        D_overlay_42_02A02F58 += 1;
                        *D_overlay_42_02A02F58 = 0;
                        amSndPlay(0x16C, 0); /* asm: a1 stale, passed as 0 */
                    } else {
                        amSndPlay(0x16E, 0); /* asm: a1 stale, passed as 0 */
                    }
                    break;
                }
            }
            /* F5C eases toward 0x1800, arg0 frames (unrolled x4) */
            n = 0;
            if (arg0 > 0) {
                tmp = arg0 & 3;
                if (tmp != 0) {
                    do {
                        n += 1;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                    } while (tmp != n);
                    if (n != arg0) {
                        goto c1_f5c_unrolled;
                    }
                } else {
c1_f5c_unrolled:
                    do {
                        n += 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                        D_overlay_42_02A02F5C += (s32) (0x1800 - D_overlay_42_02A02F5C) >> 4;
                    } while (n != arg0);
                }
            }
            if ((joyGetPressed(D_overlay_42_02A02CB4) & 0x4000) && D_overlay_42_02A02FA0 == 1) {
                D_overlay_42_02A02F5F = D_overlay_42_02A02F5E;
                D_overlay_42_02A02FA0 = 0;
            }
            break;
        }

        /* ---- common tail: keyboard ring + name strip ---- */
        if (D_overlay_42_02A02F5C < 0x7A00) {
            D_800FFE02 = D_overlay_42_02A02F5C;
            sp17C = D_800FF650;
            FRONT_GFX_PUT(0xF8000000, 0x2828A4);
            FRONT_GFX_PUT(0xBC000008, 0x0280FE80);
            entry = (u8 *) D_overlay_42_02A02CBC;
            sp18C = 0;
            for (i = 0; i < 0x29; i++) {
                ((u8 *) sp17C)[0x3A] = entry[0];
                if (i == D_overlay_42_02A02CB8 && D_overlay_42_02A02FA0 == 1) {
                    FRONT_GFX_PUT(0xBC000008, 0x190019);
                    f2 = 8.0f;
                } else {
                    f2 = 0.0f;
                }
                if (D_overlay_42_02A02FA0 == 2) {
                    if (i == 0xA || i == 0x14 || i == 0x1E) {
                        sp18C += 1;
                    }
                    if (i == 0x28) {
                        a0v = D_overlay_42_02A02F84;
                    } else {
                        a0v = ((s32 *) &D_overlay_42_02A02F68)[(i % 10) + sp18C];
                    }
                    if (a0v < 0) {
                        *(f32 *) (entry + 4) = 8.0f;
                    } else {
                        *(f32 *) (entry + 4) = (f32) ((Sinf((s16) a0v) * 8.0f) + 8.0f);
                    }
                } else {
                    /* entry[4] eases toward f2, arg0 frames (unrolled x4) */
                    n = 0;
                    if (arg0 > 0) {
                        tmp = arg0 & 3;
                        if (tmp != 0) {
                            do {
                                n += 1;
                                *(f32 *) (entry + 4) = *(f32 *) (entry + 4) + ((f2 - *(f32 *) (entry + 4)) * 0.25f);
                            } while (tmp != n);
                            if (n != arg0) {
                                goto ring_unrolled;
                            }
                        } else {
ring_unrolled:
                            do {
                                n += 4;
                                *(f32 *) (entry + 4) = *(f32 *) (entry + 4) + ((f2 - *(f32 *) (entry + 4)) * 0.25f);
                                *(f32 *) (entry + 4) = *(f32 *) (entry + 4) + ((f2 - *(f32 *) (entry + 4)) * 0.25f);
                                *(f32 *) (entry + 4) = *(f32 *) (entry + 4) + ((f2 - *(f32 *) (entry + 4)) * 0.25f);
                                *(f32 *) (entry + 4) = *(f32 *) (entry + 4) + ((f2 - *(f32 *) (entry + 4)) * 0.25f);
                            } while (n != arg0);
                        }
                    }
                }
                matrixID(sp130);
                matrixPitch((s16) (D_overlay_42_02A02F5C * -1), sp130);
                mathMtxXFMF(sp130, 0.0f, 0.0f, *(f32 *) (entry + 4), &sp12C, &sp128, &sp124);
                /* (anim + unkB*4)->unk10 + (entry[1] << 6) */
                obj = *(u8 **) (anim + ((s8) anim[0xB]) * 4 + 0x10);
                tv = obj + (((s8) entry[1]) << 6);
                D_800FFE0C = *(f32 *) (tv + 0x30) + sp12C;
                D_800FFE10 = *(f32 *) (tv + 0x34) + sp128;
                D_800FFE14 = *(f32 *) (tv + 0x38) + sp124;
                frontDrawObj(0x34);
                if (i == D_overlay_42_02A02CB8 && D_overlay_42_02A02FA0 == 1) {
                    FRONT_GFX_PUT(0xBC000008, 0x0280FE80);
                }
                entry += 8;
            }
        }
        matrixID(sp130);
        matrixPitch((s16) (D_overlay_42_02A02F5C * -1), sp130);
        mathMtxXFMF(sp130, 0.0f, D_overlay_42_02A02FA4, 0.0f, &sp12C, &sp128, &sp124);
        obj = *(u8 **) (anim + ((s8) anim[0xB]) * 4 + 0x10);
        *(f32 *) (currentobjects + 0x68C) = *(f32 *) (obj + 0xB0) + sp12C;
        *(f32 *) (currentobjects + 0x690) = (*(f32 *) (obj + 0xB4) + sp128) + 9.0f;
        *(s16 *) (currentobjects + 0x682) = (s16) (0x8000 - D_overlay_42_02A02F5C);
        *(f32 *) (currentobjects + 0x694) = *(f32 *) (obj + 0xB8) + sp124;
        oldObj688 = *(f32 *) (currentobjects + 0x688);
        *(f32 *) (currentobjects + 0x688) = D_overlay_42_02A02EE0;
        sp17C = D_800FF650;
        FRONT_GFX_PUT(0xF8000000, 0x2828A4);
        if (D_overlay_42_02A04F00[0] == 0x2C) {
            D_800FFE00 = 0;
        }
        for (i = 0; i < 6; i++) {
            ch = D_overlay_42_02A04F00[i * 2];
            if (ch != -1) {
                ((u8 *) sp17C)[0x3A] = (u8) ch;
                if (D_overlay_42_02A04F00[i * 2 + 1] != 0) {
                    objtrans = 0xFF;
                } else {
                    objtrans = 0x40;
                }
                if (i == D_overlay_42_02A02F5F) {
                    FRONT_GFX_PUT(0xBC000008, 0x190019);
                } else {
                    FRONT_GFX_PUT(0xBC000008, 0x0280FE80);
                }
                frontDrawObj(0x34);
            }
        }
        objtrans = 0xFF;
        D_800FFE08 = oldObj688;
        D_800FFE00 = -0x8000;
        fontColour(0, 0, 0xFF, 0xFF, 0xFF);
        switch (D_overlay_42_02A02FA0) {
        case 1:
        case 2:
            if (D_overlay_42_02A02FA3 != 0) {
                fontPrintXY(&frontgfx, 0xA0, 0x30, FRONT_TEXT_PTR(0x714), 4);
            } else {
                fontPrintXY(&frontgfx, 0xA0, 0x30, (char *) &D_overlay_42_02A02F40, 4);
            }
            break;
        case 0:
            fontPrintXY(&frontgfx, 0xA0, 0x30, FRONT_TEXT_PTR(0x718), 4);
            break;
        case 4:
            fontPrintXY(&frontgfx, 0xA0, 0x30, FRONT_TEXT_PTR(0x71C), 4);
            break;
        case 8:
            fontPrintXY(&frontgfx, 0xA0, 0x30, FRONT_TEXT_PTR(0x708), 4);
            break;
        case 5:
            fontPrintXY(&frontgfx, 0xA0, 0x30, FRONT_TEXT_PTR(0x70C), 4);
            break;
        }
        if (sndFlag != 0) {
            amSndPlay(0x16B, 0); /* asm: a1 stale, passed as 0 */
        }
        camSetFOV(52.0f, 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o42/overlay_42/frontKeyboard.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *frontKeyboardGetTiltList(void) {
    return D_overlay_42_02A02F18;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o42/overlay_42/frontKeyboardGetTiltList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_42_02A02C8C_1F61D54(s32 arg0) {

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o42/overlay_42/func_overlay_42_02A02C8C_1F61D54.s")
#endif
