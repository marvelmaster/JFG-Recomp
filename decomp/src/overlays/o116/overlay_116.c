#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_116_07400500;
extern s8 raceGamePickups;
extern s8 raceGameSingleScreen;
void amSndPlay(s32 soundId, void *handle);
void amSndPlayXYZ(s32 soundId, f32 x, f32 y, s32 z, s32 arg4, s32 arg5);
s32 hitPlayer(f32 x, f32 y, s32 z, f32 r, s32 flag, void *out);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg1);
void sprintPickedUpBomb(s8 a, s32 b);
void sprintPickedUpBoost(s8 a, s32 b);
void sprintPickedUpOil(s8 a, s32 b);
void sprintHitBomb(s32 a);
void sprintHitOilSlick(s32 a);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void racepickupInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    s16 v = *(s16 *) (src + 0x0A);

    if (v == 0) {
        *(s32 *) (obj + 0x88) = 0;
        *(s32 *) (obj + 0x8C) = 0x1FF;
        return;
    }
    *(s32 *) (obj + 0x88) = (s32) v * 0x3C;
    *(s32 *) (obj + 0x8C) = 0xFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o116/overlay_116/racepickupInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void racepickupControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    void *hitObj = NULL;
    s32 v = *(s32 *) (obj + 0x8C);
    s32 hitResult;
    s32 t;

    if (v >= 0x100) {
        s16 id = *(s16 *) (obj + 0x4A);
        s8 mask;

        if (id == 0x275) {
            mask = 2;
        } else if (id == 0x276) {
            mask = 4;
        } else {
            mask = 1;
        }
        v = 0xFF;
        if (!(raceGamePickups & mask)) {
            objFreeObject(arg0);
            return;
        }
        *(s32 *) (obj + 0x8C) = 0xFF;
    }
    if (v != 0) {
        t = v + (arg1 << 3);
        *(s32 *) (obj + 0x8C) = t;
        if (t >= 0x100) {
            *(s32 *) (obj + 0x8C) = 0xFF;
        }
    }
    if (raceGameSingleScreen == 0) {
        *(s16 *) (obj + 0x00) = (s16) (*(s16 *) (obj + 0x00) + (arg1 << 9));
    } else {
        *(s16 *) (obj + 0x02) = (s16) (*(s16 *) (obj + 0x02) + (arg1 << 9));
    }
    hitResult = hitPlayer(*(f32 *) (obj + 0x0C), *(f32 *) (obj + 0x10), *(s32 *) (obj + 0x14), 64.0f, 1, &hitObj);
    if (*(s32 *) (obj + 0x8C) == 0) {
        t = *(s32 *) (obj + 0x88) + arg1;
        *(s32 *) (obj + 0x88) = t;
        if (hitResult == 0 && t >= 0x168) {
            *(s32 *) (obj + 0x88) = 0;
            *(s32 *) (obj + 0x8C) = 1;
        }
    } else {
        if (hitResult != 0) {
            s8 *kind = *(s8 **) ((u8 *) hitObj + 0x68);

            switch (*(s16 *) (obj + 0x4A)) {
            case 0x275:
                sprintPickedUpOil(*kind, arg1);
                break;
            case 0x276:
                sprintPickedUpBomb(*kind, arg1);
                break;
            default:
                sprintPickedUpBoost(*kind, arg1);
                break;
            }
            if (raceGameSingleScreen != 0) {
                amSndPlay(0x193, 0);
            } else {
                amSndPlayXYZ(0x193, *(f32 *) (obj + 0x0C), *(f32 *) (obj + 0x10), *(s32 *) (obj + 0x14), 4, 0);
            }
            if (*(s32 *) (obj + 0x88) == 0) {
                *(s32 *) (obj + 0x8C) = 0;
                return;
            }
            objFreeObject(arg0);
            return;
        }
        t = *(s32 *) (obj + 0x88);
        if (t != 0) {
            s32 t5 = t - arg1;

            *(s32 *) (obj + 0x88) = t5;
            if (t5 <= 0) {
                objFreeObject(arg0);
                return;
            }
            if (t5 < 0x40) {
                *(s32 *) (obj + 0x8C) = t5 * 4;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o116/overlay_116/racepickupControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void raceobstacleInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    u8 *d = *(u8 **) (obj + 0x68);

    *(s32 *) (d + 0x00) = (s32) *(s16 *) (src + 0x0A);
    *(s32 *) (d + 0x04) = *(s32 *) (src + 0x0C);
    *(s32 *) (obj + 0x8C) = 0xFF;
    if (raceGameSingleScreen == 0) {
        *(f32 *) (obj + 0x08) = *(f32 *) (obj + 0x08) * D_overlay_116_07400500;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o116/overlay_116/raceobstacleInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void raceobstacleControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    f32 px = *(f32 *) (obj + 0x0C);
    f32 py = *(f32 *) (obj + 0x10);
    s32 pz = *(s32 *) (obj + 0x14);
    s32 hits[8]; /* out array size guessed from the stack layout */
    s32 count;
    s32 i;
    s32 others = 0;
    s32 self = 0;
    s32 t;

    count = hitPlayer(px, py, pz, 64.0f, 0, hits);
    if (count != 0) {
        for (i = count - 1; i >= 0; i--) {
            s32 hit = hits[i];

            if (*(s32 *) (d + 0x04) == hit) {
                self = 1;
            } else {
                others += 1;
                if (*(s16 *) (obj + 0x4A) == 0x278) {
                    sprintHitOilSlick(hit);
                } else {
                    sprintHitBomb(hit);
                }
            }
        }
    }
    if (self == 0) {
        *(s32 *) (d + 0x04) = 0;
    }
    if (others == 0) {
        t = *(s32 *) (d + 0x00) - arg1;
        *(s32 *) (d + 0x00) = t;
        if (t <= 0) {
            objFreeObject(arg0);
            return;
        }
        if (t < 0x40) {
            *(s32 *) (obj + 0x8C) = t * 4;
        }
    } else {
        switch (*(s16 *) (obj + 0x4A)) {
        case 0x278:
            amSndPlayXYZ(0x21D, px, py, pz, 4, 0);
            break;
        case 0x1FB:
            amSndPlay(0x21D, 0);
            break;
        case 0x279:
            *(s32 *) (obj + 0x84) = 1;
            partUpdateTriggers(arg0, 2);
            if (raceGameSingleScreen != 0) {
                amSndPlay(0x22, 0);
            } else {
                amSndPlayXYZ(0x22, px, py, pz, 4, 0);
            }
            break;
        }
        objFreeObject(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o116/overlay_116/raceobstacleControl.s")
#endif
