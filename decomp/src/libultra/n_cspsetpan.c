#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPSetChlPan(N_ALCSPlayer *seqp, u8 chan, ALPan pan) {
    N_ALEvent evt;

    evt.type = 2;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = chan | 0xB0;
    evt.msg.midi.byte1 = 0xA;
    evt.msg.midi.byte2 = pan;
    n_alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspsetpan/n_alCSPSetChlPan.s")
#endif
