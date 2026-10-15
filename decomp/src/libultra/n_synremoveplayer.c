#include "common.h"

// Only exists in the kiosk build; the US ROM has no n_alSynRemovePlayer (no asm is split for it).
#ifdef VERSION_kiosk
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synremoveplayer/n_alSynRemovePlayer.s")
#endif
