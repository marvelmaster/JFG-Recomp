#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct DayKeyframe {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
} DayKeyframe; /* size 0x14 */

extern DayKeyframe D_overlay_23_017006E0[12];
extern UnkLight *D_overlay_23_017007D0;
extern s32 D_overlay_23_017007D4;
extern s32 D_overlay_23_017007E0;
extern s32 D_overlay_23_017007E4;
extern s32 D_overlay_23_017007E8;
extern s32 D_overlay_23_017007EC;
extern s32 D_overlay_23_017007F0;
extern s32 D_overlay_23_017007F4;
extern s32 D_overlay_23_017007F8;
extern s32 D_overlay_23_017007FC;
extern s32 D_overlay_23_01700800;
extern s32 D_overlay_23_01700804;
extern s32 D_overlay_23_01700808;
extern s32 D_overlay_23_0170080C;
extern s32 D_overlay_23_01700810;
void dayUpdate(s32 arg0);
void killLight(void *arg0);
void lightSetObjectLight(void *arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5);
Object **objGetObjList(s32 *arg0, s32 *arg1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dayInit(f32 arg0, s32 arg1) {
    ObjectHeader48 lightHdr = { 0, 3, 0x41, 0xFF, 0, 0, 0, 0, 100, 100, 0, 0x00FF, -1, 0 };
    LevelHeader *level;
    s32 temp_t9;

    D_overlay_23_017007E8 = arg1 * 2;
    temp_t9 = (s32) arg0 >> 1;
    D_overlay_23_017007E0 = temp_t9;
    D_overlay_23_017007E4 = (s32) ((arg0 - (f32) (temp_t9 * 2)) * (f32) arg1);
    D_overlay_23_017007D0 = (UnkLight *) addObjectLight(NULL, &lightHdr);
    level = levelGetLevel();
    D_overlay_23_0170080C = *(u8 *) ((u8 *) level + 0xDC);
    D_overlay_23_01700810 = *(u8 *) ((u8 *) level + 0xDE);
    D_overlay_23_017007D4 = 0;
    dayUpdate(0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o23/overlay_23/dayInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00023(void) {
    if (D_overlay_23_017007D0 != NULL) {
        killLight(D_overlay_23_017007D0);
        D_overlay_23_017007D0 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o23/overlay_23/_AutoExit00023.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Interpolates between two keyframe values by t (0x4000 = 1.0).
static s32 dayLerp(s32 a, s32 b, s32 t) {
    return a + (((b - a) * t) >> 0xE);
}

void dayUpdate(s32 arg0) {
    DayKeyframe *cur;
    DayKeyframe *next;
    UnkLight *light;
    LevelHeader *level;
    Object **list;
    Object *obj;
    s32 prevMonth;
    s32 month;
    s32 elapsed;
    s32 lo;
    s32 hour;
    s32 start;
    s32 end;
    s32 t7;
    s8 hourNext;

    if (D_overlay_23_017007D4 == 0 || D_overlay_23_017007E0 != 6 || D_overlay_23_017007E4 != 0) {
        prevMonth = D_overlay_23_017007E0;
        D_overlay_23_017007E4 += arg0;
        elapsed = D_overlay_23_017007E4;
        month = D_overlay_23_017007E0;
        if (elapsed >= D_overlay_23_017007E8) {
            do {
                month++;
                D_overlay_23_017007E0 = month;
                if (month >= 0xC) {
                    D_overlay_23_017007E0 = 0;
                    month = 0;
                }
                elapsed -= D_overlay_23_017007E8;
                D_overlay_23_017007E4 = elapsed;
            } while (elapsed >= D_overlay_23_017007E8);
        }
        if (D_overlay_23_017007D4 != 0 && prevMonth < 6 && month >= 6) {
            D_overlay_23_017007E0 = 6;
            month = 6;
            D_overlay_23_017007E4 = 0;
            elapsed = 0;
        }

        cur = &D_overlay_23_017006E0[month];
        next = (month < 0xB) ? &D_overlay_23_017006E0[month + 1] : &D_overlay_23_017006E0[0];
        lo = (s32) (elapsed << 0xE) / (s32) D_overlay_23_017007E8;

        D_overlay_23_017007EC = dayLerp(cur->unk0, next->unk0, lo);
        D_overlay_23_017007F0 = dayLerp(cur->unk1, next->unk1, lo);
        D_overlay_23_017007F4 = dayLerp(cur->unk2, next->unk2, lo);
        D_overlay_23_017007F8 = dayLerp(cur->unk3, next->unk3, lo);
        D_overlay_23_017007FC = dayLerp(cur->unk4, next->unk4, lo);
        D_overlay_23_01700800 = dayLerp(cur->unk5, next->unk5, lo);
        D_overlay_23_01700804 = dayLerp(cur->unk6, next->unk6, lo);
        D_overlay_23_01700808 = dayLerp(cur->unk8, next->unk8, lo);

        light = D_overlay_23_017007D0;
        if (light != NULL) {
            *(s16 *) ((u8 *) light + 0x5A) = (s16) dayLerp(cur->unkE, next->unkE, lo);
            *(s16 *) ((u8 *) light + 0x58) = (s16) dayLerp(cur->unk10, next->unk10, lo);
            light->unk2 |= 4;
            changeLightColour(light,
                              dayLerp(cur->unkA, next->unkA, lo) & 0xFF,
                              dayLerp(cur->unkB, next->unkB, lo) & 0xFF,
                              dayLerp(cur->unkC, next->unkC, lo) & 0xFF);
            changeLightIntensity(light, dayLerp(cur->unkD, next->unkD, lo) & 0xFF);
        }

        level = levelGetLevel();
        hour = dayLerp(cur->unk12, next->unk12, lo);
        hourNext = hour + 1;
        t7 = dayLerp(cur->unk13, next->unk13, lo);
        D_overlay_23_01700810 = t7;
        *(s8 *) ((u8 *) level + 0xDE) = (s8) t7;
        *(s8 *) ((u8 *) level + 0xDF) = 1;
        if (hour != D_overlay_23_0170080C) {
            D_overlay_23_0170080C = hour;
            *(s8 *) ((u8 *) level + 0xDC) = (s8) hour;
            *(s8 *) ((u8 *) level + 0xDB) = hourNext;
            list = objGetObjList(&start, &end);
            if (start < end) {
                do {
                    obj = list[start];
                    start++;
                    if (*(s32 *) ((u8 *) obj + 0x54) != 0) {
                        if (*(s8 *) (*(u8 **) ((u8 *) obj + 0x40) + 0x1E) == 0) {
                            if (*(u8 *) ((u8 *) obj + 0xA1) == 0) {
                                lightSetObjectLight((void *) (*(s32 *) ((u8 *) obj + 0x54) + 0x10), hour, hourNext, 0, 0, 0);
                            }
                        }
                    }
                } while (start < end);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o23/overlay_23/dayUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dayStopAtNoon(void) {
    D_overlay_23_017007D4 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o23/overlay_23/dayStopAtNoon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dayGetFog(s16 *arg0, s16 *arg1, s8 *arg2, s8 *arg3, s8 *arg4) {
    *arg0 = (s16) D_overlay_23_01700804;
    *arg1 = (s16) D_overlay_23_01700808;
    *arg2 = (s8) D_overlay_23_017007F8;
    *arg3 = (s8) D_overlay_23_017007FC;
    *arg4 = (s8) D_overlay_23_01700800;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o23/overlay_23/dayGetFog.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dayGetTrackFade(s32 *arg0, s32 *arg1, s32 *arg2) {
    *arg0 = D_overlay_23_017007EC;
    *arg1 = D_overlay_23_017007F0;
    *arg2 = D_overlay_23_017007F4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o23/overlay_23/dayGetTrackFade.s")
#endif
