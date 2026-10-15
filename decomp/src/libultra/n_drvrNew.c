#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_800A97E0_AA3E0[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8008DD20(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    if ((arg0 - 200.0f) <= arg1) {
        arg1 = arg0 - 200.0f;
    }
    sp3C = atan2f(arg1 * 3.1415927f, arg0);
    sp38 = sp3C * sp3C;
    sp34 = (sp3C * 1.4142137f) / arg2;
    arg3[0] = sp38 / (1.0f + sp38 + sp34);
    arg3[1] = arg3[0] * 2.0f;
    arg3[2] = arg3[0];
    arg4[1] = ((sp38 - 1.0f) * 2.0f) / (1.0f + sp38 + sp34);
    arg4[2] = ((1.0f + sp38) - sp34) / (1.0f + sp38 + sp34);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_drvrNew/func_8008DD20.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* fx is a struct fx: s16 unk00 (rate in), s16 unk02, s32 unk28, s16 unk08[16] */
void n_alFxInitlpfilter(void *fx) {
    s32 i;
    s32 tmp;
    s16 spE;
    f32 ratio;
    f32 sp8;
    f32 sp4;

    tmp = (s32)((f32)*(s16 *)fx * 16384.0f);
    spE = (s16)(tmp >> 15);
    *(s16 *)((u8 *)fx + 0x02) = (s16)(s32)(16384.0f - (f32)spE);
    *(s32 *)((u8 *)fx + 0x28) = 0;
    for (i = 0; i < 8; i++) {
        *(s16 *)((u8 *)fx + 0x08 + i * 2) = 0;
    }
    *(s16 *)((u8 *)fx + 0x08 + 8 * 2) = spE;
    i = 9;
    ratio = (f32)spE / 16384.0f;
    sp8 = ratio;
    sp4 = ratio;
    for (; i < 16; i++) {
        sp4 *= sp8;
        *(s16 *)((u8 *)fx + 0x08 + i * 2) = (s16)(s32)(sp4 * 16384.0f);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_drvrNew/n_alFxInitlpfilter.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 alSemitones2Ratio(s32 arg0) {
    f32 result;
    f32 base;
    s32 n;

    n = arg0;
    result = 1.0f;
    if (n >= 0) {
        base = 1.0594631f;
    } else {
        base = 0.9438743f;
        n = -n;
    }
    while (n != 0) {
        if (n & 1) {
            result *= base;
        }
        base *= base;
        n >>= 1;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_drvrNew/alSemitones2Ratio.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alFxInitlpfilter_mono(void *fx, f32 arg1) {
    s32 i;
    f32 sp30[3];
    f32 sp24[3];
    f32 scale;

    if (*(s16 *)((u8 *)fx + 0x02) == 0) {
        return;
    }
    if (*(s16 *)((u8 *)fx + 0x02) < 0xA) {
        *(s16 *)((u8 *)fx + 0x02) = 0xA;
    }
    func_8008DD20(arg1, (f32)*(s16 *)fx + 10.0f, (f32)*(s16 *)((u8 *)fx + 0x02) / 10.0f, sp30, sp24);
    for (i = 3; i < 8; i++) {
        *(s16 *)((u8 *)fx + 0x08 + i * 2) = 0;
    }
    scale = 26768.0f - ((f32)*(s16 *)((u8 *)fx + 0x02) * 128.0f);
    *(s16 *)((u8 *)fx + 0x08) = (s16)(s32)(sp30[0] * scale);
    *(s16 *)((u8 *)fx + 0x0A) = (s16)(s32)(sp30[1] * scale);
    *(s16 *)((u8 *)fx + 0x0C) = 0;
    *(s16 *)((u8 *)fx + 0x18) = (s16)(s32)(sp24[1] * -16384.0f);
    *(s16 *)((u8 *)fx + 0x1A) = (s16)(s32)(sp24[2] * -16384.0f);
    for (i = 10; i < 16; i++) {
        *(s16 *)((u8 *)fx + 0x08 + i * 2) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_drvrNew/n_alFxInitlpfilter_mono.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alFxNew(void **arg0, void *arg1, s16 arg2, ALHeap *arg3) {
    u8 *fxobj;
    s32 *tbl;
    s32 idx;
    u16 i;
    u16 j;
    u8 *elem;
    u8 *sub;
    s32 tmp;
    f32 var_f8;

    tbl = NULL;
    fxobj = alHeapDBAlloc(NULL, 0, arg3, 1, 0x30);
    *arg0 = fxobj;
    /* asm: arg1 indexed by a byte offset (arg2) for the type byte, and by arg2*4 for the table pointer */
    if (*((u8 *)arg1 + arg2 + 0x1C) == 6) {
        tbl = *(s32 **)((u8 *)arg1 + arg2 * 4 + 0x20);
    } else {
        tbl = D_800A97E0_AA3E0;
    }

    idx = 0;
    *(u8 *)(fxobj + 0x08) = (u8)tbl[idx];
    idx++;
    *(s32 *)(fxobj + 0x00) = tbl[idx];
    idx++;
    *(void **)(fxobj + 0x04) = alHeapDBAlloc(NULL, 0, arg3, *(u8 *)(fxobj + 0x08), 0x28);
    *(void **)(fxobj + 0x20) = alHeapDBAlloc(NULL, 0, arg3, *(s32 *)(fxobj + 0x00), 2);
    *(void **)(fxobj + 0x28) = *(void **)(fxobj + 0x20);
    *(void **)(fxobj + 0x24) = alHeapDBAlloc(NULL, 0, arg3, *(s32 *)(fxobj + 0x00), 2);
    *(void **)(fxobj + 0x2C) = *(void **)(fxobj + 0x24);

    j = 0;
    if (*(s32 *)(fxobj + 0x00) != 0) {
        do {
            *(s16 *)(*(u8 **)(fxobj + 0x24) + j * 2) = 0;
            *(s16 *)(*(u8 **)(fxobj + 0x20) + j * 2) = *(s16 *)(*(u8 **)(fxobj + 0x24) + j * 2);
            j++;
        } while ((u32)j < (u32)*(s32 *)(fxobj + 0x00));
    }

    i = 0;
    if ((s32)*(u8 *)(fxobj + 0x08) > 0) {
        do {
            elem = *(u8 **)(fxobj + 0x04) + i * 0x28;
            *(s32 *)(elem + 0x00) = tbl[idx];
            idx++;
            *(s32 *)(elem + 0x04) = tbl[idx];
            idx++;
            *(s16 *)(elem + 0x0A) = (s16)tbl[idx];
            idx++;
            *(s16 *)(elem + 0x08) = (s16)tbl[idx];
            idx++;
            *(s16 *)(elem + 0x0C) = (s16)tbl[idx];
            idx++;
            if (tbl[idx] != 0) {
                *(f32 *)(elem + 0x10) = (f32)(((f32)tbl[idx] / 1000.0f) * 2.0f / (f32)*(s32 *)((u8 *)arg1 + 0x18));
                idx++;
                tmp = *(s32 *)(elem + 0x04) - *(s32 *)(elem + 0x00);
                var_f8 = (f32)tmp;
                if (tmp < 0) {
                    var_f8 += 4294967296.0f;
                }
                *(f32 *)(elem + 0x1C) = (f32)(((f32)tbl[idx] / 173123.4062f) * var_f8);
                idx++;
                *(f32 *)(elem + 0x14) = 1.0f;
                *(s32 *)(elem + 0x18) = 0;
                *(void **)(elem + 0x24) = alHeapDBAlloc(NULL, 0, arg3, 1, 0x38);
                sub = *(u8 **)(elem + 0x24);
                *(void **)(sub + 0x14) = alHeapDBAlloc(NULL, 0, arg3, 1, 0x20);
                *(void **)(sub + 0x18) = alHeapDBAlloc(NULL, 0, arg3, 1, 0x20);
                *(f32 *)(sub + 0x24) = 0.0f;
                *(s32 *)(sub + 0x28) = 1;
            } else {
                *(void **)(elem + 0x24) = NULL;
                idx++;
                idx++;
            }
            if (tbl[idx] != 0) {
                *(void **)(elem + 0x20) = alHeapDBAlloc(NULL, 0, arg3, 1, 0x38);
                sub = *(u8 **)(elem + 0x20);
                *(void **)(sub + 0x2C) = alHeapDBAlloc(NULL, 0, arg3, 1, 8);
                *(void **)(sub + 0x30) = alHeapDBAlloc(NULL, 0, arg3, 1, 8);
                *(s16 *)sub = (s16)tbl[idx];
                idx++;
                n_alFxInitlpfilter(sub);
            } else {
                *(void **)(elem + 0x20) = NULL;
                idx++;
            }
            i++;
        } while ((s32)i < (s32)*(u8 *)(fxobj + 0x08));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_drvrNew/n_alFxNew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void alN_PVoiceNew(void *arg0, s32 (*arg1)(void *), ALHeap *arg2) {
    u8 *pv;

    pv = (u8 *)arg0;
    *(void **)(pv + 0x0C) = alHeapDBAlloc(NULL, 0, arg2, 1, 0x20);
    *(void **)(pv + 0x10) = alHeapDBAlloc(NULL, 0, arg2, 1, 0x20);
    *(s32 *)(pv + 0x28) = arg1(pv + 0x2C);
    *(s32 *)(pv + 0x34) = 0;
    *(s32 *)(pv + 0x38) = 1;
    *(s32 *)(pv + 0x3C) = 0;
    *(void **)(pv + 0x40) = alHeapDBAlloc(NULL, 0, arg2, 1, 0x20);
    *(f32 *)(pv + 0x4C) = 0.0f;
    *(s32 *)(pv + 0x50) = 1;
    *(f32 *)(pv + 0x44) = 1.0f;
    *(s32 *)(pv + 0x48) = 0;
    *(void **)(pv + 0x54) = alHeapDBAlloc(NULL, 0, arg2, 1, 0x50);
    *(s32 *)(pv + 0x78) = 1;
    *(s32 *)(pv + 0x84) = 0;
    *(s16 *)(pv + 0x5A) = 1;
    *(s16 *)(pv + 0x68) = 1;
    *(s16 *)(pv + 0x6E) = 1;
    *(s16 *)(pv + 0x5C) = 1;
    *(s16 *)(pv + 0x5E) = 1;
    *(s16 *)(pv + 0x60) = 0;
    *(s16 *)(pv + 0x62) = 0;
    *(s16 *)(pv + 0x66) = 1;
    *(s16 *)(pv + 0x64) = 0;
    *(s16 *)(pv + 0x66) = 1;
    *(s16 *)(pv + 0x64) = 0;
    *(s32 *)(pv + 0x70) = 0;
    *(s32 *)(pv + 0x74) = 0;
    *(s16 *)(pv + 0x58) = 0;
    *(s32 *)(pv + 0x7C) = 0;
    *(s32 *)(pv + 0x80) = 0;
    *(u8 *)(pv + 0x8C) = 0;
    *(s16 *)(pv + 0x92) = 0;
    *(s16 *)(pv + 0x90) = 0;
    *(void **)(pv + 0xBC) = alHeapDBAlloc(NULL, 0, arg2, 1, 8);
    *(s32 *)(pv + 0xB8) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_drvrNew/alN_PVoiceNew.s")
#endif
