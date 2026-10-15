#include "common.h"

/* decomp: externs */
extern u32 *D_800FB110_B1750;
extern u32 *D_800FB120_B1760;
extern s32 D_800FB114_B1754;
extern s32 D_800FB124_B1764;
extern s32 D_800FB128_B1768;
extern u8 *D_800FB12C_B176C;
extern s32 D_800FB130_B1770[16];
extern unkResetColourCycle D_800FB170_B17B0[7];
extern void *D_800A31A0_A3DA0;
extern s32 D_800A31B0_A3DB0[3];
extern s16 D_800A31BC_A3DBC[3];
void *levelGetRegionFlags(void);
void levelTunePlay(f32 arg0);
void updateColourCycle(unkResetColourCycle *arg0, s32 arg1);
s32 amTuneGetSeqNo(void);
void amTunePlay(u8 arg0);
void amTuneResetChls(void);
void amTuneResetFade(void);
void amTuneScaleTempo(f32 arg0);
void amTuneSetChlMask(u16 arg0);
void amTuneStop(void);
s32 amSndPlay(s32 arg0, void *arg1, s16 arg2, void *arg3);
void amSndStop(s32 arg0, s16 arg1, s32 arg2, s16 *arg3);
void amTuneVoiceLimit(u8 arg0);
void animseqSetupGroup(s32 arg0);
void blurInit(void);
void camSetFOV(f32 arg0, s32 arg1);
void camSetNo(s32 arg0);
void dayInit(LevelHeader *arg0);
void fxInitNightVision(s32 arg0);
void gsSndpLimitVoices(s32 arg0);
void hitReset(void);
s32 mainInitRlo(void);
s32 mainGetNumberOfPlayers(void);
void objSetAnimGroup(s32 arg0);
void osCartDmaTest4_6105(f32 arg0, s32 arg1);
void rcpSetScreenColour(u8 arg0, u8 arg1, u8 arg2);
void refractInit(s16 arg0, s16 arg1, s32 arg2, s16 arg3, s32 arg4, s32 arg5);
void setWeatherLimits(s32 arg0, s32 arg1);
void setupLights(u8 arg0, s32 arg1, s32 arg2);
void setupWeather(u8 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void squadsInitialiseAfterObjects(void);
void squadsInitialiseBeforeObjects(void);
void underWaterLightsInit(void);
void viFrameRateReset(void);
extern u8 *D_800A31C4_A3DC4;
extern s32 D_800A089C_A149C;
extern u8 D_800FB1E0_B1820[];
extern u8 gfxBase[];
void fxFreeNightVision(s32 arg0);
void fxClearLevelEffects(void);
void fxCpuTextureFlush(void);
void amResetAudioMap(void);
void amSetMuteMode(s32 arg0);
void camlightFlush(void);
void freeWeather(void);
void texFreeTexture(void *tex);
void trackFreeAll(void);
void hitFree(void);
void runlinkFlushModules(void);
/* end decomp: externs */

const char D_800ACD20[] = "LOADLEVEL Error: Level out of range\n";
const char D_800ACD48[] = "levelGetRegionFlags: Ran out of levelRegionFlag structures!!\n";
const char D_800ACD88[] = "levelGetObjectID - Out of level flags\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void levelGetCounts(void) {
    LevelHeader *levelBuf;
    u8 *rec;
    s32 i;
    s32 lastIndex;
    s32 numEntries;
    s32 dataSize;
    s32 alignedSize;
    u8 *dataBuf;
    s8 world;
    s8 type;

    levelBuf = (LevelHeader *) mmAlloc(0x114, 0xFFFF00FF);
    D_800FB110_B1750 = piRomLoad(0x1EU);
    for (i = 0; i < 16; i++) {
        D_800FB130_B1770[i] = 0;
    }

    D_800FB124_B1764 = 0;
    lastIndex = 0;
    if (D_800FB110_B1750[0] != -1U) {
        i = 1;
        do {
            D_800FB124_B1764 = i;
            lastIndex = i;
            i = lastIndex + 1;
        } while (D_800FB110_B1750[i] != -1U);
    }
    D_800FB124_B1764 = lastIndex - 1;
    D_800FB12C_B176C = (u8 *) mmAlloc((lastIndex - 1) * 5, 0xFFFF00FF);
    D_800FB128_B1768 = -1;
    D_800FBBD8 = levelBuf;
    if (D_800FB124_B1764 > 0) {
        for (i = 0; i < D_800FB124_B1764; i++) {
            piRomLoadSection(0x1F, (u32) D_800FBBD8, D_800FB110_B1750[i], 0x114);
            world = *(s8 *)((u8 *) D_800FBBD8 + 0x20);
            if (D_800FB128_B1768 < world) {
                D_800FB128_B1768 = world;
            }
            type = D_800FBBD8->unk6C;
            if (type >= 0 && type < 0x10) {
                D_800FB130_B1770[type] += 1;
            }
            rec = D_800FB12C_B176C + i * 5;
            rec[0] = (u8) D_800FBBD8->unk6C;
            rec[1] = (u8) world;
            rec[2] = *(u8 *)((u8 *) D_800FBBD8 + 0x102);
            rec[3] = (u8) ((*(s8 *)((u8 *) D_800FBBD8 + 0x23) << 5) | (rec[3] & 0x1F));
            rec[3] = (u8) (((*(s8 *)((u8 *) D_800FBBD8 + 0xC8) * 8) & 0x18) | (rec[3] & 0xE7));
            rec[3] = (u8) ((*(u8 *)((u8 *) D_800FBBD8 + 0xC9) & 7) | (rec[3] & 0xF8));
            rec[4] = *(u8 *)((u8 *) D_800FBBD8 + 0x72);
        }
    }
    D_800FB128_B1768 += 1;
    mmFree(D_800FB110_B1750);
    mmFree(levelBuf);

    D_800A31A0_A3DA0 = mmAlloc(0x20, 0xFFFF00FF);
    D_800FB110_B1750 = piRomLoad(0x22U);
    numEntries = 0;
    if (D_800FB110_B1750[0] != -1U) {
        do {
            numEntries += 1;
        } while (D_800FB110_B1750[numEntries] != -1U);
    }
    lastIndex = numEntries - 1;
    dataSize = D_800FB110_B1750[lastIndex] - D_800FB110_B1750[0];
    alignedSize = (dataSize + 3) & ~3;
    dataBuf = (u8 *) mmAlloc(alignedSize + (lastIndex * 4), 0xFFFF00FF);
    D_800FB120_B1760 = (u32 *) (dataBuf + alignedSize);
    piRomLoadSection(0x23U, (u32) dataBuf, 0, dataSize);
    for (i = 0; i < lastIndex; i++) {
        D_800FB120_B1760[i] = D_800FB110_B1750[i] + (u32) dataBuf;
    }
    mmFree(D_800FB110_B1750);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetCounts.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 levelNGetType(s32 arg0) {
    if (arg0 >= 0 && arg0 < D_800FB124_B1764) {
        return D_800FB12C_B176C[arg0 * 5];
    }
    return -1U;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelNGetType.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 levelGetTune(s32 arg0) {
    if (arg0 >= 0 && arg0 < D_800FB124_B1764) {
        return D_800FB12C_B176C[arg0 * 5 + 4];
    }
    return -1U;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetTune.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s8 levelGetWorld(s32 arg0) {
    if (arg0 >= 0 && arg0 < D_800FB124_B1764) {
        return (s8) D_800FB12C_B176C[arg0 * 5 + 1];
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetWorld.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 levelGetRegionNo(s32 arg0) {
    if (arg0 >= 0 && arg0 < D_800FB124_B1764) {
        return D_800FB12C_B176C[arg0 * 5 + 2];
    }
    return 0U;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetRegionNo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 levelGetScreenMode(s32 arg0) {
    if (arg0 >= 0 && arg0 < D_800FB124_B1764) {
        return D_800FB12C_B176C[arg0 * 5 + 3] & 7;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetScreenMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u32 levelGetBlurEffect(s32 arg0) {
    if (arg0 >= 0 && arg0 < D_800FB124_B1764) {
        return (D_800FB12C_B176C[arg0 * 5 + 3] >> 3) & 3;
    }
    return 0U;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetBlurEffect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u32 levelGetGfxIndex(s32 arg0) {
    u32 camIndex;
    u32 gfxIndex;

    camIndex = mainGetNumberOfCameras() - 1;
    if (arg0 >= 0 && arg0 < D_800FB124_B1764) {
        gfxIndex = D_800FB12C_B176C[arg0 * 5 + 3] >> 5;
        if (gfxIndex != 0) {
            return gfxIndex;
        }
    }
    return camIndex;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetGfxIndex.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 levelGetWorldRegions(s32 arg0, u8 *arg1) {
    s32 count = 0;
    s32 i;
    s32 j;
    s32 found;
    u8 region;

    for (i = 0; i < D_800FB124_B1764; i++) {
        u8 *rec = D_800FB12C_B176C + i * 5;

        if (arg0 == (s8) rec[1]) {
            region = rec[2];
            if (region != 0 && region != 0xFF) {
                found = 0;
                for (j = 0; j < count; j++) {
                    if (arg1[j] == region) {
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    arg1[count] = region;
                    count += 1;
                }
            }
        }
    }
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetWorldRegions.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void levelInit(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 numLevels;
    s32 i;
    s32 playerCount;
    s32 start;
    s32 size;
    s32 freeSlot;
    s32 soundId;
    s32 fl;
    s32 k;
    s32 j;

    rumbleKill(1);
    D_800FB110_B1750 = piRomLoad(0x1EU);
    if (arg3 < 0) {
        arg3 = 0;
    }
    playerCount = mainGetNumberOfPlayers();
    if (playerCount == 2) {
        gsSndpLimitVoices(0xC);
    } else if (playerCount == 3) {
        gsSndpLimitVoices(0x10);
    } else if (playerCount == 4) {
        gsSndpLimitVoices(0x10);
    } else {
        gsSndpLimitVoices(8);
    }

    numLevels = 0;
    if (D_800FB110_B1750[0] != -1U) {
        do {
            numLevels += 1;
        } while (D_800FB110_B1750[numLevels] != -1U);
    }
    if (arg0 >= numLevels - 1) {
        arg0 = 0;
    }
    start = D_800FB110_B1750[arg0];
    size = D_800FB110_B1750[arg0 + 1] - start;
    D_800FBBD8 = (LevelHeader *) mmAlloc(size, 0xFFFF00FF);
    piRomLoadSection(0x1FU, (u32) D_800FBBD8, start, size);
    mainPreNMI();
    mmFree(D_800FB110_B1750);
    D_800FB114_B1754 = arg0;
    levelGetRegionFlags();

    for (i = 0; i < 7; i++) {
        s16 colourCycle = *(s16 *)((u8 *) D_800FBBD8 + 0x92 + i * 2);
        if (colourCycle != -1) {
            initColourCycle(&D_800FB170_B17B0[i], colourCycle);
        }
    }
    amTuneVoiceLimit(D_800FBBD8->BGColourTopB);
    amTuneResetFade();
    mainPreNMI();
    setupLights(*(u8 *)((u8 *) D_800FBBD8 + 0x104), 8, 0x10);
    mainPreNMI();
    squadsInitialiseBeforeObjects();
    mainPreNMI();
    hitReset();
    objSetAnimGroup(arg3);
    mainPreNMI();
    refractInit(*(s16 *)((u8 *) D_800FBBD8 + 0x54), *(s16 *)((u8 *) D_800FBBD8 + 0x58), arg1, *(s16 *)((u8 *) D_800FBBD8 + 0x56),
                *(s16 *)((u8 *) D_800FBBD8 + 0xCA), *(s16 *)((u8 *) D_800FBBD8 + 0xE8));
    mainPreNMI();
    animseqSetupGroup(arg3);
    mainPreNMI();
    squadsInitialiseAfterObjects();

    if (*(s16 *)((u8 *) D_800FBBD8 + 0x5A) == 0 && *(s16 *)((u8 *) D_800FBBD8 + 0x5C) == 0
        && *(u8 *)((u8 *) D_800FBBD8 + 0x60) == 0 && *(u8 *)((u8 *) D_800FBBD8 + 0x61) == 0
        && *(u8 *)((u8 *) D_800FBBD8 + 0x62) == 0) {
        for (i = 0; i < 4; i++) {
            trackSetFogOff(i);
        }
    } else {
        for (i = 0; i < 4; i++) {
            trackSetFog(i, *(s16 *)((u8 *) D_800FBBD8 + 0x5A), *(s16 *)((u8 *) D_800FBBD8 + 0x5C),
                        *(s16 *)((u8 *) D_800FBBD8 + 0x5E), (u8) *(u8 *)((u8 *) D_800FBBD8 + 0x60),
                        (u8) *(u8 *)((u8 *) D_800FBBD8 + 0x61), (u8) *(u8 *)((u8 *) D_800FBBD8 + 0x62),
                        *(u8 *)((u8 *) D_800FBBD8 + 0x63));
        }
    }

    if (D_800FBBD8->unkA0 > 0) {
        setupWeather(*(u8 *)((u8 *) D_800FBBD8 + 0xA3), D_800FBBD8->unkA0, *(s16 *)((u8 *) D_800FBBD8 + 0xA6) << 8,
                     D_800FBBD8->unkA8 << 8, D_800FBBD8->unkAA << 8,
                     *(u8 *)((u8 *) D_800FBBD8 + 0xA4) * 0x101, *(u8 *)((u8 *) D_800FBBD8 + 0xA5) * 0x101);
        setWeatherLimits(-1, -0x200);
    }
    if (*(s8 *)((u8 *) D_800FBBD8 + 0x69) == -1) {
        *(TextureHeader **)((u8 *) D_800FBBD8 + 0xB4) = texLoadTexture(*(s32 *)((u8 *) D_800FBBD8 + 0xB4));
        *(s16 *)((u8 *) D_800FBBD8 + 0xB8) = 0;
        D_800FBBD8->unkBA = 0;
    }
    fl = *(s32 *)((u8 *) D_800FBBD8 + 0xBC);
    if (fl != -1) {
        *(s32 **)((u8 *) D_800FBBD8 + 0xBC) = objGetTable(fl);
        resetMixCycle(*(PulsatingLightData **)((u8 *) D_800FBBD8 + 0xBC));
    }
    rcpSetScreenColour(*(u8 *)((u8 *) D_800FBBD8 + 0xAD), *(u8 *)((u8 *) D_800FBBD8 + 0xAE),
                       *(u8 *)((u8 *) D_800FBBD8 + 0xAF));
    viFrameRateReset();
    levelTunePlay(1.0f);
    for (i = 0; i < 4; i++) {
        camSetNo(i);
        camSetFOV((f32) *(s8 *)((u8 *) D_800FBBD8 + 0xAC), 1);
    }
    camSetNo(0);

    fl = *(s32 *)((u8 *) D_800FBBD8 + 0xE4);
    if (fl == -1) {
        *(s32 *)((u8 *) D_800FBBD8 + 0xE4) = 0;
    } else {
        *(s32 **)((u8 *) D_800FBBD8 + 0xE4) = objGetTable(fl);
    }
    mainPreNMI();
    if (*(u8 *)((u8 *) D_800FBBD8 + 0x107) != 0) {
        fxInitNightVision(1);
    }
    if (*(s8 *)((u8 *) D_800FBBD8 + 0xC2) != 0) {
        blurInit();
    }
    if (*(s8 *)((u8 *) D_800FBBD8 + 0xC8) != 0) {
        underWaterLightsInit();
    }
    if (*(u8 *)((u8 *) D_800FBBD8 + 0xF7) != 0) {
        dayInit(D_800FBBD8);
    }
    fl = *(u8 *)((u8 *) D_800FBBD8 + 0x101);
    if (fl != 0) {
        osCartDmaTest4_6105(12.0f, fl * 0x3C);
    }
    mainPreNMI();
    runlinkFreeCode(0x18);
    runlinkFreeCode(0x1E);

    for (i = 0; i < 3; i++) {
        s32 notPresent = 1;

        soundId = D_800A31BC_A3DBC[i];
        for (k = 0; k < 3; k++) {
            if (*(s16 *)((u8 *) D_800FBBD8 + 0x108 + k * 2) == soundId) {
                notPresent = 0;
            }
        }
        if (notPresent != 0) {
            if (D_800A31B0_A3DB0[i] != 0) {
                D_800A31BC_A3DBC[i] = -1;
                amSndStop(D_800A31B0_A3DB0[i], (s16) soundId, notPresent, &D_800A31BC_A3DBC[i]);
            }
        }
    }

    if (mainInitRlo() == 0) {
        *(s16 *)((u8 *) D_800FBBD8 + 0x5A) = 0x384;
        *(s16 *)((u8 *) D_800FBBD8 + 0x5C) = 0x398;
    }

    freeSlot = 0;
    for (j = 0; j < 3; j++) {
        s16 entry = *(s16 *)((u8 *) D_800FBBD8 + 0x108 + j * 2);
        s32 notFound = 1;

        if (entry != -1) {
            for (k = 0; k < 3; k++) {
                s16 v = D_800A31BC_A3DBC[k];
                if (entry == v) {
                    notFound = 0;
                } else if (v == -1) {
                    freeSlot = k;
                }
            }
            if (notFound != 0) {
                amSndPlay((u16) entry, &D_800A31B0_A3DB0[freeSlot], entry,
                          (void *) ((u8 *) D_800FBBD8 + 0x108 + j * 2));
                D_800A31BC_A3DBC[freeSlot] = *(s16 *)((u8 *) D_800FBBD8 + 0x108 + j * 2);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void levelTunePlay(f32 arg0) {
    if (*(u8 *)((u8 *) D_800FBBD8 + 0x72) != 0) {
        if (*(u8 *)((u8 *) D_800FBBD8 + 0x72) != amTuneGetSeqNo()) {
            amTuneResetChls();
            amTunePlay(*(u8 *)((u8 *) D_800FBBD8 + 0x72));
            amTuneResetFade();
            amTuneScaleTempo(arg0);
            amTuneSetChlMask(*(u16 *)((u8 *) D_800FBBD8 + 0x74));
        }
    } else {
        amTuneStop();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelTunePlay.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void levelUpdateColourCycling(s32 arg0) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (*(s16 *)((u8 *) D_800FBBD8 + 0x92 + i * 2) != -1) {
            updateColourCycle(&D_800FB170_B17B0[i], arg0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelUpdateColourCycling.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
unkResetColourCycle *levelGetColourCycling(void) {
    return D_800FB170_B17B0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetColourCycling.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 levelGetNumber(void) {
    return D_800FB114_B1754;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetNumber.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 levelGetType(void) {
    return (u8) D_800FBBD8->unk6C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetType.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 levelGetCamera(void) {
    if (D_800FBBD8 != NULL) {
        return *(u8 *)((u8 *)D_800FBBD8 + 0xE3);
    }
    return 0U;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetCamera.s")
#endif

LevelHeader *levelGetLevel(void) {
    return D_800FBBD8;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *levelGetName(s32 arg0) {
    u32 *buf;

    *(u8 *)D_800A31A0_A3DA0 = 0;
    if (arg0 < D_800FB124_B1764) {
        buf = piRomLoad(0x1EU);
        D_800FB110_B1750 = buf;
        if (buf != NULL) {
            piRomLoadSection(0x1FU, (u32) D_800A31A0_A3DA0, (s32) buf[arg0], 0x20);
            mmFree(D_800FB110_B1750);
        }
    }
    return D_800A31A0_A3DA0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetName.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void levelFreeAll(void) {
    fxFreeNightVision(1);
    fxClearLevelEffects();
    rcpSetScreenColour(0U, 0U, 0U);
    mmFree(D_800FBBD8);
    amAmbientStop();
    freeLights();
    camlightFlush();
    trackFreeAll();
    hitFree();
    amResetAudioMap();
    D_800A089C_A149C = 0;
    amSetMuteMode(0);
    if (D_800FBBD8->unkA0 > 0) {
        freeWeather();
    }
    if (*(s8 *)((u8 *)D_800FBBD8 + 0x69) == -1) {
        texFreeTexture(*(void **)((u8 *)D_800FBBD8 + 0xB4));
    }
    runlinkFlushModules();
    fxCpuTextureFlush();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelFreeAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 levelGetNextOfWorld(s32 arg0, s8 arg1) {
    s32 v = arg0 + 1;

    if (v >= D_800FB124_B1764) {
        v = 0;
    }
    while (v != arg0 && arg1 != (s8) D_800FB12C_B176C[v * 5 + 1]) {
        v++;
        if (v >= D_800FB124_B1764) {
            v = 0;
        }
    }
    return v;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetNextOfWorld.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 levelGetPrevOfWorld(s32 arg0, s8 arg1) {
    s32 v = arg0 - 1;

    if (v < 0) {
        v = D_800FB124_B1764 - 1;
    }
    while (v != arg0 && arg1 != (s8) D_800FB12C_B176C[v * 5 + 1]) {
        v--;
        if (v < 0) {
            v = D_800FB124_B1764 - 1;
        }
    }
    return v;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetPrevOfWorld.s")
#endif

// The reference to gfxBase is false, as it's checking the end of the D_800FBCA0 array
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void levelInitRegionFlags(void) {
    u8 *p = D_800FB1E0_B1820;

    do {
        s32 k;

        for (k = 0; k < 0x11; k++) {
            p[k] = 0;
        }
        p += 0x11;
    } while (p != gfxBase);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelInitRegionFlags.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *levelGetRegionFlags(void) {
    u8 idx = *(u8 *)((u8 *)D_800FBBD8 + 0x103);
    u8 *rec;

    if (idx >= 0x20) {
        D_800A31C4_A3DC4 = NULL;
        return (void *) idx;
    }
    rec = D_800FB1E0_B1820 + idx * 0x11;
    D_800A31C4_A3DC4 = rec;
    *rec = 0;
    return (void *) idx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetRegionFlags.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 levelGetObjectID(s32 arg0) {
    u8 cur;
    s32 sum;

    if (D_800A31C4_A3DC4 == NULL) {
        return -1U;
    }
    cur = *D_800A31C4_A3DC4;
    sum = cur + arg0;
    if (sum >= 0x81) {
        return -1U;
    }
    *D_800A31C4_A3DC4 = (u8) sum;
    return cur;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelGetObjectID.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void levelSetObjectFlag(s32 arg0) {
    u8 *rec = D_800A31C4_A3DC4;

    if (rec != NULL) {
        u8 *flag = rec + (arg0 >> 3) + 1;
        *flag = (u8) (*flag | (1 << (arg0 & 7)));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelSetObjectFlag.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 levelObjectFlagSet(s32 arg0) {
    u8 mode = *(u8 *)((u8 *)D_800FBBD8 + 0x102);
    u8 *rec;

    if ((mode == 0) || (mode == 0xFF)) {
        return 0;
    }
    rec = D_800A31C4_A3DC4;
    if (rec == NULL) {
        return 0;
    }
    return (rec[(arg0 >> 3) + 1] & (1 << (arg0 & 7))) != 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/level/levelObjectFlagSet.s")
#endif
