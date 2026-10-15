#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_132_08400320;
extern s16 weaponPowerUpObjects[];
extern s32 __MODULE00132;
void runlinkSetDestructTimer(s32 module, s32 a, s32 b);
void *mainGetGameCharacter(s8 a, s8 b);
void *controlGetWeaponDef(s32 arg0);
s32 hitPlayer(f32 x, f32 y, s32 zBits, f32 radius, s32 ignoreY, void *outList); /* z passed as raw word in $a2 */
void objFreeObject(void *obj);
void amSndPlay(u16 soundID, void *handlePtr);
void instQueueMsg(void *obj, s32 msg);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weaponPickupInit(void *arg0, void *arg1) {
    s32 cnt;
    s32 lim;
    s32 idx;
    s16 id;
    u8 *pk;

    cnt = *(s8 *)((u8 *)arg1 + 0xA);
    lim = *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x1F) - 1;
    if (cnt < lim) {
        lim = cnt;
    }
    if (lim < 0) {
        lim = 0;
    }
    *(s8 *)((u8 *)arg0 + 0x3A) = (s8)lim;

    id = *(s16 *)arg1;
    idx = lim;
    if (id != 0x88) {
        idx = 0;
        if (id != weaponPowerUpObjects[0]) {
            do {
                idx++;
                if (idx >= 0xF) {
                    break;
                }
            } while (id != weaponPowerUpObjects[idx]);
        }
    }
    *(s16 *)((u8 *)arg0 + 0x88) = (s16)idx;

    if (*(s16 *)arg1 == 0x88) {
        if (*(s16 *)((u8 *)arg0 + 0x88) < 8) {
            *(f32 *)((u8 *)arg0 + 0x8) = D_overlay_132_08400320;
        } else {
            *(f32 *)((u8 *)arg0 + 0x8) = 1.5f;
        }
    }

    pk = (u8 *)arg0 + 0x88;
    *(s16 *)(pk + 4) = 0;
    *(s16 *)(pk + 2) = (s16)(*(s8 *)((u8 *)arg1 + 0xB) * 0x3C);
    *(s16 *)(pk + 6) = 0xFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o132/overlay_132/weaponPickupInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weaponPickupControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *pk = obj + 0x88;
    void *hit;
    void *who;
    void *chr;
    void *def;
    s32 idx;
    s32 bit;
    s32 msg;
    s32 r;
    s32 r2;

    runlinkSetDestructTimer(__MODULE00132, 2, 2);
    *(s16 *)obj = (s16)(*(s16 *)obj + (arg1 << 7));
    r = hitPlayer(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(s32 *)(obj + 0x14), 40.0f, 0, &hit);

    if (*(s16 *)(pk + 6) == 0) {
        *(s16 *)(pk + 4) = (s16)(*(s16 *)(pk + 4) - arg1);
        if (*(s16 *)(pk + 4) <= 0) {
            *(s16 *)(pk + 4) = 0;
            if (r == 0) {
                *(s16 *)(pk + 6) = (s16)arg1;
            }
        }
        return;
    }

    *(s16 *)(pk + 6) = (s16)(*(s16 *)(pk + 6) + (arg1 * 4));
    if (*(s16 *)(pk + 6) >= 0x100) {
        *(s16 *)(pk + 6) = 0xFF;
    }
    if (r == 0) {
        return;
    }

    who = *(void **)((u8 *)hit + 0x68);
    chr = mainGetGameCharacter(*(s8 *)who, *(s8 *)((u8 *)who + 1));
    idx = *(s16 *)pk;
    def = controlGetWeaponDef(idx);
    bit = 1 << idx;

    if ((*(u16 *)((u8 *)chr + 0xA) & bit) == 0) {
        *(u16 *)((u8 *)chr + 0xA) = (u16)(*(u16 *)((u8 *)chr + 0xA) | bit);
        *(u8 *)((u8 *)chr + 0x6F) = (u8)(*(u8 *)((u8 *)chr + 0x6F) + 1);
        *(s16 *)((u8 *)chr + 0x34 + idx * 2) = *(s16 *)((u8 *)def + 0x24);
        *(s16 *)((u8 *)chr + 0x14 + idx * 2) = *(s16 *)((u8 *)def + 0x28);
        *(u8 *)((u8 *)chr + 0x54 + idx) = *(u8 *)((u8 *)def + 0x3);
        msg = idx + 0x39;
    } else {
        *(s16 *)((u8 *)chr + 0x14 + idx * 2) = (s16)(*(s16 *)((u8 *)chr + 0x14 + idx * 2) + *(s16 *)((u8 *)def + 0x2A));
        if (*(u16 *)((u8 *)chr + 0x34 + idx * 2) < *(u16 *)((u8 *)chr + 0x14 + idx * 2)) {
            *(s16 *)((u8 *)chr + 0x14 + idx * 2) = (s16)*(u16 *)((u8 *)chr + 0x34 + idx * 2);
        }
        msg = idx + 0x48;
    }

    r2 = *(s16 *)(pk + 2);
    if (r2 != 0) {
        *(s16 *)(pk + 4) = (s16)r2;
        *(s16 *)(pk + 6) = 0;
    } else {
        objFreeObject(arg0);
    }
    amSndPlay(0x8A, 0);
    instQueueMsg(who, msg);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o132/overlay_132/weaponPickupControl.s")
#endif
