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
void n_alSynStartVoiceParams(N_ALVoice *v, ALWaveTable *w, f32 pitch, s16 vol, ALPan pan, u8 fxmix, u8 arg6, f32 arg7, u8 arg8, ALMicroTime t) {
    u8 *param;

    if (v->pvoice != NULL) {
        param = (u8 *) __n_allocParam();
        if (param == NULL) {
            return;
        }
        SYN_FIELD(param, 0x4, s32) = n_syn->paramSamples + SYN_FIELD(v->pvoice, 0x88, s32);
        SYN_FIELD(param, 0x0, void *) = NULL;
        SYN_FIELD(param, 0x8, s16) = 0xD;
        SYN_FIELD(param, 0xA, s16) = v->unityPitch;
        SYN_FIELD(param, 0x12, u8) = pan;
        SYN_FIELD(param, 0x10, s16) = vol;
        SYN_FIELD(param, 0x13, u8) = fxmix;
        SYN_FIELD(param, 0xC, f32) = pitch;
        SYN_FIELD(param, 0x14, u8) = arg8;
        SYN_FIELD(param, 0x15, u8) = arg6;
        SYN_FIELD(param, 0x18, f32) = arg7;
        SYN_FIELD(param, 0x1C, s32) = _n_timeToSamples(t);
        SYN_FIELD(param, 0x20, s32) = (s32) w;
        n_alEnvmixerParam(v->pvoice, 3, param);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synstartvoiceparam/n_alSynStartVoiceParams.s")
#endif
