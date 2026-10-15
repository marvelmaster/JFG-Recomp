#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPPlay(N_ALCSPlayer *seqp) {
    N_ALEvent evt;

    evt.type = 0xF;
    n_alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspplay/n_alCSPPlay.s")
#endif
