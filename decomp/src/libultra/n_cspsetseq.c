#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPSetSeq(N_ALCSPlayer *seqp, ALCSeq *seq) {
    N_ALEvent evt;

    evt.type = 0xD;
    evt.msg.spseq.seq = seq;
    n_alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspsetseq/n_alCSPSetSeq.s")
#endif
