#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern u8 D_overlay_49_03100BD0[];
extern f32 D_overlay_49_03100C10;
extern s32 D_overlay_49_03100C20;
extern s32 D_overlay_49_03100C24;
extern s32 D_overlay_49_03100C28;
extern s32 D_overlay_49_03100C2C;
extern void *D_overlay_49_03100C30;
extern u8 D_overlay_49_03100C38[];

void func_overlay_49_03100668_1F694E0(void);
void func_overlay_49_0310069C_1F69514(s32 arg0, s32 arg1, s32 arg2);
void func_overlay_49_0310078C_1F69604(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_overlay_49_03100878_1F696F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_overlay_49_031009A8_1F69820(void);
void func_overlay_49_03100A84_1F698FC(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 cloneBlobSetup(u8 *arg0) {
    u8 *src = *(u8 **)(arg0 + 0x50);
    u8 *blob = *(u8 **)(src + 0x1C);
    u8 *ptr;
    u8 *elem;
    s32 i;

    blob[0x34] = 0x40;
    blob[0x35] = 0x40;
    blob[0x36] = 0;
    /* sig mismatch: mmAlloc2 is void in the header, asm reads the returned $v0 */
    ptr = ((void *(*)(s32, u32))mmAlloc2)(((0x40 * 0x40) >> 1) + 0x28, 0xFF7F7FFFU);
    *(u8 **)(blob + 0x28) = ptr;
    if (ptr == NULL) {
        return 0;
    }
    ptr = ((void *(*)(s32, u32))mmAlloc2)(((s32)(blob[0x34] * blob[0x35]) >> 1) + 0x28, 0xFF7F7FFFU);
    *(u8 **)(blob + 0x2C) = ptr;
    if (ptr == NULL) {
        return 0;
    }
    *(u8 **)(blob + 0x20) = (u8 *)((((u32)*(u8 **)(blob + 0x28)) & ~7U) + 8);
    *(u8 **)(blob + 0x24) = (u8 *)((((u32)*(u8 **)(blob + 0x2C)) & ~7U) + 8);

    for (i = 0; i < 2; i++) {
        elem = *(u8 **)(blob + 0x20 + i * 4);
        elem[0x00] = blob[0x34];
        elem[0x01] = blob[0x35];
        elem[0x02] = 3;
        elem[0x03] = 0;
        elem[0x04] = 0;
        elem[0x05] = 0;
        *(s16 *)(elem + 0x06) = 0;
        *(s16 *)(elem + 0x08) = 1;
        *(s16 *)(elem + 0x0A) = 0x38;
        *(void **)(elem + 0x0C) = D_overlay_49_03100BD0;
        *(s16 *)(elem + 0x10) = 0;
        *(s16 *)(elem + 0x12) = 0;
        *(s16 *)(elem + 0x14) = 0;
        *(s16 *)(elem + 0x16) = (s16)(((s32)(blob[0x34] * blob[0x35])) >> 1);
        elem[0x18] = 0;
        elem[0x19] = 0;
        elem[0x1A] = 0;
        elem[0x1B] = 0;
        elem[0x1C] = 2;
        elem[0x1D] = 0;
        elem[0x1E] = 2;
        elem[0x1F] = 0;
    }

    *(f32 *)(blob + 0x00) = (f32)*(s32 *)(src + 0x00);
    blob[0x0D] = 1;
    blob[0x0C] = src[0x0C] | 0x20;
    blob[0x0F] = 0;
    *(s16 *)(blob + 0x08) = 0;
    *(s16 *)(blob + 0x0A) = 0;
    *(u8 **)(blob + 0x04) = *(u8 **)(blob + 0x20);
    blob[0x0E] = src[0x0E];
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/cloneBlobSetup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cloneBlobDelete(u8 *arg0) {
    mmFree(*(void **)(arg0 + 0x28));
    mmFree(*(void **)(arg0 + 0x2C));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/cloneBlobDelete.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 cloneBlobCreate(u8 *arg0) {
    u8 **list = *(u8 ***)(arg0 + 0x6C);
    u8 *obj = list[*(s16 *)(arg0 + 0x3A)];
    u8 *desc;
    u8 *src;
    u8 *blob;
    u8 *rel;
    u8 *pos;
    f32 cx;
    f32 cz;
    f32 sc8;
    f32 scale;
    f32 minX;
    f32 minZ;
    f32 maxX;
    f32 maxZ;
    f32 half;
    f32 tmp;
    f32 cur;
    f32 xa;
    f32 xb;
    f32 za;
    f32 zb;
    f32 t;
    s32 flags;
    s32 i;
    s32 off;
    s32 w;
    s32 dx;
    s32 dz;
    s32 lo;
    u8 *bits;

    if (*(s16 *)(obj + 0x0A) != 0) {
        return 0;
    }
    desc = *(u8 **)(obj + 0x00);
    src = *(u8 **)(arg0 + 0x50);
    blob = *(u8 **)(src + 0x1C);
    blob[0x36] = blob[0x36] ^ 1;
    *(u8 **)(blob + 0x04) = *(u8 **)(blob + 0x20 + blob[0x36] * 4);

    D_overlay_49_03100C20 = blob[0x34];
    lo = (blob[0x34] >> 3) * blob[0x35];
    D_overlay_49_03100C28 = blob[0x35];
    bits = *(u8 **)(blob + 0x04) + 0x20;
    for (i = 0; i < lo; i++) {
        *(s32 *)(bits + i * 4) = 0;
    }

    flags = desc[0x2F];
    cx = *(f32 *)(arg0 + 0x0C);
    cz = *(f32 *)(arg0 + 0x14);
    sc8 = *(f32 *)(arg0 + 0x08);
    rel = *(u8 **)(desc + 0x38);
    pos = *(u8 **)(obj + 0x70);

    if (flags != 0) {
        /* minX/maxX: x extents, minZ/maxZ: z extents (m2c f16/f20/f18/f22) */
        minX = 32000.0f;
        maxX = -32000.0f;
        minZ = 32000.0f;
        maxZ = -32000.0f;
        if (flags > 0) {
            for (off = 0; off < flags * 0xC; off += 0xC) {
                half = *(f32 *)(rel + off + 0x8) * sc8;
                tmp = *(f32 *)(pos + off + 0x0) - cx;
                za = *(f32 *)(pos + off + 0x8) - cz;
                xa = tmp + half;
                if (maxX < xa) {
                    maxX = xa;
                }
                xb = tmp - half;
                if (xb < minX) {
                    minX = xb;
                }
                zb = za + half;
                if (maxZ < zb) {
                    maxZ = zb;
                }
                zb = za - half;
                if (zb < minZ) {
                    minZ = zb;
                }
            }
        }
        if (minX < 0.0f) {
            minX = -minX;
        }
        if (minZ < 0.0f) {
            minZ = -minZ;
        }
        if (maxX < minX) {
            maxX = minX;
        }
        if (maxZ < minZ) {
            maxZ = minZ;
        }
        if (maxZ < maxX) {
            cur = maxX + 2.0f;
        } else {
            cur = maxZ + 2.0f;
        }
        t = *(f32 *)(blob + 0x30);
        xa = 2.0f * cur;
        cur = ((100.0f / t) * xa) - 100.0f;
        if ((cur > -5.0f) && (cur < 5.0f)) {
            xa = t;
        } else {
            *(f32 *)(blob + 0x30) = xa;
        }
        *(f32 *)(blob + 0x00) = D_overlay_49_03100C10 * xa;
        scale = 64.0f / xa;
    }
    D_overlay_49_03100C24 = D_overlay_49_03100C20 >> 1;
    D_overlay_49_03100C2C = D_overlay_49_03100C28 >> 1;
    D_overlay_49_03100C30 = *(u8 **)(blob + 0x04) + 0x20;

    flags = desc[0x2F];
    for (i = 0, off = 0; i < flags; i++, off += 0xC) {
        s32 r6 = (s32)(*(f32 *)(rel + off + 0x8) * sc8 * scale);
        s32 dX = (s32)((*(f32 *)(pos + off + 0x0) - cx) * scale);
        if (((-D_overlay_49_03100C24 - r6) < dX) && (dX < (D_overlay_49_03100C24 + r6))) {
            s32 dZ = (s32)((*(f32 *)(pos + off + 0x8) - cz) * scale);
            if (((-D_overlay_49_03100C2C - r6) < dZ) && (dZ < (D_overlay_49_03100C2C + r6))) {
                /* sig mismatch: prototype takes 3 args, asm passes scale, x, z, r, offset */
                ((void (*)(f32, s32, s32, s32, s32))func_overlay_49_0310069C_1F69514)(scale, dX, dZ, r6, off);
                flags = desc[0x2F];
            }
        }
    }
    /* sig mismatch: takes no args, asm passes the scale in $f12 */
    ((void (*)(f32))func_overlay_49_03100A84_1F698FC)(scale);
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/cloneBlobCreate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_49_03100668_1F694E0(void) {
    u8 *p = D_overlay_49_03100C38;
    s32 i = 0;

    do {
        i += 4;
        *(s32 *)(p + 0x0) = 0;
        *(s32 *)(p + 0x4) = 0;
        *(s32 *)(p + 0x8) = 0;
        *(s32 *)(p + 0xC) = 0;
        p += 0x10;
    } while (i != 0x20);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/func_overlay_49_03100668_1F694E0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_49_0310069C_1F69514(s32 arg0, s32 arg1, s32 arg2) {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 s4;

    func_overlay_49_03100668_1F694E0();
    s3 = 0;
    s1 = 3;
    s2 = (arg2 * -2) + 5;
    s4 = arg2;
    s0 = 1 - arg2;
    func_overlay_49_0310078C_1F69604(arg0, arg1, 0, arg2);
    if (arg2 > 0) {
        do {
            s3 += 1;
            if (s0 < 0) {
                s0 += s1;
                s1 += 2;
                s2 += 2;
            } else {
                s0 += s2;
                s1 += 2;
                s2 += 4;
                s4 -= 1;
            }
            func_overlay_49_0310078C_1F69604(arg0, arg1, s3, s4);
        } while (s3 < s4);
    }
    func_overlay_49_031009A8_1F69820();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/func_overlay_49_0310069C_1F69514.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_49_0310078C_1F69604(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 negX = -arg2;
    s32 negY = -arg3;

    func_overlay_49_03100878_1F696F0(arg0, arg1, arg2, arg3);
    func_overlay_49_03100878_1F696F0(arg0, arg1, arg3, arg2);
    func_overlay_49_03100878_1F696F0(arg0, arg1, arg3, negX);
    func_overlay_49_03100878_1F696F0(arg0, arg1, arg2, negY);
    func_overlay_49_03100878_1F696F0(arg0, arg1, negX, negY);
    func_overlay_49_03100878_1F696F0(arg0, arg1, negY, negX);
    func_overlay_49_03100878_1F696F0(arg0, arg1, negY, arg2);
    func_overlay_49_03100878_1F696F0(arg0, arg1, negX, arg3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/func_overlay_49_0310078C_1F69604.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_49_03100878_1F696F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 a0;
    s32 a1;
    u8 newVal;
    u8 *cell;
    u8 cur;
    u8 other;

    a0 = arg0 + arg2 + D_overlay_49_03100C24;
    a1 = arg1 + arg3 + D_overlay_49_03100C2C;
    if (a0 < 0) {
        a0 = 0;
    } else if (a0 >= D_overlay_49_03100C20) {
        a0 = D_overlay_49_03100C20 - 1;
    }
    newVal = a0 | 0x80;
    if (a1 < 0) {
        a1 = 0;
    } else if (a1 >= D_overlay_49_03100C28) {
        a1 = D_overlay_49_03100C28 - 1;
    }
    cell = &D_overlay_49_03100C38[a1 * 2];
    cur = cell[0];
    if (((cur & 0x80) == 0) && !(cell[1] & 0x80)) {
        cell[0] = newVal;
        return;
    }
    if (((cur & 0x80) != 0) && !(cell[1] & 0x80)) {
        if ((s32)newVal < (s32)cur) {
            cell[1] = cur;
            cell[0] = newVal;
            return;
        }
        cell[1] = newVal;
        return;
    }
    other = cell[1];
    if (((cur & 0x80) != 0) && ((other & 0x80) != 0)) {
        if ((s32)newVal < (s32)cur) {
            cell[0] = newVal;
            return;
        }
        if ((s32)other < (s32)newVal) {
            cell[1] = newVal;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/func_overlay_49_03100878_1F696F0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_49_031009A8_1F69820(void) {
    u8 *v0 = D_overlay_49_03100C30;
    u8 *a1;
    s32 count = 0;
    s32 t0;
    s32 t9;
    u8 a2;
    u8 a3;

    if (D_overlay_49_03100C28 > 0) {
        a1 = D_overlay_49_03100C38;
        do {
            a2 = a1[0];
            count += 1;
            if (a2 & 0x80) {
                a3 = a1[1];
                t0 = a2 & ~0x80;
                if (a3 & 0x80) {
                    t9 = t0 & 1;
                    if ((a3 & ~0x80) >= t0) {
                        do {
                            if (t9 != 0) {
                                v0[t0 >> 1] |= 8;
                            } else {
                                v0[t0 >> 1] |= 0x80;
                            }
                            t0 += 1;
                            t9 = t0 & 1;
                        } while ((a1[1] & ~0x80) >= t0);
                    }
                }
            }
            v0 += D_overlay_49_03100C20 >> 1;
            a1 += 2;
        } while (count < D_overlay_49_03100C28);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/func_overlay_49_031009A8_1F69820.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_49_03100A84_1F698FC(void) {
    u8 *v0 = D_overlay_49_03100C30;
    s32 rows = D_overlay_49_03100C28 - 2;
    s32 outer = rows - 1;
    s32 inner;
    s32 col;
    u8 a2;
    u8 t0;
    u8 t2;
    u8 t3;
    u8 t4;
    u8 s0;
    u8 t7;
    u8 t8;
    u8 a2b;

    if (rows != 0) {
        inner = (D_overlay_49_03100C20 >> 1) - 1;
        do {
            col = 0;
            if (inner > 0) {
                do {
                    a2 = v0[0x00];
                    t0 = v0[0x01];
                    t2 = v0[0x20];
                    t3 = v0[0x21];
                    t4 = v0[0x40];
                    s0 = v0[0x41];
                    t7 = t2 & 0xF0;
                    v0[0x20] = t7;
                    t8 = t7 | (((((s32)a2 >> 4) + (a2 & 0xF) + ((s32)t0 >> 4) + ((s32)t2 >> 4) +
                                  ((s32)t3 >> 4) + ((s32)t4 >> 4) + (t4 & 0xF) + ((s32)s0 >> 4)) >> 3) & 0xF);
                    a2b = t3 & 0xF;
                    v0[0x20] = t8;
                    v0[0x21] = a2b;
                    v0[0x21] = (u8)(a2b | ((((a2 & 0xF) + ((s32)t0 >> 4) + (t0 & 0xF) + (t8 & 0xF) + a2b +
                                             (t4 & 0xF) + ((s32)s0 >> 4) + (s0 & 0xF)) * 2) & 0xF0));
                    col += 1;
                    inner = (D_overlay_49_03100C20 >> 1) - 1;
                    v0 += 1;
                } while (col < inner);
            }
            v0 += 1;
            outer -= 1;
        } while (outer != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o49/overlay_49/func_overlay_49_03100A84_1F698FC.s")
#endif
