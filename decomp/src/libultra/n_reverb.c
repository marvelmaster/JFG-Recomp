#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
s32 *n_alMainBusPull(s32 arg0, s32 *arg1);
void n_alFxInitlpfilter(void *state);
void *_n_loadBuffer(void *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, void *arg5);
f32 _doModFunc(void *arg0, s32 arg1);
s32 *n_alAuxBusPull(s32 samples, s32 *cmd, s32 busIdx, s32 *cmdCount);
void *_n_saveBuffer(void *arg0, s32 arg1, u32 arg2, s32 arg3, void *arg4);
void *_n_loadOutputBuffer(void *arg0, void *arg1, s32 arg2, s32 arg3, void *arg4);
void *_n_filterBuffer(void *arg0, s32 arg1, s32 arg2, void *arg3);
extern u8 D_80105014_B1754[];
extern u8 D_80105016_B1756[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. DKR alFxPull (libultra/src/audio/mips1/reverb.c): same per-section
// load / output / ffcoef / fbcoef / filter / save / gain order and the
// in_ptr == prev_out_ptr buffer swap. JFG asm is the truth (N_ prefix, 0x48
// bus stride, byte flags, mixer cmd 0x0C, 0x0A/0x02 cmds).
void *n_alFxPull(s32 arg0, void *arg1, s32 arg2) {
    u8 *out;
    u8 *bus;
    u8 *fx;                 /* reverb state: n_syn->auxBus[busIdx] + 0x20 */
    u8 *ent;                /* fx->ent table, 0x28 bytes per entry */
    u32 *cmd;
    s32 auxCount;
    u32 pos;
    u32 sp64;               /* previous entry's buffer offset */
    u32 sp70;
    u32 sp6C;
    u32 j;                  /* bus index inside the reverb (0 or 1) */
    s16 i;                  /* entry index */
    s16 dmemA;              /* 0x7C0 */
    s16 dmemB;              /* 0x930 */
    s16 dmemC;              /* 0 (swapped with dmemD) */
    s16 dmemD;              /* 0x170 (swapped with dmemC) */
    s16 swp;
    u32 sp34;
    u8 flagA;
    u8 flagB;

    out = arg1;
    bus = (u8 *) n_syn->auxBus + arg2 * 0x48;
    fx = *(u8 **) (bus + 0x20);
    sp64 = 0;
    auxCount = 1;
    out = (u8 *) n_alAuxBusPull(arg0, (s32 *) out, arg2, &auxCount);

    dmemA = 0x7C0;
    dmemB = 0x930;
    dmemC = 0;
    dmemD = 0x170;
    flagA = D_80105014_B1754[arg2];
    flagB = D_80105016_B1756[arg2];

    if (flagA == 0) {
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = 0x0C00C000;
        cmd[1] = (dmemA & 0xFFFF) | 0x07C00000;
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = 0x0C004000;
        cmd[1] = (dmemA & 0xFFFF) | 0x09300000;
    }
    out = _n_saveBuffer(fx, 0, *(u32 *) (fx + 0x28), dmemA, out);
    if (flagA != 0) {
        out = _n_saveBuffer(fx, 1, *(u32 *) (fx + 0x2C), 0x930, out);
    }

    j = 0;
    do {
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = ((u32) (s32) dmemB & 0xFFFFFF) | 0x02000000;
        cmd[1] = 0x170;

        i = 0;
        if (*(u8 *) (fx + 8) > 0) {
            do {
                ent = *(u8 **) (fx + 4) + i * 0x28;
                pos = *(u32 *) (fx + 0x28 + j * 4);
                sp70 = pos - *(s32 *) (ent + 0x00) * 2;
                sp6C = pos - *(s32 *) (ent + 0x04) * 2;

                if (flagB != 0 && flagA != 0) {
                    *(s16 *) (ent + 0x08) = -*(s16 *) (ent + 0x08);
                    *(s16 *) (ent + 0x0A) = -*(s16 *) (ent + 0x0A);
                }

                if (sp70 == sp64) {
                    swp = dmemD;
                    dmemD = dmemC;
                    dmemC = swp;
                } else {
                    out = _n_loadBuffer(fx, j, sp70, dmemC, 0xB8, out);
                }
                out = _n_loadOutputBuffer(fx, ent, j, dmemD, out);

                if (*(s16 *) (ent + 0x08) != 0) {
                    cmd = (u32 *) out;
                    out += 8;
                    cmd[0] = (u32) *(u16 *) (ent + 0x08) | 0x0C000000;
                    cmd[1] = ((dmemC & 0xFFFF) << 16) | (dmemD & 0xFFFF);
                    if (*(void **) (ent + 0x24) == NULL && *(void **) (ent + 0x20) == NULL) {
                        out = _n_saveBuffer(fx, j, sp6C, dmemD, out);
                    }
                }

                if (*(s16 *) (ent + 0x0A) != 0) {
                    cmd = (u32 *) out;
                    out += 8;
                    cmd[0] = (u32) *(u16 *) (ent + 0x0A) | 0x0C000000;
                    cmd[1] = ((dmemD & 0xFFFF) << 16) | (dmemC & 0xFFFF);
                    out = _n_saveBuffer(fx, j, sp70, dmemC, out);
                }

                if (*(void **) (ent + 0x20) != NULL) {
                    out = _n_filterBuffer(*(void **) (ent + 0x20), j, dmemD, out);
                }

                if (*(void **) (ent + 0x24) == NULL) {
                    out = _n_saveBuffer(fx, j, sp6C, dmemD, out);
                }

                if (*(s16 *) (ent + 0x0C) != 0) {
                    if (flagA != 0) {
                        cmd = (u32 *) out;
                        out += 8;
                        cmd[0] = (u32) *(u16 *) (ent + 0x0C) | 0x0C000000;
                        cmd[1] = ((dmemD & 0xFFFF) << 16) | (dmemB & 0xFFFF);
                    } else {
                        /* asm: float * 1.4142f, truncated to u32, clamped to 0x7FFF */
                        sp34 = (u32) ((f32) *(s16 *) (ent + 0x0C) * 1.4142f);
                        if (sp34 >= 0x8000U) {
                            sp34 = 0x7FFF;
                        }
                        cmd = (u32 *) out;
                        out += 8;
                        cmd[0] = (sp34 & 0xFFFF) | 0x0C000000;
                        cmd[1] = ((dmemD & 0xFFFF) << 16) | (dmemB & 0xFFFF);
                    }
                }

                sp64 = *(u32 *) (fx + 0x28 + j * 4) + *(s32 *) (ent + 0x04) * 2;
                i++;
            } while (i < *(u8 *) (fx + 8));
        }

        if (flagA != 0 && j == 0) {
            out = _n_loadBuffer(fx, 1, *(u32 *) (fx + 0x2C), dmemA, 0xB8, out);
            if (flagB != 0) {
                cmd = (u32 *) out;
                out += 8;
                cmd[0] = 0x0C005A82;
                cmd[1] = ((dmemB & 0xFFFF) << 16) | 0x650;
            } else {
                cmd = (u32 *) out;
                out += 8;
                cmd[0] = 0x0C005A82;
                cmd[1] = ((dmemB & 0xFFFF) << 16) | 0x4E0;
            }
        }

        cmd = (u32 *) out;
        out += 8;
        cmd[0] = ((u32) (s32) dmemB & 0xFFFFFF) | 0x0A000000;
        cmd[1] = 0x07C00170;

        /* advance this bus's write pointer, wrap it back by the buffer length */
        *(u32 *) (fx + 0x28 + j * 4) += 0x170;
        if ((u32) (*(u32 *) (fx + 0x20 + j * 4) + (u32) (*(s32 *) fx * 2))
            < *(u32 *) (fx + 0x28 + j * 4)) {
            *(u32 *) (fx + 0x28 + j * 4) -= *(s32 *) fx * 2;
        }

        j++;
    } while (flagA >= j);
    return out;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/n_alFxPull.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 n_alFxParamHdl(void *arg0, s32 arg1, s32 *arg2) {
    u8 *fx = arg0;
    u8 *ent;
    u32 param = arg1 & 7;
    s32 idx = arg1 >> 3;
    s32 val = *arg2;
    f32 sp1C = 0.0f;
    void *lpf;

    if (idx >= *(s32 *) (fx + 8)) {
        return 0;
    }
    ent = *(u8 **) (fx + 4) + idx * 0x28;

    switch (param) {
        case 0:
            *(s32 *) (ent + 0x00) = ((val * n_syn->outputRate) / 1000) & ~7;
            break;
        case 1:
            *(s32 *) (ent + 0x04) = ((val * n_syn->outputRate) / 1000) & ~7;
            break;
        case 2:
            *(s16 *) (ent + 0x0A) = (s16) val;
            break;
        case 3:
            *(s16 *) (ent + 0x08) = (s16) val;
            break;
        case 4:
            *(s16 *) (ent + 0x0C) = (s16) val;
            break;
        case 5:
            *(f32 *) (ent + 0x10) = (((f32) val / 1000.0f) * 2.0f) / (f32) n_syn->outputRate;
            break;
        case 6:
            sp1C = (f32) val;
            break;
        case 7:
            lpf = *(void **) (ent + 0x20);
            if (lpf != NULL) {
                *(s16 *) lpf = (s16) val;
                n_alFxInitlpfilter(lpf);
            }
            break;
    }

    /* clamp start/end to the buffer bounds */
    if ((u32) *(s32 *) (ent + 0x00) >= (u32) (*(s32 *) (fx + 0) - 0x10)) {
        *(s32 *) (ent + 0x00) = *(s32 *) (fx + 0) - 0x10;
    }
    if ((u32) *(s32 *) (ent + 0x00) >= (u32) (*(s32 *) (fx + 0) - 8)) {
        *(s32 *) (ent + 0x00) = *(s32 *) (fx + 0) - 8;
    }
    if ((u32) *(s32 *) (ent + 0x00) >= (u32) *(s32 *) (ent + 0x04)) {
        *(s32 *) (ent + 0x04) = *(s32 *) (ent + 0x00) + 8;
    }

    if (*(void **) (ent + 0x24) != NULL) {
        if (param != 6) {
            if ((*(s32 *) (ent + 0x04) - *(s32 *) (ent + 0x00)) != 0) {
                sp1C = (*(f32 *) (ent + 0x1C) / (f32) (*(s32 *) (ent + 0x04) - *(s32 *) (ent + 0x00))) * 173123.4f;
            } else {
                sp1C = 0.0f;
            }
        }
        *(f32 *) (ent + 0x1C) = (f32) (*(s32 *) (ent + 0x04) - *(s32 *) (ent + 0x00)) * (sp1C / 173123.4f);
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/n_alFxParamHdl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *_n_loadOutputBuffer(void *arg0, void *arg1, s32 arg2, s32 arg3, void *arg4) {
    u8 *tbl = arg0;
    u8 *ent = arg1;
    u8 *out = arg4;
    u8 *state;
    s32 len;
    s32 sp34 = 0;
    s32 sp2C = 0xB8;
    s32 sp48 = 0x2E0;
    s32 sp4C;
    s32 sp50;
    s32 sp44;
    s16 sp2A;
    u32 *cmd;
    f32 sp3C;
    f32 sp38;
    f32 sp40;

    state = *(u8 **) (ent + 0x24);
    if (state != NULL) {
        len = *(s32 *) (ent + 0x04) - *(s32 *) (ent + 0x00);
        sp38 = _doModFunc(ent, sp2C);
        sp38 /= (f32) len;
        sp38 = (f32) (s32) (sp38 * 32768.0f);
        sp38 /= 32768.0f;
        sp3C = 1.0f - sp38;
        sp40 = *(f32 *) (state + 0x24) + (sp3C * (f32) sp2C);
        sp4C = (s32) sp40;
        *(f32 *) (state + 0x24) = sp40 - (f32) sp4C;

        sp44 = *(s32 *) (tbl + arg2 * 4 + 0x28) + (*(s32 *) (ent + 0x04) - *(s32 *) (ent + 0x18)) * -2;
        sp34 = (sp44 & 7) >> 1;
        out = _n_loadBuffer(tbl, arg2, sp44 - (sp34 * 2), sp48, sp4C + sp34, out);

        sp50 = (s32) (sp3C * 32768.0f);
        sp2A = (s16) (arg3 >> 8);
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = (u32) (((u32) osVirtualToPhysical(*(void **) (state + arg2 * 4 + 0x14)) & 0xFFFFFF) | 0x05000000);
        cmd[1] = (u32) (((*(u32 *) (state + 0x28) & 3) << 0x1E) | ((sp50 & 0xFFFF) << 0xE)
                        | (((sp48 + (sp34 * 2)) & 0xFFF) * 4) | (sp2A & 3));
        *(s32 *) (state + 0x28) = 0;
        *(s32 *) (ent + 0x18) = *(s32 *) (ent + 0x18) + (sp4C - sp2C);
    } else {
        sp44 = *(s32 *) (tbl + arg2 * 4 + 0x28) + *(s32 *) (ent + 0x04) * -2;
        out = _n_loadBuffer(tbl, arg2, sp44, arg3, 0xB8, out);
    }
    return out;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/_n_loadOutputBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *_n_loadBuffer(void *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, void *arg5) {
    u8 *tbl = arg0;
    u32 *cmd;
    u32 sp24;
    u32 sp28;
    s32 sp30;
    s32 sp2C;
    u8 *out = arg5;

    sp24 = *(u32 *) (tbl + arg1 * 4 + 0x20) + (*(s32 *) tbl * 2);
    if (arg2 < *(u32 *) (tbl + arg1 * 4 + 0x20)) {
        arg2 += *(s32 *) tbl * 2;
    }
    sp28 = (arg4 * 2) + arg2;
    if (sp24 < sp28) {
        sp30 = (s32) (sp28 - sp24) >> 1;
        sp2C = (s32) (sp24 - arg2) >> 1;
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = (((sp2C * 2) & 0xFFF) << 0xC) | 0x04000000 | (arg3 & 0xFFF);
        cmd[1] = (u32) osVirtualToPhysical((void *) arg2);
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = (((sp30 * 2) & 0xFFF) << 0xC) | 0x04000000 | ((arg3 + (sp2C * 2)) & 0xFFF);
        cmd[1] = (u32) osVirtualToPhysical(*(void **) (tbl + arg1 * 4 + 0x20));
    } else {
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = (((arg4 * 2) & 0xFFF) << 0xC) | 0x04000000 | (arg3 & 0xFFF);
        cmd[1] = (u32) osVirtualToPhysical((void *) arg2);
    }
    return out;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/_n_loadBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *_n_saveBuffer(void *arg0, s32 arg1, u32 arg2, s32 arg3, void *arg4) {
    u8 *tbl = arg0;
    u32 *cmd;
    u8 *out = arg4;
    u32 sp24;
    u32 sp28;
    s32 sp30;
    s32 sp2C;

    sp24 = *(u32 *) (tbl + arg1 * 4 + 0x20) + (*(s32 *) tbl * 2);
    if (arg2 < *(u32 *) (tbl + arg1 * 4 + 0x20)) {
        arg2 += *(s32 *) tbl * 2;
    }
    sp28 = arg2 + 0x170;
    if (sp24 < sp28) {
        sp30 = (s32) (sp28 - sp24) >> 1;
        sp2C = (s32) (sp24 - arg2) >> 1;
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = (((sp2C * 2) & 0xFFF) << 0xC) | 0x06000000 | (arg3 & 0xFFF);
        cmd[1] = (u32) osVirtualToPhysical((void *) arg2);
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = (((sp30 * 2) & 0xFFF) << 0xC) | 0x06000000 | ((arg3 + (sp2C * 2)) & 0xFFF);
        cmd[1] = (u32) osVirtualToPhysical(*(void **) (tbl + arg1 * 4 + 0x20));
    } else {
        cmd = (u32 *) out;
        out += 8;
        cmd[0] = (arg3 & 0xFFF) | 0x06170000;
        cmd[1] = (u32) osVirtualToPhysical((void *) arg2);
    }
    return out;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/_n_saveBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *_n_filterBuffer(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    u8 *fx = arg0;
    u32 *cmd;
    u8 *out = arg3;
    s16 sp22 = (s16) (arg2 >> 8);

    cmd = (u32 *) out;
    out += 8;
    cmd[0] = 0x0B000020;
    cmd[1] = (u32) osVirtualToPhysical(fx + 8);

    cmd = (u32 *) out;
    out += 8;
    cmd[0] = (((*(u32 *) (fx + 0x28)) & 0xFF) << 0x10) | 0x0E000000 | (*(s16 *) (fx + 2) & 0xFFFF);
    cmd[1] = ((u32) osVirtualToPhysical(*(void **) (fx + arg1 * 4 + 0x2C)) & 0xFFFFFF)
             | ((sp22 & 0xFF) << 0x18);
    *(s32 *) (fx + 0x28) = 0;
    return out;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/_n_filterBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 _doModFunc(void *arg0, s32 arg1) {
    u8 *ent = arg0;
    f32 sp4;

    *(f32 *) (ent + 0x14) = *(f32 *) (ent + 0x14) + (*(f32 *) (ent + 0x10) * (f32) arg1);
    if (*(f32 *) (ent + 0x14) > 2.0f) {
        *(f32 *) (ent + 0x14) = *(f32 *) (ent + 0x14) - 4.0f;
    }
    sp4 = *(f32 *) (ent + 0x14);
    if (sp4 < 0.0f) {
        sp4 = -sp4;
    }
    sp4 -= 1.0f;
    return *(f32 *) (ent + 0x1C) * sp4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/_doModFunc.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 *n_alSavePull(s32 arg0, s32 *arg1) {
    u32 *cmd;

    cmd = (u32 *) n_alMainBusPull(arg0, arg1);
    cmd[0] = 0x0D000000;
    cmd += 2;
    cmd[0] = 0x062E0000;
    cmd[1] = (u32) n_syn->sv_dramout;
    cmd += 2;
    return (s32 *) cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_reverb/n_alSavePull.s")
#endif
