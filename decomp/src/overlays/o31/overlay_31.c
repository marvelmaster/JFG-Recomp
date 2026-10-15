#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void fontPrintXY(Gfx **displayList, s32 xpos, s32 ypos, char *text, s32 alignmentFlags);
f32 Sinf(s16 angle);
void **objGetObjList(s32 *, s32 *, s32 *, s32 *);
void **objGetPlayerlist(s32 *);
void *objGetPlayerNo(s32);
s32 sprintCountdown();
void amSndPlay(u16 soundID, void *handlePtr);
void amDittyPlay(s32 id);
void amTunePlay(s32 id);
void amTuneSetFade(s32 volume, s32 time);
void amTuneSetFadeScaled(f32 scale, s32 time);
void mainChangeCameras(s32 arg0);
void mainFrontInit(s32 arg0, s32 arg1, s32 arg2);
s32 mainGetGameFlag(s32 flag);
void mainPauseDisable(s32 arg0);
void mainSaveGlobalFlags(void);
void func_overlay_31_01F021F0_1F4CE40(s32 arg0);
void func_overlay_31_01F0242C_1F4D07C(s32 arg0, s32 arg1);
void func_overlay_31_01F01150_1F4BDA0(s32 arg0, s32 arg1);
f32 racecheckDistance(void *obj, f32 x, f32 y, f32 z);

extern s32 D_overlay_31_01F040DC;
extern s32 D_overlay_31_01F040E0;
extern s32 D_overlay_31_01F040E4;
extern s32 D_overlay_31_01F040E8;
extern s32 D_overlay_31_01F040EC;
extern s32 D_overlay_31_01F040F0;
extern s32 D_overlay_31_01F040F4;
extern s32 D_overlay_31_01F040F8;
extern void *D_overlay_31_01F04488[];
extern void *D_overlay_31_01F04888[];
extern f32 D_overlay_31_01F04458;
extern f32 D_overlay_31_01F0445C;
extern f32 D_overlay_31_01F04460;
extern f32 D_overlay_31_01F04464;
extern f32 D_overlay_31_01F04468;
extern f32 D_overlay_31_01F0446C;
extern s32 D_overlay_31_01F04480;
extern s32 D_overlay_31_01F04484;
extern s32 D_overlay_31_01F04908[];
extern u8 D_overlay_31_01F04918[];
extern u8 D_overlay_31_01F04936;
extern u8 multiPlayer[];
extern s32 currentGameTime;
extern u16 gameoverFade;
extern u8 multiFinished;
extern s8 raceGameLaps;
extern s8 raceGameSingleScreen;
extern s8 raceGameStartBoost;
extern s8 raceGameTime;
extern s8 raceGameType;
extern u8 raceGameIDNumber;
extern u8 racingCharacter;
extern s16 racingReturnLevel;
extern u8 racingReturnSetup;
extern u8 racingInGame;
extern u8 numberOfAI;

