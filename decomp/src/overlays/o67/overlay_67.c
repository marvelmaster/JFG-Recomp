#include "common.h"

/* decomp: externs */
Object **objGetObjList(s32 *arg0, s32 *arg1);
s16 mathDiffAngle(s16 a, s16 b);
s32 objAnimSetMove(void *arg0, s8 arg1, f32 arg2);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
f32 camDistance(f32 x, f32 y, f32 z);
void camStartShake(s32, s32, s32, s32, s32);
void *objSetupObject(void *params, s32 arg1);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void mantisLightingInit(void);
void trackGetFog(s32, s16 *, s16 *, s16 *, u8 *, u8 *, u8 *, s16 *);
void fxDrawCone(Gfx **arg0, void *arg1, s32 arg2, s32 arg3);
void *fxAllocateCone(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6, s32 arg7, s32 arg8, s32 arg9);
void fxFreeCone(void *cone);
extern s8 D_overlay_67_04304580[];
extern s32 D_overlay_67_04304430[];
extern Object *D_overlay_67_04304574[2];
extern s32 D_overlay_67_0430456C;
extern s32 D_overlay_67_043046C0[];
extern s32 D_overlay_67_043046C4[];
extern f32 D_overlay_67_04304E5C;
void mathOneFloatPY(void *obj, ...);
void objFreeObject(void *obj);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void explosionStart(s32, s16, s16, s16, s32, s32);
void trackMakePolylist(s32, f32 *, f32 *, s32 *, s32, s32, s32);
s32 trackGetIntersect(void *, f32 *, f32 *, s32, s32, void *);
void partUpdateTriggers(void *obj, s32 arg1);
void partAdjustScaling(f32 arg0);
void texDPTextureX(f32, s32, Gfx **, s32, s32, s32);
extern s32 D_84304C88[];
extern s32 D_84304CC8[];
extern f32 D_overlay_67_04304E74;
extern f32 D_overlay_67_04304E78;
void bloodSpurtAdd(f32, f32, f32, s32, f32, f32, s32, s32, f32);
void sparkAdd(void *arg0);
extern f32 D_overlay_67_04304D44;
extern f32 D_overlay_67_04304D48;
extern f32 D_overlay_67_04304D4C;
extern f32 D_overlay_67_04304D50;
extern f32 D_overlay_67_04304E60;
extern f32 D_overlay_67_04304E64;
extern f32 D_overlay_67_04304E68;
extern f32 D_overlay_67_04304E6C;
extern f32 D_overlay_67_04304E70;
extern f32 D_overlay_67_04304E58;
extern f32 D_overlay_67_04304DB4;
extern f32 D_overlay_67_04304DB8;
extern f32 D_overlay_67_04304DBC;
extern f32 D_overlay_67_04304DC0;
extern f32 D_overlay_67_04304DC4;
extern f32 D_overlay_67_04304DC8;
extern f32 D_overlay_67_04304DCC;
extern f32 D_overlay_67_04304DD0;
extern f32 D_overlay_67_04304DD4;
extern f32 D_overlay_67_04304DD8;
extern f32 D_overlay_67_04304DDC;
extern f32 D_overlay_67_04304DE0;
extern f32 D_overlay_67_04304DE4;
extern f32 D_overlay_67_04304DE8;
extern f32 D_overlay_67_04304DEC;
extern f32 D_overlay_67_04304DF0;
extern f32 D_overlay_67_04304DF4;
extern f32 D_overlay_67_04304DF8;
extern f32 D_overlay_67_04304DFC;
extern f32 D_overlay_67_04304E00;
extern f32 D_overlay_67_04304C80[];
extern u8 D_overlay_67_043044F0[];
extern s32 D_overlay_67_04304570;
extern u8 D_overlay_67_04304700[];
extern u8 D_overlay_67_043047C0[];
extern u8 D_overlay_67_043048C8[];
extern u8 D_overlay_67_043049A0[];
s32 objAnimDframe(void *obj, s32 anim, f32 speed);
void amSndPlay(s32 soundId, s32 arg1);
void amTunePlay(s32 id);
void amTuneSetFade(f32 vol, s32 arg1);
void amTuneSetVolume(s32 vol);
s32 frontGetMode(void);
s32 mainGetNextCharacter(void);
void lightObject(void *obj, void *ctl, s32 a2, s32 a3);
void modGenAnimMatrices(void *a, s32 b, void *c, s32 d, f32 e);
void objEnsureNotTargetted(void *obj);
Object *objGetPlayerNo(s32 n);
f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
s16 trackGetBlock(f32 x, f32 y, f32 z);
s32 hitVectorCheck(s32 arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5);
s32 trackNearestIntersection(s32 a, void *from, void *to, void *out, s32 mask, s32 c);
void fxMakeConeTextureCoords(void *cone, s16 a, s32 b, s32 c);
void fxMakeConeLength(void *cone, s16 len, s32 a);

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisEditMenu(s32 arg0) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisEditMenu.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s8 func_overlay_67_04300008_1F87A00(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, s16 *arg5, s16 *arg6) {
    s32 start;
    s32 end;
    s32 i;
    Object **list;
    Object *obj;
    s8 result;

    list = objGetObjList(&start, &end);
    for (i = 0; i < end - start; i++) {
        obj = list[start + i];
        if ((obj->behaviorId == 0x68) && (arg1 == *(s32 *)((u8 *)obj->racer + 0x14))) {
            *arg2 = obj->segment.trans.x_position;
            *arg3 = obj->segment.trans.y_position;
            *arg4 = obj->segment.trans.z_position;
            *arg5 = obj->segment.trans.y_rotation;
            *arg6 = obj->segment.trans.x_rotation;
        }
    }
    result = 2;
    if (arg0 != -1) {
        result = D_overlay_67_04304580[(arg0 * 8) + arg1];
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/func_overlay_67_04300008_1F87A00.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mantisJump(Object *arg0, void *arg1, s32 arg2) {
    u8 *st = (u8 *)arg1;
    ObjectTransform *tr = &arg0->segment.trans;
    s8 result;

    result = func_overlay_67_04300008_1F87A00((s32)*(s8 *)(st + 0x02), arg2,
                                              (f32 *)(st + 0x20), (f32 *)(st + 0x24), (f32 *)(st + 0x28),
                                              (s16 *)(st + 0x2C), (s16 *)(st + 0x2E));
    if (result != -1) {
        st[0x01] = result;
        st[0x02] = (s8)arg2;
        objAnimSetMove(arg0, (s8)D_overlay_67_04304430[st[0x01] * 2], 0);
        *(f32 *)(st + 0x10) = tr->x_position;
        *(f32 *)(st + 0x20) = *(f32 *)(st + 0x20) - tr->x_position;
        *(f32 *)(st + 0x14) = tr->y_position;
        *(f32 *)(st + 0x24) = *(f32 *)(st + 0x24) - tr->y_position;
        *(f32 *)(st + 0x18) = tr->z_position;
        *(f32 *)(st + 0x28) = *(f32 *)(st + 0x28) - tr->z_position;
        *(s16 *)(st + 0x1C) = tr->y_rotation;
        *(s16 *)(st + 0x2C) = mathDiffAngle(tr->y_rotation, *(s16 *)(st + 0x2C));
        *(s16 *)(st + 0x1E) = tr->x_rotation;
        *(s16 *)(st + 0x2E) = mathDiffAngle(tr->x_rotation, *(s16 *)(st + 0x2E));
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisJump.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_67_0430025C_1F87C54(void) {
    u8 *st;

    if (D_overlay_67_04304574[0] != NULL) {
        st = (u8 *)D_overlay_67_04304574[0]->racer;
        st[0x08] = 0;
        *(s32 *)(st + 0x04) = D_overlay_67_043046C0[D_overlay_67_0430456C];
        if (*(s8 *)(st + 0x0F) == -1) {
            *(s8 *)(st + 0x0F) = 0xC;
        }
    }
    if (D_overlay_67_04304574[1] != NULL) {
        st = (u8 *)D_overlay_67_04304574[1]->racer;
        st[0x08] = 0;
        *(s32 *)(st + 0x04) = D_overlay_67_043046C4[D_overlay_67_0430456C];
        if (*(s8 *)(st + 0x0F) == -1) {
            *(s8 *)(st + 0x0F) = 0xC;
        }
    }
    D_overlay_67_0430456C += 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/func_overlay_67_0430025C_1F87C54.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_67_04300300_1F87CF8(Object *arg0, void *arg1, s32 arg2) {
    u8 *st = (u8 *)arg1;
    ObjectTransform *tr = &arg0->segment.trans;

    switch (arg2) {
    case -2:
        st[0x01] = 0;
        st[0x0F] = 0x78;
        objAnimSetMove(arg0, 0, 0);
        return;
    case -3:
        st[0x01] = 1;
        objAnimSetMove(arg0, 0xF, 0);
        return;
    case -4:
        st[0x0B] |= 0xC0;
        st[0x01] = 0xA;
        objAnimSetMove(arg0, 0xA, 0);
        return;
    case -5:
        st[0x0B] |= 0xC0;
        st[0x01] = 0xB;
        objAnimSetMove(arg0, 0xB, 0);
        return;
    case -6:
        st[0x01] = 0xC;
        st[0x0F] = 0x78;
        objAnimSetMove(arg0, 2, 0);
        return;
    case -7:
        st[0x01] = 0xD;
        objAnimSetMove(arg0, 8, 0);
        return;
    case -8:
        st[0x01] = 0xE;
        objAnimSetMove(arg0, 9, 0);
        return;
    case -9:
        st[0x0C] |= 0xC0;
        st[0x01] = 0xF;
        objAnimSetMove(arg0, 0x14, 0);
        return;
    case -10:
        st[0x01] = 0x10;
        objAnimSetMove(arg0, 0x15, 0);
        return;
    case -11:
        amSndPlayXYZ(0x1B7, tr->x_position, tr->y_position, tr->z_position, 4, NULL);
        st[0x01] = 0x11;
        objAnimSetMove(arg0, 0x16, 0);
        return;
    case -12:
        amSndPlayXYZ(0x1B8, tr->x_position, tr->y_position, tr->z_position, 4, NULL);
        st[0x01] = 0x12;
        objAnimSetMove(arg0, 0x17, 0);
        return;
    case -13:
        amSndPlayXYZ(0x1B7, tr->x_position, tr->y_position, tr->z_position, 4, NULL);
        st[0x01] = 0x13;
        objAnimSetMove(arg0, 0x18, 0);
        return;
    case -18:
        st[0x01] = 0;
        st[0x0F] = -1;
        objAnimSetMove(arg0, 0, 0);
        return;
    case -14:
        st[0x0E] |= 0xC0;
        st[0x01] = 0x14;
        objAnimSetMove(arg0, 0xD, 0);
        return;
    case -15:
        st[0x0E] |= 0xC0;
        st[0x01] = 0x15;
        objAnimSetMove(arg0, 0xE, 0);
        return;
    case -16:
        st[0x01] = 0x16;
        objAnimSetMove(arg0, 0x19, 0);
        return;
    case -17:
        amSndPlayXYZ(0x1B8, tr->x_position, tr->y_position, tr->z_position, 4, NULL);
        st[0x01] = 0x17;
        objAnimSetMove(arg0, 7, 0);
        return;
    default:
        mantisJump(arg0, arg1, arg2);
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/func_overlay_67_04300300_1F87CF8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_67_0430064C_1F88044(Object *arg0, void *arg1) {
    u8 *st = (u8 *)arg1;
    u8 *script = *(u8 **)(st + 0x04);
    u8 idx;
    u8 next;
    s8 cmd;

    idx = st[0x08];
    cmd = (s8)script[idx];
    if (cmd == -1) {
        idx = 0;
        st[0x08] = 0;
        cmd = (s8)script[0];
        next = 1;
        if (cmd != -0x13) {
            do {
                idx = next;
                st[0x08] = next;
                cmd = (s8)script[idx];
                next = (u8)(idx + 1);
            } while (cmd != -0x13);
        }
    }
    next = (u8)(idx + 1);
    if (cmd == -0x13) {
        idx = next;
        st[0x08] = next;
        cmd = (s8)script[idx];
    }
    next = (u8)(idx + 1);
    if ((s8)st[0x02] == cmd) {
        st[0x08] = next;
        cmd = (s8)script[next];
    }
    func_overlay_67_04300300_1F87CF8(arg0, arg1, cmd);
    st[0x08] = (u8)(st[0x08] + 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/func_overlay_67_0430064C_1F88044.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisLand(Object *arg0, void *arg1) {
    ObjectTransform *tr = &arg0->segment.trans;
    u8 setup[0x14];
    f32 dist;
    s32 shake;
    void *made;

    dist = camDistance(tr->x_position, tr->y_position, tr->z_position);
    if (dist < 2000.0f) {
        if (dist < 800.0f) {
            shake = 0x14;
        } else {
            shake = (s32)(((2000.0f - dist) * 20.0f) / 1200.0f);
        }
        camStartShake(0, 0, 0, 0x40000000, shake);
    }
    amSndPlayXYZ(0x1B9, tr->x_position, tr->y_position, tr->z_position, 4, NULL);
    *(s16 *)(setup + 0x00) = 0x13B;
    *(s16 *)(setup + 0x04) = (s16)(s32)tr->x_position;
    *(s16 *)(setup + 0x06) = (s16)(s32)tr->y_position;
    *(s16 *)(setup + 0x08) = (s16)(s32)tr->z_position;
    *(s16 *)(setup + 0x0A) = 0;
    *(s16 *)(setup + 0x0C) = -0x4000;
    *(s16 *)(setup + 0x0E) = 0x2D;
    *(f32 *)(setup + 0x10) = 1.0f;
    made = objSetupObject(setup, 1);
    if (made != NULL) {
        *(u8 *)((u8 *)made + 0x3C) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisLand.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_67_043008C4_1F882BC(void *arg0, void *arg1, s32 arg2) {
    /* Timed event list entry (0x18 bytes), list head stored at arg1+0x34. */
    typedef struct {
        s32 time;       /* +0x00 delay, consumed from the timer */
        u8 ptIdx;       /* +0x04 index into model+0x70 table, 12 bytes each */
        s8 byteIdx;     /* +0x05 offset from arg1+0x3C, -1 = none */
        u8 byteVal;     /* +0x06 value written at arg1+0x3C+byteIdx */
        u8 spurtCount;  /* +0x07 bloodSpurtAdd calls */
        u8 sparkCount;  /* +0x08 sparkAdd calls */
        u8 spawnCount;  /* +0x09 objSetupObject calls */
        s16 explosion;  /* +0x0A explosion type, -1 = none */
        u8 unk0B;
        s32 sparkC;     /* +0x0C passed to sparkAdd */
        s32 sparkD;     /* +0x10 passed to sparkAdd */
        s16 spawnKind;  /* +0x14 object setup kind */
        s16 sound;      /* +0x16 sound id, -1 = none */
    } MantisEvent;
    /* Argument block for sparkAdd (0x24 bytes, starts at sp+0xB0). */
    typedef struct {
        s16 angA;
        s16 angB;
        f32 speedA;
        f32 x;
        f32 y;
        f32 z;
        f32 speedB;
        s16 life;       /* 20 */
        u8 unk1A;       /* 10 */
        u8 unk1B;       /* 0xFF */
        s32 sparkC;
        s32 sparkD;
    } MantisSpark;
    /* Object setup block for objSetupObject (0x18 bytes, starts at sp+0x98). */
    typedef struct {
        s16 kind;
        s16 unk02;      /* not written by this function */
        s16 x;
        s16 y;
        s16 z;
        s16 yaw;
        s16 pitch;
        u8 unk0E;       /* 0x3C */
        u8 unk0F;       /* 1 */
        f32 scale;
        f32 unk14;      /* D_overlay_67_04304D4C */
    } MantisSpawn;

    MantisEvent *ev;
    MantisSpark spark;
    MantisSpawn spawn;
    struct {
        s16 yaw;
        s16 pitch;
    } ang;
    struct {
        s32 a;
        f32 b;
    } dir;
    u8 *mdl;
    u8 *pts;
    u8 *pt;
    void *made;
    f32 px;
    f32 py;
    f32 pz;
    f32 spurtSpeed;
    s32 timer;
    s32 t0;
    s32 i;

    ev = *(MantisEvent **)((u8 *)arg1 + 0x34);
    if (ev == NULL) {
        return;
    }
    mdl = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x6C));
    timer = *(s32 *)((u8 *)arg1 + 0x38) + arg2;
    *(s32 *)((u8 *)arg1 + 0x38) = timer;
    if (timer >= ev->time) {
        t0 = timer - ev->time;
        for (;;) {
            *(s32 *)((u8 *)arg1 + 0x38) = t0;
            /* asm: the next entry's time == 0 terminates the list */
            if ((ev + 1)->time == 0) {
                ev = NULL;
                break;
            }
            ev++;

            pts = *(u8 **)(mdl + 0x70);
            pt = pts + ev->ptIdx * 0xC;
            px = *(f32 *)(pt + 0x0);
            py = *(f32 *)(pt + 0x4);
            pz = *(f32 *)(pt + 0x8);

            if (ev->byteIdx != -1) {
                *(u8 *)((u8 *)arg1 + ev->byteIdx + 0x3C) = ev->byteVal;
            }

            /* blood spurts: random yaw/pitch direction, random speed */
            if (ev->spurtCount != 0) {
                for (i = 0; i < ev->spurtCount; i++) {
                    ang.yaw = mathRnd(-0x8000, 0x7FFF);
                    ang.pitch = mathRnd(0, 0x3000);
                    spurtSpeed = (f32)mathRnd(0x1C2, 0x258) * D_overlay_67_04304D44;
                    mathOneFloatPY(&ang, &dir);
                    bloodSpurtAdd(px, py, pz, dir.a, dir.b, spurtSpeed, 0xFF, 1, 1.0f);
                }
            }

            /* sparks: shared header, random angles and two speeds per spark */
            if (ev->sparkCount != 0) {
                spark.x = px;
                spark.y = py;
                spark.z = pz;
                spark.life = 0x14;
                spark.unk1A = 10;
                spark.unk1B = 0xFF;
                spark.sparkC = ev->sparkC;
                spark.sparkD = ev->sparkD;
                for (i = 0; i < ev->sparkCount; i++) {
                    spark.angA = mathRnd(-0x8000, 0x7FFF);
                    spark.angB = mathRnd(0, 0x3000);
                    spark.speedA = (f32)mathRnd(0x46, 0x5A) * D_overlay_67_04304D48;
                    spark.speedB = (f32)mathRnd(0x19, 0x32) * D_overlay_67_04304D48;
                    sparkAdd(&spark);
                }
            }

            /* object spawns: random yaw/pitch/scale, clear +0x3C of each new object */
            if (ev->spawnCount != 0) {
                spawn.kind = ev->spawnKind;
                spawn.x = (s16)(s32)px;
                spawn.y = (s16)(s32)py;
                spawn.z = (s16)(s32)pz;
                spawn.unk0E = 0x3C;
                spawn.unk0F = 1;
                spawn.unk14 = D_overlay_67_04304D4C;
                for (i = 0; i < ev->spawnCount; i++) {
                    spawn.yaw = mathRnd(-0x8000, 0x7FFF);
                    spawn.pitch = mathRnd(0, 0x3000);
                    spawn.scale = (f32)mathRnd(0x2EE, 0x384) * D_overlay_67_04304D50;
                    made = objSetupObject(&spawn, 1);
                    if (made != NULL) {
                        *(s32 *)((u8 *)made + 0x3C) = 0;
                    }
                }
            }

            if (ev->explosion != -1) {
                explosionStart(ev->explosion, (s16)(s32)px, (s16)(s32)py, (s16)(s32)pz, 0x64, 0);
            }

            if (ev->sound != -1) {
                amSndPlayXYZ((u16)ev->sound, px, py, pz, 4, NULL);
            }

            if (t0 < ev->time) {
                break;
            }
            t0 -= ev->time;
        }
    }
    *(MantisEvent **)((u8 *)arg1 + 0x34) = ev;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/func_overlay_67_043008C4_1F882BC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisInit(Object *arg0, void *arg1) {
    u8 *setup = (u8 *)arg1;
    u8 *st;
    u8 *tbl;

    arg0->segment.trans.y_rotation = (s16)(setup[0x0B] << 8);
    st = (u8 *)arg0->racer;
    st[0x00] = setup[0x0A];
    D_overlay_67_04304574[st[0x00] & 1] = arg0;
    st[0x01] = 0;
    st[0x02] = 0xFF;
    st[0x03] = 0;
    if ((D_overlay_67_04304574[0] != NULL) && (D_overlay_67_04304574[1] != NULL)) {
        D_overlay_67_0430456C = 0;
        func_overlay_67_0430025C_1F87C54();
    }
    st[0x0F] = 0x3C;
    st[0x09] = 0;
    st[0x0A] = 0;
    st[0x0B] = 0;
    st[0x0C] = 0;
    st[0x0D] = 0;
    st[0x0E] = 0;
    objAnimSetMove(arg0, (s8)D_overlay_67_04304430[st[0x01] * 2], 0);
    *(void **)(st + 0x34) = NULL;
    *(s32 *)(st + 0x38) = 0;
    st[0x3C] = 0xFF;
    st[0x3D] = 0xFF;
    st[0x3E] = 0xFF;
    st[0x3F] = 0xFF;
    st[0x40] = 0xFF;
    st[0x41] = 0xFF;
    tbl = *(u8 **)((u8 *)arg0 + 0x40);
    hitInitObjectHit(arg0, 0xF00, 1, 1, *(s16 *)(tbl + 0xB4), *(s16 *)(tbl + 0xB6), *(s16 *)(tbl + 0xB8),
                     *(f32 *)(tbl + 0xBC), *(f32 *)(tbl + 0xC0), -1.0f, 1.0f, 1);
    *(u8 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x31) = 0xFF;
    if (runlinkIsModuleLoaded(0x27) == 0) {
        mantisLightingInit();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisControl(Object *arg0, s32 arg1) {
    u8 pb1[0x1C];         /* objSetupObject params, sp+0xA0 */
    u8 pb2[0x1C];         /* objSetupObject params, sp+0x84 */
    u8 pb3[0x1C];         /* objSetupObject params, sp+0x68 */
    u8 *st;               /* arg0->racer state block (sp+0x30 holds st+0x42) */
    u8 *ctl;              /* *(*(arg0+0x6C)): model/anim control block (sp+0x5C) */
    u8 *hdr;              /* arg0->0x4C header */
    u8 *rec;
    u8 *pe;
    u8 *pl;               /* player->0x4C */
    u8 *c68;
    u8 *c70;
    u8 v;
    u8 flags;
    Object *player;       /* sp+0x48 */
    Object *spawn;
    s16 *blk;
    s16 *endp;            /* a3 cursor */
    f32 *pFrame;          /* &arg0->0x28 (anim frame / timer) */
    f32 *tab;
    f32 frameBefore;      /* sp+0xC0 */
    f32 var;
    f32 dx, dy, dz;
    f32 f12, f14, fpitch;
    s32 yawAcc;
    s32 angle;
    s32 res;
    s32 sIdx;
    s32 i;
    s32 k;

    st = (u8 *)arg0->racer;
    blk = (s16 *)(st + 0x42);
    player = objGetPlayerNo(0);
    ctl = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x6C));
    pFrame = (f32 *)((u8 *)arg0 + 0x28);

    if (player != NULL && ctl != NULL) {
        angle = Arctanf(arg0->segment.trans.x_position - player->segment.trans.x_position,
                        arg0->segment.trans.z_position - player->segment.trans.z_position);
        angle -= arg0->segment.trans.y_rotation;

        /* turn accumulator (st+0x30) toward the player, arg1 steps */
        for (i = arg1; i != 0; i--) {
            *(s32 *)(st + 0x30) += mathDiffAngle((s16)*(s32 *)(st + 0x30), (s16)angle) >> 3;
        }
        yawAcc = *(s32 *)(st + 0x30);

        /* parameter table at st+0x42: 10 s16 entries, a3 = st+0x56 after it */
        blk[0] = 8;
        blk[1] = (s16)yawAcc;
        blk[2] = 0xC8;
        blk[3] = (s16)(yawAcc >> 2);
        blk[4] = 0xCE;
        blk[5] = (s16)(yawAcc >> 2);
        blk[6] = 0xD4;
        blk[7] = (s16)(yawAcc >> 2);
        blk[8] = 0xDA;
        blk[9] = (s16)(yawAcc >> 2);

        /* record flags in the 0x34-byte records at header+0x40 */
        hdr = *(u8 **)((u8 *)arg0 + 0x4C);
        rec = *(u8 **)(hdr + 0x40);
        for (pe = (u8 *)D_overlay_67_043044F0; pe[1] != 0xFF; pe += 2, rec += 0x34) {
            rec[0x30] |= 0x20;
            rec[0x30] &= 0xBF;
            if (pe[1] != 0xFE) {
                flags = st[pe[1] + 9];
                if (flags & 1) {
                    rec[0x30] = (u8)(rec[0x30] | 0x40);
                } else if (flags & 2) {
                    rec[0x30] &= 0xDF;
                }
            }
        }

        /* st+9..st+14: clear bits in the per-slot flag bytes */
        for (i = 5; i >= 0; i--) {
            v = st[9 + i];
            if (v & 0x30) {
                v -= 0x10;
            }
            if (v & 0xC0) {
                v -= 0x40;
            }
            st[9 + i] = (u8)(v & ~4);
        }

        hdr = *(u8 **)((u8 *)arg0 + 0x4C);
        if (hdr[0x31] != 0xFF) {
            sIdx = D_overlay_67_043044F0[hdr[0x31] * 2 + 1];
            if (sIdx != 0xFE) {
                if (st[sIdx + 9] & 2) {
                    st[sIdx + 9] |= 4;
                }
            }
            hdr[0x31] = 0xFF;
        }

        for (i = 5; i >= 0; i--) {
            st[9 + i] &= ~2;
        }

        /* asm passes a3 = st+0x56 as a fourth argument (sig mismatch with the 3-arg definition above) */
        ((void (*)(Object *, u8 *, s32, s16 *))func_overlay_67_043008C4_1F882BC)(arg0, st, arg1, blk + 10);

        /* 6 lanes: write sprite-like entries at a3 for each active slot */
        endp = blk + 10;
        for (i = 5; i >= 0; i--) {
            v = st[0x3C + i];
            if (v != 0xFF) {
                endp[1] = 0x20;
                endp += 6;
                endp[-6] = (s16)((v * 6) | 0x4000);
                endp[-3] = 0x20;
                endp[-4] = (s16)(((v * 6) + 2) | 0x4000);
                endp[-1] = 0x20;
                endp[-2] = (s16)(((v * 6) + 4) | 0x4000);
            }
        }
        endp[0] = 0x1000;

        if ((s8)st[0] == 0) {
            /* sig mismatch: real callee takes (obj, 6, 0, table) */
            ((void (*)(Object *, s32, s32, s16 *))mantisEditMenu)(arg0, 6, 0, endp);
        }

        frameBefore = *pFrame;

        switch ((s8)st[1]) {
        case 0:
        case 12:
            objAnimDframe(arg0, D_overlay_67_04304430[(s8)st[1] * 2 + 1], (f32)arg1);
            if ((s8)st[0x0F] != -1) {
                st[0x0F] = (u8)((s8)st[0x0F] - arg1);
                if ((s8)st[0x0F] <= 0) {
                    st[0x0F] = 0;
                    func_overlay_67_0430064C_1F88044(arg0, st);
                }
            } else {
                Object *other = D_overlay_67_04304574[(st[0] ^ 1) & 1];
                if (other != NULL && *(s8 *)((u8 *)other->racer + 0x0F) == -1) {
                    st[0x0F] = 0xF;
                    *(s8 *)((u8 *)other->racer + 0x0F) = 0xF;
                }
            }
            goto tail;

        case 1:
            res = objAnimDframe(arg0, 0x3B75C28F, (f32)arg1);
            if (frameBefore < D_overlay_67_04304DB4 && D_overlay_67_04304DB4 <= *pFrame) {
                st[3] = 1;
            }
            if (frameBefore < D_overlay_67_04304DB8 && D_overlay_67_04304DB8 <= *pFrame) {
                st[3] = 1;
            }
            if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 10:
        case 11:
            if ((s8)st[1] == 0xA) {
                res = objAnimDframe(arg0, 0x3BE56042, (f32)arg1);
                if (frameBefore < D_overlay_67_04304DBC) {
                    st[0x0B] |= 2;
                    if (D_overlay_67_04304DBC <= *pFrame) {
                        st[3] = 0xA;
                    }
                }
            } else {
                res = objAnimDframe(arg0, 0x3BA3D70A, (f32)arg1);
                if (frameBefore < D_overlay_67_04304DC0) {
                    st[0x0B] |= 2;
                    if (D_overlay_67_04304DC0 <= *pFrame) {
                        st[3] = 0xB;
                    }
                }
            }
            hdr = *(u8 **)((u8 *)arg0 + 0x4C);
            if (*(s16 *)(hdr + 0x06) <= 0) {
                *(u8 **)(st + 0x34) = D_overlay_67_04304700;
                *(s32 *)(st + 0x38) = 0;
                func_overlay_67_04300300_1F87CF8(arg0, st, -0xB);
            } else if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 2:
            res = objAnimDframe(arg0, 0x3C0B4396, (f32)arg1);
            if (res != 0) {
                *pFrame = 1.0f;
            }
            var = (*pFrame - D_overlay_67_04304DC4) / D_overlay_67_04304DC8;
            if (var > 0.0f) {
                if (var > 1.0f) {
                    var = 1.0f;
                }
                dx = ((*(f32 *)(st + 0x20) * var) + *(f32 *)(st + 0x10)) - arg0->segment.trans.x_position;
                dy = (Sinf((s16)(s32)(32768.0f * var)) * 400.0f)
                     + (((*(f32 *)(st + 0x24) * var) + *(f32 *)(st + 0x14)) - arg0->segment.trans.y_position);
                arg0->segment.trans.y_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2C) * var) + *(s16 *)(st + 0x1C));
                arg0->segment.trans.x_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2E) * var) + *(s16 *)(st + 0x1E));
                dz = ((*(f32 *)(st + 0x28) * var) + *(f32 *)(st + 0x18)) - arg0->segment.trans.z_position;
                objMoveXYZ(arg0, dx, dy, dz);
            }
            if (frameBefore < D_overlay_67_04304DCC && D_overlay_67_04304DCC <= *pFrame) {
                mantisLand(arg0, st);
            }
            if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 3:
            res = objAnimDframe(arg0, 0x3C0B4396, (f32)arg1);
            if (res != 0) {
                *pFrame = 1.0f;
            }
            var = (*pFrame - D_overlay_67_04304DD0) / D_overlay_67_04304DD4;
            if (var > 0.0f) {
                if (var > 1.0f) {
                    var = 1.0f;
                }
                dx = ((*(f32 *)(st + 0x20) * var) + *(f32 *)(st + 0x10)) - arg0->segment.trans.x_position;
                dy = (Sinf((s16)(s32)(32768.0f * var)) * 400.0f)
                     + (((*(f32 *)(st + 0x24) * var) + *(f32 *)(st + 0x14)) - arg0->segment.trans.y_position);
                arg0->segment.trans.y_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2C) * var) + *(s16 *)(st + 0x1C));
                arg0->segment.trans.x_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2E) * var) + *(s16 *)(st + 0x1E));
                dz = ((*(f32 *)(st + 0x28) * var) + *(f32 *)(st + 0x18)) - arg0->segment.trans.z_position;
                objMoveXYZ(arg0, dx, dy, dz);
            }
            if (frameBefore < D_overlay_67_04304DD8 && D_overlay_67_04304DD8 <= *pFrame) {
                mantisLand(arg0, st);
            }
            if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 4:
        case 6:
        case 8:
            res = objAnimDframe(arg0, 0x3C0B4396, (f32)arg1);
            if (res != 0) {
                *pFrame = 1.0f;
            }
            var = (*pFrame - D_overlay_67_04304DDC) / D_overlay_67_04304DE0;
            if (var > 0.0f) {
                if (var > 1.0f) {
                    var = 1.0f;
                }
                dx = ((*(f32 *)(st + 0x20) * var) + *(f32 *)(st + 0x10)) - arg0->segment.trans.x_position;
                dy = (Sinf((s16)(s32)(32768.0f * var)) * 250.0f)
                     + (((*(f32 *)(st + 0x24) * var) + *(f32 *)(st + 0x14)) - arg0->segment.trans.y_position);
                arg0->segment.trans.y_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2C) * var) + *(s16 *)(st + 0x1C));
                arg0->segment.trans.x_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2E) * var) + *(s16 *)(st + 0x1E));
                dz = ((*(f32 *)(st + 0x28) * var) + *(f32 *)(st + 0x18)) - arg0->segment.trans.z_position;
                objMoveXYZ(arg0, dx, dy, dz);
            }
            if (frameBefore < D_overlay_67_04304DE4 && D_overlay_67_04304DE4 <= *pFrame) {
                mantisLand(arg0, st);
            }
            if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 5:
        case 7:
        case 9:
            res = objAnimDframe(arg0, 0x3C0B4396, (f32)arg1);
            if (res != 0) {
                *pFrame = 1.0f;
            }
            var = (*pFrame - D_overlay_67_04304DE8) / 0.375f;
            if (var > 0.0f) {
                if (var > 1.0f) {
                    var = 1.0f;
                }
                dx = ((*(f32 *)(st + 0x20) * var) + *(f32 *)(st + 0x10)) - arg0->segment.trans.x_position;
                dy = (Sinf((s16)(s32)(32768.0f * var)) * 250.0f)
                     + (((*(f32 *)(st + 0x24) * var) + *(f32 *)(st + 0x14)) - arg0->segment.trans.y_position);
                arg0->segment.trans.y_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2C) * var) + *(s16 *)(st + 0x1C));
                arg0->segment.trans.x_rotation = (s16)((s32)((f32)*(s16 *)(st + 0x2E) * var) + *(s16 *)(st + 0x1E));
                dz = ((*(f32 *)(st + 0x28) * var) + *(f32 *)(st + 0x18)) - arg0->segment.trans.z_position;
                objMoveXYZ(arg0, dx, dy, dz);
            }
            if (frameBefore < D_overlay_67_04304DEC && D_overlay_67_04304DEC <= *pFrame) {
                mantisLand(arg0, st);
            }
            if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 13:
        case 14:
            if (objAnimDframe(arg0, D_overlay_67_04304430[(s8)st[1] * 2 + 1], (f32)arg1) != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 15:
            res = objAnimDframe(arg0, 0x3BDA9004, (f32)arg1);
            if (frameBefore < D_overlay_67_04304DF0) {
                st[0x0C] |= 2;
                if (D_overlay_67_04304DF0 <= *pFrame) {
                    st[3] = 0xF;
                }
            }
            hdr = *(u8 **)((u8 *)arg0 + 0x4C);
            if (*(s16 *)(hdr + 0x06) <= 0) {
                *(u8 **)(st + 0x34) = D_overlay_67_043047C0;
                *(s32 *)(st + 0x38) = 0;
                func_overlay_67_04300300_1F87CF8(arg0, st, -0xC);
            } else if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 16:
            res = objAnimDframe(arg0, 0x3C08A47F, (f32)arg1);
            if (frameBefore < D_overlay_67_04304DF4) {
                st[0x0A] |= 2;
                if (D_overlay_67_04304DF4 <= *pFrame) {
                    st[3] = 0x10;
                }
            }
            hdr = *(u8 **)((u8 *)arg0 + 0x4C);
            if (*(s16 *)(hdr + 0x06) <= 0) {
                if (*(s16 *)(*(u8 **)((u8 *)player + 0x4C) + 0x06) < 0x100) {
                    *(s16 *)(hdr + 0x06) = 0x100;
                } else if (D_overlay_67_04304574[0] != NULL && D_overlay_67_04304574[1] != NULL) {
                    *(u8 **)(st + 0x34) = D_overlay_67_043049A0;
                    *(s32 *)(st + 0x38) = 0;
                    func_overlay_67_04300300_1F87CF8(arg0, st, -0x11);
                } else {
                    *(s16 *)((u8 *)player->racer + 0x5C8) = 0x3C;
                    amTuneSetFade(0.5f, 0);
                    {
                        s32 nextChar = mainGetNextCharacter();
                        mainChangeLevel(0x189, nextChar, 0, frontGetMode(), 0, 0);
                    }
                }
            } else if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 17:
            if (objAnimDframe(arg0, 0x3B88A47F, (f32)arg1) != 0) {
                func_overlay_67_0430025C_1F87C54();
                st[0x0B] |= 1;
                objEnsureNotTargetted(arg0);
                hdr = *(u8 **)((u8 *)arg0 + 0x4C);
                *(s16 *)(hdr + 0x06) = 0xF00;
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 18:
            if (objAnimDframe(arg0, 0x3B88A47F, (f32)arg1) != 0) {
                func_overlay_67_0430025C_1F87C54();
                st[0x0C] |= 1;
                objEnsureNotTargetted(arg0);
                hdr = *(u8 **)((u8 *)arg0 + 0x4C);
                *(s16 *)(hdr + 0x06) = 0x1E00;
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 19:
            if (objAnimDframe(arg0, 0x3B88A47F, (f32)arg1) != 0) {
                func_overlay_67_0430025C_1F87C54();
                st[0x0E] |= 1;
                objEnsureNotTargetted(arg0);
                hdr = *(u8 **)((u8 *)arg0 + 0x4C);
                *(s16 *)(hdr + 0x06) = 0x3200;
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 20:
        case 21:
            if ((s8)st[1] == 0x14) {
                res = objAnimDframe(arg0, 0x3C03126F, (f32)arg1);
                if (frameBefore < D_overlay_67_04304DF8) {
                    st[0x0E] |= 2;
                    if (D_overlay_67_04304DF8 <= *pFrame) {
                        st[3] = 0x14;
                    }
                }
            } else {
                res = objAnimDframe(arg0, 0x3C03126F, (f32)arg1);
                if (frameBefore < D_overlay_67_04304DFC) {
                    st[0x0E] |= 2;
                    if (D_overlay_67_04304DFC <= *pFrame) {
                        st[3] = 0x15;
                    }
                }
            }
            hdr = *(u8 **)((u8 *)arg0 + 0x4C);
            if (*(s16 *)(hdr + 0x06) <= 0) {
                *(u8 **)(st + 0x34) = D_overlay_67_043048C8;
                *(s32 *)(st + 0x38) = 0;
                func_overlay_67_04300300_1F87CF8(arg0, st, -0xD);
            } else if (res != 0) {
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 22:
            res = objAnimDframe(arg0, 0x3BDA9004, (f32)arg1);
            if (frameBefore < D_overlay_67_04304E00 && D_overlay_67_04304E00 <= *pFrame) {
                amSndPlay(0x1B2, 0);
            }
            if (res != 0) {
                *pFrame = 1.0f;
                if (D_overlay_67_04304570 == 0) {
                    amTuneSetVolume(0x70);
                    amTunePlay(0x35);
                    amTuneSetFade(10.0f, 0x50);
                    D_overlay_67_04304570 = 1;
                }
                func_overlay_67_0430064C_1F88044(arg0, st);
            }
            goto tail;

        case 23:
            if (objAnimDframe(arg0, 0x3B8754F3, (f32)arg1) != 0) {
                D_overlay_67_04304574[(s8)st[0]] = NULL;
                if (D_overlay_67_04304574[0] == NULL && D_overlay_67_04304574[1] == NULL) {
                    s32 nextChar = mainGetNextCharacter();
                    mainChangeLevel(0x189, nextChar, 0, frontGetMode(), 1, 0);
                } else {
                    func_overlay_67_0430025C_1F87C54();
                }
                objFreeObject(arg0);
                return;
            }
            goto tail;

        default:
            break;
        }

tail:
        /* anim matrices / light for the model block */
        if ((s8)ctl[0x0A] != 0) {
            modGenAnimMatrices(ctl, *(s32 *)ctl, arg0, 0x3F800000, 0.0f);
            lightObject(arg0, ctl, *(s32 *)((u8 *)arg0 + 0x54),
                        *(s32 *)(ctl + ((s8)ctl[0x0B] * 4) + 0x10));
            ctl[0x0A] = 0;
        }

        switch (st[3]) {
        case 1:
            *(s16 *)(pb1 + 0x00) = 0x2D6;
            *(s16 *)(pb1 + 0x0C) = 0;
            *(s16 *)(pb1 + 0x0E) = 0;
            pb1[0x10] = 5;
            *(s8 *)(pb1 + 0x11) = -0x4B;
            *(s16 *)(pb1 + 0x12) = 0x113;
            *(s16 *)(pb1 + 0x14) = 0x16C;
            *(s16 *)(pb1 + 0x16) = 0x16C;
            *(s16 *)(pb1 + 0x18) = 0x888;
            *(s16 *)(pb1 + 0x1A) = 0x28;
            if (objGetPlayerNo(0) != NULL) {
                c68 = *(u8 **)(ctl + 0x68);
                *(s16 *)(pb1 + 0x04) = (s16)*(f32 *)(c68 + 0x0C);
                *(s16 *)(pb1 + 0x06) = (s16)*(f32 *)(c68 + 0x10);
                *(s16 *)(pb1 + 0x08) = (s16)*(f32 *)(c68 + 0x14);
                *(s16 *)(pb1 + 0x0A) = arg0->segment.trans.y_rotation + 0x4000;
                spawn = (Object *)objSetupObject(pb1, 1);
                if (spawn != NULL) {
                    *(s32 *)((u8 *)spawn + 0x3C) = 0;
                }
                c68 = *(u8 **)(ctl + 0x68);
                *(s16 *)(pb1 + 0x04) = (s16)*(f32 *)(c68 + 0x18);
                *(s16 *)(pb1 + 0x06) = (s16)*(f32 *)(c68 + 0x1C);
                *(s16 *)(pb1 + 0x08) = (s16)*(f32 *)(c68 + 0x20);
                *(s16 *)(pb1 + 0x0A) = arg0->segment.trans.y_rotation - 0x4000;
                spawn = (Object *)objSetupObject(pb1, 1);
                if (spawn != NULL) {
                    *(s32 *)((u8 *)spawn + 0x3C) = 0;
                }
            }
            amSndPlayXYZ(0xF3, arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                         arg0->segment.trans.z_position, 4, NULL);
            break;

        case 10:
        case 11:
            pl = *(u8 **)((u8 *)player + 0x4C);
            c68 = *(u8 **)(ctl + 0x68);
            f12 = *(f32 *)(pl + 0x0C) - *(f32 *)(c68 + 0x60);
            dy = *(f32 *)(pl + 0x10) - *(f32 *)(c68 + 0x64);
            f14 = *(f32 *)(pl + 0x14) - *(f32 *)(c68 + 0x68);
            *(s16 *)(pb2 + 0x00) = 0x2D9;
            *(s16 *)(pb2 + 0x04) = (s16)(s32)*(f32 *)(c68 + 0x60);
            *(s16 *)(pb2 + 0x06) = (s16)(s32)*(f32 *)(c68 + 0x64);
            *(s16 *)(pb2 + 0x08) = (s16)(s32)*(f32 *)(c68 + 0x68);
            pb2[0x0A] = 2;
            pb2[0x0B] = 0x14;
            *(s16 *)(pb2 + 0x0C) = (s16)(Arctanf(f12, f14) + 0x8000);
            *(u16 *)(pb2 + 0x0E) = Arctanf(dy, sqrtf((f12 * f12) + (f14 * f14)));
            *(f32 *)(pb2 + 0x10) = 0.25f;
            *(f32 *)(pb2 + 0x14) = 16.0f;
            *(Object **)(pb2 + 0x18) = arg0;
            spawn = (Object *)objSetupObject(pb2, 1);
            if (spawn != NULL) {
                *(s32 *)((u8 *)spawn + 0x3C) = 0;
                amSndPlayXYZ(0x1BB, spawn->segment.trans.x_position, spawn->segment.trans.y_position,
                             spawn->segment.trans.z_position, 4, NULL);
            }
            break;

        case 15:
            pl = *(u8 **)((u8 *)player + 0x4C);
            c68 = *(u8 **)(ctl + 0x68);
            f12 = *(f32 *)(pl + 0x0C) - *(f32 *)(c68 + 0x90);
            dy = *(f32 *)(pl + 0x10) - *(f32 *)(c68 + 0x94);
            f14 = *(f32 *)(pl + 0x14) - *(f32 *)(c68 + 0x98);
            *(s16 *)(pb3 + 0x00) = 0x2E7;
            *(s16 *)(pb3 + 0x04) = (s16)(s32)*(f32 *)(c68 + 0x90);
            *(s16 *)(pb3 + 0x06) = (s16)(s32)*(f32 *)(c68 + 0x94);
            *(s16 *)(pb3 + 0x08) = (s16)(s32)*(f32 *)(c68 + 0x98);
            pb3[0x0A] = 3;
            pb3[0x0B] = 0x14;
            *(s16 *)(pb3 + 0x0C) = (s16)(Arctanf(f12, f14) + 0x8000);
            *(u16 *)(pb3 + 0x0E) = Arctanf(dy, sqrtf((f12 * f12) + (f14 * f14)));
            *(f32 *)(pb3 + 0x10) = 1.0f;
            *(f32 *)(pb3 + 0x14) = 20.0f;
            *(Object **)(pb3 + 0x18) = arg0;
            spawn = (Object *)objSetupObject(pb3, 1);
            if (spawn != NULL) {
                *(s32 *)((u8 *)spawn + 0x3C) = 0;
                amSndPlayXYZ(0x1BC, spawn->segment.trans.x_position, spawn->segment.trans.y_position,
                             spawn->segment.trans.z_position, 4, NULL);
            }
            break;

        case 16:
            pl = *(u8 **)((u8 *)player + 0x4C);
            c70 = *(u8 **)(ctl + 0x70);
            f12 = *(f32 *)(pl + 0x0C) - *(f32 *)(c70 + 0xE4);
            dy = *(f32 *)(pl + 0x10) - *(f32 *)(c70 + 0xE8);
            f14 = *(f32 *)(pl + 0x14) - *(f32 *)(c70 + 0xEC);
            *(s16 *)(pb3 + 0x00) = 0x2E7;
            *(s16 *)(pb3 + 0x04) = (s16)(s32)*(f32 *)(c70 + 0xE4);
            *(s16 *)(pb3 + 0x06) = (s16)(s32)*(f32 *)(c70 + 0xE8);
            *(s16 *)(pb3 + 0x08) = (s16)(s32)*(f32 *)(c70 + 0xEC);
            pb3[0x0A] = 2;
            pb3[0x0B] = 0x19;
            *(s16 *)(pb3 + 0x0C) = (s16)(Arctanf(f12, f14) + 0x7800);
            *(u16 *)(pb3 + 0x0E) = Arctanf(dy, sqrtf((f12 * f12) + (f14 * f14)));
            *(f32 *)(pb3 + 0x10) = 0.5f;
            *(Object **)(pb3 + 0x18) = arg0;
            tab = D_overlay_67_04304C80;
            for (k = 4; k >= 0; k--) {
                *(f32 *)(pb3 + 0x14) = *tab * 16.0f;
                spawn = (Object *)objSetupObject(pb3, 1);
                if (spawn != NULL) {
                    *(s32 *)((u8 *)spawn + 0x3C) = 0;
                }
                *(s16 *)(pb3 + 0x0C) += 0x400;
                tab -= 1;
            }
            amSndPlayXYZ(0xC4, spawn->segment.trans.x_position, spawn->segment.trans.y_position,
                         spawn->segment.trans.z_position, 4, NULL);
            break;

        case 20:
        case 21:
            pl = *(u8 **)((u8 *)player + 0x4C);
            c68 = *(u8 **)(ctl + 0x68);
            f12 = *(f32 *)(pl + 0x0C) - *(f32 *)(c68 + 0x00);
            dy = *(f32 *)(pl + 0x10) - *(f32 *)(c68 + 0x04);
            f14 = *(f32 *)(pl + 0x14) - *(f32 *)(c68 + 0x08);
            *(s16 *)(pb2 + 0x00) = 0x2D9;
            *(s16 *)(pb2 + 0x04) = (s16)(s32)*(f32 *)(c68 + 0x00);
            *(s16 *)(pb2 + 0x06) = (s16)(s32)*(f32 *)(c68 + 0x04);
            *(s16 *)(pb2 + 0x08) = (s16)(s32)*(f32 *)(c68 + 0x08);
            pb2[0x0A] = 4;
            pb2[0x0B] = 0x14;
            *(s16 *)(pb2 + 0x0C) = (s16)(Arctanf(f12, f14) + 0x8000);
            *(u16 *)(pb2 + 0x0E) = Arctanf(dy, sqrtf((f12 * f12) + (f14 * f14)));
            *(f32 *)(pb2 + 0x10) = D_overlay_67_04304E58;
            *(f32 *)(pb2 + 0x14) = 20.0f;
            *(Object **)(pb2 + 0x18) = arg0;
            spawn = (Object *)objSetupObject(pb2, 1);
            if (spawn != NULL) {
                *(s32 *)((u8 *)spawn + 0x3C) = 0;
                amSndPlayXYZ(0xC5, spawn->segment.trans.x_position, spawn->segment.trans.y_position,
                             spawn->segment.trans.z_position, 4, NULL);
            }
            break;

        default:
            break;
        }

        st[3] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisSplitGfx(void **arg0, Object *arg1, s32 arg2) {
    u8 *st = (u8 *)arg1->racer;
    u32 *dl;
    s16 fogA;
    s16 fogB;
    s16 fogC;
    s16 fogD;
    u8 fr;
    u8 fg;
    u8 fb;
    u8 flags;
    s32 span;

    if (arg2 < 0 || arg2 >= 6) {
        return;
    }
    flags = st[arg2 + 9];
    if (flags & 0x40) {
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xF8000000;
        dl[1] = 0xFFFFFFFF;
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xBC000008;
        dl[1] = 0x05000500;
    } else if (flags & 0x10) {
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xF8000000;
        dl[1] = 0x32FF32FF;
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xBC000008;
        dl[1] = 0x05000500;
    } else if (flags & 0x04) {
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xF8000000;
        dl[1] = 0xFF3232FF;
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xBC000008;
        dl[1] = 0x05000500;
    } else {
        trackGetFog(0, &fogA, &fogB, &fogC, &fr, &fg, &fb, &fogD);
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xF8000000;
        dl[1] = (u32)((fr << 0x18) | (fg << 0x10) | (fb << 8) | 0xFF);
        dl = (u32 *)*arg0;
        *arg0 = dl + 2;
        dl[0] = 0xBC000008;
        span = fogB - fogA;
        dl[1] = (u32)(((((0x1F400 / span) & 0xFFFF) << 0x10)) |
                      ((((s32)((fogA * -0x100) + 0x1F400)) / span) & 0xFFFF));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisSplitGfx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantismissileInit(Object *arg0, void *arg1) {
    u8 *setup = (u8 *)arg1;
    u8 *st;
    u8 *tbl;
    f32 varF6;

    arg0->segment.trans.y_rotation = *(s16 *)(setup + 0x0A);
    arg0->segment.trans.x_rotation = *(s16 *)(setup + 0x0C);
    arg0->segment.trans.z_rotation = *(s16 *)(setup + 0x0E);
    *(f32 *)((u8 *)arg0 + 0x1C) = 0.0f;
    arg0->segment.trans.scale = (f32)setup[0x10] * D_overlay_67_04304E5C;
    *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x20) = (f32)setup[0x11] * D_overlay_67_04304E5C;

    st = (u8 *)arg0->racer;
    *(f32 *)(st + 0x0C) = 0.0f;
    varF6 = (f32)*(u16 *)(setup + 0x12);
    *(s16 *)(st + 0x1E) = 0;
    *(f32 *)(st + 0x10) = varF6 * D_overlay_67_04304E5C;
    *(s16 *)(st + 0x14) = *(s16 *)(setup + 0x14);
    *(s16 *)(st + 0x16) = *(s16 *)(setup + 0x16);
    *(s16 *)(st + 0x1A) = 0;
    *(s16 *)(st + 0x1C) = 0;
    *(s16 *)(st + 0x1E) = 0;
    *(s16 *)(st + 0x18) = *(s16 *)(setup + 0x18);
    *(s32 *)(st + 0x20) = *(s32 *)(setup + 0x1C);

    /* model -> table of 10-byte entries, indexed by the count at +0x30 */
    tbl = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x6C));
    tbl = *(u8 **)tbl;
    *(s32 *)(st + 0x04) = 0;
    st[0x02] = 0;
    st[0x03] = 0;
    {
        u8 *entry = *(u8 **)(tbl + 0x1C) + (*(s32 *)*(u8 **)(tbl + 0x30)) * 10;
        *(s32 *)(st + 0x08) = (s32)fxAllocateCone(*(s16 *)(entry + 0), *(s16 *)(entry + 2), *(s16 *)(entry + 4),
                                                 -0x8000, 0, 20.0f, 200.0f, 8, 0x10, -1);
    }
    st[0x00] = 0;
    st[0x01] = (s8)(setup[0x1A] * 6);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantismissileInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantismissileControl(Object *arg0, s32 arg1) {
    u8 *st = (u8 *)arg0->racer;
    s32 i;
    s32 temp;
    s32 brightness;
    s32 cone;
    s16 yawDiff;
    s16 pitchDiff;
    s16 tmp16;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 f;
    f32 powVal;
    u8 *tgt;
    u8 *tgt2;
    void *targetPtr;
    void *hitOut;
    /* sp+0x80: trackNearestIntersection output (obj, then hit position) */
    struct {
        void *obj;
        f32 pos[3];
    } hit;
    /* sp+0xAC..0xD8: hitVectorCheck segment. [3..5] = obj pos (+0xC),
       [6..8] = obj pos copy at sp+0xC4 (trackNearestIntersection 'from'),
       [9..10] = radius (scale * 32) at +0x24/+0x28 */
    f32 seg[11];

    *(s32 *)((u8 *)arg0 + 0x84) = 0;
    seg[6] = arg0->segment.trans.x_position;
    seg[7] = arg0->segment.trans.y_position;
    seg[8] = arg0->segment.trans.z_position;

    switch (st[0x00]) {
    case 0:
        /* asm: loop runs arg1 times (asm delay-slot counter, not m2c's arg1-1) */
        for (i = 0; i < arg1; i++) {
            vx = *(f32 *)((u8 *)arg0 + 0x1C);
            vy = *(f32 *)((u8 *)arg0 + 0x20);
            vz = *(f32 *)((u8 *)arg0 + 0x24);
            arg0->segment.trans.x_position += vx;
            arg0->segment.trans.y_position += vy;
            arg0->segment.trans.z_position += vz;
            *(f32 *)((u8 *)arg0 + 0x1C) = vx * D_overlay_67_04304E60;
            *(f32 *)((u8 *)arg0 + 0x20) = vy * D_overlay_67_04304E60;
            *(f32 *)((u8 *)arg0 + 0x24) = vz * D_overlay_67_04304E60;
        }
        *(s16 *)((u8 *)arg0 + 0x2E) = trackGetBlock(arg0->segment.trans.x_position,
                                                    arg0->segment.trans.y_position,
                                                    arg0->segment.trans.z_position);
        vy = *(f32 *)((u8 *)arg0 + 0x20);
        if ((D_overlay_67_04304E64 < vy) && (vy < D_overlay_67_04304E68)) {
            st[0x00] = 1;
            amSndPlayXYZ(0xBA, arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                         arg0->segment.trans.z_position, 4, NULL);
        }
        break;

    case 1:
        *(s32 *)((u8 *)arg0 + 0x84) |= 1;
        *(f32 *)(st + 0x04) = *(f32 *)(st + 0x04) + ((f32)arg1 * D_overlay_67_04304E6C);
        if (*(f32 *)(st + 0x04) > 2.0f) {
            st[0x00] = 2;
            *(f32 *)(st + 0x04) = 2.0f;
        }
        break;

    case 2:
        *(s32 *)((u8 *)arg0 + 0x84) |= 6;
        /* target (st+0x20)->transform (+0x4C): position at +0xC/+0x10/+0x14 */
        tgt = *(u8 **)(*(u8 **)(st + 0x20) + 0x4C);
        tx = *(f32 *)(tgt + 0x0C);
        ty = *(f32 *)(tgt + 0x10);
        tz = *(f32 *)(tgt + 0x14);
        for (i = 0; i < arg1; i++) {
            dx = arg0->segment.trans.x_position - tx;
            dz = arg0->segment.trans.z_position - tz;
            dy = arg0->segment.trans.y_position - ty;
            dist = sqrtf((dx * dx) + (dz * dz));

            /* yaw: turn towards target with st+0x1A as angular velocity */
            yawDiff = mathDiffAngle(arg0->segment.trans.y_rotation, Arctanf(dx, dz));
            temp = (s32)((f32)*(s16 *)(st + 0x14) * *(f32 *)(st + 0x0C));
            if ((yawDiff < 0) && (yawDiff >= -0x5FFF)) {
                tmp16 = *(s16 *)(st + 0x1A);
                *(s16 *)(st + 0x1A) = (s16)(tmp16 + (((-temp - tmp16) * 5) >> 6));
            } else if ((yawDiff > 0) && (yawDiff < 0x6000)) {
                tmp16 = *(s16 *)(st + 0x1A);
                *(s16 *)(st + 0x1A) = (s16)(tmp16 + (((temp - tmp16) * 5) >> 6));
            } else {
                tmp16 = *(s16 *)(st + 0x1A);
                *(s16 *)(st + 0x1A) = (s16)(tmp16 - (tmp16 >> 3));
            }
            arg0->segment.trans.y_rotation = (s16)(arg0->segment.trans.y_rotation + *(s16 *)(st + 0x1A));

            /* pitch: st+0x1C angular velocity, target st+0x16 * blend */
            pitchDiff = mathDiffAngle(arg0->segment.trans.x_rotation, -Arctanf(dy, dist));
            temp = (s32)((f32)*(s16 *)(st + 0x16) * *(f32 *)(st + 0x0C));
            if ((pitchDiff < 0) && (pitchDiff >= -0x5FFF)) {
                tmp16 = *(s16 *)(st + 0x1C);
                *(s16 *)(st + 0x1C) = (s16)(tmp16 + ((-temp - tmp16) >> 3));
            } else if ((pitchDiff > 0) && (pitchDiff < 0x6000)) {
                tmp16 = *(s16 *)(st + 0x1C);
                *(s16 *)(st + 0x1C) = (s16)(tmp16 + ((temp - tmp16) >> 3));
            } else {
                tmp16 = *(s16 *)(st + 0x1C);
                *(s16 *)(st + 0x1C) = (s16)(tmp16 - (tmp16 >> 3));
            }
            arg0->segment.trans.x_rotation = (s16)(arg0->segment.trans.x_rotation + *(s16 *)(st + 0x1C));

            /* roll (z) eases towards st+0x18, blend st+0x0C approaches 1.0 */
            tmp16 = *(s16 *)(st + 0x1E);
            *(s16 *)(st + 0x1E) = (s16)(tmp16 + ((*(s16 *)(st + 0x18) - tmp16) >> 4));
            f = *(f32 *)(st + 0x0C);
            *(f32 *)(st + 0x0C) = f + ((1.0f - f) * 0.125f);
            arg0->segment.trans.z_rotation = (s16)(arg0->segment.trans.z_rotation + *(s16 *)(st + 0x1E));

            *(f32 *)((u8 *)arg0 + 0x24) = -*(f32 *)(st + 0x0C) * *(f32 *)(st + 0x10);
            mathOneFloatPY(arg0, (u8 *)arg0 + 0x1C);
            objMoveXYZ(arg0, *(f32 *)((u8 *)arg0 + 0x1C), *(f32 *)((u8 *)arg0 + 0x20),
                       *(f32 *)((u8 *)arg0 + 0x24));
        }

        st[0x02] = (u8)(st[0x02] + (arg1 * 0x10));
        powVal = Powerf(D_overlay_67_04304E70, arg1);
        f = *(f32 *)(st + 0x04);
        *(f32 *)(st + 0x04) = f + (((1.0f + (0.25f * Sinf(st[0x02] << 8))) - f) * (1.0f - powVal));

        /* from = pos copy at sp+0xC4 (taken at entry), to = obj pos */
        if (trackNearestIntersection((s32)arg0, &seg[6], &arg0->segment.trans.x_position, &hit, 0, 0) != 0) {
            objMoveXYZ(arg0, hit.pos[0] - arg0->segment.trans.x_position,
                       hit.pos[1] - arg0->segment.trans.y_position,
                       hit.pos[2] - arg0->segment.trans.z_position);
            st[0x00] = 3;
        }

        seg[3] = arg0->segment.trans.x_position;
        seg[4] = arg0->segment.trans.y_position;
        seg[5] = arg0->segment.trans.z_position;
        seg[9] = arg0->segment.trans.scale * 32.0f;
        seg[10] = arg0->segment.trans.scale * 32.0f;
        targetPtr = *(void **)(st + 0x20);
        if (hitVectorCheck((s32)arg0, seg, 1, &targetPtr, &hitOut, 0) != 0) {
            /* asm reloads st+0x20 here (hitVectorCheck may change targetPtr) */
            tgt2 = *(u8 **)(*(u8 **)(st + 0x20) + 0x4C);
            *(s16 *)(tgt2 + 0x06) = (s16)(*(s16 *)(tgt2 + 0x06) - 0x200);
            st[0x00] = 3;
        }

        if (arg1 < (s32)st[0x01]) {
            st[0x01] = (u8)(st[0x01] - arg1);
        } else {
            st[0x00] = 3;
        }
        break;

    case 3:
        amSndPlayXYZ(0x96, arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                     arg0->segment.trans.z_position, 4, NULL);
        explosionStart(3, (s16)(s32)arg0->segment.trans.x_position,
                       (s16)(s32)arg0->segment.trans.y_position,
                       (s16)(s32)arg0->segment.trans.z_position, 0x64, 0);
        objFreeObject(arg0);
        break;

    default:
        break;
    }

    /* common tail: exhaust cone */
    cone = *(s32 *)(st + 0x08);
    if (cone != 0) {
        if (0.0f < *(f32 *)(st + 0x04)) {
            temp = arg1 * 0x10;
            if (1.25f < *(f32 *)(st + 0x04)) {
                brightness = (s32)((*(f32 *)(st + 0x04) - 1.25f) * 128.0f);
            } else {
                brightness = 0;
            }
            tgt2 = *(u8 **)((u8 *)arg0 + 0x78);
            if (tgt2 != NULL) {
                tgt = *(u8 **)tgt2;
                if (tgt != NULL) {
                    tgt[0x3B] = (s8)brightness;
                }
            }
            st[0x03] = (u8)(st[0x03] + temp);
            /* asm: a2 still holds the cone pointer, a3 = frames * 0x10 */
            fxMakeConeTextureCoords((void *)cone, (s16)(st[0x03] << 8), cone, temp);
            fxMakeConeLength((void *)cone, (s16)(s32)(*(f32 *)(st + 0x04) * 200.0f), 0xFF);
        }
    }
    partUpdateTriggers(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantismissileControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantismissileDrawThruster(Gfx **arg0, MatrixS **arg1, Object *arg2) {
    u8 *st = (u8 *)arg2->racer;

    if ((*(s32 *)(st + 0x08) != 0) && (*(f32 *)(st + 0x04) > 0.0f)) {
        camPushModelMtx(arg0, arg1, &arg2->segment.trans, 1.0f, 0.0f);
        fxDrawCone(arg0, (void *)*(s32 *)(st + 0x08), 6, 0xFF);
        camRestoreModelMtx(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantismissileDrawThruster.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantismissileFree(Object *arg0) {
    s32 cone = *(s32 *)((u8 *)arg0->racer + 0x08);

    if (cone != 0) {
        fxFreeCone((void *)cone);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantismissileFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisboltInit(Object *arg0, void *arg1) {
    u8 *params = (u8 *)arg1;
    u8 *st = (u8 *)arg0->racer;
    u8 temp_t1;

    arg0->segment.trans.y_rotation = *(s16 *)(params + 0x0C);
    arg0->segment.trans.x_rotation = *(s16 *)(params + 0x0E);
    *(f32 *)((u8 *)arg0 + 0x24) = -(f32)*(s32 *)(params + 0x14);
    mathOneFloatPY((u8 *)arg0 + 0x1C);
    arg0->segment.trans.scale = (f32)*(s32 *)(params + 0x10);
    *(s32 *)st = *(s32 *)(params + 0x18);
    *(s16 *)(st + 4) = (s16)(params[0x0B] * 6);
    temp_t1 = params[0x0A];
    st[7] = 0;
    st[6] = temp_t1;
    hitInitObjectHit(arg0, (temp_t1 & 0xFF) << 8, 1, 4, 0, 0, 0, 80.0f, 80.0f, 100.0f, 1.0f, 0x11U);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisboltInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisboltControl(Object *arg0, s32 arg1) {
    u8 *st = (u8 *)arg0->racer;
    u8 *track = *(u8 **)((u8 *)arg0 + 0x4C);
    f32 pos[3];
    s32 sp70;
    s32 sp3C = 0;
    f32 temp_f0 = (f32)arg1;

    if ((*(s16 *)(track + 0x06) <= 0) || (st[7] != 0)) {
        explosionStart(3, (s16)arg0->segment.trans.x_position, (s16)arg0->segment.trans.y_position,
                       (s16)arg0->segment.trans.z_position, 0x64, 0);
        objFreeObject(arg0);
        return;
    }
    *(s16 *)(st + 4) = (s16)(*(s16 *)(st + 4) - arg1);
    if (*(s16 *)(st + 4) < 0) {
        objFreeObject(arg0);
        return;
    }
    arg0->segment.trans.z_rotation = (s16)(arg0->segment.trans.z_rotation + (arg1 << 0xC));
    pos[0] = arg0->segment.trans.x_position;
    pos[1] = arg0->segment.trans.y_position;
    pos[2] = arg0->segment.trans.z_position;
    objMoveXYZ(arg0, *(f32 *)((u8 *)arg0 + 0x1C) * temp_f0, *(f32 *)((u8 *)arg0 + 0x20) * temp_f0,
               *(f32 *)((u8 *)arg0 + 0x24) * temp_f0);
    sp70 = *(s32 *)(track + 0x24);
    trackMakePolylist(1, pos, &arg0->segment.trans.x_position, &sp70, 0xCE002000, 0, 0);
    if (trackGetIntersect(arg0, pos, &arg0->segment.trans.x_position, sp70, 1, &sp3C) != 0) {
        st[7] = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisboltControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisboltDraw(Gfx **arg0, MatrixS **arg1, Object *arg2) {
    u8 *st = (u8 *)arg2->racer;
    s32 var_v0;
    s32 temp_v1;
    s32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 temp_f28;
    f32 var_f20;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 sp80;
    u32 sp78;
    void *sp7C;
    void *sp74;
    Gfx *g;

    var_v0 = (st[6] == 2) ? 0 : 1;
    spC0 = arg2->segment.trans.z_rotation;
    spBC = arg2->segment.trans.x_position;
    spB8 = arg2->segment.trans.y_position;
    spB4 = arg2->segment.trans.z_position;
    temp_v1 = var_v0 * 4;
    temp_f28 = arg2->segment.trans.scale;
    arg2->segment.trans.x_position = spBC - (4.0f * *(f32 *)((u8 *)arg2 + 0x1C));
    arg2->segment.trans.y_position = spB8 - (4.0f * *(f32 *)((u8 *)arg2 + 0x20));
    arg2->segment.trans.z_position = spB4 - (4.0f * *(f32 *)((u8 *)arg2 + 0x24));
    var_f20 = 0.5f;
    var_s2 = 0xFF;
    var_s4 = 0;
    var_s3 = 0x33;
    sp80 = temp_v1;
    texDPTextureX(spB4, 0x40800000, arg0, *(s32 *)(*(u8 **)((u8 *)arg2 + 0x6C) + temp_v1), 0x207, 0);
    sp78 = ((((((u32)D_84304CC8 & 6) | 0x28) & 0xFF) << 0x10) | 0x04000000 | 0x3A);
    sp74 = D_84304C88;
    sp7C = D_84304CC8;
    for (var_s5 = 4; var_s5 != 0; var_s5--) {
        arg2->segment.trans.scale = var_f20 * temp_f28;
        camPushModelMtx(arg0, arg1, &arg2->segment.trans, 1.0f, 0.0f);
        if (sp80 == 0) {
            g = *arg0;
            *arg0 = g + 1;
            g->words.w1 = ((var_s2 & 0xFF) << 8) | 0xFF000000 | (var_s3 & 0xFF);
            g->words.w0 = 0xFA000000;
            g = *arg0;
            *arg0 = g + 1;
            g->words.w1 = -1U;
        } else {
            g = *arg0;
            *arg0 = g + 1;
            g->words.w1 = ((var_s2 & 0xFF) << 0x10) | ((var_s4 & 0xFF) << 8) | (var_s3 & 0xFF);
            g->words.w0 = 0xFA000000;
            g = *arg0;
            *arg0 = g + 1;
            g->words.w1 = -1U;
        }
        (*arg0)->words.w0 = 0xFB000000;
        g = *arg0;
        *arg0 = g + 1;
        g->words.w0 = sp78;
        g->words.w1 = (u32)sp7C;
        g = *arg0;
        *arg0 = g + 1;
        g->words.w0 = 0x05310040;
        g->words.w1 = (u32)sp74;
        g = *arg0;
        *arg0 = g + 1;
        g->words.w1 = 0;
        g->words.w0 = 0xE7000000;
        camPopModelMtx(arg0);
        arg2->segment.trans.x_position += *(f32 *)((u8 *)arg2 + 0x1C);
        arg2->segment.trans.y_position += *(f32 *)((u8 *)arg2 + 0x20);
        arg2->segment.trans.z_position += *(f32 *)((u8 *)arg2 + 0x24);
        arg2->segment.trans.z_rotation += 0x800;
        var_f20 += 0.125f;
        var_s2 -= 0x3D;
        var_s4 += 0x3D;
        var_s3 += 0x33;
    }
    g = *arg0;
    *arg0 = g + 1;
    g->words.w1 = -1U;
    g->words.w0 = 0xFA000000;
    arg2->segment.trans.z_rotation = (s16)spC0;
    arg2->segment.trans.x_position = spBC;
    arg2->segment.trans.y_position = spB8;
    arg2->segment.trans.scale = temp_f28;
    arg2->segment.trans.z_position = spB4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisboltDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisrockInit(Object *arg0, void *arg1) {
    u8 *params = (u8 *)arg1;
    u8 *st = (u8 *)arg0->racer;
    u8 temp_t1;

    arg0->segment.trans.y_rotation = *(s16 *)(params + 0x0C);
    arg0->segment.trans.z_rotation = 0;
    arg0->segment.trans.x_rotation = *(s16 *)(params + 0x0E);
    arg0->segment.trans.scale = arg0->segment.trans.scale * (f32)*(s32 *)(params + 0x10);
    *(f32 *)((u8 *)arg0 + 0x24) = -(f32)*(s32 *)(params + 0x14);
    mathOneFloatPY((u8 *)arg0 + 0x1C);
    *(s32 *)st = *(s32 *)(params + 0x18);
    *(s16 *)(st + 4) = (s16)(params[0x0B] * 6);
    temp_t1 = params[0x0A];
    st[7] = 0;
    st[6] = temp_t1;
    hitInitObjectHit(arg0, (temp_t1 & 0xFF) << 8, 1, 4, 0, 0, 0, 10.0f, 10.0f, 100.0f, 1.0f, 0x11U);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisrockInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisrockControl(Object *arg0, s32 arg1) {
    u8 *st = (u8 *)arg0->racer;
    u8 *track = *(u8 **)((u8 *)arg0 + 0x4C);
    s16 hp = *(s16 *)(track + 0x06);
    s32 temp_s1 = hp >> 8;
    f32 temp_f0 = (f32)arg1;
    u8 spawn[0x24];
    f32 pos[3];
    s32 spCC = 0;
    s32 var_s0;
    s32 n;
    s32 spC4;
    void *sp8C = NULL;
    f32 temp_f20 = D_overlay_67_04304E78;
    f32 temp_f22 = D_overlay_67_04304E74;
    void *temp_v0_2;

    if (hp <= 0) {
        explosionStart(3, (s16)arg0->segment.trans.x_position, (s16)arg0->segment.trans.y_position,
                       (s16)arg0->segment.trans.z_position, 0x64, 0);
        amSndPlayXYZ(0x96U, arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                     arg0->segment.trans.z_position, 4U, NULL);
        objFreeObject(arg0);
        return;
    }
    if (st[7] != 0) {
        if (temp_s1 > 0) {
            spCC = 0x10000 / temp_s1;
        }
        *(s16 *)(spawn + 0) = 0x138;
        *(s16 *)(spawn + 4) = (s16)arg0->segment.trans.x_position;
        *(s16 *)(spawn + 6) = (s16)arg0->segment.trans.y_position;
        *(s16 *)(spawn + 8) = (s16)arg0->segment.trans.z_position;
        *(s16 *)(spawn + 14) = 0x3C;
        *(f32 *)(spawn + 24) = 0.25f;
        spawn[28] = 0x64;
        *(s32 *)(spawn + 32) = 0;
        n = temp_s1 - 1;
        if (temp_s1 != 0) {
            var_s0 = spCC * n;
            /* asm: do/while, runs temp_s1 - 1 times */
            do {
                *(s16 *)(spawn + 10) = (s16)(mathRnd(-0x800, 0x800) + var_s0);
                *(s16 *)(spawn + 12) = (s16)mathRnd(0x2800, 0x3800);
                *(f32 *)(spawn + 16) = (f32)mathRnd(0x32, 0x4B) * temp_f20;
                *(f32 *)(spawn + 20) = (f32)mathRnd(0x32, 0x4B) * temp_f22;
                temp_v0_2 = objSetupObject(spawn, 1);
                var_s0 += -spCC;
                if (temp_v0_2 != NULL) {
                    *(s32 *)((u8 *)temp_v0_2 + 0x3C) = 0;
                }
                n -= 1;
            } while (n != 0);
        }
        amSndPlayXYZ(0x195U, arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                     arg0->segment.trans.z_position, 4U, NULL);
        objFreeObject(arg0);
        return;
    }
    *(s16 *)(st + 4) = (s16)(*(s16 *)(st + 4) - arg1);
    if ((*(s16 *)(st + 4) < 0) || (*(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x06) <= 0)) {
        objFreeObject(arg0);
        return;
    }
    arg0->segment.trans.z_rotation = (s16)(arg0->segment.trans.z_rotation + (arg1 << 0x0A));
    pos[0] = arg0->segment.trans.x_position;
    pos[1] = arg0->segment.trans.y_position;
    pos[2] = arg0->segment.trans.z_position;
    objMoveXYZ(arg0, *(f32 *)((u8 *)arg0 + 0x1C) * temp_f0, *(f32 *)((u8 *)arg0 + 0x20) * temp_f0,
               *(f32 *)((u8 *)arg0 + 0x24) * temp_f0);
    spC4 = *(s32 *)(track + 0x24);
    trackMakePolylist(1, pos, &arg0->segment.trans.x_position, &spC4, 0xCE002000, 0, 0);
    if (trackGetIntersect(arg0, pos, &arg0->segment.trans.x_position, spC4, 1, &sp8C) != 0) {
        st[7] = 1;
    }
    *(s32 *)((u8 *)arg0 + 0x84) = 1;
    partAdjustScaling(arg0->segment.trans.scale / *(f32 *)(*(u8 **)((u8 *)arg0 + 0x40)));
    partUpdateTriggers(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o67/overlay_67/mantisrockControl.s")
#endif
