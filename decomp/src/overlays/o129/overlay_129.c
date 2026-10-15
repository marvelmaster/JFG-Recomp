#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct TransformerState {
    f32 trigRadiusSq;            /* 0x00 */
    f32 yMin;                    /* 0x04 */
    f32 yMax;                    /* 0x08 */
    u8 mode;                     /* 0x0C */
    u8 state;                    /* 0x0D */
    u8 nextState;                /* 0x0E */
    u8 timer;                    /* 0x0F */
    s32 sndHandle;               /* 0x10 */
    void *spawn;                 /* 0x14 */
    u8 active;                   /* 0x18 */
    u8 fogR;                     /* 0x19 */
    u8 fogG;                     /* 0x1A */
    u8 fogB;                     /* 0x1B */
    s16 fogNear;                 /* 0x1C */
    s16 fogFar;                  /* 0x1E */
} TransformerState;

extern u8 D_overlay_129_08101060[];
extern u8 D_overlay_129_08101068[];
extern u8 D_overlay_129_08101070[];
extern u8 D_overlay_129_08101090[];
extern u8 D_overlay_129_081010B0[];
extern u8 D_overlay_129_081010D0[];
extern u8 D_overlay_129_081010F0[];
extern u8 D_overlay_129_08101110[];
extern u8 D_overlay_129_08101130[];
extern u8 D_overlay_129_08101150[];
extern u8 D_overlay_129_08101170[];
extern u8 D_overlay_129_08101180[];
extern f32 D_overlay_129_0810121C;
extern f32 D_overlay_129_08101220;
extern f32 D_overlay_129_08101224;
extern f32 D_overlay_129_08101228;
extern f32 D_overlay_129_0810122C;
extern f32 D_overlay_129_08101230;
extern f32 D_overlay_129_08101240;
extern f32 D_overlay_129_08101244;
extern f32 D_overlay_129_08101248;
extern f32 D_overlay_129_0810124C;
extern f32 D_overlay_129_08101250;
extern f32 D_overlay_129_08101254;
extern f32 D_overlay_129_08101258;
extern f32 D_overlay_129_0810125C;
extern s16 D_overlay_129_08101260;
extern s16 D_overlay_129_08101262;
extern s16 D_overlay_129_08101264;
extern f32 D_overlay_129_08101268;
extern f32 D_overlay_129_0810126C;
extern s16 D_overlay_129_08101270;

f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
void *objSetupObject(void *params, s32 arg1, void *owner);
void *objGetPlayerNo(s32 player);
Object **objGetObjList(s32 *start, s32 *end);
void *camGetPtr(void);
void *mainGetGameCharacter(s32 player, s32 idx);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndStopXYZ(s32 handle);
void hitInitObjectHit(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g, f32 h, f32 i, f32 j, s32 k);
void trackGetFog(s32 fogIdx, void *a, void *b, void *c, void *d, void *e, void *f, void *g);
void trackFadeFog(s32 fogIdx, s32 red, s32 green, s32 blue, s32 near, s32 far, f32 timer);
s32 setupClearScreen(void *arg0);
void blastdoorStatus(s32 door, s32 open);
void mainPauseDisable(s32 n);
void objMoveXYZ(Object *obj, f32 x, f32 y, f32 z);
s16 dAngle(s16 a, s16 b, f32 c);
u16 Arctanf(f32 y, f32 x);
f32 Cosf(s32 angle);
void *modLoadModel(s32 id, s32 flags);
void modFreeModel(void *model);
void modGenAnimMatrices(void *model, s32 count, void *obj, s32 arg3, f32 arg4);
s32 makeModelGfx(void *dst, void *hdr, s32 a, s32 b, s32 start, s32 end, s32 c);
s32 objAnimSetMove(void *obj, s8 arg1, s32 arg2);
void mmFree(void *data);
void func_overlay_129_081008CC_1FCE09C(void *arg0, s32 arg1, s32 arg2);
void *func_overlay_129_0810084C_1FCE01C(void);
void *func_overlay_129_08100224_1FCD9F4(void *arg0);
void *func_overlay_129_0810028C_1FCDA5C(void *arg0);

