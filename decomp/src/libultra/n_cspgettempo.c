#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 n_alCSPGetTempo(N_ALCSPlayer *seqp) {
    if (seqp->target == NULL) {
        return 0;
    }
    return (s32)((f32)seqp->uspt / seqp->target->qnpt);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspgettempo/n_alCSPGetTempo.s")
#endif

void func_800869FC(void) {
}

void func_80086A04(void) {
}
