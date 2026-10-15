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
void n_alCSPStop(N_ALCSPlayer *seqp) {
    s16 evtType;

    evtType = 0x11;
    n_alEvtqPostEvent((ALEventQueue *) ((u8 *) seqp + 0x48), (N_ALEvent *) &evtType, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspstop/n_alCSPStop.s")
#endif
