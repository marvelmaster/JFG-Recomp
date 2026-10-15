#include "common.h"

/* decomp: externs */
void *objSetupObject(void *params, s32 arg1);
void GetRomlistInfo(void **, s32 *, s32);
void doorRegisterOpener(u8, s32);
s32 levelGetObjectID(u8);
s32 objGetControlNo(s16);
Object **objGetObjList(s32 *, s32 *);
f32 GetRange(f32, f32, f32, f32, f32, f32);
s16 mathDiffAngle(s16, s16);
void frontFreeMenuFrame(s32, s16, s16, s16, s32, s32, s32);
void AIJunctionInit(void *);
void AIJunctionControl(void *, s32);
void CopyStaticsToSquads(void *, void *);
s32 GetClosestPatrolNode(s32, void *); /* sig from asm: (0, obj) */
s32 GetNextNodeNumber(f32, f32, f32, s32); /* sig from asm: x, y, z (in a2), 0 */
s32 squadsAddToActiveSquaddies(u8, u8, s32, void *); /* sig from asm: 4 args */
void ReallyAddInterestingEvent(void *);
void doorUnlock(u8, s32);
s32 levelObjectFlagSet(s32);
extern void **animpath;

const char D_800AD890[] = "CRITICAL ERROR: objSetupObject() returned NULL\n";
const char D_800AD8C0[] = "GFDS:%d ???\n";
const char D_800AD8D0[] = "**** WARNING: Duplicate squadron ID:%d ****\n";
const char D_800AD900[] = "WARNING:Can't lock to node, no nodes\n";

// .data
u32 *BaddyDataArray = NULL; // Effectively unused
u32 *D_800A4334 = NULL;     // Unknown type

