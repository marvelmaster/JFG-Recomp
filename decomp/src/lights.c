#include "common.h"
#include "math.h"

/* decomp: externs */
extern void *D_800A18A0;
extern u8 D_800F65E8[];
void trackLightMove(void *, f32, f32, f32);
void trackLightDelete(void *, s32, s32, void *);
void trackLightColour(void *, s32, s32, s32, s32);
void updateColourCycle(unkResetColourCycle *arg0, s32 arg1);
void mathOneFloatPY(s16 *, f32 *, f32 *);
void mathOneFloatRPY(s16 *, f32 *, s8, s16);
s32 camlightAdd(void *arg0, void *arg1);
Object **objGetObjList(s32 *, s32 *);
void *camGetPtr(void);
void instLockMsg(void *, s32);
void matrix_SCL_RPY_XYZ(void *, void *);
void lightEnviroMap(s32, s32, s32, void *);
void lightMakeJointPositions(s16, f32 *, s32, void *, void *);
void lightMultiLight(s32, s32, f32 *, s32, void *, s32, s32);
void lightSingleLight(s32, s32, f32 *, void *, s32);
void lightTwoLights(s32, s32, void *, s32, f32 *, void *, s32);
f32 lightDirectionCalc(f32, f32, f32, f32, f32, f32, f32);
void lightSetObjectLight(void *, s32, s32, s16, s16, s32);
void func_80021B9C(void *, void *);
extern ObjectLightUnk70 *D_800F65E0;

void freeLights(void) {
    if (D_800A1898 != NULL) {
        mmFree(D_800A1898);
        D_800A1898 = NULL;
        D_800A189C = 0;
    }
    if (D_800F65E0 != NULL) {
        mmFree(D_800F65E0);
        D_800F65E0 = NULL;
    }
    if (D_800A18A0 != NULL) {
        mmFree(D_800A18A0);
        D_800A18A0 = NULL;
    }
    D_800A1894 = 0;
    D_800A1890 = 0;
}

#ifdef NON_MATCHING
extern s32 D_800A1890; // gMaxLights
extern void *D_800A18A0;

// Reasonably certain this 0x200 is the size of ObjectLightUnk70
#define SIZE_0X200 sizeof(ObjectLightUnk70)

