#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void *objGetPlayerNo(s32 arg0);
void objFreeObject(void *obj);
s32 mainAnyoneHas(s32 arg0);
s32 mainGetGameFlag(s32 arg0);
s32 mainPlayerHas(s8 arg0, s8 arg1, u8 arg2);
s32 mainPlayerHasWeapon(s8 arg0, s8 arg1, u8 arg2);
void mainPlayerCollected(f32 arg0, s8 arg1, s8 arg2, u8 arg3);
void instQueueMsg(void *obj, s32 msg);
void amSndPlay(u16 soundID, void *handlePtr);
void amDittyPlay(s32 seqID);
void partUpdateTriggers(void *obj, s32 arg1);
extern s16 D_overlay_43_02B00400[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void collectableInit(void *arg0, void *arg1) {
    *(u8 *)((u8 *)arg0 + 0x3A) = 0;
    *(s32 *)((u8 *)arg0 + 0x88) = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o43/overlay_43/collectableInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void collectableControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *player;
    u8 *s3;
    u8 *ent;
    u8 *p;
    s32 res[2];
    s32 k;
    s16 nextId;
    s16 q;
    s16 snd;
    s16 id;
    s32 g0;
    s32 g1;
    s32 g2;
    u16 v0u;
    f32 dx;
    f32 dy;
    f32 dz;

    if (*(s8 *)(obj + 0x3A) != 0) {
        return;
    }
    player = objGetPlayerNo(0);
    if (player == NULL) {
        objFreeObject(arg0);
        return;
    }
    s3 = *(u8 **)(player + 0x68);
    ent = (u8 *)D_overlay_43_02B00400;
    if (*(s16 *)ent != -1) {
        if (*(s16 *)(obj + 0x4A) != *(s16 *)ent) {
            do {
                nextId = *(s16 *)(ent + 0x20);
                ent += 0x20;
                if (nextId == -1) {
                    break;
                }
            } while (*(s16 *)(obj + 0x4A) != nextId);
        }
    }

    if (*(s32 *)(obj + 0x88) != 0) {
        /* asm loop runs twice: p = ent + 1, then p = ent */
        for (k = 1; k >= 0; k--) {
            p = ent + k;
            switch (p[4]) {
            case 0:
                res[k] = mainGetGameFlag(p[6]);
                break;
            case 1:
                res[k] = mainPlayerHas(*(s8 *)s3, *(s8 *)(s3 + 1), p[6]);
                break;
            case 2:
                res[k] = mainPlayerHasWeapon(*(s8 *)s3, *(s8 *)(s3 + 1), p[6]);
                break;
            case 3:
                res[k] = mainAnyoneHas(p[6]);
                break;
            default:
                res[k] = 0;
                break;
            }
        }
        if ((res[0] != 0) || (res[1] != 0)) {
            if (*(s16 *)(ent + 2) != 0) {
                obj[0x3A] = 1;
            } else {
                objFreeObject(arg0);
            }
        }
        *(s32 *)(obj + 0x88) = 0;
    }

    *(s16 *)obj = (s16)(*(s16 *)obj + *(s16 *)(ent + 0x1E) * arg1);
    v0u = *(u16 *)(ent + 0x1C);
    dx = *(f32 *)(obj + 0xC) - *(f32 *)(player + 0xC);
    dy = *(f32 *)(obj + 0x10) - *(f32 *)(player + 0x10);
    dz = *(f32 *)(obj + 0x14) - *(f32 *)(player + 0x14);
    if (v0u != 0) {
        if ((dx * dx + dz * dz) < *(f32 *)(ent + 0x18)) {
            *(s32 *)(obj + 0x84) = v0u;
        } else {
            *(s32 *)(obj + 0x84) = 0;
        }
        partUpdateTriggers(arg0, arg1);
    }

    if (((dx * dx + dz * dz) < *(f32 *)(ent + 0xC)) && (*(f32 *)(ent + 0x10) < dy) && (dy < *(f32 *)(ent + 0x14))) {
        if (ent[4] == 0) {
            mainSetGameFlag(ent[6], 1);
        } else if ((ent[4] == 1) || (ent[4] == 3)) {
            mainPlayerCollected(dy, *(s8 *)s3, *(s8 *)(s3 + 1), ent[6]);
        }
        q = *(s16 *)(ent + 8);
        if (q != -1) {
            instQueueMsg(s3, q);
        }
        snd = *(s16 *)(ent + 0xA);
        if (snd != -1) {
            if (snd & 0x1000) {
                amSndPlay(snd & 0xEFFF, 0);
            } else {
                amDittyPlay(snd & 0xFF);
            }
        } else {
            id = *(s16 *)ent;
            if ((id >= 0x265) && (id < 0x268)) {
                g0 = mainGetGameFlag(0x2D);
                g1 = mainGetGameFlag(0x2C);
                g2 = mainGetGameFlag(0x2E);
                amDittyPlay((g2 + g1 + g0 + 0x46) & 0xFF);
            }
        }
        if (*(s16 *)(ent + 2) != 0) {
            obj[0x3A] = 1;
        } else {
            objFreeObject(arg0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o43/overlay_43/collectableControl.s")
#endif
