#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_124_07C009B0;
extern f32 D_overlay_124_07C009B4;
extern f32 D_overlay_124_07C009B8;
f32 Sinf(s16 angle);
s32 mainGetGameFlag(s32 flag);
void mainSetGameFlag(s32 flag, s32 value);
s32 addObjectLight(Object *obj, ObjectHeader48 *def);
void trackLightColour(void *light, s32 r, s32 g, s32 b, s32 intensity);
s32 trackLightAdd(f32, f32, s32, f32, f32, f32, f32, s32, s32, s32);
void trackLightMove(f32, f32, s32, f32, f32, f32);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void sparkAdd(void *arg0);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
void func_overlay_124_07C00000_1FC9678(Object *arg0, u8 *arg1);
u8 func_overlay_124_07C00150_1FC97C8(u8 *arg0);
void func_overlay_124_07C001C8_1FC9840(Object *arg0, u8 *arg1, s32 arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_124_07C00000_1FC9678(Object *arg0, u8 *arg1) {
    f32 sinY;
    f32 cosY;
    f32 sinX;
    f32 cosX;
    f32 radius;
    f32 spread;
    f32 fl;
    f32 offX;
    f32 offY;
    f32 offZ;
    s32 lightId;
    u8 intensity;

    if (*(s32 *)(arg1 + 0x20) != 0) {
        sinY = Sinf(arg0->segment.trans.y_rotation);
        cosY = Cosf((s32) arg0->segment.trans.y_rotation);
        sinX = Sinf(arg0->segment.trans.x_rotation);
        cosX = Cosf((s32) arg0->segment.trans.x_rotation);
        spread = *(f32 *)(arg1 + 0x28);
        radius = *(f32 *)(arg1 + 0x24);
        fl = radius * cosX;
        offX = arg0->segment.trans.x_position - (fl * sinY);
        offY = arg0->segment.trans.y_position + (radius * sinX);
        offZ = arg0->segment.trans.z_position - (fl * cosY);
        lightId = *(s32 *)(arg1 + 0x2C);
        if (lightId != 0) {
            trackLightMove(radius, fl, lightId, offX, offY, offZ);
            return;
        }
        intensity = arg1[7];
        *(s32 *)(arg1 + 0x2C) = trackLightAdd(offX, offY, lightId, offX, offZ, spread,
                                              spread * D_overlay_124_07C009B0,
                                              (s32) (arg1[4] * intensity) >> 8,
                                              (s32) (arg1[5] * intensity) >> 8,
                                              (s32) (arg1[6] * intensity) >> 8);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o124/overlay_124/func_overlay_124_07C00000_1FC9678.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_overlay_124_07C00150_1FC97C8(u8 *arg0) {
    switch (arg0[0]) {
    case 0:
        return arg0[8];
    case 1:
        return mainGetGameFlag(arg0[2]);
    case 2:
        return mainGetGameFlag(arg0[2]) == 0;
    default:
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o124/overlay_124/func_overlay_124_07C00150_1FC97C8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_124_07C001C8_1FC9840(Object *arg0, u8 *arg1, s32 arg2) {
    u8 flags;
    s16 v;
    s32 doY;

    flags = arg1[1];
    doY = flags & 2;
    if (flags & 1) {
        if (arg1[8] == 0) {
            v = *(s16 *)(arg1 + 0x10);
            v = (s16) (v - (v >> 5));
            *(s16 *)(arg1 + 0x10) = v;
            if (v >= -0x20 && v < 0x21) {
                *(s16 *)(arg1 + 0x10) = 0;
            }
        }
        arg0->segment.trans.y_rotation = (s16) (arg0->segment.trans.y_rotation + (*(s16 *)(arg1 + 0x10) * arg2));
        doY = arg1[1] & 2;
    }
    if (doY != 0) {
        if (arg1[8] == 0) {
            v = *(s16 *)(arg1 + 0x12);
            v = (s16) (v - (v >> 5));
            *(s16 *)(arg1 + 0x12) = v;
            if (v >= -0x20 && v < 0x21) {
                *(s16 *)(arg1 + 0x12) = 0;
            }
        }
        arg0->segment.trans.x_rotation = (s16) (arg0->segment.trans.x_rotation + (*(s16 *)(arg1 + 0x12) * arg2));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o124/overlay_124/func_overlay_124_07C001C8_1FC9840.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void spotlightInit(Object *arg0, void *arg1) {
    u8 *def = (u8 *)arg1;
    u8 *state;
    u8 lightDef[0x18];
    u8 *hdr;
    u8 *list;
    u8 *ent;
    u8 *ent2;
    u8 *vals;
    u8 *dst;
    s32 count;
    s32 i;
    f32 rad;
    u16 radRaw;

    state = *(u8 **)((u8 *)arg0 + 0x68);
    arg0->segment.trans.y_rotation = (s16) (def[0xA] << 8);
    arg0->segment.trans.x_rotation = (s16) (def[0xB] << 8);
    arg0->segment.trans.scale = (f32) def[0x1F] * D_overlay_124_07C009B4;
    state[0] = def[0x10];
    state[1] = def[0x12];
    state[2] = def[0x11];
    state[3] = def[0x13];
    state[4] = def[0x14];
    state[5] = def[0x15];
    state[6] = def[0x16];
    state[8] = 1;
    *(s16 *)(state + 0xA) = 0;
    state[7] = def[0x17];

    radRaw = *(u16 *)(def + 0x1C);
    rad = (f32) radRaw;
    *(f32 *)(state + 0xC) = rad * rad;
    *(s16 *)(state + 0x10) = (s16) ((s8) def[0xC] << 6);
    *(s16 *)(state + 0x12) = (s16) ((s8) def[0xD] << 6);
    *(s16 *)(state + 0x14) = (s16) (arg0->segment.trans.y_rotation - (def[0xE] << 7));
    *(s16 *)(state + 0x16) = (s16) (arg0->segment.trans.y_rotation + (def[0xE] << 7));
    *(s16 *)(state + 0x18) = (s16) (arg0->segment.trans.x_rotation - (def[0xF] << 7));
    *(s16 *)(state + 0x1A) = (s16) (arg0->segment.trans.x_rotation + (def[0xF] << 7));
    *(s32 *)(state + 0x1C) = 0;
    state[8] = func_overlay_124_07C00150_1FC97C8(state);
    *(s32 *)(state + 0x20) = 0;
    *(s32 *)(state + 0x2C) = 0;

    /* light definition passed to addObjectLight, built on the stack in the asm */
    lightDef[0] = def[0x1A];
    lightDef[1] = 3;
    lightDef[2] = (u8) (~def[0x19] & 0x61);
    lightDef[3] = 0xFF;
    for (i = 4; i < 0xC; i++) {
        lightDef[i] = 0;
    }
    lightDef[0xC] = (u8) (((def[0x18] << 3) >> 8) & 0xFF);
    lightDef[0xD] = (u8) (def[0x18] << 3);
    lightDef[0xE] = (u8) (((def[0x18] << 3) >> 8) & 0xFF);
    lightDef[0xF] = (u8) (def[0x18] << 3);
    lightDef[0x10] = def[0x14];
    lightDef[0x11] = def[0x15];
    lightDef[0x12] = def[0x16];
    lightDef[0x13] = (state[8] != 0) ? def[0x17] : 0;
    lightDef[0x14] = 0xFF;
    lightDef[0x15] = 0xFF;
    lightDef[0x16] = 0;
    lightDef[0x17] = 0;
    if (def[0x1A] == 3) {
        lightDef[2] |= 0x40;
    }
    *(s32 *)(state + 0x20) = addObjectLight(arg0, (ObjectHeader48 *) lightDef);
    *(f32 *)(state + 0x28) = (f32) (def[0x21] << 3);
    *(f32 *)(state + 0x24) = (f32) (def[0x20] << 3);
    if (def[0x1A] == 3 && !(def[0x19] & 0x40)) {
        func_overlay_124_07C00000_1FC9678(arg0, state);
    }
    *((u8 *)arg0 + 0x3A) = 0;
    hitInitObjectHit(arg0, def[0x1E] << 8, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);

    /* copy the colour fields into matching entries of the object's sub-table */
    hdr = *(u8 **)((u8 *)arg0 + 0x6C);
    if (hdr != NULL) {
        list = *(u8 **)hdr;
        ent = *(u8 **)(hdr + 4);
        count = *(s16 *)(list + 0x12);
        ent2 = *(u8 **)(list + 0x1C);
        vals = ent2;
        dst = ent;
        for (i = 0; i < count; i++) {
            if (vals[6] == 0 && vals[7] == 0 && vals[8] == 0) {
                dst[6] = state[4];
                dst[7] = state[5];
                dst[8] = state[6];
            }
            vals += 0xA;
            dst += 0xA;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o124/overlay_124/spotlightInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void spotlightControl(Object *arg0, s32 arg1) {
    u8 *state;
    u8 *ext;
    void *light;
    s32 trackId;
    s32 count;
    s32 i;
    f32 f20;
    struct {
        s16 x;       /* 0x00 */
        s16 y;       /* 0x02 */
        f32 scale;   /* 0x04 */
        f32 px;      /* 0x08 */
        f32 py;      /* 0x0C */
        f32 pz;      /* 0x10 */
        f32 speed;   /* 0x14 */
        s16 life;    /* 0x18 */
        u8 unk1A;    /* 0x1A */
        u8 unk1B;    /* 0x1B */
        s32 unk1C;   /* 0x1C */
        s32 unk20;   /* 0x20 */
    } spark;

    state = *(u8 **)((u8 *)arg0 + 0x68);
    light = *(void **)(state + 0x20);
    trackId = *(s32 *)(state + 0x2C);

    if (state[8] != 0 && state[0] != 3) {
        ext = *(u8 **)((u8 *)arg0 + 0x4C);
        if (*(s16 *)(ext + 6) > 0) {
            *(s16 *)(ext + 6) = (s16) (*(s16 *)(ext + 6) - *(s16 *)(*(u8 **)((u8 *)arg0 + 0x5C) + 0x130) - *(s32 *)((u8 *)arg0 + 0x88));
            if (*(s16 *)(ext + 6) <= 0) {
                amSndPlayXYZ(0xD3, arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                             arg0->segment.trans.z_position, 4, NULL);
                *((u8 *)arg0 + 0x3A) = 1;
                state[8] = 0;
                if (light != NULL) {
                    changeLightIntensity((UnkLight *) light, 0);
                }
                if (trackId != 0) {
                    trackLightColour((void *) trackId, state[4], state[5], state[6], 0);
                }
                if (state[0] == 2) {
                    mainSetGameFlag(state[2], 1);
                }
            }
        }
    }

    func_overlay_124_07C001C8_1FC9840(arg0, state, arg1);

    if (state[8] == 0) {
        if (*(s16 *)(state + 0xA) != 0) {
            *(s16 *)(state + 0xA) = (s16) (*(s16 *)(state + 0xA) - arg1);
            if (*(s16 *)(state + 0xA) <= 0) {
                *(s16 *)(state + 0xA) = 0;
                *((u8 *)arg0 + 0x3A) = 0;
                if (light != NULL) {
                    changeLightIntensity((UnkLight *) light, state[7]);
                }
                if (trackId != 0) {
                    trackLightColour((void *) trackId, state[4], state[5], state[6], state[7]);
                }
                amSndPlayXYZ(0xD2, arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                             arg0->segment.trans.z_position, 4, NULL);
                count = state[3];
                if (count != 0) {
                    spark.px = arg0->segment.trans.x_position;
                    spark.py = arg0->segment.trans.y_position;
                    spark.pz = arg0->segment.trans.z_position;
                    spark.life = 0x14;
                    spark.unk1A = 0xA;
                    spark.unk1B = 0xFF;
                    spark.unk1C = -0x7F01;
                    spark.unk20 = (s32) 0xFF0000FF;
                    f20 = D_overlay_124_07C009B8;
                    for (i = 0; i < count; i++) {
                        spark.x = (s16) (mathRnd(-0x2000, 0x2000) + arg0->segment.trans.y_rotation);
                        spark.y = (s16) (mathRnd(-0x2000, 0x2000) + arg0->segment.trans.x_rotation);
                        spark.scale = (f32) mathRnd(0xA, 0x14) * f20;
                        spark.speed = (f32) mathRnd(0xC, 0x19) * f20;
                        sparkAdd(&spark);
                    }
                }
            }
        } else {
            *((u8 *)arg0 + 0x3A) = 1;
            *(s16 *)(state + 0xA) = (s16) mathRnd(0x1E, 0x1E0);
            if (light != NULL) {
                changeLightIntensity((UnkLight *) light, 0);
            }
            if (trackId != 0) {
                trackLightColour((void *) trackId, state[4], state[5], state[6], 0);
            }
        }
    }

    if (trackId != 0) {
        func_overlay_124_07C00000_1FC9678(arg0, state);
    }
    *(s32 *)((u8 *)arg0 + 0x88) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o124/overlay_124/spotlightControl.s")
#endif