void setupLights(s32 count, UNUSED s32 arg1, UNUSED s32 arg2) {
    s32 i;
    ObjectLight **buffer;

    freeLights();
    D_800A1890 = count;
    buffer = mmAlloc(D_800A1890 * (sizeof(s32 *) + sizeof(ObjectLight)), COLOUR_TAG_MAGENTA);
    D_800F65E0 = mmAlloc((D_800A1890 * SIZE_0X200) + SIZE_0X200, COLOUR_TAG_MAGENTA);
    D_800A18A0 = mmAlloc(SIZE_0X200 + 0x40, COLOUR_TAG_MAGENTA);
    D_800A1898 = buffer;
    D_800A189C = (ObjectLight *) &buffer[D_800A1890];
    for (i = 0; i < D_800A1890; i++) {
        D_800A1898[i] = &D_800A189C[i];
        D_800A189C[i].unk70 = &D_800F65E0[(i * SIZE_0X200)];
    }
    lightCreateLightTable(0xFF, 0xFF, 0xFF, D_800F65E0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/setupLights.s")
#endif

extern f32 D_800AC360; // = 0.3000000119f
void *trackLightAdd(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_80020D94(ObjectLight *arg0) {
    if (!(arg0->type & 0x40)) {
        arg0->unk6C = trackLightAdd(arg0->pos.z, arg0->unk1C, arg0->unk20, arg0->unk24 * 1.25f,
                                    arg0->unk24 * 0.3000000119f, (s32) (arg0->unk40 * arg0->unk43) >> 8,
                                    (s32) (arg0->unk41 * arg0->unk43) >> 8, (s32) (arg0->unk42 * arg0->unk43) >> 8);
    } else {
        arg0->unk6C = NULL;
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ObjectLight *addRomdefLight(s32 arg0, void *arg1) {
    u8 *def = (u8 *) arg1;
    u8 *light = NULL;
    u8 *lvlBase;

    if (D_800A1894 < D_800A1890) {
        light = (u8 *) D_800A1898[D_800A1894];
        D_800A1894 += 1;
        light[0x00] = (def[0x0A] >> 4) & 0xF;
        light[0x01] = def[0x0A] & 0xF;
        if ((def[0x0B] & 0xE0) == 0x40) {
            light[0x00] = 3;
        }
        light[0x02] = 7;
        light[0x04] = 0;
        light[0x03] = ~def[0x1F] & 0x61;
        *(s16 *)(light + 0x06) = -1;
        *(f32 *)(light + 0x08) = 0.0f;
        *(f32 *)(light + 0x0C) = 0.0f;
        *(f32 *)(light + 0x10) = 0.0f;
        *(s32 *)(light + 0x14) = 0;
        *(f32 *)(light + 0x18) = (f32) *(s16 *)(def + 0x04);
        *(f32 *)(light + 0x1C) = (f32) *(s16 *)(def + 0x06);
        *(f32 *)(light + 0x20) = (f32) *(s16 *)(def + 0x08);
        *(f32 *)(light + 0x24) = (f32) *(s16 *)(def + 0x10);
        *(f32 *)(light + 0x28) = *(f32 *)(light + 0x24);
        *(f32 *)(light + 0x2C) = *(f32 *)(light + 0x24);
        if (light[0x00] == 2) {
            *(f32 *)(light + 0x28) = (f32) *(s16 *)(def + 0x12);
        }
        *(f32 *)(light + 0x30) = *(f32 *)(light + 0x24) * *(f32 *)(light + 0x24);
        *(f32 *)(light + 0x34) = 1.0f / *(f32 *)(light + 0x24);
        light[0x40] = def[0x0C];
        light[0x41] = def[0x0D];
        light[0x42] = def[0x0E];
        light[0x43] = def[0x0F];
        *(f32 *)(light + 0x44) = (f32) def[0x0F];
        *(s32 *)(light + 0x54) = 0;
        if (def[0x1E] < 7) {
            s32 idx = def[0x1E] * 2;
            lvlBase = (u8 *) levelGetLevel();
            if (*(s16 *)(lvlBase + idx + 0x92) != -1) {
                initColourCycle((unkResetColourCycle *) (light + 0x48), *(s16 *)(lvlBase + idx + 0x92));
            }
        }
        *(s16 *)(light + 0x58) = *(s16 *)(def + 0x16);
        *(s16 *)(light + 0x5C) = *(s16 *)(def + 0x1A);
        *(s16 *)(light + 0x5A) = *(s16 *)(def + 0x18);
        *(s16 *)(light + 0x5E) = *(s16 *)(def + 0x1C);
        func_80020D94((ObjectLight *) light);
        func_80021444((unk800DC950 *) light, 0);
    }
    return (ObjectLight *) light;
}

s32 addObjectLight(Object *arg0, ObjectHeader48 *arg1) {
    u8 *rec = (u8 *) arg1;
    u8 *light = NULL;

    if (D_800A1894 < D_800A1890) {
        light = (u8 *) D_800A1898[D_800A1894];
        D_800A1894 += 1;
        light[0x00] = rec[0x00];
        light[0x01] = rec[0x01];
        light[0x02] = 7;
        light[0x03] = rec[0x02];
        *(u16 *)(light + 0x04) = *(u16 *)(rec + 0x04);
        *(s16 *)(light + 0x06) = (s8) rec[0x03];
        *(f32 *)(light + 0x08) = (f32) *(s16 *)(rec + 0x06);
        *(f32 *)(light + 0x0C) = (f32) *(s16 *)(rec + 0x08);
        *(Object **)(light + 0x14) = arg0;
        *(f32 *)(light + 0x18) = *(f32 *)(light + 0x08);
        *(f32 *)(light + 0x10) = (f32) *(s16 *)(rec + 0x0A);
        *(f32 *)(light + 0x1C) = *(f32 *)(light + 0x0C);
        *(f32 *)(light + 0x20) = *(f32 *)(light + 0x10);
        *(f32 *)(light + 0x24) = (f32) *(u16 *)(rec + 0x0C);
        *(f32 *)(light + 0x28) = *(f32 *)(light + 0x24);
        *(f32 *)(light + 0x2C) = *(f32 *)(light + 0x24);
        if (light[0x00] == 2) {
            *(f32 *)(light + 0x28) = (f32) *(u16 *)(rec + 0x0E);
        }
        *(f32 *)(light + 0x30) = *(f32 *)(light + 0x24) * *(f32 *)(light + 0x24);
        *(f32 *)(light + 0x34) = 1.0f / *(f32 *)(light + 0x24);
        light[0x40] = rec[0x10];
        light[0x41] = rec[0x11];
        light[0x42] = rec[0x12];
        light[0x43] = rec[0x13];
        *(f32 *)(light + 0x44) = (f32) rec[0x13];
        if (*(s16 *)(rec + 0x14) != -1) {
            initColourCycle((unkResetColourCycle *) (light + 0x48), (s32) *(s16 *)(rec + 0x14));
        } else {
            *(s32 *)(light + 0x54) = 0;
        }
        *(s16 *)(light + 0x5C) = 0;
        *(s16 *)(light + 0x58) = rec[0x16] << 8;
        *(s16 *)(light + 0x5E) = 0;
        *(s16 *)(light + 0x5A) = rec[0x17] << 8;
        func_80020D94((ObjectLight *) light);
        func_80021444((unk800DC950 *) light, 0);
    }
    return (s32) light;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/addRomdefLight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lights/addObjectLight.s")
#endif

void turnLightOff(UnkLight *light) {
    light->unk3 &= ~1;
}

void turnLightOn(UnkLight *light) {
    light->unk3 |= 1;
}

void toggleLight(UnkLight *light) {
    light->unk3 ^= 1;
}

void changeLightColour(UnkLight *light, u8 red, u8 green, u8 blue) {
    light->red = red;
    light->green = green;
    light->blue = blue;
    light->unk2 |= 2;
    light->unk54 = 0;
}

void changeLightColourCycle(s32 arg0, s32 arg1) {
    initColourCycle(arg0 + 0x48, arg1);
}

void changeLightIntensity(UnkLight *light, u8 intensity) {
    light->unk43 = intensity;
    light->unk44 = intensity;
    if (light->unk6C != 0) {
        light->unk2 |= 2;
    }
}

void lightUpdateLights(s32 arg0) {
    s32 i;
    for (i = 0; i < D_800A1894; i++) {
        func_80021444(D_800A1898[i], arg0);
    }
}

// Same as func_80032424 in DKR
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Same as func_80032424 in DKR
void func_80021444(unk800DC950 *arg0, s32 arg1) {
    u8 *l = (u8 *) arg0;
    u8 *parent = *(u8 **) (l + 0x14);
    s32 parentOk = (parent != NULL) && (*(u8 *) (parent + 0xA0) == 0);
    s16 rot[3];
    s32 t7;

    if (parentOk) {
        s16 idx = *(s16 *) (l + 0x06);
        if (idx >= 0) {
            u8 *tbl = *(u8 **) (parent + 0x6C);
            u8 *cfg = *(u8 **) (tbl + (*(s8 *) (parent + 0x3A) * 4));
            if (cfg != NULL && idx < *(u8 *) (*(u8 **) cfg + 0x2D)) {
                u8 *entry = *(u8 **) (cfg + 0x68) + idx * 0xC;
                *(f32 *) (l + 0x18) = *(f32 *) (entry + 0x0);
                *(f32 *) (l + 0x1C) = *(f32 *) (entry + 0x4);
                l[0x02] |= 1;
                *(f32 *) (l + 0x20) = *(f32 *) (entry + 0x8);
            }
        } else {
            pointListRPY(1, (s16 *) parent, (s32 *) (l + 0x08), (f32 *) (l + 0x18));
            *(f32 *) (l + 0x18) += *(f32 *) (parent + 0x0C);
            *(f32 *) (l + 0x1C) = *(f32 *) (l + 0x1C) + *(f32 *) (parent + 0x10);
            l[0x02] |= 1;
            *(f32 *) (l + 0x20) = *(f32 *) (l + 0x20) + *(f32 *) (parent + 0x14);
        }
        l[0x02] |= 4;
        if (*(void **) (l + 0x6C) != NULL) {
            trackLightMove(*(void **) (l + 0x6C), *(f32 *) (l + 0x18), *(f32 *) (l + 0x1C), *(f32 *) (l + 0x20));
        }
    }

    if (*(s32 *) (l + 0x54) != 0) {
        updateColourCycle((unkResetColourCycle *) (l + 0x48), arg1);
        l[0x40] = l[0x50];
        l[0x41] = l[0x51];
        l[0x42] = l[0x52];
        if (!(l[0x03] & 0x10)) {
            l[0x43] = l[0x53];
            *(f32 *) (l + 0x44) = (f32) l[0x53];
        }
        l[0x02] |= 2;
    }

    if (*(s16 *) (l + 0x5C) != 0) {
        l[0x02] |= 4;
        *(s16 *) (l + 0x58) = *(s16 *) (l + 0x58) + (*(s16 *) (l + 0x5C) * arg1);
    }
    if (*(s16 *) (l + 0x5E) != 0) {
        l[0x02] |= 4;
        *(s16 *) (l + 0x5A) = *(s16 *) (l + 0x5A) + (*(s16 *) (l + 0x5E) * arg1);
    }

    t7 = l[0x02] & 2;
    if ((l[0x02] & 1) || (parentOk && (l[0x02] & 2))) {
        *(f32 *) (l + 0x38) = *(f32 *) (l + 0x1C) - *(f32 *) (l + 0x28);
        *(f32 *) (l + 0x3C) = *(f32 *) (l + 0x1C) + *(f32 *) (l + 0x28);
        t7 = l[0x02] & 2;
    }
    if (t7 != 0) {
        lightCreateLightTable(l[0x40], l[0x41], l[0x42], (s32 *) *(void **) (l + 0x70));
        if (*(void **) (l + 0x6C) != NULL) {
            trackLightColour(*(void **) (l + 0x6C), l[0x40], l[0x41], l[0x42], l[0x43]);
        }
    }

    if ((l[0x02] & 4) && (l[0x00] == 3 || l[0x00] == 0)) {
        rot[0] = *(s16 *) (l + 0x58);
        rot[1] = *(s16 *) (l + 0x5A);
        rot[2] = 0;
        *(f32 *) (l + 0x68) = -1.0f;
        mathOneFloatPY(rot, (f32 *) (l + 0x60), (f32 *) (l + 0x60));
        if (parentOk) {
            pointListRPY(1, (s16 *) parent, (s32 *) (l + 0x60), (f32 *) (l + 0x60));
        }
        *(f32 *) (l + 0x60) = -*(f32 *) (l + 0x60);
        *(f32 *) (l + 0x64) = -*(f32 *) (l + 0x64);
        *(f32 *) (l + 0x68) = -*(f32 *) (l + 0x68);
    }
    l[0x02] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/func_80021444.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void killLight(void *arg0) {
    s32 count = D_800A1894;
    s32 idx = 0;
    s32 i;
    ObjectLight *found = NULL;

    for (i = 0; i < count; i++) {
        if (arg0 == D_800A1898[i]) {
            found = D_800A1898[i];
            idx = i + 1;
            break;
        }
    }
    if (found != NULL) {
        void *trackLight = *(void **) ((u8 *) arg0 + 0x6C);
        if (trackLight != NULL) {
            trackLightDelete(trackLight, idx, count, found);
        }
        D_800A1894 = count - 1;
        for (i = idx - 1; i < D_800A1894; i++) {
            D_800A1898[i] = D_800A1898[i + 1];
        }
        D_800A1898[D_800A1894] = found;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/killLight.s")
#endif

UNUSED unk800DC950 **lightGetLights(s32 *arg0) {
    *arg0 = D_800A1894;
    return D_800A1898;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *lightGetStrongestEffect(f32 arg0, f32 arg1, f32 arg2) {
    f32 best = 0.0f;
    void *bestLight = NULL;
    s32 i;

    // Loop runs from count-1 down to index 1 (index 0 is not visited), as in the asm.
    for (i = D_800A1894 - 1; i > 0; i--) {
        u8 *light = (u8 *) D_800A1898[i];
        if (light != NULL) {
            f32 dx = arg0 - *(f32 *) (light + 0x18);
            f32 dy = arg1 - *(f32 *) (light + 0x1C);
            f32 dz = arg2 - *(f32 *) (light + 0x20);
            f32 distSq = (dx * dx) + (dy * dy) + (dz * dz);
            if (distSq < *(f32 *) (light + 0x30)) {
                f32 intensity = (1.0f - (sqrtf(distSq) * *(f32 *) (light + 0x34))) * *(f32 *) (light + 0x44);
                if (best < intensity) {
                    best = intensity;
                    bestLight = light;
                }
            }
        }
    }
    return bestLight;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightGetStrongestEffect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lightUpdateObjects(void) {
    s32 start;
    s32 end;
    Object **list;
    s32 i;

    list = objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        u8 *obj = (u8 *) list[i];
        void *lightBlock = *(void **) (obj + 0x54);
        u8 *obj40 = *(u8 **) (obj + 0x40);
        if (lightBlock != NULL && *(s8 *) (obj40 + 0x1E) == 0 && obj[0xA1] == 0) {
            if (*(s8 *) ((u8 *) levelGetLevel() + 0x6B) != 0) {
                instLockMsg(obj, (s32) lightBlock);
            } else {
                func_80021B9C(obj, lightBlock);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightUpdateObjects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80021B9C(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *blk = (u8 *) arg1;
    u8 *lvl = (u8 *) levelGetLevel();
    s32 maxVal = 0;
    s32 i;

    *(s16 *) (blk + 0x0E) = 1;
    for (i = 0; i < D_800A1894; i++) {
        u8 *lt = (u8 *) D_800A1898[i];
        if (lt[0x03] & 1) {
            if (lt[0x43] != 0) {
                u8 kind = lt[0x00];
                s32 val = 0;
                f32 vx;
                f32 vy;
                f32 vz;

                if (kind != 0) {
                    f32 objX = *(f32 *) (obj + 0x0C);
                    f32 objY = *(f32 *) (obj + 0x10);
                    f32 objZ = *(f32 *) (obj + 0x14);
                    f32 dx = *(f32 *) (lt + 0x18) - objX;
                    f32 dy = *(f32 *) (lt + 0x1C) - objY;
                    f32 dz = *(f32 *) (lt + 0x20) - objZ;
                    f32 d2xz = (dx * dx) + (dz * dz);
                    f32 d2 = d2xz + (dy * dy);
                    f32 d;
                    f32 dir;

                    vx = dx;
                    vy = dy;
                    vz = dz;
                    switch (kind) {
                    case 2:
                        if (d2xz < *(f32 *) (lt + 0x30) && *(f32 *) (lt + 0x38) < objY && objY <= *(f32 *) (lt + 0x3C)) {
                            val = (s32) lightDistanceCalc(*(f32 *) (lt + 0x44), sqrtf(d2xz), *(f32 *) (lt + 0x34), (s32) lt[0x01]);
                        }
                        break;
                    case 3:
                        if (d2 < *(f32 *) (lt + 0x30)) {
                            d = sqrtf(d2);
                            dir = lightDirectionCalc(*(f32 *) (lt + 0x60), *(f32 *) (lt + 0x64), *(f32 *) (lt + 0x68), dx, dy, dz, d);
                            if (dir > 0.0f) {
                                val = (s32) (lightDistanceCalc(*(f32 *) (lt + 0x44), d, *(f32 *) (lt + 0x34), (s32) lt[0x01]) * dir);
                            }
                        }
                        break;
                    default:
                        if (d2 < *(f32 *) (lt + 0x30)) {
                            val = (s32) lightDistanceCalc(*(f32 *) (lt + 0x44), sqrtf(d2), *(f32 *) (lt + 0x34), (s32) lt[0x01]);
                        }
                        break;
                    }
                } else {
                    vx = *(f32 *) (lt + 0x60);
                    vy = *(f32 *) (lt + 0x64);
                    vz = *(f32 *) (lt + 0x68);
                    val = (s32) lt[0x43];
                }

                if (val != 0) {
                    s16 cur = *(s16 *) (blk + 0x0E);
                    u8 *slot = blk + 0x30;

                    if ((lt[0x03] & 0x20) && maxVal < val) {
                        maxVal = val;
                    }
                    if (cur < 4) {
                        slot = blk + (cur << 5) + 0x10;
                        *(s16 *) (blk + 0x0E) = cur + 1;
                    } else {
                        s32 minV = blk[0x45];
                        u8 *cand = blk + 0x40;
                        s32 v1 = 0x40;
                        do {
                            u8 cval = cand[0x25];
                            v1 += 0x20;
                            if ((s32) cval < minV) {
                                slot = cand + 0x10;
                                minV = cval;
                            }
                            cand += 0x20;
                        } while (v1 != 0x80);
                        if ((s32) slot[0x15] >= val) {
                            slot = NULL;
                        }
                    }

                    if (slot != NULL) {
                        *(f32 *) (slot + 0x00) = vx;
                        *(f32 *) (slot + 0x04) = vy;
                        *(f32 *) (slot + 0x08) = vz;
                        *(s32 *) (slot + 0x14) = 0;
                        *(s32 *) (slot + 0x0C) = (1 << (8 - blk[0x24])) << 6;
                        slot[0x15] = (s8) val;
                        slot[0x17] = 0;
                        slot[0x16] = (s8) val;
                        *(s32 *) (slot + 0x10) = val << blk[0x24];
                        *(void **) (slot + 0x18) = *(void **) (lt + 0x70);
                    }
                }
            }
        }
    }

    {
        s32 baseV;
        s32 span;
        s32 temp = 0x13F - maxVal;

        if (lvl[0xDF] != 0) {
            baseV = lvl[0xDC];
            span = lvl[0xDB] - baseV;
        } else {
            baseV = blk[0x0D];
            span = blk[0x0C] - baseV;
        }
        if (maxVal >= 0x40) {
            baseV = (u8) ((temp * baseV) >> 8);
            span = (temp * span) >> 8;
        }
        blk[0x25] = (s8) (baseV + span);
        blk[0x26] = (s8) span;
        blk[0x27] = (u8) baseV;
        *(s32 *) (blk + 0x20) = span << blk[0x24];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/func_80021B9C.s")
#endif

#ifdef NON_EQUIVALENT
// Matching, but needs rodata migration for the jump table.
f32 lightDistanceCalc(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    f32 temp;

    temp = arg1 * arg2;
    switch (arg3) {
        case 1:
            temp = 1.0f - temp;
            break;
        case 2:
            temp = 1.0f - sqrtf(temp);
            break;
        case 3:
            temp = Cosf(temp * 16384.0f);
            break;
        case 4:
            temp = Cosf(temp * 16384.0f);
            temp *= temp;
            break;
        case 5:
            temp = 1.0f - temp;
            temp *= temp;
            break;
    }
    return arg0 * temp;
}
#else
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 lightDistanceCalc(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    f32 temp = arg1 * arg2;
    f32 result = temp;

    switch (arg3) {
    case 1:
        result = 1.0f - temp;
        break;
    case 2:
        result = 1.0f - sqrtf(temp);
        break;
    case 3:
        result = Cosf((s32) (temp * 16384.0f));
        break;
    case 4: {
        f32 c = Cosf((s32) (temp * 16384.0f));
        result = c * c;
        break;
    }
    case 5: {
        f32 t = 1.0f - temp;
        result = t * t;
        break;
    }
    }
    return arg0 * result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightDistanceCalc.s")
#endif
#endif

f32 lightDirectionCalc(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_f0;
    f32 var_f2;

    if (arg6 > 0.0f) {
        temp_f0 = 1.0f / arg6;
        var_f2 = (arg3 * temp_f0 * arg0) + (arg4 * temp_f0 * arg1) + (arg5 * temp_f0 * arg2);
        if (var_f2 < 0.0f) {
            var_f2 = 0.0f;
        }
    } else {
        var_f2 = 1.0f;
    }
    return var_f2;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lightObject(void *arg0, void *arg1, void *arg2, void *arg3) {
    u8 *part = (u8 *) arg1;
    u8 *model = *(u8 **) part;
    u8 *lit = (u8 *) arg2;
    f32 tmpMtx[4][4];
    f32 pos[3];
    s32 count;

    if (arg2 != NULL || *(s32 *) (model + 0x70) != 0) {
        count = (s8) model[0x4F];
        if (count <= 0) {
            if (arg3 == NULL) {
                matrix_SCL_RPY_XYZ(arg0, tmpMtx);
                arg3 = tmpMtx;
            }
            count = 1;
        }
        if (arg2 != NULL) {
            f32 scale = *(f32 *) lit;
            u8 *d = lit + 0x10;
            u8 savedR = 0;
            u8 savedG = 0;
            u8 savedB = 0;
            s32 savedA = 0;
            s16 n;

            if (scale != 1.0f) {
                s32 t;
                savedR = d[0x15];
                savedG = d[0x17];
                savedB = d[0x16];
                savedA = *(s32 *) (d + 0x10);
                t = (s32) ((f32) d[0x15] * scale);
                d[0x15] = (u8) t;
                t = (s32) ((f32) d[0x17] * scale);
                d[0x16] = (u8) (d[0x15] - t);
                *(s32 *) (d + 0x10) = (s32) (((u8) d[0x16]) << d[0x14]);
                d[0x17] = (u8) t;
            }

            n = *(s16 *) (lit + 0x0E);
            if (n > 0) {
                lightMakeJointPositions(n, (f32 *) d, count, arg3, D_800A18A0);
                if (n == 1) {
                    lightSingleLight(*(s32 *) (part + 0x04), *(s32 *) (model + 0x6C), (f32 *) d, D_800A18A0, *(s32 *) (model + 0x68));
                } else if (n == 2) {
                    lightTwoLights(*(s32 *) (part + 0x04), *(s32 *) (model + 0x6C), D_800A18A0, count, (f32 *) d, lit + 0x30, *(s32 *) (model + 0x68));
                } else {
                    lightMultiLight(*(s32 *) (part + 0x04), *(s32 *) (model + 0x6C), (f32 *) d, *(s32 *) (model + 0x68), D_800A18A0, count, n);
                }
            }

            if (*(f32 *) lit != 1.0f) {
                d[0x15] = savedR;
                d[0x17] = savedG;
                d[0x16] = savedB;
                *(s32 *) (d + 0x10) = savedA;
            }
        }
        if (*(s32 *) (model + 0x70) != 0) {
            u8 *cam = (u8 *) camGetPtr();
            pos[0] = *(f32 *) (cam + 0x0C) - *(f32 *) ((u8 *) arg0 + 0x0C);
            pos[1] = *(f32 *) (cam + 0x10) - *(f32 *) ((u8 *) arg0 + 0x10);
            pos[2] = *(f32 *) (cam + 0x14) - *(f32 *) ((u8 *) arg0 + 0x14);
            lightMakeJointPositions(1, pos, count, arg3, D_800A18A0);
            lightEnviroMap(*(s32 *) (model + 0x20), *(s32 *) (model + 0x70), *(s32 *) (model + 0x68), D_800A18A0);
        }
    }
}

void lightDefaultObjectLight(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4) {
    lightSetObjectLight(D_800F65E8, arg0, arg1, arg2, arg3, arg4);
}

void lightSetObjectLight(void *arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5) {
    u8 *light = (u8 *) arg0;
    u8 lo = (u8) arg1;
    u8 hi = (u8) arg2;
    u8 minV = lo;
    s8 diff;
    s32 shift = arg5 & 7;
    s16 rot[3];
    f32 vec[3];

    if (hi < lo) {
        minV = hi;
    }
    light[0x17] = minV;
    light[0x15] = hi;
    diff = (s8) (hi - minV);
    light[0x16] = (u8) diff;
    *(s32 *) (light + 0x10) = (s32) ((diff & 0xFF) << shift);
    light[0x14] = (s8) shift;
    *(s32 *) (light + 0x0C) = (1 << (8 - shift)) << 6;
    *(s16 *) (light + 0x1E) = arg3;
    *(s16 *) (light + 0x1C) = arg4;

    rot[0] = arg4;
    rot[1] = arg3;
    rot[2] = 0;
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = 1.0f;
    mathOneFloatRPY(rot, vec, (s8) hi, arg3);
    *(f32 *) (light + 0x00) = vec[0];
    *(f32 *) (light + 0x04) = vec[1];
    *(f32 *) (light + 0x08) = vec[2];
    *(void **) (light + 0x18) = D_800F65E0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightObject.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightDefaultObjectLight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightSetObjectLight.s")
#endif

void lightSetupLightSources(Object *obj) {
    s32 i;
    for (i = 0; i < obj->segment.header->unk25; i++) {
        obj->unk74[i] = addObjectLight(obj, &obj->segment.header->unk48[i]);
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lightSetupFlareSources(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *hdr;
    s32 i = 0;
    s32 off = 0;

    hdr = *(u8 **)(obj + 0x40);
    if (hdr[0x26] > 0) {
        do {
            s32 flare = camlightAdd(arg0, *(u8 **)(hdr + 0x4C) + (i << 5));

            i += 1;
            *(s32 *)(*(u8 **)(obj + 0x78) + off) = flare;
            hdr = *(u8 **)(obj + 0x40);
            off += 4;
        } while (i < hdr[0x26]);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightSetupFlareSources.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 lightInitObjectLighting(void *arg0, void *arg1) {
    u8 *lvl;
    u8 *hdr;
    u8 *light = (u8 *)arg1;
    s32 var_t1 = 0;

    lvl = (u8 *)levelGetLevel();
    hdr = *(u8 **)((u8 *)arg0 + 0x40);
    *(void **)((u8 *)arg0 + 0x54) = arg1;
    if (*(s8 *)(hdr + 0x1E) == 0) {
        *(s16 *)(light + 0xE) = 1;
        if (lvl[0xDF] != 0) {
            lightSetObjectLight(light + 0x10, lvl[0xDC], lvl[0xDB], *(s16 *)(lvl + 0xD6), (s16)(*(s16 *)(lvl + 0xD4) + 0x8000), 0);
        } else {
            lightSetObjectLight(light + 0x10, (s32)(*(f32 *)(hdr + 0x94) * 255.0f), (s32)(*(f32 *)(hdr + 0x90) * 255.0f), *(s16 *)(hdr + 0x9C), *(s16 *)(hdr + 0x9E), *(s16 *)(hdr + 0xA0));
        }
        var_t1 = 0x90;
        light[4] = 0xFF;
        light[5] = 0xFF;
        light[6] = 0xFF;
        light[7] = 0xFF;
        light[8] = 0xFF;
        light[9] = 0xFF;
        light[10] = 0xFF;
        *(f32 *)light = 1.0f;
    } else if (*(s8 *)(hdr + 0x1E) == 1) {
        light[4] = 0xFF;
        light[5] = 0xFF;
        light[6] = 0xFF;
        light[7] = 0;
        var_t1 = 8;
        *(f32 *)light = 1.0f;
    }
    return (var_t1 & ~3) + 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightInitObjectLighting.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lightAdjustGlowingLight(void *arg0) {
    u8 *src = *(u8 **)((u8 *)arg0 + 0x3C);
    struct {
        u8 kind;
        u8 unk21;
        u8 pad22[6];
        f32 x;
        f32 y;
        f32 z;
        u8 r;
        u8 g;
        u8 b;
        u8 a;
        s16 unk38;
        u16 unk3A;
        s16 unk3C;
        s8 unk3E;
        s8 unk3F;
    } desc;

    desc.kind = 0x41;
    desc.unk21 = src[0x13];
    desc.x = (f32)*(s16 *)(src + 0x4);
    desc.y = (f32)*(s16 *)(src + 0x6);
    desc.z = (f32)*(s16 *)(src + 0x8);
    desc.r = src[0xA];
    desc.g = src[0xB];
    desc.b = src[0xC];
    desc.a = src[0xD];
    desc.unk38 = 0x61;
    desc.unk3A = *(u16 *)(src + 0xE);
    desc.unk3E = -1;
    desc.unk3F = 0;
    desc.unk3C = (s16)((s32)(*(u16 *)(src + 0xE) * src[0x10]) / 100);
    *(s32 *)((u8 *)arg0 + 0x68) = camlightAdd(NULL, &desc);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/lights/lightAdjustGlowingLight.s")
#endif

s32 lightKillGlowingLight(void *arg0) {
    camlightDelete(arg0);
    return 1;
}
