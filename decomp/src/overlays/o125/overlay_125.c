#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct TargetswitchRacer {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC;
} TargetswitchRacer;

typedef struct TargetswitchSetup {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ s16 unk14;
} TargetswitchSetup;

extern f32 D_overlay_125_07D005B0;
extern f32 D_overlay_125_07D00590[5];
void hitInitObjectHit(Object *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6,
                      f32 f1, f32 f2, f32 f3, f32 f4, s32 a7);
s16 objTvTimes(u8 n);
u8 doorRegisterOpener(u8 id, s32 flags);
void doorUnlock(u8 id, s32 flags);
s32 mainGetGameFlag(s16 flag);
void cutcameraActivate(u8 arg);
void amSndPlay(u16 soundID, void *handlePtr);
void amDittyPlay(s32 id);
void objAnimDframe(void *obj, s32 animBits, f32 frame, void *obj2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void targetswitchInit(Object *arg0, TargetswitchSetup *arg1) {
    TargetswitchRacer *racer;
    s16 temp_t1;
    f32 temp_f0;

    arg0->segment.trans.y_rotation = arg1->unkC;
    arg0->segment.trans.x_rotation = arg1->unkE;
    arg0->segment.trans.scale = (f32)arg1->unkB * D_overlay_125_07D005B0;
    racer = (TargetswitchRacer *)arg0->racer;
    racer->unk2 = objTvTimes(arg1->unk11);
    racer->unk0 = racer->unk2;
    temp_t1 = (s16)(arg1->unk12 << 8);
    racer->unk6 = (u16)temp_t1;
    racer->unkA = 0;
    racer->unk9 = arg1->unk10;
    racer->unkB = 0;
    racer->unkC = 0;
    racer->unk8 = arg1->unkA;
    racer->unk4 = arg1->unk14;
    temp_f0 = arg0->segment.trans.scale * 10.0f;
    hitInitObjectHit(arg0, (u16)temp_t1, 1, 0x18, 0, 5, -8, temp_f0, temp_f0, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o125/overlay_125/targetswitchInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void targetswitchControl(Object *arg0, s32 arg1) {
    TargetswitchRacer *racer;
    u8 *anim;
    u8 *temp_t3;
    u8 *temp_t1;
    u8 *entry;
    u8 *table;
    s16 *outp;
    f32 *temp_t2;
    f32 temp_f0;
    s32 divisor;
    s32 quot;
    s32 var_v0;
    s32 var_v1;
    s32 var_a2;
    s32 var_a3;
    s32 count;
    s32 idx;
    s32 i;
    s16 temp_a0;
    u8 temp_a0_3;
    s16 temp_a0_4;

    racer = (TargetswitchRacer *)arg0->racer;
    if (racer->unkC == 0) {
        racer->unkC = doorRegisterOpener(racer->unk8, 0x40);
    }
    if (racer->unkA == 0) {
        temp_a0 = racer->unk4;
        if ((temp_a0 != 0) && (mainGetGameFlag(temp_a0) != 0)) {
            *(f32 *)((u8 *)arg0 + 0x28) = 1.0f;
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6) = 0;
            racer->unkB = 4;
            racer->unkA = 1;
            doorUnlock(racer->unk8, 0);
        }
    }
    anim = *(u8 **)((u8 *)arg0 + 0x4C);
    var_v1 = *(s16 *)(anim + 6);
    divisor = (s32)(racer->unk6 >> 10);
    if (var_v1 < 0) {
        *(s16 *)(anim + 6) = 0;
        var_v1 = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6);
    }
    var_v0 = var_v1 >> 8;
    if (var_v1 > 0) {
        if (var_v1 < (s32)racer->unk6) {
            if (arg1 < racer->unk0) {
                racer->unk0 = (s16)(racer->unk0 - arg1);
                var_v1 = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6);
            } else {
                racer->unk0 = racer->unk2;
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6) = (s16)racer->unk6;
                amSndPlay(0x194, 0);
                var_v1 = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6);
            }
        }
        var_v0 = var_v1 >> 8;
    }
    temp_t3 = (u8 *)(*(void ***)((u8 *)arg0 + 0x6C))[*(s8 *)((u8 *)arg0 + 0x3A)];
    temp_t1 = *(u8 **)temp_t3;
    quot = var_v0 / divisor;
    var_a2 = 4 - quot;
    /* asm: the addiu -1 sits in the beqz delay slot, so it runs on both paths */
    var_a2 -= 1;
    if (var_a2 != racer->unkB) {
        amSndPlay(0x193, 0);
        racer->unkB = (u8)var_a2;
    }
    temp_t2 = &D_overlay_125_07D00590[var_a2];
    temp_f0 = *temp_t2;
    if (temp_f0 < *(f32 *)((u8 *)arg0 + 0x28)) {
        objAnimDframe(arg0, (s32)0xBC23D70A, (f32)arg1, arg0);
        if (*(f32 *)((u8 *)arg0 + 0x28) < temp_f0) {
            *(f32 *)((u8 *)arg0 + 0x28) = temp_f0;
        }
    } else {
        objAnimDframe(arg0, (s32)0x3C23D70A, (f32)arg1, arg0);
        if (temp_f0 < *(f32 *)((u8 *)arg0 + 0x28)) {
            *(f32 *)((u8 *)arg0 + 0x28) = temp_f0;
        }
    }
    if ((temp_t2 == &D_overlay_125_07D00590[4]) && (racer->unkA == 0)) {
        temp_a0_3 = racer->unk9;
        racer->unkA = 1;
        if (temp_a0_3 != 0) {
            cutcameraActivate(temp_a0_3);
        }
        amDittyPlay(0xF);
        doorUnlock(racer->unk8, 0x10);
        temp_a0_4 = racer->unk4;
        if (temp_a0_4 != 0) {
            mainSetGameFlag((s32)temp_a0_4, 1);
        }
    }
    i = 0;
    do {
        entry = *(u8 **)(temp_t3 + 0x74);
        outp = *(s16 **)(temp_t3 + 0x78 + (*(s8 *)(temp_t3 + 0xB) * 4));
        if ((u32)temp_t2 >= (u32)&D_overlay_125_07D00590[1]) {
            var_a3 = 0x100;
            temp_t2 -= 1;
        } else {
            var_a3 = 0;
        }
        var_a2 = 0;
        count = *(u8 *)(temp_t1 + 0x2C);
        if (count > 0) {
            do {
                idx = *(u32 *)(entry + 4) & 0xFF;
                table = *(u8 **)(*(u8 **)(temp_t1 + 0x18) + (idx << 3));
                /* asm: the sh of a3 is in the bne delay slot, so it stores on both paths */
                *(s16 *)entry = (s16)var_a3;
                *outp++ = (s16)((*(s16 *)entry >> 8) * *(s16 *)(table + 0x16));
                if (*(s16 *)(entry + 2) >= 0) {
                    *outp++ = (s16)((*(s16 *)(entry + 2) >> 8) * *(s16 *)(table + 0x16));
                }
                var_a2 += 1;
                entry += 8;
            } while (var_a2 < count);
        }
        i += 1;
    } while (i != 4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o125/overlay_125/targetswitchControl.s")
#endif
