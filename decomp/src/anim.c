#include "common.h"

#ifdef VERSION_us
const char D_800AEF90_AFB90[] = "Path %d, Obj %d\n";
#endif
const char D_800AFB30[] = "Before Level Number %d (%d)\n";
const char D_800AFB50[] = "After  Level Number %d\n";

extern s32 *D_80105498;
extern u8 * D_8010549C;
extern u32 D_801054A0;

/* decomp: externs */
extern void **animpath;
extern u8 racingCharacter;
extern void *D_800A7E88;
extern void *D_800A7E8C;
extern s32 D_800A7E90;
extern s32 *D_800A7E7C;
extern s8 D_800A7EB0[];
extern s16 D_800A7F30[];
extern s16 D_800A7F40[];
extern s16 D_800A7F48[];
extern u32 *D_80105284;
extern void *animcamera[];
extern s32 D_80105298[];
extern u8 animscroll[];
extern u8 animlockon[];
extern u8 animlight[];
extern u8 fadeR[];
extern s16 fadeA;
extern s16 fadeCount;
extern s16 trackFade;
extern s16 trackFadeCount;
extern s16 trackFadeEnd;
extern s32 animTemp;
extern s32 numanimlockons;
extern s32 playing;
extern void *D_800A7E70;
extern s32 D_800A7E74;
extern s32 D_800A7E78;
extern s32 D_800A7E80;
extern s32 D_800A7E84;
extern s32 D_800A7E98;
extern f32 D_800A7E9C;
extern f32 D_800A7EA4;
extern f32 D_800A7EA8;
extern s32 D_800A7EAC;
extern s32 D_80000308;
extern s16 trackFadeStart;
extern s16 trackFadeTime;
void mmFree(void *data);
s32 mainGetGameFlag(s32 flag);
s32 mainGetNextCharacter(s32 arg0);
s32 mainGetPlayerCharacter(s32 arg0);
void objAddAnimPlayer(void *obj, void *arg1);
void *objSetupObject(void *params, s32 arg1);
void objFreeObject(void *obj);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndStopXYZ(void *soundMask);
void amSndStop(s32 handle);
void amSndSetPitchXYZ(SoundMask *soundMask, s32 pitch);
void camSetFOV(f32 fov, s32 force);
void animseqFreeGroup(void);
void animseqInitGroup(void);
void animseqResetGroup(void);
void animseqInitCaptions();
void animseqLockOnUpdate();
void func_80077BE8(void);
s32 animseqUpdatePath();
void animseqUpdatePath_4arg(void *path, f32 dt, s32 a, s32 b); /* NM link alias of animseqUpdatePath */
void animseqUpdateCaptions(s32 arg0);
void animseqUpdateLightChangers(s32 arg0);
void animseqUpdateTextureScrollers(void *path, f32 arg1, s32 arg2, s32 arg3);
void animseqProcessCommandList(void);
void osCartTest3_6105(s32 arg0);
void amSndPlay(u16 soundId, void *handlePtr);
void amTunePlay(u8 seqId);
void amTuneResetFade(void);
void amTuneSetFade(f32 fade, u8 volume);
void amTuneSetVolume(u8 volume);
void amAmbientPlay(u8 seqId);
void amAmbientResetFade(void);
void amAmbientSetFade(f32 fade, u8 volume);
void amAmbientSetVolume(u8 volume);
void subtitleStart(s32 arg0);
void subtitlesFree(void);
void changeWeather(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void trackFadeFog(s32 fogIdx, s32 red, s32 green, s32 blue, s32 near, s32 far, f32 timer);
void explosionStart(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5);
void camStartShake(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
void *trackGetTrack(void);
void objAnimSetMove(void *obj, s32 anim, f32 speed);
void frontSetInstrumentsHide();
void DoSquaddiesCollide();
void mainSyncNextLevel(void);
s32 frontGetMode(void);
void mainChangeLevel(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void mainFrontInit(s32 arg0, s32 arg1, s32 arg2);
void frontCharSelectSetQuitMode(s8 arg0);
void mainSetGameFlag(s32 arg0, s32 arg1);
void mainSetAnimGroup(s32 arg0);
void joyDisable(s32 player);
void joyEnable(s32 player);
void animseqStartNoisyFade(void *arg0, f32 arg1, s32 arg2, s32 arg3);
void animseqLockOnInit(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void animseqLockOnDelete(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void animseqReleaseBits(s32 arg0);
void animseqStartCaption(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8);
void animseqAddChangeLight(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void animseqFireBullet(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_800767A0(s32 *arg0) {
    D_80105498 = arg0;
    D_8010549C = *arg0;
    D_801054A0 = 0x80;
}

s32 func_800767C4(u32 arg0) {
    s32 ret;

    ret = 0;
    if (arg0 != 0) {
        arg0 = 1 << (arg0 + 0x1F);
        do {
            if (D_801054A0 == 0) {
                D_8010549C++;
                D_801054A0 = 0x80;
            }
            if (*D_8010549C & D_801054A0) {
                ret |= arg0;
            }
            arg0 >>= 1;
            D_801054A0 >>= 1;
        } while (arg0 != 0);
    }
    return ret;
}

s32 func_80076840(u32 arg0) {
    u32 temp_v0;
    s32 ret;

    ret = 0;
    if (arg0 != 0) {
        temp_v0 = 0xFFFFFFFF << (arg0 - 1);
        arg0 = 1 << (arg0 - 1);
        do {
            if (D_801054A0 == 0) {
                D_8010549C++;
                D_801054A0 = 0x80;
            }
            if (*D_8010549C & D_801054A0) {
                ret |= arg0;
            }
            arg0 >>= 1;
            D_801054A0 >>= 1;
        } while (arg0 != 0);
        if (ret & temp_v0) {
            ret |= temp_v0;
        }
    }
    return ret;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800768D4(void) {
    if (D_801054A0 != 0x80) {
        D_8010549C += 1;
    }
    *D_80105498 = (s32) D_8010549C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_800768D4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80076918(void) {
    if (D_800A7E88 != NULL) {
        D_800A7E88 = NULL;
        D_800A7E8C = NULL;
        D_800A7E90 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_80076918.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s8 func_80076948(void *arg0) {
    return D_800A7EB0[(*(u16 *)((u8 *)arg0 + 2) >> 8) & 0xFF];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_80076948.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80076968(void) {
    u8 *ptr;
    s32 count;
    s32 sum;
    s32 len;
    s32 done;

    ptr = D_800A7E88;
    count = 0;
    sum = 0;
    done = 0;
    if (ptr != NULL) {
        do {
            if (((*(u16 *)(ptr + 2) >> 8) & 0xFF) == 0x7F) {
                done = 1;
            }
            len = func_80076948(ptr);
            sum += len;
            if (len != 0) {
                count += 1;
                ptr += (len >> 1) * 2;
                if (count >= 0x2001) {
                    done = 1;
                }
            } else {
                sum = 0;
                done = 1;
            }
        } while (done == 0);
    }
    return sum;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_80076968.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80076A20(void) {
    s32 *base;
    u8 *temp;

    base = D_800A7E7C;
    temp = (u8 *)base + (*base & 0xFFFFFF);
    D_800A7E88 = temp;
    D_800A7E8C = temp;
    D_800A7E90 = func_80076968();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_80076A20.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80076A70(s32 arg0) {
    void *path;
    void *obj;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        obj = *(void **)((u8 *)path + 0x08);
        if (obj != NULL) {
            objFreeObject(obj);
        }
        mmFree(path);
    }
    animpath[arg0 & 0xFF] = NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_80076A70.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqInitPath(s32 arg0) {
    u8 *path;
    u8 *node;
    u8 *obj;
    u8 *sub;
    s16 setup[5];
    s16 id;
    s32 chr;
    s8 level;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        node = *(u8 **)(path + 0x20);
        if (node != NULL) {
            if (*(void **)(path + 0x08) == NULL) {
                id = *(s16 *)(path + 0x02);
                if (id != -1) {
                    if (id == 0xC5 || id == 0xC6) {
                        chr = mainGetPlayerCharacter(0);
                        if (mainGetGameFlag(0x5F) != 0) {
                            chr |= 4;
                        }
                        *(s16 *)(path + 0x02) = D_800A7F30[chr & 7];
                        id = *(s16 *)(path + 0x02);
                    }
                    if (id == 0x106 || id == 0x8A || id == 0x10A) {
                        level = levelGetLevel()->unk6C;
                        if (level == 1 || level == 2) {
                            *(s16 *)(path + 0x02) = D_800A7F40[mainGetNextCharacter(level) & 3];
                        } else {
                            *(s16 *)(path + 0x02) = D_800A7F48[mainGetNextCharacter(level) & 3];
                        }
                    }
                    setup[0] = *(s16 *)(path + 0x02);
                    ((u8 *)setup)[2] = 0x0A;
                    setup[2] = (s16)*(f32 *)(node + 0x0C);
                    setup[3] = (s16)*(f32 *)(node + 0x10);
                    setup[4] = (s16)*(f32 *)(node + 0x14);
                    obj = objSetupObject(setup, 1);
                    *(void **)(path + 0x08) = obj;
                    if (obj != NULL) {
                        *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) | 0x400);
                        *(s32 *)(obj + 0x3C) = 0;
                        if (*(s16 *)(obj + 0x48) == 0x33) {
                            objAddAnimPlayer(obj, obj);
                        }
                        id = *(s16 *)(path + 0x02);
                        path[0x24] = 0xFF;
                        path[0x25] = 0xFF;
                        path[0x26] = 0;
                        path[0x27] = 0;
                        *(s16 *)(path + 0x2A) = 0;
                        *(f32 *)(path + 0x2C) = 1.0f;
                        *(f32 *)(path + 0x30) = 0.0f;
                        if (id == 0x29B || id == 0x29C || id == 0x29D) {
                            *(s8 *)(obj + 0x3A) = (s8)(mainGetNextCharacter(-1) & 3);
                            if (*(s8 *)(obj + 0x3A) == 3) {
                                *(s8 *)(obj + 0x3A) = (s8)(racingCharacter & 3);
                            }
                            if (*(s8 *)(obj + 0x3A) >= *(s8 *)(*(u8 **)(obj + 0x40) + 0x1F)) {
                                *(s8 *)(obj + 0x3A) = 0;
                            }
                        }
                        if (*(s32 *)(obj + 0x5C) != 0) {
                            sub = *(u8 **)(obj + 0x4C);
                            *(u16 *)(sub + 0x0A) &= 0xFFFE;
                        }
                    }
                }
            }
        }
        path[0x28] = 0x64;
        path[0x29] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqInitPath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqResetPath(s32 arg0) {
    u8 *path;
    u8 *obj;
    u8 *sub;
    void *snd;
    u8 flags;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        flags = path[0x16];
        if (!(flags & 8)) {
            obj = *(u8 **)(path + 0x08);
            path[0x16] = flags & 0x80;
            *(f32 *)(path + 0x10) = 1.0f;
            *(f32 *)(path + 0x1C) = 0.0f;
            path[0x01] = path[0x00];
            path[0x14] = path[0x06];
            path[0x15] = path[0x07];
            *(f32 *)(path + 0x0C) = (f32)*(s16 *)(path + 0x04) / 16384.0f;
            *(s32 *)(path + 0x18) = (s32)(*(u8 **)(path + 0x20));
            if (obj != NULL) {
                *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) | 0x400);
                path[0x24] = 0xFF;
                path[0x25] = 0xFF;
                path[0x26] = 0;
                path[0x27] = 0;
                *(s16 *)(path + 0x2A) = 0;
                *(f32 *)(path + 0x2C) = 1.0f;
                *(f32 *)(path + 0x30) = 0.0f;
                if (*(s32 *)(obj + 0x5C) != 0) {
                    sub = *(u8 **)(obj + 0x4C);
                    *(u16 *)(sub + 0x0A) &= 0xFFFE;
                }
                animseqInitCaptions(path, 0, 0, 0);
                snd = *(void **)(obj + 0x88);
                if (snd != NULL) {
                    amSndStopXYZ(snd);
                    *(void **)(obj + 0x88) = NULL;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqResetPath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqStartPath(s32 arg0) {
    u8 *path;
    u8 *obj;
    u8 *sub;
    u8 flags;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        flags = path[0x16];
        if (!(flags & 8)) {
            if (!(flags & 1)) {
                obj = *(u8 **)(path + 0x08);
                path[0x16] = (u8)((flags | 1) & 0xFB);
                if (obj != NULL) {
                    *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) & 0xFBFF);
                    if (*(s32 *)(obj + 0x5C) != 0) {
                        sub = *(u8 **)(obj + 0x4C);
                        *(u16 *)(sub + 0x0A) |= 1;
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqStartPath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqStopPath(s32 arg0) {
    u8 *path;
    u8 *obj;
    u8 *sub;
    u8 flags;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        flags = path[0x16];
        if (!(flags & 8) && (flags & 5)) {
            obj = *(u8 **)(path + 0x08);
            path[0x16] = flags & 0xFA;
            if (obj != NULL) {
                *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) | 0x400);
                if (*(s32 *)(obj + 0x5C) != 0) {
                    sub = *(u8 **)(obj + 0x4C);
                    *(u16 *)(sub + 0x0A) &= 0xFFFE;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqStopPath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqHoldPath(s32 arg0) {
    u8 *path;
    u8 *obj;
    u8 *sub;
    u8 flags;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        flags = path[0x16];
        if (!(flags & 8)) {
            if (flags & 1) {
                path[0x16] = flags & 0xFE;
            } else {
                obj = *(u8 **)(path + 0x08);
                if (obj != NULL) {
                    *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) & 0xFBFF);
                    if (*(s32 *)(obj + 0x5C) != 0) {
                        sub = *(u8 **)(obj + 0x4C);
                        *(u16 *)(sub + 0x0A) |= 1;
                    }
                }
            }
            path[0x16] |= 4;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqHoldPath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqLockPath(s32 arg0) {
    u8 *path;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        path[0x16] |= 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqLockPath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqUnLockPath(s32 arg0) {
    u8 *path;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        path[0x16] &= 0xF7;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqUnLockPath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqSndPlay(s32 arg0, u16 arg1) {
    u8 *path;
    u8 *obj;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        obj = *(u8 **)(path + 0x08);
        if (obj != NULL) {
            if (*(void **)(obj + 0x88) == NULL) {
                amSndPlayXYZ(arg1, *(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 1, obj + 0x88);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqSndPlay.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqSndStop(s32 arg0) {
    u8 *path;
    u8 *obj;
    void *snd;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        obj = *(u8 **)(path + 0x08);
        if (obj != NULL) {
            snd = *(void **)(obj + 0x88);
            if (snd != NULL) {
                amSndStopXYZ(snd);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqSndStop.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800772C4(s32 count, u8 *nodes, s32 data, void **outNodes, s32 *outData) {
    u8 *node;
    s32 remaining;
    s32 flag;
    f32 scale;

    node = nodes;
    remaining = count;
    if (count > 0) {
        do {
            func_800767A0(&data);
            node[0x06] = func_800767C4(8);
            flag = func_800767C4(1);
            node[0x07] = func_800767C4(1);
            *(f32 *)(node + 0x0C) = (f32) func_80076840(0x12) * 0.125f;
            *(f32 *)(node + 0x10) = (f32) func_80076840(0x12) * 0.125f;
            *(f32 *)(node + 0x14) = (f32) func_80076840(0x12) * 0.125f;
            *(s16 *)(node + 0x00) = (s16) (func_800767C4(0xC) * 0x10);
            *(s16 *)(node + 0x02) = (s16) (func_800767C4(0xC) * 0x10);
            *(s16 *)(node + 0x04) = (s16) (func_800767C4(0xC) * 0x10);
            *(f32 *)(node + 0x08) = (f32) func_800767C4(0xC) * 0.01f;
            if (flag == 0) {
                *(f32 *)(node + 0x08) = *(f32 *)(node + 0x08) * 0.390625f;
            }
            *(s16 *)(node + 0x18) = (s16) (func_80076840(0xC) * 4);
            *(s16 *)(node + 0x1A) = (s16) (func_80076840(0xC) * 4);
            *(s16 *)(node + 0x1C) = (s16) (func_80076840(0xC) * 4);
            scale = (f32) func_800767C4(0xC) * 0.5f;
            node[0x1E] = 0;
            *(f32 *)(node + 0x20) = scale;
            func_800768D4();
            remaining -= 1;
            node += 0x2C;
        } while (remaining > 0);
    }
    if (outNodes != NULL) {
        *outNodes = node;
    }
    if (outData != NULL) {
        *outData = data;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_800772C4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqLinkNodes(s32 arg0) {
    u8 *path;
    u8 *nodes;
    s32 count;
    s32 i;

    path = animpath[arg0 & 0xFF];
    if (path != NULL) {
        count = path[0x17];
        nodes = *(u8 **)(path + 0x20);
        if (count >= 2) {
            for (i = 0; i < count; i++) {
                if (i > 0) {
                    *(u8 **)(nodes + i * 0x2C + 0x24) = nodes + (i - 1) * 0x2C;
                }
                if (i < count - 1) {
                    *(u8 **)(nodes + i * 0x2C + 0x28) = nodes + (i + 1) * 0x2C;
                }
            }
        }
        if (path[0x16] & 0x80) {
            *(u8 **)(nodes + 0x24) = nodes + (count - 1) * 0x2C;
            *(u8 **)(nodes + (count - 1) * 0x2C + 0x28) = nodes;
        } else {
            *(u8 **)(nodes + 0x24) = nodes;
            *(u8 **)(nodes + (count - 1) * 0x2C + 0x28) = nodes + (count - 1) * 0x2C;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqLinkNodes.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqInit(void) {
    s32 i;
    u8 *p;

    D_80105284 = piRomLoad(0x41);
    animpath = (void **) mmAlloc(0x400, 0x4080F0FF);
    for (i = 0; i < 0x400; i += 4) {
        *(s32 *)((u8 *)animpath + i) = 0;
    }
    for (p = (u8 *)animcamera; p < (u8 *)D_80105298; p += 4) {
        *(s32 *)p = 0;
    }
    for (p = (u8 *)D_80105298; p < animscroll; p += 4) {
        *(s32 *)p = 0;
    }
    for (p = animscroll; p < animlockon; p += 0x14) {
        *p = 0xFF;
        *(s32 *)(p + 0x04) = 0;
        *(s32 *)(p + 0x0C) = 0;
    }
    for (p = animlockon; p < fadeR; p += 8) {
        *p = 0xFF;
    }
    numanimlockons = 0;
    for (p = animlight; p < (u8 *)D_80105498; p += 0x40) {
        *(s32 *)(p + 0x00) = 0;
        *(s32 *)(p + 0x10) = 0;
        *(s32 *)(p + 0x20) = 0;
        *(s32 *)(p + 0x30) = 0;
    }
    fadeA = 0;
    fadeCount = 0;
    animTemp = 0;
    trackFadeEnd = 0xFF;
    trackFade = trackFadeEnd;
    trackFadeCount = 0;
    animseqInitCaptions(fadeR);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80077784(void) {
    s32 *p;

    p = D_80105298;
    do {
        if (*p != 0) {
            amSndStop(*p);
            *p = 0;
        }
        p++;
    } while ((u8 *)p != animscroll);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_80077784.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqFreeLevelData(void) {
    if (D_800A7E70 != NULL) {
        mmFree(D_800A7E70);
        D_800A7E70 = NULL;
        D_800A7E78 = -1;
        animseqFreeGroup();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqFreeLevelData.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqLoadLevelData(s32 arg0) {
    u32 *entry;
    s32 start;
    void *buf;

    if (arg0 != -1) {
        if (arg0 != D_800A7E78) {
            animseqFreeLevelData();
            entry = (u32 *)((u8 *)D_80105284 + arg0 * 4);
            start = entry[0];
            D_800A7E74 = entry[1] - start;
            if (D_800A7E74 > 0) {
                buf = mmAlloc(D_800A7E74, 0x4080F0FF);
                D_800A7E70 = buf;
                if (buf != NULL) {
                    piRomLoadSection(0x42, (u32) buf, start, D_800A7E74);
                    D_800A7E78 = arg0;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqLoadLevelData.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqFreeGroup(void) {
    u8 *p;
    s32 i;

    if (D_800A7E7C != NULL) {
        if (D_800A7E84 != 0) {
            mmFree(D_800A7E7C);
            D_800A7E84 = 0;
        }
        D_800A7E7C = NULL;
        D_800A7E80 = -1;
        func_80076918();
        i = 0;
        do {
            func_80076A70(i & 0xFF);
            i += 1;
        } while (i < 0x100);
        for (p = (u8 *)animcamera; p < (u8 *)D_80105298; p += 4) {
            *(s32 *)p = 0;
        }
        for (p = animscroll; p < animlockon; p += 0x14) {
            *p = 0xFF;
            *(s32 *)(p + 0x04) = 0;
            *(s32 *)(p + 0x0C) = 0;
        }
        for (p = animlockon; p < fadeR; p += 8) {
            *p = 0xFF;
        }
        numanimlockons = 0;
        for (p = animlight; p < (u8 *)D_80105498; p += 0x40) {
            *(s32 *)(p + 0x00) = 0;
            *(s32 *)(p + 0x10) = 0;
            *(s32 *)(p + 0x20) = 0;
            *(s32 *)(p + 0x30) = 0;
        }
        fadeA = 0;
        fadeCount = 0;
        animTemp = 0;
        trackFadeEnd = 0xFF;
        trackFade = trackFadeEnd;
        trackFadeCount = 0;
        func_80077784();
        animseqInitCaptions();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqFreeGroup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqSetupGroup(s32 arg0) {
    u32 *entry;
    u32 word;
    s32 groupId;
    s32 offset;

    if (arg0 >= 0 && arg0 < 0x100) {
        if (arg0 != D_800A7E80) {
            animseqFreeGroup();
            entry = (u32 *)D_800A7E70;
            do {
                word = *entry;
                entry++;
                groupId = (s32) (word >> 0x18);
            } while (arg0 != groupId && groupId != 0xFF);
            if (groupId == arg0) {
                offset = word & 0xFFFFFF;
                if (offset != 0xFFFFFF) {
                    D_800A7E80 = groupId;
                    D_800A7E7C = (s32 *)((u8 *)D_800A7E70 + offset);
                    func_80077BE8();
                    animseqInitGroup();
                    animseqResetGroup();
                    D_800A7EA4 = (f32) *(s8 *)((u8 *)levelGetLevel() + 0xAC);
                    D_800A7EA8 = 0.0f;
                    D_800A7EAC = 0;
                    playing = 1;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqSetupGroup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqInitGroup(void) {
    s32 i;

    i = 0;
    do {
        animseqInitPath(i & 0xFF);
        i += 1;
    } while (i != 0x100);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqInitGroup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqResetGroup(void) {
    s32 i;

    if (D_800A7E7C != NULL) {
        i = 0;
        do {
            animseqResetPath(i & 0xFF);
            i += 1;
        } while (i != 0x100);
        D_800A7E8C = D_800A7E88;
        D_800A7E98 = 0;
        D_800A7E9C = 0.0f;
        func_80077784();
        animseqLockOnUpdate();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqResetGroup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80077BE8(void) {
    s32 *entry;
    s32 numPaths;
    s32 i;
    s32 word;
    s32 pathIdx;
    u8 *src;
    u8 *path;
    u8 flags;

    entry = (s32 *)((u8 *)D_800A7E7C + 4);
    numPaths = ((u32) *D_800A7E7C >> 0x18) & 0xFF;
    func_80076A20();
    for (i = numPaths; i > 0; i--) {
        word = *entry;
        entry++;
        src = (u8 *)D_800A7E7C + (word & 0xFFFFFF);
        pathIdx = ((u32) word >> 0x18) & 0xFF;
        animpath[pathIdx] = mmAlloc(src[0] * 0x2C + 0x34, 0x4080F0FF);
        path = animpath[pathIdx];
        if (path != NULL) {
            if (src[0] > 0) {
                *(u8 **)(path + 0x20) = path + 0x34;
            } else {
                *(u8 **)(path + 0x20) = NULL;
            }
            *(void **)(path + 0x08) = NULL;
            *(s16 *)(path + 0x02) = *(s16 *)(src + 0x02);
            path[0x00] = src[0x01];
            *(s16 *)(path + 0x04) = *(s16 *)(src + 0x04);
            path[0x06] = src[0x06];
            flags = src[0x07];
            path[0x16] = 0;
            path[0x07] = flags;
            if (flags & 0x80) {
                path[0x16] = 0x80;
                path[0x07] = flags & 0x7F;
            }
            path[0x17] = src[0x00];
            animseqResetPath(pathIdx);
            func_800772C4(path[0x17], *(u8 **)(path + 0x20), (s32) (src + 8), NULL, NULL);
            animseqLinkNodes(pathIdx);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/func_80077BE8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqUpdate(s32 arg0) {
    s32 stepArg;
    s32 advance;
    s32 timeTicks;
    s32 newTime;
    s32 i;
    f32 frameTime;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 speed;
    f32 pitchF;
    s32 pitch;
    u16 cmdWord;
    u16 cmdTime;
    u8 *p;
    u8 *path;
    u8 *obj;
    SoundMask *snd;

    if (D_800A7E7C != NULL && playing != 0) {
        if (osTvType == 0) {
            frameTime = 0.02f;
        } else {
            frameTime = 0.016666668f;
        }
        advance = arg0;
        stepArg = arg0;
        if (numanimlockons > 0) {
            animseqUpdatePath(arg0);
        }
        if (D_800A7E8C != NULL && playing == 1) {
            cmdWord = *(u16 *)((u8 *)D_800A7E8C + 2);
            if ((cmdWord >> 8) == 0x7B) {
                cmdTime = *(u16 *)D_800A7E8C;
                if ((f32) cmdTime / 100.0f < (f32) (D_800A7E98 + arg0) * frameTime) {
                    if (osTvType == 0) {
                        timeTicks = cmdTime >> 1;
                    } else {
                        timeTicks = (cmdTime * 6) / 10;
                    }
                    advance = timeTicks - D_800A7E98;
                    D_800A7E8C = (u8 *)D_800A7E8C + 4;
                    playing = (s8) cmdWord;
                    if ((s8) cmdWord == 0) {
                        stepArg = advance;
                    }
                }
            }
        }
        if (advance > 0) {
            for (p = (u8 *)animcamera; p < (u8 *)D_80105298; p += 4) {
                *(s32 *)p = 0;
            }
            newTime = D_800A7E98 + advance;
            if (D_800A7EAC != 0) {
                if (advance < D_800A7EAC) {
                    D_800A7EAC -= advance;
                    D_800A7EA4 = D_800A7EA4 + (D_800A7EA8 * (f32) advance);
                } else {
                    speed = D_800A7EA8 * (f32) D_800A7EAC;
                    D_800A7EAC = 0;
                    D_800A7EA4 = D_800A7EA4 + speed;
                }
            }
            D_800A7E98 = newTime;
            D_800A7E9C = (f32) newTime * frameTime;
            for (i = 0; i < 0x100; i++) {
                path = animpath[i];
                if (path != NULL && (path[0x16] & 5)) {
                    animseqUpdateTextureScrollers(path, (f32) advance * frameTime, advance, stepArg);
                }
            }
            if (playing == 1) {
                animseqProcessCommandList();
            }
            animseqUpdateLightChangers(advance);
            animseqUpdateCaptions(advance);
            osCartTest3_6105(advance);
            for (i = 0; i < 0x100; i++) {
                path = animpath[i];
                if (path != NULL) {
                    obj = *(u8 **)(path + 0x08);
                    if (obj != NULL) {
                        snd = *(SoundMask **)(obj + 0x88);
                        if (snd != NULL) {
                            amSndSetXYZ(snd, *(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
                            if (path[0x28] != 0x64 || path[0x29] != 0) {
                                vx = *(f32 *)(obj + 0x1C);
                                vy = *(f32 *)(obj + 0x20);
                                vz = *(f32 *)(obj + 0x24);
                                speed = sqrtf(vx * vx + vy * vy + vz * vz);
                                pitchF = (f32) path[0x28] + ((f32) path[0x29] * speed);
                                if (pitchF < 0.0f) {
                                    pitch = -1;
                                } else {
                                    pitch = (s32) pitchF;
                                }
                                amSndSetPitchXYZ(snd, pitch & 0xFF);
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Command stream: entries of u16 words. [0] = time (1/100 s), [1] = opcode << 8 | arg,
// [2..] = extra args. An entry advances cmd by (4 + extra bytes) / 2 words; the stream
// ends at word 0x7F00. Path layout as in animseqInitPath (+0x08 obj, +0x16 flags, ...).
// Arguments are passed exactly as the asm loads them (lhu = u16, lh = s16).
void animseqProcessCommandList(void) {
    u16 *cmd;
    u16 cmdWord;
    u16 cmdTime;
    u16 w2;
    u16 w3;
    u16 w4;
    u16 w5;
    u16 w6;
    s32 idx;
    s32 argA;
    s32 argB;
    s32 argC;
    s32 argD;
    s32 argE;
    s32 argF;
    s32 *sndSlot;
    s32 clearBuf[2];
    u8 *clear;
    u8 *path;
    u8 *obj;
    u8 *sub;
    u8 *node;
    u8 *hdr;
    u8 *ent;
    u8 *ent74;
    u8 *elem;
    u8 *track;
    u8 *light;
    u8 *sc;
    u32 word4;
    f32 curTime;
    f32 dt;
    f32 fa;
    f32 fb;
    f32 fc;

    if (animseqUpdatePath(D_80000308) != 0) {
        cmd = (u16 *) D_800A7E8C;
        if (cmd != NULL) {
            cmdWord = cmd[1];
            while (cmdWord != 0x7F00) {
                cmdTime = cmd[0];
                curTime = (f32) cmdTime / 100.0f;
                if (!(curTime < D_800A7E9C && playing == 1)) {
                    break;
                }
                dt = D_800A7E9C - curTime;
                idx = cmdWord & 0xFF;

                switch ((cmdWord >> 8) & 0xFF) {
                case 0x00:
                    cmd += 2;
                    animseqStartPath(idx);
                    /* overlay_47 animseqUpdatePath(path, dt, 0, 0); see sibling in o47 */
                    animseqUpdatePath_4arg(animpath[idx], dt, 0, 0);
                    break;

                case 0x01:
                    cmd += 2;
                    animseqStopPath(idx);
                    break;

                case 0x02:
                    cmd += 2;
                    path = (u8 *) animpath[idx];
                    if (path != NULL) {
                        if (path[0x16] & 1) {
                            animseqResetPath(idx);
                            animseqStartPath(idx);
                            animseqStartNoisyFade(animpath[idx], dt, 0, 0);
                        } else {
                            animseqResetPath(idx);
                        }
                    }
                    break;

                case 0x03:
                    cmd += 2;
                    path = (u8 *) animpath[idx];
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        path[0x16] = (u8) (path[0x16] | 2);
                        if (obj != NULL && (path[0x16] & 5)) {
                            animcamera[0] = obj;
                        }
                    }
                    break;

                case 0x04:
                    cmd += 2;
                    path = (u8 *) animpath[idx];
                    if (path != NULL) {
                        path[0x16] = (u8) (path[0x16] & 0xFFFD);
                    }
                    break;

                case 0x05:
                    cmd += 2;
                    animseqHoldPath(idx);
                    break;

                case 0x06:
                    w2 = cmd[2];
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        path[0x15] = (u8) (w2 >> 8);
                        path[0x01] = (u8) (w2 & 0xFF);
                    }
                    break;

                case 0x07:
                    fa = (f32) cmd[2] * 0.001f;
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        *(f32 *)(path + 0x10) = fa;
                    }
                    break;

                case 0x08:
                    fa = (f32) cmd[2];
                    fb = (f32) cmd[3];
                    path = (u8 *) animpath[idx];
                    cmd += 4;
                    if (path != NULL) {
                        fa = fa * 0.01f;
                        *(s16 *)(path + 0x2A) = (s16) (s32) (fb * 60.0f * 0.01f);
                        if (*(s16 *)(path + 0x2A) == 0) {
                            *(f32 *)(path + 0x2C) = fa;
                        } else {
                            *(f32 *)(path + 0x30) = (fa - *(f32 *)(path + 0x2C))
                                                    / (f32) *(s16 *)(path + 0x2A);
                        }
                    }
                    break;

                case 0x09:
                    cmd += 2;
                    animseqLockPath(idx);
                    break;

                case 0x0A:
                    cmd += 2;
                    animseqUnLockPath(idx);
                    break;

                case 0x20:
                    w2 = cmd[2];
                    cmd += 3;
                    amSndPlay(w2, 0);
                    break;

                case 0x21:
                    cmd += 2;
                    amTunePlay(idx);
                    amTuneResetFade();
                    break;

                case 0x22:
                    w2 = cmd[2];
                    cmd += 3;
                    amTuneSetFade(((f32) w2 / 100.0f) - dt, idx);
                    break;

                case 0x23:
                    cmd += 2;
                    amTuneSetVolume(idx);
                    amTuneResetFade();
                    break;

                case 0x24:
                    cmd += 2;
                    amAmbientPlay(idx);
                    amAmbientResetFade();
                    break;

                case 0x25:
                    w2 = cmd[2];
                    cmd += 3;
                    amAmbientSetFade(((f32) w2 / 100.0f) - dt, idx);
                    break;

                case 0x26:
                    cmd += 2;
                    amAmbientSetVolume(idx);
                    amAmbientResetFade();
                    break;

                case 0x27:
                    sndSlot = &D_80105298[idx];
                    argA = *sndSlot;
                    w3 = cmd[2];
                    cmd += 3;
                    if (argA != 0) {
                        amSndStop(argA);
                        *sndSlot = 0;
                    }
                    amSndPlay(w3, sndSlot);
                    break;

                case 0x28:
                    sndSlot = &D_80105298[idx];
                    argA = *sndSlot;
                    cmd += 2;
                    if (argA != 0) {
                        amSndStop(argA);
                        *sndSlot = 0;
                    }
                    break;

                case 0x29:
                    path = (u8 *) animpath[idx];
                    w3 = cmd[2];
                    cmd += 3;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            if (*(void **)(obj + 0x88) != NULL) {
                                amSndStopXYZ(*(void **)(obj + 0x88));
                                *(void **)(obj + 0x88) = NULL;
                            }
                            amSndPlayXYZ(w3, *(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10),
                                         *(f32 *)(obj + 0x14), 1, obj + 0x88);
                        }
                    }
                    break;

                case 0x2A:
                    path = (u8 *) animpath[idx];
                    cmd += 2;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            if (*(void **)(obj + 0x88) != NULL) {
                                amSndStopXYZ(*(void **)(obj + 0x88));
                                *(void **)(obj + 0x88) = NULL;
                            }
                        }
                    }
                    break;

                case 0x2B:
                    w2 = cmd[2];
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        path[0x28] = (u8) (w2 >> 8);
                        path[0x29] = (u8) (w2 & 0xFF);
                    }
                    break;

                case 0x40:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    fa = (f32) cmd[4];
                    fb = (f32) cmd[5];
                    argA = (w2 >> 8) & 0xFF;
                    argB = (w3 >> 8) & 0xFF;
                    argC = w3 & 0xFF;
                    argD = w2 & 0xFF;
                    cmd += 6;
                    if ((idx & 0xF) == 7) {
                        argE = (argD == 0) ? 0xFF : 0;
                        animseqLockOnInit(argA, argB, argC, argE, (s32) (fa * 0.01f * 60.0f));
                    } else {
                        clear = (u8 *) clearBuf;
                        clear[0] = (u8) idx;
                        if (argD != 0) {
                            clear[0] = (u8) (idx | 0x80);
                        }
                        clear[1] = (u8) argA;
                        clear[2] = (u8) argB;
                        clear[3] = (u8) argC;
                        *(s16 *)(clear + 4) = (s16) (s32) ((fa / 100.0f) * 60.0f);
                        if (fb > 0.0f) {
                            *(s16 *)(clear + 6) = (s16) (s32) ((fb / 100.0f) * 60.0f);
                        } else {
                            *(s16 *)(clear + 6) = (s16) 0xFFFF;
                        }
                        setupClearScreen(clear);
                    }
                    break;

                case 0x41:
                    cmd += 2;
                    subtitleStart(idx);
                    break;

                case 0x42:
                    cmd += 2;
                    subtitlesFree();
                    break;

                case 0x43:
                    fa = (f32) cmd[2];
                    cmd += 3;
                    changeWeather(0, 0, 0,
                                  (s32) (((f32) (cmdWord & 0xFF) / 255.0f) * 65535.0f),
                                  0xFFFF,
                                  (s32) (fa * 0.01f * 60.0f));
                    break;

                case 0x44:
                    fa = (f32) cmd[2];
                    argA = (s16) cmd[3];
                    argB = (s16) cmd[4];
                    argC = (s16) cmd[5];
                    cmd += 6;
                    changeWeather((s32) ((f32) argA * 0.00390625f),
                                  (s32) ((f32) argB * 0.00390625f),
                                  (s32) ((f32) argC * 0.00390625f),
                                  1, 1, (s32) fa);
                    break;

                case 0x45:
                    fa = (f32) cmd[3] / 100.0f;
                    w2 = cmd[2];
                    w4 = cmd[4];
                    w5 = cmd[5];
                    cmd += 6;
                    trackFadeFog(0, idx, (w2 >> 8) & 0xFF, w2 & 0xFF, w4, w5, fa - dt);
                    break;

                case 0x46:
                    w3 = cmd[2];
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            explosionStart((s16) w3,
                                           (s16) (s32) *(f32 *)(obj + 0x0C),
                                           (s16) (s32) *(f32 *)(obj + 0x10),
                                           (s16) (s32) *(f32 *)(obj + 0x14),
                                           0x64, 0);
                        }
                    }
                    break;

                case 0x47:
                    fa = (f32) cmd[2] / 100.0f;
                    fb = (f32) cmd[3] / 100.0f;
                    fc = (f32) cmd[4] / 100.0f;
                    cmd += 5;
                    camStartShake(0, fa, fb, fc, idx);
                    break;

                case 0x48:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    cmd += 4;
                    track = (u8 *) trackGetTrack();
                    if (track != NULL && (s32) w2 < *(s16 *)(track + 0x18)) {
                        node = *(u8 **)(*(u8 **)track + (w2 * 8));
                        if (node != NULL) {
                            *(s16 *)(node + 0x14) = (s16) (((s32) (w3 << 8)) / 6000);
                        }
                    }
                    break;

                case 0x49:
                    w2 = cmd[2];
                    argA = (s16) cmd[3];
                    argB = (s16) cmd[4];
                    fa = (f32) cmd[5];
                    cmd += 6;
                    sc = (u8 *) animscroll + ((idx & 7) * 0x14);
                    sc[0x00] = (u8) w2;
                    *(s16 *)(sc + 0x02) = (s16) (s32) (fa * 0.6f);
                    *(s32 *)(sc + 0x08) = (((s32) argA * 0x10000) / 6000 - *(s32 *)(sc + 0x04))
                                          / *(s16 *)(sc + 0x02);
                    *(s32 *)(sc + 0x10) = (((s32) argB * 0x10000) / 6000 - *(s32 *)(sc + 0x0C))
                                          / *(s16 *)(sc + 0x02);
                    break;

                case 0x4A:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    argA = (s32) w2 >> 8;
                    cmd += 4;
                    if (argA != 0) {
                        animseqLockOnDelete(idx, w2 & 0xFF, (s32) w3 >> 8, w3 & 0xFF, argA);
                    } else {
                        animseqReleaseBits(idx);
                    }
                    break;

                case 0x4B:
                    fa = (f32) cmd[2] * 60.0f;
                    cmd += 3;
                    trackFadeTime = (s16) (s32) (fa * 0.01f);
                    trackFadeCount = trackFadeTime;
                    trackFadeStart = trackFade;
                    trackFadeEnd = idx;
                    break;

                case 0x4C:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    w4 = cmd[4];
                    w5 = cmd[5];
                    w6 = cmd[6];
                    cmd += 7;
                    animseqStartCaption(idx,
                                        (s32) w2 >> 8,
                                        w2 & 0xFF,
                                        w3 & 0xFF00,
                                        (w3 & 0xFF) << 8,
                                        w4 & 0xFF00,
                                        (w4 & 0xFF) << 8,
                                        w5,
                                        w6);
                    break;

                case 0x4D:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    w4 = cmd[4];
                    w5 = cmd[5];
                    w6 = cmd[6];
                    cmd += 7;
                    animseqAddChangeLight(w2, (s32) (f32) w3, w4, w5,
                                          (s32) w6 >> 8, w6 & 0xFF, idx);
                    break;

                case 0x60:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    w4 = cmd[4];
                    cmd += 5;
                    path = (u8 *) animpath[idx];
                    fa = (f32) w3 / 16384.0f;
                    fb = (f32) w4 / 16384.0f;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            objAnimSetMove(obj, (w2 >> 8) & 0xFF, fa);
                            path[0x14] = (u8) (w2 & 0xFF);
                            *(f32 *)(path + 0x0C) = fb;
                        }
                    }
                    break;

                case 0x61:
                    w2 = cmd[2];
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL && (s32) w2 < *(s8 *)(*(u8 **)(obj + 0x40) + 0x1F)) {
                            *(s8 *)(obj + 0x3A) = (s8) w2;
                        }
                    }
                    break;

                case 0x62:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    path = (u8 *) animpath[idx];
                    cmd += 4;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            *(s32 *)(obj + 0x84) |= (s32) (((u32) w2 << 16) | w3);
                        }
                    }
                    break;

                case 0x63:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    path = (u8 *) animpath[idx];
                    cmd += 4;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            *(s32 *)(obj + 0x84) &= ~(s32) (((u32) w2 << 16) | w3);
                        }
                    }
                    break;

                case 0x64:
                    path = (u8 *) animpath[idx];
                    cmd += 2;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            *(s16 *)(obj + 0x06) = (s16) (*(s16 *)(obj + 0x06) & ~0x400);
                        }
                    }
                    break;

                case 0x65:
                    path = (u8 *) animpath[idx];
                    cmd += 2;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            *(s16 *)(obj + 0x06) = (s16) (*(s16 *)(obj + 0x06) | 0x400);
                        }
                    }
                    break;

                case 0x66:
                    w2 = cmd[2];
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            *(s32 *)(obj + 0x8C) = w2;
                        }
                    } else {
                        animTemp = w2;
                    }
                    break;

                case 0x67:
                    w2 = cmd[2];
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            if (w2 != 0) {
                                *(s16 *)(obj + 0x06) = (s16) (*(s16 *)(obj + 0x06) | 4);
                            } else {
                                *(s16 *)(obj + 0x06) = (s16) (*(s16 *)(obj + 0x06) & 0xFFFB);
                            }
                        }
                    }
                    break;

                case 0x68:
                    w2 = cmd[2];
                    fa = (f32) cmd[3];
                    path = (u8 *) animpath[idx];
                    cmd += 4;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            argA = path[0x25];
                            path[0x25] = (u8) w2;
                            path[0x27] = 0;
                            path[0x24] = (u8) argA;
                            path[0x26] = (s8) (s32) ((fa / 100.0f) * 60.0f);
                            obj[0x39] = (u8) argA;
                        }
                    }
                    break;

                case 0x69:
                    w2 = cmd[2];
                    fa = (f32) cmd[3];
                    path = (u8 *) animpath[idx];
                    cmd += 4;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL
                            && (*(s16 *)(obj + 0x48) == 0x5F || *(s16 *)(obj + 0x48) == 0x96)) {
                            sub = *(u8 **)(obj + 0x68) + ((s32) w2 >> 8) * 12;
                            if (*(s32 *)sub != 0) {
                                sub[0x06] = (u8) (w2 & 0xFF);
                                sub[0x07] = 0;
                                sub[0x05] = sub[0x04];
                                sub[0x08] = (s8) (s32) ((fa / 100.0f) * 60.0f);
                            }
                        }
                    }
                    break;

                case 0x6A:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    w4 = cmd[4];
                    fa = (f32) cmd[5];
                    path = (u8 *) animpath[idx];
                    cmd += 6;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            light = *(u8 **)(obj + 0x74);
                            argA = (s32) w2 >> 8;
                            if (light != NULL
                                && argA < *(s8 *)(*(u8 **)(obj + 0x40) + 0x25)) {
                                animseqAddChangeLight(((s32 *) light)[argA],
                                                      w2 & 0xFF,
                                                      (s32) w3 >> 8,
                                                      w3 & 0xFF,
                                                      w4,
                                                      *(s32 *)&fa,
                                                      1);
                            }
                        }
                    }
                    break;

                case 0x6B:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    w4 = cmd[4];
                    fa = (f32) cmd[5];
                    path = (u8 *) animpath[idx];
                    cmd += 6;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            light = *(u8 **)(obj + 0x78);
                            argA = (s32) w2 >> 8;
                            if (light != NULL
                                && argA < *(u8 *)(*(u8 **)(obj + 0x40) + 0x26)) {
                                animseqFireBullet(((s32 *) light)[argA],
                                                  w2 & 0xFF,
                                                  (s32) w3 >> 8,
                                                  w3 & 0xFF,
                                                  w4,
                                                  *(s32 *)&fa,
                                                  0);
                            }
                        }
                    }
                    break;

                case 0x6C:
                    argA = (u8) (cmd[2] & 0xFF);
                    path = (u8 *) animpath[idx];
                    cmd += 3;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            obj[0x9F] = (u8) argA;
                        }
                    }
                    break;

                case 0x6D:
                    fa = (f32) (s16) cmd[3] * 0.00390625f;
                    argA = (u8) (cmd[2] & 0xFF);
                    w5 = cmd[5];
                    fb = (f32) (s16) cmd[4] * 0.00390625f;
                    path = (u8 *) animpath[idx];
                    cmd += 6;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            sub = *(u8 **)(obj + 0x50);
                            if (sub != NULL) {
                                switch (argA) {
                                case 0:
                                    sub[0x0C] = 0;
                                    break;
                                case 1:
                                    sub[0x0C] = 5;
                                    sub[0x0D] = 1;
                                    break;
                                case 2:
                                case 3:
                                case 4:
                                    sub[0x0C] = 1;
                                    sub[0x0D] = (u8) (argA - 1);
                                    break;
                                case 5:
                                case 6:
                                case 7:
                                case 8:
                                    if (argA == 5) {
                                        sub[0x0C] = 0xD;
                                    } else {
                                        sub[0x0C] = 9;
                                    }
                                    node = *(u8 **)(sub + 0x1C);
                                    if (node != NULL && (node[0x0C] & 8)) {
                                        node[0xBA] = (u8) w5;
                                        if (argA == 5) {
                                            node[0x0D] = 1;
                                        } else {
                                            node[0x0D] = (u8) (argA - 5);
                                        }
                                        if (w5 == 0) {
                                            *(f32 *)node = *(f32 *)sub;
                                            *(f32 *)(node + 0xAC) =
                                                *(f32 *)(*(u8 **)(obj + 0x40) + 0x5C);
                                        } else if (w5 == 2) {
                                            *(f32 *)node = fa;
                                            *(f32 *)(node + 0xAC) = fb;
                                        }
                                    }
                                    break;
                                default:
                                    break;
                                }
                            }
                        }
                    }
                    break;

                case 0x6E:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    w4 = cmd[4];
                    w5 = cmd[5];
                    fa = (f32) cmd[6];
                    path = (u8 *) animpath[idx];
                    cmd += 7;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            /* asm: obj, (v0>>8), v0&0xFF, cmd3, cmd4, cmd5, time (7 args) */
                            frontSetInstrumentsHide(obj, (s32) w2 >> 8, w2 & 0xFF, w3,
                                                    w4, w5,
                                                    (s32) (fa * 0.01f * 60.0f));
                        }
                    }
                    break;

                case 0x6F:
                    w2 = cmd[2];
                    w3 = cmd[3];
                    path = (u8 *) animpath[idx];
                    cmd += 4;
                    argA = (w2 & 0xFF00) >> 8;
                    argB = w2 & 0xFF;
                    if (path != NULL) {
                        obj = *(u8 **)(path + 0x08);
                        if (obj != NULL) {
                            ent = *(u8 **)(*(u8 **)(obj + 0x6C) + *(s8 *)(obj + 0x3A) * 4);
                            hdr = *(u8 **)ent;
                            if (argA < hdr[0x10]) {
                                ent74 = *(u8 **)(ent + 0x74);
                                node = ent74 + argA * 8;
                                word4 = *(u32 *)(node + 4);
                                elem = *(u8 **)(*(u8 **)(hdr + 0x18) + ((word4 & 0xFF) * 8));
                                *(u32 *)(node + 4) = word4 & 0xFFF1FFFF;
                                *(s16 *)(elem + 0x06) = (s16) (*(s16 *)(elem + 0x06) & 0xFFF1FFFF);
                                *(s16 *)(elem + 0x14) = (s16) (((s32) (w3 << 8)) / 6000);
                                switch (argB) {
                                case 1:
                                    *(u32 *)(node + 4) |= 0x80000;
                                    *(s16 *)(elem + 0x06) = (s16) (*(s16 *)(elem + 0x06) | 0x80000);
                                    break;
                                case 2:
                                    *(u32 *)(node + 4) |= 0x40000;
                                    *(s16 *)(elem + 0x06) = (s16) (*(s16 *)(elem + 0x06) | 0x40000);
                                    break;
                                default:
                                    break;
                                }
                            }
                        }
                    }
                    break;

                case 0x74:
                    cmd += 2;
                    frontSetInstrumentsHide(1);
                    break;

                case 0x75:
                    cmd += 2;
                    DoSquaddiesCollide(0);
                    break;

                case 0x76:
                    cmd += 2;
                    mainSyncNextLevel();
                    break;

                case 0x77:
                    cmd += 2;
                    if (mainGetGameFlag(0x5A) != 0 && mainGetGameFlag(0x5B) != 0
                        && mainGetGameFlag(0x5C) != 0) {
                        argA = mainGetNextCharacter(5);
                        mainChangeLevel(0xD4, argA, 0, frontGetMode(), 1, 0);
                    } else {
                        mainFrontInit(5, 0x7F, 0);
                        frontCharSelectSetQuitMode(0);
                    }
                    break;

                case 0x78:
                    w2 = cmd[2];
                    cmd += 3;
                    mainSetGameFlag(w2, idx);
                    break;

                case 0x79:
                    fa = (f32) idx;
                    fb = (f32) cmd[2] * 60.0f;
                    cmd += 3;
                    argA = (s32) (fb * 0.01f);
                    D_800A7EAC = argA;
                    if (argA > 0) {
                        D_800A7EA8 = (fa - D_800A7EA4) / (f32) argA;
                    } else {
                        D_800A7EA4 = fa;
                    }
                    break;

                case 0x7A:
                    w2 = cmd[2];
                    argA = ((s32) cmdWord >> 4) & 0xF;
                    argB = w2 & 0xFFF;
                    argC = (s32) w2 >> 12;
                    argD = cmdWord & 0xF;
                    cmd += 3;
                    if (argB == 0xFFF) {
                        argB = *(u8 *)((u8 *) mainGetGame() + 1);
                    }
                    /* asm: a0 is not set before this call (leftover register); 0 used here */
                    argE = mainGetNextCharacter(0);
                    if (argA != 0) {
                        argF = argA - 1;
                        if ((argE & 3) == 3) {
                            if ((argF & 3) != 3) {
                                argF = racingCharacter;
                            }
                        }
                    } else {
                        argF = (u8) argE;
                    }
                    if (argB == 0x168) {
                        argA = 0x17;
                    } else {
                        argA = frontGetMode();
                    }
                    mainChangeLevel(argB, argF, argC, argA, 1, 0);
                    mainSetAnimGroup(argD);
                    break;

                case 0x7B:
                    cmdTime = cmd[0];
                    D_800A7E98 = (s32) (cmdTime * 60) / 100;
                    fa = (f32) cmdTime;
                    cmd += 2;
                    D_800A7E9C = fa * 0.01f;
                    playing = (s8) (cmdWord & 0xFF);
                    break;

                case 0x7C:
                    cmd += 2;
                    joyDisable(idx & 3);
                    break;

                case 0x7D:
                    cmd += 2;
                    joyEnable(idx & 3);
                    break;

                case 0x7E:
                    cmdTime = cmd[0];
                    D_800A7E98 -= (s32) (cmdTime * 60) / 100;
                    fa = (f32) cmdTime;
                    cmd = (u16 *) D_800A7E88;
                    D_800A7E9C = D_800A7E9C - (fa * 0.01f);
                    break;

                default:
                    /* opcodes outside the table: no-op, stream position unchanged */
                    break;
                }

                cmdWord = cmd[1];
            }
            D_800A7E8C = cmd;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqProcessCommandList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *animseqCamera(s32 arg0, void *arg1) {
    u8 *cam;
    u8 *out;

    cam = (u8 *) animcamera[arg0];
    out = (u8 *) arg1;
    if (cam != NULL) {
        *(f32 *)(out + 0x0C) = *(f32 *)(cam + 0x0C); /* asm: lwc1 (float copy) */
        *(f32 *)(out + 0x10) = *(f32 *)(cam + 0x10); /* asm: lwc1 (float copy) */
        *(f32 *)(out + 0x14) = *(f32 *)(cam + 0x14); /* asm: lwc1 (float copy) */
        *(s16 *)(out + 0x3E) = *(s16 *)(cam + 0x2E);
        *(s16 *)(out + 0x00) = (s16) (0x8000 - *(s16 *)(cam + 0x00));
        *(s16 *)(out + 0x02) = (s16) -*(s16 *)(cam + 0x02);
        *(s16 *)(out + 0x04) = *(s16 *)(cam + 0x04);
        camSetFOV(D_800A7EA4, 0);
    }
    return cam;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqCamera.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqGetPathNumbers(f32 arg0, f32 arg1, f32 arg2, s16 *arg3, s16 *arg4) {
    s32 found;
    s32 pathIdx;
    s32 nodeIdx;
    s32 i;
    u8 *path;
    u8 *head;
    u8 *node;
    u8 *next;
    f32 dy;
    f32 dx;
    f32 dz;

    found = 0;
    for (i = 3; i != 0; i--) {
        *(s16 *)((u8 *)arg3 + i * 2) = -1;
    }
    if (animpath != NULL) {
        for (pathIdx = 0; pathIdx < 0x100; pathIdx++) {
            path = animpath[pathIdx];
            if (path != NULL) {
                head = *(u8 **)(path + 0x20);
                node = head;
                nodeIdx = 0;
                while (node != NULL) {
                    dy = *(f32 *)(node + 0x10) - arg1;
                    if (dy > -16.0f && dy < 16.0f) {
                        dx = *(f32 *)(node + 0x0C) - arg0;
                        dz = *(f32 *)(node + 0x14) - arg2;
                        if ((dx * dx + dz * dz) < 1024.0f) {
                            arg3[found] = (s16) pathIdx;
                            arg4[found] = (s16) nodeIdx;
                            found++;
                            if (found == 3) {
                                return;
                            }
                            break;
                        }
                    }
                    next = *(u8 **)(node + 0x28);
                    if (next == head || next == node) {
                        break;
                    }
                    node = next;
                    nodeIdx++;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqGetPathNumbers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *animseqWhichPathHasObject(s32 arg0) {
    s32 i;
    void *temp;

    for (i = 0; i < 0x100; i++) {
        temp = animpath[i];
        if (temp != NULL && arg0 == *(s32 *)((u8 *)temp + 0x8)) {
            return temp;
        }
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqWhichPathHasObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 animseqGetFirstFreeIndex(void) {
    s32 i;
    void **p;

    i = 0xFF;
    p = animpath + 0xFF;
    for (;;) {
        if (*p == NULL) {
            return i;
        }
        p--;
        if (i-- == 0) {
            return -1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqGetFirstFreeIndex.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqPlay(void) {
    playing = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqPlay.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqPause(void) {
    playing = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/anim/animseqPause.s")
#endif
