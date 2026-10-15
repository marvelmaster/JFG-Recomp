#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern void *D_overlay_2_00200850;
extern u8 D_overlay_2_00203790;
extern void *refractBuffers[2];
extern s32 refractCurrentBuffer;
extern s32 refractDelay;
extern s32 refractWhichBuffer;
extern s32 refractThisObject;
extern u8 D_overlay_2_00200858[];
extern u8 D_overlay_2_00202058[];
extern u8 D_overlay_2_00203858[];
extern Gfx *D_overlay_2_00203FD8[2];
void refractFreeAll(void);
void CreateRefractTask(void);
void refractOutputAssembler(void);
void rcpInitDpNoSize(Gfx **dlist);
void objPrintObject(Gfx **arg0, MatrixS **arg1, s32 *arg2, void *arg3);
void trackGetFog(s32 fogIdx, s16 *a, s16 *b, s16 *c, u8 *d, u8 *e, u8 *f, s16 *g);
void camSetNo(s32 arg0);
void camSetView(void **arg0, void **arg1);
Object **objGetObjList(s32 *arg0, s32 *arg1);
s32 rcpFast3d(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void refractInit(void) {
    s32 width;
    s32 height;
    s32 pad;
    void *msg;
    u8 *alloc;
    u8 *aligned;

    msg = NULL;
    if (D_overlay_2_00203790 == 0) {
        refractTaskActive = 0;
        refractWhichBuffer = 0;
        refractDelay = 2;
        D_overlay_2_00200850 = NULL;
        viGetCurrentSize(&width, &height);
        alloc = D_overlay_2_00200850 = (u8 *)mmAlloc((width * height * 4) + 0x40, -1U);
        if (alloc != NULL) {
            if ((u32)alloc & 0x3F) {
                aligned = (u8 *)(((u32)alloc & ~0x3F) + 0x40);
            } else {
                aligned = alloc;
            }
            refractBuffers[0] = aligned;
            refractBuffers[1] = (u8 *)((u32)aligned + (width * height * 2));
            refractCurrentBuffer = (s32)refractBuffers[refractWhichBuffer];
            if (osRecvMesg(&refractDoneMsgQueue, &msg, 0) == 0) {
                do {
                } while (osRecvMesg(&refractDoneMsgQueue, &msg, 0) == 0);
            }
            D_overlay_2_00203790 = 1;
        } else {
            refractFreeAll();
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o2/overlay_2/refractInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void refractFreeAll(void) {
    if (D_overlay_2_00200850 != NULL) {
        mmFree(D_overlay_2_00200850);
        D_overlay_2_00200850 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o2/overlay_2/refractFreeAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00002(void) {
    refractFreeAll();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o2/overlay_2/_AutoExit00002.s")
#endif

#ifdef NON_MATCHING
/* Appends one 64-bit display list command at gfx and advances it. */
#define REFRACT_GFX(w0v, w1v) \
    do { \
        gfx->words.w0 = (u32)(w0v); \
        gfx->words.w1 = (u32)(w1v); \
        gfx++; \
    } while (0)

// decomp: m2c + cleanup, non-matching
// Builds the display list for the current refract buffer: viewport/CI setup,
// fog, then every object with behaviour 0x18 whose child has racer type 0xE6.
void CreateRefractTask(void) {
    Gfx *gfx;
    void *mtx;
    void *aux;
    Object **objs;
    Object *obj;
    Object *child;
    s32 first;
    s32 count;
    s32 width;
    s32 height;
    s32 idx;
    s32 i;
    s16 fogNear;
    s16 fogFar;
    s16 fogUnk1;
    s16 fogUnk2;
    u8 fogR;
    u8 fogG;
    u8 fogB;
    s32 fogSpan;

    objs = objGetObjList(&first, &count);
    viGetCurrentSize(&width, &height);
    idx = refractWhichBuffer;
    gfx = (Gfx *)(D_overlay_2_00200858 + idx * 0xC00);
    mtx = D_overlay_2_00202058 + idx * 0xC00;
    aux = D_overlay_2_00203858 + idx * 0x3C0;

    segSetBase(&gfx, 0, 0);
    segSetBase(&gfx, 1, (s32)refractBuffers[idx]);
    segSetBase(&gfx, 2, otherZbuf);
    rcpInitSp(&gfx);
    rcpInitDpNoSize(&gfx);

    REFRACT_GFX(0xB6000000, 1);
    REFRACT_GFX(((width - 1) & 0xFFF) | 0xFF100000, (u32)refractBuffers[idx] + 0x80000000);
    REFRACT_GFX(0xED000000,
                (((s32)((f32)(u32)width * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(u32)height * 4.0f) & 0xFFF));
    REFRACT_GFX(0xBC000002, 0);
    REFRACT_GFX(0xF7000000, 0);
    REFRACT_GFX(0xBA001402, 0x300000);
    REFRACT_GFX((((width - 1) & 0x3FF) << 14) | 0xF6000000 | (((height - 1) & 0x3FF) << 2), 0);
    REFRACT_GFX(0xE7000000, 0);
    texDPInit(&gfx);

    REFRACT_GFX(0xBC000002, 0);
    REFRACT_GFX(0xB6000000, 0x1000);
    REFRACT_GFX(0xF9000000, 0x64);
    REFRACT_GFX(0xFA000000, 0xFFFFFFFF);
    REFRACT_GFX(0xFB000000, 0xFFFFFF00);
    REFRACT_GFX(0xE7000000, 0);
    camSetNo(0);
    camSetView((void **)&gfx, (void **)&mtx);

    REFRACT_GFX(0xE7000000, 0);
    trackGetFog(0, &fogNear, &fogFar, &fogUnk1, &fogR, &fogG, &fogB, &fogUnk2);
    REFRACT_GFX(0xF8000000, ((u32)fogR << 24) | ((u32)fogG << 16) | ((u32)fogB << 8) | 0xFF);
    fogSpan = fogFar - fogNear;
    REFRACT_GFX(0xBC000008,
                ((0x1F400 / fogSpan) << 16) | ((((-(s32)fogNear) * 0x100) + 0x1F400) / fogSpan & 0xFFFF));
    sprSetTextureFilter(0);

    for (i = first; i < count; i++) {
        obj = objs[i];
        if (obj->behaviorId == 0x18) {
            child = *(Object **)((u8 *)obj->racer + 0x24);
            if (child != NULL && *(u16 *)((u8 *)child->racer + 0x2C) == 0xE6) {
                refractThisObject = 1;
                objPrintObject((Gfx **)&gfx, (MatrixS **)&mtx, (s32 *)&aux, obj);
                refractThisObject = 0;
            }
        }
    }

    REFRACT_GFX(0xBC00000A, 0);
    REFRACT_GFX(0xE9000000, 0);
    REFRACT_GFX(0xB8000000, 0);
    D_overlay_2_00203FD8[refractWhichBuffer] = gfx;
    sprSetTextureFilter(1);
}
#undef REFRACT_GFX
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o2/overlay_2/CreateRefractTask.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void refractTick() {
    /* dlist, mtxp and arg2 are not read by the asm */
    CreateRefractTask();
    rcpFast3d((s32)(D_overlay_2_00200858 + refractWhichBuffer * 0xC00),
              (s32)D_overlay_2_00203FD8[refractWhichBuffer], 4, (s32)refractBuffers[refractWhichBuffer]);
    refractWhichBuffer = refractWhichBuffer ^ 1;
    refractCurrentBuffer = (s32)refractBuffers[refractWhichBuffer];
    refractTaskActive = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o2/overlay_2/refractTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void refractOutput() {
    /* args are not read by the asm */
    refractOutputAssembler();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o2/overlay_2/refractOutput.s")
#endif
