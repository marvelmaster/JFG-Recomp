#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern f32 D_overlay_136_08801E90;
extern f32 D_overlay_136_08801E94;
extern s32 __MODULE00136;
f32 Sinf(s16 angle);
void staticcamAdd(void);
void runlinkSetDestructTimer(s32 overlayIndex, s32 selfDestructTimer, s32 refCount, void *obj);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
s32 addRomdefLight(void);
void amCreateAudioPoint(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, u8 arg5, u8 volume, u16 distance, u8 arg8, u8 pitch, u8 arg10, u8 arg11, void *soundMask);
u8 amSoundIsLooped(u16 soundID);
void objFreeObject(void *obj);
void amAudioLineAddVertex(s32 a0, s32 a1, f32 x, f32 y, f32 z, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12);
void *trackGetTrack(void);
s32 camlightAdd(void *arg0, u8 *arg1, void *arg2);
void splinecamMakeSpline(u8 arg0);
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))
extern f32 D_overlay_136_08801E9C;
extern u8 PatrolNodes[];
void cameraAddOverrideObject(void *obj);
void **objGetObjList(s32 *, s32 *);
void **squadsGetSquadronList(s32 *);
f32 GetRangeSquared(f32, f32, f32, f32, f32, f32);
s32 GetClosestPatrolNode(f32, f32, void *, void *, f32, s32);
void *func_overlay_136_08801740_1FD4A40(void *arg0);
extern void *D_overlay_136_08801E60;
extern f32 D_overlay_136_08801E98;
void objAnimSetMove(u8 *obj, u8 move, s32 a, u8 b);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void exitInit(u8 *arg0, u8 *arg1) {
    f32 sp28;
    f32 temp_f2;
    u8 temp_v0;
    u8 *temp_s1;

    temp_v0 = *(u8 *)(arg1 + 0x12);
    if ((s32) temp_v0 < 5) {
        *(f32 *)(arg0 + 0x8) = D_overlay_136_08801E90;
    } else {
        *(f32 *)(arg0 + 0x8) = (f32) temp_v0 * D_overlay_136_08801E94;
    }
    temp_s1 = *(u8 **)(arg0 + 0x68);
    *(s16 *)(arg0 + 0x0) = (s16) (*(u8 *)(arg1 + 0x13) << 0xA);
    *(s16 *)(arg0 + 0x2) = (s16) (*(u8 *)(arg1 + 0x1B) << 0xA);
    sp28 = Sinf(*(s16 *)(arg0 + 0x0));
    *(f32 *)(temp_s1 + 0x0) = Cosf((s32) *(s16 *)(arg0 + 0x2)) * sp28;
    *(f32 *)(temp_s1 + 0x4) = -Sinf(*(s16 *)(arg0 + 0x2));
    sp28 = Cosf((s32) *(s16 *)(arg0 + 0x0));
    temp_f2 = Cosf((s32) *(s16 *)(arg0 + 0x2)) * sp28;
    *(f32 *)(temp_s1 + 0x8) = temp_f2;
    *(f32 *)(temp_s1 + 0xC) = -((*(f32 *)(temp_s1 + 0x0) * *(f32 *)(arg0 + 0xC)) +
                                (*(f32 *)(temp_s1 + 0x4) * *(f32 *)(arg0 + 0x10)) +
                                (temp_f2 * *(f32 *)(arg0 + 0x14)));
    *(s32 *)(temp_s1 + 0x10) = *(u8 *)(arg1 + 0x12);
    *(s16 *)(temp_s1 + 0x14) = (s16) *(u8 *)(arg1 + 0x18);
    *(s16 *)(temp_s1 + 0x16) = (s16) *(u8 *)(arg1 + 0x15);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/exitInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void staticcamInit(u8 *arg0, u8 *arg1) {
    *(s16 *)(arg0 + 0x0) = *(s16 *)(arg1 + 0xE);
    *(s16 *)(arg0 + 0x2) = *(s16 *)(arg1 + 0xC);
    *(s16 *)(arg0 + 0x4) = *(s16 *)(arg1 + 0xA);
    staticcamAdd();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/staticcamInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void setupInit(u8 *arg0, u8 *arg1) {
    runlinkSetDestructTimer(__MODULE00136, 2, 2, arg0);
    *(s32 *)(arg0 + 0x88) = *(u8 *)(arg1 + 0xA);
    *(s32 *)(arg0 + 0x8C) = *(u8 *)(arg1 + 0xB);
    *(s16 *)(arg0 + 0x0) = (s16) (*(u8 *)(arg1 + 0xC) << 0xA);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/setupInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Door record layout (jfg-re docs/levels.md, jfg_forge/core/level_objects.py,
// doorInit: record +0x0A/+0x18 -> object yaw/pitch, low nibble cleared).
void doorInit(u8 *arg0, u8 *arg1) {
    u8 *st;
    u8 *model;
    u8 *sub;
    u8 *grp;
    u8 *src;
    u8 *dst;
    void **tbl;
    u8 *ent;
    u8 *keyp;
    f32 scale;
    f32 maxAbs;
    f32 val;
    f32 hitRadius;
    s32 type;
    s32 v;
    s32 i;
    s32 j;
    s32 k;
    s32 count;
    s32 vcount;
    s32 mn;
    s32 mx;
    s32 key;
    s32 found;

    /* door state at obj+0x68 */
    st = RD_PTR(arg0, 0x68);
    RD_F32(st, 0x0) = RD_F32(arg0, 0x10);
    RD_S16(st, 0x36) = (s16) (RD_U8(arg1, 0xE) << 1);
    RD_U16(st, 0x40) = RD_U8(arg1, 0x10);
    RD_U8(st, 0x42) = RD_U8(arg1, 0x11);
    RD_U8(st, 0x43) = RD_U8(arg1, 0x12);
    RD_S16(st, 0x2E) = RD_S16(arg1, 0xA);
    RD_S16(st, 0x30) = RD_S16(arg1, 0x18);
    RD_S16(st, 0x2C) = RD_S16(arg1, 0xC);
    RD_U8(st, 0x44) = RD_U8(arg1, 0x14);
    RD_U8(st, 0x45) = RD_U8(arg1, 0x15);
    RD_U8(st, 0x4A) = 0;
    RD_F32(st, 0x4) = (f32) RD_U8(arg1, 0x16) * 0.015625f;
    v = RD_U8(arg1, 0x17);
    if (v != 0) {
        RD_S32(st, 0x28) = v;
    } else {
        RD_S32(st, 0x28) = 0xFF;
    }

    type = RD_U8(st, 0x42);
    if (type == 6) {
        RD_U8(st, 0x42) = 4;
        RD_U16(st, 0x40) = (u16) (RD_U16(st, 0x40) * 10);
        type = 4;
    }
    switch (type) {
    case 4:
        if (RD_S16(st, 0x2C) < 0) {
            RD_S16(st, 0x32) = -0x80;
        } else {
            RD_S16(st, 0x32) = 0x80;
        }
        break;
    case 5:
        /* yaw/pitch-style angles: byte * D_overlay_136_08801E98, 0xFF = negated alt byte */
        if (RD_U8(arg1, 0x1E) == 0xFF) {
            RD_U8(st, 0x46) = RD_U8(arg1, 0x1F);
            RD_F32(st, 0x14) = -(f32) RD_U8(arg1, 0x1A) * D_overlay_136_08801E98;
        } else {
            RD_U8(st, 0x46) = RD_U8(arg1, 0x1E);
            RD_F32(st, 0x14) = (f32) RD_U8(arg1, 0x1A) * D_overlay_136_08801E98;
        }
        if (RD_U8(arg1, 0x1F) == 0xFF) {
            RD_U8(st, 0x47) = RD_U8(arg1, 0x1E);
            RD_F32(st, 0x18) = -(f32) RD_U8(arg1, 0x1B) * D_overlay_136_08801E98;
        } else {
            RD_U8(st, 0x47) = RD_U8(arg1, 0x1F);
            RD_F32(st, 0x18) = (f32) RD_U8(arg1, 0x1B) * D_overlay_136_08801E98;
        }
        RD_U8(st, 0x48) = RD_U8(arg1, 0x20);
        RD_F32(st, 0x1C) = (f32) RD_U8(arg1, 0x1C) * D_overlay_136_08801E98;
        RD_U8(st, 0x49) = RD_U8(arg1, 0x21);
        RD_F32(st, 0x20) = (f32) RD_U8(arg1, 0x1D) * D_overlay_136_08801E98;
        if (RD_U8(st, 0x49) == 0xFF) {
            objAnimSetMove(arg0, RD_U8(st, 0x47), 0, 0xFF);
            RD_F32(st, 0x24) = RD_F32(st, 0x18);
        } else {
            objAnimSetMove(arg0, RD_U8(st, 0x49), 0, 0xFF);
            RD_F32(st, 0x24) = RD_F32(st, 0x20);
        }
        if (RD_U8(st, 0x48) != 0xFF) {
            RD_U8(arg0, 0x3A) = 1;
        } else {
            RD_U8(arg0, 0x3A) = RD_U8(arg1, 0xF);
        }
        break;
    default:
        if (RD_S16(st, 0x2C) < 0) {
            RD_S16(st, 0x32) = -0x100;
        } else {
            RD_S16(st, 0x32) = 0x100;
        }
        break;
    }

    RD_S32(st, 0x10) = 0;
    RD_S16(st, 0x34) = 0;
    if (RD_U8(st, 0x43) != 0) {
        RD_S16(st, 0x3E) = 8;
    } else {
        RD_S16(st, 0x3E) = 0;
    }
    RD_U8(st, 0x4B) = RD_U8(arg1, 0x22);
    RD_S16(arg0, 0x0) = (s16) (RD_S16(st, 0x2E) & 0xFFF0);
    RD_S16(arg0, 0x2) = (s16) (RD_S16(st, 0x30) & 0xFFF0);
    maxAbs = 0.0f;
    if (RD_U8(st, 0x42) != 5) {
        RD_U8(arg0, 0x3A) = RD_U8(arg1, 0xF);
    }

    /* size byte (min 10) / 64 scales the model radius */
    scale = (f32) RD_U8(arg1, 0x13);
    if (scale < 10.0f) {
        scale = 10.0f;
    }
    model = RD_PTR(arg0, 0x40);
    RD_F32(arg0, 0x8) = RD_F32(model, 0x0) * (scale * 0.015625f);
    if (RD_S8(arg0, 0x3A) >= RD_S8(model, 0x1F)) {
        RD_U8(arg0, 0x3A) = 0;
    }
    count = RD_S8(model, 0x1F);

    /* per-sub-part transformed vertex copy, min/max and bounding extent */
    for (i = 0; i < count; i++) {
        sub = RD_PTR(RD_PTR(arg0, 0x6C), i * 4);
        grp = RD_PTR(sub, 0x0);
        if (RD_S8(grp, 0x4E) == 0) {
            src = RD_PTR(grp, 0x1C);
            dst = RD_PTR(sub, 0x4);
            vcount = RD_S16(grp, 0x12);
            mn = 0x7D00;
            mx = -0x7D00;
            for (j = 0; j < vcount; j++) {
                RD_S16(dst, 0x2) = (s16) (s32) ((f32) RD_S16(src, 0x2) * RD_F32(st, 0x4));
                v = RD_S16(dst, 0x2);
                if (mx < v) {
                    mx = v;
                }
                if (v < mn) {
                    mn = v;
                }
                src += 0xA;
                dst += 0xA;
            }
            RD_S16(sub, 0x8E) = (s16) mn;
            RD_S16(sub, 0x94) = (s16) mx;
            for (j = 0; j < 6; j++) {
                val = (f32) RD_S16(sub, 0x8C + j * 2);
                if (val < 0.0f) {
                    val = -val;
                }
                if (maxAbs < val) {
                    maxAbs = val;
                }
            }
            RD_F32(arg0, 0x34) = RD_F32(arg0, 0x8) * maxAbs;
        }
    }

    RD_S16(st, 0x38) = 0;
    RD_S16(st, 0x3A) = 0;
    RD_S16(st, 0x3C) = 0;

    /* table search: D_overlay_136_08801E60 is a NULL-terminated list of entries
       (s16 x3 payload at +0/+2/+4, -1-terminated key list from +6). The first
       key matching record +0x00 copies the payload into the door state. */
    tbl = (void **) &D_overlay_136_08801E60;
    found = 0;
    for (k = 0;; k++) {
        ent = (u8 *) tbl[k];
        if (ent == NULL || found) {
            break;
        }
        if (RD_S16(ent, 0x6) != -1) {
            keyp = ent + 0x6;
            key = RD_S16(keyp, 0);
            do {
                if (RD_S16(arg1, 0x0) == key) {
                    found = 1;
                    RD_S16(st, 0x38) = RD_S16(ent, 0x0);
                    RD_S16(st, 0x3A) = RD_S16(ent, 0x2);
                    RD_S16(st, 0x3C) = RD_S16(ent, 0x4);
                }
                keyp += 2;
                key = RD_S16(keyp, 0);
            } while (key != -1 && !found);
        }
    }

    hitRadius = RD_F32(arg0, 0x8) * 32.0f;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, hitRadius, hitRadius, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/doorInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void doorSwitchInit(u8 *arg0, u8 *arg1) {
    f32 var_f0;
    u8 *temp_v0;

    temp_v0 = *(u8 **)(arg0 + 0x68);
    *(s32 *)(temp_v0 + 0x4) = 0;
    *(u8 *)(temp_v0 + 0x8) = 0;
    *(f32 *)(temp_v0 + 0x0) = 0.0f;
    *(u8 *)(temp_v0 + 0xA) = 0xFF;
    *(u8 *)(temp_v0 + 0xB) = 0;
    *(u8 *)(temp_v0 + 0x9) = *(u8 *)(arg1 + 0xE);
    *(u8 *)(temp_v0 + 0xC) = *(u8 *)(arg1 + 0xF);
    var_f0 = (f32) *(u8 *)(arg1 + 0xD);
    if (var_f0 < 10.0f) {
        var_f0 = 10.0f;
    }
    *(f32 *)(arg0 + 0x8) = *(f32 *)(*(u8 **)(arg0 + 0x40)) * (var_f0 / 64.0f);
    *(s16 *)(arg0 + 0x0) = (s16) (*(u8 *)(arg1 + 0xA) << 8);
    *(s16 *)(arg0 + 0x2) = (s16) (*(u8 *)(arg1 + 0xB) << 8);
    *(s16 *)(arg0 + 0x4) = (s16) (*(u8 *)(arg1 + 0xC) << 8);
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/doorSwitchInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fogInit(u8 *arg0, u8 *arg1) {
    f32 var_f0;
    u8 temp_t6;

    temp_t6 = *(u8 *)(arg1 + 0xA);
    var_f0 = (f32) temp_t6;
    var_f0 = var_f0 * 8.0f;
    *(f32 *)(arg0 + 0x88) = var_f0 * var_f0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/fogInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void skyInit(u8 *arg0, u8 *arg1) {
    *(s32 *)(arg0 + 0x88) = *(u8 *)(arg1 + 0xA);
    *(s32 *)(arg0 + 0x8C) = *(u8 *)(arg1 + 0xB);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/skyInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void audioPointInit(u8 *arg0, u8 *arg1) {
    u8 *temp_v1;
    u16 temp_t7;

    temp_v1 = *(u8 **)(arg0 + 0x68);
    temp_t7 = *(u16 *)(arg1 + 0xA);
    *(u16 *)(temp_v1 + 0x0) = temp_t7;
    *(u16 *)(temp_v1 + 0x2) = *(u16 *)(arg1 + 0xC);
    *(u8 *)(temp_v1 + 0xC) = *(u8 *)(arg1 + 0x11);
    *(u8 *)(temp_v1 + 0x6) = *(u8 *)(arg1 + 0x10);
    *(u8 *)(temp_v1 + 0x4) = *(u8 *)(arg1 + 0xE);
    *(u8 *)(temp_v1 + 0x5) = *(u8 *)(arg1 + 0xF);
    *(u8 *)(temp_v1 + 0x8) = 0;
    *(u8 *)(temp_v1 + 0xD) = *(u8 *)(arg1 + 0x12);
    if (amSoundIsLooped(temp_t7) != 0) {
        amCreateAudioPoint(temp_t7, (f32) *(s16 *)(arg1 + 0x4), (f32) *(s16 *)(arg1 + 0x6), (f32) *(s16 *)(arg1 + 0x8), 9,
                           *(u8 *)(temp_v1 + 0x5), *(u8 *)(temp_v1 + 0x4), *(u16 *)(temp_v1 + 0x2), *(u8 *)(temp_v1 + 0xC),
                           *(u8 *)(temp_v1 + 0x6), *(u8 *)(temp_v1 + 0xD), 0, temp_v1 + 8);
    } else {
        amCreateAudioPoint(temp_t7, (f32) *(s16 *)(arg1 + 0x4), (f32) *(s16 *)(arg1 + 0x6), (f32) *(s16 *)(arg1 + 0x8), 0xA,
                           *(u8 *)(temp_v1 + 0x5), *(u8 *)(temp_v1 + 0x4), *(u16 *)(temp_v1 + 0x2), *(u8 *)(temp_v1 + 0xC),
                           *(u8 *)(temp_v1 + 0x6), *(u8 *)(temp_v1 + 0xD), 0, temp_v1 + 8);
    }
    objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/audioPointInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void audioLineInit(u8 *arg0, u8 *arg1) {
    u8 temp_t7;
    u16 temp_t8;
    u8 *temp_v0;

    temp_v0 = *(u8 **)(arg0 + 0x68);
    temp_t7 = *(u8 *)(arg1 + 0xA);
    *(u8 *)(temp_v0 + 0x0) = temp_t7;
    temp_t8 = *(u16 *)(arg1 + 0xC);
    *(u16 *)(temp_v0 + 0x2) = temp_t8;
    *(u8 *)(temp_v0 + 0xC) = *(u8 *)(arg1 + 0xE);
    *(u8 *)(temp_v0 + 0xD) = *(u8 *)(arg1 + 0xF);
    *(s32 *)(temp_v0 + 0x8) = 0;
    *(u16 *)(temp_v0 + 0x4) = *(u16 *)(arg1 + 0x10);
    *(u8 *)(temp_v0 + 0x11) = *(u8 *)(arg1 + 0x14);
    *(u8 *)(temp_v0 + 0x10) = *(u8 *)(arg1 + 0x13);
    *(u8 *)(temp_v0 + 0xE) = *(u8 *)(arg1 + 0xB);
    *(u8 *)(temp_v0 + 0xF) = *(u8 *)(arg1 + 0x12);
    *(u8 *)(temp_v0 + 0x12) = *(u8 *)(arg1 + 0x15);
    amAudioLineAddVertex(temp_t7 & 0xFF, temp_t8 & 0xFFFF, (f32) *(s16 *)(arg1 + 0x4), (f32) *(s16 *)(arg1 + 0x6),
                         (f32) *(s16 *)(arg1 + 0x8), *(u8 *)(temp_v0 + 0xF), *(u8 *)(temp_v0 + 0xE), *(u8 *)(temp_v0 + 0x10),
                         *(u8 *)(temp_v0 + 0x12), *(u16 *)(temp_v0 + 0x4), *(u8 *)(temp_v0 + 0x11), *(u8 *)(temp_v0 + 0xC),
                         *(u8 *)(temp_v0 + 0xD));
    objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/audioLineInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void texscrollInit(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *temp_v0;
    u8 *temp_v1;

    temp_v1 = *(u8 **)(arg0 + 0x68);
    temp_v0 = trackGetTrack();
    *(s16 *)(temp_v1 + 0x0) = *(s16 *)(arg1 + 0xA);
    if (*(s16 *)(temp_v1 + 0x0) < 0) {
        *(s16 *)(temp_v1 + 0x0) = 0;
    }
    if (*(s16 *)(temp_v1 + 0x0) >= *(s16 *)(temp_v0 + 0x18)) {
        *(s16 *)(temp_v1 + 0x0) = (s16) (*(s16 *)(temp_v0 + 0x18) - 1);
    }
    *(s16 *)(temp_v1 + 0x4) = (s16) *(s8 *)(arg1 + 0xC);
    *(s16 *)(temp_v1 + 0x6) = (s16) *(s8 *)(arg1 + 0xD);
    if (arg2 == 0) {
        *(s16 *)(temp_v1 + 0x8) = 0;
        *(s16 *)(temp_v1 + 0xA) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/texscrollInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rgbalightInit(u8 *arg0, u8 *arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x68) = addRomdefLight();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/rgbalightInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lensflareInit(u8 *arg0, u8 *arg1) {
    u8 setup[0x20];

    setup[0x00] = 0x21;
    *(s16 *)(setup + 0x18) = -1;
    if (*(u8 *)(arg1 + 0xE) != 0) {
        setup[0x00] = 0x23;
    }
    if (*(u8 *)(arg1 + 0xF) != 0) {
        setup[0x00] |= 4;
    }
    if (*(u8 *)(arg1 + 0x10) != 0) {
        *(s16 *)(setup + 0x18) = 0x61;
    }
    setup[0x01] = 0x50;
    *(s16 *)(setup + 0x02) = *(s16 *)(arg1 + 0xC);
    *(s16 *)(setup + 0x06) = 0;
    *(f32 *)(setup + 0x08) = 0.0f;
    *(f32 *)(setup + 0x0C) = 0.0f;
    *(f32 *)(setup + 0x10) = 0.0f;
    *(s16 *)(setup + 0x04) = *(s16 *)(arg1 + 0xA);
    setup[0x14] = *(u8 *)(arg1 + 0x12);
    setup[0x15] = *(u8 *)(arg1 + 0x13);
    setup[0x16] = *(u8 *)(arg1 + 0x14);
    *(s16 *)(setup + 0x1A) = 0x64;
    *(s16 *)(setup + 0x1C) = 0x64;
    *(s8 *)(setup + 0x1E) = -1;
    *(s8 *)(setup + 0x1F) = 1;
    setup[0x17] = *(u8 *)(arg1 + 0x15);
    *(s32 *)(arg0 + 0x88) = camlightAdd(arg0, setup, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/lensflareInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flareswitchInit(u8 *arg0, u8 *arg1, s32 arg2) {
    *(f32 *)(arg0 + 0x8) = (f32) *(s16 *)(arg1 + 0xA);
    *(f32 *)(arg0 + 0x8) = *(f32 *)(arg0 + 0x8) / 40.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/flareswitchInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void waveswellInit(u8 *arg0, u8 *arg1, s32 arg2) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/waveswellInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splinecamnodeInit(u8 *arg0, u8 *arg1, s32 arg2) {
    f32 var_f6;
    f32 var_f8;
    f32 var_f16;
    f32 var_f18;
    u8 temp_t8;
    u8 *temp_v0;

    temp_v0 = *(u8 **)(arg0 + 0x68);
    *(u8 *)(temp_v0 + 0x0) = *(u8 *)(arg1 + 0xA);
    *(u8 *)(temp_v0 + 0x1) = *(u8 *)(arg1 + 0xB);
    temp_t8 = *(u8 *)(arg1 + 0x24);
    var_f6 = (f32) temp_t8;
    *(f32 *)(temp_v0 + 0x4) = var_f6;
    *(s16 *)(temp_v0 + 0x2) = (s16) (*(s16 *)(arg1 + 0xC) * 4);
    *(u8 *)(temp_v0 + 0x2C) = *(u8 *)(arg1 + 0xF);
    *(s8 *)(temp_v0 + 0x2D) = (s8) (*(u8 *)(arg1 + 0xD) & 1);
    *(s8 *)(temp_v0 + 0x2E) = (s8) (*(u8 *)(arg1 + 0xE) & 1);
    *(u8 *)(temp_v0 + 0x38) = *(u8 *)(arg1 + 0x12);
    *(s8 *)(temp_v0 + 0x39) = (s8) (*(u8 *)(arg1 + 0xD) & 2);
    *(s8 *)(temp_v0 + 0x3A) = (s8) (*(u8 *)(arg1 + 0xE) & 2);
    *(u8 *)(temp_v0 + 0x44) = *(u8 *)(arg1 + 0x15);
    *(s8 *)(temp_v0 + 0x45) = (s8) (*(u8 *)(arg1 + 0xD) & 4);
    *(s8 *)(temp_v0 + 0x46) = (s8) (*(u8 *)(arg1 + 0xE) & 4);
    *(f32 *)(temp_v0 + 0x8) = (f32) *(s16 *)(arg1 + 0x4);
    *(f32 *)(temp_v0 + 0xC) = (f32) *(s16 *)(arg1 + 0x6);
    *(f32 *)(temp_v0 + 0x10) = (f32) *(s16 *)(arg1 + 0x8);
    *(f32 *)(temp_v0 + 0x14) = (f32) *(s16 *)(arg1 + 0x18);
    *(f32 *)(temp_v0 + 0x18) = (f32) *(s16 *)(arg1 + 0x1A);
    *(f32 *)(temp_v0 + 0x1C) = (f32) *(s16 *)(arg1 + 0x1C);
    var_f16 = (f32) *(u16 *)(arg1 + 0x1E);
    *(f32 *)(temp_v0 + 0x20) = var_f16;
    var_f8 = (f32) *(u16 *)(arg1 + 0x20);
    *(f32 *)(temp_v0 + 0x24) = var_f8;
    var_f18 = (f32) *(u16 *)(arg1 + 0x22);
    *(f32 *)(temp_v0 + 0x28) = var_f18;
    splinecamMakeSpline(*(u8 *)(temp_v0 + 0x0));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/splinecamnodeInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *hitstaticInit(u8 *arg0, u8 *arg1) {
    u8 *shape;
    u8 *obj;
    f32 *scaleOut;
    f32 scale;
    f32 maxAbs;
    f32 a;
    s32 i;

    scale = (f32) RD_U8(arg1, 0xB);
    if (scale < 10.0f) {
        scale = 10.0f;
    }
    scale = scale * 0.015625f;
    shape = RD_PTR(arg0, 0x40);
    scaleOut = (f32 *) RD_PTR(arg0, 0x50);
    RD_F32(arg0, 0x8) = RD_F32(shape, 0x0) * scale;
    if (scaleOut != NULL) {
        *scaleOut = RD_F32(shape, 0x54) * scale;
    }
    RD_U8(arg0, 0x3A) = RD_U8(arg1, 0xA);
    RD_S16(arg0, 0x0) = (s16) (RD_U8(arg1, 0xC) << 8);
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
    if ((s8) RD_U8(arg0, 0x3A) >= RD_S8(RD_PTR(arg0, 0x40), 0x1F)) {
        RD_U8(arg0, 0x3A) = 0;
    }
    obj = *(u8 **) (RD_PTR(arg0, 0x6C) + ((s8) RD_U8(arg0, 0x3A) * 4));
    /* asm: max absolute value of six s16 fields at obj+0x8C..0x96 */
    maxAbs = 0.0f;
    for (i = 0; i < 6; i++) {
        a = (f32) RD_S16(obj, 0x8C + (i * 2));
        if (a < 0.0f) {
            a = -a;
        }
        if (a > maxAbs) {
            maxAbs = a;
        }
    }
    RD_F32(arg0, 0x34) = RD_F32(arg0, 0x8) * maxAbs;
    return obj + 0x96;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/hitstaticInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void overrideCInit(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *temp_v0;

    temp_v0 = RD_PTR(arg0, 0x68);
    RD_F32(temp_v0, 0x0) = (f32) RD_U16(arg1, 0xA);
    RD_F32(temp_v0, 0x4) = (f32) (RD_S16(arg1, 0x6) + RD_S16(arg1, 0x1A));
    RD_F32(temp_v0, 0x8) = (f32) (RD_S16(arg1, 0x6) - RD_S16(arg1, 0x1A));
    RD_F32(temp_v0, 0xC) = (f32) RD_U16(arg1, 0xC);
    RD_F32(temp_v0, 0x10) = (f32) (RD_S16(arg1, 0x6) + RD_S16(arg1, 0x1C));
    RD_F32(temp_v0, 0x14) = (f32) (RD_S16(arg1, 0x6) - RD_S16(arg1, 0x1C));
    RD_S32(temp_v0, 0x18) = (s32) (f32) RD_U16(arg1, 0xE);
    RD_F32(temp_v0, 0x1C) = (f32) RD_S16(arg1, 0x10);
    RD_F32(temp_v0, 0x20) = (f32) RD_S16(arg1, 0x12);
    RD_F32(temp_v0, 0x24) = RD_F32(arg0, 0xC) + (f32) RD_S16(arg1, 0x14);
    RD_F32(temp_v0, 0x28) = RD_F32(arg0, 0x10) + (f32) RD_S16(arg1, 0x16);
    RD_F32(temp_v0, 0x2C) = RD_F32(arg0, 0x14) + (f32) RD_S16(arg1, 0x18);
    if (arg2 == 0) {
        cameraAddOverrideObject(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/overrideCInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void AIPointInit(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;
    u8 temp_t1;

    temp_v0 = RD_PTR(arg0, 0x68);
    RD_U8(temp_v0, 0x0) = RD_U8(arg1, 0xA);
    RD_U8(temp_v0, 0x1) = RD_U8(arg1, 0xB);
    RD_U8(temp_v0, 0x2) = RD_U8(arg1, 0xC);
    RD_U8(temp_v0, 0x3) = RD_U8(arg1, 0xD);
    RD_U8(temp_v0, 0x4) = RD_U8(arg1, 0xE);
    temp_t1 = RD_U8(arg1, 0xF);
    RD_U8(temp_v0, 0x5) = 0;
    RD_U8(temp_v0, 0x6) = temp_t1;
    RD_U8(temp_v0, 0x8) = RD_U8(arg1, 0x10);
    RD_U8(temp_v0, 0x9) = RD_U8(arg1, 0x11);
    RD_U8(temp_v0, 0xA) = RD_U8(arg1, 0x12);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/AIPointInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_136_08801740_1FD4A40(void *arg0) {
    s32 count;
    void **list;
    u8 *best;
    u8 *cand;
    f32 bestDist;
    f32 dist;

    list = squadsGetSquadronList(&count);
    bestDist = D_overlay_136_08801E9C;
    best = NULL;
    if (count != 0) {
        count = count - 1;
        do {
            cand = list[count];
            if (arg0 != cand && (((u32) RD_U16(RD_PTR(cand, 0x68), 0x1A)) >> 0xC) != 4) {
                dist = GetRangeSquared(RD_F32(cand, 0xC), RD_F32(cand, 0x10), RD_F32(cand, 0x14),
                                       RD_F32(arg0, 0xC), RD_F32(arg0, 0x10), RD_F32(arg0, 0x14));
                if (dist < bestDist) {
                    bestDist = dist;
                    best = cand;
                }
            }
        } while (count-- != 0);
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/func_overlay_136_08801740_1FD4A40.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SquadronInit(u8 *arg0, u8 *arg1) {
    u8 *v;
    u8 *patrol;
    u8 t6;
    u8 t6b;

    v = RD_PTR(arg0, 0x68);
    RD_U8(v, 0x64) = RD_U8(arg1, 0x2D);
    if ((RD_U16(v, 0x1A) >> 0xC) == 4) {
        if (RD_PTR(v, 0x5C) == NULL) {
            *(u8 **) (v + 0x5C) = func_overlay_136_08801740_1FD4A40(arg0);
        }
        RD_U8(arg1, 0xB) = 0;
    }
    RD_U16(v, 0x2C) = RD_U16(arg1, 0x36);
    RD_U8(v, 0x1) = RD_U8(arg1, 0xB);
    RD_U8(v, 0x3) = RD_U8(arg1, 0xC);
    RD_U8(v, 0x4) = RD_U8(arg1, 0xD);
    RD_U8(v, 0x5) = RD_U8(arg1, 0xE);
    RD_U8(v, 0x6) = RD_U8(arg1, 0xF);
    RD_U8(v, 0x7) = RD_U8(arg1, 0x10);
    RD_U8(v, 0x8) = RD_U8(arg1, 0x11);
    RD_U8(v, 0x9) = RD_U8(arg1, 0x12);
    RD_U8(v, 0xA) = RD_U8(arg1, 0x13);
    RD_U8(v, 0xB) = RD_U8(arg1, 0x14);
    RD_U8(v, 0x2) = RD_U8(arg1, 0x15);
    RD_U8(v, 0xC) = RD_U8(arg1, 0x16);
    RD_U8(v, 0xD) = RD_U8(arg1, 0x17);
    RD_U8(v, 0xE) = RD_U8(arg1, 0x18);
    RD_U8(v, 0xF) = RD_U8(arg1, 0x19);
    RD_S8(v, 0x10) = RD_S8(arg1, 0x1A);
    RD_S8(v, 0x11) = RD_S8(arg1, 0x1B);
    RD_S8(v, 0x12) = RD_S8(arg1, 0x1C);
    RD_U8(v, 0x13) = RD_U8(arg1, 0x1D);
    RD_U8(v, 0x14) = RD_U8(arg1, 0x1E);
    RD_S8(v, 0x15) = RD_S8(arg1, 0x1F);
    RD_S8(v, 0x16) = RD_S8(arg1, 0x20);
    RD_S8(v, 0x17) = RD_S8(arg1, 0x21);
    RD_U8(v, 0x18) = RD_U8(arg1, 0x22);
    RD_U8(v, 0x19) = RD_U8(arg1, 0x23);
    t6 = (u8) ((RD_U8(arg1, 0x29) * 0x10) | (RD_U8(v, 0x1A) & 0xFF0F));
    RD_U8(v, 0x1A) = t6;
    RD_U8(v, 0x1A) = (u8) ((RD_U8(arg1, 0x24) & 0xF) | (t6 & 0xF0));
    RD_S8(v, 0x1B) = RD_S8(arg1, 0x25);
    RD_S8(v, 0x1C) = RD_S8(arg1, 0x26);
    RD_S8(v, 0x1D) = RD_S8(arg1, 0x27);
    RD_U8(v, 0x1E) = RD_U8(arg1, 0x28);
    RD_U8(v, 0x76) = RD_U8(arg1, 0x35);
    RD_U8(v, 0x1F) = RD_U8(arg1, 0x2E);
    RD_U8(v, 0x20) = RD_U8(arg1, 0x2F);
    RD_U8(v, 0x21) = RD_U8(arg1, 0x30);
    RD_U8(v, 0x22) = RD_U8(arg1, 0x32);
    RD_U8(v, 0x23) = RD_U8(arg1, 0x33);
    RD_S16(v, 0x2A) = (s16) (RD_U8(arg1, 0x34) << 8);
    RD_S8(v, 0x24) = RD_S8(arg1, 0x38);
    RD_S8(v, 0x25) = RD_S8(arg1, 0x39);
    RD_S16(v, 0x28) = (s16) (RD_U16(arg1, 0x3A) & 0xFFF7);
    RD_U8(v, 0x26) = RD_U8(arg1, 0x3C);
    RD_U8(v, 0x27) = RD_U8(arg1, 0x3D);
    t6b = (u8) ((RD_U8(arg1, 0xA) & 3) | (RD_U8(v, 0x34) & 0xFFFC));
    RD_U8(v, 0x34) = t6b;
    RD_U8(v, 0x60) = RD_U8(arg1, 0x2A);
    RD_U8(v, 0x33) = 0;
    RD_U8(v, 0x34) = (u8) (t6b & 3);
    RD_U8(v, 0x35) = 0;
    RD_U8(v, 0x2E) = 1;
    RD_U8(v, 0x37) = 0;
    RD_U8(v, 0x38) = 1;
    RD_U8(v, 0x39) = 1;
    RD_U8(v, 0x3A) = 0;
    RD_U8(v, 0x3C) = 0;
    RD_U8(v, 0x54) = 0;
    RD_U8(v, 0x61) = RD_U8(arg1, 0x2B);
    RD_F32(v, 0x48) = RD_F32(arg0, 0xC);
    RD_F32(v, 0x4C) = RD_F32(arg0, 0x10);
    RD_F32(v, 0x50) = RD_F32(arg0, 0x14);
    RD_U8(v, 0x66) = 0;
    RD_U8(v, 0x68) = 0;
    RD_U8(v, 0x6A) = 0;
    RD_F32(v, 0x6C) = 1.0f;
    RD_F32(v, 0x70) = 0.0f;
    RD_U8(v, 0x7B) = RD_U8(arg1, 0x3E);
    RD_U8(v, 0x74) = 0;
    RD_U8(v, 0x62) = RD_U8(arg1, 0x2C);
    RD_U8(v, 0x77) = 0xFF;
    RD_U8(v, 0x36) = 0;
    RD_S8(v, 0x78) = -1;
    RD_U8(v, 0x75) = RD_U8(arg1, 0x31);
    RD_S8(v, 0x7A) = RD_S8(arg1, 0x3F);
    RD_S16(v, 0x40) = (s16) RD_F32(arg0, 0xC);
    RD_S16(v, 0x42) = (s16) RD_F32(arg0, 0x10);
    RD_U8(v, 0x65) = 0;
    RD_S16(v, 0x44) = (s16) RD_F32(arg0, 0x14);
    RD_U16(v, 0x92) = RD_U16(arg1, 0x40);
    if (RD_U8(v, 0x58) == 0) {
        RD_U8(v, 0x63) = 0;
        RD_S16(v, 0x0) = 0;
    }
    RD_S16(arg0, 0x0) = (s16) (0xC000 - (RD_S8(v, 0x1B) << 8));
    if ((RD_U8(v, 0x1A) & 0xF) == 6) {
        patrol = PatrolNodes + (GetClosestPatrolNode(RD_F32(arg0, 0xC), RD_F32(arg0, 0x10), arg0, arg1,
                                                     RD_F32(arg0, 0x14), 0) * 0x34);
        if (patrol != NULL && (RD_U8(patrol, 0x17) >> 6) != 0) {
            RD_U8(v, 0x33) = 0x1F;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/SquadronInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void AIJunctionInit(u8 *arg0, u8 *arg1) {
    u8 *var_a2;
    void **list;
    u8 *obj;
    s32 start;
    s32 total;
    s32 i;
    s32 found;
    u8 cur;
    u8 newIdx;

    var_a2 = RD_PTR(arg0, 0x68);
    cur = 0;
    list = objGetObjList(&start, &total);
    if (var_a2 != NULL && arg1 != NULL) {
        RD_U8(var_a2, 0x10) = (u8) (RD_U8(var_a2, 0x10) & 0xFE);
        newIdx = RD_U8(arg1, 0xA);
        if (newIdx != 0) {
            RD_U8(var_a2, 0x11) = newIdx;
        } else {
            do {
                cur = (u8) (cur + 1);
                found = 0;
                for (i = start; i < total; i++) {
                    obj = list[i];
                    if (RD_S16(obj, 0x48) == 0x1B) {
                        var_a2 = RD_PTR(obj, 0x68);
                        if (obj != arg0 && cur == RD_U8(var_a2, 0x11)) {
                            found = 1;
                            break;
                        }
                    }
                }
            } while (found != 0);
            RD_U8(arg1, 0xA) = cur;
            RD_U8(var_a2, 0x11) = cur;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o136/overlay_136/AIJunctionInit.s")
#endif
