#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void func_overlay_30_01E000F4_1F491C4(void *arg0, void *arg1, u8 **arg2);
void func_overlay_30_01E00288_1F49358(void *arg0, void *arg1, void *arg2);
void func_overlay_30_01E00C14_1F49CE4(void *arg0, void *arg1, void *arg2);
s16 func_overlay_30_01E01134_1F4A204(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5, s32 *arg6);
s32 func_overlay_30_01E012F0_1F4A3C0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_overlay_30_01E01508_1F4A5D8(void *arg0, void *arg1, void *arg2);
s32 func_overlay_30_01E018D0_1F4A9A0(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modPhitInit(void *arg0, s32 arg1) {
    u8 *info;
    u8 *list;
    u8 *mesh;
    u8 *data;
    s32 i;
    s8 idx;

    info = *(u8 **)((u8 *)arg0 + 0x40);
    list = *(u8 **)((u8 *)arg0 + 0x6C);
    idx = (s8) info[0x71];
    if (idx >= 0) {
        mesh = *(u8 **)(list + idx * 4);
        data = *(u8 **)mesh;
        if (arg1 & 4) {
            func_overlay_30_01E000F4_1F491C4(mesh, data, (u8 **)(mesh + 0xC));
        } else {
            func_overlay_30_01E000F4_1F491C4(mesh, data, (u8 **)(data + 0x60));
        }
        return;
    }
    i = 0;
    if ((s8) info[0x1F] > 0) {
        do {
            mesh = *(u8 **)(list + i * 4);
            data = *(u8 **)mesh;
            if (arg1 & 4) {
                func_overlay_30_01E000F4_1F491C4(mesh, data, (u8 **)(mesh + 0xC));
            } else {
                func_overlay_30_01E000F4_1F491C4(mesh, data, (u8 **)(data + 0x60));
            }
            i += 1;
        } while (i < (s8) info[0x1F]);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/modPhitInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_30_01E000F4_1F491C4(void *arg0, void *arg1, u8 **arg2) {
    u8 *block;
    s32 *clr;
    s32 n;
    s32 count14;
    u8 *vtx;
    u8 *ptr;
    u8 *end;
    s32 size;
    s32 delay;

    if ((*(s16 *)((u8 *)arg1 + 0x4E) == 0) && (*arg2 == NULL)) {
        /* sig mismatch: mmAlloc2 is void in the header, asm reads the returned $v0 */
        block = ((void *(*)(s32, u32))mmAlloc2)(0x8000, 0xFF0000FFU);
        if (block != NULL) {
            clr = (s32 *)block;
            for (n = 0x2000; n != 0; n -= 4) {
                clr[0] = 0;
                clr[1] = 0;
                clr[2] = 0;
                clr[3] = 0;
                clr += 4;
            }
            *arg2 = block;
            *(u8 **)block = block + 0x14;
            count14 = *(s16 *)((u8 *)arg1 + 0x14);
            vtx = mmAlign4(block + (count14 * 0xE) + 0x14);
            *(u8 **)(*arg2 + 4) = vtx;
            ptr = vtx + (count14 * 4);
            *(u8 **)(*arg2 + 8) = ptr;
            end = mmAlign4(ptr + count14);
            func_overlay_30_01E00C14_1F49CE4(arg0, arg1, *arg2);
            *(u8 **)(*arg2 + 0xC) = end;
            size = (end + ((*(u16 *)(*arg2 + 0x10) + *(u16 *)(*arg2 + 0x12)) * 0x10)) - block;
            if (size >= 0x8001) {
                mmFree(*arg2);
                *arg2 = NULL;
                return;
            }
            delay = mmGetDelay();
            mmSetDelay(0);
            mmFree(block);
            mmAllocAtAddr(size, block, 0xFF0000FFU);
            mmSetDelay(delay);
            func_overlay_30_01E00288_1F49358(arg0, arg1, *arg2);
            func_overlay_30_01E01508_1F4A5D8(arg0, arg1, *arg2);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/func_overlay_30_01E000F4_1F491C4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_30_01E00288_1F49358(void *arg0, void *arg1, void *arg2) {
    u8 *groups;
    u8 *ents;
    u8 *recs;
    u8 *flags8;
    u8 *planes;
    u8 *verts;
    u8 *grp;
    u8 *ent;
    u8 *rec;
    u8 *pl;
    u8 *pli;
    u8 *p;
    u8 *vA;
    u8 *vB;
    u8 *vX;
    s32 g;
    s32 gOff;
    s32 count;
    s32 n;
    s32 n1;
    s32 start;
    s32 end;
    s32 base;
    s32 i;
    s32 eOff;
    s32 k;
    s32 k2;
    s32 kn;
    s32 a2;
    s32 s0;
    s32 s3;
    s32 t2;
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 len;
    f32 f0;
    f32 f2;
    f32 f20;
    f32 f22;
    f32 f24;
    f32 f26;
    f32 f28;
    f32 sA;
    f32 sD;
    f32 sE;
    f32 sF;
    f32 sG;
    f32 nxi;
    f32 nyi;
    f32 nzi;
    f32 nzv;

    groups = *(u8 **)((u8 *)arg1 + 0x24);
    ents = *(u8 **)((u8 *)arg1 + 0x20);
    recs = *(u8 **)arg2;
    flags8 = *(u8 **)((u8 *)arg2 + 8);
    planes = *(u8 **)((u8 *)arg2 + 0xC);
    verts = *(u8 **)((u8 *)arg0 + 4);
    count = *(s16 *)((u8 *)arg1 + 0x16);
    n = 0;

    /* pass 1: one plane per active entry */
    if (count > 0) {
        g = 0;
        gOff = 0;
        do {
            grp = groups + gOff;
            base = *(s16 *)(grp + 6);
            start = *(s16 *)(grp + 8);
            end = *(s16 *)(grp + 0x18);
            if (start < end) {
                i = start;
                eOff = start * 0x10;
                do {
                    ent = ents + eOff;
                    if (!(ent[0] & 0x80)) {
                        vA = verts + (ent[1] + base) * 0xA;
                        vB = verts + (ent[2] + base) * 0xA;
                        vX = verts + (ent[3] + base) * 0xA;
                        ax = (f32) *(s16 *)(vA + 0);
                        ay = (f32) *(s16 *)(vA + 2);
                        az = (f32) *(s16 *)(vA + 4);
                        bx = (f32) *(s16 *)(vB + 0);
                        by = (f32) *(s16 *)(vB + 2);
                        bz = (f32) *(s16 *)(vB + 4);
                        cx = (f32) *(s16 *)(vX + 0);
                        cy = (f32) *(s16 *)(vX + 2);
                        cz = (f32) *(s16 *)(vX + 4);
                        f2 = cz - bz;
                        f0 = by - ay;
                        f26 = cy - by;
                        f24 = bz - az;
                        f22 = cx - bx;
                        nx = (f0 * f2) - (f24 * f26);
                        sA = bx - ax;
                        ny = (f24 * f22) - (sA * f2);
                        nz = (sA * f26) - (f0 * f22);
                        len = sqrtf((nx * nx) + (ny * ny) + (nz * nz));
                        if (len > 0.0f) {
                            nx = nx / len;
                            ny = ny / len;
                            nz = nz / len;
                        }
                        pl = planes + n * 0x10;
                        *(f32 *)(pl + 0) = nx;
                        *(f32 *)(pl + 4) = ny;
                        *(f32 *)(pl + 8) = nz;
                        *(f32 *)(pl + 0xC) = (f32) -((ax * nx) + (ay * ny) + (az * nz));
                        n += 1;
                        rec = recs + i * 0xE;
                        *(s16 *)(rec + 2) = *(s16 *)(rec + 8);
                        *(s16 *)(rec + 4) = *(s16 *)(rec + 0xA);
                        *(s16 *)(rec + 6) = *(s16 *)(rec + 0xC);
                        flags8[i] &= 0xF8;
                    }
                    i += 1;
                    eOff += 0x10;
                } while (i < end);
            }
            g += 1;
            gOff += 0x10;
        } while (g < count);
    }

    /* pass 2: neighbour planes and flag propagation */
    n1 = n;
    if (count > 0) {
        g = 0;
        gOff = 0;
        do {
            grp = groups + gOff;
            base = *(s16 *)(grp + 6);
            start = *(s16 *)(grp + 8);
            end = *(s16 *)(grp + 0x18);
            if (*(u16 *)(grp + 0xC) & 0x880) {
                end = start - 1;
            }
            if (start < end) {
                i = start;
                eOff = start * 0x10;
                do {
                    ent = ents + eOff;
                    if (!(ent[0] & 0x80)) {
                        rec = recs + i * 0xE;
                        s3 = *(s16 *)rec;
                        pli = planes + s3 * 0x10;
                        nxi = *(f32 *)(pli + 0);
                        nyi = *(f32 *)(pli + 4);
                        nzi = *(f32 *)(pli + 8);
                        for (k = 0; k < 3; k++) {
                            kn = k + 1;
                            if (kn >= 3) {
                                kn = 0;
                            }
                            a2 = kn + 1;
                            if (a2 >= 3) {
                                a2 = 0;
                            }
                            s0 = *(u16 *)(rec + 2 + k * 2);
                            t2 = ent[a2 + 1] + base;
                            if (s0 < n1) {
                                pl = planes + s0 * 0x10;
                                vA = verts + (ent[1 + k] + base) * 0xA;
                                vB = verts + (ent[1 + kn] + base) * 0xA;
                                vX = verts + t2 * 0xA;
                                ax = (f32) *(s16 *)(vA + 0);
                                ay = (f32) *(s16 *)(vA + 2);
                                az = (f32) *(s16 *)(vA + 4);
                                bx = (f32) *(s16 *)(vB + 0);
                                by = (f32) *(s16 *)(vB + 2);
                                bz = (f32) *(s16 *)(vB + 4);

                                sF = *(f32 *)(pl + 8) + nzi;
                                f0 = ((*(f32 *)(pl + 4) + nyi) * 10.0f) + ay;
                                sE = by - ay;
                                f2 = ((sF * 10.0f) + az) - bz;
                                sD = bz - az;
                                f22 = (((*(f32 *)(pl + 0) + nxi) * 10.0f) + ax) - bx;
                                f24 = (sE * f2) - (sD * (f0 - by));
                                f28 = bx - ax;
                                f26 = (sD * f22) - (f28 * f2);
                                f20 = (f28 * (f0 - by)) - (sE * f22);
                                nzv = f20;
                                len = sqrtf((f24 * f24) + (f26 * f26) + (f20 * f20));
                                if (len > 0.0f) {
                                    f24 = f24 / len;
                                    nzv = f20 / len;
                                    f26 = f26 / len;
                                }
                                if (s0 != s3) {
                                    for (k2 = 0; k2 < 3; k2++) {
                                        p = recs + s0 * 0xE + k2 * 2 + 2;
                                        if (*(u16 *)p == (u16) s3) {
                                            *(u16 *)p = (u16) (n | 0x8000);
                                        }
                                    }
                                    if ((*(f32 *)(pl + 0xC)
                                         + (((f32) *(s16 *)(vX + 0) * *(f32 *)(pl + 0))
                                            + ((f32) *(s16 *)(vX + 2) * *(f32 *)(pl + 4))
                                            + ((f32) *(s16 *)(vX + 4) * *(f32 *)(pl + 8)))) < 0.0f) {
                                        flags8[i] |= (u8) (1 << k);
                                    }
                                    if (((*(f32 *)(pl + 8) * nzi)
                                         + ((*(f32 *)(pl + 0) * nxi) + (*(f32 *)(pl + 4) * nyi))) < 0.0f) {
                                        sG = sE;
                                        if (by < ay) {
                                            sG = -sE;
                                        }
                                        if (sG <= sqrtf((f28 * f28) + (sD * sD))) {
                                            ent[0] |= (u8) ((1 << k) * 4);
                                        }
                                    }
                                } else {
                                    flags8[i] |= (u8) (1 << k);
                                }
                                *(s16 *)(rec + 2 + k * 2) = (s16) n;
                                pl = planes + n * 0x10;
                                *(f32 *)(pl + 0) = f24;
                                *(f32 *)(pl + 4) = f26;
                                *(f32 *)(pl + 8) = nzv;
                                *(f32 *)(pl + 0xC) = (f32) -((ax * f24) + (ay * f26) + (az * nzv));
                                n += 1;
                            }
                        }
                    }
                    i += 1;
                    eOff += 0x10;
                } while (i < end);
            }
            g += 1;
            gOff += 0x10;
        } while (g < count);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/func_overlay_30_01E00288_1F49358.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_30_01E00C14_1F49CE4(void *arg0, void *arg1, void *arg2) {
    u8 *groups;
    u8 *ents;
    u8 *recs;
    u8 *flags8;
    u8 *grp;
    u8 *ent;
    u8 *rec;
    u8 *p;
    s32 g;
    s32 gOff;
    s32 count;
    s32 total;
    s32 total1;
    s32 start;
    s32 end;
    s32 base;
    s32 i;
    s32 eOff;
    s32 k;
    s32 k2;
    s32 kn;
    s32 s0;
    s32 s2;
    s32 nb;
    s32 r;
    s32 a1;
    s32 t8;
    s32 idxA;
    s32 idxB;
    s32 outA;
    s32 outB;

    groups = *(u8 **)((u8 *)arg1 + 0x24);
    ents = *(u8 **)((u8 *)arg1 + 0x20);
    recs = *(u8 **)arg2;
    flags8 = *(u8 **)((u8 *)arg2 + 8);
    count = *(s16 *)((u8 *)arg1 + 0x16);
    total = 0;

    /* pass 1: per-entry record with the three neighbour links */
    if (count > 0) {
        g = 0;
        gOff = 0;
        do {
            grp = groups + gOff;
            base = *(s16 *)(grp + 6);
            start = *(s16 *)(grp + 8);
            end = *(s16 *)(grp + 0x18);
            if (start < end) {
                i = start;
                eOff = start * 0x10;
                do {
                    ent = ents + eOff;
                    if (!(ent[0] & 0x80)) {
                        rec = recs + i * 0xE;
                        flags8[i] = 0;
                        *(s16 *)rec = (s16) i;
                        for (k = 0; k < 3; k++) {
                            kn = k + 1;
                            if (kn >= 3) {
                                kn = 0;
                            }
                            idxA = ent[1 + k] + base;
                            idxB = ent[1 + kn] + base;
                            nb = func_overlay_30_01E01134_1F4A204(arg0, arg1, i, idxA, idxB, &outA, &outB);
                            if (nb != -1) {
                                *(s16 *)(rec + 8 + k * 2) = (s16) nb;
                            } else {
                                *(s16 *)(rec + 8 + k * 2) = (s16) i;
                            }
                        }
                        total += 1;
                        *(s16 *)(rec + 2) = *(s16 *)(rec + 8);
                        *(s16 *)(rec + 4) = *(s16 *)(rec + 0xA);
                        *(s16 *)(rec + 6) = *(s16 *)(rec + 0xC);
                    }
                    i += 1;
                    eOff += 0x10;
                } while (i < end);
            }
            g += 1;
            gOff += 0x10;
        } while (g < count);
    }

    /* pass 2: renumber against the neighbour list and set the flag bits */
    total1 = total;
    if (count > 0) {
        g = 0;
        gOff = 0;
        do {
            grp = groups + gOff;
            base = *(s16 *)(grp + 6);
            start = *(s16 *)(grp + 8);
            end = *(s16 *)(grp + 0x18);
            if (*(u16 *)(grp + 0xC) & 0x880) {
                end = start - 1;
            }
            if (start < end) {
                i = start;
                eOff = start * 0x10;
                do {
                    ent = ents + eOff;
                    if (!(ent[0] & 0x80)) {
                        rec = recs + i * 0xE;
                        s2 = *(s16 *)rec;
                        for (k = 0; k < 3; k++) {
                            kn = k + 1;
                            if (kn >= 3) {
                                kn = 0;
                            }
                            s0 = *(u16 *)(rec + 2 + k * 2);
                            if (s0 < total1) {
                                a1 = ent[0];
                                t8 = a1 & 2;
                                if ((a1 & 1) && (ents[s0 * 0x10] & 2)) {
                                    r = func_overlay_30_01E018D0_1F4A9A0(arg0, arg1, (u16) s0,
                                            *(u8 **)((u8 *)arg1 + 0x1C) + ((ent[1 + k] + base) * 0xA),
                                            *(u8 **)((u8 *)arg1 + 0x1C) + ((ent[1 + kn] + base) * 0xA));
                                    ent[0] &= 0xFE;
                                    flags8[s0] |= (u8) (1 << (r + 3));
                                } else if (t8 != 0) {
                                    p = ents + s0 * 0x10;
                                    if (p[0] & 1) {
                                        p[0] &= 0xFE;
                                        flags8[i] |= (u8) (1 << (k + 3));
                                    }
                                }
                                if (s0 != s2) {
                                    for (k2 = 0; k2 < 3; k2++) {
                                        p = recs + s0 * 0xE + k2 * 2 + 2;
                                        if (*(u16 *)p == (u16) s2) {
                                            *(u16 *)p = (u16) (total | 0x8000);
                                        }
                                    }
                                }
                                *(s16 *)(rec + 2 + k * 2) = (s16) total;
                                total += 1;
                            }
                        }
                    }
                    i += 1;
                    eOff += 0x10;
                } while (i < end);
            }
            g += 1;
            gOff += 0x10;
        } while (g < count);
    }
    *(s16 *)((u8 *)arg2 + 0x10) = (s16) total1;
    *(s16 *)((u8 *)arg2 + 0x12) = (s16) (total - total1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/func_overlay_30_01E00C14_1F49CE4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_overlay_30_01E01134_1F4A204(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5, s32 *arg6) {
    u8 *groups;
    u8 *ents;
    u8 *verts;
    u8 *grp;
    u8 *ent;
    s32 g;
    s32 count;
    s32 base;
    s32 start;
    s32 end;
    s32 i;
    s32 k;
    s32 kn;

    groups = *(u8 **)((u8 *)arg1 + 0x24);
    ents = *(u8 **)((u8 *)arg1 + 0x20);
    verts = *(u8 **)((u8 *)arg0 + 4);
    count = *(s16 *)((u8 *)arg1 + 0x16);

    for (g = 0; g < count; g++) {
        grp = groups + g * 0x10;
        base = *(s16 *)(grp + 6);
        start = *(s16 *)(grp + 8);
        end = *(s16 *)(grp + 0x18);
        if (*(u16 *)(grp + 0xC) & 0x880) {
            end = start - 1;
        }
        for (i = start; i < end; i++) {
            ent = ents + i * 0x10;
            if (ent[0] & 0x80) {
                continue;
            }
            if (i == arg2) {
                continue;
            }
            for (k = 0; k < 3; k++) {
                kn = k + 1;
                if (kn >= 3) {
                    kn = 0;
                }
                if (func_overlay_30_01E012F0_1F4A3C0(verts, arg3, arg4, ent[1 + k] + base, ent[1 + kn] + base) != 0) {
                    *arg6 = k;
                    *arg5 = g;
                    return (s16) i;
                }
            }
        }
    }
    return -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/func_overlay_30_01E01134_1F4A204.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_30_01E012F0_1F4A3C0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s16 *p1;
    s16 *p2;
    s16 *p3;
    s16 *p4;

    p1 = (s16 *)((u8 *)arg0 + arg1 * 0xA);
    p2 = (s16 *)((u8 *)arg0 + arg2 * 0xA);
    p3 = (s16 *)((u8 *)arg0 + arg3 * 0xA);
    p4 = (s16 *)((u8 *)arg0 + arg4 * 0xA);

    if ((arg1 == arg3) && (arg2 == arg4)) {
        return 1;
    }
    if ((arg1 == arg4) && (arg2 == arg3)) {
        return 1;
    }
    if ((p1[0] == p3[0]) && (p1[1] == p3[1]) && (p1[2] == p3[2])) {
        if ((p2[0] == p4[0]) && (p2[1] == p4[1]) && (p2[2] == p4[2])) {
            return 2;
        }
        return 0;
    }
    if ((p1[0] == p4[0]) && (p1[1] == p4[1]) && (p1[2] == p4[2])) {
        if ((p2[0] == p3[0]) && (p2[1] == p3[1]) && (p2[2] == p3[2])) {
            return 2;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/func_overlay_30_01E012F0_1F4A3C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_30_01E01508_1F4A5D8(void *arg0, void *arg1, void *arg2) {
    u8 *groups;
    u8 *ents;
    u8 *verts;
    u8 *outs;
    u8 *grp;
    u8 *ent;
    u8 *vtx;
    s32 g;
    s32 gOff;
    s32 count;
    s32 start;
    s32 end;
    s32 base;
    s32 i;
    s32 k;
    s32 j;
    s32 minX;
    s32 maxX;
    s32 minY;
    s32 maxY;
    s32 minZ;
    s32 maxZ;
    s32 bits;
    s32 bit;
    s32 lo;
    s32 hi;
    s32 step;
    s32 x;
    s32 y;
    s32 z;

    groups = *(u8 **)((u8 *)arg1 + 0x24);
    ents = *(u8 **)((u8 *)arg1 + 0x20);
    verts = *(u8 **)((u8 *)arg0 + 4);
    outs = *(u8 **)((u8 *)arg2 + 4);
    count = *(s16 *)((u8 *)arg1 + 0x16);

    if (count > 0) {
        g = 0;
        gOff = 0;
        do {
            grp = groups + gOff;
            base = *(s16 *)(grp + 6);
            start = *(s16 *)(grp + 8);
            end = *(s16 *)(grp + 0x18);
            if (*(u16 *)(grp + 0xC) & 0x880) {
                end = start - 1;
            }
            for (i = start; i < end; i++) {
                ent = ents + i * 0x10;
                if (ent[0] & 0x80) {
                    *(s32 *)(outs + i * 4) = 0;
                    continue;
                }
                minX = 0x7D00;
                maxX = -0x7D00;
                minY = 0x7D00;
                maxY = -0x7D00;
                minZ = 0x7D00;
                maxZ = -0x7D00;
                for (k = 0; k < 3; k++) {
                    vtx = verts + (ent[1 + k] + base) * 0xA;
                    x = *(s16 *)(vtx + 0);
                    y = *(s16 *)(vtx + 2);
                    z = *(s16 *)(vtx + 4);
                    if (x > maxX) {
                        maxX = x;
                    }
                    if (x < minX) {
                        minX = x;
                    }
                    if (y > maxY) {
                        maxY = y;
                    }
                    if (y < minY) {
                        minY = y;
                    }
                    if (z > maxZ) {
                        maxZ = z;
                    }
                    if (z < minZ) {
                        minZ = z;
                    }
                }
                bits = 0;
                bit = 1;

                /* X slabs: 8 cells from arg0->unk8C to arg0->unk92 */
                step = ((s32) (*(s16 *)((u8 *)arg0 + 0x92) - *(s16 *)((u8 *)arg0 + 0x8C)) >> 3) + 1;
                lo = *(s16 *)((u8 *)arg0 + 0x8C);
                hi = lo + step;
                for (j = 0; j < 8; j++) {
                    if ((hi >= minX) && (maxX >= lo)) {
                        bits |= bit;
                    }
                    hi += step;
                    lo += step;
                    bit *= 2;
                }

                /* Z slabs: 8 cells from arg0->unk90 to arg0->unk96 */
                step = ((s32) (*(s16 *)((u8 *)arg0 + 0x96) - *(s16 *)((u8 *)arg0 + 0x90)) >> 3) + 1;
                lo = *(s16 *)((u8 *)arg0 + 0x90);
                hi = lo + step;
                for (j = 0; j < 8; j++) {
                    if ((hi >= minZ) && (maxZ >= lo)) {
                        bits |= bit;
                    }
                    hi += step;
                    lo += step;
                    bit *= 2;
                }

                /* Y slabs: 8 cells from arg0->unk8E to arg0->unk94 */
                step = ((s32) (*(s16 *)((u8 *)arg0 + 0x94) - *(s16 *)((u8 *)arg0 + 0x8E)) >> 3) + 1;
                lo = *(s16 *)((u8 *)arg0 + 0x8E);
                hi = lo + step;
                for (j = 0; j < 8; j++) {
                    if ((hi >= minY) && (maxY >= lo)) {
                        bits |= bit;
                    }
                    hi += step;
                    lo += step;
                    bit *= 2;
                }
                *(s32 *)(outs + i * 4) = bits;
            }
            g += 1;
            gOff += 0x10;
        } while (g < count);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/func_overlay_30_01E01508_1F4A5D8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_30_01E018D0_1F4A9A0(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4) {
    s16 *p = (s16 *) arg3;
    s16 *q = (s16 *) arg4;
    u8 *verts = *(u8 **) ((u8 *) arg0 + 0x04);
    u8 *index = *(u8 **) ((u8 *) arg1 + 0x20);
    u8 *ents = *(u8 **) ((u8 *) arg1 + 0x24);
    s16 count = *(s16 *) ((u8 *) arg1 + 0x16);
    s32 ret = -1;
    s32 e;
    s32 k;

    for (e = 0; e < count; e++) {
        u8 *ent = ents + e * 0x10;
        u8 *base = index + arg2 * 0x10;
        s16 t5;

        if (*(u32 *) (ent + 0x0C) & 0x880) {
            continue;
        }
        if ((arg2 < *(s16 *) (ent + 0x08)) || !(arg2 < *(s16 *) (ent + 0x18))) {
            continue;
        }

        t5 = *(s16 *) (ent + 0x06);
        for (k = 0; k < 3; k++) {
            s32 k2 = (k + 1 < 3) ? k + 1 : 0;
            s16 *a = (s16 *) (verts + (base[k + 1] + t5) * 0xA);
            s16 *b = (s16 *) (verts + (base[k2 + 1] + t5) * 0xA);

            if ((p[0] == a[0] && p[1] == a[1] && p[2] == a[2] && q[0] == b[0] && q[1] == b[1] && q[2] == b[2]) ||
                (p[0] == b[0] && p[1] == b[1] && p[2] == b[2] && q[0] == a[0] && q[1] == a[1] && q[2] == a[2])) {
                ret = k;
                break;
            }
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o30/overlay_30/func_overlay_30_01E018D0_1F4A9A0.s")
#endif
