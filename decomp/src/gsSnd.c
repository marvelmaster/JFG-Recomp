#include "gsSnd.h"
#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern SoundPlayer *gSoundPlayerPtr;
extern ALSoundStateLists gSoundStateLists;
extern u16 *gSoundGroupVolume;
extern s16 D_800A95B4_AA1B4;
void n_alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);
void func_80084910(void *arg0);
void func_80085CF8(ALEventQueue *evtq, void *arg1, u16 arg2);
void func_80086120(ALSoundState *arg0);
void n_alSynStopVoice(void *v);
void n_alSynFreeVoice(void *v);
void n_alSynAddSndPlayer(ALPlayer *client);
ALMicroTime n_alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt);
void n_alEvtqNew(ALEventQueue *evtq, void *items, s32 itemCount);
s32 func_80084848(void *arg0);
extern u32 globalVolume;
void func_80085C0C(ALSoundState *arg0);
void func_80085C7C(ALSoundState *arg0);
u16 getSoundStateCounts(u16 *numFree, u16 *numAllocated);
s32 n_alSynAllocVoice(void *v, ALVoiceConfig *vc);
void n_alSynSetVol(void *v, s32 volume, s32 delta);
void n_alSynSetPan(void *v, u8 pan);
void n_alSynSetPitch(void *v, f32 pitch);
void n_alSynSetFXMix(void *v, s32 fxmix);
void n_alSynStartVoiceParams(void *v, ALWaveTable *w, f32 pitch, u32 vol, s32 pan, s32 fxmix,
                             s32 unk0, f32 unk1, s32 unk2, s32 delta);

typedef struct unkSndpConfig {
    s32 numStates;      /* 0x00 */
    s32 numEvents;      /* 0x04 */
    s32 maxChannels;    /* 0x08 */
    ALHeap *heap;       /* 0x0C */
    u16 numGroups;      /* 0x10 (asm: lhu) */
} unkSndpConfig;

typedef struct unkSndEvtItem {
    ALLink node;        /* 0x00 */
    s32 delta;          /* 0x08 */
    s16 type;           /* 0x0C */
    s16 pad0E;
    ALSoundState *state; /* 0x10 */
} unkSndEvtItem;
/* JFG sound state, layout from asm of func_80084910 / func_80085EF0.
   Offsets 0x34 and up differ from libaudio's ALSoundState (retries, volume, priority, pan, fxmix). */
