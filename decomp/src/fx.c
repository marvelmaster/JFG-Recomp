#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern u8 D_80102760_B1750[];
s16 levelGetNumber(void);
s32 texLoadSprite(s32 spriteId, s32 arg1, void *owner);
void texFreeSprite(s32 handle, void *owner);
s32 texAnimateSprite(s32 handle, s32 *state, s32 frames, void *data, s32 dt);
void camDoSprite(s32 arg0, s32 arg1, s32 arg2, void *entry, s32 handle, s32 arg5, s32 arg6);
void *camGetPtr(void);
void texFreeTexture(void *tex);
f32 Sinf(s32 angle);
void func_80068CD4(void *arg0);
void func_80068CDC(void *arg0);
void func_80068D34(void *arg0);
void func_80069320(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6, f32 arg7);
void func_80069510(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6, f32 arg7);
void fxMakeConeTextureCoords(void *arg0, s16 arg1);
void mathOneFloatPY(void *mtx, f32 *out, s32 angle);
void func_8006A224(s32 count, s16 offX, s16 offY, s16 offZ, s16 angleX, s16 angleY, f32 *src, u8 *dst);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
void func_8006FFF8(void *arg0);
u8 *mmAlign4(u8 *address);
s32 trackPolyHeight(f32 x, f32 z, f32 *out, s32 flags);
s32 wakeAllocate(s8 type, s32 a1, s32 a2, s32 a3, s32 a4, f32 scale);
extern s32 D_800A6780_A7380;
extern s32 D_800A6784_A7384;
extern u16 D_800A6794_A7394;
extern u16 D_800A6798_A7398;
extern s8 D_800A67A0_A73A0;
extern u8 D_800A67A4_A73A4[];
extern u8 D_800A67AC_A73AC[];
extern void *D_800A67B0_A73B0;
extern s32 D_800A6950_A7550;
extern u8 D_A6958[];
extern s32 D_80102DB0_B1DA0;
extern s32 D_80102DB4_B1DA4;
extern s32 D_80102DB8_B1DA8;
extern s32 D_800A6788_A7388;
extern s32 D_800A678C_A738C;
extern s32 D_800A6790_A7390;
extern u16 D_800A679C_A739C;
extern u32 D_80102D38_B1D28;
extern u8 D_80102D50_B1D40;
extern u8 D_80102D58_B1D48;
extern u8 D_80102D70_B1D60;
extern s32 D_80102D8C_B1D7C;
extern s32 D_80102D90_B1D80;
extern s32 D_80102D94_B1D84;
extern u8 D_800A6810_A7410[];
extern u8 D_800A6848_A7448[];
extern u8 D_800A6880_A7480[];
extern u8 D_800A688C_A748C[];
extern u8 D_800A6898_A7498[];
extern u8 D_800A68B0_A74B0[];
extern u8 D_800A68BC_A74BC[];
extern u8 D_800A68EC_A74EC[];
extern u8 D_800A68F8_A74F8[];
extern u8 D_800A6904_A7504[];
extern u8 D_800A6918_A7518[];
extern s32 D_800A67B4_A73B4;
extern u8 D_800A67B8_A73B8[];
extern u8 D_800A6928_A7528[];
extern u8 D_80102D88_B1D78;
extern f32 D_80102DA8_B1D98;
extern f32 D_80102DAC_B1D9C;
extern s32 D_80102D98_B1D88;
extern s32 D_80102DA0_B1D90;
extern s32 D_80102DA4_B1D94;
extern s32 D_80102DBC_B1DAC;
void func_8006C1B8();
void func_8006C1CC(u8 *arg0, u8 *arg1, u16 *arg2, u32 *arg3);
void func_8006C280(s32 arg0);
void func_8006C454(Gfx **dlist, void **mtxp, void **vtxp);
void func_8006C560(u8 *arg0, s32 arg1, s32 arg2, void *arg3, u8 *arg4, u8 *arg5, u8 *arg6, u8 *arg7, u8 *arg8);
void func_8006CAAC(s32 arg0);
void func_8006CD60(Gfx **dlist, void **mtxp, void **vtxp);
void func_8006CE58(Gfx **dlist, void **mtxp, void **vtxp);
void func_8006CF50(Gfx **dlist, void **mtxp, void **vtxp);
void func_8006D048(void *arg0, u8 *arg1, u16 *arg2, u32 *arg3);
void func_8006D1A8(s32 arg0);
void func_8006D2F0(Gfx **dlist, void **mtxp, void **vtxp);
void camOrthoYAspect(f32 arg0);
void camStandardOrtho();
void camSetView();
s32 viGetScaleXY(f32 *arg0, f32 *arg1);

typedef struct FxLine {
    s16 x0;     /* 0x00 */
    s16 x1;     /* 0x02 */
    s32 packed; /* 0x04: y0 * 0x10 | flags in high half, low byte = type */
} FxLine;

typedef struct FxText {
    s16 x;      /* 0x00 */
    s16 y;      /* 0x02 */
    u8 text[0x20];
} FxText;

extern FxLine D_80102DC0_B1DB0[2][0x94];
extern s32 D_80103B80_B2B70[2];
extern s32 D_80103B88_B2B78[2];
extern s32 D_80103B90_B2B80;
extern s32 D_80103B94_B2B84;
extern FxText sniperStructs[2][0x10];
extern u8 multiPlayerGame;
extern s32 D_800A6B64_A7764[];
extern u8 D_800A6BA8_A77A8[];

typedef struct FxPat {
    s8 dx;  /* 0x00 */
    s8 dy;  /* 0x01 */
} FxPat;

typedef struct FxScreenEffect {
    s32 unk0;   /* 0x00 */
    s16 unk4;   /* 0x04 */
    s16 unk6;   /* 0x06 */
    s16 unk8;   /* 0x08 */
    s16 unkA;   /* 0x0A */
    s16 unkC;   /* 0x0C */
    s16 unkE;   /* 0x0E */
    s32 unk10;  /* 0x10 */
} FxScreenEffect;

