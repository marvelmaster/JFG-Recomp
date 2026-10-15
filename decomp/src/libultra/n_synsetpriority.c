#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynSetPriority(N_ALVoice *voice, s16 priority) {
    voice->priority = priority;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synsetpriority/n_alSynSetPriority.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8008EDC4(void) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synsetpriority/func_8008EDC4.s")
#endif
