#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
s32 func_8008BA2C(ALCSeq *seq, s32 track);
u8 func_8008B838(ALCSeq *seq, s32 track);
s32 func_8008B3EC(ALCSeq *seq, s32 track, N_ALEvent *evt, s32 flag);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSeqNew(ALCSeq *seq, u8 *ptr) {
    s32 i;
    u32 trackOffset;

    seq->base = (ALCMidiHdr *) ptr;
    seq->validTracks = 0;
    seq->lastTicks = 0;
    seq->lastDeltaTicks = 0;
    seq->deltaFlag = 1;
    for (i = 0; i < 16; i++) {
        seq->lastStatus[i] = 0;
        seq->curBUPtr[i] = NULL;
        seq->curBULen[i] = 0;
        trackOffset = seq->base->trackOffset[i];
        if (trackOffset != 0) {
            seq->validTracks |= 1 << i;
            seq->curLoc[i] = ptr + trackOffset;
            seq->evtDeltaTicks[i] = func_8008BA2C(seq, i);
        } else {
            seq->curLoc[i] = NULL;
        }
    }
    seq->qnpt = 1.0f / (f32) seq->base->division;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cseq/n_alCSeqNew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSeqNextEvent(ALCSeq *seq, N_ALEvent *evt, s32 arg2) {
    u32 minDelta = -1;
    u32 lastDelta = seq->lastDeltaTicks;
    s32 bestTrack = 0;
    s32 i;

    for (i = 0; i < 16; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag != 0) {
                seq->evtDeltaTicks[i] -= lastDelta;
            }
            if (seq->evtDeltaTicks[i] < minDelta) {
                minDelta = seq->evtDeltaTicks[i];
                bestTrack = i;
            }
        }
    }
    func_8008B3EC(seq, bestTrack, evt, arg2);
    evt->msg.midi.ticks = minDelta;
    seq->lastTicks += minDelta;
    seq->lastDeltaTicks = minDelta;
    if (evt->type != 0x12) {
        seq->evtDeltaTicks[bestTrack] += func_8008BA2C(seq, bestTrack);
    }
    seq->deltaFlag = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cseq/n_alCSeqNextEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8008B3EC(ALCSeq *seq, s32 track, N_ALEvent *evt, s32 flag) {
    u8 status;
    u8 metaType;
    u8 data;
    u8 b0;
    u8 cnt;
    u8 *p;
    s32 offset;

    status = func_8008B838(seq, track);
    if (status == 0xFF) {
        metaType = func_8008B838(seq, track);
        if (metaType == 0x51) {
            evt->type = 3;
            evt->msg.midi.status = status;
            evt->msg.midi.byte1 = metaType;
            /* asm: these three bytes are stored at +0xB/+0xC/+0xD (not ALTempoEvent layout) */
            *((u8 *) evt + 0xB) = func_8008B838(seq, track);
            *((u8 *) evt + 0xC) = func_8008B838(seq, track);
            *((u8 *) evt + 0xD) = func_8008B838(seq, track);
            seq->lastStatus[track] = 0;
        } else if (metaType == 0x2F) {
            seq->validTracks ^= 1 << track;
            if (seq->validTracks != 0) {
                evt->type = 0x12;
            } else {
                evt->type = 4;
            }
        } else if (metaType == 0x2E) {
            data = func_8008B838(seq, track);
            evt->msg.midi.duration = data << 8;
            data = func_8008B838(seq, track);
            evt->msg.midi.duration += data;
            seq->lastStatus[track] = 0;
            evt->type = 0x13;
        } else if (metaType == 0x2D) {
            /* loop command: count byte + 32-bit big-endian backward offset */
            p = seq->curLoc[track];
            b0 = p[0];
            p++;
            cnt = *p;
            if (cnt == 0 || flag == 0) {
                *p = b0;
                seq->curLoc[track] = p + 5;
            } else {
                if (cnt != 0xFF) {
                    *p = cnt - 1;
                }
                p++;
                offset = (s32) p[0] << 24;
                p++;
                offset += (s32) p[0] << 16;
                p++;
                offset += (s32) p[0] << 8;
                p++;
                offset += p[0];
                p++;
                seq->curLoc[track] = p - offset;
            }
            seq->lastStatus[track] = 0;
            evt->type = 0x14;
        }
    } else {
        evt->type = 1;
        if (status & 0x80) {
            evt->msg.midi.status = (status & 0xF0) | track;
            evt->msg.midi.byte1 = func_8008B838(seq, track);
            seq->lastStatus[track] = evt->msg.midi.status;
        } else {
            evt->msg.midi.status = seq->lastStatus[track];
            evt->msg.midi.byte1 = status;
        }
        if ((evt->msg.midi.status & 0xF0) != 0xC0 && (evt->msg.midi.status & 0xF0) != 0xD0) {
            evt->msg.midi.byte2 = func_8008B838(seq, track);
            if ((evt->msg.midi.status & 0xF0) == 0x90) {
                evt->msg.midi.duration = func_8008BA2C(seq, track);
            }
        } else {
            evt->msg.midi.byte2 = 0;
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cseq/func_8008B3EC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 n_alCSeqGetTicks(ALCSeq *seq) {
    return seq->lastTicks;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cseq/n_alCSeqGetTicks.s")
#endif

void func_8008B828(void) {
}

void func_8008B830(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_8008B838(ALCSeq *seq, s32 track) {
    u8 ret;
    u8 hi;
    u8 lo;
    u8 len;
    s32 off;

    if (seq->curBULen[track] != 0) {
        ret = *seq->curBUPtr[track];
        seq->curBUPtr[track]++;
        seq->curBULen[track]--;
    } else {
        ret = *seq->curLoc[track];
        seq->curLoc[track]++;
        if (ret == 0xFE) {
            hi = *seq->curLoc[track];
            seq->curLoc[track]++;
            if (hi != 0xFE) {
                lo = *seq->curLoc[track];
                seq->curLoc[track]++;
                len = *seq->curLoc[track];
                seq->curLoc[track]++;
                off = ((s32) hi << 8) + lo;
                seq->curBUPtr[track] = seq->curLoc[track] - off - 4;
                seq->curBULen[track] = len;
                ret = *seq->curBUPtr[track];
                seq->curBUPtr[track]++;
                seq->curBULen[track]--;
            }
        }
    }
    return ret;
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cseq/func_8008B838.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8008BA2C(ALCSeq *seq, s32 track) {
    s32 ret;
    s32 b;

    ret = func_8008B838(seq, track);
    if (ret & 0x80) {
        ret &= 0x7F;
        do {
            b = func_8008B838(seq, track);
            ret = (ret << 7) + (b & 0x7F);
        } while (b & 0x80);
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cseq/func_8008BA2C.s")
#endif
