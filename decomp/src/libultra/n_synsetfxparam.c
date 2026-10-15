#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#include "audio_internal.h"

s32 n_alFxParamHdl(void *filter, s32 paramID, void *param);
void n_alFxInitlpfilter_mono(void *fx, f32 rate);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynSetFXParam(ALFxRef fx, s16 paramID, void *param) {
    n_alFxParamHdl(fx, paramID, param);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synsetfxparam/n_alSynSetFXParam.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynSetOutputLPParam(ALFxRef fx, s16 paramID, void *param) {
    ALLowPass *lp = (ALLowPass *)fx;

    if (paramID == 8) {
        lp->fgain = (s16)(s32)((f32)*(s32 *)param * 0.1f);
    } else if (paramID == 9) {
        lp->fc = (s16)*(s32 *)param;
    }
    n_alFxInitlpfilter_mono(fx, (f32)n_syn->outputRate);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synsetfxparam/n_alSynSetOutputLPParam.s")
#endif
