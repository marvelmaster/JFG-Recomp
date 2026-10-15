#include "common.h"
#include "PR/n_libaudio.h"
#include "PR/os_reg.h"
#include "naudio/n_seqp.h"
#include "naudio/n_sndp.h"
#include "audio.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 D_800E9774_EA374;
extern u8 *seqIndex;
extern u8 D_800E94F4_EA0F4;
extern u8 D_800E94F5_EA0F5;
extern s16 D_800E9520_EA120;
extern s8 D_800A068C_A128C;
extern s32 D_800A06A8_A12A8;
extern s32 D_800A0694_A1294;
extern u8 D_800A0698_A1298;
extern u8 D_800A069C_A129C;
extern s8 D_800A06B4_A12B4;
extern u8 D_800B0B50_B1750;
extern u8 D_800B8B50_B9750;
extern u8 D_800A0674_A1274;
extern ALSeqFile *seqFile;
extern ALBankFile *sfxBankPtr;
extern s32 maxSound;
extern s32 sfxIndex;
u16 amGetSfxCount(void);
s32 scalevol(s32 vol);
void gsSndpStop(SoundHandle state);
void gsSndpSetParam(SoundHandle soundMask, s16 type, u32 paramValue);
void amTuneMuteChl(s32 chan);
void amTuneUnmuteChl(s32 chan);
s16 amTuneGetTempoBPM(void);
void amTuneSetTempoBPM(s32 bpm);
s32 amDittyPlaying(void);
void stop_ALSeqp(N_ALSeqPlayer *seqp);
extern u8 D_800A0688_A1288;
extern ALCSeq D_800E9678_EA278;
void n_alCSPSetMessageQ(void *seqp, OSMesgQueue *mq);
u8 *piRomGetSectionPtr(u32 assetIndex, u32 assetOffset);
void amTuneSetReverbOnOff(u8 arg0);
#endif

#ifdef VERSION_us
const char D_800A9FB0[] = "No I'm not playing MIDI sequence %d, its over 32K\n";
#endif
const char D_800AA950[] = "WARNING: Sync arrived before wait - music will be out of sync with sequence\n";
#ifdef VERSION_us
const char D_800AA034[] = "I'm not playing any ditty over 4K nowadays (%d)\n";
#endif
const char D_800AA9A0[] = "amSndPlay: Illegal sound effects table index\n";
const char D_800AA9D0[] = "amSndPlayDirect: Somebody tried to play illegal sound %d\n";
const char D_800AAA0C[] = "Invalid midi sequence index\n";
#ifdef VERSION_kiosk
const char D_800AAA2C[] = "amTuneRestart:Jump failed - not previously pushed onto seq player %x\n";
#endif

void n_alCSPVoiceLimit(N_ALCSPlayer *seqp, u8 value);
u32 gsSndpGetGlobalVolume(void); //sndp_get_global_volume
void gsSndpSetMasterVolume(u8 channel, u16 volume); //sndp_set_group_volume
void amSndPlay(u16 soundID, SoundHandle *handlePtr);
void amAmbientSetVolume(u8 volume);
extern u8 sfxRelativeVolume;
extern u8 gAudioVolumeSetting;
extern N_ALSeqPlayer *ambientSeqPlayer; // Official Name: ambientSeqPlayer
#define AL_SNDP_GROUP_VOLUME_MAX 32767
void music_sequence_init(u8 seqID, N_ALSeqPlayer *seqPlayer); // Could be different in kiosk

void amTuneStop(void);
void music_sequence_start(u8 seqID, N_ALSeqPlayer *seqPlayer);

extern u8 gCanPlayMusic;
extern s32 gBlockMusicChange;
extern s32 audioPrevCount;
extern s32 gMusicTempo;
extern u32 gDynamicMusicChannelMask;
extern N_ALSeqPlayer *tuneSeqPlayer; // Official Name: tuneSeqPlayer
extern N_ALSeqPlayer **tuneSeqPlayers; // Official Name: tuneSeqPlayers
extern u8 gBlockVoiceLimitChange;
#define AUDIO_CHANNELS 16
#define MUSIC_CHAN_MASK_NONE 0xFFFFFFFF

