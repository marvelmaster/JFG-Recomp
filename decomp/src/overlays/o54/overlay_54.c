#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_54_036007A0[];
extern f32 D_overlay_54_03600A80;
extern f32 D_overlay_54_03600A84;
extern f32 D_overlay_54_03600A88;
f32 Sinf(s32 angle);
f32 Powerf(f32 x, s32 n);
s32 mathSin(s16 angle);
s16 dAngle(s16 cur, s16 target, f32 rate);
void fxMakeConeLength(void *obj, s16 len, u8 alpha);
void fxMakeConeTextureCoords(void *obj, s16 angle);
void *objSetupObject(void *setup, s32 arg1);
void amSndPlay(s32 id, s32 arg1);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void camSetNo(s8 n);
void cameraTopDown(void *ship, void *sub, f32 dt);
void controlReadJoypad(s8 n);
void func_overlay_54_03600000_1F75A48(void *arg0, s32 arg1);
void func_overlay_54_03600140_1F75B88(void *arg0, void *arg1, s32 arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_54_03600000_1F75A48(void *arg0, s32 arg1) {
    s32 i;
    s32 var_s0;
    s32 temp_v0;
    s32 temp_s1_2;
    s16 temp_s1;
    u8 temp_s0;
    void *obj;
    u8 *slot;

    for (i = 0; i < 2; i++) {
        obj = *(void **) ((u8 *) arg0 + 0x598 + i * 4);
        slot = (u8 *) arg0 + i;
        if (obj != NULL) {
            temp_s0 = *(u8 *) (slot + 0x5AC);
            temp_v0 = arg1 * 0x10;
            if (*(s8 *) ((u8 *) arg0 + 0x14A) != 0) {
                var_s0 = temp_s0 + temp_v0;
                if (var_s0 >= 0x100) {
                    var_s0 = 0xFF;
                }
            } else {
                var_s0 = temp_s0 - (arg1 * 8);
                if (var_s0 < 0x80) {
                    var_s0 = 0x80;
                }
            }
            *(u8 *) (slot + 0x5AC) = (u8) var_s0;
            *(s8 *) (slot + 0x5A8) = (s8) (*(s8 *) (slot + 0x5A8) + temp_v0);
            temp_s1 = *(s16 *) ((u8 *) obj + 0x20);
            temp_s1_2 = (s32) ((temp_s1 + ((s32) (*(s16 *) ((u8 *) obj + 0x20) * mathSin((s16) (*(s8 *) (slot + 0x5A8) << 8))) >> 0x14)) * var_s0) >> 8;
            fxMakeConeTextureCoords(obj, (s16) (*(s8 *) (slot + 0x5A8) << 8));
            fxMakeConeLength(obj, (s16) temp_s1_2, *(u8 *) (slot + 0x5AC));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o54/overlay_54/func_overlay_54_03600000_1F75A48.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_54_03600140_1F75B88(void *arg0, void *arg1, s32 arg2) {
    /* object setup block passed to objSetupObject (layout from the stack offsets) */
    struct {
        s16 unk00;
        s8 unk02;
        s8 unk03;
        s16 unk04;
        s16 unk06;
        s16 unk08;
        u8 unk0A;
        s8 unk0B;
        s16 unk0C;
        s16 unk0E;
        s8 unk10;
        s8 unk11;
        s8 unk12;
        s8 unk13;
        f32 unk14;
        void *unk18;
        s32 unk1C;
        s32 unk20;
    } spawn;
    s8 temp_v0;
    u8 *temp_s0;

    temp_v0 = *(s8 *) ((u8 *) arg1 + 0x344);
    temp_s0 = D_overlay_54_036007A0 + *(u8 *) ((u8 *) arg1 + 0x345) * 0xC;
    if (temp_v0 > 0) {
        *(s8 *) ((u8 *) arg1 + 0x344) = (s8) (temp_v0 - arg2);
    }
    if ((controlDkeys & 0x2000) || ((controlKeys & 0x2000) && (*(s8 *) ((u8 *) arg1 + 0x344) <= 0) && (*(s16 *) (temp_s0 + 2) != 0))) {
        spawn.unk02 = 0x24;
        spawn.unk03 = 0;
        spawn.unk00 = *(s16 *) (temp_s0 + 6);
        spawn.unk04 = (s16) (s32) ((Sinf(*(s16 *) arg0 + 0x8000) * -32.0f) + *(f32 *) ((u8 *) arg0 + 0xC));
        spawn.unk06 = (s16) (s32) *(f32 *) ((u8 *) arg0 + 0x10);
        spawn.unk08 = (s16) (s32) ((Cosf(*(s16 *) arg0 + 0x8000) * -32.0f) + *(f32 *) ((u8 *) arg0 + 0x14));
        spawn.unk0A = temp_s0[1];
        spawn.unk0B = (s8) temp_s0[4];
        spawn.unk0E = 0;
        spawn.unk0C = *(s16 *) arg0 + 0x8000;
        spawn.unk10 = 0;
        spawn.unk11 = 0;
        spawn.unk1C = 0;
        spawn.unk20 = 0;
        spawn.unk14 = *(f32 *) ((u8 *) arg1 + 0x34C) + *(f32 *) (temp_s0 + 8);
        spawn.unk13 = -1;
        spawn.unk18 = arg0;
        objSetupObject(&spawn, 1);
        amSndPlay(3, 0);
        *(s8 *) ((u8 *) arg1 + 0x344) = (s8) temp_s0[0];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o54/overlay_54/func_overlay_54_03600140_1F75B88.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shipControl(void *arg0, s32 arg1) {
    u8 *sub;
    f32 dt;
    f32 f2;
    f32 f10;
    f32 f12;
    f32 tmp;
    s16 steps;
    s16 v;
    s32 i;
    s32 target;

    dt = (f32) arg1;
    sub = *(u8 **) ((u8 *) arg0 + 0x68);
    steps = (s16) arg1;
    controlReadJoypad(*(s8 *) sub);
    if (controlKeys & 0x10) {
        f2 = 1.5f;
    } else {
        f2 = 1.0f;
    }
    for (i = 0; i < steps; i++) {
        tmp = *(f32 *) (sub + 0x350);
        *(f32 *) (sub + 0x350) = tmp + ((f2 - tmp) * D_overlay_54_03600A80);
    }
    target = (s32) (controlXjoy * -0x10000) / 6300;
    for (i = 0; i < steps; i++) {
        v = *(s16 *) (sub + 0x346);
        *(s16 *) (sub + 0x346) = (s16) (v + (((s32) ((s16) target - v)) >> 4));
    }
    if ((((s32) ((s16) target - *(s16 *) (sub + 0x346))) >> 4) == 0) {
        *(s16 *) (sub + 0x346) = (s16) target;
    }
    *(s16 *) arg0 = (s16) (*(s16 *) arg0 + (s32) ((f32) *(s16 *) (sub + 0x346) * dt * *(f32 *) (sub + 0x350)));

    target = (s32) (controlXjoy * -0x1400) / 70;
    for (i = 0; i < steps; i++) {
        v = *(s16 *) (sub + 0x34A);
        *(s16 *) (sub + 0x34A) = (s16) (v + (((s32) ((s16) target - v)) >> 4));
    }
    if ((((s32) ((s16) target - *(s16 *) (sub + 0x34A))) >> 4) == 0) {
        *(s16 *) (sub + 0x34A) = (s16) target;
    }
    *(s16 *) ((u8 *) arg0 + 0x4) = (s16) (s32) ((f32) *(s16 *) (sub + 0x34A) * *(f32 *) (sub + 0x350));

    if (controlYjoy < -0x3F) {
        *(s8 *) (sub + 0x14A) = -0x7F;
    } else if (controlYjoy >= 0x40) {
        *(s8 *) (sub + 0x14A) = 0x7F;
    } else {
        *(s8 *) (sub + 0x14A) = (s8) (controlYjoy * 2);
    }
    f12 = 14.0f;
    if (controlYjoy != 0) {
        f10 = ((f32) controlYjoy * 7.0f) / 70.0f;
        f12 = 14.0f + f10;
    }
    for (i = 0; i < steps; i++) {
        tmp = *(f32 *) (sub + 0x34C);
        *(f32 *) (sub + 0x34C) = tmp + ((f12 - tmp) * D_overlay_54_03600A84);
    }
    /* sig mismatch: asm passes extra args to Sinf */
    *(f32 *) ((u8 *) arg0 + 0x1C) = (f32) (((f32 (*)(f32, s32, s16, s32, s32 *)) Sinf)(D_overlay_54_03600A84, *(s16 *) arg0 + 0x8000, (s16) arg1, arg1, &controlYjoy) * -*(f32 *) (sub + 0x34C));
    *(f32 *) ((u8 *) arg0 + 0x20) = *(f32 *) ((u8 *) levelGetLevel() + 0x28);
    *(f32 *) ((u8 *) arg0 + 0x24) = (f32) (Cosf(*(s16 *) arg0 + 0x8000) * -*(f32 *) (sub + 0x34C));
    *(f32 *) ((u8 *) arg0 + 0x10) = 0.0f;
    objMoveXYZ(arg0, *(f32 *) ((u8 *) arg0 + 0x1C) * dt, *(f32 *) ((u8 *) arg0 + 0x20) * dt, *(f32 *) ((u8 *) arg0 + 0x24) * dt);
    func_overlay_54_03600140_1F75B88(arg0, sub, arg1);
    *(s16 *) (sub + 0x348) = dAngle(*(s16 *) (sub + 0x348), (s16) ((*(s8 *) (sub + 0x14A) << 7) - 0x4000), 1.0f - Powerf(D_overlay_54_03600A88, arg1));
    v = *(s16 *) (sub + 0x348);
    *(s16 *) (sub + 0x240) = 6;
    *(s16 *) (sub + 0x244) = 0xC;
    *(s16 *) (sub + 0x248) = 0x1000;
    *(s16 *) (sub + 0x242) = v;
    *(s16 *) (sub + 0x246) = v;
    func_overlay_54_03600000_1F75A48(sub, arg1);
    camSetNo(*(s8 *) sub);
    cameraTopDown(arg0, sub, dt);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o54/overlay_54/shipControl.s")
#endif
