#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_800FB080_B1750;
extern s32 D_800FB084_B1754;
void mathOneFloatRPY(void *angles, f32 *vec);
void mathOneFloatYPR(void *angles, f32 *vec);
f32 Powerf(f32 base, s32 n);
f32 Sinf(s32);
s16 dAngle(s16 a, s16 b, f32 c);
void func_80042368(void *arg0, void *arg1, s32 arg2, s32 arg3);
void lobbycamGetFocalPoint(void *cam, f32 *outX, f32 *outY, f32 *outZ);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void staticcamFree(void) {
    D_800FB084_B1754 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/staticcamFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void staticcamAdd(s32 id) {
    D_800FB084_B1754 = id;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/staticcamAdd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void staticcamDelete(s32 id) {
    if (id == D_800FB084_B1754) {
        D_800FB084_B1754 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/staticcamDelete.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 lobbycamInuse(void) {
    return D_800FB080_B1750;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/lobbycamInuse.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 staticcamInuse(void) {
    return D_800FB084_B1754;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/staticcamInuse.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lobbycamGetFocalPoint(void *cam, f32 *outX, f32 *outY, f32 *outZ) {
    f32 vec[3];

    // asm: vec = cam+0x14 / cam+0x18 / cam+0x1C; rotated by the angles at cam
    vec[0] = *(f32 *)((u8 *)cam + 0x14);
    vec[1] = *(f32 *)((u8 *)cam + 0x18);
    vec[2] = *(f32 *)((u8 *)cam + 0x1C);
    if (*(s16 *)((u8 *)cam + 0x6) != 0) {
        mathOneFloatYPR(cam, vec);
    } else {
        mathOneFloatRPY(cam, vec);
    }
    *outX = vec[0] + *(f32 *)((u8 *)cam + 0x8);
    *outY = vec[1] + *(f32 *)((u8 *)cam + 0xC);
    *outZ = vec[2] + *(f32 *)((u8 *)cam + 0x10);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/lobbycamGetFocalPoint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80042368(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *lobby = (u8 *)D_800FB080_B1750;
    u8 *cam = (u8 *)arg0;
    u8 *out = (u8 *)arg1;
    f32 posBlend = 1.0f;
    f32 angBlend = 1.0f;
    f32 fx, fy, fz;
    f32 dx, dy, dz;
    f32 dist2, scale;
    f32 ox, oy, oz;
    f32 rx, rz;
    s16 yaw;
    s16 pitch;

    if (arg3 != 0) {
        posBlend = 1.0f - Powerf(0.875f, arg2);
        angBlend = 1.0f - Powerf(0.9f, arg2);
    }
    *(f32 *)(cam + 0x14) = *(f32 *)(lobby + 0x24);
    *(f32 *)(cam + 0x18) = *(f32 *)(lobby + 0x28);
    *(f32 *)(cam + 0x1C) = *(f32 *)(lobby + 0x2C);
    lobbycamGetFocalPoint(arg0, &fx, &fy, &fz);

    dx = fx - *(f32 *)(lobby + 0x0);
    dy = fy - *(f32 *)(lobby + 0x4);
    dz = fz - *(f32 *)(lobby + 0x8);
    dist2 = (dx * dx) + (dy * dy) + (dz * dz);
    scale = dist2;
    if (dist2 > 0.0f) {
        scale = *(f32 *)(lobby + 0x14) / sqrtf(dist2);
    }

    ox = *(f32 *)(out + 0xC);
    oy = *(f32 *)(out + 0x10);
    oz = *(f32 *)(out + 0x14);
    *(f32 *)(out + 0xC) = ox + (((dx * scale) + fx) - ox) * posBlend;
    *(f32 *)(out + 0x10) = oy + (((dy * scale) + fy + *(f32 *)(lobby + 0x18)) - oy) * posBlend;
    *(f32 *)(out + 0x14) = oz + (((dz * scale) + fz) - oz) * posBlend;

    rx = *(f32 *)(out + 0xC) - fx;
    rz = *(f32 *)(out + 0x14) - fz;
    yaw = (s16)(0x8000 - Arctanf(rx, rz));
    pitch = (s16)Arctanf(*(f32 *)(out + 0x10) - fy, sqrtf((rx * rx) + (rz * rz)));
    *(s16 *)(out + 0x0) = dAngle(*(s16 *)(out + 0x0), yaw, angBlend);
    *(s16 *)(out + 0x2) = dAngle(*(s16 *)(out + 0x2), pitch, angBlend);
    *(s16 *)(out + 0x4) = dAngle(*(s16 *)(out + 0x4), 0, angBlend);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/func_80042368.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lobbycamPosition(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *lobby = (u8 *)D_800FB080_B1750;
    u8 *cam = (u8 *)arg0;
    u8 *out = (u8 *)arg1;
    f32 posBlend = 1.0f;
    f32 angBlend = 1.0f;
    f32 fx, fy, fz;
    f32 tx, tz;
    f32 lx, lz, absz, lim, r, t;
    f32 sinA, cosA;
    f32 dx, dz, dist, dist2, scale;
    f32 candX, candY, candZ;
    f32 ox, oy, oz;
    f32 rx, rz;
    s16 angDiff;
    s16 yaw;

    if (*(s16 *)(lobby + 0x22) < 0x100) {
        func_80042368(arg0, arg1, arg2, arg3);
        return;
    }
    if (arg3 != 0) {
        posBlend = 1.0f - Powerf(0.9f, arg2);
        angBlend = 1.0f - Powerf(0.9375f, arg2);
    }
    *(f32 *)(cam + 0x14) = *(f32 *)(lobby + 0x24);
    *(f32 *)(cam + 0x18) = *(f32 *)(lobby + 0x28);
    *(f32 *)(cam + 0x1C) = *(f32 *)(lobby + 0x2C);
    lobbycamGetFocalPoint(arg0, &fx, &fy, &fz);

    tx = *(f32 *)(lobby + 0x0);
    tz = *(f32 *)(lobby + 0x8);
    if (*(f32 *)(lobby + 0x1C) != 0.0f) {
        // asm: rotate the offset to the focal point into lobby-local space and clamp it
        sinA = Sinf(*(s16 *)(lobby + 0x20));
        cosA = Cosf(*(s16 *)(lobby + 0x20));
        rx = fx - *(f32 *)(lobby + 0x0);
        rz = fz - *(f32 *)(lobby + 0x8);
        lx = (rx * cosA) - (rz * sinA);
        lz = (rx * sinA) + (rz * cosA);
        lim = *(f32 *)(lobby + 0x1C);
        if (lx < -lim) {
            lx = -lim;
        }
        if (lim < lx) {
            lx = lim;
        }
        absz = lz;
        if (lz < 0.0f) {
            absz = -lz;
        }
        if (absz < *(f32 *)(lobby + 0x14)) {
            r = *(f32 *)(lobby + 0x14);
            if (r < sqrtf((lx * lx) + (lz * lz))) {
                t = sqrtf((r * r) - (absz * absz));
                if (lx < 0.0f) {
                    lx += t;
                } else {
                    lx -= t;
                }
            } else {
                lx = 0.0f;
            }
        }
        tx += lx * cosA;
        tz -= lx * sinA;
    }

    dx = tx - fx;
    dz = tz - fz;
    dist2 = (dx * dx) + (dz * dz);
    dist = dist2;
    if (dist2 > 0.0f) {
        dist = sqrtf(dist2);
        scale = *(f32 *)(lobby + 0x14) / dist;
        dx *= scale;
        dz *= scale;
    }
    candX = fx + dx;
    candY = *(f32 *)(lobby + 0x18) + fy;
    candZ = fz + dz;

    angDiff = (s16)(Arctanf(*(f32 *)(lobby + 0x0) - candX, *(f32 *)(lobby + 0x8) - candZ) - *(s16 *)(lobby + 0x20));
    if (((angDiff != 0x7FFF) && ((angDiff < -*(s16 *)(lobby + 0x22)) || (*(s16 *)(lobby + 0x22) < angDiff)))
        || (dist < *(f32 *)(lobby + 0x14))) {
        candX = tx;
        candZ = tz;
    }

    ox = *(f32 *)(out + 0xC);
    oy = *(f32 *)(out + 0x10);
    oz = *(f32 *)(out + 0x14);
    *(f32 *)(out + 0xC) = ox + ((candX - ox) * posBlend);
    *(f32 *)(out + 0x10) = oy + ((candY - oy) * posBlend);
    *(f32 *)(out + 0x14) = oz + ((candZ - oz) * posBlend);

    rx = *(f32 *)(out + 0xC) - fx;
    rz = *(f32 *)(out + 0x14) - fz;
    yaw = (s16)(0x8000 - Arctanf(rx, rz));
    /* asm: pitch (Arctanf of y vs horizontal distance) is computed here but its result is unused */
    *(s16 *)(out + 0x0) = dAngle(*(s16 *)(out + 0x0), yaw, angBlend);
    *(s16 *)(out + 0x2) = dAngle(*(s16 *)(out + 0x2), 0, angBlend);
    *(s16 *)(out + 0x4) = dAngle(*(s16 *)(out + 0x4), 0, angBlend);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/lobbycamPosition.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void staticcamPosition(void *arg0) {
    u8 *st = (u8 *)D_800FB084_B1754;
    u8 *cam = (u8 *)arg0;

    if (st != NULL) {
        *(f32 *)(cam + 0xC) = *(f32 *)(st + 0xC);
        *(f32 *)(cam + 0x10) = *(f32 *)(st + 0x10);
        *(f32 *)(cam + 0x14) = *(f32 *)(st + 0x14);
        *(s16 *)(cam + 0x4) = *(s16 *)(st + 0x4);
        *(s16 *)(cam + 0x2) = -*(s16 *)(st + 0x2);
        *(s16 *)(cam + 0x0) = (s16)(0x8000 - *(s16 *)(st + 0x0));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/staticcamera/staticcamPosition.s")
#endif
