#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#include "audio_internal.h"

/* physical voice as used by the n_audio driver (only fields seen in asm) */
typedef struct N_PVoice_s {
    ALLink node;            /* 0x00 */
    N_ALVoice *voice;       /* 0x08 */
    u8 pad0C[0x7C];         /* 0x0C */
    s32 unk88;              /* 0x88 */
} N_PVoice;

ALParam *__n_allocParam(void);
void n_alEnvmixerParam(void *filter, s32 paramID, void *param);
s32 _allocatePVoice(N_PVoice **pvoice, s16 priority);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 n_alSynAllocVoice(N_ALVoice *voice, ALVoiceConfig *vc) {
    N_PVoice *pvoice = NULL;
    ALParam *param;
    s32 stolen;

    voice->priority = vc->priority;
    voice->unityPitch = vc->unityPitch;
    voice->table = NULL;
    voice->fxBus = vc->fxBus;
    voice->state = 0;
    voice->pvoice = NULL;

    stolen = _allocatePVoice(&pvoice, vc->priority);
    if (pvoice != NULL) {
        if (stolen != 0) {
            pvoice->unk88 = 0x228;
            pvoice->voice->pvoice = NULL;
            pvoice->voice = voice;
            voice->pvoice = pvoice;

            param = __n_allocParam();
            if (param != NULL) {
                param->delta = n_syn->paramSamples;
                param->type = 0xB;
                param->data.i = 0;
                param->moredata.i = 0x170;
                n_alEnvmixerParam(voice->pvoice, 3, param);
            }
            param = __n_allocParam();
            if (param != NULL) {
                param->delta = n_syn->paramSamples + pvoice->unk88;
                param->type = 0xF;
                param->next = NULL;
                n_alEnvmixerParam(voice->pvoice, 3, param);
            }
        } else {
            pvoice->unk88 = 0;
            pvoice->voice = voice;
            voice->pvoice = pvoice;
        }
    }
    return pvoice != NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synallocvoice/n_alSynAllocVoice.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 _allocatePVoice(N_PVoice **arg0, s16 arg1) {
    N_PVoice *cand;
    s32 found = 0;

    if (n_syn->pLameList.next != NULL) {
        cand = (N_PVoice *)n_syn->pLameList.next;
        *arg0 = cand;
        alUnlink(&cand->node);
        alLink(&cand->node, &n_syn->pAllocList);
    } else if (n_syn->pFreeList.next != NULL) {
        cand = (N_PVoice *)n_syn->pFreeList.next;
        *arg0 = cand;
        alUnlink(&cand->node);
        alLink(&cand->node, &n_syn->pAllocList);
    } else {
        cand = (N_PVoice *)n_syn->pAllocList.next;
        if (cand != NULL) {
            do {
                if (arg1 >= cand->voice->priority && cand->unk88 == 0) {
                    *arg0 = cand;
                    arg1 = cand->voice->priority;
                    found = 1;
                }
                cand = (N_PVoice *)cand->node.next;
            } while (cand != NULL);
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synallocvoice/_allocatePVoice.s")
#endif
