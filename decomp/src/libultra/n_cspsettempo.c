#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPSetTempo(N_ALCSPlayer *seqp, s32 tempo) {
    N_ALEvent evt;

    evt.type = 7;
    evt.msg.tempo.status = 0xFF;
    evt.msg.tempo.type = 0x51;
    evt.msg.tempo.byte1 = (u8)((tempo & 0xFF0000) >> 16);
    evt.msg.tempo.byte2 = (u8)((tempo & 0xFF00) >> 8);
    evt.msg.tempo.byte3 = (u8)(tempo & 0xFF);
    n_alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspsettempo/n_alCSPSetTempo.s")
#endif
