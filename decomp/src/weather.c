#include "common.h"

typedef enum WeatherType { WEATHER_SNOW, WEATHER_RAIN, WEATHER_UNK } WeatherType;
enum ViewportCount {
    VIEWPORTS_COUNT_1_PLAYER,
    VIEWPORTS_COUNT_2_PLAYERS,
    VIEWPORTS_COUNT_3_PLAYERS,
    VIEWPORTS_COUNT_4_PLAYERS
};

/* decomp: externs */
typedef struct {
    s16 unk0;
    s16 unk2;
    // s16 unk4;
    s32 unk4;
} unk80127BF8;
extern unk80127BF8 D_80101568;

/* 0x2C-byte weather template (D_800A6300[2], copied into D_800A6388). D_800A6390 is D_800A6388.unk8. */
typedef struct WeatherTable {
    /* 0x00 */ void *unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ TextureHeader *unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s32 unk28;
} WeatherTable;

/* D_80101528: weather state, all words */
typedef struct WeatherState {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
} WeatherState;

/* 0x10-byte particle entry (D_800A6384) */
typedef struct WeatherParticle {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s8 unkC;
    /* 0x0D */ s8 unkD;
    /* 0x0E */ s8 unkE;
    /* 0x0F */ u8 unkF;
} WeatherParticle;

/* 10-byte vertex used by the weather quads (D_800A63B4, D_800A63C4, D_80101584) */
typedef struct WeatherVtx {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ u8 r;
    /* 0x07 */ u8 g;
    /* 0x08 */ u8 b;
    /* 0x09 */ u8 a;
} WeatherVtx;

/* 0x2C-byte snow/rain drop entry (D_800A63D4[16]) */
typedef struct WeatherDrop {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ s16 unk6;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 pad1A[2];
    /* 0x1C */ u8 pad1C[0xC];
    /* 0x28 */ f32 unk28;
} WeatherDrop;

/* D_8010158C: camera data */
typedef struct WeatherCam {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u8 pad2[0xA];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
} WeatherCam;

/* height query result (track or hit) */
typedef struct HeightPoint {
    /* 0x00 */ f32 height;
    /* 0x04 */ u8 pad4[0xF];
    /* 0x13 */ s8 unk13;
} HeightPoint;

extern WeatherTable D_800A6300[2];
extern WeatherTable D_800A6388;
extern WeatherParticle *D_800A6384;
extern WeatherVtx *D_800A63B4;
extern s32 D_800A63B8;
extern u8 *D_800A63BC;
extern u16 *D_800A63C0;
extern WeatherVtx *D_800A63C4[2];
extern u32 *D_800A63CC;
extern s8 D_800A63D0;
extern WeatherDrop D_800A63D4[16];
extern f32 D_800A66B8;
extern f32 D_800A66BC;
extern f32 D_800A66C0;
extern f32 D_800A66C4;
extern f32 D_800A66C8;
extern f32 D_800A66CC;
extern f32 D_800A66D0;
extern f32 D_800A66D4;
extern s32 D_800A66E0;
extern s32 D_800A66E4;
extern s32 D_800A66EC;
extern s32 D_800A66F0;
extern s32 D_800A66F4;
extern s32 D_800A66F8;
extern s32 D_800A66FC;
extern s32 D_800A6700;
extern void *D_800A6704;
extern void *D_800A6708;
extern s32 D_800A670C;
extern SoundMask *D_800A6710;
extern s32 D_800A6714;
extern s32 D_800A6784_A7384;
extern WeatherState D_80101528;
extern s32 D_80101520;
extern s32 D_80101524;
extern s32 D_80101570;
extern s32 D_80101574;
extern s8 D_80101578;
extern u32 *D_8010157C;
extern void *D_80101580;
extern WeatherVtx *D_80101584;
extern void *D_80101588;
extern WeatherCam *D_8010158C;
extern void *D_80101590;
extern s32 D_80101594;
extern s32 D_80101598;
extern s32 D_8010159C;
extern s32 D_801015A0;
extern s32 D_801015A4;
extern s32 D_801015A8;
extern s32 D_801015AC;
extern s32 D_801015B0;
void mathOneFloatPY(s16 *, f32 *);
extern u8 D_A5CD8;

