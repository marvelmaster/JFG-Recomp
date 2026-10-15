#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_13_00D01780;
extern f32 D_overlay_13_00D01784;
extern f32 D_overlay_13_00D01788;
extern f32 D_overlay_13_00D0178C;
extern Gfx *frontgfx;
extern MatrixS *frontmtx;
extern u8 weaponTable[];
extern u8 multiPlayerGame;
extern f32 D_overlay_13_00D017BC;
extern f32 D_overlay_13_00D017C0;
extern f32 D_overlay_13_00D017C4;
extern f32 D_overlay_13_00D017C8;
extern u8 D_overlay_13_00D0166C[];
extern u8 D_overlay_13_00D01358[];
extern u8 D_overlay_13_00D01362[];
extern u8 D_overlay_13_00D013C8[];
extern u8 D_overlay_13_00D013D2[];
extern u8 D_overlay_13_00D0155C[];
extern u8 D_overlay_13_00D01566[];
extern u8 D_overlay_13_00D01770[];
extern u8 D_overlay_13_00D01778[];
extern u8 D_80D011C0[];
extern u8 D_80D01238[];
s32 controlGetMaxCharge(void *chr, u8 chrType, void **entry);
void fxDrawLineInWindow(s16 x0, s16 y0, s16 x1, s16 y1, u8 colour, s32 player);
void fxTinyPrint(s16 x, s16 y, u8 *str);
void fxInttostr(s8 *buf, s32 value, s32 pad);
s32 camGetNo(void);
void camSetNo(s32 arg0);
void *camGetPtr(void);
void camSetView(void **arg0, void **arg1);
f32 camGetProjZ(f32 arg0, f32 arg1, f32 arg2);
s32 camProjectPoint(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, s32 arg5);
void texDPTextureX(Gfx **dl, s32 a, s32 b, s32 c);
void *mainGetGameCharacter(s8 arg0, s8 arg1);
void controlGetGunBarrelPos(void *obj, void *state, f32 *x, f32 *y, f32 *z);
void mathOneFloatPY(void *obj, f32 *out);
s32 trackNearestIntersection(s32 a, void *from, void *to, void *out, s32 mask, s32 c);
s32 hitPlayerAimCheck(s32 arg0, f32 arg1, f32 *arg2);
f32 Sinf(s32 angle);
void frontDrawTarget(void *arg0, s16 x, s16 y, s16 *rot, f32 z);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontInitTarget(void) {
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o13/overlay_13/frontInitTarget.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontPlayerTarget(s32 arg0, void *arg1, s32 arg2) {
    u8 *pl;
    u8 *chr;
    u8 *w;
    s16 camNo;
    s16 rot[3];
    s16 aimIn[2];
    s16 hitFlag;
    f32 gunPos[3];
    f32 target[3];
    f32 aim[2];
    f32 aimZ;
    f32 range;
    f32 dist;
    f32 ratio;
    f32 scale;
    f32 projX;
    f32 projY;
    u8 hitBuf[0x30];
    Object *hitObj;

    pl = (u8 *) arg1;
    camNo = camGetNo();
    camSetNo(*(s8 *) pl);
    camGetPtr();
    chr = mainGetGameCharacter(*(s8 *) pl, *(s8 *) (pl + 1));
    scale = D_overlay_13_00D01780;
    rot[0] = -0x8000 - *(s16 *) chr;
    rot[1] = -*(s16 *) (chr + 2);
    rot[2] = 0;

    controlGetGunBarrelPos((void *) arg0, arg1, &gunPos[0], &gunPos[1], &gunPos[2]);

    w = weaponTable + chr[0x70] * 0x30;
    range = (f32) (w[7] * 6) * *(f32 *) (w + 0x10);
    if (D_overlay_13_00D01784 < range) {
        range = D_overlay_13_00D01784;
    }
    aimZ = -range;
    aimIn[0] = *(s16 *) (pl + 0x1CA);
    aimIn[1] = *(s16 *) (pl + 0x1CC);
    mathOneFloatPY(aimIn, aim);

    target[0] = gunPos[0] + aim[0];
    target[1] = gunPos[1] + aim[1];
    target[2] = gunPos[2] + aimZ;

    hitFlag = 0;
    dist = range;
    if (trackNearestIntersection(0, gunPos, target, hitBuf, 0x2000, 0) != 0) {
        hitObj = *(Object **) hitBuf;
        if (hitObj != NULL && hitObj->behaviorId == 0x74) {
            hitFlag = 1;
        }
        /* asm: hit distance is read from the out buffer at +0x20 (sp+0xBC) */
        dist = *(f32 *) (hitBuf + 0x20);
    }

    pl[0x540] = (hitPlayerAimCheck(arg0, dist, &dist) & 1) | (pl[0x540] & 0xFFFE);
    if (hitFlag != 0) {
        pl[0x540] = pl[0x540] | 1;
    }

    ratio = dist / range;
    if (pl[0x540] & 1) {
        u8 t8;

        t8 = (pl[0x541] & 0xFF0F) | 0xA0;
        pl[0x541] = t8;
        scale += D_overlay_13_00D01788 * Sinf(((u32) (t8 & 0xFF) >> 4) << 11);
    } else if (chr[0x70] != 9 && chr[0x70] != 1) {
        u8 v;
        u32 top;

        v = pl[0x541];
        top = v >> 4;
        if (top == 0) {
            void *p = *(void **) (pl + 0x1BC);

            if (p != NULL) {
                *(u8 *) ((u8 *) p + *(s8 *) pl + 0x93) = 0;
                *(void **) (pl + 0x1BC) = NULL;
            }
        } else {
            pl[0x541] = (u8) (((top - 1) * 0x10) | (v & 0xFF0F));
        }
    }

    if (ratio > 0.0f) {
        camSetView((void **) &frontgfx, (void **) &frontmtx);
        texDPInit(&frontgfx);
        texDPTextureX(&frontgfx, 0, 5, 0);

        gunPos[0] = gunPos[0] + aim[0] * ratio;
        gunPos[1] = gunPos[1] + aim[1] * ratio;
        gunPos[2] = gunPos[2] + aimZ * ratio;

        dist = -camGetProjZ(gunPos[0], gunPos[1], gunPos[2]) / D_overlay_13_00D0178C;
        scale *= 1.0f + (3.0f * dist);

        frontgfx->words.w1 = 0;
        frontgfx->words.w0 = 0xE7000000;
        frontgfx++;
        frontgfx->words.w1 = -0x100;
        frontgfx->words.w0 = 0xFB000000;
        frontgfx++;

        if (camProjectPoint(gunPos[0], gunPos[1], gunPos[2], &projX, &projY, 1) != 0) {
            frontDrawTarget(arg1, (s16) (s32) projX, (s16) (s32) projY, rot, dist);
        }
    }

    if (camNo != *(s8 *) pl) {
        camSetNo(camNo);
        if (ratio > 0.0f) {
            camSetView((void **) &frontgfx, (void **) &frontmtx);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o13/overlay_13/frontPlayerTarget.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Reticle / target drawer. D_overlay_13_00D0166C is a 16-byte entry per character type
// (+0 line record list, +4 u16 count, +6 u16 mode, +8 / +0xC texture words).
// Line records are 10 bytes: s16 x0, y0, x1, y1, u16 flags, u8 colour.
// flags bit 9 = skip when flag==0, bit 0 = skip when flag!=0, bit 10 = colour+0x10 when flag!=0,
// flags >> 11 = mirror type (1..4 draw extra lines, 5/6 are the two-sided variants).
// flag = pl[0x540] & 1. Table bases are the overlay's own .data (offset 0x198.. -> D01358 etc).
void frontDrawTarget(void *arg0, s16 x, s16 y, s16 *rot, f32 z) {
    u8 *pl;
    u8 *chr;
    u8 *entry;
    u8 *rec;
    u8 *p;
    void *lines;
    u8 numBuf[12];
    f32 frac;
    s32 maxCharge;
    s32 chrType;
    s32 flag;
    s32 mode;
    s32 count;
    s32 i;
    s32 n;
    s32 colour;
    s32 colourMirror;
    s32 type;
    s32 flags;
    s32 player;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s16 textX;

    pl = (u8 *) arg0;
    chr = (u8 *) mainGetGameCharacter(*(s8 *) pl, *(s8 *) (pl + 1));
    chrType = chr[0x70];
    entry = D_overlay_13_00D0166C + chrType * 0x10;
    maxCharge = controlGetMaxCharge(chr, chrType, (void **) entry);
    player = pl[0];
    flag = pl[0x540] & 1;

    switch (chrType) {
    case 5:
        fxInttostr((s8 *) numBuf, (s32) (z * D_overlay_13_00D017BC), 1);
        textX = x + 0x14;
        fxTinyPrint(textX, (s16) (y - 0x10), numBuf);
        fxInttostr((s8 *) numBuf, (s32) ((f32) *(s16 *) (pl + 0x1D0) * D_overlay_13_00D017C0), 1);
        fxTinyPrint(textX, (s16) (y - 8), numBuf);
        break;
    case 1:
        textX = x + 0x1B;
        if (flag != 0) {
            fxTinyPrint(textX, (s16) (y - 0xF), D_overlay_13_00D01770);
            fxTinyPrint(textX, (s16) (y - 8), D_overlay_13_00D01778);
        } else {
            fxInttostr((s8 *) numBuf, (s32) (z * D_overlay_13_00D017C4), 1);
            fxTinyPrint(textX, (s16) (y - 0xF), numBuf);
            fxInttostr((s8 *) numBuf, (s32) ((f32) *(s16 *) (pl + 0x1D0) * D_overlay_13_00D017C8), 1);
            fxTinyPrint(textX, (s16) (y - 8), numBuf);
        }
        break;
    case 3:
        frac = (f32) (*(s16 *) (pl + 0x53E) - 0x20) / ((f32) maxCharge - 32.0f);
        n = (s32) (5.0f * frac);
        if (n > 0) {
            p = D_overlay_13_00D01358 + (n - 1) * 10;
            do {
                p[9] |= 0x20;
                p -= 10;
            } while ((u32) p >= (u32) D_overlay_13_00D01362);
        }
        break;
    case 6:
        frac = (f32) *(s16 *) (pl + 0x53E) / (f32) maxCharge;
        n = (s32) (5.0f - 5.0f * frac);
        if (n > 0) {
            p = D_overlay_13_00D013C8 + (n - 1) * 10;
            do {
                p[9] &= 0xDF;
                p -= 10;
            } while ((u32) p >= (u32) D_overlay_13_00D013D2);
        }
        break;
    case 4:
        frac = (f32) *(s16 *) (pl + 0x53E) / (f32) maxCharge;
        n = (s32) (5.0f - 5.0f * frac);
        if (n > 0) {
            p = D_overlay_13_00D0155C + (n - 1) * 10;
            do {
                p[9] &= 0xDF;
                p -= 10;
            } while ((u32) p >= (u32) D_overlay_13_00D01566);
        }
        break;
    case 11:
        frac = (f32) ((*(s16 *) (pl + 0x53E) - 0x20) >> 4) * 100.0f;
        fxInttostr((s8 *) numBuf, (s32) frac, 1);
        fxTinyPrint((s16) (x + 0x14), (s16) (y - 0x10), numBuf);
        break;
    case 7:
        frac = ((*(f32 *) (pl + 0x1EC) - 1.0f) * 225.0f) + 100.0f;
        fxInttostr((s8 *) numBuf, (s32) frac, 1);
        fxTinyPrint(0x20, (s16) (y - 8), numBuf);
        break;
    }

    count = *(u16 *) (entry + 4);
    lines = *(void **) entry;
    for (i = 0; i < count; i++) {
        rec = (u8 *) lines + i * 10;
        flags = *(u16 *) (rec + 8);
        if (((flags & 0x200) && flag == 0) || ((flags & 0x1) && flag != 0)) {
            continue;
        }
        x0 = *(s16 *) (rec + 0);
        y0 = *(s16 *) (rec + 2);
        x1 = *(s16 *) (rec + 4);
        y1 = *(s16 *) (rec + 6);
        colour = *(u8 *) (rec + 9);
        if ((flags & 0x400) && flag != 0) {
            colour += 0x10;
        }
        type = flags >> 11;

        if (type == 5) {
            if (multiPlayerGame == 0) {
                fxDrawLineInWindow(x0, (s16) (y0 + y), x1, (s16) (y1 + y), colour & 0xFF, player);
                fxDrawLineInWindow((s16) (0x140 - x1), (s16) (y0 + y), (s16) (0x140 - x0), (s16) (y1 + y),
                                   colour & 0xFF, player);
            }
        } else if (type == 6) {
            if (multiPlayerGame == 0) {
                fxDrawLineInWindow((s16) (x0 + x), y0, (s16) (x1 + x), y1, colour & 0xFF, player);
                fxDrawLineInWindow((s16) (x0 + x), (s16) (0xF0 - y1), (s16) (x1 + x), (s16) (0xF0 - y0),
                                   colour & 0xFF, player);
            }
        } else {
            fxDrawLineInWindow((s16) (x + x0), (s16) (y + y0), (s16) (x + x1), (s16) (y + y1), colour & 0xFF,
                               player);
            switch (type) {
            case 1:
                fxDrawLineInWindow((s16) (x - x0), (s16) (y + y0), (s16) (x - x1), (s16) (y + y1), colour | 0x40,
                                   player);
                break;
            case 2:
                fxDrawLineInWindow((s16) (x + x0), (s16) (y - y0), (s16) (x + x1), (s16) (y - y1), colour & 0xFF,
                                   player);
                break;
            case 3:
                colourMirror = (colour | 0x40) & 0xFF;
                fxDrawLineInWindow((s16) (x - x0), (s16) (y - y0), (s16) (x - x1), (s16) (y - y1), colourMirror,
                                   player);
                fxDrawLineInWindow((s16) (x - y0), (s16) (y + x0), (s16) (x - y1), (s16) (y + x1), colourMirror,
                                   player);
                fxDrawLineInWindow((s16) (x + y0), (s16) (y - x0), (s16) (x + y1), (s16) (y - x1), colour & 0xFF,
                                   player);
                break;
            case 4:
                fxDrawLineInWindow((s16) (x - x0), (s16) (y - y0), (s16) (x - x1), (s16) (y - y1), colour | 0x40,
                                   player);
                break;
            }
        }
    }

    switch (chrType) {
    case 3:
        n = (s32) (5.0f * frac);
        if (n > 0) {
            p = D_overlay_13_00D01358 + (n - 1) * 10;
            do {
                p[9] &= 0xDF;
                p -= 10;
            } while ((u32) p >= (u32) D_overlay_13_00D01362);
        }
        break;
    case 6:
        n = (s32) (5.0f - 5.0f * frac);
        if (n > 0) {
            p = D_overlay_13_00D013C8 + (n - 1) * 10;
            do {
                p[9] |= 0x20;
                p -= 10;
            } while ((u32) p >= (u32) D_overlay_13_00D013D2);
        }
        break;
    case 4:
        n = (s32) (5.0f - 5.0f * frac);
        if (n > 0) {
            p = D_overlay_13_00D0155C + (n - 1) * 10;
            do {
                p[9] |= 0x20;
                p -= 10;
            } while ((u32) p >= (u32) D_overlay_13_00D01566);
        }
        break;
    }

    mode = *(u16 *) (entry + 6);
    if (mode == 2) {
        rot[2] += 0x2000;
    }
    if (mode != 0) {
        camPushModelMtx(&frontgfx, &frontmtx, (ObjectTransform *) rot, 1.0f, 0.0f);
        if (flag == 0) {
            frontgfx->words.w0 = 0xFA000000;
            frontgfx->words.w1 = *(u32 *) (entry + 8);
        } else {
            frontgfx->words.w0 = 0xFA000000;
            frontgfx->words.w1 = *(u32 *) (entry + 0xC);
        }
        frontgfx++;
        frontgfx->words.w0 = ((((u32) D_80D011C0 & 6) | 0x60) & 0xFF) << 16 | 0x04000080;
        frontgfx->words.w1 = (u32) D_80D011C0;
        frontgfx++;
        frontgfx->words.w0 = 0x05300040;
        frontgfx->words.w1 = (u32) D_80D01238;
        frontgfx++;
        camPopModelMtx(&frontgfx);
    }
    if (mode == 2) {
        rot[2] -= 0x2000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o13/overlay_13/frontDrawTarget.s")
#endif
