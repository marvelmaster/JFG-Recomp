#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 D_800A400C;
extern s32 D_800A4010;
extern void *D_800A4014;
extern void *D_800A4018;
extern s32 D_800A401C;
extern void (*D_800A4020)(Gfx **dlist, s32 arg1);
extern s32 D_800A4024;
extern s32 D_800A4028;
extern s32 D_800A402C;
extern s32 D_800A4030;
extern u8 D_800A403C[];
extern u8 D_800A4060[];
extern u8 D_800A4168[];
extern u8 D_800A4084[];
extern u8 D_800A40A8[];
extern u8 D_800A40E8[];
extern u8 D_800A41B0[];
extern u8 D_800A41F8[];
extern u8 D_800A4240[];
extern u8 D_800A4278[];
extern u8 D_800A42B8[];
extern u32 texFrame(void *arg0, s32 arg1);
extern u8 D_800FF220;
extern u8 D_800FF221;
extern u8 D_800FF222;
extern u8 D_800FF223;
extern u8 D_800FF224;
extern u8 D_800FF225;
extern u8 D_800FF226;
extern u8 D_800FF227;
extern s32 D_800FF228;
extern s32 D_800FF22C;
extern u8 D_800FF230[];
extern u8 D_800FF310[];
extern u8 D_800FF3F0[];
extern u8 D_800FF4D0[];
extern u8 D_800FED90[];
extern u8 D_800FFE40_B2840[];
extern u8 D_800B0350_B0F50[];
extern u8 D_8009F250_9FE50[];
extern u8 D_8009F3D0_9FFD0[];
extern OSMesgQueue *D_800FF5B0;
extern OSMesgQueue cloneDoneMsgQueue;
extern OSMesgQueue D_800FF190;
extern void *D_800FF1A8;
extern OSMesgQueue D_800FF1B0;
extern void *D_800FF1E0;
extern void *D_800FF200;
extern void *D_800FF5D0;
extern void *D_800FF608;
extern void *D_800FF640;
extern s32 camIsUserView(s32 arg0);
extern s32 camGetVisibleUserView(s32 arg0, s32 *x0, s32 *y0, s32 *x1, s32 *y1);
void rcpCheckClear(Gfx **dlist);
void rcpMosaicClear(Gfx **dlist);
void rcpClearZBuffer(Gfx **dlist, s32 screenW, s32 screenH, s32 x0, s32 y0, s32 x1, s32 y1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 rcpFast3d(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *task = NULL;
    s32 taskType;

    D_800A4034 = 1;
    taskType = 3;
    switch (arg2) {
    default:
        /* asm: falls through with the uninitialised stack slot sp1C as the task */
        break;
    case 0:
        task = D_800FF230 + D_800A4024 * 0x70;
        D_800A4024 ^= 1;
        taskType = 0x23;
        *(u32 *)(task + 0x50) = (u32)&D_800FF1C8;
        *(u32 *)(task + 0x58) = 0xFF0000FF;
        *(u32 *)(task + 0x5C) = 0xFF0000FF;
        *(s32 *)(task + 0x6C) = 2;
        break;
    case 3:
        task = D_800FF310 + D_800A4028 * 0x70;
        D_800A4028 ^= 1;
        *(u32 *)(task + 0x50) = (u32)&cloneDoneMsgQueue;
        *(u32 *)(task + 0x54) = (u32)&D_800A403C;
        *(u32 *)(task + 0x58) = 0xFF00FFFF;
        *(u32 *)(task + 0x5C) = 0xFF00FFFF;
        *(s32 *)(task + 0x6C) = 5;
        break;
    case 4:
        task = D_800FF3F0 + D_800A402C * 0x70;
        D_800A402C ^= 1;
        *(u32 *)(task + 0x50) = (u32)&refractDoneMsgQueue;
        *(u32 *)(task + 0x54) = (u32)&D_800A4060;
        *(u32 *)(task + 0x58) = 0xFFFF00FF;
        *(u32 *)(task + 0x5C) = 0xFFFF00FF;
        *(s32 *)(task + 0x6C) = 6;
        break;
    case 5:
        task = D_800FF4D0 + D_800A4030 * 0x70;
        D_800A4030 ^= 1;
        *(u32 *)(task + 0x50) = (u32)&D_800FF628;
        *(u32 *)(task + 0x54) = (u32)&D_800A4084;
        *(u32 *)(task + 0x58) = 0xFF00FF;
        *(u32 *)(task + 0x5C) = 0xFF00FF;
        *(s32 *)(task + 0x6C) = 7;
        break;
    }
    *(s32 *)(task + 0x68) = 0;
    *(u32 *)(task + 0x30) = (u32)&D_800FED90;
    *(s32 *)(task + 0x34) = 0x400;
    *(u32 *)(task + 0x48) = (u32)&D_800FFE40_B2840;
    *(s32 *)(task + 0x4C) = 0xA00;
    *(s32 *)(task + 0x08) = taskType;
    *(s32 *)(task + 0x40) = arg0;
    *(u32 *)(task + 0x18) = (u32)&D_8009F250_9FE50;
    *(s32 *)(task + 0x44) = (arg1 - arg0) >> 3;
    *(s32 *)(task + 0x10) = 1;
    *(s32 *)(task + 0x14) = 2;
    *(s32 *)(task + 0x1C) = (s32)(D_8009F3D0_9FFD0 - D_8009F250_9FE50);
    *(u32 *)(task + 0x20) = (u32)&D_8009F3D0_9FFD0;
    *(u32 *)(task + 0x28) = (u32)&D_800B0350_B0F50;
    *(s32 *)(task + 0x2C) = 0x800;
    *(s32 *)(task + 0x38) = 0;
    *(s32 *)(task + 0x3C) = 0;
    *(s32 *)(task + 0x00) = 0;
    *(s32 *)(task + 0x0C) = arg3;
    *(s32 *)(task + 0x60) = 0xFF;
    *(s32 *)(task + 0x64) = 0xFF;
    osWritebackDCacheAll();
    osSendMesg(D_800FF5B0, task, 1);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpFast3d.s")
#endif

s32 rcpWaitDP(void) {
    s32 *unkMsg = NULL;
    s32 *refractDoneMsg = NULL;
    s32 *blurDoneMsg = NULL;

    if (D_800A4034 == FALSE) {
        return 0;
    }
    osRecvMesg(&D_800FF1C8, (OSMesg) &unkMsg, OS_MESG_BLOCK);
    if (blurTaskActive) {
        osRecvMesg(&D_800FF628, (OSMesg) &blurDoneMsg, OS_MESG_BLOCK);
        blurTaskActive = FALSE;
    }
    if (refractTaskActive) {
        osRecvMesg(&refractDoneMsgQueue, (OSMesg) &refractDoneMsg, OS_MESG_BLOCK);
        refractTaskActive = FALSE;
    }
    if (cloneTaskActive) {
        TrapDanglingJump();
        cloneTaskActive = FALSE;
    }
    D_800A4034 = FALSE;
    return unkMsg[1];
}

/**
 * Sets the primitive colour for the cyclemode fillrect background.
 */
void rcpSetScreenColour(u8 red, u8 green, u8 blue) {
    sBackgroundPrimColourR = red;
    sBackgroundPrimColourG = green;
    sBackgroundPrimColourB = blue;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpSetBorderColour(s32 arg0, s32 arg1, s32 arg2) {
    s32 colour;

    colour = ((arg0 << 8) & 0xF800) | ((arg1 * 8) & 0x7C0) | ((arg2 >> 2) & 0x3E) | 1;
    *(volatile s32 *)&D_800A400C = colour;
    D_800A400C = colour | (colour << 0x10);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpSetBorderColour.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpClearZBuffer(Gfx **dlist, s32 screenW, s32 screenH, s32 x0, s32 y0, s32 x1, s32 y1) {
    Gfx *cmd;
    u32 wMinus1;
    u32 hMinus1;
    s32 zTile;

    if (otherZbuf != 0 && x0 < x1 && y0 < y1) {
        wMinus1 = screenW - 1;
        hMinus1 = screenH - 1;
        zTile = (wMinus1 & 0xFFF) | 0xFF100000;

        cmd = (*dlist)++;
        cmd->words.w0 = 0xE7000000;
        cmd->words.w1 = 0;
        cmd = (*dlist)++;
        cmd->words.w0 = 0xED000000;
        cmd->words.w1 = (((s32)((f32)wMinus1 * 4.0f) & 0xFFF) << 0xC) | ((s32)((f32)hMinus1 * 4.0f) & 0xFFF);
        cmd = (*dlist)++;
        cmd->words.w0 = 0xEF30000F;
        cmd->words.w1 = 0;
        cmd = (*dlist)++;
        cmd->words.w0 = zTile;
        cmd->words.w1 = 0x02000000;
        cmd = (*dlist)++;
        cmd->words.w0 = 0xF7000000;
        cmd->words.w1 = 0xFFFCFFFC;
        cmd = (*dlist)++;
        cmd->words.w0 = 0xF6000000 | (((x1 + 3) & ~3 & 0x3FF) << 0xE) | ((y1 & 0x3FF) * 4);
        cmd->words.w1 = (((x0 & ~3) & 0x3FF) << 0xE) | ((y0 & 0x3FF) * 4);
        cmd = (*dlist)++;
        cmd->words.w0 = 0xE7000000;
        cmd->words.w1 = 0;
        cmd = (*dlist)++;
        cmd->words.w0 = zTile;
        cmd->words.w1 = 0x01000000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpClearZBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpClearScreen(Gfx **dlist, s32 arg1, s32 arg2) {
    s32 screenW;
    s32 screenH;
    s32 userView;
    s32 visX0;
    s32 visY0;
    s32 visX1;
    s32 visY1;
    s32 colour;
    Gfx *cmd;

    viGetCurrentSize(&screenW, &screenH);
    rcpClearZBuffer(dlist, screenW, screenH, 0, 0, screenW, screenH);
    if (arg2 != 0) {
        userView = camIsUserView(0);
        if (D_800A401C != 0) {
            rcpCheckClear(dlist);
        } else if (D_800A4014 != NULL) {
            rcpMosaicClear(dlist);
        } else if (D_800A4020 != NULL) {
            D_800A4020(dlist, arg1);
        } else {
            cmd = (*dlist)++;
            cmd->words.w0 = 0xF7000000;
            if (userView != 0) {
                cmd->words.w1 = D_800A400C;
            } else {
                colour = ((sBackgroundPrimColourR << 8) & 0xF800) | ((sBackgroundPrimColourG * 8) & 0x7C0)
                       | (((s32)sBackgroundPrimColourB >> 2) & 0x3E) | 1;
                cmd->words.w1 = (colour << 0x10) | colour;
            }
            cmd = (*dlist)++;
            cmd->words.w0 = (((screenW - 1) & 0x3FF) << 0xE) | 0xF6000000 | (((screenH - 1) & 0x3FF) * 4);
            cmd->words.w1 = 0;
        }
        if (userView != 0 && camGetVisibleUserView(0, &visX0, &visY0, &visX1, &visY1) != 0) {
            cmd = (*dlist)++;
            cmd->words.w1 = 0;
            cmd->words.w0 = 0xBA001402;
            cmd = (*dlist)++;
            cmd->words.w0 = 0xFA000000;
            cmd->words.w1 = (sBackgroundPrimColourR << 0x18) | (sBackgroundPrimColourG << 0x10)
                          | (sBackgroundPrimColourB << 8) | 0xFF;
            cmd = (*dlist)++;
            cmd->words.w1 = 0xFFFDF6FB;
            cmd->words.w0 = 0xFCFFFFFF;
            cmd = (*dlist)++;
            cmd->words.w1 = 0x0F0A4000;
            cmd->words.w0 = 0xB900031D;
            cmd = (*dlist)++;
            cmd->words.w0 = ((visX1 & 0x3FF) << 0xE) | 0xF6000000 | ((visY1 & 0x3FF) * 4);
            cmd->words.w1 = ((visX0 & 0x3FF) << 0xE) | ((visY0 & 0x3FF) * 4);
        }
    }
    cmd = (*dlist)++;
    cmd->words.w1 = 0;
    cmd->words.w0 = 0xE7000000;
    camSetScissor(dlist);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpClearScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpInitDp(Gfx **dList) {
    s32 screenW;
    s32 screenH;
    s32 pad[2];
    Gfx *cmd;

    viGetCurrentSize(&screenW, &screenH);
    cmd = (*dList)++;
    cmd->words.w1 = 0;
    cmd->words.w0 = 0xE7000000;
    cmd = (*dList)++;
    cmd->words.w1 = 0x01000000;
    cmd->words.w0 = ((screenW - 1) & 0xFFF) | 0xFF100000;
    cmd = (*dList)++;
    cmd->words.w0 = 0xFE000000;
    cmd->words.w1 = 0x02000000;
    gSPDisplayList((*dList)++, D_800A40E8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpInitDp.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpInitDpNoSize(Gfx **dList) {
    gSPDisplayList((*dList)++, D_800A40E8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpInitDpNoSize.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpInitSp(Gfx **dList) {
    gSPDisplayList((*dList)++, D_800A40A8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpInitSp.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpInit(OSSched *sc) {
    D_800FF5B0 = osScGetInterruptQ(sc);
    osCreateMesgQueue(&D_800FF190, &D_800FF1A8, 1);
    osCreateMesgQueue(&D_800FF1B0, &D_800FF1E0, 8);
    osCreateMesgQueue(&D_800FF1C8, &D_800FF200, 8);
    osCreateMesgQueue(&cloneDoneMsgQueue, &D_800FF5D0, 8);
    osCreateMesgQueue(&refractDoneMsgQueue, &D_800FF608, 8);
    osCreateMesgQueue(&D_800FF628, &D_800FF640, 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Two-pass mosaic clear. Emits a G_DL call to the header DL at D_800A4168, then
// a G_DMADL for the texture in D_800A4014 and a grid of textured-rect quads
// (3 cmds each) covering the screen, stepping by the texture size. If
// D_800A4018 is set, a second G_DMADL and a second grid pass follow, using
// screen size x16 (the asm multiplies W/H by 4 again; cf. DKR bgdraw_texture,
// which notes the same double *4). Texture header layout from
// include/structs.h TextureHeader: width @0, height @1, numberOfCommands @0xA,
// cmd @0xC (same as the DKR bgdraw_texture TextureHeader fields).
void rcpMosaicClear(Gfx **dlist) {
    TextureHeader *tex;
    TextureHeader *tex2;
    Gfx *cmd;
    s32 screenW;
    s32 screenH;
    s32 passes;
    s32 pass;
    s32 limW;
    s32 limH;
    s32 tileW;
    s32 tileH;
    s32 rectH;
    s32 yStep;
    s32 yStart;
    s32 mask;
    s32 xOff;
    s32 x;
    s32 y;
    s32 xEnd;
    s32 t1;
    s32 t2;

    viGetCurrentSize(&screenW, &screenH);
    tex = (TextureHeader *)D_800A4014;
    tex2 = (TextureHeader *)D_800A4018;

    cmd = *dlist;
    cmd->words.w0 = 0x06000000;             /* G_DL */
    cmd->words.w1 = (u32)D_800A4168;
    cmd++;

    cmd->words.w0 = 0x07000000 | ((tex->numberOfCommands & 0xFF) << 16) | ((tex->numberOfCommands * 8) & 0xFFFF); /* G_DMADL */
    cmd->words.w1 = (u32)tex->cmd + 0x80000000;
    cmd++;

    tileW = tex->width * 4;                 /* x step, also the quad width */
    tileH = tex->height * 4;                /* first-pass row height */
    limW = screenW * 4;
    limH = screenH * 4;
    yStep = tileH;
    if (tex2 != NULL) {
        yStep = tex2->height * 4 + tileH;
    }
    mask = tileW - 1;

    passes = (tex2 != NULL) ? 2 : 1;
    yStart = 0;
    rectH = tileH;
    for (pass = 0; pass < passes; pass++) {
        if (pass == 1) {
            cmd->words.w0 = 0x07000000 | ((tex2->numberOfCommands & 0xFF) << 16) | ((tex2->numberOfCommands * 8) & 0xFFFF); /* G_DMADL */
            cmd->words.w1 = (u32)tex2->cmd + 0x80000000;
            cmd++;

            limW = screenW * 16;
            limH = screenH * 16;
            yStart = tileH;
            rectH = tex2->height * 4;
        }

        xOff = 0;
        for (y = yStart; (u32)y < (u32)limH; y += yStep) {
            t1 = (y + rectH) & 0xFFF;
            t2 = y & 0xFFF;
            for (x = -xOff; (u32)x < (u32)limW; x += tileW) {
                xEnd = x + tileW;
                if (x < 0) {
                    cmd->words.w0 = 0xE4000000 | ((xEnd & 0xFFF) << 12) | t1;
                    cmd->words.w1 = t2;
                    cmd++;
                    cmd->words.w0 = 0xB3000000;
                    cmd->words.w1 = (u32)(x * -0x80000);   /* clip offset: -x*8 << 16 */
                    cmd++;
                    cmd->words.w0 = 0xB2000000;
                    cmd->words.w1 = 0x04000400;
                    cmd++;
                } else {
                    cmd->words.w0 = 0xE4000000 | ((xEnd & 0xFFF) << 12) | t1;
                    cmd->words.w1 = ((x & 0xFFF) << 12) | t2;
                    cmd++;
                    cmd->words.w0 = 0xB3000000;
                    cmd->words.w1 = 0;
                    cmd++;
                    cmd->words.w0 = 0xB2000000;
                    cmd->words.w1 = 0x04000400;
                    cmd++;
                }
            }
            xOff = (xOff + D_800A4010) & mask;
        }
    }

    cmd->words.w0 = 0xE7000000;             /* G_RDPPIPESYNC */
    cmd->words.w1 = 0;
    cmd++;
    *dlist = cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpMosaicClear.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rcpCheckClear(Gfx **dlist) {
    s32 screenW;
    s32 screenH;
    s32 x;
    s32 y;
    s32 parity;
    Gfx *cmd;

    viGetCurrentSize(&screenW, &screenH);
    cmd = (*dlist)++;
    cmd->words.w0 = 0x06000000;
    cmd->words.w1 = (u32)&D_800A41B0;
    cmd = (*dlist)++;
    cmd->words.w0 = 0xFA000000;
    cmd->words.w1 = (D_800FF220 << 0x18) | (D_800FF221 << 0x10) | (D_800FF222 << 8) | D_800FF223;

    y = 0;
    parity = 0;
    if (screenH != 0) {
        do {
            x = parity * D_800FF228;
            while ((u32)x < (u32)screenW) {
                cmd = (*dlist)++;
                cmd->words.w1 = ((x & 0x3FF) << 0xE) | ((y & 0x3FF) * 4);
                cmd->words.w0 = (((x + D_800FF228) & 0x3FF) << 0xE) | 0xF6000000 | (((y + D_800FF22C) & 0x3FF) * 4);
                x += D_800FF228 * 2;
            }
            y += D_800FF22C;
            parity ^= 1;
        } while ((u32)y < (u32)screenH);
    }

    y = 0;
    cmd = (*dlist)++;
    cmd->words.w0 = 0xFA000000;
    cmd->words.w1 = (D_800FF224 << 0x18) | (D_800FF225 << 0x10) | (D_800FF226 << 8) | D_800FF227;
    parity = 1;
    if (screenH != 0) {
        do {
            x = parity * D_800FF228;
            while ((u32)x < (u32)screenW) {
                cmd = (*dlist)++;
                cmd->words.w1 = ((x & 0x3FF) << 0xE) | ((y & 0x3FF) * 4);
                cmd->words.w0 = (((x + D_800FF228) & 0x3FF) << 0xE) | 0xF6000000 | (((y + D_800FF22C) & 0x3FF) * 4);
                x += D_800FF228 * 2;
            }
            y += D_800FF22C;
            parity ^= 1;
        } while ((u32)y < (u32)screenH);
    }

    cmd = (*dlist)++;
    cmd->words.w1 = 0;
    cmd->words.w0 = 0xE7000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpCheckClear.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Walks a 0xC-byte entry array {void *tile; s32 frame; s16 x; s16 y} (a NULL
// tile terminates) and emits, per visible tile, a 5-command quad into the DL,
// bracketed by a DL call and a prim colour set (colour = r,g,b,a).
// Tile record: u8 w @0, u8 h @1, s16 (h-1 source) @0xA, data ptr @0xC.
// Layout of the emitted commands follows the asm (gbi-style words).
void rcpTileWrite(Gfx **dlist, void *arg1, s32 xOff, s32 yOff, u8 r, u8 g, u8 b, u8 a) {
    Gfx *cmd;
    u8 *entry;
    u8 *tile;
    s32 xOff4;
    s32 yOff4;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 clipX;
    s32 clipY;
    s32 hm1;

    cmd = *dlist;
    cmd->words.w0 = 0x06000000;             /* G_DL */
    cmd->words.w1 = (u32)D_800A41F8;
    cmd++;
    cmd->words.w0 = 0xFA000000;             /* G_SETPRIMCOLOR */
    cmd->words.w1 = (r << 24) | (g << 16) | (b << 8) | a;
    cmd++;

    xOff4 = xOff * 4;
    yOff4 = yOff * 4;
    entry = (u8 *)arg1;
    tile = *(u8 **)entry;
    if (tile != NULL) {
        do {
            left = *(s16 *)(entry + 8) * 4 + xOff4;
            top = *(s16 *)(entry + 0xA) * 4 + yOff4;
            right = tile[0] * 4 + left;
            bottom = tile[1] * 4 + top;
            if (right > 0 && bottom > 0) {
                clipX = 0;
                clipY = 0;
                if (left < 0) {
                    clipX = -(left * 8);
                    left = 0;
                }
                if (top < 0) {
                    clipY = -(top * 8);
                    top = 0;
                }
                cmd->words.w0 = *(u32 *)(*(u8 **)(tile + 0xC));
                /* sig mismatch: texFrame takes 2 args, asm passes 4 */
                cmd->words.w1 = ((u32 (*)(void *, s32, s32, s32))texFrame)(tile, *(s32 *)(entry + 4), xOff, yOff4)
                                + 0x80000000;
                cmd++;

                hm1 = *(s16 *)(tile + 0xA) - 1;
                cmd->words.w0 = 0x07000000 | ((hm1 & 0xFF) << 16) | ((hm1 * 8) & 0xFFFF);
                cmd->words.w1 = *(u32 *)(tile + 0xC) + 0x80000008;
                cmd++;

                cmd->words.w0 = 0xE4000000 | ((right & 0xFFF) << 12) | (bottom & 0xFFF);
                cmd->words.w1 = ((left & 0xFFF) << 12) | (top & 0xFFF);
                cmd++;

                cmd->words.w0 = 0xB3000000;
                cmd->words.w1 = (clipX << 16) | (clipY & 0xFFFF);
                cmd++;

                cmd->words.w0 = 0xB2000000;
                cmd->words.w1 = 0x04000400;
                cmd++;
            }
            tile = *(u8 **)(entry + 0xC);
            entry += 0xC;
        } while (tile != NULL);
    }

    cmd->words.w0 = 0xE7000000;             /* G_RDPPIPESYNC */
    cmd->words.w1 = 0;
    cmd++;
    cmd->words.w0 = 0xFA000000;             /* G_SETPRIMCOLOR */
    cmd->words.w1 = 0xFFFFFFFF;
    cmd++;
    *dlist = cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpTileWrite.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Extended rcpTileWrite: same 12-byte entry walk and 5-command quad per tile,
// but positions and sizes are scaled by sx/sy (f32), a palette row is selected
// from the colour alpha/flag bytes, and the flags 0x1000 / 0x2000 mirror the
// tile in X / Y (edges are then taken from the origin and extended backwards).
// Clipping is against the current VI size; the texture S/T start offsets and
// the per-pixel S/T steps (dsdx/dtdy, 12-bit fraction) are emitted as B3/B2.
void rcpTileWriteX(Gfx **dlist, void *arg1, f32 x, f32 y, f32 sx, f32 sy, s32 colour, s32 flag) {
    Gfx *cmd;
    u8 *entry;
    u8 *tile;
    u8 *pal;
    s32 scrW;
    s32 scrH;
    f32 sx4;
    f32 sy4;
    s32 xOff4;
    s32 yOff4;
    s32 xs;
    s32 ys;
    s32 wpx;
    s32 hpx;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 sOff;
    s32 tOff;
    s32 dsdx;
    s32 dtdy;
    s32 hm1;

    viGetCurrentSize(&scrW, &scrH);
    scrW *= 4;
    scrH *= 4;
    sx4 = sx * 4.0f;
    sy4 = sy * 4.0f;
    xOff4 = (s32)(x * 4.0f);
    yOff4 = (s32)(y * 4.0f);

    /* palette row: table A if the colour's low byte is 0xFF, else table B; row = flag & 0xFF */
    if ((colour & 0xFF) == 0xFF) {
        pal = D_800A4278 + (flag & 0xFF) * 0x10;
    } else {
        pal = D_800A42B8 + (flag & 0xFF) * 0x10;
    }

    cmd = *dlist;
    cmd->words.w0 = 0x06000000;             /* G_DL */
    cmd->words.w1 = (u32)D_800A4240;
    cmd++;
    cmd->words.w0 = 0x07020010;
    cmd->words.w1 = (u32)pal + 0x80000000;
    cmd++;
    cmd->words.w0 = 0xFA000000;             /* G_SETPRIMCOLOR */
    cmd->words.w1 = colour;
    cmd++;

    entry = (u8 *)arg1;
    tile = *(u8 **)entry;
    if (tile != NULL) {
        do {
            xs = *(s16 *)(entry + 8);
            ys = *(s16 *)(entry + 0xA);
            wpx = (s32)((f32)tile[0] * sx4);
            hpx = (s32)((f32)tile[1] * sy4);

            if (flag & 0x1000) {
                right = xOff4 - (s32)((f32)xs * sx4);
                left = right - wpx;
            } else {
                left = (s32)((f32)xs * sx4) + xOff4;
                right = left + wpx;
            }
            if (flag & 0x2000) {
                bottom = yOff4 - (s32)((f32)ys * sy4);
                top = bottom - hpx;
            } else {
                top = (s32)((f32)ys * sy4) + yOff4;
                bottom = top + hpx;
            }

            if (left < scrW && top < scrH && right > 0 && bottom > 0 && left < right && top < bottom) {
                sOff = 0;
                tOff = 0;
                dsdx = (((s32)tile[0] - 1) << 12) / (right - left);
                dtdy = (((s32)tile[1] - 1) << 12) / (bottom - top);
                if (flag & 0x1000) {
                    sOff = ((s32)tile[0] - 1) << 5;
                    dsdx = -dsdx;
                }
                if (flag & 0x2000) {
                    tOff = ((s32)tile[1] - 1) << 5;
                    dtdy = -dtdy;
                }
                if (left < 0) {
                    sOff += (-left * dsdx) >> 7;
                    left = 0;
                }
                if (top < 0) {
                    tOff += (-top * dtdy) >> 7;
                    top = 0;
                }

                cmd->words.w0 = *(u32 *)(*(u8 **)(tile + 0xC));
                cmd->words.w1 = texFrame(tile, *(s32 *)(entry + 4)) + 0x80000000;
                cmd++;

                hm1 = *(s16 *)(tile + 0xA) - 1;
                cmd->words.w0 = 0x07000000 | ((hm1 & 0xFF) << 16) | ((hm1 * 8) & 0xFFFF);
                cmd->words.w1 = (u32)(*(u8 **)(tile + 0xC) + 8) + 0x80000000;
                cmd++;

                cmd->words.w0 = 0xE4000000 | ((right & 0xFFF) << 12) | (bottom & 0xFFF);
                cmd->words.w1 = ((left & 0xFFF) << 12) | (top & 0xFFF);
                cmd++;

                cmd->words.w0 = 0xB3000000;
                cmd->words.w1 = (sOff << 16) | (tOff & 0xFFFF);
                cmd++;

                cmd->words.w0 = 0xB2000000;
                cmd->words.w1 = (dsdx << 16) | (dtdy & 0xFFFF);
                cmd++;
            }
            tile = *(u8 **)(entry + 0xC);
            entry += 0xC;
        } while (tile != NULL);
    }

    cmd->words.w0 = 0xE7000000;             /* G_RDPPIPESYNC */
    cmd->words.w1 = 0;
    cmd++;
    cmd->words.w0 = 0xFA000000;             /* G_SETPRIMCOLOR */
    cmd->words.w1 = 0xFFFFFFFF;
    cmd++;
    *dlist = cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/rcpFast3d/rcpTileWriteX.s")
#endif