// .bss
void *D_800FF6B0;
void *DisactivatedSquaddies;
s32 D_800FF6B8;
s32 D_800FF6BC;
s32 SquadsModuleFlags;
#ifdef VERSION_kiosk
u8 D_800FF6C4[5];
#else
u8 D_800FF6C4[0x35];
#endif
u8 D_800FF6C9; // Linked with above?
u8 squadsBehaviour;
s32 D_800FF6CC;
s32 SquaddieGrowlTimer;
s32 iDeltaTime;
s32 PlayersDisguise;
RomDefHeader *GlobalStartOfRomdefList;
s32 GlobalSizeOfRomdefList;
Object *D_800FF6E4;
Object_Racer *D_800FF6E8; // Could be any Object64 from DKR
Object *D_800FF6EC;
Object_Racer *D_800FF6F0; // Not sure if array, or not. Could be any Object64 from DKR
UNUSED u8 PathLists[0x3C];
s32 *D_800FF734;
UNUSED u8 AnimPathNumbers[0x40];
s32 MaxPatrolNodes;
void *PatrolNodes;

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 squadsIsTribal(s32 arg0) {
    if (arg0 >= 0x11C && arg0 < 0x121) {
        return 1;
    }
    return arg0 == 0x66 || arg0 == 0x70 || arg0 == 0x90 || arg0 == 0x97 || arg0 == 0x157 || arg0 == 0xA5;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsIsTribal.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u32 *squadsGetSquadronList(s32 *arg0) {
    *arg0 = D_800FF6CC;
    return D_800A4334;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsGetSquadronList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 BaddyTypeToIndex(s32 arg0) {
    switch (arg0) {
    case 0x29:
        return 0;
    case 0x5F:
        return 1;
    case 0xBE:
        return 2;
    case 0xBD:
        return 3;
    case 0x67:
        return 4;
    case 0x78:
        return 5;
    case 0x8C:
        return 6;
    case 0x83:
        return 7;
    case 0x2A:
        return 9;
    case 0x2B:
        return 8;
    case 0x2D:
        return 0xA;
    case 0x54:
        return 0xB;
    case 0x68:
        return 0xC;
    case 0x8D:
        return 0xD;
    case 0x99:
        return 0xE;
    case 0x9C:
        return 0xF;
    case 0xDF:
        return 0x10;
    case 0xE0:
        return 0x11;
    case 0xE1:
        return 0x12;
    case 0xE6:
        return 0x13;
    case 0xEE:
        return 0x14;
    case 0xEF:
        return 0x15;
    case 0x12F:
        return 0x16;
    case 0xF2:
        return 0x17;
    case 0xF3:
        return 0x18;
    case 0x66:
        return 0x19;
    case 0x11C:
        return 0x1A;
    case 0x11D:
        return 0x1B;
    case 0x11E:
        return 0x1C;
    case 0x11F:
        return 0x1D;
    case 0x120:
        return 0x1E;
    case 0x121:
        return 0x1F;
    case 0xF1:
        return 0x20;
    case 0xF5:
        return 0x21;
    case 0xF6:
        return 0x22;
    case 0x122:
        return 0x23;
    case 0x143:
        return 0x24;
    case 0x144:
        return 0x25;
    case 0x149:
        return 0x26;
    case 0x150:
        return 0x27;
    case 0x151:
        return 0x28;
    case 0x152:
        return 0x29;
    case 0x153:
        return 0x2A;
    case 0x166:
        return 0x2B;
    case 0x70:
        return 0x2C;
    case 0x90:
        return 0x2D;
    case 0xA5:
        return 0x2E;
    case 0x97:
        return 0x2F;
    case 0x157:
        return 0x30;
    case 0x112:
        return 0x31;
    case 0x6D:
        return 0x32;
    case 0x1E5:
        return 0x33;
    case 0x269:
        return 0x34;
    case 0x2CE:
        return 0x35;
    default:
        return -1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/BaddyTypeToIndex.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CreateStaticInstance(s32 arg0) {
    struct {
        s16 id;      /* 0x00 */
        u8 unk2;     /* 0x02 */
        s16 unk4;    /* 0x04 */
        s16 unk6;    /* 0x06 */
        s16 unk8;    /* 0x08 */
        s16 unkA;    /* 0x0A */
        s16 unkC;    /* 0x0C */
        s16 yRotation; /* 0x0E */
        u8 unk10;    /* 0x10 */
    } setup;
    u8 *flag;
    Object *obj;

    flag = &D_800FF6C4[BaddyTypeToIndex(arg0)];
    if (*flag == 0) {
        *flag = 1;
        D_800FF6F0 = NULL;
        setup.unk2 = 0x12;
        setup.unk4 = 0;
        setup.unk6 = 0;
        setup.unk8 = 0;
        setup.unkA = 0;
        setup.unkC = 0;
        setup.id = (s16) arg0;
        setup.unk10 = 0;
        setup.yRotation = D_800FF6EC->segment.trans.y_rotation;
        obj = objSetupObject(&setup, 4);
        D_800FF6E4 = obj;
        if (obj != NULL) {
            *(s32 *) ((u8 *) obj + 0x3C) = 0;
            D_800FF6E8 = obj->racer;
            obj->segment.trans.unk6 |= 0x400;
            *(s32 *) D_800FF6E8 = 0;
            D_800FF6E8->pad00[0] |= 8;
            *(s32 *) ((u8 *) D_800FF6E8 + 0x24) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/CreateStaticInstance.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsRememberRomdef(s32 arg0) {
    ((s32 *) D_800FF6BC)[(s32) D_800FF6B0] = arg0;
    D_800FF6B0 = (void *) ((s32) D_800FF6B0 + 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsRememberRomdef.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void AddToDisactivatedSquaddies(s32 arg0) {
    ((s32 *) DisactivatedSquaddies)[D_800FF6B8] = arg0;
    D_800FF6B8 += 1;
    if (D_800FF6B8 >= (s32) D_800FF6B0) {
        D_800FF6B8 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/AddToDisactivatedSquaddies.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *GetFirstDisactivatedSquaddie(s32 arg0) {
    void **slot;
    u8 *temp;
    s32 i;

    if ((s32) D_800FF6B0 >= 0x101) {
        return NULL;
    }
    if (DisactivatedSquaddies == NULL || (s32) D_800FF6B0 == 0) {
        return NULL;
    }
    slot = DisactivatedSquaddies;
    i = (s32) D_800FF6B0 - 1;
    do {
        temp = *slot;
        if (temp != NULL && arg0 == temp[0x11]) {
            *slot = NULL;
            return temp;
        }
        slot++;
    } while (i-- != 0);
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/GetFirstDisactivatedSquaddie.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsInitialiseBeforeObjects(void) {
    D_800FF6BC = (s32) mmAlloc(0x400, 0xFFFF00FFU);
    SquadsModuleFlags = 1;
    DisactivatedSquaddies = NULL;
    D_800FF6B0 = NULL;
    D_800FF6CC = 0;
    SquaddieGrowlTimer = mathRnd(0xF0, 0x168);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsInitialiseBeforeObjects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *GetSquadronFromIdentifier(s16 arg0) {
    s32 i;
    u8 *squadron;
    u8 *squadronData;

    if (D_800FF6CC == 0) {
        return NULL;
    }
    i = D_800FF6CC - 1;
    do {
        squadron = ((u8 **) D_800A4334)[i];
        if (squadron[0xA0] == 0) {
            squadronData = *(u8 **) (squadron + 0x68);
            if (arg0 == squadronData[0x64]) {
                return squadron;
            }
        }
    } while (i-- != 0);
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/GetSquadronFromIdentifier.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *GetSquaddieFromIdentifiers(s16 arg0, s16 arg1) {
    s32 i;
    u8 *squadron;
    u8 *squadronData;
    u8 *node;
    u8 *nodeData;

    if (D_800FF6CC == 0) {
        return NULL;
    }
    i = D_800FF6CC - 1;
    do {
        squadron = ((u8 **) D_800A4334)[i];
        squadronData = *(u8 **) (squadron + 0x68);
        if (arg0 == squadronData[0x64]) {
            node = *(u8 **) (squadronData + 0x58);
            if (node == NULL) {
                return NULL;
            }
            do {
                nodeData = *(u8 **) (node + 0x68);
                if (node[0xA0] == 0 && arg1 == nodeData[0x15]) {
                    return node;
                }
                node = *(u8 **) (nodeData + 0x28);
            } while (node != NULL);
            return NULL;
        }
    } while (i-- != 0);
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/GetSquaddieFromIdentifiers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsCheckEnemyPointers(s32 arg0) {
    s32 i;
    u8 *squadron;
    u8 *node;
    u8 *nodeData;

    if (D_800FF6CC == 0) {
        return;
    }
    i = D_800FF6CC - 1;
    do {
        squadron = ((u8 **) D_800A4334)[i];
        node = *(u8 **) (*(u8 **) (squadron + 0x68) + 0x58);
        while (node != NULL) {
            nodeData = *(u8 **) (node + 0x68);
            if (arg0 == *(s32 *) (nodeData + 0x64)) {
                *(s32 *) (nodeData + 0x64) = 0;
            }
            node = *(u8 **) (nodeData + 0x28);
        }
    } while (i-- != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsCheckEnemyPointers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsCheckGrenades(s32 arg0) {
    s32 i;
    u8 *squadron;
    u8 *node;
    u8 *nodeData;

    if (D_800FF6CC == 0) {
        return;
    }
    i = D_800FF6CC - 1;
    do {
        squadron = ((u8 **) D_800A4334)[i];
        node = *(u8 **) (*(u8 **) (squadron + 0x68) + 0x58);
        while (node != NULL) {
            nodeData = *(u8 **) (node + 0x68);
            if (arg0 == *(s32 *) (nodeData + 0xA8)) {
                *(s32 *) (nodeData + 0xA8) = 0;
                return;
            }
            node = *(u8 **) (nodeData + 0x28);
        }
    } while (i-- != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsCheckGrenades.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void GetFormationInfo(Object *obj, u8 *arg1, u8 *arg2, u8 *arg3) {
    f32 var_f0;
    u8 *data;
    u8 temp_v1;

    data = (u8 *) obj->racer;
    if (D_800FF6E8 != NULL && data != NULL && *(s16 *) (data + 0x2A) != 0) {
        var_f0 = (f32) *(s16 *) ((u8 *) D_800FF6E8 + 0xA6) / (f32) *(s16 *) (data + 0x2A);
    } else {
        var_f0 = 1.0f;
    }
    temp_v1 = data[0x30];
    if (temp_v1 == 3) {
        *arg1 = data[6];
        *arg2 = data[8];
        *arg3 = data[7];
    } else if (temp_v1 == 4 || (var_f0 * 100.0f) < (f32) (0x64 - data[0xD])) {
        *arg1 = data[9];
        *arg2 = data[0xB];
        *arg3 = data[0xA];
    } else {
        *arg1 = data[3];
        *arg2 = data[5];
        *arg3 = data[4];
    }
    data[0x32] = *arg3;
    data[0x31] = *arg1;
    if (*arg3 == 8 && D_800FF6E8 != NULL && (*(s32 *) D_800FF6E8 & 0x400000)) {
        *arg3 = 9;
        *(s16 *) (data + 0x2E) = 0;
    }
    if (data[0x33] != 0) {
        if (data[0x33] != 0x1A) {
            *arg3 = data[0x33];
            return;
        }
        *arg1 = 0xA;
        *arg3 = data[0x33];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/GetFormationInfo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 ProcessNodeChange(s32 arg0) {
    u8 *racer;
    u8 *node;
    u8 *prevNode;
    Object *target;
    f32 x;
    f32 y;
    f32 z;
    f32 range;
    s32 newIdx;
    s32 prevIdx;
    s16 packed;
    s16 yaw;
    s32 diff;

    racer = (u8 *) D_800FF6F0;
    newIdx = arg0 & 0xFF;
    if ((*(s16 *) (racer + 0x3C) & 0xFF) == newIdx) {
        return 0;
    }
    packed = (s16) ((*(s16 *) (racer + 0x3C) << 8) | newIdx);
    *(s16 *) (racer + 0x3C) = packed;
    prevIdx = ((u16) packed) >> 8;

    node = (u8 *) PatrolNodes + newIdx * 0x34;
    prevNode = (u8 *) PatrolNodes + prevIdx * 0x34;
    if (node[0x18] == 5) {
        if (prevNode[0x18] == 5) {
            racer[0x33] = 0x20;
        } else {
            racer[0x33] = 0x1D;
        }
    }

    if ((prevIdx & 0xFF) != 0) {
        x = *(f32 *) (node + 0);
        y = *(f32 *) (node + 4);
        z = *(f32 *) (node + 8);
    } else {
        target = *(Object **) (racer + 0x58);
        x = target->segment.trans.x_position;
        y = target->segment.trans.y_position;
        z = target->segment.trans.z_position;
    }
    *(s16 *) (racer + 0x66) = (s16) x;
    *(s16 *) (racer + 0x68) = (s16) y;
    *(s16 *) (racer + 0x6A) = (s16) z;
    *(s16 *) (racer + 0x40) = (s16) *(f32 *) (node + 0);
    *(s16 *) (racer + 0x42) = (s16) *(f32 *) (node + 4);
    *(s16 *) (racer + 0x44) = (s16) *(f32 *) (node + 8);

    range = GetRange(x, y, z, *(f32 *) (node + 0), *(f32 *) (node + 4), *(f32 *) (node + 8));
    if (range != 0.0f) {
        *(f32 *) (racer + 0x6C) = 0.0f;
        *(f32 *) (racer + 0x70) = (f32) (s8) racer[0x24] / range;
    } else {
        *(f32 *) (racer + 0x6C) = 1.0f;
        *(f32 *) (racer + 0x70) = 0.0f;
    }

    if (*(s32 *) (node + 0x14) & 4) {
        *(u16 *) (racer + 0x28) |= 0x1000;
        if (node[0x18] == 8 && mathRnd(1, 0x64) < (s32) node[0x19]) {
            *(u16 *) (racer + 0x28) &= 0xEFFF;
        }
    } else {
        *(u16 *) (racer + 0x28) &= 0xEFFF;
    }

    if (racer[0x33] != 0x1D) {
        if (racer[0] >= 2) {
            target = *(Object **) (racer + 0x58);
            *(s16 *) (racer + 0x3E) = Arctanf(target->segment.trans.x_position - *(f32 *) (node + 0),
                                              target->segment.trans.z_position - *(f32 *) (node + 8));
            diff = ((s16) mathDiffAngle(D_800FF6EC->segment.trans.y_rotation, *(s16 *) (racer + 0x3E))) >> 9;
            yaw = (s16) diff;
            if (yaw < 0) {
                yaw = -yaw;
            }
            if (yaw <= 0) {
                yaw = 1;
            }
            *(s16 *) (racer + 0x2E) = yaw;
            racer[0x33] = 0x15;
            racer[0x34] &= 0x03;
            squadsBehaviour = 0x15;
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/ProcessNodeChange.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80052900(void) {
    void *romlistBase[2];
    s32 romlistCount[2];
    s32 objStart;
    s32 objEnd;
    Object **objList;
    Object *obj;
    u8 *racer;
    u8 *entry;
    s32 i;
    s32 k;
    s32 levelObj;
    s32 total;
    s32 sum;
    u8 doorId;
    u8 step;

    GetRomlistInfo(&romlistBase[1], &romlistCount[1], 1);
    GetRomlistInfo(&romlistBase[0], &romlistCount[0], 0);

    objList = objGetObjList(&objStart, &objEnd);
    for (i = objStart; i < objEnd; i++) {
        obj = objList[i];
        if (*((u8 *) obj + 0xA0) != 0) {
            continue;
        }
        if (obj->behaviorId != 0x17) {
            continue;
        }
        racer = (u8 *) obj->racer;
        if (*(u16 *) (racer + 0x2C) == 0x2CE) {
            continue;
        }

        levelObj = levelGetObjectID(racer[0x01]);
        doorId = racer[0x75];
        *(s32 *) (racer + 0x88) = levelObj;
        *(s32 *) (racer + 0x8C) = levelObj;
        if (doorId != 0) {
            doorRegisterOpener(doorId, 0x20);
        }

        for (k = 0; k < 2; k++) {
            entry = (u8 *) romlistBase[k];
            total = romlistCount[k];
            sum = 0;
            if (total > 0) {
                do {
                    if (objGetControlNo(*(s16 *) entry) == 0x18 && racer[0x64] == entry[0x11]) {
                        entry[0x18] = (u8) *(s32 *) (racer + 0x8C);
                        *(s32 *) (racer + 0x8C) += 1;
                    }
                    step = entry[0x02];
                    sum += step;
                    entry += step;
                } while (sum < total);
            }
        }

        if (racer[0x63] >= racer[0x01]) {
            racer[0x30] = 7;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/func_80052900.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsInitialiseAfterObjects(void) {
    s32 objStart;
    s32 objEnd;
    Object **objList;
    Object *obj;
    Object *sq;
    u8 *racer;
    u8 *patrol;
    u8 *path;
    u8 *node;
    u8 *rec;
    u8 *clr;
    s32 *cursor;
    Object **objEntry;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 stop;
    s32 s0;
    s32 s1;
    s32 pathIdx;
    s32 nodeIdx;
    s32 flag;
    s32 off;

    if (runlinkIsModuleLoaded(3) == 0) {
        mmFree((void *) D_800FF6BC);
        return;
    }
    func_80052900();
    objList = objGetObjList(&objStart, &objEnd);
    D_800FF6B8 = 0;
    SquadsModuleFlags = 0x40;

    /* asm: clears 16 words walking down from the D_800FF734 variable, then
       AIJunctionInit on the final cursor (D_800FF734 - 0x40) */
    cursor = (s32 *) &D_800FF734;
    n = 0xF;
    do {
        *cursor = 0;
        cursor--;
    } while (n-- != 0);
    AIJunctionInit(cursor);

    /* behaviorId 0x1B objects: junction setup and per-racer path node marking */
    for (i = objStart; i < objEnd; i++) {
        obj = objList[i];
        if (*((u8 *) obj + 0xA0) == 0 && obj->behaviorId == 0x1B) {
            racer = (u8 *) obj->racer;
            AIJunctionControl(obj, *(s32 *) ((u8 *) obj + 0x3C));
            CopyStaticsToSquads(obj, NULL);
            /* asm: loop runs 4 times (s1 = 3..0), halfwords at racer+2*s1 */
            s1 = 3;
            do {
                pathIdx = *(s16 *) (racer + s1 * 2);
                if (pathIdx != -1) {
                    n = racer[s1 + 0xC];
                    path = (u8 *) animpath[pathIdx];
                    node = *(u8 **) (path + 0x20);
                    for (k = n; k != 0; k--) {
                        node = *(u8 **) (node + 0x28);
                    }
                    node[0x1E] = racer[0x11];
                }
            } while (s1-- != 0);
        }
    }

    /* reset patrol node flags */
    patrol = (u8 *) PatrolNodes;
    if (MaxPatrolNodes != 0) {
        n = MaxPatrolNodes - 1;
        do {
            patrol[0x2F] = 0;
            patrol += 0x34;
        } while (n-- != 0);
    }

    /* count behaviorId 0x17 objects (leftover entries first, then 4 at a time) */
    D_800FF6CC = 0;
    i = objStart;
    if (objStart < objEnd) {
        n = (objEnd - objStart) & 3;
        if (n != 0) {
            stop = objStart + n;
            do {
                obj = objList[i];
                i++;
                if (obj->behaviorId == 0x17) {
                    D_800FF6CC += 1;
                }
            } while (i != stop);
        }
        if (i != objEnd) {
            objEntry = &objList[i];
            do {
                if (objEntry[0]->behaviorId == 0x17) {
                    D_800FF6CC += 1;
                }
                if (objEntry[1]->behaviorId == 0x17) {
                    D_800FF6CC += 1;
                }
                if (objEntry[2]->behaviorId == 0x17) {
                    D_800FF6CC += 1;
                }
                if (objEntry[3]->behaviorId == 0x17) {
                    D_800FF6CC += 1;
                }
                objEntry += 4;
                i += 4;
            } while (i != objEnd);
        }
    }

    /* build the squadron array D_800A4334 */
    count = D_800FF6CC;
    if (count != 0) {
        D_800A4334 = (u32 *) mmAlloc(count * 4, 0xFFFF00FFU);
        s1 = 0;
        for (i = objStart; i < objEnd; i++) {
            obj = objList[i];
            if (obj->behaviorId == 0x17) {
                ((Object **) D_800A4334)[s1] = obj;
                s1 += 1;
                if (s1 - 1 > 0) {
                    /* asm: countdown loop with no memory effects, kept as in asm */
                    off = (s1 - 2) * 4;
                    do {
                        flag = off < 4;
                        off -= 4;
                    } while (flag == 0);
                }
            }
        }
    } else {
        D_800A4334 = NULL;
    }

    SquadsModuleFlags |= 8;
    clr = &D_800FF6C9;
    n = 0x35;
    do {
        *clr = 0;
        clr--;
    } while (n-- != 0);

    if (count != 0) {
        s1 = count - 1;
        do {
            obj = ((Object **) D_800A4334)[s1];
            D_800FF6EC = obj;
            D_800FF6F0 = obj->racer;
            CreateStaticInstance(*(u16 *) ((u8 *) obj->racer + 0x2C));
        } while (s1-- != 0);
    }
    SquadsModuleFlags &= ~8;

    if (count != 0) {
        s1 = count - 1;
        do {
            obj = ((Object **) D_800A4334)[s1];
            D_800FF6EC = obj;
            D_800FF6F0 = obj->racer;
            GetClosestPatrolNode(0, obj);
            if ((((u8 *) D_800FF6F0)[0x1A] & 0xF) == 6) {
                nodeIdx = GetNextNodeNumber(D_800FF6EC->segment.trans.x_position,
                                            D_800FF6EC->segment.trans.y_position,
                                            D_800FF6EC->segment.trans.z_position, 0);
                if (nodeIdx != 0) {
                    patrol = (u8 *) PatrolNodes + (nodeIdx & 0xFF) * 0x34;
                    if ((patrol[0x17] >> 6) != 0 && patrol != NULL) {
                        *(s16 *) ((u8 *) D_800FF6F0 + 0x3C) = patrol[0x16];
                        ProcessNodeChange(squadsAddToActiveSquaddies(((u8 *) D_800FF6F0)[0x30],
                                                                     (u8) *(s16 *) ((u8 *) D_800FF6F0 + 0x3C),
                                                                     0, patrol) & 0xFF);
                        ((u8 *) D_800FF6F0)[0x33] = 0x1F;
                    }
                } else {
                    ((u8 *) D_800FF6F0)[0x1A] = (((u8 *) D_800FF6F0)[0x1A] & 0xF0) | 2;
                }
            }
        } while (s1-- != 0);
    }

    /* rebuild DisactivatedSquaddies from D_800FF6BC records */
    if ((s32) D_800FF6B0 != 0) {
        DisactivatedSquaddies = (void *) mmAlloc((s32) D_800FF6B0 * 4, 0xFFFF00FFU);
        cursor = (s32 *) DisactivatedSquaddies;
        n = (s32) D_800FF6B0 - 1;
        do {
            *cursor = 0;
            cursor++;
        } while (n-- != 0);

        n = (s32) D_800FF6B0;
        j = n - 1;
        do {
            rec = (u8 *) ((s32 *) D_800FF6BC)[j];
            sq = GetSquadronFromIdentifier(rec[0x11]);
            D_800FF6EC = sq;
            racer = (u8 *) sq->racer;
            D_800FF6F0 = sq->racer;
            if ((*(u16 *) (racer + 0x1A) >> 12) == 1) {
                AddToDisactivatedSquaddies((s32) rec);
            } else {
                ReallyAddInterestingEvent(rec);
            }
        } while (j-- != 0);
    }
    mmFree((void *) D_800FF6BC);

    /* unlock doors for behaviorId 0x17 objects whose level flags are all set */
    objList = objGetObjList(&objStart, &objEnd);
    if (objStart < objEnd) {
        for (i = objStart; i < objEnd; i++) {
            obj = objList[i];
            if (obj->behaviorId == 0x17) {
                racer = (u8 *) obj->racer;
                D_800FF6F0 = obj->racer;
                if (racer[0x75] != 0) {
                    flag = 1;
                    s0 = 0;
                    if (racer[0x01] > 0) {
                        do {
                            if (levelObjectFlagSet(*(s32 *) ((u8 *) D_800FF6F0 + 0x88) + s0) == 0) {
                                flag = 0;
                                break;
                            }
                            s0 += 1;
                        } while (s0 < ((u8 *) D_800FF6F0)[0x01]);
                    }
                    if (flag != 0) {
                        doorUnlock(((u8 *) D_800FF6F0)[0x75], 0);
                        *(u16 *) ((u8 *) D_800FF6F0 + 0x28) |= 8;
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsInitialiseAfterObjects.s")
#endif

void squadsInit(void) {
    BaddyDataArray = piRomLoad(0x3E);
}

void squadsPreInit(RomDefHeader *list, s32 listSize) {
    RomDefHeader *header;
    s32 i;

    PlayersDisguise = 0;
    GlobalStartOfRomdefList = list;
    GlobalSizeOfRomdefList = listSize;
    header = list;
    for (i = 0; i < listSize;) {
        if (header->id == 0x61 || header->id == 5 || header->id == 0x4F) {
            runlinkDownloadCode(3);
            break;
        }
        i += header->size;
        header = (RomDefHeader *) ((u32) (header) + header->size);
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsAddInterestingEvent(s32 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6) {
    if (runlinkIsModuleLoaded(3) != 0) {
        frontFreeMenuFrame(arg0, arg1, arg2, arg3, (s32)arg4, (s32)arg5, (s32)arg6);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/squadsAddInterestingEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CopyStaticsToKernel(Object *arg0, Object *arg1) {
    D_800FF6E4 = arg0;
    if (arg0 != NULL) {
        D_800FF6E8 = arg0->racer;
    } else {
        D_800FF6E8 = NULL;
    }
    D_800FF6EC = arg1;
    if (arg1 != NULL) {
        D_800FF6F0 = arg1->racer;
    } else {
        D_800FF6F0 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/squads/CopyStaticsToKernel.s")
#endif
