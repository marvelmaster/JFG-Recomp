#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 frontGetMode();
void loadFrontEndList(void *list);
void setupFrontEndList(void *list);
void freeFrontEndList(void *list);
void sortByKills();
void sortPlayers();
void objAnimSetMove(void *obj, s32 arg1, s32 arg2);
void objAnimDframe(void *obj, s32 arg1, f32 arg2, void **arg3);
void amSndPlay();
void camDo2DSprite(Gfx **gfx, void *mtx, void *vtx, void *pos, void *tex, s32 arg5, s32 arg6);
void fontUseFont(s32 font);
void fontPrintXY(Gfx **gfx, s32 x, s32 y, void *str, s32 flags);
void fontColour(s32 r, s32 g, s32 b, s32 a, s32 alpha);
void instScreenToSpriteCoord();
void instSpriteToScreenCoord();
void texDPInit(Gfx **gfx);
extern void *D_800FF600;
extern void *D_800FF604;
extern void *D_800FF608;
extern u8 D_overlay_40_028024D0[];
extern u8 D_overlay_40_028024D8[];
extern u8 D_overlay_40_028024E0[];
extern s8 D_overlay_40_02802508[];
extern char D_overlay_40_02802510[];
extern char D_overlay_40_02802514[];
extern char D_overlay_40_0280252C[];
extern char D_overlay_40_02802528[];
extern char D_overlay_40_02802518[];
extern s8 D_overlay_40_02802564;
extern s8 D_overlay_40_02802565;
extern s16 D_overlay_40_02802560[];
extern s16 D_overlay_40_02802568[];
extern u8 D_overlay_40_02802578[];
extern s16 D_overlay_40_02802580;
extern u8 D_overlay_40_02802588[];
extern s32 D_overlay_40_028025B8;
extern s16 D_overlay_40_028025AA;
extern u16 D_overlay_40_028025B0[];
extern void *front_text;
extern Gfx *frontgfx;
extern u8 frontmtx[];
extern u8 frontvtx[];
extern u8 frontendptrs[];
extern u8 multiPlayer[];
extern u8 numberOfPlayers;
extern void *orderedPlayers[];
extern s32 runInOneFrame;
/* frontMultiStats: extra externs */
extern s32 D_overlay_40_028025A0;
extern s32 D_overlay_40_028025A4;
extern s8 D_overlay_40_028025A8;
extern s8 D_overlay_40_028025A9;
/* func_overlay_40_0280124C: extra externs */
extern char D_overlay_40_0280251C[];
extern char D_overlay_40_02802520[];
extern char D_overlay_40_02802524[];
/* func_overlay_40_02801D60: extra externs */
extern u32 D_overlay_40_028024F0[];
extern f32 D_overlay_40_02802558;
void frontGetTime(s32 arg0, u8 *a, u8 *b, u8 *c);
void camStandardOrtho(Gfx **gfx, void *mtx);
void camStandardPersp(Gfx **gfx, void *mtx);
void camSetNo(s32 arg0);
void camSetView(Gfx **gfx, s32 arg1);
void camOverrideProjScales(f32 sx, f32 sy);
void camSetFOV(f32 fov, s32 arg1);
void pauseClearScreen();
void frontDrawObj();
void func_overlay_40_028007F0_1F5A3B0(s32 arg0);
void func_overlay_40_0280124C_1F5AE0C(s32 arg0);
void func_overlay_40_02800DF8_1F5A9B8(s32 arg0);
void func_overlay_40_0280193C_1F5B4FC(s32 arg0);
void func_overlay_40_02801D60_1F5B920(s32 arg0);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitMultiStats(void) {
    s32 i;
    s32 mode;
    s32 rank;
    s32 score;
    void *player;

    loadFrontEndList(D_overlay_40_028024E0);
    setupFrontEndList(D_overlay_40_028024D8);
    loadFrontEndList(D_overlay_40_028024D0);
    D_overlay_40_02802568[0] = -1;
    D_overlay_40_02802568[5] = -1;
    D_overlay_40_02802564 = 1;
    D_overlay_40_02802565 = 0;
    D_overlay_40_02802560[0] = -0xDC;
    D_overlay_40_02802560[1] = 0x17C;
    D_overlay_40_02802580 = 0x1E;
    mode = frontGetMode(D_overlay_40_02802560);
    switch (mode) {
    case 18:
    case 19:
        sortByKills();
        break;
    case 20:
    case 21:
    case 22:
        sortPlayers(4);
        break;
    }
    for (i = 0; i < (s32) numberOfPlayers; i++) {
        player = orderedPlayers[i];
        rank = (((u8 *) player)[0x14] - 1) & 3;
        score = D_overlay_40_02802508[rank] + *(u16 *) ((u8 *) player + 0x9C);
        if (score >= 0xC351) {
            score = 0xC350;
        }
        *(u16 *) ((u8 *) player + 0x9C) = (u16) score;
        *(u16 *) ((u8 *) player + 0x94 + rank * 2) += 1;
    }
    objAnimSetMove(D_800FF608, 0, 0x3F800000);
    runInOneFrame = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/frontInitMultiStats.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMultiStats(s32 arg0) {
    s32 sp68;
    s32 i;
    s32 t5;
    s32 v0;
    s32 idx;
    s32 cnt;
    s32 step;
    s32 val;
    s8 oldSub;
    s8 oldState;
    s8 newSub;
    s8 idxB;
    s16 *cur;
    s16 *lp;
    u8 *bp;
    u8 *rec;
    u8 *obj;
    u8 *anim;
    u8 *model;
    u8 *hdr;
    u8 *ent;
    Gfx *gfx;

    sp68 = 0;
    camStandardOrtho(&frontgfx, frontmtx);
    pauseClearScreen();
    texDPInit(&frontgfx);
    D_overlay_40_028025B8 = frontGetMode();
    if (D_overlay_40_02802580 >= 0) {
        D_overlay_40_02802580 -= arg0;
        if (D_overlay_40_02802580 < 0) {
            amSndPlay(0x1C4, 0, 1);
        }
    } else {
        oldSub = D_overlay_40_02802565;
        oldState = D_overlay_40_02802564;
        switch (oldState) {
        case 1:
            switch (D_overlay_40_028025B8) {
            case 18:
            case 19:
                D_overlay_40_028025A9 = 0;
                sortByKills();
                func_overlay_40_028007F0_1F5A3B0(arg0);
                break;
            case 20:
                D_overlay_40_028025A9 = 0;
                sortPlayers(4, &D_overlay_40_028025B8, 1);
                func_overlay_40_0280124C_1F5AE0C(arg0);
                break;
            case 21:
                D_overlay_40_028025A9 = 1;
                sortPlayers(4, &D_overlay_40_028025B8, 1);
                func_overlay_40_0280124C_1F5AE0C(arg0);
                break;
            case 22:
                D_overlay_40_028025A9 = 2;
                sortPlayers(4, &D_overlay_40_028025B8, 1);
                func_overlay_40_028007F0_1F5A3B0(arg0);
                break;
            }
            break;
        case 2:
            D_overlay_40_028025A9 = 0;
            ((void (*)(s32, s32 *, s32)) func_overlay_40_02800DF8_1F5A9B8)(arg0, &D_overlay_40_028025B8, 1); /* sig mismatch: asm passes a1/a2 */
            break;
        case 3:
            D_overlay_40_028025A9 = 4;
            ((void (*)(s32, s32 *, s32)) func_overlay_40_0280193C_1F5B4FC)(arg0, &D_overlay_40_028025B8, 1); /* sig mismatch: asm passes a1/a2 */
            break;
        case 4:
            D_overlay_40_028025A9 = 6;
            sortPlayers(3, &D_overlay_40_028025B8, 1);
            func_overlay_40_02801D60_1F5B920(arg0);
            if (D_overlay_40_02802564 >= 5) {
                sp68 = 1;
            }
            break;
        }
        newSub = D_overlay_40_02802565;
        if ((newSub != 0) && (oldSub != newSub)) {
            amSndPlay(0x1C4, 0);
        }
        if (oldState != D_overlay_40_02802564) {
            amSndPlay(0x1C4, 0);
            D_overlay_40_028025AA = 0xC;
            D_overlay_40_028025A4 = 0x10000;
            if (D_overlay_40_028025A0 >= 0xB700) {
                D_overlay_40_028025A0 += 0xFFFF0000;
            }
        }
    }
    v0 = D_overlay_40_028025A0;
    t5 = v0 + ((s32) (D_overlay_40_028025A4 - v0) >> 3);
    D_overlay_40_028025A0 = t5;
    if ((t5 >= 0xB700) && (v0 < 0xB700)) {
        D_overlay_40_028025A8 = D_overlay_40_028025A9;
    }
    camSetNo(0);
    camSetView(&frontgfx, 0);
    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, frontmtx);
    /* D_overlay_40_02802588 is the tilt/bar record: +0 mode, +2 pos, +4 scale */
    *(s16 *) (D_overlay_40_02802588 + 0x0) = 0x2006;
    *(s16 *) (D_overlay_40_02802588 + 0x4) = 0x1000;
    *(s16 *) (D_overlay_40_02802588 + 0x2) = (s16) D_overlay_40_028025A0;
    obj = (u8 *) D_800FF608;
    objAnimDframe(obj, 0xBCA3D70A, (f32) arg0, &D_800FF608);
    /* obj->0x6C -> anim; *anim -> model; *model -> hdr (asm: lw from 0x6C, then 0(x) twice) */
    anim = *(u8 **) (obj + 0x6C);
    model = *(u8 **) anim;
    hdr = *(u8 **) model;
    *(s8 *) (model + 0xA) = (s8) arg0;
    idxB = *(s8 *) (model + 0xB);
    cur = *(s16 **) (model + idxB * 4 + 0x78);
    rec = *(u8 **) (model + 0x74);
    ent = model;
    i = 0;
    cnt = *(u8 *) (hdr + 0x2C);
    if (cnt > 0) {
        do {
            v0 = *(s32 *) (rec + 4);
            idx = v0 & 0xFF;
            ent = *(u8 **) (*(u8 **) (hdr + 0x18) + idx * 8);
            if (idx == 4) {
                *(s16 *) rec = (s16) (D_overlay_40_028025A8 << 8);
            }
            cur += 1;
            cur[-1] = (s16) ((*(s16 *) rec >> 8) * *(s16 *) (ent + 0x16));
            if (*(s16 *) (rec + 2) >= 0) {
                cur += 1;
                cur[-1] = (s16) ((*(s16 *) (rec + 2) >> 8) * *(s16 *) (ent + 0x16));
            }
            i += 1;
            rec += 8;
        } while (i < cnt);
        i = 0;
    }
    frontDrawObj(0x2E, ent, hdr, 4);
    frontDrawObj(0x1F);
    camSetFOV(52.0f, 1);
    if (D_overlay_40_02802580 < 0) {
        step = arg0 * 8;
        lp = D_overlay_40_02802568;
        bp = D_overlay_40_02802578;
        i = 0;
        do {
            if (i == D_overlay_40_02802564) {
                val = *bp;
                if (val < (0xFF - step)) {
                    *bp = (u8) (val + step);
                } else {
                    *bp = 0xFF;
                }
            } else {
                val = *bp;
                if (val < step) {
                    *bp = 0;
                } else {
                    *bp = (u8) (val - step);
                }
            }
            if (*lp != -1) {
                val = *bp;
                if (val > 0) {
                    fontColour(0, 0, 0x80, 0xFF, val);
                    fontPrintXY(&frontgfx, 0x7D, 0x31, ((void **) front_text)[*lp], 0);
                }
            }
            i += 1;
            bp += 1;
            lp += 1;
        } while ((i < 8) && (D_overlay_40_02802580 < 0));
    }
    fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gfx = frontgfx;
    frontgfx = gfx + 8;
    gfx->words.w1 = -1U;
    gfx->words.w0 = 0xFA000000;
    if (sp68 != 0) {
        mainChangeLevel(0, 0, 0, 8, 1, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/frontMultiStats.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupMultiStats(void) {
    freeFrontEndList(D_overlay_40_028024E0);
    runInOneFrame = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/frontCleanupMultiStats.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_40_028007F0_1F5A3B0(s32 arg0) {
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 pad6;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        u8 pad18[0x10];
        f32 unk28;
    } spr;
    char text[16];
    s32 mode;
    s32 flag;
    s32 i;
    s32 j;
    s32 snd;
    s32 cnt;
    s32 rank;
    s32 x;
    s32 y;
    s32 sy;
    s32 px;
    u8 *player;
    s16 *cntp;
    Gfx *gfx;

    spr.unk0 = 0;
    spr.unk2 = 0;
    spr.unk4 = 0;
    spr.unk14 = 0.0f;
    mode = frontGetMode();
    if (mode != 0x14) {
        if (mode != 0x16) {
            D_overlay_40_02802568[D_overlay_40_02802564] = 0x17B;
        } else {
            D_overlay_40_02802568[D_overlay_40_02802564] = 0x17E;
        }
    } else {
        D_overlay_40_02802568[D_overlay_40_02802564] = 0x17C;
    }
    flag = 0;
    if (D_overlay_40_02802565 != 0) {
        s32 d = arg0 * 0x10;
        D_overlay_40_02802560[0] = (s16) (D_overlay_40_02802560[0] - d);
        D_overlay_40_02802560[1] = (s16) (D_overlay_40_02802560[1] + d);
        if (D_overlay_40_02802560[0] < -0xDC) {
            D_overlay_40_02802564 = D_overlay_40_02802565;
            flag = 1;
            D_overlay_40_02802565 = 0;
        }
    } else {
        s32 d = arg0 * 0x10;
        s16 t = D_overlay_40_02802560[0] + d;
        D_overlay_40_02802560[0] = t;
        if (t >= 0x51) {
            D_overlay_40_02802560[0] = 0x50;
        }
        t = D_overlay_40_02802560[1] - d;
        D_overlay_40_02802560[1] = t;
        if (t < 0x50) {
            D_overlay_40_02802560[1] = 0x50;
        } else {
            D_overlay_40_028025B0[0] = 0;
            D_overlay_40_028025B0[1] = 0;
            D_overlay_40_028025B0[2] = 0;
            D_overlay_40_028025B0[3] = 0;
        }
    }
    texDPInit(&frontgfx);
    gfx = frontgfx;
    frontgfx = gfx + 8;
    gfx->words.w1 = -1U;
    gfx->words.w0 = 0xFA000000;
    fontUseFont(2);
    snd = 0;
    y = 0x64;
    if ((s32) D_overlay_40_028025B0[0] < D_overlay_40_02802508[0]
        && D_overlay_40_02802560[0] == 0x50 && D_overlay_40_02802560[1] == 0x50) {
        D_overlay_40_028025AA -= arg0;
        if (D_overlay_40_028025AA < 0) {
            D_overlay_40_028025AA += 0xC;
            amSndPlay(0x1C3, 0);
            snd = 1;
        }
    }
    j = 0;
    if ((s32) numberOfPlayers > 0) {
        cntp = (s16 *) D_overlay_40_028025B0;
        for (i = 0; i < (s32) numberOfPlayers; i++) {
            player = orderedPlayers[i];
            px = *(s32 *) (player + 0x10);
            rank = (((u8 *) player)[0x14] - 1) & 3;
            if (snd != 0) {
                if ((s32) *cntp < D_overlay_40_02802508[rank]) {
                    *cntp = *cntp + 1;
                }
            }
            sy = y;
            x = D_overlay_40_02802560[j & 1];
            instScreenToSpriteCoord(&x, &sy);
            spr.unkC = (f32) x;
            spr.unk28 = (f32) rank;
            spr.unk10 = (f32) sy;
            spr.unk8 = 0.75f;
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, *(void **) (frontendptrs + 0x208), 0, 0xFF);
            spr.unkC += 40.0f;
            spr.unk28 = (f32) *(s32 *) (player + 0x8C);
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, *(void **) (frontendptrs + 0x20C), 0, 0xFF);
            instSpriteToScreenCoord(&x, &sy);
            x += 0x58;
            sprintf(text, D_overlay_40_02802510, px);
            fontPrintXY(&frontgfx, x - 2, y, text, 1);
            fontPrintXY(&frontgfx, x + 2, y, *(void **) ((u8 *) front_text + 0x538), 0);
            x += 0x2A;
            sprintf(text, D_overlay_40_02802514, *cntp);
            fontPrintXY(&frontgfx, x, y, text, 0);
            x += 0x1C;
            sy = y + 5;
            instScreenToSpriteCoord(&x, &sy);
            spr.unkC = (f32) x;
            spr.unk10 = (f32) sy;
            spr.unk28 = 0.0f;
            spr.unk8 = 1.0f;
            if ((s32) *cntp > 0) {
                for (cnt = 0; cnt < (s32) *cntp; cnt++) {
                    if (cnt + 1 == *cntp) {
                        spr.unk28 = 1.0f;
                    }
                    camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, *(void **) (frontendptrs + 0x214), 0, 0xFF);
                    spr.unk10 += 4.0f;
                }
            }
            if (flag == 0) {
                if (joyGetPressed(*(s32 *) (player + 0x8C)) & 0x8000) {
                    if (D_overlay_40_028025B8 == 0x16) {
                        D_overlay_40_02802565 = 3;
                    } else {
                        D_overlay_40_02802565 = 2;
                    }
                }
            }
            cntp += 2;
            y += 0x1A;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/func_overlay_40_028007F0_1F5A3B0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_40_02800DF8_1F5A9B8(s32 arg0) {
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 pad6;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        u8 pad18[0x10];
        f32 unk28;
    } spr;
    char text[16];
    s32 flag;
    s32 n;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 d;
    s32 t;
    s32 yv;
    u8 *fp;
    u16 *v;
    Gfx *gfx;

    D_overlay_40_02802568[D_overlay_40_02802564] = 0x181;
    spr.unk0 = 0;
    spr.unk2 = 0;
    spr.unk4 = 0;
    flag = 0;
    spr.unk8 = 0.75f;
    spr.unk14 = 0.0f;
    if (D_overlay_40_02802565 != 0) {
        d = arg0 * 0x10;
        D_overlay_40_02802560[0] = (s16) (D_overlay_40_02802560[0] - d);
        D_overlay_40_02802560[1] = (s16) (D_overlay_40_02802560[1] + d);
        if (D_overlay_40_02802560[0] < -0xDC) {
            D_overlay_40_02802564 = D_overlay_40_02802565;
            flag = 1;
            D_overlay_40_02802565 = 0;
        }
    } else {
        d = arg0 * 0x10;
        t = D_overlay_40_02802560[0] + d;
        D_overlay_40_02802560[0] = t;
        if (t >= 0x51) {
            D_overlay_40_02802560[0] = 0x50;
        }
        t = D_overlay_40_02802560[1] - d;
        D_overlay_40_02802560[1] = t;
        if (t < 0x50) {
            D_overlay_40_02802560[1] = 0x50;
        }
    }
    texDPInit(&frontgfx);
    gfx = frontgfx;
    frontgfx = gfx + 8;
    gfx->words.w1 = -1U;
    gfx->words.w0 = 0xFA000000;
    x = D_overlay_40_02802560[1] + 0x50;
    y = 0x54;
    instScreenToSpriteCoord(&x, &y);
    i = 0;
    spr.unk10 = (f32) y;
    n = (s32) numberOfPlayers;
    if (n > 0) {
        do {
            spr.unkC = (f32) x;
            spr.unk28 = (f32) i;
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, D_800FF604, 0, 0xFF);
            i += 1;
            x += 0x1E;
        } while (i < n);
        i = 0;
    }
    yv = 0x6E;
    fontUseFont(2);
    if (n > 0) {
        fp = multiPlayer;
        do {
            x = D_overlay_40_02802560[i & 1] - 0xC;
            y = yv;
            j = 0;
            instScreenToSpriteCoord(&x, &y);
            spr.unkC = (f32) x;
            spr.unk10 = (f32) y;
            spr.unk28 = (f32) *(u16 *) (fp + 0x8C);
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, D_800FF604, 0, 0xFF);
            instSpriteToScreenCoord(&x, &y);
            x += 0x1E;
            fontPrintXY(&frontgfx, x, yv, *(void **) ((u8 *) front_text + 0x538), 0);
            x += 0x3C;
            if (n > 0) {
                v = (u16 *) fp;
                do {
                    if (i == j) {
                        fontColour(0xFF, 0x40, 0, 0xFF, 0xFF);
                    } else {
                        fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    sprintf(text, D_overlay_40_02802518, *v);
                    fontPrintXY(&frontgfx, x, yv, text, 4);
                    j += 1;
                    v += 2;
                    x += 0x1E;
                } while (j < n);
            }
            if (flag == 0) {
                if (joyGetPressed(*(u16 *) (fp + 0x8C)) & 0x8000) {
                    D_overlay_40_02802565 = 3;
                }
                if (joyGetPressed(*(u16 *) (fp + 0x8C)) & 0x4000) {
                    D_overlay_40_02802565 = 1;
                }
            }
            i += 1;
            fp += 0x140;
            yv += 0x1A;
        } while (i < n);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/func_overlay_40_02800DF8_1F5A9B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_40_0280124C_1F5AE0C(s32 arg0) {
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 pad6;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        u8 pad18[0x10];
        f32 unk28;
    } spr; /* same sprite record layout as func_overlay_40_0280193C */
    u8 timeA[2];  /* frontGetTime() output: [0] at x, [1] at x+8 */
    u8 timeA1[2]; /* copy of timeA[1] as a 1-char string */
    u8 timeB[2];
    u8 timeB1[2];
    u8 timeC[2];
    u8 timeC1[2];
    char countStr[16];
    void *player;
    s32 flag;
    s32 i;
    s32 k;
    s32 count;
    s32 d;
    s32 x;
    s32 y;
    s32 rowY;
    Gfx *gfx;

    if (D_overlay_40_028025B8 == 0x14) {
        D_overlay_40_02802568[D_overlay_40_02802564] = 0x17C;
    } else {
        D_overlay_40_02802568[D_overlay_40_02802564] = 0x17D;
    }
    spr.unk0 = 0;
    spr.unk2 = 0;
    spr.unk4 = 0;
    flag = 0;
    spr.unk14 = 0.0f;
    if (D_overlay_40_02802565 != 0) {
        d = arg0 * 0x10;
        D_overlay_40_02802560[0] = (s16) (D_overlay_40_02802560[0] - d);
        D_overlay_40_02802560[1] = (s16) (D_overlay_40_02802560[1] + d);
        if (D_overlay_40_02802560[0] < -0xDC) {
            D_overlay_40_02802564 = D_overlay_40_02802565;
            flag = 1;
            D_overlay_40_02802565 = 0;
        }
    } else {
        d = arg0 * 0x10;
        D_overlay_40_02802560[0] = (s16) (D_overlay_40_02802560[0] + d);
        if (D_overlay_40_02802560[0] >= 0x51) {
            D_overlay_40_02802560[0] = 0x50;
        }
        D_overlay_40_02802560[1] = (s16) (D_overlay_40_02802560[1] - d);
        if (D_overlay_40_02802560[1] < 0x50) {
            D_overlay_40_02802560[1] = 0x50;
        } else {
            D_overlay_40_028025B0[0] = 0;
            D_overlay_40_028025B0[1] = 0;
            D_overlay_40_028025B0[2] = 0;
            D_overlay_40_028025B0[3] = 0;
        }
    }
    texDPInit(&frontgfx);
    gfx = frontgfx;
    frontgfx = gfx + 8;
    gfx->words.w1 = -1U;
    gfx->words.w0 = 0xFA000000;
    rowY = 0x64;
    if (D_overlay_40_028025B0[0] < D_overlay_40_02802508[0]) {
        if (D_overlay_40_02802560[0] == 0x50 && D_overlay_40_02802560[1] == 0x50) {
            D_overlay_40_028025AA -= arg0;
            if (D_overlay_40_028025AA < 0) {
                D_overlay_40_028025AA += 0xC;
                for (i = 0; i < (s32) numberOfPlayers; i++) {
                    if (D_overlay_40_028025B0[i] < D_overlay_40_02802508[i]) {
                        D_overlay_40_028025B0[i] += 1;
                    }
                }
                amSndPlay(0x1C3, 0);
            }
        }
    }
    fontUseFont(2);
    for (i = 0; i < (s32) numberOfPlayers; i++) {
        player = orderedPlayers[i];
        x = D_overlay_40_02802560[i & 1];
        y = rowY;
        instScreenToSpriteCoord(&x, &y);
        spr.unkC = (f32) x;
        spr.unk10 = (f32) y;
        spr.unk28 = (f32) i;
        spr.unk8 = 0.75f;
        camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, *(void **) (frontendptrs + 0x208), 0, 0xFF);
        spr.unkC += 40.0f;
        spr.unk28 = (f32) *(u8 *) ((u8 *) player + 0x8C); /* lbu: controller index */
        camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, *(void **) (frontendptrs + 0x20C), 0, 0xFF);
        instSpriteToScreenCoord(&x, &y);
        x += 0x46;
        frontGetTime(*(s32 *) ((u8 *) player + 0x90), timeA, timeB, timeC);
        timeA1[0] = timeA[1];
        timeB1[0] = timeB[1];
        timeC1[0] = timeC[1];
        timeA[1] = 0;
        timeB[1] = 0;
        timeC[1] = 0;
        timeA1[1] = 0;
        timeB1[1] = 0;
        timeC1[1] = 0;
        fontPrintXY(&frontgfx, x, rowY, timeA, 4);
        x += 8;
        fontPrintXY(&frontgfx, x, rowY, timeA1, 4);
        x += 6;
        fontPrintXY(&frontgfx, x, rowY, D_overlay_40_0280251C, 4);
        x += 6;
        fontPrintXY(&frontgfx, x, rowY, timeB, 4);
        x += 8;
        fontPrintXY(&frontgfx, x, rowY, timeB1, 4);
        x += 6;
        fontPrintXY(&frontgfx, x, rowY, D_overlay_40_02802520, 4);
        x += 6;
        fontPrintXY(&frontgfx, x, rowY, timeC, 4);
        x += 8;
        fontPrintXY(&frontgfx, x, rowY, timeC1, 4);
        x += 0x22;
        sprintf(countStr, D_overlay_40_02802524, D_overlay_40_028025B0[i]);
        fontPrintXY(&frontgfx, x, rowY, countStr, 0);
        y = rowY + 5;
        x += 0x1C;
        instScreenToSpriteCoord(&x, &y);
        spr.unkC = (f32) x;
        spr.unk10 = (f32) y;
        spr.unk28 = 0.0f;
        spr.unk8 = 1.0f;
        count = D_overlay_40_028025B0[i];
        for (k = 0; k < count; k++) {
            if ((k + 1) == count) {
                spr.unk28 = 1.0f;
            }
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, *(void **) (frontendptrs + 0x214), 0, 0xFF);
            spr.unk10 += 4.0f;
        }
        if (flag == 0) {
            if (joyGetPressed(*(u8 *) ((u8 *) player + 0x8C)) & 0x8000) {
                if (D_overlay_40_028025B8 == 0x15) {
                    D_overlay_40_02802565 = 3;
                } else {
                    D_overlay_40_02802565 = 2;
                }
            }
        }
        rowY += 0x1A;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/func_overlay_40_0280124C_1F5AE0C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_40_0280193C_1F5B4FC(s32 arg0) {
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 pad6;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        u8 pad18[0x10];
        f32 unk28;
    } spr;
    char text[16];
    s32 flag;
    s32 n;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 yv;
    s32 d;
    s32 t;
    u8 *fp;
    Gfx *gfx;

    D_overlay_40_02802568[D_overlay_40_02802564] = 0x17;
    spr.unk0 = 0;
    spr.unk2 = 0;
    spr.unk4 = 0;
    flag = 0;
    spr.unk8 = 0.75f;
    spr.unk14 = 0.0f;
    if (D_overlay_40_02802565 != 0) {
        d = arg0 * 0x10;
        D_overlay_40_02802560[0] = (s16) (D_overlay_40_02802560[0] - d);
        D_overlay_40_02802560[1] = (s16) (D_overlay_40_02802560[1] + d);
        if (D_overlay_40_02802560[0] < -0xDC) {
            D_overlay_40_02802564 = D_overlay_40_02802565;
            flag = 1;
            D_overlay_40_02802565 = 0;
        }
    } else {
        d = arg0 * 0x10;
        t = D_overlay_40_02802560[0] + d;
        D_overlay_40_02802560[0] = t;
        if (t >= 0x51) {
            D_overlay_40_02802560[0] = 0x50;
        }
        t = D_overlay_40_02802560[1] - d;
        D_overlay_40_02802560[1] = t;
        if (t < 0x50) {
            D_overlay_40_02802560[1] = 0x50;
        }
    }
    texDPInit(&frontgfx);
    gfx = frontgfx;
    frontgfx = gfx + 8;
    gfx->words.w1 = -1U;
    gfx->words.w0 = 0xFA000000;
    x = D_overlay_40_02802560[1] + 0x29;
    y = 0x54;
    instScreenToSpriteCoord(&x, &y);
    i = 0;
    spr.unk10 = (f32) y;
    n = (s32) numberOfPlayers;
    if (n > 0) {
        do {
            spr.unkC = (f32) x;
            spr.unk28 = (f32) i;
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, D_800FF600, 0, 0xFF);
            i += 1;
            x += 0x28;
        } while (i < n);
        i = 0;
    }
    yv = 0x6E;
    fontUseFont(2);
    if (n > 0) {
        fp = multiPlayer;
        do {
            j = 0;
            x = D_overlay_40_02802560[i & 1];
            y = yv;
            instScreenToSpriteCoord(&x, &y);
            spr.unkC = (f32) x;
            spr.unk10 = (f32) y;
            spr.unk28 = (f32) *(u16 *) (fp + 0x8C);
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr.unk0, D_800FF604, 0, 0xFF);
            instSpriteToScreenCoord(&x, &y);
            x += 0x28;
            if (n > 0) {
                do {
                    sprintf(text, D_overlay_40_02802528, *(s16 *) (fp + 0x94 + j * 2));
                    fontPrintXY(&frontgfx, x, yv - 6, text, 4);
                    j += 1;
                    x += 0x28;
                } while (j < n);
            }
            if (flag == 0) {
                if (joyGetPressed(*(u16 *) (fp + 0x8C)) & 0x8000) {
                    D_overlay_40_02802565 = 4;
                }
                if (joyGetPressed(*(u16 *) (fp + 0x8C)) & 0x4000) {
                    if ((D_overlay_40_028025B8 == 0x15) || (D_overlay_40_028025B8 == 0x16)) {
                        D_overlay_40_02802565 = 1;
                    } else {
                        D_overlay_40_02802565 = 2;
                    }
                }
            }
            i += 1;
            fp += 0x140;
            yv += 0x1A;
        } while (i < n);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/func_overlay_40_0280193C_1F5B4FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_40_02801D60_1F5B920(s32 arg0) {
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 pad6;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
        u8 pad18[0x10];
        f32 unk28;
    } spr; /* same sprite record layout as func_overlay_40_028007F0 (sp+0x19C) */
    char text[16];
    s32 flag;
    s32 i;
    s32 k;
    s32 s0;  /* bar segment count (ceil(score/4), max 5) */
    s32 s1;  /* remaining bar units for this player */
    s32 tie; /* index used as 3rd arg of instScreenToSpriteCoord */
    s32 rowY;
    s32 x;
    s32 y;
    s32 d;
    s32 cnt;
    void *player;
    u32 *seg;
    Gfx *gfx;

    spr.unk0 = 0;
    spr.unk2 = 0;
    spr.unk4 = 0;
    spr.unk14 = 0.0f;
    spr.unk8 = 0.75f;
    D_overlay_40_02802568[D_overlay_40_02802564] = 0x17;
    flag = 0;

    if (D_overlay_40_02802565 != 0) {
        d = arg0 * 0x10;
        D_overlay_40_02802560[0] = (s16) (D_overlay_40_02802560[0] - d);
        D_overlay_40_02802560[1] = (s16) (D_overlay_40_02802560[1] + d);
        if (D_overlay_40_02802560[0] < -0xDC) {
            D_overlay_40_02802564 = D_overlay_40_02802565;
            flag = 1;
            D_overlay_40_02802565 = 0;
        }
    } else {
        d = arg0 * 0x10;
        D_overlay_40_02802560[0] = (s16) (D_overlay_40_02802560[0] + d);
        if (D_overlay_40_02802560[0] >= 0x51) {
            D_overlay_40_02802560[0] = 0x50;
        }
        D_overlay_40_02802560[1] = (s16) (D_overlay_40_02802560[1] - d);
        if (D_overlay_40_02802560[1] < 0x50) {
            D_overlay_40_02802560[1] = 0x50;
        } else {
            D_overlay_40_028025B0[0] = 0;
            D_overlay_40_028025B0[1] = 0;
            D_overlay_40_028025B0[2] = 0;
            D_overlay_40_028025B0[3] = 0;
        }
    }

    if ((s32) D_overlay_40_028025B0[0] < (s32) *(u16 *) ((u8 *) orderedPlayers[0] + 0x9C)
        && D_overlay_40_02802560[0] == 0x50 && D_overlay_40_02802560[1] == 0x50) {
        s0 = 0;
        D_overlay_40_028025AA -= arg0;
        if (D_overlay_40_028025AA < 0) {
            D_overlay_40_028025AA += 7;
            for (i = 0; i < (s32) numberOfPlayers; i++) {
                player = orderedPlayers[i];
                if (D_overlay_40_028025B0[i] < *(u16 *) ((u8 *) player + 0x9C)) {
                    D_overlay_40_028025B0[i] += 1;
                    if (D_overlay_40_028025B0[i] >= 0x15) {
                        s0 = 1;
                        D_overlay_40_028025B0[i] = *(u16 *) ((u8 *) player + 0x9C);
                    }
                }
            }
            amSndPlay(0x1C3, 0);
        }
        if (s0 != 0) {
            amSndPlay(0x47, 0);
        }
    }

    texDPInit(&frontgfx);
    gfx = frontgfx;
    frontgfx = gfx + 8;
    gfx->words.w1 = -1U;
    gfx->words.w0 = 0xFA000000;
    fontUseFont(2);

    if ((s32) numberOfPlayers > 0) {
        rowY = 0x64;
        tie = 0;
        i = 0;
        do {
            player = orderedPlayers[i];
            x = D_overlay_40_02802560[i & 1] + 0x1E;
            y = rowY;
            instScreenToSpriteCoord(&x, &y, tie);
            spr.unk8 = 0.75f;
            spr.unkC = (f32) x;
            spr.unk10 = (f32) y;
            spr.unk28 = (f32) tie;
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr, *(void **) (frontendptrs + 0x208), 0, 0xFF);
            x += 0x1E;
            spr.unkC = (f32) x;
            spr.unk28 = (f32) *(u8 *) ((u8 *) player + 0x8C);
            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr, *(void **) (frontendptrs + 0x20C), 0, 0xFF);
            instSpriteToScreenCoord(&x, &y);
            x += 0xF;
            sprintf(text, D_overlay_40_0280252C, D_overlay_40_028025B0[i]);
            fontPrintXY(&frontgfx, x, rowY, text, 0);

            /* bar: ceil(score / 4) segments, clamped to 5 */
            cnt = *(u16 *) ((u8 *) player + 0x9C);
            s0 = cnt / 4;
            if (cnt % 4 != 0) {
                s0 += 1;
            }
            if (s0 >= 6) {
                s0 = 5;
                x += 0x23;
            }
            s1 = D_overlay_40_028025B0[i];
            x = x + s0 * 9 + 0x15;
            y = rowY + 5;
            instScreenToSpriteCoord(&x, &y);
            spr.unkC = (f32) x;
            spr.unk8 = 1.0f;
            spr.unk10 = (f32) y;
            if (s0 != 0) {
                seg = &D_overlay_40_028024F0[s0];
                do {
                    gfx = frontgfx;
                    frontgfx = gfx + 8;
                    gfx->words.w0 = 0xFA000000;
                    gfx->words.w1 = *seg;
                    k = 0;
                    spr.unk28 = 0.0f;
                    spr.unk10 = (f32) y;
                    if (s1 > 0) {
                        do {
                            if (k == 3 || s1 == 1) {
                                spr.unk28 = 1.0f;
                            }
                            camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr, *(void **) (frontendptrs + 0x214), 0, 0xFF);
                            k++;
                            spr.unk10 += 4.0f;
                            s1--;
                        } while (k < 4 && s1 > 0);
                    }
                    seg--;
                    spr.unkC -= 9.0f;
                } while (seg != &D_overlay_40_028024F0[0]);
            }

            if (D_overlay_40_028025B0[i] >= 0x15) {
                spr.unk10 -= 10.0f;
                spr.unkC -= 4.0f;
                spr.unk8 = D_overlay_40_02802558;
                camDo2DSprite(&frontgfx, frontmtx, frontvtx, &spr, *(void **) (frontendptrs + 0x218), 0, 0xFF);
            }

            if (flag == 0) {
                if (joyGetPressed((s32) *(u8 *) ((u8 *) player + 0x8C)) & 0x8000) {
                    D_overlay_40_02802565 = 5;
                }
                if (joyGetPressed((s32) *(u8 *) ((u8 *) player + 0x8C)) & 0x4000) {
                    D_overlay_40_02802565 = 3;
                }
            }

            if (i + 1 < (s32) numberOfPlayers) {
                if (*(u16 *) ((u8 *) player + 0x9C) != *(u16 *) ((u8 *) orderedPlayers[i + 1] + 0x9C)) {
                    tie = i + 1;
                }
            }
            rowY += 0x1A;
            i++;
        } while (i < (s32) numberOfPlayers);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/func_overlay_40_02801D60_1F5B920.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *frontMultiStatsBarGetTiltList(void) {
    return D_overlay_40_02802588;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o40/overlay_40/frontMultiStatsBarGetTiltList.s")
#endif
