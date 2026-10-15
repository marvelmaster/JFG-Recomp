#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#include "audio_internal.h"

Acmd *n_alFxPull(void *f, s16 *outp, s32 out, s32 sampleOffset, Acmd *p);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALFxRef n_alSynGetFXRef(s16 bus) {
    /* aux bus entries are 0x48 bytes; fx ref at +0x20 (no header struct yet) */
    if (((ALMainBus *)n_syn->mainBus)->filter.handler == n_alFxPull) {
        return *(ALFxRef *)((u8 *)n_syn->auxBus + (s32)bus * 0x48 + 0x20);
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_syngetfxref/n_alSynGetFXRef.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALFxRef n_alSynGetOutputLPRef(s16 bus) {
    /* same layout as n_alSynGetFXRef, LP ref at +0x44 */
    if (((ALMainBus *)n_syn->mainBus)->filter.handler == n_alFxPull) {
        return *(ALFxRef *)((u8 *)n_syn->auxBus + (s32)bus * 0x48 + 0x44);
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_syngetfxref/n_alSynGetOutputLPRef.s")
#endif
