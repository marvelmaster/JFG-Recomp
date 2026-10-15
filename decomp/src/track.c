#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern void matrix_RPY_XYZ(s16 *, f32 (*)[4]);
extern s32 func_8001C550(u32);
extern u32 texFrame(void *, s32);
extern u8 D_800A0DC8_A19C8[];
extern u8 D_800A0D90_A1990[];
extern u8 D_800A0DF0_A19F0[];
extern u8 D_800A0E18_A1A18[];
extern u8 D_800A0E48_A1A48[];
extern void *level;
extern void *track;
extern TextureHeader *watereffecttexture;
extern s32 watereffectframe;
extern s32 skyframe;
extern u32 skyflags;
extern s32 globflags;
extern s16 fadeA;
extern s32 numanimlockons;
extern u8 beamScrollFlag;
extern u8 gameInWindow;
extern s8 D_800A0CD0_A18D0;
extern Gfx *D_800F2F70_B1750;
extern s32 D_800F2F74_B1754;
extern s32 D_800F2F78_B1758;
extern s32 D_800F2F7C_B175C;
extern s32 D_800F2F84_B1764;
extern s32 D_800F2F8C_B176C;
extern s32 D_800F2F98_B1778;
extern void *D_800F2F80_B1760;
extern s32 D_800F2F90_B1770;
extern void *D_800F2F88_B1768;
extern s16 D_800F2FAC_B178C;
extern s32 D_800F3360_B1B40[3];
extern s32 D_800F3370_B1B50[16];
extern f32 D_800F31CC_B19AC;
extern f32 D_800F31D0_B19B0;
extern f32 D_800F31D4_B19B4;
extern s32 numtexturescrolls;
extern s32 D_800A0D70_A1970;
extern s32 D_800A0D74_A1974;
extern MemoryPoolSlot *D_800A0D78_A1978;
extern s32 D_800A0D7C_A197C;
extern MemoryPoolSlot *D_800A0D80_A1980;
extern s32 D_80101594;
extern u8 D_A0DA8[];
extern u8 D_800F2FE8_B17C8[];
extern void *D_800F3178_B1958[];
extern s32 func_8001A990(f32, f32, f32, f32, f32, f32, f32);
extern s32 mainGetPauseMode(void);
extern f32 Sinf(s32);
extern void diRcpTrace(Gfx *dl, const char *file, s32 line);
extern void camSetNo(s32);
extern void camEnableUserView(s32, s32);
extern void camDisableUserView(s32, s32);
extern void camUserViewTick(void);
extern void camlightDraw();
extern void camlightUpdateAll(void);
extern void camlightVisibilityCheck(void);
extern void doWeather();
extern void rainSetFog(void);
extern void func_8001BBFC(s32, s32);
extern void func_8001BD94(s32);
extern void fxDrawNightVision(Gfx **);
extern void fxSetClipWindow(s32);
extern void fxUpdateLevelEffects(s32);
extern void levelUpdateColourCycling(s32);
extern void objClearFlashes(s32);
extern void shadowChangeBuffer(void);
extern void shadowGenerate(s32, s32);
extern void shadowGetBuffers(s32, s32 *, s32 *, s32 *);
extern void setWeatherLimits(s32, s32);
extern void camResetView();
extern void camSetView();
extern void *camGetPtr(void);
extern s32 camGetWaterLine(s32);
extern s32 camGetNo(void);
extern s32 camProjectPoint();
extern void fxSPDPRipple();
extern s32 trackPolyHeight(f32, f32, f32 *, s32);
extern void camStandardOrtho();
extern void texDPTextureX();
extern void camOffsetZero();
extern void camGetWindowLimits();
extern void *objSetupObject(s16 *, s32, s32);
extern void objPrintObject();
extern void objScrollTexture();
extern void setObjectViewNormal(f32, f32, f32);
extern void func_8001424C(s32, s32);
extern void func_8001C448(void);
extern void func_80015738(void);
extern void func_80012564(s32);
extern void func_8001276C(s32);
extern void func_8001296C(s32);
extern void func_80013214(void);
extern void func_80013478(s32);
extern void func_800135E0(s32, s32);
extern void trackLightFreeMem(void);
void trackLightColour(void *, s32, s32, s32, s32);
void texDisableModes(s32);
void texEnableModes(s32);
void func_8001C570(void *, s32, s32, s32);
void func_800152C0(s32, s32 *, u8 *);
s32 func_800159B8(void *, s32);
extern s32 beamScroll(void);
extern void bloodSpurtUpdateAll(s32);
extern void sparkUpdate(s32);
extern void frontMenuFrameTrackDrawingOn(s32);
extern void animseqLockOnDraw(s32);
extern void animseqPrintCaptions(Gfx **);
extern void animseqDrawNoisyFade(Gfx **);
extern void underWaterLightsUpdate(Gfx **);
extern s32 D_800F33B4_B1B94;
extern s32 PLno;
extern s32 PLlist;
extern s32 PLpolys;
extern s32 PLgrps;
extern s32 trackEdges;
extern void func_800182C0(void);
extern void hitPolyEdgeBuffer(void);
extern s32 hitPolyPlaneTest(s32, void *, void *, void *, f32, s32, f32);
extern s32 hitPolyEdgeTest(void *, void *, void *, f32, s32);
extern s32 func_80016EA0(void *, void *, void *, f32, s32, f32);
extern s32 func_800175A0(void *, void *, void *, f32, s32);
extern s32 trackCylinderIntersect(f32 *, f32 *, f32 *, f32 *, f32, f32 *, f32 *);
extern s32 trackSphereIntersect(f32 *, f32 *, f32 *, f32, f32 *, f32 *);
extern s32 trackClip3D(f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *);
extern s32 hitNearestIntersection(s32, void *, f32 *, void *, s32);
extern s16 trackFade;
extern s16 trackFadeCount;
extern void animseqUpdateTrackFade(u8 *, void *, s32);
extern void flamethrowerDraw(u8 *, void *, s32);
extern void trackLightAsm(void *, void *, u8 *);
extern void **objGetPlayerlist(s32 *);
extern void realReflectCreateList(void *, void *, s32 *, s32 *, s32 *);
extern f32 (*camGetInvProjMtx(void))[4];
extern f32 camDistance(f32, f32, f32);
extern u8 multiPlayerGame;
extern f32 D_800A0CF4_A18F4[];
extern f32 D_800F2FB8_B1798[];
extern f32 D_800F31D8_B19B8;
extern u8 osCartTest4_6105(void *, s32);
extern s32 func_80015CB8(void *);
extern u8 trackVisibleBlocks[];
s32 func_80019324(f32, f32, f32 *, f32 *);
s32 getXZCompareMask(s32, s32, s32, s32, s32);
u8 getYCompareMask(s32, s32, s32);
s32 mathXZInTri(s32, s32, void *, void *, void *);
s32 mantisLightingGetFog(s32);
void mmFree(void *);
void texFreeTexture(void *);
void objDoFrees(void);
void objFreeAll(void);
void objFreeObject(void *);
void shadowFreeBuffers(void);
void animseqFreeLevelData(void);
void controlFreePlayersStuff(void);
extern void *TrackMem;
extern void *exceptionList;
extern void *generalBuffer;
extern s32 numexceptions;
extern s32 D_80000308;
extern u8 racingInGame;
extern s32 D_800A3330_A3F30;
extern s8 D_800A0CD4_A18D4;
extern s8 D_800A0CD8_A18D8;
void func_800150A4(s16, u8, u8, u8 *, s32 *);
void func_80014B6C(s32, s32);
s32 func_80015D54(void *);
s16 objPartInv(s32 *);
void objZsortGroup(s32, s32);
void *objGetObject(s32);
void bloodSpurtsDraw(s32, void *);
void realReflectPrint(Gfx **, s32 *, s32 *);
void dropletDrawAll(Gfx **, s32 *, s32 *);
void wakeDrawRipple(void *, Gfx **);
void sparkDraw(Gfx **, s32 *, s32 *);
void mineDraw(Gfx **, s32 *);
void fxDrawLevelEffects(Gfx **, s32 *, s32 *, s32 *);
void animshipDrawThrusters(Gfx **, s32 *, void *);
void mizarDrawEffects(Gfx **, s32 *, void *);
void mantismissileDrawThruster(Gfx **, s32 *, s32 *, void *);
void hoovertankDrawEffects(Gfx **, s32 *, void *);
void regionidDraw(Gfx **, s32 *, void *);
void ammoPickupGetFade(Gfx **, s32 *, s32 *, void *);
void objDrawPlayerEffects(Gfx **, s32 *, void *);
void partDraw(Gfx **, s32 *);
void func_8001B6D8(void *, void *);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackUpdateFX(s32 arg0) {
    if (runlinkIsModuleLoaded(1) != 0) {
        bloodSpurtUpdateAll(arg0);
    }
    if (runlinkIsModuleLoaded(8) != 0) {
        sparkUpdate(arg0);
    }
    if (runlinkIsModuleLoaded(0xA) != 0) {
        frontMenuFrameTrackDrawingOn(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackUpdateFX.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackDraw(Gfx **arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 arg4) {
    s32 numCams;
    s32 timeDelta;
    s32 camIdx;
    s32 waterFrame;
    s32 waterPeriod;
    u8 *lvl;
    TextureHeader *skyTex;

    numCams = mainGetNumberOfCameras();
    if (beamScroll() != 0) {
        D_800F2F70_B1750 = *arg0;
        D_800F2F74_B1754 = *arg1;
        D_800F2F78_B1758 = *arg2;
        D_800F2F7C_B175C = *arg3;
        diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x1F8);
        camSetNo(0);
        D_800F2F98_B1778 = 1;
        D_800F2F8C_B176C = 0;
        timeDelta = (mainGetPauseMode() != 0) ? 0 : arg4;
        if (watereffecttexture != NULL) {
            waterPeriod = watereffecttexture->numOfTextures;
            waterFrame = watereffectframe + (watereffecttexture->frameAdvanceDelay * timeDelta);
            while (waterFrame >= waterPeriod) {
                waterFrame -= waterPeriod;
            }
            watereffectframe = waterFrame;
        }
        shadowGenerate(1, arg4);
        levelUpdateColourCycling(timeDelta);
        lvl = (u8 *)level;
        if (*(PulsatingLightData **)(lvl + 0xBC) != (PulsatingLightData *)-1) {
            updateMixCycle(*(PulsatingLightData **)(lvl + 0xBC), timeDelta);
        }
        D_800A0CD0_A18D0 = (*(s8 *)(lvl + 0x6C) == 2) ? 0 : 1;
        if (*(s8 *)(lvl + 0x6C) == 1 || *(s8 *)(lvl + 0x6C) == 2 || *(s8 *)(lvl + 0xCD) != 0) {
            globflags = 1;
        }
        if (*(s8 *)(lvl + 0x69) == -1) {
            skyTex = *(TextureHeader **)(lvl + 0xB4);
            *(s16 *)(lvl + 0xB8) = (s16)((*(s16 *)(lvl + 0xB8) + (*(s8 *)(lvl + 0xB2) * timeDelta)) & ((skyTex->width << 9) - 1));
            *(s16 *)(lvl + 0xBA) = (s16)((*(s16 *)(lvl + 0xBA) + (*(s8 *)(lvl + 0xB3) * timeDelta)) & ((skyTex->height << 9) - 1));
            texAnimateTexture(skyTex, &skyflags, &skyframe, timeDelta);
        }
        texDPInit(&D_800F2F70_B1750);
        /* 0xBC000002 / 0xB6000000 / 0xF9000000 / 0xFA000000 / 0xFB000000 setup commands */
        D_800F2F70_B1750->words.w0 = 0xBC000002;
        D_800F2F70_B1750->words.w1 = 0;
        D_800F2F70_B1750++;
        D_800F2F70_B1750->words.w1 = 0x1000;
        D_800F2F70_B1750->words.w0 = 0xB6000000;
        D_800F2F70_B1750++;
        D_800F2F70_B1750->words.w1 = 0x64;
        D_800F2F70_B1750->words.w0 = 0xF9000000;
        D_800F2F70_B1750++;
        D_800F2F70_B1750->words.w0 = 0xFA000000;
        D_800F2F70_B1750->words.w1 = -1U;
        D_800F2F70_B1750++;
        D_800F2F70_B1750->words.w0 = 0xFB000000;
        D_800F2F70_B1750->words.w1 = -0x100U;
        D_800F2F70_B1750++;
        rainSetFog();
        func_8001BBFC(numCams, timeDelta);
        if (*(s16 *)((u8 *)track + 0x1E) > 0) {
            func_8001276C(timeDelta);
        }
        if (beamScrollFlag != 0) {
            animseqLockOnDraw(timeDelta);
        }
        fxUpdateLevelEffects(timeDelta);
        if (gameInWindow != 0 && numCams == 1) {
            camEnableUserView(0, 1);
            camUserViewTick();
        }
        D_800F2F84_B1764 = 0;
        for (camIdx = 0; camIdx < numCams; camIdx++) {
            D_800F2F84_B1764 = camIdx;
            func_8001BD94(camIdx);
            D_800F2F70_B1750->words.w1 = 0;
            D_800F2F70_B1750->words.w0 = 0xE7000000;
            D_800F2F70_B1750++;
            camSetNo(D_800F2F84_B1764);
            camSetView(&D_800F2F70_B1750, &D_800F2F74_B1754);
            func_80015738();
            objClearFlashes(1);
            fxSetClipWindow(D_800F2F84_B1764);
            if (numCams < 2) {
                if (*(s8 *)(lvl + 0x69) == -1) {
                    func_8001296C(arg4);
                } else {
                    func_80013478(arg4);
                }
            } else {
                func_80013214();
            }
            diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x27D);
            D_800F2F70_B1750->words.w1 = 0;
            D_800F2F70_B1750->words.w0 = 0xE7000000;
            D_800F2F70_B1750++;
            func_800135E0(numCams, arg4);
            setWeatherLimits(-1, -0x200);
            if (*(s16 *)(lvl + 0xA0) > 0 && numCams < 2) {
                doWeather(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, &D_800F2F7C_B175C, timeDelta);
            }
            if (numCams < 2) {
                camlightUpdateAll();
                camlightVisibilityCheck();
                camlightDraw(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758);
                func_80012564(timeDelta);
                fxDrawNightVision(&D_800F2F70_B1750);
            }
        }
        if (numanimlockons > 0) {
            animseqPrintCaptions(&D_800F2F70_B1750);
        }
        animseqDrawNoisyFade(&D_800F2F70_B1750);
        if (fadeA != 0) {
            underWaterLightsUpdate(&D_800F2F70_B1750);
        }
        camDisableUserView(0, 1);
        camResetView(&D_800F2F70_B1750);
        D_800F2F70_B1750->words.w1 = 0;
        D_800F2F70_B1750->words.w0 = 0xE7000000;
        D_800F2F70_B1750++;
        D_800F2F70_B1750->words.w0 = 0xBC000002;
        D_800F2F70_B1750->words.w1 = 0;
        D_800F2F70_B1750++;
        shadowChangeBuffer();
        *arg0 = D_800F2F70_B1750;
        *arg1 = D_800F2F74_B1754;
        *arg2 = D_800F2F78_B1758;
        *arg3 = D_800F2F7C_B175C;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80012564(s32 arg0) {
    u8 *cam;
    f32 probeX;
    f32 probeZ;
    f32 hitY;
    f32 camY;
    f32 dy;
    f32 offX;
    f32 offZ;
    f32 sinA;
    f32 cosA;
    f32 projY;
    s32 projDummy;
    s32 vpWidth;
    s32 vpHeight;
    s32 rippleX;

    cam = (u8 *)camGetPtr();
    if (camGetWaterLine(camGetNo()) == 0) {
        return;
    }
    probeX = *(f32 *)(cam + 0xC) - (Sinf((s16)(*(s16 *)cam + 0x8000)) * 10.0f);
    probeZ = *(f32 *)(cam + 0x14) - (Cosf((s16)(*(s16 *)cam + 0x8000)) * 10.0f);
    if ((trackPolyHeight(probeX, probeZ, &hitY, 0x2000) & 0x2000) == 0) {
        return;
    }
    camY = *(f32 *)(cam + 0x10);
    if ((camY - 16.0f) >= hitY) {
        return;
    }
    viGetCurrentSize(&vpWidth, &vpHeight);
    sinA = Sinf(*(s16 *)(cam + 0x2));
    cosA = Cosf(*(s16 *)(cam + 0x2));
    dy = hitY - camY;
    if (dy >= 10.0f) {
        /* 0x41200000 is the float 10.0f passed as a raw word */
        fxSPDPRipple((void *)0x41200000, &D_800F2F70_B1750, 0, 0, vpWidth, vpHeight, arg0);
        D_80101594 = 0;
        return;
    }
    offX = (dy * sinA) - (10.0f * cosA);
    offZ = (dy * cosA) + (10.0f * sinA);
    if (offX > 0.0f) {
        offX = -offX;
    }
    if (camProjectPoint(0, offZ, offX, &projDummy, &projY, 0) != 0) {
        rippleX = (s32)projY;
        if (rippleX < vpHeight) {
            if (rippleX < 0) {
                rippleX = 0;
            }
            fxSPDPRipple(&D_800F2F70_B1750, NULL, rippleX, vpWidth, vpHeight, arg0);
            D_80101594 = rippleX;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80012564.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8001276C(s32 arg0) {
    u8 *trk;
    u8 *block;
    u8 *polyBase;
    u8 *poly;
    u8 *texTable;
    TextureHeader *tex;
    s32 numBlocks;
    s32 numPolys;
    s32 blockIdx;
    s32 polyIdx;
    s32 texIdx;
    s32 frame;

    trk = (u8 *)track;
    texTable = *(u8 **)trk;
    numBlocks = *(s16 *)(trk + 0x1A);
    block = *(u8 **)(trk + 0x04);
    for (blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
        polyBase = *(u8 **)(block + 0x0C);
        numPolys = *(s16 *)(block + 0x28);
        for (polyIdx = 0; polyIdx < numPolys; polyIdx++) {
            poly = polyBase + (polyIdx * 0x10);
            if (*(u32 *)(poly + 0xC) & 0x10000) {
                texIdx = poly[0];
                if (texIdx != 0xFF) {
                    tex = *(TextureHeader **)(texTable + (texIdx * 8));
                    if (tex->numOfTextures != 0x100 && tex->frameAdvanceDelay != 0) {
                        frame = *(u16 *)(poly + 0xA);
                        texAnimateTexture(tex, (u32 *)(poly + 0xC), &frame, arg0);
                        *(u16 *)(poly + 0xA) = (u16)frame;
                    }
                }
            }
        }
        block += 0x48;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001276C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void initSky(s32 arg0) {
    s16 setup[5];

    if (arg0 == -1) {
        D_800F2F88_B1768 = NULL;
        D_800F2FAC_B178C = arg0;
    } else {
        setup[2] = 0;
        setup[3] = 0;
        setup[4] = 0;
        ((s8 *)setup)[2] = 10;
        setup[0] = arg0;
        D_800F2F88_B1768 = objSetupObject(setup, 2, arg0);
        D_800F2FAC_B178C = arg0;
        if (D_800F2F88_B1768 != NULL) {
            *(s32 *)((u8 *)D_800F2F88_B1768 + 0x3C) = 0;
            *(s16 *)((u8 *)D_800F2F88_B1768 + 0x4A) = -1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/initSky.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackSkySet(s32 arg0) {
    D_800F2F98_B1778 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackSkySet.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Camera-relative sky grid. Layouts from jfg-re (jfg_forge/core/model_parser.py):
// vertex = 10 B (s16 x, y, z, then RGBA); triangle = 16 B (flag, 3 local
// indices, 3 corner (s,t) shorts). Emits a 5-command DL (FA, FB, G_VTX, G_TRI, E7).
// Grid: 9 points (3x3 pattern) with offsets built from P = cos*1280, Q = sin*1280
// and cell spacing A = cellU*cos, B = cellV*sin. No DKR twin: DKR's sky is a skydome object.
void func_8001296C(s32 arg0) {
    u8 *cam;
    u8 *lvl;
    u8 *skyHdr;
    u8 *vtxOut;
    u8 *triOut;
    u8 *tt;
    u32 vtxBase;
    u32 triBase;
    s32 maskU;
    s32 maskV;
    s32 uBase;
    s32 vBase;
    s32 k;
    s32 it;
    s16 vy;
    f32 sinYaw;
    f32 cosYaw;
    f32 P;
    f32 Q;
    f32 A;
    f32 B;
    f32 cellU;
    f32 cellV;
    f32 scale;
    f32 vx[9];
    f32 vz[9];
    s16 gridU[9];
    s16 gridV[9];

    cam = (u8 *)camGetPtr();
    lvl = (u8 *)level;
    skyHdr = *(u8 **)(lvl + 0xB4);
    D_800F2FAC_B178C = -1;
    vtxBase = (u32)D_800F2F78_B1758;
    triBase = (u32)D_800F2F7C_B175C;
    vtxOut = (u8 *)vtxBase;
    triOut = (u8 *)triBase;
    maskU = (skyHdr[0] << 5) - 1;
    maskV = (skyHdr[1] << 5) - 1;

    sinYaw = Sinf(-*(s16 *)cam);
    cosYaw = Cosf(-*(s16 *)cam);
    P = cosYaw * 1280.0f;
    Q = sinYaw * 1280.0f;
    cellU = (f32)((skyHdr[0] << 4) * lvl[0xB0]);
    cellV = (f32)((skyHdr[1] << 4) * lvl[0xB1]);
    A = cellU * cosYaw;
    B = cellV * sinYaw;
    scale = 1280.0f * 0.25f;
    uBase = ((s32)(*(f32 *)(cam + 0xC) * (scale / cellU)) + (*(s16 *)(lvl + 0xB8) >> 4)) & maskU;
    vBase = ((s32)(*(f32 *)(cam + 0x14) * (scale / cellV)) + (*(s16 *)(lvl + 0xBA) >> 4)) & maskV;

    vx[0] = -P - Q;
    vx[1] = P - Q;
    vx[2] = P + Q;
    vx[3] = -P + Q;
    vx[4] = 0.0f;
    vx[5] = -P - 2.0f * Q;
    vx[6] = P - 2.0f * Q;
    vx[7] = P + 2.0f * Q;
    vx[8] = -P + 2.0f * Q;

    vz[0] = -P + Q;
    vz[1] = -P - Q;
    vz[2] = P - Q;
    vz[3] = P + Q;
    vz[4] = 0.0f;
    vz[5] = Q - 2.0f * P;
    vz[6] = -2.0f * P - Q;
    vz[7] = 2.0f * P - Q;
    vz[8] = 2.0f * P + Q;

    gridU[0] = (s16)((s32)(-A - B) + uBase);
    gridU[1] = (s16)((s32)(A - B) + uBase);
    gridU[2] = (s16)((s32)(A + B) + uBase);
    gridU[3] = (s16)((s32)(B - A) + uBase);
    gridU[4] = (s16)uBase;
    gridU[5] = (s16)((s32)(-A - 2.0f * B) + uBase);
    gridU[6] = (s16)((s32)(A - 2.0f * B) + uBase);
    gridU[7] = (s16)((s32)(A + 2.0f * B) + uBase);
    gridU[8] = (s16)((s32)(2.0f * B - A) + uBase);

    gridV[0] = (s16)((s32)(B - A) + vBase);
    gridV[1] = (s16)((s32)(-A - B) + vBase);
    gridV[2] = (s16)((s32)(A - B) + vBase);
    gridV[3] = (s16)((s32)(A + B) + vBase);
    gridV[4] = (s16)vBase;
    gridV[5] = (s16)((s32)(B - 2.0f * A) + vBase);
    gridV[6] = (s16)((s32)(-2.0f * A - B) + vBase);
    gridV[7] = (s16)((s32)(2.0f * A - B) + vBase);
    gridV[8] = (s16)((s32)(2.0f * A + B) + vBase);

    camOffsetZero(&D_800F2F70_B1750, &D_800F2F74_B1754, vBase);
    texDPTextureX(&D_800F2F70_B1750, skyHdr, 0x10, skyframe << 8);

    D_800F2F70_B1750->words.w0 = 0xFA000000;
    D_800F2F70_B1750->words.w1 = -1U;
    D_800F2F70_B1750++;
    D_800F2F70_B1750->words.w0 = 0xFB000000;
    D_800F2F70_B1750->words.w1 = -1U;
    D_800F2F70_B1750++;
    /* G_VTX: 9 vertices from the vertex buffer start (segment address + 0x80000000) */
    D_800F2F70_B1750->words.w0 = ((((vtxBase + 0x80000000U) & 6) | 0x48) & 0xFF) << 16 | 0x04000062;
    D_800F2F70_B1750->words.w1 = vtxBase + 0x80000000U;
    D_800F2F70_B1750++;
    /* G_TRI block at the triangle buffer start */
    D_800F2F70_B1750->words.w0 = 0x05710080;
    D_800F2F70_B1750->words.w1 = triBase + 0x80000000U;
    D_800F2F70_B1750++;
    D_800F2F70_B1750->words.w0 = 0xE7000000;
    D_800F2F70_B1750->words.w1 = 0;
    D_800F2F70_B1750++;

    vy = (s16)(s32)(*(f32 *)(cam + 0x10) + 192.0f);
    for (k = 0; k < 9; k++) {
        *(s16 *)(vtxOut + 0) = (s16)(s32)(vx[k] + *(f32 *)(cam + 0xC));
        *(s16 *)(vtxOut + 2) = vy;
        *(s16 *)(vtxOut + 4) = (s16)(s32)(vz[k] + *(f32 *)(cam + 0x14));
        vtxOut[6] = 0xFF;
        vtxOut[7] = 0xFF;
        vtxOut[8] = 0xFF;
        vtxOut[9] = (k < 5) ? 0xFF : 0;
        vtxOut += 10;
    }

    /* 4 iterations x 2 triangles; index table D_800A0D90 holds 6 bytes per iteration */
    for (it = 0; it < 4; it++) {
        tt = D_800A0D90_A1990 + it * 6;
        triOut[0] = 0x40;
        triOut[1] = tt[0];
        triOut[2] = tt[1];
        triOut[3] = tt[2];
        *(s16 *)(triOut + 0x4) = gridU[tt[0]];
        *(s16 *)(triOut + 0x6) = gridV[tt[0]];
        *(s16 *)(triOut + 0x8) = gridU[tt[1]];
        *(s16 *)(triOut + 0xA) = gridV[tt[1]];
        *(s16 *)(triOut + 0xC) = gridU[tt[2]];
        *(s16 *)(triOut + 0xE) = gridV[tt[2]];
        triOut[0x10] = 0x40;
        triOut[0x11] = tt[3];
        triOut[0x12] = tt[4];
        triOut[0x13] = tt[5];
        *(s16 *)(triOut + 0x14) = gridU[tt[3]];
        *(s16 *)(triOut + 0x16) = gridV[tt[3]];
        *(s16 *)(triOut + 0x18) = gridU[tt[4]];
        *(s16 *)(triOut + 0x1A) = gridV[tt[4]];
        *(s16 *)(triOut + 0x1C) = gridU[tt[5]];
        *(s16 *)(triOut + 0x1E) = gridV[tt[5]];
        triOut += 0x20;
    }

    D_800F2F78_B1758 = (s32)vtxOut;
    D_800F2F7C_B175C = (s32)triOut;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001296C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80013214(void) {
    u8 *vtx;
    u8 *vtx2;
    u8 *lvl;
    u32 vtxAddr;
    s32 vpWidth;
    s32 vpHeight;
    s32 halfW;
    s32 halfH;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 mode;

    vtx = (u8 *)D_800F2F78_B1758;
    D_800F2FAC_B178C = -1;
    camStandardOrtho(&D_800F2F70_B1750, &D_800F2F74_B1754);
    texDPInit(&D_800F2F70_B1750);
    texDPTextureX(&D_800F2F70_B1750, 0, 8, 0);
    vtxAddr = (u32)vtx + 0x80000000;
    D_800F2F70_B1750->words.w0 = (((((s32)vtxAddr & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30;
    D_800F2F70_B1750->words.w1 = vtxAddr;
    D_800F2F70_B1750++;
    D_800F2F70_B1750->words.w0 = 0x05100020;
    D_800F2F70_B1750->words.w1 = (u32)D_A0DA8;
    D_800F2F70_B1750++;
    camSetView(&D_800F2F70_B1750, &D_800F2F74_B1754, vtxAddr);
    lvl = (u8 *)level;
    viGetCurrentSize(&vpWidth, &vpHeight);
    mode = camGetMode();
    camGetWindowLimits(mode, camGetNo(), &left, &top, &right, &bottom);
    halfW = (u32)vpWidth >> 1;
    halfH = (u32)vpHeight >> 1;
    *(s16 *)(vtx + 0x00) = (s16)(left - halfW);
    *(s16 *)(vtx + 0x02) = (s16)(halfH - bottom);
    *(s16 *)(vtx + 0x04) = 0x10;
    vtx[0x06] = lvl[0xD1];
    vtx[0x07] = lvl[0xD2];
    vtx[0x08] = lvl[0xD3];
    vtx[0x09] = 0xFF;
    vtx2 = vtx + 0x28;
    *(s16 *)(vtx2 - 0x1E) = (s16)(right - halfW);
    *(s16 *)(vtx2 - 0x1C) = (s16)(halfH - bottom);
    *(s16 *)(vtx2 - 0x1A) = 0x10;
    vtx2[-0x18] = lvl[0xD1];
    vtx2[-0x17] = lvl[0xD2];
    vtx2[-0x16] = lvl[0xD3];
    vtx2[-0x15] = 0xFF;
    *(s16 *)(vtx2 - 0x14) = (s16)(left - halfW);
    *(s16 *)(vtx2 - 0x12) = (s16)(halfH - top);
    *(s16 *)(vtx2 - 0x10) = 0x10;
    vtx2[-0x0E] = lvl[0xCE];
    vtx2[-0x0D] = lvl[0xCF];
    vtx2[-0x0C] = lvl[0xD0];
    vtx2[-0x0B] = 0xFF;
    *(s16 *)(vtx2 - 0x0A) = (s16)(right - halfW);
    *(s16 *)(vtx2 - 0x08) = (s16)(halfH - top);
    *(s16 *)(vtx2 - 0x06) = 0x10;
    vtx2[-0x04] = lvl[0xCE];
    vtx2[-0x03] = lvl[0xCF];
    vtx2[-0x02] = lvl[0xD0];
    vtx2[-0x01] = 0xFF;
    D_800F2F78_B1758 = (s32)vtx2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80013214.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80013478(s32 arg0) {
    u8 *cam;
    u8 *sky;

    if (D_800F2F88_B1768 != NULL) {
        sky = (u8 *)D_800F2F88_B1768;
        cam = (u8 *)camGetPtr();
        if (*(s8 *)((u8 *)level + 0x69) == 0) {
            *(f32 *)(sky + 0x0C) = *(f32 *)(cam + 0x0C) + *(f32 *)(cam + 0x30);
            *(f32 *)(sky + 0x10) = *(f32 *)(cam + 0x10) + *(f32 *)(cam + 0x34);
            *(f32 *)(sky + 0x14) = *(f32 *)(cam + 0x14) + *(f32 *)(cam + 0x38);
            *(s16 *)sky = (s16)(*(s16 *)sky + (*(u8 *)((u8 *)level + 0xE1) * arg0));
            if (*(u8 *)(*(u8 **)(sky + 0x40) + 0xA2) != 0xFF) {
                objScrollTexture(sky, arg0, &level);
            }
        } else {
            *(f32 *)(sky + 0x0C) = *(f32 *)(cam + 0x30);
            *(f32 *)(sky + 0x10) = *(f32 *)(cam + 0x34);
            *(f32 *)(sky + 0x14) = *(f32 *)(cam + 0x38);
        }
        camOffsetZero(&D_800F2F70_B1750, &D_800F2F74_B1754);
        if (D_800F2F98_B1778 != 0) {
            objPrintObject(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, sky);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80013478.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackGetSky(void) {
    return (s32)D_800F2F88_B1768;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetSky.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800135E0(s32 arg0, s32 arg1) {
    u8 *cam;
    u8 *trk;
    s16 camObj;

    D_800F2F80_B1760 = camGetPtr();
    cam = (u8 *)D_800F2F80_B1760;
    trk = (u8 *)track;
    func_8001C448();
    setObjectViewNormal((f32)D_800F3360_B1B40[0] / 65536.0f,
                        (f32)D_800F3360_B1B40[1] / 65536.0f,
                        (f32)D_800F3360_B1B40[2] / 65536.0f);
    camObj = *(s16 *)(cam + 0x3E);
    if (camObj >= 0 && camObj < *(s16 *)(trk + 0x1A)) {
        D_800F2F90_B1770 = *(s16 *)(*(u8 **)(trk + 0x04) + (camObj * 0x48) + 0x30);
    } else {
        D_800F2F90_B1770 = -1;
    }
    D_800F31CC_B19AC = *(f32 *)(cam + 0x0C);
    D_800F31D0_B19B0 = *(f32 *)(cam + 0x10);
    D_800F31D4_B19B4 = *(f32 *)(cam + 0x14);
    func_8001424C(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_800135E0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackAddTextureScroll(s32 arg0, s32 arg1, s32 arg2) {
    if (numtexturescrolls < 0x10) {
        D_800F3370_B1B50[numtexturescrolls] = (arg0 << 0x18) | ((arg1 & 0xFFF) << 0xC) | (arg2 & 0xFFF);
        numtexturescrolls += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackAddTextureScroll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackUpdateTextureScroll(void) {
    u8 *trk;
    u8 *texTable;
    u8 *block;
    u8 *polyBase;
    u8 *poly;
    u8 *vtx;
    u8 *blockVtx;
    TextureHeader *tex;
    s32 i;
    s32 entry;
    s32 texIdx;
    s32 dx;
    s32 dy;
    s32 maskS;
    s32 maskT;
    s32 numBlocks;
    s32 numPolys;
    s32 numVerts;
    s32 blockIdx;
    s32 polyIdx;
    s32 vtxIdx;
    s16 oldS;
    s16 oldT;
    s16 newS;
    s16 newT;

    if (track != NULL) {
        trk = (u8 *)track;
        texTable = *(u8 **)trk;
        numBlocks = *(s16 *)(trk + 0x1A);
        for (i = 0; i < numtexturescrolls; i++) {
            entry = D_800F3370_B1B50[i];
            texIdx = (entry >> 0x18) & 0xFF;
            dx = (s32)((u32)entry << 8) >> 0x14;
            dy = (s32)((u32)entry << 0x14) >> 0x14;
            tex = *(TextureHeader **)(texTable + (texIdx * 8));
            if (tex->width <= 0x40 && tex->height <= 0x40) {
                maskS = (tex->width << 8) - 1;
                maskT = (tex->height << 8) - 1;
            } else {
                maskS = (tex->width << 6) - 1;
                maskT = (tex->height << 6) - 1;
            }
            block = *(u8 **)(trk + 0x04);
            for (blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
                numPolys = *(s16 *)(block + 0x28);
                polyBase = *(u8 **)(block + 0x0C);
                for (polyIdx = 0; polyIdx < numPolys; polyIdx++) {
                    poly = polyBase + (polyIdx * 0x10);
                    if (poly[0] == texIdx) {
                        numVerts = *(s16 *)(poly + 0x18) - *(s16 *)(poly + 0x8);
                        blockVtx = *(u8 **)(block + 0x04) + (*(s16 *)(poly + 0x8) * 0x10);
                        for (vtxIdx = 0; vtxIdx < numVerts; vtxIdx++) {
                            vtx = blockVtx + (vtxIdx * 0x10);
                            oldS = *(s16 *)(vtx + 0x4);
                            oldT = *(s16 *)(vtx + 0x6);
                            newS = (s16)((oldS + dx) & maskS);
                            newT = (s16)((oldT + dy) & maskT);
                            *(s16 *)(vtx + 0x4) = newS;
                            *(s16 *)(vtx + 0x6) = newT;
                            *(s16 *)(vtx + 0x8) = (s16)(newS + (*(s16 *)(vtx + 0x8) - oldS));
                            *(s16 *)(vtx + 0xA) = (s16)(newT + (*(s16 *)(vtx + 0xA) - oldT));
                            *(s16 *)(vtx + 0xC) = (s16)(newS + (*(s16 *)(vtx + 0xC) - oldS));
                            *(s16 *)(vtx + 0xE) = (s16)(newT + (*(s16 *)(vtx + 0xE) - oldT));
                        }
                    }
                }
                block += 0x48;
            }
        }
    }
    numtexturescrolls = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackUpdateTextureScroll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
MemoryPoolSlot *trackLightAllocate(s32 arg0, s32 arg1) {
    MemoryPoolSlot *ret;
    MemoryPoolSlot *blockList;
    MemoryPoolSlot *slot;
    u8 *src;
    u8 *dst;
    u8 *trk;
    u8 *block;
    s32 i;
    s32 numBlocks;
    s32 lightBytes;
    s32 failed;
    s32 copyLeft;
    u8 *lightData;

    D_800A0D74_A1974 = 0;
    D_800A0D70_A1970 = arg0;
    failed = 1;
    ret = mmAlloc(arg0 << 7, 0xFF0000FFU);
    D_800A0D78_A1978 = ret;
    if (ret != NULL) {
        for (i = D_800A0D70_A1970 - 1; i > 0; i--) {
            *(f32 *)((u8 *)D_800A0D78_A1978 + (i * 0x80) + 0xC) = 0.0f;
        }
        failed = arg1;
        if (arg1 != 0) {
            trk = (u8 *)track;
            numBlocks = *(s16 *)(trk + 0x1A);
            ret = mmAlloc(numBlocks * 8, 0xFF0000FFU);
            blockList = ret;
            if (blockList != NULL) {
                block = *(u8 **)(trk + 0x04);
                D_800A0D7C_A197C = 1;
                D_800A0D80_A1980 = blockList;
                failed = 0;
                for (i = 0; i < numBlocks; i++) {
                    slot = &blockList[i];
                    lightData = *(u8 **)block;
                    lightBytes = *(s16 *)(block + 0x24) * 0xA;
                    slot->data = lightData;
                    ret = mmAlloc(lightBytes, 0xFF0000FFU);
                    slot->size = (s32)ret;
                    if (ret != NULL) {
                        src = lightData;
                        dst = (u8 *)ret;
                        for (copyLeft = lightBytes; copyLeft > 0; copyLeft--) {
                            *dst++ = *src++;
                        }
                    } else {
                        failed = 1;
                    }
                    block += 0x48;
                }
            }
        }
    }
    if (failed != 0) {
        trackLightFreeMem();
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackLightAllocate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackLightFreeMem(void) {
    MemoryPoolSlot *blockList;
    s32 i;
    s32 numBlocks;

    blockList = D_800A0D80_A1980;
    if (blockList != NULL) {
        numBlocks = *(s16 *)((u8 *)track + 0x1A);
        while (numBlocks-- != 0) { // indices numBlocks-1 .. 0
            if (blockList[numBlocks].size != 0) {
                mmFree((void *)blockList[numBlocks].size);
            }
        }
        mmFree(blockList);
        D_800A0D80_A1980 = NULL;
    }
    if (D_800A0D78_A1978 != NULL) {
        mmFree(D_800A0D78_A1978);
        D_800A0D78_A1978 = NULL;
    }
    D_800A0D74_A1974 = 0;
    D_800A0D70_A1970 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackLightFreeMem.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *trackLightAdd(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u8 *light;
    s32 i;

    if (arg3 <= 0.0f) {
        return NULL;
    }
    light = (u8 *)D_800A0D78_A1978;
    for (i = 0; i < D_800A0D70_A1970; i++, light += 0x80) {
        if (*(f32 *)(light + 0x0C) == 0.0f) {
            *(f32 *)(light + 0x00) = arg0;
            *(f32 *)(light + 0x04) = arg1;
            *(f32 *)(light + 0x08) = arg2;
            *(f32 *)(light + 0x0C) = arg3;
            *(f32 *)(light + 0x10) = arg4;
            *(f32 *)(light + 0x14) = arg3 * arg3;
            *(f32 *)(light + 0x18) = arg4 * arg4;
            *(f32 *)(light + 0x1C) = 31.99f / (arg3 - arg4);
            trackLightColour(light, arg5, arg6, arg7, 0xFF);
            D_800A0D74_A1974 += 1;
            return light;
        }
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackLightAdd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackLightDelete(void *light) {
    if (light != NULL && *(f32 *)((u8 *)light + 0x0C) != 0.0f) {
        *(f32 *)((u8 *)light + 0x0C) = 0.0f;
        D_800A0D74_A1974 -= 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackLightDelete.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackLightColour(void *light, s32 r, s32 g, s32 b, s32 intensity) {
    s32 i;
    u8 *out;
    s32 stepR;
    s32 stepG;
    s32 stepB;

    if (light != NULL) {
        i = 0x1F;
        if (intensity < 0xFF) {
            r = (r * intensity) >> 8;
            g = (g * intensity) >> 8;
            b = (b * intensity) >> 8;
        }
        stepR = r;
        stepG = g;
        stepB = b;
        out = (u8 *)light + 0x20;
        do {
            out[0] = (s8)(r >> 5);
            out[1] = (s8)(g >> 5);
            out[2] = (s8)(b >> 5);
            r += stepR;
            g += stepG;
            b += stepB;
            out += 3;
        } while (i--);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackLightColour.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackLightMove(void *light, f32 x, f32 y, f32 z) {
    if (light != NULL) {
        *(f32 *)((u8 *)light + 0x00) = x;
        *(f32 *)((u8 *)light + 0x04) = y;
        *(f32 *)((u8 *)light + 0x08) = z;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackLightMove.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80013DCC(void) {
    u8 *entry;
    u8 *srcInfo;
    u8 *dst;
    u8 *src;
    u16 *masks;
    s32 blockCount;
    s32 mode;
    s32 n;
    s32 i;
    s32 v;
    s32 g;
    s32 k;
    u16 mask;

    entry = *(u8 **)((u8 *)track + 0x04);
    blockCount = *(s16 *)((u8 *)track + 0x1A);
    mode = (D_800A0D80_A1980 != NULL) ? 1 : -1;
    for (i = 1; i < blockCount; i++, entry += 0x48) {
        if (trackVisibleBlocks[i] == 0 || (*(s8 *)(entry + 0x32) & mode) == 0) {
            continue;
        }
        srcInfo = *(u8 **)(entry + 0x34);
        if (srcInfo == NULL) {
            continue;
        }
        n = *(s16 *)(entry + 0x24);
        dst = *(u8 **)(entry + 0x00);
        src = *(u8 **)(srcInfo + 0x00);
        if (mode > 0) {
            for (v = 0; v < n; v++) {
                dst[v * 0xA + 6] = src[v * 3 + 0];
                dst[v * 0xA + 7] = src[v * 3 + 1];
                dst[v * 0xA + 8] = src[v * 3 + 2];
            }
            entry[0x32] = (s8)(*(s8 *)(entry + 0x32) ^ 1);
        } else {
            masks = *(u16 **)(srcInfo + 0x04);
            for (g = 0; g < ((n + 15) >> 4); g++) {
                mask = masks[g];
                masks[g] = 0;
                for (k = 0; mask != 0; k++, mask >>= 1) {
                    if (mask & 1) {
                        v = g * 16 + k;
                        dst[v * 0xA + 6] = src[v * 3 + 0];
                        dst[v * 0xA + 7] = src[v * 3 + 1];
                        dst[v * 0xA + 8] = src[v * 3 + 2];
                    }
                }
            }
            entry[0x32] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80013DCC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackUpdateLighting(s32 arg0, s32 arg1) {
    u8 *tbl;
    u8 *elems;
    u8 *elem;
    u8 *lights;
    s32 count;
    s32 flag;
    s32 i;
    s8 v;

    if (track == NULL || numberOfCameras >= 2) {
        return;
    }
    /* (arg0 == 0) != (table == NULL) is the asm's combined outer/inner test */
    if ((arg0 == 0) != (D_800A0D80_A1980 == NULL)) {
        tbl = (u8 *)D_800A0D80_A1980;
        if (tbl != NULL) {
            D_800A0D7C_A197C ^= 1;
            flag = D_800A0D7C_A197C;
            elems = *(u8 **)((u8 *)track + 0x04);
            count = *(s16 *)((u8 *)track + 0x1A);
            for (i = 0; i < count; i++) {
                elem = elems + i * 0x48;
                v = *(s8 *)(elem + 0x32);
                *(s8 *)(elem + 0x32) = (s8)(((v * 2) & 2) | ((v >> 1) & 1));
                *(s32 *)elem = *(s32 *)(tbl + i * 8 + flag * 4);
            }
        }
        if (runlinkIsModuleLoaded(0x1B) != 0) {
            animseqUpdateTrackFade(trackVisibleBlocks + 1, track, arg1);
        } else if (trackFade != 0xFF || trackFadeCount != 0 || runlinkIsModuleLoaded(0x17) != 0 ||
                   runlinkIsModuleLoaded(0x1D) != 0) {
            flamethrowerDraw(trackVisibleBlocks + 1, track, arg1);
        } else {
            func_80013DCC();
        }
        lights = (u8 *)D_800A0D78_A1978;
        count = D_800A0D70_A1970;
        for (i = 0; i < count; i++) {
            if (*(f32 *)(lights + i * 0x80 + 0xC) != 0.0f) {
                trackLightAsm(track, lights + i * 0x80, trackVisibleBlocks + 1);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackUpdateLighting.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8001412C(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 out0;
    s32 out1;
    s32 out2;
    s32 count;
    s32 i;
    void **players;
    u8 *obj;
    u8 *reflect;

    out0 = *arg0;
    out1 = *arg1;
    out2 = *arg2;
    players = objGetPlayerlist(&count);
    while (count-- != 0) { // indices count-1 .. 0
        obj = (u8 *)players[count];
        reflect = *(u8 **)(*(u8 **)(obj + 0x68) + 0x564);
        if (reflect != NULL) {
            if (((*(u32 *)(reflect + 0x620) << 6) >> 0x1A) != 0) {
                realReflectCreateList(obj, reflect, &out0, &out1, &out2);
            }
        }
    }
    *arg0 = out0;
    *arg1 = out1;
    *arg2 = out2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001412C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Track draw pass: builds the visible object list (objs), culls per block and
// draws in several passes. Offsets are raw (no struct in include/ fits).
void func_8001424C(s32 arg0, s32 arg1) {
    s32 objCount;      /* spFC: out param of objPartInv */
    s32 partStart;     /* s4: first index returned by objPartInv */
    s32 blockCount;    /* spF8 */
    u8 blockIds[0x90]; /* sp68 */
    void **objs;       /* sp64 = generalBuffer, object pointer list */
    s32 lastIdx;       /* sp4C = visibleCount - 1 */
    s32 i;
    s32 k;
    s32 s1;
    s32 s2;            /* visible object count */
    s32 v1;
    s32 a1Count;
    s32 end;
    u8 *obj;
    u8 *a1;
    u8 *a2;
    void *tmp0;
    void *tmp1;
    void *tmp2;
    void *tmp3;
    s32 flags;
    s32 type;
    s32 visible;

    (void)arg0;

    partStart = objPartInv(&objCount);
    objs = generalBuffer;
    if (*(s16 *)((u8 *)track + 0x1A) >= 2) {
        blockCount = 0;
        func_800150A4(0, 0, *(s16 *)((u8 *)track + 0x1A) - 1, blockIds, &blockCount);
    } else {
        blockCount = 1;
        blockIds[0] = 0;
    }
    objZsortGroup(partStart, objCount - 1);
    texDPInit(&D_800F2F70_B1750);
    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x63C);

    trackVisibleBlocks[0] = 1;
    for (i = 1; i <= *(s16 *)((u8 *)track + 0x1A); i++) {
        trackVisibleBlocks[i] = 0;
    }
    if (D_800A0CD0_A18D0 != 0 || D_800A0CD4_A18D4 != 0) {
        for (k = blockCount - 1; k >= 0; k--) {
            func_80014B6C(blockIds[k], 0x10000000);
            trackVisibleBlocks[blockIds[k] + 1] = 1;
        }
    }
    if (*(s16 *)((u8 *)track + 0x1A) < 2) {
        trackVisibleBlocks[1] = 1;
    }

    trackUpdateLighting(0, arg1);
    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x650);
    if (D_800A0CD0_A18D0 != 0) {
        for (s1 = 0; s1 < blockCount; s1++) {
            func_80014B6C(blockIds[s1], 0);
        }
    }

    s1 = (D_800A0CD8_A18D8 != 0) ? partStart : objCount;
    s2 = 0;
    if (s1 < objCount) {
        do {
            obj = objGetObject(s1);
            s1 += 1;
            if (obj != NULL) {
                visible = trackVisibleBlocks[*(s16 *)(obj + 0x2E) + 1];
                type = *(s16 *)(obj + 0x48);
                if ((visible != 0 && func_80015D54(obj) != 0) || type == 0x24 || type == 0x8E) {
                    objs[s2] = obj;
                    s2 += 1;
                }
            }
        } while (s1 < objCount);
    }
    if (*(s8 *)((u8 *)level + 0xF2) != 0) {
        bloodSpurtsDraw(s2, objs);
    }

    if (racingInGame != 0 || multiPlayerGame != 0) {
        s1 = 0;
        if (s2 > 0) {
            do {
                obj = objs[s1];
                if (*(s16 *)(obj + 0x4A) == 0x1FB) {
                    objPrintObject(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, obj);
                    s2 -= 1;
                    if (s1 < s2) {
                        v1 = s1;
                        a1Count = (s2 - s1) & 3;
                        if (a1Count != 0) {
                            end = a1Count + s1;
                            do {
                                tmp0 = objs[v1 + 1];
                                v1 += 1;
                                objs[v1 - 1] = tmp0;
                            } while (end != v1);
                        }
                        if (v1 != s2) {
                            do {
                                tmp0 = objs[v1 + 1];
                                tmp1 = objs[v1 + 2];
                                tmp2 = objs[v1 + 3];
                                tmp3 = objs[v1 + 4];
                                v1 += 4;
                                objs[v1 - 4] = tmp0;
                                objs[v1 - 3] = tmp1;
                                objs[v1 - 2] = tmp2;
                                objs[v1 - 1] = tmp3;
                            } while (v1 != s2);
                        }
                    }
                } else {
                    s1 += 1;
                }
            } while (s1 < s2);
        }
    }

    s1 = 0;
    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x683);
    if (s2 > 0) {
        do {
            obj = objs[s1];
            s1 += 1;
            if (*(u32 *)(obj + 0x5C) != 0 && !(*(s16 *)(obj + 6) & 0xC) && *(u8 *)(obj + 0x39) == 0xFF) {
                objPrintObject(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, obj);
            }
        } while (s1 != s2);
    }

    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x68F);
    lastIdx = s2 - 1;
    for (i = lastIdx; i >= 0; i--) {
        obj = objs[i];
        a1 = *(u8 **)(obj + 0x50);
        if (a1 != NULL && *(u8 *)(obj + 0x92) == 0) {
            if (*(u8 *)(a1 + 0xC) & 0x18) {
                a2 = *(u8 **)(a1 + 0x1C);
                if (a2 != NULL) {
                    ((void (*)(void *, void *, void *))func_8001B6D8)(obj, a2, a2); /* sig mismatch: asm passes a2 as 3rd arg */
                    a1 = *(u8 **)(obj + 0x50);
                }
            }
            func_8001B6D8(obj, a1);
        }
    }

    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x6A3);
    if (s2 > 0) {
        s1 = 0;
        do {
            obj = objs[s1];
            s1 += 1;
            if (!(*(s16 *)(obj + 6) & 0xC) && *(u8 *)(obj + 0x39) == 0xFF && *(u32 *)(obj + 0x5C) == 0) {
                objPrintObject(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, obj);
            }
        } while (s1 != s2);
    }

    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x6AF);
    for (i = lastIdx; i >= 0; i--) {
        obj = objs[i];
        if (*(s16 *)(obj + 6) & 8) {
            objPrintObject(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, obj);
        }
    }
    if (runlinkIsModuleLoaded(8) != 0) {
        realReflectPrint(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758);
    }

    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x6BF);
    if (D_800A0CD0_A18D0 != 0) {
        for (k = blockCount - 1; k >= 0; k--) {
            func_80014B6C(blockIds[k], 4);
        }
    }

    if (*(s8 *)((u8 *)level + 0xF2) != 0) {
        diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x6CD);
        dropletDrawAll(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758);
        if (D_800A0CD0_A18D0 != 0) {
            for (k = blockCount - 1; k >= 0; k--) {
                func_80014B6C(blockIds[k], 0x20000000);
            }
            for (i = lastIdx; i >= 0; i--) {
                obj = objs[i];
                a1 = *(u8 **)(obj + 0x50);
                if (a1 != NULL && *(u8 *)(obj + 0x92) != 0) {
                    if (*(u8 *)(a1 + 0xC) & 0x18) {
                        a2 = *(u8 **)(a1 + 0x1C);
                        if (a2 != NULL) {
                            ((void (*)(void *, void *, void *))func_8001B6D8)(obj, a2, a2); /* sig mismatch: asm passes a2 as 3rd arg */
                            a1 = *(u8 **)(obj + 0x50);
                        }
                    }
                    func_8001B6D8(obj, a1);
                }
            }
        }
    }

    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x6E8);
    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x6F0);
    for (i = lastIdx; i >= 0; i--) {
        obj = objs[i];
        if (*(void **)(obj + 0x58) != NULL) {
            wakeDrawRipple(*(void **)(obj + 0x58), &D_800F2F70_B1750);
        }
    }

    if (runlinkIsModuleLoaded(1) != 0) {
        sparkDraw(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758);
    }
    if (runlinkIsModuleLoaded(0xA) != 0) {
        mineDraw(&D_800F2F70_B1750, &D_800F2F78_B1758);
    }
    fxDrawLevelEffects(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, &D_800F2F7C_B175C);
    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x707);

    for (i = lastIdx; i >= 0; i--) {
        obj = objs[i];
        flags = *(s16 *)(obj + 6);
        if ((flags & 4) || *(u8 *)(obj + 0x39) < 0xFF) {
            objPrintObject(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, obj);
            flags = *(s16 *)(obj + 6);
        }
        if (flags & 0x200) {
            type = *(s16 *)(obj + 0x48);
            if (type >= 2) {
                switch (type) {
                case 0x5F:
                case 0x96:
                    mizarDrawEffects(&D_800F2F70_B1750, &D_800F2F74_B1754, obj);
                    break;
                case 0x6C:
                    mantismissileDrawThruster(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, obj);
                    break;
                case 0x85:
                    regionidDraw(&D_800F2F70_B1750, &D_800F2F74_B1754, obj);
                    break;
                case 0x88:
                    ammoPickupGetFade(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758, obj);
                    break;
                case 0xA7:
                    animshipDrawThrusters(&D_800F2F70_B1750, &D_800F2F74_B1754, obj);
                    break;
                case 0xA9:
                    hoovertankDrawEffects(&D_800F2F70_B1750, &D_800F2F74_B1754, obj);
                    break;
                }
            } else if (type == 1) {
                objDrawPlayerEffects(&D_800F2F70_B1750, &D_800F2F74_B1754, obj);
            }
        }
    }

    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x725);
    if (D_800A3330_A3F30 == 0 && camGetMode() == 0) {
        partDraw(&D_800F2F70_B1750, &D_800F2F74_B1754);
    }

    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x731);
    func_8001412C(&D_800F2F70_B1750, &D_800F2F74_B1754, &D_800F2F78_B1758);
    globflags = 0;
    diRcpTrace(D_800F2F70_B1750, "track/track.c", 0x736);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001424C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80014B6C(s32 arg0, s32 arg1) {
    u8 *entry;
    u8 *rec;
    TextureHeader *tex;
    Gfx *dl;
    s32 mask;
    s32 value;
    s32 start;
    s32 end;
    s32 flags;
    s32 texIdx;
    s32 hasTex;
    s32 alpha;
    s32 tint;
    s32 useTex;
    s32 n;
    u32 vtx;
    u32 tri;

    entry = *(u8 **)((u8 *)track + 0x04) + arg0 * 0x48;
    mask = 0x10000400;
    value = 0;
    switch (arg1) {
    case 0x10000000:
        texDisableModes(2);
        start = 0;
        end = entry[0x46];
        value = 0x10000000;
        break;
    case 0x4:
        mask = 0x30000400;
        start = entry[0x47];
        end = *(s16 *)(entry + 0x28);
        break;
    case 0x20000000:
        mask = 0x30000400;
        value = 0x20000000;
        start = entry[0x47];
        end = *(s16 *)(entry + 0x28);
        break;
    default:
        start = entry[0x46];
        end = entry[0x47];
        break;
    }

    rec = *(u8 **)(entry + 0x0C) + start * 0x10;
    for (; start < end; start++, rec += 0x10) {
        flags = *(s32 *)(rec + 0x0C);
        if (value != (flags & mask)) {
            continue;
        }
        texIdx = rec[0x00];
        tex = NULL;
        hasTex = 0;
        if (texIdx != 0xFF) {
            hasTex = 1;
            tex = *(TextureHeader **)(*(u8 **)((u8 *)track + 0x00) + texIdx * 8);
        }
        alpha = *(u16 *)(rec + 0x0A) << 8;
        tint = (alpha >> 8) & 0xFF;
        vtx = *(u32 *)(entry + 0x00) + *(s16 *)(rec + 0x06) * 0xA;
        tri = *(u32 *)(entry + 0x04) + *(s16 *)(rec + 0x08) * 0x10;

        dl = D_800F2F70_B1750;
        D_800F2F70_B1750 = dl + 1;
        if (tex != NULL && (tex->flags & 0x40) && ((flags & 0x30) != 0x20)) {
            dl->words.w0 = 0xFB000000;
            dl->words.w1 = ((u32)tint << 24) | ((u32)tint << 16) | ((u32)tint << 8) | (u32)tint;
        } else {
            dl->words.w1 = 0xFFFFFF00;
            dl->words.w0 = 0xFB000000;
        }

        if (!(flags & 0x180)) {
            flags |= globflags;
        }
        useTex = flags & 0x4000;
        if (useTex != 0 && tex != NULL) {
            func_8001C570(tex, alpha, flags, alpha);
        } else {
            texDPTextureX(&D_800F2F70_B1750, tex, flags | 2, alpha);
        }

        n = *(s16 *)(rec + 0x16) - *(s16 *)(rec + 0x06);
        dl = D_800F2F70_B1750;
        D_800F2F70_B1750 = dl + 1;
        dl->words.w0 = (((n * 0xA) + 8) & 0xFFFF) | 0x04000000 | ((((n * 8) | (vtx & 6)) & 0xFF) << 0x10);
        dl->words.w1 = vtx + 0x80000000;

        n = *(s16 *)(rec + 0x18) - *(s16 *)(rec + 0x08);
        dl = D_800F2F70_B1750;
        D_800F2F70_B1750 = dl + 1;
        dl->words.w1 = tri + 0x80000000;
        dl->words.w0 = ((n * 0x10) & 0xFFFF) | 0x05000000 | ((((n - 1) * 0x10) | hasTex) & 0xFF) << 0x10;

        if (useTex != 0) {
            texDPInit(&D_800F2F70_B1750);
        }
    }
    if (arg1 == 0x10000000) {
        texEnableModes(2);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80014B6C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800150A4(s16 arg0, u8 arg1, u8 arg2, u8 *arg3, s32 *arg4) {
    u8 *nodes;
    u8 *node;
    s16 nodeIdx;
    s16 left;
    s16 right;
    u8 lo;
    u8 hi;
    u8 mid;
    s32 value;

    nodes = *(u8 **)((u8 *)track + 0x14);
    nodeIdx = arg0;
    lo = arg1;
    hi = arg2;
    for (;;) {
        node = nodes + nodeIdx * 8;
        left = *(s16 *)(node + 0);
        right = *(s16 *)(node + 2);
        mid = node[5];
        if (node[4] == 0) {
            value = (s32)*(f32 *)((u8 *)D_800F2F80_B1760 + 0x0C);
        } else if (node[4] == 1) {
            value = (s32)*(f32 *)((u8 *)D_800F2F80_B1760 + 0x10);
        } else {
            value = (s32)*(f32 *)((u8 *)D_800F2F80_B1760 + 0x14);
        }
        if (value < *(s16 *)(node + 6)) {
            if (left != -1) {
                func_800150A4(left, lo, mid - 1, arg3, arg4);
            } else {
                func_800152C0(lo, arg4, arg3);
            }
            if (right != -1) {
                lo = mid;
                nodeIdx = right;
                continue;
            }
            func_800152C0(hi, arg4, arg3);
            return;
        }
        if (right != -1) {
            func_800150A4(right, mid, hi, arg3, arg4);
        } else {
            func_800152C0(hi, arg4, arg3);
        }
        if (left != -1) {
            hi = mid - 1;
            nodeIdx = left;
            continue;
        }
        func_800152C0(lo, arg4, arg3);
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_800150A4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800152C0(s32 arg0, s32 *arg1, u8 *arg2) {
    s32 visible;
    u8 *flags;
    s32 base;

    if (arg0 < *(s16 *)((u8 *)track + 0x1A)) {
        visible = 1;
        base = D_800F2F90_B1770;
        if (base != -1) {
            flags = *(u8 **)((u8 *)track + 0x10);
            visible = (flags[base + (arg0 >> 3)] >> (arg0 & 7)) & 0xFF;
        }
        if (visible & 1) {
            if (func_800159B8(*(u8 **)((u8 *)track + 0x08) + arg0 * 0xC, arg0) != 0) {
                arg2[*arg1] = (s8)arg0;
                *arg1 += 1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_800152C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackGetBlock(f32 arg0, f32 arg1, f32 arg2) {
    s16 *blocks;
    s32 count;
    s32 i;
    s32 x;
    s32 z;
    s32 dist;
    s32 bestDist;
    s32 best;

    best = -1;
    if (track != NULL) {
        count = *(s16 *)((u8 *)track + 0x1A);
        blocks = *(s16 **)((u8 *)track + 0x08);
        bestDist = 0x7FFF;
        x = (s32)arg0;
        z = (s32)arg2;
        for (i = 0; i < count; i++, blocks += 6) {
            if (blocks[3] >= x && x >= blocks[0] && blocks[5] >= z && z >= blocks[2]) {
                dist = ((s32)(blocks[1] + blocks[4]) >> 1) - (s32)arg1;
                if (dist < 0) {
                    dist = -dist;
                }
                if (dist < bestDist) {
                    bestDist = dist;
                    best = i;
                }
            }
        }
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetBlock.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackGetBlockList(s32 arg0, s32 arg1, s16 *arg2) {
    s16 *blocks;
    s32 found;
    s32 i;

    found = 0;
    for (i = 0; i < *(s16 *)((u8 *)track + 0x1A); i++) {
        blocks = (s16 *)(*(u8 **)((u8 *)track + 0x08) + i * 12);
        if (arg0 < blocks[3] + 4 && blocks[0] - 4 < arg0 && arg1 < blocks[5] + 4 && blocks[2] - 4 < arg1) {
            *arg2 = (s16)i;
            found++;
            arg2++;
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetBlockList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackGetCubeBlockList(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    s16 *blocks;
    s32 count;
    s32 found;
    s32 i;

    found = 0;
    count = *(s16 *)((u8 *)track + 0x1A);
    blocks = *(s16 **)((u8 *)track + 0x08);
    for (i = 0; i < count; i++, blocks += 6) {
        if (blocks[3] >= (s16)(arg1 - 4) && (s16)(arg4 + 4) >= blocks[0] &&
            blocks[5] >= (s16)(arg3 - 4) && (s16)(arg6 + 4) >= blocks[2] &&
            blocks[4] >= (s16)(arg2 - 4) && (s16)(arg5 + 4) >= blocks[1]) {
            arg0[found] = i;
            found++;
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetCubeBlockList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *trackBlockDim(s32 arg0) {
    if (arg0 < 0 || *(s16 *)((u8 *)track + 0x1A) < arg0) {
        return NULL;
    }
    return *(u8 **)((u8 *)track + 0x08) + arg0 * 0xC;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackBlockDim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80015738(void) {
    f32 *src;
    f32 *dst;
    f32 (*invMtx)[4];
    f32 pa[3];
    f32 pb[3];
    f32 pc[3];
    f32 nx;
    f32 ny;
    f32 nz;
    f32 invLen;
    s32 i;

    invMtx = camGetInvProjMtx();
    for (i = 0; i < 3; i++) {
        src = D_800A0CF4_A18F4 + i * 9;
        dst = D_800F2FB8_B1798 + i * 4;
        mathMtxXFMF(invMtx, src[0], src[1], src[2], &pa[0], &pa[1], &pa[2]);
        mathMtxXFMF(invMtx, src[3], src[4], src[5], &pb[0], &pb[1], &pb[2]);
        mathMtxXFMF(invMtx, src[6], src[7], src[8], &pc[0], &pc[1], &pc[2]);
        nx = (pb[2] - pc[2]) * pa[1] + pb[1] * (pc[2] - pa[2]) + pc[1] * (pa[2] - pb[2]);
        ny = (pb[0] - pc[0]) * pa[2] + pb[2] * (pc[0] - pa[0]) + pc[2] * (pa[0] - pb[0]);
        nz = (pb[1] - pc[1]) * pa[0] + pb[0] * (pc[1] - pa[1]) + pc[0] * (pa[1] - pb[1]);
        invLen = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
        if (invLen > 0.0f) {
            nx *= invLen;
            ny *= invLen;
            nz *= invLen;
        }
        dst[0] = nx;
        dst[1] = ny;
        dst[2] = nz;
        dst[3] = -((pa[0] * nx) + (pa[1] * ny) + (pa[2] * nz));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80015738.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_800159B8(void *arg0, s32 arg1) {
    u8 *box;
    f32 *pl;
    s32 p;
    s32 c;
    s32 inside;
    s32 x;
    s32 y;
    s32 z;
    long long acc;
    f32 cx;
    f32 cy;
    f32 cz;

    box = (u8 *)arg0;
    for (p = 0; p < 3; p++) {
        pl = D_800F2FB8_B1798 + p * 4;
        inside = 0;
        for (c = 0; c < 8 && !inside; c++) {
            x = (c & 1) ? *(s16 *)(box + 0x0) : *(s16 *)(box + 0x6);
            y = (c & 2) ? *(s16 *)(box + 0x2) : *(s16 *)(box + 0x8);
            z = (c & 4) ? *(s16 *)(box + 0x4) : *(s16 *)(box + 0xA);
            acc = (long long)((f32)x * pl[0]);
            acc = (long long)((f32)acc + (f32)y * pl[1]);
            acc = (long long)((f32)acc + (f32)z * pl[2]);
            acc = (long long)((f32)acc + pl[3]);
            if (acc > 0) {
                inside = 1;
            }
        }
        if (!inside) {
            return 0;
        }
    }
    cx = (f32)((*(s16 *)(box + 0x6) + *(s16 *)(box + 0x0)) >> 1);
    cy = (f32)((*(s16 *)(box + 0x8) + *(s16 *)(box + 0x2)) >> 1);
    cz = (f32)((*(s16 *)(box + 0xA) + *(s16 *)(box + 0x4)) >> 1);
    D_800F31D8_B19B8 = camDistance(cx, cy, cz);
    if (D_800F31D8_B19B8 < 1000.0f) {
        D_800F2F8C_B176C = 1;
        return 1;
    }
    D_800F2F8C_B176C = 0;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_800159B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80015CB8(void *arg0) {
    u8 *sub;
    s32 result;

    sub = *(u8 **)((u8 *)arg0 + 0x68);
    result = 0xFF;
    if (*(s32 *)(sub + 0x5C0) == 0) {
        if (*(u8 *)(sub + 0x568) == 0xA) {
            result = 0xFF - (*(s8 *)(sub + 0x19C) * 2);
        } else if (camGetNo() == *(s8 *)(sub + 0x0)) {
            result = 0xFF - (*(s8 *)(sub + 0x19C) * 4);
            if (multiPlayerGame != 0) {
                result -= *(s8 *)(sub + 0x19C);
            }
            if (result < 0) {
                result = 0;
            }
        }
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80015CB8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80015D54(void *arg0) {
    u8 *obj;
    u8 *sub68;
    u8 *sub24;
    s32 result;
    s16 range;
    f32 dist;
    f32 rem;
    f32 band;
    f32 px;
    f32 py;
    f32 pz;
    f32 *pl;
    s32 i;
    u8 cam;

    obj = (u8 *)arg0;
    result = 1;
    switch (*(s16 *)(obj + 0x48)) {
    case 0x2:
        sub68 = *(u8 **)(obj + 0x68);
        *(u8 *)(obj + 0x39) = (u8)*(s16 *)(sub68 + 0x90);
        sub24 = *(u8 **)(sub68 + 0x24);
        if (sub24 != NULL) {
            cam = (u8)func_80015CB8(sub24);
            if (cam != 0xFF) {
                *(u8 *)(obj + 0x39) = (u8)((*(u8 *)(obj + 0x39) * cam) >> 8);
            }
        }
        break;
    case 0x1:
        *(u8 *)(obj + 0x39) = (u8)func_80015CB8(obj);
        break;
    case 0x26:
        *(u8 *)(obj + 0x39) = *(u8 *)(*(u8 **)(obj + 0x68) + 0x8);
        break;
    case 0x18:
        *(u8 *)(obj + 0x39) = (u8)(0xFF - *(u8 *)(*(u8 **)(obj + 0x68) + 0x55));
        break;
    case 0x2B:
    case 0x3D:
    case 0x50:
    case 0x51:
        *(u8 *)(obj + 0x39) = (u8)*(s32 *)(obj + 0x8C);
        break;
    case 0x42:
        *(u8 *)(obj + 0x39) = osCartTest4_6105(obj, camGetNo());
        result = 1;
        break;
    case 0x55:
    case 0x56:
    case 0x5E:
    case 0x66:
    case 0x67:
    case 0x7A:
    case 0x7B:
    case 0x7E:
    case 0x86:
    case 0xA6:
    case 0xA7:
        *(u8 *)(obj + 0x39) = (u8)*(s32 *)(obj + 0x8C);
        break;
    case 0x54:
    case 0xA8:
        *(u8 *)(obj + 0x39) = *(u8 *)(*(u8 **)(obj + 0x68) + 0x7);
        break;
    case 0x6E:
        if (*(s32 *)(obj + 0x8C) >= 0xFF) {
            *(u8 *)(obj + 0x39) = 0xFF;
        } else {
            *(u8 *)(obj + 0x39) = (u8)*(s32 *)(obj + 0x8C);
        }
        break;
    default:
        *(u8 *)(obj + 0x39) = 0xFF;
        break;
    }
    if (*(u8 *)(obj + 0x39) == 0) {
        return 0;
    }
    range = *(s16 *)(*(u8 **)(obj + 0x40) + 0x16);
    if (range != 0) {
        dist = camDistance(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
        result = 1;
        if ((f32)range < dist) {
            result = 0;
        } else {
            rem = (f32)range - dist;
            band = (f32)range * 0.3f;
            if (rem < band) {
                *(u8 *)(obj + 0x39) = (u8)(s32)((f32)*(u8 *)(obj + 0x39) * (rem / band));
            }
        }
    }
    px = *(f32 *)(obj + 0xC);
    py = *(f32 *)(obj + 0x10);
    pz = *(f32 *)(obj + 0x14);
    pl = D_800F2FB8_B1798;
    for (i = 0; i < 3 && result != 0; i++) {
        if ((px * pl[0] + py * pl[1] + pz * pl[2] + pl[3] + *(f32 *)(obj + 0x34)) < 0.0f) {
            result = 0;
        }
        pl += 4;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80015D54.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackGetIntersect(s32 arg0, void *arg1, void *arg2, f32 arg3, u16 arg4, void *arg5) {
    u8 *hit;
    f32 *src;
    f32 *dst;
    s32 edges;
    s32 noLoop;
    s32 found;
    s32 hitCount;
    s32 pass;

    hit = (u8 *)arg5;
    edges = arg4 & 0x10;
    noLoop = arg4 & 0x40;
    if (edges != 0) {
        func_800182C0();
        hitPolyEdgeBuffer();
    }
    *(s32 *)(hit + 0x00) = 0;
    *(u8 *)(hit + 0x25) = 0;
    *(f32 *)(hit + 0x04) = 0.0f;
    *(f32 *)(hit + 0x08) = 0.0f;
    *(f32 *)(hit + 0x0C) = 0.0f;
    *(f32 *)(hit + 0x10) = 0.0f;
    *(f32 *)(hit + 0x14) = 0.0f;
    *(f32 *)(hit + 0x18) = 0.0f;
    *(u8 *)(hit + 0x24) = 0;
    *(s32 *)(hit + 0x20) = 0;
    *(u8 *)(hit + 0x26) = 0;
    *(u8 *)(hit + 0x27) = 0;
    *(f32 *)(hit + 0x1C) = 1.024e9f;
    found = 0;
    hitCount = 0;
    if (noLoop == 0) {
        do {
            pass = 0;
            if (hitPolyPlaneTest(arg0, arg1, arg2, arg5, arg3, (s32)arg4, arg3) != 0) {
                pass = 1;
                found = 1;
            }
            if (func_80016EA0(arg1, arg2, arg5, arg3, (s32)arg4, arg3) != 0) {
                pass = 1;
                found = 1;
            }
            if (edges != 0) {
                if (hitPolyEdgeTest(arg1, arg2, arg5, arg3, (s32)arg4) != 0) {
                    pass = 1;
                    found = 1;
                }
                if (func_800175A0(arg1, arg2, arg5, arg3, (s32)arg4) != 0) {
                    pass = 1;
                    found = 1;
                }
            }
            if (pass != 0) {
                hitCount += 1;
                if (hitCount >= 6) {
                    pass = 0;
                    found = 0;
                    src = (f32 *)arg1;
                    dst = (f32 *)arg2;
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                    *(u8 *)(hit + 0x25) = 0;
                }
            }
        } while (pass != 0);
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetIntersect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching (player-vs-track collision, 11 args; see charControl.c controlGroundHits)
u32 trackGetPlayerIntersect(void *obj, void *outPos, f32 *polyPts, f32 *pts, f32 *ptParam,
                             f32 *deltas, u16 *mask, void *hits, s32 n, s32 *outIdx, f32 *outVec) {
    u8 *hitsB;
    f32 *outP;
    f32 *p2;
    f32 *p3;
    u8 *rec;
    u32 ret = 0;
    s32 spB0 = 0;     /* pass counter, clamp test at 11 (sp B0) */
    s32 spA8 = 0;     /* set when the 0x11110000 path ran (sp A8) */
    s32 spAC = 0;     /* best hit record index, kept across passes (sp AC) */
    s32 fp = 0;       /* hit bit per point (var_fp) */
    s32 s7 = 1;       /* bit of point i (var_s7) */
    s32 i;
    s32 k;
    s32 rem;
    s32 mk;
    s32 hitHere;      /* var_s1 */
    s32 hitCount;     /* var_s6 */
    s32 flag48 = 0;   /* var_v1 in the flag scan */
    s32 flag12 = 0;   /* var_a0 in the flag scan */
    f32 ptp;          /* ptParam[i] (f20) */
    f32 bestD;
    s32 bestIdx;

    /* hit record (0x28 B): +0x00 s32 0; +0x04..+0x18 point xyz and normal xyz (f32);
       +0x1C f32 distance (1.024e9 = none); +0x20 s32; +0x24 u8 type (3 = report index);
       +0x25 u8 flags (|1 = used, |0x80 = clamped); +0x26/+0x27 u8. */
    hitsB = (u8 *)hits;
    outP = (f32 *)outPos;
    outVec[0] = 0.0f;
    outVec[1] = 0.0f;
    outVec[2] = 0.0f;
    *outIdx = -1;

    /* init hit records */
    if (n > 0) {
        k = 0;
        rem = n & 3;
        if (rem != 0) {
            do {
                { u8 *r = hitsB + (k) * 0x28;
                    *(s32 *)(r + 0x00) = 0;
                    *(f32 *)(r + 0x04) = 0.0f; *(f32 *)(r + 0x08) = 0.0f; *(f32 *)(r + 0x0C) = 0.0f;
                    *(f32 *)(r + 0x10) = 0.0f; *(f32 *)(r + 0x14) = 0.0f; *(f32 *)(r + 0x18) = 0.0f;
                    *(f32 *)(r + 0x1C) = 1.024e9f;
                    *(s32 *)(r + 0x20) = 0;
                    r[0x24] = 0; r[0x25] = 0; r[0x26] = 0; r[0x27] = 0;
                }
                k++;
            } while (k != rem);
        }
        while (k != n) {
            { u8 *r = hitsB + (k) * 0x28;
                *(s32 *)(r + 0x00) = 0;
                *(f32 *)(r + 0x04) = 0.0f; *(f32 *)(r + 0x08) = 0.0f; *(f32 *)(r + 0x0C) = 0.0f;
                *(f32 *)(r + 0x10) = 0.0f; *(f32 *)(r + 0x14) = 0.0f; *(f32 *)(r + 0x18) = 0.0f;
                *(f32 *)(r + 0x1C) = 1.024e9f;
                *(s32 *)(r + 0x20) = 0;
                r[0x24] = 0; r[0x25] = 0; r[0x26] = 0; r[0x27] = 0;
            }
            { u8 *r = hitsB + (k + 1) * 0x28;
                *(s32 *)(r + 0x00) = 0;
                *(f32 *)(r + 0x04) = 0.0f; *(f32 *)(r + 0x08) = 0.0f; *(f32 *)(r + 0x0C) = 0.0f;
                *(f32 *)(r + 0x10) = 0.0f; *(f32 *)(r + 0x14) = 0.0f; *(f32 *)(r + 0x18) = 0.0f;
                *(f32 *)(r + 0x1C) = 1.024e9f;
                *(s32 *)(r + 0x20) = 0;
                r[0x24] = 0; r[0x25] = 0; r[0x26] = 0; r[0x27] = 0;
            }
            { u8 *r = hitsB + (k + 2) * 0x28;
                *(s32 *)(r + 0x00) = 0;
                *(f32 *)(r + 0x04) = 0.0f; *(f32 *)(r + 0x08) = 0.0f; *(f32 *)(r + 0x0C) = 0.0f;
                *(f32 *)(r + 0x10) = 0.0f; *(f32 *)(r + 0x14) = 0.0f; *(f32 *)(r + 0x18) = 0.0f;
                *(f32 *)(r + 0x1C) = 1.024e9f;
                *(s32 *)(r + 0x20) = 0;
                r[0x24] = 0; r[0x25] = 0; r[0x26] = 0; r[0x27] = 0;
            }
            { u8 *r = hitsB + (k + 3) * 0x28;
                *(s32 *)(r + 0x00) = 0;
                *(f32 *)(r + 0x04) = 0.0f; *(f32 *)(r + 0x08) = 0.0f; *(f32 *)(r + 0x0C) = 0.0f;
                *(f32 *)(r + 0x10) = 0.0f; *(f32 *)(r + 0x14) = 0.0f; *(f32 *)(r + 0x18) = 0.0f;
                *(f32 *)(r + 0x1C) = 1.024e9f;
                *(s32 *)(r + 0x20) = 0;
                r[0x24] = 0; r[0x25] = 0; r[0x26] = 0; r[0x27] = 0;
            }
            k += 4;
        }
    }

    func_800182C0();
    hitPolyEdgeBuffer();

restart:
    fp = 0;
    s7 = 1;
    i = 0;
    do {
        mk = mask[i];
        ptp = ptParam[i];
        p2 = polyPts + i * 3;
        p3 = pts + i * 3;
        rec = hitsB + i * 0x28;
        hitCount = 0;
        if ((mk & 0x40) == 0) {
            do {
                hitHere = 0;
                if (hitPolyPlaneTest((s32)obj, p2, p3, rec, ptp, mk, 0.0f) != 0) {
                    outVec[0] = outVec[0] + *(f32 *)(rec + 0x10);
                    outVec[1] = outVec[1] + *(f32 *)(rec + 0x14);
                    outVec[2] = outVec[2] + *(f32 *)(rec + 0x18);
                    fp |= s7;
                    hitHere = 1;
                }
                if (func_80016EA0(p2, p3, rec, ptp, mk, 0.0f) != 0) {
                    outVec[0] = outVec[0] + *(f32 *)(rec + 0x10);
                    outVec[1] = outVec[1] + *(f32 *)(rec + 0x14);
                    outVec[2] = outVec[2] + *(f32 *)(rec + 0x18);
                    fp |= s7;
                    hitHere = 1;
                }
                if (hitPolyEdgeTest(p2, p3, rec, ptp, mk) != 0) {
                    outVec[0] = outVec[0] + *(f32 *)(rec + 0x10);
                    outVec[1] = outVec[1] + *(f32 *)(rec + 0x14);
                    outVec[2] = outVec[2] + *(f32 *)(rec + 0x18);
                    fp |= s7;
                    hitHere = 1;
                }
                if (func_800175A0(p2, p3, rec, ptp, mk) != 0) {
                    outVec[0] = outVec[0] + *(f32 *)(rec + 0x10);
                    outVec[1] = outVec[1] + *(f32 *)(rec + 0x14);
                    outVec[2] = outVec[2] + *(f32 *)(rec + 0x18);
                    fp |= s7;
                    hitHere = 1;
                }
                if (hitHere != 0) {
                    hitCount++;
                    if (rec[0x24] == 3) {
                        *outIdx = i;
                    }
                    if (hitCount < 11) {
                        if ((rec[0x25] & 0x12) != 0 && (rec[0x25] & 0x48) != 0) {
                            hitHere = 0;
                            p3[0] = p2[0]; p3[1] = p2[1]; p3[2] = p2[2];
                            *(f32 *)(rec + 0x1C) = 0.0f;
                        }
                    } else {
                        hitHere = 0;
                        p3[0] = p2[0]; p3[1] = p2[1]; p3[2] = p2[2];
                        *(f32 *)(rec + 0x1C) = 0.0f;
                        rec[0x25] = (u8)(rec[0x25] | 0x80);
                    }
                }
            } while (hitHere != 0);
        }
        i++;
        s7 <<= 1;
    } while (i < n);

    if (fp != 0 && deltas != NULL) {
        /* best hit: smallest distance among flagged records (only when n > 0) */
        bestD = 1.024e9f;
        bestIdx = spAC;
        if (n > 0) {
            k = 0;
            rem = n & 3;
            if (rem != 0) {
                do {
                    if ((fp & (1 << (k))) != 0) {
                        if (*(f32 *)(hitsB + (k) * 0x28 + 0x1C) < bestD) {
                            bestD = *(f32 *)(hitsB + (k) * 0x28 + 0x1C);
                            bestIdx = k;
                        }
                    }
                    k++;
                } while (k != rem);
            }
            while (k != n) {
                if ((fp & (1 << (k))) != 0) {
                    if (*(f32 *)(hitsB + (k) * 0x28 + 0x1C) < bestD) {
                        bestD = *(f32 *)(hitsB + (k) * 0x28 + 0x1C);
                        bestIdx = k;
                    }
                }
                if ((fp & (1 << (k + 1))) != 0) {
                    if (*(f32 *)(hitsB + (k + 1) * 0x28 + 0x1C) < bestD) {
                        bestD = *(f32 *)(hitsB + (k + 1) * 0x28 + 0x1C);
                        bestIdx = k + 1;
                    }
                }
                if ((fp & (1 << (k + 2))) != 0) {
                    if (*(f32 *)(hitsB + (k + 2) * 0x28 + 0x1C) < bestD) {
                        bestD = *(f32 *)(hitsB + (k + 2) * 0x28 + 0x1C);
                        bestIdx = k + 2;
                    }
                }
                if ((fp & (1 << (k + 3))) != 0) {
                    if (*(f32 *)(hitsB + (k + 3) * 0x28 + 0x1C) < bestD) {
                        bestD = *(f32 *)(hitsB + (k + 3) * 0x28 + 0x1C);
                        bestIdx = k + 3;
                    }
                }
                k += 4;
            }
        }
        spAC = bestIdx;
        rec = hitsB + bestIdx * 0x28;
        rec[0x25] = (u8)(rec[0x25] | 1);
        outP[0] = pts[bestIdx * 3 + 0] - deltas[bestIdx * 3 + 0];
        outP[1] = pts[bestIdx * 3 + 1] - deltas[bestIdx * 3 + 1];
        outP[2] = pts[bestIdx * 3 + 2] - deltas[bestIdx * 3 + 2];
        /* re-base all points on the new position: pts = deltas + outPos */
        if (n > 0) {
            k = 0;
            rem = n & 3;
            if (rem != 0) {
                do {
                    { f32 *pp = pts + (k) * 3; f32 *dd = deltas + (k) * 3;
                        pp[0] = dd[0] + outP[0]; pp[1] = dd[1] + outP[1]; pp[2] = dd[2] + outP[2]; }
                    k++;
                } while (k != rem);
            }
            while (k != n) {
                { f32 *pp = pts + (k) * 3; f32 *dd = deltas + (k) * 3;
                    pp[0] = dd[0] + outP[0]; pp[1] = dd[1] + outP[1]; pp[2] = dd[2] + outP[2]; }
                { f32 *pp = pts + (k + 1) * 3; f32 *dd = deltas + (k + 1) * 3;
                    pp[0] = dd[0] + outP[0]; pp[1] = dd[1] + outP[1]; pp[2] = dd[2] + outP[2]; }
                { f32 *pp = pts + (k + 2) * 3; f32 *dd = deltas + (k + 2) * 3;
                    pp[0] = dd[0] + outP[0]; pp[1] = dd[1] + outP[1]; pp[2] = dd[2] + outP[2]; }
                { f32 *pp = pts + (k + 3) * 3; f32 *dd = deltas + (k + 3) * 3;
                    pp[0] = dd[0] + outP[0]; pp[1] = dd[1] + outP[1]; pp[2] = dd[2] + outP[2]; }
                k += 4;
            }
        }
    }

    spB0 = spB0 + 1;
    ret |= (u32)fp;
    if (spB0 >= 11) {
        fp = 0;
        /* reset every point to its polygon position */
        if (n > 0) {
            k = 0;
            rem = n & 3;
            if (rem != 0) {
                do {
                    { f32 *pp = pts + (k) * 3; f32 *pl = polyPts + (k) * 3;
                        pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                    k++;
                } while (k != rem);
            }
            while (k != n) {
                { f32 *pp = pts + (k) * 3; f32 *pl = polyPts + (k) * 3;
                    pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                { f32 *pp = pts + (k + 1) * 3; f32 *pl = polyPts + (k + 1) * 3;
                    pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                { f32 *pp = pts + (k + 2) * 3; f32 *pl = polyPts + (k + 2) * 3;
                    pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                { f32 *pp = pts + (k + 3) * 3; f32 *pl = polyPts + (k + 3) * 3;
                    pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                k += 4;
            }
        }
        ret |= 0xFFFF0000;
    } else {
        flag48 = 0;
        flag12 = 0;
        /* scan the flags of all records */
        if (n > 0) {
            k = 0;
            rem = n & 3;
            if (rem != 0) {
                do {
                    { u8 f = *(hitsB + (k) * 0x28 + 0x25);
                        if ((f & 0x48) != 0) flag48 = 1;
                        if ((f & 0x12) != 0) flag12 = 1; }
                    k++;
                } while (k != rem);
            }
            while (k != n) {
                { u8 f = *(hitsB + (k) * 0x28 + 0x25);
                    if ((f & 0x48) != 0) flag48 = 1;
                    if ((f & 0x12) != 0) flag12 = 1; }
                { u8 f = *(hitsB + (k + 1) * 0x28 + 0x25);
                    if ((f & 0x48) != 0) flag48 = 1;
                    if ((f & 0x12) != 0) flag12 = 1; }
                { u8 f = *(hitsB + (k + 2) * 0x28 + 0x25);
                    if ((f & 0x48) != 0) flag48 = 1;
                    if ((f & 0x12) != 0) flag12 = 1; }
                { u8 f = *(hitsB + (k + 3) * 0x28 + 0x25);
                    if ((f & 0x48) != 0) flag48 = 1;
                    if ((f & 0x12) != 0) flag12 = 1; }
                k += 4;
            }
        }
        if (flag48 != 0 && flag12 != 0) {
            spA8 = 1;
            /* flagged records keep their flag and copy points from polygon positions */
            if (n > 0) {
                k = 0;
                rem = n & 3;
                if (rem != 0) {
                    do {
                        { u8 *r = hitsB + (k) * 0x28; f32 *pp = pts + (k) * 3; f32 *pl = polyPts + (k) * 3;
                            if (r[0x25] != 0) r[0x25] = (u8)(r[0x25] | 1);
                            pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                        k++;
                    } while (k != rem);
                }
                while (k != n) {
                    { u8 *r = hitsB + (k) * 0x28; f32 *pp = pts + (k) * 3; f32 *pl = polyPts + (k) * 3;
                        if (r[0x25] != 0) r[0x25] = (u8)(r[0x25] | 1);
                        pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                    { u8 *r = hitsB + (k + 1) * 0x28; f32 *pp = pts + (k + 1) * 3; f32 *pl = polyPts + (k + 1) * 3;
                        if (r[0x25] != 0) r[0x25] = (u8)(r[0x25] | 1);
                        pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                    { u8 *r = hitsB + (k + 2) * 0x28; f32 *pp = pts + (k + 2) * 3; f32 *pl = polyPts + (k + 2) * 3;
                        if (r[0x25] != 0) r[0x25] = (u8)(r[0x25] | 1);
                        pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                    { u8 *r = hitsB + (k + 3) * 0x28; f32 *pp = pts + (k + 3) * 3; f32 *pl = polyPts + (k + 3) * 3;
                        if (r[0x25] != 0) r[0x25] = (u8)(r[0x25] | 1);
                        pp[0] = pl[0]; pp[1] = pl[1]; pp[2] = pl[2]; }
                    k += 4;
                }
            }
            ret |= 0x11110000;
        }
    }

    if (fp != 0 && spA8 == 0) {
        goto restart;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetPlayerIntersect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Swept-sphere test of the segment arg0 -> arg1 against the PL face list (radius arg3, side margin arg5).
// Per PL entry: a positive value selects a block (blk = value | 0x80000000); otherwise the entry is a
// pointer to u16 plane indices: [0] = face plane, [1..3] = side planes (bit 0x8000 = negated).
// Block layout as in trackGetLedgeCrossed: +0x0C groups (16 B), +0x1C planes (16 B: nx, ny, nz, d).
// Hit record (arg2): +0x04 nx, +0x08 ny, +0x0C nz, +0x10 nx, +0x14 ny, +0x18 nz, +0x1C dist^2,
// +0x20 group word C, +0x24 surface byte, +0x25 surface bits (|= 2 floor, 8 ceiling, 4 wall).
// arg4 (low 16 bits): 0x80 pushes arg1 off the plane, 0x01 moves arg1 out to the sphere surface.
s32 func_80016EA0(void *arg0, void *arg1, void *arg2, f32 arg3, s32 arg4, f32 arg5) {
    f32 *start = (f32 *)arg0;
    f32 *end = (f32 *)arg1;
    u8 *hit = (u8 *)arg2;
    u8 *carriedBlk; /* asm: stack slot 0x108, read before it is written in this call (stale stack value) */
    u8 *blk;
    u16 flags = (u16)arg4;
    s32 found = 0;
    s32 i;

    if (PLno > 0) {
        blk = carriedBlk;
        for (i = 0; i < PLno; i++) {
            s32 entry = ((s32 *)PLlist)[i];
            u16 *idx;
            f32 *face;
            f32 nx;
            f32 ny;
            f32 nz;
            f32 planeD;
            f32 dStart;
            f32 dEnd;
            f32 t;
            f32 dx;
            f32 dy;
            f32 dz;
            f32 bx;
            f32 by;
            f32 bz;
            s32 k;
            s32 inside;

            if (entry > 0) {
                blk = (u8 *)((u32)entry | 0x80000000);
                continue;
            }

            idx = (u16 *)(u32)entry;
            face = (f32 *)(*(u8 **)(blk + 0x1C) + (idx[0] * 0x10));
            nx = face[0];
            ny = face[1];
            nz = face[2];
            planeD = face[3] - arg3;
            dEnd = ((end[2] * nz) + ((nx * end[0]) + (ny * end[1]))) + planeD;
            if (dEnd >= 0.0f) {
                continue;
            }
            dStart = ((start[2] * nz) + ((nx * start[0]) + (ny * start[1]))) + planeD;
            if (dStart < 0.0f) {
                continue;
            }

            /* crossing point along start -> end, pulled back by the radius onto the face */
            t = dStart / (dStart - dEnd);
            dx = (end[0] - start[0]) * t;
            dy = (end[1] - start[1]) * t;
            dz = (end[2] - start[2]) * t;
            bx = (start[0] + dx) - (arg3 * nx);
            by = (start[1] + dy) - (arg3 * ny);
            bz = (start[2] + dz) - (arg3 * nz);

            /* the contact point must lie inside the side planes (idx[1..3]) within margin arg5 */
            inside = 1;
            for (k = 1; k < 4 && inside; k++) {
                u16 v = idx[k];
                f32 *side = (f32 *)(*(u8 **)(blk + 0x1C) + ((v & 0x7FFF) * 0x10));
                f32 dist = ((side[0] * bx) + (side[1] * by)) + (side[2] * bz) + side[3];

                if ((v & 0x8000) != 0) {
                    dist = -dist;
                }
                if (arg5 < dist) {
                    inside = 0;
                }
            }
            if (inside == 0) {
                continue;
            }

            {
                u8 *grp;

                found = 1;
                *(f32 *)(hit + 0x1C) = ((dx * dx) + (dy * dy)) + (dz * dz);

                if ((flags & 0x81) != 0) {
                    if ((flags & 1) != 0) {
                        arg3 = arg3 + 0.01f;
                        end[0] = (arg3 * nx) + bx;
                        end[1] = (arg3 * ny) + by;
                        end[2] = (arg3 * nz) + bz;
                    } else {
                        f32 push = 0.01f - dEnd;

                        end[0] = end[0] + (push * nx);
                        end[1] = end[1] + (push * ny);
                        end[2] = end[2] + (push * nz);
                    }
                    *(f32 *)(hit + 0x04) = nx;
                    *(f32 *)(hit + 0x08) = ny;
                    *(f32 *)(hit + 0x0C) = nz;
                    if (ny >= 0.707f) {
                        hit[0x25] |= 2;
                    } else if (ny <= -0.866f) {
                        hit[0x25] |= 8;
                    } else {
                        hit[0x25] |= 4;
                    }
                } else if (ny >= 0.707f) {
                    end[1] = (-((end[2] * nz) + (nx * end[0]) + planeD) / ny) + 0.01f;
                    *(f32 *)(hit + 0x04) = nx;
                    *(f32 *)(hit + 0x08) = ny;
                    *(f32 *)(hit + 0x0C) = nz;
                    hit[0x25] |= 2;
                } else if (ny <= -0.866f) {
                    f32 push = 0.01f - dEnd;

                    end[0] = end[0] + (push * nx);
                    end[1] = end[1] + (push * ny);
                    end[2] = end[2] + (push * nz);
                    hit[0x25] |= 8;
                } else {
                    /* wall: slide end onto the face; the rotation angle picks the xz push length */
                    f32 side = -dEnd;
                    f32 px = end[0] + (side * nx);
                    f32 py = end[1] + (side * ny);
                    f32 pz = end[2] + (side * nz);
                    f32 vx = end[0] - px;
                    f32 vy = end[1] - py;
                    f32 vz = end[2] - pz;
                    f32 cosv = Cosf((s32)(s16)Arctanf(vy, sqrtf((vx * vx) + (vz * vz))));

                    if (cosv != 0.0f) {
                        f32 scale = (side + 0.01f) / cosv;
                        f32 lenXZ = sqrtf((nx * nx) + (nz * nz));

                        end[0] = end[0] + (scale * (nx / lenXZ));
                        end[2] = end[2] + (scale * (nz / lenXZ));
                    } else {
                        end[0] = px;
                        end[1] = py;
                        end[2] = pz;
                    }
                    hit[0x25] |= 4;
                }

                *(f32 *)(hit + 0x10) = nx;
                *(f32 *)(hit + 0x14) = ny;
                *(f32 *)(hit + 0x18) = nz;
                grp = *(u8 **)(blk + 0x0C) + (((s16 *)PLgrps)[i] * 0x10);
                hit[0x24] = (*(u8 **)track)[(grp[0] * 8) + 7];
                *(s32 *)(hit + 0x20) = *(s32 *)(grp + 0x0C);
            }
            break;
        }
        carriedBlk = blk;
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80016EA0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Swept-sphere test of the segment arg0 -> arg1 against the track edge list (trackEdges, 0x30 B per edge,
// count D_800F33B4_B1B94). Per edge: capsule test (trackCylinderIntersect) first, then the two end spheres
// (point A at +0x00, point B at +0x0C) if the capsule missed. On the first hit the loop stops.
// Edge layout: +0x00 A (f32 xyz), +0x0C B (f32 xyz), +0x18 unit direction A->B (f32 xyz), +0x24 length,
// +0x28 block pointer, +0x2C group index (s16), +0x2E flag (s16).
// Hit record (arg2): +0x04/+0x08/+0x0C normal (x, y, z), +0x10/+0x14/+0x18 same normal, +0x1C dist^2,
// +0x20 group word C, +0x24 surface byte (*track)[group[0]*8+7], +0x25 surface bits (|= 2 floor, 8 ceiling,
// 4 wall), +0x26 edge flag byte.
// arg4 (low 16 bits): 0x80 pushes arg1 off the plane, 0x01 moves arg1 to the contact point.
s32 func_800175A0(void *arg0, void *arg1, void *arg2, f32 arg3, s32 arg4) {
    f32 *start = (f32 *)arg0;
    f32 *end = (f32 *)arg1;
    u8 *hit = (u8 *)arg2;
    u16 flags = (u16)arg4;
    f32 dir[3];
    f32 segLen;
    f32 tEnter;
    f32 tExit;
    f32 contact[3];
    f32 ex;
    f32 ey;
    f32 ez;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 lenSq;
    s32 found = 0;
    s32 i;

    dx = end[0] - start[0];
    dy = end[1] - start[1];
    dz = end[2] - start[2];
    lenSq = (dx * dx) + (dy * dy) + (dz * dz);
    if (lenSq <= 0.0f) {
        return 0;
    }

    segLen = sqrtf(lenSq);
    dir[0] = dx / segLen;
    dir[1] = dy / segLen;
    dir[2] = dz / segLen;

    for (i = 0; i < D_800F33B4_B1B94; i++) {
        u8 *edge = (u8 *)trackEdges + (i * 0x30);
        f32 edgeLen = *(f32 *)(edge + 0x24);
        f32 *edgeDir = (f32 *)(edge + 0x18);

        /* capsule test: contact on the edge segment */
        if (trackCylinderIntersect(start, dir, (f32 *)edge, edgeDir, arg3, &tEnter, &tExit) != 0
            && tEnter >= 0.0f && tEnter <= segLen) {
            f32 px;
            f32 py;
            f32 pz;
            f32 t;

            px = (dir[0] * tEnter) + start[0];
            py = (dir[1] * tEnter) + start[1];
            pz = (dir[2] * tEnter) + start[2];
            contact[0] = px;
            contact[1] = py;
            contact[2] = pz;

            /* t = projection of (P - A) on the edge, Q = A + t * edgeDir */
            t = ((((px - *(f32 *)(edge + 0x00)) * edgeDir[0]) + ((py - *(f32 *)(edge + 0x04)) * edgeDir[1]))
                + ((pz - *(f32 *)(edge + 0x08)) * edgeDir[2]))
                / ((edgeDir[2] * edgeDir[2]) + ((edgeDir[0] * edgeDir[0]) + (edgeDir[1] * edgeDir[1])));
            if (t >= 0.0f && t <= edgeLen) {
                found = 1;
                ex = px - ((edgeDir[0] * t) + *(f32 *)(edge + 0x00));
                ey = py - ((edgeDir[1] * t) + *(f32 *)(edge + 0x04));
                ez = pz - ((edgeDir[2] * t) + *(f32 *)(edge + 0x08));
            }
        }

        /* end spheres: A, then B (only while nothing was hit yet) */
        if (!found && trackSphereIntersect(start, dir, (f32 *)edge, arg3, &tEnter, &tExit) != 0
            && tEnter >= 0.0f && tEnter <= segLen) {
            found = 1;
            contact[0] = (dir[0] * tEnter) + start[0];
            contact[1] = (dir[1] * tEnter) + start[1];
            contact[2] = (dir[2] * tEnter) + start[2];
            ex = contact[0] - *(f32 *)(edge + 0x00);
            ey = contact[1] - *(f32 *)(edge + 0x04);
            ez = contact[2] - *(f32 *)(edge + 0x08);
        }
        if (!found && trackSphereIntersect(start, dir, (f32 *)(edge + 0x0C), arg3, &tEnter, &tExit) != 0
            && tEnter >= 0.0f && tEnter <= segLen) {
            found = 1;
            contact[0] = (dir[0] * tEnter) + start[0];
            contact[1] = (dir[1] * tEnter) + start[1];
            contact[2] = (dir[2] * tEnter) + start[2];
            ex = contact[0] - *(f32 *)(edge + 0x0C);
            ey = contact[1] - *(f32 *)(edge + 0x10);
            ez = contact[2] - *(f32 *)(edge + 0x14);
        }

        if (found) {
            f32 pn;
            f32 dist;
            u8 *blk;
            u8 *grp;

            /* unit normal = (contact - closest) / radius */
            nx = ex / arg3;
            ny = ey / arg3;
            nz = ez / arg3;
            pn = ((contact[0] * nx) + (contact[1] * ny)) + (contact[2] * nz);
            dist = ((end[2] * nz) + ((nx * end[0]) + (ny * end[1]))) - pn;

            if ((flags & 0x81) != 0) {
                if ((flags & 1) == 0) {
                    /* push arg1 off the plane along the normal */
                    f32 push = 0.01f - dist;

                    end[0] = end[0] + (push * nx);
                    end[1] = end[1] + (push * ny);
                    end[2] = end[2] + (push * nz);
                } else {
                    end[0] = contact[0];
                    end[1] = contact[1];
                    end[2] = contact[2];
                }
                *(f32 *)(hit + 0x04) = nx;
                *(f32 *)(hit + 0x08) = ny;
                *(f32 *)(hit + 0x0C) = nz;
                if (ny >= 0.707f) {
                    hit[0x25] |= 2;
                } else if (ny <= -0.866f) {
                    hit[0x25] |= 8;
                } else {
                    hit[0x25] |= 4;
                }
            } else if (ny >= 0.707f) {
                /* floor: solve the plane for end.y */
                end[1] = (-((end[2] * nz) + (nx * end[0]) - pn) / ny) + 0.01f;
                *(f32 *)(hit + 0x04) = nx;
                *(f32 *)(hit + 0x08) = ny;
                *(f32 *)(hit + 0x0C) = nz;
                hit[0x25] |= 2;
            } else if (ny <= -0.866f) {
                /* ceiling: push off the plane */
                f32 push = 0.01f - dist;

                end[0] = end[0] + (push * nx);
                end[1] = end[1] + (push * ny);
                end[2] = end[2] + (push * nz);
                hit[0x25] |= 8;
            } else {
                /* wall: slide end onto the face; the rotation angle picks the xz push length */
                f32 side = -dist;
                f32 px = end[0] + (side * nx);
                f32 py = end[1] + (side * ny);
                f32 pz = end[2] + (side * nz);
                f32 vx = end[0] - px;
                f32 vy = end[1] - py;
                f32 vz = end[2] - pz;
                f32 cosv = Cosf((s32)(s16)Arctanf(vy, sqrtf((vx * vx) + (vz * vz))));

                if (cosv != 0.0f) {
                    f32 scale = (side + 0.01f) / cosv;
                    f32 lenXZ = sqrtf((nx * nx) + (nz * nz));

                    end[0] = end[0] + (scale * (nx / lenXZ));
                    end[2] = end[2] + (scale * (nz / lenXZ));
                } else {
                    end[0] = px;
                    end[1] = py;
                    end[2] = pz;
                }
                hit[0x25] |= 4;
            }

            *(f32 *)(hit + 0x1C) = tEnter * tEnter;
            *(f32 *)(hit + 0x10) = nx;
            *(f32 *)(hit + 0x14) = ny;
            *(f32 *)(hit + 0x18) = nz;
            blk = *(u8 **)(edge + 0x28);
            grp = *(u8 **)(blk + 0x0C) + (*(s16 *)(edge + 0x2C) * 0x10);
            hit[0x24] = (*(u8 **)track)[(grp[0] * 8) + 7];
            *(s32 *)(hit + 0x20) = *(s32 *)(grp + 0x0C);
            hit[0x26] = (u8)*(s16 *)(edge + 0x2E);
            break;
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_800175A0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackCylinderIntersect(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, f32 *arg6) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 nLen;
    f32 nLenSq;
    f32 dist;
    f32 absDist;
    f32 qx;
    f32 qy;
    f32 qz;
    f32 t0;
    f32 mx;
    f32 my;
    f32 mz;
    f32 mLen;
    f32 along;
    f32 half;
    s32 hit;

    dx = arg0[0] - arg2[0];
    dy = arg0[1] - arg2[1];
    dz = arg0[2] - arg2[2];
    /* n = normalize(arg1 x arg3) */
    nx = (arg1[1] * arg3[2]) - (arg3[1] * arg1[2]);
    ny = (arg1[2] * arg3[0]) - (arg3[2] * arg1[0]);
    nz = (arg1[0] * arg3[1]) - (arg3[0] * arg1[1]);
    nLenSq = (nz * nz) + ((nx * nx) + (ny * ny));
    if (nLenSq == 0.0f) {
        return 0;
    }
    nLen = sqrtf(nLenSq);
    nx = nx / nLen;
    ny = ny / nLen;
    nz = nz / nLen;
    dist = (nz * dz) + ((dx * nx) + (dy * ny));
    absDist = (dist < 0.0f) ? -dist : dist;
    hit = 0;
    if (absDist <= arg4) {
        hit = 1;
    }
    if (hit != 0) {
        /* q = (arg0 - arg2) x arg3 */
        qx = (dy * arg3[2]) - (arg3[1] * dz);
        qy = (dz * arg3[0]) - (arg3[2] * dx);
        qz = (dx * arg3[1]) - (arg3[0] * dy);
        t0 = -((nz * qz) + ((qx * nx) + (qy * ny))) / nLen;
        /* m = n x arg3, u = normalize(m) */
        mx = (ny * arg3[2]) - (arg3[1] * nz);
        my = (nz * arg3[0]) - (arg3[2] * nx);
        mz = (nx * arg3[1]) - (arg3[0] * ny);
        mLen = sqrtf((mz * mz) + ((mx * mx) + (my * my)));
        mx = mx / mLen;
        my = my / mLen;
        mz = mz / mLen;
        along = (mz * arg1[2]) + ((arg1[0] * mx) + (arg1[1] * my));
        half = sqrtf((arg4 * arg4) - (absDist * absDist)) / along;
        if (half < 0.0f) {
            half = -half;
        }
        *arg5 = t0 - half;
        *arg6 = t0 + half;
    }
    return hit;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackCylinderIntersect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackSphereIntersect(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 b;
    f32 c;
    f32 disc;
    f32 root;
    s32 hit;

    dx = arg0[0] - arg2[0];
    dy = arg0[1] - arg2[1];
    dz = arg0[2] - arg2[2];
    b = (arg1[2] * dz) + ((dx * arg1[0]) + (dy * arg1[1]));
    disc = b * b;
    c = ((dx * dx) + (dy * dy) + (dz * dz)) - (arg3 * arg3);
    hit = 0;
    if (c <= disc) {
        hit = 1;
    }
    if (hit != 0) {
        root = sqrtf(disc - c);
        *arg4 = -b - root;
        *arg5 = -b + root;
    }
    return hit;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackSphereIntersect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800182C0(void) {
    u8 *base;
    u8 *poly;
    u8 *flags;
    u8 *verts;
    u8 *edge;
    u8 *grp;
    s32 i;
    s32 e;
    s32 listVal;
    s32 polyIdx;
    s32 grpIdx;
    s32 bit;
    s32 nextE;
    u8 *vA;
    u8 *vB;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;

    base = NULL;
    D_800F33B4_B1B94 = 0;
    for (i = 0; i < PLno; i++) {
        listVal = ((s32 *)PLlist)[i];
        if (listVal > 0) {
            base = (u8 *)(listVal | 0x80000000);
            continue;
        }
        polyIdx = ((s16 *)PLpolys)[i];
        grpIdx = ((s16 *)PLgrps)[i];
        poly = *(u8 **)(base + 0x04) + polyIdx * 0x10;
        grp = *(u8 **)(base + 0x0C) + grpIdx * 0x10;
        verts = *(u8 **)(base + 0x00) + *(s16 *)(grp + 0x6) * 0xA;
        flags = *(u8 **)(base + 0x20);
        for (e = 0; e < 3; e++) {
            bit = 1 << e;
            if ((flags[polyIdx] & bit) == 0) {
                continue;
            }
            nextE = e + 1;
            if (nextE >= 3) {
                nextE = 0;
            }
            edge = (u8 *)trackEdges + D_800F33B4_B1B94 * 0x30;
            vA = verts + poly[e + 1] * 0xA;
            vB = verts + poly[nextE + 1] * 0xA;
            *(f32 *)(edge + 0x00) = (f32)*(s16 *)(vA + 0x0);
            *(f32 *)(edge + 0x04) = (f32)*(s16 *)(vA + 0x2);
            *(f32 *)(edge + 0x08) = (f32)*(s16 *)(vA + 0x4);
            *(f32 *)(edge + 0x0C) = (f32)*(s16 *)(vB + 0x0);
            *(f32 *)(edge + 0x10) = (f32)*(s16 *)(vB + 0x2);
            *(f32 *)(edge + 0x14) = (f32)*(s16 *)(vB + 0x4);
            dx = *(f32 *)(edge + 0x0C) - *(f32 *)(edge + 0x00);
            dy = *(f32 *)(edge + 0x10) - *(f32 *)(edge + 0x04);
            dz = *(f32 *)(edge + 0x14) - *(f32 *)(edge + 0x08);
            len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
            *(f32 *)(edge + 0x24) = len;
            if (len <= 0.0f) {
                continue;
            }
            *(u8 **)(edge + 0x28) = base;
            *(f32 *)(edge + 0x18) = dx / len;
            *(f32 *)(edge + 0x1C) = dy / len;
            *(f32 *)(edge + 0x20) = dz / len;
            *(s16 *)(edge + 0x2E) = 0;
            *(s16 *)(edge + 0x2C) = (s16)grpIdx;
            if (poly[0] & (bit * 4)) {
                *(s16 *)(edge + 0x2E) = 1;
            }
            D_800F33B4_B1B94 += 1;
            if (D_800F33B4_B1B94 >= *(s16 *)((u8 *)level + 0xEC)) {
                return;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_800182C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Nearest-hit segment query (start -> end) against the track cube blocks.
// Pass 1: each cube block (track+0x08, 0xC stride, s16 min[3] at +0x00, max[3] at +0x06) is
// clipped against the segment with trackClip3D. Hit blocks (max 0x14) are kept with their xz
// and y compare masks, block pointer (track+0x04, 0x48 stride) and clip entry t, insertion-
// sorted by entry t ascending.
// Pass 2: blocks in that order. Poly (blk+0x0C, 0x10 stride: flags +0x0C, group range
// +0x08..+0x18) groups (blk+0x18, 8 B: u16 plane index + 3 neighbour edge planes, sign bit =
// negated) are tested against the segment's crossing with the plane (blk+0x1C, 0x10 stride).
// The crossing t = dStart / (dStart - dEnd) is kept when inside all three edges and nearer
// than the best so far. The scan stops after the first block that produced a hit.
// mask: poly flags that exclude a poly (also OR'd with 0xCE000880 before use).
// reqMask: when non-zero, polys must carry one of its flags and hitNearestIntersection is skipped.
// out: +0x00 s32 0, +0x04 hit point xyz, +0x10 plane A,B,C,D, +0x20 distance from start,
// +0x24 poly flags, +0x28 surface id (track[0] + poly[0]*8 + 7). Returns 1 on hit.
s32 trackNearestIntersection(s32 hitCtx, f32 *start, f32 *end, void *out, s32 mask, s32 reqMask) {
    s32 xzMaskTab[0x14];
    u8 yMaskTab[0x14];
    f32 tabT[0x14];
    u8 *blkTab[0x14];
    f32 cMin[3];
    f32 cMax[3];
    f32 bestPt[3];
    f32 sx;
    f32 sy;
    f32 sz;
    f32 ex;
    f32 ey;
    f32 ez;
    f32 tEnter;
    f32 tExit;
    f32 tf;
    f32 bestT;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 planeA;
    f32 planeB;
    f32 planeC;
    f32 planeD;
    f32 startD;
    f32 endD;
    f32 t;
    f32 hx;
    f32 hy;
    f32 hz;
    f32 d;
    s16 *cube;
    u8 *blk;
    u8 *poly;
    u8 *polys;
    u8 *groups;
    u8 *planes;
    u8 *plane;
    u8 *ep;
    u8 *hitPlane;
    u8 *tb;
    u8 yMaskCur;
    u8 hitSurf;
    u8 ty;
    u16 *grp;
    u32 *xzMasks;
    u8 *yMasks;
    u32 flags;
    u32 hitFlags;
    u32 xzBits;
    u32 raw;
    s32 xzMaskCur;
    s32 xzTemp;
    s32 numBlocks;
    s32 count;
    s32 b;
    s32 i;
    s32 j;
    s32 g;
    s32 e;
    s32 minX;
    s32 maxX;
    s32 minY;
    s32 maxY;
    s32 minZ;
    s32 maxZ;
    s32 tmp;
    s32 hit;
    s32 polyCount;
    s32 gStart;
    s32 gEnd;
    s32 inside;

    count = 0;
    numBlocks = *(s16 *)((u8 *)track + 0x1A);
    for (b = 0; b < numBlocks; b++) {
        cube = (s16 *)(*(u8 **)((u8 *)track + 0x08) + b * 0xC);
        sx = start[0];
        sy = start[1];
        sz = start[2];
        ex = end[0];
        ey = end[1];
        ez = end[2];
        cMin[0] = (f32)cube[0];
        cMin[1] = (f32)cube[1];
        cMin[2] = (f32)cube[2];
        cMax[0] = (f32)cube[3];
        cMax[1] = (f32)cube[4];
        cMax[2] = (f32)cube[5];

        if (trackClip3D(&sx, &sy, &sz, &ex, &ey, &ez, cMin, cMax, &tEnter, &tExit) == 0) {
            continue;
        }

        /* clipped endpoints truncated to ints; box of the clipped segment */
        minX = (s32)sx;
        maxX = (s32)ex;
        if (maxX < minX) {
            tmp = minX;
            minX = maxX;
            maxX = tmp;
        }
        minY = (s32)sy;
        maxY = (s32)ey;
        if (maxY < minY) {
            tmp = minY;
            minY = maxY;
            maxY = tmp;
        }
        minZ = (s32)sz;
        maxZ = (s32)ez;
        if (maxZ < minZ) {
            tmp = minZ;
            minZ = maxZ;
            maxZ = tmp;
        }

        xzMaskTab[count] = getXZCompareMask((s32)cube, minX, minZ, maxX, maxZ);
        yMaskTab[count] = getYCompareMask((s32)cube, minY, maxY);
        tabT[count] = tEnter;
        blkTab[count] = *(u8 **)((u8 *)track + 0x04) + b * 0x48;

        /* insertion of the new entry (index count) into the list sorted by t ascending */
        for (j = count; j > 0 && tabT[j] < tabT[j - 1]; j--) {
            tf = tabT[j];
            tabT[j] = tabT[j - 1];
            tabT[j - 1] = tf;

            xzTemp = xzMaskTab[j];
            xzMaskTab[j] = xzMaskTab[j - 1];
            xzMaskTab[j - 1] = xzTemp;

            tb = blkTab[j];
            blkTab[j] = blkTab[j - 1];
            blkTab[j - 1] = tb;

            ty = yMaskTab[j];
            yMaskTab[j] = yMaskTab[j - 1];
            yMaskTab[j - 1] = ty;
        }

        count++;
        if (count >= 0x14) {
            break;
        }
    }

    dx = end[0] - start[0];
    dy = end[1] - start[1];
    dz = end[2] - start[2];
    hit = 0;
    bestT = 1.0f;
    bestPt[0] = end[0];
    bestPt[1] = end[1];
    bestPt[2] = end[2];
    mask |= 0xCE000880;

    for (i = 0; i < count; i++) {
        blk = blkTab[i];
        yMaskCur = yMaskTab[i];
        xzMaskCur = xzMaskTab[i];
        polyCount = *(s16 *)(blk + 0x28);
        polys = *(u8 **)(blk + 0x0C);
        xzMasks = *(u32 **)(blk + 0x10);
        yMasks = *(u8 **)(blk + 0x14);
        groups = *(u8 **)(blk + 0x18);
        planes = *(u8 **)(blk + 0x1C);

        for (j = 0; j < polyCount; j++) {
            poly = polys + j * 0x10;
            flags = *(u32 *)(poly + 0x0C);
            gStart = *(s16 *)(poly + 0x08);
            gEnd = *(s16 *)(poly + 0x18);

            if ((flags & mask) != 0 || (reqMask != 0 && (flags & reqMask) == 0)) {
                gStart = gEnd;
            }

            for (g = gStart; g < gEnd; g++) {
                xzBits = xzMasks[g] & xzMaskCur;
                if ((xzBits & 0xFFFF) == 0 || (xzBits & 0xFFFF0000) == 0 ||
                    (yMasks[g] & yMaskCur & 0xFF) == 0) {
                    continue;
                }

                grp = (u16 *)(groups + g * 8);
                plane = planes + grp[0] * 0x10;
                planeA = *(f32 *)(plane + 0x00);
                planeB = *(f32 *)(plane + 0x04);
                planeC = *(f32 *)(plane + 0x08);
                planeD = *(f32 *)(plane + 0x0C);

                endD = planeA * end[0] + planeB * end[1] + planeC * end[2] + planeD;
                if (endD < 0.0f) {
                    startD = planeA * start[0] + planeB * start[1] + planeC * start[2] + planeD;
                    if (startD >= 0.0f) {
                        t = startD / (startD - endD);
                        hx = start[0] + dx * t;
                        hy = start[1] + dy * t;
                        hz = start[2] + dz * t;

                        /* hit point must lie on the inner side of the three edge planes */
                        inside = 1;
                        for (e = 1; e < 4 && inside; e++) {
                            raw = grp[e];
                            ep = planes + (raw & 0x7FFF) * 0x10;
                            d = *(f32 *)(ep + 0x00) * hx + *(f32 *)(ep + 0x04) * hy +
                                *(f32 *)(ep + 0x08) * hz + *(f32 *)(ep + 0x0C);
                            if ((raw & 0x8000) != 0) {
                                d = -d;
                            }
                            if (d > 0.0f) {
                                inside = 0;
                            }
                        }

                        if (inside != 0 && t < bestT) {
                            bestT = t;
                            bestPt[0] = hx;
                            bestPt[1] = hy;
                            bestPt[2] = hz;
                            hitSurf = *(u8 *)(*(u8 **)track + poly[0] * 8 + 7);
                            hitFlags = flags;
                            hitPlane = plane;
                            hit = 1;
                        }
                    }
                }
            }
        }

        if (hit != 0) {
            break;
        }
    }

    if (reqMask == 0 && hitNearestIntersection(hitCtx, start, bestPt, out, mask) != 0) {
        return 1;
    }

    if (hit != 0) {
        *(s32 *)((u8 *)out + 0x00) = 0;
        *(f32 *)((u8 *)out + 0x04) = bestPt[0];
        *(f32 *)((u8 *)out + 0x08) = bestPt[1];
        *(f32 *)((u8 *)out + 0x0C) = bestPt[2];
        *(f32 *)((u8 *)out + 0x10) = *(f32 *)(hitPlane + 0x00);
        *(f32 *)((u8 *)out + 0x14) = *(f32 *)(hitPlane + 0x04);
        *(f32 *)((u8 *)out + 0x18) = *(f32 *)(hitPlane + 0x08);
        *(f32 *)((u8 *)out + 0x1C) = *(f32 *)(hitPlane + 0x0C);
        dx *= bestT;
        dy *= bestT;
        dz *= bestT;
        *(f32 *)((u8 *)out + 0x20) = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
        *(u32 *)((u8 *)out + 0x24) = hitFlags;
        *(s32 *)((u8 *)out + 0x28) = hitSurf;
    } else {
        *(f32 *)((u8 *)out + 0x20) = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    }
    return hit;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackNearestIntersection.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackClip3D(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5,
                f32 *arg6, f32 *arg7, f32 *arg8, f32 *arg9) {
    f32 dx = *arg3 - *arg0;
    f32 dy = *arg4 - *arg1;
    f32 dz = *arg5 - *arg2;
    f32 tEnter = 0.0f;
    f32 tExit = 1.0f;
    s32 hit = 0;
    s32 inside = (arg6[0] <= *arg0) && (*arg0 <= arg7[0]) && (arg6[1] <= *arg1) && (*arg1 <= arg7[1]) &&
                 (arg6[2] <= *arg2) && (*arg2 <= arg7[2]);

    if (dx == 0.0f && dy == 0.0f && dz == 0.0f && inside) {
        *arg8 = 0.0f;
        *arg9 = 0.0f;
        return 1;
    }

    if (func_80019324(dx, arg6[0] - *arg0, &tEnter, &tExit) != 0 &&
        func_80019324(-dx, *arg0 - arg7[0], &tEnter, &tExit) != 0 &&
        func_80019324(dy, arg6[1] - *arg1, &tEnter, &tExit) != 0 &&
        func_80019324(-dy, *arg1 - arg7[1], &tEnter, &tExit) != 0 &&
        func_80019324(dz, arg6[2] - *arg2, &tEnter, &tExit) != 0 &&
        func_80019324(-dz, *arg2 - arg7[2], &tEnter, &tExit) != 0) {
        hit = 1;
        if (tExit < 1.0f) {
            *arg3 = *arg0 + (tExit * dx);
            *arg4 = *arg1 + (tExit * dy);
            *arg5 = *arg2 + (tExit * dz);
        }
        *arg9 = tExit;
        if (tEnter > 0.0f) {
            *arg0 += tEnter * dx;
            *arg1 += tEnter * dy;
            *arg2 += tEnter * dz;
        }
        *arg8 = tEnter;
    }
    return hit;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackClip3D.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80019324(f32 p, f32 q, f32 *tEnter, f32 *tExit) {
    f32 t;
    s32 ret;

    ret = 1;
    if (p > 0.0f) {
        t = q / p;
        if (*tExit < t) {
            return 0;
        }
        if (*tEnter < t) {
            *tEnter = t;
        }
    } else if (p < 0.0f) {
        t = q / p;
        if (t < *tEnter) {
            return 0;
        }
        if (t < *tExit) {
            *tExit = t;
        }
    } else if (q > 0.0f) {
        return 0;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_80019324.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackPolyHeight(f32 arg0, f32 arg1, f32 *arg2, s32 arg3) {
    s16 blockList[32];
    s32 x = (s32)arg0;
    s32 z = (s32)arg1;
    s32 numBlocks;
    s32 b;

    numBlocks = trackGetBlockList(x, z, blockList);
    *arg2 = -32768.0f;
    for (b = 0; b < numBlocks; b++) {
        s32 blockIdx = blockList[b];
        u8 *blk = *(u8 **)((u8 *)track + 0x04) + blockIdx * 0x48;
        u32 xzMask = (u32)getXZCompareMask((s32)(*(u8 **)((u8 *)track + 0x08) + blockIdx * 0xC), x, z, x, z);
        u8 *polys = *(u8 **)(blk + 0x0C);
        s32 polyCount = *(s16 *)(blk + 0x28);
        s32 p;

        for (p = 0; p < polyCount; p++) {
            u8 *poly = polys + p * 0x10;
            u32 flags = *(u32 *)(poly + 0x0C);

            if (flags & arg3) {
                u8 *verts = *(u8 **)(blk + 0x00) + *(s16 *)(poly + 0x06) * 0xA;
                u8 *tris = *(u8 **)(blk + 0x04);
                u32 *masks = *(u32 **)(blk + 0x10);
                s32 tStart = *(s16 *)(poly + 0x08);
                s32 tEnd = *(s16 *)(poly + 0x18);
                s32 t;

                for (t = tStart; t < tEnd; t++) {
                    u32 m = masks[t] & xzMask;

                    if ((m >> 16) != 0 && (m & 0xFFFF)) {
                        u8 *tri = tris + t * 0x10;

                        if (mathXZInTri(x, z, verts + tri[1] * 0xA, verts + tri[2] * 0xA, verts + tri[3] * 0xA)) {
                            *arg2 = (f32)*(s16 *)(verts + tri[1] * 0xA + 2);
                            return (s32)flags;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackPolyHeight.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Walks the PL edge list; for each boundary edge of a triangle, tests whether the
// segment a->b crosses the vertical wall through that edge (wall normal = up x E,
// up = (0,10,0)), and whether the crossing point lies within the edge.
// On a hit: out[0..2] = edge start vertex, out[3..5] = edge end vertex,
// out[6] = edge parameter s, out[7] (0x1C) = wall plane record. Returns sign of N.D (+1/-1), or 0.
s32 trackGetLedgeCrossed(f32 *a, f32 *b, f32 *out) {
    f32 dx = b[0] - a[0];
    f32 dy = b[1] - a[1];
    f32 dz = b[2] - a[2];
    s32 result = 0;
    u8 *blk = NULL; // asm: first poly-list entry read from an uninitialised stack slot if PLlist[0] <= 0
    s32 i;

    for (i = 0; i < PLno; i++) {
        s32 entry = ((s32 *)PLlist)[i];

        if (entry > 0) {
            blk = (u8 *)((u32)entry | 0x80000000);
        } else {
            s32 polyIdx = ((s16 *)PLpolys)[i];
            s32 grpIdx = ((s16 *)PLgrps)[i];
            u8 *tri = *(u8 **)(blk + 0x04) + polyIdx * 0x10;
            u8 *grp = *(u8 **)(blk + 0x0C) + grpIdx * 0x10;
            u8 *verts = *(u8 **)(blk + 0x00) + *(s16 *)(grp + 0x06) * 0xA;
            u8 edgeFlags = (*(u8 **)(blk + 0x20))[polyIdx];
            u32 edgeBits = (edgeFlags >> 3) & 0xFF;
            s32 e;

            if (edgeBits & 7) {
                for (e = 0; e < 3; e++) {
                    if (edgeBits & (1 << e)) {
                        s32 e1 = (e + 1) % 3;
                        u8 *va = verts + tri[1 + e] * 0xA;
                        u8 *vb = verts + tri[1 + e1] * 0xA;
                        f32 x0 = (f32)*(s16 *)(va + 0);
                        f32 y0 = (f32)*(s16 *)(va + 2);
                        f32 z0 = (f32)*(s16 *)(va + 4);
                        f32 x1 = (f32)*(s16 *)(vb + 0);
                        f32 y1 = (f32)*(s16 *)(vb + 2);
                        f32 z1 = (f32)*(s16 *)(vb + 4);
                        f32 ex = x1 - x0;
                        f32 ey = y1 - y0;
                        f32 ez = z1 - z0;
                        // wall normal N = up x E with up = (0, 10, 0): (10*ez, 0, -10*ex)
                        f32 nx = 10.0f * ez;
                        f32 ny = 0.0f;
                        f32 nz = -(ex * 10.0f);
                        f32 denom = (nz * dz) + ((dx * nx) + (dy * ny));

                        if (denom != 0.0f) {
                            s32 sign = (denom < 0.0f) ? -1 : 1;
                            f32 cx = nx * (x0 - a[0]);
                            f32 cy = ny * (y0 - a[1]);
                            f32 cz = nz * (z0 - a[2]);
                            f32 t = (cz + (cx + cy)) / denom;

                            if (t >= 0.0f && t <= 1.0f) {
                                f32 ix = (dx * t) + a[0];
                                f32 iy = (dy * t) + a[1];
                                f32 iz = (dz * t) + a[2];
                                f32 edgeLen2 = (ez * ez) + ((ex * ex) + (ey * ey));
                                f32 dotE = (ez * (iz - z0)) + ((ex * (ix - x0)) + (ey * (iy - y0)));
                                f32 s = dotE / edgeLen2;

                                if (s >= 0.0f && s <= 1.0f) {
                                    u8 *planeRec;

                                    result = sign;
                                    out[0] = x0;
                                    out[1] = y0;
                                    out[2] = z0;
                                    out[3] = x1;
                                    out[4] = y1;
                                    out[5] = z1;
                                    out[6] = s;
                                    planeRec = *(u8 **)(blk + 0x1C) + (*(u16 *)(*(u8 **)(blk + 0x18) + polyIdx * 8)) * 0x10;
                                    *(u8 **)((u8 *)out + 0x1C) = planeRec;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (result != 0) {
            break;
        }
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetLedgeCrossed.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 trackGetAdjacentLedge(f32 *arg0, f32 *arg1) {
    u8 *blk = NULL;
    s32 found = 0;
    s32 i;
    s32 e;

    for (i = 0; i < PLno; i++) {
        s32 entry = ((s32 *)PLlist)[i];

        if (entry > 0) {
            blk = (u8 *)((u32)entry | 0x80000000);
        } else {
            s32 polyIdx = ((s16 *)PLpolys)[i];
            s32 grpIdx = ((s16 *)PLgrps)[i];
            u8 *tris = *(u8 **)(blk + 0x04) + polyIdx * 0x10;
            u8 *grp = *(u8 **)(blk + 0x0C) + grpIdx * 0x10;
            u8 *verts = *(u8 **)(blk + 0x00) + *(s16 *)(grp + 0x06) * 0xA;
            u32 edgeBits = ((*(u8 **)(blk + 0x20))[polyIdx] >> 3) & 0xFF;

            if (edgeBits & 7) {
                for (e = 0; e < 3; e++) {
                    if (edgeBits & (1 << e)) {
                        u8 *va = verts + tris[e * 0x10 + 1] * 0xA;
                        u8 *vb = verts + tris[((e + 1) % 3) * 0x10 + 1] * 0xA;

                        if (arg0[6] < 0.5f) {
                            if ((s32)arg0[0] == *(s16 *)(vb + 0) && (s32)arg0[1] == *(s16 *)(vb + 2) &&
                                (s32)arg0[2] == *(s16 *)(vb + 4)) {
                                found = 1;
                                arg1[0] = (f32)*(s16 *)(va + 0);
                                arg1[1] = (f32)*(s16 *)(va + 2);
                                arg1[2] = (f32)*(s16 *)(va + 4);
                                arg1[3] = (f32)*(s16 *)(vb + 0);
                                arg1[4] = (f32)*(s16 *)(vb + 2);
                                arg1[5] = (f32)*(s16 *)(vb + 4);
                            }
                        } else {
                            if ((s32)arg0[3] == *(s16 *)(va + 0) && (s32)arg0[4] == *(s16 *)(va + 2) &&
                                (s32)arg0[5] == *(s16 *)(va + 4)) {
                                found = 1;
                                arg1[0] = (f32)*(s16 *)(va + 0);
                                arg1[1] = (f32)*(s16 *)(va + 2);
                                arg1[2] = (f32)*(s16 *)(va + 4);
                                arg1[3] = (f32)*(s16 *)(vb + 0);
                                arg1[4] = (f32)*(s16 *)(vb + 2);
                                arg1[5] = (f32)*(s16 *)(vb + 4);
                            }
                        }
                    }
                }
            }
        }
        if (found) {
            break;
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetAdjacentLedge.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Cylinder variant of trackGetHeights (same 0x14-byte record / 0x14 cap / bubble-sort shape).
// Walks the cube block list around (x,z) +/- radius and gathers the wall planes whose
// triangle contains (x,z), or whose triangle edge lies within radius of (x,z). negSide picks
// the plane side (0: planeB > 0, else planeB < 0) and the triangle winding used for the test.
// Records (0x14 B in D_800F2FE8_B17C8): +0x00 f32 height at (x,z), +0x04 A, +0x08 B, +0x0C C,
// +0x10 u32 poly flags, +0x13 s8 surface id (2 when poly flags & 0x2000).
// With outList: every hit is recorded (capped at 0x14), sorted by height descending, and the
// f32 pointer table D_800F3178_B1958 is returned via *outList. With outList NULL: returns 1 at
// the first hit whose height lies in [yMin, yMax], else 0.
s32 trackCylinderHeights(f32 x, f32 z, f32 yMin, f32 yMax, f32 radius, s32 mask, s32 negSide, f32 ***outList) {
    s32 blockList[8];
    f32 radiusSq;
    s32 ix;
    s32 iz;
    s32 r;
    s16 minX;
    s16 minY;
    s16 minZ;
    s16 maxX;
    s16 maxY;
    s16 maxZ;
    s32 blockCount;
    s32 count;
    s32 b;
    s32 p;
    s32 g;
    s32 polyCount;
    s32 xzMask;
    s32 rem;
    s32 i;
    s32 j;
    s32 last;
    s32 swapped;
    void *tmp;

    if (outList != NULL) {
        *outList = NULL;
    }
    ix = (s32)x;
    iz = (s32)z;
    r = (s32)radius;
    minX = (s16)(ix - r);
    minY = (s16)(s32)yMin;
    minZ = (s16)(iz - r);
    maxX = (s16)(ix + r);
    maxY = (s16)(s32)yMax;
    maxZ = (s16)(iz + r);
    radiusSq = radius * radius;

    blockCount = trackGetCubeBlockList(blockList, minX, minY, minZ, maxX, maxY, maxZ);
    if (blockCount == 0 || blockCount >= 8) {
        return 0;
    }

    count = 0;
    for (b = 0; b < blockCount; b++) {
        u8 *blk = *(u8 **)((u8 *)track + 0x04) + blockList[b] * 0x48;
        u8 *polys = *(u8 **)(blk + 0x0C);
        u32 *xzMasks = *(u32 **)(blk + 0x10);

        xzMask = getXZCompareMask((s32)(*(u8 **)((u8 *)track + 0x08) + blockList[b] * 0xC), minX, minZ, maxX, maxZ);
        polyCount = *(s16 *)(blk + 0x28);

        for (p = 0; p < polyCount; p++) {
            u8 *poly = polys + p * 0x10;
            u32 flags = *(u32 *)(poly + 0x0C);
            s32 vBase = *(s16 *)(poly + 0x06);
            s32 gStart = *(s16 *)(poly + 0x08);
            s32 gEnd = *(s16 *)(poly + 0x18);
            s8 surf;

            if (flags & 0x2000) {
                surf = 2;
            } else {
                surf = *(u8 *)(*(u8 **)track + poly[0] * 8 + 7);
            }
            if (flags & mask) {
                gStart = gEnd;
            }

            for (g = gStart; g < gEnd; g++) {
                u32 xzBits = xzMasks[g] & xzMask;
                u16 planeIdx = *(u16 *)(*(u8 **)(blk + 0x18) + g * 8);
                u8 *plane = *(u8 **)(blk + 0x1C) + planeIdx * 0x10;
                f32 planeB = *(f32 *)(plane + 0x04);

                if ((xzBits >> 16) != 0 && (xzBits & 0xFFFF) != 0 &&
                    ((negSide == 0 && planeB > 0.0f) || (negSide != 0 && planeB < 0.0f))) {
                    u8 *tri = *(u8 **)(blk + 0x04) + g * 0x10;
                    u8 *verts = *(u8 **)blk;
                    u8 *p0 = verts + (tri[1] + vBase) * 0xA;
                    u8 *p1 = verts + (tri[2] + vBase) * 0xA;
                    u8 *p2 = verts + (tri[3] + vBase) * 0xA;
                    s32 y0 = *(s16 *)(p0 + 2);
                    s32 y1 = *(s16 *)(p1 + 2);
                    s32 y2 = *(s16 *)(p2 + 2);

                    /* skip only when all three vertices are below minY or all above maxY */
                    if (!((y0 < minY && y1 < minY && y2 < minY) || (y0 > maxY && y1 > maxY && y2 > maxY))) {
                        f32 planeA = *(f32 *)(plane + 0x00);
                        f32 planeC = *(f32 *)(plane + 0x08);
                        f32 planeD = *(f32 *)(plane + 0x0C);
                        f32 p0x = (f32)*(s16 *)(p0 + 0);
                        f32 p0z = (f32)*(s16 *)(p0 + 4);
                        f32 p1x = (f32)*(s16 *)(p1 + 0);
                        f32 p1z = (f32)*(s16 *)(p1 + 4);
                        f32 p2x = (f32)*(s16 *)(p2 + 0);
                        f32 p2z = (f32)*(s16 *)(p2 + 4);
                        s32 hit;

                        if (negSide == 0) {
                            hit = mathXZInTri(ix, iz, p0, p1, p2);
                        } else {
                            hit = mathXZInTri(ix, iz, p2, p1, p0);
                        }
                        if (hit == 0) {
                            hit = func_8001A990(x, z, p0x, p0z, p1x, p1z, radiusSq) != 0 ||
                                  func_8001A990(x, z, p1x, p1z, p2x, p2z, radiusSq) != 0 ||
                                  func_8001A990(x, z, p2x, p2z, p0x, p0z, radiusSq) != 0;
                        }

                        if (hit) {
                            if (outList != NULL) {
                                u8 *rec = D_800F2FE8_B17C8 + count * 0x14;

                                *(f32 *)(rec + 0x00) = -(((planeA * x) + (planeC * z) + planeD) / planeB);
                                *(f32 *)(rec + 0x04) = planeA;
                                *(f32 *)(rec + 0x08) = planeB;
                                *(f32 *)(rec + 0x0C) = planeC;
                                *(u32 *)(rec + 0x10) = flags;
                                *(s8 *)(rec + 0x13) = surf;
                                count++;
                                if (count >= 0x14) {
                                    goto done;
                                }
                            } else {
                                f32 h = -(((planeA * x) + (planeC * z) + planeD) / planeB);

                                if (yMin <= h && h <= yMax) {
                                    count = 1;
                                    goto done;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

done:
    if (outList != NULL) {
        if (count > 0) {
            /* pointer table: 4 at a time after the (count & 3) remainder, as in the asm */
            rem = count & 3;
            for (i = 0; i != rem; i++) {
                D_800F3178_B1958[i] = D_800F2FE8_B17C8 + i * 0x14;
            }
            for (; i != count; i += 4) {
                u8 *rec = D_800F2FE8_B17C8 + i * 0x14;

                D_800F3178_B1958[i] = rec;
                D_800F3178_B1958[i + 1] = rec + 0x14;
                D_800F3178_B1958[i + 2] = rec + 0x28;
                D_800F3178_B1958[i + 3] = rec + 0x3C;
            }

            /* bubble sort, heights descending; each pass covers all count-1 pairs */
            last = count - 1;
            do {
                swapped = 1;
                for (j = 0; j < last; j++) {
                    if (*(f32 *)D_800F3178_B1958[j] < *(f32 *)D_800F3178_B1958[j + 1]) {
                        tmp = D_800F3178_B1958[j];
                        D_800F3178_B1958[j] = D_800F3178_B1958[j + 1];
                        D_800F3178_B1958[j + 1] = tmp;
                        swapped = 0;
                    }
                }
            } while (swapped == 0);
        }
        *outList = (f32 **)D_800F3178_B1958;
    }
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackCylinderHeights.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8001A990(f32 px, f32 pz, f32 ax, f32 az, f32 bx, f32 bz, f32 radiusSq) {
    f32 dx = bx - ax;
    f32 dz = bz - az;
    f32 lenSq = (dx * dx) + (dz * dz);
    f32 t;
    f32 ex;
    f32 ez;

    if (lenSq > 0.0f) {
        t = (((px - ax) * dx) + ((pz - az) * dz)) / lenSq;
        if (t >= 0.0f && t <= 1.0f) {
            ex = px - ((t * dx) + ax);
            ez = pz - ((t * dz) + az);
            if (((ex * ex) + (ez * ez)) <= radiusSq) {
                return 1;
            }
        }
    }
    ex = px - ax;
    ez = pz - az;
    if (((ex * ex) + (ez * ez)) <= radiusSq) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001A990.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Finds the triangle under (x,z) inside the block containing (x,y,z) (xz/y masks and
// the mask arg5 filter) whose wall-plane height at (x,z) is closest to y.
// Returns the triangle record; *outY = plane height, *outPlane = plane record.
void *trackGetNearestPoly(f32 x, f32 y, f32 z, f32 *outY, void **outPlane, s32 mask) {
    s32 blockIdx;
    s32 ix;
    s32 iy;
    s32 iz;
    s32 xzMask;
    u8 yMask;
    u8 *blk;
    u8 *polys;
    s32 polyCount;
    s32 p;
    f32 bestDist = 32768.0f;
    void *best = NULL;

    blockIdx = trackGetBlock(x, y, z);
    if (blockIdx < 0) {
        return NULL;
    }
    ix = (s32)x;
    iy = (s32)y;
    iz = (s32)z;
    xzMask = getXZCompareMask((s32)(*(u8 **)((u8 *)track + 0x08) + blockIdx * 0xC), ix, iz, ix, iz);
    yMask = getYCompareMask((s32)(*(u8 **)((u8 *)track + 0x08) + blockIdx * 0xC), iy, iy);

    blk = *(u8 **)((u8 *)track + 0x04) + blockIdx * 0x48;
    polys = *(u8 **)(blk + 0x0C);
    polyCount = *(s16 *)(blk + 0x28);

    for (p = 0; p < polyCount; p++) {
        u8 *poly = polys + p * 0x10;

        if ((*(u32 *)(poly + 0x0C) & mask) == 0) {
            u8 *verts = *(u8 **)(blk + 0x00) + *(s16 *)(poly + 0x06) * 0xA;
            u8 *tris = *(u8 **)(blk + 0x04);
            u32 *xzMasks = *(u32 **)(blk + 0x10);
            u8 *yMasks = *(u8 **)(blk + 0x14);
            s32 groupEnd = *(s16 *)(poly + 0x18);
            s32 g;

            for (g = *(s16 *)(poly + 0x08); g < groupEnd; g++) {
                u32 xzBits = xzMasks[g] & xzMask;
                u8 yBits = yMasks[g] & yMask;

                if ((xzBits & 0xFFFF) != 0 && (xzBits >> 16) != 0 && (yBits & 0xFF) != 0) {
                    u8 *tri = tris + g * 0x10;

                    if (mathXZInTri(ix, iz, verts + tri[1] * 0xA, verts + tri[2] * 0xA, verts + tri[3] * 0xA) != 0) {
                        u8 *plane = *(u8 **)(blk + 0x1C) + (*(u16 *)(*(u8 **)(blk + 0x18) + g * 8)) * 0x10;
                        f32 planeA = *(f32 *)(plane + 0x0);
                        f32 planeB = *(f32 *)(plane + 0x4);
                        f32 planeC = *(f32 *)(plane + 0x8);
                        f32 planeD = *(f32 *)(plane + 0xC);

                        if (planeB != 0.0f) {
                            f32 planeY = -(((planeA * x) + (planeC * z) + planeD) / planeB);
                            f32 dist = y - planeY;

                            if (y < planeY) {
                                dist = -dist;
                            }
                            if (dist < bestDist) {
                                bestDist = dist;
                                if (outY != NULL) {
                                    *outY = planeY;
                                }
                                if (outPlane != NULL) {
                                    *outPlane = plane;
                                }
                                best = tri;
                            }
                        }
                    }
                }
            }
        }
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetNearestPoly.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Gathers the wall planes under (x,z) from the blocks returned by trackGetBlockList.
// Layout as in trackGetNearestPoly (block +0x00 verts, +0x04 tris, +0x0C polys,
// +0x10 xz masks, +0x14 y masks (unused here), +0x18 groups (u16 plane idx at g*8),
// +0x1C planes (16 B: A,B,C,D), +0x28 poly count).
// Each hit is a 0x14-byte record in D_800F2FE8_B17C8:
//   +0x00 f32 height at (x,z) = -(A*x + C*z + D) / B, +0x04 A, +0x08 B, +0x0C C,
//   +0x10 u32 poly flags, +0x13 s8 surface id (2 when poly flags & 0x2000).
// Records are capped at 0x14 and sorted by height (descending) through pointers in
// D_800F3178_B1958, which is returned via *outList. Returns the record count.
s32 trackGetHeights(f32 x, f32 z, s32 mask, void **outList) {
    s16 blockList[0x20];
    void *tmp;
    u8 *blk;
    u8 *polys;
    u32 *xzMasks;
    s32 ix;
    s32 iz;
    s32 blockCount;
    s32 n;
    s32 b;
    s32 p;
    s32 g;
    s32 i;
    s32 j;
    s32 rem;
    s32 last;
    s32 swapped;
    s32 xzMask;
    s32 polyCount;

    ix = (s32)x;
    iz = (s32)z;
    *outList = NULL;
    blockCount = trackGetBlockList(ix, iz, blockList);
    if (blockCount == 0 || blockCount >= 0x20) {
        return 0;
    }

    n = 0;
    for (b = 0; b < blockCount; b++) {
        blk = *(u8 **)((u8 *)track + 0x04) + blockList[b] * 0x48;
        xzMask = getXZCompareMask((s32)(*(u8 **)((u8 *)track + 0x08) + blockList[b] * 0xC), ix, iz, ix, iz);
        polys = *(u8 **)(blk + 0x0C);
        polyCount = *(s16 *)(blk + 0x28);
        xzMasks = *(u32 **)(blk + 0x10);

        for (p = 0; p < polyCount; p++) {
            u8 *poly = polys + p * 0x10;
            u32 flags = *(u32 *)(poly + 0x0C);
            s32 gStart = *(s16 *)(poly + 0x08);
            s32 gEnd = *(s16 *)(poly + 0x18);
            s8 surf;
            s32 vBase = *(s16 *)(poly + 0x06);

            if (flags & 0x2000) {
                surf = 2;
            } else {
                surf = *(s8 *)(*(u8 **)track + poly[0] * 8 + 7);
            }
            if (flags & mask) {
                gStart = gEnd;
            }

            for (g = gStart; g < gEnd; g++) {
                u32 xzBits = xzMasks[g] & xzMask;
                u16 planeIdx = *(u16 *)(*(u8 **)(blk + 0x18) + g * 8);
                u8 *plane = *(u8 **)(blk + 0x1C) + planeIdx * 0x10;
                f32 planeB = *(f32 *)(plane + 0x04);

                if ((xzBits >> 16) != 0 && (xzBits & 0xFFFF) != 0 && planeB > 0.0f) {
                    u8 *tri = *(u8 **)(blk + 0x04) + g * 0x10;
                    u8 *verts = *(u8 **)blk;

                    if (mathXZInTri(ix, iz,
                                    verts + (tri[1] + vBase) * 0xA,
                                    verts + (tri[2] + vBase) * 0xA,
                                    verts + (tri[3] + vBase) * 0xA) != 0) {
                        f32 planeA = *(f32 *)(plane + 0x00);
                        f32 planeC = *(f32 *)(plane + 0x08);
                        f32 planeD = *(f32 *)(plane + 0x0C);
                        u8 *rec = D_800F2FE8_B17C8 + n * 0x14;

                        *(f32 *)(rec + 0x00) = -(((planeA * x) + (planeC * z) + planeD) / planeB);
                        *(f32 *)(rec + 0x04) = planeA;
                        *(f32 *)(rec + 0x08) = planeB;
                        *(f32 *)(rec + 0x0C) = planeC;
                        *(u32 *)(rec + 0x10) = flags;
                        *(s8 *)(rec + 0x13) = surf;
                        n++;
                        if (n >= 0x14) {
                            goto done;
                        }
                    }
                }
            }
        }
    }

done:
    if (n > 0) {
        /* pointer table: 4 at a time after the (n & 3) remainder, as in the asm */
        rem = n & 3;
        for (i = 0; i != rem; i++) {
            D_800F3178_B1958[i] = D_800F2FE8_B17C8 + i * 0x14;
        }
        for (; i != n; i += 4) {
            u8 *rec = D_800F2FE8_B17C8 + i * 0x14;

            D_800F3178_B1958[i] = rec;
            D_800F3178_B1958[i + 1] = rec + 0x14;
            D_800F3178_B1958[i + 2] = rec + 0x28;
            D_800F3178_B1958[i + 3] = rec + 0x3C;
        }

        /* bubble sort, heights descending; each pass covers all n-1 pairs */
        last = n - 1;
        do {
            swapped = 1;
            if (last > 0) {
                rem = last & 3;
                for (j = 0; j != rem; j++) {
                    if (*(f32 *)D_800F3178_B1958[j] < *(f32 *)D_800F3178_B1958[j + 1]) {
                        tmp = D_800F3178_B1958[j];
                        D_800F3178_B1958[j] = D_800F3178_B1958[j + 1];
                        D_800F3178_B1958[j + 1] = tmp;
                        swapped = 0;
                    }
                }
                for (; j != last; j += 4) {
                    if (*(f32 *)D_800F3178_B1958[j] < *(f32 *)D_800F3178_B1958[j + 1]) {
                        tmp = D_800F3178_B1958[j];
                        D_800F3178_B1958[j] = D_800F3178_B1958[j + 1];
                        D_800F3178_B1958[j + 1] = tmp;
                        swapped = 0;
                    }
                    if (*(f32 *)D_800F3178_B1958[j + 1] < *(f32 *)D_800F3178_B1958[j + 2]) {
                        tmp = D_800F3178_B1958[j + 1];
                        D_800F3178_B1958[j + 1] = D_800F3178_B1958[j + 2];
                        D_800F3178_B1958[j + 2] = tmp;
                        swapped = 0;
                    }
                    if (*(f32 *)D_800F3178_B1958[j + 2] < *(f32 *)D_800F3178_B1958[j + 3]) {
                        tmp = D_800F3178_B1958[j + 2];
                        D_800F3178_B1958[j + 2] = D_800F3178_B1958[j + 3];
                        D_800F3178_B1958[j + 3] = tmp;
                        swapped = 0;
                    }
                    if (*(f32 *)D_800F3178_B1958[j + 3] < *(f32 *)D_800F3178_B1958[j + 4]) {
                        tmp = D_800F3178_B1958[j + 3];
                        D_800F3178_B1958[j + 3] = D_800F3178_B1958[j + 4];
                        D_800F3178_B1958[j + 4] = tmp;
                        swapped = 0;
                    }
                }
            }
        } while (swapped == 0);
    }

    *outList = D_800F3178_B1958;
    return n;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetHeights.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *trackGetTrack(void) {
    return track;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackGetTrack.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackFreeAll(void) {
    s32 i;
    s32 count;

    trackLightFreeMem();
    if (exceptionList != NULL) {
        mmFree(exceptionList);
        exceptionList = NULL;
        numexceptions = 0;
    }
    controlFreePlayersStuff();
    if (watereffecttexture != NULL) {
        texFreeTexture(watereffecttexture);
        watereffecttexture = NULL;
    }

    count = *(s16 *)((u8 *)track + 0x1A);
    for (i = 0; i < count; i++) {
        u8 *block = *(u8 **)((u8 *)track + 0x04) + i * 0x48;

        if (*(void **)(block + 0x34) != NULL) {
            mmFree(*(void **)(block + 0x34));
        }
    }

    count = *(s16 *)((u8 *)track + 0x18);
    for (i = 0; i < count; i++) {
        texFreeTexture(*(void **)(*(u8 **)((u8 *)track + 0x00) + i * 8));
    }

    mmFree(TrackMem);
    mmFree((void *)PLlist);
    mmFree((void *)PLgrps);
    mmFree((void *)PLpolys);
    if (mantisLightingGetFog(D_80000308) != 0) {
        mmFree((void *)trackEdges);
    }
    shadowFreeBuffers();
    if (D_800F2F88_B1768 != NULL) {
        objFreeObject(D_800F2F88_B1768);
        objDoFrees();
    }
    animseqFreeLevelData();
    objFreeAll();
    track = NULL;
    if (generalBuffer != NULL) {
        mmFree(generalBuffer);
        generalBuffer = NULL;
    }
    beamScrollFlag = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackFreeAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackMakeAbsolute(s32 *arg0, s32 arg1) {
    s32 *node = arg0;

    while (node != NULL) {
        if (node[1] != 0) {
            node[1] += arg1;
        }
        if (node[2] != 0) {
            node[2] += arg1;
        }
        trackMakeAbsolute((void *)node[1], arg1);
        node = (s32 *)node[2];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackMakeAbsolute.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// arg0 (object): u8 +0x39 = intensity, scales the prim alpha of the shadow.
// arg1 (draw header): u8 +0x0C buffer select, u16 +0x08 texture param (<<8),
//   u8 +0x0F entry count, s16 start[] at +0x10 and s16 end[] at +0x16 (both stride 2).
// Texture records are 8 B, vertex records 10 B (see jfg-re docs/technical-notes.md).
void func_8001B6D8(void *arg0, void *arg1) {
    s32 bufVtx;
    s32 bufTc;
    s32 bufTex;
    s32 count;
    s32 entry;
    s32 idx;
    s32 end;
    s32 i;
    s32 fade;
    s32 dS;
    s32 dT;
    s32 uOff;
    s32 vOff;
    u32 addr;
    u8 bufSel;
    u8 *rec;
    u8 *vtx;
    Gfx *gfx;

    bufSel = *(u8 *)((u8 *)arg1 + 0xC);
    if (bufSel != 0) {
        shadowGetBuffers(bufSel, &bufVtx, &bufTc, &bufTex);
        count = *(u8 *)((u8 *)arg1 + 0xF);
        for (entry = 0; entry < count; entry++) {
            idx = *(s16 *)((u8 *)arg1 + 0x10 + entry * 2);
            if (idx != -1) {
                rec = (u8 *)(bufTex + idx * 8);
                vtx = (u8 *)(bufVtx + *(s16 *)(rec + 6) * 10);
                fade = ((s32)*(u8 *)((u8 *)arg0 + 0x39) * vtx[9]) >> 8;
                if (fade > 0) {
                    gfx = D_800F2F70_B1750;
                    D_800F2F70_B1750 = gfx + 1;
                    gfx->words.w1 = fade & 0xFF;
                    gfx->words.w0 = 0xFA000000;
                    end = *(s16 *)((u8 *)arg1 + 0x16 + entry * 2);
                    for (i = idx; i < end; i++) {
                        rec = (u8 *)(bufTex + i * 8);
                        texDPTextureX(&D_800F2F70_B1750, *(void **)rec, 0xE,
                                      *(u16 *)((u8 *)arg1 + 0x8) << 8);
                        vOff = *(s16 *)(rec + 6);
                        uOff = *(s16 *)(rec + 4);
                        dS = *(s16 *)(rec + 0xE) - vOff;
                        dT = *(s16 *)(rec + 0xC) - uOff;

                        addr = (u32)(bufVtx + vOff * 10) + 0x80000000U;
                        gfx = D_800F2F70_B1750;
                        D_800F2F70_B1750 = gfx + 1;
                        gfx->words.w1 = addr;
                        gfx->words.w0 = ((((dS * 8) | (addr & 6)) & 0xFF) << 16) | 0x04000000
                                        | (((dS * 10) + 8) & 0xFFFF);

                        gfx = D_800F2F70_B1750;
                        D_800F2F70_B1750 = gfx + 1;
                        gfx->words.w1 = (u32)(bufTc + uOff * 16) + 0x80000000U;
                        gfx->words.w0 = (((((dT - 1) * 16) | 1) & 0xFF) << 16) | 0x05000000
                                        | ((dT * 16) & 0xFFFF);
                    }
                    gfx = D_800F2F70_B1750;
                    D_800F2F70_B1750 = gfx + 1;
                    gfx->words.w1 = -1;
                    gfx->words.w0 = 0xFA000000;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001B6D8.s")
#endif

// In this struct, data is rightshifted 16 bytes, so make the smooth transition more precise.
typedef struct EnvironmentFog {
    /* 0x00 */ s32 r;
    /* 0x04 */ s32 g;
    /* 0x08 */ s32 b;
    /* 0x0C */ s32 near;
    /* 0x10 */ s32 far;
} EnvironmentFog;

typedef struct EnvironmentFogCompact {
    /* 0x30 */ u8 r;
    /* 0x31 */ u8 g;
    /* 0x32 */ u8 b;
    /* 0x33 */ s8 unk33;
    /* 0x34 */ s16 near;
    /* 0x36 */ s16 far;
} EnvironmentFogCompact;

/* Size: 0x40 bytes */
typedef struct FogData {
    EnvironmentFog fog; // Current fog properties. What you'll actually see ingame.
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x20 */ EnvironmentFog
        addFog; // Fog override. This will apply over the current fog to give a smooth transition effect.
    EnvironmentFogCompact intendedFog; // Fog properties the game will try to be if the switch timer is 0.
    /* 0x38 */ s32 switchTimer;
    /* 0x3C */ Object *fogChanger;
} FogData;
extern FogData D_800F3D20[4];

void trackSetFog(s32 fogIdx, s16 near, s16 far, s16 arg3, u8 red, u8 green, u8 blue, s8 arg7) {
    s32 tempNear;
    FogData *fogData;

    fogData = &D_800F3D20[fogIdx];

    if (far < near) {
        tempNear = near;
        near = far;
        far = tempNear;
    }

    if (far > 1023) {
        far = 1023;
    }
    if (near >= far - 5) {
        near = far - 5;
    }

    fogData->addFog.near = 0;
    fogData->addFog.far = 0;
    fogData->addFog.r = 0;
    fogData->addFog.g = 0;
    fogData->addFog.b = 0;
    fogData->fog.r = red << 16;
    fogData->fog.g = green << 16;
    fogData->fog.b = blue << 16;
    fogData->fog.near = near << 16;
    fogData->fog.far = far << 16;
    fogData->unk14 = near << 16;
    fogData->unk18 = arg3 << 16;
    fogData->intendedFog.unk33 = arg7;
    fogData->intendedFog.near = near;
    fogData->intendedFog.far = far;
    fogData->switchTimer = 0;
    fogData->fogChanger = NULL;
    fogData->intendedFog.r = red;
    fogData->intendedFog.g = green;
    fogData->intendedFog.b = blue;
}

void trackGetFog(s32 playerID, s16 *near, s16 *far, s16 *unk18, u8 *r, u8 *g, u8 *b, s8 *unk33) {
    FogData *fogData;

    if (runlinkIsModuleLoaded(39) != 0) {
        TrapDanglingJump(near, far, r, g, b);
        *unk18 = 0;
        *unk33 = 0;
    } else if (runlinkIsModuleLoaded(23) != 0) {
        TrapDanglingJump(near, far, r, g, b);
        *unk18 = 0;
        *unk33 = 0;
    } else {
        fogData = &D_800F3D20[playerID];
        *near = fogData->fog.near >> 16;
        *far = fogData->fog.far >> 16;
        *unk18 = fogData->unk18 >> 16;
        *r = fogData->fog.r >> 16;
        *g = fogData->fog.g >> 16;
        *b = fogData->fog.b >> 16;
        *unk33 = fogData->intendedFog.unk33 & 0x7F;
    }
    if (runlinkIsModuleLoaded(29) != 0) {
        TrapDanglingJump(r, g, b, near, far, unk33);
    }
}

void trackSetFogOff(s32 playerID) {
    D_800F3D20[playerID].addFog.near = 0;
    D_800F3D20[playerID].addFog.far = 0;
    D_800F3D20[playerID].addFog.r = 0;
    D_800F3D20[playerID].addFog.g = 0;
    D_800F3D20[playerID].addFog.b = 0;
    D_800F3D20[playerID].fog.near = 1018 << 16;
    D_800F3D20[playerID].fog.far = 1023 << 16;
    D_800F3D20[playerID].intendedFog.r = D_800F3D20[playerID].fog.r >> 16;
    D_800F3D20[playerID].intendedFog.g = D_800F3D20[playerID].fog.g >> 16;
    D_800F3D20[playerID].intendedFog.b = D_800F3D20[playerID].fog.b >> 16;
    D_800F3D20[playerID].intendedFog.near = 1018;
    D_800F3D20[playerID].intendedFog.far = 1023;
    D_800F3D20[playerID].switchTimer = 0;
    D_800F3D20[playerID].fogChanger = NULL;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8001BBFC(s32 arg0, s32 arg1) {
    FogData *fogData;
    s32 i;

    for (i = 0; i < arg0; i++) {
        s8 dir;

        fogData = &D_800F3D20[i];
        dir = fogData->intendedFog.unk33;

        if (dir > 0) {
            s32 limit = fogData->unk18;
            s32 near = fogData->fog.near + ((arg1 * (dir & 0x7F)) << 0xB);

            fogData->fog.near = near;
            if (limit < near) {
                fogData->fog.near = (limit - near) + limit;
                fogData->intendedFog.unk33 = dir | 0x80;
            }
        } else if (dir < 0) {
            s32 limit = fogData->unk14;
            s32 near = fogData->fog.near - ((arg1 * (dir & 0x7F)) << 0xB);

            fogData->fog.near = near;
            if (near < limit) {
                fogData->fog.near = (limit - near) + limit;
                fogData->intendedFog.unk33 = dir ^ 0x80;
            }
        } else {
            s32 timer = fogData->switchTimer;

            if (timer > 0) {
                if (arg1 < timer) {
                    fogData->fog.r += fogData->addFog.r * arg1;
                    fogData->fog.g += fogData->addFog.g * arg1;
                    fogData->fog.b += fogData->addFog.b * arg1;
                    fogData->switchTimer -= arg1;
                    fogData->fog.near += fogData->addFog.near * arg1;
                    fogData->fog.far += fogData->addFog.far * arg1;
                } else {
                    fogData->fog.r = fogData->intendedFog.r << 0x10;
                    fogData->fog.g = fogData->intendedFog.g << 0x10;
                    fogData->fog.b = fogData->intendedFog.b << 0x10;
                    fogData->fog.near = fogData->intendedFog.near << 0x10;
                    fogData->fog.far = fogData->intendedFog.far << 0x10;
                    fogData->switchTimer = 0;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001BBFC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8001BD94(s32 arg0) {
    s16 fogNear;
    s16 fogFar;
    s16 unk18;
    u8 r;
    u8 g;
    u8 b;
    s8 unk33;
    s32 diff;
    Gfx *dl;

    trackGetFog(arg0, &fogNear, &fogFar, &unk18, &r, &g, &b, &unk33);

    dl = D_800F2F70_B1750;
    D_800F2F70_B1750 = dl + 1;
    dl->words.w0 = 0xF8000000;
    dl->words.w1 = ((u32)r << 24) | ((u32)g << 16) | ((u32)b << 8) | 0xFF;

    dl = D_800F2F70_B1750;
    D_800F2F70_B1750 = dl + 1;
    dl->words.w0 = 0xBC000008;
    diff = fogFar - fogNear;
    dl->words.w1 = (((0x1F400 / diff) & 0xFFFF) << 16) | ((((fogNear * -0x100) + 0x1F400) / diff) & 0xFFFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001BD94.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackChangeFog(Object *arg0) {
    s32 playerCount;
    void **players;
    void *fogParams;
    FogData *fogData;
    s32 i;
    s32 fogIdx;
    f32 px;
    f32 pz;
    s32 near;
    s32 far;
    s32 limit;
    s32 switchTime;

    fogParams = *(void **)((u8 *)arg0 + 0x3C);
    players = (void **) objGetPlayerlist(&playerCount);
    for (i = 0; i < playerCount; i++) {
        fogIdx = -1;
        px = 0.0f;
        pz = 0.0f;
        if (players != NULL) {
            Object *player = (Object *) players[i];
            s8 racerIdx = *(s8 *)player->racer;
            if (racerIdx >= 0 && racerIdx < 4 && arg0 != D_800F3D20[racerIdx].fogChanger) {
                px = player->segment.trans.x_position;
                pz = player->segment.trans.z_position;
                fogIdx = racerIdx;
            }
        } else if (i < 4 && arg0 != D_800F3D20[i].fogChanger) {
            /* asm reads a 0x4C-stride table with no base symbol here */
            fogIdx = i;
            px = *(f32 *)(u32)(i * 0x4C + 0xC);
            pz = *(f32 *)(u32)(i * 0x4C + 0x14);
        }

        if (fogIdx != -1) {
            px -= arg0->segment.trans.x_position;
            pz -= arg0->segment.trans.z_position;
            if (((px * px) + (pz * pz)) < *(f32 *)((u8 *)arg0 + 0x88)) {
                near = *(s16 *)((u8 *)fogParams + 0x0E);
                far = *(s16 *)((u8 *)fogParams + 0x10);
                switchTime = *(s16 *)((u8 *)fogParams + 0x12);
                if (far < near) {
                    s32 tmp = near;
                    near = far;
                    far = tmp;
                }
                limit = far - 5;
                if (far >= 0x400) {
                    far = 0x3FF;
                    limit = 0x3FA;
                }
                if (near >= limit) {
                    near = limit;
                }

                fogData = &D_800F3D20[fogIdx];
                fogData->intendedFog.r = *((u8 *)fogParams + 0x0B);
                fogData->intendedFog.g = *((u8 *)fogParams + 0x0C);
                fogData->intendedFog.b = *((u8 *)fogParams + 0x0D);
                fogData->intendedFog.near = near;
                fogData->intendedFog.far = far;
                fogData->switchTimer = switchTime;
                fogData->fogChanger = arg0;
                fogData->addFog.r = (((s32) fogData->intendedFog.r << 16) - fogData->fog.r) / switchTime;
                fogData->addFog.g = (((s32) fogData->intendedFog.g << 16) - fogData->fog.g) / switchTime;
                fogData->addFog.b = (((s32) fogData->intendedFog.b << 16) - fogData->fog.b) / switchTime;
                fogData->addFog.near = (((s32) near << 16) - fogData->fog.near) / switchTime;
                fogData->addFog.far = (((s32) far << 16) - fogData->fog.far) / switchTime;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/trackChangeFog.s")
#endif

void trackFadeFog(s32 fogIdx, s32 red, s32 green, s32 blue, s32 near, s32 far, f32 timer) {
    s32 temp;
    s32 switchTimer;
    FogData *fogData;

    fogData = &D_800F3D20[fogIdx];

    if (osTvType == OS_TV_TYPE_PAL) {
        switchTimer = (timer * 50.0f);
    } else {
        switchTimer = (timer * 60.0f);
    }

    if (far < near) {
        temp = near;
        near = far;
        far = temp;
    }

    if (far > 1023) {
        far = 1023;
    }
    if (near >= far - 5) {
        near = far - 5;
    }

    fogData->intendedFog.r = red;
    fogData->intendedFog.g = green;
    fogData->intendedFog.b = blue;
    fogData->intendedFog.near = near;
    fogData->intendedFog.far = far;

    if (switchTimer > 0) {
        fogData->switchTimer = switchTimer;
        fogData->addFog.r = ((red << 16) - fogData->fog.r) / switchTimer;
        fogData->addFog.g = ((green << 16) - fogData->fog.g) / switchTimer;
        fogData->addFog.b = ((blue << 16) - fogData->fog.b) / switchTimer;
        fogData->addFog.near = ((near << 16) - fogData->fog.near) / switchTimer;
        fogData->addFog.far = ((far << 16) - fogData->fog.far) / switchTimer;
    } else {
        fogData->switchTimer = 0;
        fogData->fog.r = red << 16;
        fogData->fog.g = green << 16;
        fogData->fog.b = blue << 16;
        fogData->fog.near = near << 16;
        fogData->fog.far = far << 16;
    }
    fogData->fogChanger = NULL;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8001C448(void) {
    f32 mtx[4][4];
    f32 vx;
    f32 vy;
    f32 vz;
    s16 rot[3];

    vx = 0.0f;
    vy = 0.0f;
    vz = -65536.0f;
    rot[0] = *(s16 *)((u8 *)D_800F2F80_B1760 + 0x0);
    rot[1] = *(s16 *)((u8 *)D_800F2F80_B1760 + 0x2);
    rot[2] = *(s16 *)((u8 *)D_800F2F80_B1760 + 0x4);
    matrix_RPY_XYZ(rot, mtx);
    mathMtxXFMF(mtx, vx, vy, vz, &vx, &vy, &vz);
    D_800F3360_B1B40[0] = (s32) vx;
    D_800F3360_B1B40[1] = (s32) vy;
    D_800F3360_B1B40[2] = (s32) vz;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001C448.s")
#endif

// Returns the index of the highest set bit, or -1 for 0.
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8001C550(u32 arg0) {
    s32 n = -1;
    s32 t;

    if (arg0 != 0) {
        do {
            t = arg0 >> 1;
            n += 1;
            arg0 = t;
        } while (t != 0);
    }
    return n;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001C550.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
static Gfx *trackGfxNext(void) {
    Gfx *dl = D_800F2F70_B1750;
    D_800F2F70_B1750 = dl + 1;
    return dl;
}

void func_8001C570(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    TextureHeader *hdr = (TextureHeader *) arg0;
    TextureHeader *tex;
    Gfx *dl;
    u32 frameWord;
    u32 frameAddr;
    s32 shiftS;
    s32 shiftT;
    s32 logW;
    s32 logH;
    s32 waterFx;
    s32 frameArg;
    s32 frameIdx;
    s32 tileWord2;
    s32 tileWord;
    s32 shiftTileA;
    s32 shiftTileB;
    s32 count;
    s32 tint;

    frameWord = texFrame(arg0, arg1);
    if (*((u8 *)arg0 + 0x1B) >= 2) {
        dl = trackGfxNext();
        dl->words.w0 = hdr->cmd->words.w0;
        dl->words.w1 = frameWord;
        dl = trackGfxNext();
        dl->words.w0 = 0x06000000;
        dl->words.w1 = (u32) ((u8 *) hdr->cmd + 8);
        dl = trackGfxNext();
        dl->words.w0 = 0x06000000;
        dl->words.w1 = (u32) D_800A0E48_A1A48;
        return;
    }

    shiftS = func_8001C550(hdr->width);
    tex = (TextureHeader *) watereffecttexture;
    shiftT = func_8001C550(hdr->height);
    if (tex != NULL) {
        frameArg = watereffectframe;
        waterFx = 1;
    } else {
        tex = hdr;
        frameIdx = (arg1 >> 8) + 0x100;
        if (frameIdx >= (s32) hdr->numOfTextures) {
            frameIdx = frameIdx - hdr->numOfTextures;
        }
        frameArg = frameIdx << 8;
        waterFx = 0;
    }
    frameAddr = texFrame(tex, frameArg);
    logW = func_8001C550(tex->width);
    logH = func_8001C550(tex->height);

    dl = trackGfxNext();
    dl->words.w0 = 0xFD700000;
    dl->words.w1 = frameAddr;

    tileWord = ((logH & 0xF) << 14);
    shiftTileA = (shiftT - logH) & 0xF;
    shiftTileB = (logW & 0xF) * 0x10;
    tileWord2 = (shiftT & 0xF) << 14;

    dl = trackGfxNext();
    dl->words.w0 = 0xF5700100;
    dl->words.w1 = tileWord | 0x07000000 | ((shiftTileA & 0xF) << 10) | shiftTileB | (((shiftS - logW) & 0xF));

    dl = trackGfxNext();
    dl->words.w1 = 0;
    dl->words.w0 = 0xE6000000;

    dl = trackGfxNext();
    dl->words.w0 = 0xF3000000;
    count = ((((s32) (tex->width * tex->height) + 1) >> 1) - 1);
    if (count >= 0x7FF) {
        count = 0x7FF;
    }
    dl->words.w1 = ((count & 0xFFF) << 12) | 0x07000000;

    dl = trackGfxNext();
    dl->words.w1 = 0;
    dl->words.w0 = 0xE7000000;

    dl = trackGfxNext();
    dl->words.w0 = ((((s32) (tex->width + 7) >> 3) & 0x1FF) << 9) | 0xF5680000 | 0x100;
    dl->words.w1 = tileWord | 0x01000000 | ((shiftTileA & 0xF) << 10) | shiftTileB | ((shiftS - logW) & 0xF);

    dl = trackGfxNext();
    dl->words.w0 = 0xF2000000;
    dl->words.w1 = ((((tex->width - 1) * 4) & 0xFFF) << 12) | 0x01000000 | (((tex->height - 1) * 4) & 0xFFF);

    if (waterFx) {
        dl = trackGfxNext();
        dl->words.w0 = 0xFD100000;
        dl->words.w1 = frameWord;

        dl = trackGfxNext();
        dl->words.w0 = 0xF5100000;
        dl->words.w1 = tileWord2 | 0x07000000 | ((shiftS & 0xF) * 0x10);

        dl = trackGfxNext();
        dl->words.w1 = 0;
        dl->words.w0 = 0xE6000000;

        dl = trackGfxNext();
        dl->words.w0 = 0xF3000000;
        count = (hdr->width * hdr->height) - 1;
        if (count >= 0x7FF) {
            count = 0x7FF;
        }
        dl->words.w1 = ((count & 0xFFF) << 12) | 0x07000000;

        dl = trackGfxNext();
        dl->words.w1 = 0;
        dl->words.w0 = 0xE7000000;

        dl = trackGfxNext();
        dl->words.w1 = tileWord2 | ((shiftS & 0xF) * 0x10);
        dl->words.w0 = ((((s32) ((hdr->width * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;

        dl = trackGfxNext();
        dl->words.w0 = 0xF2000000;
        dl->words.w1 = ((((hdr->width - 1) * 4) & 0xFFF) << 12) | (((hdr->height - 1) * 4) & 0xFFF);

        dl = trackGfxNext();
        dl->words.w1 = (u32) D_800A0DC8_A19C8;
        dl->words.w0 = 0x06000000;
        return;
    }

    dl = trackGfxNext();
    dl->words.w0 = 0xFD700000;
    dl->words.w1 = frameWord;

    dl = trackGfxNext();
    dl->words.w0 = 0xF5700000;
    dl->words.w1 = tileWord2 | 0x07000000 | ((shiftS & 0xF) * 0x10);

    dl = trackGfxNext();
    dl->words.w1 = 0;
    dl->words.w0 = 0xE6000000;

    dl = trackGfxNext();
    dl->words.w0 = 0xF3000000;
    count = ((((s32) (hdr->width * hdr->height) + 1) >> 1) - 1);
    if (count >= 0x7FF) {
        count = 0x7FF;
    }
    dl->words.w1 = ((count & 0xFFF) << 12) | 0x07000000;

    dl = trackGfxNext();
    dl->words.w1 = 0;
    dl->words.w0 = 0xE7000000;

    dl = trackGfxNext();
    dl->words.w1 = tileWord2 | ((shiftS & 0xF) * 0x10);
    dl->words.w0 = ((((s32) (hdr->width + 7) >> 3) & 0x1FF) << 9) | 0xF5680000;

    dl = trackGfxNext();
    dl->words.w0 = 0xF2000000;
    dl->words.w1 = ((((hdr->width - 1) * 4) & 0xFFF) << 12) | (((hdr->height - 1) * 4) & 0xFFF);

    dl = trackGfxNext();
    dl->words.w0 = 0x06000000;
    if ((arg2 & 0x70) == 0x10) {
        dl->words.w1 = (u32) D_800A0E18_A1A18;
    } else {
        dl->words.w1 = (u32) D_800A0DF0_A19F0;
    }

    tint = (arg1 >> 8) & 0xFF;
    dl = trackGfxNext();
    dl->words.w0 = 0xFB000000;
    dl->words.w1 = (tint << 24) | (tint << 16) | (tint << 8) | tint;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/track/func_8001C570.s")
#endif