extern void *camGetPtr(void);
extern void *camGetRotationMtx(void);
extern void *camGetProjOrgMtx(void);
extern void camDoSprite(void **arg0, void **arg1, void **arg2, void *arg3, s32 arg4, s32 arg5, u8 arg6);
extern void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
extern void *texLoadSprite(s32 spriteId, s32 arg1);
extern void texFreeSprite(void *sprite);
extern void texFreeTexture(void *tex);
extern void *objGetPlayerNo(s32 playerNo);
extern s32 trackGetHeights(f32 x, f32 z, s32 radius, void *heights);
extern s32 hitGetHeights(f32 x, f32 z, s32 radius, void *heights);
extern void mathMtxFastXFMF(void *mtx, f32 *in, f32 *out);
extern void amSndPlay(s32 soundId, void *handlePtr, s32 *a, s32 *b);
extern void amSndPlayXYZ(f32 a, f32 b, s32 soundId, f32 c, f32 d, f32 e, s32 arg6, SoundMask **soundMask);
extern void amSndStopXYZ(SoundMask *soundMask);
extern s32 fxFadeOn(s32 arg0, s32 *arg1);
extern void setupClearScreen(void *arg0);
extern void rainFree(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void rainMove(void);
extern f32 Sinf(s32 angle);
extern void func_overlay_3430_D6600000(f32 a, f32 b, f32 c, s32 d);

void initWeather(void);
void freeWeather(void);
void setupWeather(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void changeWeather(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void doWeather(void **arg0, void **arg1, void **arg2, void **arg3, s32 arg4);
void func_8005C0CC(void);
void func_8005C3C8(void);
void func_8005C6E4(s32 unused0, s32 arg1, s32 arg2, s32 unused3);
void func_8005C7D0(void);
void func_8005C858(s32 arg0, s32 arg1, f32 arg2);
void func_8005CAE0(s32 arg0);
void func_8005CC28(s32 arg0);
void func_8005D458(s32 arg0);
void func_8005D568(s32 arg0);
void func_8005D654(void);
void func_8005D6A4(s32 arg0, void *arg1);
/* decomp: externs end */

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void initWeather(void) {
    D_800A6388.unk0 = NULL;
    D_800A6388.unk4 = 0;
    D_800A6384 = NULL;
    D_80101520 = 0;
    D_80101570 = 24;
    D_80101574 = 12;
    D_800A63C4[0] = NULL;
    D_800A63C4[1] = NULL;
    D_800A63BC = NULL;
    D_80101568.unk0 = -1;
    D_80101568.unk2 = -0x200;
    if (D_800A63CC == NULL) {
        D_800A63CC = piRomLoad(0x1B);
        D_800A63D0 = 0;
        while (D_800A63CC[D_800A63D0] != -1U) {
            D_800A63D0++;
        }
    }
    D_80101578 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/initWeather.s")
#endif

/* decomp: setWeatherLimits (human) */
void setWeatherLimits(s16 arg0, s16 arg1) {
    if (D_80101568.unk2 < D_80101568.unk0) {
        D_80101568.unk0 = arg0;
        D_80101568.unk2 = arg1;
    } else {
        D_80101568.unk0 = arg1;
        D_80101568.unk2 = arg0;
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void freeWeather(void) {
    if (D_800A63BC != NULL) {
        mmFree(D_800A63BC);
        D_800A63BC = NULL;
    }
    if (D_800A63C4[0] != NULL) {
        mmFree(D_800A63C4[0]);
        D_800A63C4[0] = NULL;
    }
    if (D_800A63C4[1] != NULL) {
        mmFree(D_800A63C4[1]);
        D_800A63C4[1] = NULL;
    }
    if (D_800A6384 != NULL) {
        mmFree(D_800A6384);
        D_800A6384 = NULL;
    }
    if (D_800A6388.unk0 != NULL) {
        mmFree(D_800A6388.unk0);
        D_800A6388.unk0 = NULL;
    }
    if (D_800A6388.unk8 != NULL) {
        texFreeTexture(D_800A6388.unk8);
        D_800A6388.unk8 = NULL;
    }
    if (D_800A63C0 != NULL) {
        mmFree(D_800A63C0);
        D_800A63C0 = NULL;
    }
    if (D_800A66D8 != 0) {
        func_8005C7D0();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/freeWeather.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void setupWeather(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 var_s1;
    WeatherTable *temp_s0;
    WeatherParticle *p;
    WeatherVtx *v;
    s32 i;
    s32 j;
    s32 k;
    s32 temp_a2;
    s32 temp_s1;
    s16 temp_s1_2;
    s16 temp_s2;
    s32 a;
    u8 *q;

    var_s1 = arg0;
    freeWeather();
    D_80101528.unkC = arg2;
    D_80101528.unk10 = 0;
    D_80101528.unk14 = arg2;
    D_80101528.unk18 = arg3;
    D_80101528.unk1C = 0;
    D_80101528.unk20 = arg3;
    D_80101528.unk28 = 0;
    D_80101528.unk4 = 0;
    D_80101528.unk34 = 0;
    D_80101528.unk3C = 0;
    D_80101528.unk24 = arg4;
    D_80101528.unk2C = arg4;
    D_80101528.unk0 = arg5;
    D_80101528.unk8 = arg5;
    D_80101528.unk30 = arg6;
    D_80101528.unk38 = arg6;
    if (var_s1 >= 2) {
        var_s1 = 1;
    }
    temp_s0 = &D_800A6300[var_s1];
    if ((s32) temp_s0->unk8 == 1) {
        func_8005C6E4(arg1, arg5 + 1, arg6 + 1, arg5);
        return;
    }
    D_800A6388 = *temp_s0;
    D_800A6388.unk0 = (void *) mmAlloc(temp_s0->unk4 * 0xC, 0xAA55FFFF);
    if ((s32) temp_s0->unk8 == 0) {
        func_8005D654();
    }
    D_80101520 = arg1;
    D_800A63C0 = (u16 *) mmAlloc(arg1 * 2, 0xAA55FFFF);
    D_800A6384 = (WeatherParticle *) mmAlloc(arg1 * 0x10, 0xAA55FFFF);
    for (i = 0; i < D_80101520; i++) {
        p = D_800A6384 + i;
        p->unk0 = mathRnd(0, D_800A6388.unk18);
        p->unk4 = mathRnd(0, D_800A6388.unk1C);
        p->unk8 = mathRnd(0, D_800A6388.unk20);
        p->unkC = (s8) (1 << (mathRnd(0, 0x20) + 5));
        p->unkD = (s8) (1 << (mathRnd(0, 0x20) + 5));
        p->unkE = (s8) (1 << (mathRnd(0, 0x20) + 5));
        p->unkF = mathRnd(0, D_800A6388.unk4 - 1);
    }

    temp_a2 = arg1 * 4;
    temp_s1 = arg1 * 0x14 * 2;
    D_800A63C4[0] = (WeatherVtx *) mmAlloc(temp_s1, 0xAA55FFFF);
    D_800A63C4[1] = (WeatherVtx *) mmAlloc(temp_s1, 0xAA55FFFF);
    for (k = 0; k < 2; k++) {
        for (j = 0; j < temp_a2; j++) {
            v = D_800A63C4[k] + j;
            v->r = 0xFF;
            v->g = 0xFF;
            v->b = 0xFF;
            v->a = 0xFF;
        }
    }

    temp_s1_2 = (s16) ((D_800A6388.unk8->width << 5) - 1);
    temp_s2 = (s16) ((D_800A6388.unk8->height << 5) - 1);
    D_800A63BC = (u8 *) mmAlloc(D_80101574 * 0x10, 0xAA55FFFF);
    for (i = 0; i < D_80101574; i += 2) {
        /* two 0x10-byte halves per iteration, offsets mirror the asm stores */
        q = D_800A63BC + (i * 0x10);
        a = i * 2;
        q[0x00] = 0;
        q[0x01] = (u8) (a + 3);
        q[0x02] = (u8) (a + 1);
        q[0x03] = (u8) a;
        *(s16 *) (q + 0x04) = 0;
        *(s16 *) (q + 0x06) = temp_s2;
        *(s16 *) (q + 0x08) = temp_s1_2;
        *(s16 *) (q + 0x0A) = 0;
        *(s16 *) (q + 0x0C) = 0;
        *(s16 *) (q + 0x0E) = 0;
        q[0x10] = 0;
        q[0x11] = (u8) (a + 3);
        q[0x12] = (u8) (a + 2);
        q[0x13] = (u8) (a + 1);
        *(s16 *) (q + 0x14) = 0;
        *(s16 *) (q + 0x16) = temp_s2;
        *(s16 *) (q + 0x18) = temp_s1_2;
        *(s16 *) (q + 0x1A) = temp_s2;
        *(s16 *) (q + 0x1C) = temp_s1_2;
        *(s16 *) (q + 0x1E) = 0;
    }
    D_80101578 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/setupWeather.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void changeWeather(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if ((arg5 > 0) && ((arg0 != D_80101528.unk14) || (arg1 != D_80101528.unk20) || (arg2 != D_80101528.unk2C) || (arg3 != D_80101528.unk0) || (arg4 != D_80101528.unk30))) {
        D_80101528.unk14 = arg0;
        D_80101528.unk20 = arg1;
        D_80101528.unk2C = arg2;
        D_80101528.unk10 = (arg0 - D_80101528.unkC) / arg5;
        D_80101528.unk1C = (arg1 - D_80101528.unk18) / arg5;
        D_80101528.unk28 = (arg2 - D_80101528.unk24) / arg5;
        if (D_800A66D8 == 0) {
            D_80101528.unk8 = arg3;
            D_80101528.unk38 = arg4;
            D_80101528.unk3C = arg5;
            D_80101528.unk4 = (arg3 - D_80101528.unk0) / arg5;
            D_80101528.unk34 = (arg4 - D_80101528.unk30) / arg5;
            return;
        }
        D_80101528.unk0 = arg3;
        D_80101528.unk30 = arg4;
        D_80101528.unk3C = 0;
        func_8005C858(arg3 + 1, arg4 + 1, (f32) arg5 / 60.0f);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/changeWeather.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void doWeather(void **arg0, void **arg1, void **arg2, void **arg3, s32 arg4) {
    D_8010157C = (u32 *) *arg0;
    D_80101580 = *arg1;
    D_80101584 = (WeatherVtx *) *arg2;
    D_80101588 = *arg3;
    D_8010158C = (WeatherCam *) camGetPtr();
    D_80101590 = camGetRotationMtx();
    if (D_800A66D8 != 0) {
        func_8005CAE0(arg4);
    } else {
        if (D_80101528.unk3C > 0) {
            if (arg4 < D_80101528.unk3C) {
                D_80101528.unk0 += D_80101528.unk4 * arg4;
                D_80101528.unkC += D_80101528.unk10 * arg4;
                D_80101528.unk18 += D_80101528.unk1C * arg4;
                D_80101528.unk3C -= arg4;
                D_80101528.unk24 += D_80101528.unk28 * arg4;
                D_80101528.unk30 += D_80101528.unk34 * arg4;
            } else {
                D_80101528.unk3C = 0;
                D_80101528.unk0 = D_80101528.unk8;
                D_80101528.unkC = D_80101528.unk14;
                D_80101528.unk18 = D_80101528.unk20;
                D_80101528.unk24 = D_80101528.unk2C;
                D_80101528.unk30 = D_80101528.unk38;
            }
        }
        D_80101524 = (D_80101520 * D_80101528.unk0) >> 0x10;
        D_80101568.unk4 = (D_80101568.unk0 + ((D_80101568.unk2 - D_80101568.unk0) * D_80101528.unk30)) >> 0x10;
        func_8005D6A4(arg4, &D_80101568);
        if ((D_80101524 > 0) && (D_80101568.unk4 < D_80101568.unk0)) {
            D_800A63B4 = D_800A63C4[D_80101578];
            func_8005C0CC();
            func_8005C3C8();
            D_80101578 = 1 - D_80101578;
        }
    }
    *arg0 = D_8010157C;
    *arg1 = D_80101580;
    *arg2 = D_80101584;
    *arg3 = D_80101588;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/doWeather.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005C0CC(void) {
    s16 temp_s5;
    s16 temp_s6;
    s32 sp58;
    s32 sp54;
    s32 sp5C;
    s32 i;
    s32 temp_f6;
    f32 vec[3];
    WeatherParticle *p;
    WeatherVtx *out;
    s16 xs;
    s32 xi;
    s32 yi;

    temp_s5 = D_800A6388.unk24;
    temp_s6 = D_800A6388.unk26;
    D_800A63B8 = 0;
    out = D_800A63B4;
    sp58 = (s32) (D_8010158C->unk10 * 65536.0f);
    sp54 = (s32) (D_8010158C->unk14 * 65536.0f);
    if (D_80101524 > 0) {
        sp5C = (s32) (D_8010158C->unkC * 65536.0f);
        for (i = 0; i < D_80101524; i++) {
            p = D_800A6384 + i;
            vec[0] = (f32) (((p->unk0 - sp5C) & D_800A6388.unk18) + D_800A6388.unkC) * 0.000015258789f;
            vec[1] = (f32) (((p->unk4 - sp58) & D_800A6388.unk1C) + D_800A6388.unk10) * 0.000015258789f;
            vec[2] = (f32) (((p->unk8 - sp54) & D_800A6388.unk20) + D_800A6388.unk14) * 0.000015258789f;
            mathMtxFastXFMF(D_80101590, vec, vec);
            temp_f6 = (s32) vec[2];
            if (((s16) temp_f6 < D_80101568.unk0) && (D_80101568.unk4 < (s16) temp_f6)) {
                xi = (s32) vec[0];
                yi = (s32) vec[1];
                xs = (s16) (xi - temp_s5);
                out[0].x = xs;
                out[1].x = (s16) (xi + temp_s5);
                out[2].x = out[1].x;
                out[3].x = out[0].x;
                out[0].y = (s16) (yi + temp_s6);
                out[1].y = out[0].y;
                out[2].y = (s16) (yi - temp_s6);
                out[3].y = out[2].y;
                out[0].z = (s16) temp_f6;
                out[1].z = (s16) temp_f6;
                out[2].z = (s16) temp_f6;
                out[3].z = (s16) temp_f6;
                D_800A63B8 += 4;
                out += 4;
                ((u16 *) D_800A63C0)[D_800A63B8 >> 2] = (u16) i;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005C0CC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005C3C8(void) {
    s32 var_t1;
    s32 temp_a0;
    s32 temp_t8;
    u32 temp_t0;
    u32 temp_t0_2;
    u32 *dl;
    void *temp_v0;

    if (D_800A6388.unk8 != NULL) {
        D_80101570 = 4;
        D_80101574 = 2;
        if (D_800A63B8 >= 4) {
            temp_v0 = camGetProjOrgMtx();
            dl = D_8010157C;
            D_8010157C += 2;
            dl[1] = (u32) temp_v0 + 0x80000000;
            dl[0] = 0x01000040;
            dl = D_8010157C;
            D_8010157C += 2;
            dl[0] = 0xBC00000A;
            dl[1] = 0;
            texDPTextureX((Gfx **) &D_8010157C, D_800A6388.unk8, 2, 0);
            dl = D_8010157C;
            D_8010157C += 2;
            dl[0] = 0xFA000000;
            dl[1] = 0xE0F0FFA0;
            dl = D_8010157C;
            D_8010157C += 2;
            dl[0] = 0xFB000000;
            dl[1] = 0x4080FF00;
            var_t1 = 0;
            if (D_80101570 < D_800A63B8) {
                do {
                    dl = D_8010157C;
                    D_8010157C += 2;
                    temp_t0 = (u32) (D_800A63B4 + var_t1) + 0x80000000;
                    dl[0] = (u32) ((((D_80101570 * 8) | (temp_t0 & 6)) & 0xFF) << 0x10) | 0x04000000 | (((D_80101570 * 0xA) + 8) & 0xFFFF);
                    dl[1] = temp_t0;
                    dl = D_8010157C;
                    D_8010157C += 2;
                    dl[0] = (u32) ((((((D_80101574 - 1) * 0x10) | 1) & 0xFF) << 0x10) | 0x05000000 | ((D_80101574 * 0x10) & 0xFFFF));
                    dl[1] = (u32) D_800A63BC + 0x80000000;
                    var_t1 += D_80101570;
                } while ((var_t1 + D_80101570) < D_800A63B8);
            }
            temp_a0 = D_800A63B8 - var_t1;
            dl = D_8010157C;
            D_8010157C += 2;
            temp_t0_2 = (u32) (D_800A63B4 + var_t1) + 0x80000000;
            dl[0] = (u32) ((((temp_a0 * 8) | (temp_t0_2 & 6)) & 0xFF) << 0x10) | 0x04000000 | (((temp_a0 * 0xA) + 8) & 0xFFFF);
            dl[1] = temp_t0_2;
            temp_t8 = (D_800A63B8 - var_t1) >> 1;
            dl = D_8010157C;
            D_8010157C += 2;
            dl[0] = (u32) ((((((temp_t8 - 1) * 0x10) | 1) & 0xFF) << 0x10) | 0x05000000 | ((temp_t8 * 0x10) & 0xFFFF));
            dl[1] = (u32) D_800A63BC + 0x80000000;
            dl = D_8010157C;
            D_8010157C += 2;
            dl[1] = 0xFFFFFFFF;
            dl[0] = 0xFA000000;
            dl = D_8010157C;
            D_8010157C += 2;
            dl[0] = 0xFB000000;
            dl[1] = 0xFFFFFFFF;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005C3C8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005C6E4(s32 unused0, s32 arg1, s32 arg2, s32 unused3) {
    D_800A66DC = arg1;
    D_800A66E0 = 0;
    D_800A66E4 = D_800A66DC;
    D_800A66E8 = arg2;
    D_800A66EC = 0;
    D_800A66F0 = D_800A66E8;
    D_800A66F4 = 0;
    D_800A66F8 = 0;
    D_800A66FC = 0;
    D_800A6700 = 0;
    D_800A670C = 0;
    rainFree(0x2BC, 0x2BC, 0x2BC, 0x2080E002, 0xA0E0FF04, 0x226);
    D_800A6704 = texLoadSprite(0x4A, 0);
    D_800A6708 = texLoadTexture(0x1AC);
    D_800A66D8 = 1;
    D_80101594 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005C6E4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005C7D0(void) {
    if (D_800A6704 != NULL) {
        texFreeSprite(D_800A6704);
        D_800A6704 = NULL;
    }
    if (D_800A6708 != NULL) {
        texFreeTexture(D_800A6708);
        D_800A6708 = NULL;
    }
    if (D_800A6710 != NULL) {
        amSndStopXYZ(D_800A6710);
        D_800A6710 = NULL;
    }
    rainMove();
    D_800A66D8 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005C7D0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005C858(s32 arg0, s32 arg1, f32 arg2) {
    if (osTvType == 0) {
        D_800A66F4 = (s32) (50.0f * arg2);
    } else {
        D_800A66F4 = (s32) (60.0f * arg2);
    }
    D_800A66E4 = arg0;
    D_800A66E0 = (s32) (arg0 - D_800A66DC) / (s32) D_800A66F4;
    D_800A66F0 = arg1;
    D_800A66EC = (s32) (arg1 - D_800A66E8) / (s32) D_800A66F4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005C858.s")
#endif

/* decomp: rainSetFog / rainDensity (human) */
void rainSetFog(void) {
    s32 a, b;

    if (D_800A66D8 != WEATHER_SNOW && camGetMode() == VIEWPORTS_COUNT_1_PLAYER) {
        if (!(levelGetLevel()->unkA2 & 1)) {
            a = ((D_800A66DC * -38) >> 16) + 1018;
            b = ((D_800A66DC * -20) >> 16) + 1023;
            trackSetFog(0, a, b, a, 28, 15, 36, 0);
        }
    }
}

f32 rainDensity(void) {
    f32 var_f2;

    var_f2 = (f32) (((D_800A66E8 >> 2) * D_800A66DC) >> 14) / 0x10000;
    if (var_f2 < 0.0f) {
        var_f2 = 0.0f;
    }
    if (var_f2 > 1.0f) {
        var_f2 = 1.0f;
    }
    return var_f2;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005CAE0(s32 arg0) {
    if ((camGetMode() == 0) && (D_800A66D8 != 0)) {
        if (D_800A66F4 > 0) {
            if (arg0 < D_800A66F4) {
                D_800A66F4 -= arg0;
                D_800A66DC += D_800A66E0 * arg0;
                D_800A66E8 += D_800A66EC * arg0;
            } else {
                D_800A66F4 = 0;
                D_800A66DC = D_800A66E4;
                D_800A66E8 = D_800A66F0;
            }
        }
        func_overlay_3430_D6600000((f32) D_80101528.unkC / 65536.0f, ((f32) D_80101528.unk18 / 65536.0f) - 5.0f, (f32) D_80101528.unk24 / 65536.0f, arg0);
        func_8005D568(arg0);
        func_8005CC28(arg0);
        func_8005D458(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005CAE0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005CC28(s32 arg0) {
    s32 temp_t1;
    s32 temp_t4;
    s32 temp_t7;
    s32 var_v0;
    s32 var_s3;
    s32 var_s3_2;
    s32 found;
    s32 ang;
    s32 trackOk;
    s32 hitOk;
    f32 radius;
    f32 x;
    f32 z;
    void *player;
    HeightPoint *hp_track;
    HeightPoint *hp_hit;
    WeatherDrop *drop;
    WeatherVtx *vtx;
    u32 *dl;

    if ((D_800A6704 != NULL) && (D_800A6708 != NULL)) {
        temp_t1 = (s32) (((s32) D_800A66E8 >> 2) * D_800A66DC) >> 0xE;
        if (temp_t1 >= 0x4001) {
            player = objGetPlayerNo(0);
            if (player != NULL) {
                temp_t4 = D_800A6700 - arg0;
                D_800A6700 = temp_t4;
                if (temp_t4 <= 0) {
                    do {
                        /* find a free drop slot (up to 16 tries) */
                        found = 0;
                        drop = D_800A63D4;
                        var_s3 = 0x10;
                        do {
                            var_s3 -= 1;
                            if (drop->unk6 == 0) {
                                found = 1;
                            } else {
                                drop++;
                            }
                        } while ((var_s3 > 0) && (found == 0));

                        if (found != 0) {
                            ang = mathRnd(0, 0x10000);
                            radius = (f32) mathRnd(0x1E, 0x12C);
                            x = (Sinf(ang) * radius) + *(f32 *) ((u8 *) player + 0xC);
                            z = (Cosf(ang) * radius) + *(f32 *) ((u8 *) player + 0x14);
                            trackOk = trackGetHeights(x, z, 0x400, &hp_track);
                            hitOk = hitGetHeights(x, z, 0x400, &hp_hit);
                            if ((trackOk != 0) || (hitOk != 0)) {
                                drop->unkC = x;
                                drop->unk14 = z;
                                drop->unk6 = 1;
                                drop->unk28 = 0.0f;
                                drop->unk18 = mathRnd(0x40, (temp_t1 >> 0xA) + 0x60);
                                if ((trackOk != 0) && (hitOk != 0)) {
                                    trackOk = 0;
                                }
                                if (trackOk != 0) {
                                    drop->unk10 = hp_track->height;
                                    if (hp_track->unk13 == 2) {
                                        drop->unk6 = (s16) (drop->unk6 + 1);
                                    }
                                } else {
                                    drop->unk10 = hp_hit->height;
                                }
                            }
                        }

                        temp_t7 = D_800A6700 + 2;
                        D_800A6700 = temp_t7;
                        var_v0 = temp_t7;
                        if (temp_t7 >= 0) {
                            var_v0 = (temp_t7 - (temp_t1 >> 0xA)) + 0x40;
                            D_800A6700 = var_v0;
                            if (var_v0 < 0) {
                                D_800A6700 = 0;
                                var_v0 = 0;
                            }
                        }
                    } while (var_v0 <= 0);
                }
            }
        }

        dl = D_8010157C;
        D_8010157C += 2;
        dl[1] = (u32) -0x100;
        dl[0] = 0xFB000000;

        drop = D_800A63D4;
        var_s3_2 = 0;
        do {
            if (drop->unk6 != 0) {
                drop->unk28 = drop->unk28 + ((f32) arg0 * 0.175f);
                if (drop->unk28 < 4.0f) {
                    if (drop->unk6 == 1) {
                        dl = D_8010157C;
                        D_8010157C += 2;
                        dl[0] = 0xFA000000;
                        dl[1] = (u32) ((drop->unk18 & 0xFF) | ~0xFF);
                        camDoSprite((void **) &D_8010157C, &D_80101580, (void **) &D_80101584, drop, (s32) D_800A6704, 0xE, 0);
                    } else {
                        texDPTextureX((Gfx **) &D_8010157C, D_800A6708, 0xE, 0);
                        dl = D_8010157C;
                        D_8010157C += 2;
                        dl[1] = 0xC0E0FFFF;
                        dl[0] = 0xFA000000;
                        {
                            u32 addr = (u32) D_80101584 + 0x80000000;
                            dl = D_8010157C;
                            D_8010157C += 2;
                            dl[0] = (u32) ((((addr & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30;
                            dl[1] = addr;
                        }
                        dl = D_8010157C;
                        D_8010157C += 2;
                        dl[1] = (u32) &D_A5CD8;
                        dl[0] = 0x05110020;

                        vtx = D_80101584;
                        vtx->x = (s16) ((D_800A66B8 * drop->unk28) + drop->unkC);
                        vtx->y = (s16) drop->unk10;
                        vtx->z = (s16) ((D_800A66C8 * drop->unk28) + drop->unk14);
                        vtx->r = 0xFF;
                        vtx->g = 0xFF;
                        vtx->b = 0xFF;
                        vtx->a = 0xFF;
                        vtx++;
                        vtx->x = (s16) ((D_800A66BC * drop->unk28) + drop->unkC);
                        vtx->y = (s16) drop->unk10;
                        vtx->z = (s16) ((D_800A66CC * drop->unk28) + drop->unk14);
                        vtx->r = 0xFF;
                        vtx->g = 0xFF;
                        vtx->b = 0xFF;
                        vtx->a = 0xFF;
                        vtx++;
                        vtx->x = (s16) ((D_800A66C0 * drop->unk28) + drop->unkC);
                        vtx->y = (s16) drop->unk10;
                        vtx->z = (s16) ((D_800A66D0 * drop->unk28) + drop->unk14);
                        vtx->r = 0xFF;
                        vtx->g = 0xFF;
                        vtx->b = 0xFF;
                        vtx->a = 0xFF;
                        vtx++;
                        vtx->x = (s16) ((D_800A66C4 * drop->unk28) + drop->unkC);
                        vtx->y = (s16) drop->unk10;
                        vtx->z = (s16) ((D_800A66D4 * drop->unk28) + drop->unk14);
                        vtx->r = 0xFF;
                        vtx->g = 0xFF;
                        vtx->b = 0xFF;
                        vtx->a = 0xFF;
                        vtx++;
                        D_80101584 = vtx;
                    }
                } else {
                    drop->unk6 = 0;
                }
            }
            var_s3_2 += 1;
            drop++;
        } while (var_s3_2 != 0x10);

        dl = D_8010157C;
        D_8010157C += 2;
        dl[1] = 0xFFFFFFFF;
        dl[0] = 0xFA000000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005CC28.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005D458(s32 arg0) {
    s32 sp1C;
    s32 temp_t6;

    if (D_800A66FC > 0) {
        temp_t6 = D_800A66FC - arg0;
        D_800A66FC = temp_t6;
        if (temp_t6 <= 0) {
            if (D_800A66E8 >= 0x8001) {
                if (fxFadeOn(6, &D_800A66FC) == 0) {
                    setupClearScreen(&D_800A6714);
                    D_800A6784_A7384 = 0;
                }
            }
            ((void (*)(s32, void *)) amSndPlay)(6, NULL);
            D_800A66FC = 0;
        }
    } else if (D_800A66DC >= 0xC001) {
        if (D_800A66F8 > 0) {
            D_800A66F8 -= arg0;
            return;
        }
        sp1C = (s32) ((D_800A66DC * 0x258) + 0xFE3E0000) >> 0xE;
        amSndPlay(7, NULL, &D_800A66F8, &D_800A66FC);
        D_800A66FC = sp1C + 0x3C;
        D_800A66F8 = mathRnd(0x4B0, 0x5DC) - sp1C;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005D458.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005D568(s32 arg0) {
    f32 sp28;
    f32 sp24;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;

    sp28 = 1152.0f - (f32) ((s32) D_800A66DC >> 6);
    sp24 = Sinf(-0x8000 - D_8010158C->unk0);
    temp_f12 = D_8010158C->unk10;
    temp_f2 = D_8010158C->unkC - (sp28 * sp24);
    temp_f14 = D_8010158C->unk14 - (sp28 * Cosf(-0x8000 - D_8010158C->unk0));
    if (D_800A6710 != NULL) {
        amSndSetXYZ(D_800A6710, temp_f2, temp_f12, temp_f14);
        return;
    }
    amSndPlayXYZ(temp_f12, temp_f14, 4, temp_f2, temp_f12, temp_f14, 1, &D_800A6710);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005D568.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005D654(void) {
    D_80101598 = 0;
    D_8010159C = 0;
    D_801015A0 = 0;
    D_801015A4 = 0;
    /* D_800A6390 is D_800A6388.unk8 (texture header slot of the template) */
    D_800A6388.unk8 = texLoadTexture(*D_800A63CC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005D654.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005D6A4(s32 arg0, void *arg1) {
    s16 angles[2];
    f32 dir[2];
    f32 z;
    s32 smoothX;
    s32 smoothY;
    s32 smoothZ;
    s32 sumX;
    s32 sumY;
    s32 sumZ;
    s32 i;
    WeatherParticle *p;

    D_80101598 -= arg0;
    if (D_80101598 <= 0) {
        D_80101598 = mathRnd(0xB4, 0x12C);
        angles[0] = mathRnd(-0x8000, 0x7FFF);
        angles[1] = mathRnd(-0x800, -0x400);
        z = -(f32) mathRnd(0x28000, 0x58000);
        mathOneFloatPY(angles, dir);
        D_801015A8 = (s32) dir[0];
        D_801015AC = (s32) dir[1];
        D_801015B0 = (s32) z;
    }

    smoothX = D_8010159C;
    smoothY = D_801015A0;
    smoothZ = D_801015A4;
    sumX = 0;
    sumY = 0;
    sumZ = 0;
    for (i = 0; i < arg0; i++) {
        smoothX += (D_801015A8 - smoothX) >> 6;
        smoothY += (D_801015AC - smoothY) >> 6;
        smoothZ += (D_801015B0 - smoothZ) >> 6;
        sumX += smoothX + D_80101528.unkC;
        sumY += smoothY + D_80101528.unk18;
        sumZ += smoothZ + D_80101528.unk24;
    }
    D_8010159C = smoothX;
    D_801015A0 = smoothY;
    D_801015A4 = smoothZ;

    p = D_800A6384;
    for (i = 0; i < D_80101520; i++) {
        p->unk0 = (p->unk0 + (sumX >> 1)) & D_800A6388.unk18;
        p->unk4 = (p->unk4 + (sumY >> 1)) & D_800A6388.unk1C;
        p->unk8 = (p->unk8 + (sumZ >> 1)) & D_800A6388.unk20;
        p++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/weather/func_8005D6A4.s")
#endif
