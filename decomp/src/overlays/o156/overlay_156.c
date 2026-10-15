#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 D_A00002E8;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 osRamTest4_6105(void) {
    if (D_A00002E8 != 0xC86E2000) {
        return 0;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o156/overlay_156/osRamTest4_6105.s")
#endif
