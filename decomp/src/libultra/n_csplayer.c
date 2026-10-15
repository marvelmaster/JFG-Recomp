#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"

/*
 * N_ALCSPlayer in PR/n_libaudio.h is 4 bytes short from frameTime on:
 * the asm has chanState at 0x64, vAllocHead 0x68, vFreeList 0x70, ...
 * Fields at 0x5C and above are therefore accessed by raw offset.
 */
#define CSP_FIELD(p, off, type) (*(type *)((u8 *)(p) + (off)))

extern s32 D_800A97BC_AA3BC;
void n_alCSPAllChanOn(N_ALCSPlayer *seqp);
void __n_initChanState(N_ALCSPlayer *seqp); /* sig mismatch: n_seqp.h uses N_ALSeqPlayer */
ALMicroTime func_80086C80(void *arg0);
void func_80087810(N_ALCSPlayer *arg0, N_ALEvent *evt);
void func_800897D4(N_ALCSPlayer *arg0, N_ALEvent *evt);
void func_80089A14(ALEventQueue *evtq, N_ALEventListItem *item);
void func_80089B08(N_ALCSPlayer *arg0, f32 tempoVal);
void __n_CSPPostNextSeqEvent(N_ALCSPlayer *arg0);
s32 __alCSeqNextDelta(ALCSeq *seq, s32 *delta);
s16 __n_vsVol(N_ALVoiceState *voice, N_ALCSPlayer *seqp);
ALMicroTime __n_vsDelta(N_ALVoiceState *voice, ALMicroTime t);
void n_alSynSetLpf_freq(N_ALVoice *v, f32 freq);
void n_alSynSetLpf_gain(N_ALVoice *v, s16 gain);
void n_alSynSetDistort(N_ALVoice *v, u8 distort);
ALSound *__n_lookupSoundQuick(N_ALCSPlayer *seqp, u8 key, u8 vel, u8 chan);
N_ALVoiceState *__n_lookupVoice(N_ALCSPlayer *seqp, u8 key, u8 chan);
N_ALVoiceState *__n_mapVoice(N_ALCSPlayer *seqp, u8 key, u8 vel, u8 chan);
void __n_setInstChanState(N_ALCSPlayer *seqp, ALInstrument *inst, s32 chan);
ALPan __n_vsPan(N_ALVoiceState *voice, N_ALCSPlayer *seqp);
f32 _depth2Cents(u8 depth);
extern s32 D_800A95C0_AA1C0[];
extern s32 D_80104FD0_B1750[];
f32 alSemitones2Ratio(s32 semitones);
void func_800874FC(N_ALCSPlayer *arg0);
void __n_initFromBank(N_ALCSPlayer *seqp, ALBank *b);
void __n_seqpReleaseVoice(N_ALCSPlayer *seqp, N_ALVoice *voice, ALMicroTime deltaTime);
char __n_voiceNeedsNoteKill(N_ALCSPlayer *seqp, N_ALVoice *voice, ALMicroTime killTime);
void __n_seqpStopOsc(N_ALCSPlayer *seqp, N_ALVoiceState *vs);
void __n_unmapVoice(N_ALCSPlayer *seqp, N_ALVoice *voice);
u8 __n_vsMix(N_ALVoiceState *voice, N_ALCSPlayer *seqp);
ALFxRef n_alSynGetOutputLPRef(s16 bus);
void n_alSynSetOutputLPParam(ALFxRef fx, s16 paramID, void *param);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPNew(N_ALCSPlayer *seqp, ALSeqpConfig *config) {
    ALHeap *heap;
    N_ALVoiceState *vs;
    N_ALEventListItem *items;
    s32 i;

    heap = config->heap;
    seqp->node.next = NULL;
    seqp->target = NULL;
    seqp->bank = NULL;
    seqp->drvr = n_syn;
    seqp->chanMask = 0xFFFF;
    n_alCSPAllChanOn(seqp);
    seqp->uspt = 0x1E8;
    seqp->nextDelta = 0;
    seqp->state = 0;
    seqp->vol = 0x7FFF;
    seqp->debugFlags = config->debugFlags;
    seqp->maxChannels = config->maxChannels;
    seqp->curTime = 0;
    seqp->nextEvent.type = AL_SEQP_API_EVT;
    CSP_FIELD(seqp, 0x60, ALMicroTime) = 0x3E80;
    CSP_FIELD(seqp, 0x74, void *) = config->initOsc;
    CSP_FIELD(seqp, 0x78, void *) = config->updateOsc;
    CSP_FIELD(seqp, 0x7C, void *) = config->stopOsc;
    CSP_FIELD(seqp, 0x80, f32) = 0.0f;
    CSP_FIELD(seqp, 0x84, f32) = 1.0f;
    CSP_FIELD(seqp, 0x88, void *) = NULL;
    CSP_FIELD(seqp, 0x8C, u8) = (u8)config->maxVoices;
    CSP_FIELD(seqp, 0x8D, u8) = 0;
    CSP_FIELD(seqp, 0x64, ALChanState *) = alHeapDBAlloc(NULL, 0, heap, config->maxChannels, 0x34);
    __n_initChanState(seqp);

    /* build the voice-state free list */
    CSP_FIELD(seqp, 0x70, N_ALVoiceState *) = NULL;
    vs = alHeapDBAlloc(NULL, 0, heap, config->maxVoices, 0x40);
    for (i = 0; i < config->maxVoices; i++) {
        N_ALVoiceState *v = (N_ALVoiceState *)((u8 *)vs + i * 0x40);
        v->next = CSP_FIELD(seqp, 0x70, N_ALVoiceState *);
        CSP_FIELD(seqp, 0x70, N_ALVoiceState *) = v;
    }
    CSP_FIELD(seqp, 0x68, N_ALVoiceState *) = NULL;
    CSP_FIELD(seqp, 0x6C, N_ALVoiceState *) = NULL;

    items = alHeapDBAlloc(NULL, 0, heap, config->maxEvents, 0x1C);
    n_alEvtqNew(&seqp->evtq, items, config->maxEvents);

    seqp->node.next = NULL;
    seqp->node.handler = func_80086C80;
    seqp->node.clientData = seqp;
    n_alSynAddSeqPlayer((ALPlayer *)seqp);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/n_alCSPNew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/*
 * Compact-sequence event handler (cf. SDK cspplayer.c __CSPHandleNextSeqEvent).
 * Runs the event at seqp->nextEvent, then fetches the next one from evtq.
 * Event msg fields start at seqp+0x3C (N_ALEvent.msg). chanState entries
 * are 0x34 bytes each; their fields are accessed by raw offset.
 */
ALMicroTime func_80086C80(void *arg0) {
    N_ALCSPlayer *seqp = (N_ALCSPlayer *)arg0;
    N_ALEvent evt;
    N_AL19Event *e19 = &seqp->nextEvent.msg.evt19;
    N_ALVoiceState *vs;
    N_ALVoice *voice;
    ALMicroTime delta;
    void *osc;
    f32 oscVal;
    s16 vol;
    u8 chan;
    u8 *chanPtr;
    ALFxRef fx;

    do {
        switch (CSP_FIELD(seqp, 0x38, u16)) {
        case 0:
            func_800874FC(seqp);
            break;
        case 2:
        case 21:
            func_80087810(seqp, &seqp->nextEvent);
            break;
        case 7:
            func_800897D4(seqp, &seqp->nextEvent);
            break;
        case 5: /* voice off */
            voice = seqp->nextEvent.msg.note.voice;
            n_alSynStopVoice(voice);
            n_alSynFreeVoice(voice);
            vs = voice->clientPrivate;
            if (vs->flags != 0) {
                __n_seqpStopOsc(seqp, vs);
            }
            __n_unmapVoice(seqp, voice);
            break;
        case 6: /* envelope volume */
            voice = seqp->nextEvent.msg.vol.voice;
            vs = voice->clientPrivate;
            if (vs->envPhase == 0) {
                vs->envPhase = 1;
            }
            delta = seqp->nextEvent.msg.vol.delta;
            vs->envEndTime = seqp->curTime + delta;
            vs->envGain = seqp->nextEvent.msg.vol.vol;
            vol = __n_vsVol(vs, seqp);
            n_alSynSetVol(voice, vol, delta);
            break;
        case 9: /* re-post self one frame later */
            evt.type = 9;
            n_alEvtqPostEvent(&seqp->evtq, &evt, CSP_FIELD(seqp, 0x60, ALMicroTime));
            break;
        case 10: /* overall volume */
            seqp->vol = seqp->nextEvent.msg.spvol.vol;
            vs = seqp->vAllocHead;
            if (vs != NULL) {
                do {
                    vol = __n_vsVol(vs, seqp);
                    n_alSynSetVol(&vs->voice, vol, __n_vsDelta(vs, seqp->curTime));
                    vs = vs->next;
                } while (vs != NULL);
            }
            break;
        case 22: /* tremolo oscillator */
            vs = seqp->nextEvent.msg.osc.vs;
            osc = seqp->nextEvent.msg.osc.oscState;
            delta = CSP_FIELD(seqp, 0x78, ALOscUpdate)(osc, &oscVal);
            vs->tremelo = (u8)(s32)oscVal;
            vol = __n_vsVol(vs, seqp);
            n_alSynSetVol(&vs->voice, vol, __n_vsDelta(vs, seqp->curTime));
            evt.type = 22;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = osc;
            n_alEvtqPostEvent(&seqp->evtq, &evt, delta);
            break;
        case 23: /* vibrato oscillator */
            vs = seqp->nextEvent.msg.osc.vs;
            osc = seqp->nextEvent.msg.osc.oscState;
            chan = seqp->nextEvent.msg.osc.chan;
            delta = CSP_FIELD(seqp, 0x78, ALOscUpdate)(osc, &oscVal);
            vs->vibrato = oscVal;
            chanPtr = CSP_FIELD(seqp, 0x64, u8 *) + chan * 0x34;
            n_alSynSetPitch(&vs->voice, *(f32 *)(chanPtr + 0x14) * (vs->pitch * vs->vibrato));
            if (chanPtr[0x11] != 0) {
                n_alSynSetLpf_freq(&vs->voice,
                    *(f32 *)(chanPtr + 0x14) * (440.0f * alSemitones2Ratio(vs->key - vs->sound->keyMap->keyBase)) * vs->vibrato);
            }
            evt.type = 23;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = osc;
            evt.msg.osc.chan = chan;
            n_alEvtqPostEvent(&seqp->evtq, &evt, delta);
            break;
        case 24: /* FX mix */
            CSP_FIELD(seqp, 0x80, f32) = CSP_FIELD(seqp, 0x3C, f32);
            CSP_FIELD(seqp, 0x84, f32) = CSP_FIELD(seqp, 0x40, f32);
            vs = seqp->vAllocHead;
            if (vs != NULL) {
                do {
                    n_alSynSetFXMix(&vs->voice, (u8)__n_vsMix(vs, seqp));
                    vs = vs->next;
                } while (vs != NULL);
            }
            break;
        case 25: /* FX / output LP parameter */
            if (e19->unk01 < 8) {
                fx = n_alSynGetFXRef(e19->unk00);
                if (fx != NULL) {
                    n_alSynSetFXParam(fx, (e19->unk02 * 8) | (e19->unk01 & 7), &e19->param);
                }
            } else {
                fx = n_alSynGetOutputLPRef(e19->unk00);
                if (fx != NULL) {
                    n_alSynSetOutputLPParam(fx, e19->unk01, &e19->param);
                }
            }
            break;
        case 12: /* chanState[chan].unk08 = byte */
            chan = e19->unk00;
            chanPtr = CSP_FIELD(seqp, 0x64, u8 *) + chan * 0x34;
            chanPtr[0x08] = e19->unk01;
            break;
        case 13: /* sequence + reset chanMask, bank init */
            seqp->target = CSP_FIELD(seqp, 0x3C, ALCSeq *);
            seqp->chanMask = 0xFFFF;
            if (seqp->bank != NULL) {
                __n_initFromBank(seqp, seqp->bank);
            }
            break;
        case 14: /* bank */
            seqp->bank = CSP_FIELD(seqp, 0x3C, ALBank *);
            __n_initFromBank(seqp, seqp->bank);
            break;
        case 15:
            if (seqp->state != 1) {
                seqp->state = 1;
                __n_CSPPostNextSeqEvent(seqp);
            }
            break;
        case 16:
            if (seqp->state == 2) {
                vs = CSP_FIELD(seqp, 0x68, N_ALVoiceState *);
                if (vs != NULL) {
                    do {
                        n_alSynStopVoice(&vs->voice);
                        n_alSynFreeVoice(&vs->voice);
                        if (vs->flags != 0) {
                            __n_seqpStopOsc(seqp, vs);
                        }
                        __n_unmapVoice(seqp, &vs->voice);
                        vs = CSP_FIELD(seqp, 0x68, N_ALVoiceState *);
                    } while (vs != NULL);
                }
                seqp->state = 0;
            }
            break;
        case 17:
            if (seqp->state == 1) {
                n_alEvtqFlushType(&seqp->evtq, 0);
                n_alEvtqFlushType(&seqp->evtq, 0x15);
                n_alEvtqFlushType(&seqp->evtq, 2);
                n_alEvtqFlushType(&seqp->evtq, 0x16);
                n_alEvtqFlushType(&seqp->evtq, 0x17);
                for (vs = CSP_FIELD(seqp, 0x68, N_ALVoiceState *); vs != NULL; vs = vs->next) {
                    if (__n_voiceNeedsNoteKill(seqp, &vs->voice, 0xC350) != 0) {
                        __n_seqpReleaseVoice(seqp, &vs->voice, 0xC350);
                    }
                }
                seqp->state = 2;
                evt.type = 16;
                n_alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
            }
            break;
        default:
            break;
        }
        seqp->nextDelta = n_alEvtqNextEvent(&seqp->evtq, &seqp->nextEvent);
    } while (seqp->nextDelta == 0);
    seqp->curTime += seqp->nextDelta;
    return seqp->nextDelta;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_80086C80.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800874FC(N_ALCSPlayer *arg0) {
    N_ALEvent evt;

    if (arg0->target == NULL) {
        return;
    }
    n_alCSeqNextEvent(arg0->target, &evt, 1);
    switch (evt.type) {
    case AL_SEQ_MIDI_EVT:
        func_80087810(arg0, &evt);
        __n_CSPPostNextSeqEvent(arg0);
        break;
    case AL_TEMPO_EVT:
        func_800897D4(arg0, &evt);
        __n_CSPPostNextSeqEvent(arg0);
        break;
    case AL_SEQ_END_EVT:
        if (D_800A97BC_AA3BC == 0) {
            arg0->state = AL_STOPPING;
            evt.type = AL_SEQP_STOP_EVT;
            n_alEvtqPostEvent(&arg0->evtq, &evt, AL_EVTQ_END);
        }
        break;
    case AL_TRACK_END:
    case AL_CSP_LOOPSTART:
    case AL_CSP_LOOPEND:
        __n_CSPPostNextSeqEvent(arg0);
        break;
    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_800874FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8008760C(N_ALCSPlayer *arg0, u8 arg1) {
    N_ALVoiceState *vs;
    s16 vol;

    vs = CSP_FIELD(arg0, 0x68, N_ALVoiceState *);
    while (vs != NULL) {
        if (vs->channel == arg1 && vs->envPhase != 3) {
            vol = __n_vsVol(vs, arg0);
            n_alSynSetVol(&vs->voice, vol, __n_vsDelta(vs, arg0->curTime));
        }
        vs = vs->next;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_8008760C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800876B8(N_ALCSPlayer *arg0, u8 arg1) {
    ALChanState *chan;
    N_ALVoiceState *vs;
    s8 semis;
    f32 pitchBend;
    s16 gain;

    chan = &CSP_FIELD(arg0, 0x64, ALChanState *)[arg1];
    semis = (s8)((s8)chan->unk12 - 0x40);
    pitchBend = chan->pitchBend;
    vs = CSP_FIELD(arg0, 0x68, N_ALVoiceState *);
    while (vs != NULL) {
        if (vs->channel == arg1) {
            gain = chan->unk11;
            n_alSynSetLpf_gain(&vs->voice, gain);
            if (gain != 0) {
                n_alSynSetLpf_freq(&vs->voice,
                    alSemitones2Ratio((vs->key - vs->sound->keyMap->keyBase) + semis) * 440.0f * pitchBend);
            }
        }
        vs = vs->next;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_800876B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/*
 * MIDI message handler for the compact sequence player (cf. DKR-style
 * __CSPHandleMIDIMsg). arg1->msg.midi is an ALMIDIEvent:
 * ticks(+0), status(+4), byte1(+5), byte2(+6), duration(+8).
 * Channel state: ALChanState[16] at seqp+0x64 (stride 0x34).
 * Voice list: seqp+0x68. Event queue: seqp+0x48.
 * Some seqp fields are read with CSP_FIELD because the header is off.
 * chanSaved / vsSaved reproduce the stale stack slots (0x94 / 0x9C) that the
 * sustain-pedal release path reads (asm: sp94 / sp9C not set on that path).
 */
void func_80087810(N_ALCSPlayer *arg0, N_ALEvent *arg1) {
    ALMIDIEvent *midi = &arg1->msg.midi;
    ALEventQueue *evtq = (ALEventQueue *)((u8 *)arg0 + 0x48);
    ALMicroTime (*initOsc)(void **, f32 *, u8, u8, u8, u8, u8);
    ALChanState *chanSaved;
    ALChanState *chan;
    N_ALVoiceState *vsSaved;
    N_ALVoiceState *vs;
    N_ALVoiceState *lp;
    N_ALVoice *voice;
    N_ALEvent e;
    ALVoiceConfig vc;
    ALSound *sound;
    ALBank *bank;
    ALInstrument *inst;
    ALMicroTime delta;
    ALMicroTime curTime;
    void *oscState;
    struct oscstate *os;
    f32 depth;
    f32 pitchRatio;
    f32 vibRatio;
    f32 lpfFreq;
    f32 bendRatio;
    f32 bendCents;
    s32 cmd;
    s32 ch;
    s32 cents;
    s32 oscType;
    s32 bendVal;
    s32 diff;
    s32 sampleNo;
    u8 key;
    u8 val;
    u8 fxmix;
    u8 lpf;
    u8 pan;
    u8 cur;
    u8 target;
    u8 inc;
    u16 mask;
    s16 vol;

    cmd = midi->status & 0xF0;
    ch = midi->status & 0xF;
    key = midi->byte1;
    val = midi->byte2;
    curTime = CSP_FIELD(arg0, 0x1C, ALMicroTime);
    initOsc = (ALMicroTime (*)(void **, f32 *, u8, u8, u8, u8, u8))CSP_FIELD(arg0, 0x74, void *);

    switch (cmd) {
    case 0x90:
        if (val != 0) {
            if ((CSP_FIELD(arg0, 0x2C, s32) != 1) || !(CSP_FIELD(arg0, 0x30, u16) & (1 << ch))) {
                /* voice not allowed to play: post a timed 0x15 event only */
                if (midi->duration != 0) {
                    e.type = 0x15;
                    e.msg.midi.status = ch | 0x80;
                    e.msg.midi.byte1 = key;
                    e.msg.midi.byte2 = 0;
                    delta = CSP_FIELD(arg0, 0x24, s32) * midi->duration;
                    D_80104FD0_B1750[ch] = delta;
                    n_alEvtqPostEvent(evtq, &e, delta);
                }
            } else {
                chanSaved = &CSP_FIELD(arg0, 0x64, ALChanState *)[ch];
                chan = chanSaved;
                sound = __n_lookupSoundQuick(arg0, key, val, ch);
                if (sound == NULL) {
                    return;
                }
                vc.priority = chan->priority;
                vc.fxBus = chan->fxbus;
                vc.unityPitch = 0;
                vsSaved = __n_mapVoice(arg0, key, val, ch);
                vs = vsSaved;
                if (vs == NULL) {
                    return;
                }
                voice = &vs->voice;
                n_alSynAllocVoice(voice, &vc);
                vs->sound = sound;
                vs->envPhase = 0;
                vs->phase = (chan->sustain >= 0x40) ? 2 : 0;

                cents = ((key - sound->keyMap->keyBase) * 100) + sound->keyMap->detune;
                if (chan->usechanparams != 0) {
                    cents += chan->pitch;
                }
                vs->pitch = alCents2Ratio(cents);
                if (chan->usechanparams != 0) {
                    vs->envEndTime = curTime + chan->attackTime;
                    vs->envGain = chan->attackVolume;
                } else {
                    vs->envEndTime = curTime + sound->envelope->attackTime;
                    vs->envGain = sound->envelope->attackVolume;
                }
                vs->flags = 0;

                /* tremolo oscillator */
                inst = chan->instrument;
                depth = 127.0f;
                if (chan->usechanparams != 0) {
                    oscType = chan->tremType;
                } else {
                    oscType = inst->tremType;
                }
                if ((oscType != 0) && (initOsc != NULL)) {
                    if (chan->usechanparams != 0) {
                        delta = initOsc(&oscState, &depth, chan->tremType, chan->tremRate, chan->tremDepth,
                                        chan->tremDelay, chan->timeindex);
                    } else {
                        delta = initOsc(&oscState, &depth, inst->tremType, inst->tremRate, inst->tremDepth,
                                        inst->tremDelay, chan->timeindex);
                    }
                    if (delta != 0) {
                        e.type = 0x16;
                        e.msg.osc.vs = vs;
                        e.msg.osc.oscState = oscState;
                        n_alEvtqPostEvent(evtq, &e, delta);
                        vs->flags |= 1;
                        vs->oscState = oscState;
                    }
                }
                vs->tremelo = (u8)(s8)(u32)depth;

                /* vibrato oscillator */
                depth = 1.0f;
                if (chan->usechanparams != 0) {
                    oscType = chan->vibType;
                } else {
                    oscType = inst->vibType;
                }
                if ((oscType != 0) && (initOsc != NULL)) {
                    if (chan->usechanparams != 0) {
                        delta = initOsc(&oscState, &depth, chan->vibType, chan->vibRate, chan->vibDepth,
                                        chan->vibDelay, chan->timeindex);
                    } else {
                        delta = initOsc(&oscState, &depth, inst->vibType, inst->vibRate, inst->vibDepth,
                                        inst->vibDelay, chan->timeindex);
                    }
                    if (delta != 0) {
                        e.type = 0x17;
                        e.msg.osc.vs = vs;
                        e.msg.osc.oscState = oscState;
                        e.msg.osc.chan = ch;
                        n_alEvtqPostEvent(evtq, &e, delta);
                        vs->flags |= 2;
                        vs->oscState2 = (struct oscstate *)oscState;
                    }
                }
                vs->vibrato = depth;

                pitchRatio = vs->pitch * chan->pitchBend * vs->vibrato;
                fxmix = __n_vsMix(vs, arg0);
                lpf = chan->unk11;
                if (lpf != 0) {
                    lpfFreq = alSemitones2Ratio(((cents / 100) + chan->unk12) - 0x40) * 440.0f * chan->pitchBend;
                } else {
                    lpfFreq = 127.0f;
                }
                pan = __n_vsPan(vs, arg0);
                vol = __n_vsVol(vs, arg0);
                if (chan->usechanparams != 0) {
                    delta = chan->attackTime;
                } else {
                    delta = sound->envelope->attackTime;
                }
                n_alSynStartVoiceParams(voice, sound->wavetable, pitchRatio, vol, pan, fxmix, lpf, lpfFreq,
                                        chan->unk13, delta);

                /* volume envelope event (decay stage) */
                e.type = 6;
                e.msg.vol.voice = voice;
                if (chan->usechanparams != 0) {
                    e.msg.vol.delta = chan->decayTime;
                    e.msg.vol.vol = chan->decayVolume;
                } else {
                    e.msg.vol.delta = sound->envelope->decayTime;
                    e.msg.vol.vol = sound->envelope->decayVolume;
                }
                n_alEvtqPostEvent(evtq, &e, delta);

                if (midi->duration != 0) {
                    e.type = 0x15;
                    e.msg.midi.status = ch | 0x80;
                    e.msg.midi.byte1 = key;
                    e.msg.midi.byte2 = 0;
                    delta = CSP_FIELD(arg0, 0x24, s32) * midi->duration;
                    D_80104FD0_B1750[ch] = delta;
                    n_alEvtqPostEvent(evtq, &e, delta);
                }
                if (((chan->notemesgflags & 1) != 0) && (CSP_FIELD(arg0, 0x88, void *) != NULL)) {
                    osSendMesg(CSP_FIELD(arg0, 0x88, OSMesgQueue *),
                               (void *)((D_80104FD0_B1750[ch] & ~0xFF) | (chan->notemesgflags >> 2)), 0);
                }
            }
            break;
        }
        /* velocity 0: fall through to note-off */
    case 0x80:
        vsSaved = __n_lookupVoice(arg0, key, ch);
        vs = vsSaved;
        if (vs == NULL) {
            return;
        }
        chan = &CSP_FIELD(arg0, 0x64, ALChanState *)[ch];
        chanSaved = chan;
        if (vs->phase == 2) {
            vs->phase = 4;
        } else {
            vs->phase = 3;
            if (chan->usechanparams != 0) {
                __n_seqpReleaseVoice(arg0, &vs->voice, chan->releaseTime);
            } else {
                __n_seqpReleaseVoice(arg0, &vs->voice, vs->sound->envelope->releaseTime);
            }
        }
        if (((chan->notemesgflags & 2) != 0) && (CSP_FIELD(arg0, 0x88, void *) != NULL)) {
            osSendMesg(CSP_FIELD(arg0, 0x88, OSMesgQueue *),
                       (void *)((key << 0x10) | 8 | (chan->notemesgflags >> 2)), 0);
        }
        return;

    case 0xA0:
        vsSaved = __n_lookupVoice(arg0, key, ch);
        vs = vsSaved;
        if (vs == NULL) {
            return;
        }
        vs->velocity = val;
        vol = __n_vsVol(vs, arg0);
        n_alSynSetVol(&vs->voice, vol, __n_vsDelta(vs, curTime));
        break;

    case 0xD0:
        for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
            if (lp->channel == ch) {
                lp->velocity = key;
                vol = __n_vsVol(lp, arg0);
                n_alSynSetVol(&lp->voice, vol, __n_vsDelta(lp, curTime));
            }
        }
        break;

    case 0xB0:
        chan = &CSP_FIELD(arg0, 0x64, ALChanState *)[ch];
        switch (key) {
        case 0x0A: /* pan */
            chan->pan = val;
            for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
                if (lp->channel == ch) {
                    pan = __n_vsPan(lp, arg0);
                    n_alSynSetPan(&lp->voice, pan);
                }
            }
            break;
        case 0xFD:
            chan->fadevolinc = val;
            break;
        case 0xFF:
            if (chan->fadevolinc == 0) {
                chan->fadevolinc = 0x90;
            }
            if (chan->fadevoltarget != val) {
                if (chan->fadevolcurrent == chan->fadevoltarget) {
                    chan->fadevoltarget = val;
                    midi->byte1 = 0xFE; /* asm: marks the posted event as a fade step */
                    goto fade_step;
                }
                chan->fadevoltarget = val;
            }
            break;
        case 0xFE:
fade_step:
            cur = chan->fadevolcurrent;
            target = chan->fadevoltarget;
            inc = chan->fadevolinc;
            diff = (s32)target - (s32)cur;
            if (diff > 0) {
                if (inc & 0x80) {
                    inc = (inc & 0x7F) * 2;
                }
                if ((s32)inc < diff) {
                    diff = inc;
                }
            } else {
                inc &= 0x7F;
                if (diff < -(s32)inc) {
                    diff = -(s32)inc;
                }
            }
            cur += diff;
            chan->fadevolcurrent = cur;
            if (cur != target) {
                n_alEvtqPostEvent(evtq, arg1, CSP_FIELD(arg0, 0x24, s32) * 0x64);
            }
            if (cur != 0) {
                CSP_FIELD(arg0, 0x30, u16) = (u16)(CSP_FIELD(arg0, 0x30, u16) | (1 << ch));
            } else {
                CSP_FIELD(arg0, 0x30, u16) = (u16)(CSP_FIELD(arg0, 0x30, u16) & ~(1 << ch));
            }
            func_8008760C(arg0, ch);
            break;
        case 0xFC:
            chan->fadevolcurrent = val;
            chan->fadevoltarget = val;
            if (val == 0) {
                mask = CSP_FIELD(arg0, 0x30, u16) & ((1 << ch) ^ 0xFFFF);
            } else {
                mask = CSP_FIELD(arg0, 0x30, u16) | (1 << ch);
            }
            CSP_FIELD(arg0, 0x30, u16) = mask;
            func_8008760C(arg0, ch);
            break;
        case 0x21:
            chan->unk11 = val;
            func_800876B8(arg0, ch);
            break;
        case 0x22:
            chan->unk12 = val;
            func_800876B8(arg0, ch);
            break;
        case 0x23:
            chan->unk13 = val;
            for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
                if (lp->channel == ch) {
                    n_alSynSetDistort(&lp->voice, val);
                }
            }
            break;
        case 0x1E:
            if (CSP_FIELD(arg0, 0x88, void *) != NULL) {
                osSendMesg(CSP_FIELD(arg0, 0x88, OSMesgQueue *),
                           (void *)((val & 7) | 0x10 | ((CSP_FIELD(arg0, 0x10, s32) << 5) & ~0xFF)), 0);
            }
            break;
        case 0x07: /* volume */
            chan->vol = val;
            for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
                if ((lp->channel == ch) && (lp->envPhase != 3)) {
                    vol = __n_vsVol(lp, arg0);
                    n_alSynSetVol(&lp->voice, vol, __n_vsDelta(lp, curTime));
                }
            }
            break;
        case 0x10:
            chan->priority = val;
            break;
        case 0x40: /* sustain pedal */
            chan->sustain = val;
            for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
                if ((lp->channel == ch) && (lp->phase != 3)) {
                    if (val >= 0x40) {
                        if (lp->phase == 0) {
                            lp->phase = 2;
                        }
                    } else if (lp->phase == 2) {
                        lp->phase = 0;
                    } else if (lp->phase == 4) {
                        lp->phase = 3;
                        if (chanSaved->usechanparams != 0) {
                            if (chan->releaseTime < 0x3E80) {
                                delta = 0x3E80;
                            } else {
                                delta = chan->releaseTime;
                            }
                            __n_seqpReleaseVoice(arg0, &lp->voice, delta);
                        } else {
                            /* asm: uses the stale sp9C voice (vsSaved), not lp */
                            if (vsSaved->sound->envelope->releaseTime < 0x3E80) {
                                delta = 0x3E80;
                            } else {
                                delta = vsSaved->sound->envelope->releaseTime;
                            }
                            __n_seqpReleaseVoice(arg0, &lp->voice, delta);
                        }
                    }
                }
            }
            break;
        case 0x5B:
            chan->fxmix = (chan->fxmix & 0x80) | val;
            val = chan->fxmix >> 7;
            /* fall through */
        case 0x41:
            chan->fxmix = (chan->fxmix & 0x7F) | (val << 7);
            for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
                if (lp->channel == ch) {
                    n_alSynSetFXMix(&lp->voice, chan->fxmix);
                }
            }
            break;
        case 0x5C:
            if (((s32)val < CSP_FIELD(n_syn, 0x3C, s32)) && ((s32)val >= 0)) {
                chan->fxbus = val;
            }
            break;
        case 0x20:
            chan->instmajor = val;
            break;
        case 0x14:
            chan->attackTime = D_800A95C0_AA1C0[val];
            break;
        case 0x15:
            chan->attackVolume = val;
            break;
        case 0x16:
            chan->decayTime = D_800A95C0_AA1C0[val];
            break;
        case 0x17:
            chan->decayVolume = val;
            break;
        case 0x18:
            chan->releaseTime = D_800A95C0_AA1C0[val];
            break;
        case 0x02:
            chan->pitch = (s8)(val - 0x40);
            break;
        case 0x03:
            chan->bendRange = (s16)(chan->bendRange / 100);
            chan->bendRange = (s16)(chan->bendRange * 100);
            chan->bendRange = (s16)(chan->bendRange + val);
            break;
        case 0x04:
            chan->bendRange = (s16)(chan->bendRange % 100);
            chan->bendRange = (s16)(chan->bendRange + (val * 100));
            break;
        case 0x0B:
            if (val != 0) {
                val += 0x80;
            }
            chan->vibType = val;
            chan->usechanparams = 1;
            break;
        case 0x0C:
            chan->vibRate = val;
            chan->usechanparams = 1;
            break;
        case 0x0D:
            chan->vibDepth = (s8)(val * 2);
            chan->usechanparams = 1;
            break;
        case 0x0E:
            chan->vibDelay = val;
            chan->usechanparams = 1;
            break;
        case 0x0F:
            chan->tremType = val;
            chan->usechanparams = 1;
            break;
        case 0x11:
            chan->tremRate = val;
            chan->usechanparams = 1;
            break;
        case 0x12:
            chan->tremDepth = val;
            chan->usechanparams = 1;
            break;
        case 0x13:
            chan->tremDelay = val;
            chan->usechanparams = 1;
            break;
        case 0x01: /* depth of the vibrato oscillator */
            val *= 2;
            for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
                if ((lp->channel == ch) && (lp->oscState2 != NULL)) {
                    os = lp->oscState2;
                    switch (os->unk04 & ~0x80) {
                    case 2:
                        os->unk10 = -_depth2Cents(val);
                        /* fall through */
                    case 3:
                    case 4:
                    case 5:
                        os->unk0c = _depth2Cents(val);
                        break;
                    case 7:
                    case 9:
                    case 13:
                        os->unk0c = _depth2Cents(val) / 2.0f;
                        break;
                    case 10:
                        os->unk0c = _depth2Cents(val) * 2.0f;
                        break;
                    default:
                        os->unk0c = _depth2Cents(val);
                        break;
                    }
                }
            }
            break;
        case 0x19:
            chan->timeindex = val;
            break;
        default:
            break;
        }
        break;

    case 0xC0: /* program change */
        chan = &CSP_FIELD(arg0, 0x64, ALChanState *)[ch];
        sampleNo = (chan->instmajor << 7) + key;
        bank = CSP_FIELD(arg0, 0x20, ALBank *);
        if (sampleNo < bank->instCount) {
            __n_setInstChanState(arg0, bank->instArray[sampleNo], ch);
        }
        break;

    case 0xE0: /* pitch bend */
        chan = &CSP_FIELD(arg0, 0x64, ALChanState *)[ch];
        bendVal = ((val << 7) + key) - 0x2000;
        cents = (s32)(chan->bendRange * bendVal) / 8192;
        bendRatio = alCents2Ratio(cents);
        chan->pitchBend = bendRatio;
        for (lp = CSP_FIELD(arg0, 0x68, N_ALVoiceState *); lp != NULL; lp = lp->next) {
            if (lp->channel == ch) {
                n_alSynSetPitch(&lp->voice, lp->pitch * bendRatio * lp->vibrato);
                if (chan->unk11 != 0) {
                    n_alSynSetLpf_freq(&lp->voice,
                        alSemitones2Ratio(lp->key - lp->sound->keyMap->keyBase) * 440.0f * bendRatio * lp->vibrato);
                }
            }
        }
        break;

    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_80087810.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800897D4(N_ALCSPlayer *arg0, N_ALEvent *arg1) {
    N_ALEventListItem *item;
    N_ALEventListItem *next;
    N_ALEventListItem *held;
    s32 accum;
    s32 savedDelta;
    s32 oldUspt;
    s32 tempo;

    held = NULL;
    accum = 0;
    if (arg1->msg.midi.status == 0xFF && arg1->msg.tempo.type == 0x51) {
        oldUspt = arg0->uspt;
        tempo = (arg1->msg.tempo.byte1 << 16) | (arg1->msg.tempo.byte2 << 8) | arg1->msg.tempo.byte3;
        func_80089B08(arg0, (f32)tempo);

        /* pull the pending note-off events out of the queue */
        item = (N_ALEventListItem *)arg0->evtq.allocList.next;
        while (item != NULL) {
            accum += item->delta;
            next = (N_ALEventListItem *)item->node.next;
            if (item->evt.type == AL_CSP_NOTEOFF_EVT) {
                alUnlink((ALLink *)item);
                *(s16 *)&arg0->evtq.eventCount -= 1;
                if (held != NULL) {
                    alLink((ALLink *)item, (ALLink *)held);
                } else {
                    item->node.next = NULL;
                    item->node.prev = NULL;
                    held = item;
                }
                savedDelta = accum;
                if (next != NULL) {
                    accum -= item->delta;
                    next->delta += item->delta;
                }
                item->delta = savedDelta;
            }
            item = next;
        }

        /* rescale the held events to the new tempo and re-queue them */
        item = held;
        while (item != NULL) {
            next = (N_ALEventListItem *)item->node.next;
            item->delta = arg0->uspt * (item->delta / oldUspt);
            func_80089A14(&arg0->evtq, item);
            item = next;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_800897D4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80089A14(ALEventQueue *evtq, N_ALEventListItem *arg1) {
    u32 intMask;
    ALLink *sp20;
    N_ALEventListItem *nxt;

    intMask = osSetIntMask(1);
    sp20 = &evtq->allocList;
    while (1) {
        if (sp20->next == NULL) {
            alLink((ALLink *)arg1, sp20);
            *(s16 *)&evtq->eventCount += 1;
            break;
        }
        nxt = (N_ALEventListItem *)sp20->next;
        if (arg1->delta < nxt->delta) {
            nxt->delta -= arg1->delta;
            alLink((ALLink *)arg1, sp20);
            *(s16 *)&evtq->eventCount += 1;
            break;
        }
        arg1->delta -= nxt->delta;
        sp20 = (ALLink *)nxt;
    }
    osSetIntMask(intMask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_80089A14.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80089B08(N_ALCSPlayer *arg0, f32 tempoVal) {
    f32 *pt = &tempoVal;
    if (arg0->target) {
        arg0->uspt = (s32)(*pt * arg0->target->qnpt);
    } else {
        arg0->uspt = 0x1E8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_80089B08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __n_CSPPostNextSeqEvent(N_ALCSPlayer *arg0) {
    N_ALEvent evt;
    s32 delta;

    if (arg0->state == AL_PLAYING) {
        if (arg0->target != NULL) {
            if (__alCSeqNextDelta(arg0->target, &delta) != 0) {
                evt.type = AL_SEQ_REF_EVT;
                n_alEvtqPostEvent(&arg0->evtq, &evt, arg0->uspt * delta);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/__n_CSPPostNextSeqEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alCSPVoiceLimit(N_ALCSPlayer *arg0, u8 arg1) {
    CSP_FIELD(arg0, 0x8C, u8) = arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/n_alCSPVoiceLimit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80089BF4(void) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_csplayer/func_80089BF4.s")
#endif
