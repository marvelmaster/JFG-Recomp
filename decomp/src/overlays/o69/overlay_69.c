#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 objSetupObject(void *spawn, s32 arg1);
void **objGetObjList(s32 *first, s32 *last);
s32 hitVectorCheck(s32 arg0, void *arg1, s32 arg2, void **arg3, void **arg4, s32 arg5);
void fxDrawLineInWindow(s16 x0, s16 y0, s16 x1, s16 y1, s32 colour, s32 arg5);
void texDPTextureX(void **gfx, s32 arg1, s32 arg2, s32 arg3);
void camStandardOrtho(void);
void fontUseFont(s32 font);
void fontBackground(s32 r, s32 g, s32 b, s32 a);
void fontColour(u8 r, u8 g, u8 b, u8 a, s32 flags);
void fontPrintXY(void **gfx, s32 x, s32 y, char *text, s32 flags);
void frontDrawRectangle(void **gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void fxScreenEffect(void **gfx, s32 *src, s32 w, s32 h, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 colour);
void rcpTileWriteX(void **gfx, void *tile, s32 arg2, s32 arg3, f32 scaleX, f32 scaleY, s32 colour, s32 flags);
void func_overlay_69_045014D0_1FA49B8(void **arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 *otherScreen;
extern s32 D_overlay_69_04502000[];
extern s32 D_overlay_69_04502010;
extern s32 D_overlay_69_04502014;
extern s8 D_overlay_69_04501F08[];
extern s8 D_overlay_69_04501F50[];
extern u32 D_overlay_69_04501EF8[];
extern s32 D_overlay_69_04501D48[];
extern void *D_overlay_69_04501DCC[];
extern u8 D_overlay_69_04501DE4[];
extern char D_overlay_69_04501FB0[];
extern char D_overlay_69_04501FBC[];
extern char D_overlay_69_04501FC0[];
extern char D_overlay_69_04501FC8[];
extern char D_overlay_69_04501FCC[];
extern char D_overlay_69_04501FD8[];
extern char D_overlay_69_04501FDC[];
extern char D_overlay_69_04501FE4[];
extern u8 D_84501F68[];
extern u8 *front_text;
extern u16 gameoverFade;
extern s8 multiFinished;
extern s32 currentGameTime;
extern s32 multiGameTime;
extern s8 clayPigeonCursor;
extern f32 D_overlay_69_04501E04[];
extern f32 D_overlay_69_04501FE8;
extern f32 D_overlay_69_04501FEC;
extern f32 D_overlay_69_04501FF0;
extern f32 D_overlay_69_04501FF4;
extern f32 D_overlay_69_04501FF8;
extern f32 D_overlay_69_04501FFC;
extern u8 D_overlay_69_04501BA0[];
extern u8 D_overlay_69_04501C60[];
void *camGetPtr(void);
s32 camProjectPoint(f32 x, f32 y, f32 z, f32 *sx, f32 *sy, s32 flag);
void camReversePoint(f32 x, f32 y, f32 *ox, f32 *oy, f32 *oz, s32 flag);
f32 Powerf(f32 base, s32 n);
s32 trackNearestIntersection(s32 a, void *from, void *to, void *out, s32 mask, s32 c);
void amSndPlay(u16 soundID, void *handlePtr);
s32 func_overlay_69_0450135C_1FA4844(s32 arg0, f32 *arg1, void *arg2, f32 *arg3);
void func_overlay_69_04500A84_1FA3F6C(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 animseqCamera(s32 n, void *cam);
s16 trackGetBlock(f32 x, f32 y, f32 z);
void texFreeTexture(TextureHeader *tex);
void mainFrontInit(s32 arg0, s32 arg1, s32 arg2);
void amTuneSetFade(f32 fade, u8 volume);
extern u8 multiPlayer;
extern void *orderedPlayers[];
extern s32 D_overlay_69_04501D34[];
extern s16 D_overlay_69_04501DFC[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void duckshootInit(s32 arg0) {
    u8 spawn[0x12];
    s32 i;

    for (i = 0; i < arg0; i++) {
        *(s16 *)(spawn + 0x00) = 0x23E;
        spawn[0x02] = 0x12;
        *(s16 *)(spawn + 0x04) = 0;
        *(s16 *)(spawn + 0x06) = 0;
        *(s16 *)(spawn + 0x08) = 0;
        *(s16 *)(spawn + 0x0A) = 0;
        *(s16 *)(spawn + 0x0C) = 0;
        *(s16 *)(spawn + 0x0E) = 0;
        spawn[0x10] = (u8) i;
        spawn[0x11] = 0;
        D_overlay_69_04502000[i] = objSetupObject(spawn, 1);
    }
    currentGameTime = multiGameTime;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o69/overlay_69/duckshootInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Duck-shoot main update: while the round timer runs, every player's aim point is
// steered (func_A84). When the timer runs out, the per-player score records
// (multiPlayer, 0xA0 bytes each) are filled from the target objects, bubble-sorted
// by score, ranked, and the winner is picked. multiFinished then walks the
// end-of-round state machine (1 = fade in, 2 = wait for button, 3 = fade out, 4 = done).
void duckshootUpdate(s32 arg0, s32 arg1) {
    u8 *cam;
    u8 *obj;
    u8 *stats;
    u8 *e;
    u8 *cur;
    u8 *prev;
    u8 *pa;
    u8 *pb;
    u8 *first;
    s16 rot[3];
    s32 *pts;
    s32 k;
    s32 swapped;
    s32 rank;
    s32 pressed;
    s32 fade;
    s8 absX;
    s8 absY;
    u16 buttons;

    cam = (u8 *) camGetPtr();
    animseqCamera(0, cam);

    if (multiFinished == 0) {
        if (currentGameTime != 0) {
            currentGameTime -= arg1;

            if (currentGameTime > 0) {
                /* round still running: steer each player's aim point */
                rot[0] = (s16) (-0x8000 - *(s16 *) (cam + 0x00));
                rot[1] = (s16) -*(s16 *) (cam + 0x02);
                rot[2] = (s16) -*(s16 *) (cam + 0x04);
                pts = (s32 *) D_overlay_69_04501D34[arg0];

                for (k = 0; k < arg0; k++) {
                    obj = (u8 *) D_overlay_69_04502000[k];
                    pointListRPY(1, rot, (s32 *) ((u8 *) pts + k * 0xC), (f32 *) (obj + 0xC));

                    *(f32 *) (obj + 0xC) = *(f32 *) (obj + 0xC) + *(f32 *) (cam + 0xC);
                    *(f32 *) (obj + 0x10) = *(f32 *) (obj + 0x10) + *(f32 *) (cam + 0x10);
                    *(f32 *) (obj + 0x14) = *(f32 *) (obj + 0x14) + *(f32 *) (cam + 0x14);
                    *(s16 *) (obj + 0x2E) = trackGetBlock(*(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10),
                                                          *(f32 *) (obj + 0x14));

                    absX = joyGetAbsX(k);
                    absY = joyGetAbsY(k);
                    buttons = joyGetButtons(k);
                    pressed = joyGetPressed(k);
                    func_overlay_69_04500A84_1FA3F6C(obj, *(void **) (obj + 0x68), absX, absY, (s32) buttons,
                                                     pressed, arg1);
                }
            } else {
                /* round over: build the score records and rank the players */
                currentGameTime = 0;

                if (arg0 > 0) {
                    k = 0;
                    if (arg0 & 1) {
                        /* player 0 */
                        obj = (u8 *) D_overlay_69_04502000[0];
                        stats = *(u8 **) (obj + 0x68);
                        e = (u8 *) &multiPlayer;
                        e[0x8C] = stats[0];
                        *(u16 *) (e + 0x00) = *(u16 *) (stats + 0x6);
                        *(u16 *) (e + 0x08) = *(u16 *) (stats + 0x4);
                        *(s16 *) (e + 0x10) = (s16) (*(u16 *) (stats + 0x6) - *(u16 *) (stats + 0x4));
                        if (*(u16 *) (stats + 0x2) != 0) {
                            *(s32 *) (e + 0x90) = (s32) ((s32) (*(u16 *) (stats + 0x6) * 0x64) /
                                                         (s32) *(u16 *) (stats + 0x2));
                        } else {
                            *(s32 *) (e + 0x90) = 0;
                        }
                        orderedPlayers[0] = e;
                        k = 1;
                    }

                    for (; k < arg0; k += 2) {
                        /* player k */
                        obj = (u8 *) D_overlay_69_04502000[k];
                        stats = *(u8 **) (obj + 0x68);
                        e = (u8 *) &multiPlayer + k * 0xA0;
                        e[0x8C] = stats[0];
                        *(u16 *) (e + 0x00) = *(u16 *) (stats + 0x6);
                        *(u16 *) (e + 0x08) = *(u16 *) (stats + 0x4);
                        *(s16 *) (e + 0x10) = (s16) (*(u16 *) (stats + 0x6) - *(u16 *) (stats + 0x4));
                        if (*(u16 *) (stats + 0x2) != 0) {
                            *(s32 *) (e + 0x90) = (s32) ((s32) (*(u16 *) (stats + 0x6) * 0x64) /
                                                         (s32) *(u16 *) (stats + 0x2));
                        } else {
                            *(s32 *) (e + 0x90) = 0;
                        }
                        orderedPlayers[k] = e;

                        /* player k + 1 */
                        obj = (u8 *) D_overlay_69_04502000[k + 1];
                        stats = *(u8 **) (obj + 0x68);
                        e = (u8 *) &multiPlayer + (k + 1) * 0xA0;
                        e[0x8C] = stats[0];
                        *(u16 *) (e + 0x00) = *(u16 *) (stats + 0x6);
                        *(u16 *) (e + 0x08) = *(u16 *) (stats + 0x4);
                        *(s16 *) (e + 0x10) = (s16) (*(u16 *) (stats + 0x6) - *(u16 *) (stats + 0x4));
                        if (*(u16 *) (stats + 0x2) != 0) {
                            *(s32 *) (e + 0x90) = (s32) ((s32) (*(u16 *) (stats + 0x6) * 0x64) /
                                                         (s32) *(u16 *) (stats + 0x2));
                        } else {
                            *(s32 *) (e + 0x90) = 0;
                        }
                        orderedPlayers[k + 1] = e;
                    }
                }

                /* bubble sort orderedPlayers (descending on unk10, then on unk90) */
                do {
                    swapped = 1;
                    for (k = 0; k < arg0 - 1; k++) {
                        pa = (u8 *) orderedPlayers[k];
                        pb = (u8 *) orderedPlayers[k + 1];
                        if ((*(s16 *) (pa + 0x10) < *(s16 *) (pb + 0x10)) ||
                            ((*(s16 *) (pb + 0x10) == *(s16 *) (pa + 0x10)) &&
                             ((u32) *(s32 *) (pa + 0x90) < (u32) *(s32 *) (pb + 0x90)))) {
                            orderedPlayers[k] = pb;
                            orderedPlayers[k + 1] = pa;
                            swapped = 0;
                        }
                    }
                } while (swapped == 0);

                /* rank: equal (unk10, unk90) share the rank of the first of them (1-based) */
                if (arg0 > 0) {
                    prev = NULL;
                    rank = 0;
                    for (k = 0; k < arg0; k++) {
                        cur = (u8 *) orderedPlayers[k];
                        if ((prev == NULL) || (*(s16 *) (prev + 0x10) != *(s16 *) (cur + 0x10)) ||
                            (*(s32 *) (prev + 0x90) != *(s32 *) (cur + 0x90))) {
                            rank = k + 1;
                        }
                        cur[0x14] = (u8) rank;
                        prev = cur;
                    }
                }

                /* winner: player 0 if ranks of first two differ, otherwise draw (-1) */
                first = (u8 *) orderedPlayers[0];
                if (first[0x14] != ((u8 *) orderedPlayers[1])[0x14]) {
                    D_overlay_69_04502010 = (s32) first[0x8C];
                } else {
                    D_overlay_69_04502010 = -1;
                }
                multiFinished = 1;
                D_overlay_69_04502014 = 0;

                if ((D_overlay_69_04502010 >= 0) && (D_overlay_69_04502010 < 4)) {
                    *(void **) &D_overlay_69_04501DE4 =
                        texLoadTexture(D_overlay_69_04501DFC[D_overlay_69_04502010]);
                }
            }
        }
    } else {
        switch (multiFinished) {
        case 1:
            /* fade in the result banner */
            D_overlay_69_04502014 = D_overlay_69_04502014 + arg1;
            if (D_overlay_69_04502014 >= 0xFF) {
                D_overlay_69_04502014 = 0xFE;
            }
            fade = gameoverFade + arg1;
            gameoverFade = (u16) fade;
            if ((fade & 0xFFFF) >= 0x100) {
                gameoverFade = 0xFF;
                multiFinished = 2;
            }
            break;

        case 2:
            /* wait for any player to press A/Start */
            if (arg0 > 0) {
                k = 0;
                do {
                    pressed = joyGetPressed(k);
                    k++;
                    if (pressed & 0x9000) {
                        amTuneSetFade(1.0f, 0);
                        multiFinished = 3;
                        break;
                    }
                } while (k != arg0);
            }
            break;

        case 3:
            /* fade out */
            D_overlay_69_04502014 = D_overlay_69_04502014 - (arg1 * 8);
            if (D_overlay_69_04502014 <= 0) {
                D_overlay_69_04502014 = 0;
                mainFrontInit(0x16, 0, 0);
                texFreeTexture(*(TextureHeader **) &D_overlay_69_04501DE4);
                *(void **) &D_overlay_69_04501DE4 = NULL;
                multiFinished = 4;
            }
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o69/overlay_69/duckshootUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Duck/clay-pigeon aim update: moves the aim point in screen space, steers the
// state record (arg1) velocities, projects two corners of the view frustum,
// raycasts along the aim ray and, when requested (arg5 & 0x2000), spawns a
// shot object (spawn record layout cf. duckshootInit).
void func_overlay_69_04500A84_1FA3F6C(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 spawn[0x24];
    u8 hit[0x24];
    u8 *cam;
    u8 *pl;
    u8 *st;
    s16 rot[3];
    s32 vpW;
    s32 vpH;
    s32 x;
    s32 y;
    s32 hitCount;
    s32 v1;
    f32 blend;
    f32 velX;
    f32 velY;
    f32 tgtX;
    f32 tgtY;
    f32 aimX;
    f32 aimY;
    f32 aimPosX;
    f32 aimPosY;
    f32 corner0[3];
    f32 corner1[3];
    f32 world1[3];
    f32 world2[3];
    f32 scr1x;
    f32 scr1y;
    f32 scr2x;
    f32 scr2y;
    f32 p0[3];
    f32 p1[3];
    f32 dX;
    f32 dY;
    f32 hdx;
    f32 hdy;
    f32 hdz;
    f32 hx;
    f32 hy;
    f32 hz;
    f32 frac;
    f32 hitDist;
    f32 dxs;
    f32 dys;
    f32 dzs;
    void *spawned;
    u16 yaw;
    u16 pitch;

    /* asm: arg4 (0x158) is never read */
    (void) arg4;

    cam = (u8 *) camGetPtr();
    pl = (u8 *) arg0;
    st = (u8 *) arg1;
    viGetCurrentSize(&vpW, &vpH);
    x = arg2;
    y = arg3;

    if (clayPigeonCursor == 0) {
        /* absolute mode: clamp x to [-0x44, 0x44], y to [-0x34, 0x34], aim at screen point */
        if (x >= 0x45) {
            x = 0x44;
        } else if (x < -0x44) {
            x = -0x44;
        }
        if (y >= 0x35) {
            y = 0x34;
        }
        if (y < -0x34) {
            y = -0x34;
        }
        aimX = (f32) (s32) ((x * 2) + ((u32) vpW >> 1));
        aimY = (f32) (s32) ((y * 2) + ((u32) vpH >> 1));
        blend = 1.0f - Powerf(D_overlay_69_04501FE8, arg6); /* asm also has x,y in a2/a3; Powerf takes (base, n) */
    } else {
        /* relative mode: 5-unit dead zone around 0, step towards it, clamp to +-0x3C */
        if (x >= -5 && x < 6) {
            x = 0;
        } else if (x > 0) {
            x -= 5;
            if (x >= 0x3D) {
                x = 0x3C;
            }
        } else {
            x += 5;
            if (x < -0x3C) {
                x = -0x3C;
            }
        }
        if (y >= -5 && y < 6) {
            y = 0;
        } else if (y > 0) {
            y -= 5;
            if (y >= 0x3D) {
                y = 0x3C;
            }
        } else {
            y += 5;
            if (y < -0x3C) {
                y = -0x3C;
            }
        }

        blend = 1.0f - Powerf(D_overlay_69_04501FEC, arg6); /* asm also has x,y in a2/a3; Powerf takes (base, n) */

        if (x < 0) {
            tgtX = -D_overlay_69_04501E04[-x];
        } else {
            tgtX = D_overlay_69_04501E04[x];
        }
        velX = *(f32 *) (st + 0x18);
        *(f32 *) (st + 0x18) = velX + ((tgtX - velX) * blend);
        if (x == 0) {
            velX = *(f32 *) (st + 0x18);
            if ((D_overlay_69_04501FF0 < velX) && (velX < D_overlay_69_04501FF4)) {
                *(f32 *) (st + 0x18) = 0.0f;
            }
        }

        if (y < 0) {
            tgtY = -D_overlay_69_04501E04[-y];
        } else {
            tgtY = D_overlay_69_04501E04[y];
        }
        velY = *(f32 *) (st + 0x1C);
        *(f32 *) (st + 0x1C) = velY + ((tgtY - velY) * blend);
        if (y == 0) {
            velY = *(f32 *) (st + 0x1C);
            if ((D_overlay_69_04501FF8 < velY) && (velY < D_overlay_69_04501FFC)) {
                *(f32 *) (st + 0x1C) = 0.0f;
            }
        }

        /* integrate velocity arg6 times (asm: do/while counter decremented in delay slot => arg6 iterations) */
        aimX = *(f32 *) (st + 0x10);
        aimY = *(f32 *) (st + 0x14);
        if (arg6 != 0) {
            velX = *(f32 *) (st + 0x18);
            velY = *(f32 *) (st + 0x1C);
            v1 = arg6 - 1;
            do {
                aimX += velX;
                if (clayPigeonCursor == 1) {
                    aimY -= velY;
                } else {
                    aimY += velY;
                }
            } while (v1-- != 0);
        }

        if (aimX < 24.0f) {
            aimX = 24.0f;
            *(f32 *) (st + 0x18) = 0.0f;
        }
        if (296.0f < aimX) {
            aimX = 296.0f;
            *(f32 *) (st + 0x18) = 0.0f;
        }
        if (aimY < 16.0f) {
            aimY = 16.0f;
            *(f32 *) (st + 0x1C) = 0.0f;
        }
        blend = 1.0f;
        if (224.0f < aimY) {
            *(f32 *) (st + 0x1C) = 0.0f;
            aimY = 224.0f;
        }
    }

    /* blend the aim position towards the target (both modes) */
    velX = *(f32 *) (st + 0x10);
    *(f32 *) (st + 0x10) = velX + ((aimX - velX) * blend);
    velY = *(f32 *) (st + 0x14);
    *(f32 *) (st + 0x14) = velY + ((aimY - velY) * blend);
    aimPosX = *(f32 *) (st + 0x10);
    aimPosY = *(f32 *) (st + 0x14);

    /* frustum corners: (-16, 16, -16) and (16, -16, -16) projected, then reversed to world space */
    corner0[0] = -16.0f;
    corner0[1] = 16.0f;
    corner0[2] = -16.0f;
    corner1[0] = 16.0f;
    corner1[1] = -16.0f;
    corner1[2] = -16.0f;
    world1[2] = -2048.0f;
    world2[2] = -2048.0f;

    if ((camProjectPoint(corner0[0], corner0[1], corner0[2], &scr1x, &scr1y, 0) != 0) &&
        (camProjectPoint(corner1[0], corner1[1], corner1[2], &scr2x, &scr2y, 0) != 0)) {
        camReversePoint(scr1x, scr1y, &world1[0], &world1[1], &world1[2], 0);
        camReversePoint(scr2x, scr2y, &world2[0], &world2[1], &world2[2], 0);

        dX = scr2x - scr1x;
        dY = scr1y - scr2y;

        /* interpolate the two aim-ray end points from the aim position */
        p0[0] = corner0[0] + ((aimPosX - scr1x) * ((corner1[0] - corner0[0]) / dX));
        p0[1] = corner0[1] + ((aimPosY - scr1y) * ((corner0[1] - corner1[1]) / dY));
        p0[2] = corner0[2];
        p1[0] = world1[0] + ((aimPosX - scr1x) * ((world2[0] - world1[0]) / dX));
        p1[1] = world1[1] + ((aimPosY - scr1y) * ((world1[1] - world2[1]) / dY));
        p1[2] = world1[2];

        /* camera rotation (s16 yaw/pitch/roll at cam+0,+2,+4) applied to both points */
        rot[0] = (s16) (-0x8000 - *(s16 *) (cam + 0x00));
        rot[1] = (s16) -*(s16 *) (cam + 0x02);
        rot[2] = (s16) -*(s16 *) (cam + 0x04);

        pointListRPY(1, rot, (s32 *) p0, p0);
        p0[0] += *(f32 *) (cam + 0x0C);
        p0[1] += *(f32 *) (cam + 0x10);
        p0[2] += *(f32 *) (cam + 0x14);

        pointListRPY(1, rot, (s32 *) p1, p1);
        p1[0] += *(f32 *) (cam + 0x0C);
        p1[1] += *(f32 *) (cam + 0x10);
        p1[2] += *(f32 *) (cam + 0x14);

        hitCount = trackNearestIntersection(0, p0, p1, hit, 0, 0);
        hx = p1[0];
        hy = p1[1];
        hz = p1[2];

        /* asm passes arg6 in the 5th stack slot; func_135C never reads it */
        if ((hitCount | func_overlay_69_0450135C_1FA4844((s32) arg0, p0, p1, &frac)) != 0) {
            hdx = p0[0] - p1[0];
            hdy = p0[1] - p1[1];
            hdz = p0[2] - p1[2];
            /* hit record distance float (asm sp90 = trackNearest out record + 0x20) */
            hitDist = *(f32 *) (hit + 0x20);
            frac = 1.0f - (hitDist / sqrtf((hdx * hdx) + (hdy * hdy) + (hdz * hdz)));
            hx += hdx * frac;
            hy += hdy * frac;
            hz += hdz * frac;
        }

        if (((arg5 & 0x2000) != 0) && (*(s16 *) (st + 0x0C) != 0)) {
            dxs = *(f32 *) (pl + 0x0C) - hx;
            dys = hy - *(f32 *) (pl + 0x10);
            dzs = *(f32 *) (pl + 0x14) - hz;

            /* spawn record (base sp4C) */
            *(s16 *) (spawn + 0x00) = 0x50;
            *(s16 *) (spawn + 0x04) = (s16) (s32) *(f32 *) (pl + 0x0C);
            *(s16 *) (spawn + 0x06) = (s16) (s32) *(f32 *) (pl + 0x10);
            *(s16 *) (spawn + 0x08) = (s16) (s32) *(f32 *) (pl + 0x14);
            spawn[0x0A] = 1;
            spawn[0x0B] = 10;
            yaw = Arctanf(dxs, dzs);
            *(u16 *) (spawn + 0x0C) = yaw;
            pitch = Arctanf(dys, sqrtf((dxs * dxs) + (dzs * dzs)));
            *(u16 *) (spawn + 0x0E) = pitch;
            spawn[0x10] = 0;
            spawn[0x11] = 0;
            spawn[0x13] = st[0x00];
            *(f32 *) (spawn + 0x14) = 100.0f;
            *(void **) (spawn + 0x18) = arg0;
            *(void **) (spawn + 0x1C) = D_overlay_69_04501BA0;
            *(void **) (spawn + 0x20) = D_overlay_69_04501C60;

            spawned = (void *) objSetupObject(spawn, 1);
            if (spawned != NULL) {
                *(s32 *) ((u8 *) spawned + 0x3C) = 0;
            }

            *(u16 *) (st + 0x02) = (u16) (*(u16 *) (st + 0x02) + 1);
            if (*(s16 *) (st + 0x0C) > 0) {
                *(s16 *) (st + 0x0C) = (s16) (*(s16 *) (st + 0x0C) - 1);
            }

            amSndPlay(0xDA, NULL);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o69/overlay_69/func_overlay_69_04500A84_1FA3F6C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_69_0450135C_1FA4844(s32 arg0, f32 *arg1, void *arg2, f32 *arg3) {
    void *hitList[0x100];
    f32 hitPos[3];
    void *hitObj;
    void **list;
    s32 first;
    s32 last;
    s32 count;
    s32 n;
    s32 k;
    u8 *obj;
    u8 *hit;
    u8 *def;
    f32 dx;
    f32 d2;

    list = objGetObjList(&first, &last);
    count = last - first;
    list += first;
    n = 0;
    for (k = 0; k < count; k++) {
        obj = (u8 *) list[k];
        hit = *(u8 **)(obj + 0x4C);
        if (hit != NULL) {
            def = *(u8 **)(obj + 0x40);
            if (*(u16 *)(def + 0x14) & 0x40) {
                if (hit[0x30] == 1 || hit[0x30] == 2) {
                    hitList[n] = obj;
                    n++;
                }
            }
        }
    }
    if (n > 0) {
        n = hitVectorCheck(0, hitPos, n, hitList, &hitObj, arg0);
    }
    if (n > 0) {
        dx = arg1[0] - *(f32 *)((u8 *) hitObj + 0x10);
        d2 = dx * dx;
        *arg3 = sqrtf((2.0f * d2) + d2);
    }
    return n;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o69/overlay_69/func_overlay_69_0450135C_1FA4844.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_69_045014D0_1FA49B8(void **arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4) {
    s8 *rec;
    s8 *vrec;
    u8 *vtx;
    u32 *gfx;
    s32 i;

    if ((arg2 >= 0) && (arg2 < 4)) {
        rec = D_overlay_69_04501F08;
        for (i = 0; i < 0xD; i++) {
            fxDrawLineInWindow((s16) (rec[0] + arg3), (s16) (rec[1] + arg4), (s16) (rec[2] + arg3),
                               (s16) (rec[3] + arg4), rec[4], 0);
            rec += 5;
        }

        vtx = *arg1;
        vrec = D_overlay_69_04501F50;
        for (i = 0; i < 0xB; i++) {
            *(s16 *)(vtx + 0x0) = (s16) (vrec[0] + (arg3 - 0xA0));
            *(s16 *)(vtx + 0x2) = (s16) (vrec[1] + (0x78 - arg4));
            *(s16 *)(vtx + 0x4) = 1;
            vtx[0x6] = 0xFF;
            vtx[0x7] = 0xFF;
            vtx[0x8] = 0xFF;
            vtx[0x9] = 0xFF;
            vtx += 0xA;
            vrec += 2;
        }

        texDPTextureX(arg0, 0, 5, 0);

        gfx = (u32 *) *arg0;
        *arg0 = (u8 *) gfx + 8;
        gfx[0] = 0xFA000000;
        gfx[1] = D_overlay_69_04501EF8[arg2];

        gfx = (u32 *) *arg0;
        *arg0 = (u8 *) gfx + 8;
        gfx[0] = (((((u32) *arg1 + 0x80000000) & 6) | 0x60) & 0xFF) << 16 | 0x04000080;
        gfx[1] = (u32) *arg1 + 0x80000000;

        gfx = (u32 *) *arg0;
        *arg0 = (u8 *) gfx + 8;
        gfx[1] = (u32) D_84501F68;
        gfx[0] = 0x05300040;

        gfx = (u32 *) *arg0;
        *arg0 = (u8 *) gfx + 8;
        gfx[1] = 0;
        gfx[0] = 0xE7000000;

        gfx = (u32 *) *arg0;
        *arg0 = (u8 *) gfx + 8;
        gfx[1] = -1;
        gfx[0] = 0xFA000000;

        *arg1 = vtx;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o69/overlay_69/func_overlay_69_045014D0_1FA49B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void duckshootDrawTargets(void **arg0, void *arg1, void **arg2, s32 arg3) {
    char sp74[0x10];
    s32 sp70;
    s32 sp6C;
    s32 i;
    s32 temp;
    s16 *rec;
    u8 *col;
    u8 *obj;
    u8 *stats;
    s32 yBase;
    char *label;

    camStandardOrtho();
    for (i = 0; i < arg3; i++) {
        obj = (u8 *) D_overlay_69_04502000[i];
        stats = *(u8 **)(obj + 0x68);
        func_overlay_69_045014D0_1FA49B8(arg0, arg2, i, (s32) *(f32 *)(stats + 0x10), (s32) *(f32 *)(stats + 0x14));
    }

    if (multiFinished != 0) {
        fontUseFont(1);
        fontBackground(0, 0, 0, 0);
        viGetCurrentSize(&sp70, &sp6C);
        temp = (0xFF - gameoverFade) << 8;
        fxScreenEffect(arg0, otherScreen, sp70, sp6C, 0, 0, sp70, sp6C, (temp << 8) | temp | 0xFF000000);
        if ((D_overlay_69_04502010 >= 0) && (D_overlay_69_04502010 < 4)) {
            label = *(char **)(front_text + 0x820);
            yBase = 0x40;
            rcpTileWriteX(arg0, D_overlay_69_04501DE4, 0x43210000, 0x42A20000, 1.5f, 1.5f,
                          D_overlay_69_04502014, 1);
            rcpTileWriteX(arg0, D_overlay_69_04501DE4, 0x43200000, 0x42A00000, 1.5f, 1.5f,
                          (D_overlay_69_04501D48[D_overlay_69_04502010] & ~0xFF) | D_overlay_69_04502014, 1);
        } else {
            label = *(char **)(front_text + 0x81C);
            yBase = 0x48;
        }
        fontColour(0, 0, 0, 0xFF, D_overlay_69_04502014);
        fontPrintXY(arg0, 0xA1, yBase + 1, label, 0xC);
        fontColour(0xFF, 0xFF, 0, 0xFF, D_overlay_69_04502014);
        fontPrintXY(arg0, 0x9F, yBase - 1, label, 0xC);
    }

    fontUseFont(2);
    fontBackground(0, 0, 0, 0);
    frontDrawRectangle(arg0, 0, 0xC0, 0x140, 0xF0, 0x80);

    rec = (s16 *) D_overlay_69_04501DCC[arg3];
    for (i = 0; i < arg3; i++) {
        obj = (u8 *) D_overlay_69_04502000[i];
        stats = *(u8 **)(obj + 0x68);
        col = (u8 *) &D_overlay_69_04501D48[i];
        fontColour(col[0], col[1], col[2], 0xFF, 0xF0);
        fontPrintXY(arg0, rec[0], rec[1], D_overlay_69_04501FB0, 1);
        sprintf(sp74, D_overlay_69_04501FBC, *(u16 *)(stats + 0x2));
        fontPrintXY(arg0, rec[0], rec[1], sp74, 0);
        fontPrintXY(arg0, rec[2], rec[3], D_overlay_69_04501FC0, 1);
        sprintf(sp74, D_overlay_69_04501FC8, *(u16 *)(stats + 0x6));
        fontPrintXY(arg0, rec[2], rec[3], sp74, 0);
        fontPrintXY(arg0, rec[4], rec[5], D_overlay_69_04501FCC, 1);
        sprintf(sp74, D_overlay_69_04501FD8, *(u16 *)(stats + 0x4));
        fontPrintXY(arg0, rec[4], rec[5], sp74, 0);
        if (*(s16 *)(stats + 0xC) >= 0) {
            fontPrintXY(arg0, rec[4], rec[5] + 0xA, D_overlay_69_04501FDC, 1);
            sprintf(sp74, D_overlay_69_04501FE4, *(s16 *)(stats + 0xC));
            fontPrintXY(arg0, rec[4], rec[5] + 0xA, sp74, 0);
        }
        rec += 6;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o69/overlay_69/duckshootDrawTargets.s")
#endif
