#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#define SYN_FIELD(p, off, type) (*(type *)((u8 *)(p) + (off)))
struct ALParam_s *__n_allocParam(void);
void _n_freePVoice(void *pvoice);
void n_alEnvmixerParam(void *pvoice, s32 mode, void *param);
s32 _n_timeToSamples(s32 micros);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynStopVoice(N_ALVoice *v) {
    void *param;

    if (v->pvoice != NULL) {
        param = __n_allocParam();
        if (param == NULL) {
            return;
        }
        SYN_FIELD(param, 0x4, s32) = n_syn->paramSamples + SYN_FIELD(v->pvoice, 0x88, s32);
        SYN_FIELD(param, 0x0, void *) = NULL;
        SYN_FIELD(param, 0x8, s16) = 0xF;
        n_alEnvmixerParam(v->pvoice, 3, param);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synstopvoice/n_alSynStopVoice.s")
#endif
