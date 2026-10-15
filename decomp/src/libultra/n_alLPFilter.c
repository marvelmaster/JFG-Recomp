#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void *n_alResamplePull(void *filter, s16 *outp, void *p);
void n_alFxInitlpfilter_mono(void *fx, s32 bits);
void n_alLoadParam(void *filter, s32 paramID, void *param);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *n_alLPFilterPull(void *arg0, s16 *arg1, s32 arg2, void *arg3) {
    s32 *cmd;
    s32 *w;
    f32 freq;
    u8 mix;

    cmd = n_alResamplePull(arg0, arg1, arg3);
    mix = *(u8 *)((u8 *) arg0 + 0x8C);
    if (mix != 0 && mix < 0x40) {
        if (mix >= 6) {
            freq = 26755.0f / sqrtf((f32) mix + 1.0f);
        } else {
            freq = 65536.0f / ((f32) mix + 1.0f);
        }
        if (freq < 7723.0f) {
            freq = 7723.0f;
        }
        w = cmd;
        cmd += 2;
        w[0] = *arg1 & 0xFFFF;
        w[1] = (((u32) freq & 0xFFFF) << 16) | ((mix + 1) & 0xFFFF);
    }
    if (*(s16 *)((u8 *) arg0 + 0x92) > 0) {
        if (*(s32 *)((u8 *) arg0 + 0xB8) != 0) {
            n_alFxInitlpfilter_mono((u8 *) arg0 + 0x90, 0x46AC4400);
        }
        w = cmd;
        cmd += 2;
        w[0] = 0x0B000020;
        w[1] = osVirtualToPhysical((u8 *) arg0 + 0x98);
        if (*(s32 *)((u8 *) arg0 + 0xB8) == 2) {
            *(s32 *)((u8 *) arg0 + 0xB8) = 0;
        }
        w = cmd;
        cmd += 2;
        w[0] = (*arg1 & 0xFFFF) | (((*(s32 *)((u8 *) arg0 + 0xB8) & 0xFF) << 16) | 0x0E000000);
        w[1] = osVirtualToPhysical(*(void **)((u8 *) arg0 + 0xBC)) & 0xFFFFFF & 0xFFFFFF;
        *(s32 *)((u8 *) arg0 + 0xB8) = 0;
    }
    return cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alLPFilter/n_alLPFilterPull.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 n_alLPFilterParam(void *arg0, s32 arg1, void *arg2) {
    u8 *f = (u8 *) arg0;

    switch (arg1) {
    case 4:
        *(s16 *)(f + 0x92) = 0;
        n_alLoadParam(arg0, 4, arg2);
        break;
    case 18:
        *(s16 *)(f + 0x92) = (s16) (s32) arg2;
        *(s32 *)(f + 0xB8) = *(s32 *)(f + 0xB8) | 2;
        break;
    case 19:
        *(s16 *)(f + 0x90) = (s16) *(f32 *) &arg2;
        *(s32 *)(f + 0xB8) = *(s32 *)(f + 0xB8) | 2;
        break;
    case 17:
        *(u8 *)(f + 0x8C) = (u8) (s32) arg2;
        break;
    default:
        n_alLoadParam(arg0, arg1, arg2);
        break;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alLPFilter/n_alLPFilterParam.s")
#endif
