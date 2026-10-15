#include "common.h"

/* decomp: externs */
void starfieldInit(s32, s32, s32, s32, s32, s32, s32);
void starfieldFree(void);
void loadFrontEndList(void *);
void setupFrontEndList(void *);
void freeFrontEndList(void *);
s32 levelGetWorld(u32);
s32 mainGetGameFlag(s32);
void camStandardOrtho(void **, void **);
void camCopyOrthoMatrix(f32 (*)[4]);
void matrixScale(f32, f32, f32, f32 (*)[4]);
void matrixTranslate(f32, f32, f32, f32 (*)[4]);
void mathMtxF2L(f32 (*)[4], void *);
void texDPTextureX(Gfx **, void *, s32, s32);
void lightObject(void *, s32, s32, s32);
void objPrintObject(void *, void *, void *, void *);
void func_overlay_9_00902880_1F03658(s32);
void func_overlay_9_00902978_1F03750(void *, s32);
void func_overlay_9_009030E8_1F03EC0(void *);
void func_overlay_9_00903908_1F046E0(s32);
void func_overlay_9_009037E4_1F045BC(void *, s16, s32);
void func_overlay_9_00903D0C_1F04AE4(void *);
s32 frontGetSelectableCharacter(s32, s32);
f32 Sinf(s32);
extern void *D_800FF518;
extern s16 D_800FF9E0;
extern void *D_800FF5A0;
extern s32 runInOneFrame;
extern s32 pausePlayer;
extern u8 D_overlay_9_009043F8[];
extern u8 D_overlay_9_00904400[];
extern u8 D_overlay_9_0090441C[];
extern u8 D_overlay_9_00904424[];
extern u8 D_overlay_9_0090448C[];
extern u8 D_overlay_9_0090469C[];
extern s16 D_overlay_9_0090444C[];
extern u8 D_overlay_9_00904990[];
extern s32 D_overlay_9_00904908;
extern s32 D_overlay_9_0090490C;
extern s32 D_overlay_9_00904914;
extern f32 D_overlay_9_00909790;
extern f32 D_overlay_9_00909794;
extern f32 D_overlay_9_00909798;
extern f32 D_overlay_9_0090979C;
extern f32 D_overlay_9_009097A0;
extern f32 D_overlay_9_009097A4;
extern s32 D_overlay_9_009097A8;
extern f32 D_overlay_9_009097AC;
extern s32 D_overlay_9_009097B0;
extern s32 D_overlay_9_009097B4;
extern s32 D_overlay_9_009097B8;
extern s32 D_overlay_9_009097BC;
extern s32 D_overlay_9_009097C0;
extern s32 D_overlay_9_009097C4;
extern s32 D_overlay_9_009097C8;
extern s16 D_overlay_9_009097CC;
extern s32 D_overlay_9_00904910;
extern s16 D_overlay_9_00904918;
extern u8 currentobjects[];
extern void *frontendptrs[];
extern Gfx *frontgfx;
extern u8 *frontmtx;
extern void *frontvtx;
extern u8 D_overlay_9_009043C8;
extern u8 D_overlay_9_009043E0;
extern u8 D_overlay_9_009043C9[];
extern u8 D_overlay_9_009043E1[];
/* frontMap additions */
void amSndPlay(u16 soundID, void *handlePtr);
void amTuneStop(s32);
void mainResetRegion(void);
s32 levelGetRegionNo(u32);
void mainValidateRestart(s32 *, s32 *, s32 *);
void pauseSetNewLevel(s32, s32, s32, s32);
void pauseClearScreen(void);
void pauseSetScreen(s32);
void rcpClearScreen(Gfx **, u8 **, s32);
void rcpClearZBuffer(Gfx **, s32, s32, s32, s32, s32, s32);
void camSetNo(s32, Gfx *);
void camSetView(Gfx **, s32);
void camSetFOV(f32, s32);
void camStandardPersp(Gfx **, u8 **);
void camOverrideProjScales(f32, f32);
void camDo2DSprite(Gfx **, u8 **, void **, s16 *, s32, s32, s32);
void fontColour(s32, s32, s32, s32, s32);
void fontPrintXY(Gfx **, s32, s32, s8 *, s32);
void fontUseFont(s32);
void frontDrawObj(s32);
s8 *frontGetWorldName(u8);
void starfieldDrawSP(Gfx **, s32);
void starfieldMove(f32, f32, s32, s32);
s32 objGetPlayerNo(s32);
void func_overlay_9_00902FB0_1F03D88(s16, s16, s16, s16);
void func_overlay_9_0090343C_1F04214(s32);
void func_overlay_9_009039F0_1F047C8(void);
extern s8 frontJoyDx[];
extern s8 frontJoyDy[];
extern u8 allLevelCheat;
extern u8 racingCharacter;
extern s16 D_overlay_9_00904438[];
extern f32 D_overlay_9_00904970;
extern f32 D_overlay_9_00904974;
extern f32 D_overlay_9_00904978;
extern f32 D_overlay_9_0090497C;
extern f32 D_overlay_9_00904980;
extern s8 D_overlay_9_00904958[];
extern s8 D_overlay_9_00904968[];
extern u8 D_809043A0[];
extern s16 D_overlay_9_0090475C;
extern u8 D_overlay_9_009047DC;
extern s8 D_overlay_9_009043C0;
extern s8 D_overlay_9_009043C1[];

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitMap(s32 arg0) {
    u8 *ent;
    u8 *p;
    u8 *obj;
    Game *game;
    s32 i;
    s32 worldId;
    s32 found;

    if (D_overlay_9_00904908 == 0) {
        D_overlay_9_009097C0 = arg0;
        if (arg0 == 1) {
            D_overlay_9_009097C4 = pausePlayer;
        } else {
            D_overlay_9_009097C4 = 0;
        }
        runInOneFrame = 1;
        loadFrontEndList(D_overlay_9_009043F8);
        loadFrontEndList(D_overlay_9_00904400);
        setupFrontEndList(D_overlay_9_0090441C);
        setupFrontEndList(D_overlay_9_00904424);
        *((s8 *)D_800FF5A0 + 0x3A) = 0;
        D_overlay_9_00909790 = 0.0f;
        D_overlay_9_00909794 = 0.0f;
        D_overlay_9_009097B4 = 0;
        p = D_overlay_9_0090448C;
        for (i = 0; i < 0xB; i++) {
            func_overlay_9_00903D0C_1F04AE4(p);
            p += 0x30;
        }
        if (runlinkIsModuleLoaded(5) != 0) {
            D_overlay_9_009097B0 = 0;
        } else {
            D_overlay_9_009097B0 = 1;
        }
        starfieldInit(0x320, 0x190, 0x190, 0x12C, -1, 0xFF, 0x12C);
        D_overlay_9_009097A8 = 0;
        ent = D_overlay_9_0090469C;
        D_overlay_9_0090490C = 0;
        if (ent[0] == 0) {
            p = D_overlay_9_00904990 + ent[1] * 0x4E0;
            D_overlay_9_00909798 = (f32)(*(s16 *)(p + 0x4CC) << 8);
            D_overlay_9_0090979C = (f32)(*(s16 *)(p + 0x4CE) << 8);
        } else {
            obj = currentobjects + (ent[1] << 5);
            D_overlay_9_00909798 = *(f32 *)(obj + 0xC) * 256.0f;
            D_overlay_9_0090979C = *(f32 *)(obj + 0x10) * 256.0f;
        }
        D_overlay_9_009097A0 = D_overlay_9_00909798;
        D_overlay_9_009097A4 = D_overlay_9_0090979C;
        D_overlay_9_009097AC = *(f32 *)(ent + 4);
        D_overlay_9_009097BC = (s32)*(f32 *)(ent + 8);
        D_overlay_9_009097B8 = 0;
        game = mainGetGame();
        if (mainGetGameFlag(0) != 0) {
            *(u16 *)((u8 *)game + 0x1C0) |= 0x40;
        }
        if (mainGetGameFlag(2) != 0) {
            *(u16 *)((u8 *)game + 0x2AC) |= 0x200;
        }
        D_overlay_9_00904914 = *(u8 *)game & 3;
        func_overlay_9_009037E4_1F045BC(D_800FF518, (s16)(D_overlay_9_00904914 << 8), 3);
        D_overlay_9_00904908 = 1;
        worldId = levelGetWorld(*(u16 *)((u8 *)game + D_overlay_9_00904914 * 0x76 + 0x1D0) >> 5);
        ent = D_overlay_9_0090469C;
        i = 0;
        found = 0;
        if (ent[0] != 0xFF) {
            do {
                if (worldId == ent[2]) {
                    found = 1;
                    func_overlay_9_00902880_1F03658(i);
                    D_overlay_9_00909798 = D_overlay_9_009097A0;
                    D_overlay_9_0090979C = D_overlay_9_009097A4;
                    D_overlay_9_00909790 = D_overlay_9_00909798;
                    D_overlay_9_00909794 = D_overlay_9_0090979C - 120.0f;
                } else {
                    i++;
                    ent += 0xC;
                }
            } while (ent[0] != 0xFF && !found);
        }
        D_overlay_9_009097C8 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/frontInitMap.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupMap(void) {
    starfieldFree();
    if (D_overlay_9_009097B0 != 0) {
        runlinkFreeCode(5);
    }
    freeFrontEndList(D_overlay_9_009043F8);
    freeFrontEndList(D_overlay_9_00904400);
    runInOneFrame = 0;
    D_overlay_9_00904908 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/frontCleanupMap.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMapInitWorldIcons(void) {
    u8 *p;
    s32 i;

    loadFrontEndList(D_overlay_9_00904400);
    setupFrontEndList(D_overlay_9_00904424);
    D_overlay_9_009097B4 = 0;
    p = D_overlay_9_0090448C;
    for (i = 0; i != 0xB; i++) {
        func_overlay_9_00903D0C_1F04AE4(p);
        p += 0x30;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/frontMapInitWorldIcons.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMapDrawWorldIcon(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    u8 *ent;
    u8 *p;
    u8 *obj;
    s32 found;
    s32 t1;
    s32 t0;

    D_overlay_9_00909790 = 0.0f;
    D_overlay_9_00909794 = 0.0f;
    ent = D_overlay_9_0090469C;
    found = 0;
    if (ent[0] != 0xFF) {
        do {
            if (arg0 == ent[2]) {
                found = 1;
                if (ent[0] == 0) {
                    p = D_overlay_9_00904990 + ent[1] * 0x4E0;
                    *(s16 *)(p + 0x4CC) = arg1;
                    *(s16 *)(p + 0x4CE) = arg2;
                    camStandardOrtho((void **)&frontgfx, (void **)&frontmtx);
                    func_overlay_9_00902978_1F03750(p, arg3);
                    func_overlay_9_009030E8_1F03EC0(p);
                } else {
                    obj = currentobjects + (ent[1] << 5);
                    *(f32 *)(obj + 0xC) = (f32)arg1;
                    *(f32 *)(obj + 0x10) = (f32)arg2;
                    t1 = arg3 << 7;
                    t0 = arg3 << 8;
                    *(s16 *)(currentobjects + 0x200) = (s16)(*(s16 *)(currentobjects + 0x200) + (arg3 << 8));
                    *(s16 *)(currentobjects + 0x220) = (s16)(*(s16 *)(currentobjects + 0x220) + t1);
                    *(s16 *)(currentobjects + 0x580) = (s16)(*(s16 *)(currentobjects + 0x580) + t1);
                    *(s16 *)(currentobjects + 0x240) = (s16)(*(s16 *)(currentobjects + 0x240) - (arg3 * 0xA0));
                    *(s16 *)(currentobjects + 0x1C0) = (s16)(*(s16 *)(currentobjects + 0x1C0) + t0);
                    *(s16 *)(currentobjects + 0x280) = (s16)(*(s16 *)(currentobjects + 0x280) + t0);
                    *(s16 *)(currentobjects + 0x560) = (s16)(*(s16 *)(currentobjects + 0x560) + t0);
                    *(s16 *)(currentobjects + 0x562) = (s16)(*(s16 *)(currentobjects + 0x562) + (arg3 << 5));
                    *(s16 *)(currentobjects + 0x1E0) = (s16)(*(s16 *)(currentobjects + 0x1E0) + t0);
                    func_overlay_9_00903908_1F046E0(ent[1]);
                }
            }
            ent += 0xC;
        } while (ent[0] != 0xFF && !found);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/frontMapDrawWorldIcon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMapCleanupWorldIcons(void) {
    freeFrontEndList(D_overlay_9_00904400);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/frontMapCleanupWorldIcons.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// World-map front end. World entries (D_overlay_9_0090469C, 12 B): +0 type (0 = map node,
// else object), +1 index, +2 world id, +3 visible flag, +4 f32 scroll target, +8 s16 target.
// World nodes (D_overlay_9_00904990, 0x4E0 B): +0x4C8 path ptr, +0x4CC/4CE/4D0 s16 pos,
// +0x4D4/4D6/4D8 s16 rotation, +0x4DA draw flag. Link table (D_overlay_9_009047DC, 0x14 B):
// +0 node id, +1 target id, +2/+3 direction codes, +4..+0x12 s16 line endpoints, +0x14 next id.
void frontMap(s32 arg0) {
    Game *game;
    Gfx *g;
    u8 *ent;                /* world entry for the current node */
    u8 *lvl;                /* level-select block */
    u8 *lk;                 /* link entry */
    u8 *fp;                 /* world entry walker */
    u8 *obj;
    u8 *wo;                 /* world node walker (0x4E0 stride) */
    u8 *path;
    u8 *tgt;
    u8 *vtx;
    u8 *sortList[11];       /* sp+0xF8 */
    char txt[0x30];         /* sp+0xC8 */
    s16 rot[3];             /* sp+0x130 */
    f32 pt[3];              /* sp+0x138 */
    struct {                /* sp+0x1AC: block passed to camDo2DSprite */
        s16 x0;
        s16 y0;
        s16 z0;
        s16 pad6;
        f32 scale;          /* 0x1B4 */
        f32 fx;             /* 0x1B8 */
        f32 fy;             /* 0x1BC */
        f32 fz;             /* 0x1C0 */
        u8 pad18[0x10];
        f32 fe;             /* 0x1D4 */
    } spr;
    s16 *rec;
    s16 *sp;
    s32 levelNo;            /* sp+0x14C, -1 = none */
    s32 levelSub;           /* sp+0x19C */
    s32 regionVal;          /* sp+0x148 */
    s32 foundSel;           /* sp+0x150 */
    s32 jxNeg;              /* s1: stick left  */
    s32 jxPos;              /* s2: stick right */
    s32 jyPos;              /* s3: stick down  */
    s32 jyNeg;              /* s4: stick up    */
    s32 found;
    s32 cnt;                /* s5 */
    s32 i;
    s32 sc;
    s32 x, y, x1, y1, x2, y2, camX, camY;
    s32 a, s0, s1, s6, t;
    s32 visFlag;
    s32 idx;
    s32 bx;
    s32 next;
    s32 swapped;
    f32 sx0, sy0;           /* sp+0x178 / sp+0x174 */
    f32 zoom, f20, scrollF, f6, f8, f18, f0;

    jxNeg = 0;
    jxPos = 0;
    jyPos = 0;
    jyNeg = 0;
    if (D_overlay_9_00904908 != 0) {
        objGetPlayerNo(0);  /* asm: first call, a0 not set here (stale), result unused */
        game = mainGetGame();
        ent = D_overlay_9_0090469C + D_overlay_9_0090490C * 0xC;
        lvl = (u8 *)game + D_overlay_9_00904914 * 0x76 + 0x15C;

        /* ---- A button: enter the selected world ---- */
        if ((joyGetPressed(D_overlay_9_009097C4) & 0x8000) && D_overlay_9_009097C8 == 0 &&
            ((((1 << ent[2]) & *(u16 *)((u8 *)game + D_overlay_9_00904914 * 0x76 + 0x1C0)) != 0) ||
             allLevelCheat != 0)) {
            levelNo = -1;
            amSndPlay(0x16D, 0);
            if (lvl[0x71] == ent[2]) {
                amTuneStop(ent[2]);
                mainResetRegion();
            }
            if (lvl[0x71] == ent[2] && D_overlay_9_009097C0 == 1) {
                levelNo = *(u16 *)(lvl + 0x74) >> 5;
                levelSub = *(u16 *)(lvl + 0x74) & 0x1F;
            } else {
                /* search the level table: rows of 4 s16 (world, then one level per player) */
                if (levelNo == -1) {
                    rec = (s16 *)&D_overlay_9_0090475C;
                    if (rec[0] != -1) {
                        do {
                            if (rec[0] == ent[2]) {
                                levelSub = 0;
                                levelNo = rec[1 + D_overlay_9_00904914];
                            } else {
                                rec += 4;
                            }
                        } while (levelNo == -1 && rec[0] != -1);
                    }
                }
            }
            if (levelNo != -1) {
                if (levelGetRegionNo(levelNo) != 0 || levelNo != (*(u16 *)(lvl + 0x74) >> 5)) {
                    lvl[5] = (u8)(lvl[5] & 0xE0);
                }
                regionVal = *(u16 *)(lvl + 4) & 0x1F;
                mainValidateRestart(&levelNo, &levelSub, &regionVal);
                lvl[5] = (u8)((regionVal & 0x1F) | (lvl[5] & 0xE0));
                if (D_overlay_9_009097C0 == 1) {
                    if ((D_overlay_9_00904914 & 3) == 3) {
                        D_overlay_9_00904914 = racingCharacter;
                    }
                    pauseSetNewLevel(levelNo, D_overlay_9_00904914, levelSub, 0x10);
                } else {
                    mainChangeLevel(levelNo, D_overlay_9_00904914, 0, 0x10, 1, 0);
                }
            }
        }

        sx0 = D_overlay_9_00909790;
        sy0 = D_overlay_9_00909794;
        rcpClearScreen(&frontgfx, &frontmtx, 0);
        pauseClearScreen();
        texDPInit(&frontgfx);
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xBC000002; g->words.w1 = 0;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xB6000000; g->words.w1 = 0x1001;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xF8000000; g->words.w1 = 0xFFFFFFFF;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xBC000008; g->words.w1 = 0x64009867;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xE7000000; g->words.w1 = 0;
        camSetNo(0, g);
        camSetView(&frontgfx, 0);
        camSetFOV(50.0f, 1);

        /* ---- stick directions for the selected player ---- */
        if (D_overlay_9_009097C8 == 0) {
            t = frontJoyDx[D_overlay_9_009097C4];
            if (t < -0x20) {
                jxNeg = 1;
            } else if (t >= 0x21) {
                jxPos = 1;
            }
            t = frontJoyDy[D_overlay_9_009097C4];
            if (t < -0x20) {
                jyNeg = 1;
            } else if (t >= 0x21) {
                jyPos = 1;
            }
        }

        /* ---- move the cursor along the link table ---- */
        if (D_overlay_9_009097A8 == 0) {
            lk = (u8 *)&D_overlay_9_009047DC;
            found = 0;
            if (D_overlay_9_009047DC != 0xFF) {
                do {
                    if (D_overlay_9_0090490C == lk[0]) {
                        if (D_overlay_9_0090469C[lk[1] * 0xC + 3] != 0 &&
                            D_overlay_9_0090469C[lk[0] * 0xC + 3] != 0 &&
                            ((jxNeg && lk[2] == 0) || (jxPos && lk[2] == 1) ||
                             (jyNeg && lk[2] == 3) || (jyPos && lk[2] == 2))) {
                            foundSel = lk[1];
                            found = 1;
                        }
                    }
                    if (found == 0 && D_overlay_9_0090490C == lk[1]) {
                        if (D_overlay_9_0090469C[lk[1] * 0xC + 3] != 0 &&
                            D_overlay_9_0090469C[lk[0] * 0xC + 3] != 0 &&
                            ((jxNeg && lk[3] == 0) || (jxPos && lk[3] == 1) ||
                             (jyNeg && lk[3] == 3) || (jyPos && lk[3] == 2))) {
                            foundSel = lk[0];
                            found = 1;
                        }
                    }
                    next = lk[0x14];
                    lk += 0x14;
                } while (next != 0xFF && found == 0);
            }
            if (found != 0) {
                amSndPlay(0x16B, 0);        /* asm: 3rd arg is stale (found flag), not passed */
                func_overlay_9_00902880_1F03658(foundSel);
            } else if (jxNeg != 0 || jxPos != 0 || jyPos != 0 || jyNeg != 0) {
                amSndPlay(0x16E, 0);        /* asm: 3rd arg is stale, not passed */
            }
        }
        if (D_overlay_9_009097A8 != 0) {
            t = D_overlay_9_009097A8 - arg0;
            D_overlay_9_009097A8 = t;
            if (t < 0) {
                D_overlay_9_009097A8 = 0;
            }
            goto block_90;
        }

        /* ---- ease camera toward the selected node: arg0 steps, 4x unrolled ---- */
        cnt = 0;
        if (arg0 > 0) {
            f20 = *(f32 *)(D_overlay_9_0090469C + D_overlay_9_0090490C * 0xC + 4);
            if ((arg0 & 3) != 0) {
                zoom = D_overlay_9_0090979C - 120.0f;
                cnt = 1;
                scrollF = D_overlay_9_00909798 - D_overlay_9_00909790;
                if ((arg0 & 3) != 1) {
                    do {
                        cnt += 1;
                        D_overlay_9_00909790 += scrollF * 0.125f;
                        D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                        scrollF = D_overlay_9_00909798 - D_overlay_9_00909790;
                        D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904970;
                    } while ((arg0 & 3) != cnt);
                }
                D_overlay_9_00909790 += scrollF * 0.125f;
                D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904970;
                if (cnt != arg0) {
                    goto scroll_tail;
                }
            } else {
scroll_tail:
                zoom = D_overlay_9_0090979C - 120.0f;
                i = cnt + 4;
                scrollF = (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                f6 = zoom - D_overlay_9_00909794;
                if (i != arg0) {
                    do {
                        D_overlay_9_00909790 += scrollF;
                        D_overlay_9_00909794 += f6 * 0.125f;
                        i += 4;
                        D_overlay_9_00909790 += (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                        D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904974;
                        D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                        D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904978;
                        D_overlay_9_00909790 += (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                        D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                        D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_0090497C;
                        D_overlay_9_00909790 += (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                        D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                        scrollF = (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                        f6 = zoom - D_overlay_9_00909794;
                        D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904980;
                    } while (i != arg0);
                }
                D_overlay_9_00909790 += scrollF;
                D_overlay_9_00909794 += f6 * 0.125f;
                D_overlay_9_00909790 += (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904974;
                D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904978;
                D_overlay_9_00909790 += (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_0090497C;
                D_overlay_9_00909790 += (D_overlay_9_00909798 - D_overlay_9_00909790) * 0.125f;
                D_overlay_9_00909794 += (zoom - D_overlay_9_00909794) * 0.125f;
                D_overlay_9_009097AC += (f20 - D_overlay_9_009097AC) * D_overlay_9_00904980;
            }
block_90:
            cnt = 0;
        }

        /* ---- second ease: D98/D9C/BC toward the node target (4x unrolled) ---- */
        if (arg0 > 0) {
            ent = D_overlay_9_0090469C + D_overlay_9_0090490C * 0xC;
            if ((arg0 & 3) != 0) {
                do {
                    cnt += 1;
                    D_overlay_9_009097BC += (*(s16 *)(ent + 8) - D_overlay_9_009097BC) >> 3;
                    D_overlay_9_0090979C += (D_overlay_9_009097A4 - D_overlay_9_0090979C) * 0.125f;
                    D_overlay_9_00909798 += (D_overlay_9_009097A0 - D_overlay_9_00909798) * 0.125f;
                } while ((arg0 & 3) != cnt);
                if (cnt != arg0) {
                    goto ease2_tail;
                }
            } else {
ease2_tail:
                a = *(s16 *)(ent + 8);
                do {
                    D_overlay_9_009097BC += (a - D_overlay_9_009097BC) >> 3;
                    D_overlay_9_00909798 += (D_overlay_9_009097A0 - D_overlay_9_00909798) * 0.125f;
                    D_overlay_9_0090979C += (D_overlay_9_009097A4 - D_overlay_9_0090979C) * 0.125f;
                    D_overlay_9_009097BC += (a - D_overlay_9_009097BC) >> 3;
                    D_overlay_9_00909798 += (D_overlay_9_009097A0 - D_overlay_9_00909798) * 0.125f;
                    D_overlay_9_0090979C += (D_overlay_9_009097A4 - D_overlay_9_0090979C) * 0.125f;
                    D_overlay_9_009097BC += (a - D_overlay_9_009097BC) >> 3;
                    D_overlay_9_00909798 += (D_overlay_9_009097A0 - D_overlay_9_00909798) * 0.125f;
                    D_overlay_9_0090979C += (D_overlay_9_009097A4 - D_overlay_9_0090979C) * 0.125f;
                    D_overlay_9_009097BC += (a - D_overlay_9_009097BC) >> 3;
                    D_overlay_9_00909798 += (D_overlay_9_009097A0 - D_overlay_9_00909798) * 0.125f;
                    D_overlay_9_0090979C += (D_overlay_9_009097A4 - D_overlay_9_0090979C) * 0.125f;
                    cnt += 4;
                } while (cnt != arg0);
            }
            cnt = 0;
        }

        camStandardPersp(&frontgfx, &frontmtx);
        spr.x0 = 0;
        spr.y0 = 0;
        spr.z0 = 0;
        spr.fz = 0.0f;
        spr.fe = 0.0f;
        spr.scale = 0.5f;
        texDPInit(&frontgfx);
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xE7000000; g->words.w1 = 0;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xFA000000; g->words.w1 = 0xFFFFFFFF;

        /* ---- 2D sprites from the (x, y) pair list at D_overlay_9_00904438 ---- */
        if (D_overlay_9_00904438[0] != -1) {
            sp = D_overlay_9_00904438;
            do {
                spr.fx = (f32)sp[0] - D_overlay_9_00909790 * 0.75f;
                y = sp[1];
                sp += 2;
                spr.fy = 120.0f - ((f32)y - D_overlay_9_00909794 * 0.75f);
                camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, (s16 *)&spr,
                              *(s32 *)((u8 *)frontendptrs + 0x108), 5, 0xFF);
            } while (sp[0] != -1);
            cnt = 0;
        }
        starfieldDrawSP(&frontgfx, 0x43800000);
        camStandardPersp(&frontgfx, &frontmtx);

        /* ---- per-entry visibility (world entries) ---- */
        if (D_overlay_9_0090469C[0] != 0xFF) {
            fp = D_overlay_9_0090469C;
            do {
                if ((*(u16 *)((u8 *)game + D_overlay_9_00904914 * 0x76 + 0x1C0) & (1 << fp[2])) != 0 ||
                    allLevelCheat != 0) {
                    fp[3] = 1;
                } else {
                    fp[3] = 0;
                }
                if (fp[2] == 1) {
                    if (mainGetGameFlag(0x5D) != 0) {
                        fp[3] = 0;
                    }
                }
                if (fp[0] == 1 && fp[3] != 0) {
                    func_overlay_9_00903908_1F046E0(fp[1]);
                }
                fp += 0xC;
            } while (fp[0] != 0xFF);
        }
        texDPInit(&frontgfx);

        /* ---- world nodes: path update, visibility, sort list ---- */
        wo = D_overlay_9_00904990;
        cnt = 0;
        do {
            path = *(u8 **)(wo + 0x4C8);
            if ((s8)path[0x18] != -1) {
                f0 = Sinf(*(s16 *)(wo + 0x4D4));
                pt[1] = 0.0f;
                pt[0] = f0 * (f32)*(s16 *)(path + 0x28);
                pt[2] = Cosf(*(s16 *)(wo + 0x4D4)) * (f32)*(s16 *)(path + 0x28) * *(f32 *)(path + 0x1C);
                rot[0] = *(s16 *)(path + 0x20);
                rot[1] = *(s16 *)(wo + 0x4D6);
                rot[2] = *(s16 *)(wo + 0x4D8);
                pointListRPY(1, rot, (s32 *)pt, pt);
                tgt = D_overlay_9_00904990 + (s8)path[0x18] * 0x4E0;
                *(s16 *)(wo + 0x4CC) = (s16)(s32)((f32)*(s16 *)(tgt + 0x4CC) + pt[0]);
                *(s16 *)(wo + 0x4CE) = (s16)(s32)((f32)*(s16 *)(tgt + 0x4CE) + pt[1]);
                *(s16 *)(wo + 0x4D0) = (s16)(s32)((f32)*(s16 *)(tgt + 0x4D0) + pt[2]);
                *(s16 *)(wo + 0x4D4) = (s16)(*(s16 *)(wo + 0x4D4) + *(s16 *)(path + 0x26) * arg0);
                *(s16 *)(wo + 0x4D6) = (s16)(*(s16 *)(wo + 0x4D6) + *(s16 *)(path + 0x2A));
                *(s16 *)(wo + 0x4D8) = (s16)(*(s16 *)(wo + 0x4D8) + *(s16 *)(path + 0x2C));
            }
            sortList[cnt] = wo;
            idx = ((s8)path[0x18] != -1) ? (s8)path[0x18] : cnt;
            cnt += 1;
            visFlag = 0;
            if (D_overlay_9_0090469C[0] != 0xFF) {
                fp = D_overlay_9_0090469C;
                for (;;) {
                    if (fp[0] == 0 && idx == fp[1] &&
                        (*(u16 *)((u8 *)game + D_overlay_9_00904914 * 0x76 + 0x1C0) & (1 << fp[2])) != 0) {
                        visFlag = 1;
                    }
                    fp += 0xC;
                    if (visFlag != 0 || fp[0] == 0xFF) {
                        break;
                    }
                }
            }
            if (allLevelCheat != 0) {
                visFlag = 1;
            }
            wo[0x4DA] = (u8)visFlag;
            wo += 0x4E0;
        } while (cnt != 0xB);

        /* ---- bubble sort of the 11 node pointers (pairs i, i+1 for i = 0..9) ---- */
        do {
            swapped = 0;
            i = 0;
            do {
                if (*(s16 *)(sortList[i] + 0x4D0) < *(s16 *)(sortList[i + 1] + 0x4D0)) {
                    wo = sortList[i];
                    sortList[i] = sortList[i + 1];
                    sortList[i + 1] = wo;
                    swapped = 1;
                }
                i += 1;
            } while (i < 10);
        } while (swapped != 0);

        spr.scale = 1.0f;
        spr.fe = 0.0f;
        i = 0;
        do {
            wo = sortList[i];
            func_overlay_9_00902978_1F03750(wo, arg0);
            if (wo[0x4DA] != 0) {
                camStandardOrtho((void **)&frontgfx, (void **)&frontmtx);
                func_overlay_9_009030E8_1F03EC0(wo);
            }
            i += 1;
        } while (i < 11);

        g = frontgfx; frontgfx++;
        g->words.w1 = 0; g->words.w0 = 0xE7000000;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xBA001402; g->words.w1 = 0;
        g = frontgfx; frontgfx++;
        g->words.w1 = 0xFFFDF6FB; g->words.w0 = 0xFCFFFFFF;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xFA000000; g->words.w1 = 0x400080;

        /* ---- background grid lines: x from -0x96 to 0x44C step 0x32 ---- */
        bx = -0x96;
        do {
            s0 = bx - (s32)(D_overlay_9_00909790 * 1.5f);
            s6 = s0 + 0x32;
            if (s0 < 0x140) {
                if (s6 > 0) {
                    y = -0x64;
                    do {
                        y1 = (s32)((f32)y - D_overlay_9_00909794 * 1.5f);
                        y2 = y1 + 0x32;
                        if (y1 < 0xF0 && y2 > 0) {
                            func_overlay_9_00902FB0_1F03D88((s16)s0, (s16)y1, (s16)s6, (s16)y1);
                            func_overlay_9_00902FB0_1F03D88((s16)s0, (s16)y1, (s16)s0, (s16)y2);
                        }
                        y += 0x32;
                    } while (y != 0x47E);
                }
            }
            bx += 0x32;
        } while (bx < 0x44C);

        texDPInit(&frontgfx);
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xBA001402; g->words.w1 = 0;
        g = frontgfx; frontgfx++;
        g->words.w1 = 0xFFFDF6FB; g->words.w0 = 0xFCFFFFFF;
        g = frontgfx; frontgfx++;
        g->words.w0 = 0xFA000000; g->words.w1 = 0xFF0080;
        f20 = (viGetVideoMode() & 1) ? 0.75f : 1.0f;

        /* ---- link lines between visible nodes ---- */
        if (D_overlay_9_009047DC != 0xFF) {
            lk = (u8 *)&D_overlay_9_009047DC;
            do {
                if (D_overlay_9_0090469C[lk[0] * 0xC + 3] != 0 && D_overlay_9_0090469C[lk[1] * 0xC + 3] != 0) {
                    camX = (s32)(D_overlay_9_00909790 * f20);
                    camY = (s32)D_overlay_9_00909794;
                    x = (s16)(((s32)((f32)*(s16 *)(lk + 4) * f20) - camX) + 0xA0);
                    y = (s16)(*(s16 *)(lk + 6) - camY);
                    x1 = ((s32)((f32)*(s16 *)(lk + 8) * f20) - camX) + 0xA0;
                    y1 = *(s16 *)(lk + 0xA) - camY;
                    func_overlay_9_00902FB0_1F03D88((s16)x, (s16)y, (s16)x1, (s16)y1);
                    if (*(s16 *)(lk + 0xC) != -1) {
                        x2 = ((s32)((f32)*(s16 *)(lk + 0xC) * f20) - camX) + 0xA0;
                        y2 = *(s16 *)(lk + 0xE) - camY;
                        func_overlay_9_00902FB0_1F03D88((s16)x1, (s16)y1, (s16)x2, (s16)y2);
                        if (*(s16 *)(lk + 0x10) != -1) {
                            func_overlay_9_00902FB0_1F03D88((s16)x2, (s16)y2,
                                (s16)(((s32)((f32)*(s16 *)(lk + 0x10) * f20) - camX) + 0xA0),
                                (s16)(*(s16 *)(lk + 0x12) - camY));
                        }
                    }
                }
                next = lk[0x14];
                lk += 0x14;
            } while (next != 0xFF);
        }
        texDPTextureX(&frontgfx, 0, 0, 0);
        camStandardOrtho((void **)&frontgfx, (void **)&frontmtx);
        g = frontgfx; frontgfx++;
        g->words.w1 = 0xFFFFFFFF; g->words.w0 = 0xFA000000;

        /* ---- node quads (4 vertices of 10 B each, plus one display-list word) ---- */
        if (D_overlay_9_0090469C[0] != 0xFF) {
            fp = D_overlay_9_0090469C;
            do {
                if (fp[3] != 0) {
                    if (fp[0] == 0) {
                        wo = D_overlay_9_00904990 + fp[1] * 0x4E0;
                        s0 = *(s16 *)(wo + 0x4CC) - (s32)D_overlay_9_00909790;
                        s1 = (0x78 - *(s16 *)(wo + 0x4CE)) + (s32)D_overlay_9_00909794;
                    } else {
                        obj = currentobjects + (fp[1] << 5);
                        s0 = (s32)(*(f32 *)(obj + 0xC) - (f32)(s32)D_overlay_9_00909790);
                        s1 = (s32)(120.0f - (*(f32 *)(obj + 0x10) - (f32)(s32)D_overlay_9_00909794));
                    }
                    s0 -= 0x1E;
                    a = *(s16 *)(fp + 8) - D_overlay_9_009097BC;
                    if (a >= 0x1389) {
                        a = 0x1388;
                    }
                    if (a < -0x1388) {
                        a = -0x1388;
                    }
                    sc = a >> 8;
                    if (sc == 1) {
                        sc = 2;
                    } else if (sc == -1) {
                        sc = -2;
                    }
                    vtx = (u8 *)frontvtx;
                    g = frontgfx; frontgfx++;
                    g->words.w0 = (((((u32)vtx + 0x80000000u) & 6) | 0x20) & 0xFF) << 16 | 0x04000030;
                    g->words.w1 = (u32)vtx + 0x80000000u;

                    /* vertex 0 */
                    *(s16 *)(vtx + 0) = (s16)(s0 - D_overlay_9_009043C0);
                    *(s16 *)(vtx + 2) = (s16)(D_overlay_9_009043C1[0] * sc + s1);
                    *(s16 *)(vtx + 4) = 0;
                    vtx[6] = 0; vtx[7] = 0xA0; vtx[8] = 0; vtx[9] = 0xFF;
                    vtx += 0xA;
                    /* vertex 1 */
                    *(s16 *)(vtx + 0) = (s16)(s0 - D_overlay_9_009043C1[1]);
                    *(s16 *)(vtx + 2) = (s16)(D_overlay_9_009043C1[2] * sc + s1);
                    *(s16 *)(vtx + 4) = 0;
                    vtx[6] = 0; vtx[7] = 0xA0; vtx[8] = 0; vtx[9] = 0xFF;
                    vtx += 0xA;
                    /* vertex 2 */
                    *(s16 *)(vtx + 0) = (s16)(s0 - D_overlay_9_009043C1[3]);
                    *(s16 *)(vtx + 2) = (s16)(D_overlay_9_009043C1[4] * sc + s1);
                    *(s16 *)(vtx + 4) = 0;
                    vtx[6] = 0; vtx[7] = 0xA0; vtx[8] = 0; vtx[9] = 0xFF;
                    vtx += 0xA;
                    /* vertex 3 */
                    *(s16 *)(vtx + 0) = (s16)(s0 - D_overlay_9_009043C1[5]);
                    *(s16 *)(vtx + 2) = (s16)(D_overlay_9_009043C1[6] * sc + s1);
                    *(s16 *)(vtx + 4) = 0;
                    vtx[6] = 0; vtx[7] = 0xA0; vtx[8] = 0; vtx[9] = 0xFF;
                    vtx += 0xA;
                    frontvtx = vtx;

                    g = frontgfx; frontgfx++;
                    g->words.w0 = 0x05110020;
                    g->words.w1 = (u32)D_809043A0;
                }
                fp += 0xC;
            } while (fp[0] != 0xFF);
        }

        /* ---- labels: names and counters for each visible entry ---- */
        cnt = 0;
        if (D_overlay_9_0090469C[0] != 0xFF) {
            fp = D_overlay_9_0090469C;
            do {
                if (fp[0] == 0) {
                    wo = D_overlay_9_00904990 + fp[1] * 0x4E0;
                    s0 = *(s16 *)(wo + 0x4CC);
                    s1 = *(s16 *)(wo + 0x4CE);
                } else {
                    obj = currentobjects + (fp[1] << 5);
                    s0 = (s16)(s32)*(f32 *)(obj + 0xC);
                    s1 = (s16)(s32)*(f32 *)(obj + 0x10);
                }
                x = (s0 - (s32)D_overlay_9_00909790) + 0xA0;
                y = (s32)((f32)s1 - D_overlay_9_00909794);
                fontUseFont(2);
                if (cnt == D_overlay_9_0090490C) {
                    fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
                } else {
                    fontColour(0, 0xFF, 0, 0xFF, 0xFF);
                }
                if (fp[3] != 0) {
                    fontPrintXY(&frontgfx, x + 0x1E, y - 0xF, frontGetWorldName(fp[2]), 0);
                    fontUseFont(3);
                    if (cnt == D_overlay_9_0090490C) {
                        fontColour(0x62, 0x62, 0, 0xFF, 0xFF);
                    } else {
                        fontColour(0, 0x62, 0, 0xFF, 0xFF);
                    }
                    sprintf(txt, (char *)D_overlay_9_00904958, x - 0xA0, y - 0x78);
                    x2 = x + 0x1B;
                    fontPrintXY(&frontgfx, x2, y + 6, (s8 *)txt, 0);
                    sprintf(txt, (char *)D_overlay_9_00904968,
                            *(s16 *)(fp + 8) - *(s16 *)(D_overlay_9_0090469C + D_overlay_9_0090490C * 0xC + 8));
                    fontPrintXY(&frontgfx, x2, y + 0xF, (s8 *)txt, 0);
                }
                next = fp[0xC];
                fp += 0xC;
                cnt += 1;
            } while (next != 0xFF);
        }

        func_overlay_9_009039F0_1F047C8();
        camSetView(&frontgfx, 0);
        camStandardPersp(&frontgfx, &frontmtx);
        func_overlay_9_0090343C_1F04214(arg0);
        rcpClearZBuffer(&frontgfx, 0x140, 0xF0, 0, 0, 0x13F, 0xEF);
        camOverrideProjScales(1.0f, 1.0f);
        camSetFOV(50.0f, 1);
        camStandardPersp(&frontgfx, &frontmtx);
        frontDrawObj(0x13);
        frontDrawObj(0x20);
        camSetFOV(50.0f, 1);
        starfieldMove(0.5f - (D_overlay_9_00909790 - sx0), D_overlay_9_00909794 - sy0, 0, arg0);

        /* ---- scroll the world-object texture offsets ---- */
        *(s16 *)(currentobjects + 0x200) = (s16)(*(s16 *)(currentobjects + 0x200) + (arg0 << 8));
        *(s16 *)(currentobjects + 0x220) = (s16)(*(s16 *)(currentobjects + 0x220) + (arg0 << 7));
        *(s16 *)(currentobjects + 0x240) = (s16)(*(s16 *)(currentobjects + 0x240) - (arg0 * 0xA0));
        *(s16 *)(currentobjects + 0x1C0) = (s16)(*(s16 *)(currentobjects + 0x1C0) + (arg0 << 8));
        *(s16 *)(currentobjects + 0x580) = (s16)(*(s16 *)(currentobjects + 0x580) + (arg0 << 7));
        *(s16 *)(currentobjects + 0x1E0) = (s16)(*(s16 *)(currentobjects + 0x1E0) + (arg0 << 8));
        *(s16 *)(currentobjects + 0x280) = (s16)(*(s16 *)(currentobjects + 0x280) + (arg0 << 8));
        *(s16 *)(currentobjects + 0x560) = (s16)(*(s16 *)(currentobjects + 0x560) + (arg0 << 8));
        *(s16 *)(currentobjects + 0x562) = (s16)(*(s16 *)(currentobjects + 0x562) + (arg0 << 5));

        if (D_overlay_9_009097C0 == 1) {
            if (joyGetPressed(D_overlay_9_009097C4) & 0x4000) {
                pauseSetScreen(1);
                D_overlay_9_009097C8 = 1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/frontMap.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_9_00902880_1F03658(s32 arg0) {
    u8 *ent;
    u8 *p;
    u8 *obj;

    D_overlay_9_0090490C = arg0;
    ent = D_overlay_9_0090469C + arg0 * 0xC;
    if (ent[0] == 0) {
        p = D_overlay_9_00904990 + ent[1] * 0x4E0;
        D_overlay_9_009097A0 = (f32)*(s16 *)(p + 0x4CC);
        D_overlay_9_009097A4 = (f32)*(s16 *)(p + 0x4CE);
    } else {
        obj = currentobjects + (ent[1] << 5);
        D_overlay_9_009097A0 = *(f32 *)(obj + 0xC);
        D_overlay_9_009097A4 = *(f32 *)(obj + 0x10);
    }
    if (D_overlay_9_009097A8 == 0) {
        D_overlay_9_009097A8 = 0xF;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_00902880_1F03658.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Texture-coordinate scroll for one world-map icon entry a (stride 0x4E0).
// Coordinates are kept in 23 records of 0x10 bytes: an s16 origin pair at +0 and two
// s16 pairs at +4 / +8 that follow the origin's movement (delta-tracked).
// Pass 1 (texture 0x4C4, scroll record 0x4C8) advances by step * arg1 on every call.
// Pass 2 (texture 0x4C0) counts timer 0x4D2 down by arg1 (before its NULL check); when
// the timer is below zero it is reloaded from scroll+0x0A (s8) and one step is applied.
// Texture wrap mask is (tex size in 32-px units << 5) - 1, cf. DKR weather.c snow scroll.
void func_overlay_9_00902978_1F03750(void *arg0, s32 arg1) {
    u8 *a = (u8 *)arg0;
    u8 *scroll = *(u8 **)(a + 0x4C8);
    u8 *tex;
    u8 *q;
    s16 *s;
    s32 stepX;
    s32 stepY;
    s32 maskX;
    s32 maskY;
    s32 ox;
    s32 oy;
    s32 nx;
    s32 ny;
    s32 timer;
    s32 i;

    tex = *(u8 **)(a + 0x4C4);
    if (tex != NULL) {
        stepX = *(s16 *)(scroll + 0x10) * arg1;
        stepY = *(s16 *)(scroll + 0x12) * arg1;
        maskX = (tex[0] << 5) - 1;
        maskY = (tex[1] << 5) - 1;

        s = (s16 *)(a + 0x264);
        ox = s[0];
        oy = s[1];
        nx = (ox + stepX) & maskX;
        ny = (oy + stepY) & maskY;
        s[0] = nx;
        s[1] = ny;
        s[2] += nx - ox;
        s[3] += ny - oy;
        s[4] += nx - ox;
        s[5] += ny - oy;

        s = (s16 *)(a + 0x274);
        ox = s[0];
        oy = s[1];
        nx = (ox + stepX) & maskX;
        ny = (oy + stepY) & maskY;
        s[0] = nx;
        s[1] = ny;
        s[2] += nx - ox;
        s[3] += ny - oy;
        s[4] += nx - ox;
        s[5] += ny - oy;

        s = (s16 *)(a + 0x284);
        ox = s[0];
        oy = s[1];
        nx = (ox + stepX) & maskX;
        ny = (oy + stepY) & maskY;
        s[0] = nx;
        s[1] = ny;
        s[2] += nx - ox;
        s[3] += ny - oy;
        s[4] += nx - ox;
        s[5] += ny - oy;

        for (i = 0; i < 5; i++) {
            q = a + 0x290 + i * 0x40;

            s = (s16 *)(q + 0x04);
            ox = s[0];
            oy = s[1];
            nx = (ox + stepX) & maskX;
            ny = (oy + stepY) & maskY;
            s[0] = nx;
            s[1] = ny;
            s[2] += nx - ox;
            s[3] += ny - oy;
            s[4] += nx - ox;
            s[5] += ny - oy;

            s = (s16 *)(q + 0x14);
            ox = s[0];
            oy = s[1];
            nx = (ox + stepX) & maskX;
            ny = (oy + stepY) & maskY;
            s[0] = nx;
            s[1] = ny;
            s[2] += nx - ox;
            s[3] += ny - oy;
            s[4] += nx - ox;
            s[5] += ny - oy;

            s = (s16 *)(q + 0x24);
            ox = s[0];
            oy = s[1];
            nx = (ox + stepX) & maskX;
            ny = (oy + stepY) & maskY;
            s[0] = nx;
            s[1] = ny;
            s[2] += nx - ox;
            s[3] += ny - oy;
            s[4] += nx - ox;
            s[5] += ny - oy;

            s = (s16 *)(q + 0x34);
            ox = s[0];
            oy = s[1];
            nx = (ox + stepX) & maskX;
            ny = (oy + stepY) & maskY;
            s[0] = nx;
            s[1] = ny;
            s[2] += nx - ox;
            s[3] += ny - oy;
            s[4] += nx - ox;
            s[5] += ny - oy;
        }
    }

    tex = *(u8 **)(a + 0x4C0);
    *(s16 *)(a + 0x4D2) = (s16)(*(s16 *)(a + 0x4D2) - arg1);
    if (tex != NULL) {
        timer = *(s16 *)(a + 0x4D2);
        if (timer < 0) {
            *(s16 *)(a + 0x4D2) = (s16)(timer + *(s8 *)(scroll + 0x0A));
            stepX = *(s16 *)(scroll + 0x0C);
            stepY = *(s16 *)(scroll + 0x0E);
            maskX = (tex[0] << 5) - 1;
            maskY = (tex[1] << 5) - 1;

            s = (s16 *)(a + 0x4);
            ox = s[0];
            oy = s[1];
            nx = (ox + stepX) & maskX;
            ny = (oy + stepY) & maskY;
            s[0] = nx;
            s[1] = ny;
            s[2] += nx - ox;
            s[3] += ny - oy;
            s[4] += nx - ox;
            s[5] += ny - oy;

            s = (s16 *)(a + 0x14);
            ox = s[0];
            oy = s[1];
            nx = (ox + stepX) & maskX;
            ny = (oy + stepY) & maskY;
            s[0] = nx;
            s[1] = ny;
            s[2] += nx - ox;
            s[3] += ny - oy;
            s[4] += nx - ox;
            s[5] += ny - oy;

            s = (s16 *)(a + 0x24);
            ox = s[0];
            oy = s[1];
            nx = (ox + stepX) & maskX;
            ny = (oy + stepY) & maskY;
            s[0] = nx;
            s[1] = ny;
            s[2] += nx - ox;
            s[3] += ny - oy;
            s[4] += nx - ox;
            s[5] += ny - oy;

            for (i = 0; i < 5; i++) {
                q = a + 0x30 + i * 0x40;

                s = (s16 *)(q + 0x04);
                ox = s[0];
                oy = s[1];
                nx = (ox + stepX) & maskX;
                ny = (oy + stepY) & maskY;
                s[0] = nx;
                s[1] = ny;
                s[2] += nx - ox;
                s[3] += ny - oy;
                s[4] += nx - ox;
                s[5] += ny - oy;

                s = (s16 *)(q + 0x14);
                ox = s[0];
                oy = s[1];
                nx = (ox + stepX) & maskX;
                ny = (oy + stepY) & maskY;
                s[0] = nx;
                s[1] = ny;
                s[2] += nx - ox;
                s[3] += ny - oy;
                s[4] += nx - ox;
                s[5] += ny - oy;

                s = (s16 *)(q + 0x24);
                ox = s[0];
                oy = s[1];
                nx = (ox + stepX) & maskX;
                ny = (oy + stepY) & maskY;
                s[0] = nx;
                s[1] = ny;
                s[2] += nx - ox;
                s[3] += ny - oy;
                s[4] += nx - ox;
                s[5] += ny - oy;

                s = (s16 *)(q + 0x34);
                ox = s[0];
                oy = s[1];
                nx = (ox + stepX) & maskX;
                ny = (oy + stepY) & maskY;
                s[0] = nx;
                s[1] = ny;
                s[2] += nx - ox;
                s[3] += ny - oy;
                s[4] += nx - ox;
                s[5] += ny - oy;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_00902978_1F03750.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_9_00902FB0_1F03D88(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 x0 = arg0;
    s32 y0 = arg1;
    s32 x1 = arg2;
    s32 y1 = arg3;
    s32 t;
    Gfx *g;

    if (x1 < x0) {
        t = x0;
        x0 = x1;
        x1 = t;
    }
    if (y1 < y0) {
        t = y0;
        y0 = y1;
        y1 = t;
    }
    if (x1 == x0) {
        x1 += 1;
    }
    y1 += 1;
    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 >= 0x140) {
        x1 = 0x13F;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (y1 >= 0xF0) {
        y1 = 0xEF;
    }
    if (x1 > 0 && x0 < 0x13F && y1 > 0 && y0 < 0xEF) {
        g = frontgfx++;
        g->words.w0 = ((x1 & 0x3FF) << 0xE) | 0xF6000000 | ((y1 & 0x3FF) * 4);
        g->words.w1 = ((x0 & 0x3FF) << 0xE) | ((y0 & 0x3FF) * 4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_00902FB0_1F03D88.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_9_009030E8_1F03EC0(void *arg0) {
    u8 *a = (u8 *)arg0;
    void *sp9C = *(void **)(a + 0x4C8);
    f32 sc;
    f32 mtx[4][4];
    u32 addr;
    Gfx *g;

    sc = 1.0f - (((f32)*(s16 *)(a + 0x4D0) * 0.5f) / 60.0f);
    camCopyOrthoMatrix(mtx);
    matrixScale(sc, sc, sc, mtx);
    matrixTranslate((f32)*(s16 *)(a + 0x4CC) - D_overlay_9_00909790,
                    120.0f - ((f32)*(s16 *)(a + 0x4CE) - D_overlay_9_00909794), 0.0f, mtx);
    mathMtxF2L(mtx, frontmtx);
    g = frontgfx++;
    g->words.w0 = 0x01000040;
    g->words.w1 = (u32)frontmtx + 0x80000000;
    addr = (u32)a + 0x80000170;
    frontmtx += 0x40;
    g = frontgfx++;
    g->words.w0 = (s32)((((addr & 6) | 0xC0) & 0xFF) << 0x10) | 0x04000000 | 0xF8;
    g->words.w1 = addr;
    texDPTextureX(&frontgfx, *(void **)(a + 0x4C0), 1, 0);
    g = frontgfx++;
    g->words.w0 = 0x05F10100;
    g->words.w1 = (u32)a + 0x80000000;
    g = frontgfx++;
    g->words.w1 = (u32)a + 0x80000100;
    g->words.w0 = 0x05610070;
    if (*(void **)(a + 0x4C4) != NULL) {
        camCopyOrthoMatrix(mtx);
        matrixScale(sc, sc, sc, mtx);
        matrixTranslate((f32)*(s16 *)(a + 0x4CC) - D_overlay_9_00909790,
                        120.0f - ((f32)*(s16 *)(a + 0x4CE) - D_overlay_9_00909794), 0.0f, mtx);
        mathMtxF2L(mtx, frontmtx);
        g = frontgfx++;
        g->words.w0 = 0x01000040;
        addr = (u32)a + 0x800003D0;
        g->words.w1 = (u32)frontmtx + 0x80000000;
        frontmtx += 0x40;
        g = frontgfx++;
        g->words.w0 = (s32)((((addr & 6) | 0xC0) & 0xFF) << 0x10) | 0x04000000 | 0xF8;
        g->words.w1 = addr;
        g = frontgfx++;
        g->words.w1 = 0;
        g->words.w0 = 0xE7000000;
        texDPTextureX(&frontgfx, *(void **)(a + 0x4C4), 5, 0);
        g = frontgfx++;
        g->words.w0 = 0xFA000000;
        g->words.w1 = *(s32 *)((u8 *)sp9C + 0x14);
        g = frontgfx++;
        g->words.w1 = (u32)a + 0x80000260;
        g->words.w0 = 0x05F10100;
        g = frontgfx++;
        g->words.w1 = (u32)a + 0x80000360;
        g->words.w0 = 0x05610070;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_009030E8_1F03EC0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// World map screen: joystick selection, scroll easing toward D_overlay_9_009097CC
// and world-based object update.
void func_overlay_9_0090343C_1F04214(s32 arg0) {
    s32 changed = 0;
    s32 prevSel;
    s32 scroll;
    s32 scrollStart;
    s32 mode;
    s32 steps;
    s32 i;
    s32 world;
    s32 found;
    u8 *entry;

    if (arg0 < D_overlay_9_00904918) {
        D_overlay_9_00904918 -= arg0;
    } else {
        D_overlay_9_00904918 = 0;
    }

    if ((joyGetPressed(D_overlay_9_009097C4) & 2) && (D_overlay_9_00904918 == 0) && (D_overlay_9_009097C8 == 0)) {
        prevSel = D_overlay_9_00904914;
        D_overlay_9_00904914 = frontGetSelectableCharacter(D_overlay_9_00904914, -1);
        if (prevSel != D_overlay_9_00904914) {
            D_overlay_9_009097CC -= 0x8000;
            D_overlay_9_00904910 = -1;
            D_overlay_9_00904918 = 7;
            changed = 1;
        }
    } else if ((joyGetPressed(D_overlay_9_009097C4) & 1) && (D_overlay_9_00904918 == 0)) {
        if (D_overlay_9_009097C8 == 0) {
            prevSel = D_overlay_9_00904914;
            D_overlay_9_00904914 = frontGetSelectableCharacter(D_overlay_9_00904914, 1);
            if (prevSel != D_overlay_9_00904914) {
                D_overlay_9_009097CC += 0x8000;
                D_overlay_9_00904910 = 1;
                D_overlay_9_00904918 = 7;
                changed = 1;
            }
        }
    }

    if (changed != 0) {
        /* level of the newly selected character's game slot (stride 0x76, +0x1D0) */
        world = levelGetWorld(*(u16 *)((u8 *)mainGetGame() + D_overlay_9_00904914 * 0x76 + 0x1D0) >> 5);
        entry = D_overlay_9_0090469C;
        i = 0;
        found = 0;
        if (*entry != 0xFF) {
            do {
                if (world == entry[2]) {
                    found = 1;
                    func_overlay_9_00902880_1F03658(i);
                } else {
                    i++;
                    entry += 0xC;
                }
            } while ((*entry != 0xFF) && (found == 0));
        }
    }

    scroll = D_800FF9E0;
    scrollStart = scroll;
    mode = 0;
    if (D_overlay_9_00904910 == -1) {
        if (scroll < D_overlay_9_009097CC) {
            mode = 1;
            scroll += 0x10000;
        }
    } else if (D_overlay_9_00904910 == 1) {
        if (D_overlay_9_009097CC < scroll) {
            mode = 2;
            scroll += 0xFFFF0000;
        }
    }

    if (arg0 > 0) {
        steps = arg0 & 3;
        i = 0;
        if (steps != 0) {
            do {
                i++;
                scroll += (D_overlay_9_009097CC - scroll) >> 4;
            } while (i != steps);
        }
        while (i != arg0) {
            scroll += (D_overlay_9_009097CC - scroll) >> 4;
            scroll += (D_overlay_9_009097CC - scroll) >> 4;
            scroll += (D_overlay_9_009097CC - scroll) >> 4;
            scroll += (D_overlay_9_009097CC - scroll) >> 4;
            i += 4;
        }
    }

    D_800FF9E0 = scroll;
    if (mode == 1) {
        scroll += 0xFFFF0000;
    } else if (mode == 2) {
        scroll += 0x10000;
    }
    if (scroll < 0) {
        scroll += 0x8000;
    }
    if (scrollStart < 0) {
        scrollStart += 0x8000;
    }

    if (((D_overlay_9_00904910 == 1) && (scrollStart < 0x4001) && (scroll >= 0x4001)) ||
        ((D_overlay_9_00904910 == -1) && (scrollStart >= 0x4001) && (scroll < 0x4001))) {
        func_overlay_9_009037E4_1F045BC(D_800FF518, (s16)(D_overlay_9_00904914 << 8), 3);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_0090343C_1F04214.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_9_009037E4_1F045BC(void *arg0, s16 arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *ent;
    u8 *model;
    u8 *e;
    u8 *tex;
    s16 *out;
    s32 s;
    s32 count;
    s32 i;
    u32 flags;
    s16 v2;

    ent = ((u8 **)*(u8 **)(obj + 0x6C))[(s8)obj[0x3A]];
    e = *(u8 **)(ent + 0x74);
    model = *(u8 **)ent;
    s = arg1;
    if (e != NULL) {
        out = *(s16 **)(ent + 0x78 + ((s8)ent[0xB] * 4));
        count = model[0x2C];
        for (i = 0; i < count; i++) {
            flags = *(u32 *)(e + 4);
            tex = *(u8 **)(*(u8 **)(model + 0x18) + ((flags & 0xFF) << 3));
            if ((flags & 0x10000) && (arg2 << 8) == *(u16 *)(tex + 0x12)) {
                *(s16 *)e = (s16)s;
                if (*(s16 *)(e + 2) >= 0) {
                    s += 0x100;
                    if (s >= *(u16 *)(tex + 0x12)) {
                        s -= 0x100;
                    }
                    *(s16 *)(e + 2) = (s16)s;
                }
            }
            v2 = *(s16 *)(e + 2);
            if (v2 >= 0) {
                *out++ = (s16)((v2 >> 8) * *(s16 *)(tex + 0x16));
            }
            *out++ = (s16)((*(s16 *)e >> 8) * *(s16 *)(tex + 0x16));
            e += 8;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_009037E4_1F045BC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_9_00903908_1F046E0(s32 arg0) {
    u8 *ent;
    u8 *ptr;
    s16 idx;

    ent = currentobjects + (arg0 << 5);
    idx = *(s16 *)(ent + 6);
    ptr = (u8 *)frontendptrs[idx];
    if (idx == 0x7F) {
        lightObject(ptr, *(s32 *)(*(u8 **)(ptr + 0x6C)), *(s32 *)(ptr + 0x54), 0);
    }
    *(f32 *)(ptr + 0xC) = *(f32 *)(ent + 0xC) - D_overlay_9_00909790;
    *(f32 *)(ptr + 0x10) = 120.0f - (*(f32 *)(ent + 0x10) - D_overlay_9_00909794);
    *(s16 *)(ptr + 0x0) = *(s16 *)(ent + 0x0);
    *(s16 *)(ptr + 0x2) = *(s16 *)(ent + 0x2);
    *(s16 *)(ptr + 0x4) = *(s16 *)(ent + 0x4);
    *(s8 *)(ptr + 0x3A) = *(s8 *)(ent + 0x1C);
    *(f32 *)(ptr + 0x8) = *(f32 *)(ent + 0x8);
    objPrintObject(&frontgfx, &frontmtx, &frontvtx, ptr);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_00903908_1F046E0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_9_009039F0_1F047C8(void) {
    s16 *v;
    s32 n;
    f32 sc;
    f32 fx;
    f32 fy;
    f32 gx;
    f32 gy;
    s32 x1;
    s32 y1;
    s32 x2;
    s32 y2;
    Gfx *g;

    texDPInit(&frontgfx);
    g = frontgfx++;
    g->words.w0 = 0xBA001402;
    g->words.w1 = 0;
    g = frontgfx++;
    g->words.w0 = 0xFCFFFFFF;
    g->words.w1 = 0xFFFDF6FB;
    g = frontgfx++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = 0xFF0080;

    v = D_overlay_9_0090444C;
    fx = (f32)(s32)D_overlay_9_00909798;
    fy = (f32)(s32)D_overlay_9_00909790;
    gy = (f32)(s32)D_overlay_9_0090979C;
    gx = (f32)(s32)D_overlay_9_00909794;
    n = 0;
    do {
        sc = D_overlay_9_009097AC;
        x1 = (s32)(((v[0] * sc + fx) - fy) + 160.0f);
        y1 = (s32)((v[1] * sc + gy) - gx);
        x2 = (s32)(((v[2] * sc + fx) - fy) + 160.0f);
        y2 = (s32)((v[3] * sc + gy) - gx);
        v += 4;
        n++;
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= 0x141) {
            x2 = 0x140;
        }
        if (y2 >= 0xF1) {
            y2 = 0xF0;
        }
        if (x2 >= 0 && y2 >= 0 && x1 < 0x141 && y1 < 0xF1) {
            g = frontgfx++;
            g->words.w0 = (((x2 + 1) & 0x3FF) << 0xE) | 0xF6000000 | (((y2 + 1) & 0x3FF) * 4);
            g->words.w1 = ((x1 & 0x3FF) << 0xE) | ((y1 & 0x3FF) * 4);
        }
    } while (n != 8);
    texDPInit(&frontgfx);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_009039F0_1F047C8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_9_00903D0C_1F04AE4(void *arg0) {
    u8 *rec = (u8 *)arg0;
    u8 *entry;
    u8 *ptr0;
    u8 *ptr1;
    u8 *p3;             /* 10-byte records at entry + 0x17A */
    u8 *p1;             /* 10-byte records at entry + 0x3DA */
    u8 *pA;             /* 16-byte records at entry + 0x000 */
    u8 *pB;             /* 16-byte records at entry + 0x260 */
    u8 *fp;             /* byte table cursor (D_29) */
    u8 *sp9C;           /* byte table cursor (D_41) */
    s16 sel;
    s32 idx;
    s32 n0;
    s32 n1 = 0;         /* asm: stack slot 0xDC only written when ptr1 != NULL */
    s32 r0;
    s32 r1;
    s32 cxA;
    s32 cyB;
    s32 iA;
    s32 iB;
    s32 s4;
    s32 s5;
    s32 s6;
    s32 s7;
    f32 rad;
    f32 f24;
    f32 f26;
    f32 f28;
    f32 kA;
    f32 kB;
    f32 kC;
    f32 kD;
    f32 sinv;
    f32 cosv;

    idx = D_overlay_9_009097B4;
    D_overlay_9_009097B4 = idx + 1;
    entry = D_overlay_9_00904990 + idx * 0x4E0;

    *(s16 *)(entry + 0x4CC) = *(s16 *)(rec + 0x6);
    *(s16 *)(entry + 0x4D0) = 0;
    *(s16 *)(entry + 0x4D2) = 0;
    *(s16 *)(entry + 0x4CE) = *(s16 *)(rec + 0x8);
    ptr0 = frontendptrs[*(s16 *)(rec + 0x0)];
    *(void **)(entry + 0x4C0) = ptr0;
    sel = *(s16 *)(rec + 0x2);
    if (sel != -1) {
        *(void **)(entry + 0x4C4) = frontendptrs[sel];
    } else {
        *(void **)(entry + 0x4C4) = NULL;
    }
    *(void **)(entry + 0x4C8) = arg0;
    *(s16 *)(entry + 0x4D6) = *(s16 *)(rec + 0x22);
    *(s16 *)(entry + 0x4D8) = *(s16 *)(rec + 0x24);

    ptr1 = *(u8 **)(entry + 0x4C4);
    n0 = ((s32) *ptr0 >> 1) - 1;
    if (ptr1 != NULL) {
        n1 = ((s32) *ptr1 >> 1) - 1;
    }

    /* asm: 0x3D0..0x3D4 zeroed, then copied to 0x170..0x174 */
    *(s16 *)(entry + 0x3D0) = 0;
    *(s16 *)(entry + 0x3D2) = 0;
    *(s16 *)(entry + 0x3D4) = 0;
    *(s16 *)(entry + 0x170) = 0;
    *(s16 *)(entry + 0x172) = 0;
    *(s16 *)(entry + 0x174) = 0;
    entry[0x176] = D_overlay_9_009043C8;
    entry[0x177] = D_overlay_9_009043C8;
    entry[0x178] = D_overlay_9_009043C8;
    entry[0x179] = 0xFF;
    entry[0x3D6] = D_overlay_9_009043E0;
    entry[0x3D7] = D_overlay_9_009043E0;
    entry[0x3D8] = D_overlay_9_009043E0;
    entry[0x3D9] = 0xFF;

    rad = (f32) rec[4] + 3.0f;
    r0 = mathRnd(0, 0x20) << 5;
    r1 = mathRnd(0, 0x20) << 5;
    cxA = (n1 + 1) << 5;
    cyB = (n0 + 1) << 5;
    f26 = (f32) (n0 << 5);
    f24 = (f32) cyB;
    f28 = (f32) cxA;
    kA = (f32) (n1 * 8);
    kB = (f32) r0;
    kC = (f32) r1;
    kD = (f32) (n1 << 5);
    iA = cxA + r1;
    iB = cxA + r0;

    p3 = entry + 0x17A;
    p1 = entry + 0x3DA;
    pA = entry;
    pB = entry + 0x260;
    fp = D_overlay_9_009043C9;
    sp9C = D_overlay_9_009043E1;
    s5 = 1;
    s6 = 0;
    do {
        s7 = s5 + 1;
        s4 = s6 + 0xB21;
        /* asm: Sinf/Cosf take the angle in a0 only; Sinf calls below
         * with a0 = s4 are the same callee (a1 is incidental). */
        sinv = Sinf(s6);
        cosv = Cosf(s6);

        *(s16 *)(p3 + 0) = (s16) (s32) ((f32) rec[4] * sinv);
        *(s16 *)(p3 + 2) = (s16) (s32) ((f32) rec[4] * cosv);
        *(s16 *)(p3 + 4) = 0;
        p3[6] = *fp;
        p3[7] = *fp;
        p3[8] = *fp;
        p3[9] = 0xFF;

        *(s16 *)(p1 + 0) = (s16) (s32) (rad * sinv);
        *(s16 *)(p1 + 2) = (s16) (s32) (rad * cosv);
        *(s16 *)(p1 + 4) = 0;
        p1[6] = *sp9C;
        p1[7] = *sp9C;
        p1[8] = *sp9C;
        p1[9] = 0xFF;

        pA[0] = 0x40;
        pA[1] = 0;
        pA[2] = s5;
        pA[3] = s7;
        *(s16 *)(pA + 4) = cyB;
        *(s16 *)(pA + 6) = cyB;
        *(s16 *)(pA + 8) = (s16) (s32) (f24 + f26 * sinv);
        *(s16 *)(pA + 0xA) = (s16) (s32) (f24 + f26 * cosv);
        *(s16 *)(pA + 0xC) = (s16) (s32) (Sinf(s4) * f26 + f24);
        *(s16 *)(pA + 0xE) = (s16) (s32) (Cosf(s4) * f26 + f24);

        pB[0] = 0x40;
        pB[1] = 0;
        pB[2] = s5;
        pB[3] = s7;
        *(s16 *)(pB + 4) = iB;
        *(s16 *)(pB + 6) = iA;
        *(s16 *)(pB + 8) = (s16) (s32) (f28 + kA * sinv + kB);
        *(s16 *)(pB + 0xA) = (s16) (s32) (f28 + kD * cosv + kC);
        *(s16 *)(pB + 0xC) = (s16) (s32) (Sinf(s4) * kA + f28 + kB);
        *(s16 *)(pB + 0xE) = (s16) (s32) (Cosf(s4) * kD + f28 + kC);

        p3 += 0xA;
        p1 += 0xA;
        pA += 0x10;
        pB += 0x10;
        fp += 1;
        sp9C += 1;
        s5 = s7;
        s6 = s4;
    } while (s7 != 0x18);

    pB[-0xD] = 1;
    pA[-0xD] = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o9/overlay_9/func_overlay_9_00903D0C_1F04AE4.s")
#endif
