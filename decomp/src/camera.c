#include "common.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_HEIGHT_PAL (SCREEN_HEIGHT + 44)
#define SCREEN_WIDTH_HALF (SCREEN_WIDTH / 2)
#define SCREEN_HEIGHT_HALF (SCREEN_HEIGHT / 2)
#define SCREEN_HEIGHT_HALF_PAL (SCREEN_HEIGHT_HALF + 12)

#define SCREEN_WIDTH_FLOAT ((float) (SCREEN_WIDTH))
#define SCREEN_HEIGHT_FLOAT ((float) (SCREEN_HEIGHT))
#define SCREEN_WIDTH_FLOAT_HALF ((float) SCREEN_WIDTH / 2)
#define SCREEN_HEIGHT_FLOAT_HALF ((float) SCREEN_HEIGHT / 2)

#define CAMERA_ASPECT (SCREEN_WIDTH_FLOAT / SCREEN_HEIGHT_FLOAT)
#define CAMERA_FAR 15000.0f
#define CAMERA_NEAR 10.0f
#define CAMERA_DEFAULT_FOV 60.0f
#define CAMERA_MIN_FOV 0.0f
#define CAMERA_MAX_FOV 90.0f
#define CAMERA_SCALE 1.0f

/* decomp: externs */
extern s32 D_800A2ED0;
extern u8 D_800A316C;
extern s32 D_800FA630;
extern s32 D_800FA634;
extern s8 D_800FA650;
extern u16 D_800FAA68;
extern f32 D_800FAA70[];
extern u8 D_800FAB38[];
extern f32 D_800FB078;
extern f32 D_800A3168;
extern u8 D_800A3170[];
extern u8 D_800A3174[];
extern f32 D_800A317C[];
extern u8 D_800A3178[];
extern s32 D_800FAA5C;
extern f32 D_800FAA60;
extern f32 D_800FAA64;
extern s32 D_800FB518;
extern s32 D_800A2FA4;
extern u8 D_800A2ED4[];
extern u8 D_800A2FB8[];
extern u8 cameraActorArray[];
extern void *D_800FAB30;
extern Matrix D_800FAAB0;
extern Matrix D_800FB038;
extern f32 aspectRatioFloat;
extern u8 D_800A2F04[];
extern u8 D_800FA600[];
extern u8 D_800FA658[];
extern f32 D_800A3128;
extern f32 D_800A3130;
extern f32 D_800A3134[];
void conv_mult_matrix(f32 (*)[4], void *); /* sig guess */
void mathRSMtx(s32, f32, f32, f32 (*)[4]);
void matrixID(f32 (*)[4]);
void mathScaleMtx(f32 (*)[4], f32, f32, f32);
void matrixScale(f32, f32, f32, f32 (*)[4]);
void mathSquashY(f32 (*)[4], f32);
void mathTransY(f32 (*)[4], f32);
void matrix_SCL_RPY_XYZ(ObjectTransform *, f32 (*)[4]);
void sprDPset(void **, s32, s32, s32, s32);
void camStopShakes(void);
void func_8003F66C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void mathMtxF2L(f32 (*)[4], void *);
s32 frontGet2PlayerSplit(f32 *);
s32 levelGetType(f32 *);
extern f32 D_800A313C;
extern Matrix D_800FAF78;
extern Matrix D_800FAFB8;
extern Matrix D_800FAFF8;
extern Matrix D_800FAAF0;
extern MatrixS D_800FAF38;
extern ObjectTransform D_800FA638;
extern ObjectTransform D_800A30F8;
void camSetViewport(void **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void camSetProjMtx(void **arg0, void **arg1);
void camCopyOrthoMatrix(f32 (*)[4]);
void mathMtxCatF(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
void matrix_XYZ_YPR(ObjectTransform *arg0, f32 (*arg1)[4]);
void matrix_RPY_XYZ(ObjectTransform *arg0, f32 (*arg1)[4]);

const char D_800ACC60[] = "Camera Error: Illegal mode!\n";
const char D_800ACC80[] = "Illegal CAMERA number %d\n";
const char D_800ACC9C[] = "%f\n";
const char D_800ACCA0[] = "\nCam do 2D sprite called with NULL pointer!";
const char D_800ACCCC[] = "CAM Error!! Convlist overflow.\n";

#if 0
extern s32 D_B0000578;
extern s32 D_800FB0F4; //gActiveCameraID;
extern Matrix D_800FB530; // gPerspectiveMatrixF;
extern MatrixS D_800FB5F8; // gProjectionMatrixS;
extern u16 D_800FB528; // perspNorm;
extern f32 D_800FBB38; // gCurCamFOV;
extern s8 D_800A3720; // AntiPiracyViewport = FALSE;
extern s32 D_800FB0F0; // gActiveCameraID;

void camInit(void) {
    s32 i;
    s32 j;
    u32 stat;

    // clang-format off
    // This section is highly suspicous to be undefined behaviour as we have it defined right now.
    for (i = 0; i < 5; i++) { gModelMatrixF[i] = (Matrix *) &D_80120DA0[(i << 1)]; }
    // clang-format on

    for (j = 0; j < 8; j++) {
        D_800FB0F4 = j;
        func_8003F66C(200, 200, 200, 0, 0, 180);
    }

    gCutsceneCameraActive = FALSE;
    D_800FB0F4 = 0;
    gModelMatrixStackPos = 0;
    gCameraMatrixPos = 0;
    gNumberOfViewports = 0;
    gSpriteAnimOff = FALSE;
    D_80120D18 = 0;
    gAdjustViewportHeight = 0;
    D_800A3720 = FALSE;

    WAIT_ON_IOBUSY(stat);

    // 0xB0000578 is a direct read from the ROM as opposed to RAM
    if (((D_B0000578 & 0xFFFF) & 0xFFFF) != 0x8965) {
        D_800A3720 = TRUE;
    }

    guPerspectiveF(D_800FB530, &D_800FB528, CAMERA_DEFAULT_FOV, CAMERA_ASPECT, CAMERA_NEAR, CAMERA_FAR,
                   CAMERA_SCALE);
    f32_matrix_to_s16_matrix(&D_800FB530, &D_800FB5F8);
    D_800FBB38 = CAMERA_DEFAULT_FOV;
}
#else
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camInit(s32 arg0) {
    s32 i;
    u8 next;

    D_800FA634 = 0;
    D_800FA630 = 0;
    D_800FA650 = 0;
    i = 0;
    do {
        D_800FA634 = i;
        func_8003F66C(200, 200, 200, 0, 0, 180);
        i += 1;
        *(f32 *)(cameraActorArray + D_800FA634 * 0x4C + 0x2C) = 60.0f;
    } while (i != 4);
    camStopShakes();
    if (arg0 != 0) {
        D_800A2ED0 = 0;
    }
    D_800FB078 = 60.0f;
    guPerspectiveF((f32 (*)[4])D_800FAA70, &D_800FAA68, D_800FB078, 1.3333334f, 10.0f, 15000.0f, 1.0f);
    next = (u8)((D_800A316C + 1) & 0xF);
    D_800A316C = next;
    mathMtxF2L((f32 (*)[4])D_800FAA70, (void *)(D_800FAB38 + ((next & 0xFF) << 6)));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camInit.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camUseShake(void) {
    D_800FB518 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camUseShake.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camIgnoreShake(void) {
    D_800FB518 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camIgnoreShake.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 camGetFOV(void) {
    return D_800FB078;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetFOV.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camOverrideProjScales(f32 arg0, f32 arg1) {
    D_800FAA60 = arg0;
    D_800FAA64 = arg1;
    D_800FAA5C = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camOverrideProjScales.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetFOV(f32 fov, s32 force) {
    s32 cam;
    f32 scaled;
    s32 videoMode;
    s32 splitType;
    u8 next;

    cam = D_800FA634;
    *(f32 *)(cameraActorArray + cam * 0x4C + 0x2C) = fov;
    scaled = fov;
    if (D_800A3174[cam] != 0) {
        scaled *= 1.0f / ((0.25f * (D_800A317C[cam] - 1.0f)) + 1.0f);
    }
    if ((scaled > 0.0f) && (scaled < 90.0f)) {
        if ((force != 0) || (scaled != D_800FB078)) {
            D_800FB078 = scaled;
            guPerspectiveF((f32 (*)[4])D_800FAA70, &D_800FAA68, D_800FB078, 1.3333334f, 10.0f, 15000.0f, 1.0f);
            D_800A3168 = D_800FAA70[0] / 1.817394f;
            videoMode = viGetVideoMode();
            if (D_800FAA5C != 0) {
                D_800FAA70[0] *= D_800FAA60;
                D_800FAA5C = 0;
                D_800FAA70[5] = D_800FAA70[5] * D_800FAA64;
            } else if (videoMode & 1) {
                splitType = levelGetType(D_800FAA70);
                if ((splitType == 1) || (splitType == 2)) {
                    D_800FAA70[5] = D_800FAA70[5] * 1.33f;
                } else {
                    D_800FAA70[0] *= 0.75f;
                }
            } else if ((D_800FA630 == 1) && (frontGet2PlayerSplit(D_800FAA70) != 0)) {
                D_800FAA70[5] = D_800FAA70[5] * 0.75f;
                D_800FAA70[0] *= 0.75f;
            }
            next = (u8)((D_800A316C + 1) & 0xF);
            D_800A316C = next;
            mathMtxF2L((f32 (*)[4])D_800FAA70, (void *)(D_800FAB38 + ((next & 0xFF) << 6)));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetFOV.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 camDistance(f32 x, f32 y, f32 z) {
    u8 *cam;
    f32 dx;
    f32 dy;
    f32 dz;

    cam = cameraActorArray + D_800FA634 * 0x4C;
    dx = x - *(f32 *)(cam + 0xC);
    dy = y - *(f32 *)(cam + 0x10);
    dz = z - *(f32 *)(cam + 0x14);
    return sqrtf((dx * dx) + (dy * dy) + (dz * dz));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camDistance.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8003F66C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 *cam;

    cam = cameraActorArray + D_800FA634 * 0x4C;
    *(s16 *)(cam + 0x4) = (s16)(arg3 * 0xB6);
    *(s16 *)(cam + 0x2) = (s16)(arg4 * 0xB6);
    *(s16 *)(cam + 0x0) = (s16)(arg5 * 0xB6);
    *(s16 *)(cam + 0x4A) = 0;
    *(f32 *)(cam + 0xC) = (f32)arg0;
    *(f32 *)(cam + 0x10) = (f32)arg1;
    *(f32 *)(cam + 0x14) = (f32)arg2;
    *(f32 *)(cam + 0x18) = (f32)arg0;
    *(f32 *)(cam + 0x1C) = (f32)arg1;
    *(f32 *)(cam + 0x20) = (f32)arg2;
    *(u8 *)(cam + 0x3C) = 0;
    *(f32 *)(cam + 0x30) = 0.0f;
    *(f32 *)(cam + 0x34) = 0.0f;
    *(f32 *)(cam + 0x38) = 0.0f;
    *(f32 *)(cam + 0x24) = 128.0f;
    *(f32 *)(cam + 0x28) = 32.0f;
    *(s16 *)(cam + 0x3E) = -1;
    *(f32 *)(cam + 0x40) = 0.0f;
    *(u8 *)(cam + 0x3D) = D_800A3170[D_800FA634];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/func_8003F66C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camGetMode(void) {
    return D_800FA630;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camSetMode(s32 arg0) {
    s32 *mode = &D_800FA630;
    s32 *no = &D_800FA634;
    s32 cur;

    if ((arg0 < 0) || (arg0 >= 4)) {
        arg0 = 0;
    }
    cur = *no;
    *mode = arg0;
    if (arg0 < cur) {
        *no = 0;
    }
    return arg0 + 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camGetNo(void) {
    return D_800FA634;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetNo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetNo(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 4)) {
        arg0 = 0;
    }
    D_800FA634 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetNo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 camGetWaterLine(s32 arg0) {
    return D_800A3178[arg0];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetWaterLine.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetWaterLine(s32 arg0, s32 arg1) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        D_800A3178[arg0] = arg1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetWaterLine.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camUserViewTick(void) {
    u8 *view;
    u8 *dst;
    s32 i;
    s32 flags;
    s32 fld0;
    s32 fld2;
    s32 fld8;
    s32 fldA;

    D_800A2FA4 = 1 - D_800A2FA4;
    view = D_800A2ED4;
    for (i = 0; i != 4; i++, view += 0x34) {
        flags = *(s32 *)(view + 0x30);
        if (flags & 4) {
            flags &= ~1;
        } else if (flags & 2) {
            flags |= 1;
        }
        flags &= ~6;
        *(s32 *)(view + 0x30) = flags;
        if (flags & 1) {
            if (!(flags & 8)) {
                fld8 = (*(s32 *)(view + 0x0) * 4) + ((*(s32 *)(view + 0x8) - *(s32 *)(view + 0x0) + 1) * 2);
            } else {
                fld8 = *(s32 *)(view + 0x10) * 4;
            }
            if (!(flags & 0x10)) {
                fldA = (*(s32 *)(view + 0x4) * 4) + ((*(s32 *)(view + 0xC) - *(s32 *)(view + 0x4) + 1) * 2);
            } else {
                fldA = *(s32 *)(view + 0x14) * 4;
            }
            if (!(flags & 0x20)) {
                fld0 = (*(s32 *)(view + 0x8) - *(s32 *)(view + 0x0) + 1) * 2;
            } else {
                fld0 = *(s32 *)(view + 0x18) * 2;
            }
            if (!(flags & 0x40)) {
                fld2 = (*(s32 *)(view + 0xC) - *(s32 *)(view + 0x4) + 1) * 2;
            } else {
                fld2 = *(s32 *)(view + 0x1C) * 2;
            }
            dst = D_800A2FB8 + ((i + (D_800A2FA4 * 5) + 0xA) * 0x10);
            *(s16 *)(dst + 0x8) = (s16)fld8;
            *(s16 *)(dst + 0xA) = (s16)fldA;
            *(s16 *)(dst + 0x0) = (s16)fld0;
            *(s16 *)(dst + 0x2) = (s16)fld2;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camUserViewTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camEnableUserView(s32 arg0, s32 arg1) {
    u8 *view = D_800A2ED4 + arg0 * 0x34;

    if (arg1 != 0) {
        *(s32 *)(view + 0x30) |= 1;
    } else {
        *(s32 *)(view + 0x30) |= 2;
    }
    *(s32 *)(view + 0x30) &= ~4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camEnableUserView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camDisableUserView(s32 arg0, s32 arg1) {
    u8 *view = D_800A2ED4 + arg0 * 0x34;

    if (arg1 != 0) {
        *(s32 *)(view + 0x30) &= ~1;
    } else {
        *(s32 *)(view + 0x30) |= 4;
    }
    *(s32 *)(view + 0x30) &= ~2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camDisableUserView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camIsUserView(s32 arg0) {
    return *(s32 *)(D_800A2ED4 + arg0 * 0x34 + 0x30) & 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camIsUserView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetUserView(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 width;
    s32 height;
    s32 tmp;
    u8 *view;

    viGetCurrentSize(&width, &height);
    if (arg3 < arg1) {
        tmp = arg1;
        arg1 = arg3;
        arg3 = tmp;
    }
    if (arg4 < arg2) {
        tmp = arg2;
        arg2 = arg4;
        arg4 = tmp;
    }
    view = D_800A2ED4 + arg0 * 0x34;
    if (((u32)arg1 < (u32)width) && (arg3 >= 0) && ((u32)arg2 < (u32)height) && (arg4 >= 0)) {
        *(s32 *)(view + 0x20) = (arg1 < 0) ? 0 : arg1;
        *(s32 *)(view + 0x24) = (arg2 < 0) ? 0 : arg2;
        *(s32 *)(view + 0x28) = (arg3 < width) ? arg3 : width - 1;
        *(s32 *)(view + 0x2C) = (arg4 < height) ? arg4 : height - 1;
    } else {
        *(s32 *)(view + 0x20) = 0;
        *(s32 *)(view + 0x24) = 0;
        *(s32 *)(view + 0x28) = 0;
        *(s32 *)(view + 0x2C) = 0;
    }
    *(s32 *)(view + 0x0) = arg1;
    *(s32 *)(view + 0x4) = arg2;
    *(s32 *)(view + 0x8) = arg3;
    *(s32 *)(view + 0xC) = arg4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetUserView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetUserViewSpecial(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *view = D_800A2ED4 + arg0 * 0x34;

    if (arg1 != 0x8000) {
        *(s32 *)(view + 0x10) = arg1;
        *(s32 *)(view + 0x30) |= 8;
    } else {
        *(s32 *)(view + 0x30) &= ~8;
    }
    if (arg2 != 0x8000) {
        *(s32 *)(view + 0x14) = arg2;
        *(s32 *)(view + 0x30) |= 0x10;
    } else {
        *(s32 *)(view + 0x30) &= ~0x10;
    }
    if (arg3 != 0x8000) {
        *(s32 *)(view + 0x18) = arg3;
        *(s32 *)(view + 0x30) |= 0x20;
    } else {
        *(s32 *)(view + 0x30) &= ~0x20;
    }
    if (arg4 != 0x8000) {
        *(s32 *)(view + 0x1C) = arg4;
        *(s32 *)(view + 0x30) |= 0x40;
    } else {
        *(s32 *)(view + 0x30) &= ~0x40;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetUserViewSpecial.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camGetVisibleUserView(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    u8 *view = D_800A2ED4 + arg0 * 0x34;

    *arg1 = *(s32 *)(view + 0x20);
    *arg2 = *(s32 *)(view + 0x24);
    *arg3 = *(s32 *)(view + 0x28);
    *arg4 = *(s32 *)(view + 0x2C);
    return (*arg1 | *arg2 | *arg3 | *arg4) != 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetVisibleUserView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camGetUserView(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    u8 *view = D_800A2ED4 + arg0 * 0x34;

    *arg1 = *(s32 *)(view + 0x0);
    *arg2 = *(s32 *)(view + 0x4);
    *arg3 = *(s32 *)(view + 0x8);
    *arg4 = *(s32 *)(view + 0xC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetUserView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camGetWindowLimits(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    u8 *view = D_800A2ED4 + arg1 * 0x34;
    s32 videoMode;
    s32 halfW;
    s32 halfH;

    if (*(s32 *)(view + 0x30) & 1) {
        *arg2 = *(s32 *)(view + 0x20);
        *arg3 = *(s32 *)(view + 0x24);
        *arg4 = *(s32 *)(view + 0x28);
        *arg5 = *(s32 *)(view + 0x2C);
        return;
    }
    viGetCurrentSize(arg4, arg5);
    videoMode = viGetVideoMode();
    halfW = (u32)*arg4 >> 1;
    halfH = (u32)*arg5 >> 1;
    *arg2 = 0;
    *arg3 = 0;
    if (arg0 == 1) {
        if ((videoMode & 1) || (frontGet2PlayerSplit((f32 *)arg0) != 0)) {
            if (arg1 == 0) {
                *arg4 = halfW;
            } else {
                *arg2 = halfW;
            }
        } else {
            if (arg1 == 0) {
                *arg5 = halfH;
            } else {
                *arg3 = halfH;
            }
        }
    } else if ((arg0 == 2) || (arg0 == 3)) {
        if (arg1 & 1) {
            *arg2 = halfW;
        } else {
            *arg4 = halfW;
        }
        if (arg1 & 2) {
            *arg3 = halfH;
        } else {
            *arg5 = halfH;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetWindowLimits.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetView(void **arg0, void **arg1) {
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;
    s32 vpW;
    s32 vpH;
    s32 videoMode;
    f32 scale;
    Gfx *dl;

    camGetWindowLimits(D_800FA630, D_800FA634, &ulx, &uly, &lrx, &lry);
    videoMode = viGetVideoMode();
    if ((videoMode == 2) || (videoMode == 3)) {
        vpW = 0xE0;
        vpH = 0xA8;
    } else {
        vpW = 0xA0;
        vpH = 0x78;
    }
    if (D_800FA630 >= 2) {
        vpW = (u32)vpW >> 1;
        vpH = (u32)vpH >> 1;
    }
    if (D_800A3174[D_800FA634] != 0) {
        scale = 1.0f + (0.25f * (D_800A317C[D_800FA634] - 1.0f));
        vpW = (s32)((f32)vpW * scale);
        vpH = (s32)((f32)vpH * scale);

        dl = (Gfx *)*arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0xBC000404;
        dl->words.w1 = 1;

        dl = (Gfx *)*arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0xBC000C04;
        dl->words.w1 = 1;

        dl = (Gfx *)*arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0xBC001404;
        dl->words.w1 = 0xFFFF;

        dl = (Gfx *)*arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0xBC001C04;
        dl->words.w1 = 0xFFFF;
    }

    dl = (Gfx *)*arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = ((((s32)((f32)ulx * 4.0f)) & 0xFFF) << 12) | 0xED000000 | (((s32)((f32)uly * 4.0f)) & 0xFFF);
    dl->words.w1 = ((((s32)((f32)lrx * 4.0f)) & 0xFFF) << 12) | (((s32)((f32)lry * 4.0f)) & 0xFFF);

    camSetViewport(arg0, vpW, vpH, ((u32)(lrx + ulx)) >> 1, ((u32)(lry + uly)) >> 1);
    if (arg1 != NULL) {
        camSetProjMtx(arg0, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetScissor(Gfx **dlist) {
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;
    Gfx *dl;

    camGetWindowLimits(D_800FA630, D_800FA634, &ulx, &uly, &lrx, &lry);
    dl = *dlist;
    *dlist = dl + 1;
    dl->words.w0 = ((((s32)((f32)ulx * 4.0f)) & 0xFFF) << 12) | 0xED000000 | (((s32)((f32)uly * 4.0f)) & 0xFFF);
    dl->words.w1 = ((((s32)((f32)lrx * 4.0f)) & 0xFFF) << 12) | (((s32)((f32)lry * 4.0f)) & 0xFFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetScissor.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camGetPlayerProjMtx(s32 arg0, f32 (*arg1)[4]) {
    mathMtxCatF(D_800FAF78, (f32 (*)[4])D_800FAA70, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetPlayerProjMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetProjMtx(void **arg0, void **arg1) {
    u8 *cam = cameraActorArray + D_800FA634 * 0x4C;
    Gfx *dl;

    if ((D_800FB078 != *(f32 *)(cam + 0x2C)) || (D_800A3174[D_800FA634] != 0)) {
        camSetFOV(*(f32 *)(cam + 0x2C), 0);
    }
    if (arg0 != NULL) {
        dl = (Gfx *)*arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0xB4000000;
        dl->words.w1 = D_800FAA68;
    }

    D_800FA638.y_rotation = (s16)(*(s16 *)(cam + 0x0) + 0x8000);
    D_800FA638.x_rotation = (s16)(*(s16 *)(cam + 0x2) + *(s16 *)(cam + 0x4A));
    D_800FA638.z_rotation = *(s16 *)(cam + 0x4);
    D_800FA638.x_position = -*(f32 *)(cam + 0xC);
    D_800FA638.y_position = -*(f32 *)(cam + 0x10);
    D_800FA638.z_position = -*(f32 *)(cam + 0x14);
    if (D_800FB518 != 0) {
        D_800FA638.x_position -= *(f32 *)(cam + 0x30);
        D_800FA638.y_position -= *(f32 *)(cam + 0x34);
        D_800FA638.z_position -= *(f32 *)(cam + 0x38);
    }
    matrix_XYZ_YPR(&D_800FA638, D_800FAF78);
    mathMtxCatF(D_800FAF78, (f32 (*)[4])D_800FAA70, D_800FAAF0);
    if (arg0 != NULL) {
        mathMtxF2L(D_800FAAF0, *arg1);
        dl = (Gfx *)*arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0x01000040;
        dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
        *arg1 = (void *)((u8 *)*arg1 + 0x40);
    }

    D_800FA638.y_rotation = (s16)(-0x8000 - *(s16 *)(cam + 0x0));
    D_800FA638.x_rotation = (s16)-(*(s16 *)(cam + 0x2) + *(s16 *)(cam + 0x4A));
    D_800FA638.z_rotation = (s16)-*(s16 *)(cam + 0x4);
    D_800FA638.x_position = *(f32 *)(cam + 0xC);
    D_800FA638.y_position = *(f32 *)(cam + 0x10);
    D_800FA638.z_position = *(f32 *)(cam + 0x14);
    if (D_800FB518 != 0) {
        D_800FA638.x_position += *(f32 *)(cam + 0x30);
        D_800FA638.y_position += *(f32 *)(cam + 0x34);
        D_800FA638.z_position += *(f32 *)(cam + 0x38);
    }
    matrix_RPY_XYZ(&D_800FA638, D_800FAFB8);
    mathMtxF2L(D_800FAFB8, D_800FAF38);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetProjMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camOrthoYAspect(f32 arg0) {
    D_800A313C = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camOrthoYAspect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camStandardOrtho(void **arg0, void **arg1) {
    s32 width;
    s32 height;
    u8 *ortho;
    Gfx *dl;

    viGetCurrentSize(&width, &height);
    ortho = D_800A2FB8 + D_800FA634 * 0x10;
    *(s16 *)(ortho + 0x50) = (s16)(width * 2);
    *(s16 *)(ortho + 0x52) = (s16)(width * 2);
    *(s16 *)(ortho + 0x58) = (s16)(width * 2);
    *(s16 *)(ortho + 0x5A) = (s16)(height * 2);

    dl = (Gfx *)*arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x03800010;
    dl->words.w1 = (s32)((u32)ortho + 0x80000050);
    camCopyOrthoMatrix((f32 (*)[4])D_800FAAF0);
    mathMtxF2L(D_800FAAF0, *arg1);
    dl = (Gfx *)*arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x01000040;
    dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
    *arg1 = (void *)((u8 *)*arg1 + 0x40);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camStandardOrtho.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camStandardPersp(void **arg0, void **arg1) {
    Gfx *dl;

    dl = (Gfx *)*arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0xB4000000;
    dl->words.w1 = D_800FAA68;
    matrix_XYZ_YPR(&D_800A30F8, D_800FAFF8);
    mathMtxCatF(D_800FAFF8, (f32 (*)[4])D_800FAA70, D_800FAAF0);
    mathMtxF2L(D_800FAAF0, *arg1);
    dl = (Gfx *)*arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x01000040;
    dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
    *arg1 = (void *)((u8 *)*arg1 + 0x40);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camStandardPersp.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetViewport(void **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Gfx *dl;
    u8 *var;

    if (!(*(s32 *)(D_800A2ED4 + D_800FA634 * 0x34 + 0x30) & 1)) {
        var = D_800A2FB8 + D_800FA634 * 0x10;
        *(s16 *)(var + 0x8) = (s16)(arg3 * 4);
        *(s16 *)(var + 0xA) = (s16)(arg4 * 4);
        *(s16 *)(var + 0x0) = (s16)(arg1 * 4);
        *(s16 *)(var + 0x2) = (s16)(arg2 * 4);
    } else {
        var = D_800A2FB8 + (D_800FA634 + D_800A2FA4 * 5 + 0xA) * 0x10;
    }
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x03800010;
    dl->words.w1 = (s32)((u32)var + 0x80000000);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetViewport.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camResetView(void **arg0) {
    Gfx *dl;
    s32 width;
    s32 height;
    s32 hm1;
    f32 fh;
    u32 halfW;
    u32 halfH;

    D_800FA634 = 4;
    viGetCurrentSize(&width, &height);
    if (!(*(s32 *)(D_800A2ED4 + D_800FA634 * 0x34 + 0x30) & 1)) {
        dl = *arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0xED000000;
        hm1 = height - 1;
        fh = (f32)hm1;
        if (hm1 < 0) {
            fh += 4294967296.0f;
        }
        dl->words.w1 = (s32)((((s32)((f32)(width - 1) * 4.0f) & 0xFFF) << 0xC) | ((s32)(fh * 4.0f) & 0xFFF));
        halfW = (u32)width >> 1;
        halfH = (u32)height >> 1;
        camSetViewport(arg0, (s32)halfW, (s32)halfH, (s32)halfW, (s32)halfH);
    } else {
        camSetScissor((Gfx **)arg0);
        camSetViewport(arg0, 0, 0, 0, 0);
    }
    D_800FA634 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camResetView.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camOffsetZero(s32 arg0, s32 arg1) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camOffsetZero.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camDoSprite(void **arg0, void **arg1, void **arg2, void *arg3, s32 arg4, s32 arg5, u8 arg6) {
    u8 *spr = (u8 *)arg3;
    u8 *vtx;
    Gfx *dl;
    f32 scaleX;
    f32 scaleY;
    s32 angle;
    s32 flags;

    vtx = (u8 *)*arg2;
    *(s16 *)(vtx + 0x0) = (s16)*(f32 *)(spr + 0xC);
    *(s16 *)(vtx + 0x2) = (s16)*(f32 *)(spr + 0x10);
    vtx[0x6] = 0xFF;
    vtx[0x7] = 0xFF;
    vtx[0x8] = 0xFF;
    vtx[0x9] = 0xFF;
    *(s16 *)(vtx + 0x4) = (s16)(s32)*(f32 *)(spr + 0x14);
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x04000000 | ((((((u32)vtx + 0x80000000U) & 6U) | 8U) & 0xFFU) << 0x10) | 0x12;
    dl->words.w1 = (s32)((u32)vtx + 0x80000000U);
    *arg2 = (void *)(vtx + 0xA);

    angle = *(s32 *)(cameraActorArray + 4 + D_800FA634 * 0x4C) + *(s16 *)(spr + 0x4);
    scaleX = *(f32 *)(spr + 0x8) * D_800A3168;
    scaleY = aspectRatioFloat;
    if (viGetVideoMode() & 1) {
        scaleX *= 0.75f;
        scaleY *= 1.3334f;
    }
    mathRSMtx(angle, scaleX, scaleY, D_800FAAB0);
    if (arg5 & 0x20000000) {
        matrixID(D_800FAFF8);
        D_800FAFF8[1][1] = -1.0f;
        mathMtxCatF(D_800FAAB0, D_800FAFF8, D_800FAAB0);
    }
    mathMtxF2L(D_800FAAB0, *arg1);
    D_800FAB30 = *arg1;
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x01020040;
    dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
    *arg1 = (void *)((u8 *)*arg1 + 0x40);
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w1 = 1;
    dl->words.w0 = 0xBC000002;
    flags = arg5 & ~1;
    if (flags & 4) {
        flags |= 1;
    }
    sprDPset(arg0, arg4, flags & 0xF, *(s32 *)(spr + 0x28), (s32)arg6);
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0xBC00000A;
    dl->words.w1 = 0;
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0xBC000002;
    dl->words.w1 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camDoSprite.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camDoSpriteDirect(void **arg0, void **arg1, void **arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, f32 arg8, s32 arg9, s32 arg10, u8 arg11) {
    u8 *vtx;
    Gfx *dl;
    f32 scaleX;
    f32 scaleY;
    s32 angle;
    s32 flags;

    vtx = (u8 *)*arg2;
    *(s16 *)(vtx + 0x0) = arg4;
    *(s16 *)(vtx + 0x2) = arg5;
    vtx[0x6] = 0xFF;
    vtx[0x7] = 0xFF;
    vtx[0x8] = 0xFF;
    vtx[0x9] = 0xFF;
    *(s16 *)(vtx + 0x4) = arg6;
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x04000000 | ((((((u32)vtx + 0x80000000U) & 6U) | 8U) & 0xFFU) << 0x10) | 0x12;
    dl->words.w1 = (s32)((u32)vtx + 0x80000000U);
    *arg2 = (void *)(vtx + 0xA);

    scaleY = aspectRatioFloat;
    angle = *(s32 *)(cameraActorArray + 4 + D_800FA634 * 0x4C) + arg7;
    arg8 *= D_800A3168;
    scaleX = arg8;
    if (viGetVideoMode() & 1) {
        scaleX *= 0.75f;
        scaleY *= 1.3334f;
    }
    mathRSMtx(angle, scaleX, scaleY, D_800FAAB0);
    if (arg10 & 0x20000000) {
        matrixID(D_800FAFF8);
        D_800FAFF8[1][1] = -1.0f;
        mathMtxCatF(D_800FAAB0, D_800FAFF8, D_800FAAB0);
    }
    mathMtxF2L(D_800FAAB0, *arg1);
    D_800FAB30 = *arg1;
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x01020040;
    dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
    *arg1 = (void *)((u8 *)*arg1 + 0x40);
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w1 = 1;
    dl->words.w0 = 0xBC000002;
    flags = arg10 & ~1;
    if (flags & 4) {
        flags |= 1;
    }
    sprDPset(arg0, arg3, flags & 0xF, arg9, (s32)arg11);
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0xBC00000A;
    dl->words.w1 = 0;
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0xBC000002;
    dl->words.w1 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camDoSpriteDirect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camDo2DSprite(void **arg0, void **arg1, void **arg2, void *arg3, s32 arg4, s32 arg5, u8 arg6) {
    u8 *spr = (u8 *)arg3;
    u8 *vtx;
    Gfx *dl;
    Matrix sc;
    Matrix rot;
    f32 s;

    if (arg4 != 0) {
        vtx = (u8 *)*arg2;
        *(s16 *)(vtx + 0x0) = (s16)(s32)*(f32 *)(spr + 0xC);
        *(s16 *)(vtx + 0x2) = (s16)(s32)*(f32 *)(spr + 0x10);
        vtx[0x6] = 0xFF;
        vtx[0x7] = 0xFF;
        vtx[0x8] = 0xFF;
        vtx[0x9] = 0xFF;
        *(s16 *)(vtx + 0x4) = (s16)(s32)*(f32 *)(spr + 0x14);
        dl = *arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0x04000000 | ((((((u32)vtx + 0x80000000U) & 6U) | 8U) & 0xFFU) << 0x10) | 0x12;
        dl->words.w1 = (s32)((u32)vtx + 0x80000000U);
        *arg2 = (void *)(vtx + 0xA);

        D_800FA638.y_rotation = -*(s16 *)(spr + 0x0);
        D_800FA638.x_rotation = -*(s16 *)(spr + 0x2);
        D_800FA638.x_position = 0.0f;
        D_800FA638.z_rotation = (s16)(*(s32 *)(cameraActorArray + 4 + D_800FA634 * 0x4C) + *(s16 *)(spr + 0x4));
        D_800FA638.y_position = 0.0f;
        D_800FA638.z_position = 0.0f;

        s = *(f32 *)(spr + 0x8);
        if (D_800FA650 != 0) {
            mathScaleMtx(sc, s, s, 1.0f);
            mathRSMtx(0, 1.0f, aspectRatioFloat, rot);
            mathMtxCatF(rot, sc, D_800FAFF8);
        } else {
            mathScaleMtx(D_800FAFF8, s, s, 1.0f);
        }
        matrix_XYZ_YPR(&D_800FA638, rot);
        mathMtxCatF(D_800FAFF8, rot, D_800FAAB0);
        mathMtxF2L(D_800FAAB0, *arg1);
        D_800FAB30 = *arg1;
        dl = *arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0x01020040;
        dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
        *arg1 = (void *)((u8 *)*arg1 + 0x40);
        dl = *arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w1 = 1;
        dl->words.w0 = 0xBC000002;
        sprDPset(arg0, arg4, arg5, *(s32 *)(spr + 0x28), (s32)arg6);
        dl = *arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0xBC00000A;
        dl->words.w1 = 0;
        dl = *arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w1 = 0;
        dl->words.w0 = 0xBC000002;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camDo2DSprite.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camPushFloatModelMtx(void **arg0, void **arg1, f32 (*arg2)[4]) {
    Gfx *dl;
    s32 i;

    for (i = 0; i < 16; i++) {
        ((f32 *)D_800FAAB0)[i] = ((f32 *)arg2)[i];
    }
    mathMtxCatF(arg2, D_800FAAF0, D_800FB038);
    mathMtxF2L(D_800FB038, *arg1);
    D_800FAB30 = *arg1;
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x01010040;
    dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
    *arg1 = (void *)((u8 *)*arg1 + 0x40);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camPushFloatModelMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camPushMuzzleMtx(void **arg0, void **arg1, f32 *arg2, f32 (*arg3)[4]) {
    Gfx *dl;
    Matrix tmp;
    f32 ox;
    f32 oy;
    f32 oz;
    s32 i;

    D_800FAAB0[3][0] = 0.0f;
    D_800FAAB0[3][1] = 0.0f;
    D_800FAAB0[3][2] = 0.0f;
    mathMtxCatF(arg3, D_800FAAB0, tmp);
    for (i = 0; i < 16; i++) {
        ((f32 *)D_800FAAB0)[i] = ((f32 *)tmp)[i];
    }
    mathMtxXFMF(D_800FAAB0, arg2[0], arg2[1], arg2[2], &ox, &oy, &oz);
    D_800FAAB0[3][0] = arg2[0];
    D_800FAAB0[3][1] = arg2[1];
    D_800FAAB0[3][2] = arg2[2];
    mathMtxCatF(D_800FAAB0, D_800FAAF0, D_800FB038);
    mathMtxF2L(D_800FB038, *arg1);
    D_800FAB30 = *arg1;
    dl = *arg0;
    *arg0 = (void *)(dl + 1);
    dl->words.w0 = 0x01010040;
    dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
    *arg1 = (void *)((u8 *)*arg1 + 0x40);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camPushMuzzleMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camScaleModelMtx(void **arg0, void **arg1, f32 arg2) {
    Gfx *dl;

    if (arg2 != 1.0f) {
        matrixScale(arg2, arg2, arg2, D_800FAAB0);
        mathMtxCatF(D_800FAAB0, D_800FAAF0, D_800FB038);
        mathMtxF2L(D_800FB038, *arg1);
        D_800FAB30 = *arg1;
        dl = *arg0;
        *arg0 = (void *)(dl + 1);
        dl->words.w0 = 0x01010040;
        dl->words.w1 = (s32)((u32)*arg1 + 0x80000000);
        *arg1 = (void *)((u8 *)*arg1 + 0x40);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camScaleModelMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camPushModelMtx(Gfx **dList, MatrixS **mtx, ObjectTransform *trans, f32 scale, f32 scaleY) {
    Gfx *dl;

    matrix_SCL_RPY_XYZ(trans, D_800FAAB0);
    if (scaleY != 0.0f) {
        mathTransY(D_800FAAB0, scaleY);
    }
    if (scale != 1.0f) {
        mathSquashY(D_800FAAB0, scale);
    }
    mathMtxCatF(D_800FAAB0, D_800FAAF0, D_800FB038);
    mathMtxF2L(D_800FB038, *mtx);
    D_800FAB30 = *mtx;
    dl = *dList;
    *dList = dl + 1;
    dl->words.w0 = 0x01010040;
    dl->words.w1 = (s32)((u32)*mtx + 0x80000000);
    *mtx = (MatrixS *)((u8 *)*mtx + 0x40);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camPushModelMtx.s")
#endif

void camRestoreModelMtx(Gfx **dlist) {
    gDkrInsertMatrix((*dlist)++, G_MWO_MATRIX_XX_XY_I, G_MTX_DKR_INDEX_0);
}

void camPopModelMtx(Gfx **dlist) {
    gDkrInsertMatrix((*dlist)++, G_MWO_MATRIX_XX_XY_I, G_MTX_DKR_INDEX_0);
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *camGetPtr(void) {
    return cameraActorArray + D_800FA634 * 0x4C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetPtr.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *camGetListPtr(void) {
    return cameraActorArray;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetListPtr.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 (*camGetInvProjMtx(void))[4] {
    return D_800FAFB8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetInvProjMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *camGetProjOrgMtx(void) {
    return D_800FAB38 + (D_800A316C << 6);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetProjOrgMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 (*camGetProjectionMtx(void))[4] {
    return D_800FAAF0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetProjectionMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 (*camGetRotationMtx(void))[4] {
    return D_800FAF78;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetRotationMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camProjectPoint(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, u8 arg5) {
    s32 var_v1;
    u8 *var_v0;
    s16 *ent;
    f32 temp_f0;

    var_v1 = 0;
    if (arg5 != 0) {
        mathMtxXFMF(D_800FAF78, arg0, arg1, arg2, &arg0, &arg1, &arg2);
    }
    temp_f0 = -(D_800FAA70[11] * arg2);
    if (temp_f0 < -2.0f) {
        var_v0 = D_800A2FB8 + (D_800FA634 * 0x10);
        if (*(s32 *) (D_800A2F04 + (D_800FA634 * 0x34)) & 1) {
            var_v0 += ((D_800A2FA4 * 5) + 0xA) * 0x10;
        }
        ent = (s16 *) var_v0;
        var_v1 = 1;
        *arg3 = (f32) (ent[4] >> 2) - ((D_800FAA70[0] * arg0 * (f32) (ent[0] >> 2)) / temp_f0);
        *arg4 = (f32) (ent[5] >> 2) + ((D_800FAA70[5] * arg1 * (f32) (ent[1] >> 2)) / temp_f0);
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camProjectPoint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camReversePoint(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, u8 arg5) {
    s16 *ent;
    f32 temp_f0;
    f32 temp_f4;

    ent = (s16 *) (D_800A2FB8 + (D_800FA634 * 0x10));
    temp_f0 = D_800FAA70[11] * (*arg4 * D_800FAA70[10]);
    temp_f4 = (f32) (ent[5] >> 2);
    *arg2 = ((((f32) (ent[4] >> 2)) - arg0) * temp_f0) / (D_800FAA70[0] * (f32) (ent[0] >> 2));
    *arg3 = (((arg1 - temp_f4) * temp_f0) / (D_800FAA70[5] * (f32) (ent[1] >> 2)));
    if (arg5 != 0) {
        mathMtxXFMF(D_800FAFB8, *arg2, *arg3, *arg4, arg2, arg3, arg4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camReversePoint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 camGetProjZ(f32 arg0, f32 arg1, f32 arg2) {
    f32 *p2 = &arg2;

    return D_800FAF78[3][2] + ((arg0 * D_800FAF78[0][2]) + (arg1 * D_800FAF78[1][2]) + (*p2 * D_800FAF78[2][2]));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camGetProjZ.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camCopyOrthoMatrix(f32 (*arg0)[4]) {
    s32 width;
    s32 height;
    s32 i;

    viGetCurrentSize(&width, &height);
    arg0[0][0] = D_800A3128;
    arg0[0][1] = D_800A3128;
    arg0[0][2] = D_800A3130;
    for (i = 0; i < 12; i++) {
        ((f32 *) arg0)[3 + i] = D_800A3134[i];
    }
    arg0[3][3] = (f32) ((u32) width >> 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camCopyOrthoMatrix.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camStartShake(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s16 *shake;

    if ((arg0 >= 0) && (arg0 < 4)) {
        shake = (s16 *) (D_800FA600 + arg0 * 0xC);
        shake[0] = (s16) (s32) (arg1 * 60.0f);
        shake[3] = 0;
        *(s32 *) &shake[4] = arg4;
        shake[1] = (s16) (shake[0] + (s32) (arg2 * 60.0f));
        shake[2] = (s16) (shake[1] + (s32) (arg3 * 60.0f));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camStartShake.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camStopShakes(void) {
    s32 i;
    u8 *cam = cameraActorArray;
    u8 *shake = D_800FA600;

    D_800FB518 = 0;
    i = 3;
    do { /* asm: bnez delay-slot loop, runs 4 times (count 3..0) */
        *(f32 *) (cam + 0x30) = 0.0f;
        *(f32 *) (cam + 0x34) = 0.0f;
        *(f32 *) (cam + 0x38) = 0.0f;
        *(s32 *) (shake + 8) = 0;
        cam += 0x4C;
        shake += 0xC;
    } while (i-- != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camStopShakes.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camScreenShake(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 i;
    u8 *cam;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 amount;

    if (D_800FA630 >= 0) {
        cam = cameraActorArray;
        for (i = 0; i <= D_800FA630; i++) {
            dx = arg0 - *(f32 *) (cam + 0xC);
            dy = arg1 - *(f32 *) (cam + 0x10);
            dz = arg2 - *(f32 *) (cam + 0x14);
            dist = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
            if (dist < arg3) {
                amount = ((arg3 - dist) * arg4) / arg3;
                if (*(f32 *) (cam + 0x34) < amount) {
                    *(f32 *) (cam + 0x34) = amount;
                }
            }
            cam += 0x4C;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camScreenShake.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camSetZoom(s32 arg0, f32 arg1) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        D_800A3174[arg0] = 1;
        D_800A317C[arg0] = arg1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camSetZoom.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camConvertMatrixList(s32 arg0, s32 arg1) {
    s32 idx = D_800A2ED0;
    u8 *entry = D_800FA658 + idx * 8;

    *(s32 *) entry = arg0;
    D_800A2ED0 = idx + 1;
    *(s16 *) (entry + 4) = arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camConvertMatrixList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camTick(s32 arg0) {
    u8 *cam = cameraActorArray;
    u8 *shake = D_800FA600;
    s32 i;
    s32 temp_v1;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a1;
    s16 *sh;

    *(s16 *) (D_800FA658 + D_800A2ED0 * 8 + 4) = -1;
    conv_mult_matrix(D_800FAAF0, D_800FA658);
    D_800A2ED0 = 0;
    D_800FB518 = 0;
    for (i = 0; i < 4; i++) { /* asm: bnez delay-slot loop, runs 4 times */
        D_800A3174[3 - i] = 0;
        D_800A3178[3 - i] = 1;
        *(f32 *) (cam + 0x30) = 0.0f;
        *(f32 *) (cam + 0x34) = 0.0f;
        *(f32 *) (cam + 0x38) = 0.0f;
        sh = (s16 *) shake;
        if (*(s32 *) (shake + 8) != 0) {
            sh[3] = (s16) (sh[3] + arg0);
            if (sh[3] >= sh[2]) {
                *(s32 *) (shake + 8) = 0;
            } else {
                D_800FB518 = 1;
                temp_v1 = sh[3];
                temp_a0 = sh[1];
                var_a1 = *(s32 *) (shake + 8);
                if (temp_a0 < temp_v1) {
                    temp_v0_2 = sh[2];
                    var_a1 = (s32) ((temp_v0_2 - temp_v1) * var_a1) / (s32) (temp_v0_2 - temp_a0);
                } else {
                    temp_v0_3 = sh[0];
                    if (temp_v1 < temp_v0_3) {
                        var_a1 = (s32) (temp_v1 * var_a1) / temp_v0_3;
                    }
                }
                *(f32 *) (cam + 0x34) = (f32) mathRnd(0, var_a1);
            }
        }
        cam += 0x4C;
        shake += 0xC;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera/camTick.s")
#endif
