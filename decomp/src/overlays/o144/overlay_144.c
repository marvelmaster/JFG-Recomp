#include "common.h"

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 osRamTest3_6105(void) {
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o144/overlay_144/osRamTest3_6105.s")
#endif
