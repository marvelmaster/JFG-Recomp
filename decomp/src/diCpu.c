#include "common.h"
#include "PR/rdb.h"
#include "PRinternal/rmonint.h"
#include "stdarg.h"

extern OSThread *__osGetActiveQueue(void);

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_800A6E90;
extern s32 D_800A6E94;
extern s32 D_800A6E98;
extern s32 D_800A6EE0;
extern void *D_80103234;
extern u8 D_80103238[];
extern s32 D_80705014;
extern s32 D_80705018;
extern s32 D_8070501C;
extern s32 D_80000310;
extern u32 D_80102600_B1AA0;
extern u32 D_801026A8_B1B48;
extern u32 D_80102750_B1BF0;
extern void func_80067AA0(s32 arg0);
extern void render_epc_lock_up_display(epcInfo *arg0);
extern MemoryPoolSlot *mmGetSlotPtr(s32 poolIndex);
extern u16 D_800A7128[];
extern u16 D_800A7130[];
extern u16 D_800A7138[];
extern u8 D_800A6EE4[];
extern const char *D_800A6E9C[];
extern const char *errorStringPointers[];
extern char *D_800A6E80;
extern s32 FreeRAM;
extern u8 cpuTraceTrackBufStatus;
extern s32 D_800A333C_A3F3C;
extern void *D_800A3340_A3F40;
extern s32 D_800A3344_A3F44;
extern s32 D_800A3348_A3F48;
void *objGetPlayerNo(s32); /* sig guess */
#endif

#ifdef VERSION_kiosk
const char D_800AF300[] = "7.2";
#else
const char D_800AF300[] = "9.6";
#endif
const char D_800AF304[] = "interrupt";
const char D_800AF310[] = "TLB modify";
const char D_800AF31C[] = "TLB load or fetch";
const char D_800AF330[] = "TLB store";
const char D_800AF33C[] = "addr load or fetch";
const char D_800AF350[] = "addr store";
const char D_800AF35C[] = "bus error fetch";
const char D_800AF36C[] = "bus error reference";
const char D_800AF380[] = "syscall";
const char D_800AF388[] = "breakpoint";
const char D_800AF394[] = "reserved instruction";
const char D_800AF3AC[] = "co-pro unusable";
const char D_800AF3BC[] = "overflow";
const char D_800AF3C8[] = "trap";
const char D_800AF3D0[] = "virtual coherency";
const char D_800AF3E4[] = "floating point";
const char D_800AF3F4[] = ">fault< ";
const char D_800AF400[] = "CORE";
const char D_800AF408[] = "";
#ifdef VERSION_kiosk
// These rodata symbols are contained within the relevant functions, which I didn't do for kiosk.
const char D_800AF40C[] = "%08x:%08x";
const char D_800AF418[] = "MEMORY REGION %d";
const char D_800AF42C[] = "MOD";
const char D_800AF430[] = "OFFSET";
const char D_800AF438[] = "SIZE";
const char D_800AF440[] = "ADDRESS";
const char D_800AF448[] = "Texture %d";
const char D_800AF454[] = "Module %d";
const char D_800AF460[] = "%d";
const char D_800AF464[] = "%08x";
const char D_800AF46C[] = "%d";
const char D_800AF470[] = "%08x";
const char D_800AF478[] = "Module %d at %08x";
const char D_800AF48C[] = "%1x";
const char D_800AF490[] = "%d lines logged";
const char D_800AF4A0[] = "Page %d/%d";
#endif

/**
 * Start the exception program counter thread.
 */
