#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
s32 *n_alEnvmixerPull(N_ALVoice *voice, s32 samples, s32 *cmd);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 *n_alAuxBusPull(s32 samples, s32 *cmd, s32 busIdx, s32 *cmdCount) {
    /* N_ALAuxBus (0x48 bytes) has no struct in the headers: raw offsets.
       +0x14 = voice count, +0x1C = voice pointer array. */
    u8 *auxBus = (u8 *)n_syn->auxBus + busIdx * 0x48;
    N_ALVoice **voices = *(N_ALVoice ***)(auxBus + 0x1C);
    s32 numVoices = *(s32 *)(auxBus + 0x14);
    s32 numPulled = 0;
    u32 maxScale = 1;
    u32 scale;
    u32 ratio;
    s32 word;
    s32 i;
    u8 *pv;
    u8 *vv;

    cmd[0] = 0x020007C0;
    cmd[1] = 0x2E0;
    cmd += 2;
    *cmdCount = 0;

    if (numVoices != 0) {
        for (i = 0; i < numVoices; i++) {
            pv = (u8 *)voices[i]->pvoice;
            if (pv != NULL && *(s16 *)(pv + 0x18) == busIdx) {
                vv = *(u8 **)(pv + 0x8);
                if (vv != NULL && *(u8 *)(vv + 0x8C) >= 0x40) {
                    cmd = n_alEnvmixerPull(voices[i], samples, cmd);
                    *cmdCount += 1;
                    numPulled += 1;
                    scale = *(u8 *)(vv + 0x8C);
                    if (maxScale < (u8)scale) {
                        maxScale = scale;
                    }
                }
            }
        }
    }

    if (numPulled != 0) {
        maxScale -= 0x3E;
        if (maxScale >= 7) {
            ratio = (u32)(26755.0f / sqrtf((f32)maxScale));
        } else {
            ratio = (u32)(65536.0f / (f32)maxScale);
        }
        word = (s32)(((ratio & 0xFFFF) << 16) | (maxScale & 0xFFFF));
        cmd[0] = 0x4E0;
        cmd[1] = word;
        cmd += 2;
        cmd[0] = 0x650;
        cmd[1] = word;
        cmd += 2;
    }

    if (numVoices != 0) {
        for (i = 0; i < numVoices; i++) {
            N_ALVoice *voice = voices[i];
            s32 take = 0;

            pv = (u8 *)voice->pvoice;
            if (pv != NULL && *(s16 *)(pv + 0x18) == busIdx) {
                vv = *(u8 **)(pv + 0x8);
                take = (vv == NULL || *(u8 *)(vv + 0x8C) < 0x40);
            }
            if (take || (pv == NULL && busIdx == 0)) {
                s32 *before = cmd;

                cmd = n_alEnvmixerPull(voice, samples, cmd);
                if (cmd != before) {
                    *cmdCount += 1;
                }
            }
        }
    }
    return cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_auxbus/n_alAuxBusPull.s")
#endif
