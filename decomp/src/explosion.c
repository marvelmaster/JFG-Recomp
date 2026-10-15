#include "common.h"

/* decomp: externs */
extern s32 explosionNoTypes;
extern void *explosionTypes[];
extern u8 D_800A11B0_A1DB0;
extern f32 D_800F6B10_B1760[];
extern s32 D_800A11B4_A1DB4;
extern u8 D_800F6B60_B17B0[];
void *objSetupObject(void *params, s32 arg1);
void objFreeObject(void *obj);
void partInitTrigger(void *arg0, s32 arg1, s16 arg2);
s32 camlightAdd(void *arg0, void *arg1);
void explosionAddBlast(f32 x, f32 y, f32 a, f32 z, f32 b, f32 c, f32 d, s32 e, s32 f);
void updateColourCycle(unkResetColourCycle *arg0, s32 arg1);
f32 Sinf(s16 angle);
void texFreeSprite(s32 handle, void *owner);
s32 texLoadSprite(s32 spriteId, s32 arg1, void *owner);
s32 texAnimateSprite(s32 handle, s32 *state, s32 frames, void *data, s32 dt);
void *camGetPtr(void);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
extern u8 D_F2D58[];
extern u8 D_F2E58[];
void partUpdateTriggers(void *obj, s32 arg1, u8 count);
void killLight(void *arg0);
void camlightDelete(void *arg0);
void camIgnoreShake(void);
void camUseShake(void);
void camScreenShake(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern s16 D_800F2D60_B1850;
extern s16 D_800F2D64_B1854;
extern u8 D_800F2D68_B1858[];
extern s32 D_800A333C_A3F3C;
extern void *D_800A3340_A3F40;
extern s32 D_800A3344_A3F44;
extern s32 D_800A3348_A3F48;
Object **objGetObjList(s32 *arg0, s32 *arg1);
s32 hitPlayerKilledPlayer(void *arg0, void *arg1);
void mainIncreaseWeaponKills(s32 arg0);
s16 mathDiffAngle(s16 arg0, s16 arg1);
void cutcameraUpdate(void *arg0, void *arg1, f32 arg2);
void func_8002A7DC(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5, f32 *arg6, f32 *arg7);
f32 func_8002A958(void *arg0, void *arg1, f32 arg2);
s32 func_8002AA30(void *arg0, s32 arg1);
s32 func_8002ABA4(void *arg0, void *arg1, f32 *arg2);

const char D_800AC3F0[] = "explosion %d out of range\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void explosionStart(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
    u8 *def;

    if (arg0 < explosionNoTypes) {
        def = (u8 *)explosionTypes[arg0];
        *(s16 *)(def + 0x6) = arg2;
        *(s16 *)(def + 0x8) = arg3;
        *(s16 *)(def + 0x4) = arg1;
        *(s8 *)(def + 0x50) = (s8) arg4;
        *(s32 *)(def + 0x54) = arg5;
        objSetupObject(def, 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/explosionStart.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objExplosionSetupTriggers(void *arg0, s32 arg1, void *arg2) {
    u8 *def = (u8 *)arg2;
    u8 count;
    s32 i;
    s32 s1;
    s32 s2;
    s16 entry;

    *(s32 *)((u8 *)arg0 + 0x70) = arg1;
    count = def[0x30];
    i = 0;
    s1 = 0;
    s2 = 0;
    if ((s32) count > 0) {
        do {
            entry = *(s16 *)(*(u8 **)(def + 0xC) + s2);
            partInitTrigger((void *) (arg1 + s1), (entry >> 8) & 0xFF, entry & 0xFF);
            count = def[0x30];
            i += 1;
            s1 += 0x24;
            s2 += 2;
        } while (i < (s32) count);
    }
    return ((count * 0x24) + 3) & ~3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/objExplosionSetupTriggers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void explosionInit(Object *arg0, void *arg1) {
    u8 *def = (u8 *)arg1;
    u8 *racer;
    u8 light[0x18];
    u8 cam[0x20];
    s16 t2;
    s16 t3;
    u8 a;
    s32 i;

    racer = (u8 *) arg0->racer;
    *(s32 *)(racer + 0xC) = 0;
    *(s32 *)(racer + 0x8) = 0;
    *(void **)(racer + 0x24) = racer + 0x30;
    *(s16 *)(racer + 0x0) = 0;
    *(void **)(racer + 0x20) = arg1;
    *(f32 *)(racer + 0x4) = 0.0f;
    *(s32 *)((u8 *)arg0 + 0x3C) = 0;
    arg0->segment.trans.unk6 |= 0x400;
    if (*(s16 *)(def + 0x3E) == 0) {
        *(f32 *)(racer + 0x4) = (f32) (*(s16 *)(def + 0x3E)) * 0.003051851f;
    }
    for (i = 0; i < (s32) def[0x31]; i++) {
        (*(u8 **)(racer + 0x24))[i] = 0;
    }
    if (*(s16 *)(def + 0x36) != 0) {
        light[0] = 1;
        light[1] = 3;
        light[2] = 0x21;
        light[3] = 0xFF;
        *(s16 *)(light + 0x4) = 0;
        *(s16 *)(light + 0x6) = 0;
        *(s16 *)(light + 0x8) = 0;
        *(s16 *)(light + 0xA) = 0;
        *(s16 *)(light + 0xC) = *(s16 *)(def + 0x36);
        *(s16 *)(light + 0xE) = *(s16 *)(def + 0x36);
        light[0x13] = 0xFF;
        *(s16 *)(light + 0x14) = *(s16 *)(def + 0x38);
        light[0x16] = 0;
        light[0x17] = 0;
        *(s32 *)(racer + 0x8) = addObjectLight((Object *) arg0, (ObjectHeader48 *) light);
    }
    if (*(s16 *)(def + 0x3A) != 0) {
        initColourCycle((unkResetColourCycle *) (racer + 0x10), *(s16 *)(def + 0x3C));
        cam[0] = 1;
        cam[1] = 0;
        *(s16 *)(cam + 0x2) = 0;
        *(s16 *)(cam + 0x4) = 0;
        *(s16 *)(cam + 0x6) = 0;
        *(f32 *)(cam + 0x8) = 0.0f;
        *(f32 *)(cam + 0xC) = 0.0f;
        *(f32 *)(cam + 0x10) = 0.0f;
        cam[0x14] = racer[0x18];
        cam[0x15] = racer[0x19];
        cam[0x16] = racer[0x1A];
        cam[0x17] = racer[0x1B];
        *(s16 *)(cam + 0x18) = -1;
        *(s16 *)(cam + 0x1A) = *(s16 *)(def + 0x3A);
        *(s16 *)(cam + 0x1C) = *(s16 *)(def + 0x3A);
        cam[0x1E] = 0xFF;
        *(s32 *)(racer + 0xC) = camlightAdd(arg0, cam);
    }
    t2 = *(s16 *)(def + 0x4A);
    if (t2 != 0) {
        t3 = *(s16 *)(def + 0x4E);
        if (t3 != 0) {
            a = def[0x4C];
            if (a != 0) {
                explosionAddBlast(arg0->segment.trans.x_position, arg0->segment.trans.y_position, (f32) a,
                                  arg0->segment.trans.z_position, (f32) t2, (f32) a,
                                  (f32) t3 / 60.0f, (s32) *(s8 *)(def + 0x50), *(s32 *)(def + 0x54));
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/explosionInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Racer (obj+0x68): +0x0 s16 timer, +0x4 f32 shake level, +0x8 light ptr, +0xC camlight ptr,
// +0x10 unkResetColourCycle (+0x18..0x1B colour bytes, +0x1C ptr to limit word), +0x24 u8* trigger state.
// Def (racer+0x20): +0x10/+0x14 s16* trigger lo/hi (count +0x30); +0x18 setup-record base (stride 0x22),
// +0x1C s16* hi, +0x20 u8* lo, +0x24 u8* increment (count +0x31); +0x28 record base (stride 0x1C,
// count +0x32, start time s16 @+0xA); +0x34 s16 end time; +0x3E/+0x40/+0x44 s16 threshold lists.
// Field names are not in jfg-re; raw offsets kept.
void explosionControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *racer = *(u8 **)(obj + 0x68);
    u8 *def = *(u8 **)(racer + 0x20);
    s16 *lo16;
    s16 *hi16;
    u8 *lo8;
    s16 *hi1C;
    s16 oldTimer;
    s16 timer;
    s32 i;
    s32 v;
    u8 *st;
    u8 *rec;
    u8 *cl;
    u8 *light;
    s16 mult;
    f32 fa;

    oldTimer = *(s16 *)racer;
    timer = (s16) (oldTimer + arg1);
    *(s16 *)racer = timer;
    *(s32 *)(obj + 0x84) = 0;

    /* trigger bitmask: bit i set while lo <= timer < hi */
    lo16 = *(s16 **)(def + 0x10);
    hi16 = *(s16 **)(def + 0x14);
    for (i = 0; i < (s32) def[0x30]; i++) {
        if (timer >= lo16[i] && timer < hi16[i]) {
            *(s32 *)(obj + 0x84) |= (1 << i);
        }
    }
    partUpdateTriggers(arg0, arg1, def[0x30]);

    /* per-trigger accumulators: fire setup records when the byte drains below arg1 */
    lo8 = *(u8 **)(def + 0x20);
    hi1C = *(s16 **)(def + 0x1C);
    for (i = 0; i < (s32) def[0x31]; i++) {
        timer = *(s16 *)racer;
        if (timer >= lo8[i] && timer < hi1C[i]) {
            st = *(u8 **)(racer + 0x24) + i;
            v = *st;
            if (v < arg1) {
                rec = *(u8 **)(def + 0x18) + i * 0x22;
                *(s16 *)(rec + 0x4) = (s16) (s32) *(f32 *)(obj + 0xC);
                *(s16 *)(rec + 0x6) = (s16) (s32) *(f32 *)(obj + 0x10);
                *(s16 *)(rec + 0x8) = (s16) (s32) *(f32 *)(obj + 0x14);
                *st = (u8) (v + (*(u8 **)(def + 0x24))[i] - arg1);
                objSetupObject(rec, 1);
            } else {
                *st = (u8) (v - arg1);
            }
        }
    }

    /* timed records (start time at +0xA): fire when start time was crossed this tick */
    rec = *(u8 **)(def + 0x28);
    for (i = 0; i < (s32) def[0x32]; i++, rec += 0x1C) {
        timer = *(s16 *)racer;
        if (!(timer < *(s16 *)(rec + 0xA)) && *(s16 *)(rec + 0xA) >= oldTimer) {
            *(s16 *)(rec + 0x4) = (s16) (s32) *(f32 *)(obj + 0xC);
            *(s16 *)(rec + 0x6) = (s16) (s32) *(f32 *)(obj + 0x10);
            *(s16 *)(rec + 0x8) = (s16) (s32) *(f32 *)(obj + 0x14);
            objSetupObject(rec, 1);
        }
    }

    /* threshold list: index i ends at 0, 1 or 2 depending on the lists at +0x40 */
    i = 0;
    timer = *(s16 *)racer;
    if (*(s16 *)(def + 0x3E) < timer) {
        do {
            v = *(s16 *)(def + 0x40 + i * 2);
            i++;
            if (!(v < timer)) {
                break;
            }
        } while (i != 2);
    }

    /* scale accumulator at racer+0x4 and colour/camlight update */
    mult = *(s16 *)(def + 0x44 + i * 2);
    fa = (f32) arg1;
    *(f32 *)(racer + 0x4) = *(f32 *)(racer + 0x4) + (fa * (f32) mult) * 0.003051851f;
    cl = *(u8 **)(racer + 0xC);
    if (cl != NULL) {
        updateColourCycle((unkResetColourCycle *) (racer + 0x10), arg1);
        if (*(s32 *)(racer + 0x10) < *(s32 *) (*(u8 **)(racer + 0x1C)) - 1) {
            cl[0x38] = racer[0x18];
            cl[0x39] = racer[0x19];
            cl[0x3A] = racer[0x1A];
            cl[0x3B] = racer[0x1B];
        } else {
            camlightDelete(*(void **)(racer + 0xC));
            *(void **)(racer + 0xC) = NULL;
        }
    }
    if (*(u8 **)(racer + 0x8) != NULL) {
        updateColourCycle((unkResetColourCycle *) (racer + 0x10), arg1);
        light = *(u8 **)(racer + 0x8);
        if (*(s32 *) (*(u8 **)(light + 0x54)) == *(s32 *)(light + 0x48) + 1) {
            killLight(light);
            *(void **)(racer + 0x8) = NULL;
        }
    }

    /* end of life vs. shake */
    timer = *(s16 *)racer;
    if (timer >= *(s16 *)(def + 0x34)) {
        camIgnoreShake();
        if (*(void **)(racer + 0x8) != NULL) {
            killLight(*(void **)(racer + 0x8));
        }
        if (*(void **)(racer + 0xC) != NULL) {
            camlightDelete(*(void **)(racer + 0xC));
        }
        objFreeObject(arg0);
    } else if (*(f32 *)(racer + 0x4) > 2.0f) {
        camUseShake();
        /* asm passes obj+0x14 raw in $a2 (integer register), hence the cast */
        ((void (*)(f32, f32, s32, f32, f32)) camScreenShake)(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10),
            *(s32 *)(obj + 0x14), 1000.0f, (f32) mathRnd(0, (s32) *(f32 *)(racer + 0x4)));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/explosionControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shockwaveStart(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7, u8 arg8) {
    u8 setup[0x20];

    *(s16 *)(setup + 0x00) = 0x73;
    *(s8 *)(setup + 0x02) = 0x22;
    *(s16 *)(setup + 0x04) = arg0;
    *(s16 *)(setup + 0x06) = arg1;
    *(s16 *)(setup + 0x08) = arg2;
    *(s16 *)(setup + 0x0C) = (s16) (s32) (arg3 * 327.67f);
    *(s16 *)(setup + 0x0E) = (s16) (s32) (arg4 * 327.67f);
    *(s16 *)(setup + 0x10) = (s16) (s32) (arg5 * 327.67f);
    *(s16 *)(setup + 0x12) = (s16) (s32) (arg6 * 327.67f);
    *(s16 *)(setup + 0x18) = arg7;
    *(s16 *)(setup + 0x1C) = (s16) arg8;
    objSetupObject(setup, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/shockwaveStart.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shockwaveInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *def = (u8 *)arg1;
    u8 *racer = *(u8 **)(obj + 0x68);
    u8 *v;
    s32 n;
    s32 angle;
    s32 k;

    if (D_800A11B0_A1DB0 != 0) {
        angle = 0;
        for (k = 0; k < 10; k++) {
            D_800F6B10_B1760[k * 2] = Sinf((s16) angle);
            D_800F6B10_B1760[k * 2 + 1] = Cosf(angle);
            angle += 0x1999;
        }
        D_800A11B0_A1DB0 = 0;
    }
    n = 0;
    v = racer;
    do {
        n += 4;
        *(s16 *)(v + 0xC) = 0;
        v[0x10] = 0xFF;
        v[0x11] = 0xFF;
        v[0x12] = 0xFF;
        v[0x13] = 0xFF;
        *(s16 *)(v + 0x16) = 0;
        v[0x1A] = 0xFF;
        v[0x1B] = 0xFF;
        v[0x1C] = 0xFF;
        v[0x1D] = 0xFF;
        *(s16 *)(v + 0x20) = 0;
        v[0x24] = 0xFF;
        v[0x25] = 0xFF;
        v[0x26] = 0xFF;
        v[0x27] = 0xFF;
        v += 0x28;
        *(s16 *)(v - 0x26) = 0;
        v[-0x22] = 0xFF;
        v[-0x21] = 0xFF;
        v[-0x20] = 0xFF;
        v[-0x1F] = 0xFF;
    } while (n != 0x28);
    *(s16 *)(obj + 0x2) = *(s16 *)(def + 0xA);
    *(f32 *)(racer + 0x198) = (f32) (*(s16 *)(def + 0xE)) * 0.003051851f;
    *(f32 *)(racer + 0x194) = (f32) (*(s16 *)(def + 0xC)) * 0.003051851f;
    *(f32 *)(racer + 0x19C) = (f32) (*(s16 *)(def + 0x10)) * 0.003051851f;
    *(f32 *)(racer + 0x1A0) = (f32) (*(s16 *)(def + 0x12)) * 0.003051851f;
    *(f32 *)(racer + 0x1A4) = (f32) (*(s16 *)(def + 0x14)) * 0.003051851f;
    *(f32 *)(racer + 0x1A8) = (f32) (*(s16 *)(def + 0x16)) * 0.003051851f;
    *(s16 *)(racer + 0x1D8) = *(s16 *)(def + 0x18);
    *(u16 *)(racer + 0x1D6) = *(u16 *)(def + 0x1C);
    *(void **)(racer + 0x190) = texLoadTexture((s32) *(s16 *)(def + 0x1A));
    racer[0x1DA] = 0;
    *(u32 *)(racer + 0x1CC) = 0;
    *(s16 *)(racer + 0x1D4) = (s16) (def[0x20] << 8);
    *(s32 *)(racer + 0x1D0) = 0;
    initColourCycle((unkResetColourCycle *) (racer + 0x1AC), (s32) def[0x1E]);
    initColourCycle((unkResetColourCycle *) (racer + 0x1BC), (s32) def[0x1F]);
    *(s32 *)(obj + 0x3C) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/shockwaveInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Racer = obj+0x68 (same as objDrawShockWave). f32 scroll/scale fields 0x194..0x1A8, two ring
// buffers of 10 records (stride 0x14, base racer + index*0xC8, index toggled at +0x1DA), timers 0x1D4..0x1D8.
// The asm multiplies 0x19C/0x1A0 by 0x1A4/0x1A8 once per arg1 tick (unrolled by IDO); written as a loop.
// cf. objDrawShockWave for the same racer layout. Racer fields are not named in jfg-re.
void shockwaveControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *racer = *(u8 **)(obj + 0x68);
    TextureHeader *model;
    f32 f0;
    f32 f2;
    f32 scale;
    f32 ratio;
    f32 span;
    f32 sn;
    f32 cs;
    s32 i;
    s32 idx;
    s32 w;
    s32 prod;
    s16 plus;
    s16 minus;
    s16 cur;
    u16 v;
    u8 *rec;
    u8 *tbl;

    *(f32 *)(racer + 0x194) = *(f32 *)(racer + 0x194) + *(f32 *)(racer + 0x19C) * (f32) arg1;
    *(f32 *)(racer + 0x198) = *(f32 *)(racer + 0x198) + *(f32 *)(racer + 0x1A0) * (f32) arg1;
    if (arg1 > 0) {
        f0 = *(f32 *)(racer + 0x1A4);
        f2 = *(f32 *)(racer + 0x1A8);
        for (i = 0; i < arg1; i++) {
            *(f32 *)(racer + 0x19C) = *(f32 *)(racer + 0x19C) * f0;
            *(f32 *)(racer + 0x1A0) = *(f32 *)(racer + 0x1A0) * f2;
        }
    }

    /* life timers: 0x1D8 counts down by ticks; otherwise 0x1D4 drains by 0x1D6 per tick */
    cur = *(s16 *)(racer + 0x1D8);
    if (cur > 0) {
        *(s16 *)(racer + 0x1D8) = (s16) (cur - arg1);
    } else {
        prod = (s32) *(u16 *)(racer + 0x1D6) * arg1;
        v = *(u16 *)(racer + 0x1D4);
        if (prod < (s32) v) {
            *(u16 *)(racer + 0x1D4) = (u16) (v - prod);
        } else {
            objFreeObject(arg0);
            return;
        }
    }

    updateColourCycle((unkResetColourCycle *) (racer + 0x1AC), arg1);
    updateColourCycle((unkResetColourCycle *) (racer + 0x1BC), arg1);

    /* rebuild the active ring buffer: 10 sin/cos points, scaled by radius (f194) and f198 */
    idx = racer[0x1DA];
    scale = *(f32 *)(racer + 0x194);
    if (scale < 0.0f) {
        scale = 0.0f;
    }
    rec = racer + idx * 0xC8;
    for (i = 0; i < 10; i++) {
        sn = D_800F6B10_B1760[i * 2];
        cs = D_800F6B10_B1760[i * 2 + 1];
        *(s16 *)(rec + 0xA) = (s16) (s32) (sn * scale);
        *(s16 *)(rec + 0x0) = (s16) (s32) (sn * *(f32 *)(racer + 0x198));
        *(s16 *)(rec + 0xE) = (s16) (s32) (cs * scale);
        *(s16 *)(rec + 0x4) = (s16) (s32) (cs * *(f32 *)(racer + 0x198));
        rec += 0x14;
    }

    /* texture-dependent span values, stored to the globals and to the 0x80-stride table */
    model = *(TextureHeader **)(racer + 0x190);
    w = (s32) model->width - 1;
    ratio = *(f32 *)(racer + 0x194) / *(f32 *)(racer + 0x198);
    span = ratio * (f32) (w * 8);
    plus = (s16) (s32) ((f32) (w * 16) + span);
    minus = (s16) (s32) ((f32) (w * 16) - span);
    D_800F2D60_B1850 = plus;
    D_800F2D64_B1854 = minus;
    tbl = (u8 *) D_800F2D68_B1858 + 0x30;
    *(s16 *)(tbl - 0x14) = plus;
    *(s16 *)(tbl - 0x24) = plus;
    *(s16 *)(tbl - 0x04) = minus;
    *(s16 *)(tbl - 0x18) = minus;
    for (i = 0; i < 2; i++, tbl += 0x80) {
        *(s16 *)(tbl + 0x08) = plus;
        *(s16 *)(tbl + 0x0C) = minus;
        *(s16 *)(tbl + 0x1C) = plus;
        *(s16 *)(tbl + 0x2C) = plus;
        *(s16 *)(tbl + 0x48) = plus;
        *(s16 *)(tbl + 0x5C) = plus;
        *(s16 *)(tbl + 0x6C) = plus;
        *(s16 *)(tbl + 0x28) = minus;
        *(s16 *)(tbl + 0x3C) = minus;
        *(s16 *)(tbl + 0x4C) = minus;
        *(s16 *)(tbl + 0x68) = minus;
        *(s16 *)(tbl + 0x7C) = minus;
    }

    texAnimateTexture(model, (u32 *) (racer + 0x1CC), (s32 *) (racer + 0x1D0), arg1);
    racer[0x1DA] = racer[0x1DA] ^ 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/shockwaveControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// arg2 is the object (ObjectTransform header at +0x00..+0x17); racer = obj+0x68.
// Racer fields at 0x1B4..0x1DA are not named in jfg-re; raw offsets kept.
void objDrawShockWave(Gfx **arg0, s32 (**arg1)[4][4], ObjectTransform *arg2) {
    u8 *obj = (u8 *)arg2;
    Gfx *dl;
    s32 (*mtx)[4][4];
    u8 *racer;
    u8 *model;
    u32 colour;
    u32 addr;

    dl = *arg0;
    mtx = *arg1;

    dl->words.w1 = 0;
    dl->words.w0 = 0xE7000000;
    dl++;

    if (arg2->x_rotation != 0) {
        arg2->y_rotation = -*(s16 *)camGetPtr();
    }

    racer = *(u8 **)(obj + 0x68);
    model = *(u8 **)(racer + 0x190);

    if (*(s16 *)(model + 0x6) & 0x40) {
        colour = (*(u8 *)(racer + 0x1B4) << 24) | (*(u8 *)(racer + 0x1B5) << 16) |
                 (*(u8 *)(racer + 0x1B6) << 8) | (*(s32 *)(racer + 0x1D0) & 0xFF);
    } else {
        colour = (*(u8 *)(racer + 0x1B4) << 24) | (*(u8 *)(racer + 0x1B5) << 16) |
                 (*(u8 *)(racer + 0x1B6) << 8) | 0xFF;
    }
    dl->words.w0 = 0xFB000000;
    dl->words.w1 = colour;
    dl++;

    dl->words.w0 = 0xFA000000;
    dl->words.w1 = (*(u8 *)(racer + 0x1C4) << 24) | (*(u8 *)(racer + 0x1C5) << 16) |
                   (*(u8 *)(racer + 0x1C6) << 8) | ((*(u16 *)(racer + 0x1D4) >> 8) & 0xFF);
    dl++;

    camPushModelMtx(&dl, &mtx, arg2, 1.0f, 0.0f);
    texDPTextureX(&dl, *(void **)(racer + 0x190), 0x20E, *(s32 *)(racer + 0x1D0) << 8);

    addr = (u32)racer + *(u8 *)(racer + 0x1DA) * 0x14 * 0xA + 0x80000000;
    dl->words.w0 = 0x040000D0 | ((((addr & 6) | 0xA0) & 0xFF) << 16);
    dl->words.w1 = addr;
    dl++;

    dl->words.w0 = 0x05F10100;
    dl->words.w1 = (u32)D_F2D58;
    dl++;

    dl->words.w0 = 0x05310040;
    dl->words.w1 = (u32)D_F2E58;
    dl++;

    camPopModelMtx(&dl);

    dl->words.w0 = 0xFB000000;
    dl->words.w1 = -1;
    dl++;

    dl->words.w0 = 0xFA000000;
    dl->words.w1 = -1;
    dl++;

    *arg0 = dl;
    *arg1 = mtx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/objDrawShockWave.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void expspriteInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *def = (u8 *)arg1;
    u8 *racer = *(u8 **)(obj + 0x68);
    s32 *handle = *(s32 **)(obj + 0x6C);

    texFreeSprite(*handle, arg0);
    *handle = texLoadSprite(*(s16 *)(def + 0xE), 0, arg0);
    *(f32 *)(obj + 0x8) = (f32) (*(u16 *)(def + 0x12)) * 0.001f;
    *(s16 *)(racer + 0x0) = *(s16 *)(def + 0x4);
    *(s16 *)(racer + 0x2) = *(s16 *)(def + 0x6);
    *(s16 *)(racer + 0x8) = 0;
    *(s16 *)(racer + 0x6) = 0;
    *(s16 *)(racer + 0x4) = *(s16 *)(def + 0x8);
    *(void **)(racer + 0x30) = arg1;
    racer[0x9] = def[0x16];
    *(s32 *)(obj + 0x3C) = 0;
    initColourCycle((unkResetColourCycle *) (racer + 0x10), (s32) def[0x17]);
    initColourCycle((unkResetColourCycle *) (racer + 0x20), (s32) def[0x18]);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/expspriteInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void expspriteControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *racer = *(u8 **)(obj + 0x68);
    u8 *def = *(u8 **)(racer + 0x30);
    s32 *hp = *(s32 **)(obj + 0x6C);
    s32 handle = *hp;
    s32 state = 1;
    s32 t;
    s32 lo;
    u8 v;

    if (handle == 0) {
        objFreeObject(arg0);
        return;
    }
    *(s16 *)(racer + 0x6) = (s16) (*(s16 *)(racer + 0x6) + arg1);
    if (*(s16 *)(racer + 0x6) >= *(s16 *)(def + 0xC)) {
        v = racer[0x8];
        lo = arg1 * def[0x14];
        if (lo < (s32) v) {
            racer[0x8] = (u8) (v - lo);
        } else {
            objFreeObject(arg0);
            return;
        }
    } else {
        v = racer[0x8];
        if ((s32) v < 0xFF) {
            t = (v + (arg1 * def[0x15])) & 0xFFFF;
            if (t >= 0x100) {
                t = 0xFF;
            }
            racer[0x8] = (u8) t;
        }
    }
    *(s16 *)(obj + 0x4) = (s16) (*(s16 *)(obj + 0x4) + (arg1 * *(u16 *)(def + 0x1A)));
    obj[0x39] = racer[0x8];
    updateColourCycle((unkResetColourCycle *) (racer + 0x10), arg1);
    updateColourCycle((unkResetColourCycle *) (racer + 0x20), arg1);
    texAnimateSprite(handle, &state, racer[0x9], obj + 0x28, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/expspriteControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void explosionFlushBlasts(void) {
    u8 *p = D_800F6B60_B17B0;
    s32 n = 0xF;

    do {
        *(s16 *)(p + 0x1C) = 0;
        p += 0x24;
    } while (n--);
    D_800A11B4_A1DB4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/explosionFlushBlasts.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void explosionAddBlast(f32 x, f32 y, f32 a, f32 z, f32 b, f32 c, f32 d, s32 e, s32 f) {
    u8 *p;
    s32 i;
    s32 j;

    if (D_800A11B4_A1DB4 < 0x10) {
        i = 0;
        if (*(s16 *)(D_800F6B60_B17B0 + 0x1C) != 0) {
            i = 1;
            while (i < 15 && *(s16 *)(D_800F6B60_B17B0 + i * 0x24 + 0x1C) != 0) {
                i++;
            }
        }
        D_800A11B4_A1DB4 += 1;
    } else {
        i = 0;
        for (j = 1; j < 16; j++) {
            if (*(f32 *)(D_800F6B60_B17B0 + j * 0x24 + 0x14) < *(f32 *)(D_800F6B60_B17B0 + i * 0x24 + 0x14)) {
                i = j;
            }
        }
    }
    p = D_800F6B60_B17B0 + i * 0x24;
    *(f32 *)(p + 0x00) = x;
    *(f32 *)(p + 0x04) = y;
    *(f32 *)(p + 0x08) = a;
    *(f32 *)(p + 0x0C) = z;
    *(f32 *)(p + 0x10) = 16384.0f / z;
    *(u8 *)(p + 0x1E) = 1;
    *(f32 *)(p + 0x14) = b;
    *(s16 *)(p + 0x1C) = (s16) (s32) (c * 60.0f);
    *(f32 *)(p + 0x18) = b / (f32) *(s16 *)(p + 0x1C);
    *(u8 *)(p + 0x1F) = (u8) d;
    *(s32 *)(p + 0x20) = e;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/explosionAddBlast.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void explosionHitTick(s32 arg0) {
    Object **list;
    s32 idx;
    s32 count;
    s16 type;
    s16 angle;
    s16 s0v;
    s8 a0;
    u8 *obj;
    u8 *sub;
    u8 *fp;
    u8 *blk;
    u8 *s4;
    u8 *s6;
    u8 *ent;
    s32 kind;
    s32 n;
    s32 hit;
    s32 flag;
    s32 v;
    f32 dt;
    f32 objRadius;
    f32 objHeight;
    f32 vertRange;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist2;
    f32 blastRadius;
    f32 reach2;
    f32 scaled;
    f32 dpx;
    f32 dpy;
    f32 dpz;
    f32 t;
    u8 *p;
    s16 timer;

    dt = (f32) arg0;
    if (D_800A11B4_A1DB4 > 0) {
        list = objGetObjList(&idx, &count);
        D_800A333C_A3F3C = 4;
        D_800A3348_A3F48 = 1;
        D_800A3340_A3F40 = NULL;
        D_800A3344_A3F44 = 0;
        if (idx < count) {
            do {
                obj = (u8 *) list[idx];
                idx += 1;
                sub = *(u8 **)(obj + 0x4C);
                if (*(u16 *)(*(u8 **)(obj + 0x40) + 0x14) & 0x2000) {
                    D_800A3340_A3F40 = obj;
                    D_800A3344_A3F44 = (s32) (*(u8 **)(obj + 0x40) + 4);
                    D_800A3348_A3F48 = 1;
                    type = *(s16 *)(obj + 0x48);
                    kind = -1;
                    s4 = NULL;
                    switch (type) {
                    case 0xA6:
                    case 0xA7:
                        if (sub != NULL) {
                            objRadius = *(f32 *)(sub + 0x24);
                            fp = obj + 0xC;
                            kind = 1;
                        }
                        break;
                    case 0x14:
                        s6 = *(u8 **)(obj + 0x68);
                        if (s6 != NULL) {
                            objRadius = *(f32 *)(s6 + 0x4);
                            fp = obj + 0xC;
                            kind = 1;
                        }
                        break;
                    case 0x1:
                    case 0x18:
                        if (sub != NULL) {
                            objRadius = *(f32 *)(sub + 0x24);
                            objHeight = *(f32 *)(sub + 0x28);
                            kind = *(u8 *)(sub + 0x30);
                            fp = sub + 0xC;
                        }
                        break;
                    case 0x4E:
                    case 0x5B:
                    case 0x74:
                    case 0x84:
                        kind = 0xFF;
                        break;
                    case 0x6C:
                        objRadius = *(f32 *)(sub + 0x24);
                        objHeight = *(f32 *)(sub + 0x28);
                        kind = *(u8 *)(sub + 0x30);
                        fp = sub + 0xC;
                        break;
                    default:
                        s4 = *(u8 **)(obj + 0x7C);
                        if (s4 != NULL) {
                            objRadius = 0.0f;
                            fp = obj + 0xC;
                            kind = 1;
                        }
                        break;
                    }

                    if (kind != -1) {
                        blk = D_800F6B60_B17B0;
                        n = 16;
                        /* asm: the blast pointer only advances for processed slots;
                         * skipped slots re-test the same record (no addiu $s1 on those
                         * branches). Reproduced as-is. */
                        do {
                            if (*(s16 *)(blk + 0x1C) > 0 && (s4 == NULL || (*(u8 *)(blk + 0x1E) & 1))) {
                                if (kind == 0xFF) {
                                    objRadius = 0.0f;
                                    hit = func_8002ABA4(obj, blk, &dist2);
                                } else {
                                    blastRadius = *(f32 *)(blk + 0x0C);
                                    dx = *(f32 *)(fp + 0x0) - *(f32 *)(blk + 0x0);
                                    dy = *(f32 *)(fp + 0x4) - *(f32 *)(blk + 0x4);
                                    dz = *(f32 *)(fp + 0x8) - *(f32 *)(blk + 0x8);
                                    hit = 0;
                                    reach2 = blastRadius + objRadius;
                                    if (kind == 2) {
                                        vertRange = blastRadius + objHeight;
                                    }
                                    reach2 = reach2 * reach2;
                                    dist2 = dx * dx + dz * dz;
                                    if (dist2 < reach2) {
                                        t = dist2 + dy * dy;
                                        dist2 = t;
                                        if (kind != 2) {
                                            if (t < reach2) {
                                                hit = 1;
                                            }
                                        } else if (-vertRange < dy && dy < vertRange) {
                                            hit = 1;
                                        }
                                    }
                                }

                                if (hit != 0) {
                                    if (sub != NULL) {
                                        *(s32 *)(sub + 0x3C) = 0;
                                    }
                                    dist2 = sqrtf(dist2) - objRadius;
                                    if (dist2 < 0.0f) {
                                        dist2 = 0.0f;
                                    }
                                    type = *(s16 *)(obj + 0x48);
                                    scaled = *(f32 *)(blk + 0x14) * dt;
                                    switch (type) {
                                    case 0xA6:
                                    case 0xA7:
                                        *(s16 *)(sub + 0x6) = (s16) (*(s16 *)(sub + 0x6) - (s32) (scaled * Cosf((s32) (*(f32 *)(blk + 0x10) * dist2))));
                                        break;
                                    case 0x14:
                                        *(s16 *)(s6 + 0x2) = (s16) (*(s16 *)(s6 + 0x2) - (s32) (scaled * Cosf((s32) (*(f32 *)(blk + 0x10) * dist2))));
                                        if (*(s16 *)(s6 + 0x2) < 0) {
                                            *(s16 *)(s6 + 0x2) = 0;
                                        }
                                        break;
                                    case 0x1:
                                        dist2 = func_8002A958(blk, sub, dist2);
                                        t = scaled * Cosf((s32) (*(f32 *)(blk + 0x10) * dist2));
                                        if (*(s16 *)(sub + 0x6) >= 0x100) {
                                            ent = *(u8 **)(obj + 0x68);
                                            v = func_8002AA30(sub, (s32) t);
                                            *(s16 *)(ent + 0x536) = (s16) (*(s16 *)(ent + 0x536) + v);
                                            if (*(s16 *)(sub + 0x6) < 0x100) {
                                                v = *(s32 *)(blk + 0x20);
                                                if (v != 0) {
                                                    hitPlayerKilledPlayer((void *) v, obj);
                                                }
                                            }
                                        }
                                        break;
                                    case 0x18:
                                        dist2 = func_8002A958(blk, sub, dist2);
                                        t = scaled * Cosf((s32) (*(f32 *)(blk + 0x10) * dist2));
                                        angle = (s16) mathDiffAngle(*(s16 *)(obj + 0x0), (s16) Arctanf(dx, dz));
                                        flag = angle >= 0x4000;
                                        if (flag == 0) {
                                            flag = angle < -0x3FFF;
                                        }
                                        s0v = *(s16 *)(sub + 0x6);
                                        *(u8 *)(sub + 0x8) = (u8) (((flag << 5) & 0x20) | (*(u8 *)(sub + 0x8) & 0xFFDF));
                                        /* sig mismatch: func_8002AA30 is 2-arg, asm passes flag as 3rd */
                                        v = ((s32 (*)(void *, s32, s32)) func_8002AA30)(sub, (s32) t, flag);
                                        (void) v;
                                        if (*(s16 *)(sub + 0x6) <= 0) {
                                            a0 = *(s8 *)(blk + 0x1F);
                                            ent = *(u8 **)(obj + 0x68);
                                            if (a0 != 0x64 && s0v > 0 && !(*(u32 *)ent & 8)) {
                                                mainIncreaseWeaponKills(a0);
                                            }
                                        }
                                        break;
                                    case 0x4E:
                                    case 0x74:
                                        ent = *(u8 **)(obj + 0x5C);
                                        if (ent != NULL) {
                                            t = scaled * Cosf((s32) (*(f32 *)(blk + 0x10) * dist2));
                                            *(u8 *)(ent + 0x12A) = 1;
                                            *(s16 *)(ent + 0x130) = (s16) (*(s16 *)(ent + 0x130) + (s32) t);
                                        }
                                        break;
                                    case 0x5B:
                                    case 0x84:
                                        *(s32 *)(obj + 0x88) = *(s32 *)(obj + 0x88) + (s32) (scaled * Cosf((s32) (*(f32 *)(blk + 0x10) * dist2)));
                                        break;
                                    case 0x6C:
                                        cutcameraUpdate(obj, blk, scaled);
                                        break;
                                    default:
                                        if (s4 != NULL) {
                                            func_8002A7DC(blk, dist2, dx, dy, dz, &dpx, &dpy, &dpz);
                                            *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) + dpx;
                                            *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + dpy;
                                            *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) + dpz;
                                            *s4 &= 0xFFFD;
                                        }
                                        break;
                                    }
                                }
                                blk += 0x24;
                            }
                        } while (--n != 0);
                    }
                    D_800A3348_A3F48 = 4;
                }
            } while (idx < count);
        }

        /* decay pass over the 16 blast records */
        p = D_800F6B60_B17B0;
        n = 16;
        do {
            timer = *(s16 *)(p + 0x1C);
            if (timer != 0) {
                *(s16 *)(p + 0x1C) = (s16) (timer - arg0);
                *(u8 *)(p + 0x1E) = (u8) (*(u8 *)(p + 0x1E) & ~1);
                if (*(s16 *)(p + 0x1C) <= 0) {
                    *(s16 *)(p + 0x1C) = 0;
                    D_800A11B4_A1DB4 = D_800A11B4_A1DB4 - 1;
                } else {
                    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) - *(f32 *)(p + 0x18) * dt;
                }
            }
            p += 0x24;
        } while (--n != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/explosionHitTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 explosionBlastHit(f32 x, f32 y, f32 z, f32 radius, s32 exact) {
    u8 *p;
    s32 i;
    s32 hit = 0;

    if (D_800A11B4_A1DB4 != 0) {
        p = D_800F6B60_B17B0;
        i = 0xF;
        do {
            if (*(s16 *)(p + 0x1C) != 0) {
                f32 dx = *(f32 *)(p + 0x00) - x;
                f32 dy = *(f32 *)(p + 0x04) - y;
                f32 dz = *(f32 *)(p + 0x08) - z;
                f32 r = radius;

                if (exact == 0) {
                    r = *(f32 *)(p + 0x0C) + radius;
                }
                if ((dx * dx + dy * dy + dz * dz) < r * r) {
                    hit = 1;
                    i = 0;
                }
            }
            p += 0x24;
        } while (i--);
    }
    return hit;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/explosionBlastHit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002A7DC(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    u8 *obj = (u8 *)arg0;
    f32 len2;
    f32 scale;
    f32 inv;
    f32 spd;

    len2 = arg2 * arg2 + arg3 * arg3 + arg4 * arg4;
    scale = len2;
    if (len2 != 0.0f) {
        inv = 1.0f / sqrtf(len2);
        spd = Cosf((s32) (*(f32 *)(obj + 0x10) * arg1)) * (0.1f * *(f32 *)(obj + 0x14));
        if (spd < 1.0f) {
            spd = 1.0f;
        }
        scale = inv * spd;
    }
    *arg5 = arg2 * scale;
    *arg6 = arg3 * scale;
    *arg7 = arg4 * scale;
    if (*arg6 >= 0.0f) {
        if (*arg6 < 1.5f) {
            *arg6 = 1.5f;
        }
    } else {
        if (*arg6 > -1.5f) {
            *arg6 = -1.5f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/func_8002A7DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 func_8002A958(void *arg0, void *arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *vec = (u8 *)arg1;
    u8 *list;
    u8 *src;
    s32 n;
    s32 i;
    f32 best = arg2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    n = *(s16 *)(vec + 0x32);
    if (n == 0) {
        list = NULL;
        n = 1;
    } else {
        list = *(u8 **)(vec + 0x40);
    }
    for (i = 0; i < n; i++) {
        if (list == NULL) {
            src = vec;
        } else {
            src = list;
            list += 0x34;
        }
        dx = *(f32 *)(src + 0x0C) - *(f32 *)(obj + 0x00);
        dy = *(f32 *)(src + 0x10) - *(f32 *)(obj + 0x04);
        dz = *(f32 *)(src + 0x14) - *(f32 *)(obj + 0x08);
        dist = sqrtf(dx * dx + dy * dy + dz * dz) - *(f32 *)(src + 0x24);
        if (dist < best) {
            best = dist;
        }
    }
    if (best < 0.0f) {
        best = 0.0f;
    }
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/func_8002A958.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8002AA30(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    s32 amount = arg1;
    s32 total = 0;
    s32 k;
    s32 share;
    s32 t1;
    s16 count;
    u32 flags;
    u8 *e;

    if (amount <= 0) {
        return 0;
    }
    count = *(s16 *)(obj + 0x32);
    if (count == 0) {
        if (*(u32 *)(obj + 0x08) & 0x40000000) {
            return 0;
        }
        if (obj[0x2F] != 100) {
            amount = ((s32) (obj[0x2F] * amount * 0xA4)) >> 14;
        }
        *(s16 *)(obj + 0x2C) = (s16) (*(s16 *)(obj + 0x2C) + amount);
        *(s16 *)(obj + 0x06) = (s16) (*(s16 *)(obj + 0x06) - amount);
        return amount;
    }

    e = *(u8 **)(obj + 0x40);
    share = amount / count;
    for (k = 0; k < count; k++) {
        if (k == count - 1) {
            share = amount;
        }
        flags = *(u32 *)(e + 0x30);
        if (!(flags & 0x20000000) && !(flags & 0x40000000)) {
            t1 = share;
            if (e[0x2F] != 100) {
                t1 = ((s32) (e[0x2F] * share * 0xA4)) >> 14;
            }
            total += t1;
            amount -= share;
            obj[0x31] = (s8) ((s32) (e - *(u8 **)(obj + 0x40)) / 0x34);
            *(s16 *)(e + 0x2C) = (s16) (*(s16 *)(e + 0x2C) + t1);
            *(s16 *)(obj + 0x06) = (s16) (*(s16 *)(obj + 0x06) - t1);
        }
        e += 0x34;
    }
    if (total != 0) {
        total += amount;
        *(s16 *)(obj + 0x06) = (s16) (*(s16 *)(obj + 0x06) - amount);
    }
    return total;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/func_8002AA30.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8002ABA4(void *arg0, void *arg1, f32 *arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *vec = (u8 *)arg1;
    u8 *box;
    s16 *bx;
    f32 scale;
    f32 cosA;
    f32 sinA;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 ex = 0.0f;
    f32 ey = 0.0f;
    f32 ez = 0.0f;
    f32 d;
    f32 r;
    s32 outside = 0;

    box = ((u8 **) *(u8 **)(obj + 0x6C))[(s8) obj[0x3A]];
    if (box == NULL) {
        return 0;
    }
    scale = *(f32 *)(obj + 0x08);
    sinA = Sinf(-*(s16 *)obj);
    cosA = Cosf((s32) -*(s16 *)obj);

    dx = *(f32 *)(vec + 0x00) - *(f32 *)(obj + 0x0C);
    dz = *(f32 *)(vec + 0x08) - *(f32 *)(obj + 0x14);
    rx = dx * cosA + dz * sinA;
    rz = dz * cosA - dx * sinA;
    ry = *(f32 *)(vec + 0x04) - *(f32 *)(obj + 0x10);

    bx = (s16 *) (box + 0x8C);
    if (rx < bx[0] * scale) {
        ex = bx[0] * scale - rx;
        outside = 1;
    } else if (bx[3] * scale < rx) {
        ex = rx - bx[3] * scale;
        outside = 1;
    }
    if (ry < bx[1] * scale) {
        ey = bx[1] * scale - ry;
        outside = 1;
    } else if (bx[4] * scale < ry) {
        ey = ry - bx[4] * scale;
        outside = 1;
    }
    if (rz < bx[2] * scale) {
        ez = bx[2] * scale - rz;
        outside = 1;
    } else if (bx[5] * scale < rz) {
        ez = rz - bx[5] * scale;
        outside = 1;
    }
    if (!outside) {
        *arg2 = 0.0f;
        return 1;
    }
    d = ex * ex + ey * ey + ez * ez;
    *arg2 = d;
    r = *(f32 *)(vec + 0x0C);
    return (d < r * r) ? 1 : 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/explosion/func_8002ABA4.s")
#endif
