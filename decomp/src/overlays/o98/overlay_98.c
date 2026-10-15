#include "common.h"

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 osCartDmaTest4_6105(void) {
    if (securitybuffer != NULL) {
        romCopy(0xDC0, (u32) securitybuffer, 0x10);
        if ((((u32 *) securitybuffer)[0] == 0xB06DA99E) && (((u32 *) securitybuffer)[1] == 0x5A0B4670)) {
            return 1;
        }
        return 0;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o98/overlay_98/osCartDmaTest4_6105.s")
#endif
