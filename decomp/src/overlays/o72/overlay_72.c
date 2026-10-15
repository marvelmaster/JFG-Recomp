#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct AmmoPickupData {
    s16 type;
    u8 unk2;
    u8 weapon;
    s16 timer;
    s16 fade;
    u8 unk7;
    u16 flagId;
} AmmoPickupData;

extern s32 __MODULE00072;
void objAnimSetMove(void *obj, s32 arg1, s32 arg2);
void *controlGetWeaponDef(s32 weapon);
void *mainGetGameCharacter(s32 arg0, s8 arg1);
void *objGetPlayerNo(s32 player);
s32 mainGetGameFlag(s32 flag);
void amSndPlay(s32 sfxId, s32 arg1, void *arg2);
void instQueueMsg(void *data, s32 msg);
void objFreeObject(void *obj);
void runlinkSetDestructTimer(s32 module, s32 arg1, s32 arg2);
s32 hitPlayer(f32 x, f32 y, s32 z, f32 radius, s32 arg4, void **hits);
/* decomp: end externs */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void ammoPickupInit(void *arg0, void *arg1) {
    AmmoPickupData *data;

    data = *(AmmoPickupData **)((u8 *)arg0 + 0x68);
    data->type = *(s16 *)arg1;
    data->unk2 = (u8) *(s8 *)((u8 *)arg1 + 0xA);
    data->weapon = *(u8 *)((u8 *)arg1 + 0xB);
    data->timer = 0;
    data->fade = 0xFF;
    data->flagId = *(u16 *)((u8 *)arg1 + 0xE);
    *(s16 *)arg0 = (s16) (*(u8 *)((u8 *)arg1 + 0xC) << 8);
    objAnimSetMove(arg0, 0, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o72/overlay_72/ammoPickupInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void ammoPickupControl(void *arg0, s32 arg1) {
    void *hitList[13]; /* asm: sp+0x64..0x98 */
    AmmoPickupData *data;
    void *hitData;
    void *wdef;
    void *ch;
    u16 *ammoCur;
    u16 *ammoMax;
    s32 hitCount;
    s32 handled;
    s32 weapon;
    s32 msg;
    s32 i;
    u16 sum;

    runlinkSetDestructTimer(__MODULE00072, 2, 2);
    data = *(AmmoPickupData **)((u8 *)arg0 + 0x68);
    if (data->type == 0xE7 && mainGetGameFlag(data->flagId + 0x80) != 0) {
        objFreeObject(arg0);
        return;
    }
    if (data->type == 0x17E || data->type == 0xE7) {
        *(s16 *)arg0 = (s16) (*(s16 *)arg0 + (arg1 << 7));
    }

    hitCount = hitPlayer(*(f32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 0x10),
                         *(s32 *)((u8 *)arg0 + 0x14), 40.0f, 0, hitList);

    if (data->fade == 0) {
        data->timer = (s16) (data->timer - arg1);
        if (data->timer <= 0) {
            data->timer = 0;
            if (hitCount == 0) {
                data->fade = (s16) arg1;
            }
        }
        return;
    }

    data->fade = (s16) (data->fade + (arg1 << 2));
    if (data->fade >= 0x100) {
        data->fade = 0xFF;
    }
    if (hitCount <= 0) {
        return;
    }

    i = 0;
    do {
        hitData = *(void **)((u8 *)hitList[i] + 0x68);
        weapon = data->weapon;
        ch = mainGetGameCharacter(*(s8 *)hitData, *((s8 *)hitData + 1));
        wdef = controlGetWeaponDef(weapon);
        ammoCur = (u16 *)((u8 *)ch + 0x14) + weapon;
        ammoMax = (u16 *)((u8 *)ch + 0x34) + weapon;

        handled = 0;
        if (*(u16 *)((u8 *)ch + 0xA) & (1 << data->weapon)) {
            if (data->type != 0xE7
                || !(*(s16 *)((u8 *)wdef + 0x2E) < (s32) (*ammoMax + *(s16 *)((u8 *)wdef + 0x26)))) {
                handled = 1;
            }
        }
        i++;

        if (handled != 0) {
            i = hitCount;
            msg = weapon;
            switch (data->type) {
            case 0xCF:
                sum = (u16) (*ammoCur + *(s16 *)((u8 *)wdef + 0x2A));
                if ((s32) *ammoMax < (s32) sum) {
                    sum = *ammoMax;
                }
                *ammoCur = sum;
                msg = weapon + 0x48;
                amSndPlay(0x1E9, 0, wdef);
                break;
            case 0x17E:
                sum = (u16) (*ammoCur + *(s16 *)((u8 *)wdef + 0x2C));
                if ((s32) *ammoMax < (s32) sum) {
                    sum = *ammoMax;
                }
                *ammoCur = sum;
                msg = weapon + 0x57;
                amSndPlay(0x1E9, 0, wdef);
                break;
            case 0xE7:
                *ammoMax = (u16) (*ammoMax + *(s16 *)((u8 *)wdef + 0x26));
                msg = weapon + 0x75;
                mainSetGameFlag(data->flagId + 0x80, 1);
                amSndPlay(0x1EA, 0, wdef);
                break;
            case 0xE8:
                *ammoCur = *ammoMax;
                msg = weapon + 0x66;
                amSndPlay(0x1E9, 0, wdef);
                break;
            }
            instQueueMsg(hitData, msg);
            if (data->unk2 != 0) {
                data->timer = (s16) (data->unk2 * 0x3C);
                data->fade = 0;
            } else {
                objFreeObject(arg0);
            }
        }
    } while (i < hitCount);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o72/overlay_72/ammoPickupControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 ammoPickupGetFade(void *arg0, s32 arg1) {
    AmmoPickupData *data;
    void *player;
    void *ch;
    void *wdef;
    u8 weapon;

    data = *(AmmoPickupData **)((u8 *)arg0 + 0x68);
    player = objGetPlayerNo(arg1);
    if (player != NULL) {
        ch = mainGetGameCharacter(arg1, *((s8 *)*(void **)((u8 *)player + 0x68) + 1));
        wdef = controlGetWeaponDef(data->weapon);
        weapon = data->weapon;
        if (!(*(u16 *)((u8 *)ch + 0xA) & (1 << weapon))
            || (data->type == 0xE7
                && *(s16 *)((u8 *)wdef + 0x2E) < (s32) (*(u16 *)((u8 *)ch + 0x34 + weapon * 2) + *(s16 *)((u8 *)wdef + 0x26)))) {
            return (((s16) data->fade) >> 2) & 0xFF;
        }
    }
    return data->unk7;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o72/overlay_72/ammoPickupGetFade.s")
#endif
