#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct Droplet {
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6;      /* 0 = free, 1 = rising, 2 = landed / fading */
    /* 0x07 */ u8 unk7;      /* life counter, starts at 0x80 */
    /* 0x08 */ f32 unk8;     /* size scale */
    /* 0x0C */ f32 unkC;     /* x */
    /* 0x10 */ f32 unk10;    /* y */
    /* 0x14 */ f32 unk14;    /* z */
    /* 0x18 */ f32 unk18;    /* floor height (y clamp) */
    /* 0x1C */ f32 unk1C;    /* x velocity */
    /* 0x20 */ f32 unk20;    /* y velocity (gravity applied each update) */
    /* 0x24 */ f32 unk24;    /* z velocity */
    /* 0x28 */ f32 unk28;    /* age */
    /* 0x2C */ s32 unk2C;    /* 0/1 index of the sub-buffer used for the quad */
    /* 0x30 */ u8 pad30[0x50];
} Droplet; /* Size: 0x80 bytes */

extern u8 D_overlay_1_00100C30[];
extern void *D_overlay_1_00100C50;
extern void *D_overlay_1_00100C54;
extern TextureHeader *D_overlay_1_00100C58;
extern s32 D_overlay_1_00100C5C;
extern f32 D_overlay_1_00100C60;
extern f32 D_overlay_1_00100C64;
extern Droplet D_overlay_1_00100C70[0x20];
extern s32 D_overlay_1_00101C70;

void *texLoadSprite(s32 spriteId, s32 arg1);
void texFreeSprite(void *handle);
void texFreeTexture(void *tex);
void texDPTextureX(Gfx **dl, void *tex, s32 b, s32 c);
void camDoSprite(void **arg0, void **arg1, void **arg2, void *arg3, void *arg4, s32 arg5, u8 arg6);
void *camGetPtr(void);
void runlinkSetDestructTimer(s32 a, s32 b, s32 c, void *obj);

static Gfx *dropletGfxNext(Gfx **gfx) {
    Gfx *g = *gfx;

    *gfx = g + 1;
    return g;
}
#endif

