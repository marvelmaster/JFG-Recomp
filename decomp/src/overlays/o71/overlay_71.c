#include "common.h"

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 osCartDmaTest3_6105(void) {
    if (securitybuffer != NULL) {
        romCopy(0xF80, (u32) securitybuffer, 0x10);
        if ((((u32 *) securitybuffer)[0] == 0x6E5F923A) && (((u32 *) securitybuffer)[1] == 0xFB0BE5F6)) {
            return 1;
        }
        return 0;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o71/overlay_71/osCartDmaTest3_6105.s")
#endif