void *objSetupObject(s16 *, s32, ...);
void amSndPlayXYZ(s32 soundID, f32 x, f32 y, f32 z, s32 arg4, void *handlePtr);
void amSndStopXYZ(s32 handle);
s32 trackGetHeights(f32 x, f32 z, s32 arg2, s32 *heights);
void texFreeTexture(void *texture);
void mainRefreshMultiPlayer(void);
s32 func_overlay_31_01F038E0_1F4E530(s32 arg0, void *arg1, s32 arg2, s32 *arg3);
void func_overlay_31_01F026B8_1F4D308(Gfx **arg0, s32 arg1);
void func_overlay_31_01F029FC_1F4D64C(Gfx **arg0, void *arg1);
void frontDrawRectangle(Gfx **displayList, s32 x, s32 y, s32 w, s32 h, s32 alpha);
void frontDrawRectangles(Gfx **displayList, s32 count, void *rects, s32 arg3);
void drawGlowingText(Gfx **displayList, s32 xpos, s32 ypos, char *text, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
void fontUseFont(s32 font);
void fontBackground(s32 r, s32 g, s32 b, s32 a);
void fxDrawDigitalNumber(s32 xpos, s32 ypos, s32 value, s32 digits, s32 arg4);
void fxScreenEffect(Gfx **displayList, s32 *buffer, s32 w, s32 h, s32 a, s32 b, s32 c, s32 d, s32 colour);
void rcpTileWrite(Gfx **displayList, void *texture, s32 x, s32 y, s32 r, s32 g, s32 b, s32 a);
void rcpTileWriteX(Gfx **displayList, void *texture, f32 x, f32 y, f32 sx, f32 sy, s32 colour, s32 arg7);
s32 frontGet2PlayerSplit(void);
extern TextureHeader *D_overlay_31_01F03F78;
extern TextureHeader *D_overlay_31_01F03F90;
extern TextureHeader *D_overlay_31_01F03FB4;
extern TextureHeader *D_overlay_31_01F03FCC;
extern TextureHeader *D_overlay_31_01F03FE4;
extern TextureHeader *D_overlay_31_01F03FFC;
extern TextureHeader *D_overlay_31_01F04014;
extern TextureHeader *D_overlay_31_01F0402C;
extern TextureHeader *D_overlay_31_01F04044;
extern void *D_overlay_31_01F03DF8[];
extern s16 D_overlay_31_01F03ED8[];
extern u8 D_overlay_31_01F03E18[];
extern s16 *D_overlay_31_01F03F48[];
extern s16 *D_overlay_31_01F03F70[];
extern void *D_overlay_31_01F0405C[];
extern void *D_overlay_31_01F04068[];
extern char *D_overlay_31_01F04078[];
extern char *D_overlay_31_01F04098[];
extern void *D_overlay_31_01F040A8[];
extern s16 D_overlay_31_01F040FC[];
extern s32 D_overlay_31_01F04108[];
extern u8 D_overlay_31_01F04158[];
extern u8 D_overlay_31_01F04248[];
extern f32 D_overlay_31_01F04470;
extern s32 D_overlay_31_01F04920;
extern u8 D_overlay_31_01F04930;
extern u8 D_overlay_31_01F04931;
extern s32 D_overlay_31_01F0490C;
extern s32 D_overlay_31_01F04910;
extern s32 D_overlay_31_01F04914;
extern char D_overlay_31_01F043D0[];
extern char D_overlay_31_01F043E8[];
extern char D_overlay_31_01F04400[];
extern char D_overlay_31_01F04414[];
extern char D_overlay_31_01F04420[];
extern char D_overlay_31_01F04428[];
extern char D_overlay_31_01F04434[];
extern char D_overlay_31_01F0443C[];
extern char D_overlay_31_01F04444[];
extern char D_overlay_31_01F04450[];
extern s32 D_800FEDE0[];
extern u32 D_800FF32C;
extern u32 D_800FF340;
extern u32 D_800FF354;
extern u32 D_800FF368;
extern u8 D_800FF382;
extern void *front_text;
extern s8 D_800FED62;
extern u8 D_800FED6B;
extern s8 D_800FEE02;
extern u8 D_800FEE0B;
extern s8 D_800FEEA2;
extern u8 D_800FEEAB;
extern s8 D_800FEF42;
extern u8 D_800FEF4B;
extern s16 D_800FF1BA;
extern s16 D_800FF1BC;
extern s16 D_800FF1BE;
extern u8 numberOfPlayers;
extern s8 raceGamePickups;
extern s8 raceGameStoredLaps;
extern s8 raceGameStoredPickups;
extern s8 raceGameStoredStartBoost;
extern s8 raceGameStoredType;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 sprintAIPlayer(s32 arg0) {
    s32 ret = 0;
    if (arg0 >= 0 && arg0 < 4) {
        if (D_overlay_31_01F04918[(arg0 * 0x28) + 0x15] != 0) {
            ret = 1;
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintAIPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void drawGlowingText(Gfx **displayList, s32 xpos, s32 ypos, char *text, s32 alignmentFlags, s32 red, s32 green, s32 blue, s32 alpha, s32 glowPhase) {
    s32 glow;
    s32 glowAmount;

    if (glowPhase != 0) {
        if (glowPhase >= 0x100) {
            fontColour(red, green, blue, 0xFF, alpha);
        } else if (glowPhase < 0x80) {
            fontColour(red, green, blue, 0xFF, (alpha * (glowPhase * 2)) >> 8);
        } else {
            if (glowPhase < 0xC0) {
                glow = (glowPhase - 0x80) * 4;
            } else {
                glow = (0x100 - glowPhase) * 4;
            }
            glowAmount = (alpha * glow) >> 8;
            fontColour(0xFF, 0xFF, 0xFF, 0xFF, glowAmount);
            fontPrintXY(displayList, xpos - 1, ypos, text, alignmentFlags);
            fontPrintXY(displayList, xpos, ypos + 1, text, alignmentFlags);
            fontPrintXY(displayList, xpos + 1, ypos, text, alignmentFlags);
            fontPrintXY(displayList, xpos, ypos - 1, text, alignmentFlags);
            fontColour((((0xFF - red) * glow) >> 8) + red,
                       (((0xFF - green) * glow) >> 8) + green,
                       (((0xFF - blue) * glow) >> 8) + blue,
                       0xFF, glowAmount);
        }
        fontPrintXY(displayList, xpos, ypos, text, alignmentFlags);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/drawGlowingText.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void racecheckRefresh(void) {
    s32 objStart;
    s32 objEnd;
    void **objList;
    void *obj;
    u8 *extra;
    s32 i;
    s32 count;

    for (i = 0; i < 0x100; i++) {
        D_overlay_31_01F04488[i] = NULL;
    }
    D_overlay_31_01F040DC = 0;
    D_overlay_31_01F040E0 = 0;
    D_overlay_31_01F040E4 = -1;
    D_overlay_31_01F040E8 = 0;
    objList = objGetObjList(&objStart, &objEnd, &D_overlay_31_01F040DC, &D_overlay_31_01F040E0);
    count = objEnd - objStart;
    for (i = 0; i < count; i++) {
        obj = objList[objStart + i];
        if (*(s16 *)((u8 *)obj + 0x48) == 0x79) {
            extra = *(u8 **)((u8 *)obj + 0x68);
            D_overlay_31_01F04488[extra[0]] = obj;
            D_overlay_31_01F040DC += 1;
        } else if (*(s16 *)((u8 *)obj + 0x4A) == 0x274) {
            D_overlay_31_01F04888[D_overlay_31_01F040E0] = obj;
            D_overlay_31_01F040E0 += 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racecheckRefresh.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void racecheckInit(void *arg0, void *arg1) {
    u8 *extra;
    s16 yaw;
    f32 sinYaw;
    f32 cosYaw;
    f32 posX;
    f32 posZ;
    f32 span;

    *(f32 *)((u8 *)arg0 + 0x08) = (f32)*(u8 *)((u8 *)arg1 + 0x0D) * D_overlay_31_01F04458;
    *(s16 *)((u8 *)arg0 + 0x02) = 0;
    *(s16 *)((u8 *)arg0 + 0x00) = (s16)(*(u16 *)((u8 *)arg1 + 0x0C) << 0xA);
    *(s16 *)((u8 *)arg0 + 0x04) = 0;

    extra = *(u8 **)((u8 *)arg0 + 0x68);
    extra[0] = *(u8 *)((u8 *)arg1 + 0x0A);
    extra[1] = *(u8 *)((u8 *)arg1 + 0x12);
    extra[2] = *(u8 *)((u8 *)arg1 + 0x13);
    *(f32 *)(extra + 0x08) = (f32)*(u8 *)((u8 *)arg1 + 0x0B) * D_overlay_31_01F0445C;

    span = (f32)(*(u8 *)((u8 *)arg1 + 0x0D) * 4);
    *(f32 *)(extra + 0x0C) = span * span;

    yaw = *(s16 *)((u8 *)arg0 + 0x00);
    sinYaw = Sinf(yaw);
    cosYaw = Cosf(yaw);
    posX = *(f32 *)((u8 *)arg0 + 0x0C);
    posZ = *(f32 *)((u8 *)arg0 + 0x14);

    *(f32 *)(extra + 0x10) = sinYaw;
    *(f32 *)(extra + 0x14) = 0.0f;
    *(f32 *)(extra + 0x18) = cosYaw;
    *(f32 *)(extra + 0x1C) = -((sinYaw * posX) + (cosYaw * posZ));

    span = (f32)(*(u8 *)((u8 *)arg1 + 0x0E) * 8);
    *(f32 *)(extra + 0x20) = posX + (span * cosYaw);
    *(f32 *)(extra + 0x24) = posZ - (span * sinYaw);

    span = (f32)(*(u8 *)((u8 *)arg1 + 0x0F) * 8);
    *(f32 *)(extra + 0x28) = posX + (span * cosYaw);
    *(f32 *)(extra + 0x2C) = posZ - (span * sinYaw);

    span = (f32)(*(u8 *)((u8 *)arg1 + 0x10) * 8);
    *(f32 *)(extra + 0x30) = posX + (span * cosYaw);
    *(f32 *)(extra + 0x34) = posZ - (span * sinYaw);

    span = (f32)(*(u8 *)((u8 *)arg1 + 0x11) * 8);
    *(f32 *)(extra + 0x38) = posX + (span * cosYaw);
    *(f32 *)(extra + 0x3C) = posZ - (span * sinYaw);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racecheckInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *racecheckFindNearest(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    s32 n;
    f32 bestDist;
    void *best;
    void *node;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 cmp;
    void **slot;

    bestDist = D_overlay_31_01F04460;
    best = NULL;
    slot = D_overlay_31_01F04488;
    n = 0xFF;
    do {
        node = *slot;
        slot++;
        if (node != NULL) {
            dx = *(f32 *)((u8 *)node + 0x0C) - arg0;
            dz = *(f32 *)((u8 *)node + 0x14) - arg2;
            dist = (dx * dx) + (dz * dz);
            cmp = dist;
            if (arg3 == 0) {
                /* as in the asm, the y delta is added unsquared */
                cmp = dist + (*(f32 *)((u8 *)node + 0x10) - arg1);
            }
            if ((best == NULL) || (cmp < bestDist)) {
                best = node;
                bestDist = cmp;
            }
        }
    } while (n-- != 0);
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racecheckFindNearest.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *racecheckFindPrevious(s32 arg0) {
    s32 idx;
    void *node;

    idx = arg0 - 1;
    for (;;) {
        if (idx < 0) {
            idx = 0xFF;
        }
        node = D_overlay_31_01F04488[idx];
        if (idx == arg0) {
            break;
        }
        idx -= 1;
        if (node != NULL) {
            break;
        }
    }
    return node;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racecheckFindPrevious.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *racecheckFindNext(s32 arg0) {
    s32 idx;
    void *node;

    idx = arg0 + 1;
    for (;;) {
        if (idx >= 0x100) {
            idx = 0;
        }
        node = D_overlay_31_01F04488[idx];
        if (idx == arg0) {
            break;
        }
        idx += 1;
        if (node != NULL) {
            break;
        }
    }
    return node;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racecheckFindNext.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 racecheckStatus(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    u8 *extra;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 distSq;
    f32 dist;

    if (arg0 != NULL) {
        dx = *(f32 *)((u8 *)arg0 + 0x0C) - arg1;
        dz = *(f32 *)((u8 *)arg0 + 0x14) - arg3;
        extra = *(u8 **)((u8 *)arg0 + 0x68);
        distSq = (dx * dx) + (dz * dz);
        if (arg4 == 0) {
            dy = *(f32 *)((u8 *)arg0 + 0x10) - arg2;
            distSq = dy * dy;
        }
        if (distSq < *(f32 *)(extra + 0x0C)) {
            /* racecheckDistance is inlined in the asm */
            dist = (*(f32 *)(extra + 0x10) * arg1) + (*(f32 *)(extra + 0x14) * arg2) +
                   (*(f32 *)(extra + 0x18) * arg3) + *(f32 *)(extra + 0x1C);
            if (dist < 0.0f) {
                return 1;
            }
            return -1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racecheckStatus.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 racecheckDistance(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 *extra;
    f32 dist;

    dist = 32768.0f;
    if (arg0 != NULL) {
        extra = *(u8 **)((u8 *)arg0 + 0x68);
        dist = (*(f32 *)(extra + 0x10) * arg1) + (*(f32 *)(extra + 0x14) * arg2) +
               (*(f32 *)(extra + 0x18) * arg3) + *(f32 *)(extra + 0x1C);
    }
    return dist;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racecheckDistance.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintInit(void) {
    s32 playerCount;
    void **playerList;
    u8 *racer;
    void *player;
    void *node;
    u8 *nodeExtra;
    s32 status;
    s32 i;
    s8 temp;

    racecheckRefresh();
    playerList = objGetPlayerlist(&playerCount);
    racer = D_overlay_31_01F04918;
    node = NULL;
    nodeExtra = NULL;
    for (i = 0; i < playerCount; i++) {
        player = playerList[i];
        status = 0;
        if (player != NULL) {
            node = racecheckFindNearest(*(f32 *)((u8 *)player + 0x0C), *(f32 *)((u8 *)player + 0x10),
                                        *(f32 *)((u8 *)player + 0x14), 1);
            status = racecheckStatus(node, *(f32 *)((u8 *)player + 0x0C), *(f32 *)((u8 *)player + 0x10),
                                     *(f32 *)((u8 *)player + 0x14), 1);
            if (node != NULL) {
                nodeExtra = *(u8 **)((u8 *)node + 0x68);
            }
        }
        if (status != -1) {
            if (status != 1) {
                *(void **)(racer + 0x00) = NULL;
                *(void **)(racer + 0x04) = NULL;
            } else {
                *(void **)(racer + 0x00) = node;
                *(void **)(racer + 0x04) = racecheckFindNext(nodeExtra[0]);
            }
        } else {
            *(void **)(racer + 0x00) = racecheckFindPrevious(nodeExtra[0]);
            *(void **)(racer + 0x04) = node;
        }
        *(s32 *)(racer + 0x08) = 0;
        *(s32 *)(racer + 0x0C) = 0;
        *(f32 *)(racer + 0x10) = racecheckDistance(*(void **)(racer + 0x04),
                                                   *(f32 *)((u8 *)player + 0x0C),
                                                   *(f32 *)((u8 *)player + 0x10),
                                                   *(f32 *)((u8 *)player + 0x14));
        racer[0x14] = 0;
        temp = (s8)(i - 1);
        racer[0x15] = (u8)(i >= (playerCount - numberOfAI));
        *(s8 *)(racer + 0x16) = temp;
        *(s8 *)(racer + 0x17) = temp;
        racer[0x18] = (u8)i;
        *(s8 *)(racer + 0x19) = raceGameStartBoost;
        racer[0x1A] = 0;
        *(s8 *)(racer + 0x1B) = 0;
        *(s16 *)(racer + 0x1C) = 0;
        racer[0x1E] = 0;
        *(s32 *)(racer + 0x24) = 0;
        racer += 0x28;
    }

    D_overlay_31_01F04484 = 0x168;
    if (racingInGame != 0 && raceGameSingleScreen == 0) {
        D_overlay_31_01F04484 = 0x294;
    }
    D_overlay_31_01F040EC = 0;
    D_overlay_31_01F040F0 = -1;
    D_overlay_31_01F04908[0] = 0;
    D_overlay_31_01F04908[1] = 0;
    D_overlay_31_01F04908[2] = 0;
    D_overlay_31_01F04908[3] = 0;
    D_overlay_31_01F040F4 = 0;
    D_overlay_31_01F040F8 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintUpdate(s32 arg0) {
    s32 playerCount;
    void **playerList;
    u8 *racer;
    u8 *other;
    void *player;
    void *prev;
    void *next;
    void *node;
    u8 *nodeExtra;
    u8 *prevExtra;
    s32 prevStatus;
    s32 nextStatus;
    s32 temp;
    f32 oldDist;
    f32 newDist;
    f32 distDelta;
    f32 px;
    f32 py;
    f32 pz;
    s32 rank;
    s32 ahead;
    s32 oldTimer;
    s32 i;
    s32 j;

    playerList = objGetPlayerlist(&playerCount);
    if (playerCount > 0) {
        for (i = 0; i < playerCount; i++) {
            racer = D_overlay_31_01F04918 + (i * 0x28);
            player = playerList[i];
            px = *(f32 *)((u8 *)player + 0x0C);
            py = *(f32 *)((u8 *)player + 0x10);
            pz = *(f32 *)((u8 *)player + 0x14);
            prev = *(void **)(racer + 0x00);
            next = *(void **)(racer + 0x04);
            if (prev != NULL && next != NULL) {
                prevStatus = racecheckStatus(prev, px, py, pz, 1);
                nextStatus = racecheckStatus(next, px, py, pz, 1);
                if (nextStatus == 1) {
                    node = next;
                    *(void **)(racer + 0x00) = node;
                    nodeExtra = *(u8 **)((u8 *)node + 0x68);
                    *(void **)(racer + 0x04) = racecheckFindNext(nodeExtra[0]);
                    temp = *(s32 *)(racer + 0x0C) + 1;
                    *(s32 *)(racer + 0x0C) = temp;
                    if (temp >= D_overlay_31_01F040DC) {
                        if (racer[0x14] == 0 && racer[0x1E] == 0) {
                            *(s32 *)(racer + 0x08) += 1;
                        }
                        *(s32 *)(racer + 0x0C) = temp - D_overlay_31_01F040DC;
                        racer[0x14] = 0;
                    }
                } else if (prevStatus == -1) {
                    node = prev;
                    *(void **)(racer + 0x04) = node;
                    nodeExtra = *(u8 **)((u8 *)node + 0x68);
                    *(void **)(racer + 0x00) = racecheckFindPrevious(nodeExtra[0]);
                    temp = *(s32 *)(racer + 0x0C) - 1;
                    *(s32 *)(racer + 0x0C) = temp;
                    if (temp < 0) {
                        racer[0x14] = 1;
                        *(s32 *)(racer + 0x0C) = temp + D_overlay_31_01F040DC;
                    }
                }
                oldDist = *(f32 *)(racer + 0x10);
                newDist = racecheckDistance(*(void **)(racer + 0x04), px, py, pz);
                *(f32 *)(racer + 0x10) = newDist;
                distDelta = newDist - oldDist;
                if (D_overlay_31_01F04484 <= 0 && D_overlay_31_01F04464 < distDelta &&
                    distDelta < D_overlay_31_01F04468) {
                    *(s32 *)(racer + 0x24) += arg0;
                } else {
                    *(s32 *)(racer + 0x24) = 0;
                }
            }
            if (*(s8 *)(racer + 0x1B) > 0) {
                *(s8 *)(racer + 0x1B) = (s8)(*(s8 *)(racer + 0x1B) - arg0);
            }
        }

        for (i = 0; i < playerCount; i++) {
            racer = D_overlay_31_01F04918 + (i * 0x28);
            rank = 0;
            for (j = 0; j < playerCount; j++) {
                if (j == i) {
                    continue;
                }
                other = D_overlay_31_01F04918 + (j * 0x28);
                /* is racer j ahead of racer i? */
                ahead = 0;
                if (*(s32 *)(racer + 0x08) < *(s32 *)(other + 0x08) ||
                    (s32)racer[0x1E] < (s32)other[0x1E]) {
                    ahead = 1;
                } else if (*(s32 *)(other + 0x08) == *(s32 *)(racer + 0x08)) {
                    if (racer[0x14] != 0 && other[0x14] == 0) {
                        ahead = 1;
                    } else if (other[0x14] == racer[0x14]) {
                        if (*(s32 *)(racer + 0x0C) < *(s32 *)(other + 0x0C)) {
                            ahead = 1;
                        } else if (*(s32 *)(other + 0x0C) == *(s32 *)(racer + 0x0C) &&
                                   *(f32 *)(other + 0x10) < *(f32 *)(racer + 0x10)) {
                            ahead = 1;
                        }
                    }
                }
                rank += ahead;
            }
            if (rank == racer[0x18]) {
                *(s16 *)(racer + 0x1C) = (s16)(*(s16 *)(racer + 0x1C) + arg0);
            } else {
                *(s16 *)(racer + 0x1C) = 0;
            }
            racer[0x18] = (u8)rank;
            if (racer[0x15] != 0 && *(s8 *)(racer + 0x16) == 0) {
                prev = *(void **)(racer + 0x00);
                prevExtra = *(u8 **)((u8 *)prev + 0x68);
                if (prevExtra[2] != 0) {
                    if (rank == 0 && *(s16 *)(racer + 0x1C) >= 0x168) {
                        *(s8 *)(racer + 0x17) = 1;
                    } else if (rank != 0 || *(s16 *)(racer + 0x1C) < 0x168) {
                        *(s8 *)(racer + 0x17) = 0;
                    }
                }
            }
        }

        oldTimer = D_overlay_31_01F04484;
        if (oldTimer > 0) {
            D_overlay_31_01F04484 = oldTimer - arg0;
            if (oldTimer >= 0x12C && D_overlay_31_01F04484 < 0x12C) {
                amSndPlay(0x164, NULL);
            } else if (oldTimer >= 0xF0 && D_overlay_31_01F04484 < 0xF0) {
                amSndPlay(0x162, NULL);
            } else if (oldTimer >= 0xB4 && D_overlay_31_01F04484 < 0xB4) {
                amSndPlay(0x160, NULL);
            } else if (oldTimer >= 0x78 && D_overlay_31_01F04484 < 0x78) {
                amSndPlay(0xDA, NULL);
            }
        }
        if (D_overlay_31_01F04484 < 0x78) {
            func_overlay_31_01F021F0_1F4CE40(arg0);
            func_overlay_31_01F01150_1F4BDA0(playerCount, arg0);
        }
        if (racingInGame != 0 && D_overlay_31_01F04936 != 0) {
            func_overlay_31_01F0242C_1F4D07C(0, arg0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_31_01F01150_1F4BDA0(s32 arg0, s32 arg1) {
    u8 *racer;
    u8 *mp;
    u32 timeLimit;
    u32 *timeField;
    s32 temp;
    s32 allDone;
    s32 i;
    s32 p;
    u16 fade;
    u8 state;

    state = multiFinished;
    switch (state) {
    case 0:
        timeLimit = (u32)(raceGameTime * 0xE10);
        currentGameTime += arg1;
        for (i = 0; i < arg0; i++) {
            racer = D_overlay_31_01F04918 + (i * 0x28);
            if (racer[0x1E] == 0) {
                timeField = (u32 *)(multiPlayer + (i * 0xA0) + 0x90);
                *timeField = *timeField + arg1;
                if (raceGameType != 0 && timeLimit < *timeField) {
                    *timeField = timeLimit;
                }
            }
        }
        D_overlay_31_01F04480 = -1;
        if (raceGameType == 0) {
            for (i = 0; i < arg0; i++) {
                racer = D_overlay_31_01F04918 + (i * 0x28);
                if (*(s32 *)(racer + 0x08) >= raceGameLaps && racer[0x1E] == 0) {
                    racer[0x1E] = (u8)(4 - racer[0x18]);
                    if (racer[0x15] == 0) {
                        racer[0x15] = 1;
                        racer[0x17] = (u8)mathRnd(0, 2);
                    }
                }
            }
        } else if (currentGameTime >= (s32)timeLimit) {
            currentGameTime = (s32)timeLimit;
            for (i = 0; i < arg0; i++) {
                racer = D_overlay_31_01F04918 + (i * 0x28);
                racer[0x1E] = (u8)(4 - racer[0x18]);
                if (racer[0x15] == 0) {
                    racer[0x15] = 1;
                    racer[0x17] = (u8)mathRnd(0, 2);
                }
            }
        }
        temp = arg0 - 1;
        allDone = 1;
        for (i = 0; i < arg0; i++) {
            racer = D_overlay_31_01F04918 + (i * 0x28);
            if (racer[0x1E] == 0 && racer[0x15] == 0) {
                allDone = 0;
            }
        }
        if (allDone != 0) {
            for (i = temp; i >= 0; i--) {
                mp = multiPlayer + (i * 0xA0);
                racer = D_overlay_31_01F04918 + (i * 0x28);
                *(s8 *)(mp + 0x14) = (s8)(5 - racer[0x1E]);
            }
            multiFinished = 1;
            if (raceGameSingleScreen != 0) {
                amDittyPlay(0x4E);
                amTuneSetFadeScaled(D_overlay_31_01F0446C, 0x20);
            } else if (racingInGame == 0 || D_overlay_31_01F04936 == 4) {
                amTunePlay(0x57);
            } else {
                amTunePlay(0x58);
            }
        }
        break;
    case 1:
        fade = (u16)(gameoverFade + arg1);
        gameoverFade = fade;
        if (fade >= 0x100) {
            gameoverFade = 0xFF;
            multiFinished = 2;
            if (raceGameSingleScreen != 0) {
                amTuneSetFadeScaled(2.0f, 0x7F);
            }
        }
        break;
    case 2:
        for (p = 1; p <= arg0; p++) {
            if (joyGetPressed(p) & 0x9000) {
                if (D_overlay_31_01F040F4 != 0) {
                    mainSaveGlobalFlags();
                }
                if (racingInGame != 0) {
                    if (raceGameSingleScreen != 0) {
                        mainChangeLevel((s32)racingReturnLevel, (s32)racingCharacter, (s32)racingReturnSetup, 0x10, 1, 0);
                    } else if (D_overlay_31_01F04936 == 4 && mainGetGameFlag(0x25) == 0) {
                        mainChangeLevel(0x18A, 3, 0, 0x10, 1, 0);
                    } else {
                        mainChangeLevel(0x11D, 3, 0, 0x10, 1, 0);
                    }
                    multiFinished = 3;
                } else {
                    amTuneSetFade(0x3F000000, 0);
                    mainChangeCameras(1);
                    mainFrontInit(0x15, 0, 0);
                    multiFinished = 3;
                }
                break;
            }
        }
        break;
    }
    if (state != 0) {
        mainPauseDisable(0xA);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/func_overlay_31_01F01150_1F4BDA0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 sprintAIJoypad(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    u8 *racer;
    void *player;
    void *next;
    u8 *nextExtra;
    f32 targetX;
    f32 targetZ;
    f32 scale;
    f32 dx;
    f32 dz;
    f32 len;
    f32 mag;
    s32 temp;

    if (arg0 < 0 || arg0 >= 4) {
        return 0;
    }
    racer = D_overlay_31_01F04918 + (arg0 * 0x28);
    if (racer[0x15] == 0) {
        return 0;
    }
    if (sprintCountdown(racer) != 0) {
        *arg1 = 0;
        *arg2 = 0;
        *arg3 = 0;
        *arg4 = 0;
        return 1;
    }
    player = objGetPlayerNo(arg0);
    if (*(s32 *)(racer + 0x24) >= 0x15 && raceGameIDNumber == 2) {
        temp = *(s32 *)(racer + 0x0C);
        if (temp >= 0xF && temp < 0x11) {
            *(void **)(racer + 0x04) = racecheckFindNext(0x27);
            *(void **)(racer + 0x00) = racecheckFindPrevious(0x28);
            *(s32 *)(racer + 0x0C) = 0x27;
            racer[0x14] = 1;
            *(s32 *)(racer + 0x24) = 0;
        }
    }

    next = *(void **)(racer + 0x04);
    nextExtra = *(u8 **)((u8 *)next + 0x68);
    switch (racer[0x17]) {
    case 0:
        targetX = *(f32 *)(nextExtra + 0x20);
        targetZ = *(f32 *)(nextExtra + 0x24);
        scale = 65.0f;
        break;
    case 2:
        targetX = *(f32 *)(nextExtra + 0x28);
        targetZ = *(f32 *)(nextExtra + 0x2C);
        scale = 60.0f;
        break;
    case 3:
        targetX = *(f32 *)(nextExtra + 0x38);
        targetZ = *(f32 *)(nextExtra + 0x3C);
        scale = 62.5f;
        break;
    default:
        targetX = *(f32 *)(nextExtra + 0x30);
        targetZ = *(f32 *)(nextExtra + 0x34);
        scale = 62.5f;
        break;
    }
    dx = *(f32 *)((u8 *)player + 0x0C) - targetX;
    dz = targetZ - *(f32 *)((u8 *)player + 0x14);
    len = sqrtf((dx * dx) + (dz * dz));
    mag = len;
    if (len > 0.0f) {
        mag = (*(f32 *)(nextExtra + 0x08) * scale) / len;
    }
    *arg1 = (s32)(dx * mag);
    *arg2 = (s32)(dz * mag);
    *arg3 = 0;
    *arg4 = 0;

    switch (racer[0x16]) {
    case 0:
        if (racer[0x18] != 0 && *(s8 *)(racer + 0x1B) <= 0 && *(s8 *)(racer + 0x19) > 0) {
            *(s8 *)(racer + 0x1B) = 0x78;
            *arg4 = 0x8000;
        }
        if (racer[0x18] != 3 && racer[0x1A] != 0 && mathRnd(1, 0x3E8) >= 0x3D0) {
            *arg4 |= 0x2000;
        }
        break;
    case 1:
        if (racer[0x18] != 0 && *(s8 *)(racer + 0x1B) <= 0 && *(s8 *)(racer + 0x19) > 0) {
            if (mathRnd(1, 0x3E8) >= 0x3DF) {
                *(s8 *)(racer + 0x1B) = 0x78;
                *arg4 = 0x8000;
            }
        }
        if (racer[0x18] != 3 && racer[0x1A] != 0 && mathRnd(1, 0x3E8) >= 0x3E4) {
            *arg4 |= 0x2000;
        }
        break;
    default:
        break;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintAIJoypad.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintPickedUpBoost(s32 arg0) {
    u8 *racer;

    if (arg0 >= 0 && arg0 < 4) {
        racer = D_overlay_31_01F04918 + (arg0 * 0x28);
        if (racer[0x19] < 0x64) {
            racer[0x19] = (u8)(racer[0x19] + 1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintPickedUpBoost.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintPickedUpOil(s32 arg0) {
    if (arg0 >= 0 && arg0 < 4) {
        D_overlay_31_01F04918[(arg0 * 0x28) + 0x1A] = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintPickedUpOil.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintPickedUpBomb(s32 arg0) {
    if (arg0 >= 0 && arg0 < 4) {
        D_overlay_31_01F04918[(arg0 * 0x28) + 0x1A] = 2;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintPickedUpBomb.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 sprintPlayerBoost(s32 arg0) {
    u8 *racer;

    if (arg0 >= 0 && arg0 < 4) {
        racer = D_overlay_31_01F04918 + (arg0 * 0x28);
        if ((s32)racer[0x19] > 0) {
            racer[0x19] = (u8)(racer[0x19] - 1);
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintPlayerBoost.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 sprintPlayerFire(void *arg0, s32 arg1) {
    u8 *racer;
    s16 setup[6];
    f32 **heights;
    f32 x;
    f32 y;
    f32 z;
    s32 count;
    s32 i;
    void *obj;

    if (arg1 >= 0 && arg1 < 4) {
        racer = D_overlay_31_01F04918 + (arg1 * 0x28);
        if (racer[0x1A] != 0) {
            x = *(f32 *)((u8 *)arg0 + 0xC);
            y = *(f32 *)((u8 *)arg0 + 0x10);
            z = *(f32 *)((u8 *)arg0 + 0x14);
            setup[2] = (s16)x;
            setup[3] = (s16)y;
            setup[4] = (s16)z;
            count = trackGetHeights(x, z, 0, (s32 *)&heights);
            if (count != 0) {
                i = count - 1;
                do {
                    if (*heights[i] < y) {
                        setup[3] = (s16)*heights[i];
                        break;
                    }
                    i -= 1;
                } while (i != 0);
            }
            if (racer[0x1A] == 2) {
                setup[0] = 0x279;
                setup[5] = 0x1E0;
                if (raceGameSingleScreen != 0) {
                    amSndPlay(0x215, NULL);
                } else {
                    amSndPlayXYZ(0x215, x, y, z, 4, NULL);
                }
            } else {
                if (raceGameSingleScreen == 0) {
                    setup[0] = 0x278;
                    amSndPlayXYZ(0x216, x, y, z, 4, NULL);
                } else {
                    setup[0] = 0x1FB;
                    amSndPlay(0x216, NULL);
                }
                setup[5] = 0x258;
            }
            obj = objSetupObject(setup, 1);
            if (obj != NULL) {
                *(s32 *)((u8 *)obj + 0x3C) = 0;
            }
            racer[0x1A] = 0;
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintPlayerFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 sprintCountdown() {
    if (D_overlay_31_01F04484 >= 0x78) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintCountdown.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintHitOilSlick(void *arg0) {
    u8 *player;
    s32 handle;
    s32 idx;
    f32 x;
    f32 y;
    f32 z;

    x = *(f32 *)((u8 *)arg0 + 0xC);
    y = *(f32 *)((u8 *)arg0 + 0x10);
    z = *(f32 *)((u8 *)arg0 + 0x14);
    player = *(u8 **)((u8 *)arg0 + 0x68);
    if (player != NULL) {
        player[0x576] = 0x1E;
        player[0x13E] = 2;
        *(s16 *)(player + 0x13C) = *(s16 *)(player + 0x11C);
        if (raceGameSingleScreen != 0) {
            amSndPlay(0x21C, NULL);
        } else {
            handle = *(s32 *)(player + 0x5E0);
            if (handle != 0) {
                amSndStopXYZ(handle);
            }
            handle = *(s32 *)(player + 0x5E8);
            if (handle != 0) {
                amSndStopXYZ(handle);
            }
            amSndPlayXYZ(0x21C, x, y, z, 4, player + 0x5E0);
            if (player[0] == 0 && (numberOfPlayers - numberOfAI) == 1) {
                idx = racingCharacter * 2;
                amSndPlayXYZ(mathRnd(D_overlay_31_01F040FC[idx], D_overlay_31_01F040FC[idx + 1]) & 0xFFFF, x, y, z, 4, player + 0x5E8);
            } else {
                amSndPlayXYZ(mathRnd(0xA0, 0xA9) & 0xFFFF, x, y, z, 4, player + 0x5E8);
            }
        }
        if (sprintAIPlayer(player[0]) == 0) {
            rumbleMax(player[0], 0x28, 0.2f);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintHitOilSlick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintHitBomb(void *arg0) {
    u8 *player;
    s32 handle;
    s32 idx;
    f32 x;
    f32 y;
    f32 z;

    x = *(f32 *)((u8 *)arg0 + 0xC);
    y = *(f32 *)((u8 *)arg0 + 0x10);
    z = *(f32 *)((u8 *)arg0 + 0x14);
    player = *(u8 **)((u8 *)arg0 + 0x68);
    if (player != NULL) {
        player[0x576] = 0x3C;
        player[0x13E] = 2;
        *(s16 *)(player + 0x13C) = *(s16 *)(player + 0x11C);
        if (raceGameSingleScreen != 0) {
            amSndPlay(0x21C, NULL);
        } else {
            handle = *(s32 *)(player + 0x5E0);
            if (handle != 0) {
                amSndStopXYZ(handle);
            }
            handle = *(s32 *)(player + 0x5E8);
            if (handle != 0) {
                amSndStopXYZ(handle);
            }
            amSndPlayXYZ(0x21C, x, y, z, 4, player + 0x5E0);
            if (player[0] == 0 && (numberOfPlayers - numberOfAI) == 1) {
                idx = racingCharacter * 2;
                amSndPlayXYZ(mathRnd(D_overlay_31_01F040FC[idx], D_overlay_31_01F040FC[idx + 1]) & 0xFFFF, x, y, z, 4, player + 0x5E8);
            } else {
                amSndPlayXYZ(mathRnd(0xA0, 0xA9) & 0xFFFF, x, y, z, 4, player + 0x5E8);
            }
        }
        if (sprintAIPlayer(player[0]) == 0) {
            rumbleMax(player[0], 0x4B, 0.2f);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintHitBomb.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_31_01F021F0_1F4CE40(s32 arg0) {
    s16 setup[6];
    s16 *table;
    void *obj;
    void *spawned;
    s32 chosen;

    if (D_overlay_31_01F040E0 > 0 && raceGamePickups != 0) {
        D_overlay_31_01F040E8 -= arg0;
        if (D_overlay_31_01F040E8 <= 0) {
            if (D_overlay_31_01F040E0 >= 2) {
                do {
                    chosen = mathRnd(0, D_overlay_31_01F040E0 - 1);
                } while (chosen == D_overlay_31_01F040E4);
            } else {
                chosen = 0;
            }
            table = (s16 *)D_overlay_31_01F03DF8[raceGamePickups];
            obj = D_overlay_31_01F04888[chosen];
            setup[0] = table[mathRnd(0, 7)];
            setup[2] = (s16)*(f32 *)((u8 *)obj + 0xC);
            setup[3] = (s16)*(f32 *)((u8 *)obj + 0x10);
            setup[4] = (s16)*(f32 *)((u8 *)obj + 0x14);
            setup[5] = 0xA;
            spawned = objSetupObject(setup, 1, obj, table);
            if (spawned != NULL) {
                *(s32 *)((u8 *)spawned + 0x3C) = 0;
            }
            D_overlay_31_01F040E4 = chosen;
            D_overlay_31_01F040E8 = mathRnd(0, 0xB4) + 0x12C;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/func_overlay_31_01F021F0_1F4CE40.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintInitInstruments(void) {
    D_overlay_31_01F03F78 = texLoadTexture(0x266);
    D_overlay_31_01F03F90 = texLoadTexture(0x269);
    D_overlay_31_01F03FB4 = texLoadTexture(0x267);
    D_overlay_31_01F03FCC = texLoadTexture(0x268);
    D_overlay_31_01F03FE4 = texLoadTexture(0x26A);
    D_overlay_31_01F03FFC = texLoadTexture(0x26B);
    D_overlay_31_01F04014 = texLoadTexture(0x26C);
    D_overlay_31_01F0402C = texLoadTexture(0x26D);
    D_overlay_31_01F04044 = texLoadTexture(0x26E);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintInitInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_31_01F0242C_1F4D07C(s32 arg0, s32 arg1) {
    u8 *racer;
    s32 result;
    s32 t;

    if (arg0 >= 0 && arg0 < numberOfPlayers) {
        if (D_overlay_31_01F040EC == 0) {
            racer = D_overlay_31_01F04918 + (arg0 * 0x28);
            result = func_overlay_31_01F038E0_1F4E530((D_800FEDE0[arg0 * 0x28] * 0x64) / 60, racer + 0x1F, arg0, &D_overlay_31_01F040EC);
            *(s32 *)(racer + 0x20) = result;
            if (result != 0) {
                if (raceGameIDNumber == 0) {
                    if (racer[0x1E] == 4 && !(D_800FF382 & 1)) {
                        mainSetGameFlag(0x42, 1);
                        D_overlay_31_01F040F8 = 1;
                    }
                } else if (raceGameIDNumber == 1) {
                    if (racer[0x1E] == 4 && !(D_800FF382 & 2)) {
                        mainSetGameFlag(0x43, 1);
                        D_overlay_31_01F040F8 = 1;
                    }
                } else if (raceGameIDNumber == 2 && racer[0x1E] == 4 && !(D_800FF382 & 4)) {
                    mainSetGameFlag(0x44, 1);
                    D_overlay_31_01F040F8 = 1;
                }
                if (!(D_800FF382 & 0x10) && (D_800FF32C >> 0x12) < 0xBB8 && (D_800FF340 >> 0x12) < 0xFA0) {
                    mainSetGameFlag(0x46, 1);
                    D_overlay_31_01F040F8 = 1;
                }
                D_overlay_31_01F040F4 = 1;
            }
        }
        if (D_overlay_31_01F040EC < 0x100) {
            t = D_overlay_31_01F040EC + (arg1 * 4);
            D_overlay_31_01F040EC = t;
            if (t >= 0x100) {
                D_overlay_31_01F040EC = 0x100;
                D_overlay_31_01F040F0 = 0;
            }
        } else if (D_overlay_31_01F040F0 >= 0 && D_overlay_31_01F040F0 < 4) {
            t = D_overlay_31_01F04908[D_overlay_31_01F040F0] + (arg1 * 8);
            D_overlay_31_01F04908[D_overlay_31_01F040F0] = t;
            if (t >= 0x101) {
                D_overlay_31_01F040F0 += 1;
                D_overlay_31_01F04908[D_overlay_31_01F040F0 - 1] = 0x100;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/func_overlay_31_01F0242C_1F4D07C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_31_01F026B8_1F4D308(Gfx **arg0, s32 arg1) {
    char timeBuf[32];
    s32 top;
    s32 height;
    s32 textY;
    s32 total;
    s32 mins;
    s32 secs;
    s32 cs;
    s32 state;
    s32 w;
    s32 h;
    s32 lineY;

    if (arg1 >= 0 && arg1 < numberOfPlayers) {
        top = 0x26;
        if (raceGameSingleScreen != 0) {
            top = 0x78;
            height = 0x16;
            textY = 0x78;
            if (D_overlay_31_01F040F8 != 0) {
                textY = 0x70;
                height = 0x1E;
            }
        } else {
            height = 0x16;
            textY = 0x26;
            if (D_overlay_31_01F040F8 != 0) {
                top = 0x2E;
                height = 0x1E;
            }
        }
        w = (D_overlay_31_01F040EC << 6) >> 8;
        h = (height * D_overlay_31_01F040EC) >> 8;
        frontDrawRectangle(arg0, 0xA0 - w, top - h, w + 0xA0, h + top, 0xA0);

        total = D_800FEDE0[arg1 * 0x28];
        mins = total / 3600;
        if (mins >= 0x64) {
            mins = 0x63;
        }
        secs = (total % 3600) / 60;
        cs = (((total % 3600) % 60) * 0x64) / 60;
        sprintf(timeBuf, D_overlay_31_01F043D0, mins, secs, cs);

        state = D_overlay_31_01F04918[(arg1 * 0x28) + 0x1E];
        fontUseFont(2);
        lineY = textY - 0x13;
        drawGlowingText(arg0, 0xA0, lineY, D_overlay_31_01F04098[-state], 4, 0, 0x80, 0xFF, 0xFF, D_overlay_31_01F04908[0]);
        lineY += 0xD;
        drawGlowingText(arg0, 0xA0, lineY, timeBuf, 4, 0, 0x80, 0xFF, 0xFF, D_overlay_31_01F0490C);
        if (D_overlay_31_01F040F8 != 0) {
            lineY += 0xF;
            drawGlowingText(arg0, 0xA0, lineY, D_overlay_31_01F043E8, 4, 0xFF, 0xFF, 0x40, 0xFF, D_overlay_31_01F04910);
        }
        drawGlowingText(arg0, 0xA0, lineY + 0xF, D_overlay_31_01F04400, 4, 0xFF, 0x55, 0, 0xFF, D_overlay_31_01F04914);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/func_overlay_31_01F026B8_1F4D308.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_31_01F029FC_1F4D64C(Gfx **arg0, void *arg1) {
    u8 *rectA;
    u8 *rectB;
    s32 *var_a2;
    void *racer;
    s32 i;
    s32 limit;
    s32 temp_v1;
    s32 value;
    s32 neg;

    if (arg1 != NULL) {
        racer = *(void **)((u8 *)arg1 + 0x68);
        i = 0;
        if (racer != NULL) {
            rectA = (u8 *)D_overlay_31_01F04248;
            rectB = (u8 *)D_overlay_31_01F04158;
            var_a2 = D_overlay_31_01F04108;
            limit = (s32)(*(f32 *)((u8 *)racer + 4) * D_overlay_31_01F04470);
            if (limit < 0) {
                limit = -limit;
            }
            do {
                temp_v1 = *(s32 *)(rectA + 8) & ~0xFF;
                if (i < limit) {
                    *(s32 *)(rectA + 8) = temp_v1 | 0xAA;
                    *(s32 *)(rectB + 8) = ((*var_a2 * 0xAA) >> 8) | temp_v1;
                } else {
                    *(s32 *)(rectA + 8) = temp_v1 | 0x55;
                    *(s32 *)(rectB + 8) = ((*var_a2 * 0x55) >> 8) | temp_v1;
                }
                i += 1;
                var_a2 += 1;
                rectA += 0xC;
                rectB += 0xC;
            } while (i != 0x14);
            value = (s32)(*(f32 *)((u8 *)racer + 4) * 25.0f);
            neg = value < 0x1F5;
            if (value < 0) {
                value = -value;
                neg = value < 0x1F5;
            }
            fxDrawDigitalNumber(0xA8, 0xCC, value, 3, neg ^ 1);
        }
    }
    frontDrawRectangles(arg0, 0x14, D_overlay_31_01F04248, 0);
    frontDrawRectangles(arg0, 0x14, D_overlay_31_01F04158, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/func_overlay_31_01F029FC_1F4D64C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintDrawInstruments(Gfx **arg0, MatrixS **arg1, Vtx **arg2, u8 arg3) {
    char buf1[32];
    char buf2[32];
    s32 w;
    s32 h;
    u8 *racer;
    s16 *pos;
    u8 *col;
    s32 idx;
    s32 var_s3;
    s32 state;
    s32 x3;
    s32 s2;
    void **slot;

    if (arg3 > 0) {
        fontBackground(0, 0, 0, 0);
        if ((s32)multiFinished > 0 && (s32)multiFinished < 0xA) {
            fontUseFont(0);
            viGetCurrentSize(&w, &h);
            fxScreenEffect(arg0, otherScreen, w, h, 0, 0, w, h, ((0xFF - gameoverFade) << 0x18) | 0xFFFF00);
        }
        if (racingInGame != 0 && raceGameSingleScreen == 0) {
            if (D_overlay_31_01F04936 != 0) {
                var_s3 = 4 - D_overlay_31_01F04936;
            } else {
                var_s3 = D_overlay_31_01F04930;
            }
            func_overlay_31_01F029FC_1F4D64C(arg0, objGetPlayerNo(0));
            sprintf(buf1, D_overlay_31_01F04414, D_overlay_31_01F04920);
            sprintf(buf2, D_overlay_31_01F04420, D_overlay_31_01F04931);
            fontUseFont(2);
            fontColour(0, 0, 0, 0xFF, 0xFF);
            fontPrintXY(arg0, 0x1F, 0x11, buf1, 0);
            fontPrintXY(arg0, 0x117, 0x2B, buf2, 4);
            fontPrintXY(arg0, 0x39, 0xC1, D_overlay_31_01F04078[var_s3], 0);
            fontColour(0, 0xFF, 0x80, 0xFF, 0xFF);
            fontPrintXY(arg0, 0x1E, 0x10, buf1, 0);
            fontPrintXY(arg0, 0x116, 0x2A, buf2, 4);
            fontPrintXY(arg0, 0x38, 0xC0, D_overlay_31_01F04078[var_s3], 0);
            rcpTileWrite(arg0, D_overlay_31_01F0405C[D_overlay_31_01F04918[0x1A]], 0x26, 0x22, 0xFF, 0xFF, 0xFF, 0xFF);
            rcpTileWrite(arg0, &D_overlay_31_01F03F90, 0x116, 0x1C, 0xFF, 0xFF, 0xFF, 0xFF);
            slot = &D_overlay_31_01F04068[var_s3];
            rcpTileWriteX(arg0, *slot, 43.0f, 209.0f, 1.5f, 1.5f, 0xFE, 1);
            rcpTileWriteX(arg0, *slot, 42.0f, 208.0f, 1.5f, 1.5f, 0xFF80FE, 1);
            if (D_overlay_31_01F04936 != 0) {
                func_overlay_31_01F026B8_1F4D308(arg0, 0);
            }
        } else if (raceGameSingleScreen != 0 || arg3 >= 3) {
            racer = D_overlay_31_01F04918;
            idx = 0;
            if (arg3 > 0) {
                do {
                    pos = D_overlay_31_01F03ED8 + (idx * 10);
                    col = D_overlay_31_01F03E18 + (idx * 4);
                    state = racer[0x1E];
                    if (state == 0) {
                        sprintf(buf1, D_overlay_31_01F04428, *(s32 *)(racer + 0x8));
                        sprintf(buf2, D_overlay_31_01F04434, racer[0x19]);
                        fontColour(0, 0, 0, 0xFF, 0xFF);
                        fontUseFont(2);
                        fontPrintXY(arg0, pos[2] + 1, pos[3] + 1, buf1, 0);
                        rcpTileWrite(arg0, &D_overlay_31_01F03F78, pos[4] + 1, pos[5] + 1, 0, 0, 0, 0xFF);
                        fontPrintXY(arg0, pos[6] + 1, pos[7] + 1, buf2, 0);
                        fontColour(col[0], col[1], col[2], 0xFF, 0xFF);
                        fontUseFont(2);
                        fontPrintXY(arg0, pos[2], pos[3], buf1, 0);
                        rcpTileWrite(arg0, &D_overlay_31_01F03F78, pos[4], pos[5], 0xFF, 0xFF, 0xFF, 0xFF);
                        fontPrintXY(arg0, pos[6], pos[7], buf2, 0);
                        rcpTileWrite(arg0, D_overlay_31_01F0405C[racer[0x1A]], pos[8], pos[9], 0xFF, 0xFF, 0xFF, 0xFF);
                        rcpTileWrite(arg0, D_overlay_31_01F04068[racer[0x18]], pos[0] + 1, pos[1] + 1, 0, 0, 0, 0xFF);
                        rcpTileWrite(arg0, D_overlay_31_01F04068[racer[0x18]], pos[0], pos[1], col[0], col[1], col[2], 0xFF);
                    } else {
                        sprintf(buf1, D_overlay_31_01F0443C, *(s32 *)((u8 *)front_text + 0x600), D_overlay_31_01F04098[-state]);
                        s2 = 0;
                        if (idx & 1) {
                            s2 = 1;
                            x3 = 0x120;
                        } else {
                            x3 = 0x20;
                        }
                        fontUseFont(2);
                        fontColour(0, 0, 0, 0xFF, 0xFF);
                        fontPrintXY(arg0, x3 + 1, pos[3] + 1, buf1, s2);
                        fontColour(col[0], col[1], col[2], 0xFF, 0xFF);
                        fontPrintXY(arg0, x3, pos[3], buf1, s2);
                    }
                    idx += 1;
                    racer += 0x28;
                } while (idx != arg3);
            }
            if (racingInGame != 0 && D_overlay_31_01F04936 != 0) {
                func_overlay_31_01F026B8_1F4D308(arg0, 0);
            }
        } else {
            racer = D_overlay_31_01F04918;
            idx = 0;
            do {
                if ((viGetVideoMode() & 1) || frontGet2PlayerSplit() != 0) {
                    pos = D_overlay_31_01F03F48[idx];
                } else {
                    pos = D_overlay_31_01F03F70[idx];
                }
                state = racer[0x1E];
                if (state != 0) {
                    var_s3 = 4 - state;
                } else {
                    var_s3 = racer[0x18];
                }
                sprintf(buf1, D_overlay_31_01F04444, *(s32 *)(racer + 0x8));
                sprintf(buf2, D_overlay_31_01F04450, racer[0x19]);
                fontUseFont(2);
                fontColour(0, 0, 0, 0xFF, 0xFF);
                fontPrintXY(arg0, pos[0] + 1, pos[1] + 1, buf1, 0);
                fontPrintXY(arg0, pos[2] + 1, pos[3] + 0xF, buf2, 4);
                fontPrintXY(arg0, pos[4] + 0xF, pos[5] - 0xF, D_overlay_31_01F04078[var_s3], 0);
                fontColour(0, 0xFF, 0x80, 0xFF, 0xFF);
                fontPrintXY(arg0, pos[0], pos[1], buf1, 0);
                fontPrintXY(arg0, pos[2], pos[3] + 0xE, buf2, 4);
                fontPrintXY(arg0, pos[4] + 0xE, pos[5] - 0x10, D_overlay_31_01F04078[var_s3], 0);
                rcpTileWrite(arg0, &D_overlay_31_01F03F90, pos[2], pos[3], 0xFF, 0xFF, 0xFF, 0xFF);
                slot = &D_overlay_31_01F04068[var_s3];
                rcpTileWriteX(arg0, *slot, (f32)(pos[4] + 1), (f32)(pos[5] + 1), 1.5f, 1.5f, 0xFE, 1);
                rcpTileWriteX(arg0, *slot, (f32)pos[4], (f32)pos[5], 1.5f, 1.5f, 0xFF80FE, 1);
                rcpTileWrite(arg0, D_overlay_31_01F0405C[racer[0x1A]], pos[6], pos[7], 0xFF, 0xFF, 0xFF, 0xFF);
                idx += 1;
                racer += 0x28;
            } while (idx != arg3);
        }
        if (D_overlay_31_01F04484 > 0 && D_overlay_31_01F04484 < 0x169) {
            slot = &D_overlay_31_01F040A8[(D_overlay_31_01F04484 / 30)];
            if (*slot != NULL) {
                rcpTileWrite(arg0, *slot, 0xA1, 0x79, 0, 0, 0, 0xFF);
                rcpTileWrite(arg0, *slot, 0x9F, 0x77, 0xFF, 0xFF, 0, 0xFF);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintDrawInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintFreeInstruments(void) {
    texFreeTexture(D_overlay_31_01F03FCC);
    D_overlay_31_01F03FCC = 0;
    texFreeTexture(D_overlay_31_01F03FB4);
    D_overlay_31_01F03FB4 = 0;
    texFreeTexture(D_overlay_31_01F03F78);
    D_overlay_31_01F03F78 = 0;
    texFreeTexture(D_overlay_31_01F03F90);
    D_overlay_31_01F03F90 = 0;
    texFreeTexture(D_overlay_31_01F03FE4);
    D_overlay_31_01F03FE4 = 0;
    texFreeTexture(D_overlay_31_01F03FFC);
    D_overlay_31_01F03FFC = 0;
    texFreeTexture(D_overlay_31_01F04014);
    D_overlay_31_01F04014 = 0;
    texFreeTexture(D_overlay_31_01F0402C);
    D_overlay_31_01F0402C = 0;
    texFreeTexture(D_overlay_31_01F04044);
    D_overlay_31_01F04044 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintFreeInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void racingInGameStart(s32 arg0) {
    s32 next;
    s32 nextNext;

    mainRefreshMultiPlayer();
    gameoverFade = 0;
    D_800FED62 = 3;
    D_800FED6B = (racingCharacter & 0x1F) | (D_800FED6B & 0xFFE0);
    D_800FF1BA = 0;
    D_800FEE02 = 3;
    next = (racingCharacter + 1) & 3;
    D_800FEE0B = (next & 0x1F) | (D_800FEE0B & 0xFFE0);
    D_800FF1BC = 0;
    D_800FEEA2 = 3;
    nextNext = (next + 1) & 3;
    D_800FEEAB = (nextNext & 0x1F) | (D_800FEEAB & 0xFFE0);
    D_800FF1BE = 0;
    D_800FEF42 = 3;
    D_800FEF4B = ((nextNext + 1) & 3) | (D_800FEF4B & 0xFFE0);
    raceGameStoredType = raceGameType;
    raceGameStoredLaps = raceGameLaps;
    raceGameStoredPickups = raceGamePickups;
    raceGameStoredStartBoost = raceGameStartBoost;
    raceGameType = 0;
    raceGameLaps = 3;
    raceGamePickups = 7;
    raceGameStartBoost = 3;
    raceGameSingleScreen = (s8)arg0;
    currentGameTime = 0;
    multiFinished = 0;
    numberOfAI = 3;
    numberOfPlayers = 4;
    racingInGame = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racingInGameStart.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void racingInGameEnd(void) {
    raceGameType = raceGameStoredType;
    raceGameLaps = raceGameStoredLaps;
    raceGamePickups = raceGameStoredPickups;
    raceGameStartBoost = raceGameStoredStartBoost;
    numberOfPlayers = 1;
    racingInGame = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/racingInGameEnd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_31_01F038E0_1F4E530(s32 arg0, void *arg1, s32 arg2, s32 *arg3) {
    u32 *tbl;
    s32 idx;
    s32 k;
    u32 t0;
    u32 w;
    u32 *p;

    switch (raceGameIDNumber) {
    case 0:
        tbl = (u32 *) &globalflags;
        break;
    case 1:
        tbl = &D_800FF32C;
        break;
    case 2:
        tbl = &D_800FF340;
        break;
    case 3:
        tbl = &D_800FF354;
        break;
    default:
        tbl = &D_800FF368;
        break;
    }

    idx = 5;
    if ((u32) arg0 < (tbl[4] >> 18)) {
        do {
            idx--;
            if (idx <= 0) {
                break;
            }
        } while ((u32) arg0 < (tbl[idx - 1] >> 18));
    }

    if (idx != 5) {
        if (idx < 4) {
            for (k = 4; k > idx; k--) {
                /* shift the packed fields of entry k-1 into entry k */
                t0 = tbl[k - 1];
                w = tbl[k];
                w = ((((t0 >> 18) << 2) | ((w >> 16) & 3)) << 16) | (w & 0xFFFF);
                w = (((((t0 >> 12) & 0x3F) ^ (w >> 12)) & 0x3F) << 12) ^ w;
                w = (w & 0xFFFF0000) | ((w & 0xF03F) | (((t0 >> 6) & 0x3F) << 6));
                w = (w & 0xFFFFFF00) | ((w & 0xC0) | (t0 & 0x3F));
                tbl[k] = w;
            }
        }
        p = &tbl[idx];
        w = (((u32) ((arg0 << 2) | ((*p >> 16) & 3))) << 16) | (*p & 0xFFFF);
        *p = w;
        if (racingCharacter & 3) {
            w = *p;
            w = ((((w >> 12) ^ 9) & 0x3F) << 12) ^ w;
            w = (w & 0xFFFF0000) | ((w & 0xF03F) | 0x500);
            w = (w & 0xFFFFFF00) | ((w & 0xC0) | 0xD);
            *p = w;
        } else {
            w = *p;
            w = ((((w >> 12) ^ 0x15) & 0x3F) << 12) ^ w;
            w = (w & 0xFFFF0000) | ((w & 0xF03F) | 0x100);
            w = (w & 0xFFFFFF00) | ((w & 0xC0) | 0xB);
            *p = w;
        }
    } else {
        tbl = NULL;
    }
    *(u8 *) arg1 = (u8) idx;
    return (s32) tbl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/func_overlay_31_01F038E0_1F4E530.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprintShipCollision(void *arg0, void *arg1) {
    u8 *temp_v1;
    u8 *temp_s1;
    u8 *temp_s7;
    u8 *temp_s2;
    u8 *var_s4;
    u8 *var_s0;
    s16 temp_s6;
    s16 temp_s3;
    s32 var_s5;
    s32 i;
    s32 j;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 var_f12;
    f32 var_f20;
    f32 var_f22;

    temp_v1 = *(u8 **)((u8 *)arg0 + 0x4C);
    temp_s1 = *(u8 **)((u8 *)arg0 + 0x68);
    temp_s6 = *(s16 *)(temp_v1 + 0x32);
    temp_s7 = *(u8 **)((u8 *)arg1 + 0x4C);
    temp_s2 = *(u8 **)((u8 *)arg1 + 0x68);
    var_s4 = *(u8 **)(temp_v1 + 0x40);
    var_s5 = 0;

    for (i = 0; i < temp_s6; i++) {
        temp_s3 = *(s16 *)(temp_s7 + 0x32);
        var_s0 = *(u8 **)(temp_s7 + 0x40);
        for (j = 0; j < temp_s3; j++) {
            temp_f20 = (*(f32 *)(var_s4 + 0xC) + *(f32 *)(temp_s1 + 0x354)) - (*(f32 *)(var_s0 + 0xC) + *(f32 *)(temp_s2 + 0x354));
            temp_f26 = *(f32 *)(var_s4 + 0x10) - *(f32 *)(var_s0 + 0x10);
            temp_f22 = (*(f32 *)(var_s4 + 0x14) + *(f32 *)(temp_s1 + 0x35C)) - (*(f32 *)(var_s0 + 0x14) + *(f32 *)(temp_s2 + 0x35C));
            temp_f24 = *(f32 *)(var_s4 + 0x24) + *(f32 *)(var_s0 + 0x24);
            temp_f0 = sqrtf((temp_f20 * temp_f20) + (temp_f22 * temp_f22));
            var_s0 += 0x34;
            if ((-temp_f24 < temp_f26) && (temp_f26 < temp_f24) && (temp_f0 < temp_f24)) {
                if (temp_f0 != 0.0f) {
                    var_f12 = temp_f24 - temp_f0;
                    temp_f2 = var_f12 / (2.0f * temp_f0);
                    var_f20 = temp_f20 * temp_f2;
                    var_f22 = temp_f22 * temp_f2;
                } else {
                    var_f20 = 0.0f;
                    var_f22 = temp_f0 * -0.5f;
                    var_f12 = temp_f24 - temp_f0;
                }
                *(f32 *)(temp_s1 + 0x354) = *(f32 *)(temp_s1 + 0x354) + var_f20;
                *(f32 *)(temp_s1 + 0x35C) = *(f32 *)(temp_s1 + 0x35C) + var_f22;
                *(f32 *)(temp_s2 + 0x354) = *(f32 *)(temp_s2 + 0x354) - var_f20;
                *(f32 *)(temp_s2 + 0x35C) = *(f32 *)(temp_s2 + 0x35C) - var_f22;
                if (var_f12 > 5.0f) {
                    var_s5 = 1;
                }
            }
        }
        var_s4 += 0x34;
    }

    if (var_s5 != 0) {
        if (sprintAIPlayer(*(s8 *)temp_s1) == 0) {
            rumbleMax((s32) *(s8 *)temp_s1, 0x32, 0.2f);
        }
        if (sprintAIPlayer(*(s8 *)temp_s2) == 0) {
            /* asm: second rumble also targets temp_s1 (arg0), not temp_s2 */
            rumbleMax((s32) *(s8 *)temp_s1, 0x32, 0.2f);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o31/overlay_31/sprintShipCollision.s")
#endif