typedef struct unkSndState {
    struct unkSndState *next;        /* 0x00 */
    struct unkSndState *prev;        /* 0x04 */
    ALSound *sound;                  /* 0x08 */
    ALVoice voice;                   /* 0x0C */
    f32 slideMult;                   /* 0x28 */
    f32 pitch;                       /* 0x2C */
    struct unkSndState **userHandle; /* 0x30 */
    s32 retries;                     /* 0x34 */
    s16 volume;                      /* 0x38 */
    s16 envVolume;                   /* 0x3A */
    s32 envEndTime;                  /* 0x3C */
    u8 priority;                     /* 0x40 */
    u8 pan;                          /* 0x41 */
    u8 fxmix;                        /* 0x42 */
    u8 flags;                        /* 0x43 */
    u8 state;                        /* 0x44 */
} unkSndState;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void gsSndpNew(unkSndpConfig *cfg) {
    s32 i;
    s16 evtType;
    ALSoundState *states;
    ALSoundState *st;
    void *evtItems;

    gSoundPlayerPtr->maxSystemSoundChannels = cfg->maxChannels;
    gSoundPlayerPtr->curTime = cfg->maxChannels;
    gSoundPlayerPtr->soundStatesArray = NULL;
    gSoundPlayerPtr->maxActiveSounds = 0x3E80;
    states = alHeapDBAlloc(NULL, 0, cfg->heap, 1, cfg->numStates * 0x48);
    *(ALSoundState **) ((u8 *) gSoundPlayerPtr + 0x44) = states;
    evtItems = alHeapDBAlloc(NULL, 0, cfg->heap, 1, cfg->numEvents * 0x1C);
    n_alEvtqNew(&gSoundPlayerPtr->evtq, evtItems, cfg->numEvents);
    gSoundStateLists.freeHead = states;
    /* JFG sound states are 0x48 bytes (unkSndState), not sizeof(ALSoundState) */
    for (i = 1; (u32) i < (u32) cfg->numStates; i++) {
        st = (ALSoundState *) ((u8 *) *(ALSoundState **) ((u8 *) gSoundPlayerPtr + 0x44) + i * 0x48);
        alLink((ALLink *) st, (ALLink *) ((u8 *) st - 0x48));
    }
    gSoundGroupVolume = alHeapDBAlloc(NULL, 0, cfg->heap, 2, cfg->numGroups);
    if (cfg->numGroups != 0) {
        i = 0;
        do {
            gSoundGroupVolume[i] = 0x7FFF;
            i++;
        } while (i < (u16) cfg->numGroups);
    }
    gSoundPlayerPtr->node.next = NULL;
    gSoundPlayerPtr->node.handler = (ALVoiceHandler) func_80084848;
    gSoundPlayerPtr->node.clientData = gSoundPlayerPtr;
    n_alSynAddSndPlayer((ALPlayer *) gSoundPlayerPtr);
    evtType = 0x20;
    n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &evtType, gSoundPlayerPtr->maxActiveSounds);
    gSoundPlayerPtr->frameTime = n_alEvtqNextEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &gSoundPlayerPtr->nextEvent.msg);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/gsSndpNew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80084848(void *arg0) {
    u8 *sp = (u8 *) arg0;
    s16 evtType;

    do {
        if (*(s16 *) (sp + 0x2C) == 0x20) {
            evtType = 0x20;
            n_alEvtqPostEvent((ALEventQueue *) (sp + 0x14), (ALEvent *) &evtType, *(s32 *) (sp + 0x4C));
        } else {
            func_80084910(sp + 0x2C);
        }
        *(s32 *) (sp + 0x50) = (s32) n_alEvtqNextEvent((ALEventQueue *) (sp + 0x14), (ALEvent *) (sp + 0x2C));
    } while (*(s32 *) (sp + 0x50) == 0);
    *(s32 *) (sp + 0x54) += *(s32 *) (sp + 0x50);
    return *(s32 *) (sp + 0x50);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/func_80084848.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Structure follows cf. DKR sndp_handle_event (audiosfx.c); field offsets from the asm.
void func_80084910(void *arg0) {
    ALSndpEvent *event = (ALSndpEvent *) arg0;
    ALSndpEvent nextStateEvent;
    ALSndpEvent evt;
    ALVoiceConfig config;
    ALSound *sound;
    ALKeyMap *keyMap;
    ALEventQueue *evtq;
    unkSndState *st;
    unkSndState *nextState;
    unkSndState *iterState;
    s32 limitReached;
    s32 isVoiceAllocated;
    s32 lastInSequence;
    s32 isEventForSingleSound;
    s32 delta;
    s32 tmp;
    u32 volume;
    s32 pan;
    s32 fxMix;
    u16 numFree;
    u16 numAlloc;

    evtq = &gSoundPlayerPtr->evtq;
    lastInSequence = TRUE;
    isVoiceAllocated = FALSE;
    st = NULL;
    nextState = NULL;

    do {
        if (nextState != NULL) {
            nextStateEvent.common.state = (ALSoundState *) st;
            nextStateEvent.common.type = event->common.type;
            nextStateEvent.common.param = event->common.param;
            event = &nextStateEvent;
        }

        st = (unkSndState *) event->common.state;
        sound = st->sound;
        if (sound == NULL) {
            getSoundStateCounts(&numFree, &numAlloc);
            osSyncPrintf("Bad soundState: voices =%d, states free =%d, states busy =%d, type %d data %x\n",
                         D_800A95B4_AA1B4, numFree, numAlloc, (s32) event->common.type, event->common.param);
            return;
        }

        keyMap = sound->keyMap;
        nextState = st->next;

        switch (event->common.type) {
            case AL_SNDP_PLAY_EVT:
                if (st->state != SOUND_STATE_INIT && st->state != SOUND_STATE_WAIT_VOICE) {
                    return;
                }
                if (st->state == SOUND_STATE_PLAYING) {
                    /* asm: unreachable (state is already checked to be 4 or 5) */
                    osSyncPrintf("playing a playing sound\n");
                }

                config.priority = st->priority;
                config.fxBus = 0;
                config.unityPitch = 0;

                limitReached = (D_800A95B4_AA1B4 >= gSoundPlayerPtr->curTime);
                if (!limitReached || (st->flags & SOUND_FLAG_RETRIGGER)) {
                    isVoiceAllocated = n_alSynAllocVoice(&st->voice, &config);
                }

                if (!isVoiceAllocated) {
                    if ((st->flags & (SOUND_FLAG_RETRIGGER | SOUND_FLAG_LOOPED)) || st->retries > 0) {
                        st->state = SOUND_STATE_WAIT_VOICE;
                        st->retries = st->retries - 1;
                        n_alEvtqPostEvent(evtq, (ALEvent *) event, 33333);
                    } else if (limitReached) {
                        iterState = (unkSndState *) gSoundStateLists.allocTail;
                        do {
                            if ((s32) st->priority >= (s32) iterState->priority) {
                                if (!(iterState->flags & (SOUND_FLAG_RETRIGGER | SOUND_FLAG_LOOPED)) &&
                                    (iterState->flags & SOUND_FLAG_PLAYING) &&
                                    (iterState->state != SOUND_STATE_PREEMPT)) {
                                    limitReached = FALSE;
                                    evt.common.type = AL_SNDP_END_EVT;
                                    evt.common.state = (ALSoundState *) iterState;
                                    iterState->state = SOUND_STATE_PREEMPT;
                                    n_alEvtqPostEvent(evtq, (ALEvent *) &evt, 1000);
                                    n_alSynSetVol(&iterState->voice, 0, 1000);
                                }
                            }
                            iterState = iterState->prev;
                        } while (limitReached && iterState != NULL);

                        if (!limitReached) {
                            st->retries = 2;
                            n_alEvtqPostEvent(evtq, (ALEvent *) event, 1001);
                        } else {
                            func_80085C0C((ALSoundState *) st);
                        }
                    } else {
                        func_80085C0C((ALSoundState *) st);
                    }
                    return;
                }

                st->flags |= SOUND_FLAG_PLAYING;
                st->envVolume = (s16) sound->envelope->attackVolume;
                delta = (s32) (((f32) sound->envelope->attackTime / st->pitch) / st->slideMult);
                st->envEndTime = (s32) (gSoundPlayerPtr->nextDelta + delta);

                tmp = ((s32) (s16) gSoundGroupVolume[keyMap->keyMin & 0x3F] *
                       ((s32) (st->envVolume * st->volume * sound->sampleVolume) / 16129)) / 32767;
                if (tmp <= 0) {
                    volume = 0;
                } else {
                    volume = (u32) (tmp - 1);
                }
                volume = (u32) (volume * globalVolume) >> 8;

                pan = (s32) st->pan + sound->samplePan - 0x40;
                if (pan < 0) {
                    pan = 0;
                }
                if (pan > 0x7F) {
                    pan = 0x7F;
                }

                fxMix = (st->fxmix & 0x7F) + ((keyMap->keyMax & 0xF) * 8);
                if (fxMix < 0) {
                    fxMix = 0;
                }
                if (fxMix > 0x7F) {
                    fxMix = 0x7F;
                }
                fxMix |= st->fxmix & 0x80;

                n_alSynStartVoiceParams(&st->voice, sound->wavetable, st->pitch * st->slideMult, volume, pan, fxMix,
                                        0, 0.0f, 0, delta);
                st->state = SOUND_STATE_PLAYING;
                D_800A95B4_AA1B4 += 1;

                if (!(st->flags & SOUND_FLAG_LOOPED)) {
                    if (delta == 0) {
                        st->envVolume = (s16) sound->envelope->decayVolume;
                        tmp = ((s32) (s16) gSoundGroupVolume[keyMap->keyMin & 0x3F] *
                               ((s32) (st->envVolume * st->volume * sound->sampleVolume) / 16129)) / 32767;
                        if (tmp <= 0) {
                            volume = 0;
                        } else {
                            volume = (u32) (tmp - 1);
                        }
                        volume = (u32) (volume * globalVolume) >> 8;
                        delta = (s32) (((f32) sound->envelope->decayTime / st->slideMult) / st->pitch);
                        st->envEndTime = (s32) (gSoundPlayerPtr->nextDelta + delta);
                        n_alSynSetVol(&st->voice, volume, delta);
                        evt.common.type = AL_SNDP_RELEASE_EVT;
                        evt.common.state = (ALSoundState *) st;
                        n_alEvtqPostEvent(evtq, (ALEvent *) &evt, delta);
                        if (st->flags & SOUND_FLAG_PITCH_SLIDE) {
                            func_80085C7C((ALSoundState *) st);
                        }
                    } else {
                        evt.common.type = AL_SNDP_DECAY_EVT;
                        evt.common.state = (ALSoundState *) st;
                        delta = (s32) (((f32) sound->envelope->attackTime / st->pitch) / st->slideMult);
                        n_alEvtqPostEvent(evtq, (ALEvent *) &evt, delta);
                    }
                }
                break;

            case AL_SNDP_RELEASE_EVT:
            case AL_SNDP_STOP_EVT:
            case AL_SNDP_RELEASE_NEXT_EVT:
                if ((event->common.type != AL_SNDP_RELEASE_NEXT_EVT) || (st->flags & SOUND_FLAG_LOOPED)) {
                    switch (st->state) {
                        case SOUND_STATE_PLAYING:
                            func_80085CF8(evtq, st, AL_SNDP_DECAY_EVT);
                            delta = (s32) (((f32) sound->envelope->releaseTime / st->slideMult) / st->pitch);
                            n_alSynSetVol(&st->voice, 0, delta);
                            if (delta != 0) {
                                evt.common.type = AL_SNDP_END_EVT;
                                evt.common.state = (ALSoundState *) st;
                                n_alEvtqPostEvent(evtq, (ALEvent *) &evt, delta);
                                st->state = SOUND_STATE_STOPPING;
                            } else {
                                func_80085C0C((ALSoundState *) st);
                            }
                            break;
                        case SOUND_STATE_WAIT_VOICE:
                        case SOUND_STATE_INIT:
                            func_80085C0C((ALSoundState *) st);
                            break;
                    }
                    if (event->common.type == AL_SNDP_RELEASE_EVT) {
                        event->common.type = AL_SNDP_RELEASE_NEXT_EVT;
                    }
                }
                break;

            case AL_SNDP_PAN_EVT:
                st->pan = (u8) event->common.param;
                if (st->state == SOUND_STATE_PLAYING) {
                    pan = (s32) st->pan + sound->samplePan - 0x40;
                    if (pan < 0) {
                        pan = 0;
                    }
                    if (pan > 0x7F) {
                        pan = 0x7F;
                    }
                    n_alSynSetPan(&st->voice, (u8) pan);
                }
                break;

            case AL_SNDP_PITCH_EVT:
                st->pitch = *(f32 *) &event->common.param;
                if (st->state == SOUND_STATE_PLAYING) {
                    n_alSynSetPitch(&st->voice, st->pitch * st->slideMult);
                    if (st->flags & SOUND_FLAG_PITCH_SLIDE) {
                        func_80085C7C((ALSoundState *) st);
                    }
                }
                break;

            case AL_SNDP_FX_EVT:
                st->fxmix = (u8) event->common.param;
                if (st->state == SOUND_STATE_PLAYING) {
                    fxMix = (st->fxmix & 0x7F) + ((keyMap->keyMax & 0xF) * 8);
                    if (fxMix < 0) {
                        fxMix = 0;
                    }
                    if (fxMix > 0x7F) {
                        fxMix = 0x7F;
                    }
                    fxMix |= st->fxmix & 0x80;
                    n_alSynSetFXMix(&st->voice, fxMix);
                }
                break;

            case AL_SNDP_VOL_EVT:
                st->volume = (s16) event->common.param;
                if (st->state == SOUND_STATE_PLAYING) {
                    tmp = ((s32) (s16) gSoundGroupVolume[keyMap->keyMin & 0x3F] *
                           ((s32) (st->envVolume * st->volume * sound->sampleVolume) / 16129)) / 32767;
                    if (tmp <= 0) {
                        volume = 0;
                    } else {
                        volume = (u32) (tmp - 1);
                    }
                    volume = (u32) (volume * globalVolume) >> 8;
                    if ((st->envEndTime - gSoundPlayerPtr->nextDelta) < 0x3E8) {
                        delta = 0x3E8;
                    } else {
                        delta = st->envEndTime - gSoundPlayerPtr->nextDelta;
                    }
                    n_alSynSetVol(&st->voice, volume, delta);
                }
                break;

            case AL_SNDP_GROUP_VOL_EVT:
                if (st->state == SOUND_STATE_PLAYING) {
                    delta = (s32) (((f32) sound->envelope->releaseTime / st->slideMult) / st->pitch);
                    tmp = ((s32) (s16) gSoundGroupVolume[keyMap->keyMin & 0x3F] *
                           ((s32) (st->envVolume * st->volume * sound->sampleVolume) / 16129)) / 32767;
                    if (tmp <= 0) {
                        volume = 0;
                    } else {
                        volume = (u32) (tmp - 1);
                    }
                    volume = (u32) (volume * globalVolume) >> 8;
                    n_alSynSetVol(&st->voice, volume, delta);
                }
                break;

            case AL_SNDP_DECAY_EVT:
                if (!(st->flags & SOUND_FLAG_LOOPED)) {
                    st->envVolume = (s16) sound->envelope->decayVolume;
                    tmp = ((s32) (s16) gSoundGroupVolume[keyMap->keyMin & 0x3F] *
                           ((s32) (st->envVolume * st->volume * sound->sampleVolume) / 16129)) / 32767;
                    if (tmp <= 0) {
                        volume = 0;
                    } else {
                        volume = (u32) (tmp - 1);
                    }
                    volume = (u32) (volume * globalVolume) >> 8;
                    delta = (s32) (((f32) sound->envelope->decayTime / st->slideMult) / st->pitch);
                    st->envEndTime = (s32) (gSoundPlayerPtr->nextDelta + delta);
                    n_alSynSetVol(&st->voice, volume, delta);
                    evt.common.type = AL_SNDP_RELEASE_EVT;
                    evt.common.state = (ALSoundState *) st;
                    n_alEvtqPostEvent(evtq, (ALEvent *) &evt, delta);
                    if (st->flags & SOUND_FLAG_PITCH_SLIDE) {
                        func_80085C7C((ALSoundState *) st);
                    }
                }
                break;

            case AL_SNDP_END_EVT:
                func_80085C0C((ALSoundState *) st);
                break;

            case AL_SNDP_RETRIGGER_EVT:
                if (st->flags & SOUND_FLAG_RETRIGGER) {
                    ad_sndp_play(event->retrigger.bank, (s16) event->retrigger.soundIndex, (u16) st->volume,
                                 (u8) st->pan, st->pitch, (u8) st->fxmix, (void **) st->userHandle);
                }
                break;

            default:
                osSyncPrintf("Nonsense sndp event\n");
                break;
        }

        st = nextState;
        isEventForSingleSound = event->common.type & (AL_SNDP_PLAY_EVT | AL_SNDP_PITCH_EVT | AL_SNDP_DECAY_EVT |
                                                      AL_SNDP_END_EVT | AL_SNDP_RETRIGGER_EVT);
        if (st != NULL && !isEventForSingleSound) {
            lastInSequence = st->flags & SOUND_FLAG_FINAL_IN_SEQUENCE;
        }
    } while (!lastInSequence && st != NULL && !isEventForSingleSound);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/func_80084910.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80085C0C(ALSoundState *arg0) {
    if (arg0->flags & 4) {
        n_alSynStopVoice(&arg0->voice);
        n_alSynFreeVoice(&arg0->voice);
    }
    func_80086120(arg0);
    func_80085CF8(&gSoundPlayerPtr->evtq, arg0, 0xFFFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/func_80085C0C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80085C7C(ALSoundState *arg0) {
    f32 ratio;
    ALSndpEvent evt;

    ratio = alCents2Ratio((s32) arg0->sound->keyMap->detune) * arg0->pitch;
    evt.common.type = 0x10;
    evt.common.state = arg0;
    *(s32 *) &evt.common.param = *(s32 *) &ratio;
    n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &evt, 0x8235);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/func_80085C7C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80085CF8(ALEventQueue *evtq, void *arg1, u16 arg2) {
    OSIntMask mask;
    unkSndEvtItem *item;
    unkSndEvtItem *next;

    mask = osSetIntMask(OS_IM_NONE);
    item = (unkSndEvtItem *) evtq->allocList.next;
    while (item != NULL) {
        next = (unkSndEvtItem *) item->node.next;
        if ((item->state == arg1) && (item->type & arg2)) {
            if (next != NULL) {
                next->delta += item->delta;
            }
            alUnlink((ALLink *) item);
            *(s16 *) ((u8 *) evtq + 0x10) = (s16) (*(s16 *) ((u8 *) evtq + 0x10) - 1);
            alLink((ALLink *) item, (ALLink *) evtq);
        }
        item = next;
    }
    osSetIntMask(mask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/func_80085CF8.s")
#endif

// ALSoundStateLists gSoundStateLists = { NULL, NULL, NULL };
extern ALSoundStateLists gSoundStateLists;

/**
 * Takes two pointers as arguments and writes the number of free and allocated sound states to them.
 * Additionally, it counts the number of allocated sound states in reverse order.
 * But why? It should be the same as in the forward order.
 * Official Name: getSoundStateCounts
 */
u16 getSoundStateCounts(u16 *numFree, u16 *numAllocated) {
    OSIntMask mask;
    u16 allocatedCounter;
    u16 freeCounter;
    u16 allocatedRevCounter;
    ALSoundState *allocatedPtr;
    ALSoundState *freePtr;
    ALSoundState *allocatedRevPtr;

    mask = osSetIntMask(OS_IM_NONE);
    allocatedPtr = gSoundStateLists.allocHead;
    freePtr = gSoundStateLists.freeHead;
    allocatedRevPtr = gSoundStateLists.allocTail;

    for (allocatedCounter = 0; allocatedPtr != NULL; allocatedCounter++, allocatedPtr = allocatedPtr->next) {}
    for (freeCounter = 0; freePtr != NULL; freeCounter++, freePtr = freePtr->next) {}
    for (allocatedRevCounter = 0; allocatedRevPtr != NULL; allocatedRevCounter++, allocatedRevPtr = allocatedRevPtr->prev) {}

    *numFree = freeCounter;
    *numAllocated = allocatedCounter;

    osSetIntMask(mask);

    return allocatedRevCounter;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALLink *func_80085EF0(ALBank *arg0, ALSound *arg1) {
    ALSoundState *st;
    ALKeyMap *keyMap;
    s32 loopFlag;
    OSIntMask mask;

    keyMap = arg1->keyMap;
    mask = osSetIntMask(OS_IM_NONE);
    st = gSoundStateLists.freeHead;
    if (st != NULL) {
        gSoundStateLists.freeHead = st->next;
        alUnlink((ALLink *) st);
        if (gSoundStateLists.allocHead != NULL) {
            st->next = gSoundStateLists.allocHead;
            st->prev = NULL;
            gSoundStateLists.allocHead->prev = st;
            gSoundStateLists.allocHead = st;
        } else {
            st->prev = NULL;
            st->next = st->prev;
            gSoundStateLists.allocHead = st;
            gSoundStateLists.allocTail = st;
        }
        osSetIntMask(mask);
        loopFlag = (arg1->envelope->decayTime + 1) == 0;
        st->sound = arg1;
        st->pad3E[2] = (u8) (loopFlag + 0x40);
        st->state = 5;
        st->pitch = 1.0f;
        *(s32 *) ((u8 *) st + 0x34) = 2;
        st->flags = keyMap->keyMax & 0xF0;
        st->userHandle = NULL;
        if (st->flags & 0x20) {
            st->slideMult = alCents2Ratio(SOUND_PARAM_PITCH(keyMap));
        } else {
            st->slideMult = alCents2Ratio(SOUND_PARAM_PITCH(keyMap) + keyMap->detune);
        }
        if (loopFlag != 0) {
            st->flags |= 2;
        }
        st->pad3E[4] = 0;
        st->pad3E[3] = 0x40;
        *(s16 *) ((u8 *) st + 0x38) = 0x7FFF;
    } else {
        osSetIntMask(mask);
    }
    return (ALLink *) st;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/func_80085EF0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80086120(ALSoundState *arg0) {
    if (gSoundStateLists.allocHead == arg0) {
        gSoundStateLists.allocHead = arg0->next;
    }
    if (gSoundStateLists.allocTail == arg0) {
        gSoundStateLists.allocTail = arg0->prev;
    }
    alUnlink((ALLink *) arg0);
    if (gSoundStateLists.freeHead != NULL) {
        arg0->next = gSoundStateLists.freeHead;
        arg0->prev = NULL;
        gSoundStateLists.freeHead->prev = arg0;
        gSoundStateLists.freeHead = arg0;
    } else {
        arg0->prev = NULL;
        arg0->next = NULL;
        gSoundStateLists.freeHead = arg0;
    }
    if (arg0->flags & 4) {
        D_800A95B4_AA1B4 -= 1;
    }
    arg0->state = 0;
    if (arg0->userHandle != NULL) {
        if (*arg0->userHandle == arg0) {
            *arg0->userHandle = NULL;
        }
        arg0->userHandle = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/func_80086120.s")
#endif

typedef struct {
    u8 pad[0x40];
    u8 unk40;
    u8 pad41[0x3];
    u8 unk44;
} UnkSndPriority;

/**
 * Sets the priority for voice allocation and for preempting another sound.
 * Official Name: gsSndpSetPriority
 */
void gsSndpSetPriority(UnkSndPriority *sndp, u8 priority) {
    if (sndp != NULL) {
        sndp->unk40 = (s16) priority;
    }
}

/**
 * Retrieves the current sound state, refer to the SoundStates enum.
 * Official Name: gsSndpGetState
 */
u8 gsSndpGetState(ALSoundState *sndp) {
    if (sndp != NULL) {
        return sndp->state;
    } else {
        return SOUND_STATE_NONE;
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *ad_sndp_play(ALBank *arg0, s16 arg1, u16 arg2, u8 arg3, f32 arg4, u8 arg5, void **arg6) {
    ALSoundState *st = NULL;
    ALSoundState *cur;
    ALSound *sound;
    ALKeyMap *keyMap;
    ALSndpEvent playEvt;
    ALSndpEvent retrigEvt;
    s16 retrigIdx = 0;
    s32 durAccum = 0;
    s32 dur = 0;
    s32 retrigDur = 0;
    s32 vol;

    if (arg1 != 0) {
        do {
            // asm: sound = *(instArray[0] + sndId * 4 + 0xC)
            sound = *(ALSound **)((u8 *)arg0->instArray[0] + (arg1 * 4) + 0xC);
            cur = (ALSoundState *) func_80085EF0(arg0, sound);
            if (cur != NULL) {
                *(ALSoundState **)((u8 *)gSoundPlayerPtr + 0x40) = cur;
                playEvt.common.type = 1;
                playEvt.common.state = cur;

                vol = arg3 + cur->pad3E[3] - 0x40;
                if (vol >= 0x80) {
                    vol = 0x7F;
                } else if (vol < 0) {
                    vol = 0;
                }
                cur->pad3E[3] = (u8) vol;
                *(s16 *)((u8 *)cur + 0x38) = (s16)(((u32)(arg2 * *(s16 *)((u8 *)cur + 0x38))) >> 0xF);
                cur->pitch = cur->pitch * arg4;
                cur->pad3E[4] = arg5;

                keyMap = sound->keyMap;
                dur = SOUND_PARAM_DURATION(keyMap);
                if (cur->flags & 0x10) {
                    cur->flags = (u8) (cur->flags & ~0x10);
                    n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &playEvt, durAccum + 1);
                    retrigDur = dur + 1;
                    retrigIdx = arg1;
                } else {
                    n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &playEvt, dur + 1);
                }
                st = cur;
            } else {
                osSyncPrintf("Sound state allocate failed - sndId %d\n", arg1);
            }
            durAccum += dur;
            keyMap = sound->keyMap;
            arg1 = (s16) SOUND_PARAM_NEXT_SOUND(keyMap);
        } while ((arg1 != 0) && (cur != NULL));

        if (st != NULL) {
            st->flags = (u8) (st->flags | 1);
            st->userHandle = (struct ALSoundState **) arg6;
            if (retrigIdx != 0) {
                st->flags = (u8) (st->flags | 0x10);
                retrigEvt.retrigger.type = 0x200;
                retrigEvt.retrigger.state = st;
                retrigEvt.retrigger.soundIndex = retrigIdx;
                retrigEvt.retrigger.bank = arg0;
                n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &retrigEvt, retrigDur);
            }
        }
    }
    if (arg6 != NULL) {
        *arg6 = st;
    }
    return st;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gsSnd/ad_sndp_play.s")
#endif

typedef struct unk800DC6BC_40 {
    ALLink node;
    u8 pad0C[0x38];
} unk800DC6BC_40;
typedef struct unk800DC6BC {
    ALPlayer node;
    ALEventQueue evtq;
    ALEvent nextEvent;
    ALSynth *drvr;
    u32 unk3C;
    unk800DC6BC_40 *unk40;
    s32 soundChannelsMax;
    s32 soundChannels;
    s32 frameTime;
    ALMicroTime nextDelta;
    ALMicroTime curTime;
} unk800DC6BC; // ALSndPlayer
extern SoundPlayer *gSoundPlayerPtr;
extern void osSyncPrintf(const char *fmt, ...);
void n_alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);
extern const char D_800B002C[];

void gsSndpStop(ALSoundState *state) {
    ALEvent alEvent;

    alEvent.type = AL_SNDP_STOP_EVT;
    alEvent.msg.sndpevent.soundState = state;
    if (state != NULL) {
        alEvent.msg.sndpevent.soundState->flags &= ~AL_SNDP_PITCH_EVT;
        n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, &alEvent, 0);
    } else {
        osSyncPrintf("WARNING: Attempt to stop NULL sound aborted\n");
    }
}

void sndp_stop_with_flags(u8 event) {
    OSIntMask mask;
    ALEvent evt;
    ALSoundState *queue;

    mask = osSetIntMask(OS_IM_NONE);
    queue = gSoundStateLists.allocHead;
    while (queue != NULL) {
        evt.type = AL_SNDP_STOP_EVT;
        evt.msg.sndpevent.soundState = queue;
        if ((queue->flags & event) == event) {
            evt.msg.sndpevent.soundState->flags &= ~AL_SNDP_PITCH_EVT;
            n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, &evt, 0);
        }
        queue = queue->next;
    }
    osSetIntMask(mask);
}

/**
 * Stops all sounds from playing.
 * Official Name: gsSndpStopAll
 */
void gsSndpStopAll(void) {
    sndp_stop_with_flags(SOUND_FLAG_FINAL_IN_SEQUENCE);
}

/**
 * Stops all retriggered sounds from playing.
 * Official Name: gsSndpStopAllRetrigger
 */
void gsSndpStopAllRetrigger(void) {
    sndp_stop_with_flags(SOUND_FLAG_FINAL_IN_SEQUENCE | SOUND_FLAG_RETRIGGER);
}

/**
 * Stops all looped sounds from playing.
 * Official Name: gsSndpStopAllLooped
 */
void gsSndpStopAllLooped(void) {
    sndp_stop_with_flags(SOUND_FLAG_FINAL_IN_SEQUENCE | SOUND_FLAG_LOOPED);
}

/**
 * Send a message to the sound player to update an existing property of the sound entry.
 * Official Name: gsSndpSetParam
 */
void gsSndpSetParam(SoundHandle soundMask, s16 type, u32 paramValue) {
    ALSndpEvent evt;
    evt.common.type = type;
    evt.common.state = soundMask;
    evt.common.param = paramValue;
    if (soundMask != NULL) {
        n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &evt, 0);
    } else {
        osSyncPrintf("WARNING: Attempt to modify NULL sound aborted\n");
    }
}

extern u16 *gSoundGroupVolume;

/**
 * Returns the volume level of the channel ID.
 * Official Name: gsSndpGetMasterVolume
 */
u16 gsSndpGetMasterVolume(u8 groupID) {
    return gSoundGroupVolume[groupID];
}

void gsSndpSetMasterVolume(u8 groupID, u16 volume) {
    OSIntMask mask;
    ALSoundState *state;
    s32 i;
    ALSndpEvent evt;

    mask = osSetIntMask(OS_IM_NONE);
    state = gSoundStateLists.allocHead;
    gSoundGroupVolume[groupID] = volume;

    for (i = 0; state != NULL;) {
        if (SOUND_PARAM_GROUP(state->sound->keyMap) == groupID) {
            evt.common.type = AL_SNDP_GROUP_VOL_EVT;
            evt.common.state = state;
            n_alEvtqPostEvent(&gSoundPlayerPtr->evtq, (ALEvent *) &evt, 0);
        }
        i++, state = state->next;
    }

    osSetIntMask(mask);
}

extern u32 globalVolume; // u32 globalVolume = 0x100;

void gsSndpSetGlobalVolume(u32 arg0) {
    if (arg0 > 0x100) {
        arg0 = 0x100;
    }
    globalVolume = arg0;
}

extern u32 globalVolume;

u32 gsSndpGetGlobalVolume(void) {
    return globalVolume;
}

void gsSndpLimitVoices(s32 arg0) {
    if (gSoundPlayerPtr->maxSystemSoundChannels >= arg0) {
        gSoundPlayerPtr->curTime = arg0;
    } else {
        gSoundPlayerPtr->curTime = gSoundPlayerPtr->maxSystemSoundChannels;
    }
}
