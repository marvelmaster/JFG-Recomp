#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
void n_alEvtqPostExternEvent(void *drvr, ALEventQueue *evtq, ALEvent *evt, s32 delta);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPSendMidi(N_ALCSPlayer *seqp, s32 ticks, u8 status, u8 byte1, u8 byte2) {
    N_ALEvent evt;

    evt.type = 2;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = status;
    evt.msg.midi.byte1 = byte1;
    evt.msg.midi.byte2 = byte2;
    evt.msg.midi.duration = 0;
    n_alEvtqPostExternEvent(seqp, &seqp->evtq, (ALEvent *)&evt, ticks);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspsendmidi/n_alCSPSendMidi.s")
#endif
