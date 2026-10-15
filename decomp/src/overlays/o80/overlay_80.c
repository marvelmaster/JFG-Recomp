#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_80_05001490[];
extern s16 D_overlay_80_05001510[];
extern f32 D_overlay_80_05001540;
s32 objGetObjList(s32 *start, s32 *end);
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))
#define WR_PTR(p, off, v) (*(void **)((u8 *)(p) + (off)) = (v))
extern f32 D_overlay_80_05001544;
extern f32 D_overlay_80_05001548;
extern f32 D_overlay_80_0500154C;
extern f32 D_overlay_80_05001568;
extern f32 D_overlay_80_0500156C;
extern f32 D_overlay_80_05001570;
extern f32 D_overlay_80_05001574;
extern f32 D_overlay_80_05001578;
extern f32 D_overlay_80_0500157C;
extern f32 D_overlay_80_05001580;
extern f32 D_overlay_80_05001584;
extern f32 D_overlay_80_05001588;
extern f32 D_overlay_80_0500158C;
f32 Sinf(s16 angle);
s16 hitPlayer(f32 x, f32 y, f32 z, f32 radius, s32 ignoreY, void **out);
void *func_overlay_80_05001324_1FABABC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void objMoveXYZnocheck(void);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg);
/* decomp: end externs */

