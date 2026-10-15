#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern void *D_overlay_5_00500D14;
extern void *D_overlay_5_00500DA8;
extern s32 D_overlay_5_00500D10;
extern u8 D_overlay_5_00500D60[];
extern s32 D_overlay_5_00500D18;
extern void *D_overlay_5_00500D20;
extern void *D_overlay_5_00500DF8;
extern f32 D_overlay_5_00500D50;
extern u8 D_overlay_5_00500D28[];
extern u8 D_overlay_5_00500DB0[];
extern s32 D_overlay_5_00500DDC;
extern f32 D_overlay_5_00500DE0;
extern f32 D_overlay_5_00500DE4;
extern f32 D_overlay_5_00500DE8;
extern f32 D_overlay_5_00500DEC;
extern f32 D_overlay_5_00500DF0;
extern f32 D_overlay_5_00500DF4;
extern s32 D_overlay_5_00500D1C;
void rainFastDraw(s32 a0, s32 a1, s32 a2, s32 a3, void *p4, void *p5, s32 p6, f32 p7, f32 p8, f32 p9, f32 p10);
void *camGetPtr(void);
void starfieldFastMove(s32 count, void *stars, f32 dx, f32 dy, f32 dz, f32 p5, f32 p6, f32 p7, f32 p8, f32 p9, f32 p10, f32 p11, f32 p12, f32 p13);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 starfieldActive(void) {
    return (s32)D_overlay_5_00500D14;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/starfieldActive.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void starfieldFree(void) {
    if (D_overlay_5_00500D14 != NULL) {
        mmFree(D_overlay_5_00500D14);
        D_overlay_5_00500D14 = NULL;
        D_overlay_5_00500DA8 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/starfieldFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void starfieldInit(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4, u32 arg5, s32 arg6) {
    u8 *cfg = D_overlay_5_00500D60;
    f32 *star;
    s16 *pal;
    s32 t8;
    s32 t9;
    s32 i;
    s32 k;
    s32 r0;
    s32 g0;
    s32 b0;
    s32 dr;
    s32 dg;
    s32 db;
    s32 r;
    s32 g;
    s32 b;

    D_overlay_5_00500D14 = mmAlloc(arg0 * 0xC + 0x200, -1U);
    D_overlay_5_00500DA8 = (u8 *)D_overlay_5_00500D14 + arg0 * 0xC;
    *(f32 *)(cfg + 0x8) = (f32)arg1;
    *(f32 *)(cfg + 0x14) = (f32)arg2;
    *(f32 *)(cfg + 0x20) = (f32)arg3;
    t8 = arg1 << 7;
    t9 = arg2 << 7;
    *(f32 *)(cfg + 0x24) = (f32)arg6;
    *(f32 *)(cfg + 0x0) = *(f32 *)(cfg + 0x8) * -0.5f;
    D_overlay_5_00500D10 = arg0;
    *(f32 *)(cfg + 0x4) = *(f32 *)(cfg + 0x8) * 0.5f;
    *(f32 *)(cfg + 0xC) = *(f32 *)(cfg + 0x14) * -0.5f;
    *(f32 *)(cfg + 0x10) = *(f32 *)(cfg + 0x14) * 0.5f;
    *(f32 *)(cfg + 0x18) = 1.0f;
    *(f32 *)(cfg + 0x1C) = *(f32 *)(cfg + 0x20) + 1.0f;
    *(s32 *)(cfg + 0x2C) = 0;
    *(f32 *)(cfg + 0x28) = 255.0f / *(f32 *)(cfg + 0x24);

    star = (f32 *)D_overlay_5_00500D14;
    for (i = 0; i < arg0; i++) {
        star[0] = (f32)mathRnd(-t8, t8) * 0.00390625f;
        star[1] = (f32)mathRnd(-t9, t9) * 0.00390625f;
        star[2] = (f32)mathRnd(0x100, (arg3 + 1) << 8) * 0.00390625f;
        star += 3;
    }

    r0 = (arg4 >> 0x18) & 0xFF;
    g0 = (arg4 >> 0x10) & 0xFF;
    b0 = (arg4 >> 8) & 0xFF;
    dr = ((arg5 >> 0x18) & 0xFF) - r0;
    dg = ((arg5 >> 0x10) & 0xFF) - g0;
    db = ((arg5 >> 8) & 0xFF) - b0;

    pal = (s16 *)D_overlay_5_00500DA8;
    for (k = 0; k < 0x100; k++) {
        r = ((((s32)(dr * k)) >> 8) + r0) & 0xF8;
        g = ((((s32)(dg * k)) >> 8) + g0) & 0xF8;
        b = ((((s32)(db * k)) >> 8) + b0) & 0xF8;
        pal[k] = (s16)((r << 8) | (g * 8) | (b >> 2) | 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/starfieldInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void starfieldMove(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    u8 *cfg = D_overlay_5_00500D60;
    f32 s;

    *(f32 *)(cfg + 0x30) = arg0;
    *(f32 *)(cfg + 0x34) = arg1;
    *(f32 *)(cfg + 0x38) = arg2;
    if (D_overlay_5_00500D14 != NULL) {
        s = (f32)arg3;
        starfieldFastMove(D_overlay_5_00500D10, D_overlay_5_00500D14,
                          arg0 * s, arg1 * s, arg2 * s,
                          *(f32 *)(cfg + 0x0), *(f32 *)(cfg + 0x0),
                          *(f32 *)(cfg + 0x8), *(f32 *)(cfg + 0x8),
                          *(f32 *)(cfg + 0x10), *(f32 *)(cfg + 0x10),
                          *(f32 *)(cfg + 0x18), *(f32 *)(cfg + 0x18),
                          *(f32 *)(cfg + 0x20));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/starfieldMove.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void starfieldDrawSP(Gfx **arg0, f32 arg1) {
    s32 sp44;
    s32 sp40;
    Gfx *gfx;
    f32 *star;
    s32 i;
    f32 z;
    f32 sc;
    s32 x;
    s32 y;
    s32 c;

    viGetCurrentSize(&sp44, &sp40);
    gfx = *arg0;
    gfx->words.w0 = 0x06000000;
    gfx->words.w1 = (u32)D_overlay_5_00500D28;
    gfx += 1;
    star = (f32 *)D_overlay_5_00500D14;
    for (i = 0; i < D_overlay_5_00500D10; i++) {
        z = star[2];
        if ((z >= 8.0f) && (z < 300.0f)) {
            sc = arg1 / z;
            x = (s32)(star[0] * sc) + ((u32)sp44 >> 1);
            y = ((u32)sp40 >> 1) - (s32)(star[1] * sc);
            if ((x >= 0) && (y >= 0) && (x < sp44) && (y < sp40)) {
                c = 0xFF - (s32)((z - 8.0f) * D_overlay_5_00500D50);
                gfx[0].words.w0 = 0xFA000000;
                gfx[0].words.w1 = (c << 0x18) | (c << 0x10) | (c << 8) | 0xFF;
                gfx[1].words.w0 = 0xF6000000 | ((x + 1) << 0xE) | ((y + 1) * 4);
                gfx[1].words.w1 = (x << 0xE) | (y * 4);
                gfx += 2;
            }
        }
        star += 3;
    }
    *arg0 = gfx;
    texDPInit(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/starfieldDrawSP.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 rainActive(void) {
    return (s32)D_overlay_5_00500D20;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/rainActive.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rainFree(void) {
    if (D_overlay_5_00500D20 != NULL) {
        mmFree(D_overlay_5_00500D20);
        D_overlay_5_00500D20 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/rainFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rainInit(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4, u32 arg5, s32 arg6) {
    u8 *cfg = D_overlay_5_00500DB0;
    u8 *buf;
    f32 *pos;
    u32 *col;
    s32 t9;
    s32 t0;
    s32 t1;
    s32 r0;
    s32 g0;
    s32 b0;
    s32 a0;
    s32 dr;
    s32 dg;
    s32 db;
    s32 da;
    s32 i;
    s32 k;

    buf = (u8 *)mmAlloc(arg0 * 0x10, -1U);
    *(f32 *)(cfg + 0x8) = (f32)arg1;
    *(f32 *)(cfg + 0x0) = *(f32 *)(cfg + 0x8) * -0.5f;
    *(f32 *)(cfg + 0x14) = (f32)arg2;
    *(f32 *)(cfg + 0x4) = *(f32 *)(cfg + 0x8) * 0.5f;
    *(f32 *)(cfg + 0xC) = *(f32 *)(cfg + 0x14) * -0.5f;
    *(f32 *)(cfg + 0x20) = (f32)arg3;
    *(f32 *)(cfg + 0x10) = *(f32 *)(cfg + 0x14) * 0.5f;
    *(f32 *)(cfg + 0x18) = *(f32 *)(cfg + 0x20) * -0.5f;
    *(f32 *)(cfg + 0x24) = (f32)arg6;
    *(f32 *)(cfg + 0x1C) = *(f32 *)(cfg + 0x20) * 0.5f;

    t9 = arg1 << 7;
    t0 = arg2 << 7;
    t1 = arg3 << 7;
    D_overlay_5_00500D20 = buf;
    D_overlay_5_00500DF8 = buf + arg0 * 0xC;
    D_overlay_5_00500D18 = arg0;
    *(s32 *)(cfg + 0x2C) = 0;
    *(f32 *)(cfg + 0x28) = 255.0f / *(f32 *)(cfg + 0x24);

    pos = (f32 *)buf;
    col = (u32 *)(buf + arg0 * 0xC);
    r0 = (arg4 >> 0x18) & 0xFF;
    g0 = (arg4 >> 0x10) & 0xFF;
    b0 = (arg4 >> 8) & 0xFF;
    a0 = arg4 & 0xFF;
    dr = ((arg5 >> 0x18) & 0xFF) - r0;
    dg = ((arg5 >> 0x10) & 0xFF) - g0;
    db = ((arg5 >> 8) & 0xFF) - b0;
    da = (arg5 & 0xFF) - a0;

    for (i = 0; i < arg0; i++) {
        pos[0] = (f32)mathRnd(-t9, t9) * 0.00390625f;
        pos[1] = (f32)mathRnd(-t0, t0) * 0.00390625f;
        pos[2] = (f32)mathRnd(-t1, t1) * 0.00390625f;
        k = mathRnd(0, 0xFF);
        col[i] = ((((dr * k) >> 8) + r0) << 0x18) | ((((dg * k) >> 8) + g0) << 0x10) |
                 ((((db * k) >> 8) + b0) << 8) | (((da * k) >> 8) + a0);
        pos += 3;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/rainInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rainMove(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    u8 *cfg = D_overlay_5_00500DB0;
    u8 *cam = camGetPtr();
    f32 dX = 0.0f;
    f32 dY = 0.0f;
    f32 dZ = 0.0f;
    f32 inv;
    f32 s;
    f32 x;
    f32 y;
    f32 z;

    if ((D_overlay_5_00500DDC != 0) && (arg3 != 0)) {
        inv = 1.0f / (f32)arg3;
        dX = (D_overlay_5_00500DEC - *(f32 *)(cam + 0xC)) * inv;
        dY = (D_overlay_5_00500DF0 - *(f32 *)(cam + 0x10)) * inv;
        dZ = (D_overlay_5_00500DF4 - *(f32 *)(cam + 0x14)) * inv;
    }
    D_overlay_5_00500DEC = *(f32 *)(cam + 0xC);
    D_overlay_5_00500DF0 = *(f32 *)(cam + 0x10);
    D_overlay_5_00500DF4 = *(f32 *)(cam + 0x14);
    D_overlay_5_00500DDC = 1;

    x = arg0 + dX;
    y = arg1 + dY;
    z = arg2 + dZ;
    D_overlay_5_00500DE0 = x;
    D_overlay_5_00500DE4 = y;
    D_overlay_5_00500DE8 = z;

    if (D_overlay_5_00500D20 != NULL) {
        s = (f32)arg3;
        starfieldFastMove(D_overlay_5_00500D18, D_overlay_5_00500D20,
                          x * s, y * s, z * s,
                          *(f32 *)(cfg + 0x0), *(f32 *)(cfg + 0x0),
                          *(f32 *)(cfg + 0x8), *(f32 *)(cfg + 0x8),
                          *(f32 *)(cfg + 0x10), *(f32 *)(cfg + 0x10),
                          *(f32 *)(cfg + 0x18), *(f32 *)(cfg + 0x18),
                          *(f32 *)(cfg + 0x20));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/rainMove.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rainSetDraw(s32 arg0) {
    D_overlay_5_00500D1C = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/rainSetDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rainResetCamera(void) {
    D_overlay_5_00500DDC = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/rainResetCamera.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rainDraw(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4) {
    s32 count;

    if (D_overlay_5_00500D1C != 0) {
        count = (s32) ((f32) D_overlay_5_00500D18 * arg4);
        if ((D_overlay_5_00500D20 != NULL) && (count > 0)) {
            rainFastDraw(arg0, arg1, arg2, count, D_overlay_5_00500D20, D_overlay_5_00500DF8,
                         (s32) *(s16 *) camGetPtr() + 0x8000, D_overlay_5_00500DE0, D_overlay_5_00500DE0,
                         D_overlay_5_00500DE8, arg3);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o5/overlay_5/rainDraw.s")
#endif
