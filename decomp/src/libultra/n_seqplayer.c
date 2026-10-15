#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "naudio/n_seqp.h"

/* N_ALSeqPlayer fields from chanState onward: the header layout is 4 bytes short
   there (see n_libaudio.h), so these use the offsets the binary actually uses. */
#define SEQP_AT(seqp, off, type)  (*(type *) ((u8 *) (seqp) + (off)))
#define SEQP_CHANSTATE(seqp)      SEQP_AT(seqp, 0x64, ALChanState *)
#define SEQP_VALLOC_HEAD(seqp)    SEQP_AT(seqp, 0x68, N_ALVoiceState *)
#define SEQP_VALLOC_TAIL(seqp)    SEQP_AT(seqp, 0x6C, N_ALVoiceState *)
#define SEQP_VFREE(seqp)          SEQP_AT(seqp, 0x70, N_ALVoiceState *)
#define SEQP_VOICELIMIT(seqp)     SEQP_AT(seqp, 0x8C, u8)
#define SEQP_VOICECOUNT(seqp)     SEQP_AT(seqp, 0x8D, u8)
#define SEQP_STOPFN(seqp)         (*(ALOscStop *) ((u8 *) (seqp) + 0x7C))
/* ALChanState elements are 0x34 bytes in the binary; the header struct does not match, so use raw offsets */
#define SEQP_CS(seqp, chan)       ((u8 *) SEQP_CHANSTATE(seqp) + (chan) * 0x34)
#define SEQP_CS_AT(cs, off, type) (*(type *) ((u8 *) (cs) + (off)))
/* decomp: externs end */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_unmapVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice) {
    N_ALVoiceState *prev = NULL;
    N_ALVoiceState *vs = SEQP_VALLOC_HEAD(seqp);

    while (vs != NULL) {
        if (&vs->voice == voice) {
            if (prev != NULL) {
                prev->next = vs->next;
            } else {
                SEQP_VALLOC_HEAD(seqp) = vs->next;
            }
            if (SEQP_VALLOC_TAIL(seqp) == vs) {
                SEQP_VALLOC_TAIL(seqp) = prev;
            }
            vs->next = SEQP_VFREE(seqp);
            SEQP_VFREE(seqp) = vs;
            SEQP_VOICECOUNT(seqp) -= 1;
            return;
        }
        prev = vs;
        vs = vs->next;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_unmapVoice.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_seqpReleaseVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime deltaTime) {
    N_ALVoiceState *vs = (N_ALVoiceState *) voice->clientPrivate;
    N_ALEventListItem *item;
    N_ALEventListItem *next;
    N_ALEvent evt;

    if (vs->envPhase == 0) {
        // drop pending envelope events for this voice, folding their delta into the next one
        item = (N_ALEventListItem *) seqp->evtq.allocList.next;
        while (item != NULL) {
            next = (N_ALEventListItem *) item->node.next;
            if (item->evt.type == AL_SEQP_ENV_EVT && item->evt.msg.note.voice == voice) {
                if (next != NULL) {
                    next->delta += item->delta;
                }
                alUnlink((ALLink *) item);
                alLink((ALLink *) item, &seqp->evtq.freeList);
            }
            item = next;
        }
    }

    vs->velocity = 0;
    vs->envPhase = 3;
    vs->envGain = 0;
    vs->envEndTime = seqp->curTime + deltaTime;
    n_alSynSetPriority(voice, 0);
    n_alSynSetVol(voice, 0, deltaTime);

    evt.type = AL_NOTE_END_EVT;
    evt.msg.note.voice = voice;
    n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime + 0x7D00);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_seqpReleaseVoice.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
char __n_voiceNeedsNoteKill(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime killTime) {
    N_ALEventListItem *item;
    N_ALEventListItem *next;
    ALMicroTime accum = 0;
    char result = 1;

    item = (N_ALEventListItem *) seqp->evtq.allocList.next;
    while (item != NULL) {
        next = (N_ALEventListItem *) item->node.next;
        accum += item->delta;
        if (item->evt.type == AL_NOTE_END_EVT && item->evt.msg.note.voice == voice) {
            if (killTime < accum) {
                if (next != NULL) {
                    next->delta += item->delta;
                }
                alUnlink((ALLink *) item);
                alLink((ALLink *) item, &seqp->evtq.freeList);
            } else {
                result = 0;
            }
            break;
        }
        item = next;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_voiceNeedsNoteKill.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
N_ALVoiceState *__n_mapVoice(N_ALSeqPlayer *seqp, u8 key, u8 vel, u8 chan) {
    N_ALVoiceState *vs = SEQP_VFREE(seqp);

    if (SEQP_VOICELIMIT(seqp) < SEQP_VOICECOUNT(seqp)) {
        return NULL;
    }
    if (vs != NULL) {
        SEQP_VFREE(seqp) = vs->next;
        vs->next = NULL;
        if (SEQP_VALLOC_HEAD(seqp) == NULL) {
            SEQP_VALLOC_HEAD(seqp) = vs;
        } else {
            SEQP_VALLOC_TAIL(seqp)->next = vs;
        }
        SEQP_VALLOC_TAIL(seqp) = vs;
        vs->channel = chan;
        vs->key = key;
        vs->velocity = vel;
        vs->voice.clientPrivate = vs;
        SEQP_VOICECOUNT(seqp) += 1;
    }
    return vs;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_mapVoice.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
N_ALVoiceState *__n_lookupVoice(N_ALSeqPlayer *seqp, u8 key, u8 chan) {
    N_ALVoiceState *vs = SEQP_VALLOC_HEAD(seqp);

    while (vs != NULL) {
        if (vs->key == key && vs->channel == chan && vs->phase != 3 && vs->phase != 4) {
            return vs;
        }
        vs = vs->next;
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_lookupVoice.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALSound *__n_lookupSoundQuick(N_ALSeqPlayer *seqp, u8 key, u8 vel, u8 chan) {
    ALInstrument *inst = SEQP_CHANSTATE(seqp)[chan].instrument;
    s32 lo = 1;
    s32 hi = inst->soundCount;
    s32 mid;
    ALSound *sound;
    ALKeyMap *km;

    // binary search over the 1-based sound array, keyed on key range then velocity range
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        sound = inst->soundArray[mid - 1];
        km = sound->keyMap;
        if (key >= km->keyMin && key <= km->keyMax && vel >= km->velocityMin && vel <= km->velocityMax) {
            return sound;
        }
        if (key < km->keyMin || (vel < km->velocityMin && km->keyMax >= key)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_lookupSoundQuick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 __n_vsVol(N_ALVoiceState *voice, N_ALSeqPlayer *seqp) {
    ALChanState *cs = &SEQP_CHANSTATE(seqp)[voice->channel];
    s32 env;
    s32 scale;

    env = (voice->tremelo * voice->velocity * voice->envGain) >> 6;
    scale = (cs->vol * (voice->sound->sampleVolume * seqp->vol)) >> 14;
    if (cs->fadevolcurrent != 0xFF) {
        scale = ((cs->fadevolcurrent * scale) + 1) >> 8;
    }
    env *= scale;
    env = (s32) ((u32) env >> 15);
    return (s16) env;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_vsVol.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Not declared in n_seqp.h. Two float scales live in the seqp at 0x80/0x84 (names unknown).
u8 __n_vsMix(N_ALVoiceState *voice, N_ALSeqPlayer *seqp) {
    ALChanState *cs = &SEQP_CHANSTATE(seqp)[voice->channel];
    s32 flag = cs->fxmix & 0x80;
    s32 mix;

    mix = (s32) (((f32) ((cs->fxmix & 0x7F) + (s32) (SEQP_AT(seqp, 0x80, f32) * 127.0f)))
                 * SEQP_AT(seqp, 0x84, f32));
    if (mix > 0x7F) {
        mix = 0x7F;
    }
    if (mix < 0) {
        mix = 0;
    }
    return (u8) ((mix | flag) & 0xFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_vsMix.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALMicroTime __n_vsDelta(N_ALVoiceState *voice, ALMicroTime t) {
    ALMicroTime d = voice->envEndTime - t;

    if (d >= 0) {
        return d;
    }
    return 1000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_vsDelta.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALPan __n_vsPan(N_ALVoiceState *voice, N_ALSeqPlayer *seqp) {
    s32 pan = SEQP_CHANSTATE(seqp)[voice->channel].pan + voice->sound->samplePan - 0x40;

    if (pan <= 0) {
        pan = 0;
    }
    if (pan >= 0x7F) {
        pan = 0x7F;
    }
    return (ALPan) pan;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_vsPan.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_initFromBank(N_ALSeqPlayer *seqp, ALBank *b) {
    ALInstrument *inst = NULL;
    s32 i = 0;

    // first non-empty instrument slot in the bank
    do {
        inst = (ALInstrument *) b->instArray[i];
        i++;
    } while (inst == NULL);

    for (i = 0; i < seqp->maxChannels; i++) {
        __n_resetPerfChanState(seqp, i);
        __n_setInstChanState(seqp, inst, i);
    }
    if (b->percussion != NULL) {
        __n_resetPerfChanState(seqp, i);
        __n_setInstChanState(seqp, b->percussion, 9);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_initFromBank.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_initChanState(N_ALSeqPlayer *seqp) {
    s32 i;

    for (i = 0; i < seqp->maxChannels; i++) {
        SEQP_CHANSTATE(seqp)[i].instrument = NULL;
        __n_resetPerfChanState(seqp, i);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_initChanState.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_resetPerfChanState(N_ALSeqPlayer *seqp, s32 chan) {
    u8 *cs = SEQP_CS(seqp, chan);

    SEQP_CS_AT(cs, 0x04, s16) = 200;        /* bend range (cents) */
    SEQP_CS_AT(cs, 0x06, u8) = 0;
    SEQP_CS_AT(cs, 0x07, u8) = 0x40;        /* pan */
    SEQP_CS_AT(cs, 0x08, u8) = 5;           /* priority */
    SEQP_CS_AT(cs, 0x09, u8) = 0x7F;        /* volume */
    SEQP_CS_AT(cs, 0x0A, u8) = 0;
    SEQP_CS_AT(cs, 0x0B, u8) = 0;
    SEQP_CS_AT(cs, 0x0C, u8) = 0;
    SEQP_CS_AT(cs, 0x0D, u8) = 0xFF;
    SEQP_CS_AT(cs, 0x0E, u8) = 0xFF;
    SEQP_CS_AT(cs, 0x0F, u8) = 0;
    SEQP_CS_AT(cs, 0x10, u8) = 0;
    SEQP_CS_AT(cs, 0x11, u8) = 0;
    SEQP_CS_AT(cs, 0x12, u8) = 0;
    SEQP_CS_AT(cs, 0x13, u8) = 0;
    SEQP_CS_AT(cs, 0x14, f32) = 1.0f;       /* pitch bend ratio */
    SEQP_CS_AT(cs, 0x32, u8) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_resetPerfChanState.s")
#endif

void func_8008A8DC(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_setInstChanState(N_ALSeqPlayer *seqp, ALInstrument *inst, s32 chan) {
    u8 *cs = SEQP_CS(seqp, chan);
    ALSound *sound;

    SEQP_CS_AT(cs, 0x00, ALInstrument *) = inst;
    SEQP_CS_AT(cs, 0x07, u8) = inst->pan;
    SEQP_CS_AT(cs, 0x09, u8) = inst->volume;
    SEQP_CS_AT(cs, 0x08, u8) = inst->priority;
    SEQP_CS_AT(cs, 0x04, s16) = inst->bendRange;
    if (inst->soundCount == 0) {
        return;
    }
    sound = inst->soundArray[0];
    SEQP_CS_AT(cs, 0x18, ALEnvelope *) = sound->envelope;
    SEQP_CS_AT(cs, 0x1C, ALKeyMap *) = sound->keyMap;
    SEQP_CS_AT(cs, 0x20, ALWaveTable *) = sound->wavetable;
    SEQP_CS_AT(cs, 0x24, u8) = 0;
    SEQP_CS_AT(cs, 0x25, u8) = sound->samplePan;
    SEQP_CS_AT(cs, 0x26, u8) = sound->sampleVolume;
    SEQP_CS_AT(cs, 0x27, u8) = 0;
    SEQP_CS_AT(cs, 0x28, u8) = inst->tremType;
    SEQP_CS_AT(cs, 0x29, u8) = inst->tremRate;
    SEQP_CS_AT(cs, 0x2A, u8) = inst->tremDepth;
    SEQP_CS_AT(cs, 0x2B, u8) = inst->tremDelay;
    SEQP_CS_AT(cs, 0x2C, u8) = inst->vibType;
    SEQP_CS_AT(cs, 0x2D, u8) = inst->vibRate;
    SEQP_CS_AT(cs, 0x2E, u8) = inst->vibDepth;
    SEQP_CS_AT(cs, 0x2F, u8) = inst->vibDelay;
    SEQP_CS_AT(cs, 0x31, u8) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_setInstChanState.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_seqpStopOsc(N_ALSeqPlayer *seqp, N_ALVoiceState *vs) {
    N_ALEventListItem *item = (N_ALEventListItem *) seqp->evtq.allocList.next;
    N_ALEventListItem *next;
    s16 type;

    // stop pending tremolo (0x16) / vibrato (0x17) osc events for this voice state
    while (item != NULL) {
        next = (N_ALEventListItem *) item->node.next;
        type = item->evt.type;
        if ((type == AL_TREM_OSC_EVT || type == AL_VIB_OSC_EVT) && item->evt.msg.osc.vs == vs) {
            SEQP_STOPFN(seqp)(item->evt.msg.osc.oscState);
            alUnlink((ALLink *) item);
            if (next != NULL) {
                next->delta += item->delta;
            }
            alLink((ALLink *) item, &seqp->evtq.freeList);
            if (type == AL_TREM_OSC_EVT) {
                *((u8 *) vs + 0x37) &= 0xFE;    /* tremolo flag */
            } else {
                *((u8 *) vs + 0x37) &= 0xFD;    /* vibrato flag */
            }
            if (*((u8 *) vs + 0x37) == 0) {
                return;
            }
        }
        item = next;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_seqplayer/__n_seqpStopOsc.s")
#endif
