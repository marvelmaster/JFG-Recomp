#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 resolutionSettings[];          /* 10-word entries, indexed by D_800FF988 * 10 */
extern s32 D_800A3900_A4500[4];           /* [0] base, [1]/[2] buffers (malloc), [3] zbuffer (0x0C) */
extern s32 D_800A3928_A4528;
extern OSMesg D_800FEB60_B1750[];
extern OSMesgQueue D_800FEB80_B1770;
extern OSScClient D_800FEC40_B1830;
extern s8 D_800FECA5_B1895;
extern s8 D_800FECA6_B1896;
extern s8 D_800FECA7_B1897;
extern s8 D_800FECA9_B1899;
extern u8 D_800FECAB_B189B;
extern u8 D_800FECAC_B189C;
extern u8 D_800FECAD_B189D;
extern f32 D_800FECC8_B18B8;
extern s32 D_800A3924_A4524;
extern s32 D_800FEC58_B1848;
extern s32 D_800FEC70_B1860;
extern u8 D_800FEC78_B1868[];
extern f32 aspectRatioFloat;
extern s32 viFramesPerSecond;
extern s32 viNoZbufferRealloc;
extern s8 widescreenVOffsetMirror;
extern s8 framebufferChoice;
extern s32 framebufferPointers_[3];
extern f32 hScale;
extern f32 vScale;
extern s32 framebufferSize;
extern s32 someResVar;
extern s32 runInOneFrame;
extern OSViMode osViMode_custom;
extern s8 D_800A32A0_A3EA0;
extern s32 extraScreen;