// decomp: m2c + cleanup, non-matching
void butterflyInit(void *arg0, void *arg1, s32 arg2) {
    u8 *data;
    u8 *setup;
    u8 *src;
    u8 *dst;
    u8 *q;
    s16 *tbl;
    u8 *tex;
    void **ptrs;
    s32 i;
    s32 mask3;
    s32 mask0;

    setup = (u8 *) arg1;
    data = *(u8 **) ((u8 *) arg0 + 0x68);
    if (arg2 == 0) {
        *(f32 *) ((u8 *) arg0 + 0x20) = 0.0f;
        data[0xFE] = 0;
        *(s32 *) (data + 0x100) = 0;
        *(s16 *) (data + 0x104) = 0;
        data[0xFD] = 0;
        *(s16 *) (data + 0x106) = 0x180;
        *(f32 *) (data + 0x108) = 0.0f;

        /* 8 x 4-byte copies, 16-byte stride */
        for (i = 0; i < 8; i++) {
            src = &D_overlay_80_05001490[i * 0x10];
            dst = data + i * 0x10;
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
        }

        /* 6 entries of three s16 values, each also writes 0xFF colour bytes */
        dst = data;
        for (i = 0; i < 6; i++) {
            tbl = &D_overlay_80_05001510[i * 3];
            *(s16 *) (dst + 0x80) = tbl[0];
            q = dst + 0x0A;
            *(s16 *) (q + 0x78) = tbl[1];
            *(s16 *) (q + 0x7A) = tbl[2];
            q[0x7C] = 0xFF;
            q[0x7D] = 0xFF;
            q[0x7E] = 0xFF;
            q[0x7F] = 0xFF;
            *(s16 *) (q + 0xB2) = tbl[0];
            *(s16 *) (q + 0xB4) = tbl[1];
            *(s16 *) (q + 0xB6) = tbl[2];
            q[0xB8] = 0xFF;
            q[0xB9] = 0xFF;
            q[0xBA] = 0xFF;
            q[0xBB] = 0xFF;
            dst = q;
        }
        data[0xFC] = 1;
    }

    *(f32 *) ((u8 *) arg0 + 0x08) = (f32) setup[0xD] * D_overlay_80_05001540;
    ptrs = *(void ***) ((u8 *) arg0 + 0x6C);
    if ((s32) setup[0xC] < (s8) (*(u8 **) ((u8 *) arg0 + 0x40))[0x1F]) {
        *(void **) (data + 0xF8) = ptrs[setup[0xC]];
    } else {
        *(void **) (data + 0xF8) = ptrs[0];
    }

    tex = *(u8 **) (data + 0xF8);
    mask3 = 0;
    mask0 = 0;
    if (tex != NULL) {
        mask3 = (tex[0] - 1) << 5;
        mask0 = (tex[1] - 1) << 5;
    }

    /* 4 entries of twelve s16 values, masked by mask3 (even word) or mask0 (odd word) */
    src = (u8 *) D_overlay_80_05001490;
    dst = data;
    do {
        *(s16 *) (dst + 0x04) = (s16) (*(s16 *) (src + 0x04) & mask3);
        *(s16 *) (dst + 0x06) = (s16) (*(s16 *) (src + 0x06) & mask0);
        *(s16 *) (dst + 0x08) = (s16) (*(s16 *) (src + 0x08) & mask3);
        *(s16 *) (dst + 0x0A) = (s16) (*(s16 *) (src + 0x0A) & mask0);
        *(s16 *) (dst + 0x0C) = (s16) (*(s16 *) (src + 0x0C) & mask3);
        *(s16 *) (dst + 0x0E) = (s16) (*(s16 *) (src + 0x0E) & mask0);
        *(s16 *) (dst + 0x14) = (s16) (*(s16 *) (src + 0x14) & mask3);
        *(s16 *) (dst + 0x16) = (s16) (*(s16 *) (src + 0x16) & mask0);
        *(s16 *) (dst + 0x18) = (s16) (*(s16 *) (src + 0x18) & mask3);
        *(s16 *) (dst + 0x1A) = (s16) (*(s16 *) (src + 0x1A) & mask0);
        *(s16 *) (dst + 0x1C) = (s16) (*(s16 *) (src + 0x1C) & mask3);
        *(s16 *) (dst + 0x1E) = (s16) (*(s16 *) (src + 0x1E) & mask0);
        src += 0x20;
        dst += 0x20;
    } while (src != (u8 *) D_overlay_80_05001510);

    *(s32 *) (data + 0x110) = 0x100;
    *(s32 *) (data + 0x114) = 0x100;
    *(f32 *) (data + 0x10C) = 1.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o80/overlay_80/butterflyInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void butterflyControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *setup = RD_PTR(obj, 0x3C);
    u8 *data = RD_PTR(obj, 0x68);
    void *hits[8];
    u8 *tgt;
    u8 *tp;
    s32 isBig;
    s16 speedRaw;
    s16 absSpeed;
    s16 turnStep;
    s16 yaw;
    s16 yawDiff;
    f32 rate;
    f32 cap;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 radius;
    f32 scale;
    f32 blend;
    s32 cnt;
    s32 idx;
    s32 t;
    s32 sinV;
    s32 cosV;
    s32 absSin;
    s32 cosA;
    u8 toggle;
    u8 *base;
    f32 lim;
    f32 tpy;

    isBig = (RD_U8(setup, 0x0C) == 2);
    speedRaw = RD_S16(data, 0x106);
    absSpeed = speedRaw;
    if (speedRaw < 0) {
        absSpeed = (s16) (speedRaw * -1);
    }
    rate = D_overlay_80_05001544;
    if (isBig) {
        rate = D_overlay_80_05001544 * D_overlay_80_05001548;
    }
    cap = 3.0f;
    if (isBig) {
        cap = 3.0f * D_overlay_80_0500154C;
    }
    turnStep = (s16) (absSpeed * arg1);

    switch (RD_U8(data, 0xFD)) {
    case 0:
        RD_F32(data, 0x108) = 0.0f;
        radius = (f32) RD_U16(setup, 0x0A);
        if (hitPlayer((f32) RD_S16(setup, 0x04), 0.0f, (f32) RD_S16(setup, 0x08), radius, 1, hits) > 0) {
            RD_U16(data, 0x104) = 0xF0;
            RD_U8(data, 0xFD) = 3;
            WR_PTR(data, 0x100, hits[0]);
        } else {
            tgt = func_overlay_80_05001324_1FABABC((f32) RD_S16(setup, 0x04), 0.0f, (f32) RD_S16(setup, 0x08), radius, 1);
            WR_PTR(data, 0x100, tgt);
            if (tgt != NULL) {
                RD_U16(data, 0x104) = 0xF0;
                RD_U8(data, 0xFD) = 3;
            }
        }
        RD_F32(obj, 0x28) = RD_F32(obj, 0x28) + ((f32) arg1 * D_overlay_80_05001568);
        if (RD_F32(obj, 0x28) >= 1.0f) {
            RD_F32(obj, 0x28) = RD_F32(obj, 0x28) - 1.0f;
        }
        if (isBig) {
            RD_F32(obj, 0x28) = D_overlay_80_0500156C;
        }
        break;

    case 1:
    case 2:
        if (speedRaw < 0x480) {
            RD_S16(data, 0x106) = (s16) (speedRaw + (arg1 * 0x10));
            if (RD_S16(data, 0x106) >= 0x481) {
                RD_S16(data, 0x106) = 0x480;
            }
        }
        dx = RD_F32(obj, 0x0C) - (f32) RD_S16(setup, 0x04);
        dz = RD_F32(obj, 0x14) - (f32) RD_S16(setup, 0x08);
        yaw = RD_S16(obj, 0x00);
        yawDiff = (s16) (Arctanf(dx, dz) - yaw);
        if (yawDiff < 0) {
            if (-turnStep < yawDiff) {
                RD_S16(obj, 0x00) = (s16) (yaw + yawDiff);
            } else {
                RD_S16(obj, 0x00) = (s16) (yaw - turnStep);
            }
        } else if (yawDiff > 0) {
            if (yawDiff < turnStep) {
                RD_S16(obj, 0x00) = (s16) (yaw + yawDiff);
            } else {
                RD_S16(obj, 0x00) = (s16) (yaw + turnStep);
            }
        }
        dy = (f32) RD_S16(setup, 0x06) - RD_F32(obj, 0x10);
        if (dy < 0.0f) {
            RD_F32(obj, 0x20) = RD_F32(obj, 0x20) - (rate * (f32) arg1);
            if (RD_F32(obj, 0x20) < dy) {
                RD_F32(obj, 0x20) = dy;
            }
        } else if (dy > 0.0f) {
            RD_F32(obj, 0x20) = RD_F32(obj, 0x20) + (rate * (f32) arg1);
            if (dy < RD_F32(obj, 0x20)) {
                RD_F32(obj, 0x20) = dy;
            }
        } else {
            RD_F32(obj, 0x20) = 0.0f;
        }
        if (RD_U8(data, 0xFD) == 1) {
            if (hitPlayer((f32) RD_S16(setup, 0x04), 0.0f, (f32) RD_S16(setup, 0x08), (f32) RD_U16(setup, 0x0A), 1, hits) > 0) {
                RD_U16(data, 0x104) = 0x78;
                RD_U8(data, 0xFD) = 3;
                WR_PTR(data, 0x100, hits[0]);
            } else {
                tgt = func_overlay_80_05001324_1FABABC((f32) RD_S16(setup, 0x04), 0.0f, (f32) RD_S16(setup, 0x08), (f32) RD_U16(setup, 0x0A), 1);
                WR_PTR(data, 0x100, tgt);
                if (tgt != NULL) {
                    RD_U16(data, 0x104) = 0xF0;
                    RD_U8(data, 0xFD) = 3;
                }
            }
        }
        if (RD_U8(data, 0xFD) != 3) {
            dy = RD_F32(obj, 0x10) - (f32) RD_S16(setup, 0x06);
            if (sqrtf((dx * dx) + (dy * dy) + (dz * dz)) < 4.0f) {
                objMoveXYZnocheck();
                objMoveXYZ(arg0, -dx, -dy, -dz);
                RD_F32(obj, 0x20) = 0.0f;
                RD_U8(data, 0xFD) = 0;
                RD_F32(data, 0x108) = 0.0f;
            }
        }
        RD_F32(obj, 0x28) = RD_F32(obj, 0x28) + (D_overlay_80_05001570 * (f32) arg1);
        if (RD_F32(obj, 0x28) >= 1.0f) {
            RD_F32(obj, 0x28) = RD_F32(obj, 0x28) - 1.0f;
        }
        break;

    case 3:
        if (speedRaw < 0x480) {
            RD_S16(data, 0x106) = (s16) (speedRaw + (arg1 * 0x10));
            if (RD_S16(data, 0x106) >= 0x481) {
                RD_S16(data, 0x106) = 0x480;
            }
        }
        tp = RD_PTR(RD_PTR(data, 0x100), 0x4C);
        dx = RD_F32(tp, 0x0C) - (f32) RD_S16(setup, 0x04);
        radius = (f32) (RD_U16(setup, 0x0A) * 2);
        dz = RD_F32(tp, 0x14) - (f32) RD_S16(setup, 0x08);
        if ((radius * radius) < ((dx * dx) + (dz * dz))) {
            WR_PTR(data, 0x100, NULL);
            radius = (f32) RD_U16(setup, 0x0A);
            if (hitPlayer((f32) RD_S16(setup, 0x04), 0.0f, (f32) RD_S16(setup, 0x08), radius, 1, hits) > 0) {
                RD_U16(data, 0x104) = 0xF0;
                WR_PTR(data, 0x100, hits[0]);
            } else {
                tgt = func_overlay_80_05001324_1FABABC((f32) RD_S16(setup, 0x04), 0.0f, (f32) RD_S16(setup, 0x08), radius, 1);
                WR_PTR(data, 0x100, tgt);
                if (tgt != NULL) {
                    RD_U16(data, 0x104) = 0xF0;
                }
            }
        }
        tgt = RD_PTR(data, 0x100);
        if (tgt != NULL) {
            tp = RD_PTR(tgt, 0x4C);
            dx = RD_F32(obj, 0x0C) - RD_F32(tp, 0x0C);
            dz = RD_F32(obj, 0x14) - RD_F32(tp, 0x14);
            yaw = RD_S16(obj, 0x00);
            yawDiff = (s16) (Arctanf(dx, dz) - yaw);
            if (yawDiff < 0) {
                if (-turnStep < yawDiff) {
                    RD_S16(obj, 0x00) = (s16) (yaw + yawDiff);
                } else {
                    RD_S16(obj, 0x00) = (s16) (yaw - turnStep);
                }
            } else if (yawDiff > 0) {
                if (yawDiff < turnStep) {
                    RD_S16(obj, 0x00) = (s16) (yaw + yawDiff);
                } else {
                    RD_S16(obj, 0x00) = (s16) (yaw + turnStep);
                }
            }
            dy = RD_F32(tp, 0x10) - RD_F32(obj, 0x10);
            if (dy < 0.0f) {
                RD_F32(obj, 0x20) = RD_F32(obj, 0x20) - (rate * (f32) arg1);
                if (RD_F32(obj, 0x20) < dy) {
                    RD_F32(obj, 0x20) = dy;
                }
            } else if (dy > 0.0f) {
                RD_F32(obj, 0x20) = RD_F32(obj, 0x20) + (rate * (f32) arg1);
                if (dy < RD_F32(obj, 0x20)) {
                    RD_F32(obj, 0x20) = dy;
                }
            }
            if (((dx * dx) + (dz * dz)) < 256.0f) {
                RD_U8(data, 0xFD) = 4;
            }
        } else {
            RD_U8(data, 0xFD) = 1;
        }
        RD_F32(obj, 0x28) = RD_F32(obj, 0x28) + (D_overlay_80_05001574 * (f32) arg1);
        if (RD_F32(obj, 0x28) >= 1.0f) {
            RD_F32(obj, 0x28) = RD_F32(obj, 0x28) - 1.0f;
        }
        break;

    case 4:
        if (speedRaw >= 0x181) {
            RD_S16(data, 0x106) = (s16) (speedRaw - (arg1 * 0x10));
            if (RD_S16(data, 0x106) < 0x180) {
                RD_S16(data, 0x106) = 0x180;
            }
        }
        dx = RD_F32(obj, 0x0C) - (f32) RD_S16(setup, 0x04);
        radius = (f32) (RD_U16(setup, 0x0A) * 2);
        dz = RD_F32(obj, 0x14) - (f32) RD_S16(setup, 0x08);
        if ((radius * radius) < ((dx * dx) + (dz * dz))) {
            RD_U8(data, 0xFD) = 2;
        } else {
            t = RD_U16(data, 0x104);
            if (arg1 < t) {
                RD_U16(data, 0x104) = (u16) (t - arg1);
            } else {
                RD_U16(data, 0x104) = 0;
                cnt = hitPlayer(RD_F32(obj, 0x0C), 0.0f, RD_F32(obj, 0x14), 150.0f, 1, hits);
                if (cnt == 0) {
                    WR_PTR(data, 0x100, NULL);
                    RD_U8(data, 0xFD) = 1;
                } else {
                    idx = cnt;
                    if (idx >= 2) {
                        idx = mathRnd(1, cnt);
                    }
                    RD_U16(data, 0x104) = 0xF0;
                    WR_PTR(data, 0x100, hits[idx - 1]);
                }
            }
            if (RD_U8(data, 0xFD) == 4) {
                tp = RD_PTR(RD_PTR(data, 0x100), 0x4C);
                dx = RD_F32(obj, 0x0C) - RD_F32(tp, 0x0C);
                dz = RD_F32(obj, 0x14) - RD_F32(tp, 0x14);
                if (D_overlay_80_05001578 < ((dx * dx) + (dz * dz))) {
                    RD_U8(data, 0xFD) = 3;
                } else {
                    if (mathRnd(0, 0x64) >= 0x63) {
                        RD_S16(data, 0x106) = (s16) -RD_S16(data, 0x106);
                    }
                    RD_S16(obj, 0x00) = (s16) (RD_S16(obj, 0x00) + (arg1 * RD_S16(data, 0x106)));
                    tpy = RD_F32(tp, 0x10);
                    if ((tpy + 40.0f) < RD_F32(obj, 0x10)) {
                        RD_U8(data, 0xFE) = 0;
                    } else if (RD_F32(obj, 0x10) < tpy) {
                        RD_U8(data, 0xFE) = 1;
                    }
                    if (RD_U8(data, 0xFE) != 0) {
                        RD_F32(obj, 0x20) = RD_F32(obj, 0x20) + (rate * (f32) arg1);
                    } else {
                        RD_F32(obj, 0x20) = RD_F32(obj, 0x20) - (rate * (f32) arg1);
                    }
                    RD_S16(obj, 0x00) = (s16) (RD_S16(obj, 0x00) + RD_S16(data, 0x106));
                }
            }
        }
        RD_F32(obj, 0x28) = RD_F32(obj, 0x28) + (D_overlay_80_0500157C * (f32) arg1);
        if (RD_F32(obj, 0x28) >= 1.0f) {
            RD_F32(obj, 0x28) = RD_F32(obj, 0x28) - 1.0f;
        }
        break;

    case 5:
        RD_S32(obj, 0x84) = 1;
        partUpdateTriggers(arg0, arg1);
        t = RD_S32(data, 0x110) - (arg1 * 0x18);
        RD_F32(data, 0x10C) = RD_F32(data, 0x10C) + (D_overlay_80_05001580 * (f32) arg1);
        RD_S32(data, 0x110) = t;
        if (t < 0x48) {
            cnt = RD_S32(data, 0x114) - (arg1 << 5);
            RD_S32(data, 0x110) = 0x48;
            RD_S32(data, 0x114) = cnt;
            if (cnt <= 0) {
                RD_S32(data, 0x114) = 0;
                objFreeObject(arg0);
            }
        }
        break;
    }

    if (RD_U8(data, 0xFD) != 0) {
        blend = RD_F32(data, 0x108);
        if (blend < cap) {
            RD_F32(data, 0x108) = blend + (0.25f * (f32) arg1);
            if (cap < RD_F32(data, 0x108)) {
                RD_F32(data, 0x108) = cap;
            }
        }
    }

    if (RD_F32(data, 0x108) != 0.0f) {
        if (RD_U8(data, 0xFD) != 5) {
            if (RD_U8(data, 0xFD) == 4) {
                lim = D_overlay_80_05001588;
            } else {
                lim = D_overlay_80_05001584;
            }
            if (isBig) {
                lim = lim * D_overlay_80_0500158C;
            }
            if (RD_F32(obj, 0x20) < -lim) {
                RD_F32(obj, 0x20) = -lim;
            }
            if (lim < RD_F32(obj, 0x20)) {
                RD_F32(obj, 0x20) = lim;
            }
            RD_F32(obj, 0x1C) = Sinf(RD_S16(obj, 0x00)) * -RD_F32(data, 0x108);
            RD_F32(obj, 0x24) = Cosf((s32) RD_S16(obj, 0x00)) * -RD_F32(data, 0x108);
            objMoveXYZ(arg0, RD_F32(obj, 0x1C), RD_F32(obj, 0x20), RD_F32(obj, 0x24));
        }
    }

    toggle = (u8) (1 - RD_U8(data, 0xFC));
    RD_U8(data, 0xFC) = toggle;
    base = data + ((toggle & 0xFF) * 0x3C);
    if (isBig) {
        scale = 65536.0f;
    } else {
        scale = 32768.0f;
    }
    sinV = (s32) (Sinf((s16) (s32) (RD_F32(obj, 0x28) * scale)) * 64.0f);
    cosV = (s32) (Cosf((s32) (RD_F32(obj, 0x28) * scale)) * 64.0f);
    absSin = sinV;
    if (absSin < 0) {
        absSin = -absSin;
    }
    cosA = cosV;
    if ((isBig == 0) && (cosV < 0)) {
        cosA = -cosV;
    }
    RD_S16(base, 0x80) = (s16) -absSin;
    RD_S16(base, 0x82) = (s16) cosA;
    RD_S16(base, 0x8A) = (s16) -absSin;
    RD_S16(base, 0x8C) = (s16) cosA;
    RD_S16(base, 0xA8) = (s16) absSin;
    RD_S16(base, 0xAA) = (s16) cosA;
    RD_S16(base, 0xB2) = (s16) absSin;
    RD_S16(base, 0xB4) = (s16) cosA;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o80/overlay_80/butterflyControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_80_05001324_1FABABC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 start;
    s32 end;
    void **objs;
    void *obj;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    objs = (void **) objGetObjList(&start, &end);
    while (start < end) {
        obj = objs[start];
        start++;
        if (*(s16 *) ((u8 *) obj + 0x48) == 0x32) {
            dx = *(f32 *) ((u8 *) obj + 0x0C) - arg0;
            dz = *(f32 *) ((u8 *) obj + 0x14) - arg2;
            if (arg4 == 0) {
                dy = *(f32 *) ((u8 *) obj + 0x10) - arg1;
                dist = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
            } else {
                dist = sqrtf((dx * dx) + (dz * dz));
            }
            if (dist < arg3) {
                return obj;
            }
        }
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o80/overlay_80/func_overlay_80_05001324_1FABABC.s")
#endif
