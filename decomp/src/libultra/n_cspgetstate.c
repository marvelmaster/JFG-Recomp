#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 n_alCSPGetState(N_ALCSPlayer *seqp) {
    return seqp->state;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspgetstate/n_alCSPGetState.s")
#endif

#ifdef NON_MATCHING
// decomp: non-matching. The asm block holds two empty functions (jr $ra; nop each);
// splat merged them, the second starts at 0x800899E0.
void func_800899D8_8A5D8(void) {
}

void func_800899E0(void) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cspgetstate/func_800899D8_8A5D8.s")
#endif
