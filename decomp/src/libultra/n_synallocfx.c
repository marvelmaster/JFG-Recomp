#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#define SYN_FIELD(p, off, type) (*(type *)((u8 *)(p) + (off)))
struct ALParam_s *__n_allocParam(void);
void _n_freePVoice(void *pvoice);
void n_alEnvmixerParam(void *pvoice, s32 mode, void *param);
s32 _n_timeToSamples(s32 micros);
void n_alFxNew(void *fx, void *c, s16 bus, void *hp);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALFxRef n_alSynAllocFX(s16 arg0, ALSynConfig *arg1, ALHeap *arg2) {
    n_alFxNew((u8 *) n_syn->auxBus + arg0 * 0x48 + 0x24, arg1, arg0, arg2);
    return SYN_FIELD((u8 *) n_syn->auxBus + arg0 * 0x48, 0x24, ALFxRef);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synallocfx/n_alSynAllocFX.s")
#endif
