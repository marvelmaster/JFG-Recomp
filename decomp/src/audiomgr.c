#include "common.h"
#ifdef NON_MATCHING
#include "PR/n_libaudio.h"
/* decomp: externs */
extern N_ALGlobals ALGLOBALS;
typedef struct AMDmaNode {
    struct AMDmaNode *next;
    struct AMDmaNode *prev;
    u32 unk8;
    s32 unkC;
    void *unk10;
} AMDmaNode;
extern struct {
    u8 unk0;
    u8 pad1[3];
    AMDmaNode *unk4;
    void *unk8;
} D_800F1B68_B9B18;
extern s32 D_800A06D0_A12D0;
extern s32 D_800A06D4_A12D4;
extern AMDmaNode *D_800A06C0_A12C0;
extern s32 D_800A06DC_A12DC;
extern s32 D_800A06E4_A12E4;
extern s32 D_800A06E8_A12E8;
extern u8 D_800F2178_BA128[];
extern s32 D_800A06C4_A12C4;
extern s32 D_800A06C8_A12C8;
extern s32 D_800A06CC_A12CC;
extern s32 D_800A06D8_A12D8;
extern s32 D_800A06E0_A12E0;
extern s32 D_800A06F0_A12F0;
extern s32 D_800F29E0_BA990;
extern OSScTask D_800F1A58_B9A08;
extern u8 D_8009F250_9FE50[];
extern u8 D_8009F3D0_9FFD0[];
extern u8 D_8009DA10_9E610[];
extern u8 D_800AFC10_B0810[];
void __clearAudioDMA(void);
#endif
extern u32 D_800A06F4_A12F4[];
extern OSSched *D_800E97A0_B1750;
extern ALHeap *D_800E97A4_B1754;
extern OSScClient D_800E97A8_B1758;
extern s32 viFramesPerSecond;
extern s32 D_800F2168_BA118;
extern s32 D_800F216C_BA11C;
extern s32 D_800F2170_BA120;
extern OSThread D_800F17C0_B9770;
extern u8 D_800F17B8_B9768[];
extern u8 D_800F17C6_B9776[];
extern OSMesgQueue D_800F1AF4_B9AA4;
extern OSMesgQueue D_800F1B0C_B9ABC;
extern OSMesgQueue D_800F2898_BA848;
extern OSMesg D_800F1B24_B9AD4[];
extern OSMesg D_800F1B44_B9AF4[];
extern OSMesg D_800F28B0_BA860[];
extern ALLink D_800F1B78_B9B28;
extern ALLink D_800F1B8C_B9B3C;
extern s32 D_800A07FC_A13FC;
void *__amDmaNew(void **arg0);
void __amMain(void *arg0);
void __amHandleFrameMsg(void);
void __amHandleDoneMsg(void);