void func_overlay_1_00100000_1ED3B20(void);

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_1_00100000_1ED3B20(void) {
    s32 i;
    s32 sub;
    u8 *blk;
    u8 *p;
    s16 w;
    s16 h;

    D_overlay_1_00100C50 = texLoadSprite(0x48, 0);
    D_overlay_1_00100C54 = texLoadSprite(0x45, 0);
    D_overlay_1_00100C58 = texLoadTexture(0x1AC);
    for (i = 0; i < 0x20; i++) {
        blk = (u8 *) &D_overlay_1_00100C70[i];
        D_overlay_1_00100C70[i].unk6 = 0;
        for (sub = 1; sub <= 2; sub++) {
            p = blk + sub * 0x28;
            p[0x18] = 0xFF;
            p[0x19] = 0xFF;
            p[0x1A] = 0xFF;
            p[0x1B] = 0xFF;
            p[0x22] = 0xFF;
            p[0x23] = 0xFF;
            p[0x24] = 0xFF;
            p[0x25] = 0xFF;
            p[0x2C] = 0xFF;
            p[0x2D] = 0xFF;
            p[0x2E] = 0xFF;
            p[0x2F] = 0xFF;
            p[0x0E] = 0xFF;
            p[0x0F] = 0xFF;
            p[0x10] = 0xFF;
            p[0x11] = 0xFF;
        }
    }
    D_overlay_1_00100C5C = 0;
    if (D_overlay_1_00100C58 != NULL) {
        w = (s16) ((D_overlay_1_00100C58->width - 1) << 5);
        h = (s16) ((D_overlay_1_00100C58->height - 1) << 5);
        *(s16 *) (D_overlay_1_00100C30 + 0x08) = w;
        *(s16 *) (D_overlay_1_00100C30 + 0x0C) = w;
        *(s16 *) (D_overlay_1_00100C30 + 0x0E) = h;
        *(s16 *) (D_overlay_1_00100C30 + 0x18) = w;
        *(s16 *) (D_overlay_1_00100C30 + 0x1A) = h;
        *(s16 *) (D_overlay_1_00100C30 + 0x1E) = h;
    }
    D_overlay_1_00101C70 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/func_overlay_1_00100000_1ED3B20.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dropletFreeLib(void) {
    if (D_overlay_1_00100C50 != NULL) {
        texFreeSprite(D_overlay_1_00100C50);
    }
    if (D_overlay_1_00100C54 != NULL) {
        texFreeSprite(D_overlay_1_00100C54);
    }
    if (D_overlay_1_00100C58 != NULL) {
        texFreeTexture(D_overlay_1_00100C58);
    }
    D_overlay_1_00101C70 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/dropletFreeLib.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
Droplet *dropletAdd(f32 size, f32 x, f32 y, f32 z, f32 floorY, f32 vx, f32 vy, f32 vz) {
    s32 i;
    Droplet *d;

    if (D_overlay_1_00101C70 == 0) {
        func_overlay_1_00100000_1ED3B20();
    }
    if (D_overlay_1_00100C5C >= 0x20) {
        return NULL;
    }
    /* first free slot; if none is free this ends at 0x20 (asm returns the one-past-end slot) */
    for (i = 0; i < 0x20; i++) {
        if (D_overlay_1_00100C70[i].unk6 == 0) {
            break;
        }
    }
    d = &D_overlay_1_00100C70[i];
    if (i < 0x20) {
        d->unk4 = 0;
        d->unk6 = 1;
        d->unk7 = 0x80;
        d->unk8 = size;
        d->unkC = x;
        d->unk10 = y;
        d->unk14 = z;
        d->unk18 = floorY;
        d->unk1C = vx;
        d->unk20 = vy;
        d->unk24 = vz;
        d->unk2C = 1;
        d->unk28 = 0.0f;
        D_overlay_1_00100C5C += 1;
    }
    return d;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/dropletAdd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *dropletUpdate(Droplet *d, s32 budget) {
    void *ret;
    s32 n;
    s32 m;
    s32 state;
    s32 flip;
    s32 t6;
    f32 vy;
    f32 half;
    u8 life;
    u8 *base;
    u8 *vtx;

    /* budget is the per-frame step count passed in from dropletUpdateAll */
    runlinkSetDestructTimer(1, 0x32, 0xA, d);
    state = d->unk6;
    n = budget;
    if (state == 1) {
        n -= 1;
        if (n != 0) {
            do {
                vy = d->unk20;
                d->unk10 += vy;
                d->unkC += d->unk1C;
                d->unk20 = vy - D_overlay_1_00100C60;
                d->unk14 += d->unk24;
                if (d->unk10 < d->unk18) {
                    d->unk10 = d->unk18;
                    d->unk6 = 2;
                    state = 2;
                    break;
                }
                n -= 1;
            } while (n != 0);
        }
    }
    ret = (void *) n;
    if (state == 2) {
        m = n - 1;
        if (n != 0) {
            life = d->unk7;
            do {
                life = (u8) (life - 2);
                d->unk28 += 0.5f;
                d->unk7 = life;
                if (life == 0) {
                    ret = &D_overlay_1_00100C5C;
                    d->unk6 = 0;
                    D_overlay_1_00100C5C -= 1;
                    state = d->unk6;
                    break;
                }
                ret = (void *) m;
                m -= 1;
            } while (m != 0);
        }
        if (state != 0) {
            flip = 1 - d->unk2C;
            d->unk2C = flip;
            base = (u8 *) d + flip * 0x28 + 0x30;
            half = d->unk8 * (24.0f - (0.1875f * (f32) d->unk7));
            vtx = base + 0x1E;
            t6 = (s32) d->unk18;
            *(s16 *) (vtx - 0x1C) = (s16) t6;
            *(s16 *) (vtx - 0x1E) = (s16) (s32) (d->unkC - half);
            *(s16 *) (vtx - 0x1A) = (s16) (s32) (d->unk14 + half);
            *(s16 *) (vtx - 0x12) = (s16) t6;
            *(s16 *) (vtx - 0x14) = (s16) (s32) (d->unkC + half);
            *(s16 *) (vtx - 0x10) = (s16) (s32) (d->unk14 + half);
            *(s16 *) (vtx - 0x08) = (s16) t6;
            *(s16 *) (vtx - 0x0A) = (s16) (s32) (d->unkC - half);
            *(s16 *) (vtx - 0x06) = (s16) (s32) (d->unk14 - half);
            *(s16 *) (vtx + 0x02) = (s16) t6;
            *(s16 *) (vtx + 0x00) = (s16) (s32) (d->unkC + half);
            *(s16 *) (vtx + 0x04) = (s16) (s32) (d->unk14 - half);
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/dropletUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dropletUpdateAll(s32 arg0) {
    s32 i;

    if (D_overlay_1_00100C5C != 0) {
        for (i = 0; i < 0x20; i++) {
            if (D_overlay_1_00100C70[i].unk6 != 0) {
                dropletUpdate(&D_overlay_1_00100C70[i], arg0);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/dropletUpdateAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_1_00100678_1ED4198(Droplet *d, Gfx **gfx, void **arg2, void **arg3) {
    f32 scale;
    u8 *lvl;
    Gfx *g;
    u32 addr;

    if ((d->unk6 == 1 && D_overlay_1_00100C50 != NULL) || d->unk6 == 2) {
        lvl = (u8 *) levelGetLevel();
        scale = d->unk8;
        if (d->unk6 != 2) {
            sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, lvl[0xF3], lvl[0xF4], lvl[0xF5]);
            d->unk8 = scale;
            camDoSprite(gfx, arg2, arg3, d, D_overlay_1_00100C50, 6, 0xFF);
            sprClearIA2ColOverride();
        } else {
            texDPTextureX(gfx, D_overlay_1_00100C58, 0xE, 0);
            if (d->unk7 < 0x20) {
                g = dropletGfxNext(gfx);
                g->words.w0 = 0xFA000000;
                g->words.w1 = (s32) (((d->unk7 * 8) & 0xFF) | ~0xFF);
            }
            /* asm: vertex/quad address from the active sub-buffer */
            addr = (u32) d + d->unk2C * 0x28 + 0x80000030;
            g = dropletGfxNext(gfx);
            g->words.w0 = (((((addr & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30);
            g->words.w1 = addr;
            g = dropletGfxNext(gfx);
            g->words.w1 = (u32) D_overlay_1_00100C30;
            g->words.w0 = 0x05110020;
            /* asm: derefs the sprite handle to read a threshold byte */
            if (D_overlay_1_00100C54 != NULL && d->unk28 < (f32) *(u8 *) D_overlay_1_00100C54) {
                d->unk8 = (f32) (scale * D_overlay_1_00100C64);
                g = dropletGfxNext(gfx);
                g->words.w0 = 0xFA000000;
                g->words.w1 = (lvl[0xF3] << 0x18) | (lvl[0xF4] << 0x10) | (lvl[0xF5] << 8) | 0xA0;
                g = dropletGfxNext(gfx);
                g->words.w1 = -0x100;
                g->words.w0 = 0xFB000000;
                camDoSprite(gfx, arg2, arg3, d, D_overlay_1_00100C54, 0xE, 0);
            }
        }
        d->unk8 = scale;
        g = dropletGfxNext(gfx);
        g->words.w1 = 0;
        g->words.w0 = 0xE7000000;
        g = dropletGfxNext(gfx);
        g->words.w1 = -1;
        g->words.w0 = 0xFB000000;
        g = dropletGfxNext(gfx);
        g->words.w1 = -1;
        g->words.w0 = 0xFA000000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/func_overlay_1_00100678_1ED4198.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dropletDrawAll(Gfx **gfx, void **arg1, void **arg2) {
    s32 order[0x20];
    f32 dist[0x20];
    s32 n;
    s32 i;
    s32 j;
    s32 idx;
    f32 od;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 *camPos;
    Droplet *d;

    if (D_overlay_1_00101C70 != 0 && D_overlay_1_00100C5C != 0) {
        camPos = (f32 *) ((u8 *) camGetPtr() + 0xC);
        n = 0;
        for (i = 0; i < 0x20; i++) {
            d = &D_overlay_1_00100C70[i];
            if (d->unk6 != 0) {
                dx = d->unkC - camPos[0];
                dy = d->unk10 - camPos[1];
                dz = d->unk14 - camPos[2];
                order[n] = i;
                dist[n] = (dx * dx) + (dy * dy) + (dz * dz);
                n += 1;
            }
        }
        /* ascending by distance (insertion sort, same order as the asm's swap loop) */
        for (i = 1; i < n; i++) {
            idx = order[i];
            od = dist[i];
            for (j = i; j > 0 && dist[j - 1] > od; j--) {
                dist[j] = dist[j - 1];
                order[j] = order[j - 1];
            }
            dist[j] = od;
            order[j] = idx;
        }
        for (i = 0; i < n; i++) {
            func_overlay_1_00100678_1ED4198(&D_overlay_1_00100C70[order[i]], gfx, arg1, arg2);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/dropletDrawAll.s")
#endif

#if 0
void dropletFreeLib(void);
void _AutoExit00001(void) {
    //Call dropletFreeLib();
    //dropletFreeLib();
    func_overlay_1_00100000_1ED3B20();
}
#else
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00001(void) {
    dropletFreeLib();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o1/overlay_1/_AutoExit00001.s")
#endif
#endif