#ifdef NON_MATCHING
// Need to migrate data to define diCpuThreadStack
void diCpuTraceInit(void) {
    osCreateThread(&diCpuOSThread, 0, diCpuThread, 0, &diCpuThreadStack, OS_PRIORITY_MAX);
    osStartThread(&diCpuOSThread);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/diCpuTraceInit.s")
#endif

void diCpuThread(UNUSED void *unused) {
    s32 sp2C;
    s32 s0 = 0;
    osCreateMesgQueue(&D_801031C0, D_801031D8, ARRAY_COUNT(D_801031D8));
    osSetEventMesg(OS_EVENT_FAULT, &D_801031C0, (OSMesg) RMON_MESG_FAULT);
    osSetEventMesg(OS_EVENT_CPU_BREAK, &D_801031C0, (OSMesg) RMON_MESG_CPU_BREAK);
    osCreatePiManager(150, &D_80103218, D_801031F8, ARRAY_COUNT(D_801031F8));
    while (1) {
        osRecvMesg(&D_801031C0, (OSMesg) &sp2C, 1);
        s0 |= sp2C;
        if (!(s0 & RMON_MESG_FAULT) && !(s0 & RMON_MESG_CPU_BREAK)) {
            continue;
        }
        s0 &= ~RMON_MESG_FAULT;
        stop_all_threads_except_main();
        func_800677E4();
    }
}

/**
 * Stop all threads except for the main thread 1
 */
void stop_all_threads_except_main(void) {
    OSThread *node = __osGetActiveQueue();
    while (node->priority != -1) {
        if (node->priority > OS_PRIORITY_IDLE && node->priority <= OS_PRIORITY_APPMAX) {
            osStopThread((OSThread *) &node->next);
        }
        node = node->tlnext;
    }
}

#if 0
extern s32 D_800A6E90;
extern s32 D_800A6E94;
extern s32 D_800A6E98;
extern s8 D_800AF400;
extern s8 D_800AF408;
extern void *D_80103234;
extern ? D_80103238;
extern s32 D_80705014;
extern s32 D_80705018;
extern s32 D_8070501C;

void func_800676F8(void *arg0) {
    void *sp28;
    s32 var_v1;
    void *temp_a0;

    D_80705014 = D_800A6E98;
    D_80705018 = D_800A6E90;
    D_8070501C = D_800A6E94;
    _bcopy(arg0, (void *)0x80705094, 0x230);
    temp_a0 = arg0->unkF4;
    sp28 = temp_a0;
    _bcopy(temp_a0, (void *)0x80705294, 0x200);
    D_80103234 = temp_a0;
    _bcopy(temp_a0, &D_80103238, 0x200);
    var_v1 = 0x100005494;
    if (0x100005494 & 0x1F) {
        var_v1 = (0x100005494 & ~0x1F) + 0x20;
    }
    packWriteFile(0, -1, &D_800AF400, &D_800AF408, (u8 *)0x80700000, var_v1);
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800676F8(void *arg0) {
    void *temp_a0;
    s32 size;

    D_80705014 = D_800A6E98;
    D_80705018 = D_800A6E90;
    D_8070501C = D_800A6E94;
    _bcopy(arg0, (void *) 0x80705094, 0x230);
    temp_a0 = *(void **) ((u8 *) arg0 + 0xF4);
    _bcopy(temp_a0, (void *) 0x80705294, 0x200);
    D_80103234 = temp_a0;
    _bcopy(temp_a0, D_80103238, 0x200);
    size = (s32) (0x80705494U + 0x7F900000U); /* asm: 0x5494 after wrap */
    if (size & 0x1F) {
        size = (size & ~0x1F) + 0x20;
    }
    packWriteFile(0, -1, (char *) D_800AF400, (char *) D_800AF408, (u8 *) 0x80700000, size);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/func_800676F8.s")
#endif

// write_epc_data_to_cpak
void func_800677E4(void) {
    OSThread *thread;

    for (thread = __osGetActiveQueue(); thread->priority != -1; thread = thread->tlnext) {
        if (thread->priority > OS_PRIORITY_IDLE) {
            if (thread->flags & 2 || thread->flags & 1) {
                break;
            }
        }
    }
    if (thread->priority != -1) {
        func_800676F8(thread);
    }
    func_80067880(thread);
}

// interactive_crash_screens
#if 0 /* old NON_EQUIVALENT attempt */
extern s32 osCicId;
extern s32 D_800A6E98;

void func_80067880(OSThread *thread) {
    s32 i;

    // Anti Piracy Check
    if ((D_800A3B74 == 0) || (osCicId != 6105)) {
        while (1) {}
    }
    if (D_800A6E98 == 0) {
        if (thread && thread && thread) {}
    }
    if (viGetVideoMode() != 0) {
        D_800A6EDC = 1;
    } else {
        D_800A6EDC = 0;
    }
    for (i = 0; i < 100; i++) {
        func_8006869C();
    }
    while (1) {}
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Pad-driven crash screen. Pages: 0 = epc/register page, 1 = address nibble editor,
// 2..4 = hex dumps from fixed data addresses, 5 = memory-pool slot table, 6+ = lockup log.
void func_80067880(OSThread *thread) {
    s32 lastPage = -1;      /* asm sp9C: page drawn on the previous frame */
    s32 page = 0;           /* asm s4: current page */
    s32 redraw = 1;         /* asm s6: force a redraw */
    s32 slotScroll = 0;     /* asm s7: first visible slot in the pool table */
    s32 memRegion = 0;      /* asm sp68: memory pool index */
    u32 memAddr;            /* asm sp74: address being edited */
    s32 nibbleCursor = 1;   /* asm sp8C: highlighted nibble */
    s32 maxPage;            /* asm sp94 */
    u16 pressed;            /* asm $v0 from joyGetPressed */
    s32 i;
    s32 row;
    s32 x;
    s32 cont;
    u32 *cursor;
    u32 value;
    u32 mask;
    u32 newAddr;
    s32 shift;
    s32 slotIdx;
    s32 nibbleIdx;
    u32 nibbles;
    s32 moduleId;
    s32 moduleAddress;
    s32 linesLogged;
    MemoryPoolSlot *base;
    MemoryPoolSlot *slot;
    u32 tag;
    u32 tagAddr;
    s32 tagType;

    // Anti Piracy Check
    if ((D_800A3B74 == 0) || (D_80000310 != 0x17D9)) {
        while (1) {}
    }

    if (D_800A6E98 == 0) {
        maxPage = D_800A6E94 / 20;
        if ((D_800A6E94 % 20) != 0) {
            maxPage += 1;
        }
    } else {
        maxPage = 0x19;
    }
    maxPage += 5;

    if (viGetVideoMode() != 0) {
        D_800A6EDC = 1;
    } else {
        D_800A6EDC = 0;
    }
    memAddr = 0x80100000;

    for (i = 0; i < 100; i++) {
        func_8006869C();
    }
    if (debugMenuEnable == 0) {
        osWritebackDCacheAll();
        while (1) {}
    }
    osViSetSpecialFeatures(0xA2);

    while (1) {
        joyRead(0, 2);
        pressed = joyGetPressed(0);

        if (pressed & 0x8000) {
            page += 1;
        } else if (pressed & 0x4000) {
            page -= 1;
        }
        if (page < 0) {
            page = maxPage;
        }
        if (maxPage < page) {
            page = 0;
        }

        // Page 1: move the highlighted nibble and edit the address
        if (lastPage == 1) {
            if (pressed & 2) {
                redraw = 1;
                nibbleCursor += 1;
                if (nibbleCursor >= 6) {
                    nibbleCursor = 1;
                }
            }
            if (pressed & 1) {
                redraw = 1;
                nibbleCursor -= 1;
                if (nibbleCursor <= 0) {
                    nibbleCursor = 5;
                }
            }
            if (pressed & 0xC) {
                redraw = 1;
                shift = nibbleCursor * 4;
                mask = 0xFU << shift;
                if (pressed & 8) {
                    newAddr = memAddr + (1U << shift);
                } else {
                    newAddr = memAddr - (1U << shift);
                }
                newAddr = (newAddr & mask) | (memAddr & ~mask);
                if (newAddr >= 0x803FFF60U) {
                    newAddr = 0x803FFF60;
                }
                if (newAddr < 0x80000451U) {
                    newAddr = 0x80000450;
                }
                memAddr = newAddr;
            }
        }

        // Page 5: scroll the memory pool table and switch pool
        if (lastPage == 5) {
            if (pressed & 0x800) {
                slotScroll -= 0x12;
                redraw = 1;
                if (slotScroll < 0) {
                    slotScroll = 0;
                }
            }
            if (pressed & 0x400) {
                slotScroll += 0x12;
                redraw = 1;
            }
            if ((pressed & 8) && (slotScroll > 0)) {
                slotScroll -= 1;
                redraw = 1;
            }
            if (pressed & 4) {
                slotScroll += 1;
                redraw = 1;
            }
            if (pressed & 0x2000) {
                redraw = 1;
                memRegion ^= 1;
            }
        }

        if (pressed & 0x10) {
            redraw = 1;
            D_800A6EDC += 1;
            if (D_800A6EDC >= 3) {
                D_800A6EDC = 0;
            }
        }

        if ((lastPage != page) || (redraw != 0)) {
            switch (page) {
                case 0:
                    lastPage = page;
                    redraw = 0;
                    render_epc_lock_up_display((epcInfo *) thread);
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    func_8006869C();
                    if (page == 1) {
                        cursor = (u32 *) (memAddr + 0xA0);
                    } else if (page == 2) {
                        cursor = &D_80102600_B1AA0;
                    } else if (page == 3) {
                        cursor = &D_801026A8_B1B48;
                    } else {
                        cursor = &D_80102750_B1BF0;
                    }
                    x = 0xA8;
                    do {
                        row = 0x14;
                        do {
                            cursor -= 1;
                            value = *cursor;
                            cpuXYPrintf(x, (row + 3) * 8, "%08x:%08x", (u32) cursor, value);
                            if ((page == 1) && (row == 1)) {
                                row = 0;
                            }
                            // asm: branch on the old row value, decrement sits in the delay slot
                            cont = (row != 0);
                            row -= 1;
                        } while (cont);
                        x -= 0x94;
                    } while (x != -0x80);
                    lastPage = page;
                    redraw = 0;
                    break;
                case 5:
                    slotIdx = 0;
                    row = 0x2C;
                    func_8006869C();
                    D_800A6EE0 = 1;
                    cpuXYPrintf(0x64, 0x18, "MEMORY REGION %d", memRegion);
                    D_800A6EE0 = 2;
                    cpuXYPrintf(0x20, 0x20, "MOD");
                    cpuXYPrintf(0x48, 0x20, "OFFSET");
                    cpuXYPrintf(0x98, 0x20, "SIZE");
                    cpuXYPrintf(0xE0, 0x20, "ADDRESS");
                    D_800A6EE0 = 0;
                    base = mmGetSlotPtr(memRegion);
                    slot = base;
                    do {
                        if (slot->flags != 0) {
                            if ((slotIdx >= slotScroll) && (slotIdx < (slotScroll + 0x12))) {
                                tag = slot->colourTag;
                                tagAddr = tag & 0xFFFFFF;
                                tagType = (tag >> 24) & 0xFF;
                                if (tagType == 0xFF) {
                                    cpuXYPrintf(0x20, row, "Texture %d", tagAddr);
                                } else if (tagType == 0xFE) {
                                    cpuXYPrintf(0x20, row, "Module %d", tagAddr);
                                } else {
                                    cpuXYPrintf(0x20, row, "%d", tagType);
                                    cpuXYPrintf(0x48, row, "%08x", tagAddr);
                                }
                                cpuXYPrintf(0x98, row, "%d", slot->size);
                                cpuXYPrintf(0xE0, row, "%08x", (u32) slot->data);
                                row += 8;
                            }
                            slotIdx += 1;
                        }
                        slot = base + slot->nextIndex;
                    } while (slot->nextIndex != -1);
                    lastPage = page;
                    redraw = 0;
                    break;
                default:
                    lastPage = page;
                    redraw = 0;
                    /* sig mismatch: asm also passes $a1 (pressed buttons); callee ignores it */
                    ((void (*)(s32, u16)) func_80067AA0)((page * 0x14) - 0x50, pressed);
                    break;
            }

            if (page == 1) {
                if (runlinkGetAddressInfo(memAddr, &moduleId, &moduleAddress, NULL) != 0) {
                    D_800A6EE0 = 1;
                    cpuXYPrintf(0x14, 0x18, "Module %d at %08x", moduleId, moduleAddress);
                    D_800A6EE0 = 0;
                }
                nibbles = memAddr;
                nibbleIdx = 0;
                do {
                    if (nibbleIdx == nibbleCursor) {
                        D_800A6EE0 = 1;
                    }
                    cpuXYPrintf(0x4C - (nibbleIdx * 8), 0x20, "%1x", nibbles & 0xF);
                    nibbleIdx += 1;
                    D_800A6EE0 = 0;
                    nibbles = (u32) ((s32) nibbles >> 4);
                } while (nibbleIdx != 8);
            }

            if (D_800A6E98 == 0) {
                linesLogged = D_800A6E94;
            } else {
                linesLogged = 0x1F4;
            }
            cpuXYPrintf(0x32, 0xC8, "%d lines logged", linesLogged);
            cpuXYPrintf(0xDC, 0xC8, "Page %d/%d", page + 1, maxPage + 1);
        }

        osWritebackDCacheAll();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/func_80067880.s")
#endif

UNUSED void diCpuReportWatchpoint(u32 address) {
    s32 moduleAddress;
    s32 moduleId;
    s32 i;
    for (i = 0; i < 100; i++) {
        func_8006869C();
    }
    cpuXYPrintf(30, 80, "Watchpoint exception at %x\n", address);
    if (runlinkGetAddressInfo(address, &moduleId, &moduleAddress, NULL)) {
        cpuXYPrintf(30, 100, "Module %d at %08x", moduleId, moduleAddress);
    }
    while (1) {} // Infinite loop; waiting for the player to reset the console?
}

#ifdef VERSION_kiosk
const char D_800AF4DC[] = "%04d: %04d: %s";
const char D_800AF4EC[] = "Fault in thread %d   (%s)";
const char D_800AF508[] = "epc NULL";
const char D_800AF514[] = "epc %d,%x,%s";
const char D_800AF524[] = "epc %08x,?,?,?";
const char D_800AF534[] = "ra   NULL";
const char D_800AF540[] = "ra   %d,%x,%s";
const char D_800AF550[] = "ra   %08x,?,?,?";
const char D_800AF560[] = " cause\t\tmmAlloc(%d,%8x)\n";
const char D_800AF57C[] = "%s exception";
const char D_800AF58C[] = "cause\t\t\t%08x";
const char D_800AF59C[] = "crashed %s %s";
const char D_800AF5AC[] = "crashed %s type %d";
const char D_800AF5C0[] = "crashed %s unknown";
const char D_800AF5D4[] = "error %s %s";
const char D_800AF5E0[] = "error %s type %d";
const char D_800AF5F4[] = "error %s unknown";
const char D_800AF608[] = "aborted %s %s";
const char D_800AF618[] = "aborted %s type %d";
const char D_800AF62C[] = "aborted %s unknown";
const char D_800AF640[] = "badvaddr\t%08x";
const char D_800AF650[] = "free ram\t\t%08x";
const char D_800AF660[] = "at 0x%08x v0 0x%08x";
const char D_800AF674[] = "v1 0x%08x a0 0x%08x";
const char D_800AF688[] = "a1 0x%08x a2 0x%08x";
const char D_800AF69C[] = "a3 0x%08x t0 0x%08x";
const char D_800AF6B0[] = "t1 0x%08x t2 0x%08x";
const char D_800AF6C4[] = "t3 0x%08x t4 0x%08x";
const char D_800AF6D8[] = "t5 0x%08x t6 0x%08x";
const char D_800AF6EC[] = "t7 0x%08x s0 0x%08x";
const char D_800AF700[] = "s1 0x%08x s2 0x%08x";
const char D_800AF714[] = "s3 0x%08x s4 0x%08x";
const char D_800AF728[] = "s5 0x%08x s6 0x%08x";
const char D_800AF73C[] = "s7 0x%08x t8 0x%08x";
const char D_800AF750[] = "t9 0x%08x gp 0x%08x";
const char D_800AF764[] = "sp 0x%08x s8 0x%08x";
const char D_800AF778[] = "sr 0x%08x";
const char D_800AF784[] = "Level is\t\t\t%s";
const char D_800AF794[] = "Position is\t%.1f, %.1f, %.1f";
const char D_800AF7B4[] = "Track polygon buffer overflow";
const char D_800AF7D4[] = "Track edge buffer overflow";
const char D_800AF7F0[] = "Object polygon buffer overflow";
const char D_800AF810[] = "Object edge buffer overflow";
#endif

#if 0 /* old NON_EQUIVALENT attempt */
extern s32 D_800A6E90;
extern s32 D_800A6E94;
extern s32 D_800A6E98;

void diCpuLogMessage(const char *format, ...) {
    va_list args;
    char sp20[255];
    s32 i;
    char *var_v0;
    char *var_a1;
    char var_a0;

    va_start(args, format);
    vsprintf(&sp20, format, &args);
    va_end(args);

    var_a1 = (D_800A6E94 * 41) + 0x80700000;
    var_v0 = &sp20;
    i = 0;
    if (var_v0[i] != 0) {
        var_a0 = sp20[i];
    loop_2:
        *var_a1 = var_a0;
        var_a0 = var_v0[1];
        var_a1 += 1;
        var_v0 += 1;
        i++;
        if (var_a0 != 0 && i < 40) {
            goto loop_2;
        }
    }
    *var_a1 = 0;
    D_800A6E94++;
    if (D_800A6E94 >= 500) {
        D_800A6E98 = 1;
        D_800A6E94 = 0;
    }
    if (D_800A6E98 != 0) {
        D_800A6E90 = D_800A6E94;
    }
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void diCpuLogMessage(const char *format, ...) {
    va_list args;
    char buf[255];
    s32 i;
    u8 *dst;

    va_start(args, format);
    vsprintf(buf, format, args);
    va_end(args);

    dst = (u8 *) (D_800A6E94 * 0x29 + 0x80700000);
    for (i = 0; (buf[i] != 0) && (i < 0x28); i++) {
        dst[i] = buf[i];
    }
    dst[i] = 0;
    D_800A6E94 += 1;
    if (D_800A6E94 >= 0x1F4) {
        D_800A6E98 = 1;
        D_800A6E94 = 0;
    }
    if (D_800A6E98 != 0) {
        D_800A6E90 = D_800A6E94;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/diCpuLogMessage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80067AA0(s32 arg0) {
    s32 done = 0;
    s32 line = 0;
    s32 idx;
    s32 y = 0x1E;

    func_8006869C();
    idx = arg0 + D_800A6E90;
    if (idx >= 0x1F4) {
        idx -= 0x1F4;
    }
    do {
        if ((D_800A6E98 == 0) && (idx >= D_800A6E94)) {
            done = 1;
        }
        if (!done) {
            cpuXYPrintf(0x14, y, "%04d: %04d: %s", line + arg0, idx, (char *) (idx * 0x29 + 0x80700000));
            idx += 1;
            y += 8;
            if (idx >= 0x1F4) {
                idx -= 0x1F4;
            }
        }
        line += 1;
    } while ((line < 0x14) && !done);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/func_80067AA0.s")
#endif

void render_epc_lock_up_display(epcInfo *arg0);

void diCpuTraceMallocFault(s32 epc, s32 size, u32 colourTag) {
    epcInfo epcinfo;
    bzero(&epcinfo, sizeof(epcInfo));
    epcinfo.epc = epc & 0xFFFFFFFFFFFFFFFF;
    epcinfo.a0 = size;
    epcinfo.a1 = colourTag;
    epcinfo.cause = -1;
    render_epc_lock_up_display(&epcinfo);
    osWritebackDCacheAll();
    while (1) {}
}

s32 diCpuTraceGetFault(void) {
    return 0;
}

void diCpuTraceTick(s32 arg0) {
    D_800A6E8C += arg0;
    if (D_800A6E8C > 60) {
        D_800A6E8C = 0;
        D_800A6E88++;
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void render_epc_lock_up_display(epcInfo *arg0) {
    s32 moduleId;
    s32 moduleAddress;
    u32 *moduleInfo;
    u8 *regs = (u8 *) arg0 + 0x20; /* regs + k == arg0 + 0x20 + k (at, v0, ... sr, cause, badvaddr) */
    s32 epc;
    u32 ra;
    u32 cause;
    u32 idx;
    void *level;
    void *player;
    u8 trackStatus;

    func_8006869C();
    cpuXYPrintf(0x20, 0x18, "Fault in thread %d   (%s)", arg0->thread[0], D_800A6E80);
    epc = arg0->epc;
    if (epc == 0) {
        cpuXYPrintf(0x20, 0x22, "epc NULL");
    } else if (runlinkGetAddressInfo((u32) epc, &moduleId, &moduleAddress, &moduleInfo) != 0) {
        cpuXYPrintf(0x20, 0x22, "epc %d,%x", moduleId, moduleAddress);
    } else {
        cpuXYPrintf(0x20, 0x22, "epc %08x,?,?,?", *(u32 *) (regs + 0xFC));
    }
    ra = *(u32 *) (regs + 0xE4);
    if (ra == 0) {
        cpuXYPrintf(0x20, 0x28, "ra   NULL");
    } else if (runlinkGetAddressInfo(ra, &moduleId, &moduleAddress, &moduleInfo) != 0) {
        cpuXYPrintf(0x20, 0x28, "ra   %d,%x", moduleId, moduleAddress);
    } else {
        cpuXYPrintf(0x20, 0x28, "ra   %08x,?,?,?", *(u32 *) (regs + 0xE4));
    }
    cause = *(u32 *) (regs + 0x100);
    if (cause == -1U) {
        cpuXYPrintf(0x20, 0x2E, " cause\t\tmmAlloc(%d,%8x)\n", *(s32 *) (regs + 0x1C), *(s32 *) (regs + 0x24));
    } else {
        idx = (cause >> 2) & 0x1F;
        if (idx < 0x10U) {
            cpuXYPrintf(0x20, 0x2E, "%s exception", D_800A6E9C[idx]);
        } else {
            cpuXYPrintf(0x20, 0x2E, "cause\t\t\t%08x", cause);
        }
    }
    if ((D_800A3348_A3F48 != 4) && (D_800A333C_A3F3C != 0)) {
        switch (D_800A3348_A3F48) {
            case 1:
                if (D_800A3344_A3F44 != 0) {
                    cpuXYPrintf(0x20, 0x34, "crashed %s %s", errorStringPointers[D_800A333C_A3F3C], (char *) D_800A3344_A3F44);
                } else if (D_800A3340_A3F40 != NULL) {
                    cpuXYPrintf(0x20, 0x34, "crashed %s type %d", errorStringPointers[D_800A333C_A3F3C], *(s16 *) ((u8 *) D_800A3340_A3F40 + 0x48));
                } else {
                    cpuXYPrintf(0x20, 0x34, "crashed %s unknown", errorStringPointers[D_800A333C_A3F3C]);
                }
                break;
            case 3:
                if (D_800A3344_A3F44 != 0) {
                    cpuXYPrintf(0x20, 0x34, "error %s %s", errorStringPointers[D_800A333C_A3F3C], (char *) D_800A3344_A3F44);
                } else if (D_800A3340_A3F40 != NULL) {
                    cpuXYPrintf(0x20, 0x34, "error %s type %d", errorStringPointers[D_800A333C_A3F3C], *(s16 *) ((u8 *) D_800A3340_A3F40 + 0x48));
                } else {
                    cpuXYPrintf(0x20, 0x34, "error %s unknown", errorStringPointers[D_800A333C_A3F3C]);
                }
                break;
            case 2:
                if (D_800A3344_A3F44 != 0) {
                    cpuXYPrintf(0x20, 0x34, "aborted %s %s", errorStringPointers[D_800A333C_A3F3C], (char *) D_800A3344_A3F44);
                } else if (D_800A3340_A3F40 != NULL) {
                    cpuXYPrintf(0x20, 0x34, "aborted %s type %d", errorStringPointers[D_800A333C_A3F3C], *(s16 *) ((u8 *) D_800A3340_A3F40 + 0x48));
                } else {
                    cpuXYPrintf(0x20, 0x34, "aborted %s unknown", errorStringPointers[D_800A333C_A3F3C]);
                }
                break;
        }
    } else {
        cpuXYPrintf(0x20, 0x34, "badvaddr\t%08x", *(u32 *) (regs + 0x104));
    }
    cpuXYPrintf(0x20, 0x3A, "free ram\t\t%08x", FreeRAM);
    cpuXYPrintf(0x20, 0x44, "at 0x%08x v0 0x%08x", *(u32 *) (regs + 0x4), *(u32 *) (regs + 0xC));
    cpuXYPrintf(0x20, 0x4A, "v1 0x%08x a0 0x%08x", *(u32 *) (regs + 0x14), *(u32 *) (regs + 0x1C));
    cpuXYPrintf(0x20, 0x50, "a1 0x%08x a2 0x%08x", *(u32 *) (regs + 0x24), *(u32 *) (regs + 0x2C));
    cpuXYPrintf(0x20, 0x56, "a3 0x%08x t0 0x%08x", *(u32 *) (regs + 0x34), *(u32 *) (regs + 0x3C));
    cpuXYPrintf(0x20, 0x5C, "t1 0x%08x t2 0x%08x", *(u32 *) (regs + 0x44), *(u32 *) (regs + 0x4C));
    cpuXYPrintf(0x20, 0x62, "t3 0x%08x t4 0x%08x", *(u32 *) (regs + 0x54), *(u32 *) (regs + 0x5C));
    cpuXYPrintf(0x20, 0x68, "t5 0x%08x t6 0x%08x", *(u32 *) (regs + 0x64), *(u32 *) (regs + 0x6C));
    cpuXYPrintf(0x20, 0x6E, "t7 0x%08x s0 0x%08x", *(u32 *) (regs + 0x74), *(u32 *) (regs + 0x7C));
    cpuXYPrintf(0x20, 0x74, "s1 0x%08x s2 0x%08x", *(u32 *) (regs + 0x84), *(u32 *) (regs + 0x8C));
    cpuXYPrintf(0x20, 0x7A, "s3 0x%08x s4 0x%08x", *(u32 *) (regs + 0x94), *(u32 *) (regs + 0x9C));
    cpuXYPrintf(0x20, 0x80, "s5 0x%08x s6 0x%08x", *(u32 *) (regs + 0xA4), *(u32 *) (regs + 0xAC));
    cpuXYPrintf(0x20, 0x86, "s7 0x%08x t8 0x%08x", *(u32 *) (regs + 0xB4), *(u32 *) (regs + 0xBC));
    cpuXYPrintf(0x20, 0x8C, "t9 0x%08x gp 0x%08x", *(u32 *) (regs + 0xC4), *(u32 *) (regs + 0xCC));
    cpuXYPrintf(0x20, 0x92, "sp 0x%08x s8 0x%08x", *(u32 *) (regs + 0xD4), *(u32 *) (regs + 0xDC));
    cpuXYPrintf(0x20, 0x98, "sr 0x%08x", *(u32 *) (regs + 0xF8));
    level = levelGetLevel();
    if ((level != NULL) && (((u32) level) & 0x80000000)) {
        cpuXYPrintf(0x20, 0xA4, "Level is\t\t\t%s", level);
    }
    player = objGetPlayerNo(0);
    if ((player != NULL) && (((u32) player) & 0x80000000)) {
        cpuXYPrintf(0x20, 0xAA, "Position is\t%.1f, %.1f, %.1f", (u8 *) player + 0xC, (u8 *) player + 0x10, (u8 *) player + 0x14);
    }
    trackStatus = cpuTraceTrackBufStatus;
    if (trackStatus & 1) {
        cpuXYPrintf(0x20, 0xB0, "Track polygon buffer overflow");
    }
    if (trackStatus & 2) {
        cpuXYPrintf(0x20, 0xB6, "Track edge buffer overflow");
    }
    if (trackStatus & 4) {
        cpuXYPrintf(0x20, 0xBC, "Object polygon buffer overflow");
    }
    if (trackStatus & 8) {
        cpuXYPrintf(0x20, 0xC2, "Object edge buffer overflow");
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/render_epc_lock_up_display.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800683D0(s32 arg0, s32 arg1, u16 *arg2) {
    s32 width;
    s32 height;
    u16 *palette;
    u16 *row = arg2;
    u16 *dst;
    s32 rowsDrawn;
    s32 lines;
    u16 pixel;
    u16 bits;
    u16 pixelDst;

    viGetCurrentSize(&width, &height);
    dst = (u16 *) ((u8 *) otherScreen + (((arg1 * width) + arg0) * 2));
    if (D_800A6EE0 == 2) {
        palette = D_800A7138;
    } else if (D_800A6EE0 != 0) {
        palette = D_800A7130;
    } else {
        palette = D_800A7128;
    }
    /* asm: bnez delay-slot loop, 5 glyph rows (0xA bytes per glyph) */
    for (lines = 4; lines >= 0; lines--) {
        rowsDrawn = (D_800A6EDC != 0) ? 2 : 1;
        for (; rowsDrawn > 0; rowsDrawn--) {
            bits = *row;
            pixelDst = 0;
            if (bits != 0) {
                do {
                    pixel = palette[bits & 3];
                    bits = (bits >> 2) & 0xFFFF;
                    dst[pixelDst] = pixel;
                    pixelDst++;
                } while (bits != 0);
            }
            dst = (u16 *) ((u8 *) dst + (width * 2));
        }
        row++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/func_800683D0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800684F0(s32 x, s32 y, char *s) {
    s32 posX = x;
    s32 posY = y;
    u8 *p = (u8 *) s;
    u8 c;

    c = *p;
    while (c != 0) {
        if ((c >= 0x61) && (c < 0x7B)) {
            c -= 0x20;
        }
        if (c == 0xA) {
            posY += 6;
            posX = 0x20;
        } else if (c == 9) {
            posX = (posX & ~0xF) + 0x10;
        } else if (c == 0x20) {
            posX += 4;
        } else if ((c >= 0x21) && (c < 0x5B)) {
            func_800683D0(posX, posY, (u16 *) (D_800A6EE4 + (c * 10) - 0x14A));
            posX += 8;
        }
        p++;
        c = *p;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diCpu/func_800684F0.s")
#endif

void cpuXYPrintf(s32 x, s32 y, const char *format, ...) {
    va_list args;
    char s[255];

    va_start(args, format);
    vsprintf(s, format, args);
    va_end(args);

    if (D_800A6EDC != 0) {
        if (D_800A6EDC == 1) {
            y -= 8;
        } else {
            y -= 104;
        }
        if (y >= 0 && y < 116) {
            y *= 2;
            goto block_7;
        }
    } else {
    block_7:
        func_800684F0(x, y, s);
    }
}

// Zeroes out `otherScreen`
void func_8006869C(void) {
    UNUSED s32 pad;
    s32 height;
    s32 width;
    s32 screenSize;
    s16 *var_v1;

    viGetCurrentSize(&height, &width);
    screenSize = height * width;
    var_v1 = otherScreen;
    while (screenSize--) {
        *var_v1 = 0;
        var_v1++;
    }
}

void __rmonSendFault(OSThread *thread) {
    volatile float f UNUSED;
    u8 *tPtr;
    u32 sent = 0;

    /* touch fpu to ensure registers are saved to the context structure */
    f = 0.0f;

    tPtr = (u8 *) thread;
    // sizeof(OSThread) in original, 0x230 in this.
    // TrapDanglingJump is __osRdbSend in the orginal
    while (sent < 0x230) {
        sent += TrapDanglingJump(tPtr + sent, 0x230 - sent, RDB_TYPE_GtoH_FAULT);
    }
}
