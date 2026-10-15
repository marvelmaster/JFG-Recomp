#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#include "audio_internal.h"
ALParam *__n_allocParam(void);
void n_alEnvmixerParam(struct N_PVoice_s *pvoice, s32 type, ALParam *param);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynSetDistort(N_ALVoice *voice, u8 arg1) {
    ALParam *param;

    if (voice->pvoice != NULL) {
        param = __n_allocParam();
        if (param == NULL) {
            return;
        }
        param->delta = n_syn->paramSamples + *(s32 *)((u8 *)voice->pvoice + 0x88);
        param->type = 0x11;
        param->data.i = arg1;
        param->next = NULL;
        n_alEnvmixerParam(voice->pvoice, 3, param);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alsynsetdistort/n_alSynSetDistort.s")
#endif