void viChangeMode(s32 arg0);
void viAllocateZBuffer(s32 arg0, s32 arg1);
void viFreeZBuffer(s32 arg0, s32 arg1);
void viFrameRateReset(void);
void viSetTiming(void);
void viGetCurrentSize(s32 *arg0, s32 *arg1);
void fontSetWindow0(s32 arg0, s32 arg1);
void func_80055D44(s32 arg0, s32 arg1, s32 *arg2);
OSViMode *func_80055DA8(s32 arg0);
void func_80055E68(void);
void func_80055F4C(void *arg0, OSViMode *arg1, s32 arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viInit(OSSched *sc) {
    s32 var_v0;

    if (osTvType == 0) {
        viFramesPerSecond = 50;
        aspectRatioFloat = 1.2121212f;
        var_v0 = 264;
        D_800FECC8_B18B8 = 1.1f;
    } else {
        viFramesPerSecond = 60;
        aspectRatioFloat = 1.3333334f;
        var_v0 = 240;
        D_800FECC8_B18B8 = 1.0f;
    }
    osCreateMesgQueue(&D_800FEB80_B1770, D_800FEB60_B1750, 8);
    osScAddClient(sc, &D_800FEC40_B1830, &D_800FEB80_B1770, 2U);
    D_800A3900_A4500[0] = (s32) mmAlloc((var_v0 * 0x500) + 0x30, -1U);
    widescreenVOffsetMirror = 0;
    D_800FECA5_B1895 = 0;
    D_800FECA6_B1896 = 0;
    D_800FECA7_B1897 = 1;
    viNoZbufferRealloc = 0;
    viChangeMode(0);
    D_800A3928_A4528 = 1;
    D_800FECA9_B1899 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viChangeMode(s32 arg0) {
    s32 *res;
    s32 bufSize;
    s32 alignedBase;
    s32 mode;

    D_800FF988 = arg0 & 3 & ~D_800A3928_A4528;
    D_800A3928_A4528 = 0;
    if (osTvType == 2) {
        D_800FF988 += 4;
    } else if (osTvType == 0) {
        D_800FF988 += 8;
    }
    res = &resolutionSettings[D_800FF988 * 10];
    hScale = (f32) res[0] / 320.0f;
    vScale = (f32) res[1] / 240.0f;
    fontSetWindow0(res[0], res[1]);
    if (viNoZbufferRealloc == 0) {
        viFreeZBuffer(res[0], res[1]);
    }
    if (D_800A3900_A4500[1] != 0) {
        mmFree((void *) D_800A3900_A4500[1]);
        D_800A3900_A4500[1] = 0;
    }
    if (D_800A3900_A4500[2] != 0) {
        mmFree((void *) D_800A3900_A4500[2]);
        D_800A3900_A4500[2] = 0;
    }
    framebufferChoice = 0;
    alignedBase = (D_800A3900_A4500[0] + 0x3F) & ~0x3F;
    mode = D_800FF988 & 3;
    framebufferPointers_[0] = alignedBase;
    bufSize = res[0] * res[1] * 2;
    framebufferPointers_[1] = 0;
    framebufferPointers_[2] = 0;
    if ((mode != 2) && (mode != 3)) {
        framebufferPointers_[1] = alignedBase + bufSize;
    } else {
        D_800A3900_A4500[1] = (s32) mmAlloc(bufSize + 0x30, -1U);
        framebufferPointers_[1] = (D_800A3900_A4500[1] + 0x3F) & ~0x3F;
    }
    if (D_800FECA6_B1896 != 0) {
        D_800A3900_A4500[2] = (s32) mmAlloc(bufSize + 0x30, -1U);
        framebufferPointers_[2] = (D_800A3900_A4500[2] + 0x3F) & ~0x3F;
    }
    D_800FECA5_B1895 = D_800FECA6_B1896;
    if (D_800FECA7_B1897 != 0) {
        /* m2c shows a 4th arg (&D_800A3900) on this first call only; the callee
           prototype here takes 3, so the extra register arg is dropped. */
        func_80055D44(framebufferPointers_[0], bufSize, framebufferPointers_);
        func_80055D44(framebufferPointers_[1], bufSize, framebufferPointers_);
        if (D_800FECA5_B1895 != 0) {
            func_80055D44(framebufferPointers_[2], bufSize, framebufferPointers_);
        }
    }
    D_800FECA7_B1897 = 1;
    if (viNoZbufferRealloc == 0) {
        viAllocateZBuffer(res[0], res[1]);
    }
    viFrameRateReset();
    func_80055E68();
    viSetTiming();
    viNoZbufferRealloc = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viChangeMode.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viReset(void) {
    s32 w;
    s32 h;
    s32 count;
    s32 i;

    viGetCurrentSize(&w, &h);
    count = (u32) (w * h) >> 1;
    for (i = 0; i < count; i++) {
        ((s32 *) currentScreen)[i] = 0;
    }
    for (i = 0; i < count; i++) {
        ((s32 *) otherScreen)[i] = 0;
    }
    osWritebackDCacheAll();
    if ((D_800FF988 != 0) && (D_800FF988 != 4)) {
        if (osTvType == 0) {
            D_800FF988 = 0xE;
        } else if (osTvType == 2) {
            D_800FF988 = 0xD;
        } else {
            D_800FF988 = 0xC;
        }
        viSetTiming();
    }
    osViBlack(0U);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viReset.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viAllocateZBuffer(s32 arg0, s32 arg1) {
    s32 size;

    size = (arg0 * arg1 * 2) + 0x30;
    framebufferSize = size;
    D_800A3900_A4500[3] = (s32) mmAlloc(size, -1U);
    otherZbuf = (D_800A3900_A4500[3] + 0x3F) & ~0x3F;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viAllocateZBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viFreeZBuffer(s32 arg0, s32 arg1) {
    if (D_800A3900_A4500[3] != 0) {
        mmFree((void *) D_800A3900_A4500[3]);
        D_800A3900_A4500[3] = 0;
        otherZbuf = 0;
        framebufferSize = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viFreeZBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viSetTiming(void) {
    s32 *res;
    OSViMode *var_v0;
    s32 var_a0;
    s32 var_a1;
    s32 temp_t8;

    res = &resolutionSettings[D_800FF988 * 10];
    func_80055F4C(func_80055DA8(res[5]), &osViMode_custom, 0x50);
    D_800FEC58_B1848 = res[0];
    D_800FEC70_B1860 = (s32) (res[0] << 9) / res[2];
    var_a0 = res[4];
    var_a1 = var_a0 << 0x11;
    if (D_800FF988 & 1) {
        var_a1 = var_a0 << 0x11;
        if (((u32) (someResVar * 2) >> 0x1F) != 0) {
            var_a0 += widescreenVOffsetMirror;
            var_a1 = var_a0 << 0x11;
        }
    }
    var_v0 = &osViMode_custom;
    do {
        var_v0->fldRegs[0].origin = res[0] * 2;
        temp_t8 = var_v0->fldRegs[0].vStart + var_a1;
        var_v0->fldRegs[0].vStart = temp_t8;
        /* asm steps the cursor by 0x14 bytes (raw byte add) */
        var_v0 = (OSViMode *) ((u8 *) var_v0 + 0x14);
        var_v0->comRegs.leap = (u32) ((s32) (res[1] << 0xA) / res[3]);
        var_v0->comRegs.hStart = temp_t8 - (((0xF0 - var_a0) - res[3]) * 2);
    } while ((u8 *) var_v0 != D_800FEC78_B1868);
    if (D_800A3924_A4524 != 0) {
        osViSetMode(&osViMode_custom);
    }
    osViSetSpecialFeatures(0x52U);
    D_800A3924_A4524 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viSetTiming.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viGetCurrentSize(s32 *arg0, s32 *arg1) {
    s32 *res;

    res = &resolutionSettings[D_800FF988 * 10];
    *arg0 = res[0];
    *arg1 = res[1];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viGetCurrentSize.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viConvertXY(s32 *arg0, s32 *arg1) {
    *arg0 = (s32) ((f32) *arg0 * hScale);
    *arg1 = (s32) ((f32) *arg1 * vScale);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viConvertXY.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viGetScaleXY(f32 *arg0, f32 *arg1) {
    *arg0 = hScale;
    *arg1 = vScale;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viGetScaleXY.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viFrameRateReset(void) {
    D_800FECAD_B189D = 1;
    D_800FECAB_B189B = 0;
    D_800FECAC_B189C = 2;
    runInOneFrame = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viFrameRateReset.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 viFrameSync(s32 arg0) {
    s32 frames;
    s32 result;
    u8 temp_t1;
    OSMesgQueue *q = &D_800FEB80_B1770;

    frames = 1;
    if (D_800FECA9_B1899 != 0) {
        D_800FECA9_B1899 -= 1;
        if (D_800FECA9_B1899 == 0) {
            osViBlack(0U);
        }
    }
    if (arg0 != 8) {
        func_80055E68();
    }
    if (osRecvMesg(q, NULL, 0) != -1) {
        do {
            frames = (frames + 1) & 0xFF;
        } while (osRecvMesg(q, NULL, 0) != -1);
    }
    if (D_800FECAC_B189C == 3) {
        result = frames;
        if (frames < 3) {
            temp_t1 = D_800FECAB_B189B + 1;
            D_800FECAB_B189B = temp_t1;
            if (temp_t1 >= 0x1F) {
                D_800FECAC_B189C = 2;
            }
        } else {
            goto block_16;
        }
    } else {
        result = frames;
        if ((frames >= 3) && (D_800FECAD_B189D == 0)) {
            D_800FECAC_B189C = 3;
block_16:
            D_800FECAB_B189B = 0;
        }
    }
    if (runInOneFrame != 0) {
        D_800FECAC_B189C = 1;
    }
    if (result < (s32) D_800FECAC_B189C) {
        do {
            osRecvMesg(q, NULL, 1);
            result = (frames + 1) & 0xFF;
            frames = result;
        } while (result < (s32) D_800FECAC_B189C);
    }
    osViSwapBuffer(otherScreen);
    osRecvMesg(q, NULL, 1);
    D_800FECAD_B189D = 0;
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viFrameSync.s")
#endif

s32 viGetVideoMode(void) {
    return D_800FF988 & 3;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s8 viGetWideAdjust(void) {
    return widescreenVOffsetMirror;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viGetWideAdjust.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viSetWideAdjust(s8 arg0) {
    s8 var_a0;

    var_a0 = arg0;
    if (var_a0 < -0x1E) {
        var_a0 = -0x1E;
    }
    if (var_a0 >= 0x1F) {
        var_a0 = 0x1E;
    }
    widescreenVOffsetMirror = var_a0;
    /* asm passes var_a0 in $a0; viSetTiming takes no arguments and ignores it */
    viSetTiming();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viSetWideAdjust.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viSetTrippleBuffer(s32 arg0) {
    D_800FECA6_B1896 = arg0 & 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viSetTrippleBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s8 viGetTrippleBuffer(void) {
    return D_800FECA5_B1895;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viGetTrippleBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 viChangeBuffers(void) {
    return D_800FECA6_B1896 != D_800FECA5_B1895;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viChangeBuffers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void viNoClear(void) {
    D_800FECA7_B1897 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viNoClear.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 viDisplayingScreen0(void) {
    if ((s32) otherScreen == *framebufferPointers_) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/viDisplayingScreen0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80055D44(s32 arg0, s32 arg1, s32 *arg2) {
    s32 i;
    s32 n = arg1 >> 2;
    s32 *p = (s32 *)arg0;

    if (D_800A32A0_A3EA0 != 0) {
        for (i = 0; i != n; i++) {
            *p++ = 0;
        }
    } else {
        for (i = 0; i != n; i++) {
            *p++ = -1;
        }
    }
    osWritebackDCacheAll();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/func_80055D44.s")
#endif

//get_osViMode
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
OSViMode *func_80055DA8(s32 arg0) {
    switch (arg0) {
        case 0:  return &osViModeNtscLpn1;
        case 1:  return &osViModeNtscLan1;
        case 2:  return &osViModeNtscHpn1;
        case 3:  return &osViModeNtscHaf1;
        case 4:  return &osViModeMpalLpn1;
        case 5:  return &osViModeMpalLan1;
        case 6:  return &osViModeMpalHpn1;
        case 7:  return &osViModeMpalHaf1;
        case 8:  return &osViModePalLpn1;
        case 9:  return &osViModePalLan1;
        case 10: return &osViModePalHpn1;
        case 11: return &osViModePalHaf1;
        default: return NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/func_80055DA8.s")
#endif

//swap_framebuffer_pointers
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80055E68(void) {
    s32 idx;

    otherScreen = (s32 *)framebufferPointers_[framebufferChoice];
    framebufferChoice += 1;
    if (D_800FECA5_B1895 != 0) {
        if (framebufferChoice >= 3) {
            framebufferChoice = 0;
        }
        idx = framebufferChoice;
        extraScreen = framebufferPointers_[idx];
        if (idx < 2) {
            currentScreen = framebufferPointers_[idx + 1];
        } else {
            currentScreen = framebufferPointers_[0];
        }
    } else {
        idx = framebufferChoice;
        if (idx >= 2) {
            framebufferChoice = 0;
            idx = 0;
        }
        currentScreen = framebufferPointers_[idx];
        extraScreen = currentScreen;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/func_80055E68.s")
#endif

//osVimode_copy
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80055F4C(void *arg0, OSViMode *arg1, s32 arg2) {
    u8 *src = (u8 *)arg0;
    u8 *dst = (u8 *)arg1;
    s32 i;

    for (i = 0; i != arg2; i++) {
        dst[i] = src[i];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameVi/func_80055F4C.s")
#endif