const char D_800AAA80[] = "audio: ai out of samples\n";
const char D_800AAA9C[] = "OH DEAR - No audio DMA buffers left\n";
const char D_800AAAC4[] = "Dma not done\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amCreateAudioMgr(ALSynConfig *c, s32 priority, OSSched *sched) {
    u32 paramBuf[0x108 / 4];
    u8 *thr;
    u8 *cur;
    u8 *slot;
    u8 *s0;
    u8 *s1;
    u8 *s2;
    u8 *p;
    s32 i;
    s32 j;
    s32 n;
    f32 temp_f0;
    s32 temp_f4;

    D_800E97A0_B1750 = sched;
    D_800E97A4_B1754 = c->heap;
    c->outputRate = osAiSetFrequency(0x5604);
    c->dmaproc = (void *) __amDmaNew;

    for (i = 0; i < c->maxFXbusses; i++) {
        if (((u8 *) c)[0x1C + i] == 6) {
            for (j = 0; j < 0x108 / 4; j++) {
                paramBuf[j] = D_800A06F4_A12F4[j];
            }
            *(void **) ((u8 *) c + 0x20 + i * 4) = paramBuf;
        }
    }

    n_alInit(&ALGLOBALS, c);
    temp_f0 = ((f32) c->outputRate * 2.0f) / (f32) viFramesPerSecond;
    temp_f4 = (s32) temp_f0;
    n = temp_f4;
    D_800F2168_BA118 = temp_f4;
    if ((f32) n < temp_f0) {
        n = n + 1;
        D_800F2168_BA118 = n;
    }
    D_800F2168_BA118 = ((n / 184) * 0xB8) + 0xB8;
    D_800F216C_BA11C = D_800F2168_BA118 - 0xB8;
    D_800F2170_BA120 = 0x1000;

    thr = (u8 *) &D_800F17C0_B9770;
    p = (u8 *) alHeapDBAlloc(NULL, 0, c->heap, 1, 0x6F40);
    *(u8 **) (thr + 0x280) = p;
    *(u8 **) (thr + 0x284) = p + 0x37A0;
    *(u8 **) (thr + 0x288) = p;
    *(u8 **) (thr + 0x28C) = p + 0x37A0;

    s0 = (u8 *) alHeapDBAlloc(NULL, 0, c->heap, 1, D_800F2170_BA120 * 0xC);
    cur = thr;
    slot = thr;
    do {
        cur += 2;
        *(u8 **) (slot + 0x310) = s0;
        *(u8 **) (slot + 0x31C) = s0;
        slot += 4;
        *(u16 *) (cur + 0x306) = 0;
        s0 += D_800F2170_BA120 * 4;
    } while (cur < (u8 *) D_800F17C6_B9776);

    s0 = (u8 *) alHeapDBAlloc(NULL, 0, c->heap, 1, 0xBE00);
    D_800F1B78_B9B28.next = NULL;
    D_800F1B78_B9B28.prev = NULL;
    s1 = (u8 *) &D_800F1B78_B9B28;
    s2 = (u8 *) &D_800F1B8C_B9B3C;
    do {
        alLink((ALLink *) s2, (ALLink *) s1);
        s2 += 0x14;
        *(u8 **) (s1 + 0x10) = s0;
        s1 += 0x14;
        s0 += 0x280;
    } while (s2 != (u8 *) &D_800F2168_BA118);
    *(u8 **) (s1 + 0x10) = s0;

    osCreateMesgQueue(&D_800F1B0C_B9ABC, D_800F1B44_B9AF4, 8);
    osCreateMesgQueue(&D_800F1AF4_B9AA4, D_800F1B24_B9AD4, 8);
    osCreateMesgQueue(&D_800F2898_BA848, D_800F28B0_BA860, 0x4C);
    osCreateThread(&D_800F17C0_B9770, -4, __amMain, NULL, D_800F17B8_B9768, priority);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/amCreateAudioMgr.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __amMain(UNUSED void *arg0) {
    void *sp44;
    void *sp40;
    s32 var_s0;

    sp44 = NULL;
    sp40 = NULL;
    var_s0 = 0;
    osScAddClient(D_800E97A0_B1750, &D_800E97A8_B1758, &D_800F1AF4_B9AA4, 1);
    do {
        osRecvMesg(&D_800F1AF4_B9AA4, &sp44, 1);
        switch (*(s16 *) sp44) {
            case 4:
                break;
            case 1:
                __amHandleFrameMsg();
                osRecvMesg(&D_800F1B0C_B9ABC, &sp40, 1);
                __amHandleDoneMsg();
                break;
            case 10:
                var_s0 = 1;
                break;
        }
    } while (var_s0 == 0);
    n_alClose(&ALGLOBALS);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/__amMain.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amGo(void) {
    osStartThread(&D_800F17C0_B9770);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/amGo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amStop(void) {
    osStopThread(&D_800F17C0_B9770);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/amStop.s")
#endif

s32 amAudioMgrGetNextFrameCount(void) {
    return nextFrameCount;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. DKR __amHandleFrameMsg (same engine; JFG layout differs, asm is truth).
// am = D_800F17C0_B9770. Layout from asm: ACMDList[2] @0x280 (backup pair
// @0x288), alloc'd ACMD block @0x290/0x294, frameSamples s16[3] @0x308,
// output data ptrs @0x310 (+0x31C..0x324 shadow), the OSScTask at
// D_800F1A58_B9A08 (== am + 0x298).
void __amHandleFrameMsg(void) {
    u8 *am = (u8 *) &D_800F17C0_B9770;
    u8 *blk;
    u8 *node;
    u8 *a2;
    u8 *v3;
    void *tmp;
    s16 *fs;
    Acmd *cmdList;
    Acmd *cmdp;
    OSScTask *t;
    s32 mode;
    s32 lastIdx;
    s32 nextIdx;
    s32 curList;
    s32 i;
    s32 cmdLen;
    s32 sz;
    u32 samplesLeft;
    u32 physBuf;

    __clearAudioDMA();

    lastIdx = D_800A06CC_A12CC;
    /* asm reads the AI length register directly (inlined osAiGetLength) */
    samplesLeft = osAiGetLength() >> 2;
    osAiSetNextBuffer(*(void **) (am + 0x310 + lastIdx * 4),
                      (u32) (*(s16 *) (am + 0x308 + lastIdx * 2) * 4));

    mode = D_800A06DC_A12DC;
    if (mode == 1) {
        D_800F29E0_BA990 += 2;
        if (D_800F29E0_BA990 < 6) {
            D_800A06E8_A12E8 = 0;
        } else {
            D_800F29E0_BA990 = 6;
            D_800A06E8_A12E8 = 1;
        }
    }

    if (D_800A06E4_A12E4 > 0) {
        D_800A06E4_A12E4 -= 1;
        if (D_800A06E4_A12E4 <= 0) {
            mmFree(*(void **) (am + 0x290));
            mmFree(*(void **) (am + 0x328));
            i = 0;
            do {
                node = (u8 *) D_800A06C0_A12C0 + i;
                if (D_800F1B68_B9B18.unk4 == (AMDmaNode *) node) {
                    D_800F1B68_B9B18.unk4 = ((AMDmaNode *) node)->next;
                }
                if (D_800F1B68_B9B18.unk8 == node) {
                    D_800F1B68_B9B18.unk8 = ((AMDmaNode *) node)->next;
                }
                alUnlink((ALLink *) node);
                i += 0x14;
            } while (i != 0x5F0);
            mmFree(D_800A06C0_A12C0);
            D_800A06C0_A12C0 = NULL;
        }
    }

    if (D_800A06E0_A12E0 != mode) {
        D_800A06E8_A12E8 = 0;
        if (mode == 1 && D_800A06C0_A12C0 == NULL) {
            *(u8 **) (am + 0x290) = (u8 *) mmAlloc(0x29B80, -1U);
            *(u8 **) (am + 0x294) = *(u8 **) (am + 0x290) + 0x14DC0;
            a2 = (u8 *) mmAlloc(D_800F2170_BA120 * 0x48, -1U);
            v3 = am;
            do {
                v3 += 4;
                *(u8 **) (v3 + 0x324) = a2;
                *(u8 **) (v3 + 0x30C) = a2;
                a2 += D_800F2170_BA120 * 0x18;
            } while (v3 < am + 0xC);

            *(u8 **) (am + 0x280) = *(u8 **) (am + 0x290);
            *(u8 **) (am + 0x284) = *(u8 **) (am + 0x294);
            blk = (u8 *) mmAlloc(0xC3F0, -1U);
            D_800A06C0_A12C0 = (AMDmaNode *) blk;
            if (D_800F1B68_B9B18.unk8 != NULL) {
                alLink((ALLink *) blk, (ALLink *) D_800F1B68_B9B18.unk8);
            } else {
                D_800F1B68_B9B18.unk8 = blk;
                ((AMDmaNode *) blk)->next = NULL;
                ((AMDmaNode *) blk)->prev = NULL;
            }

            a2 = blk + 0x5F0;
            i = 0;
            do {
                alLink((ALLink *) (blk + i + 0x14), (ALLink *) (blk + i));
                ((AMDmaNode *) (blk + i))->unk10 = a2;
                i += 0x14;
                a2 += 0x280;
            } while (i != 0x5DC);
            ((AMDmaNode *) (blk + i))->unk10 = a2;
            D_800F29E0_BA990 = 1;
        } else {
            v3 = am;
            do {
                tmp = *(void **) (v3 + 0x31C);
                v3 += 4;
                *(void **) (v3 + 0x30C) = tmp;
            } while (v3 != am + 0xC);
            D_800A06E4_A12E4 = 0xC;
            *(u8 **) (am + 0x280) = *(u8 **) (am + 0x288);
            *(u8 **) (am + 0x284) = *(u8 **) (am + 0x28C);
        }
        D_800A06E0_A12E0 = mode;
    }

    if (mode == 0) {
        nextFrameCount = 2;
    } else {
        nextFrameCount = D_800F29E0_BA990 * 2;
    }

    nextIdx = D_800A06C8_A12C8;
    physBuf = osVirtualToPhysical(*(void **) (am + 0x310 + nextIdx * 4));

    fs = (s16 *) (am + 0x308 + nextIdx * 2);
    if (((s32) samplesLeft >= 0x139) & D_800A06D8_A12D8) {
        D_800A06D8_A12D8 = 0;
        *fs = (s16) D_800F216C_BA11C;
    } else {
        D_800A06D8_A12D8 = 1;
        *fs = (s16) D_800F2168_BA118;
    }
    if (D_800A06DC_A12DC == 1) {
        *fs = (s16) (*fs * D_800F29E0_BA990);
    }

    curList = D_800A06C4_A12C4;
    cmdList = *(Acmd **) (am + 0x280 + curList * 4);
    cmdp = n_alAudioFrame(cmdList, &cmdLen, (s16 *) physBuf, *fs);
    if (D_800A06F0_A12F0 < cmdLen) {
        D_800A06F0_A12F0 = cmdLen;
    }

    t = &D_800F1A58_B9A08;
    t->next = NULL;
    t->flags = OS_SC_NEEDS_RSP;
    t->msgQ = &D_800F1B0C_B9ABC;
    t->msg = NULL;
    t->unk58 = -1;
    t->unk5C = 0;
    t->unk60 = 0xFF;
    t->unk64 = 0;
    t->unk6C = 1;
    t->list.t.type = M_AUDTASK;
    t->list.t.flags = OS_TASK_DP_WAIT;
    t->list.t.ucode_boot = (u64 *) D_8009F250_9FE50;
    t->list.t.ucode_boot_size = (u32) (D_8009F3D0_9FFD0 - D_8009F250_9FE50);
    t->list.t.ucode = (u64 *) D_8009DA10_9E610;
    t->list.t.ucode_size = 0x1000;
    t->list.t.ucode_data = (u64 *) D_800AFC10_B0810;
    t->list.t.ucode_data_size = 0x800;
    t->list.t.data_ptr = (u64 *) cmdList;
    sz = (s32) ((u8 *) cmdp - (u8 *) cmdList);
    t->list.t.data_size = (sz >> 3) << 3;
    t->list.t.yield_data_ptr = NULL;
    t->list.t.yield_data_size = 0;

    osSendMesg(osScGetCmdQ(D_800E97A0_B1750), (OSMesg) t, 0);

    D_800A06C4_A12C4 ^= 1;
    D_800A06CC_A12CC = nextIdx;
    D_800A06C8_A12C8 = (nextIdx + 1) % 3;
    D_800A06D0_A12D0 += 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/__amHandleFrameMsg.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __amHandleDoneMsg(void) {
    s32 *p;

    p = &D_800A07FC_A13FC;
    if ((osAiGetLength() >> 2) == 0) {
        if (*p == 0) {
            *p = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/__amHandleDoneMsg.s")
#endif

//__amDma
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u32 func_80002764(u32 arg0, s32 arg1, s32 arg2) {
    AMDmaNode *var_s0;
    AMDmaNode *var_a2 = NULL;
    AMDmaNode *temp_s0;
    AMDmaNode *temp_t0;
    u32 temp_v0;
    s32 sp40;
    s32 temp_t6;
    u32 temp_a3;
    void *sp44;

    sp40 = arg0 & 1;
    var_s0 = D_800F1B68_B9B18.unk4;
    while (var_s0 != NULL) {
        temp_v0 = var_s0->unk8;
        if (arg0 < temp_v0) {
            break;
        }
        var_a2 = var_s0;
        if (((s32)(temp_v0 + 0x280)) >= ((s32)(arg0 + arg1))) {
            var_s0->unkC = D_800A06D0_A12D0;
            return osVirtualToPhysical((u8 *)var_s0->unk10 + (arg0 - temp_v0));
        }
        var_s0 = var_s0->next;
    }
    temp_s0 = (AMDmaNode *)D_800F1B68_B9B18.unk8;
    if (temp_s0 == NULL && var_a2 == NULL) {
        var_a2 = D_800F1B68_B9B18.unk4;
    }
    if (temp_s0 == NULL) {
        return osVirtualToPhysical(var_a2->unk10) + sp40;
    }
    D_800F1B68_B9B18.unk8 = temp_s0->next;
    alUnlink((ALLink *)temp_s0);
    if (var_a2 != NULL) {
        alLink((ALLink *)temp_s0, (ALLink *)var_a2);
    } else {
        temp_t0 = D_800F1B68_B9B18.unk4;
        if (temp_t0 != NULL) {
            D_800F1B68_B9B18.unk4 = temp_s0;
            temp_s0->next = temp_t0;
            temp_s0->prev = NULL;
            temp_t0->prev = temp_s0;
        } else {
            D_800F1B68_B9B18.unk4 = temp_s0;
            temp_s0->next = NULL;
            temp_s0->prev = NULL;
        }
    }
    temp_a3 = arg0 - sp40;
    temp_s0->unk8 = temp_a3;
    temp_s0->unkC = D_800A06D0_A12D0;
    sp44 = temp_s0->unk10;
    temp_t6 = D_800A06D4_A12D4 * 0x18;
    D_800A06D4_A12D4 += 1;
    osPiStartDma((OSIoMesg *)(D_800F2178_BA128 + temp_t6), 1, 0, temp_a3, sp44, 0x280U, &D_800F2898_BA848);
    return osVirtualToPhysical(sp44) + sp40;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/func_80002764.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *__amDmaNew(void **arg0) {
    if (D_800F1B68_B9B18.unk0 == 0) {
        D_800F1B68_B9B18.unk4 = NULL;
        D_800F1B68_B9B18.unk8 = &D_800F1B78_B9B28;
        D_800F1B68_B9B18.unk0 = 1;
    }
    *arg0 = &D_800F1B68_B9B18;
    return (void *)func_80002764;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/__amDmaNew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void __clearAudioDMA(void) {
    s32 pad;
    void *msg = NULL;
    AMDmaNode *cur;
    AMDmaNode *next;
    u32 i;

    if (D_800A06D4_A12D4 != 0) {
        i = 0;
        do {
            osRecvMesg(&D_800F2898_BA848, &msg, 0);
            i++;
        } while (i < (u32) D_800A06D4_A12D4);
    }
    cur = D_800F1B68_B9B18.unk4;
    while (cur != NULL) {
        next = cur->next;
        if ((u32) (cur->unkC + 1) < (u32) D_800A06D0_A12D0) {
            if (cur == D_800F1B68_B9B18.unk4) {
                D_800F1B68_B9B18.unk4 = next;
            }
            alUnlink((ALLink *) cur);
            if (D_800F1B68_B9B18.unk8 != NULL) {
                alLink((ALLink *) cur, (ALLink *) D_800F1B68_B9B18.unk8);
            } else {
                D_800F1B68_B9B18.unk8 = cur;
                cur->next = NULL;
                cur->prev = NULL;
            }
        }
        cur = next;
    }
    D_800A06D4_A12D4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/__clearAudioDMA.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amAudioMgrSetScheduleMode(s32 arg0) {
    s32 *p;

    p = &D_800A06DC_A12DC;
    *p = arg0;
    if (arg0 == 1) {
        D_800A06E4_A12E4 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/amAudioMgrSetScheduleMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 amAudioMgrHaveRunALargeFrame(void) {
    return D_800A06E8_A12E8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/amAudioMgrHaveRunALargeFrame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 amAudioMgrHaveFreedLargeBuffers(void) {
    return D_800A06C0_A12C0 == 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audiomgr/amAudioMgrHaveFreedLargeBuffers.s")
#endif
