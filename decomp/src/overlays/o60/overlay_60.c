#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_60_03C00910[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *getDeathMatchObjectTable(void) {
    return D_overlay_60_03C00910;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o60/overlay_60/getDeathMatchObjectTable.s")
#endif
