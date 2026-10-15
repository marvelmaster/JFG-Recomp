#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 func_overlay_4_00401398_1EF7688(void *arg0, void *arg1);
s32 makeModelGfx(void *dst, void *hdr, s32 a, s32 b, s32 start, s32 end, s32 c);
void func_overlay_4_00401488_1EF7778(void *arg0, void *arg1, s32 arg2, s32 arg3);
void func_overlay_4_004015A8_1EF7898(void *arg0);
void func_overlay_4_00400CB8_1EF6FA8(void *arg0, void **arg1, s32 arg2);
void func_overlay_4_004012BC_1EF75AC(s16 *arg0, s32 arg1, void *arg2);
void rcpFast3d(s32 a0, s32 a1, s32 a2, s32 a3);
void modFreeModel(s32 modelHandle);
void mathOneFloatPY(void *arg0, f32 *arg1);
void matrixID(f32 (*)[4]);
void mathMtxCatF(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
void mathMtxF2L(f32 (*)[4], void *);
void rcpInitDpNoSize(Gfx **dl);
void diRcpTrace();
extern u8 D_1000A0838[];
extern u8 D_80401718[];
extern u8 D_overlay_4_00401730[];
extern u8 D_overlay_4_00401740[];
extern f32 D_overlay_4_004016D8[4][4];
extern f32 D_overlay_4_00401698[4][4];
extern u8 D_overlay_4_00401660[];
extern s8 D_overlay_4_00401728;
extern void *D_overlay_4_00401880[];
extern f32 D_overlay_4_00401754;
extern OSMesgQueue cloneDoneMsgQueue;
s16 dAngle(s16 a, s16 b, f32 c);
void matrix_XYZ_YPR(s16 *arg0, f32 (*arg1)[4]);
extern u8 D_overlay_4_00401760[];
extern u8 D_overlay_4_00401838[];
extern f32 D_overlay_4_00401750;
extern s32 D_overlay_4_004017A4;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 cloneSetupShadow(void *arg0) {
    u8 *obj;
    u8 *src;
    u8 *sub;
    u8 *hdr;
    void **arr;
    void *tmp;
    void **var_v0;
    s32 idx;

    obj = arg0;
    src = *(u8 **) (obj + 0x50);
    sub = *(u8 **) (src + 0x1C);
    if (func_overlay_4_00401398_1EF7688(obj, sub) == 0) {
        return 0;
    }
    *(f32 *) (sub + 0xAC) = 1.0f;
    arr = *(void ***) (obj + 0x6C);
    tmp = arr[(s8) obj[0x3A]];
    *(void **) (sub + 0x60) = tmp;
    idx = *(s8 *) (*(u8 **) (obj + 0x40) + 0x60);
    if (idx >= 0) {
        var_v0 = (void **) tmp;
        *(void **) (sub + 0x64) = arr[idx];
    } else {
        var_v0 = *(void ***) (sub + 0x60);
        *(void ***) (sub + 0x64) = var_v0;
    }
    if (*(u8 *) ((u8 *) (*var_v0) + 0x2F) != 0) {
        *(u8 *) (sub + 0xBA) = 1;
    }
    func_overlay_4_00401488_1EF7778(obj, sub, 0x400, 0xB);

    hdr = *(u8 **) (sub + 0x20) - 0x20;
    hdr[0x00] = 0x40;
    hdr[0x01] = 0x40;
    hdr[0x02] = 5;
    hdr[0x03] = 0;
    hdr[0x04] = 0;
    hdr[0x05] = 0;
    *(s16 *) (hdr + 0x06) = 0;
    *(s16 *) (hdr + 0x08) = 1;
    *(s16 *) (hdr + 0x0A) = 0x38;
    *(void **) (hdr + 0x0C) = D_overlay_4_00401660;
    *(s16 *) (hdr + 0x10) = 0;
    *(s16 *) (hdr + 0x12) = 0;
    *(s16 *) (hdr + 0x14) = 0;
    *(s16 *) (hdr + 0x16) = 0x1000;
    hdr[0x18] = 0;
    hdr[0x19] = 0;
    hdr[0x1A] = 0;
    hdr[0x1B] = 0;
    hdr[0x1C] = 2;
    hdr[0x1D] = 0;
    hdr[0x1E] = 2;
    hdr[0x1F] = 0;
    *(u8 **) (sub + 0x04) = hdr;

    *(f32 *) (sub + 0x00) = *(f32 *) (src + 0x00);
    *(u8 *) (sub + 0x0C) = (u8) (src[0x0C] | 0x20);
    *(u8 *) (sub + 0x0D) = src[0x0D];
    *(u8 *) (sub + 0x0E) = src[0x0E];
    *(u8 *) (sub + 0x0F) = 0;
    *(s16 *) (sub + 0x08) = 0;
    *(s16 *) (sub + 0x0A) = 0;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/cloneSetupShadow.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cloneTasksQueueAndWait(void) {
    void *sp44;
    void *sp3C;
    void **var_s3;
    s32 var_s2;
    void *temp_s0;
    void *var_s1;

    sp3C = NULL;
    var_s2 = 0;
    if (D_overlay_4_00401728 > 0) {
        var_s3 = D_overlay_4_00401880;
        do {
            temp_s0 = *var_s3;
            var_s1 = NULL;
            if (var_s2 > 0) {
                var_s1 = var_s3[-1];
            }
            if (*(u8 *) ((u8 *) temp_s0 + 0xB9) != 0) {
                rcpFast3d(*(s32 *) ((u8 *) temp_s0 + 0x28), *(s32 *) ((u8 *) temp_s0 + 0x30), 3,
                          *(s32 *) ((u8 *) temp_s0 + 0x20));
                *(u8 *) ((u8 *) temp_s0 + 0xB9) = 0;
                if (var_s1 != NULL) {
                    func_overlay_4_004015A8_1EF7898(var_s1);
                }
                osRecvMesg(&cloneDoneMsgQueue, &sp3C, 1);
            }
            var_s2 += 1;
            var_s3 += 1;
        } while (var_s2 < D_overlay_4_00401728);
        /* asm: sp44 is only written when at least one queued clone was seen */
        sp44 = temp_s0;
    }
    func_overlay_4_004015A8_1EF7898(sp44);
    D_overlay_4_00401728 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/cloneTasksQueueAndWait.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cloneDelete(void *arg0) {
    u8 *obj;
    s32 i;

    obj = arg0;
    mmFree(*(void **) (obj + 0x24));
    mmFree(*(void **) (obj + 0x28));
    mmFree(*(void **) (obj + 0x2C));
    if (*(void **) (obj + 0x34) != NULL) {
        mmFree(*(void **) (obj + 0x34));
    }
    if (*(s32 *) (obj + 0x68) != 0) {
        modFreeModel(*(s32 *) (obj + 0x68));
    }
    for (i = 0; i < *(u8 *) (obj + 0xB8); i++) {
        mmFree(*(void **) (obj + 0x38 + 4 * i));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/cloneDelete.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 cloneShadowCreate(void *arg0, s32 arg1, s32 arg2) {
    u8 *obj;
    u8 *sub;
    u8 *shd;
    u8 *fp;
    u8 *lst;
    u8 *lvl;
    u8 *sp148[8];     /* record pointers (asm stack 0x148..0x167) */
    u8 **s0p;
    u8 *rec;
    u8 *ent;
    u8 *e;
    u8 *vtx;
    s16 rot[3];       /* 0x128..0x12C */
    f32 offs[3];      /* 0x134..0x13C: -obj->unkC/unk10/unk14 (stored only) */
    f32 (*sp88)[4];   /* sub + 0x6C */
    f32 spE8[4][4];   /* 0xE8..0x127 */
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spB8;
    s16 ang[2];       /* 0xA0 / 0xA2 */
    s32 count;        /* spA8 / var_a3 */
    s32 rem;
    s32 k;
    s32 n;
    s32 s3;
    s32 i;
    s32 off;
    s16 yaw;
    s16 pitch;
    u8 a1val;
    f32 f0;
    f32 f20;
    f32 f22;
    f32 f24;
    f32 f26;
    f32 f28;
    f32 wgt;
    f32 rad;
    f32 tmp;

    obj = arg0;
    sub = *(u8 **) (*(u8 **) (obj + 0x50) + 0x1C);
    shd = *(u8 **) (sub + 0x60);
    if (shd[0x0A] != 0) {
        if (*(void **) (sub + 0x30) == NULL) {
            return 0;
        }
        sub[0xB9] = 2;
        cloneTaskActive = 1;
        D_overlay_4_00401880[D_overlay_4_00401728] = sub;
        D_overlay_4_00401728 += 1;
        return 1;
    }
    fp = *(u8 **) shd;
    lvl = (u8 *) levelGetLevel();
    count = 0;

    if (arg1 != 0) {
        lst = *(u8 **) (obj + 0x54);
        if ((lst != NULL) && (*(s16 *) (lst + 0xE) >= 2)) {
            /* build record table: record k at D_overlay_4_00401760 + k * 0x48,
             * record +0x40 points at lst entry (0x30 + k * 0x20) */
            rec = D_overlay_4_00401760;
            ent = lst + 0x30;
            i = 1;
            do {
                *(u8 **) (rec + 0x40) = ent;
                i += 1;
                ent += 0x20;
                count += 1;
                rec += 0x48;
            } while (i < *(s16 *) (lst + 0xE));

            /* asm: first pass writes (count & 3) entries, then 4-at-a-time */
            k = 0;
            if (count > 0) {
                rem = count & 3;
                if (rem != 0) {
                    rec = D_overlay_4_00401760;
                    do {
                        sp148[k] = rec;
                        k += 1;
                        rec += 0x48;
                    } while (rem != k);
                    if (k != count) {
                        goto block_15;
                    }
                } else {
block_15:
                    rec = D_overlay_4_00401760 + (k * 0x48);
                    s0p = &sp148[k];
                    {
                        u8 *a0p = rec + 0x48;
                        u8 *a1p = rec + 0x90;
                        u8 *v1p = rec + 0xD8;
                        do {
                            s0p[3] = v1p;
                            v1p += 0x120;
                            s0p[1] = a0p;
                            s0p[2] = a1p;
                            s0p[0] = rec;
                            rec += 0x120;
                            a1p += 0x120;
                            a0p += 0x120;
                            s0p += 4;
                        } while (v1p != D_overlay_4_00401838 + (count * 0x48));
                    }
                }
            }

            /* sort network on key = record->unk40->unk15, descending (asm order) */
            n = count - 1;
            if (n > 0) {
                do {
                    s3 = 0;
                    if (n & 1) {
                        s3 = 1;
                        if (*(*(u8 **) (sp148[0] + 0x40) + 0x15) < *(*(u8 **) (sp148[1] + 0x40) + 0x15)) {
                            u8 *tswap = sp148[0];
                            sp148[0] = sp148[1];
                            sp148[1] = tswap;
                        }
                        if (n != 1) {
                            goto block_23;
                        }
                    } else {
block_23:
                        s0p = &sp148[s3];
                        do {
                            u8 *p0 = s0p[0];
                            u8 *p1 = s0p[1];
                            u8 key1 = *(*(u8 **) (p1 + 0x40) + 0x15);
                            u8 *p2;
                            if (*(*(u8 **) (p0 + 0x40) + 0x15) < key1) {
                                s0p[0] = p1;
                                s0p[1] = p0;
                                p1 = p0;
                                key1 = *(*(u8 **) (p0 + 0x40) + 0x15);
                            }
                            p2 = s0p[2];
                            if (key1 < *(*(u8 **) (p2 + 0x40) + 0x15)) {
                                s0p[1] = p2;
                                s0p[2] = p1;
                            }
                            s0p += 2;
                        } while (s0p != &sp148[n]);
                    }
                    n -= 1;
                } while (n != 0);
            }

            if ((s32) sub[0xD] < count) {
                count = sub[0xD];
            }
            if (count != 0) {
                e = *(u8 **) (sp148[0] + 0x40);
                f20 = *(f32 *) (e + 0x0);
                f22 = *(f32 *) (e + 0x8);
                f24 = *(f32 *) (e + 0x4);
                yaw = (s16) Arctanf(-f20, -f22);
                pitch = (s16) Arctanf(f24, sqrtf((f20 * f20) + (f22 * f22)));
                a1val = e[0x15];
                if ((s32) a1val < (s32) lvl[0xDE]) {
                    wgt = (1.0f / (f32) lvl[0xDE]) * (f32) a1val;
                    ang[0] = dAngle(*(s16 *) (lvl + 0xD4), yaw, wgt);
                    ang[1] = dAngle(*(s16 *) (lvl + 0xD6), pitch, wgt);
                    ang[0] = dAngle(ang[0], *(s16 *) (sub + 0xB4), wgt);
                    ang[1] = dAngle(ang[1], *(s16 *) (sub + 0xB6), wgt);
                    *(s16 *) (sub + 0xB4) = ang[0];
                    *(s16 *) (sub + 0xB6) = ang[1];
                    a1val = lvl[0xDE];
                } else {
                    ang[0] = yaw;
                    ang[1] = pitch;
                    *(s16 *) (sub + 0xB4) = ang[0];
                    *(s16 *) (sub + 0xB6) = ang[1];
                }
                func_overlay_4_004012BC_1EF75AC(ang, a1val, sp148[0]);

                s0p = &sp148[1];
                i = 1;
                if (count >= 2) {
                    do {
                        e = *(u8 **) (*s0p + 0x40);
                        f20 = *(f32 *) (e + 0x0);
                        f22 = *(f32 *) (e + 0x8);
                        f24 = *(f32 *) (e + 0x4);
                        ang[0] = (s16) Arctanf(-f20, -f22);
                        ang[1] = (s16) Arctanf(f24, sqrtf((f20 * f20) + (f22 * f22)));
                        func_overlay_4_004012BC_1EF75AC(ang, e[0x15], *s0p);
                        i += 1;
                        s0p += 1;
                    } while (i != count);
                }
            }
        } else {
            /* asm 0x8A0: no usable entry list */
            count = 0;
            if (lvl[0xDE] != 0) {
                ang[0] = *(s16 *) (lvl + 0xD4);
                ang[1] = *(s16 *) (lvl + 0xD6);
                *(s16 *) (sub + 0xB4) = ang[0];
                *(s16 *) (sub + 0xB6) = ang[1];
                sp148[0] = D_overlay_4_00401760;
                count = 1;
                func_overlay_4_004012BC_1EF75AC(ang, lvl[0xDE], D_overlay_4_00401760);
            }
        }
    } else {
        if (lvl[0xDE] == 0) {
            return 0;
        }
        sp148[0] = D_overlay_4_00401760;
        D_overlay_4_004017A4 = lvl[0xDE];
        count = 1;
        matrixID((f32 (*)[4]) D_overlay_4_00401760);
        *(f32 *) (D_overlay_4_00401760 + 0x14) = 0.0f;
    }

    /* block_47 (asm 0x93C) */
    offs[2] = -*(f32 *) (obj + 0x14);
    offs[1] = -*(f32 *) (obj + 0x10);
    offs[0] = -*(f32 *) (obj + 0xC);
    rot[2] = 0;
    rot[1] = 0;
    rot[0] = 0;
    sp88 = (f32 (*)[4]) (sub + 0x6C);
    matrix_XYZ_YPR(rot, sp88);

    if (sub[0xBA] == 0) {
        spB8 = *(f32 *) (*(u8 **) (obj + 0x40) + 0x5C) * *(f32 *) (obj + 0x8);
    } else if (sub[0xBA] == 1) {
        f24 = 32000.0f;
        f28 = -32000.0f;
        f22 = 32000.0f;
        f26 = -32000.0f;
        for (s3 = 0; s3 < count; s3 += 1) {
            mathMtxCatF(sp88, (f32 (*)[4]) sp148[s3], spE8);
            off = 0;
            for (i = 0; i < (s32) fp[0x2F]; i++) {
                vtx = *(u8 **) (shd + 0x70) + off;
                rad = *(f32 *) (*(u8 **) (fp + 0x38) + off + 0x8) * *(f32 *) (obj + 0x8);
                mathMtxXFMF(spE8, *(f32 *) (vtx + 0x0), *(f32 *) (vtx + 0x4), *(f32 *) (vtx + 0x8),
                            &spD4, &spD0, &spCC);
                f0 = spD4 + rad;
                if (f26 < f0) {
                    f26 = f0;
                }
                f0 = spD4 - rad;
                if (f0 < f22) {
                    f22 = f0;
                }
                f0 = spCC + rad;
                if (f28 < f0) {
                    f28 = f0;
                }
                f0 = spCC - rad;
                if (f0 < f24) {
                    f24 = f0;
                }
                off += 0xC;
            }
        }
        if (f22 < 0.0f) {
            f22 = -f22;
        }
        if (f24 < 0.0f) {
            f24 = -f24;
        }
        if (f26 < f22) {
            f26 = f22;
        }
        if (f28 < f24) {
            f28 = f24;
        }
        if (f28 < f26) {
            f20 = f26 + 10.0f;
        } else {
            f20 = f28 + 10.0f;
        }
        f0 = *(f32 *) (sub + 0xB0);
        f20 = 2.0f * f20;
        tmp = ((100.0f / f0) * f20) - 100.0f;
        if ((tmp > -5.0f) && (tmp < 5.0f)) {
            f20 = f0;
        } else {
            *(f32 *) (sub + 0xB0) = f20;
        }
        *(f32 *) (sub + 0x0) = D_overlay_4_00401750 * f20;
        spB8 = 64.0f / f20;
    } else if (sub[0xBA] == 2) {
        spB8 = *(f32 *) (sub + 0xAC);
    }
    /* asm: spB8 is left as stack garbage when sub->unkBA > 2 */

    matrixID(spE8);
    spE8[0][0] = spB8;
    spE8[1][1] = spB8;
    spE8[2][2] = spB8;
    mathMtxCatF(sp88, spE8, sp88);
    func_overlay_4_00400CB8_1EF6FA8(obj, (void **) sp148, count);
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/cloneShadowCreate.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_4_00400CB8_1EF6FA8(void *arg0, void **arg1, s32 arg2) {
    u8 *sub;
    u8 *o;
    void **arr;
    Gfx *dl;
    void *sp16C;
    void *sp164;
    void *sp158;
    void *temp_s0;
    f32 (*sp4C)[4];
    f32 sp118[4][4];
    f32 spD8[4][4];
    s32 spD0;
    s32 spCC;
    s32 var_s3;
    s32 var_t0;
    s32 i;
    u32 v;
    u32 a3;

    sub = *(u8 **) (*(u8 **) ((u8 *) arg0 + 0x50) + 0x1C);
    sp16C = *(void **) (sub + 0x60);
    sp164 = *(void **) (sub + 0x64);
    if (D_overlay_4_00401728 < 0xF) {
        var_t0 = 0;
        if (*(s16 *) ((u8 *) arg0 + 0x48) == 0x33) {
            var_t0 = 1;
            spD0 = *(s32 *) ((u8 *) arg0 + 0x8C);
            sp158 = *(void **) ((u8 *) arg0 + 0x68);
        }
        var_s3 = *(s32 *) (sub + 0x2C);
        spCC = var_t0;
        dl = *(Gfx **) (sub + 0x28);
        diRcpTrace(dl, D_overlay_4_00401730, 0x25D, arg0);
        segSetBase(&dl, 0, 0);
        segSetBase(&dl, 1, *(s32 *) (sub + 0x20));

        dl->words.w1 = 0x300000;
        dl->words.w0 = 0xBA001402;
        dl++;
        dl->words.w0 = 0xFF88003F;
        dl->words.w1 = *(s32 *) (sub + 0x20) + 0x80000000;
        dl++;
        dl->words.w1 = 0;
        dl->words.w0 = 0xF7000000;
        dl++;
        dl->words.w1 = 0x100100;
        dl->words.w0 = 0xED000000;
        dl++;
        dl->words.w0 = 0xF60FC0FC;
        dl->words.w1 = 0;
        dl++;
        rcpInitDpNoSize(&dl);
        dl->words.w0 = 0xB6000000;
        dl->words.w1 = 0x1F3204;
        dl++;
        dl->words.w1 = 0;
        dl->words.w0 = 0xBB000000;
        dl++;
        dl->words.w0 = 0xBC000002;
        dl->words.w1 = 0;
        dl++;
        dl->words.w0 = 0x03800010;
        dl->words.w1 = (u32) D_80401718;
        dl++;
        dl->words.w0 = 0xBC000404;
        dl->words.w1 = 2;
        dl++;
        dl->words.w0 = 0xBC000C04;
        dl->words.w1 = 2;
        dl++;
        dl->words.w1 = 0xFFFE;
        dl->words.w0 = 0xBC001404;
        dl++;
        dl->words.w0 = 0xBC001C04;
        dl->words.w1 = 0xFFFE;
        dl++;
        dl->words.w0 = 0xED004004;
        dl->words.w1 = 0xFC0FC;
        dl++;

        sp4C = (f32 (*)[4]) (sub + 0x6C);
        if (arg2 - 1 >= 0) {
            i = arg2 - 1;
            do {
                v = *(u8 *) ((u8 *) (*(void **) &arg1[i]) + 0x44) & 0xFF;
                a3 = (v << 0x18) | (v << 0x10) | (v << 8);
                dl->words.w0 = 0xFA000000;
                dl->words.w1 = a3 | 0xFF;
                dl++;
                dl->words.w1 = a3 | 0xFF;
                dl->words.w0 = 0xFB000000;
                dl++;
                mathMtxCatF(sp4C, (f32 (*)[4]) arg1[i], sp118);
                mathMtxCatF(sp118, D_overlay_4_004016D8, sp118);
                mathMtxCatF(sp118, D_overlay_4_00401698, spD8);
                mathMtxF2L(spD8, (void *) var_s3);
                dl->words.w1 = var_s3 + 0x80000000;
                dl->words.w0 = 0x01000040;
                dl++;
                var_s3 += 0x40;
                dl->words.w0 = (((((u32) *(u32 *) ((u8 *) sp16C + 4 * (*(s8 *) ((u8 *) sp16C + 0xB)) + 0x10)) + 0x80000000) & 0xFFFFFF) | 0xBF000000);
                dl->words.w1 = *(u32 *) ((u8 *) sp164 + 4) + 0x80000000;
                dl++;
                dl->words.w0 = 0x02000050;
                dl->words.w1 = (u32) D_1000A0838;
                dl++;
                dl->words.w0 = 0x06000000;
                dl->words.w1 = *(u32 *) (sub + 0x34) + 0x80000000;
                dl++;
                dl->words.w1 = 0;
                dl->words.w0 = 0xBF000000;
                dl++;
                if (spCC != 0) {
                    o = *(u8 **) (*(u8 **) ((u8 *) arg0 + 0x60) + 4);
                    arr = *(void ***) (o + 0x6C);
                    temp_s0 = arr[spD0];
                    mathMtxCatF((f32 (*)[4]) sp158, spD8, sp118);
                    mathMtxF2L(sp118, (void *) var_s3);
                    dl->words.w1 = var_s3 + 0x80000000;
                    dl->words.w0 = 0x01010040;
                    dl++;
                    var_s3 += 0x40;
                    dl->words.w0 = (((((u32) *(u32 *) ((u8 *) temp_s0 + 4 * (*(s8 *) ((u8 *) temp_s0 + 0xB)) + 0x10)) + 0x80000000) & 0xFFFFFF) | 0xBF000000);
                    dl->words.w1 = *(u32 *) ((u8 *) temp_s0 + 4) + 0x80000000;
                    dl++;
                    dl->words.w0 = 0x06000000;
                    dl->words.w1 = *(u32 *) ((u8 *) sub + spD0 * 4 + 0x38) + 0x80000000;
                    dl++;
                    dl->words.w1 = 0;
                    dl->words.w0 = 0xBF000000;
                    dl++;
                }
                i -= 1;
            } while (i >= 0);
        }

        dl->words.w0 = 0xBC00000A;
        dl->words.w1 = 0;
        dl++;
        dl->words.w1 = 0;
        dl->words.w0 = 0xE9000000;
        dl++;
        dl->words.w1 = 0;
        dl->words.w0 = 0xB8000000;
        dl++;
        diRcpTrace(dl, D_overlay_4_00401740, 0x2A7);
        *(u8 *) (sub + 0xB9) = 1;
        *(Gfx **) (sub + 0x30) = dl;
        cloneTaskActive = 1;
        D_overlay_4_00401880[D_overlay_4_00401728] = sub;
        D_overlay_4_00401728 += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/func_overlay_4_00400CB8_1EF6FA8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_4_004012BC_1EF75AC(s16 *arg0, s32 arg1, void *arg2) {
    f32 tmp[3];
    f32 a;
    f32 b;
    f32 c;

    if (arg0[1] < 0) {
        arg0[1] = 0;
    }
    arg0[1] = (s16) (arg0[1] - 0x4000);
    arg0[1] = (s16) (arg0[1] >> 1);
    arg0[1] = (s16) (arg0[1] + 0x4000);
    tmp[0] = 0.0f;
    tmp[1] = 0.0f;
    tmp[2] = -1.0f;
    mathOneFloatPY(arg0, tmp);
    a = tmp[0];
    b = tmp[1];
    c = tmp[2];
    *(s32 *) ((u8 *) arg2 + 0x44) = arg1;
    matrixID(arg2);
    *(f32 *) ((u8 *) arg2 + 0x00) = D_overlay_4_00401754;
    *(f32 *) ((u8 *) arg2 + 0x14) = 0.0f;
    *(f32 *) ((u8 *) arg2 + 0x10) = -(a / b);
    *(f32 *) ((u8 *) arg2 + 0x28) = D_overlay_4_00401754;
    *(f32 *) ((u8 *) arg2 + 0x18) = -(c / b);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/func_overlay_4_004012BC_1EF75AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_4_00401398_1EF7688(void *arg0, void *arg1) {
    u8 *obj;
    u8 *sub;
    void *slot;
    s32 cnt;
    s32 pcnt;

    obj = (u8 *) arg0;
    sub = (u8 *) arg1;
    slot = mmAlloc(0x10B4, 0xFF7F7FFF);
    *(void **) (sub + 0x24) = slot;
    if (slot == NULL) {
        return 0;
    }
    *(u32 *) (sub + 0x20) = ((*(u32 *) (sub + 0x24) + 0x20) & ~0x3F) + 0x80;
    if (*(s16 *) (obj + 0x48) == 1) {
        cnt = 0x28;
        pcnt = 6;
    } else {
        cnt = 0x3C;
        pcnt = 0xA;
    }
    slot = mmAlloc(cnt * 8, 0xFF7F7FFF);
    *(void **) (sub + 0x28) = slot;
    if (slot == NULL) {
        mmFree(*(void **) (sub + 0x24));
        return 0;
    }
    slot = mmAlloc(pcnt << 6, 0xFF7F7FFF);
    *(void **) (sub + 0x2C) = slot;
    if (slot == NULL) {
        mmFree(*(void **) (sub + 0x24));
        mmFree(*(void **) (sub + 0x28));
        return 0;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/func_overlay_4_00401398_1EF7688.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_4_00401488_1EF7778(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *obj;
    u8 *sub;
    u8 *temp_s3;
    u8 *var_s2;
    void **slots;
    void *v0;
    s8 temp_t4;
    s32 var_s0;
    s32 var_s1;

    obj = (u8 *) arg0;
    sub = (u8 *) arg1;
    makeModelGfx(sub + 0x34, *(void **) *(void ***) (sub + 0x64), arg2, arg3, 0, 0xFF, 1);
    if (*(s16 *) (obj + 0x48) != 1 && *(s8 *) (*(u8 **) (obj + 0x40) + 0x20) > 0) {
        var_s0 = 0;
        temp_s3 = *(u8 **) (*(u8 **) (obj + 0x60) + 0x4);
        var_s1 = 0;
        var_s2 = sub + 0x38;
        temp_t4 = *(s8 *) (*(u8 **) (temp_s3 + 0x40) + 0x1F);
        *(s8 *) (sub + 0xB8) = temp_t4;
        if ((temp_t4 & 0xFF) > 0) {
            do {
                slots = *(void ***) (temp_s3 + 0x6C);
                v0 = *(void **) ((u8 *) slots + var_s1);
                makeModelGfx(var_s2, *(void **) v0, arg2, arg3, 0, 0xFF, 1);
                var_s0 += 1;
                var_s1 += 4;
                var_s2 += 4;
            } while (var_s0 < (s32) (u8) *(u8 *) (sub + 0xB8));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/func_overlay_4_00401488_1EF7778.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_4_004015A8_1EF7898(void *arg0) {
    u8 *p;
    u32 *w;
    s32 rows;
    s32 cols;
    s32 sum;
    s32 n;

    p = *(u8 **) ((u8 *) arg0 + 0x20);
    rows = 0x3D;
    do {
        cols = 0x3D;
        do {
            sum = p[0x00] + p[0x01] + p[0x02] + p[0x40] + p[0x42] + p[0x80] + p[0x81] + p[0x82];
            p[0x41] = (u8) (sum >> 3);
            p += 1;
        } while (cols-- != 0);
        p += 2;
    } while (rows-- != 0);
    w = *(u32 **) ((u8 *) arg0 + 0x20);
    n = 0x3FF;
    do {
        *w = (*w & 0xF0F0F0F0) >> 4;
        w += 1;
    } while (n-- != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o4/overlay_4/func_overlay_4_004015A8_1EF7898.s")
#endif
