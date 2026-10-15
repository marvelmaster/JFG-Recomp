#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynAddPlayer(ALPlayer *client) {
    OSIntMask mask;

    mask = osSetIntMask(1);
    client->samplesLeft = n_syn->curSamples;
    client->next = n_syn->head;
    n_syn->head = client;
    osSetIntMask(mask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synaddplayer/n_alSynAddPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynAddSndPlayer(ALPlayer *client) {
    OSIntMask mask;

    mask = osSetIntMask(1);
    client->samplesLeft = n_syn->curSamples;
    client->next = n_syn->head;
    n_syn->head = client;
    osSetIntMask(mask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synaddplayer/n_alSynAddSndPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynAddSeqPlayer(ALPlayer *client) {
    OSIntMask mask;

    mask = osSetIntMask(1);
    client->samplesLeft = n_syn->curSamples;
    client->next = n_syn->head;
    n_syn->head = client;
    osSetIntMask(mask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synaddplayer/n_alSynAddSeqPlayer.s")
#endif
