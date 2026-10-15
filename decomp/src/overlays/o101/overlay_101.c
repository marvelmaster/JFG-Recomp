#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))
#define GFX_NEXT(p)    ((Gfx *)((u8 *)(p) + 8))

extern u8 D_overlay_101_06501040[];
extern u8 D_overlay_101_06501134[];
extern f32 D_overlay_101_06501160;
extern f32 D_overlay_101_06501168;
extern f32 D_overlay_101_06501174;
extern f32 D_overlay_101_0650116C;
extern f32 D_overlay_101_06501170;
extern s32 __MODULE00101;
extern u8 multiPlayerGame;

f32 Sinf(s16 angle);
void *camGetPtr(void);
void objFreeObject(void *obj);
void amSndPlayXYZ(u16 soundID, s32 x, s32 y, s32 z, s32 flags, void *handle);
void runlinkSetDestructTimer(s32 module, s32 a, s32 b);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f1, f32 f2,
                      f32 f3, f32 f4, s32 a12);
void texDPTextureX(Gfx **dl, void *tex, s32 a, s32 b);
void func_overlay_101_0650056C_1FB8724(void *arg0, void *arg1, s32 arg2);
void func_overlay_101_06500000_1FB81B8(void *arg0, void *arg1, s32 arg2, s16 arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_101_06500000_1FB81B8(void *arg0, void *arg1, s32 arg2, s16 arg3) {
    /* asm: arg2/arg3 are clobbered before first use, so they are ignored */
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 *mem;
    u8 *tbl;
    u8 *part;
    u8 *src;
    u8 *rec;
    u8 b0;
    u8 b1;
    s32 s4v;
    s32 s5v;
    s32 s6v;
    s32 s7v;
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    s32 v;
    s32 ang;
    f32 k160;
    f32 k168;
    f32 f20b;
    f32 f24;
    f32 f22;
    f32 f20;
    f32 f18;
    f32 f16;
    f32 f14;
    f32 f12;
    f32 f8;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    u8 c4;
    u8 c5;

    mem = RD_PTR(st, 0x14);
    if (mem == NULL) {
        mem = (u8 *)mmAlloc(0x1720, 0xFFFF);
        RD_PTR(st, 0x14) = mem;
    }
    if (mem != NULL) {
        tbl = RD_PTR(st, 0);
        RD_PTR(st, 0x10) = mem + 0x280;
        RD_PTR(st, 0x18) = mem + 0x280 + 0xB40;
        RD_PTR(st, 0x1C) = mem + 0x280 + 0xB40 + 0x4B0;
        if (tbl != NULL) {
            b0 = RD_U8(tbl, 0);
            b1 = RD_U8(tbl, 1);
            s4v = b0 << 4;
            s5v = b0 << 3;
            s6v = b1 << 4;
            s7v = b1 << 3;
        } else {
            s4v = 0;
            s5v = 0;
            s6v = 0;
            s7v = 0;
        }
        k160 = D_overlay_101_06501160;
        k168 = D_overlay_101_06501168;
        part = RD_PTR(st, 0x10);
        src = D_overlay_101_06501040;

        for (i = 0; i < 0x28; i++) {
            c0 = src[0];
            c1 = src[1];
            c2 = src[2];
            c3 = src[3];
            c4 = src[4];
            c5 = src[5];

            RD_F32(part, 0x24) = (f32)((s32)(c0 << 9) >> 7) - 256.0f;
            RD_F32(part, 0x28) = 256.0f - (f32)((s32)(c1 << 9) >> 7);
            RD_S16(part, 0x2C) = (s16)(((s32)(c0 * s4v) >> 7) + s5v);
            RD_S16(part, 0x2E) = (s16)(s7v - ((s32)(c1 * s6v) >> 7));
            RD_F32(part, 0x30) = (f32)((s32)(c2 << 9) >> 7) - 256.0f;
            RD_F32(part, 0x34) = 256.0f - (f32)((s32)(c3 << 9) >> 7);
            RD_S16(part, 0x38) = (s16)(((s32)(c2 * s4v) >> 7) + s5v);
            RD_S16(part, 0x3A) = (s16)(s7v - ((s32)(c3 * s6v) >> 7));
            RD_F32(part, 0x3C) = (f32)((s32)(c4 << 9) >> 7) - 256.0f;
            RD_F32(part, 0x40) = 256.0f - (f32)((s32)(c5 << 9) >> 7);
            RD_S16(part, 0x44) = (s16)(((s32)(c4 * s4v) >> 7) + s5v);
            RD_S16(part, 0x46) = (s16)(s7v - ((s32)(c5 * s6v) >> 7));
            RD_S16(part, 0) = 0;
            RD_S16(part, 2) = 0;

            /* random angular velocities, magnitude clamped to at least 0x100 */
            v = mathRnd(-0x800, 0x800);
            if (v > 0) {
                if (v < 0x100) {
                    v = 0x100;
                }
            } else if (v >= -0xFF) {
                v = -0x100;
            }
            RD_S16(part, 6) = (s16)v;

            v = mathRnd(-0x800, 0x800);
            if (v > 0) {
                if (v < 0x100) {
                    v = 0x100;
                }
            } else if (v >= -0xFF) {
                v = -0x100;
            }
            RD_S16(part, 8) = (s16)v;

            v = mathRnd(-0x800, 0x800);
            if (v > 0) {
                if (v < 0x100) {
                    v = 0x100;
                }
            } else if (v >= -0xFF) {
                v = -0x100;
            }
            RD_S16(part, 0xA) = (s16)v;

            f24 = RD_F32(part, 0x24);
            f22 = RD_F32(part, 0x30);
            f20 = RD_F32(part, 0x3C);
            f16 = RD_F32(part, 0x28);
            f14 = RD_F32(part, 0x34);
            f12 = RD_F32(part, 0x40);
            f18 = (f24 + f22 + f20) * k160;
            RD_F32(part, 0xC) = f18;
            f8 = (f16 + f14 + f12) * k160;
            RD_F32(part, 0x14) = 0.0f;
            RD_F32(part, 0x24) = f24 - f18;
            RD_F32(part, 0x10) = f8;
            RD_F32(part, 0x28) = f16 - f8;
            RD_F32(part, 0x30) = f22 - f18;
            RD_F32(part, 0x3C) = f20 - f18;
            RD_F32(part, 0x34) = f14 - RD_F32(part, 0x10);
            RD_F32(part, 0x40) = f12 - RD_F32(part, 0x10);

            f20b = (f32)mathRnd(5, 0xF) * k168;
            ang = mathRnd(-0x8000, 0x7FFF);
            RD_F32(part, 0x18) = Sinf(ang) * f20b;
            RD_F32(part, 0x1C) = (f32)mathRnd(0, 0x14) * k168;
            RD_F32(part, 0x20) = Cosf(ang) * f20b;

            part += 0x48;
            src += 6;
        }

        /* fill the 0x28 index records (16 bytes each) */
        rec = RD_PTR(st, 0x14);
        a = 0;
        for (i = 0; i < 0x28; i++) {
            rec[1] = (u8)a;
            a++;
            rec[2] = (u8)a;
            a++;
            rec[3] = (u8)a;
            a++;
            rec[0] = 0x40;
            if (a + 3 >= 0x19) {
                a = 0;
            }
            rec += 0x10;
        }

        /* mark the two 0x78-entry blocks */
        for (k = 0; k < 2; k++) {
            rec = RD_PTR(st, 0x18 + 4 * k);
            for (j = 0; j < 30; j++) {
                RD_U8(rec, 0x10) = 0xFF;
                RD_U8(rec, 0x11) = 0xFF;
                RD_U8(rec, 0x12) = 0xFF;
                RD_U8(rec, 0x13) = 0xFF;
                RD_U8(rec, 0x1A) = 0xFF;
                RD_U8(rec, 0x1B) = 0xFF;
                RD_U8(rec, 0x1C) = 0xFF;
                RD_U8(rec, 0x1D) = 0xFF;
                RD_U8(rec, 0x24) = 0xFF;
                RD_U8(rec, 0x25) = 0xFF;
                RD_U8(rec, 0x26) = 0xFF;
                RD_U8(rec, 0x27) = 0xFF;
                rec += 0x28;
                RD_U8(rec, -0x22) = 0xFF;
                RD_U8(rec, -0x21) = 0xFF;
                RD_U8(rec, -0x20) = 0xFF;
                RD_U8(rec, -0x1F) = 0xFF;
            }
        }

        func_overlay_101_0650056C_1FB8724(obj, st, 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o101/overlay_101/func_overlay_101_06500000_1FB81B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_101_0650056C_1FB8724(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 *tbl;
    u8 *out;
    u8 *part;
    u8 *vp;
    s16 *vout;
    u8 *cam;
    u8 b0;
    u8 b1;
    s32 n;
    s32 spDC;
    s32 spD8;
    s32 shX;
    s32 shY;
    s32 camX;
    s32 negCamY;
    s32 i;
    s32 k;
    s32 p;
    s32 v;
    s32 w;
    f32 kRot;
    f32 kVel;
    f32 oSinX;
    f32 oCosX;
    f32 oSinZ;
    f32 oCosZ;
    f32 vel30;
    f32 vel14;
    f32 vel16;
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;
    f32 vx;
    f32 vy;
    f32 x1;
    f32 x2;
    f32 y1;
    f32 z1;
    f32 t0v;
    f32 t2v;
    f32 t12;

    cam = camGetPtr();
    kRot = D_overlay_101_0650116C;
    kVel = D_overlay_101_06501170;
    oSinX = Sinf(-RD_S16(obj, 2));
    oCosX = Cosf(-RD_S16(obj, 2));
    oSinZ = Sinf(-RD_S16(obj, 4));
    oCosZ = Cosf(-RD_S16(obj, 4));
    vel30 = oSinZ * oCosX * kVel;
    vel14 = oCosZ * oCosX * kRot;
    vel16 = oSinX * kRot;

    if (multiPlayerGame != 0) {
        camX = 0;
        negCamY = 0;
    } else {
        camX = RD_S16(cam, 0);
        negCamY = -RD_S16(cam, 2);
    }

    tbl = RD_PTR(st, 0);
    out = RD_PTR(st, 0x14);
    part = RD_PTR(st, 0x10);
    vout = (s16 *)RD_PTR(st, RD_S32(obj, 0x8C) * 4 + 0x18);

    if (tbl != NULL) {
        b0 = RD_U8(tbl, 0);
        b1 = RD_U8(tbl, 1);
        spDC = b0 << 4;
        spD8 = b1 << 4;
        n = 0;
        if (b0 != 0) {
            do {
                n += 1;
            } while (((s32)b0 >> n) != 0);
        }
        shX = 0xB - n;
        n = 0;
        if (b0 != 0) {
            do {
                n += 1;
            } while (((s32)b0 >> n) != 0);
        }
        shY = 0xB - n;
    } else {
        spDC = 0;
        spD8 = 0;
        shX = 0;
        shY = 0;
    }

    for (p = 0; p < 0x28; p++) {
        /* advance the particle k times (arg2 frames) */
        for (k = arg2; k != 0; k--) {
            t0v = RD_F32(part, 0x18);
            t2v = RD_F32(part, 0x1C);
            t12 = RD_F32(part, 0x20);
            RD_F32(part, 0xC) = RD_F32(part, 0xC) + t0v;
            RD_F32(part, 0x10) = RD_F32(part, 0x10) + t2v;
            RD_F32(part, 0x14) = RD_F32(part, 0x14) + t12;
            RD_S16(part, 0) = (s16)(RD_S16(part, 0) + RD_S16(part, 6));
            RD_S16(part, 2) = (s16)(RD_S16(part, 2) + RD_S16(part, 8));
            RD_S16(part, 4) = (s16)(RD_S16(part, 4) + RD_S16(part, 0xA));
            RD_F32(part, 0x18) = t0v + vel30;
            RD_F32(part, 0x1C) = t2v + vel14;
            RD_F32(part, 0x20) = t12 + vel16;
        }

        sx = Sinf(RD_S16(part, 0));
        cx = Cosf(RD_S16(part, 0));
        sy = Sinf(RD_S16(part, 2));
        cy = Cosf(RD_S16(part, 2));
        sz = Sinf(RD_S16(part, 4));
        cz = Cosf(RD_S16(part, 4));

        /* transform the three local vertices into the output shorts */
        vp = part + 0x24;
        for (i = 0; i < 3; i++) {
            vx = RD_F32(vp, 0);
            vy = RD_F32(vp, 4);
            x1 = vx * cz;
            x2 = x1 - vy * sz;
            y1 = vx * sz + vy * cz;
            z1 = y1 * sy;
            vout[0] = (s16)(s32)(RD_F32(part, 0xC) + x2 * cx + z1 * sx);
            vout[1] = (s16)(s32)(RD_F32(part, 0x10) + y1 * cy);
            vout[2] = (s16)(s32)((RD_F32(part, 0x14) + z1 * cx) - x2 * sx);
            vout += 5;
            vp += 0xC;
        }

        v = ((s32)((camX - RD_S16(part, 0)) - RD_S16(obj, 0)) >> shX) + spDC;
        w = ((s32)((negCamY - RD_S16(part, 2)) - RD_S16(obj, 2)) >> shY) + spD8;
        RD_S16(out, 0x4) = (s16)(RD_S16(part, 0x2C) + v);
        RD_S16(out, 0x6) = (s16)(RD_S16(part, 0x2E) + w);
        RD_S16(out, 0x8) = (s16)(RD_S16(part, 0x38) + v);
        RD_S16(out, 0xA) = (s16)(RD_S16(part, 0x3A) + w);
        RD_S16(out, 0xC) = (s16)(RD_S16(part, 0x44) + v);
        RD_S16(out, 0xE) = (s16)(RD_S16(part, 0x46) + w);
        out += 0x10;
        part += 0x48;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o101/overlay_101/func_overlay_101_0650056C_1FB8724.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void glassInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *par = (u8 *)arg1;
    u8 *dl;
    u8 *rec;
    u8 *inner;
    u8 *a3p;
    s32 i;
    s32 t4;
    s32 t2;

    RD_S16(obj, 0) = RD_S16(par, 0xA);
    RD_S16(obj, 2) = RD_S16(par, 0xC);
    RD_S16(obj, 4) = RD_S16(par, 0xE);
    RD_F32(obj, 8) = RD_F32(RD_PTR(obj, 0x40), 0) * (f32)RD_U8(par, 0x10) * D_overlay_101_06501174;
    t4 = RD_U8(par, 0x12) << 8;
    RD_S32(obj, 0x88) = t4;
    if (t4 <= 0) {
        RD_S32(obj, 0x88) = 0x100;
    }
    RD_S32(obj, 0x8C) = 1;

    dl = RD_PTR(obj, 0x68);
    inner = RD_PTR(RD_PTR(obj, 0x6C), 0);
    a3p = RD_PTR(inner, 0);
    t2 = RD_S32(RD_PTR(a3p, 0x18), 0);
    RD_PTR(dl, 4) = dl + 0x20;
    RD_PTR(dl, 8) = dl + 0x40;
    RD_PTR(dl, 0xC) = D_overlay_101_06501134;
    RD_S32(dl, 0) = t2;

    for (i = 0; i != 2; i++) {
        rec = RD_PTR(dl, 4 + 4 * i);
        RD_U8(rec, 0) = 0x40;
        RD_U8(rec, 1) = 0;
        RD_U8(rec, 2) = 1;
        RD_U8(rec, 3) = 2;
        RD_U8(rec, 0x10) = 0x40;
        RD_U8(rec, 0x11) = 0;
        RD_U8(rec, 0x12) = 2;
        RD_U8(rec, 0x13) = 3;
    }

    hitInitObjectHit(obj, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o101/overlay_101/glassInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void glassControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *sp30;
    u8 *sp2C;
    u8 *cam;
    u8 *ptr;
    u8 *vp;
    u8 *v0x;
    u8 a0b;
    u8 a2b;
    s16 vA;
    s16 vT;
    s32 v1;
    s32 t9;
    s32 t6;
    s32 t4;
    s32 ra;
    s32 cx;
    s32 xa;
    s32 xb;
    s32 cy;
    s32 ya;
    s32 yb;

    runlinkSetDestructTimer(__MODULE00101, 2, 2);
    if (!(RD_S16(obj, 6) & 0x400)) {
        sp30 = RD_PTR(obj, 0x68);
        sp2C = RD_PTR(obj, 0x5C);
        cam = camGetPtr();
        v1 = RD_S32(obj, 0x88);
        RD_S32(obj, 0x8C) = 1 - RD_S32(obj, 0x8C);
        if (v1 <= 0) {
            t9 = v1 - arg1;
            RD_S32(obj, 0x88) = t9;
            if (-t9 >= 0xB5) {
                v0x = RD_PTR(obj, 0x3C);
                if (v0x != NULL && (RD_U8(v0x, 3) & 1)) {
                    RD_S16(obj, 6) = (s16)(RD_S16(obj, 6) | 0x400);
                } else {
                    objFreeObject(obj);
                }
            } else {
                func_overlay_101_0650056C_1FB8724(obj, sp30, arg1);
            }
        } else {
            ptr = RD_PTR(sp30, 0);
            a0b = RD_U8(ptr, 0);
            a2b = RD_U8(ptr, 1);
            vA = (s16)(-RD_S16(obj, 0));
            vT = (s16)(-RD_S16(obj, 2));
            if (multiPlayerGame == 0) {
                vA = (s16)(vA + RD_S16(cam, 0));
                vT = (s16)(vT - RD_S16(cam, 2));
            }
            t4 = a0b * 16;
            ra = a2b * 16;
            vp = RD_PTR(sp30, RD_S32(obj, 0x8C) * 4 + 4) + 0x10;
            cx = t4 + (((s32)(a0b * vA)) >> 11);
            xa = cx + t4;
            xb = cx - t4;
            RD_S16(vp, -0xC) = (s16)xa;
            RD_S16(vp, -0x8) = (s16)xa;
            RD_S16(vp, -0x4) = (s16)xb;
            RD_S16(vp, 0x4) = (s16)xa;
            RD_S16(vp, 0x8) = (s16)xb;
            RD_S16(vp, 0xC) = (s16)xb;
            cy = ra + (((s32)(a2b * vT)) >> 11);
            ya = cy - ra;
            yb = cy + ra;
            RD_S16(vp, -0xA) = (s16)ya;
            RD_S16(vp, -0x6) = (s16)yb;
            RD_S16(vp, -0x2) = (s16)yb;
            RD_S16(vp, 0x6) = (s16)ya;
            RD_S16(vp, 0xA) = (s16)yb;
            RD_S16(vp, 0xE) = (s16)ya;

            if (RD_S8(sp2C, 0x12A) != 0) {
                t6 = RD_S32(obj, 0x88) - RD_S16(sp2C, 0x130);
                RD_S32(obj, 0x88) = t6;
                if (t6 <= 0) {
                    RD_S32(obj, 0x88) = 0;
                    v0x = RD_PTR(obj, 0x4C);
                    RD_U16(v0x, 0xA) = (u16)(RD_U16(v0x, 0xA) & 0xFFFE);
                    func_overlay_101_06500000_1FB81B8(obj, sp30, cy, vA);
                    amSndPlayXYZ(0xD3, RD_S32(obj, 0xC), RD_S32(obj, 0x10), RD_S32(obj, 0x14), 4, 0);
                    if (RD_S32(sp30, 0x10) == 0) {
                        objFreeObject(obj);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o101/overlay_101/glassControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void glassDraw(Gfx **arg0, MatrixS **arg1, ObjectTransform *arg2) {
    u8 *obj = (u8 *)arg2;
    u8 *data;
    Gfx *dl;
    u32 tag;
    u32 a1v;
    u32 t3v;
    s32 t0v;
    s32 t1v;
    s32 t2v;
    s32 t4v;
    s32 a3v;

    runlinkSetDestructTimer(__MODULE00101, 2, 2);
    data = RD_PTR(obj, 0x68);
    camPushModelMtx(arg0, arg1, arg2, 1.0f, 0.0f);
    texDPTextureX(arg0, *(void **)data, 0xF, 0);

    dl = (Gfx *)*arg0;
    *arg0 = GFX_NEXT(dl);
    dl->words.w0 = 0xFA000000;
    dl->words.w1 = -1U;
    dl = (Gfx *)*arg0;
    *arg0 = GFX_NEXT(dl);
    dl->words.w1 = -1U;
    dl->words.w0 = 0xFB000000;

    t0v = 0x78;
    if (RD_S32(obj, 0x88) > 0) {
        dl = (Gfx *)*arg0;
        *arg0 = GFX_NEXT(dl);
        tag = (u32)RD_S32(data, 0xC) + 0x80000000U;
        dl->words.w0 = ((((tag & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30;
        dl->words.w1 = tag;
        dl = (Gfx *)*arg0;
        *arg0 = GFX_NEXT(dl);
        dl->words.w0 = 0x05110020;
        dl->words.w1 = *(u32 *)(data + RD_S32(obj, 0x8C) * 4 + 4) + 0x80000000U;
    } else {
        t4v = RD_S32(data, 0x14);
        t3v = *(u32 *)(data + RD_S32(obj, 0x8C) * 4 + 0x18);
        do {
            a1v = t3v + 0x80000000U;
            if (t0v < 0x19) {
                a3v = t0v;
                t1v = t0v / 3;
                t0v = 0;
            } else {
                a3v = 0x18;
                t1v = 8;
                t0v -= 0x18;
            }
            dl = (Gfx *)*arg0;
            *arg0 = GFX_NEXT(dl);
            dl->words.w0 = ((((a3v * 8) | (a1v & 6)) & 0xFF) << 0x10) | 0x04000000 |
                           (((a3v * 0xA) + 8) & 0xFFFF);
            dl->words.w1 = a1v;
            dl = (Gfx *)*arg0;
            *arg0 = GFX_NEXT(dl);
            t2v = t1v * 0x10;
            dl->words.w1 = t4v + 0x80000000U;
            dl->words.w0 = ((((((t1v - 1) * 0x10) | 1) & 0xFF) << 0x10) | 0x05000000) | (t2v & 0xFFFF);
            t3v += a3v * 0xA;
            t4v += t2v;
        } while (t0v != 0);
    }
    camRestoreModelMtx(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o101/overlay_101/glassDraw.s")
#endif
