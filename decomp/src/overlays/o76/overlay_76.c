#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void beamControl(void *arg0, s32 arg1, s32 arg2);
void runlinkSetDestructTimer(s32 overlayIndex, s32 selfDestructTimer, s32 refCount);
void texDPTextureX(Gfx **dl, void *tex, s32 rtile, s32 tmem);
extern s32 __MODULE00076;
extern f32 D_overlay_76_04C00EA0;
extern f32 D_overlay_76_04C00EA4;
extern s16 D_overlay_76_04C00D14;
extern u8 D_overlay_76_04C00D38[];
extern u8 D_overlay_76_04C00DB8[];
extern u8 D_overlay_76_04C00DE8[];
extern u8 D_overlay_76_04C00E68[];
extern s32 D_84C00D18;
extern s32 D_84C00D38;
extern s32 D_84C00DE8;
extern s8 beamScrollFlag;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void beamInit(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *def = (u8 *)arg1;
    u8 *t1;
    u8 *var_t0;
    u8 *var_v0;
    s32 var_a3;
    s32 var_v1;

    *(s16 *)(obj + 0x0) = *(s16 *)(def + 0x22);
    *(s16 *)(obj + 0x2) = *(s16 *)(def + 0x20);
    *(s16 *)(obj + 0x4) = (s16)(*(s8 *)(def + 0x1F) << 6);
    t1 = *(u8 **)(obj + 0x68);
    *(f32 *)(obj + 0x8) = D_overlay_76_04C00EA0;
    *(f32 *)(t1 + 0xA0) = (f32)*(s16 *)(def + 0xE) * 10.0f;
    *(f32 *)(t1 + 0xA4) = (f32)*(s16 *)(def + 0x10) * 10.0f;
    *(f32 *)(t1 + 0xA8) = (f32)*(s16 *)(def + 0x12) * 10.0f;
    *(f32 *)(t1 + 0xAC) = (f32)*(u16 *)(def + 0xA) * 10.0f;
    *(f32 *)(t1 + 0xB0) = (f32)*(u16 *)(def + 0xC) * 10.0f;
    *(f32 *)(t1 + 0xB4) = (f32)*(u16 *)(def + 0x1A) * 10.0f;
    *(f32 *)(t1 + 0xB8) = (f32)*(u8 *)(def + 0x1C) * D_overlay_76_04C00EA4;
    *(f32 *)(t1 + 0xBC) = (f32)*(u8 *)(def + 0x1D) * D_overlay_76_04C00EA4;
    *(f32 *)(t1 + 0xC0) = (f32)*(u8 *)(def + 0x14) * D_overlay_76_04C00EA4;
    *(f32 *)(t1 + 0xC4) = (f32)*(u8 *)(def + 0x15) * D_overlay_76_04C00EA4;
    t1[0xC8] = *(u8 *)(def + 0x16);
    t1[0xC9] = *(u8 *)(def + 0x17);
    t1[0xCA] = *(u8 *)(def + 0x18);
    t1[0xCB] = *(u8 *)(def + 0x19);
    t1[0xCC] = *(u8 *)(def + 0x1E);

    /* two rows of 8 vertices, 0x50 bytes per row, 0xA bytes per vertex */
    for (var_a3 = 0; var_a3 != 0xA0; var_a3 += 0x50) {
        var_v0 = t1 + var_a3;
        var_t0 = var_v0;
        for (var_v1 = 1; var_v1 <= 8; var_v1++) {
            if (var_v1 < 4) {
                var_t0[6] = 0xFF;
                var_t0[7] = 0xFF;
                var_t0[8] = 0xFF;
                var_t0[9] = *(u8 *)(def + 0x19);
            } else {
                var_t0[6] = *(u8 *)(def + 0x16);
                var_t0[7] = *(u8 *)(def + 0x17);
                var_t0[9] = 0;
                var_t0[8] = *(u8 *)(def + 0x18);
            }
            var_t0 += 0xA;
        }
    }
    if (arg2 == 0) {
        t1[0xCD] = 0;
        t1[0xCE] = 0;
    }
    beamControl(arg0, 8, var_a3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o76/overlay_76/beamInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void beamControl(void *arg0, s32 arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *beam;
    u8 *vtx;
    u8 cc;
    f32 hx;
    f32 hz;
    f32 pts[8][3]; /* 0-3: rest corners, 4-7: animated corners */
    f32 span;
    f32 t;
    f32 speed;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d2;
    f32 k;
    s32 i;
    s32 count;

    /* asm: arg1/arg2 are passed by beamInit but never read here */
    runlinkSetDestructTimer(__MODULE00076, 2, 2);
    beam = *(u8 **)(obj + 0x68);
    beam[0xCD] ^= 1;
    *(u16 *)(beam + 0xCE) = 0;

    /* half extents: size * 0.5 (fields are the same ones beamInit fills) */
    hx = *(f32 *)(beam + 0xAC) * *(f32 *)(beam + 0xB8) * 0.5f;
    hz = *(f32 *)(beam + 0xB0) * *(f32 *)(beam + 0xBC) * 0.5f;
    if (hx != 0.0f && hz != 0.0f) {
        beamScrollFlag = 1;
        pts[0][0] = -hx; pts[0][1] = hz;  pts[0][2] = 0.0f;
        pts[1][0] = hx;  pts[1][1] = hz;  pts[1][2] = 0.0f;
        pts[2][0] = hx;  pts[2][1] = -hz; pts[2][2] = 0.0f;
        pts[3][0] = -hx; pts[3][1] = -hz; pts[3][2] = 0.0f;

        cc = beam[0xCC];
        *(u16 *)(beam + 0xCE) |= (cc & 1);
        if (cc & 2) {
            span = *(f32 *)(beam + 0xB8) * *(f32 *)(beam + 0xBC);
            if (*(f32 *)(beam + 0xC0) <= span) {
                t = (span - *(f32 *)(beam + 0xC0)) /
                    (*(f32 *)(beam + 0xC4) - *(f32 *)(beam + 0xC0));
                if (t > 1.0f) {
                    t = 1.0f;
                }
                speed = *(f32 *)(beam + 0xB4) * t;
                /* push each rest corner out from beam centre (0xA0..0xA8) */
                for (i = 0; i < 4; i++) {
                    dx = pts[i][0] - *(f32 *)(beam + 0xA0);
                    dy = pts[i][1] - *(f32 *)(beam + 0xA4);
                    dz = pts[i][2] - *(f32 *)(beam + 0xA8);
                    d2 = dx * dx + dy * dy + dz * dz;
                    k = 0.0f;
                    if (d2 != 0.0f) {
                        k = speed / sqrtf(d2);
                    }
                    pts[i + 4][0] = pts[i][0] + dx * k;
                    pts[i + 4][1] = pts[i][1] + dy * k;
                    pts[i + 4][2] = pts[i][2] + dz * k;
                }
                *(u16 *)(beam + 0xCE) |= (beam[0xCC] & 6);
            }
        }

        /* 8 vertices if the animated pass ran (flag 0x2), else 4 */
        count = (*(u16 *)(beam + 0xCE) & 2) ? 8 : 4;
        vtx = beam + beam[0xCD] * 0x50;
        i = 0;
        /* asm: count is always 4 or 8, so the single-vertex remainder path is never taken */
        do {
            *(s16 *)(vtx + 0x0) = (s16)pts[i + 0][0];
            *(s16 *)(vtx + 0x2) = (s16)pts[i + 0][1];
            *(s16 *)(vtx + 0x4) = (s16)pts[i + 0][2];
            if (*(s32 *)(obj + 0x88) != 0) {
                if (i + 0 < 4) {
                    vtx[0x9] = beam[0xCB];
                } else {
                    vtx[0x6] = beam[0xC8];
                    vtx[0x7] = beam[0xC9];
                    vtx[0x8] = beam[0xCA];
                }
            }
            vtx += 0xA;

            *(s16 *)(vtx + 0x0) = (s16)pts[i + 1][0];
            *(s16 *)(vtx + 0x2) = (s16)pts[i + 1][1];
            *(s16 *)(vtx + 0x4) = (s16)pts[i + 1][2];
            if (*(s32 *)(obj + 0x88) != 0) {
                if (i + 1 < 4) {
                    vtx[0x9] = beam[0xCB];
                } else {
                    vtx[0x6] = beam[0xC8];
                    vtx[0x7] = beam[0xC9];
                    vtx[0x8] = beam[0xCA];
                }
            }
            vtx += 0xA;

            *(s16 *)(vtx + 0x0) = (s16)pts[i + 2][0];
            *(s16 *)(vtx + 0x2) = (s16)pts[i + 2][1];
            *(s16 *)(vtx + 0x4) = (s16)pts[i + 2][2];
            if (*(s32 *)(obj + 0x88) != 0) {
                if (i + 2 < 4) {
                    vtx[0x9] = beam[0xCB];
                } else {
                    vtx[0x6] = beam[0xC8];
                    vtx[0x7] = beam[0xC9];
                    vtx[0x8] = beam[0xCA];
                }
            }
            vtx += 0xA;

            *(s16 *)(vtx + 0x0) = (s16)pts[i + 3][0];
            *(s16 *)(vtx + 0x2) = (s16)pts[i + 3][1];
            *(s16 *)(vtx + 0x4) = (s16)pts[i + 3][2];
            if (*(s32 *)(obj + 0x88) != 0) {
                if (i + 3 < 4) {
                    vtx[0x9] = beam[0xCB];
                } else {
                    vtx[0x6] = beam[0xC8];
                    vtx[0x7] = beam[0xC9];
                    vtx[0x8] = beam[0xCA];
                }
            }
            vtx += 0xA;

            i += 4;
        } while (i != count);
    }
    *(s32 *)(obj + 0x88) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o76/overlay_76/beamControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void beamScroll(s32 arg0) {
    u8 *var_a0;
    u8 *var_v1;
    s32 var_v0;
    s32 i;

    D_overlay_76_04C00D14 = (s16)((D_overlay_76_04C00D14 + (arg0 * 2)) & 0x3FF);
    for (var_v0 = 0; var_v0 < 3; var_v0++) {
        if (var_v0 == 0) {
            var_v1 = D_overlay_76_04C00D38;
            var_a0 = D_overlay_76_04C00DB8;
        } else {
            var_v1 = D_overlay_76_04C00DE8;
            var_a0 = D_overlay_76_04C00E68;
        }
        for (i = 7; i >= 0; i--) {
            *(s16 *)(var_v1 + 0x6) = (s16)(*(s16 *)(var_a0 + 0x0) + D_overlay_76_04C00D14);
            *(s16 *)(var_v1 + 0xA) = (s16)(*(s16 *)(var_a0 + 0x2) + D_overlay_76_04C00D14);
            *(s16 *)(var_v1 + 0xE) = (s16)(*(s16 *)(var_a0 + 0x4) + D_overlay_76_04C00D14);
            var_a0 += 6;
            var_v1 += 0x10;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o76/overlay_76/beamScroll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void beamDraw(Gfx **arg0, MatrixS **arg1, ObjectTransform *arg2) {
    u8 *beam;
    u8 *texp;
    Gfx *gp;
    u32 vtx;
    u16 flags;

    runlinkSetDestructTimer(__MODULE00076, 2, 2);
    beam = *(u8 **)((u8 *)arg2 + 0x68);
    if (beam[0xCC] != 0) {
        camPushModelMtx(arg0, arg1, arg2, 1.0f, 0.0f);
        gp = *arg0; *arg0 = gp + 1;
        gp->words.w0 = 0xE7000000;
        gp->words.w1 = 0;
        gp = *arg0; *arg0 = gp + 1;
        gp->words.w1 = -1U;
        gp->words.w0 = 0xFB000000;
        flags = *(u16 *)(beam + 0xCE);
        if (flags & 1) {
            texDPTextureX(arg0, 0, 0x17, 0);
            gp = *arg0; *arg0 = gp + 1;
            gp->words.w1 = -0x30U;
            gp->words.w0 = 0xFA000000;
            vtx = (u32)(beam + beam[0xCD] * 0x50) + 0x80000000u;
            gp = *arg0; *arg0 = gp + 1;
            gp->words.w0 = (((((vtx & 6) | 0x20) & 0xFF) << 0x10)) | 0x04000000 | 0x30;
            gp->words.w1 = vtx;
            gp = *arg0; *arg0 = gp + 1;
            gp->words.w1 = (u32)&D_84C00D18;
            gp->words.w0 = 0x05100020;
            gp = *arg0; *arg0 = gp + 1;
            gp->words.w1 = 0;
            gp->words.w0 = 0xE7000000;
            flags = *(u16 *)(beam + 0xCE);
        }
        if (flags & 6) {
            texp = *(u8 **)((u8 *)arg2 + 0x6C);
            texDPTextureX(arg0, *(void **)texp, 0x17, 0);
            gp = *arg0; *arg0 = gp + 1;
            gp->words.w1 = -1U;
            gp->words.w0 = 0xFA000000;
            vtx = (u32)(beam + beam[0xCD] * 0x50) + 0x80000000u;
            gp = *arg0; *arg0 = gp + 1;
            gp->words.w0 = (((((vtx & 6) | 0x40) & 0xFF) << 0x10)) | 0x04000000 | 0x58;
            gp->words.w1 = vtx;
            flags = *(u16 *)(beam + 0xCE);
            if (flags & 4) {
                gp = *arg0; *arg0 = gp + 1;
                gp->words.w1 = (u32)&D_84C00DE8;
                gp->words.w0 = 0x05710080;
            }
            if (flags & 2) {
                gp = *arg0; *arg0 = gp + 1;
                gp->words.w1 = (u32)&D_84C00D38;
                gp->words.w0 = 0x05710080;
            }
            gp = *arg0; *arg0 = gp + 1;
            gp->words.w1 = 0;
            gp->words.w0 = 0xE7000000;
        }
        gp = *arg0; *arg0 = gp + 1;
        gp->words.w1 = -1U;
        gp->words.w0 = 0xFA000000;
        camPopModelMtx(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o76/overlay_76/beamDraw.s")
#endif
