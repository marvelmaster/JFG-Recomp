#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"

/* resampler fields used by n_alResamplePull (not yet in a header) */
typedef struct N_ALResamplerDecomp {
    u8 pad00[0x40];
    void *buf;          /* 0x40 */
    f32 ratio;          /* 0x44 */
    s32 adpcm;          /* 0x48 */
    f32 accum;          /* 0x4C */
    s32 motion;         /* 0x50 */
} N_ALResamplerDecomp;

Acmd *n_alAdpcmPull(void *f, s16 *outp, s32 count, Acmd *p);
s32 n_alLoadParam(void *filter, s32 paramID, void *param);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
Acmd *n_alResamplePull(void *arg0, s16 *arg1, Acmd *arg2) {
    N_ALResamplerDecomp *rs = (N_ALResamplerDecomp *)arg0;
    Acmd *cmd = arg2;
    s16 count = 0x170;
    u32 *w;
    s32 ratioInt;
    f32 accumF;
    s32 srcBytes;

    if (rs->adpcm != 0) {
        w = (u32 *)n_alAdpcmPull(arg0, &count, 0xB8, arg2);
        cmd = (Acmd *)((u8 *)w + 8);
        w[0] = ((count & 0xFFFFFF) | 0x0A000000);
        w[1] = (((*arg1 & 0xFFFF) << 16) | 0x170);
    } else {
        if ((f64)rs->ratio > 1.99996) {
            rs->ratio = 1.999959946f;
        }
        rs->ratio = (f32)(s32)(rs->ratio * 32768.0f);
        rs->ratio = rs->ratio / 32768.0f;
        accumF = rs->accum + (rs->ratio * 184.0f);
        srcBytes = (s32)accumF;
        rs->accum = accumF - (f32)srcBytes;
        cmd = n_alAdpcmPull(arg0, &count, srcBytes, arg2);
        ratioInt = (s32)(rs->ratio * 32768.0f);
        w = (u32 *)cmd;
        cmd = (Acmd *)((u8 *)w + 8);
        w[0] = ((u32)osVirtualToPhysical(rs->buf) & 0xFFFFFF) | 0x05000000;
        w[1] = ((rs->motion & 3) << 30) | ((ratioInt & 0xFFFF) << 14) | ((count & 0xFFF) * 4);
        rs->motion = 0;
    }
    return cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_resample/n_alResamplePull.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 n_alResampleParam(void *arg0, s32 arg1, void *arg2) {
    n_alLoadParam(arg0, arg1, arg2);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_resample/n_alResampleParam.s")
#endif