void func_overlay_129_08100000_1FCD7D0(void *arg0, f32 arg1);
void func_overlay_129_08100084_1FCD854(void *arg0, f32 arg1);
void func_overlay_129_081000D0_1FCD8A0(void *arg0, void *arg1, s32 arg2);
void func_overlay_129_08100EB8_1FCE688(void *arg0, s32 arg1, s32 arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_129_08100000_1FCD7D0(void *arg0, f32 arg1) {
    u16 sp36;
    u8 sp35;

    trackGetFog(0, (u8 *)arg0 + 0x1C, (u8 *)arg0 + 0x1E, &sp36, (u8 *)arg0 + 0x19, (u8 *)arg0 + 0x1A, (u8 *)arg0 + 0x1B, &sp35);
    trackFadeFog(0, 0, 0, 0, 0x3C0, 0x3DE, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_08100000_1FCD7D0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_129_08100084_1FCD854(void *arg0, f32 arg1) {
    TransformerState *st = (TransformerState *)arg0;

    trackFadeFog(0, st->fogR, st->fogG, st->fogB, st->fogNear, st->fogFar, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_08100084_1FCD854.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_129_081000D0_1FCD8A0(void *arg0, void *arg1, s32 arg2) {
    TransformerState *st = (TransformerState *)arg1;
    Object *tr = (Object *)arg0;
    Object *spawn;
    s16 *spawnState;
    s16 *params;

    /* arg0: transformer object (pos at 0x0C/0x10/0x14, 0x8C = active flag),
       arg1: transformer state. */
    if (st->active != 0) {
        params = (s16 *)D_overlay_129_08101180;
        params[2] = (s16) tr->segment.trans.x_position;
        params[3] = (s16) (tr->segment.trans.y_position + 62.5f);
        params[4] = (s16) tr->segment.trans.z_position;
        st->active = 0;
        st->spawn = objSetupObject(D_overlay_129_08101180, 1, arg1);
    }
    spawn = (Object *)st->spawn;
    if (spawn != NULL) {
        spawnState = (s16 *)spawn->racer;
        if (*(s32 *)((u8 *)arg0 + 0x8C) != 0) {
            spawnState[1] = (s16) (spawnState[1] + (arg2 * 2));
            if (spawnState[1] >= 0x100) {
                spawnState[1] = 0xFF;
            }
        } else {
            spawnState[1] = (s16) (spawnState[1] - (arg2 * 0x10));
            if (spawnState[1] < 0) {
                spawnState[1] = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_081000D0_1FCD8A0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_129_08100224_1FCD9F4(void *arg0) {
    switch (*(s8 *)((u8 *)arg0 + 0x1)) {
    case 0:
        return D_overlay_129_08101070;
    case 4:
        return D_overlay_129_081010B0;
    case 1:
        return D_overlay_129_081010F0;
    case 5:
        return D_overlay_129_08101130;
    default:
        return NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_08100224_1FCD9F4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_129_0810028C_1FCDA5C(void *arg0) {
    switch (*(s8 *)((u8 *)arg0 + 0x1)) {
    case 0:
        return D_overlay_129_08101090;
    case 4:
        return D_overlay_129_081010D0;
    case 1:
        return D_overlay_129_08101110;
    case 5:
        return D_overlay_129_08101150;
    default:
        return NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_0810028C_1FCDA5C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void transformerInit(Object *obj, void *setup) {
    TransformerState *st = (TransformerState *)obj->racer;
    f32 radius;
    u8 mode;

    radius = (f32) *(s16 *)((u8 *)setup + 0xA);
    st->trigRadiusSq = radius * radius;
    st->yMin = obj->segment.trans.y_position + (f32) *(s8 *)((u8 *)setup + 0xB);
    st->yMax = obj->segment.trans.y_position + (f32) *(s8 *)((u8 *)setup + 0xC);
    st->state = 0;
    mode = *(u8 *)((u8 *)setup + 0xD) & 0xF;
    st->mode = mode;
    st->nextState = 0;
    st->timer = 0;
    st->sndHandle = 0;
    st->active = 1;
    *(u8 *)((u8 *)obj + 0x3A) = D_overlay_129_08101170[mode];
    hitInitObjectHit(-1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/transformerInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void transformerControl(Object *obj, s32 arg1) {
    TransformerState *st;
    Object *player;
    u8 *pst;
    u8 *chr;
    u16 pressed;
    u8 next;
    u8 doorIdx;

    player = objGetPlayerNo(0);
    if (player != NULL) {
        st = (TransformerState *)obj->racer;
        pst = (u8 *)player->racer;
        pressed = joyGetPressed(0);
        chr = mainGetGameCharacter(0, pst[1]);
        func_overlay_129_081000D0_1FCD8A0(obj, st, arg1);
        next = st->state;
        switch (next) {
        case 0:
            if ((pressed & 0x8000) && (*(s32 *)(pst + 0x568) == 0) && (*(s16 *)(*(u8 **)((u8 *)player + 0x4C) + 6) >= 0x100) && ((*(s16 *)(chr + 0x12) > 0) || (*(u32 *)(chr + 0x4) & 0x1F)) && (func_overlay_129_08100224_1FCD9F4(pst) != NULL)) {
                f32 dx = player->segment.trans.x_position - obj->segment.trans.x_position;
                f32 dz = player->segment.trans.z_position - obj->segment.trans.z_position;

                if (((dx * dx) + (dz * dz)) < st->trigRadiusSq) {
                    f32 py = player->segment.trans.y_position;

                    if ((st->yMin <= py) && (py <= st->yMax)) {
                        pst[0x19F] = 1;
                        *(s32 *)((u8 *)obj + 0x88) = 0;
                        *(s32 *)((u8 *)obj + 0x8C) = 1;
                        func_overlay_129_081008CC_1FCE09C(player, 0, 1);
                        func_overlay_129_08100000_1FCD7D0(st, 4.0f);
                        amSndPlayXYZ(0x18, obj->segment.trans.x_position, obj->segment.trans.y_position, obj->segment.trans.z_position, 1, (u8 *)st + 0x10);
                        st->state = 6;
                        st->timer = 0xF0;
                        st->nextState = 1;
                    }
                }
            }
            next = st->state;
            break;
        case 1:
            setupClearScreen(D_overlay_129_08101068);
            st->state = 6;
            st->timer = 0x4B;
            st->nextState = 2;
            next = 6;
            break;
        case 2:
            doorIdx = st->mode;
            if (doorIdx != (*(u16 *)(chr + 0x4) & 0x1F)) {
                if (*(s16 *)(chr + 0x12) > 0) {
                    pst[0x189] = doorIdx;
                    *(u16 *)(chr + 0x4) = (u16) ((st->mode & 0x1F) | (*(u16 *)(chr + 0x4) & 0xFFE0));
                    *(s16 *)(chr + 0x12) = (s16) (*(s16 *)(chr + 0x12) - 1);
                    blastdoorStatus(0, 0);
                    blastdoorStatus(1, 1);
                } else {
                    pst[0x189] = 0;
                    *(u16 *)(chr + 0x4) = (u16) (*(u16 *)(chr + 0x4) & 0xFFE0);
                    blastdoorStatus(0, 1);
                    blastdoorStatus(1, 0);
                }
            } else {
                pst[0x189] = 0;
                *(u16 *)(chr + 0x4) = (u16) (*(u16 *)(chr + 0x4) & 0xFFE0);
                blastdoorStatus(0, 1);
                blastdoorStatus(1, 0);
            }
            func_overlay_129_08100EB8_1FCE688(player, *(s16 *)((u8 *)func_overlay_129_08100224_1FCD9F4(pst) + ((*(u16 *)(chr + 0x4) & 0x1F) * 2)), *(s16 *)((u8 *)func_overlay_129_0810028C_1FCDA5C(pst) + ((*(u16 *)(chr + 0x4) & 0x1F) * 2)));
            if (st->sndHandle != 0) {
                amSndStopXYZ(st->sndHandle);
            }
            amSndPlayXYZ(0xDB, obj->segment.trans.x_position, obj->segment.trans.y_position, obj->segment.trans.z_position, 4, NULL);
            st->state = 3;
            next = 3;
            break;
        case 3:
            setupClearScreen(D_overlay_129_08101060);
            st->timer = 0x3C;
            st->state = 6;
            st->nextState = 4;
            next = 6;
            break;
        case 4:
            *(s32 *)((u8 *)obj + 0x8C) = 0;
            st->timer = 0x3C;
            st->state = 6;
            st->nextState = 5;
            func_overlay_129_08100084_1FCD854(st, 1.0f);
            next = st->state;
            break;
        case 5:
            pst[0x19F] = 0;
            *(f32 *)(pst + 0x594) = 0.0f;
            *(f32 *)(pst + 0x118) = 0.0f;
            st->state = 0;
            next = 0;
            break;
        case 6:
            if (arg1 < (s32) st->timer) {
                st->timer = (u8) (st->timer - arg1);
            } else {
                st->state = st->nextState;
            }
            next = st->state;
            break;
        }
        if (next != 0) {
            if (*(s32 *)(pst + 0x5C8) < 0xA) {
                *(s32 *)(pst + 0x5C8) = 0xA;
            }
            mainPauseDisable(0xA);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/transformerControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_129_0810084C_1FCE01C(void) {
    Object **list;
    s32 start;
    s32 end;
    s32 i;
    void *found = NULL;

    list = objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        if (list[i]->behaviorId == 0x7C) {
            found = list[i];
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_0810084C_1FCE01C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_129_081008CC_1FCE09C(void *arg0, s32 arg1, s32 arg2) {
    u8 *cam;
    f32 dx;
    f32 dz;

    cam = (u8 *)camGetPtr();
    D_overlay_129_0810124C = ((Object *)arg0)->segment.trans.x_position;
    D_overlay_129_08101250 = ((Object *)arg0)->segment.trans.y_position + 4.0f;
    D_overlay_129_08101254 = ((Object *)arg0)->segment.trans.z_position;
    D_overlay_129_08101240 = ((Object *)arg0)->segment.trans.x_position;
    D_overlay_129_08101244 = ((Object *)arg0)->segment.trans.y_position + 50.0f;
    D_overlay_129_08101248 = ((Object *)arg0)->segment.trans.z_position;
    dx = *(f32 *)(cam + 0xC) - D_overlay_129_0810124C;
    dz = *(f32 *)(cam + 0x14) - D_overlay_129_08101254;
    D_overlay_129_08101258 = sqrtf((dx * dx) + (dz * dz));
    D_overlay_129_0810125C = *(f32 *)(cam + 0x10) - D_overlay_129_08101250;
    if (arg2 != 0) {
        D_overlay_129_08101260 = (s16) (0x8000 - Arctanf(dx, dz));
    } else {
        D_overlay_129_08101260 = (s16) arg1;
    }
    D_overlay_129_08101262 = 0;
    D_overlay_129_08101264 = (s16) arg2;
    D_overlay_129_08101268 = D_overlay_129_08101258;
    D_overlay_129_0810126C = D_overlay_129_0810125C;
    D_overlay_129_08101270 = (s16) arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_081008CC_1FCE09C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void transformerCamera(Object *cam, s32 arg1) {
    f32 blend;
    f32 dx;
    f32 dz;
    s16 yaw;
    u16 pitch;
    Object *tr;

    if (D_overlay_129_08101264 != 0) {
        /* asm: Powerf called with only the base argument set */
        blend = 1.0f - ((f32 (*)(f32))Powerf)(D_overlay_129_0810121C);
    } else {
        blend = 1.0f;
    }
    tr = func_overlay_129_0810084C_1FCE01C();
    if ((tr != NULL) && (*(s32 *)((u8 *)tr + 0x8C) == 0)) {
        D_overlay_129_08101258 += (D_overlay_129_08101268 - D_overlay_129_08101258) * blend;
        D_overlay_129_0810125C += (D_overlay_129_0810126C - D_overlay_129_0810125C) * blend;
    } else {
        D_overlay_129_08101258 += (120.0f - D_overlay_129_08101258) * blend;
        D_overlay_129_0810125C += (0.0f - D_overlay_129_0810125C) * blend;
    }
    D_overlay_129_08101262 += arg1 * 8;
    if (D_overlay_129_08101262 >= 0xC1) {
        D_overlay_129_08101262 = 0xC0;
    }
    D_overlay_129_08101260 += D_overlay_129_08101262 * arg1;
    cam->segment.trans.x_position = (Sinf(D_overlay_129_08101260) * D_overlay_129_08101258) + D_overlay_129_0810124C;
    cam->segment.trans.y_position = D_overlay_129_08101250 + D_overlay_129_0810125C;
    cam->segment.trans.z_position = D_overlay_129_08101254 - (Cosf((s32) D_overlay_129_08101260) * D_overlay_129_08101258);
    dx = cam->segment.trans.x_position - D_overlay_129_08101240;
    dz = cam->segment.trans.z_position - D_overlay_129_08101248;
    yaw = (s16) (0x8000 - Arctanf(dx, dz));
    pitch = Arctanf(cam->segment.trans.y_position - D_overlay_129_08101244, sqrtf((dx * dx) + (dz * dz)));
    if (D_overlay_129_08101264 != 0) {
        blend = 1.0f - Powerf(D_overlay_129_08101220, arg1);
    } else {
        blend = 1.0f;
    }
    cam->segment.trans.y_rotation = dAngle(cam->segment.trans.y_rotation, yaw, blend);
    cam->segment.trans.x_rotation = dAngle(cam->segment.trans.x_rotation, (s16) pitch, blend);
    D_overlay_129_08101264 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/transformerCamera.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void transformerMovePlayer(void *arg0, void *arg1, s32 arg2) {
    Object *tr;
    f32 blend;
    f32 fade;
    f32 tx;
    f32 tz;
    f32 targetY;
    f32 limit;

    tr = func_overlay_129_0810084C_1FCE01C();
    if (tr != NULL) {
        blend = Powerf(D_overlay_129_08101224, arg2);
        *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)((u8 *)arg0 + 0x20) * blend;
        fade = 1.0f - blend;
        if (*(s32 *)((u8 *)tr + 0x8C) != 0) {
            *(f32 *)((u8 *)arg1 + 0x594) = *(f32 *)((u8 *)arg1 + 0x594) + ((1.0f - *(f32 *)((u8 *)arg1 + 0x594)) * fade);
        } else {
            *(f32 *)((u8 *)arg1 + 0x594) = *(f32 *)((u8 *)arg1 + 0x594) + ((0.0f - *(f32 *)((u8 *)arg1 + 0x594)) * fade);
        }
        tx = tr->segment.trans.x_position;
        *(s32 *)((u8 *)tr + 0x88) += arg2;
        tz = tr->segment.trans.z_position;
        targetY = ((Sinf((s16) (*(s32 *)((u8 *)tr + 0x88) << 8)) * 8.0f) + 40.0f) * *(f32 *)((u8 *)arg1 + 0x594) + *(f32 *)((u8 *)tr + 0x10);
        fade = 1.0f - Powerf(D_overlay_129_08101228, arg2);
        limit = (targetY - ((Object *)arg0)->segment.trans.y_position) * fade;
        blend = (f32) arg2 * D_overlay_129_0810122C;
        if (blend < limit) {
            limit = blend;
        }
        if (*(f32 *)((u8 *)arg0 + 0x20) < D_overlay_129_08101230) {
            *(f32 *)((u8 *)arg0 + 0x20) = D_overlay_129_08101230;
        }
        objMoveXYZ(arg0, (tx - ((Object *)arg0)->segment.trans.x_position) * fade, limit, (tz - ((Object *)arg0)->segment.trans.z_position) * fade);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/transformerMovePlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_129_08100EB8_1FCE688(void *arg0, s32 arg1, s32 arg2) {
    s32 *model;
    s32 *oldModel;
    s32 *newModel;
    void *anim;
    s32 numBones;

    model = modLoadModel(arg1, 1);
    if (model != NULL) {
        modFreeModel(*(void **)((u8 *)arg0 + 0x6C));
        *(s32 **)((u8 *)arg0 + 0x6C) = model;
        /* asm: objAnimSetMove called with a non-float 3rd argument */
        ((s32 (*)(void *, s8, s32))objAnimSetMove)(arg0, *(s8 *)((u8 *)arg0 + 0x3B), *(s32 *)((u8 *)arg0 + 0x28));
        numBones = model[0];
        modGenAnimMatrices(model, numBones, arg0, *(s32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x48), 0.0f);
        model[0xA / 4] = 0;
        anim = *(void **)((u8 *)arg0 + 0x50);
        if (*(u32 *)((u8 *)anim + 0xC) & 8) {
            void *sub = *(void **)((u8 *)anim + 0x1C);

            if (sub != NULL) {
                oldModel = *(s32 **)((u8 *)sub + 0x34);
                if (oldModel != NULL) {
                    mmFree(oldModel);
                }
                newModel = *(s32 **)((u8 *)sub + 0x68);
                if (newModel != NULL) {
                    modFreeModel(newModel);
                    *(s32 **)((u8 *)sub + 0x68) = NULL;
                }
                if (arg1 != arg2) {
                    *(s32 **)((u8 *)sub + 0x60) = model;
                    newModel = modLoadModel(arg2, 1);
                    *(s32 **)((u8 *)sub + 0x68) = newModel;
                    *(s32 **)((u8 *)sub + 0x64) = newModel;
                    makeModelGfx((u8 *)sub + 0x34, (void *)*newModel, 0x400, 0xB, 0, 0xFF, 1);
                } else {
                    *(s32 **)((u8 *)sub + 0x60) = model;
                    *(s32 **)((u8 *)sub + 0x64) = model;
                    makeModelGfx((u8 *)sub + 0x34, (void *)numBones, 0x400, 0xB, 0, 0xFF, 1);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o129/overlay_129/func_overlay_129_08100EB8_1FCE688.s")
#endif
