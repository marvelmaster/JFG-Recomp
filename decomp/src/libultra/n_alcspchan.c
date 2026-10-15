#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPAllChanOn(N_ALCSPlayer *seqp) {
    ALChanState *chanState;
    s32 i;

    seqp->chanMask = 0xFFFF;
    /* asm: chanState lives at 0x64 (N_ALCSPlayer in n_libaudio.h places it at 0x60) */
    for (i = 0; i < seqp->maxChannels; i++) {
        chanState = *(ALChanState **) ((u8 *) seqp + 0x64);
        chanState[i].fadevoltarget = 0xFF;
        chanState[i].fadevolcurrent = 0xFF;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alcspchan/n_alCSPAllChanOn.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPChanOff(N_ALCSPlayer *seqp, u8 chan) {
    n_alCSPSendMidi(seqp, 0, chan | 0xB0, 0xFF, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alcspchan/n_alCSPChanOff.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPChanOn(N_ALCSPlayer *seqp, u8 chan) {
    seqp->chanMask |= 1 << chan;
    n_alCSPSendMidi(seqp, 0, chan | 0xB0, 0xFF, 0xFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alcspchan/n_alCSPChanOn.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPChanFade(N_ALCSPlayer *seqp, u8 chan, u8 fade) {
    n_alCSPSendMidi(seqp, 0, chan | 0xB0, 0xFF, fade);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alcspchan/n_alCSPChanFade.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPChanSurround(N_ALCSPlayer *seqp, u8 chan, u8 value) {
    n_alCSPSendMidi(seqp, 0, chan | 0xB0, 0x41, value);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alcspchan/n_alCSPChanSurround.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPChanFadeForce(N_ALCSPlayer *seqp, u8 chan, u8 value) {
    n_alCSPSendMidi(seqp, 0, chan | 0xB0, 0xFC, value);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_alcspchan/n_alCSPChanFadeForce.s")
#endif
