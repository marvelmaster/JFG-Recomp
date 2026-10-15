#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void amSetMuteMode(s32 mode);
void frontSetInstrumentsHide(s32 hide);
void mainPauseDisable(s32 arg);
void *objGetObjList(s32 *start, s32 *end);
void *objGetPlayerNo(s32 player);
void *camGetListPtr(void);
s16 objTvTimes(s16 time, void *obj);
void rainResetCamera(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cutcameraInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *def = (u8 *)arg1;
    u8 *cut;

    cut = *(u8 **)(obj + 0x68);
    /* asm passes arg1 (the definition) as the second argument */
    *(s16 *)(cut + 0x14) = objTvTimes(*(s16 *)(def + 0x10), arg1);
    cut[0x17] = *(u8 *)(def + 0x12);
    *(s16 *)(obj + 0x4) = *(s16 *)(def + 0xA);
    *(s16 *)(obj + 0x2) = *(s16 *)(def + 0xC);
    *(s16 *)(obj + 0x0) = *(s16 *)(def + 0xE);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o85/overlay_85/cutcameraInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cutcameraActivate(s32 arg0) {
    s32 start;
    s32 end;
    void **list;
    s32 i;
    u8 *obj;
    u8 *cut;
    u8 *player;

    list = (void **)objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        obj = (u8 *)list[i];
        if (*(s16 *)(obj + 0x48) == 0x64) {
            cut = *(u8 **)(obj + 0x68);
            if (arg0 == cut[0x17]) {
                player = (u8 *)objGetPlayerNo(0);
                *(void **)(*(u8 **)(player + 0x68) + 0x5C0) = obj;
                joyDisable(0);
                mainPauseDisable(0xA);
                cut[0x16] = 0;
                *(s16 *)(cut + 0x12) = *(s16 *)(cut + 0x14);
                amSetMuteMode(2);
                frontSetInstrumentsHide(1);
                return;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o85/overlay_85/cutcameraActivate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cutcameraControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *cut;
    u8 *player;
    u8 *pd;
    u8 *slot;
    s8 *idx;

    cut = *(u8 **)(obj + 0x68);
    if (*(s16 *)(cut + 0x12) != 0) {
        if (arg1 < *(s16 *)(cut + 0x12)) {
            *(s16 *)(cut + 0x12) = (s16)(*(s16 *)(cut + 0x12) - arg1);
        } else {
            *(s16 *)(cut + 0x12) = 0;
            player = (u8 *)objGetPlayerNo(0);
            pd = *(u8 **)(player + 0x68);
            *(s32 *)(pd + 0x5C0) = 0;
            idx = (s8 *)pd;
            slot = (u8 *)camGetListPtr() + (*idx * 0x4C);
            *(f32 *)(slot + 0xC) = *(f32 *)(cut + 0x0);
            *(f32 *)(slot + 0x10) = *(f32 *)(cut + 0x4);
            *(f32 *)(slot + 0x14) = *(f32 *)(cut + 0x8);
            *(s16 *)(slot + 0x0) = *(s16 *)(cut + 0x10);
            *(s16 *)(slot + 0x2) = *(s16 *)(cut + 0xE);
            *(s16 *)(slot + 0x4) = *(s16 *)(cut + 0xC);
            amSetMuteMode(0);
            frontSetInstrumentsHide(0);
            joyEnable((s32)*idx);
            if (runlinkIsModuleLoaded(5) != 0) {
                rainResetCamera();
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o85/overlay_85/cutcameraControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cutcameraUpdate(void *arg0, void *arg1, s32 arg2) {
    u8 *cam = (u8 *)arg0;
    u8 *subj = (u8 *)arg1;
    u8 *cut;

    cut = *(u8 **)(subj + 0x68);
    if (cut[0x16] == 0) {
        *(f32 *)(cut + 0x0) = *(f32 *)(cam + 0xC);
        *(f32 *)(cut + 0x4) = *(f32 *)(cam + 0x10);
        *(f32 *)(cut + 0x8) = *(f32 *)(cam + 0x14);
        *(s16 *)(cut + 0x10) = *(s16 *)(cam + 0x0);
        *(s16 *)(cut + 0xE) = *(s16 *)(cam + 0x2);
        cut[0x16] = 1;
        *(s16 *)(cut + 0xC) = *(s16 *)(cam + 0x4);
    }
    *(f32 *)(cam + 0xC) = *(f32 *)(subj + 0xC);
    *(f32 *)(cam + 0x10) = *(f32 *)(subj + 0x10);
    *(f32 *)(cam + 0x14) = *(f32 *)(subj + 0x14);
    *(s16 *)(cam + 0x0) = (s16)(0x8000 - *(s16 *)(subj + 0x0));
    *(s16 *)(cam + 0x2) = (s16)-*(s16 *)(subj + 0x2);
    *(s16 *)(cam + 0x4) = *(s16 *)(subj + 0x4);
    if (runlinkIsModuleLoaded(5) != 0) {
        rainResetCamera();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o85/overlay_85/cutcameraUpdate.s")
#endif
