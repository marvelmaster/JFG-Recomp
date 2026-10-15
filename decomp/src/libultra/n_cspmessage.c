#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPSetMessageQ(N_ALCSPlayer *seqp, OSMesgQueue *mq) {
    *(OSMesgQueue **) ((u8 *) seqp + 0x88) = mq;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspmessage/n_alCSPSetMessageQ.s")
#endif

void func_8008BB9C(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPSetMessage(N_ALCSPlayer *seqp, s32 msgIdx, s32 msgVal) {
    ALInstrument *inst;
    s32 idx;

    idx = msgIdx & 0xFF;
    if (idx < seqp->bank->instCount) {
        inst = seqp->bank->instArray[idx];
        if (inst != NULL) {
            inst->flags = (u8) (((msgVal & 0xFF) * 2) | (inst->flags & 1));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspmessage/n_alCSPSetMessage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPSetChanMessage(N_ALCSPlayer *seqp, s32 chan, u8 msgVal) {
    ALChanState *chanState = *(ALChanState **) ((u8 *) seqp + 0x64);
    chanState[chan].notemesgflags = (u8) msgVal;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspmessage/n_alCSPSetChanMessage.s")
#endif

void func_8008BC38(void) {
}
