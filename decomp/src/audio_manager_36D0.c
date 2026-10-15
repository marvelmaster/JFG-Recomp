#include "common.h"

const char D_800AAAE0[] = "OUT OF AUDIO POINTS\n";

#define SOUND_MASK_HEAP_COUNT 40

/* decomp: externs */
#ifdef NON_MATCHING
extern struct SoundData *D_800F35F0;
extern SoundMask *D_800F29F8_B1758;
extern SoundMask **D_800F2A00_B1760;
extern u8 D_800F29FC_B175C;
extern u16 D_800A0800_A1400;
extern SoundMask **D_800F35F4;
extern s32 D_800A0814_A1414;
extern u8 D_800F2A48_B17A8[];
extern s32 D_800A1094[];
void amGetSfxSettings(s32 *arg0, s32 *arg1, s32 *arg2);
void amResetAudioMap(void);
void amPlayAudioLines(void);
void amSndStop(s32 handle);
void amSndPlayDirect(s32 soundID, u8 volume, u8 pan, f32 pitch, u8 arg4, void **handlePtr);
void gsSndpSetParam(s32 handle, s16 type, u32 paramValue);
void gsSndpSetPriority(s32 handle, u8 priority);
u8 *camGetListPtr(void);
void camGetPlayerProjMtx(s32 arg0, f32 (*arg1)[4]);
s32 amCalcSfxStereo(f32 x, f32 y, f32 z);
void amSndSetEcho(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80003AC0(SoundMask *arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4);
void func_80003C44(s32 arg0);
void func_80003DC4(SoundMask *arg0);
void duckshootInit(void *arg0, s32 arg1); /* runtime-linked overlay call, 2 args per asm */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amInitAudioMap(void) {
    s32 i;

    amGetSfxSettings((s32 *) &D_800F35F0, 0, 0);
    D_800F29F8_B1758 = (SoundMask *) mmAlloc(0x5A0, 0xFFFFFF);
    D_800F2A00_B1760 = (SoundMask **) mmAlloc(0xA0, 0xFFFFFF);
    D_800F35F4 = (SoundMask **) mmAlloc(0xA0, 0xFFFFFF);
    D_800A0800_A1400 = 0;
    for (i = 0; i < SOUND_MASK_HEAP_COUNT; i++) {
        D_800F29F8_B1758[i].unk18 = 0;
    }
    amResetAudioMap();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/amInitAudioMap.s")
#endif

void amAmbientPause(void) {
    amAmbientStop();
    D_800F3604 = TRUE;
}

void amAmbientRestart(void) {
    D_800F3604 = FALSE;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amResetAudioMap(void) {
    SoundMask *pool;
    SoundMask *snd;
    s32 i;

    pool = D_800F29F8_B1758;
    D_800F29FC_B175C = 0;
    i = 0;
    do {
        D_800F2A00_B1760[i] = pool;
        pool++;
        D_800F29FC_B175C++;
        i = D_800F29FC_B175C;
    } while (i < SOUND_MASK_HEAP_COUNT);
    D_800F29FC_B175C = i - 1;

    for (i = 0; i < D_800A0800_A1400; i++) {
        snd = D_800F35F4[i];
        snd->unk12 = 0;
        if (snd->unk18 != 0) {
            amSndStop(snd->unk18);
        }
    }
    D_800A0800_A1400 = 0;
    D_800F3604 = FALSE;
    for (i = 0; i < 12; i++) {
        *(s32 *) (D_800F2A48_B17A8 + i * 0x10) = 0;
    }
    if (runlinkIsModuleLoaded(0x2C) != 0) {
        amPlayAudioLines();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/amResetAudioMap.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-frame update of the positional ambient-sound map (SoundMask list in D_800F35F4).
// Field names: flags/unk11 bit 0x2 = SINGLE_PLAYER, 0x4 = ONE_TIME_TRIGGER (cf. DKR
// src/audio_spatial.h, audspat_update_all). unk10 = minVolume, unk20 = fastFalloff,
// unk21 = priority, distance = range (0x14), unk23 is a raw byte (via +0x23).
void amPlayAudioMap(s32 arg0, s32 arg1, s32 arg2) {
    s32 numCams;
    u8 *camList;
    SoundMask *snd;
    u8 *cam;
    s32 i;
    s32 j;
    s32 vol;
    s32 range;
    s32 dist;
    s32 v1;
    s32 flag;
    u32 pan;
    u32 stereo;
    u32 sp7C; /* asm: stack slot 0x7C, read as the starting pan, stored back after the loop */
    f32 pitch;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 nearest;
    f32 falloff;

    /* asm: arg0..arg2 are spilled to the stack and never read */
    numCams = mainGetNumberOfCameras();
    if (numCams == 1) {
        camGetPlayerProjMtx(0, D_800F3608);
    }
    camList = camGetListPtr();

    if (D_800A0800_A1400 > 0) {
        pan = sp7C;
        for (i = 0; i < D_800A0800_A1400; i++) {
            vol = 0;
            snd = D_800F35F4[i];

            if (snd->unk11 & 2) {
                /* SINGLE_PLAYER: only handled when there is exactly one camera (camera 0) */
                if (numCams == 1) {
                    dx = snd->pos.x - *(f32 *) (camList + 0xC);
                    dy = snd->pos.y - *(f32 *) (camList + 0x10);
                    dz = snd->pos.z - *(f32 *) (camList + 0x14);
                    range = snd->distance;
                    dist = (s32) sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                    if (dist < range && snd->unk12 == 0) {
                        pitch = (f32) snd->pitch / 100.0f;
                        stereo = amCalcSfxStereo(snd->pos.x, snd->pos.y, snd->pos.z);
                        pan = stereo;
                        if ((stereo >> 24) != 0) {
                            pan = stereo & 0xFF;
                            flag = 0x80;
                        } else {
                            flag = 0;
                        }
                        if (numCams != 1) {
                            pan = 0x40;
                        }
                        if (snd->unk18 == 0 && (snd->unk22 == 0 || !(snd->unk11 & 4))) {
                            amSndPlayDirect(snd->soundId, snd->volume, pan & 0xFF, pitch, flag,
                                            (void **) &snd->unk18);
                            snd->unk22 = 1;
                        } else if (snd->unk18 != 0) {
                            gsSndpSetParam(snd->unk18, 8, scalevol(snd->volume << 8));
                            gsSndpSetParam(snd->unk18, 0x10, *(u32 *) &pitch);
                            gsSndpSetParam(snd->unk18, 4, pan);
                            amSndSetEcho(snd->unk18, *(s32 *) &snd->pos.x, *(s32 *) &snd->pos.y,
                                         *(s32 *) &snd->pos.z);
                            gsSndpSetParam(snd->unk18, 0x100, flag);
                        }
                        snd->unk12 = 1;
                    } else if (range < dist && snd->unk12 != 0) {
                        snd->unk12 = 0;
                    }
                }
            } else {
                /* positional: loudest falloff over all cameras, then pan from the nearest camera */
                if (numCams > 0) {
                    cam = camList;
                    for (j = 0; j < numCams; j++) {
                        dx = snd->pos.x - *(f32 *) (cam + 0xC);
                        dy = snd->pos.y - *(f32 *) (cam + 0x10);
                        dz = snd->pos.z - *(f32 *) (cam + 0x14);
                        range = snd->distance;
                        dist = (s32) sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                        if (dist < range) {
                            if (snd->unk20 == 0) {
                                /* linear falloff */
                                v1 = (s32) ((1.0f - ((f32) dist / (f32) range)) * (f32) snd->volume);
                            } else {
                                /* quadratic falloff */
                                falloff = (f32) (range - dist) / (f32) range;
                                v1 = (s32) (falloff * falloff * (f32) snd->volume);
                            }
                            if (vol < v1) {
                                vol = v1;
                                pan = amCalcSfxStereo(snd->pos.x, snd->pos.y, snd->pos.z);
                            }
                        }
                        cam += 0x4C;
                    }
                }

                if (vol < snd->unk10) {
                    nearest = 999999.0f;
                    if (numCams > 0) {
                        cam = camList;
                        for (j = 0; j < numCams; j++) {
                            dx = snd->pos.x - *(f32 *) (cam + 0xC);
                            dy = snd->pos.y - *(f32 *) (cam + 0x10);
                            dz = snd->pos.z - *(f32 *) (cam + 0x14);
                            dist = (s32) sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                            if ((f32) dist < nearest) {
                                pan = amCalcSfxStereo(snd->pos.x, snd->pos.y, snd->pos.z);
                                nearest = (f32) dist;
                            }
                            cam += 0x4C;
                        }
                    }
                    vol = snd->unk10;
                }

                if (vol >= 0xB) {
                    pitch = (f32) snd->pitch / 100.0f;
                    flag = 0;
                    if (numCams != 1) {
                        pan = 0x40;
                    }
                    if ((pan >> 24) != 0) {
                        pan &= 0xFF;
                        flag = 0x80;
                    }
                    if (*((u8 *) snd + 0x23) == 0) {
                        if (snd->unk18 == 0 && (snd->unk22 == 0 || !(snd->unk11 & 4))) {
                            amSndPlayDirect(snd->soundId, vol & 0xFF, pan & 0xFF, pitch, flag,
                                            (void **) &snd->unk18);
                            snd->unk22 = 1;
                        } else if (snd->unk18 != 0) {
                            gsSndpSetParam(snd->unk18, 8, scalevol(vol << 8));
                            gsSndpSetParam(snd->unk18, 0x10, *(u32 *) &pitch);
                            gsSndpSetParam(snd->unk18, 4, pan);
                            gsSndpSetPriority(snd->unk18, snd->unk21);
                            amSndSetEcho(snd->unk18, *(s32 *) &snd->pos.x, *(s32 *) &snd->pos.y,
                                         *(s32 *) &snd->pos.z);
                            gsSndpSetParam(snd->unk18, 0x100, flag);
                        }
                    } else {
                        func_80003AC0(snd, vol, pitch, pan, flag);
                    }
                } else {
                    if (snd->unk18 != 0) {
                        amSndStop(snd->unk18);
                        if (*((u8 *) snd + 0x23) != 0) {
                            func_80003DC4(snd);
                        }
                    } else {
                        snd->unk22 = 1;
                    }
                }
            }
        }
        sp7C = pan;
    }

    for (i = 0; i < 4; i++) {
        func_80003C44(i);
    }

    for (i = 0; i < D_800A0800_A1400; i++) {
        snd = D_800F35F4[i];
        if (*((u8 *) snd + 0x23) != 0) {
            snd->unk22 = 1;
        }
        if ((snd->unk11 & 4) && snd->unk22 != 0 && snd->unk18 == 0) {
            func_80003E24(i);
        }
    }

    if (runlinkIsModuleLoaded(0x2C) != 0) {
        duckshootInit(camList, numCams);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/amPlayAudioMap.s")
#endif

s32 amCalcSfxStereo(f32 x, f32 y, f32 z) {
    s16 arctan;
    s32 ret;
    f32 ox;
    f32 oy;
    f32 oz;

    if (mainGetNumberOfCameras() >= 2) {
        return 64;
    }
    mathMtxXFMF(D_800F3608, x, y, z, &ox, &oy, &oz);
    arctan = Arctanf(ox, oz);
    if (arctan >= -0x2000 && arctan <= 0x2000) {
        ret = 64 + ((arctan * 0x3F) / 8192);
    } else if (arctan < -0x2000 && arctan > -0x6000) {
        ret = (64 + ((s32) ((-arctan * 0x3F) + 0xFFE86000) / 16384)) | 0xFF000000;
    } else if (arctan > 0x2000 && arctan < 0x6000) {
        ret = (64 + ((s32) ((-arctan * 0x3F) + 0x17A000) / 16384)) | 0xFF000000;
    } else {
        ret = 64 | 0xFF000000;
    }
    return ret;
}

void amCreateAudioPoint(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, u8 arg5, u8 volume, u16 distance, u8 arg8, u8 pitch,
                        u8 argA, u8 argB, SoundMask **soundMask);

/* Size: 0x0A bytes */
typedef struct SoundData {
    u16 soundBite; // Audio file index.
    u8 volume;     // Multiplied by 256. 128 = 32768, max volume.
    u8 unk3;
    u8 pitch; // Fractional. 100 = 1.0f.
    u8 unk5;
    u16 distance; // Ingame units distance, same as any other.
    u8 unk8;
    u8 unk9;
} SoundData;
extern SoundData *D_800F35F0;

void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, SoundMask **soundMask) {

    if (soundMask == NULL || *soundMask == NULL) {
        amCreateAudioPoint(D_800F35F0[soundId].soundBite, x, y, z, arg4, D_800F35F0[soundId].unk3,
                           D_800F35F0[soundId].volume, D_800F35F0[soundId].distance, 0, D_800F35F0[soundId].pitch,
                           D_800F35F0[soundId].unk8, D_800F35F0[soundId].unk5, soundMask);
    }
}

void amSndSetVolXYZ(SoundMask *soundMask, u8 volume) {
    if (soundMask != NULL) {
        soundMask->volume = volume;
    }
}

void amSndSetPitchXYZ(SoundMask *soundMask, u8 pitch) {
    if (soundMask != NULL) {
        soundMask->pitch = pitch;
    }
}

void amSndPlayDirectXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, u8 volume, f32 pitch, u8 arg7,
                        SoundMask **soundMask) {
    amCreateAudioPoint(soundId, x, y, z, arg4, 100, volume, 15000, 0, pitch, 0x3F, 0, soundMask);
}

void amSndSetXYZ(SoundMask *soundMask, f32 x, f32 y, f32 z) {
    if (soundMask != NULL) {
        soundMask->pos.x = x;
        soundMask->pos.y = y;
        soundMask->pos.z = z;
    }
}

extern SoundMask **D_800F35F4; // gSoundMaskHeapUsed
extern u16 D_800A0800_A1400;

void amSndStopXYZ(SoundMask *soundMask) {
    s32 i;

    if (soundMask != NULL) {
#ifdef VERSION_kiosk
        for (i = 0; i < SOUND_MASK_HEAP_COUNT; i++)
#else
        for (i = 0; i < D_800A0800_A1400; i++)
#endif
        {
            if (soundMask == D_800F35F4[i]) {
                func_80003E24(i);
                break;
            }
        }
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amSndUnlinkHandleXYZ(SoundMask *arg0) {
    s32 i;

    if (arg0 != NULL) {
        for (i = 0; i < D_800A0800_A1400; i++) {
            if (arg0 == D_800F35F4[i]) {
                arg0->soundMask = NULL;
                return;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/amSndUnlinkHandleXYZ.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amCreateAudioPoint(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, u8 arg5, u8 volume, u16 distance, u8 arg8, u8 pitch,
                        u8 argA, u8 argB, SoundMask **soundMask) {
    SoundMask *snd;

    if (D_800A0814_A1414 < D_800A0800_A1400) {
        D_800A0814_A1414 = D_800A0800_A1400;
    }
    if (D_800A0800_A1400 == SOUND_MASK_HEAP_COUNT) {
        if (soundMask != NULL) {
            *soundMask = NULL;
        }
    } else {
        snd = D_800F2A00_B1760[D_800F29FC_B175C];
        D_800F29FC_B175C--;
        snd->pos.x = x;
        snd->pos.y = y;
        snd->pos.z = z;
        snd->soundId = soundId;
        snd->unk11 = arg4;
        snd->unk10 = arg5;
        snd->volume = volume;
        snd->pitch = pitch;
        snd->distance = distance;
        snd->unk20 = arg8;
        snd->unk22 = 0;
        snd->unk21 = argA;
        snd->soundMask = soundMask;
        *((u8 *) snd + 0x23) = argB;
        D_800F35F4[D_800A0800_A1400] = snd;
        D_800A0800_A1400++;
        if (soundMask != NULL) {
            *soundMask = snd;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/amCreateAudioPoint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* asm: stub, the four args are spilled to the stack and ignored */
void amSndSetEcho(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/amSndSetEcho.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80003AC0(SoundMask *arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    u8 *base;
    u8 *entry;
    s32 count;
    s32 i;
    s32 g;
    s32 minIdx;
    s32 minVol;

    g = *((u8 *) arg0 + 0x23);
    base = (u8 *) D_800F2A48_B17A8 + g * 0x30 - 0x30;
    count = ((s32 *) &D_800A0800_A1400)[g];
    for (i = 0; i < count; i++) {
        entry = base + i * 0x10;
        if (*(SoundMask **) entry == arg0) {
            *(f32 *) (entry + 4) = arg2;
            *(s32 *) (entry + 0xC) = arg3;
            entry[8] = (u8) arg1;
            entry[9] = (u8) arg4;
            return;
        }
    }

    minVol = base[8];
    minIdx = 0; /* asm: uninitialised when count == 0 */
    for (i = 0; i < count; i++) {
        entry = base + i * 0x10;
        if (*(SoundMask **) entry == NULL) {
            *(SoundMask **) entry = arg0;
            *(f32 *) (entry + 4) = arg2;
            *(s32 *) (entry + 0xC) = arg3;
            entry[8] = (u8) arg1;
            entry[9] = (u8) arg4;
            return;
        }
        if (!(minVol < entry[8])) {
            minVol = entry[8];
            minIdx = i;
        }
    }

    if (minVol < arg1) {
        entry = base + minIdx * 0x10;
        if ((*(SoundMask **) entry)->unk18 != 0) {
            amSndStop((*(SoundMask **) entry)->unk18);
        }
        *(SoundMask **) entry = arg0;
        *(f32 *) (entry + 4) = arg2;
        *(s32 *) (entry + 0xC) = arg3;
        entry[8] = (u8) arg1;
        entry[9] = (u8) arg4;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/func_80003AC0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80003C44(s32 arg0) {
    u8 *entry;
    SoundMask *snd;
    s32 i;

    entry = (u8 *) D_800F2A48_B17A8 + arg0 * 0x30;
    for (i = 0; i < D_800A1094[arg0]; i++) {
        snd = *(SoundMask **) entry;
        if (snd != NULL) {
            if (snd->unk18 == 0 && (!(snd->unk11 & 4) || snd->unk22 == 0)) {
                amSndPlayDirect(*(u16 *) ((u8 *) snd + 0xC), entry[8], entry[0xF], *(f32 *) (entry + 4), entry[9],
                                (void **) &snd->unk18);
            }
            if (snd->unk18 != 0) {
                gsSndpSetParam(snd->unk18, 8, scalevol(entry[8] << 8));
                gsSndpSetParam(snd->unk18, 0x10, *(u32 *) (entry + 4));
                gsSndpSetParam(snd->unk18, 4, *(u32 *) (entry + 0xC));
                gsSndpSetPriority(snd->unk18, snd->unk21);
                amSndSetEcho(snd->unk18, *(s32 *) &snd->pos.x, *(s32 *) &snd->pos.y, *(s32 *) &snd->pos.z);
                gsSndpSetParam(snd->unk18, 0x100, entry[9]);
            }
            snd->unk22 = 1;
        }
        entry += 0x10;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/func_80003C44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80003DC4(SoundMask *arg0) {
    u8 *entry;
    s32 count;
    s32 g;
    s32 i;

    g = *((u8 *) arg0 + 0x23);
    count = ((s32 *) &D_800A0800_A1400)[g];
    entry = (u8 *) D_800F2A48_B17A8 + g * 0x30 - 0x30;
    for (i = 0; i < count; i++) {
        if (*(SoundMask **) entry == arg0) {
            *(s32 *) entry = 0;
            return;
        }
        entry += 0x10;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/func_80003DC4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80003E24(s32 arg0) {
    SoundMask *snd;

    if (D_800A0800_A1400 != 0) {
        snd = D_800F35F4[arg0];
        if (snd->unk18 != 0) {
            amSndStop(snd->unk18);
        }
        if (snd->soundMask != NULL) {
            *snd->soundMask = NULL;
        }
        if (*((u8 *) snd + 0x23) != 0) {
            func_80003DC4(snd);
        }
        D_800F29FC_B175C++;
        D_800F2A00_B1760[D_800F29FC_B175C] = D_800F35F4[arg0];
        D_800F35F4[arg0] = D_800F35F4[D_800A0800_A1400 - 1];
        D_800A0800_A1400--;
        D_800F35F4[D_800A0800_A1400] = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/func_80003E24.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 amSndGetXYZVolume(u16 soundId, Vec3f *arg1, Vec3f *arg2) {
    SoundData *sfx;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 range;
    s32 minVol;
    s32 scaled;

    dx = arg1->x - arg2->x;
    dy = arg1->y - arg2->y;
    dz = arg1->z - arg2->z;
    dist = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    sfx = &D_800F35F0[soundId];
    minVol = sfx->unk3;
    range = (f32) sfx->distance;
    if (dist < range) {
        scaled = (s32) ((f32) sfx->volume * (1.0f - (dist / range)));
        if (minVol < scaled) {
            minVol = scaled;
        }
    }
    return minVol;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_36D0/amSndGetXYZVolume.s")
#endif