/**
 * Changes the volume of each sound channel depending on what value is passed through.
 * Official Name: amSetMuteMode
 */
void amSetMuteMode(s32 behaviour) {
    switch (behaviour) {
        case VOLUME_LOWER: // Mute most sound effects and half the volume of music.
            gsSndpSetMasterVolume(0, 0);
            gsSndpSetMasterVolume(1, AL_SNDP_GROUP_VOLUME_MAX);
            n_alCSPSetVol(ambientSeqPlayer, 0);
            break;
        case VOLUME_LOWER_AMBIENT: // Mute the ambient channel, making course elements stop making noise.
            gsSndpSetMasterVolume(0, 0);
            break;
        default: // Restore sound back to normal.
            gsSndpSetMasterVolume(0, AL_SNDP_GROUP_VOLUME_MAX);
            gsSndpSetMasterVolume(1, AL_SNDP_GROUP_VOLUME_MAX);
            n_alCSPSetVol(ambientSeqPlayer, (s16) (gsSndpGetGlobalVolume() * sfxRelativeVolume));
            break;
    }
    gAudioVolumeSetting = behaviour;
}

/**
 * Queue a new music sequence to play if not blocked.
 * Stops any playing existing music beforehand.
 * Official Name: amTunePlay
 */
extern u32 *seqLen;
void amTunePlay(u8 seqID) {
#ifdef VERSION_kiosk
    if (gBlockMusicChange == FALSE) {
        if (gCanPlayMusic) {
            amTuneStop();
            music_sequence_start(seqID, tuneSeqPlayer);
        }
        gMusicTempo = n_alCSPGetTempo(tuneSeqPlayer);
        audioPrevCount = osGetCount();
        gDynamicMusicChannelMask = MUSIC_CHAN_MASK_NONE;
    }
#else
    if (gBlockMusicChange == FALSE && seqLen[seqID] <= 0x8000) {
        if (gCanPlayMusic) {
            amTuneStop();
            music_sequence_init(seqID, tuneSeqPlayer);
        }
        gMusicTempo = n_alCSPGetTempo(tuneSeqPlayer);
        audioPrevCount = osGetCount();
        gDynamicMusicChannelMask = MUSIC_CHAN_MASK_NONE;
    }
#endif
}

/**
 * Update the background music voice limit if not prevented from doing so.
 * Official Name: amTuneVoiceLimit
 */
void amTuneVoiceLimit(u8 voiceLimit) {
    if (gBlockVoiceLimitChange == FALSE) {
        n_alCSPVoiceLimit(tuneSeqPlayer, voiceLimit);
    }
}

void amTuneSetVolume(u8 volume);

extern u8 D_800A0EFC; //gMusicBaseVolume?
extern s32 gTuneFade;
extern s32 D_800EA090;
extern s32 D_800EA094;

