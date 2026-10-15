#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s16 D_800A9820_AA420[];
extern s16 D_800A991E_AA51E[];
s32 n_alLPFilterParam(void *filter, s32 paramID, void *param);
void *n_alLPFilterPull(void *filter, s16 *outp, s32 out, void *p);
s16 func_8009127C(f32 arg0, f32 arg1, s32 arg2, s16 *arg3);
extern u8 D_80105010_B1750;
extern u8 D_80105011_B1751;
extern u8 D_80105012_B1752;
void n_alLoadParam(void *filter, s32 paramID, void *param);
void _n_freeParam(void *param);
void _n_freePVoice(void *pvoice);
s32 n_alEnvmixerParam(void *arg0, s32 arg1, void *arg2);
Acmd *func_80090F98(void *arg0, s16 *arg1, s32 arg2, s32 arg3, Acmd *arg4);
s16 func_8009148C(s16 arg0, s32 arg1, s16 arg2, s32 arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/*
 * Envelope mixer pull (N_ prefix of the SDK alEnvmixerPull plus Rare surround/LPF).
 * Param list node (cf. DKR libultra/src/audio/env.c ALParam: next @0x0, delta @0x4,
 * type @0x8): +0x0A s16 flag, +0x0C word, +0x10 s16/s32, +0x12 u8, +0x13 u8,
 * +0x14 u8, +0x15 u8, +0x18 f32, +0x1C s32 length, +0x20 word.
 * Mixer (ALEnvMixer): ctrlList @0x7C, ctrlTail @0x80, see n_alEnvmixerParam.
 * sp44/sp48 = curTime/prevTime, sp40 = dt (multiple of 0xB8), sp30 = budget,
 * sp4E = bufPos (s16), sp3E = bufPos2 (s16).
 */
Acmd *n_alEnvmixerPull(void *arg0, s32 arg1, Acmd *arg2) {
    u8 *f;
    u8 *node;
    Acmd *dl;
    s32 curTime;
    s32 prevTime;
    s32 dt;
    s32 budget;
    s16 bufPos;
    s16 bufPos2;
    u8 b13;

    f = (u8 *)arg0;
    curTime = arg1;
    dl = arg2;
    bufPos = 0;
    budget = 0xB8;
    bufPos2 = 0;

    if (*(u8 **)(f + 0x7C) != NULL) {
        do {
            prevTime = curTime;
            node = *(u8 **)(f + 0x7C);
            curTime = *(s32 *)(node + 0x4);
            dt = (((curTime - prevTime) + 0xB7) / 184) * 0xB8;
            if (dt == 0) {
                curTime = prevTime;
            }
            if (budget < dt) {
                break;
            }

            switch (*(u16 *)(node + 0x8)) {
            case 13:
                if (*(s16 *)(node + 0xA) != 0) {
                    *(s32 *)(f + 0x48) = 1;
                }
                n_alLoadParam(f, 5, *(void **)(node + 0x20));
                *(s32 *)(f + 0x84) = 1;
                *(s32 *)(f + 0x78) = 1;
                *(s32 *)(f + 0x70) = 0;
                *(s32 *)(f + 0x74) = (((*(s32 *)(node + 0x1C)) + 0xB7) / 184) * 0xB8;
                *(s16 *)(f + 0x5A) = *(s16 *)(node + 0x10);
                *(s16 *)(f + 0x58) = *(u8 *)(node + 0x12);
                b13 = *(u8 *)(node + 0x13);
                *(s16 *)(f + 0x60) = (s16)((D_800A9820_AA420[b13 & 0x7F] & 0xFFFE) | (b13 >> 7));
                if (D_80105010_B1750 == 0) {
                    *(s16 *)(f + 0x60) = (s16)(*(s16 *)(f + 0x60) & 0xFFFE);
                }
                *(s16 *)(f + 0x62) = (s16)(D_800A991E_AA51E[-(b13 & 0x7F)] & 0xFFFE);
                if (D_80105012_B1752 != 0) {
                    *(s16 *)(f + 0x58) = (s16)((*(s16 *)(f + 0x58) >> 1) + 0x20);
                } else if (D_80105011_B1751 != 0) {
                    *(s16 *)(f + 0x58) = 0x40;
                }
                if (*(s32 *)(node + 0x1C) != 0) {
                    *(s16 *)(f + 0x5C) = 1;
                    *(s16 *)(f + 0x5E) = 1;
                } else {
                    *(s16 *)(f + 0x5C) = (s16)((D_800A9820_AA420[*(s16 *)(f + 0x58)] * *(s16 *)(f + 0x5A)) >> 15);
                    *(s16 *)(f + 0x5E) = (s16)((D_800A991E_AA51E[-*(s16 *)(f + 0x58)] * *(s16 *)(f + 0x5A)) >> 15);
                }
                *(f32 *)(f + 0x44) = *(f32 *)(node + 0xC);
                *(s16 *)(f + 0x92) = *(u8 *)(node + 0x15);
                *(s16 *)(f + 0x90) = (s16)(s32)*(f32 *)(node + 0x18);
                *(s32 *)(f + 0xB8) = 1;
                *(u8 *)(f + 0x8C) = *(u8 *)(node + 0x14);
                break;
            case 11:
            case 12:
            case 16:
                /* asm: a2 = &bufPos2 (s16 *), unused by the callee; passed as s32 */
                dl = func_80090F98(f, &bufPos, (s32)&bufPos2, dt, dl);
                if (*(s32 *)(f + 0x70) >= *(s32 *)(f + 0x74)) {
                    *(s16 *)(f + 0x68) = (s16)((D_800A9820_AA420[*(s16 *)(f + 0x58)] * *(s16 *)(f + 0x5A)) >> 15);
                    *(s16 *)(f + 0x6E) = (s16)((D_800A991E_AA51E[-*(s16 *)(f + 0x58)] * *(s16 *)(f + 0x5A)) >> 15);
                    *(s32 *)(f + 0x70) = *(s32 *)(f + 0x74);
                    *(s16 *)(f + 0x5C) = *(s16 *)(f + 0x68);
                    *(s16 *)(f + 0x5E) = *(s16 *)(f + 0x6E);
                } else {
                    *(s16 *)(f + 0x5C) = func_8009148C(*(s16 *)(f + 0x5C), *(s32 *)(f + 0x70), *(s16 *)(f + 0x66), *(u16 *)(f + 0x64));
                    *(s16 *)(f + 0x5E) = func_8009148C(*(s16 *)(f + 0x5E), *(s32 *)(f + 0x70), *(s16 *)(f + 0x6C), *(u16 *)(f + 0x6A));
                }
                if (*(s16 *)(f + 0x5C) == 0) {
                    *(s16 *)(f + 0x5C) = 1;
                }
                if (*(s16 *)(f + 0x5E) == 0) {
                    *(s16 *)(f + 0x5E) = 1;
                }
                if (*(u16 *)(node + 0x8) == 0xC) {
                    if (D_80105012_B1752 != 0) {
                        *(s16 *)(f + 0x58) = (s16)((*(s16 *)(node + 0xE) >> 1) + 0x20);
                    } else if (D_80105011_B1751 != 0) {
                        *(s16 *)(f + 0x58) = 0x40;
                    } else {
                        *(s16 *)(f + 0x58) = (s16)*(s32 *)(node + 0xC);
                    }
                }
                if (*(u16 *)(node + 0x8) == 0xB) {
                    *(s32 *)(f + 0x70) = 0;
                    *(s16 *)(f + 0x5A) = (s16)*(s32 *)(node + 0xC);
                    *(s32 *)(f + 0x74) = (((*(s32 *)(node + 0x10)) + 0xB7) / 184) * 0xB8;
                }
                if (*(u16 *)(node + 0x8) == 0x10) {
                    if ((((*(s16 *)(f + 0x60) ^ *(s16 *)(f + 0x62)) & 1) ^ ((*(s32 *)(node + 0xC) + 1) >> 7)) != 0
                        && D_80105010_B1750 != 0) {
                        if (*(s16 *)(f + 0x58) >= 0x41) {
                            *(s16 *)(f + 0x60) = (s16)(*(s16 *)(f + 0x60) ^ 1);
                        } else {
                            *(s16 *)(f + 0x62) = (s16)(*(s16 *)(f + 0x62) ^ 1);
                        }
                    }
                    *(s16 *)(f + 0x60) = (s16)((D_800A9820_AA420[*(s32 *)(node + 0xC) & 0x7F] & 0xFFFE) | (*(s16 *)(f + 0x60) & 1));
                    *(s16 *)(f + 0x62) = (s16)((D_800A991E_AA51E[-(*(s32 *)(node + 0xC) & 0x7F)] & 0xFFFE) | (*(s16 *)(f + 0x62) & 1));
                }
                *(s32 *)(f + 0x78) = 1;
                break;
            case 14:
                if (*(s16 *)(node + 0xA) != 0) {
                    *(s32 *)(f + 0x48) = 1;
                }
                n_alLoadParam(f, 5, *(void **)(node + 0xC));
                *(s32 *)(f + 0x84) = 1;
                break;
            case 15:
                dl = func_80090F98(f, &bufPos, (s32)&bufPos2, dt, dl);
                n_alEnvmixerParam(f, 4, NULL);
                break;
            case 0:
                *(s32 *)(*(u8 **)(node + 0xC) + 0x88) = 0;
                _n_freePVoice(*(void **)(node + 0xC));
                break;
            case 7:
                dl = func_80090F98(f, &bufPos, (s32)&bufPos2, dt, dl);
                *(f32 *)(f + 0x44) = *(f32 *)(node + 0xC);
                break;
            case 8:
                dl = func_80090F98(f, &bufPos, (s32)&bufPos2, dt, dl);
                *(s32 *)(f + 0x48) = 1;
                break;
            case 5:
                dl = func_80090F98(f, &bufPos, (s32)&bufPos2, dt, dl);
                n_alLoadParam(f, 5, *(void **)(node + 0xC));
                break;
            default:
                dl = func_80090F98(f, &bufPos, (s32)&bufPos2, dt, dl);
                n_alEnvmixerParam(f, *(s16 *)(node + 0x8), *(void **)(node + 0xC));
                break;
            }

            bufPos2 = (s16)(bufPos2 + (dt << 1));
            budget -= dt;
            *(u8 **)(f + 0x7C) = *(u8 **)node;
            if (*(u8 **)(f + 0x7C) == NULL) {
                *(u8 **)(f + 0x80) = NULL;
            }
            _n_freeParam(node);
        } while (*(u8 **)(f + 0x7C) != NULL);
    }

    dl = func_80090F98(f, &bufPos, (s32)&bufPos2, budget, dl);
    if (*(s32 *)(f + 0x74) < *(s32 *)(f + 0x70)) {
        *(s32 *)(f + 0x70) = *(s32 *)(f + 0x74);
    }
    return dl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_env/n_alEnvmixerPull.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* arg0 is the ALEnvMixer (ctrlList @0x7C, ctrlTail @0x80, flags @0x78/0x84) */
s32 n_alEnvmixerParam(void *arg0, s32 arg1, void *arg2) {
    u8 *f;

    f = (u8 *)arg0;
    switch (arg1) {
    case 3:
        if (*(void **)(f + 0x80) != NULL) {
            *(void **)(*(u8 **)(f + 0x80)) = arg2;
        } else {
            *(void **)(f + 0x7C) = arg2;
        }
        *(void **)(f + 0x80) = arg2;
        break;
    case 4:
        *(s32 *)(f + 0x78) = 1;
        *(s32 *)(f + 0x84) = 0;
        *(s16 *)(f + 0x5A) = 1;
        *(s32 *)(f + 0x74) = 0;
        *(f32 *)(f + 0x4C) = 0.0f;
        *(s32 *)(f + 0x50) = 1;
        *(s32 *)(f + 0x48) = 0;
        n_alLPFilterParam(f, 4, arg2);
        break;
    case 9:
        *(s32 *)(f + 0x84) = 1;
        break;
    default:
        n_alLPFilterParam(f, arg1, arg2);
        break;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_env/n_alEnvmixerParam.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* arg2 is unused in the asm (a2 is not read) */
Acmd *func_80090F98(void *arg0, s16 *arg1, s32 arg2, s32 arg3, Acmd *arg4) {
    u8 *f;
    Acmd *sp34;
    Acmd *cmd;

    f = (u8 *)arg0;
    sp34 = arg4;
    if (*(s32 *)(f + 0x84) != 1 || arg3 == 0) {
        return sp34;
    }
    sp34 = (Acmd *)n_alLPFilterPull(f, arg1, arg3, arg4);
    if (*(s32 *)(f + 0x78) != 0) {
        *(s32 *)(f + 0x78) = 0;
        *(s16 *)(f + 0x68) = (s16)(((s32)(D_800A9820_AA420[*(s16 *)(f + 0x58)] * *(s16 *)(f + 0x5A))) >> 15);
        *(s16 *)(f + 0x66) = func_8009127C((f32)*(s16 *)(f + 0x5C), (f32)*(s16 *)(f + 0x68), *(s32 *)(f + 0x74),
                                           (s16 *)(f + 0x64));
        *(s16 *)(f + 0x6E) = (s16)(((s32)(D_800A991E_AA51E[-*(s16 *)(f + 0x58)] * *(s16 *)(f + 0x5A))) >> 15);
        *(s16 *)(f + 0x6C) = func_8009127C((f32)*(s16 *)(f + 0x5E), (f32)*(s16 *)(f + 0x6E), *(s32 *)(f + 0x74),
                                           (s16 *)(f + 0x6A));

        cmd = sp34;
        sp34++;
        cmd->words.w0 = ((u32)*(s16 *)(f + 0x5C) & 0xFFFF) | 0x09060000;
        cmd->words.w1 = (((u32)*(s16 *)(f + 0x60) & 0xFFFF) << 16) | ((u32)*(s16 *)(f + 0x62) & 0xFFFF);

        cmd = sp34;
        sp34++;
        cmd->words.w0 = ((u32)*(s16 *)(f + 0x6E) & 0xFFFF) | 0x09040000;
        cmd->words.w1 = (((u32)*(s16 *)(f + 0x6C) & 0xFFFF) << 16) | ((u32)*(u16 *)(f + 0x6A) & 0xFFFF);

        cmd = sp34;
        sp34++;
        cmd->words.w0 = ((u32)*(s16 *)(f + 0x68) & 0xFFFF) | 0x09000000;
        cmd->words.w1 = (((u32)*(s16 *)(f + 0x66) & 0xFFFF) << 16) | ((u32)*(u16 *)(f + 0x64) & 0xFFFF);

        cmd = sp34;
        sp34++;
        cmd->words.w0 = ((u32)*(s16 *)(f + 0x5E) & 0xFFFF) | 0x03010000;
        cmd->words.w1 = osVirtualToPhysical(*(void **)(f + 0x54));
    } else {
        cmd = sp34;
        sp34++;
        cmd->words.w0 = 0x03000000;
        cmd->words.w1 = osVirtualToPhysical(*(void **)(f + 0x54));
    }
    *(s16 *)arg1 = (s16)(*arg1 + 0x170);
    *(s32 *)(f + 0x70) = *(s32 *)(f + 0x70) + 0xB8;
    return sp34;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_env/func_80090F98.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_8009127C(f32 arg0, f32 arg1, s32 arg2, s16 *arg3) {
    s16 spE;
    s16 spC;
    f32 sp8;
    f32 sp4;
    f32 sp0;
    f32 var_f12;
    f32 var_f14;

    var_f12 = arg0;
    var_f14 = arg1;
    if (arg2 == 0) {
        if (var_f12 <= var_f14) {
            *arg3 = (s16)0xFFFF;
            return 0x7FFF;
        }
        *arg3 = 0;
        return -0x8000;
    }
    sp8 = 1.0f / (f32)arg2;
    if (var_f14 < 1.0f) {
        var_f14 = 1.0f;
    }
    if (var_f12 <= 0.0f) {
        var_f12 = 1.0f;
    }
    sp4 = (var_f14 - var_f12) * sp8 * 8.0f;
    spE = (s16)(s32)sp4;
    sp0 = sp4 - (f32)spE;
    spE -= 1;
    sp0 += 1.0f;
    spC = (s16)(s32)sp0;
    spE += spC;
    sp0 -= (f32)spC;
    *arg3 = (s16)(u32)(65535.0f * sp0);
    return spE;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_env/func_8009127C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_8009148C(s16 arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 n;
    s32 sp4;

    n = arg1 >> 3;
    if (n == 0) {
        return arg0;
    }
    sp4 = (arg3 & 0xFFFF) * n;
    sp4 = sp4 >> 0x10;
    sp4 += arg2 * n;
    return (s16)(arg0 + sp4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_env/func_8009148C.s")
#endif
