#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 __osContLastCmd;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Builds a 0x40-byte CIC-6105 command block in securitybuffer: 0xFF fill,
// bytes 0x2E/0x2F = 0x0F, then the 16 input bytes at 0x30.
void osCic6105SendData(void *arg0, s32 arg1) {
    u8 *sb;
    u8 *src;
    s32 i;

    /* arg1 is spilled by the asm but never read */
    sb = (u8 *)securitybuffer;
    for (i = 0; i < 0x2E; i++) {
        sb[i] = 0xFF;
    }
    sb[0x2E] = 0xF;
    sb[0x2F] = 0xF;
    src = (u8 *)arg0;
    for (i = 0; i < 0x10; i++) {
        sb[0x30 + i] = src[i];
    }
    __osSiGetAccess();
    __osContLastCmd = 0xFE;
    osWritebackDCache(sb, 0x40);
    __osSiRawStartDma(1, sb);
    __osSiRelAccess();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o45/overlay_45/osCic6105SendData.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void osCic6105StartGetData(s32 arg0) {
    /* arg0 is spilled by the asm but never read */
    __osSiGetAccess();
    __osContLastCmd = 0xFE;
    osInvalDCache(securitybuffer, 0x40);
    __osSiRawStartDma(0, securitybuffer);
    __osSiRelAccess();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o45/overlay_45/osCic6105StartGetData.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void osCic6105GetReadData(u8 *arg0) {
    u8 *sb;
    s32 i;

    sb = (u8 *)securitybuffer;
    for (i = 0; i < 0x10; i++) {
        arg0[i] = sb[0x30 + i];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o45/overlay_45/osCic6105GetReadData.s")
#endif
