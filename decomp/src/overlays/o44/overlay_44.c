#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_overlay_44_02C00DB8;
extern s32 D_overlay_44_02C00F34;
extern s32 D_overlay_44_02C010B0;
extern s32 D_overlay_44_02C0122C;
extern f32 D_overlay_44_02C00C3C;
extern f32 D_overlay_44_02C00C40;
extern u8 D_overlay_44_02C00C50[];
extern u8 D_overlay_44_02C01244[];
void amAudioLinesReset(void);
void amSndStop(s32);
s32 amLineDefinitionComplete(s32);
void amSndPlayDirect(s32, u8, u8, f32, u8, void **);
void gsSndpSetParam(s32, s16, u32);
void gsSndpSetPriority(s32, u8);
s32 func_overlay_44_02C007D8_1F643B8(f32, f32, f32, void *, f32 *, f32 *, f32 *);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoInit00044(void) {
    D_overlay_44_02C00DB8 = 0;
    D_overlay_44_02C00F34 = 0;
    D_overlay_44_02C010B0 = 0;
    D_overlay_44_02C0122C = 0;
    amAudioLinesReset();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o44/overlay_44/_AutoInit00044.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAudioLinesReset(void) {
    f32 temp_f20;
    u8 *var_s1;
    u8 *var_s2;
    s32 temp_a0;
    u8 temp_v0;
    s32 w;

    temp_f20 = D_overlay_44_02C00C3C;
    var_s2 = D_overlay_44_02C00C50 + 4;
    var_s1 = D_overlay_44_02C00C50;
    do {
        temp_a0 = *(s32 *)(var_s1 + 0x168);
        *(s32 *)(var_s1 + 0x16C) = 0;
        if (temp_a0 != 0) {
            temp_v0 = var_s1[0x174];
            if (temp_v0 == 0) {
                amSndStop(temp_a0);
            } else if (temp_v0 == 1) {
                amAmbientStop();
            }
            *(s32 *)(var_s1 + 0x168) = 0;
        }
        *(s8 *)(var_s1 + 0x178) = -1;
        *(f32 *)(var_s1 + 0x0) = temp_f20;
        for (w = 0; w < 89; w++) {
            ((f32 *)var_s2)[w] = temp_f20;
        }
        var_s1 += 0x17C;
        var_s2 += 0x17C;
    } while (var_s2 != D_overlay_44_02C01244);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o44/overlay_44/amAudioLinesReset.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amPlayAudioLines(s32 arg0, s32 arg1) {
    /* asm: fp seed lives in stale frame slot 0x228 across calls */
    static u32 sp228;
    u32 var_fp = sp228;
    u8 sp22F = (u8)sp228;
    u8 *rec;
    u8 *pt;
    u8 *s4;
    s32 sp234;
    s32 sp230;
    s32 sp22C;
    s32 sp224;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    s32 sp188[30];
    s32 sp10C[30];
    s32 sp94[30];
    s32 k;
    s32 j;
    s32 count;
    s32 s5;
    s32 s6;
    s32 total;
    s32 sum;
    s32 v1;
    s32 v0_6;
    s32 type;
    s32 temp_a0;
    f32 f0;
    f32 f2;
    f32 f12;

    sp224 = 0;
    sp234 = 0;
    rec = D_overlay_44_02C00C50;
    do {
        if (*(s32 *)(rec + 0x16C) != 0) {
            if (amLineDefinitionComplete(sp234 & 0xFF) != 0) {
                sp22C = 0;
                sp230 = 0;
                if (arg1 > 0) {
                    do {
                        pt = (u8 *)arg0 + (sp230 * 0x4C);
                        s5 = 0;
                        s4 = rec;
                        s6 = *(s32 *)(rec + 0x170);
                        count = *(s8 *)(rec + 0x178);
                        if (count > 0) {
                            for (j = 0; j < count; j++) {
                                sp188[j] = func_overlay_44_02C007D8_1F643B8(*(f32 *)(pt + 0xC), *(f32 *)(pt + 0x10),
                                                                            *(f32 *)(pt + 0x14), s4, &sp20C, &sp208, &sp204);
                                sp10C[j] = 0x40;
                                if (sp188[j] < s6) {
                                    s6 = sp188[j];
                                }
                                s5 += sp188[j];
                                s4 += 0xC;
                            }
                        }
                        total = *(s32 *)(rec + 0x170);
                        f2 = (f32)total;
                        f12 = (f32)rec[0x175];
                        if (rec[0x179] == 0) {
                            v1 = (s32)((1.0f - ((f32)s6 / f2)) * f12);
                        } else {
                            f0 = (f32)(total - s6) / f2;
                            v1 = (s32)(f0 * f0 * f12);
                        }
                        if (v1 >= sp22C) {
                            sp22C = v1;
                            count = *(s8 *)(rec + 0x178);
                            sum = 0;
                            if (count == 1) {
                                var_fp = (u32)sp10C[0];
                            } else {
                                var_fp = 0;
                                if (count > 0) {
                                    for (j = 0; j < count; j++) {
                                        sp94[j] = s5 - sp188[j];
                                        sum += sp94[j];
                                    }
                                    f0 = (f32)sum;
                                    for (j = 0; j < count; j++) {
                                        var_fp = (u32)(s32)((f32)(s32)var_fp + (((f32)sp94[j] / f0) * (f32)sp10C[j]));
                                    }
                                }
                            }
                            if (s6 < 0x190) {
                                var_fp = (u32)(s32)((((f32)((s32)var_fp - 0x40)) * ((f32)s6 / 400.0f)) + 64.0f);
                            }
                        }
                        sp230 = sp230 + 1;
                    } while (sp230 != arg1);
                }
                type = rec[0x174];
                if (type == 0) {
                    v1 = rec[0x176];
                    if (sp22C < v1) {
                        sp22C = v1;
                    }
                    if (sp22C >= 0xB) {
                        sp210 = (f32)rec[0x177] / 100.0f;
                        v0_6 = 0;
                        if ((var_fp >> 24) != 0) {
                            var_fp &= 0xFF;
                            v0_6 = 0x80;
                        }
                        temp_a0 = *(s32 *)(rec + 0x168);
                        if (temp_a0 == 0) {
                            amSndPlayDirect(*(u16 *)(rec + 0x16E), sp22F, (u8)(var_fp & 0xFF), sp210, (u8)v0_6,
                                            (void **)(rec + 0x168));
                        } else {
                            gsSndpSetParam(temp_a0, 8, scalevol(sp22C << 8));
                            gsSndpSetParam(temp_a0, 0x10, *(s32 *)&sp210);
                            if (arg1 != 1) {
                                var_fp = 0x40;
                            }
                            gsSndpSetParam(temp_a0, 4, var_fp);
                            gsSndpSetPriority(temp_a0, rec[0x17A]);
                        }
                    } else {
                        temp_a0 = *(s32 *)(rec + 0x168);
                        if (temp_a0 != 0) {
                            amSndStop(temp_a0);
                        }
                    }
                } else if (type == 1) {
                    if (sp224 < sp22C) {
                        sp224 = sp22C;
                    }
                }
            }
        }
        sp234 = sp234 + 1;
        rec += 0x17C;
    } while (sp234 != 4);
    sp228 = var_fp;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o44/overlay_44/amPlayAudioLines.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAudioLineAddVertex(u8 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8,
                          u16 arg9, u8 arg10, u8 arg11, u8 arg12) {
    u8 *temp_v1;
    u8 *temp_a0;

    if (((s32)arg11 < 4) && ((s32)arg12 < 0x1E)) {
        temp_v1 = D_overlay_44_02C00C50 + (arg11 * 0x17C);
        temp_a0 = temp_v1 + (arg12 * 0xC);
        *(f32 *)(temp_a0 + 0x0) = arg2;
        *(f32 *)(temp_a0 + 0x4) = arg3;
        *(f32 *)(temp_a0 + 0x8) = arg4;
        if (arg12 == 0) {
            *(s32 *)(temp_v1 + 0x16C) = (s32)(arg1 & 0xFFFF);
            temp_v1[0x174] = arg0;
            *(s32 *)(temp_v1 + 0x170) = (s32)arg9;
            temp_v1[0x179] = arg10;
            temp_v1[0x175] = arg6;
            temp_v1[0x176] = arg5;
            temp_v1[0x177] = arg7;
            temp_v1[0x17A] = arg8;
        }
        if ((s8)temp_v1[0x178] < (s32)arg12) {
            temp_v1[0x178] = (u8)arg12;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o44/overlay_44/amAudioLineAddVertex.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_44_02C007D8_1F643B8(f32 arg0, f32 arg1, f32 arg2, void *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    f32 x0 = *(f32 *)((u8 *)arg3 + 0x0);
    f32 y0 = *(f32 *)((u8 *)arg3 + 0x4);
    f32 z0 = *(f32 *)((u8 *)arg3 + 0x8);
    f32 x1 = *(f32 *)((u8 *)arg3 + 0xC);
    f32 y1 = *(f32 *)((u8 *)arg3 + 0x10);
    f32 z1 = *(f32 *)((u8 *)arg3 + 0x14);
    f32 dx = x1 - x0;
    f32 dy = y1 - y0;
    f32 dz = z1 - z0;
    f32 t;
    f32 zz;
    f32 dist;

    if ((x1 == x0) && (dy == 0.0f) && (dz == 0.0f)) {
        t = 0.0f;
    } else {
        t = (((arg0 - x0) * dx) + ((arg1 - y0) * dy) + ((arg2 - z0) * dz)) / ((dx * dx) + (dy * dy) + (dz * dz));
    }
    if (t < 0.0f) {
        *arg4 = x0;
        *arg5 = y0;
        *arg6 = z0;
        dist = sqrtf(((x0 - arg0) * (x0 - arg0)) + ((y0 - arg1) * (y0 - arg1)) + ((z0 - arg2) * (z0 - arg2)));
    } else if (t > 1.0f) {
        *arg4 = x1;
        *arg5 = y1;
        *arg6 = z1;
        dist = sqrtf(((x1 - arg0) * (x1 - arg0)) + ((y1 - arg1) * (y1 - arg1)) + ((z1 - arg2) * (z1 - arg2)));
    } else {
        *arg4 = (t * dx) + x0;
        *arg5 = (t * dy) + y0;
        zz = (t * dz) + z0;
        *arg6 = zz;
        dist = sqrtf(((zz - arg2) * (zz - arg2)) + (((*arg4 - arg0) * (*arg4 - arg0)) + ((*arg5 - arg1) * (*arg5 - arg1))));
    }
    return (s32)dist;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o44/overlay_44/func_overlay_44_02C007D8_1F643B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 amLineDefinitionComplete(s32 arg0) {
    u8 *var_a2;
    s32 var_v1;
    s32 var_a0;
    s32 temp_a1;
    s8 temp_a3;
    f32 temp_f0;

    var_a2 = D_overlay_44_02C00C50 + ((arg0 & 0xFF) * 0x17C);
    temp_a3 = *(s8 *)(var_a2 + 0x178);
    var_v1 = 1;
    if (temp_a3 <= 0) {
        return 0;
    }
    var_a0 = 0;
    temp_a1 = *(s8 *)(var_a2 + 0x178);
    do {
        temp_f0 = *(f32 *)var_a2;
        var_a0 += 1;
        if ((D_overlay_44_02C00C40 == temp_f0) || (D_overlay_44_02C00C40 == (temp_f0 + 1.0f)) ||
            (D_overlay_44_02C00C40 == (temp_f0 + 2.0f))) {
            var_v1 = 0;
        }
        var_a2 += 0xC;
    } while (var_a0 < temp_a1);
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o44/overlay_44/amLineDefinitionComplete.s")
#endif
