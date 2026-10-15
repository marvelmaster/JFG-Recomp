#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern void *frontendptrs[];
extern Gfx *frontgfx;
extern void *frontvtx;
extern u8 D_800FF8E0[];
extern u8 D_800FFDA0[];
extern s16 D_800FFDA6;
extern u8 D_overlay_41_02901570[];
extern u8 D_overlay_41_02901610[];
extern f32 D_overlay_41_02901694;
extern f32 D_overlay_41_02901698;
extern s16 D_overlay_41_029016DC;
extern u8 D_829015F0[];
extern u8 currentobjects[];
extern u8 frontmtx[];
extern s16 D_overlay_41_02901650;
extern f32 D_overlay_41_0290169C;
extern f32 D_overlay_41_029016A0;
extern f32 D_overlay_41_029016A4;
extern f32 D_overlay_41_029016A8;
extern f32 D_overlay_41_029016AC;
extern f32 D_overlay_41_029016B0;
extern f32 D_overlay_41_029016B4;
extern f32 D_overlay_41_029016B8;
extern f32 D_overlay_41_029016BC;
extern f32 D_overlay_41_029016C0;
extern f32 D_overlay_41_029016C4;
extern f32 D_overlay_41_029016C8;
extern u16 D_overlay_41_029016D0[];
extern s16 D_overlay_41_029016D8;
extern s16 D_overlay_41_029016DA;
extern s16 D_overlay_41_029016DE;
extern void *D_overlay_41_029016E0;
extern void *D_overlay_41_029016E4;
extern u16 D_overlay_41_02901614[];
extern u8 D_overlay_41_0290161C[];
extern u8 *D_overlay_41_0290163C[];
extern s32 D_overlay_41_02901644[];
extern s32 D_overlay_41_0290164C;
extern s16 D_overlay_41_02901654;
extern s32 D_overlay_41_02901658;
extern void *D_overlay_41_0290165C;
extern f32 D_overlay_41_02901660;
extern void *D_overlay_41_02901664;
void *menuCamGetObjPtr(void);
void objScrollTexture(void *obj, s32 a1, s32 a2);
void objAnimDframe(void *obj, f32 a1, f32 a2, s32 a3);
s32 fxFadeOn(void *obj, s32 a1, s32 a2, s32 a3);
void fxInttostr(u8 *str, s32 value, s32 a2, u16 *ptr);
void fxTinyPrint(s32 x, s32 y, u8 *str, u16 *ptr);
void frontTeleporterTick(f32 a0, f32 a1, s32 a2, s32 a3, s32 a4);
void camStandardPersp(Gfx **dl, void *mtx);
void rcpClearZBuffer(f32 a0, f32 a1, Gfx **dl, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
void amSndPlay(s32 id, void *handle);
void amSndSetVol(s32 id, void *handle, s32 vol);
void amSndStop(void *a, void *b, ...);
void frontDrawObj(s32 arg0);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
void modGenAnimMatrices(void *model, s32 count, void *obj, f32 scale, f32 arg4);
void lightObject(void *arg0, void *arg1, void *arg2, void *arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Character badge HUD: obj = frontendptrs[table+6] (table = D_800FF8E0 or D_800FFDA0),
// part = obj->part table[obj+0x3A]. Refreshes the part's matrices/lighting when part+0xA is set,
// then if obj+0x28 < D_overlay_41_02901698 emits a 9-vertex set (10-byte vertices, x/y/z s16 then
// RGBA bytes) built from the part bounding box at part+0x68, the 4 sprite textures and a closing
// closing block. Vertex stride 0xA matches the vertex writers in overlay_14.c (frontDrawObj HUD code).
void frontDrawCharBadge(s32 arg0, s32 arg1) {
    u8 *vtxStart;   /* sp6C: frontvtx at entry */
    u8 *vtx;
    u8 *obj;        /* s2 */
    u8 *part;       /* s1 */
    f32 *bx;        /* part+0x68 bounding box floats */
    s32 partId;     /* s3: part+0x00 */
    s32 showBadge;  /* sp4C */
    s32 midX;
    s32 midY;
    s32 midZ;
    u8 *tbl;
    void **sprTex;
    void *sprTexAlt;
    u32 sprite;
    u32 vtxSeg;
    f32 scale;
    s32 i;
    Gfx *gfx;

    vtxStart = (u8 *) frontvtx;
    if (arg0 == 0) {
        tbl = D_800FF8E0;
    } else {
        tbl = D_800FFDA0;
    }
    obj = (u8 *) frontendptrs[*(s16 *) (tbl + 6)];
    part = *(u8 **) (*(u8 **) (obj + 0x6C) + *(s8 *) (obj + 0x3A) * 4);
    partId = *(s32 *) part;
    if (viGetVideoMode() & 1) {
        scale = D_overlay_41_02901694;
    } else {
        scale = 1.0f;
    }
    if (*(s8 *) (part + 0xA) != 0) {
        modGenAnimMatrices(part, partId, obj, scale, 0.0f);
        lightObject(obj, part, *(void **) (obj + 0x54),
                    *(void **) (part + (*(s8 *) (part + 0xB) << 2) + 0x10));
        *(s8 *) (part + 0xA) = 0;
    }

    showBadge = 0;
    if (*(f32 *) (obj + 0x28) < D_overlay_41_02901698) {
        showBadge = 1;
    }
    if (showBadge != 0) {
        bx = *(f32 **) (part + 0x68);
        /* box mid points (truncated to int): x uses +0/+0xC, y uses +4/+0x1C, z uses +8/+0x14 */
        midX = (s32) (((bx[3] - bx[0]) / 2.0f) + bx[0]);
        midY = (s32) (((bx[7] - bx[1]) / 2.0f) + bx[1]);
        midZ = (s32) (((bx[5] - bx[2]) / 2.0f) + bx[2]);

        /* 9 vertices, 10 bytes each: x,y,z (s16) at +0/+2/+4; colour bytes filled below */
        vtx = vtxStart;
        *(s16 *) (vtx + 0) = (s16) (s32) bx[0];
        *(s16 *) (vtx + 2) = (s16) (s32) bx[1];
        *(s16 *) (vtx + 4) = (s16) (s32) bx[2];
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) midX;
        *(s16 *) (vtx + 2) = (s16) (s32) bx[1];
        *(s16 *) (vtx + 4) = (s16) midZ;
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) (s32) bx[3];
        *(s16 *) (vtx + 2) = (s16) (s32) bx[4];
        *(s16 *) (vtx + 4) = (s16) (s32) bx[5];
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) (s32) bx[0];
        *(s16 *) (vtx + 2) = (s16) midY;
        *(s16 *) (vtx + 4) = (s16) (s32) bx[2];
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) midX;
        *(s16 *) (vtx + 2) = (s16) midY;
        *(s16 *) (vtx + 4) = (s16) midZ;
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) (s32) bx[3];
        *(s16 *) (vtx + 2) = (s16) midY;
        *(s16 *) (vtx + 4) = (s16) (s32) bx[5];
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) (s32) bx[0];
        *(s16 *) (vtx + 2) = (s16) (s32) bx[7];
        *(s16 *) (vtx + 4) = (s16) (s32) bx[2];
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) midX;
        *(s16 *) (vtx + 2) = (s16) (s32) bx[7];
        *(s16 *) (vtx + 4) = (s16) midZ;
        vtx += 0xA;
        *(s16 *) (vtx + 0) = (s16) (s32) bx[9];
        *(s16 *) (vtx + 2) = (s16) (s32) bx[10];
        *(s16 *) (vtx + 4) = (s16) (s32) bx[11];
        vtx += 0xA;
        frontvtx = vtx;

        /* colour bytes (RGBA = 0xFF) for the vertices just written */
        if (vtxStart != vtx) {
            u8 *cv = vtxStart;
            do {
                cv[6] = 0xFF;
                cv[7] = 0xFF;
                cv[8] = 0xFF;
                cv[9] = 0xFF;
                cv += 0xA;
            } while (cv != vtx);
        }

        /* G_VTX-style command loading the vertices (segment 0x80000000 + address) */
        vtxSeg = (u32) vtxStart + 0x80000000;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = ((((vtxSeg & 6) | 0x48) & 0xFF) << 16) | 0x04000000 | 0x62;
        gfx->words.w1 = vtxSeg;

        if (arg0 == 0) {
            sprTex = (void **) ((u8 *) frontendptrs + D_overlay_41_02901610[*(s8 *) (obj + 0x3A)] * 4);
            sprite = (u32) D_overlay_41_02901570;
            for (i = 0; i < 4; i++) {
                texDPTextureX(&frontgfx, *sprTex, 0, arg1 << 8);
                sprTex++;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w1 = sprite + 0x80000000;
                gfx->words.w0 = 0x05110020;
                sprite += 0x20;
            }
        } else {
            /* asm: lw -0xC(frontendptrs + D*4), i.e. element D - 3 */
            sprTexAlt = frontendptrs[D_800FFDA6 - 3];
            sprite = (u32) D_overlay_41_02901570;
            for (i = 0; i < 4; i++) {
                texDPTextureX(&frontgfx, sprTexAlt, 0, i << 16);
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w1 = sprite + 0x80000000;
                gfx->words.w0 = 0x05110020;
                sprite += 0x20;
            }
        }
        texDPInit(&frontgfx);
    }

    if (arg0 == 0) {
        frontDrawObj(0xB);
    } else {
        frontDrawObj(0x31);
    }

    if (showBadge != 0) {
        vtxSeg = (u32) vtxStart + 0x80000000;
        texDPTextureX(&frontgfx, NULL, 0, 0);
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xBA001402;
        gfx->words.w1 = 0;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xFC767EEC;
        gfx->words.w1 = 0xFFFDF6FB;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xEF082C0F;
        gfx->words.w1 = 0x00504240;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = ((s16) D_overlay_41_029016DC >> 2) & 0xFF;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0xFA000000;
        gfx->words.w1 = (D_overlay_41_029016DC & 0xFF) | 0x1A0000;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = ((((vtxSeg & 6) | 0x48) & 0xFF) << 16) | 0x04000000 | 0x62;
        gfx->words.w1 = vtxSeg;
        gfx = frontgfx;
        frontgfx = gfx + 1;
        gfx->words.w0 = 0x05110020;
        gfx->words.w1 = (u32) &D_829015F0;
        texDPInit(&frontgfx);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o41/overlay_41/frontDrawCharBadge.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Front-end character badge. cur = currentobjects[0xB] (arg0 == 0) or [0x31] (else), 0x20 bytes each.
// obj = frontendptrs[cur->unk6]; part = obj->part[obj->unk3A] (part+0xA = redraw flag).
// State machine in D_overlay_41_02901650 (0 idle, 1 scroll, 2/3 slide, 4 hidden).
// Text entries: D_overlay_41_0290161C blocks of four {s16 x, s16 y}, width reduced per char.
// Gfx/vertex and rcp usage follows frontDrawCharBadge above.
void frontCharBadge(s32 arg0, s32 arg1, s32 arg2) {
    u8 *cur;
    u8 *obj;
    u8 *part;
    u8 *cam;
    u8 *ent;
    u8 *txt;
    u8 *fxp;
    u8 *s;
    u8 *p;
    u8 numStr[8];           /* sp50 */
    u16 *num;               /* a3 pointer walking D_overlay_41_029016D0 */
    f32 f12;
    f32 f14;
    f32 dist;
    f32 cy;
    s32 state;
    s32 flags;
    s32 fade;               /* var_a2 (fade flag) */
    s32 mode;               /* var_a3 (text scroll flag) */
    s32 lim;                /* var_a1 */
    s32 wrap;               /* sp98 */
    s32 i;
    s32 j;
    s32 rem;
    s32 v;
    s32 x;
    s32 len;
    s32 step;
    u8 first;
    u8 t5;

    cur = (u8 *) currentobjects + ((arg0 == 0) ? 0xB : 0x31) * 0x20;
    obj = (u8 *) frontendptrs[*(s16 *) (cur + 0x6)];
    if (D_overlay_41_02901650 == 4 && *(f32 *) (obj + 0x28) < D_overlay_41_0290169C) {
        D_overlay_41_029016D0[0] = 0;
        D_overlay_41_029016D0[1] = 0;
        D_overlay_41_029016D0[2] = 0;
        D_overlay_41_029016D0[3] = 0;
        D_overlay_41_029016D8 = 0;
        D_overlay_41_02901650 = 1;
        D_overlay_41_029016DA = 3;
    } else if (D_overlay_41_029016A0 < *(f32 *) (obj + 0x28)) {
        D_overlay_41_02901650 = 4;
    }
    state = D_overlay_41_02901650;
    if (state != 4) {
        objScrollTexture(obj, arg2, arg2);
    }
    part = *(u8 **) (*(u8 **) (obj + 0x6C) + *(s8 *) (obj + 0x3A) * 4);
    *(s8 *) (part + 0xA) = (s8) arg2;

    if (arg0 == 0) {
        cam = (u8 *) D_overlay_41_029016E0;
        if (cam == NULL) {
            D_overlay_41_029016E0 = menuCamGetObjPtr();
            cam = (u8 *) D_overlay_41_029016E0;
        }
        if (cam == NULL) {
            return;
        }
        D_overlay_41_029016E4 = *(void **) (cam + 0x68);
        ent = (u8 *) D_overlay_41_029016E4;
        if (ent == NULL) {
            return;
        }
        flags = *(s32 *) ent;
        if (*(f32 *) (ent + 0x28) <= 0.5f || (flags & 4) != 0) {
            f12 = 240.0f;
        } else {
            f12 = 100.0f;
        }
        dist = *(f32 *) (cur + 0xC) - f12;
        if (dist < 0.0f) {
            dist = -dist;
        }
        if ((flags & 2) != 0 && dist < 1.0f && f12 == 100.0f) {
            wrap = 0x8000;
            if (arg2 > 0) {
                i = 0;
                rem = arg2 & 3;
                if (rem != 0) {
                    do {
                        v = *(s16 *) (cur + 0);
                        i += 1;
                        if (v < 0) {
                            *(s16 *) (cur + 0) = v + 0x8000;
                        }
                        v = 0x8000 - *(s16 *) (cur + 0);
                        step = v >> 4;
                        if (v >= 0x1601) {
                            step = 0x1600 >> 4;
                        }
                        *(s16 *) (cur + 0) += step;
                    } while (rem != i);
                    if (i != arg2) {
                        goto block_33;
                    }
                } else {
block_33:
                    do {
                        v = *(s16 *) (cur + 0);
                        if (v < 0) {
                            *(s16 *) (cur + 0) = v + 0x8000;
                        }
                        v = 0x8000 - *(s16 *) (cur + 0);
                        step = v >> 4;
                        if (v >= 0x1601) {
                            step = 0x1600 >> 4;
                        }
                        *(s16 *) (cur + 0) += step;

                        v = *(s16 *) (cur + 0);
                        if (v < 0) {
                            *(s16 *) (cur + 0) = v + 0x8000;
                        }
                        v = 0x8000 - *(s16 *) (cur + 0);
                        step = v >> 4;
                        if (v >= 0x1601) {
                            step = 0x1600 >> 4;
                        }
                        *(s16 *) (cur + 0) += step;

                        v = *(s16 *) (cur + 0);
                        if (v < 0) {
                            *(s16 *) (cur + 0) = v + 0x8000;
                        }
                        v = 0x8000 - *(s16 *) (cur + 0);
                        step = v >> 4;
                        if (v >= 0x1601) {
                            step = 0x1600 >> 4;
                        }
                        *(s16 *) (cur + 0) += step;

                        v = *(s16 *) (cur + 0);
                        if (v < 0) {
                            *(s16 *) (cur + 0) = v + 0x8000;
                        }
                        v = 0x8000 - *(s16 *) (cur + 0);
                        step = v >> 4;
                        if (v >= 0x1601) {
                            step = 0x1600 >> 4;
                        }
                        *(s16 *) (cur + 0) += step;
                        i += 4;
                    } while (i != arg2);
                }
                wrap = 0x8000;
            }
            if ((wrap - *(s16 *) (cur + 0)) < 0x800) {
                f14 = D_overlay_41_029016A4;
            } else {
                f14 = D_overlay_41_029016A8;
            }
        } else {
            f14 = D_overlay_41_029016AC;
            *(s16 *) (cur + 0) += arg2 * 0x160;
        }

        /* height/colour ease toward f12 (1 step, then 4-step unroll) */
        if (arg2 > 0) {
            i = 0;
            rem = arg2 & 3;
            if (rem != 0) {
                do {
                    dist = *(f32 *) (cur + 0xC);
                    i += 1;
                    *(f32 *) (cur + 0xC) = dist + (f12 - dist) * D_overlay_41_029016B0;
                } while (rem != i);
                if (i != arg2) {
                    goto block_c4;
                }
            } else {
block_c4:
                do {
                    dist = *(f32 *) (cur + 0xC);
                    *(f32 *) (cur + 0xC) = dist + (f12 - dist) * D_overlay_41_029016B4;
                    dist = *(f32 *) (cur + 0xC);
                    *(f32 *) (cur + 0xC) = dist + (f12 - dist) * D_overlay_41_029016B4;
                    dist = *(f32 *) (cur + 0xC);
                    *(f32 *) (cur + 0xC) = dist + (f12 - dist) * D_overlay_41_029016B4;
                    dist = *(f32 *) (cur + 0xC);
                    *(f32 *) (cur + 0xC) = dist + (f12 - dist) * D_overlay_41_029016B4;
                    i += 4;
                } while (i != arg2);
            }
        }
        if (*(f32 *) (cur + 0xC) > 230.0f) {
            *(s8 *) (obj + 0x3A) = *(s8 *) (ent + 0x51);
            if ((*(s32 *) ent & 4) != 0) {
                /* a1 is the Duff-prologue remainder on the asm path; not every path sets it */
                frontTeleporterTick(f12, f14, arg2, arg2 & 3, arg2);
            }
        }
    } else {
        *(s16 *) (cur + 0) = 0;
        if (arg1 != 0) {
            f14 = D_overlay_41_029016B8;
        } else {
            *(f32 *) (obj + 0x28) = 1.0f;
            f14 = D_overlay_41_029016BC;
        }
    }

    objAnimDframe(obj, f14, (f32) arg2, arg2);
    if (f14 != D_overlay_41_02901660) {
        if (D_overlay_41_02901664 != NULL) {
            amSndStop(D_overlay_41_02901664, &D_overlay_41_02901664);
        }
        if (f14 == D_overlay_41_029016C0) {
            amSndPlay(0xCE, &D_overlay_41_02901664);
        } else {
            amSndPlay(0xCD, &D_overlay_41_02901664);
        }
    }
    if (D_overlay_41_029016C4 < *(f32 *) (obj + 0x28)) {
        if (*(f32 *) (cur + 0xC) < 110.0f || arg0 != 0) {
            D_overlay_41_029016DC = 0xFF;
            D_overlay_41_02901658 = 0;
            D_overlay_41_029016DE = 3;
        }
    }
    D_overlay_41_02901660 = f14;
    if (arg0 == 0) {
        dist = *(f32 *) (cur + 0xC);
        cy = 120.0f - *(f32 *) (cur + 0x10);
        rcpClearZBuffer(160.0f, f14, &frontgfx, 320, 240,
                        (s32) ((dist - 56.0f) + 160.0f),
                        (s32) (cy - 142.0f),
                        (s32) (dist + 45.0f + 160.0f),
                        (s32) (cy + 47.0f));
    }
    camStandardPersp(&frontgfx, frontmtx);
    frontDrawCharBadge(arg0, D_overlay_41_02901658);

    if (*(f32 *) (obj + 0x28) < D_overlay_41_029016C8) {
        if (D_overlay_41_02901650 != 4) {
            fade = 1;
            D_overlay_41_029016D8 += arg2;
            mode = 0;
            lim = 0;
            switch (D_overlay_41_02901650) {
            case 0:
                fade = 0;
                break;
            case 1:
                if (D_overlay_41_029016D8 >= 0x79) {
                    D_overlay_41_029016D8 = 0;
                    D_overlay_41_02901650 = D_overlay_41_029016DA;
                    D_overlay_41_029016D0[0] = 0;
                    D_overlay_41_029016D0[1] = 0;
                    D_overlay_41_029016D0[2] = 0;
                    D_overlay_41_029016D0[3] = 0;
                } else {
                    mode = 1;
                }
                break;
            case 2:
                lim = -0x40;
                if (D_overlay_41_029016D8 >= 0x3D) {
                    D_overlay_41_029016D8 = 0;
                    D_overlay_41_02901650 = 1;
                    D_overlay_41_029016DA = 3;
                }
                break;
            case 3:
                lim = 0x40;
                if (D_overlay_41_029016D8 >= 0x3D) {
                    D_overlay_41_029016D8 = 0;
                    D_overlay_41_02901650 = 1;
                    D_overlay_41_029016DA = 2;
                }
                break;
            }

            fxp = (u8 *) &D_overlay_41_029016D8;
            if (arg0 == 0) {
                fxp = (u8 *) frontendptrs[D_overlay_41_02901610[*(s8 *) (obj + 0x3A)]];
                v = D_overlay_41_02901658 + lim * arg2;
                D_overlay_41_02901658 = v;
                if (v < 0) {
                    D_overlay_41_02901658 = 0;
                    v = 0;
                }
                if (v >= *(u16 *) (fxp + 0x12)) {
                    D_overlay_41_02901658 = *(u16 *) (fxp + 0x12) - 1;
                }
            }
            if (fxFadeOn(fxp, lim, fade, mode) != 0 || arg0 != 0) {
                fade = 0;
            }

            if (fade != 0) {
                txt = (u8 *) D_overlay_41_0290161C + arg0 * 0x10;
                num = D_overlay_41_029016D0;
                for (i = 0; i < 4; i++) {
                    fxInttostr(numStr, *num * 100, 0, num);
                    x = *(s16 *) txt;
                    if (num >= &D_overlay_41_029016D0[2]) {
                        if (numStr[1] != 0) {
                            p = &numStr[1];
                            do {
                                t5 = p[1];
                                p++;
                                x -= 4;
                            } while (t5 != 0);
                        }
                    }
                    fxTinyPrint((s16) x, *(s16 *) (txt + 2), numStr, num);
                    if (mode != 0) {
                        *num += D_overlay_41_02901614[i] * arg2;
                    }
                    if (*num >= 0x7531) {
                        *num = 0;
                    }
                    num++;
                    txt += 4;
                }
                if (arg0 == 0) {
                    fxTinyPrint(0xF0, 0x89, D_overlay_41_0290163C[0], num);
                } else {
                    fxTinyPrint(0xD3, 0x86, D_overlay_41_0290163C[1], num);
                }
                if (mode != 0) {
                    D_overlay_41_0290164C -= arg2;
                    if (D_overlay_41_0290164C < 0) {
                        do {
                            s = D_overlay_41_0290163C[arg0];
                            first = s[0];
                            len = D_overlay_41_02901644[arg0];
                            for (j = 0; j < len; j++) {
                                s[j] = s[j + 1];
                            }
                            s[len] = first;
                            D_overlay_41_0290164C += 6;
                        } while (D_overlay_41_0290164C < 0);
                    }
                }
            }
        }

        if (D_overlay_41_029016DC > 0) {
            v = (s16) D_overlay_41_029016DC >> 1;
            if (D_overlay_41_0290165C == NULL) {
                amSndPlay(0xCF, &D_overlay_41_0290165C);
            }
            if (v >= 0x80) {
                v = 0x7F;
            }
            amSndSetVol(0xCF, D_overlay_41_0290165C, v & 0xFF);
        } else if (D_overlay_41_0290165C != NULL) {
            amSndStop(D_overlay_41_0290165C, D_overlay_41_0290165C, &D_overlay_41_0290165C);
        }

        if (D_overlay_41_02901654 < arg2) {
            v = mathRnd(0x80, 0xFF);
            if (D_overlay_41_029016DC < v) {
                D_overlay_41_029016DC = v;
                D_overlay_41_029016DE = mathRnd(1, 8);
            }
            D_overlay_41_02901654 = mathRnd(0xA0, 0xFF);
        } else {
            D_overlay_41_02901654 -= arg2;
        }
        v = D_overlay_41_029016DE * arg2;
        if (v < D_overlay_41_029016DC) {
            D_overlay_41_029016DC -= v;
        } else {
            D_overlay_41_029016DC = 0;
        }
    } else if (D_overlay_41_0290165C != NULL) {
        amSndStop(D_overlay_41_0290165C, D_overlay_41_0290165C, &D_overlay_41_0290165C);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o41/overlay_41/frontCharBadge.s")
#endif