extern FxPat D_800A6968_A7568[];
extern FxPat D_800A698C_A758C[];
extern FxPat D_800A69AC_A75AC[];
extern FxPat D_800A69CC_A75CC[];
extern u8 D_800A69EC_A75EC[];
extern u8 D_800A6B2C_A772C[];
extern u16 D_800A6B40_A7740[];
extern s32 D_800A6D00_A7900;
extern s32 D_800A6D04_A7904;
extern u8 D_800A6D08_A7908;
extern u8 D_800A6D0C_A790C;
extern u8 D_800A6BB8_A77B8[];
extern u8 D_80102CE0_B1CD0;
extern u8 D_80102CE1_B1CD1;
extern u8 D_80102CE2_B1CD2;
extern u8 D_80102CE3_B1CD3;
extern u8 D_80102CE4_B1CD4;
extern u8 D_80102CE5_B1CD5;
extern u8 D_800A6D20_A7920[];
extern u32 D_800A6D70_A7970[];
extern u32 D_800A6DA8_A79A8[];
extern s32 D_800A6E18_A7A18;
extern FxScreenEffect D_80102CE8_B1CD8[4];
extern void *D_800A6E1C_A7A1C[4];
extern void *D_80102D40_B1D30[4];
extern s32 D_80102D54_B1D44;
extern s32 D_80102D6C_B1D5C;
extern s32 D_80102D84_B1D74;
extern u8 D_80102D9F_B1D8F;
extern s32 D_800A6E28_A7A28;
extern s16 D_800A6D10_A7910;
extern s16 D_800A6D14_A7914;
extern s16 D_800A6D18_A7918;
extern u8 *CpuTexSpaceA[4];
extern u8 *CpuTexSpaceB[4];
s32 mathSin(s32 angle);
void runlinkEnsureJumpIsValid(void *ptr);
void fxScreenEffect(Gfx **dl, void *screen, s32 w, s32 h, s32 x, s32 y, s32 right, s32 bottom, void *tex);
s32 camProjectPoint(f32 x, f32 y, f32 z, f32 *sx, f32 *sy, s32 flag);
void frontPlayerScreenLimits(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxInitLevelEffects(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        u8 *e = D_80102760_B1750 + i * 0x2C;

        e[0x06] = 0;
        e[0x07] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxInitLevelEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxAddLevelEffect(s32 type, f32 x, f32 y, f32 z, s16 arg4, s16 arg5, s16 arg6, f32 radius, s32 lifetime) {
    u8 *slot = NULL;
    u8 *cand;
    s32 candLoaded;
    s32 i;

    for (i = 0; i < 0x20; i++) {
        u8 *e = D_80102760_B1750 + i * 0x2C;

        if (e[0x06] == 0) {
            slot = e;
            break;
        }
    }

    if (slot == NULL) {
        /* no free entry: evict the oldest, preferring entries that are not loaded */
        cand = D_80102760_B1750;
        candLoaded = cand[0x07];
        for (i = 1; i < 0x20; i++) {
            u8 *e = D_80102760_B1750 + i * 0x2C;

            if (e[0x07] == 0) {
                if ((candLoaded != 0) || (*(s16 *)(cand + 0x1A) < *(s16 *)(e + 0x1A))) {
                    candLoaded = 0;
                    cand = e;
                }
            } else if ((candLoaded != 0) && (*(s16 *)(cand + 0x1A) < *(s16 *)(e + 0x1A))) {
                cand = e;
            }
        }
        slot = cand;
    }

    if (slot[0x07] != 0) {
        func_80068D34(slot);
    }

    *(s16 *)(slot + 0x00) = arg4;
    *(s16 *)(slot + 0x02) = arg5;
    *(s16 *)(slot + 0x04) = arg6;
    slot[0x06] = (u8)type;
    *(f32 *)(slot + 0x08) = radius;
    *(f32 *)(slot + 0x0C) = x;
    *(f32 *)(slot + 0x10) = y;
    *(f32 *)(slot + 0x14) = z;
    *(s16 *)(slot + 0x18) = (s16)lifetime;
    *(s16 *)(slot + 0x1A) = 0;
    *(s16 *)(slot + 0x1C) = levelGetNumber();
    *(f32 *)(slot + 0x28) = 0.0f;
    func_80068CD4(slot);
    func_80068CDC(slot);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxAddLevelEffect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxClearLevelEffects(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        u8 *e = D_80102760_B1750 + i * 0x2C;

        if (e[0x07] != 0) {
            func_80068D34(e);
        }
        e[0x06] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxClearLevelEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxLevelFreeLevelEffects(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        u8 *e = D_80102760_B1750 + i * 0x2C;

        if (e[0x07] != 0) {
            func_80068D34(e);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxLevelFreeLevelEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxLevelAllocateLevelEffects(s32 level) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        u8 *e = D_80102760_B1750 + i * 0x2C;

        if ((e[0x06] != 0) && (level == *(s16 *)(e + 0x1C))) {
            func_80068CDC(e);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxLevelAllocateLevelEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80068CD4(void *arg0) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_80068CD4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80068CDC(void *arg0) {
    u8 *e = (u8 *)arg0;

    if (e[0x07] == 0) {
        if (e[0x06] == 4) {
            *(s32 *)(e + 0x24) = texLoadSprite(0x57, 0, arg0);
        }
        e[0x07] = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_80068CDC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80068D34(void *arg0) {
    u8 *e = (u8 *)arg0;

    if (e[0x07] != 0) {
        if (e[0x06] == 4) {
            texFreeSprite(*(s32 *)(e + 0x24), arg0);
        }
        e[0x07] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_80068D34.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxUpdateLevelEffects(s32 dt) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        u8 *e = D_80102760_B1750 + i * 0x2C;

        if (e[0x06] != 0) {
            *(s16 *)(e + 0x18) = (s16)(*(s16 *)(e + 0x18) - dt);
            *(s16 *)(e + 0x1A) = (s16)(*(s16 *)(e + 0x1A) + dt);
            if (*(s16 *)(e + 0x18) <= 0) {
                *(s16 *)(e + 0x18) = 0;
                if (e[0x07] != 0) {
                    func_80068D34(e);
                }
                e[0x06] = 0;
            } else if (e[0x06] == 4) {
                s32 state = 1;

                if (texAnimateSprite(*(s32 *)(e + 0x24), &state, 0xF, e + 0x28, dt) != 0) {
                    *(s16 *)(e + 0x18) = 0;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxUpdateLevelEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawLevelEffects(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *sorted[0x20];
    f32 dist[0x20];
    void *cam;
    s32 count;
    s32 i;
    s32 j;

    cam = camGetPtr();
    count = 0;
    for (i = 0; i < 0x20; i++) {
        u8 *e = D_80102760_B1750 + i * 0x2C;

        if ((e[0x06] != 0) && (e[0x07] != 0)) {
            f32 dx = *(f32 *)((u8 *)cam + 0x0C) - *(f32 *)(e + 0x0C);
            f32 dy = *(f32 *)((u8 *)cam + 0x10) - *(f32 *)(e + 0x10);
            f32 dz = *(f32 *)((u8 *)cam + 0x14) - *(f32 *)(e + 0x14);

            sorted[count] = e;
            dist[count] = (dx * dx) + (dy * dy) + (dz * dz);
            count++;
        }
    }

    /* sort farthest first */
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < (count - 1) - i; j++) {
            if (dist[j] < dist[j + 1]) {
                f32 tf = dist[j];
                u8 *te = sorted[j];

                dist[j] = dist[j + 1];
                dist[j + 1] = tf;
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = te;
            }
        }
    }

    for (i = 0; i < count; i++) {
        u8 *e = sorted[i];

        if (e[0x06] == 4) {
            camDoSprite(arg0, arg1, arg2, e, *(s32 *)(e + 0x24), 2, 0xFF);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxDrawLevelEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxFreeCone(void *cone) {
    void *tex;

    tex = *(void **)((u8 *)cone + 0x00);
    if (tex != NULL) {
        texFreeTexture(tex);
    }
    tex = *(void **)((u8 *)cone + 0x04);
    if (tex != NULL) {
        texFreeTexture(tex);
    }
    mmFree(cone);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxFreeCone.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
MemoryPoolSlot *fxAllocateCone(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 sizeA;
    s32 sizeB;
    u8 *cone;

    if (arg7 == 0) {
        sizeA = 0x280;
        sizeB = 0x154;
    } else {
        sizeA = arg7 * 0x10;
        sizeB = (arg7 * 0xA) + 0xA;
    }
    cone = (u8 *)mmAlloc(sizeA + (sizeB * 2) + 0x28, -1U);
    if (cone != NULL) {
        if (arg8 >= 0) {
            *(void **)(cone + 0x00) = texLoadTexture(arg8);
        } else {
            *(void **)(cone + 0x00) = NULL;
        }
        if (arg9 >= 0) {
            *(s32 *)(cone + 0x04) = (s32)texLoadTexture(arg9);
        } else {
            *(s32 *)(cone + 0x04) = 0;
        }
        *(u8 **)(cone + 0x10) = cone + 0x28;
        *(u8 **)(cone + 0x08) = cone + 0x28 + sizeA;
        *(u8 **)(cone + 0x0C) = cone + 0x28 + sizeA + sizeB;
        *(s8 *)(cone + 0x14) = (s8)(arg7 + 1);
        *(s8 *)(cone + 0x15) = (s8)arg7;
        *(s8 *)(cone + 0x16) = 0;
        *(f32 *)(cone + 0x18) = arg5;
        *(s16 *)(cone + 0x1C) = arg3;
        *(s16 *)(cone + 0x1E) = arg4;
        *(s16 *)(cone + 0x20) = (s16)arg6;
        *(s16 *)(cone + 0x22) = arg0;
        *(s16 *)(cone + 0x24) = arg1;
        *(s16 *)(cone + 0x26) = arg2;
        if (arg7 == 0) {
            func_80069510(cone, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        } else {
            func_80069320(cone, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        }
        fxMakeConeTextureCoords(cone, 0);
    }
    return (MemoryPoolSlot *)cone;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxAllocateCone.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Cone with N ring segments (fxAllocateCone arg7 != 0). pts[] holds the apex
// (0,0,-length) followed by N ring points (r*sin, r*cos, 0), so the transform
// call sees N+1 points. Index records are 16 bytes; triangle k is
// (0, k, k+1) and the last one wraps back to vertex 1.
void func_80069320(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6, f32 arg7) {
    u8 *cone = (u8 *)arg0;
    f32 pts[19 * 3];
    s32 count;
    s32 step;
    s32 angle;
    s32 i;
    s32 k;
    u8 *idx;

    count = *(u8 *)(cone + 0x15);
    pts[0] = 0.0f;
    pts[1] = 0.0f;
    pts[2] = -arg7;
    step = 0x10000 / count;
    angle = 0;
    for (i = 0; i < count; i++) {
        pts[3 + i * 3 + 0] = Sinf(angle) * arg6;
        pts[3 + i * 3 + 1] = Cosf(angle) * arg6;
        pts[3 + i * 3 + 2] = 0.0f;
        angle += step;
    }

    /* transform into both vertex buffers (cone+0x08, cone+0x0C) */
    for (k = 0; k < 8; k += 4) {
        func_8006A224(*(u8 *)(cone + 0x14), arg1, arg2, arg3, arg4, arg5, pts, *(u8 **)(cone + 0x08 + k));
    }

    idx = *(u8 **)(cone + 0x10);
    for (k = 1; k <= count; k++) {
        idx[0] = 0;
        idx[1] = (u8)k;
        idx[2] = (u8)(k + 1);
        idx[3] = 0;
        idx += 0x10;
    }
    idx[-0xE] = 1; /* asm: sb 1, -0xE(v0) closes the ring */
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_80069320.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Fixed 8-segment cone (fxAllocateCone arg7 == 0): inner ring of 8 points
// (vertices 1..8) and outer ring of 8 points (9..16), apex at 0.
// Outer ring uses 4*r and z = -0.33*length. Records: 32 sub-records of 16
// bytes at +0x00 and +0x10 of each 0x20 block, then 8 more sub-records.
void func_80069510(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6, f32 arg7) {
    u8 *cone = (u8 *)arg0;
    f32 pts[17 * 3];
    f32 r4;
    f32 zOuter;
    f32 *inner;
    f32 *outer;
    s32 angle;
    s32 i;
    s32 k;
    u8 *idx;
    u8 m;
    f32 s;
    f32 c;

    r4 = arg6 * 4.0f;
    zOuter = -(arg7 * 0.33f);
    pts[0] = 0.0f;
    pts[1] = 0.0f;
    pts[2] = -arg7;
    for (i = 0; i < 8; i++) {
        angle = i << 13;
        s = Sinf(angle);
        c = Cosf(angle);
        inner = &pts[3 + i * 3];
        outer = &pts[27 + i * 3];
        inner[0] = arg6 * s;
        inner[1] = arg6 * c;
        inner[2] = 0.0f;
        outer[0] = r4 * s;
        outer[1] = r4 * c;
        outer[2] = zOuter;
    }

    for (k = 0; k < 8; k += 4) {
        func_8006A224(17, arg1, arg2, arg3, arg4, arg5, pts, *(u8 **)(cone + 0x08 + k));
    }

    idx = *(u8 **)(cone + 0x10);
    for (i = 1; i < 9; i++) {
        m = (u8)(i & 7);
        idx[0x00] = 0;
        idx[0x01] = (u8)i;
        idx[0x02] = (u8)(i + 8);
        idx[0x03] = (u8)(m + 9);
        idx[0x10] = 0;
        idx[0x11] = (u8)i;
        idx[0x12] = (u8)(m + 9);
        idx[0x13] = (u8)(m + 1);
        idx += 0x20;
    }
    for (i = 1; i < 9; i++) {
        m = (u8)(i & 7);
        idx[0x00] = 0;
        idx[0x01] = (u8)i;
        idx[0x02] = (u8)(m + 9);
        idx[0x03] = (u8)(i + 8);
        idx[0x10] = 0;
        idx[0x11] = (u8)i;
        idx[0x12] = (u8)(m + 1);
        idx[0x13] = (u8)(m + 9);
        idx += 0x20;
    }
    /* 0x40-byte groups: 4 sub-records each (0x0, 0x10, 0x20, 0x30) */
    for (i = 1; i != 9; i += 4) {
        idx[0x00] = 0;
        idx[0x01] = (u8)i;
        idx[0x02] = (u8)((i & 7) + 1);
        idx[0x03] = 0;
        idx[0x10] = 0;
        idx[0x11] = (u8)(i + 1);
        idx[0x12] = (u8)(((i + 1) & 7) + 1);
        idx[0x13] = 0;
        idx[0x20] = 0;
        idx[0x21] = (u8)(i + 2);
        idx[0x22] = (u8)(((i + 2) & 7) + 1);
        idx[0x23] = 0;
        idx[0x30] = 0;
        idx[0x31] = (u8)(i + 3);
        idx[0x32] = (u8)(((i + 3) & 7) + 1);
        idx[0x33] = 0;
        idx += 0x40;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_80069510.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Fills the texcoords (+0x04..+0x0F) of each 16-byte index record. Tables
// tabA (cos axis) and tabB (sin axis) hold per-ring-point texcoords; the
// apex texcoord is the texture corner (w, h) = texture size * 16.
void fxMakeConeTextureCoords(void *arg0, s16 arg1) {
    u8 *cone = (u8 *)arg0;
    TextureHeader *tex;
    s16 tabA[20];
    s16 tabB[20];
    f32 fw;
    f32 fh;
    s32 w;
    s32 h;
    s32 count;
    s32 step;
    s32 angle;
    s32 i;
    u8 *rec;
    f32 s;
    f32 c;

    if (cone == NULL) {
        return;
    }
    tex = *(TextureHeader **)(cone + 0x00);
    if (tex == NULL) {
        return;
    }

    w = tex->width << 4;
    h = tex->height << 4;
    count = *(u8 *)(cone + 0x15);
    rec = *(u8 **)(cone + 0x10);

    if (count == 0) {
        /* 8-segment cone: ring points 1..8 (+1 offset) and 9..16 */
        fw = (f32)(w - 1);
        fh = (f32)(h - 1);
        angle = (s16)arg1;
        for (i = 0; i < 8; i++) {
            s = Sinf(angle);
            c = Cosf(angle);
            tabB[i + 1] = (s16)((s32)(102.4f * s) + w);
            tabA[i + 1] = (s16)((s32)(102.4f * c) + h);
            tabB[i + 9] = (s16)((s32)(fw * s) + w);
            tabA[i + 9] = (s16)((s32)(fh * c) + h);
            angle += 0x2000;
        }
        /* 32 records from the tables above */
        for (i = 0; i < 32; i++) {
            u8 i1 = rec[1];
            u8 i2 = rec[2];
            u8 i3 = rec[3];
            *(s16 *)(rec + 0x04) = tabB[i1];
            *(s16 *)(rec + 0x06) = tabA[i1];
            *(s16 *)(rec + 0x08) = tabB[i2];
            *(s16 *)(rec + 0x0A) = tabA[i2];
            *(s16 *)(rec + 0x0C) = tabB[i3];
            *(s16 *)(rec + 0x0E) = tabA[i3];
            rec += 0x10;
        }
        count = 8;
        step = 0x2000;
    } else {
        step = 0x10000 / count;
    }

    /* table fill: count+1 entries, same angle sequence as the transform */
    fw = (f32)(w - 1);
    fh = (f32)(h - 1);
    angle = (s16)arg1;
    for (i = 0; i <= count; i++) {
        s = Sinf(angle);
        c = Cosf(angle);
        tabB[i] = (s16)((s32)(s * fw) + w);
        tabA[i] = (s16)((s32)(c * fh) + h);
        angle = (s16)(angle + step);
    }

    /* records for the cone triangles (count records) */
    for (i = 0; i < count; i++) {
        *(s16 *)(rec + 0x04) = tabB[i];
        *(s16 *)(rec + 0x06) = tabA[i];
        *(s16 *)(rec + 0x08) = tabB[i + 1];
        *(s16 *)(rec + 0x0A) = tabA[i + 1];
        *(s16 *)(rec + 0x0C) = (s16)w;
        *(s16 *)(rec + 0x0E) = (s16)h;
        rec += 0x10;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxMakeConeTextureCoords.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxMakeConeLength(void *arg0, s16 arg1, s32 arg2) {
    u8 *cone = (u8 *)arg0;
    f32 tip[3];
    f32 ring[24];
    u8 *buf;
    s32 idx;
    s32 i;
    f32 t;
    f32 r;
    f32 yOff;

    if (cone == NULL) {
        return;
    }
    idx = *(u8 *)(cone + 0x16) ^ 1;
    *(u8 *)(cone + 0x16) = idx;
    buf = *(u8 **)(cone + 0x08 + idx * 4);

    tip[2] = (f32)(-arg1);
    mathOneFloatPY(cone + 0x1C, tip, (s32)arg1 << 16);
    *(s16 *)(buf + 0x00) = (s16)((s32)tip[0] + *(s16 *)(cone + 0x22));
    *(s16 *)(buf + 0x02) = (s16)((s32)tip[1] + *(s16 *)(cone + 0x24));
    *(s16 *)(buf + 0x04) = (s16)((s32)tip[2] + *(s16 *)(cone + 0x26));

    if (*(u8 *)(cone + 0x15) == 0) {
        if (arg2 < 0x80) {
            t = 0.0f;
        } else if (arg2 >= 0x100) {
            t = 1.0f;
        } else {
            t = (f32)(arg2 - 0x7F) * 0.0078125f;
        }
        r = *(f32 *)(cone + 0x18) * (1.0f + (2.0f * t));
        yOff = -((f32)*(s16 *)(cone + 0x20) * (0.25f * t));
        for (i = 0; i < 8; i++) {
            s32 angle = i << 0xD;

            ring[i * 3 + 0] = Sinf(angle) * r;
            ring[i * 3 + 1] = Cosf(angle) * r;
            ring[i * 3 + 2] = yOff;
        }
        func_8006A224(8, *(s16 *)(cone + 0x22), *(s16 *)(cone + 0x24), *(s16 *)(cone + 0x26),
                      *(s16 *)(cone + 0x1C), *(s16 *)(cone + 0x1E), ring, buf + 0x5A);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxMakeConeLength.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawCone(Gfx **arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *cone = (u8 *)arg1;
    Gfx *gfx;
    s32 hasTex;
    s32 vtxAddr;
    s32 triWord;
    u8 *vtx;

    if (cone != NULL) {
        hasTex = (*(void **)(cone + 0x00) != NULL);

        gfx = *arg0; *arg0 = gfx + 1;
        gfx->words.w1 = 0;
        gfx->words.w0 = 0xE7000000;
        gfx = *arg0; *arg0 = gfx + 1;
        gfx->words.w0 = 0xFA000000;
        gfx->words.w1 = (arg3 & 0xFF) | ~0xFF;
        gfx = *arg0; *arg0 = gfx + 1;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = -0x100;

        vtx = *(u8 **)(cone + 0x08 + *(u8 *)(cone + 0x16) * 4);
        vtxAddr = (s32)vtx + 0x80000000;

        if (*(u8 *)(cone + 0x15) == 0) {
            gfx = *arg0; *arg0 = gfx + 1;
            gfx->words.w0 = ((((vtxAddr & 6) | 0x88) & 0xFF) << 16) | 0x04000000 | 0xB2;
            gfx->words.w1 = vtxAddr;
            texDPTextureX(arg0, *(void **)(cone + 0x04), arg2, 0);

            gfx = *arg0; *arg0 = gfx + 1;
            triWord = (((hasTex | 0xF0) & 0xFF) << 16) | 0x05000000 | 0x100;
            gfx->words.w0 = triWord;
            gfx->words.w1 = (s32)*(u8 **)(cone + 0x10) + 0x80000000;
            texDPTextureX(arg0, *(void **)(cone + 0x00), arg2, 0);

            gfx = *arg0; *arg0 = gfx + 1;
            gfx->words.w0 = (((hasTex | 0x70) & 0xFF) << 16) | 0x05000000 | 0x80;
            gfx->words.w1 = (s32)*(u8 **)(cone + 0x10) + 0x80000200;
            texDPTextureX(arg0, *(void **)(cone + 0x04), arg2, 0);

            gfx = *arg0; *arg0 = gfx + 1;
            gfx->words.w0 = triWord;
            gfx->words.w1 = (s32)*(u8 **)(cone + 0x10) + 0x80000100;
        } else {
            u8 shadeLvl = *(u8 *)(cone + 0x14);
            u8 segs = *(u8 *)(cone + 0x15);

            texDPTextureX(arg0, *(void **)(cone + 0x00), arg2, 0);
            gfx = *arg0; *arg0 = gfx + 1;
            gfx->words.w0 = (((((vtxAddr & 6) | (shadeLvl * 8)) & 0xFF) << 16) | 0x04000000
                             | (((shadeLvl * 0xA) + 8) & 0xFFFF));
            gfx->words.w1 = vtxAddr;

            gfx = *arg0; *arg0 = gfx + 1;
            gfx->words.w0 = (((((segs - 1) * 0x10) | hasTex) & 0xFF) << 16) | 0x05000000
                            | ((segs * 0x10) & 0xFFFF);
            gfx->words.w1 = (s32)*(u8 **)(cone + 0x10) + 0x80000000;
        }

        gfx = *arg0; *arg0 = gfx + 1;
        gfx->words.w1 = 0;
        gfx->words.w0 = 0xE7000000;
        gfx = *arg0; *arg0 = gfx + 1;
        gfx->words.w1 = -1;
        gfx->words.w0 = 0xFA000000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxDrawCone.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006A224(s32 count, s16 offX, s16 offY, s16 offZ, s16 angleX, s16 angleY, f32 *src, u8 *dst) {
    f32 sinY = Sinf(angleY);
    f32 cosY = Cosf(angleY);
    f32 sinX = Sinf(angleX);
    f32 cosX = Cosf(angleX);
    s32 i;

    for (i = 0; i < count; i++) {
        f32 x = src[0];
        f32 y = src[1];
        f32 z = src[2];
        f32 yz = (z * cosY) + (y * sinY);

        dst[6] = 0xFF;
        dst[7] = 0xFF;
        dst[8] = 0xFF;
        dst[9] = 0xFF;
        *(s16 *)(dst + 0x0) = (s16)((s32)((x * cosX) + (yz * sinX)) + offX);
        *(s16 *)(dst + 0x2) = (s16)((s32)((y * cosY) - (z * sinY)) + offY);
        *(s16 *)(dst + 0x4) = (s16)((s32)((yz * cosX) - (x * sinX)) + offZ);
        src += 3;
        dst += 0xA;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006A224.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Allocates one wake/ripple block (header, vertex/colour tables, texture) for a
// wake object. a1..a3 are f32 values passed as raw bits in integer registers.
// No direct DKR twin: DKR waves.c (waves_alloc) is the ocean system and uses a
// different layout, so it was only used as a pattern reference.
s32 wakeAllocate(s8 type, s32 a1, s32 a2, s32 a3, s32 a4, f32 scale) {
    f32 fa1;
    f32 fa2;
    f32 fa3;
    f32 f4;
    s32 nDist;
    s32 half;
    s32 count;
    s32 nStrips;
    s32 stride3;
    s32 stride1;
    s32 size;
    s32 base;
    s32 v0;
    s32 i;
    s32 j;
    s32 k;
    u8 *blk;
    u8 *p;
    TextureHeader *tex;

    fa1 = *(f32 *)&a1;
    fa2 = *(f32 *)&a2;
    fa3 = *(f32 *)&a3;

    nDist = (s32)(fa1 * 60.0f); // truncating cvt.w.s
    half = (nDist + 5) >> 1;
    count = half * 2;
    nStrips = (type == 0) ? 4 : 2;
    stride3 = count * 10; // == half * 0x14
    stride1 = count * 16; // == half * 0x20
    size = half * 0x24 + nStrips * stride3 + stride1 * 2 + 0x40;

    blk = (u8 *)((void *(*)(s32, u32))mmAlloc2)(size, 0xFFFF); /* sig mismatch */
    if (blk == NULL) {
        return 0;
    }

    // Table A at +0x28: two pointers into the block (from +0x40), stride1 apart.
    // asm always takes the 2-iteration path here, so no fallback is needed.
    for (i = 0; i < 2; i++) {
        *(s32 *)(blk + 0x28 + i * 4) = (s32)(blk + 0x40) + i * stride1;
    }
    base = *(s32 *)(blk + 0x2C) + stride1;
    *(s32 *)(blk + 0x10) = base;
    *(s32 *)(blk + 0x20) = 0;
    base += half * 0x10;
    *(s32 *)(blk + 0x14) = base;
    *(s32 *)(blk + 0x24) = 0;
    base += half * 0x14;

    // Table B at +0x18: nStrips pointers, stride3 apart.
    for (j = 0; j < nStrips; j++) {
        *(s32 *)(blk + 0x18 + j * 4) = base + j * stride3;
    }

    tex = texLoadTexture(a4);
    *(TextureHeader **)(blk + 0x30) = tex;
    if (tex == NULL) {
        mmFree(blk);
        return 0;
    }

    *(u8 *)(blk + 0x00) = (type != 0) ? 1 : 0;
    *(u8 *)(blk + 0x02) = 0;
    *(u8 *)(blk + 0x01) = (u8)half;
    *(s16 *)(blk + 0x08) = 0;
    *(f32 *)(blk + 0x04) = fa2;
    *(u8 *)(blk + 0x03) = (u8)nDist;

    v0 = nDist & 0xFF;
    *(s16 *)(blk + 0x0A) = (s16)(((tex->height - 1) << 8) / v0);
    f4 = (f32)v0;
    *(f32 *)(blk + 0x0C) = (fa3 - fa2) / f4;

    // Colour bytes (0xFF) of the vertices in each table-B row.
    for (j = 0; j < nStrips; j++) {
        p = (u8 *)*(s32 *)(blk + 0x18 + j * 4);
        for (k = 0; k < count; k++) {
            p[k * 10 + 6] = 0xFF;
            p[k * 10 + 7] = 0xFF;
            p[k * 10 + 8] = 0xFF;
        }
    }

    // Alpha bytes (0x40) for the two table-A rows.
    for (j = 0; j < 2; j++) {
        p = (u8 *)*(s32 *)(blk + 0x28 + j * 4);
        for (k = 0; k < count; k++) {
            p[k * 16] = 0x40;
        }
    }

    *(s16 *)(blk + 0x34) = 0;
    *(u8 *)(blk + 0x38) = 0;
    *(u8 *)(blk + 0x39) = 0;
    *(u8 *)(blk + 0x3A) = 0;
    *(u8 *)(blk + 0x3B) = 0;
    *(s16 *)(blk + 0x36) = (s16)(s32)((scale * 256.0f) / 60.0f);
    return (s32)blk;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeAllocate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 wakeSetupRipple(void *obj, s32 buf) {
    u8 *blk;
    u8 *v;
    void *def;
    TextureHeader *tex;
    s16 uMax;
    s16 vMax;
    s32 pad;
    s32 used;
    s32 i;

    // Align buf up to 8 bytes; pad is the number of bytes skipped.
    pad = 0;
    blk = (u8 *)buf;
    if ((buf & 7) != 0) {
        pad = 8 - (buf & 7);
        blk = (u8 *)(buf + pad);
    }
    used = pad + (s32)mmAlign4((u8 *)0x88);

    def = *(void **)((u8 *)obj + 0x40);
    *(u8 **)((u8 *)obj + 0x58) = blk;
    tex = texLoadTexture((s32)*(s16 *)((u8 *)def + 0x7C));
    *(TextureHeader **)(blk + 0x70) = tex;
    if (tex == NULL) {
        return 0;
    }

    uMax = (s16)((tex->width - 1) << 5);
    vMax = (s16)((tex->height - 1) << 5);

    // Two 0x10-byte quads of ripple vertex data (layout from asm).
    *(u8 *)(blk + 0x00) = 0x40;
    *(u8 *)(blk + 0x01) = 0;
    *(u8 *)(blk + 0x02) = 1;
    *(u8 *)(blk + 0x03) = 2;
    *(s16 *)(blk + 0x04) = uMax;
    *(s16 *)(blk + 0x06) = 0;
    *(s16 *)(blk + 0x08) = 0;
    *(s16 *)(blk + 0x0A) = 0;
    *(s16 *)(blk + 0x0C) = uMax;
    *(s16 *)(blk + 0x0E) = vMax;
    *(u8 *)(blk + 0x10) = 0x40;
    *(u8 *)(blk + 0x11) = 1;
    *(u8 *)(blk + 0x12) = 2;
    *(u8 *)(blk + 0x13) = 3;
    *(s16 *)(blk + 0x14) = 0;
    *(s16 *)(blk + 0x16) = 0;
    *(s16 *)(blk + 0x18) = uMax;
    *(s16 *)(blk + 0x1A) = vMax;
    *(s16 *)(blk + 0x1C) = 0;
    *(s16 *)(blk + 0x1E) = vMax;

    // Fill colour bytes (0xFF) of two 0x28-byte entries after the header.
    v = blk;
    for (i = 0; i < 2; i++) {
        v += 0x28;
        v[0x08] = 0xFF;
        v[0x09] = 0xFF;
        v[0x0A] = 0xFF;
        v[0x0B] = 0xFF;
        v[0x12] = 0xFF;
        v[0x13] = 0xFF;
        v[0x14] = 0xFF;
        v[0x15] = 0xFF;
        v[0x1C] = 0xFF;
        v[0x1D] = 0xFF;
        v[0x1E] = 0xFF;
        v[0x1F] = 0xFF;
        v[-2] = 0xFF;
        v[-1] = 0xFF;
        v[0x00] = 0xFF;
        v[0x01] = 0xFF;
    }

    *(u8 *)(blk + 0x74) = 0;
    *(u8 *)(blk + 0x75) = 0;
    *(s16 *)(blk + 0x76) = 0;
    *(s16 *)(blk + 0x78) = 0;
    *(s16 *)(blk + 0x7A) = *(s16 *)((u8 *)def + 0x7E);
    *(f32 *)(blk + 0x7C) = *(f32 *)((u8 *)def + 0x78);

    trackPolyHeight(*(f32 *)((u8 *)obj + 0x0C), *(f32 *)((u8 *)obj + 0x14), (f32 *)(blk + 0x80), 0x2000);
    *(s32 *)(blk + 0x84) = 0;
    if (*(s8 *)((u8 *)def + 0x73) != -1) {
        *(s32 *)(blk + 0x84) = wakeAllocate(*(s8 *)((u8 *)def + 0x73),
                                            *(s32 *)((u8 *)def + 0x88),
                                            *(s32 *)((u8 *)def + 0x80),
                                            *(s32 *)((u8 *)def + 0x84),
                                            (s32)*(s16 *)((u8 *)def + 0x8C),
                                            (f32)*(s16 *)((u8 *)def + 0x8E));
    }
    return used;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeSetupRipple.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void wakeFree(void *arg0) {
    void *tex = *(void **)((u8 *)arg0 + 0x30);

    if (tex != NULL) {
        texFreeTexture(tex);
    }
    mmFree(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void wakeFreeRipple(void *arg0) {
    u8 *st = (u8 *)arg0;
    void *tex = *(void **)(st + 0x70);
    void *child = *(void **)(st + 0x84);

    if (tex != NULL) {
        texFreeTexture(tex);
    }
    if (child != NULL) {
        wakeFree(child);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeFreeRipple.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void wakeUpdate(void *arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s32 arg5) {
    u8 *w = (u8 *)arg0;
    u8 *recs = *(u8 **)(w + 0x14);
    u8 *rec;
    u8 *outA;
    u8 *outB;
    u8 *outC;
    u8 *vB;
    u8 *entry;
    TextureHeader *tex;
    s32 emit = 0;
    s32 head;
    s32 idx;
    s32 k;
    s32 s6;
    s32 fp;
    s32 s7;
    s32 s5;
    s32 texW;
    s32 t2;
    s32 t7;
    s32 tmp;
    s32 pos;
    f32 sinv;
    f32 cosv;

    if (w[0x3B] != 0) {
        s6 = w[0x39];
        for (k = 0; k < w[0x3B]; k++) {
            rec = recs + s6 * 0x14;
            s6 += 1;
            if (s6 >= w[0x01]) {
                s6 = 0;
            }
            if (arg5 >= *(s32 *)rec) {
                w[0x39] = (u8)s6;
                w[0x3B] = (u8)(w[0x3B] - 1);
            } else {
                break;
            }
        }
    }

    head = w[0x39];
    rec = recs + head * 0x14;
    rec[1] |= 0x80;

    if (w[0x00] & 2) {
        if (*(s16 *)(w + 0x08) == 0) {
            emit = 1;
        }
        *(s16 *)(w + 0x08) = (s16)(*(s16 *)(w + 0x08) + 0x40);
        if (*(s16 *)(w + 0x08) >= 0x100) {
            *(s16 *)(w + 0x08) = 0xFF;
        }
        D_800A6950_A7550 = D_800A6950_A7550 + (arg5 * 0x10);
        if (D_800A6950_A7550 >= 0x100) {
            D_800A6950_A7550 = 0xFF;
        }
    } else {
        *(s16 *)(w + 0x08) = (s16)(*(s16 *)(w + 0x08) - 0x40);
        if (*(s16 *)(w + 0x08) < 0) {
            *(s16 *)(w + 0x08) = 0;
        }
        D_800A6950_A7550 = D_800A6950_A7550 - (arg5 * 0x10);
        if (D_800A6950_A7550 < 0) {
            D_800A6950_A7550 = 0;
        }
    }

    if ((*(s16 *)(w + 0x08) != 0) && ((s32)w[0x3B] < (s32)w[0x01])) {
        rec = recs + w[0x3A] * 0x14;
        rec[0] = w[0x03];
        rec[1] = (u8)(*(s16 *)(w + 0x08) >> 1);
        if (emit != 0) {
            rec[1] |= 0x80;
        }
        *(s16 *)(rec + 0x02) = arg4;
        tex = *(TextureHeader **)(w + 0x30);
        *(s16 *)(rec + 0x04) = (s16)((tex->height - 1) << 8);
        *(s16 *)(rec + 0x06) = (s16)(s32)arg2;
        *(f32 *)(rec + 0x08) = arg1;
        *(f32 *)(rec + 0x0C) = arg3;
        *(f32 *)(rec + 0x10) = *(f32 *)(w + 0x04);
        idx = w[0x3A] + 1;
        w[0x3A] = (u8)idx;
        if ((idx & 0xFF) >= w[0x01]) {
            w[0x3A] = 0;
        }
        w[0x3B] = (u8)(w[0x3B] + 1);
    }

    w[0x02] = (u8)(1 - w[0x02]);
    w[0x38] = 0;
    if (w[0x3B] != 0) {
        idx = w[0x02];
        outA = *(u8 **)(w + 0x18 + idx * 4);
        outB = *(u8 **)(w + 0x20 + idx * 4);
        outC = *(u8 **)(w + 0x28 + idx * 4);
        tex = *(TextureHeader **)(w + 0x30);
        texW = (tex->width - 1) << 5;
        fp = 0;
        s7 = 0;
        s5 = 0;

        s6 = w[0x39];
        if (s6 != w[0x3A]) {
            do {
                rec = recs + s6 * 0x14;
                s6 += 1;
                if (s6 >= w[0x01]) {
                    s6 = 0;
                }

                if (rec[1] & 0x80) {
                    s5 = 0;
                    entry = *(u8 **)(w + 0x10) + w[0x38] * 0x10;
                    *(s16 *)(entry + 0x0C) = (s16)fp;
                    *(s16 *)(entry + 0x0E) = (s16)s7;
                    w[0x38] = (u8)(w[0x38] + 1);
                    entry = *(u8 **)(w + 0x10) + w[0x38] * 0x10;
                    *(u8 **)(entry + 0x00) = outA;
                    *(u8 **)(entry + 0x04) = outB;
                    *(u8 **)(entry + 0x08) = outC;
                    s7 = 0;
                    fp = 0;
                }

                rec[0] = (u8)(rec[0] - arg5);
                *(f32 *)(rec + 0x10) = *(f32 *)(rec + 0x10) + (*(f32 *)(w + 0x0C) * (f32)arg5);
                *(s16 *)(rec + 0x04) = (s16)(*(s16 *)(rec + 0x04) - (*(s16 *)(w + 0x0A) * arg5));

                sinv = Sinf(*(s16 *)(rec + 0x02)) * *(f32 *)(rec + 0x10);
                cosv = Cosf(*(s16 *)(rec + 0x02)) * *(f32 *)(rec + 0x10);

                *(s16 *)(outA + 0x00) = (s16)(s32)(*(f32 *)(rec + 0x08) - cosv);
                *(s16 *)(outA + 0x02) = *(s16 *)(rec + 0x06);
                fp += 2;
                t2 = ((rec[1] & 0x7F) * D_800A6950_A7550) >> 7;
                *(s16 *)(outA + 0x04) = (s16)(s32)(*(f32 *)(rec + 0x0C) + sinv);
                outA[0x09] = (u8)t2;

                vB = outA + 0x0A;
                if (outB == NULL) {
                    *(s16 *)(vB + 0x00) = (s16)(s32)(*(f32 *)(rec + 0x08) + cosv);
                    *(s16 *)(vB + 0x04) = (s16)(s32)(*(f32 *)(rec + 0x0C) - sinv);
                } else {
                    outB += 0x14;
                    *(s16 *)(vB + 0x00) = (s16)(s32)*(f32 *)(rec + 0x08);
                    *(s16 *)(vB + 0x04) = (s16)(s32)*(f32 *)(rec + 0x0C);
                    *(s16 *)(outB - 0x14) = (s16)(s32)(*(f32 *)(rec + 0x08) + cosv);
                    *(s16 *)(outB - 0x12) = *(s16 *)(rec + 0x06);
                    outB[-0x0B] = (u8)t2;
                    *(s16 *)(outB - 0x10) = (s16)(s32)(*(f32 *)(rec + 0x0C) - sinv);
                    *(s16 *)(outB - 0x0A) = *(s16 *)(vB + 0x00);
                    *(s16 *)(outB - 0x08) = *(s16 *)(rec + 0x06);
                    outB[-0x01] = (u8)t2;
                    *(s16 *)(outB - 0x06) = *(s16 *)(vB + 0x04);
                }
                vB[0x09] = (u8)t2;
                *(s16 *)(vB + 0x02) = *(s16 *)(rec + 0x06);
                outA = vB + 0x0A;

                t7 = *(s16 *)(rec + 0x04) >> 3;
                if (s5 != 0) {
                    outC[0x03] = (u8)s5;
                    *(s16 *)(outC + 0x0C) = 0;
                    *(s16 *)(outC + 0x0E) = (s16)t7;
                    outC[0x12] = (u8)s5;
                    *(s16 *)(outC + 0x18) = 0;
                    *(s16 *)(outC + 0x1A) = (s16)t7;
                    outC[0x13] = (u8)(s5 + 1);
                    *(s16 *)(outC + 0x1C) = (s16)texW;
                    *(s16 *)(outC + 0x1E) = (s16)t7;
                    outC += 0x20;
                    s7 += 2;
                    if ((s5 + 2) >= 0x11) {
                        s5 = 0;
                    }
                }
                tmp = s5 + 1;
                outC[0x01] = (u8)s5;
                *(s16 *)(outC + 0x04) = 0;
                *(s16 *)(outC + 0x06) = (s16)t7;
                outC[0x02] = (u8)tmp;
                *(s16 *)(outC + 0x08) = (s16)texW;
                *(s16 *)(outC + 0x0A) = (s16)t7;
                outC[0x11] = (u8)tmp;
                *(s16 *)(outC + 0x14) = (s16)texW;
                *(s16 *)(outC + 0x16) = (s16)t7;
                s5 += 2;
            } while (s6 != w[0x3A]);
        }

        entry = *(u8 **)(w + 0x10) + w[0x38] * 0x10;
        *(s16 *)(entry + 0x0C) = (s16)fp;
        *(s16 *)(entry + 0x0E) = (s16)s7;
        w[0x38] = (u8)(w[0x38] + 1);

        *(s16 *)(w + 0x34) = (s16)(*(s16 *)(w + 0x34) + (*(s16 *)(w + 0x36) * arg5));
        tex = *(TextureHeader **)(w + 0x30);
        pos = *(s16 *)(w + 0x34);
        if (pos >= tex->numOfTextures) {
            do {
                pos -= tex->numOfTextures;
                *(s16 *)(w + 0x34) = (s16)pos;
            } while (pos >= tex->numOfTextures);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void wakeUpdateRipple(void *arg0, s32 arg1) {
    u8 *w = (u8 *)arg0;
    u8 *st;
    u8 *quad;
    s16 *v;
    TextureHeader *tex;
    void *child;
    s32 pos;
    s32 texCount;
    s32 idx;
    s16 angle;
    f32 half;
    f32 cx;
    f32 cz;
    f32 h;

    st = *(u8 **)(w + 0x58);
    if (st == NULL) {
        return;
    }

    if (st[0x75] != 0) {
        *(s16 *)(st + 0x76) = (s16)(*(s16 *)(st + 0x76) + 0x20);
        if (*(s16 *)(st + 0x76) >= 0x100) {
            *(s16 *)(st + 0x76) = 0xFF;
        }
    } else {
        *(s16 *)(st + 0x76) = (s16)(*(s16 *)(st + 0x76) - 0x20);
        if (*(s16 *)(st + 0x76) < 0) {
            *(s16 *)(st + 0x76) = 0;
        }
    }

    if (*(s16 *)(st + 0x7A) != 0) {
        tex = *(TextureHeader **)(st + 0x70);
        if (tex != NULL) {
            *(s16 *)(st + 0x78) = (s16)(*(s16 *)(st + 0x78) + (*(s16 *)(st + 0x7A) * arg1));
            texCount = tex->numOfTextures;
            pos = *(s16 *)(st + 0x78);
            if (pos >= texCount) {
                do {
                    pos -= texCount;
                    *(s16 *)(st + 0x78) = (s16)pos;
                } while (pos >= texCount);
            }
        }
    }

    if (*(s16 *)(st + 0x76) != 0) {
        idx = 1 - st[0x74];
        st[0x74] = (u8)idx;
        quad = st + (idx & 0xFF) * 0x28;
        h = *(f32 *)(st + 0x80);
        cx = *(f32 *)(w + 0x0C);
        cz = *(f32 *)(w + 0x14);
        half = *(f32 *)(st + 0x7C);

        v = (s16 *)(quad + 0x20);
        v[0] = (s16)(s32)(cx + half);
        v[1] = (s16)(s32)h;
        v[2] = (s16)(s32)(cz - half);
        v[5] = (s16)(s32)(cx - half);
        v[6] = (s16)(s32)h;
        v[7] = (s16)(s32)(cz - half);
        v[10] = (s16)(s32)(cx + half);
        v[11] = (s16)(s32)h;
        v[12] = (s16)(s32)(cz + half);
        v[15] = (s16)(s32)(cx - half);
        v[16] = (s16)(s32)h;
        v[17] = (s16)(s32)(cz + half);
    }

    child = *(void **)(st + 0x84);
    angle = (s16)Arctanf(*(f32 *)(w + 0x1C), *(f32 *)(w + 0x24));
    if (child != NULL) {
        wakeUpdate(child, *(f32 *)(w + 0x0C), *(f32 *)(st + 0x80), *(f32 *)(w + 0x14), angle, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeUpdateRipple.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void wakeDraw(void *arg0, Gfx **arg1) {
    u8 *st = (u8 *)arg0;
    Gfx *gfx;
    TextureHeader *tex;
    u8 *rec;
    s32 count;
    s32 shade;
    s32 i;
    s32 t1;
    s32 v;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 t4;
    s32 t5;
    s32 t7;
    s32 lo;
    s32 s1;
    s32 s3;
    s32 s4;
    s32 ra;

    count = st[0x38];
    if (count > 0) {
        tex = *(TextureHeader **)(st + 0x30);
        texDPTextureX(arg1, tex, 0x1F, *(s16 *)(st + 0x34) << 8);
        shade = ((tex->flags & 0x40) != 0) ? (*(s16 *)(st + 0x34) & 0xFF) : 0xFF;

        gfx = *arg1; *arg1 = gfx + 1;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = ((shade & 0xFF) << 24) | ((shade & 0xFF) << 16) | ((shade & 0xFF) << 8) | (shade & 0xFF);
        gfx = *arg1; *arg1 = gfx + 1;
        gfx->words.w0 = 0xFA000000;
        gfx->words.w1 = -1;

        for (i = 0; i < count; i++) {
            rec = *(u8 **)(st + 0x10) + i * 0x10;
            t1 = *(s16 *)(rec + 0x0E);
            s3 = *(s32 *)(rec + 0x00);
            s1 = *(s32 *)(rec + 0x04);
            s4 = *(s32 *)(rec + 0x08);
            if (t1 != 0) {
                do {
                    a3 = s3 + 0x80000000;
                    if (t1 >= 0x11) {
                        t1 -= 0x10;
                        v = 0x10;
                    } else {
                        v = t1;
                        t1 = 0;
                    }
                    a1 = v + 2;
                    a2 = a1 * 8;
                    t7 = ((a1 * 0xA) + 8) & 0xFFFF;
                    lo = v * 0xA;
                    t4 = v * 0x10;
                    t5 = ((((((v - 1) * 0x10) | 1) & 0xFF) << 16) | 0x05000000) | (t4 & 0xFFFF);
                    ra = s4 + 0x80000000;

                    gfx = *arg1; *arg1 = gfx + 1;
                    gfx->words.w0 = ((((a2 | (a3 & 6)) & 0xFF) << 16) | 0x04000000) | t7;
                    gfx->words.w1 = a3;
                    s3 += lo;

                    gfx = *arg1; *arg1 = gfx + 1;
                    gfx->words.w0 = t5;
                    gfx->words.w1 = ra;

                    if (s1 != 0) {
                        a0 = s1 + 0x80000000;
                        gfx = *arg1; *arg1 = gfx + 1;
                        gfx->words.w0 = ((((a2 | (a0 & 6)) & 0xFF) << 16) | 0x04000000) | t7;
                        gfx->words.w1 = a0;
                        s1 += lo;

                        gfx = *arg1; *arg1 = gfx + 1;
                        gfx->words.w0 = t5;
                        gfx->words.w1 = ra;
                    }
                    s4 += t4;
                } while (t1 != 0);
            }
        }

        if (shade != 0xFF) {
            gfx = *arg1; *arg1 = gfx + 1;
            gfx->words.w1 = 0;
            gfx->words.w0 = 0xE7000000;
            gfx = *arg1; *arg1 = gfx + 1;
            gfx->words.w1 = -1;
            gfx->words.w0 = 0xFB000000;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void wakeDrawRipple(void *arg0, Gfx **arg1) {
    u8 *st = (u8 *)arg0;
    Gfx *gfx;
    TextureHeader *tex;
    void *child;
    s32 shade;
    s32 vaddr;

    if (st != NULL) {
        tex = *(TextureHeader **)(st + 0x70);
        if (tex != NULL) {
            if (*(s16 *)(st + 0x76) != 0) {
                texDPTextureX(arg1, tex, 0xF, *(s16 *)(st + 0x78) << 8);
                gfx = *arg1; *arg1 = gfx + 1;
                gfx->words.w0 = 0x07020010;
                gfx->words.w1 = (u32)D_A6958;

                shade = 0xFF;
                if (tex->flags & 0x40) {
                    shade = *(s16 *)(st + 0x78) & 0xFF;
                }
                gfx = *arg1; *arg1 = gfx + 1;
                gfx->words.w0 = 0xFA000000;
                gfx->words.w1 = ((((0xFF - (D_800A6950_A7550 >> 1)) * *(s16 *)(st + 0x76)) >> 8) & 0xFF) | ~0xFF;
                gfx = *arg1; *arg1 = gfx + 1;
                gfx->words.w0 = 0xFB000000;
                gfx->words.w1 = ((shade & 0xFF) << 24) | ((shade & 0xFF) << 16) | ((shade & 0xFF) << 8) | (shade & 0xFF);

                vaddr = (s32)(st + (st[0x74] * 0x28)) + 0x80000020;
                gfx = *arg1; *arg1 = gfx + 1;
                gfx->words.w0 = ((((vaddr & 6) | 0x20) & 0xFF) << 16) | 0x04000000 | 0x30;
                gfx->words.w1 = vaddr;
                gfx = *arg1; *arg1 = gfx + 1;
                gfx->words.w0 = 0x05110020;
                gfx->words.w1 = (s32)st + 0x80000000;
                texDPInit(arg1);
            }

            child = *(void **)(st + 0x84);
            if (child != NULL) {
                wakeDraw(child, arg1);
            }

            gfx = *arg1; *arg1 = gfx + 1;
            gfx->words.w1 = 0;
            gfx->words.w0 = 0xE7000000;
            gfx = *arg1; *arg1 = gfx + 1;
            gfx->words.w0 = 0xFA000000;
            gfx->words.w1 = -1;
            gfx = *arg1; *arg1 = gfx + 1;
            gfx->words.w1 = -1;
            gfx->words.w0 = 0xFB000000;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/wakeDrawRipple.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxInit(void) {
    u8 *base;

    base = (u8 *)mmAlloc(0x580, 0xFFFF00FF);
    *(u8 **)(D_800A67AC_A73AC + 0x0) = base;
    D_800A67B0_A73B0 = base + 0x100;
    *(s32 *)(D_800A67A4_A73A4 + 0x0) = *(s32 *)(D_800A67AC_A73AC + 0x4) + 0x100;
    *(s32 *)(D_800A67A4_A73A4 + 0x4) = *(s32 *)(D_800A67A4_A73A4 + 0x0) + 0xA0; /* asm: stores D_800A67A8 */
    D_80102DB0_B1DA0 = *(s32 *)(D_800A67A4_A73A4 + 0x4) + 0xA0;
    D_80102DB4_B1DA4 = D_80102DB0_B1DA0 + 0xC0;
    D_80102DB8_B1DA8 = D_80102DB4_B1DA4 + 0xC0;
    func_8006FFF8(D_800A67A4_A73A4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void disableClearScreen(void) {
    D_800A6780_A7380 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/disableClearScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void enableClearScreen(void) {
    D_800A6780_A7380 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/enableClearScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 fxFadeOn(void) {
    if ((D_800A6784_A7384 != 0) && ((D_800A6794_A7394 != 0) || ((D_800A6798_A7398 != 0) && (D_800A67A0_A73A0 != 0)))) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxFadeOn.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 setupClearScreen(void *arg0) {
    u8 *cfg;

    if (D_800A6780_A7380 != 0) {
        return 0;
    }
    func_8006C1B8();
    D_800A6784_A7384 = 1;
    if (arg0 == NULL) {
        return 0;
    }
    cfg = (u8 *) arg0;
    D_800A6794_A7394 = *(u16 *) (cfg + 4);
    D_800A679C_A739C = *(u16 *) (cfg + 4);
    D_800A6798_A7398 = *(u16 *) (cfg + 6);
    D_800A67A0_A73A0 = (cfg[0] & 0x80) == 0;
    D_80102D38_B1D28 = cfg[0] & 0x3F;
    D_800A678C_A738C = cfg[0] & 0x40;
    D_800A6788_A7388 = 0;
    if (D_800A67A0_A73A0 == 0) {
        D_800A6788_A7388 = 2;
    }
    if ((s32) D_800A6794_A7394 > 0) {
        D_80102D8C_B1D7C = (s32) D_80102D50_B1D40;
        D_80102D90_B1D80 = (s32) D_80102D58_B1D48;
        D_80102D94_B1D84 = (s32) D_80102D70_B1D60;
        D_80102D50_B1D40 = cfg[1];
        D_80102D58_B1D48 = cfg[2];
        D_80102D70_B1D60 = cfg[3];
        switch (D_80102D38_B1D28) {
        case 0:
            func_8006C1CC(arg0, &D_80102D70_B1D60, &D_800A6794_A7394, &D_80102D38_B1D28);
            break;
        case 1:
            func_8006C560(arg0, 0xC, 8, D_800A6810_A7410, D_800A6880_A7480, D_800A688C_A748C, D_800A68B0_A74B0, D_800A68B0_A74B0, D_800A6898_A7498);
            break;
        case 2:
            func_8006C560(arg0, 0xC, 8, D_800A6848_A7448, D_800A6880_A7480, D_800A688C_A748C, D_800A68B0_A74B0, D_800A68B0_A74B0, D_800A6898_A7498);
            break;
        case 3:
        case 4:
        case 5:
            func_8006C560(arg0, 0xA, 6, D_800A68BC_A74BC, D_800A68EC_A74EC, D_800A68F8_A74F8, D_800A6918_A7518, D_800A6918_A7518, D_800A6904_A7504);
            break;
        case 6:
            func_8006D048(arg0, &D_80102D70_B1D60, &D_800A6794_A7394, &D_80102D38_B1D28);
            break;
        }
    }
    return D_800A6790_A7390;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/setupClearScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 updateClearScreen(s32 arg0) {
    s32 steps;

    steps = arg0;
    if (D_800A6788_A7388 != 0) {
        D_800A6788_A7388 -= 1;
        steps = 0;
    } else if (steps >= 6) {
        steps = 5;
    }
    if (D_800A6790_A7390 != 0) {
        if (D_800A6794_A7394 == 0) {
            D_800A6790_A7390 = -1;
        }
        if ((D_800A6794_A7394 == 0) && (D_800A6798_A7398 == 0)) {
            func_8006C1B8(steps);
        } else {
            if ((s32) D_800A6794_A7394 > 0) {
                D_800A67B4_A73B4 = 1 - D_800A67B4_A73B4;
            }
            switch (D_80102D38_B1D28) {
            case 0:
                func_8006C280(steps);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                func_8006CAAC(steps);
                break;
            case 6:
                func_8006D1A8(steps);
                break;
            }
        }
    }
    return D_800A6790_A7390;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/updateClearScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void drawClearScreen(Gfx **dlist, void **mtxp, void **vtxp) {
    if (D_800A6790_A7390 != 0) {
        if (osTvType == 0) {
            camOrthoYAspect(1.4f);
        } else {
            camOrthoYAspect(1.2f);
        }
        camStandardOrtho(dlist, mtxp, vtxp);
        camOrthoYAspect(1.0f);
        switch (D_80102D38_B1D28) {
        case 0:
            func_8006C454(dlist, mtxp, vtxp);
            break;
        case 1:
            func_8006CD60(dlist, mtxp, vtxp);
            break;
        case 2:
            func_8006CE58(dlist, mtxp, vtxp);
            break;
        case 3:
        case 4:
        case 5:
            func_8006CF50(dlist, mtxp, vtxp);
            break;
        case 6:
            func_8006D2F0(dlist, mtxp, vtxp);
            break;
        }
        camSetView(dlist, mtxp);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/drawClearScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006C1B8(void) {
    D_800A6790_A7390 = 0;
    D_800A67B4_A73B4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006C1B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006C1CC(u8 *arg0, u8 *arg1, u16 *arg2, u32 *arg3) {
    f32 step;

    if (*arg0 & 0x80) {
        D_80102DA8_B1D98 = 255.0f;
        step = -255.0f / (f32) D_800A6794_A7394;
    } else {
        D_80102DA8_B1D98 = 0.0f;
        step = 255.0f / (f32) D_800A6794_A7394;
    }
    D_80102DAC_B1D9C = step;
    D_800A6790_A7390 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006C1CC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006C280(s32 arg0) {
    s32 remaining;
    s32 cont;

    remaining = arg0;
    do {
        cont = 1;
        if ((s32) D_800A6794_A7394 > 0) {
            if (remaining < (s32) D_800A6794_A7394) {
                D_800A6794_A7394 -= remaining;
                D_80102DA8_B1D98 += D_80102DAC_B1D9C * (f32) remaining;
            } else {
                remaining -= D_800A6794_A7394;
                cont = 0;
                if (D_80102DAC_B1D9C < 0.0f) {
                    D_80102DA8_B1D98 = 0.0f;
                } else {
                    D_80102DA8_B1D98 = 255.0f;
                }
                D_800A6794_A7394 = 0;
            }
            if (D_80102DA8_B1D98 < 0.0f) {
                D_80102DA8_B1D98 = 0.0f;
            } else if (D_80102DA8_B1D98 > 255.0f) {
                D_80102DA8_B1D98 = 255.0f;
            }
            D_80102D88_B1D78 = (u8) (s32) D_80102DA8_B1D98;
        } else if (D_800A6798_A7398 != 0xFFFF) {
            if (remaining < (s32) D_800A6798_A7398) {
                D_800A6798_A7398 -= remaining;
            } else {
                remaining -= D_800A6798_A7398;
                D_800A6798_A7398 = 0;
                if (D_800A678C_A738C != 0) {
                    D_800A678C_A738C = 0;
                    D_80102DAC_B1D9C = -D_80102DAC_B1D9C;
                    cont = 0;
                    D_800A6794_A7394 = D_800A679C_A739C;
                }
            }
        }
    } while ((cont == 0) && (remaining > 0));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006C280.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006C454(Gfx **dlist, void **mtxp, void **vtxp) {
    s32 width;
    s32 height;
    Gfx *g;

    viGetCurrentSize(&width, &height);
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x06000000;
    g->words.w1 = (u32) D_800A67B8_A73B8;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0xFA000000;
    g->words.w1 = ((u32) D_80102D50_B1D40 << 24) | ((u32) D_80102D58_B1D48 << 16) | ((u32) D_80102D70_B1D60 << 8) | D_80102D88_B1D78;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0xFCFFFFFF;
    g->words.w1 = 0xFFFDF6FB;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = (((u32) width & 0x3FF) << 0xE) | 0xF6000000 | (((u32) height & 0x3FF) * 4);
    g->words.w1 = 0;
    texDPInit(dlist);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006C454.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006C560(u8 *arg0, s32 arg1, s32 arg2, void *arg3, u8 *arg4, u8 *arg5, u8 *arg6, u8 *arg7, u8 *arg8) {
    f32 scaleX;
    f32 scaleY;
    f32 invLen;
    s16 *pts;
    u8 *tmp;
    u8 *slot;
    u8 *e;
    u8 *c;
    f32 *v0;
    f32 *v4;
    f32 *v8;
    s16 *pa;
    s16 *pb;
    s32 i;
    s32 k;

    viGetScaleXY(&scaleX, &scaleY);
    if (*arg0 & 0x80) {
        tmp = arg4;
        arg4 = arg5;
        arg5 = tmp;
        tmp = arg6;
        arg6 = arg7;
        arg7 = tmp;
    }
    invLen = 1.0f / (f32) D_800A6794_A7394;
    pts = (s16 *) arg3;
    for (i = 0; i < arg1; i++) {
        pa = pts + arg4[i] * 2;
        pb = pts + arg5[i] * 2;
        v0 = (f32 *) ((u8 *) D_80102DB0_B1DA0 + i * 0xC);
        v8 = (f32 *) ((u8 *) D_80102DB8_B1DA8 + i * 0xC);
        v4 = (f32 *) ((u8 *) D_80102DB4_B1DA4 + i * 0xC);
        v0[0] = (f32) pa[0] * scaleX;
        v0[1] = (f32) pa[1] * scaleY;
        v0[2] = (f32) arg6[i];
        v8[0] = (f32) pb[0] * scaleX;
        v8[1] = (f32) pb[1] * scaleY;
        v8[2] = (f32) arg7[i];
        v4[0] = (v8[0] - v0[0]) * invLen;
        v4[1] = (v8[1] - v0[1]) * invLen;
        v4[2] = (v8[2] - v0[2]) * invLen;
    }

    for (k = 0; k < 2; k++) {
        slot = *(u8 **) (D_800A67A4_A73A4 + k * 4);
        if (arg1 > 0) {
            for (i = 0; i < arg1; i++) {
                e = slot + i * 0xA;
                *(s16 *) (e + 4) = -0x10;
                e[6] = D_80102D50_B1D40;
                e[7] = D_80102D58_B1D48;
                e[8] = D_80102D70_B1D60;
            }
        }
    }

    for (k = 0; k < 2; k++) {
        if (arg2 > 0) {
            slot = *(u8 **) (D_800A67AC_A73AC + k * 4);
            c = arg8;
            for (i = 0; i < arg2; i++) {
                e = slot + i * 0x10;
                e[0] = 0x40;
                e[1] = c[0];
                e[2] = c[1];
                e[3] = c[2];
                c += 3;
                *(s16 *) (e + 4) = 0;
                *(s16 *) (e + 6) = 0;
                *(s16 *) (e + 8) = 0;
                *(s16 *) (e + 0xA) = 0;
                *(s16 *) (e + 0xC) = 0;
                *(s16 *) (e + 0xE) = 0;
            }
        }
    }
    D_800A6790_A7390 = 1;
    D_80102DBC_B1DAC = arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006C560.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006CAAC(s32 arg0) {
    s32 i;
    f32 t;
    f32 *a;
    f32 *b;
    u8 *slot;
    u8 *e;

    t = (f32) arg0;
    if ((s32) D_800A6794_A7394 > 0) {
        if (arg0 < (s32) D_800A6794_A7394) {
            for (i = 0; i < D_80102DBC_B1DAC; i++) {
                a = (f32 *) ((u8 *) D_80102DB0_B1DA0 + i * 0xC);
                b = (f32 *) ((u8 *) D_80102DB4_B1DA4 + i * 0xC);
                a[0] += t * b[0];
                a[1] += t * b[1];
                a[2] += t * b[2];
            }
            D_800A6794_A7394 -= arg0;
        } else {
            for (i = 0; i < D_80102DBC_B1DAC; i++) {
                a = (f32 *) ((u8 *) D_80102DB0_B1DA0 + i * 0xC);
                b = (f32 *) ((u8 *) D_80102DB8_B1DA8 + i * 0xC);
                a[0] = b[0];
                a[1] = b[1];
                a[2] = b[2];
            }
            D_800A6794_A7394 = 0;
        }
        slot = *(u8 **) (D_800A67A4_A73A4 + D_800A67B4_A73B4 * 4);
        for (i = 0; i < D_80102DBC_B1DAC; i++) {
            a = (f32 *) ((u8 *) D_80102DB0_B1DA0 + i * 0xC);
            e = slot + i * 0xA;
            *(s16 *) (e + 0) = (s16) (s32) a[0];
            *(s16 *) (e + 2) = (s16) (s32) a[1];
            e[9] = (u8) (s32) a[2];
        }
    } else if (D_800A6798_A7398 != 0xFFFF) {
        if (arg0 < (s32) D_800A6798_A7398) {
            D_800A6798_A7398 -= arg0;
            return;
        }
        D_800A6798_A7398 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006CAAC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006CD60(Gfx **dlist, void **mtxp, void **vtxp) {
    u8 *slot;
    u32 addr;
    Gfx *g;

    texDPInit(dlist);
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x06000000;
    g->words.w1 = (u32) D_800A6928_A7528;
    slot = *(u8 **) (D_800A67A4_A73A4 + D_800A67B4_A73B4 * 4);
    addr = (u32) slot + 0x80000000;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = ((((addr & 6) | 0x60) & 0xFF) << 0x10) | 0x04000000 | 0x80;
    g->words.w1 = addr;
    addr = (u32) *(u8 **) (D_800A67AC_A73AC + D_800A67B4_A73B4 * 4) + 0x80000000;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x05700080;
    g->words.w1 = addr;
    texDPInit(dlist);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006CD60.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006CE58(Gfx **dlist, void **mtxp, void **vtxp) {
    u8 *slot;
    u32 addr;
    Gfx *g;

    texDPInit(dlist);
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x06000000;
    g->words.w1 = (u32) D_800A6928_A7528;
    slot = *(u8 **) (D_800A67A4_A73A4 + D_800A67B4_A73B4 * 4);
    addr = (u32) slot + 0x80000000;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = ((((addr & 6) | 0x60) & 0xFF) << 0x10) | 0x04000000 | 0x80;
    g->words.w1 = addr;
    addr = (u32) *(u8 **) (D_800A67AC_A73AC + D_800A67B4_A73B4 * 4) + 0x80000000;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x05700080;
    g->words.w1 = addr;
    texDPInit(dlist);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006CE58.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006CF50(Gfx **dlist, void **mtxp, void **vtxp) {
    u8 *slot;
    u32 addr;
    Gfx *g;

    texDPInit(dlist);
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x06000000;
    g->words.w1 = (u32) D_800A6928_A7528;
    slot = *(u8 **) (D_800A67A4_A73A4 + D_800A67B4_A73B4 * 4);
    addr = (u32) slot + 0x80000000;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = ((((addr & 6) | 0x50) & 0xFF) << 0x10) | 0x04000000 | 0x6C;
    g->words.w1 = addr;
    addr = (u32) *(u8 **) (D_800A67AC_A73AC + D_800A67B4_A73B4 * 4) + 0x80000000;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x05500060;
    g->words.w1 = addr;
    texDPInit(dlist);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006CF50.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006D048(void *arg0, u8 *arg1, u16 *arg2, u32 *arg3) {
    D_80102D8C_B1D7C <<= 0x10;
    D_80102D90_B1D80 <<= 0x10;
    D_80102D94_B1D84 <<= 0x10;
    D_80102D88_B1D78 = 0xFF;
    D_80102DA8_B1D98 = 255.0f;
    D_80102DAC_B1D9C = 0.0f;
    D_80102D98_B1D88 = ((s32) (D_80102D50_B1D40 << 0x10) - D_80102D8C_B1D7C) / (s32) D_800A6794_A7394;
    D_80102DA0_B1D90 = ((s32) (D_80102D58_B1D48 << 0x10) - D_80102D90_B1D80) / (s32) D_800A6794_A7394;
    D_80102DA4_B1D94 = ((s32) (D_80102D70_B1D60 << 0x10) - D_80102D94_B1D84) / (s32) D_800A6794_A7394;
    D_800A6790_A7390 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006D048.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006D1A8(s32 arg0) {
    s32 remaining;
    u16 left;

    remaining = arg0;
    if ((s32) D_800A6794_A7394 > 0) {
        D_80102D8C_B1D7C += D_80102D98_B1D88 * remaining;
        D_80102D90_B1D80 += D_80102DA0_B1D90 * remaining;
        D_80102D94_B1D84 += D_80102DA4_B1D94 * remaining;
        if (remaining >= (s32) D_800A6794_A7394) {
            D_80102D8C_B1D7C = D_80102D50_B1D40 << 0x10;
            D_80102D90_B1D80 = D_80102D58_B1D48 << 0x10;
            D_80102D94_B1D84 = D_80102D70_B1D60 << 0x10;
            remaining -= D_800A6794_A7394;
            D_800A6794_A7394 = 0;
        } else {
            D_800A6794_A7394 -= remaining;
        }
    } else {
        left = D_800A6798_A7398 - remaining;
        if (D_800A6798_A7398 != 0xFFFF) {
            D_800A6798_A7398 = left;
            if (left == 0) {
                D_800A6798_A7398 = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006D1A8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006D2F0(Gfx **dlist, void **mtxp, void **vtxp) {
    s32 width;
    s32 height;
    Gfx *g;

    viGetCurrentSize(&width, &height);
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0x06000000;
    g->words.w1 = (u32) D_800A67B8_A73B8;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0xFA000000;
    g->words.w1 = ((u32) (D_80102D8C_B1D7C >> 0x10) << 0x18) | (((u32) (D_80102D90_B1D80 >> 0x10) & 0xFF) << 0x10) | (((u32) (D_80102D94_B1D84 >> 0x10) & 0xFF) << 8) | 0xFF;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = 0xFCFFFFFF;
    g->words.w1 = 0xFFFDF6FB;
    g = *dlist;
    *dlist = g + 1;
    g->words.w0 = (((u32) width & 0x3FF) << 0xE) | 0xF6000000 | (((u32) height & 0x3FF) * 4);
    g->words.w1 = 0;
    texDPInit(dlist);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006D2F0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxInitLines(void) {
    D_80103B80_B2B70[0] = 0;
    D_80103B80_B2B70[1] = 0;
    D_80103B88_B2B78[0] = 0;
    D_80103B88_B2B78[1] = 0;
    D_80103B90_B2B80 = 0;
    D_80103B94_B2B84 = -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxInitLines.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8006D110_6DD10(s16 *x0p, s16 *y0p, s16 *x1p, s16 *y1p, s32 xmin, s32 ymin, s32 xmax, s32 ymax) {
    s32 flipped;
    s32 xl, yl, xr, yr, xa, ya, xb, yb, dx, dy;

    if (*x1p >= *x0p) {
        xl = *x0p; yl = *y0p; xr = *x1p; yr = *y1p; flipped = 0;
    } else {
        xl = *x1p; yl = *y1p; xr = *x0p; yr = *y0p; flipped = 1;
    }
    if (xr < xmin || xmax < xl) {
        return 0;
    }
    dx = xr - xl;
    if (xl != xr) {
        dy = yr - yl;
        if (xmax < xr) {
            yr = ((xmax - xl) * dy) / dx + yl;
            xr = xmax;
        }
        if (xl < xmin) {
            yl += ((xmin - xl) * dy) / dx;
            xl = xmin;
        }
    }
    if (yr < yl) {
        xa = xr; ya = yr; xb = xl; yb = yl;
        flipped ^= 1;
    } else {
        xa = xl; ya = yl; xb = xr; yb = yr;
    }
    if (yb < ymin || ymax < ya) {
        return 0;
    }
    dx = xb - xa;
    if (ya != yb) {
        dy = yb - ya;
        if (ymax < yb) {
            xb = ((ymax - ya) * dx) / dy + xa;
            yb = ymax;
        }
        if (ya < ymin) {
            xa += ((ymin - ya) * dx) / dy;
            ya = ymin;
        }
    }
    if (flipped != 0) {
        *x0p = xb; *y0p = yb; *x1p = xa; *y1p = ya;
    } else {
        *x0p = xa; *y0p = ya; *x1p = xb; *y1p = yb;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006D110_6DD10.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawLine(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    s32 left, top, right, bottom;
    s32 xmin, ymin, xmax, ymax;
    s32 buf, count, type, hi;
    s16 tmp;
    FxLine *e;
    u32 a2;

    buf = D_80103B90_B2B80;
    count = D_80103B80_B2B70[buf];
    if (count >= 0x94) {
        return;
    }
    if (D_80103B94_B2B84 != -1) {
        frontPlayerScreenLimits(D_80103B94_B2B84, &left, &top, &right, &bottom);
        xmin = left + 1;
        ymin = top + 1;
        xmax = right - 2;
        ymax = bottom - 2;
    } else {
        viGetCurrentSize(&right, &bottom);
        xmin = 1;
        ymin = 1;
        xmax = right - 2;
        ymax = bottom - 2;
    }
    if (func_8006D110_6DD10(&arg0, &arg1, &arg2, &arg3, xmin, ymin, xmax, ymax) == 0) {
        return;
    }
    if (arg0 == arg2 && arg1 == arg3) {
        return;
    }
    type = arg4 & 0xF;
    if (type != 0xC && type != 0xD && type != 2) {
        if (arg2 < arg0) {
            tmp = arg0; arg0 = arg2; arg2 = tmp;
        }
        if (arg3 < arg1) {
            tmp = arg1; arg1 = arg3; arg3 = tmp;
        }
    }

    D_80103B80_B2B70[buf] = count + 1;
    e = &D_80102DC0_B1DB0[buf][count];
    e->x0 = arg0;
    hi = (arg1 * 0x10) | ((e->packed >> 16) & 0xF);
    e->packed = (e->packed & 0xFFFF) | (s32)(((u32)hi & 0xFFFF) << 16);
    a2 = (u32)(s32)(s16)(e->packed >> 16);
    e->x1 = arg2;
    e->packed = (s32)(((((u32)arg3 ^ (a2 >> 8)) << 20) >> 12) ^ a2);
    e->packed = (e->packed & ~0xFF) | arg4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxDrawLine.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawLineInWindow(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, s32 arg5) {
    s32 saved = D_80103B94_B2B84;

    D_80103B94_B2B84 = arg5;
    fxDrawLine(arg0, arg1, arg2, arg3, arg4);
    D_80103B94_B2B84 = saved;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxDrawLineInWindow.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxSetClipWindow(s32 arg0) {
    D_80103B94_B2B84 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxSetClipWindow.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxTinyPrint(s16 arg0, s16 arg1, u8 *arg2) {
    s32 width, height;
    s32 buf, count, i;
    FxText *e;

    if (multiPlayerGame != 0) {
        return;
    }
    viGetCurrentSize(&width, &height);
    if (arg0 <= 0 || width - 6 < arg0 || arg1 <= 0) {
        return;
    }
    if (height - 6 < arg1) {
        return;
    }
    buf = D_80103B90_B2B80;
    count = D_80103B88_B2B78[buf];
    if (count >= 0x10) {
        return;
    }
    D_80103B88_B2B78[buf] = count + 1;
    e = &sniperStructs[buf][count];
    e->x = arg0;
    e->y = arg1;
    for (i = 0; i < 0x1F; i++) {
        e->text[i] = arg2[i];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxTinyPrint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxInttostr(s8 *arg0, s32 arg1, s32 arg2) {
    s8 *dst = arg0;
    s32 value = arg1;
    s32 divisor = 1000000;
    s32 started = 0;
    s32 digit;

    if (value < 0) {
        value = -value;
        *dst++ = '-';
    }
    do {
        digit = value / divisor;
        value = value % divisor;
        if (digit != 0 || started != 0 || divisor == 100) {
            *dst++ = (s8)(digit + '0');
            started = 1;
        }
        divisor /= 10;
        if (divisor == 10) {
            if (arg2 != 0) {
                *dst++ = '.';
            } else {
                divisor = 0;
            }
        }
    } while (divisor != 0);
    *dst = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxInttostr.s")
#endif

#ifdef VERSION_kiosk
#pragma GLOBAL_ASM("asm/nonmatchings/fx/ClipPoint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawLine3D(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1, u8 colour) {
    f32 sx, sy;
    s16 px0, py0, px1, py1;
    s32 width, height, buf, count, hi;
    FxLine *e;
    u32 a2;

    buf = D_80103B90_B2B80;
    count = D_80103B80_B2B70[buf];
    if (count >= 0x94) {
        return;
    }
    if (camProjectPoint(x0, y0, z0, &sx, &sy, 1) == 0) {
        return;
    }
    px0 = (s16) sx;
    py0 = (s16) sy;
    if (camProjectPoint(x1, y1, z1, &sx, &sy, 1) == 0) {
        return;
    }
    px1 = (s16) sx;
    py1 = (s16) sy;
    viGetCurrentSize(&width, &height);
    if (func_8006D110_6DD10(&px0, &py0, &px1, &py1, 1, 1, width - 2, height - 2) == 0) {
        return;
    }
    if (px0 == px1 && py0 == py1) {
        return;
    }

    D_80103B80_B2B70[buf] = count + 1;
    e = &D_80102DC0_B1DB0[buf][count];
    e->x0 = px0;
    hi = (py0 * 0x10) | ((e->packed >> 16) & 0xF);
    e->packed = (e->packed & 0xFFFF) | (s32)(((u32)hi & 0xFFFF) << 16);
    a2 = (u32)(s32)(s16)(e->packed >> 16);
    e->x1 = px1;
    e->packed = (s32)(((((u32)py1 ^ (a2 >> 8)) << 20) >> 12) ^ a2);
    e->packed = (e->packed & ~0xFF) | colour;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxDrawLine3D.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void PlotAddRGB(u16 *arg0, s8 arg1, s8 arg2, s8 arg3) {
    s32 r = (((s32) *arg0 >> 11) & 0x1F) + arg1;
    s32 g = (((s32) *arg0 >> 6) & 0x1F) + arg2;
    s32 b = (((s32) *arg0 >> 1) & 0x1F) + arg3;

    if (r >= 0x20) r = 0x1F;
    if (g >= 0x20) g = 0x1F;
    if (b >= 0x20) b = 0x1F;
    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;
    *arg0 = (r << 11) | (g << 6) | (b * 2) | 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/PlotAddRGB.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void PlotAddRG(u16 *arg0, s32 arg1, s32 arg2) {
    s32 r = (((s32) *arg0 >> 11) & 0x1F) + (arg1 & 0xFF);
    s32 g = (((s32) *arg0 >> 6) & 0x1F) + (arg2 & 0xFF);
    s32 b = ((s32) *arg0 >> 1) & 0x1F;

    if (r >= 0x20) r = 0x1F;
    if (g >= 0x20) g = 0x1F;
    *arg0 = (r << 11) | (g << 6) | (b * 2) | 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/PlotAddRG.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006E1D8(u16 *screen, s32 x0, s32 y0, s32 x1, s32 y1, s32 steep) {
    s32 width, height, count, step, i, off, tmp;
    u16 *p;
    u16 v, sum;

    viGetCurrentSize(&width, &height);
    if ((steep != 0) ? (y1 < y0) : (x1 < x0)) {
        tmp = x0; x0 = x1; x1 = tmp;
        tmp = y0; y0 = y1; y1 = tmp;
    }
    p = screen + (y0 * width + x0);
    if (steep == 0) {
        count = x1 - x0 + 1;
        step = 1;
        off = width;
        if (y0 < y1) {
            step = width + 1;
        }
        if (y1 < y0) {
            step -= width;
        }
    } else {
        count = y1 - y0 + 1;
        step = width;
        off = 1;
        if (x0 < x1) {
            step += 1;
        }
        if (x1 < x0) {
            step -= 1;
        }
    }
    /* each sample brightens green by 8 (saturating at max green), in two pixels */
    for (i = 0; i < count; i++) {
        v = p[0];
        sum = (v & 0x7C0) + 0x200;
        if (sum & 0xF800) {
            sum = 0x7C0;
        }
        p[0] = (v & ~0x7C0) | sum;

        v = p[off];
        sum = (v & 0x7C0) + 0x200;
        if (sum & 0xF800) {
            sum = 0x7C0;
        }
        p[off] = (v & ~0x7C0) | sum;
        p += step;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006E1D8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006E38C(u16 *screen, s32 glyph, s32 x, s32 y, s32 red) {
    s32 width, height, mask, shift, amt, i, code;
    u32 bits;
    u16 *p;
    s32 *row;
    u16 px;
    s32 sum;

    viGetCurrentSize(&width, &height);
    mask = 0x7C0;
    shift = 6;
    if (red != 0) {
        mask = 0xF800;
        shift = 11;
    }
    p = screen + (y * width + x);
    for (row = D_800A6B64_A7764; row != (s32 *) D_800A6BA8_A77A8; row++) {
        bits = (u32) *row;
        /* 9 pixels per row, one 3-bit code each */
        for (i = 0; i < 9; i++) {
            code = bits & 7;
            bits >>= 3;
            if (code != 0) {
                amt = 4;
                if (glyph & (1 << code)) {
                    amt = 0x10;
                }
                px = p[i];
                sum = (px & mask) + (amt << shift);
                if (~mask & sum) {
                    sum = mask;
                }
                p[i] = (px & ~mask) | sum;
            }
        }
        p += width;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006E38C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006E5FC(s32 x, s32 y, s32 value, s32 width, s32 red) {
    char buf[16];
    s32 len = 0;
    s32 n;
    char *s;
    u8 glyph;
    u8 c;

    sprintf(buf, "%d", value);
    for (s = buf; *s != 0; s++) {
        len++;
    }
    if (width >= len) {
        n = len;
        s = buf;
        do {
            glyph = D_800A6BA8_A77A8[0xB];
            if (n < width) {
                n++;
            } else {
                c = (u8) *s;
                s++;
                if (c == '-') {
                    glyph = D_800A6BA8_A77A8[0xA];
                } else if (c >= '0' && c <= '9') {
                    glyph = D_800A6BA8_A77A8[c - '0'];
                }
            }
            func_8006E38C((u16 *) currentScreen, glyph, x, y, red);
            x += 10;
        } while (*s != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006E5FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawDigitalNumber(s32 arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4) {
    s32 buf = D_80103B90_B2B80;
    s32 count = D_80103B80_B2B70[buf];
    s32 hi;
    u32 t1;
    FxLine *e;

    if (count >= 0x94) {
        return;
    }
    D_80103B80_B2B70[buf] = count + 1;
    e = &D_80102DC0_B1DB0[buf][count];
    hi = (arg1 * 0x10) | ((e->packed >> 16) & 0xF);
    e->packed = (e->packed & 0xFFFF) | (s32)(((u32)hi & 0xFFFF) << 16);
    t1 = (u32)(s32)(s16)(e->packed >> 16);
    e->packed = (s32)(((((u32)arg3 ^ (t1 >> 8)) << 20) >> 12) ^ t1);
    e->x1 = arg2;
    e->packed = (e->packed & ~0xFF) | 0xE;
    e->x0 = (s16) arg0;
    if (arg4 != 0) {
        e->packed |= 0x10;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxDrawDigitalNumber.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxOutputLines(void) {
    s32 screenW;
    s32 screenH;
    s32 buf;
    s32 lineCount;
    s32 textCount;
    s32 i;
    s32 k;
    s32 n;
    s32 kind;
    s32 flags;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 dx;
    s32 dy;
    s32 adx;
    s32 ady;
    s32 ds;
    s32 fpVal;
    s32 alphaVal;
    s32 major;
    s32 minor;
    s32 minorStep;
    s32 slope;
    s32 prevMinor;
    s32 step;
    s32 t;
    u32 pos;
    u32 base;
    FxLine *ln;
    FxText *txt;
    FxPat *pat;
    u8 ch;
    u8 *p;
    s32 glyph;
    s32 width;
    s32 remaining;
    s32 row;
    s32 col;
    u8 bits;

    viGetCurrentSize(&screenW, &screenH);
    buf = D_80103B90_B2B80 ^ 1;
    D_80103B90_B2B80 = buf;
    lineCount = D_80103B80_B2B70[buf];
    ds = screenW * 2;

    for (i = 0; i < lineCount; i++) {
        ln = &D_80102DC0_B1DB0[buf][i];
        flags = ln->packed & 0xFF;
        kind = flags & 0xF;
        y0 = ln->packed >> 20;
        y1 = (s32)((u32)ln->packed << 12) >> 20;
        x0 = ln->x0;
        x1 = ln->x1;

        if (kind == 0xE) {
            func_8006E5FC(x0, y0, x1, y1, flags & 0x10);
            continue;
        }
        if (kind == 0xD || kind == 0xC) {
            func_8006E1D8((u16 *)currentScreen, x0, y0, x1, y1, kind == 0xD);
            continue;
        }

        pos = currentScreen + (y0 * ds) + (x0 * 2);
        fpVal = 0;
        alphaVal = 8;
        pat = NULL;
        if (flags & 0x10) {
            fpVal = 0x18;
            alphaVal = 0;
        }
        if (flags & 0x20) {
            alphaVal *= 2;
        } else if (flags & 0x80) {
            alphaVal = 6;
        }

        switch (kind) {
        case 3:
        case 8:
        case 9:
        case 10:
        case 11:
        case 15:
            /* line drawn with a per-kind pixel pattern at every step */
            dx = x0 - x1;
            dy = y0 - y1;
            adx = (dx < 0) ? -dx : dx;
            ady = (dy < 0) ? -dy : dy;
            prevMinor = -1;
            if (ady < adx) {
                n = adx;
                minor = y0 << 16;
                major = (dx < 0) ? 1 : -1;
                slope = (dy * 0x10000) / adx;
                minorStep = (dy < 0) ? screenW : -screenW;
            } else {
                n = ady;
                minor = x0 << 16;
                major = (dy < 0) ? screenW : -screenW;
                slope = (dx * 0x10000) / ady;
                minorStep = (dx < 0) ? 1 : -1;
            }
            step = major * 2;
            for (k = 0; k < n - 1; k++) {
                s32 cA = (fpVal * 2) & 0xFF;
                s32 cB = (alphaVal * 2) & 0xFF;
                s32 eA = fpVal & 0xFF;
                s32 eB = alphaVal & 0xFF;
                s32 cenA = (fpVal * 4) & 0xFF;
                s32 cenB = (alphaVal * 4) & 0xFF;

                switch (kind) {
                case 3:
                    PlotAddRG((u16 *)(pos - ds - 2), eA, eB);
                    PlotAddRG((u16 *)(pos - ds), cA, cB);
                    PlotAddRG((u16 *)(pos - ds + 2), eA, eB);
                    PlotAddRG((u16 *)(pos - 2), cA, cB);
                    PlotAddRG((u16 *)pos, cenA, cenB);
                    PlotAddRG((u16 *)(pos + 2), cA, cB);
                    PlotAddRG((u16 *)(pos + ds - 2), eA, eB);
                    PlotAddRG((u16 *)(pos + ds), cA, cB);
                    PlotAddRG((u16 *)(pos + ds + 2), eA, eB);
                    break;
                case 8:
                    PlotAddRG((u16 *)(pos - ds), 0, 0x10);
                    PlotAddRG((u16 *)(pos - 2), 0, 0x10);
                    PlotAddRG((u16 *)pos, 0, 0x10);
                    PlotAddRG((u16 *)(pos + 2), 0, 0x10);
                    PlotAddRGB((u16 *)(pos + ds), 0x10, 0x10, 0x10);
                    break;
                case 9:
                    PlotAddRG((u16 *)(pos - ds), 0, 0x10);
                    PlotAddRG((u16 *)(pos - 2), 0, 0x10);
                    PlotAddRG((u16 *)pos, 0, 0x10);
                    PlotAddRG((u16 *)(pos + 2), 0, 0x10);
                    PlotAddRGB((u16 *)(pos + ds), -0x10, -0x10, -0x10);
                    break;
                case 10:
                    PlotAddRG((u16 *)(pos - ds), 0x10, 0);
                    PlotAddRG((u16 *)(pos - 2), 0x10, 0);
                    PlotAddRG((u16 *)pos, 0x10, 0);
                    PlotAddRG((u16 *)(pos + 2), 0x10, 0);
                    PlotAddRGB((u16 *)(pos + ds), 0x10, 0x10, 0x10);
                    break;
                case 11:
                    PlotAddRG((u16 *)(pos - ds), 0x10, 0);
                    PlotAddRG((u16 *)(pos - 2), 0x10, 0);
                    PlotAddRG((u16 *)pos, 0x10, 0);
                    PlotAddRG((u16 *)(pos + 2), 0x10, 0);
                    PlotAddRGB((u16 *)(pos + ds), -0x10, -0x10, -0x10);
                    break;
                case 15:
                    PlotAddRGB((u16 *)(pos - ds), 0, 0, 0x10);
                    PlotAddRGB((u16 *)(pos - 2), 0, 0, 0x10);
                    PlotAddRGB((u16 *)pos, 0, 0, 0x10);
                    PlotAddRGB((u16 *)(pos + 2), 0, 0, 0x10);
                    PlotAddRGB((u16 *)(pos + ds), 0x10, 0x10, 0x10);
                    break;
                }

                t = minor + slope;
                minor = t;
                pos += step;
                if (prevMinor != (t >> 16)) {
                    prevMinor = t >> 16;
                    pos += minorStep * 2;
                }
            }
            break;
        case 2:
            if (x0 < x1) {
                n = x1 - x0;
                major = 1;
            } else {
                n = x0 - x1;
                major = -1;
            }
            minorStep = (y0 < y1) ? screenW : -screenW;
            n -= 1;
            step = (major + minorStep) * 2;
            while (n != 0 && pos >= (u32)currentScreen) {
                PlotAddRG((u16 *)pos, fpVal & 0xFF, alphaVal & 0xFF);
                n--;
                pos += step;
            }
            break;
        case 1:
            t = (x1 - x0) + 1;
            for (k = 0; k < t - 1; k++) {
                PlotAddRG((u16 *)(pos - ds), fpVal & 0xFF, alphaVal & 0xFF);
                PlotAddRG((u16 *)pos, fpVal & 0xFF, alphaVal & 0xFF);
                PlotAddRG((u16 *)(pos + ds), fpVal & 0xFF, alphaVal & 0xFF);
                pos += 2;
            }
            break;
        case 4:
            n = 0x12;
            pat = D_800A6968_A7568;
            break;
        case 5:
            n = 0x10;
            pat = D_800A698C_A758C;
            break;
        case 6:
            n = 0xF;
            pat = D_800A69AC_A75AC;
            break;
        case 7:
            n = 0xF;
            pat = D_800A69CC_A75CC;
            break;
        case 0:
            if (y1 == y0) {
                t = (x1 - x0) + 1;
                for (k = 0; k < t - 1; k++) {
                    PlotAddRG((u16 *)pos, fpVal & 0xFF, alphaVal & 0xFF);
                    pos += 2;
                }
            } else {
                t = (y1 - y0) + 1;
                if (x1 == x0) {
                    for (k = 0; k < t - 1; k++) {
                        PlotAddRG((u16 *)pos, fpVal & 0xFF, alphaVal & 0xFF);
                        pos += ds;
                    }
                }
            }
            break;
        }

        if (pat != NULL) {
            for (k = 0; k < n - 1; k++) {
                s32 dxp = pat->dx;
                if (flags & 0x40) {
                    dxp = -dxp;
                }
                PlotAddRG((u16 *)(pos + (pat->dy * screenW * 2) + (dxp * 2)), fpVal & 0xFF, alphaVal & 0xFF);
                pat++;
            }
        }
    }

    textCount = D_80103B88_B2B78[buf];
    D_80103B80_B2B70[buf] = 0;

    txt = sniperStructs[buf];
    for (i = 0; i < textCount; i++, txt++) {
        remaining = 0x1F;
        ch = txt->text[0];
        p = &txt->text[1];
        pos = currentScreen + (txt->x * 2) + (txt->y * ds);
        while (ch != 0) {
            base = pos;
            switch (ch) {
            case 0x2E:
                glyph = 0xA;
                break;
            case 0x4C:
                glyph = 0xB;
                break;
            case 0x4F:
                glyph = 0xC;
                break;
            case 0x43:
                glyph = 0xD;
                break;
            case 0x4B:
                glyph = 0xE;
                break;
            case 0x2D:
                glyph = 0xF;
                break;
            case 0x23:
                glyph = 0x10;
                break;
            default:
                glyph = ch - 0x30;
                break;
            }
            width = D_800A6B2C_A772C[glyph];
            for (row = 0; row < 5; row++) {
                for (col = 0; col < width - 1; col++) {
                    bits = D_800A69EC_A75EC[D_800A6B40_A7740[glyph] + (row * (width - 1)) + col];
                    if (bits != 0) {
                        PlotAddRG((u16 *)pos, ((s8)(fpVal * 2) >> bits) & 0xFF, ((s8)(alphaVal * 2) >> bits) & 0xFF);
                    }
                    pos += 2;
                }
                pos += (screenW - width) * 2;
            }
            pos = base + (width * 2) + 2;
            if (glyph == 0x10) {
                pos -= 2;
            }
            remaining--;
            if (remaining == 0) {
                break;
            }
            ch = *p++;
        }
    }

    D_80103B88_B2B78[D_80103B90_B2B80] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxOutputLines.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxInitNightVision(s32 arg0) {
    if (arg0 != 0) {
        D_800A6D00_A7900 = 0x20;
    } else {
        D_800A6D00_A7900 = 1;
    }
    D_800A6D08_A7908 = 1;
    D_800A6D0C_A790C = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxInitNightVision.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxFreeNightVision(s32 arg0) {
    if (arg0 != 0) {
        D_800A6D00_A7900 = 0;
    } else {
        D_800A6D00_A7900 = 0x20;
    }
    D_800A6D08_A7908 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxFreeNightVision.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 fxNightVision(void) {
    return D_800A6D00_A7900;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxNightVision.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawNightVision(Gfx **dl) {
    s32 w;
    s32 h;
    s32 i;
    s32 rnd;
    s32 bit;
    s32 y;
    Gfx *g;
    u8 text[8];

    if (D_800A6D00_A7900 != 0) {
        viGetCurrentSize(&w, &h);
        if (D_800A6D00_A7900 < 0x21) {
            D_80102CE0_B1CD0 = ((s32)(D_800A6D00_A7900 * -0xFF) >> 5) + 0xFF;
            D_80102CE1_B1CD1 = ((s32)(D_800A6D00_A7900 * -0x10) >> 5) + 0xFF;
            D_80102CE2_B1CD2 = ((s32)(D_800A6D00_A7900 * -0xC4) >> 5) + 0xFF;
            D_80102CE3_B1CD3 = 0;
            D_80102CE4_B1CD4 = (u8)((s32)(D_800A6D00_A7900 * 0x10) >> 5);
            D_80102CE5_B1CD5 = (u8)((s32)(D_800A6D00_A7900 * 4) >> 5);
            if (D_800A6D08_A7908 != 0) {
                D_800A6D00_A7900 += 1;
            } else {
                D_800A6D00_A7900 -= 1;
            }
        }
        if (D_800A6D0C_A790C != 0) {
            D_800A6D04_A7904 = 1;
            fxScreenEffect(dl, otherScreen, w, h, 0, 0, w, h, NULL);
        }
        D_800A6D0C_A790C = 1;

        g = *dl;
        *dl = g + 1;
        g->words.w0 = 0xFA000000;
        g->words.w1 = ((D_800A6D00_A7900 * 5) & 0xFF) | 0xFF0000;
        g = *dl;
        *dl = g + 1;
        g->words.w0 = 0x06000000;
        g->words.w1 = (u32)D_800A6BB8_A77B8;
        texDPInit(dl);

        y = 0xC8;
        for (i = 2; i != 0; i--) {
            rnd = mathRnd(0, 0xFF);
            for (bit = 0; bit < 7; bit++) {
                text[bit] = (rnd & 1) + 0x30;
                rnd >>= 1;
            }
            text[7] = 0;
            fxTinyPrint(0x28, y, text);
            y += 6;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxDrawNightVision.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxNightVisionSkip(void) {
    D_800A6D0C_A790C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxNightVisionSkip.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxSPDPRipple(Gfx **dl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    LevelHeader *level;
    u8 intensity;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 t0;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 s4;
    s32 s5;
    s32 s6;
    s32 t3;
    s32 hiT;
    s32 loT;
    s32 tgt;
    s32 sp44;
    s32 amp;
    s32 r;
    s32 gr;
    s32 bl;
    s32 next;
    s32 a0;
    Gfx *g;

    level = levelGetLevel();
    if (level != NULL && ((u8 *)level)[0xF6] != 0) {
        texDPTextureX(dl, NULL, 4, 0);
        g = *dl;
        *dl = g + 1;
        g->words.w0 = 0xFCFFFFFF;
        g->words.w1 = 0xFFFDF6FB;

        intensity = ((u8 *)level)[0xF6];
        a1 = arg5;
        a2 = D_800A6D10_A7910 + (arg5 * 0x200);
        a3 = D_800A6D14_A7914 + (arg5 * -0x3C0);
        t0 = D_800A6D18_A7918 + (arg5 * 0x180);
        D_800A6D10_A7910 = a2;
        D_800A6D14_A7914 = a3;
        D_800A6D18_A7918 = t0;

        s4 = a2 + (arg2 << 10);
        t3 = (intensity * 0x50) >> 7;
        s5 = a3 + (arg2 * 0xBA2);
        s6 = t0 + (arg2 * 0x28F);
        hiT = (intensity * 0x58) >> 7;
        loT = (intensity * 0x48) >> 7;
        s1 = arg2;

        if (arg2 < arg4) {
            sp44 = (arg1 & 0x3FF) << 14;
            a0 = s5 << 16;
            do {
                s2 = mathSin(a0 >> 16);
                s3 = mathSin(s4);
                amp = ((mathSin(s6) << 6) + (s3 * 0xC0) + (s2 * 0x60)) >> 8;
                a0 = amp;
                if (amp < 0) {
                    tgt = loT;
                    a0 = -amp;
                    r = 8;
                    gr = 0x20;
                    bl = 0xA0;
                } else {
                    tgt = hiT;
                    r = 0x80;
                    gr = 0xC0;
                    bl = 0xFF;
                }
                if (a0 >= 0x10001) {
                    a0 = 0x10000;
                }
                next = s1 + 1;
                s4 += 0x400;
                s5 += 0xBA2;
                s6 += 0x28F;

                a1 = (((r - 0x20) * a0) >> 16) + 0x20;
                g = *dl;
                *dl = g + 1;
                g->words.w0 = 0xFA000000;
                a2 = (((gr - 0x78) * a0) >> 16) + 0x78;
                a3 = (((bl - 0xFF) * a0) >> 16) + 0xFF;
                g->words.w1 = (a1 << 0x18) | ((a2 & 0xFF) << 0x10) | ((a3 & 0xFF) << 8) |
                              (((((tgt - t3) * a0) >> 16) + t3) & 0xFF);

                g = *dl;
                *dl = g + 1;
                g->words.w0 = ((arg3 & 0x3FF) << 14) | 0xF6000000 | ((next & 0x3FF) * 4);
                g->words.w1 = sp44 | ((s1 & 0x3FF) * 4);

                g = *dl;
                *dl = g + 1;
                g->words.w1 = 0;
                g->words.w0 = 0xE7000000;

                s1 = next;
                a0 = s5 << 16;
            } while (next != arg4);
        }
        texDPInit(dl);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxSPDPRipple.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxQueueScreenEffect(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    FxScreenEffect *e;

    if (D_800A6E18_A7A18 < 4) {
        e = &D_80102CE8_B1CD8[D_800A6E18_A7A18];
        D_800A6E18_A7A18 += 1;
        e->unk0 = arg0;
        e->unk4 = arg1;
        e->unk6 = arg2;
        e->unk8 = arg3;
        e->unkA = (s16)arg4;
        e->unkC = (s16)arg5;
        e->unkE = (s16)arg6;
        e->unk10 = arg7;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxQueueScreenEffect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxUnQueueScreenEffect(s32 arg0) {
    s32 i;
    FxScreenEffect *e;

    for (i = 0; i < D_800A6E18_A7A18; i++) {
        e = &D_80102CE8_B1CD8[i];
        fxScreenEffect((Gfx **)arg0, (void *)e->unk0, e->unk4, e->unk6, e->unk8, e->unkA, e->unkC, e->unkE, (void *)e->unk10);
    }
    D_800A6E18_A7A18 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxUnQueueScreenEffect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxScreenEffect(Gfx **dl, void *screen, s32 w, s32 h, s32 x, s32 y, s32 right, s32 bottom, void *tex) {
    u32 *pattern;
    u32 rowAddr;
    s32 mode;
    s32 top;
    s32 bandEnd;
    s32 end;
    Gfx *g;

    mode = viGetVideoMode();
    if (mode == 2 || mode == 3) {
        pattern = D_800A6DA8_A79A8;
    } else {
        pattern = D_800A6D70_A7970;
    }

    if (D_800A6D04_A7904 != 0) {
        D_800A6D04_A7904 = 0;
        g = *dl;
        *dl = g + 1;
        g->words.w1 = (u32)&D_800A6D48;
        g->words.w0 = 0x06000000;
        g = *dl;
        *dl = g + 1;
        g->words.w0 = 0xFA000000;
        g->words.w1 = (D_80102CE0_B1CD0 << 0x18) | (D_80102CE1_B1CD1 << 0x10) | (D_80102CE2_B1CD2 << 8) | 0xFF;
        g = *dl;
        *dl = g + 1;
        g->words.w0 = 0xFB000000;
        g->words.w1 = (D_80102CE3_B1CD3 << 0x18) | (D_80102CE4_B1CD4 << 0x10) | (D_80102CE5_B1CD5 << 8) | 0xFF;
    } else {
        g = *dl;
        *dl = g + 1;
        g->words.w0 = 0x06000000;
        g->words.w1 = (u32)D_800A6D20_A7920;
        g = *dl;
        *dl = g + 1;
        g->words.w0 = 0xFA000000;
        g->words.w1 = (u32)tex;
    }

    rowAddr = (u32)screen + (y * w * 2);
    top = y * 4;
    end = bottom * 4;
    if (top < end) {
        do {
            g = *dl;
            g->words.w0 = pattern[0];
            g->words.w1 = rowAddr;
            g = g + 1;
            g->words.w0 = 0x07060030;
            g->words.w1 = (u32)pattern + 0x80000008;
            *dl = g + 1;

            bandEnd = top + 0x10;
            if (end < bandEnd) {
                bandEnd = end;
            }
            g = *dl;
            *dl = g + 1;
            g->words.w0 = (((right * 4) & 0xFFF) << 12) | 0xE4000000 | (bandEnd & 0xFFF);
            g->words.w1 = (((x * 4) & 0xFFF) << 12) | (top & 0xFFF);
            g = *dl;
            *dl = g + 1;
            g->words.w0 = 0xB3000000;
            g->words.w1 = ((x * 4) << 5) << 0x10;
            g = *dl;
            *dl = g + 1;
            g->words.w0 = 0xB2000000;
            g->words.w1 = 0x04000400;

            top = bandEnd;
            rowAddr += w * 8;
        } while (top < end);
    }

    texDPInit(dl);
    g = *dl;
    *dl = g + 1;
    g->words.w0 = 0xFA000000;
    g->words.w1 = -1;
    g = *dl;
    *dl = g + 1;
    g->words.w0 = 0xFB000000;
    g->words.w1 = -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxScreenEffect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006FFF8(void *arg0) {
    s32 *var_a0;
    s32 *var_a1;
    s32 *var_t0;
    s32 var_v1;
    u8 *var_a2;

    D_80102D54_B1D44 = 0;
    var_t0 = &D_800A6E28_A7A28;
    var_a2 = &D_80102D9F_B1D8F;
    var_a1 = &D_80102D84_B1D74;
    var_a0 = &D_80102D6C_B1D5C;
    var_v1 = 3;
    do {
        *var_a0 = 0;
        *var_a1 = 0;
        *var_a2 = ((s32)TrapDanglingJump == *var_t0);
        var_a0 -= 1;
        var_a1 -= 1;
        var_a2 -= 1;
        var_t0 -= 1;
        var_v1 -= 1;
    } while (var_v1 != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/func_8006FFF8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 fxGenerateTextures(void) {
    void (*fn)(s32, void *, s32);
    s32 idx;
    s32 last;

    idx = 3;
    do {
        if (D_80102D54_B1D44 & (1 << idx)) {
            runlinkEnsureJumpIsValid(&D_800A6E1C_A7A1C[idx]);
            fn = (void (*)(s32, void *, s32))D_800A6E1C_A7A1C[idx];
            if (fn != NULL) {
                fn(idx, D_80102D40_B1D30[idx], 0);
            }
        }
        last = idx;
        idx -= 1;
    } while (idx != 0);
    D_80102D54_B1D44 = 0;
    return last;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxGenerateTextures.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxCpuTextureRequired(s32 arg0, void *arg1) {
    void (*fn)(s32, void *, s32);
    s32 idx;
    s32 size;
    s32 i;
    u8 *texA;
    u8 *texB;

    idx = arg0 - 1;
    D_80102D54_B1D44 |= 1 << idx;
    D_80102D40_B1D30[idx] = arg1;
    if (CpuTexSpaceA[idx] == NULL) {
        size = ((u8 *)arg1)[0] * ((u8 *)arg1)[1];
        texA = (u8 *)mmAlloc(size, 0xFFFF);
        CpuTexSpaceA[idx] = texA;
        texB = (u8 *)mmAlloc(size, 0xFFFF);
        CpuTexSpaceB[idx] = texB;
        if (texA == NULL || texB == NULL) {
            CpuTexSpaceA[idx] = NULL;
            CpuTexSpaceB[idx] = NULL;
        } else {
            for (i = 0; i < size - 1; i++) {
                texA[i] = 0;
                texB[i] = 0;
            }
            runlinkEnsureJumpIsValid(&D_800A6E1C_A7A1C[idx]);
            fn = (void (*)(s32, void *, s32))D_800A6E1C_A7A1C[idx];
            if (fn != NULL) {
                fn(idx, D_80102D40_B1D30[idx], 1);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxCpuTextureRequired.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 fxCpuTextureFlush(void) {
    s32 idx;
    s32 last;
    u8 *flag;

    flag = &D_80102D9F_B1D8F;
    idx = 3;
    do {
        if (CpuTexSpaceA[idx] != NULL) {
            mmFree(CpuTexSpaceA[idx]);
            mmFree(CpuTexSpaceB[idx]);
            CpuTexSpaceA[idx] = NULL;
            CpuTexSpaceB[idx] = NULL;
        }
        last = idx;
        if (*flag != 0) {
            D_800A6E1C_A7A1C[idx] = (void *)TrapDanglingJump;
        }
        flag -= 1;
        idx -= 1;
    } while (idx != 0);
    D_80102D54_B1D44 = 0;
    return last;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fx/fxCpuTextureFlush.s")
#endif