void amTuneSetFade(f32 fade, u8 volume) {
    if (volume > 0x7F) {
        volume = 0x7F;
    }
    D_800EA090 = volume;
    if (osTvType == OS_TV_TYPE_PAL) {
        gTuneFade = fade * 50.0f;
    } else {
        gTuneFade = fade * 60.0f;
    }
    if (gTuneFade > 0) {
        D_800EA094 = ((D_800A0EFC - volume) << 16) / gTuneFade;
    } else {
        amTuneSetVolume(volume);
    }
}

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneSetFadeScaled(f32 fade, s32 volume) {
    s32 vol = *(u32 *) &volume & 0xFF;

    if (vol >= 0x80) {
        vol = 0x7F;
    }
    amTuneSetFade(fade, ((seqIndex[D_800E94F4_EA0F4 * 3] * vol) / 127) & 0xFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneSetFadeScaled.s")
#endif
#endif

void amTuneResetFade(void) {
    gTuneFade = 0;
}

extern s32 gAmbientFade;
extern s32 D_800EA098;
extern s32 D_800EA09C;

void amAmbientSetFade(f32 fade, u8 volume) {
    if (volume > 0x7F) {
        volume = 0x7F;
    }
    D_800EA098 = volume;
    if (osTvType == OS_TV_TYPE_PAL) {
        gAmbientFade = fade * 50.0f;
    } else {
        gAmbientFade = fade * 60.0f;
    }
    if (gAmbientFade > 0) {
        D_800EA09C = ((D_800A0EFC - volume) << 16) / gAmbientFade;
    } else {
        amTuneSetVolume(volume);
    }
}

void amAmbientResetFade(void) {
    gAmbientFade = 0;
}

//void music_sequence_init(N_ALCSPlayer *seqp, void *sequence, u8 *seqID, ALCSeq *seq);
void func_80001990(N_ALCSPlayer *arg0, u8 *arg1, u8 *arg2, ALCSeq *arg3);
extern ALCSeq *tuneCSeqp;
extern ALCSeq **tuneCSeqs;

extern void *gMusicSequenceData;
extern void *gJingleSequenceData;
extern ALCSeq gJingleSequence;
extern DelayedSound gDelayedSounds[8];
extern OSMesgQueue animCtrlQueue;
extern u8 D_800A0EF4;
extern s32 gDelayedSoundsCount;
extern u8 gMusicNextSeqID;
extern u8 gJingleNextSeqID;
extern u8 D_800A0F34;
extern s32 D_800A0F40;
extern s8 D_800A0F4C;
extern s16 sMusicTempo; //sMusicTempo
extern ALCSeq D_800EA2D8;
extern s32 D_800EA3D4;
extern OSMesgQueue animCtrlQueue;

extern u32 D_800A0F24; //gTuneGlobalVol?
extern u8 D_800A0F48;


/**
 * Run every frame, this handles the transitions in and out of music sequences.
 * If there's something in the queue, then begin to play that.
 * Additionally, it also handles the delayed audio queue, counting down and playing any sounds.
 * Official Name: amAudioTick
 */
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAudioTick(u8 updateRate) {
    void *msg;
    s32 i;

    if (osRecvMesg(&animCtrlQueue, &msg, 0) == 0) {
        D_800E9774_EA374 = 1;
    }

    if (gTuneFade > 0 || D_800A06A8_A12A8 != -1) {
        gTuneFade -= updateRate;
        if (gTuneFade < 0) {
            gTuneFade = 0;
        }
        amTuneSetVolume((((D_800EA094 * gTuneFade) >> 16) + D_800EA090) & 0xFF);
    }
    if (gAmbientFade > 0) {
        gAmbientFade -= updateRate;
        if (gAmbientFade < 0) {
            gAmbientFade = 0;
        }
        amAmbientSetVolume((((D_800EA09C * gAmbientFade) >> 16) + D_800EA098) & 0xFF);
    }

    if (D_800A0694_A1294 > 0) {
        i = 0;
        while (i < D_800A0694_A1294) {
            gDelayedSounds[i].timer -= updateRate;
            if (gDelayedSounds[i].timer <= 0) {
                amSndPlay(gDelayedSounds[i].soundId, gDelayedSounds[i].handlePtr);
                D_800A0694_A1294 -= 1;
                if (i < D_800A0694_A1294) {
                    gDelayedSounds[i].soundId = gDelayedSounds[i + 1].soundId;
                    gDelayedSounds[i].timer = gDelayedSounds[i + 1].timer;
                    gDelayedSounds[i].handlePtr = gDelayedSounds[i + 1].handlePtr;
                }
            } else {
                i++;
            }
        }
    }

    func_80001990((N_ALCSPlayer *) tuneSeqPlayer, &D_800B0B50_B1750, &D_800A0698_A1298, tuneCSeqp);
    func_80001990((N_ALCSPlayer *) ambientSeqPlayer, &D_800B8B50_B9750, &D_800A069C_A129C, &D_800E9678_EA278);

    if (D_800E9520_EA120 == -1 && tuneSeqPlayer->target != NULL) {
        D_800E9520_EA120 = (s16) (60000000 / n_alCSPGetTempo((N_ALCSPlayer *) tuneSeqPlayer));
    }

    D_800A0F48 = 0;
    D_800A06B4_A12B4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amAudioTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amWaitForMidiSync(void) {
    void *msg;

    if (D_800E9774_EA374 != 0) {
        D_800E9774_EA374 = 0;
    } else if (osRecvMesg(&animCtrlQueue, &msg, 0) != 0) {
        do {
            mainPreNMI();
        } while (osRecvMesg(&animCtrlQueue, &msg, 0) != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amWaitForMidiSync.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amResetMidiSync(void) {
    D_800E9774_EA374 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amResetMidiSync.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneSetChlMask(s32 mask) {
    s32 chan;
    u32 chanMask = mask & 0xFFFF;

    if (D_800A0698_A1298 != 0) {
        gDynamicMusicChannelMask = chanMask;
        return;
    }
    tuneSeqPlayer->chanMask = (u16) chanMask;
    for (chan = 0; chan < AUDIO_CHANNELS; chan++) {
        if (chanMask & (1 << chan)) {
            amTuneUnmuteChl(chan);
        } else {
            amTuneMuteChl(chan);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneSetChlMask.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneMuteChl(s32 chan) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneMuteChl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneUnmuteChl(s32 chan) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneUnmuteChl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneSetChlVolume(u8 chan, u8 volume) {
    if (chan < AUDIO_CHANNELS) {
        n_alCSPSetChlVol((N_ALCSPlayer *) tuneSeqPlayer, chan, volume);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneSetChlVolume.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneResetChls(void) {
    s32 chan;
    s32 c;

    if (gBlockMusicChange == 0) {
        chan = 0;
        do {
            c = chan & 0xFF;
            amTuneUnmuteChl((u8) c);
            amTuneSetChlVolume((u8) c, 0x7F);
            chan++;
        } while (chan != AUDIO_CHANNELS);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneResetChls.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneScaleTempo(f32 scale) {
    amTuneSetTempoBPM((s32) ((f32) (u32) (amTuneGetTempoBPM() & 0xFF) * scale));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneScaleTempo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneSetTempoBPM(s32 bpm) {
    if (bpm != 0) {
        n_alCSPSetTempo((N_ALCSPlayer *) tuneSeqPlayer, (s32) ((1.0f / (f32) bpm) * 6e7f));
        D_800E9520_EA120 = (s16) bpm;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneSetTempoBPM.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 amTuneGetTempoBPM(void) {
    return D_800E9520_EA120;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneGetTempoBPM.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAmbientPlay(u8 seqID) {
    if (amDittyPlaying() == 0) {
        D_800E94F5_EA0F5 = seqID;
        music_sequence_init(seqID, ambientSeqPlayer);
        D_800A068C_A128C = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amAmbientPlay.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAmbientSetTempoBPM(s32 bpm) {
    n_alCSPSetTempo((N_ALCSPlayer *) ambientSeqPlayer, (s32) ((1.0f / (f32) bpm) * 6e7f));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amAmbientSetTempoBPM.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneStop(void) {
    if (gBlockMusicChange == 0) {
        stop_ALSeqp(tuneSeqPlayer);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneStop.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAmbientStop(void) {
    if (amDittyPlaying() == 0) {
        D_800E94F5_EA0F5 = 0;
        stop_ALSeqp(ambientSeqPlayer);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amAmbientStop.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 amTuneGetSeqNo(void) {
    if (D_800E94F4_EA0F4 != 0 && tuneSeqPlayer->state == 1) {
        return D_800E94F4_EA0F4;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneGetSeqNo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 amAmbientGetSeqNo(void) {
    return D_800E94F5_EA0F5;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amAmbientGetSeqNo.s")
#endif

void amTuneSetVolume(u8 volume) {
    s32 vol;
    if (volume > 0x7F) {
        volume = 0x7F;
    }
    D_800A0EFC = volume;
    vol = D_800A0F24 * D_800A0EFC;
    n_alCSPSetVol(tuneSeqPlayer, vol);
    D_800A0F48 = 1;
}

void amTuneSetGlobalVolume(u32 volume) {
    s32 vol;
    if (volume > 0x100) {
        volume = 0x100;
    }
    D_800A0F24 = volume;
    vol = D_800A0F24 * D_800A0EFC;
    n_alCSPSetVol(tuneSeqPlayer, vol);
}


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 amTuneGetVolume(void) {
    return D_800A0EFC;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneGetVolume.s")
#endif

/**
 * Set the volume for the jingle player.
 * The jingle player scales with sfx volume rather than music volume.
 * Official Name: amAmbientSetVolume
 */
void amAmbientSetVolume(u8 volume) {
    sfxRelativeVolume = volume;
    n_alCSPSetVol(ambientSeqPlayer, (s16) (gsSndpGetGlobalVolume() * sfxRelativeVolume));
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAmbientSetPan(s32 pan) {
    s32 chan;
    s32 p = *(u32 *) &pan & 0xFF;

    for (chan = 0; chan < AUDIO_CHANNELS; chan++) {
        n_alCSPSetChlPan((N_ALCSPlayer *) ambientSeqPlayer, (u8) chan, (u8) p);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amAmbientSetPan.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amDittyPlay(s32 seqID) {
    u8 id = seqID & 0xFF;

    if (seqLen[id] < 0x1001) {
        D_800A0674_A1274 = 1;
        D_800E94F5_EA0F5 = id;
        music_sequence_init(id, ambientSeqPlayer);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amDittyPlay.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 amDittyPlaying(void) {
    if (D_800E94F5_EA0F5 != 0 && D_800A0674_A1274 != 0 && ambientSeqPlayer->state == 1) {
        return D_800E94F5_EA0F5;
    }
    D_800A0674_A1274 = 0;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amDittyPlaying.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amSndStop(SoundHandle handle) {
    gsSndpStop(handle);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amSndStop.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amSndPlay(u16 soundID, SoundHandle *handlePtr) {
    SoundData *sfx;
    f32 pitch;
    u16 bite;

    if (maxSound < soundID) {
        if (handlePtr != NULL) {
            *handlePtr = NULL;
        }
        return;
    }
    sfx = (SoundData *) sfxIndex + soundID;
    if (sfx->soundBite == 0) {
        if (handlePtr != NULL) {
            *handlePtr = NULL;
        }
        return;
    }
    bite = sfx->soundBite;
    pitch = (f32) sfx->pitch / 100.0f;
    ad_sndp_play(sfxBankPtr->bankArray[0], (s16) bite, scalevol(sfx->volume << 8) & 0xFFFF, 0x40, pitch, 0, (void **) handlePtr);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amSndPlay.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amSndPlayDirect(s32 soundID, u8 volume, u8 pan, f32 pitch, u8 arg4, void **handlePtr) {
    s32 id = soundID & 0xFFFF;

    if (id <= 0 || amGetSfxCount() < id) {
        if (handlePtr != NULL) {
            *handlePtr = NULL;
        }
    } else {
        ad_sndp_play(sfxBankPtr->bankArray[0], (s16) id, scalevol(volume << 8) & 0xFFFF, pan, pitch, arg4, handlePtr);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amSndPlayDirect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amSndSetVol(u16 soundID, SoundHandle handle, u8 volume) {
    SoundData *sfx;

    if (handle != NULL) {
        sfx = (SoundData *) sfxIndex + soundID;
        gsSndpSetParam(handle, 8, scalevol((s32) ((f32) sfx->volume * ((f32) volume / 127.0f)) << 8));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amSndSetVol.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amSndSetPan(SoundHandle handle, s32 pan) {
    if (handle != NULL) {
        gsSndpSetParam(handle, 4, pan);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amSndSetPan.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amSndSetPitchDirect(SoundHandle handle, s32 pitch) {
    if (handle != NULL) {
        gsSndpSetParam(handle, 0x10, *(u32 *) &pitch);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amSndSetPitchDirect.s")
#endif

/**
 * Return the number of playable sounds in the audio table.
 * DKR name: sound_count
 */
extern ALBankFile *sfxBankPtr;
u16 amGetSfxCount(void) {
    return sfxBankPtr->bankArray[0]->instArray[0]->soundCount;
}

extern s32 maxSound;
extern s32 sfxIndex;
extern s32 sfxIndexSize;

void amGetSfxSettings(s32 *arg0, s32 *arg1, s32 *arg2) {
    if (arg0 != NULL) {
        *arg0 = sfxIndex;
    }
    if (arg1 != NULL) {
        *arg1 = sfxIndexSize;
    }
    if (arg2 != NULL) {
        *arg2 = maxSound;
    }
}

u8 amSoundIsLooped(u16 soundID) {
    if (soundID <= 0 || sfxBankPtr->bankArray[0]->instArray[0]->soundCount < soundID) {
        return 0;
    }
    return ((u32) (1 + sfxBankPtr->bankArray[0]->instArray[0]->soundArray[soundID - 1]->envelope->decayTime) == 0);
}

#ifdef VERSION_kiosk
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/music_sequence_start.s")
#endif

/**
 * If the sequence player is currently inactive, start a new sequence with the current properties.
 */
// void music_sequence_init(N_ALCSPlayer *seqp, void *sequence, u8 *seqID, ALCSeq *seq);
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void music_sequence_init(u8 seqID, N_ALSeqPlayer *seqPlayer) {
    stop_ALSeqp(seqPlayer);
    if ((s32) seqID < seqFile->seqCount) {
        if (seqPlayer == tuneSeqPlayer) {
            D_800A0698_A1298 = seqID;
            return;
        }
        D_800A069C_A129C = seqID;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/music_sequence_init.s")
#endif

// Could be an alternate version of the above without the sequence
void func_80001990(N_ALCSPlayer *arg0, u8 *arg1, u8 *arg2, ALCSeq *arg3);
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80001990(N_ALCSPlayer *arg0, u8 *arg1, u8 *arg2, ALCSeq *arg3) {
    s32 seqIdx;
    s32 i;

    if ((n_alCSPGetState(arg0) == 0) && (*arg2 != 0)) {
        seqIdx = *arg2;
        piRomLoadSection(0x34, (u32) arg1, seqFile->seqArray[seqIdx].offset - (s32) piRomGetSectionPtr(0x34, 0),
                         (s32) seqLen[seqIdx]);
        n_alCSeqNew(arg3, arg1);
        n_alCSPSetSeq(arg0, arg3);
        n_alCSPPlay(arg0);
        if ((N_ALSeqPlayer *) arg0 == tuneSeqPlayer) {
            D_800E94F4_EA0F4 = *arg2;
            D_800A0688_A1288 = 1;
            if (D_800A0F48 != 0) {
                amTuneSetVolume(D_800A0EFC);
            } else {
                amTuneSetVolume(seqIndex[seqIdx * 3]);
            }
            if (seqIndex[seqIdx * 3 + 1] != 0) {
                amTuneSetTempoBPM(seqIndex[seqIdx * 3 + 1]);
            } else {
                D_800E9520_EA120 = -1;
            }
            amTuneSetReverbOnOff(seqIndex[seqIdx * 3 + 2]);
            if (gDynamicMusicChannelMask != -1U) {
                for (i = 0; i < 0x10; i++) {
                    if (((1 << i) & gDynamicMusicChannelMask) != 0) {
                        amTuneUnmuteChl(i);
                    } else {
                        amTuneMuteChl(i);
                    }
                }
            }
        } else {
            amAmbientSetVolume(seqIndex[seqIdx * 3]);
            if (seqIndex[seqIdx * 3 + 1] != 0) {
                amAmbientSetTempoBPM(seqIndex[seqIdx * 3 + 1]);
            }
            D_800E94F5_EA0F5 = *arg2;
        }
        *arg2 = 0;
    }
    D_800A0F48 = 0;
    D_800A06B4_A12B4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/func_80001990.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void stop_ALSeqp(N_ALSeqPlayer *seqp) {
    if ((seqp == tuneSeqPlayer) && (D_800A0688_A1288 != 0)) {
        n_alCSPStop((N_ALCSPlayer *) seqp);
        D_800A0688_A1288 = 0;
        D_800A0698_A1298 = 0;
    } else if ((seqp == ambientSeqPlayer) && (D_800A068C_A128C != 0)) {
        n_alCSPStop((N_ALCSPlayer *) seqp);
        D_800A068C_A128C = 0;
        D_800A069C_A129C = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/stop_ALSeqp.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amTuneSetReverbOnOff(u8 arg0) {
    /* asm: arg0 is spilled to the stack and never used; empty body */
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/amTuneSetReverbOnOff.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void forcelink(void) {
    n_alCSPNew(NULL, NULL);
    n_alCSPSetMessageQ(NULL, NULL);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_1050/forcelink.s")
#endif

s32 scalevol(s32 vol) {
    return (vol * 0.5f);
}
