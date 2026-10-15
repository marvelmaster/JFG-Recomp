#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alInit(N_ALGlobals *g, ALSynConfig *c) {
    if (n_alGlobals == NULL) {
        n_alGlobals = g;
        if (n_syn == NULL) {
            n_syn = &n_alGlobals->drvr;
            n_alSynNew(c);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_sl/n_alInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alClose(N_ALGlobals *glob) {
    if (n_alGlobals != NULL) {
        n_alSynDelete();
        n_alGlobals = NULL;
        n_syn = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_sl/n_alClose.s")
#endif
