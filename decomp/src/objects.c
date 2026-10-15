#include "common.h"
#include "math.h"

/* decomp: externs */
extern s32 D_800A0834_A1434;
extern s32 D_800F2C8C_B177C;
extern u32 D_800F2CD8_B17C8[2];
extern u32 D_800F2CE0_B17D0[2];
extern u32 D_800F2CE8_B17D8[2];
extern u32 D_800F2CF0_B17E0[2];
extern s32 D_800F2D00_B17F0;
extern s32 D_800F2D14_B1804;
extern s32 D_800F2D20_B1810[];
extern SoundMask *D_800A089C_A149C;
void mineRemove(void *arg0, s32 arg1);
void squadsCheckEnemyPointers(void *arg0);
void squadsCheckGrenades(void *arg0);
void dropletUpdateAll(s32 arg0, s32 *arg1, s32 *arg2);
void *camGetListPtr(void);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndStopXYZ(void *soundMask);
s32 trackGetIntersect(void *, f32 *, f32 *, f32, s32, s16 **);
void trackMakePolylist(f32, s32, f32 *, f32 *, f32 *, s32, s32, s32);
s32 trackPolyHeight(f32, f32, void *, s32);
void partUpdateTriggers(void *, s32);
void squadsAddInterestingEvent(void *, s16, s16, s16, s32, s32, s32);
f32 Powerf(f32, s32);
extern Object *NoAddObjList[];
extern MemoryPoolSlot *objregion;
extern MemoryPoolSlot **objdeflist; // pointer variables (lw from symbol)
extern u16 *objdefno;
extern u32 *RomTab;
extern u16 objindex[];
extern s32 *animplayerlist;
extern Object **deletelist;
extern u8 D_800A097C_A157C;
extern u32 D_800F2F20_B1A10[];
extern Gfx *D_800F2CC8_B17B8;
extern MatrixS *D_800F2CCC_B17BC;
extern u8 D_A0838[];
extern u8 D_800A0A20_A1620;
extern s16 D_800A0BD8_A17D8[];
extern u8 NullTextureOffsets[];
extern f32 D_800F2E98_B1988;
extern s8 D_800A0C5C_A185C;
extern s8 D_800A0C60_A1860;
extern s8 D_800A0C64_A1864;
extern s8 D_800A0C68_A1868;
extern s8 D_800A0C6C_A186C;
void controlRestartPlayer(f32 arg0, f32 arg1, void *arg2, s32 arg3);
s32 controlPlayerOpeningChest(void *arg0);
void *trackGetTrack(void);
void *trackBlockDim(f32 arg0, f32 arg1, s16 arg2);
s16 trackGetBlock(f32 arg0, f32 arg1, f32 arg2);
void objPrintModelObject(void *arg0);
s32 squadsIsTribal(u16, void *);
void modGenAnimMatrices(void *arg0, void *arg1, void *arg2, f32 arg3, f32 arg4);
void minePushMtx(Gfx **dList, MatrixS **mtx, void *arg2);
void mizarHandBitPushMtx(Gfx **dList, MatrixS **mtx, void *arg2);
void windowDrawBeams(Gfx **dList, MatrixS **mtx, void *arg2);
void objAnimTextures(void *arg0, void *arg1, void *arg2, s8 arg3);
void lightObject(void *arg0, void *arg1, s32 arg2, s32 arg3);
void camPushFloatModelMtx(Gfx **dList, MatrixS **mtx, void *arg2);
s32 camGetProjOrgMtx(void);
f32 (*camGetRotationMtx(void))[4];
s32 camProjectPoint(f32, f32, f32, f32 *, f32 *, s32);
void texDPTextureX(Gfx **dList, s32 arg1, s32 arg2, s32 arg3);
void fxDrawLine3D(f32, f32, s32, s32, f32, f32, s32);
f32 Sinf(s16);
void objEnsureNotTargetted(void);
void partInitTrigger(void *arg0, s32 arg1, s16 arg2);
void partInitTriggerSPPos(void *arg0, s32 arg1, s16 arg2, s32 arg3);
void partInitTriggerPos(void *arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
void objDoFrees(void);
void objDeleteRomDef(u8 *arg0);
void func_80007EA0(void *obj, s32 arg1);
extern u8 arithmeticSums[];
extern s16 trackFade;
extern s16 trackFadeCount;
extern s16 trackFadeEnd;
void amSndStop(s32 handle);
void TidyLinkedList(u8 arg0);
void animshipFree(void *arg0);
void cameraDeleteOverrideObject(void *arg0);
void chargeEffectFree(void *arg0);
void cloneBlobDelete(s32 arg0);
void cloneDelete(s32 arg0);
void controlPlayerStopAimAndLook(void *arg0);
void duckshootUpdate(s32 arg0);
void func_80008F60(s32 arg0);
void func_80011AD4(Object *arg0);
void fxFreeCone(s32 arg0);
void hoovertankFree(void *arg0);
void killLight(void *arg0);
void mantismissileFree(void *arg0);
void menuCamCleanup(void *arg0);
void menuCamFacingTVCleanup(void *arg0);
void mizarFree(void *arg0);
void multiCharArmCleanup(void *arg0);
void objDeleteMine(s32 arg0);
void partNullifyCircularParticleParents(void *arg0);
void partObjFreeTriggers(void *arg0);
void severedLimbDestroy(void *arg0);
void shardClusterDestroy(void *arg0);
void sidekickpadFree(void *arg0);
void splinecamMakeSpline(void *arg0);
void staticcamDelete(void *arg0);
void trackLightDelete(void *arg0);
void wakeFreeRipple(s32 arg0);
void *func_80007984(s32 arg0);
Object **objGetObjList(s32 *arg0, s32 *arg1);
void *objSetupObject(RomDefHeader *romdef, s32 arg1);
void frontSetupMultiPickup(RomDefHeader *romdef);
void squadsRememberRomdef(RomDefHeader *romdef);
void *modLoadModel();
void modFreeModel();
s32 modLoadAnimEvents(s16 id);
void modFreeAnimEvents();
void *texLoadSprite();
void texFreeSprite(void *sprite);
void texFreeTexture(void *tex);
f32 GetRangeSquared(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern s32 playerlist;
extern s32 refractThisObject;
extern s32 D_800F2CD0_B17C0;
extern TextureHeader *D_800F2CA0_B1790;
extern u8 multiPlayerGame;
extern MemoryPoolSlot *objTempBuf;
extern s32 objTempBufSize;
extern s32 MaxTypes;
extern s32 D_800F6F54_B1794;
extern f32 obj_olddt;
extern s32 D_800F2C90_B1780;
extern s32 D_800F2C94_B1784;
extern s32 D_800F2EA0_B1990[];
extern s32 D_800F2EE0_B19D0[];
extern u8 D_800A0974_A1574;
extern u8 D_800A0978_A1578;
extern u8 numberOfPlayers;
extern u8 multiGameType;
extern u8 racingInGame;
void hitUpdate(void *arg0);
void hitModelsTick(void);
void explosionHitTick(s32 arg0);
void lightUpdateObjects(void);
s32 texAnimateSprite(s32 handle, s32 *state, s32 frames, void *data, s32 dt);
void controlPlayer(void *player, s32 arg1, s32 arg2);
void sprintUpdate(u8 arg0, s32 arg1, s32 arg2);
void shrinkbeamSoundUpdate(s32 arg0);
void func_80011E74_12A74(void);
void wakeUpdateRipple(void *arg0, s32 arg1);
void objScrollTexture(void *arg0, s32 arg1);
void func_8000FB60(void *arg0, s32 arg1);
s32 mainGetPauseMode();
s32 func_8000F8E8();
void amPlayAudioMap(s32 arg0, s32 arg1, s32 arg2);
void beamDraw(void *arg0, s32 arg1);
extern u8 D_800A09A8_A15A8[];
extern u8 D_800A09C8_A15C8[];
extern u8 D_800A09F0_A15F0[];
extern u8 D_800A0A10_A1610[];
extern u8 D_800A0BEC_A17EC[];
extern u8 D_800A0C0C_A180C[];
extern u8 D_800A0C1C_A181C[];
extern u8 D_800A0C2C_A182C[];
f32 camGetProjZ(f32, f32, f32);
s32 camGetNo(void);
void camPopModelMtx();
void camPushMuzzleMtx();
void camScaleModelMtx();
void camDoSprite();
void camDoSpriteDirect(void **arg0, void **arg1, void **arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, f32 arg9, s32 arg10, s32 arg11);
void fxDrawLine(s16, s16, s16, s16, s32);
void fxDrawCone();
void mantisSplitGfx();
void ShirukenPushMtx();
void trackGetFog(s32, s16 *, s16 *, s16 *, u8 *, u8 *, u8 *, s16 *);
void *mainGetGameCharacter(s8, s8);
extern u8 racingCharacter;
extern s8 raceGameSingleScreen;
extern u32 D_800A0930_A1530[];
extern s16 D_800A0954_A1554[];
extern s16 D_800A0964_A1564[];
s32 mainGetGameFlag(s32 flag);
s32 mainGetNumberOfPlayers(void);
u8 mainGetPlayerCharacter(s32 arg0);
s32 controlGetPlayerSetup(s16 *arg0, s16 *arg1, s16 *arg2, s16 *arg3);
void mizarInit(s32 arg0);
void modPhitInit();
void sprintInit(void *arg0);
void *levelGetColourCycling();
void glassDraw();
void blastdoorDraw();
void treeInit();
void WaterBossDrawSprites();
void animseqMuzzleFlash();
void chargeEffectDraw();
void mathRpyXyzMtx();
void mathScaleMtx();
void mathMtxCatF();
void objFreeObject();
s32 GetVtxPosition();
s32 FatBobDrawShockWave();
void SquaddieLightAndAnimate();
void objDrawShockWave();
void objDrawInvincibilityShield();
void teleportEffectDraw();
void lightShowDraw();
void mantisboltDraw();
void mizarEyeBeamDraw();
void mizarElectroDraw();
void mizarImpactDraw();
void mizarRockStormDraw();
void mizarFireBallDraw();
void mizarDeathDraw();
void twisterDraw();
void objPrintShardCluster();
void objPrintSeveredLimb();
void func_8000A9C0();
void func_8000C028(Gfx **, MatrixS **, void *);
void func_8000DD1C(void *);
void objDoPlayerTumble(Object *this);
void objUndoPlayerTumble(Object *obj);
extern s16 weaponPowerUpObjects[];
extern s32 D_800A333C_A3F3C;
extern void *D_800A3340_A3F40;
extern s32 D_800A3344_A3F44;
extern s32 D_800A3348_A3F48;
/* decomp: objSetupObject prototypes (signatures as their definitions in this file / other TUs) */
s32 cloneBlobSetup(void *arg0);
s32 cloneSetupShadow(void *arg0);
s32 cloneSetupShadow_2arg(void *arg0, s32 arg1); /* NM link alias of cloneSetupShadow (asm passes 2 args) */
void func_80006FFC(void *arg0, s32 arg1, s32 arg2);
s32 func_8000710C(void *arg0);
s32 func_80007494(void *arg0, s32 arg1);
s32 func_800075EC(void *arg0, s8 *arg1);
s32 func_80007648(void *arg0, void *arg1);
s32 func_80007760(void *arg0, void *arg1, s32 arg2);
s32 func_80007968(void *arg0, s32 arg1);
s32 func_80007974(void *arg0, s32 arg1);
s32 func_8000E5F0(void *arg0, s32 arg1);
void hitInitObjectHit(void *arg0, s16 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
s32 lightInitObjectLighting(void *arg0, void *arg1);
void lightSetupFlareSources(void *arg0);
void modelSetModelFlags(s32 arg0);
s32 objExplosionSetupTriggers(void *arg0, s32 arg1, void *arg2);
s32 wakeSetupRipple(void *arg0, s32 arg1);
void squadsTidyEventList(void *arg0);
void objSetup(void *arg0);
u8 *mmAlign4(u8 *address);
void AIJunctionInit(void *);
void AIPointInit(void *);
void CyborgMissileInit(void *);
void FatBobShockWaveInit(void *);
void FlowerBoltInit(void *);
void LaserBeamInit(void *);
void MaggotBombInit(void *);
void ShirukenInit(void *);
void SpiderSpitInit(void *);
void SquaddieInit(void *);
void SquadronInit(void *);
void TwinkleInit(void *);
void ammoPickupInit(void *);
void animInit(void *);
void animdroidInit(void *);
void animplayerInit(void *);
void animshipInit(void *);
void animswitchInit(void *);
void arcadeInit(void *);
void audioLineInit(void *);
void audioPointInit(void *);
void beamInit(void *);
void blastdoorInit(void *);
void bubblerInit(void *);
void buoyInit(void *);
void butterflyInit(void *);
void chestInit(void *);
void collectableInit(void *);
void controlPlayerInit(void *);
void craterInit(void *);
void cutcameraInit(void *);
void damagecrateInit(void *);
void doorInit(void *);
void doorSwitchInit(void *);
void dopplerPointInit(void *);
void dropletInit(void *);
void electrocutionInit(void *);
void exitInit(void *);
void explosionInit(void *);
void expspriteInit(void *);
void fireExplosionInit(void *);
void fireflyInit(void *);
void fireringInit(void *);
void fireworkInit(void *);
void fishInit(void *);
void fishfoodInit(void *);
void flagtargetInit(void *);
void flagtriggerInit(void *);
void flareInit(void *);
void flareswitchInit(void *);
void floatingInit(void *);
void flyingdebrisInit(void *);
void fogInit(void *);
void frogInit(void *);
void genericplayerInit(void *);
void glassInit(void *);
void grenadeInit(void *);
void grubInit(void *);
void healthPickupInit(void *);
void hitBridgeInit(void *);
void hitModelInit(void *);
void hitanimInit(void *);
void hitfragmentInit(void *);
void hitstaticInit(void *);
void hoovergemInit(void *);
void hoovertankInit(void *);
void invincibilityInit(void *);
void invincibilityShieldInit(void *);
void invisibilityInit(void *);
void keyInit(void *);
void laserboltInit(void *);
void lensflareInit(void *);
void lightAdjustGlowingLight(void *);
void lightShowInit(void *);
void mainclusterInit(void *);
void mantisInit(void *);
void mantisboltInit(void *);
void mantismissileInit(void *);
void mantisrockInit(void *);
void markerboxInit(void *);
void menuCamFocusInit(void *);
void menuCamInit(void *);
void mineInit(void *);
void missileInit(void *);
void mizarAISetup(void *);
void mizarDeathInit(void *);
void mizarElectroInit(void *);
void mizarEyeBeamInit(void *);
void mizarFireBallInit(void *);
void mizarHandBitInit(void *);
void mizarImpactInit(void *);
void mizarMonolithInit(void *);
void mizarSetup(void *);
void mizarWingBitInit(void *);
void mrhintsInit(void *);
void multiCharArmInit(void *);
void multiptargetInit(void *);
void multitargetInit(void *);
void muzzleFlashInit(void *);
void nightvisionpadInit(void *);
void overrideCInit(void *);
void racecheckInit(void *);
void raceobstacleInit(void *);
void racepickupInit(void *);
void refuelInit(void *);
void regionidInit(void *);
void rgbalightInit(void *);
void robotcheckInit(void *);
void robotcollectableInit(void *);
void robottargetInit(void *);
void rockstormInit(void *);
void setupInit(void *);
void severedLimbInit(void *);
void shardClusterInit(void *);
void shockwaveInit(void *);
void shrinkbeamInit(void *);
void sidekickInit(void *);
void sidekickpadInit(void *);
void skyInit(void *);
void smallclusterInit(void *);
void smokingfireInit(void *);
void spinlightInit(void *);
void splashInit(void *);
void splinecamnodeInit(void *);
void spotlightInit(void *);
void spranimInit(void *);
void sprasjiInit(void *);
void staticcamInit(void *);
void targetswitchInit(void *);
void teleportEffectInit(void *);
void terminalInit(void *);
void texscrollInit(void *);
void totemPoleInit(void *);
void trackbeamInit(void *);
void transformerInit(void *);
void treeControl(void *);
void twisterInit(void *);
void waterbubbleInit(void *);
void waveswellInit(void *);
void weaponPickupInit(void *);
void weatherInit(void *);
void windowfxInit(void *);
void zombieFlobInit(void *);
void AIJunctionControl(void *, s32);
void AIPointControl(void *, s32);
void CyborgMissileControl(void *, s32);
void FatBobShockWaveControl(void *, s32);
void FlowerBoltControl(void *, s32);
void LaserBeamControl(void *, s32);
void MaggotBombControl(void *, s32);
void ShirukenControl(void *, s32);
void SpiderSpitControl(void *, s32);
void SquaddieControl(void *, s32);
void SquadronControl(void *, s32);
void TwinkleControl(void *, s32);
void ammoPickupControl(void *, s32);
void animControl(void *, s32);
void animdroidControl(void *, s32);
void animobjControl(void *, s32);
void animplayerControl(void *, s32);
void animshipControl(void *, s32);
void animswitchControl(void *, s32);
void animtriggerControl(void *, s32);
void arcadeControl(void *, s32);
void beamControl(void *, s32);
void blastdoorControl(void *, s32);
void bubblerControl(void *, s32);
void buoyControl(void *, s32);
void butterflyControl(void *, s32);
void chestControl(void *, s32);
void collectableControl(void *, s32);
void craterControl(void *, s32);
void cutcameraControl(void *, s32);
void damagecrateControl(void *, s32);
void doorControl(void *, s32);
void doorSwitchControl(void *, s32);
void dopplerPointControl(void *, s32);
void dropletControl(void *, s32);
void effectboxControl(void *, s32);
void electrocutionControl(void *, s32);
void exitControl(void *, s32);
void explosionControl(void *, s32);
void expspriteControl(void *, s32);
void fireExplosionControl(void *, s32);
void fireflyControl(void *, s32);
void fireringControl(void *, s32);
void fireworkControl(void *, s32);
void fishControl(void *, s32);
void fishfoodControl(void *, s32);
void flagtargetControl(void *, s32);
void flagtriggerControl(void *, s32);
void flareControl(void *, s32);
void floatingControl(void *, s32);
void flyingdebrisControl(void *, s32);
void frogControl(void *, s32);
void func_80010430();
void func_80011200(void *, s32);
void glassControl(void *, s32);
void grenadeControl(void *, s32);
void grubControl(void *, s32);
void healthPickupControl(void *, s32);
void hitBridgeControl(void *, s32);
void hitfragmentControl(void *, s32);
void hoovergemControl(void *, s32);
void hoovertankControl(void *, s32);
void invincibilityControl(void *, s32);
void invincibilityShieldControl(void *, s32);
void invisibilityControl(void *, s32);
void keyControl(void *, s32);
void laserboltControl(void *, s32);
void lightShowControl(void *, s32);
void mainclusterControl(void *, s32);
void mantisControl(void *, s32);
void mantisboltControl(void *, s32);
void mantismissileControl(void *, s32);
void mantisrockControl(void *, s32);
void menuCamControl(void *, s32);
void menuCamFacingTVControl(void *, s32);
void menuCamFocusControl(void *, s32);
void mineControl(void *, s32);
void missileControl(void *, s32);
void mizarControl(void *, s32);
void mizarDeathControl(void *, s32);
void mizarElectroControl(void *, s32);
void mizarEyeBeamControl(void *, s32);
void mizarFireBallControl(void *, s32);
void mizarImpactControl(void *, s32);
void mizarMonolithControl(void *, s32);
void mizarWingBitControl(void *, s32);
void mrHintsEventHandler(void *, s32);
void mrhintsControl(void *, s32);
void multiCharArmControl(void *, s32);
void multiptargetControl(void *, s32);
void multitargetControl(void *, s32);
void nightvisionpadControl(void *, s32);
void raceobstacleControl(void *, s32);
void racepickupControl(void *, s32);
void rangetriggerControl(void *, s32);
void refuelControl(void *, s32);
void regionidControl(void *, s32);
void robotTokenControl(void *, s32);
void robotcheckControl(void *, s32);
void robotcollectableControl(void *, s32);
void robottargetControl(void *, s32);
void rockstormControl(void *, s32);
void severedLimbControl(void *, s32);
void shardClusterControl(void *, s32);
void shockwaveControl(void *, s32);
void shrinkbeamControl(void *, s32);
void sidekickControl(void *, s32);
void sidekickpadControl(void *, s32);
void skyControl(void *, s32);
void smallclusterControl(void *, s32);
void smokingfireControl(void *, s32);
void spinlightControl(void *, s32);
void splashControl(void *, s32);
void spotlightControl(void *, s32);
void spranimControl(void *, s32);
void spranimOnceControl(void *, s32);
void targetswitchControl(void *, s32);
void teleportEffectControl(void *, s32);
void terminalControl(void *, s32);
void texscrollControl(void *, s32);
void totemPoleControl(void *, s32);
void trackChangeFog(void *, s32);
void trackbeamControl(void *, s32);
void transformerControl(void *, s32);
void twisterControl(void *, s32);
void waterbubbleControl(void *, s32);
void weaponPickupControl(void *, s32);
void weatherControl(void *, s32);
void windowfxControl(void *, s32);
void zombieFlobControl(void *, s32);
void FlopsyDogFoodGone(void *, u16);
void SquaddieAnimEventHandler(void *, u16);
void animBoyEventHandler(void *, u16);
void animDogEventHandler(void *, u16);
void animGirlEventHandler(void *, u16);
void modFreeAnim(f32, s32, void *, s8);

const char D_800AAB50[] = "Objects out of ram(1) !!\n";
const char D_800AAB6C[] = "Char %d, Disguise %d\n";
const char D_800AAB84[] = "Found Boss Control At %d,%d,%d,%08x\n";
const char D_800AABAC[] = "ObjSetupObject(1) Memory fail!!\n";
const char D_800AABD0[] = "ObjSetupObject(2) Memory fail!!\n";
const char D_800AABF4[] = "ObjSetupObject(5) Memory fail!!\n";
const char D_800AAC18[] = "ObjSetupObject(6) Memory fail!!\n";
const char D_800AAC3C[] = "ObjSetupObject(3) Memory fail!!\n";
const char D_800AAC60[] = "ObjList Overflow %d!!!\n";
const char D_800AAC78[] = "NoAddObjList Overflow %d!!!\n";
const char D_800AAC98[] = "ObjSetupObject(4) Memory fail!!\n";
const char D_800AACBC[] = "objSetupObject: clone shadow set up failed\n";
const char D_800AACE8[] = "objSetupObject: clone blob shadow set up failed\n";
const char D_800AAD1C[] = "objSetupChild: memory fail\n";
#ifdef VERSION_kiosk
const char D_800AAD38[] = "stable\n";
#endif
const char D_800AAD40[] = "WARNING:%s (%x) already registered its dependancy with %s (%x)!\n";

void resetVars(void) {
    D_800F3860 = 1;
    D_800F386C = 0;
    D_800F3870 = 0;
    D_800F3908 = 0;
    D_800F3910 = 0;
    D_800F391C = 0;
    ObjListCount = 0;
    D_800F38AC = 0;
    D_800F38B8 = 0;
    D_800F38BC = 0;
    D_800F38C4 = 0;
    D_800F38C0 = 0;
    D_800F38C2 = 0;
    D_800F3948 = 0;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objFreeAll(void) {
    s32 count;
    s32 i;

    D_800F2D14_B1804 = 0;
    objDoFrees();
    count = ObjListCount;
    for (i = 0; i < count; i++) {
        func_80007EA0(ObjList[i], 1);
    }
    count = D_800F38B8;
    for (i = 0; i < count; i++) {
        Object *obj = NoAddObjList[i];
        if (obj->behaviorId == 0x18) {
            func_80007EA0(obj, 1);
        }
    }
    D_800F3908 = 0;
    ObjListCount = 0;
    D_800F38AC = 0;
    resetVars();
    mmFree((void *)D_800F2CF0_B17E0[0]);
    mmFree((void *)D_800F2CF0_B17E0[1]);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objFreeAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *objGetClosestControlType(f32 x, f32 y, f32 z, s32 type) {
    s32 typeId = type & 0xFF;
    s32 start;
    s32 end;
    s32 i;
    Object **list;
    f32 best = 5e9f;
    Object *closest = NULL;

    list = objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        Object *obj = list[i];
        f32 dist;

        if (*(u8 *)((u8 *)obj + 0xA0) != 0) {
            continue;
        }
        if ((s32)obj == D_800A0834_A1434) {
            continue;
        }
        if (obj->behaviorId != typeId) {
            continue;
        }
        if (typeId == 0x18 && (*(u32 *)obj->racer & 0x08000000)) {
            continue;
        }
        dist = GetRangeSquared(obj->segment.trans.x_position, obj->segment.trans.y_position,
                               obj->segment.trans.z_position, x, y, z);
        if (dist < best) {
            best = dist;
            closest = obj;
        }
    }
    return closest;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetClosestControlType.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *objGetClosestClass(f32 x, f32 y, f32 z, s32 type) {
    s32 typeId = type & 0xFF;
    s32 start;
    s32 end;
    s32 i;
    Object **list;
    f32 best = 5e9f;
    Object *closest = NULL;

    list = objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        Object *obj = list[i];

        if (*(u8 *)((u8 *)obj + 0xA0) != 0) {
            continue;
        }
        if ((s32)obj != D_800A0834_A1434 && typeId == *(u8 *)(*(u8 **)((u8 *)obj + 0x40) + 0x1B)) {
            f32 dist = GetRangeSquared(obj->segment.trans.x_position, obj->segment.trans.y_position,
                                       obj->segment.trans.z_position, x, y, z);
            if (dist < best) {
                best = dist;
                closest = obj;
            }
        }
    }
    return closest;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetClosestClass.s")
#endif

#ifdef VERSION_us
extern s8 D_800A0898_A1498;

void objSetObjRegionOverflow(s8 arg0) {
    D_800A0898_A1498 = arg0;
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
static void objdefFixupPtr(u8 *base, s32 offset) {
    u32 *slot = (u32 *)(base + offset);
    *slot = (u32)(base + *slot);
}

u32 objGetObjdef(s32 index) {
    s32 romStart;
    s32 romSize;
    MemoryPoolSlot *data;
    u8 *base;
    s16 count;
    u16 *ids;
    void **res;
    s32 i;
    s32 hasD0;

    if (objdefno[index] != 0) {
        objdefno[index] += 1;
        return (u32)objdeflist[index];
    }
    romStart = RomTab[index];
    romSize = RomTab[index + 1] - romStart;
    data = mmAllocR(objregion, romSize);
    if (data == NULL && D_800A0898_A1498 != 0) {
        data = mmAlloc(romSize, 0xFFFF);
    }
    if (data == NULL) {
        return 0;
    }

    piRomLoadSection(0x2F, (u32)data, romStart, romSize);
    base = (u8 *)data;
    hasD0 = *(u32 *)(base + 0xD0) != 0;
    objdefFixupPtr(base, 0x48);
    objdefFixupPtr(base, 0x4C);
    objdefFixupPtr(base, 0x40);
    objdefFixupPtr(base, 0xB0);
    objdefFixupPtr(base, 0x34);
    objdefFixupPtr(base, 0x38);
    objdefFixupPtr(base, 0x3C);
    objdefFixupPtr(base, 0x30);
    objdefFixupPtr(base, 0xA8);
    objdefFixupPtr(base, 0xAC);
    objdefFixupPtr(base, 0x50);
    if (hasD0) {
        objdefFixupPtr(base, 0xD0);
    }

    count = *(u8 *)(base + 0xA6);
    ids = *(u16 **)(base + 0xA8);
    res = *(void ***)(base + 0xAC);
    for (i = 0; i < count; i++) {
        u16 id = ids[i];
        if ((id & 0xC000) == 0xC000) {
            res[i] = texLoadTexture(id & 0x3FFF);
        } else if (id & 0x8000) {
            res[i] = texLoadSprite(id & 0x3FFF, 1, id);
        } else {
            res[i] = modLoadModel(id, 0, id);
        }
    }

    if (*(s16 *)(base + 0xD8) != -1) {
        *(s32 *)(base + 0xD4) = modLoadAnimEvents(*(s16 *)(base + 0xD8));
    } else {
        *(s32 *)(base + 0xD4) = 0;
    }

    objdeflist[index] = data;
    objdefno[index] = 1;
    return (u32)data;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetObjdef.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objFreeObjdef(s32 index) {
    u8 *data;
    u16 *ids;
    void **res;
    s16 count;
    s32 i;
    s32 animEvents;

    if (objdefno[index] != 0) {
        objdefno[index] -= 1;
        if (objdefno[index] == 0) {
            data = (u8 *)objdeflist[index];
            count = *(u8 *)(data + 0xA6);
            ids = *(u16 **)(data + 0xA8);
            res = *(void ***)(data + 0xAC);
            for (i = 0; i < count; i++) {
                u16 id = ids[i];
                if ((id & 0xC000) == 0xC000) {
                    texFreeTexture(res[i]);
                } else if (id & 0x8000) {
                    texFreeSprite(res[i]);
                } else {
                    modFreeModel(res[i]);
                }
            }
            animEvents = *(s32 *)(data + 0xD4);
            if (animEvents != 0) {
                modFreeAnimEvents(animEvents);
            }
            mmFree(data);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objFreeObjdef.s")
#endif

s32 objTvTimes(s32 timer) {
    if (osTvType != OS_TV_TYPE_PAL || timer < 0) {
        return timer;
    } else {
        return (timer * 5) / 6;
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_800052B4(s32 arg0) {
    switch (arg0) {
        case 0x29: case 0x2A: case 0x2B: case 0x2D: case 0x54:
        case 0x149: case 0x150: case 0x151: case 0x152: case 0x153:
        case 0x166: case 0x5F: case 0x67: case 0xDF: case 0xE0:
        case 0xE1: case 0x78: case 0x8C: case 0x83: case 0x66:
        case 0x11C: case 0x11D: case 0x11E: case 0x11F: case 0x120:
        case 0x70: case 0x90: case 0xA5: case 0x97: case 0x157:
        case 0x68: case 0x6D: case 0xBE: case 0xBD: case 0x269:
        case 0xEE: case 0xEF: case 0x8D: case 0x99: case 0x9C:
        case 0x12F: case 0xE6: case 0xF2: case 0xF3: case 0x121:
        case 0xF1: case 0xF5: case 0xF6: case 0x122: case 0x143:
        case 0x144: case 0x112: case 0x1E5:
            return 1;
        default:
            return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_800052B4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objLoadObjList(s32 arg0, s32 arg1) {
    MemoryPoolSlot *buf;
    u32 *table;
    s32 count;
    s32 idx;
    s32 romStart;
    s32 romSize;
    RomDefHeader *romdef;
    s32 consumed;

    buf = mmAlloc(0x3000, 0xFFFF);
    D_800F2CF0_B17E0[arg1] = (u32)buf;
    D_800F2CD8_B17C8[arg1] = (u32)&buf->colourTag;
    D_800F2CE0_B17D0[arg1] = 0;
    D_800F2CE8_B17D8[arg1] = arg0;

    table = piRomLoad(0x1C);
    count = 0;
    if (table[0] != 0xFFFFFFFFU) {
        do {
            count += 1;
        } while (table[count] != 0xFFFFFFFFU);
    }
    idx = arg0;
    if (idx >= count - 1) {
        idx = 0;
    }
    romStart = table[idx];
    romSize = table[idx + 1] - romStart;
    mmFree(table);

    if (romSize != 0) {
        piRomLoadSection(0x1D, (u32)buf, romStart, romSize);
        D_800F2CE0_B17D0[arg1] = (u32)buf->data;
        D_800F2CD8_B17C8[arg1] = (u32)&buf->colourTag;
        D_800F2D00_B17F0 = arg1;
        if (arg1 == 1) {
            squadsPreInit((RomDefHeader *)D_800F2CD8_B17C8[arg1], (s32)D_800F2CE0_B17D0[arg1]);
        }
        consumed = 0;
        if ((s32)D_800F2CE0_B17D0[arg1] > 0) {
            do {
                s32 size;

                romdef = (RomDefHeader *)D_800F2CD8_B17C8[arg1];
                if (func_800052B4(romdef->id) != 0) {
                    squadsRememberRomdef(romdef);
                } else if (romdef->id == 0x12E) {
                    frontSetupMultiPickup(romdef);
                } else {
                    objSetupObject(romdef, 1);
                }
                romdef = (RomDefHeader *)D_800F2CD8_B17C8[arg1];
                size = romdef->size;
                consumed += size;
                D_800F2CD8_B17C8[arg1] = (u32)((u8 *)romdef + size);
            } while (consumed < (s32)D_800F2CE0_B17D0[arg1]);
        }
        D_800F2CD8_B17C8[arg1] = (u32)&buf->colourTag;
        if (D_800F2C8C_B177C == 0) {
            objDoFrees();
        }
        D_800F2C8C_B177C = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objLoadObjList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objSetupPlayers(s32 arg0) {
    LevelHeader *lvl;
    Game *game;
    Object *obj;
    Object *spawned;
    Object *childObj;
    Object *obj61;            /* last object with behaviorId 0x61 (asm sp5C) */
    void *playerData;         /* spawned->unk68 */
    MemoryPoolSlot *savedTempBuf;
    s32 numPlayers;
    s32 i;
    s32 idx;
    s32 charType;
    s16 *ids;
    s8 flags;
    s8 pc;
    u8 *gc;
    u8 *rec;
    u8 *pos;
    /* Spawn records, 0x12 bytes each (RomDefHeader: id s16 @0, size u8 @2 = 0x12,
       pos x/y/z s16 @4/@6/@8, rot @0xE, player index @0x10, flags @0x11).
       Record 0 pos/rot fields are what controlGetPlayerSetup() fills in. */
    u8 playerRec[0x12 * 4];
    u8 childRec[0x10];        /* temp romdef for the child object (asm spBC) */

    lvl = levelGetLevel();
    D_800F2C90_B1780 = 0;
    D_800F3910 = 0;
    game = mainGetGame();
    numPlayers = mainGetNumberOfPlayers();
    obj61 = NULL;
    D_800F2D14_B1804 = 0;
    if (multiPlayerGame != 0 && multiGameType == 6) {
        mizarInit(numPlayers);
        return;
    }
    if (lvl->unk6C == 1 || lvl->unk6C == 2 || numPlayers <= 0) {
        return;
    }

    /* Build one spawn record per player. */
    for (i = 0; i < numPlayers; i++) {
        pc = mainGetPlayerCharacter(i);
        flags = pc;
        gc = mainGetGameCharacter(i, pc);
        if (multiPlayerGame == 0 && mainGetGameFlag(0x5F) != 0) {
            flags |= 4;
        }
        rec = &playerRec[i * 0x12];
        charType = *(u16 *)(gc + 4) & 0x1F;
        if (charType < 9) {
            ids = (s16 *)D_800A0930_A1530[charType];
        } else {
            ids = (s16 *)D_800A0930_A1530[0];
        }
        *(s16 *)rec = ids[flags & 7];
        if (multiPlayerGame != 0 && multiGameType == 4) {
            if (raceGameSingleScreen == 0) {
                *(s16 *)rec = D_800A0954_A1554[i];
            } else {
                *(s16 *)rec = D_800A0954_A1554[i + 4];
            }
        } else if (racingInGame != 0) {
            if (raceGameSingleScreen == 0) {
                *(s16 *)rec = D_800A0954_A1554[(racingCharacter + i) & 3];
            } else if (i == 0) {
                *(s16 *)rec = D_800A0954_A1554[4 + (racingCharacter & 1)];
            } else {
                *(s16 *)rec = D_800A0954_A1554[6];
            }
        } else if (multiPlayerGame != 0 && numPlayers >= 3 && (*(u16 *)(gc + 4) & 0x1F) == 0) {
            *(s16 *)rec = D_800A0964_A1564[flags & 7];
        }
        rec[0x10] = i;
        rec[2] = 0x12;
        *(s16 *)(rec + 4) = 0;
        *(s16 *)(rec + 6) = 0;
        *(s16 *)(rec + 8) = 0;
        *(s16 *)(rec + 0xA) = 0;
        *(s16 *)(rec + 0xC) = 0;
        *(s16 *)(rec + 0xE) = 0;
        rec[0x11] = flags;
    }

    /* Objects with behaviorId 6 that match arg0 override the record position. */
    for (i = 0; i < ObjListCount; i++) {
        obj = ObjList[i];
        if (*(s16 *)((u8 *)obj + 0x48) == 6 && *(s32 *)((u8 *)obj + 0x8C) == arg0) {
            idx = *(s32 *)((u8 *)obj + 0x88);
            if (idx < numPlayers) {
                pos = *(u8 **)((u8 *)obj + 0x3C);
                rec = &playerRec[idx * 0x12];
                *(s16 *)(rec + 4) = *(s16 *)(pos + 4);
                *(s16 *)(rec + 6) = *(s16 *)(pos + 6);
                *(s16 *)(rec + 8) = *(s16 *)(pos + 8);
                *(s16 *)(rec + 0xE) = *(s16 *)((u8 *)obj + 0x0);
            }
        }
    }

    /* Last behaviorId 0x61 object supplies the player-0 position and setup. */
    for (i = 0; i < ObjListCount; i++) {
        obj = ObjList[i];
        if (*(s16 *)((u8 *)obj + 0x48) == 0x61) {
            obj61 = obj;
            pos = *(u8 **)((u8 *)obj + 0x3C);
            *(s16 *)(playerRec + 4) = *(s16 *)(pos + 4);
            *(s16 *)(playerRec + 6) = *(s16 *)(pos + 6);
            *(s16 *)(playerRec + 8) = *(s16 *)(pos + 8);
            *(s16 *)(playerRec + 0xE) = *(s16 *)(pos + 0xA);
        }
    }
    controlGetPlayerSetup((s16 *)(playerRec + 4), (s16 *)(playerRec + 6),
                          (s16 *)(playerRec + 8), (s16 *)(playerRec + 0xE));

    /* Spawn the player objects. */
    for (i = 0; i < numPlayers; i++) {
        rec = &playerRec[i * 0x12];
        spawned = objSetupObject((RomDefHeader *)rec, 1);
        ((Object **)playerlist)[i] = spawned;
        if (spawned != NULL) {
            playerData = *(void **)((u8 *)spawned + 0x68);
            *(s32 *)((u8 *)spawned + 0x3C) = 0;
            if (numPlayers == 1) {
                if ((playerRec[0x11] & 3) != 3) {
                    game->pad[0] = *(s8 *)((u8 *)playerData + 1);
                    if (mainGetGameFlag(3) != 0) {
                        *(s16 *)(childRec + 0) = 0x81;
                        childRec[2] = 0x0A;
                        childRec[3] = 0;
                        *(s16 *)(childRec + 4) = 0;
                        *(s16 *)(childRec + 6) = 0;
                        *(s16 *)(childRec + 8) = 0;
                        *(void **)(childRec + 0xC) = spawned;
                        childObj = objSetupObject((RomDefHeader *)childRec, 1);
                        *(Object **)((u8 *)playerData + 0x50C) = childObj;
                        if (childObj != NULL) {
                            *(s32 *)((u8 *)childObj + 0x3C) = 0;
                        }
                        D_800F2D14_B1804 = *(s32 *)((u8 *)playerData + 0x50C);
                    }
                }
            }
            *(Object **)((u8 *)playerData + 0xFC) = obj61;
        }
    }
    D_800F3910 = numPlayers;

    /* Objects with behaviorId 0x6A get sprintInit() run with a temporary buffer. */
    for (i = 0; i < ObjListCount; i++) {
        obj = ObjList[i];
        if (*(s16 *)((u8 *)obj + 0x48) == 0x6A) {
            savedTempBuf = objTempBuf;
            objTempBufSize = 0x4000;
            objTempBuf = mmAlloc(0x4000, 0xFFFF);
            sprintInit(obj);
            mmFree(objTempBuf);
            objTempBufSize = 0x2000;
            objTempBuf = savedTempBuf;
        }
    }

    if ((multiPlayerGame != 0 && multiGameType == 4) || racingInGame != 0) {
        modPhitInit();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objSetupPlayers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80005DDC(s32 arg0, s32 arg1) {
    s32 i;
    s32 ret = 0;

    for (i = 1; i >= 0; i--) {
        u32 cur = D_800F2CD8_B17C8[i];
        u32 end = cur + D_800F2CE0_B17D0[i];

        while (cur < end) {
            RomDefHeader *romdef = (RomDefHeader *)cur;

            if (arg0 == romdef->id && arg1 == *(u8 *)(cur + 0x11)) {
                objDeleteRomDef((u8 *)cur);
                end = D_800F2CE0_B17D0[i] + D_800F2CD8_B17C8[i];
            } else {
                cur += romdef->size;
            }
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80005DDC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDeleteRomDef(u8 *arg0) {
    s32 region;
    u32 size;
    u32 regionEnd;
    u32 start0 = D_800F2CD8_B17C8[0];
    u32 start1 = D_800F2CD8_B17C8[1];
    u32 end0 = start0 + D_800F2CE0_B17D0[0];
    u32 end1 = start1 + D_800F2CE0_B17D0[1];
    u8 *dst;
    u8 *src;
    s32 i;

    size = arg0[2];
    /* asm uses signed slt compares; outside both regions it never sets region
       and reads an unset stack slot, so no early return here */
    if ((s32)arg0 >= (s32)start0 && (s32)arg0 < (s32)end0) {
        region = 0;
    } else if ((s32)arg0 >= (s32)start1 && (s32)arg0 < (s32)end1) {
        region = 1;
    }
    regionEnd = (region == 0) ? end0 : end1;

    dst = arg0;
    src = arg0 + size;
    while ((u32)src < regionEnd) {
        *dst++ = *src++;
    }
    D_800F2CE0_B17D0[region] -= size;

    for (i = 0; i < ObjListCount; i++) {
        Object *obj = ObjList[i];
        if (obj != NULL) {
            s32 romAddr = *(s32 *)((u8 *)obj + 0x3C);
            if (romAddr != 0) {
                if ((s32)arg0 < romAddr && romAddr < (s32)regionEnd) {
                    *(s32 *)((u8 *)obj + 0x3C) = romAddr - size;
                } else if ((s32)arg0 == romAddr) {
                    *(s32 *)((u8 *)obj + 0x3C) = 0;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDeleteRomDef.s")
#endif

/**
 * Returns the object at the current offset by ID.
 */
Object *objGetObject(s32 index) {
    if (index < 0 || index >= ObjListCount) {
        return 0;
    }
    return ObjList[index];
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
Object **objGetObjList(s32 *arg0, s32 *arg1) {
    *arg0 = D_800F38AC;
    *arg1 = ObjListCount;
    return ObjList;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetObjList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 objGetControlNo(s32 arg0) {
    s32 pad[2];
    u8 buf[0xC0];

    piRomLoadSection(0x2F, (u32)buf, RomTab[(s16)(*(u16 **)objindex)[arg0]], 0xC0);
    return *(s16 *)(buf + 0x1C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetControlNo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Builds the Object in the objTempBuf scratch record (objdef at +0x40, model/texture
// ptr array at +0x6C = obj+0xB4), runs the feature setup helpers, copies the record into
// an objregion block and rebases the temp-buffer-relative pointers. Fields are raw offsets.
// cf. DKR spawn_object (twin) for the overall shape. Only a1 is read by the asm (bit 1 =
// romdef id is the index, bit 0 = keep in ObjList); a2 is never read, so the 2-arg
// prototype above is correct. Callers pass (romdef, 1).
// objindex and NoAddObjList are pointer variables in the asm (lw from the symbol), so
// they are dereferenced explicitly here.
void *objSetupObject(RomDefHeader *romdef, s32 arg1) {
    u8 *tmp;
    u8 *obj;
    u8 *def;
    u8 *cur;
    u8 *p;
    u8 c0c;
    s32 index;
    s32 romId;
    s32 count;
    s32 type;
    s32 flags;
    s32 modelFlags;
    s32 cleared;
    s32 failed;
    s32 keep;
    s32 size;
    s32 words;
    s32 rem;
    s32 k;
    s32 off;
    s32 v;
    s32 i;
    s32 nw;
    s32 tb;

    if (romdef->id == 5 || romdef->id == 0x69) {
        return NULL;
    }
    if (romdef->id == 0x60 || romdef->id == 0x61) {
        return NULL;
    }
    D_800A333C_A3F3C = 1;
    D_800A3340_A3F40 = NULL;
    D_800A3344_A3F44 = 0;
    D_800A3348_A3F48 = 1;

    if (arg1 & 2) {
        index = romdef->id;
    } else {
        index = (s16)(*(u16 **)objindex)[romdef->id];
    }
    if (index < 0 || index >= MaxTypes) {
        D_800A3348_A3F48 = 3;
        return NULL;
    }

    tmp = (u8 *)objTempBuf;
    words = objTempBufSize >> 2;
    for (i = 0; i < words; i++) {
        *(s32 *)(tmp + i * 4) = 0;
    }
    cleared = i;

    obj = tmp;
    D_800A3340_A3F40 = obj;
    *(s16 *)(obj + 0x06) = 2;
    def = (u8 *)((void *(*)(s32, s32, void **, s32))objGetObjdef)(index, 1, &D_800A3340_A3F40, cleared);
    *(u8 **)(obj + 0x40) = def;
    if (def == NULL) {
        D_800A3348_A3F48 = 2;
        return NULL;
    }
    D_800A3344_A3F44 = (s32)(def + 4);
    *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) | (*(u16 *)(def + 0x14) & 0x20C));
    *(f32 *)(obj + 0x0C) = (f32)*(s16 *)((u8 *)romdef + 4);
    *(f32 *)(obj + 0x10) = (f32)*(s16 *)((u8 *)romdef + 6);
    *(f32 *)(obj + 0x14) = (f32)*(s16 *)((u8 *)romdef + 8);
    *(s16 *)(obj + 0x2E) = trackGetBlock(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
    romId = romdef->id;
    *(s16 *)(obj + 0x2C) = (s16)index;
    *(RomDefHeader **)(obj + 0x3C) = romdef;
    *(s16 *)(obj + 0x4A) = (s16)romId;
    *(f32 *)(obj + 0x08) = *(f32 *)def;
    *(u8 *)(obj + 0x39) = 0xFF;
    *(f32 *)(obj + 0x34) = (f32)*(s16 *)(def + 0x18) * *(f32 *)(obj + 0x08);
    *(u8 *)(obj + 0x91) = *(u8 *)(def + 0xA7);
    *(u8 *)(obj + 0x97) = 0xFF;
    *(u8 *)(obj + 0x98) = 0xFF;
    *(u8 *)(obj + 0x99) = 0xFF;
    *(u8 *)(obj + 0x9A) = 0xFF;
    *(s32 *)(obj + 0xA4) = 0;
    *(s32 *)(obj + 0xA8) = 0;
    *(u8 *)(obj + 0xA0) = 0;
    flags = func_8000F8E8(*(s16 *)(def + 0x1C));
    modelFlags = flags & 7;
    *(s8 *)(def + 0x1A) += 1;
    *(u8 **)(obj + 0x6C) = obj + 0xB4;
    count = *(s8 *)(def + 0x1F);
    type = *(s8 *)(def + 0x1E);
    failed = 0;

    switch (type) {
    default:
        *(u8 **)(obj + 0x6C) = NULL;
        break;
    case 4:
        for (i = 0; i < count; i++) {
            *(void **)(*(u8 **)(obj + 0x6C) + i * 4) =
                texLoadTexture(*(s32 *)(*(u8 **)(def + 0x30) + i * 4));
            if (*(void **)(*(u8 **)(obj + 0x6C) + i * 4) == NULL) {
                failed = 1;
            }
        }
        break;
    case 0:
        if (*(u8 *)(def + 0x2E) != 0) {
            modelSetModelFlags(0);
        }
        for (i = 0; i < count; i++) {
            if (i == *(s8 *)(def + 0x60)) {
                *(void **)(*(u8 **)(obj + 0x6C) + i * 4) =
                    modLoadModel(*(s32 *)(*(u8 **)(def + 0x30) + i * 4), modelFlags & ~3);
            } else {
                *(void **)(*(u8 **)(obj + 0x6C) + i * 4) =
                    modLoadModel(*(s32 *)(*(u8 **)(def + 0x30) + i * 4), modelFlags);
            }
            if (*(void **)(*(u8 **)(obj + 0x6C) + i * 4) == NULL) {
                failed = 1;
            }
        }
        modelSetModelFlags(8);
        break;
    case 1:
        for (i = 0; i < count; i++) {
            *(void **)(*(u8 **)(obj + 0x6C) + i * 4) =
                texLoadSprite(*(s32 *)(*(u8 **)(def + 0x30) + i * 4), 0xA);
            if (*(void **)(*(u8 **)(obj + 0x6C) + i * 4) == NULL) {
                failed = 1;
            }
        }
        break;
    }
    if (failed != 0) {
        func_80006FFC(obj, count, type);
        objFreeObjdef(index);
        D_800A3348_A3F48 = 2;
        return NULL;
    }

    cur = *(u8 **)(obj + 0x6C) + count * 4;
    cur += func_8000E5F0(obj, (s32)cur);

    D_800F2CA0_B1790 = NULL;
    if (flags & 0x100) {
        cur += lightInitObjectLighting(obj, cur);
        *(u8 *)(*(u8 **)(obj + 0x54) + 0x0C) = *(u8 *)(*(u8 **)(obj + 0x54) + 0x25);
        *(u8 *)(*(u8 **)(obj + 0x54) + 0x0D) = *(u8 *)(*(u8 **)(obj + 0x54) + 0x27);
    }

    if (flags & 0x200) {
        if (*(u8 *)(def + 0x61) != 0) {
            v = func_80007648(obj, cur);
            cur += v;
            if (v == 0) {
                func_80006FFC(obj, count, type);
                objFreeObjdef(index);
                D_800A3348_A3F48 = 2;
                return NULL;
            }
        }
    }

    if (flags & 0x400) {
        if (*(s8 *)(def + 0x72) != -1) {
            v = wakeSetupRipple(obj, (s32)cur);
            cur += v;
            if (v == 0) {
                if (D_800F2CA0_B1790 != NULL) {
                    texFreeTexture(D_800F2CA0_B1790);
                }
                func_80006FFC(obj, count, type);
                objFreeObjdef(index);
                D_800A3348_A3F48 = 2;
                return NULL;
            }
        }
    }

    if (flags & 0x800) {
        cur += func_80007760(obj, cur, romdef->id);
    }
    if (flags & 0x1000) {
        cur += func_80007968(obj, (s32)cur);
    }
    if (flags & 0x2000) {
        cur += func_80007974(obj, (s32)cur);
    }

    v = *(s8 *)(def + 0x20);
    if (v > 0 && v < 10) {
        *(u8 **)(obj + 0x60) = cur;
        p = mmAlign4(cur + 0x34);
        *(u8 **)(*(u8 **)(obj + 0x60) + 0x30) = p;
        cur = p + *(s8 *)(def + 0x20) * 64;
    }
    v = *(s8 *)(def + 0x21);
    if (v > 0 && v < 10) {
        p = mmAlign4(cur);
        *(u8 **)(obj + 0x64) = p;
        cur = p + v * 20;
    }

    if (*(s16 *)(def + 0x1C) == 0x27) {
        cur += objExplosionSetupTriggers(obj, (s32)cur, romdef);
    } else if (*(s8 *)(def + 0x22) > 0) {
        cur += func_80007494(obj, (s32)cur);
    }

    if (*(s8 *)(def + 0x25) > 0) {
        *(u8 **)(obj + 0x74) = cur;
        cur += *(s8 *)(def + 0x25) * 4;
    }
    if (*(u8 *)(def + 0x26) != 0) {
        *(u8 **)(obj + 0x78) = cur;
        cur += *(u8 *)(def + 0x26) * 4;
    }
    if (*(s32 *)(def + 0xD0) != 0) {
        cur += func_800075EC(obj, (s8 *)cur);
    }

    v = (s32)cur - (s32)obj;
    if (*(u8 *)(obj + 0x91) != 0) {
        p = mmAlign4(cur);
        *(u8 **)(obj + 0x80) = p;
        cur = p + *(u8 *)(def + 0xA7) * 36;
        v = (s32)cur - (s32)obj;
    }

    size = v;
    if (size & 0xF) {
        size = (size & ~0xF) + 0x10;
    }

    obj = (u8 *)mmAllocR(objregion, size);
    if (obj == NULL && D_800A0898_A1498 != 0) {
        obj = (u8 *)mmAlloc(size, 0xFFFF);
    }
    if (obj == NULL) {
        if (D_800F2CA0_B1790 != NULL) {
            texFreeTexture(D_800F2CA0_B1790);
        }
        func_80006FFC(tmp, count, type);
        objFreeObjdef(index);
        D_800A3348_A3F48 = 2;
        return NULL;
    }

    words = size >> 2;
    if (words > 0) {
        rem = words & 3;
        k = 0;
        if (rem != 0) {
            do {
                *(s32 *)(obj + k * 4) = *(s32 *)(tmp + k * 4);
                k++;
            } while (k != rem);
        }
        if (k != words) {
            off = k * 4;
            do {
                *(s32 *)(obj + off) = *(s32 *)(tmp + off);
                *(s32 *)(obj + off + 4) = *(s32 *)(tmp + off + 4);
                *(s32 *)(obj + off + 8) = *(s32 *)(tmp + off + 8);
                *(s32 *)(obj + off + 12) = *(s32 *)(tmp + off + 12);
                off += 0x10;
            } while (off != words * 4);
        }
    }

    nw = (s32)obj;
    tb = (s32)tmp;

    /* rebase temp-buffer pointers onto the new block */
    if (*(s32 *)(obj + 0x58) != 0) {
        *(s32 *)(obj + 0x58) = nw + *(s32 *)(obj + 0x58) - tb;
    }
    if (*(s32 *)(obj + 0x50) != 0) {
        *(s32 *)(obj + 0x50) = nw + *(s32 *)(obj + 0x50) - tb;
        p = *(u8 **)(obj + 0x50);
        if (*(s32 *)(p + 0x1C) != 0) {
            *(s32 *)(p + 0x1C) = nw + *(s32 *)(p + 0x1C) - tb;
        }
    }
    if (*(s32 *)(obj + 0x54) != 0) {
        *(s32 *)(obj + 0x54) = nw + *(s32 *)(obj + 0x54) - tb;
    }
    if (*(s32 *)(obj + 0x68) != 0) {
        *(s32 *)(obj + 0x68) = nw + *(s32 *)(obj + 0x68) - tb;
    }
    if (*(s32 *)(obj + 0x4C) != 0) {
        *(s32 *)(obj + 0x4C) = nw + *(s32 *)(obj + 0x4C) - tb;
        p = *(u8 **)(obj + 0x4C);
        if (*(s32 *)(p + 0x40) != 0) {
            *(s32 *)(p + 0x40) = nw + *(s32 *)(p + 0x40) - tb;
        }
    }
    if (*(s32 *)(obj + 0x5C) != 0) {
        *(s32 *)(obj + 0x5C) = nw + *(s32 *)(obj + 0x5C) - tb;
        p = *(u8 **)(obj + 0x5C);
        if (*(s32 *)(p + 0x134) != 0) {
            *(s32 *)(p + 0x134) = nw + *(s32 *)(p + 0x134) - tb;
        }
    }
    if (*(s32 *)(obj + 0x60) != 0) {
        *(s32 *)(obj + 0x60) = nw + *(s32 *)(obj + 0x60) - tb;
    }
    if (*(s32 *)(obj + 0x64) != 0) {
        *(s32 *)(obj + 0x64) = nw + *(s32 *)(obj + 0x64) - tb;
    }
    if (*(s32 *)(obj + 0x80) != 0) {
        *(s32 *)(obj + 0x80) = nw + *(s32 *)(obj + 0x80) - tb;
    }
    if (*(s32 *)(obj + 0x70) != 0) {
        *(s32 *)(obj + 0x70) = nw + *(s32 *)(obj + 0x70) - tb;
    }
    if (*(s8 *)(def + 0x25) > 0) {
        *(s32 *)(obj + 0x74) = nw + *(s32 *)(obj + 0x74) - tb;
    }
    if (*(u8 *)(def + 0x26) > 0) {
        *(s32 *)(obj + 0x78) = nw + *(s32 *)(obj + 0x78) - tb;
    }
    if (*(s32 *)(def + 0xD0) != 0) {
        *(s32 *)(obj + 0x7C) = nw + *(s32 *)(obj + 0x7C) - tb;
    }
    *(u8 **)(obj + 0x6C) = obj + 0xB4;

    keep = arg1 & 1;
    if (keep != 0) {
        ObjList[ObjListCount] = (Object *)obj;
        ObjListCount += 1;
    } else {
        (*(Object ***)NoAddObjList)[D_800F38B8] = (Object *)obj;
        D_800F38B8 += 1;
    }

    if (*(s32 *)(obj + 0x4C) != 0) {
        hitInitObjectHit(obj, 0x64, *(u8 *)(def + 0xBA), *(u8 *)(def + 0xBB),
                         *(s16 *)(def + 0xB4), *(s16 *)(def + 0xB6), *(s16 *)(def + 0xB8),
                         *(f32 *)(def + 0xBC), *(f32 *)(def + 0xC0), *(f32 *)(def + 0xC4),
                         *(f32 *)(def + 0xC8), 1);
    }
    if (*(s8 *)(def + 0x25) > 0) {
        lightSetupLightSources((Object *)obj);
    }
    if (*(u8 *)(def + 0x26) != 0) {
        ((void (*)(void *, RomDefHeader *))lightSetupFlareSources)(obj, romdef); /* sig mismatch */
    }
    ((void (*)(void *, RomDefHeader *, s32))objSetup)(obj, romdef, 0); /* sig mismatch: 3-arg call */
    if (*(s32 *)(obj + 0x5C) != 0) {
        cloneSetupShadow_2arg(obj, modelFlags); /* sig mismatch: 2-arg call, see alias */
    }

    if (func_8000710C(obj) != 0) {
        if (D_800F2CA0_B1790 != NULL) {
            texFreeTexture(D_800F2CA0_B1790);
        }
        func_80006FFC(obj, count, type);
        objFreeObjdef(index);
        mmFree(obj);
        if (keep != 0) {
            ObjListCount -= 1;
        } else {
            D_800F38B8 -= 1;
        }
        D_800A3348_A3F48 = 2;
        return NULL;
    }

    if ((flags & 0x200) != 0 && *(u8 *)(def + 0x61) != 0) {
        p = *(u8 **)(obj + 0x50);
        if (*(s32 *)(p + 0x1C) != 0) {
            c0c = *(u8 *)(p + 0x0C);
            if (c0c & 8) {
                cloneBlobSetup(obj);
            } else if (c0c & 0x10) {
                squadsTidyEventList(obj);
            }
        }
    }

    D_800F2EA0_B1990[D_800A0974_A1574] =
        ((s32)*(s16 *)(obj + 0x48) << 16) | (s32)*(s16 *)(obj + 0x4A);
    D_800A0974_A1574 = (u8)((D_800A0974_A1574 + 1) & 0xF);
    D_800A3348_A3F48 = 4;
    return obj;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objSetupObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80006FFC(void *arg0, s32 arg1, s32 arg2) {
    void **list = *(void ***)((u8 *)arg0 + 0x6C);
    s32 i;

    for (i = 0; i < arg1; i++) {
        if (arg2 == 0) {
            if (list[i] != NULL) {
                modFreeModel(list[i]);
            }
        } else if (arg2 == 4) {
            if (list[i] != NULL) {
                texFreeTexture(list[i]);
            }
        } else {
            if (list[i] != NULL) {
                texFreeSprite(list[i]);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80006FFC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8000710C(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *def = *(u8 **)(obj + 0x40);
    s8 count = *(s8 *)(def + 0x20);
    u8 *list60 = NULL;
    u8 *spriteList = NULL;
    s32 failed = 0;
    s32 i;
    s8 n21;

    if (count > 0 && count < 10) {
        list60 = *(u8 **)(obj + 0x60);
        *(s32 *)list60 = count;
        for (i = 0; i < count; i++) {
            void *p = func_80007984(((s32 *)*(u8 **)(def + 0x34))[i]);
            if (p != NULL) {
                *(f32 *)((u8 *)p + 0x8) = *(f32 *)((u8 *)p + 0x8) * *(f32 *)(obj + 0x8);
            }
            ((void **)list60)[i + 1] = p;
            if (p == NULL) {
                failed = 1;
            }
        }
        *(s32 *)(list60 + 0x2C) = *(s32 *)(def + 0x38);
    }

    n21 = *(s8 *)(def + 0x21);
    *(s8 *)(obj + 0x90) = n21;
    if ((u8)n21 > 0 && n21 < 10) {
        u8 *ent = *(u8 **)(def + 0x3C);

        spriteList = *(u8 **)(obj + 0x64);
        for (i = 0; i < (s32)(u8)n21; i++) {
            u8 *slot = spriteList + i * 0x14;
            u8 *e = ent + i * 0xC;
            u32 flags;
            u8 firstByte;
            void *tex;

            tex = texLoadSprite(*(u16 *)e, 1);
            *(void **)slot = tex;
            *(s8 *)(slot + 4) = *(s8 *)(e + 2);
            flags = *(u32 *)(e + 8);
            *(u32 *)(slot + 0xC) = flags;
            *(f32 *)(slot + 0x8) = ((f32)*(s16 *)(e + 4) / 500.0f) * *(f32 *)(obj + 0x8);
            *(u8 *)(slot + 5) = *(u8 *)(e + 3);

            firstByte = *(u8 *)tex;
            if (flags & 0x80000000) {
                *(f32 *)(slot + 0x10) = (f32)mathRnd(0, firstByte);
            } else if (flags & 0x40000000) {
                u8 *ref = spriteList + ((flags >> 0x16) & 0x3F) * 0x14;
                *(f32 *)(slot + 0x10) = *(f32 *)(ref + 0x10) + (f32)((flags >> 0x10) & 0x3F);
            } else if (flags & 0x20000000) {
                u8 *ref = spriteList + ((flags >> 0x16) & 0x3F) * 0x14;
                *(f32 *)(slot + 0x10) = *(f32 *)(ref + 0x10) - (f32)((flags >> 0x10) & 0x3F);
            }

            if ((f32)firstByte < *(f32 *)(slot + 0x10)) {
                *(f32 *)(slot + 0x10) = *(f32 *)(slot + 0x10) - (f32)firstByte;
            } else if (*(f32 *)(slot + 0x10) < 0.0f) {
                *(f32 *)(slot + 0x10) = *(f32 *)(slot + 0x10) + (f32)firstByte;
            }
            if (*(void **)slot == NULL) {
                failed = 1;
            }
        }
    }

    if (failed != 0) {
        if (list60 != NULL) {
            for (i = 0; i < *(s32 *)list60; i++) {
                u8 *p = (u8 *)((void **)list60)[i + 1];
                if (p != NULL) {
                    u8 *pd = *(u8 **)(p + 0x40);
                    func_80006FFC(p, *(s8 *)(pd + 0x1F), *(s8 *)(pd + 0x1E));
                    objFreeObjdef(*(s16 *)(p + 0x2C));
                    mmFree(p);
                }
            }
            *(s32 *)(list60 + 0x2C) = 0;
        }
        if (spriteList != NULL) {
            u8 **slots = *(u8 ***)(obj + 0x64);
            for (i = 0; i < (s32)(u8)*(s8 *)(obj + 0x90); i++) {
                if (slots[0] != NULL) {
                    texFreeSprite(slots[0]);
                    slots[0] = NULL;
                }
            }
        }
    }
    return failed;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000710C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80007494(void *arg0, s32 arg1) {
    u8 *def = *(u8 **)((u8 *)arg0 + 0x40);
    u32 *entry;
    s32 count;
    s32 i;
    s32 off = 0;

    *(s32 *)((u8 *)arg0 + 0x70) = arg1;
    count = *(s8 *)(def + 0x22);
    if (count > 0) {
        entry = *(u32 **)(def + 0x40);
        for (i = 0; i < count; i++) {
            u32 e = entry[0];
            u32 w4 = entry[1];

            if ((e & 0xFFFF0000) == 0xFFFF0000) {
                partInitTrigger((void *)(arg1 + off), (e >> 8) & 0xFF, e & 0xFF);
            } else if ((e & 0xFFFF0000) == 0xFFFE0000) {
                partInitTriggerSPPos((void *)(arg1 + off), (e >> 8) & 0xFF, e & 0xFF, w4 & 0xFF);
            } else {
                partInitTriggerPos((void *)(arg1 + off), (e >> 24) & 0xFF, (e >> 16) & 0xFF,
                                   (s16)e, (w4 >> 16) & 0xFFFF, w4 & 0xFFFF);
            }
            off += 0x24;
            entry += 2;
        }
    }
    return ((count * 0x24) + 3) & ~3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80007494.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_800075EC(void *arg0, s8 *arg1) {
    *(s8 **)((u8 *)arg0 + 0x7C) = arg1;
    *arg1 = 2;
    return 0x28;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_800075EC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Fills the 0x50-byte record at arg1 from objdef (arg0->+0x40), loads its texture.
s32 func_80007648(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *dst = (u8 *)arg1;
    u8 *def = *(u8 **)(obj + 0x40); // objdef: +0 f32 scale, +0x1E type, +0x1F count (cf. jfg-re levels.md)
    u8 flags;
    s32 size = 0x20;
    TextureHeader *tex;

    *(void **)(obj + 0x50) = dst;
    *(f32 *)(dst + 0x00) = *(f32 *)(def + 0x54);
    flags = def[0x61];
    dst[0x0C] = flags;
    dst[0x0D] = def[0x62];
    dst[0x0F] = 0;
    *(s16 *)(dst + 0x08) = 0;
    dst[0x0E] = def[0x63];
    *(s32 *)(dst + 0x1C) = 0;
    *(u16 *)(dst + 0x0A) = *(u16 *)(def + 0x66);

    if (multiPlayerGame == 0) {
        if (flags & 0x08) {
            s32 end = (((s32)dst + 0x20) & ~3) + 4;

            *(s32 *)(dst + 0x1C) = end;
            size = (end - (s32)dst) + 0xBC;
        } else if (flags & 0x10) {
            s32 end = (((s32)dst + 0x20) & ~3) + 4;

            *(s32 *)(dst + 0x1C) = end;
            size = (end - (s32)dst) + 0x38;
        }
    } else {
        dst[0x0C] = 5;
        dst[0x0D] = 1;
    }

    tex = texLoadTexture(*(s16 *)(def + 0x64));
    *(TextureHeader **)(dst + 0x04) = tex;
    if (tex == NULL) {
        return 0;
    }
    D_800F2CA0_B1790 = tex;
    return (size & ~3) + 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80007648.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Sets up the per-entry sub-array at arg1+0x44 from the model's 12-byte records
// (model +0x2F count, +0x38 records). With arg2 == 0xE6 it builds a fixed 40-entry table.
s32 func_80007760(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *dst = (u8 *)arg1;
    s32 ret = 0x44;
    s32 i;

    *(void **)(obj + 0x4C) = dst;
    if (*(s8 *)(*(u8 **)(obj + 0x40) + 0x1E) == 0) {
        u8 *model = *(u8 **)(*(u8 **)(obj + 0x6C));
        u8 count = model[0x2F];

        if (count > 0) {
            u8 *ent = dst + 0x44;
            s32 n;

            *(s16 *)(dst + 0x32) = (s16)count;
            *(u8 **)(dst + 0x40) = ent;
            n = *(s16 *)(dst + 0x32);
            ret = (n * 0x34) + 0x44;
            if (n > 0) {
                for (i = 0; i < n; i++) {
                    u8 *e = ent + i * 0x34;
                    u8 *r = *(u8 **)(model + 0x38) + i * 0xC;

                    *(s16 *)(e + 0x00) = 0;
                    *(s16 *)(e + 0x02) = 0;
                    *(s16 *)(e + 0x04) = 0;
                    *(u16 *)(e + 0x06) = *(u16 *)(r + 0x00);
                    *(s8 *)(e + 0x08) = *(s8 *)(r + 0x02);
                    *(u8 *)(e + 0x09) = r[0x03];
                    *(s16 *)(e + 0x0A) = 0;
                    *(f32 *)(e + 0x24) = *(f32 *)(r + 0x08) * *(f32 *)(obj + 0x08);
                    *(f32 *)(e + 0x28) = *(f32 *)(r + 0x08) * *(f32 *)(obj + 0x08);
                    e[0x2E] = (u8)*(u16 *)(r + 0x04);
                    e[0x2F] = (u8)*(u16 *)(r + 0x06);
                    *(s16 *)(e + 0x2C) = 0;
                    e[0x30] = (u8)((e[0x30] | 0x80) & 0xBF);
                }
            }
        }
    }

    if (arg2 == 0xE6) {
        u8 *cur = *(u8 **)(obj + 0x4C);
        u8 *ent2 = dst + ret;
        s32 n2;

        *(s16 *)(cur + 0x32) = 0x28;
        n2 = *(s16 *)(cur + 0x32);
        ret += n2 * 0x34;
        *(u8 **)(cur + 0x40) = ent2;
        for (i = 0; i < n2; i++) {
            u8 *e = ent2 + i * 0x34;

            *(s16 *)(e + 0x00) = 0;
            e[0x30] = (u8)((e[0x30] | 0x80) & 0xBF);
            *(s16 *)(e + 0x02) = 0;
            *(s16 *)(e + 0x04) = 0;
            *(s16 *)(e + 0x06) = 0;
            *(s8 *)(e + 0x08) = -1;
            e[0x09] = (u8)i;
            *(s16 *)(e + 0x0A) = 0;
            *(f32 *)(e + 0x24) = 40.0f;
            *(f32 *)(e + 0x28) = 40.0f;
            e[0x2E] = 0x64;
            e[0x2F] = 0;
            *(s16 *)(e + 0x2C) = 0;
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80007760.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80007968(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x5C) = arg1;
    return 0x13C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80007968.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80007974(void *arg0, s32 arg1) {
    u8 *p;
    p = *(u8 **)((u8 *)arg0 + 0x5C);
    *(s32 *)(p + 0x134) = arg1;
    return 0x11C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80007974.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Builds an Object record in objTempBuf (objdef at +0x40, model ptr array at +0x6C = obj+0xB4,
// count = objdef +0x1F, type = objdef +0x1E), then copies it into a fresh mmAlloc2 block.
void *func_80007984(s32 arg0) {
    u8 *objdef;
    u8 *obj;
    u8 *end;
    void *newObj = NULL;
    s32 words;
    s32 i;
    s32 count;
    s32 type;
    s32 flags;
    s32 failed = 0;
    s32 size;

    if (arg0 >= MaxTypes) {
        arg0 = 0;
    }
    objdef = (u8 *)objGetObjdef(arg0);
    if (objdef == NULL) {
        return NULL;
    }
    obj = (u8 *)objTempBuf;
    end = obj + 0xB4 + *(s8 *)(objdef + 0x1F) * 4;

    words = objTempBufSize >> 2;
    for (i = 0; i < words; i++) {
        ((s32 *)obj)[i] = 0;
    }

    *(u8 **)(obj + 0x40) = objdef;
    *(s16 *)(obj + 0x06) = 2;
    *(s16 *)(obj + 0x2C) = (s16)arg0;
    *(s16 *)(obj + 0x4A) = (s16)arg0;
    *(f32 *)(obj + 0x08) = *(f32 *)(objdef + 0x00);
    *(s16 *)(obj + 0x06) = (s16)(*(s16 *)(obj + 0x06) | (*(u16 *)(objdef + 0x14) & 0x20C));
    flags = func_8000F8E8(*(s16 *)(objdef + 0x1C), (s32 *)objTempBuf, objdef) & 7;

    count = *(s8 *)(objdef + 0x1F);
    type = *(s8 *)(objdef + 0x1E);
    *(u8 **)(obj + 0x6C) = obj + 0xB4;
    for (i = 0; i < count; i++) {
        s32 id = *(s32 *)(*(u8 **)(objdef + 0x30) + i * 4);

        if (type == 0) {
            *(void **)(*(u8 **)(obj + 0x6C) + i * 4) = modLoadModel(id, flags);
        } else {
            *(void **)(*(u8 **)(obj + 0x6C) + i * 4) = texLoadSprite(id, 0xA);
        }
        if (*(void **)(*(u8 **)(obj + 0x6C) + i * 4) == NULL) {
            failed = 1;
        }
    }

    if (failed == 0) {
        size = (s32)end - (s32)obj;
        if (size & 0xF) {
            size = (size + 0xF) & ~0xF;
        }
        /* asm: mmAlloc2 returns the block, but memory.h declares it void */
        newObj = ((void *(*)(s32, u32))mmAlloc2)(size, 0xFFFF);
        if (newObj != NULL) {
            s32 *src = (s32 *)objTempBuf;
            s32 *dst = (s32 *)newObj;

            words = size >> 2;
            for (i = 0; i < words; i++) {
                dst[i] = src[i];
            }
            *(u8 **)((u8 *)newObj + 0x6C) = (u8 *)newObj + 0xB4;
        } else {
            failed = 1;
        }
    }

    if (failed != 0) {
        func_80006FFC(obj, count, type);
        objFreeObjdef(arg0);
        newObj = NULL;
    }
    return newObj;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80007984.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objFreeObject(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 idx;

    if (*(u8 *)(obj + 0xA0) == 0) {
        deletelist[D_800F3908] = (Object *)obj;
        D_800F3908 += 1;
        *(u8 *)(obj + 0xA0) = 1;
        objEnsureNotTargetted();
        idx = D_800A097C_A157C;
        D_800F2F20_B1A10[idx] = ((u32)*(s16 *)(obj + 0x48) << 16) | *(s16 *)(obj + 0x4A);
        D_800A097C_A157C = (idx + 1) & 0xF;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objFreeObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDoFrees(void) {
    s32 i;
    s32 j;
    s32 k;

    D_800F38C4 = 0;
    for (i = 0; i < D_800F3908; i++) {
        Object *target = deletelist[i];
        s32 found = -1;

        for (j = 0; j < ObjListCount; j++) {
            if (ObjList[j] == target) {
                s32 newCount = ObjListCount - 1;

                found = j;
                if (j < D_800F38C2) {
                    D_800F38C2 -= 1;
                }
                for (k = j; k < newCount; k++) {
                    ObjList[k] = ObjList[k + 1];
                }
                ObjListCount = newCount;
                func_80007EA0(target, 0);
                break;
            }
        }

        if (found == -1) {
            for (j = 0; j < D_800F38B8; j++) {
                if (NoAddObjList[j] == target) {
                    s32 newCount = D_800F38B8 - 1;

                    for (k = j; k < newCount; k++) {
                        NoAddObjList[k] = NoAddObjList[k + 1];
                    }
                    D_800F38B8 = newCount;
                    func_80007EA0(target, 0);
                    break;
                }
            }
        }
    }
    D_800F3908 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDoFrees.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80007EA0(void *obj, s32 arg1) {
    /* Object fields used here (raw offsets, from the asm):
     *   +0x2C s16 objdef index       +0x40 objdef ptr: +0x14 u16 flags, +0x1E s8 model type,
     *                                 +0x1F s8 model count, +0x25 s8 light count,
     *                                 +0x26 u8 camlight count, +0x61 u8 flags
     *   +0x48 s16 behaviorId         +0x4A s16 (compared with 0x1B2)
     *   +0x50 clone ptr              +0x58 wake ripple handle / list head
     *   +0x60 sub-object list: s32 count, then Object* entries at +4, +8, ...
     *   +0x64 sprite array (stride 0x14, u8 count at +0x90)
     *   +0x68 private (racer) ptr    +0x6C model/texture handle array (s32 entries)
     *   +0x74 light array            +0x78 camlight array
     *   +0x7C sound ptr              +0x88 / +0x8C object refs     +0xA2 u8 particle flag
     */
    u8 *o = (u8 *)obj;
    u8 *priv;
    u8 *def;
    u8 *rec;
    u8 *sub;
    u8 *arr;
    u8 *head;
    u8 *next;
    u8 *tgt;
    s32 n;
    s32 i;
    s32 k;
    s32 cnt;

    D_800A333C_A3F3C = 2;
    D_800A3348_A3F48 = 1;
    D_800A3340_A3F40 = obj;
    D_800A3344_A3F44 = (s32)*(u8 **)(o + 0x40) + 4;
    /* record (behaviorId << 16 | +0x4A) in a small ring buffer */
    D_800F2EE0_B19D0[D_800A0978_A1578] = ((s32)*(s16 *)(o + 0x48) << 16) | *(s16 *)(o + 0x4A);
    D_800A0978_A1578 = (D_800A0978_A1578 + 1) & 0xF;

    /* drop the global "current target" reference if it points at us */
    if (D_800F2D14_B1804 != 0) {
        tgt = *(u8 **)((u8 *)D_800F2D14_B1804 + 0x68);
        if (tgt != NULL && *(void **)(tgt + 0x50) == obj) {
            *(void **)(tgt + 0x50) = NULL;
        }
    }
    objEnsureNotTargetted();
    if (arithmeticSums[5] == 0x4F) {
        func_80011AD4(obj);
    }
    if (runlinkIsModuleLoaded(3) != 0) {
        hoovertankFree(obj);
    }

    /* sub-object list at +0x60: free each entry's models/sprites, objdef and the entry itself */
    rec = *(u8 **)(o + 0x60);
    if (rec != NULL) {
        n = *(s32 *)rec;
        for (i = 0; i < n; i++) {
            sub = *(u8 **)(rec + 4 + i * 4);
            def = *(u8 **)(sub + 0x40);
            cnt = *(s8 *)(def + 0x1F);
            if (*(s8 *)(def + 0x1E) == 0) {
                arr = *(u8 **)(sub + 0x6C);
                for (k = 0; k < cnt; k++) {
                    modFreeModel(*(void **)(arr + k * 4));
                }
            } else {
                arr = *(u8 **)(sub + 0x6C);
                for (k = 0; k < cnt; k++) {
                    texFreeSprite(*(void **)(arr + k * 4));
                }
            }
            objFreeObjdef(*(s16 *)(sub + 0x2C));
            mmFree(sub);
        }
    }

    /* sprite array at +0x64, stride 0x14, count u8 at +0x90 */
    if (*(void **)(o + 0x64) != NULL) {
        cnt = *(u8 *)(o + 0x90);
        for (i = 0; i < cnt; i++) {
            texFreeSprite(*(void **)(*(u8 **)(o + 0x64) + i * 0x14));
        }
    }
    partObjFreeTriggers(obj);

    /* light array at +0x74, count s8 at objdef +0x25 */
    if (*(void **)(o + 0x74) != NULL) {
        cnt = *(s8 *)(*(u8 **)(o + 0x40) + 0x25);
        for (k = 0; k < cnt; k++) {
            killLight(*(void **)(*(u8 **)(o + 0x74) + k * 4));
        }
    }
    /* camlight array at +0x78, count u8 at objdef +0x26 */
    if (*(void **)(o + 0x78) != NULL) {
        cnt = *(u8 *)(*(u8 **)(o + 0x40) + 0x26);
        for (k = 0; k < cnt; k++) {
            camlightDelete(*(void **)(*(u8 **)(o + 0x78) + k * 4));
        }
    }
    if (*(u16 *)(*(u8 **)(o + 0x40) + 0x14) & 0x40) {
        controlPlayerStopAimAndLook(obj);
    }

    /* per-behaviour cleanup (switch 1) */
    switch (*(s16 *)(o + 0x48)) {
    case 0x80:
        trackFadeEnd = 0xFF;
        trackFade = trackFadeEnd;
        trackFadeCount = 0;
        break;
    case 0x64:
        joyEnable(0);
        break;
    case 0x88:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0x10) != NULL) {
            objFreeObject(*(void **)(priv + 0x10));
        }
        break;
    case 0x85:
        splinecamMakeSpline(obj);
        break;
    case 0x84:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0x20) != NULL) {
            killLight(*(void **)(priv + 0x20));
        }
        if (*(void **)(priv + 0x2C) != NULL) {
            trackLightDelete(*(void **)(priv + 0x2C));
        }
        break;
    case 0x13:
        cameraDeleteOverrideObject(obj);
        break;
    case 0x38:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0x0) != NULL) {
            killLight(*(void **)(priv + 0x0));
        }
        if (*(void **)(*(u8 **)(o + 0x68) + 0x4) != NULL) {
            camlightDelete(*(void **)(*(u8 **)(o + 0x68) + 0x4));
        }
        break;
    case 0x53:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x8) != NULL) {
            killLight(*(void **)(*(u8 **)(o + 0x68) + 0x8));
        }
        break;
    case 0x45:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x0) != NULL) {
            objFreeObject(*(void **)(*(u8 **)(o + 0x68) + 0x0));
        }
        break;
    case 0x11:
        staticcamDelete(obj);
        break;
    case 0x12:
        TidyLinkedList((u8)*(u8 *)(*(u8 **)(o + 0x68) + 0x0));
        break;
    case 0x1:
    case 0x32:
        /* loop runs ObjListCount times */
        cnt = ObjListCount;
        for (i = 0; i < cnt; i++) {
            rec = (u8 *)ObjList[i];
            if (*(s16 *)(rec + 0x48) == 0x16) {
                tgt = *(u8 **)(rec + 0x68);
                if (obj == *(void **)(tgt + 0x100)) {
                    *(void **)(tgt + 0x100) = NULL;
                    *(u8 *)(tgt + 0xFD) = 1;
                }
            } else if (*(s16 *)(rec + 0x48) == 0x14) {
                tgt = *(u8 **)(rec + 0x68);
                if (obj == *(void **)(tgt + 0x8)) {
                    *(void **)(tgt + 0x8) = NULL;
                }
            }
        }
        break;
    case 0x4D:
        cnt = ObjListCount;
        for (i = 0; i < cnt; i++) {
            rec = (u8 *)ObjList[i];
            if (*(s16 *)(rec + 0x48) == 0x14) {
                tgt = *(u8 **)(rec + 0x68);
                if (obj == *(void **)(tgt + 0xC)) {
                    *(void **)(tgt + 0xC) = NULL;
                }
            }
        }
        break;
    case 0xA6:
    case 0xA7:
        objDeleteMine((s32)obj);
        /* fallthrough */
    case 0x9B:
        cnt = ObjListCount;
        for (i = 0; i < cnt; i++) {
            rec = (u8 *)ObjList[i];
            if (*(s16 *)(rec + 0x48) == 0x14) {
                tgt = *(u8 **)(rec + 0x68);
                if (obj == *(void **)(tgt + 0x10)) {
                    *(void **)(tgt + 0x10) = NULL;
                }
            }
        }
        break;
    case 0x1E:
        killLight(*(void **)(o + 0x68));
        break;
    case 0x10:
        priv = *(u8 **)(o + 0x68);
        if (priv != NULL) {
            mmFree(priv);
        }
        break;
    case 0xC:
        if (*(void **)(o + 0x88) != NULL) {
            camlightDelete(*(void **)(o + 0x88));
        }
        break;
    case 0x17:
        priv = *(u8 **)(o + 0x68);
        head = *(u8 **)(priv + 0x58);
        cnt = *(u8 *)(priv + 0x0);
        if (head != NULL && cnt > 0) {
            for (k = 0; k < cnt; k++) {
                if (head == NULL) {
                    break;
                }
                next = *(u8 **)(*(u8 **)(head + 0x68) + 0x28);
                objFreeObject(head);
                head = next;
            }
        }
        if (*(void **)(priv + 0x84) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0x84));
        }
        break;
    case 0x18:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0xB4) != NULL) {
            objFreeObject(*(void **)(priv + 0xB4));
        }
        shardClusterDestroy(obj);
        if (*(void **)(priv + 0xB8) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0xB8));
        }
        if (*(void **)(priv + 0xBC) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0xBC));
        }
        if (*(void **)(priv + 0xC0) != NULL) {
            trackLightDelete(*(void **)(priv + 0xC0));
            *(void **)(priv + 0xC0) = NULL;
        }
        if (*(void **)(priv + 0xC4) != NULL) {
            killLight(*(void **)(priv + 0xC4));
            *(void **)(priv + 0xC4) = NULL;
        }
        if (*(void **)(priv + 0xB0) != NULL) {
            mmFree(*(void **)(priv + 0xB0));
        }
        tgt = *(u8 **)(priv + 0x24);
        if (tgt != NULL && *(u16 *)(*(u8 **)(tgt + 0x68) + 0x2C) == 0x70) {
            if (*(void **)(priv + 0xA8) != NULL) {
                objFreeObject(*(void **)(priv + 0xA8));
            }
        }
        cnt = ObjListCount;
        for (i = 0; i < cnt; i++) {
            rec = (u8 *)ObjList[i];
            if (*(s16 *)(rec + 0x4A) == 0x1B2 && obj == *(void **)(o + 0x8C)) {
                *(void **)(o + 0x8C) = NULL;
            }
        }
        break;
    case 0x41:
        lightKillGlowingLight(*(void **)(o + 0x68));
        break;
    case 0x24:
        animshipFree(obj);
        break;
    case 0x40:
        severedLimbDestroy(obj);
        break;
    case 0x4C:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x14) != NULL) {
            objFreeObject(*(void **)(*(u8 **)(o + 0x68) + 0x14));
        }
        break;
    case 0x4E:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x14) != NULL) {
            mmFree(*(void **)(*(u8 **)(o + 0x68) + 0x14));
        }
        break;
    case 0x52:
        priv = *(u8 **)(o + 0x68);
        /* three killLight calls on consecutive words at +0x4F8 */
        for (k = 0; k < 3; k++) {
            killLight(*(void **)(priv + 0x4F8 + k * 4));
        }
        if (*(void **)(priv + 0x504) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0x504));
        }
        break;
    case 0x59:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0x8) != NULL) {
            killLight(*(void **)(priv + 0x8));
        }
        if (*(void **)(priv + 0x4) != NULL) {
            trackLightDelete(*(void **)(priv + 0x4));
        }
        break;
    case 0x58:
        priv = *(u8 **)(o + 0x68);
        /* four killLight calls on consecutive words at +0xF30 */
        for (k = 0; k < 4; k++) {
            killLight(*(void **)(priv + 0xF30 + k * 4));
        }
        if (*(void **)(priv + 0xFC4) != NULL) {
            amSndStop((s32)*(void **)(priv + 0xFC4));
        }
        break;
    case 0x9D:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x90) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x68) + 0x90));
        }
        break;
    case 0x28:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x190) != NULL) {
            texFreeTexture(*(void **)(*(u8 **)(o + 0x68) + 0x190));
        }
        break;
    case 0x29:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x6E8) != NULL) {
            texFreeTexture(*(void **)(*(u8 **)(o + 0x68) + 0x6E8));
        }
        break;
    case 0x62:
        if (*(void **)(o + 0x88) != NULL) {
            objFreeObject(*(void **)(o + 0x88));
        }
        break;
    case 0x5F:
    case 0x96:
        mizarFree(obj);
        break;
    case 0x72:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0x0) != NULL) {
            mmFree(*(void **)(priv + 0x0));
        }
        if (*(void **)(priv + 0x4) != NULL) {
            mmFree(*(void **)(priv + 0x4));
        }
        break;
    case 0x7F:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x4) != NULL) {
            mmFree(*(void **)(*(u8 **)(o + 0x68) + 0x4));
        }
        break;
    case 0x6C:
        mantismissileFree(obj);
        break;
    case 0xA9:
        menuCamFacingTVCleanup(obj);
        break;
    case 0x63:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x0) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x68) + 0x0));
        }
        break;
    case 0x33:
        func_80008F60((s32)obj);
        break;
    }

    /* per-behaviour sound cleanup (switch 2) */
    switch (*(s16 *)(o + 0x48)) {
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x93:
        if (*(void **)(o + 0x88) != NULL) {
            amSndStopXYZ(*(void **)(o + 0x88));
        }
        break;
    case 0x37:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x4) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x68) + 0x4));
        }
        break;
    case 0x48:
        menuCamCleanup(obj);
        break;
    case 0x46:
        multiCharArmCleanup(obj);
        break;
    case 0x5C:
        sidekickpadFree(obj);
        break;
    case 0x69:
        if (*(void **)(*(u8 **)(o + 0x68) + 0xC) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x68) + 0xC));
        }
        break;
    case 0x8B:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x0) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x68) + 0x0));
        }
        break;
    case 0x5D:
        chargeEffectFree(obj);
        break;
    case 0x2:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0x78) != NULL) {
            amSndStop((s32)*(void **)(priv + 0x78));
        }
        if (*(void **)(priv + 0x74) != NULL) {
            amSndStop((s32)*(void **)(priv + 0x74));
        }
        if (*(void **)(priv + 0x7C) != NULL) {
            amSndStop((s32)*(void **)(priv + 0x7C));
        }
        if (*(void **)(priv + 0x80) != NULL) {
            amSndStop((s32)*(void **)(priv + 0x80));
        }
        break;
    case 0x5A:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x2C) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x68) + 0x2C));
        }
        break;
    case 0x7C:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x10) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x68) + 0x10));
        }
        break;
    case 0x7:
        priv = *(u8 **)(o + 0x68);
        if (*(void **)(priv + 0x8) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0x8));
        }
        if (*(void **)(priv + 0xC) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0xC));
        }
        break;
    case 0x7D:
        if (*(void **)(*(u8 **)(o + 0x68) + 0x1C) != NULL) {
            amSndStop((s32)*(void **)(*(u8 **)(o + 0x68) + 0x1C));
        }
        break;
    }

    /* extra cleanup for the objects with unk48 == 1 */
    if (*(s16 *)(o + 0x48) == 1) {
        priv = *(u8 **)(o + 0x68);
        if (*(s32 *)(priv + 0xC4) != 0) {
            amSndStop(*(s32 *)(priv + 0xC4));
        }
        if (*(s32 *)(priv + 0xD0) != 0) {
            amSndStop(*(s32 *)(priv + 0xD0));
        }
        if (*(s32 *)(priv + 0xC8) != 0) {
            amSndStop(*(s32 *)(priv + 0xC8));
        }
        if (*(s32 *)(priv + 0xCC) != 0) {
            amSndStop(*(s32 *)(priv + 0xCC));
        }
        if (*(s32 *)(priv + 0xD4) != 0) {
            amSndStop(*(s32 *)(priv + 0xD4));
        }
        if (*(s32 *)(priv + 0xD8) != 0) {
            amSndStop(*(s32 *)(priv + 0xD8));
        }
        if (*(void **)(priv + 0xBC) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0xBC));
        }
        if (*(void **)(priv + 0xF0) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0xF0));
        }
        if (*(void **)(priv + 0xE8) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0xE8));
        }
        if (*(void **)(priv + 0xEC) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0xEC));
        }
        if (*(void **)(priv + 0xC0) != NULL) {
            amSndStop(*(s32 *)(priv + 0xC0));
        }
        if (*(s32 *)(priv + 0x5D4) != 0) {
            amSndStop(*(s32 *)(priv + 0x5D4));
        }
        if (*(s32 *)(priv + 0x5D0) != 0) {
            amSndStop(*(s32 *)(priv + 0x5D0));
        }
        if (*(s32 *)(priv + 0x5D8) != 0) {
            amSndStop(*(s32 *)(priv + 0x5D8));
        }
        if (*(s32 *)(priv + 0x5DC) != 0) {
            amSndStop(*(s32 *)(priv + 0x5DC));
        }
        if (*(void **)(priv + 0x5E0) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0x5E0));
        }
        if (*(void **)(priv + 0x5E4) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0x5E4));
        }
        if (*(void **)(priv + 0x5E8) != NULL) {
            amSndStopXYZ(*(void **)(priv + 0x5E8));
        }
        if (*(s32 *)(priv + 0x550) != 0) {
            cloneDelete(*(s32 *)(priv + 0x550));
        }
        if (*(void **)(priv + 0x554) != NULL) {
            camlightDelete(*(void **)(priv + 0x554));
        }
        if (*(void **)(priv + 0x558) != NULL) {
            killLight(*(void **)(priv + 0x558));
        }
        if (*(void **)(priv + 0x55C) != NULL) {
            objFreeObject(*(void **)(priv + 0x55C));
        }
        if (*(void **)(priv + 0x560) != NULL) {
            objFreeObject(*(void **)(priv + 0x560));
        }
        if (*(void **)(priv + 0x5BC) != NULL) {
            objFreeObject(*(void **)(priv + 0x5BC));
        }
        /* four fxFreeCone calls on consecutive words at +0x598 */
        for (k = 0; k < 4; k++) {
            if (*(s32 *)(priv + 0x598 + k * 4) != 0) {
                fxFreeCone(*(s32 *)(priv + 0x598 + k * 4));
            }
        }
        cnt = ObjListCount;
        for (i = 0; i < cnt; i++) {
            rec = (u8 *)ObjList[i];
            if (*(s16 *)(rec + 0x48) == 2) {
                tgt = *(u8 **)(rec + 0x68);
                if (obj == *(void **)(tgt + 0x24)) {
                    *(void **)(tgt + 0x24) = NULL;
                }
            }
        }
    }

    /* clone data at +0x50 */
    if (*(void **)(o + 0x50) != NULL) {
        if (*(s32 *)(*(u8 **)(o + 0x50) + 0x1C) != 0) {
            if (*(u8 *)(*(u8 **)(o + 0x40) + 0x61) & 0x8) {
                cloneBlobDelete(*(s32 *)(*(u8 **)(o + 0x50) + 0x1C));
            } else if (*(u8 *)(*(u8 **)(o + 0x40) + 0x61) & 0x10) {
                duckshootUpdate(*(s32 *)(*(u8 **)(o + 0x50) + 0x1C));
            }
        }
        if (*(void **)(*(u8 **)(o + 0x50) + 0x4) != NULL) {
            texFreeTexture(*(void **)(*(u8 **)(o + 0x50) + 0x4));
        }
    }
    if (*(s32 *)(o + 0x58) != 0) {
        wakeFreeRipple(*(s32 *)(o + 0x58));
    }
    if (*(void **)(o + 0x7C) != NULL) {
        if (*(void **)(*(u8 **)(o + 0x7C) + 0x18) != NULL) {
            amSndStopXYZ(*(void **)(*(u8 **)(o + 0x7C) + 0x18));
        }
    }
    if (*(u8 *)(o + 0xA2) != 0) {
        partNullifyCircularParticleParents(obj);
    }

    /* free the model / texture / sprite handle array at +0x6C, selected by objdef type */
    def = *(u8 **)(o + 0x40);
    cnt = *(s8 *)(def + 0x1F);
    if (*(s8 *)(def + 0x1E) == 0) {
        for (k = 0; k < cnt; k++) {
            if (*(void **)(*(u8 **)(o + 0x6C) + k * 4) != NULL) {
                modFreeModel(*(void **)(*(u8 **)(o + 0x6C) + k * 4));
            }
        }
    } else if (*(s8 *)(def + 0x1E) == 4) {
        for (k = 0; k < cnt; k++) {
            texFreeTexture(*(void **)(*(u8 **)(o + 0x6C) + k * 4));
        }
    } else {
        for (k = 0; k < cnt; k++) {
            texFreeSprite(*(void **)(*(u8 **)(o + 0x6C) + k * 4));
        }
    }
    objFreeObjdef(*(s16 *)(o + 0x2C));
    mmFree(obj);
    D_800A3348_A3F48 = 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80007EA0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80008F60(s32 arg0) {
    s32 i;

    if (D_800F391C > 0) {
        for (i = 0; i < D_800F391C; i++) {
            if (animplayerlist[i] == arg0) {
                animplayerlist[i] = animplayerlist[D_800F391C - 1];
            }
        }
        D_800F391C -= 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80008F60.s")
#endif

void objObjectsPauseTick(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-frame object pass (main loop, not the cut-camera variant): decays the D_800F2C90 timer,
// refreshes the render copy of each player, runs the hit list, the per-object pass (texture
// scroll, ripples, UV scroll, sprite anim), player control / shrinkbeam sound, the second
// object pass (behaviours 9 and 0x25), the light/cut-camera/audio tail, the deferred frees and
// the three 16-entry ring indices. Object offsets as in the asm (see objObjectsCutCameraTick).
void objObjectsTick(s32 arg0) {
    s32 i;
    s32 p;
    s32 k;
    s32 count;
    s32 hitCount;
    Object **hitModels;
    void *hitArg;
    s16 behavior;
    u8 *obj;
    u8 *player;
    u8 *pd;
    u8 *hdr;
    u8 *uv;
    u8 *tbl;
    u8 *aux;
    u8 *spr;
    u16 rate;
    u16 pos;
    u16 period;

    D_800F2C94_B1784 = D_800F2C90_B1780;
    if (D_800F2C90_B1780 > 0) {
        D_800F2C90_B1780 = D_800F2C90_B1780 - arg0;
    }
    if (D_800F2C90_B1780 < 0) {
        D_800F2C90_B1780 = 0;
    }

    /* asm: $a0 is not changed here, so it is dt when there are no players,
       otherwise the last player object the loop leaves behind (passed to hitUpdate). */
    hitArg = (void *)arg0;
    for (p = 0; p < D_800F3910; p++) {
        player = ((u8 **)playerlist)[p];
        hitArg = player;
        pd = *(u8 **)(player + 0x68);
        *(f32 *)(pd + 0x3C) = *(f32 *)(player + 0xC);
        *(f32 *)(pd + 0x40) = *(f32 *)(player + 0x10);
        *(f32 *)(pd + 0x44) = *(f32 *)(player + 0x14);
        *(s16 *)(pd + 0x122) = *(s16 *)(player + 0x0);
        *(s16 *)(pd + 0x124) = *(s16 *)(player + 0x2);
        *(s16 *)(pd + 0x126) = *(s16 *)(player + 0x4);
    }

    hitUpdate(hitArg);
    explosionHitTick(arg0);
    hitModels = hitGetHitModels(&hitCount);
    if (hitCount > 0) {
        for (k = 0; k < hitCount; k++) {
            /* asm: third argument is the hit model count, not an index */
            ((void (*)(void *, s32, s32))func_8000FB60)(hitModels[k], arg0, hitCount); /* sig mismatch */
        }
    }
    hitModelsTick();

    count = ObjListCount;
    for (i = D_800F38AC; i < count; i++) {
        obj = (u8 *)ObjList[i];
        behavior = *(s16 *)(obj + 0x48);
        switch (behavior) {
        case 0x1E:
        case 0x09:
        case 0x25:
            break;
        default:
            aux = *(u8 **)(obj + 0x4C);
            if (aux == NULL || !(aux[9] & 8)) {
                ((void (*)(void *, s32, s32))func_8000FB60)(obj, arg0, i); /* sig mismatch */
            }
            hdr = *(u8 **)(obj + 0x40);
            if (*(s8 *)(hdr + 0x1E) == 0 && hdr[0xA2] != 0xFF) {
                objScrollTexture(obj, arg0);
            }
            if (behavior != 1 && *(void **)(obj + 0x58) != NULL) {
                wakeUpdateRipple(obj, arg0);
            }
            /* UV scroll: u16 offset at +8 advances by rate * dt, wrapped by the period at tbl+0x12 */
            uv = *(u8 **)(obj + 0x50);
            if (uv != NULL) {
                rate = *(u16 *)(uv + 0xA);
                if (rate != 0) {
                    tbl = *(u8 **)(uv + 0x4);
                    if (tbl != NULL) {
                        pos = (u16)(*(u16 *)(uv + 0x8) + rate * arg0);
                        *(u16 *)(uv + 0x8) = pos;
                        period = *(u16 *)(tbl + 0x12);
                        if (pos >= period) {
                            do {
                                pos = (u16)(pos - period);
                                *(u16 *)(uv + 0x8) = pos;
                            } while (pos >= period);
                        }
                    }
                }
            }
            /* sprite list: 0x14-byte entries, count at obj+0x90 (re-read every pass) */
            spr = *(u8 **)(obj + 0x64);
            if (spr != NULL) {
                for (k = 0; k < *(u8 *)(obj + 0x90); k++) {
                    texAnimateSprite(*(s32 *)spr, (s32 *)(spr + 0xC), spr[0x5], spr + 0x10, arg0);
                    spr += 0x14;
                }
            }
            break;
        }
    }

    if (multiPlayerGame != 0 && multiGameType == 6) {
        /* asm: $a2 is not set here, so it still holds the object loop's final index */
        sprintUpdate(numberOfPlayers, arg0, i);
    } else {
        /* asm: $a2 is the leftover object index on the first pass and the player index after */
        for (p = 0; p < D_800F3910; p++) {
            controlPlayer(((u8 **)playerlist)[p], arg0, i);
            i = p + 1;
        }
        if ((multiPlayerGame != 0 && multiGameType == 4) || racingInGame != 0) {
            shrinkbeamSoundUpdate(arg0);
        }
    }

    for (i = D_800F38AC; i < count; i++) {
        obj = (u8 *)ObjList[i];
        behavior = *(s16 *)(obj + 0x48);
        if (behavior == 9 || behavior == 0x25) {
            ((void (*)(void *, s32, s32))func_8000FB60)(obj, arg0, i); /* sig mismatch */
        }
    }

    lightUpdateLights(arg0);
    lightUpdateObjects();
    if (runlinkIsModuleLoaded(0x1C) != 0) {
        /* asm: no arguments are set here; $a0 is still 0x1C from the runlinkIsModuleLoaded call, $a1 is undefined */
        cutcameraControl((void *)0x1C, 0);
    }
    func_80011E74_12A74();
    amPlayAudioMap(playerlist, D_800F3910, arg0);
    if (D_800F2C8C_B177C == 0) {
        objDoFrees();
    }
    D_800F2C8C_B177C = 1;
    obj_olddt = (f32)arg0;

    D_800F2EA0_B1990[D_800A0974_A1574] = -1;
    D_800A0974_A1574 = (D_800A0974_A1574 + 1) & 0xF;
    D_800F2F20_B1A10[D_800A097C_A157C] = -1;
    D_800A097C_A157C = (D_800A097C_A157C + 1) & 0xF;
    D_800F2EE0_B19D0[D_800A0978_A1578] = -1;
    D_800A0978_A1578 = (D_800A0978_A1578 + 1) & 0xF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objObjectsTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-frame cut-camera pass over ObjList: dispatches a few behaviour ids, draws the beam
// object (behaviour 0x80) if seen, then runs the audio map and deferred frees.
void objObjectsCutCameraTick(s32 arg0) {
    Object *beamObj = NULL;
    s32 count = ObjListCount;
    s32 i;

    if (D_800F38AC < count) {
        for (i = D_800F38AC; i < count; i++) {
            Object *obj = ObjList[i];

            switch (obj->behaviorId) {
                case 0x64:
                    blastdoorControl(obj, arg0);
                    break;
                case 0x43:
                    doorSwitchControl(obj, arg0);
                    break;
                case 0x80:
                    beamObj = obj;
                    break;
                case 0x81:
                    nightvisionpadControl(obj, arg0);
                    break;
            }
        }
    }
    if (beamObj != NULL) {
        beamDraw(beamObj, arg0);
    }
    amPlayAudioMap(playerlist, D_800F3910, arg0);
    if (D_800F2C8C_B177C == 0) {
        objDoFrees();
    }
    D_800F2C8C_B177C = 1;
    obj_olddt = (f32)arg0;
    D_800F6F54_B1794 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objObjectsCutCameraTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Steps the animated textures of a model: 8-byte entries at model+0x74 (flags word at +4,
// frame at +0/+2), texture headers from anim hdr +0x18, output u16 offsets written through
// model+0x78[model+0xB]. Entry layout and texture header fields as in the asm.
void objAnimTextures(void *arg0, void *arg1, void *arg2, s8 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *hdr = (u8 *)arg1;
    u8 *model = (u8 *)arg2;
    u8 *ent;
    s16 *out;
    s32 i;

    if (mainGetPauseMode() != 0) {
        arg3 = 0;
    }
    ent = *(u8 **)(model + 0x74);
    if (ent == NULL) {
        return;
    }
    out = *(s16 **)(model + 0x78 + (*(s8 *)(model + 0x0B) * 4));
    for (i = 0; i < hdr[0x2C]; i++) {
        s32 w4 = *(s32 *)(ent + 0x04);
        TextureHeader *tex = *(TextureHeader **)(*(u8 **)(hdr + 0x18) + ((w4 & 0xFF) * 8));
        s32 frame;

        if (w4 & 0x10000) {
            frame = *(s16 *)(ent + 0x00);
            if (w4 & 0x20000) {
                blinkMode = obj[0x9F];
            }
            texAnimateTexture(tex, (u32 *)(ent + 0x04), &frame, arg3);
            *(s16 *)(ent + 0x00) = (s16)frame;
            if (*(s16 *)(ent + 0x02) >= 0) {
                frame += 0x100;
                if (frame >= tex->numOfTextures) {
                    if (tex->unk18 != 0) {
                        frame = 0;
                    } else {
                        frame -= 0x100;
                    }
                }
                *(s16 *)(ent + 0x02) = (s16)frame;
            }
        }
        if (*(s16 *)(ent + 0x02) >= 0) {
            *out++ = (s16)((*(s16 *)(ent + 0x02) >> 8) * tex->textureSize);
        }
        *out++ = (s16)((*(s16 *)(ent + 0x00) >> 8) * tex->textureSize);
        ent += 8;
    }
    if (obj[0x9F] == 1) {
        obj[0x9F] = 2;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objAnimTextures.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Object and sub-struct fields are raw offsets: no existing struct covers
// Object +0x40 (sub-struct with s8 count at +0x1E/+0x1F) or Object +0x6C
// (pointer array of per-entry records with a u8 field at +0xA).
void objResetAnimModels(s32 arg0) {
    s32 i;
    s32 k;
    Object *obj;
    u8 *objSub;
    void *elem;

    i = D_800F38AC;
    while (i < ObjListCount) {
        obj = ObjList[i];
        i++;
        objSub = *(u8 **)((u8 *)obj + 0x40);
        if (*(s8 *)(objSub + 0x1E) == 0) {
            for (k = 0; k < *(s8 *)(*(u8 **)((u8 *)obj + 0x40) + 0x1F); k++) {
                elem = ((void **)*(void **)((u8 *)obj + 0x6C))[k];
                if (elem != NULL) {
                    *(u8 *)((u8 *)elem + 0xA) = arg0;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objResetAnimModels.s")
#endif

void objMoveXYZnocheck(void) {
    D_800A1208 = 1;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objMoveXYZ(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *track;
    u8 *block;
    f32 oldX, oldY, oldZ;
    f32 newX, newY, newZ;
    s32 outside;
    s32 iX, iY, iZ;
    s16 behaviorId;
    s16 blockId;

    track = trackGetTrack();
    oldX = *(f32 *)(obj + 0xC);
    oldY = *(f32 *)(obj + 0x10);
    oldZ = *(f32 *)(obj + 0x14);
    newX = oldX + arg1;
    newY = oldY + arg2;
    newZ = oldZ + arg3;
    if (track == NULL) {
        D_800A1208 = 0;
        return 0;
    }

    outside = 0;
    if ((f32)*(s16 *)(track + 0x22) + 1000.0f < newX) outside = 1;
    if (oldX < (f32)*(s16 *)(track + 0x20) - 1000.0f) outside = 1;
    if ((f32)*(s16 *)(track + 0x26) + 3000.0f < oldY) outside = 1;
    if (oldY < (f32)*(s16 *)(track + 0x24) - 1000.0f) outside = 1;
    if ((f32)*(s16 *)(track + 0x2A) + 1000.0f < oldZ) outside = 1;
    if (oldZ < (f32)*(s16 *)(track + 0x28) - 1000.0f) outside = 1;
    if (D_800A1208 != 0) outside = 0;
    D_800A1208 = 0;
    if (outside != 0) {
        behaviorId = *(s16 *)(obj + 0x48);
        if (behaviorId == 0x99 || behaviorId == 0x9B || behaviorId == 0x3D || behaviorId == 0x18 ||
            behaviorId == 0xAB || behaviorId == 0xAD || behaviorId == 0x97 || behaviorId == 0x86 ||
            behaviorId == 0x59 || behaviorId == 0xA6 || behaviorId == 0xA7) {
            objFreeObject(obj);
            return 1;
        }
        if (behaviorId == 1) {
            controlRestartPlayer(oldY, oldZ, obj, *(s32 *)(obj + 0x68));
        }
        *(s16 *)(obj + 0x2E) = -1;
        return 1;
    }

    *(f32 *)(obj + 0xC) = newX;
    *(f32 *)(obj + 0x10) = newY;
    *(f32 *)(obj + 0x14) = newZ;
    block = trackBlockDim(oldY, oldZ, *(s16 *)(obj + 0x2E));
    if (block == NULL) {
        *(s16 *)(obj + 0x2E) = trackGetBlock((f32)(s32)newX, (f32)(s32)newY, (f32)(s32)newZ);
        return 0;
    }
    iX = (s32)newX;
    iY = (s32)newY;
    iZ = (s32)newZ;
    outside = 0;
    if (*(s16 *)(block + 6) < iX || iX < *(s16 *)(block + 0)) outside = 1;
    if (*(s16 *)(block + 8) < iY || iY < *(s16 *)(block + 2)) outside = 1;
    if (*(s16 *)(block + 0xA) < iZ || iZ < *(s16 *)(block + 4)) outside = 1;
    if (outside != 0) {
        blockId = trackGetBlock((f32)iX, (f32)iY, (f32)iZ);
        if (blockId != -1) {
            *(s16 *)(obj + 0x2E) = blockId;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objMoveXYZ.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objPrintShardCluster(ObjectTransform *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *data;
    Gfx *g;

    data = *(u8 **)(obj + 0x68);
    arg0->x_position = 0.0f;
    arg0->y_position = 0.0f;
    arg0->z_position = 0.0f;
    camPushModelMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0, 1.0f, 0.0f);
    texDPInit(&D_800F2CC8_B17B8);
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = obj[0x39] | ~0xFF;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFB000000;
    g->words.w1 = -0x100U;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xBF000000;
    g->words.w1 = 0;
    if (*(u8 *)(data + 0x1C) != 0) {
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0x02000050;
        g->words.w1 = (u32)D_A0838;
    }
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0x06000000;
    g->words.w1 = *(u32 *)(data + 0xC) + 0x80000000U;
    camRestoreModelMtx(&D_800F2CC8_B17B8);
    texDPInit(&D_800F2CC8_B17B8);
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = -1U;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFB000000;
    g->words.w1 = -0x100U;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objPrintShardCluster.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objPrintSeveredLimb(ObjectTransform *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *data;
    Gfx *g;

    data = *(u8 **)(obj + 0x68);
    texDPInit(&D_800F2CC8_B17B8);
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = obj[0x39] | ~0xFF;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFB000000;
    g->words.w1 = -0x100U;
    camPushModelMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0, 1.0f, 0.0f);
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xBF000000;
    g->words.w1 = 0;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0x02000050;
    g->words.w1 = (u32)D_A0838;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0x06000000;
    if (obj[0x39] == 0xFF) {
        g->words.w1 = *(u32 *)(data + 0xC) + 0x80000000U;
    } else {
        g->words.w1 = *(u32 *)(data + 0x10) + 0x80000000U;
    }
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xBF000000;
    g->words.w1 = 0;
    camRestoreModelMtx(&D_800F2CC8_B17B8);
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = -1U;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFB000000;
    g->words.w1 = -0x100U;
    texDPInit(&D_800F2CC8_B17B8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objPrintSeveredLimb.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDrawSimpleObject(ObjectTransform *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, s32 arg9, s32 arg10) {
    s32 hasAlpha = 0;
    u32 addr;
    s32 tint;
    Gfx *g;

    camPushModelMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0, arg8, 0.0f);
    if (!(arg6 & 0x240)) {
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0xFA000000;
        tint = arg9 & 0xFF;
        g->words.w1 = (tint << 0x18) | (tint << 0x10) | (tint << 8) | (arg10 & 0xFF);
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0xFB000000;
        g->words.w1 = -0x100U;
    }
    if (arg5 != 0) {
        hasAlpha = 1;
    }
    if (arg10 < 0xFF) {
        arg6 |= 4;
    }
    texDPTextureX(&D_800F2CC8_B17B8, arg5, arg6, arg7);
    addr = (u32)arg1 + 0x80000000U;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = ((((arg2 * 8) | (addr & 6)) & 0xFF) << 0x10) | 0x04000000 | (((arg2 * 0xA) + 8) & 0xFFFF);
    g->words.w1 = addr;
    g = D_800F2CC8_B17B8++;
    g->words.w0 = (((((arg4 - 1) * 0x10) | hasAlpha) & 0xFF) << 0x10) | 0x05000000 | ((arg4 * 0x10) & 0xFFFF);
    g->words.w1 = (u32)arg3 + 0x80000000U;
    camPopModelMtx(&D_800F2CC8_B17B8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDrawSimpleObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDrawTracer(Gfx **arg0, void **arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5, f32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    f32 spA4, spA0, sp9C, sp98, sp94, sp90;
    f32 sp8C, sp88, sp84, sp80;
    f32 sp78, sp74;
    f32 (*rot)[4];
    f32 dx, dy, lenSq, scale, t;
    Gfx *dl;
    Gfx *g;
    u8 *vtx;
    u32 vtxAddr;
    s32 i;

    if (((arg4[0] != arg5[0]) || (arg4[1] != arg5[1]) || (arg4[2] != arg5[2])) &&
        ((rot = camGetRotationMtx(),
          mathMtxXFMF(rot, arg5[0], arg5[1], arg5[2], &spA4, &spA0, &sp9C),
          mathMtxXFMF(rot, arg4[0], arg4[1], arg4[2], &sp98, &sp94, &sp90),
          !(sp9C > -10.0f)) || !(sp90 > -10.0f))) {
        if (sp9C > -10.0f) {
            t = (-10.0f - sp9C) / (sp90 - sp9C);
            sp9C = -10.0f;
            spA4 += (sp98 - spA4) * t;
            spA0 += (sp94 - spA0) * t;
        } else if (sp90 > -10.0f) {
            t = (-10.0f - sp90) / (sp9C - sp90);
            sp90 = -10.0f;
            sp98 += (spA4 - sp98) * t;
            sp94 += (spA0 - sp94) * t;
        }
        dl = *arg0;
        vtx = (u8 *)*arg1;
        if (camProjectPoint(spA4, spA0, sp9C, &sp8C, &sp88, 0) != 0) {
            if (camProjectPoint(sp98, sp94, sp90, &sp84, &sp80, 0) != 0) {
                dx = sp84 - sp8C;
                dy = sp80 - sp88;
                lenSq = (dx * dx) + (dy * dy);
                if (lenSq > 0.0f) {
                    scale = arg6 / sqrtf(lenSq);
                    dx *= scale;
                    dy *= scale;
                }
                sp78 = dx;
                sp74 = dy;

                g = dl++;
                g->words.w0 = 0x01010040;
                g->words.w1 = (u32)camGetProjOrgMtx() + 0x80000000U;
                texDPTextureX(&dl, arg2, arg9 | 6, 0);
                g = dl++;
                g->words.w0 = 0xFA000000;
                g->words.w1 = arg7;
                g = dl++;
                g->words.w0 = 0xFB000000;
                g->words.w1 = arg8;
                vtxAddr = (u32)vtx + 0x80000000U;
                g = dl++;
                g->words.w0 = ((((vtxAddr & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30;
                g->words.w1 = vtxAddr;
                g = dl++;
                g->words.w0 = 0x05110020;
                g->words.w1 = (u32)arg3 + 0x80000000U;
                g = dl++;
                g->words.w0 = 0xE7000000;
                g->words.w1 = 0;
                g = dl++;
                g->words.w0 = 0xFA000000;
                g->words.w1 = -1;
                g = dl++;
                g->words.w0 = 0xFB000000;
                g->words.w1 = -1;
                g = dl++;
                g->words.w0 = 0xBC00000A;
                g->words.w1 = 0;

                mathMtxXFMF(rot, arg5[0], arg5[1], arg5[2], &spA4, &spA0, &sp9C);
                mathMtxXFMF(rot, arg4[0], arg4[1], arg4[2], &sp98, &sp94, &sp90);
                vtx += 0x28;
                *(s16 *)(vtx - 0x28) = (s16)(spA4 + sp74);
                *(s16 *)(vtx - 0x26) = (s16)(spA0 + sp78);
                *(s16 *)(vtx - 0x24) = (s16)sp9C;
                *(s16 *)(vtx - 0x1E) = (s16)(spA4 - sp74);
                *(s16 *)(vtx - 0x1C) = (s16)(spA0 - sp78);
                *(s16 *)(vtx - 0x1A) = (s16)sp9C;
                *(s16 *)(vtx - 0x14) = (s16)(sp98 + sp74);
                *(s16 *)(vtx - 0x12) = (s16)(sp94 + sp78);
                *(s16 *)(vtx - 0x10) = (s16)sp90;
                *(s16 *)(vtx - 0x0A) = (s16)(sp98 - sp74);
                *(s16 *)(vtx - 0x08) = (s16)(sp94 - sp78);
                *(s16 *)(vtx - 0x06) = (s16)sp90;
                for (i = 0; i < 4; i++) {
                    vtx[-0x22 + i] = 0xFF;
                    vtx[-0x18 + i] = 0xFF;
                    vtx[-0x0E + i] = 0xFF;
                    vtx[-0x04 + i] = 0xFF;
                }
            }
        }
        *arg0 = dl;
        *arg1 = vtx;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDrawTracer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000A9C0(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *data = *(u8 **)(obj + 0x68);

    fxDrawLine3D(*(f32 *)(data + 4), *(f32 *)(data + 8), *(s32 *)(data + 0xC),
                 *(s32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 0x13);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000A9C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objPrintCustomObject(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s16 id = *(s16 *)(obj + 0x48);
    u8 *data = *(u8 **)(obj + 0x68);
    u8 *anim = *(u8 **)(obj + 0x40);
    void **parts = *(void ***)(obj + 0x6C);
    s32 off;
    u8 *s;
    u8 *vt;
    u8 *vs;
    s32 i;
    u32 addr;
    Gfx *g;

    switch (id) {
    case 0x44:
        SquaddieLightAndAnimate(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0);
        break;
    case 0xA2:
        if (data[0x63] != 0) {
            off = *(s32 *)(obj + 0x4C) + 0xC;
        } else {
            off = *(s32 *)(obj + 0x4C) + 0x18;
        }
        objDrawTracer(&D_800F2CC8_B17B8, &D_800F2CD0_B17C0, parts[*(s8 *)(obj + 0x3A)], data, obj + 0xC, (void *)off,
                      *(f32 *)(data + 0x6C), -1, *(s32 *)(obj + 0x8C) | 0xFF, 0x200);
        break;
    case 0x9D:
        func_8000A9C0(arg0);
        break;
    case 0x3F:
        func_8000C028(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0);
        break;
    case 0x98:
        s = data;
        vt = s + 0x600;
        if (*(s16 *)(s + 0xA78) != 0) {
            s32 c;
            camPushModelMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, (ObjectTransform *)arg0, 1.0f, 0.0f);
            texDPTextureX(&D_800F2CC8_B17B8, *(s32 *)(*(u8 **)(anim + 0xAC)), 0x206, 0);
            g = D_800F2CC8_B17B8++;
            g->words.w1 = -0x40U;
            g->words.w0 = 0xFA000000;
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xFB000000;
            g->words.w1 = *(u32 *)(D_800A0A10_A1610 + (s[0xA83] * 8));
            vs = s;
            for (i = 0; i != 3; i++) {
                u8 *nt = vt + 0xB4;
                u8 *ns = vs + 0x100;

                addr = (u32)vt + 0x80000000U;
                g = D_800F2CC8_B17B8++;
                g->words.w0 = (((((s32)addr & 6) | 0x90) & 0xFF) << 0x10) | 0x04000000 | 0xBC;
                g->words.w1 = addr;
                g = D_800F2CC8_B17B8++;
                g->words.w1 = (u32)vs + 0x80000000U;
                g->words.w0 = 0x05F10100;
                addr = (u32)nt + 0x80000000U;
                g = D_800F2CC8_B17B8++;
                g->words.w0 = (((((s32)addr & 6) | 0x90) & 0xFF) << 0x10) | 0x04000000 | 0xBC;
                g->words.w1 = addr;
                g = D_800F2CC8_B17B8++;
                g->words.w1 = (u32)ns + 0x80000000U;
                g->words.w0 = 0x05F10100;
                vt = nt + 0xB4;
                vs = ns + 0x100;
                if (i == 0) {
                    g = D_800F2CC8_B17B8++;
                    g->words.w1 = 0;
                    g->words.w0 = 0xE7000000;
                    g = D_800F2CC8_B17B8++;
                    g->words.w0 = 0xFB000000;
                    g->words.w1 = *(u32 *)(D_800A0A10_A1610 + (s[0xA83] * 8) + 4);
                }
            }
            c = 0;
            (void)c;
            camPopModelMtx(&D_800F2CC8_B17B8);
            if (s[0xA7F] != 0) {
                g = D_800F2CC8_B17B8++;
                g->words.w1 = 0;
                g->words.w0 = 0xE7000000;
                g = D_800F2CC8_B17B8++;
                g->words.w0 = 0xFA000000;
                g->words.w1 = -0x40U;
                camDoSpriteDirect(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, *(s32 *)(anim + 0xAC), (s32)*(f32 *)(obj + 0xC),
                                  (s32)*(f32 *)(obj + 0x10), (s32)*(f32 *)(obj + 0x14), (s32)*(s16 *)(s + 0xA76), *(f32 *)(s + 0xA54), 0.0f, 6, 0xC0);
            }
            texDPInit(&D_800F2CC8_B17B8);
        }
        break;
    case 0x25:
        if (data[0x23] == 0) {
            u8 *tgt = *(u8 **)data;
            if (*(u8 *)(tgt + 0xA0) != 0) {
                objFreeObject(arg0);
            } else {
                s32 a;
                s32 b;
                s32 cz;
                s32 d;
                s32 e;
                s32 f;
                u8 *p;
                s32 n;

                if (*(s16 *)(tgt + 0x48) == 0x18) {
                    GetVtxPosition(tgt);
                }
                n = 4;
                p = data + 8;
                do {
                    if (GetVtxPosition(*(void **)data, *(s16 *)(p + 0x10), &a, &b, &cz) != 0 &&
                        FatBobDrawShockWave(*(void **)data, *(s16 *)(p + 0x12), &d, &e, &f) != 0) {
                        objDrawTracer(&D_800F2CC8_B17B8, &D_800F2CD0_B17C0, (void *)*(s32 *)(*(u8 **)(anim + 0xAC)), &D_800A09A8_A15A8, &a, &d,
                                      8.0f, -1, *(s32 *)(obj + 0x8C) | 0xFF, 0x200);
                    }
                    p -= 2;
                    n -= 1;
                } while (n != 0);
            }
        }
        break;
    case 0x24:
        objPrintShardCluster(arg0);
        break;
    case 0x40:
        objPrintSeveredLimb(arg0);
        break;
    case 0x16:
        if (data[0xFD] == 5) {
            *(f32 *)(obj + 8) = *(f32 *)anim * *(f32 *)(data + 0x10C);
            objDrawSimpleObject(arg0, data + (data[0xFC] * 0x1E * 2) + 0x80, 6, data, 8, *(void **)(data + 0xF8), 0xA, 0, 1.0f,
                                (s32)(*(u32 *)(data + 0x110) * 0xFF) >> 8, (s32)(*(u32 *)(data + 0x114) * 0xFF) >> 8);
        } else {
            objDrawSimpleObject(arg0, data + (data[0xFC] * 0x1E * 2) + 0x80, 6, data, 8, *(void **)(data + 0xF8), 0xA, 0, 1.0f, 0xFF, 0xFF);
        }
        break;
    case 0x28:
        objDrawShockWave(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0);
        break;
    case 0x29:
        objDrawInvincibilityShield(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0);
        break;
    case 0x52:
        teleportEffectDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0x58:
        lightShowDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0x7F:
        mantisboltDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0xAA:
        mizarEyeBeamDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0);
        break;
    case 0xAD:
        mizarElectroDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0xAE:
        mizarImpactDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0x8B:
        mizarRockStormDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0x97:
        mizarFireBallDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0xAB:
        mizarDeathDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0x92:
        twisterDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        break;
    case 0x7B:
        if (*(s16 *)(obj + 0x4A) == 0x1FB) {
            objDrawSimpleObject(arg0, D_800A09C8_A15C8, 4, D_800A09F0_A15F0, 2, parts[0], 4, 0, 1.0f, 0, obj[0x39]);
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objPrintCustomObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDrawDoor(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *data = *(u8 **)(obj + 0x68);
    u8 type = data[0x42];
    f32 cosv;
    f32 sinv;
    f32 offZ;

    if (type == 3) {
        if (*(s16 *)(data + 0x34) == 0) {
            obj[0x3A] = 0;
            objPrintModelObject(arg0);
            return;
        }
        cosv = Cosf((s32)-*(s16 *)obj) * (f32)*(s16 *)(data + 0x34);
        sinv = Sinf(-*(s16 *)obj);
        obj[0x3A] = 1;
        *(f32 *)(obj + 0xC) -= cosv;
        offZ = sinv * (f32)*(s16 *)(data + 0x34);
        *(f32 *)(obj + 0x14) -= offZ;
        objPrintModelObject(arg0);
        obj[0x3A] = 2;
        *(f32 *)(obj + 0xC) += 2.0f * cosv;
        *(f32 *)(obj + 0x14) += 2.0f * offZ;
        objPrintModelObject(arg0);
        obj[0x3A] = 0;
        *(f32 *)(obj + 0xC) -= cosv;
        *(f32 *)(obj + 0x14) -= offZ;
        return;
    }
    if (type == 5) {
        D_800F2E98_B1988 = *(f32 *)(data + 4);
        objPrintModelObject(arg0);
        D_800F2E98_B1988 = 1.0f;
        return;
    }
    objPrintModelObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDrawDoor.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000B3DC(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s16 id = *(s16 *)(obj + 0x48);
    u8 *data = *(u8 **)(obj + 0x68);
    u8 *cobj = *(u8 **)(obj + 0x54);
    u8 *model;
    u8 *m3c;
    u8 *cyc;
    u8 *c1;
    u8 *c2;
    s32 flags;
    s32 alpha = 0xFF;
    s32 alphaOn = 0;
    s32 colourOn = 0;
    s32 objAlpha;
    s32 override = 0;
    s32 chain = 0;
    s16 fogA;
    s16 fogB;
    s16 fogC;
    s16 fogD;
    u8 fr;
    u8 fg;
    u8 fb;
    Gfx *g;

    if (id == 0xA3) {
        WaterBossDrawSprites(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        return;
    }

    flags = *(s16 *)(obj + 6) | 8;
    if (*(f32 *)(obj + 8) < 0.0f) {
        flags |= 0x20000000;
        *(f32 *)(obj + 8) = -*(f32 *)(obj + 8);
    }
    if (cobj != NULL) {
        alpha = (s32)(*(f32 *)cobj * 255.0f);
        alphaOn = 1;
        colourOn = 1;
    }
    objAlpha = obj[0x39];
    if (objAlpha >= 0x100) {
        objAlpha = 0xFF;
    }
    if (objAlpha < 0xFF) {
        flags |= 4;
        alphaOn = 1;
    }
    model = ((u8 **)*(u8 ***)(obj + 0x6C))[*(s8 *)(obj + 0x3A)];

    if (id == 0x18 && runlinkIsModuleLoaded(2) != 0 && refractThisObject == 0) {
        if (*(u16 *)(data + 0xA4) != 0) {
            trackGetFog(0, &fogA, &fogB, &fogC, &fr, &fg, &fb, &fogD);
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xF8000000;
            g->words.w1 = 0xFF3232FF;
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xBC000008;
            g->words.w1 = 0x05000500;
            WaterBossDrawSprites(arg0, &D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, model, flags, objAlpha, 1);
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xF8000000;
            g->words.w1 = (fr << 0x18) | (fg << 0x10) | (fb << 8) | 0xFF;
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xBC000008;
            g->words.w1 = ((0x1F400 / (fogB - fogA)) << 0x10) | ((((fogA * -0x100) + 0x1F400) / (fogB - fogA)) & 0xFFFF);
            *(u16 *)(data + 0xA4) = 0;
        }
    } else if (id != 0x18 || runlinkIsModuleLoaded(2) != 0) {
        chain = 1;
    }

    if (chain) {
        if (id == 0x91) {
            sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, data[1], data[2], data[3]);
            override = 1;
        } else if (id == 0x86) {
            sprSetIA2ColOverride(0xE0, 0xFF, 0xFF, 0x10, 0xA0, 0x40);
            override = 1;
        } else if (id == 0x3D) {
            switch (*(s32 *)(obj + 0x88)) {
            case 1:
                sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, 0x80, 0x00, 0xCC);
                break;
            case 2:
                sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, 0xD0, 0x00, 0x00);
                break;
            default:
                sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, 0x00, 0x28, 0xFF);
                break;
            }
            override = 1;
        } else if (id == 0x26 && (*(s16 *)(model + 6) & 0x200)) {
            sprSetIA2ColOverride(data[0x28], data[0x29], data[0x2A], data[0x18], data[0x19], data[0x1A]);
            override = 1;
        } else if (id == 0x39 && (m3c = *(u8 **)(obj + 0x3C)) != NULL && (m3c[0xD] & 0x80)) {
            cyc = (u8 *)levelGetColourCycling(0xE0);
            c1 = cyc + ((m3c[0xD] & 7) * 0x10);
            c2 = cyc + (((m3c[0xD] >> 3) & 7) * 0x10);
            sprSetIA2ColOverride(c1[8], c1[9], c1[10], c2[8], c2[9], c2[10]);
            override = 1;
        } else if (id == 0x3A) {
            if (*(s16 *)(obj + 0x4A) == 0x32B) {
                sprSetIA2ColOverride(0xFF, 0xFF, 0x00, 0xE5, 0x00, 0x00);
            } else {
                sprSetIA2ColOverride(0x28, 0xFF, 0x3C, 0x05, 0x46, 0x0B);
            }
            override = 1;
        } else {
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xFA000000;
            if (alphaOn != 0 || objAlpha < 0xFF) {
                g->words.w1 = (alpha << 0x18) | (alpha << 0x10) | (alpha << 8) | (objAlpha & 0xFF);
            } else {
                g->words.w1 = 0xFFFFFFFF;
            }
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xFB000000;
            if (colourOn != 0) {
                g->words.w1 = (cobj[4] << 0x18) | (cobj[5] << 0x10) | (cobj[6] << 8) | cobj[7];
            } else {
                g->words.w1 = 0xFFFFFF00;
            }
        }

        camDoSprite(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0, model, flags, objAlpha);
        if (id == 0x18 && *(s16 *)(*(u8 **)(*(u8 **)(data + 0x24) + 0x68) + 0x2C) == 0xE6) {
            animseqMuzzleFlash(arg0, &D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, model, flags, objAlpha, 0);
        }
        if (override != 0) {
            sprClearIA2ColOverride();
        }
        if (alphaOn != 0) {
            g = D_800F2CC8_B17B8++;
            g->words.w1 = 0xFFFFFFFF;
            g->words.w0 = 0xFA000000;
        }
        if (colourOn != 0) {
            g = D_800F2CC8_B17B8++;
            g->words.w1 = 0xFFFFFF00;
            g->words.w0 = 0xFB000000;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000B3DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objMakeGunMtx(void *arg0, void *arg1, void *arg2, s32 arg3, f32 (*arg4)[4], f32 *arg5, f32 *arg6, f32 *arg7) {
    u8 *obj = (u8 *)arg0;
    u8 *player = *(u8 **)(obj + 0x68);
    u8 *model = (u8 *)arg1;
    u8 *cam;
    u8 *camModel;
    u8 *part;
    u8 *pos;
    f32 *src;
    s16 *entry;
    s16 key;
    s32 result = 0;
    s32 i;

    if (*(s16 *)(obj + 0x48) == 1) {
        if (player[0x1FA] != 0 && controlPlayerOpeningChest(player) < 2) {
            arg3 = 0;
        } else if (arg3 >= 9 || *(s8 *)(player + 0x53C) > 0) {
            arg3 = 8;
        }
    }

    cam = *(u8 **)(obj + 0x60);
    if (cam != NULL) {
        camModel = *(u8 **)(cam + 4);
        if (camModel != NULL) {
            src = (f32 *)(*(u32 *)(model + (*(s8 *)(model + 0xB) * 4) + 0x10) +
                          ((*(u16 *)(*(u8 **)((u8 *)arg2 + 0x30) + 2)) << 6));
            for (i = 0; i < 15; i++) {
                ((f32 *)arg4)[i] = src[i];
            }
            arg4[0][3] = 0.0f;
            arg4[1][3] = 0.0f;
            arg4[2][3] = 0.0f;
            arg4[3][3] = 1.0f;
            if (*(s16 *)(obj + 0x48) == 0x33 && *(u8 **)((u8 *)arg2 + 0x30) != NULL &&
                D_800A0BD8_A17D8[0] != -1) {
                entry = D_800A0BD8_A17D8;
                key = *entry;
                for (;;) {
                    if (*(s16 *)(obj + 0x4A) == key) {
                        pos = *(u8 **)(model + 0x68);
                        arg4[3][0] = *(f32 *)(pos + 0);
                        arg4[3][1] = *(f32 *)(pos + 4);
                        arg4[3][2] = *(f32 *)(pos + 8);
                        break;
                    }
                    entry++;
                    key = *entry;
                    if (key == -1) {
                        break;
                    }
                }
            }
            part = *(u8 **)(*(u8 **)(camModel + 0x6C) + (arg3 * 4));
            if (part != NULL) {
                pos = *(u8 **)(part + 0x68);
                if (pos != NULL) {
                    mathMtxXFMF(arg4, *(f32 *)(pos + 0), *(f32 *)(pos + 4), *(f32 *)(pos + 8), arg5, arg6, arg7);
                    result = 1;
                }
            }
        }
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objMakeGunMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000BDCC(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *player;
    u8 *cam;
    u8 *model;
    u8 *part;
    u8 *hdr;
    u32 texA;
    u32 texB;
    Gfx *g;
    s32 idx = arg3;

    if (D_800A0A20_A1620 == 0) {
        player = *(u8 **)(obj + 0x68);
        if (*(s16 *)(obj + 0x48) == 1) {
            if (player[0x1FA] != 0 && controlPlayerOpeningChest(player) < 2) {
                idx = 0;
            } else if (!(arg3 < 9) || *(s8 *)(player + 0x53C) > 0) {
                idx = 8;
            }
        }
        cam = *(u8 **)(obj + 0x60);
        if (cam != NULL) {
            model = *(u8 **)(cam + 4);
            if (model != NULL) {
                part = *(u8 **)(*(u8 **)(model + 0x6C) + (idx * 4));
                if (part != NULL) {
                    if (*(s8 *)(part + 0xA) != 0) {
                        lightObject(model, part, *(s32 *)(obj + 0x54), arg4);
                        hdr = *(u8 **)part;
                        if (hdr[0x11] != 0) {
                            objAnimTextures(model, hdr, part, (s8)*(s8 *)(part + 0xA));
                        }
                        *(s8 *)(part + 0xA) = 0;
                    }
                    hdr = *(u8 **)part;
                    if (obj[0x39] < 0xFF) {
                        texB = *(u32 *)(hdr + 0x78);
                    } else {
                        texB = *(u32 *)(hdr + 0x74);
                    }
                    if (hdr[0x11] != 0) {
                        texA = *(u32 *)(part + (*(s8 *)(part + 0xB) * 4) + 0x78);
                    } else {
                        texA = (u32)NullTextureOffsets;
                    }
                    camPushFloatModelMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, (void *)arg4);
                    g = D_800F2CC8_B17B8++;
                    g->words.w0 = ((*(u32 *)(part + (*(s8 *)(part + 0xB) * 4) + 0x10) + 0x80000000U) & 0xFFFFFF) | 0xBF000000;
                    g->words.w1 = *(u32 *)(part + 4) + 0x80000000U;
                    g = D_800F2CC8_B17B8++;
                    g->words.w0 = 0x02000050;
                    g->words.w1 = texA + 0x80000000U;
                    g = D_800F2CC8_B17B8++;
                    g->words.w0 = 0x06000000;
                    g->words.w1 = texB + 0x80000000U;
                    g = D_800F2CC8_B17B8++;
                    g->words.w0 = 0xBF000000;
                    g->words.w1 = 0;
                    camRestoreModelMtx(&D_800F2CC8_B17B8);
                    texDPInit(&D_800F2CC8_B17B8);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000BDCC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000C028(Gfx **arg0, MatrixS **arg1, void *arg2) {
    u8 *obj = (u8 *)arg2;
    u8 *anim = *(u8 **)(obj + 0x88);
    u8 *model = *(u8 **)(obj + 0x68);
    Gfx *dl = *arg0;
    MatrixS *mtx = *arg1;
    s16 id = *(s16 *)(anim + 0x48);
    u8 *player = NULL;
    u8 *tbl = NULL;
    u8 *part;
    u8 *hdr;
    u8 *ent;
    u8 *pos;
    u8 *fo;
    u8 alphaArr[3];
    f32 scaleArr[3];
    s16 rot[3];
    f32 scale;
    s32 draw = 0;
    s32 kind = 0;
    s32 count = 0;
    s32 chr;
    s32 i;
    s32 n;
    MatrixS tm;
    MatrixS tm2;
    Gfx *g;

    for (i = 0; i < 3; i++) {
        alphaArr[i] = 0xFF;
        scaleArr[i] = 1.0f;
    }

    if (id == 1) {
        if (*(u8 **)(anim + 0x60) != NULL) {
            player = *(u8 **)(anim + 0x68);
            if ((*(s8 *)(player + 1) & 3) != 3) {
                chr = *(u8 *)((u8 *)mainGetGameCharacter(player[0], *(s8 *)(player + 1)) + 0x70);
                if (player[0x1FA] != 0) {
                    chr = 0;
                }
                draw = (*(u32 *)(player + 0x540) & 0x02000000) != 0;
                if (draw != 0) {
                    draw = *(s32 *)(*(u8 **)(anim + 0x60) + 4) != 0;
                    if (draw != 0) {
                        draw = (chr == 2 || chr == 0 || chr == 4 || chr == 7);
                    }
                }
                kind = chr;
                if (draw != 0) {
                    camPushFloatModelMtx(&dl, &mtx, player + 0x78);
                    rot[0] = *(s16 *)((u8 *)D_800A0C2C_A182C + (*(s8 *)(player + 1) * 6));
                    rot[1] = *(s16 *)((u8 *)D_800A0C2C_A182C + (*(s8 *)(player + 1) * 6) + 2);
                    rot[2] = *(s16 *)((u8 *)D_800A0C2C_A182C + (*(s8 *)(player + 1) * 6) + 4);
                    mathRpyXyzMtx(tm, rot);
                    camPushMuzzleMtx(&dl, &mtx, player + 0x544, tm);
                }
            }
        }
    } else if (id == 0x33) {
        if (*(s32 *)(obj + 0x8C) != 0) {
            chargeEffectDraw(&dl, &mtx, anim);
            kind = model[1];
            draw = 1;
            objFreeObject(arg2);
        }
    } else if (id == 0x18 || *(s32 *)(obj + 0x8C) != 0) {
        if (id == 0x18) {
            fo = *(u8 **)(*(u8 **)(*(u8 **)(anim + 0x68) + 0x24) + 0x68);
            scale = 100.0f / (f32)fo[2];
        } else {
            scale = 1.0f;
        }
        part = ((u8 **)*(u8 ***)(anim + 0x6C))[*(s8 *)(obj + 0x3A)];
        hdr = *(u8 **)part;
        if (model[0] < hdr[0x2D] && *(s8 *)(part + 0xA) == 0) {
            ent = *(u8 **)(hdr + 0x30) + (model[0] * 4);
            pos = (u8 *)(*(u16 *)(ent + 2) << 6) + *(s32 *)(part + (*(s8 *)(part + 0xB) * 4) + 0x10);
            *(f32 *)(pos + 0xC) = 0.0f;
            *(f32 *)(pos + 0x1C) = 0.0f;
            *(f32 *)(pos + 0x2C) = 0.0f;
            *(f32 *)(pos + 0x3C) = 1.0f;
            camPushFloatModelMtx(&dl, &mtx, pos);
            rot[0] = 0;
            rot[1] = 0x4000;
            rot[2] = 0;
            mathRpyXyzMtx(tm, rot);
            mathScaleMtx(tm2, scale, scale, scale);
            mathMtxCatF(tm, tm2, tm);
            camPushMuzzleMtx(&dl, &mtx, *(u8 **)(part + 0x68) + (model[0] * 0xC), tm);
            draw = 1;
            kind = model[1];
            alphaArr[0] = 0xFF;
        }
        if (*(s32 *)(obj + 0x8C) != 0) {
            objFreeObject(arg2);
        }
    }

    if (draw != 0) {
        switch (kind) {
        case 2:
            count = 2;
            tbl = D_800A0BEC_A17EC;
            break;
        case 0:
            count = 1;
            tbl = D_800A0C0C_A180C;
            break;
        case 4:
            count = 1;
            tbl = D_800A0C1C_A181C;
            {
                u8 *q = *(u8 **)(*(u8 **)(player + 0x560) + 0x68);
                scaleArr[0] = *(f32 *)(q + 0xA58) + *(f32 *)(q + 0xA5C);
                alphaArr[0] = q[0xA81];
            }
            break;
        case 7:
            count = 2;
            tbl = D_800A0BEC_A17EC;
            break;
        default:
            break;
        }
        for (n = 0; n < count; n++) {
            u8 *e = tbl + (n * 0x10);
            camScaleModelMtx(&dl, &mtx, scaleArr[n] * *(f32 *)(e + 8));
            g = D_800F2CC8_B17B8++;
            g->words.w1 = 0;
            g->words.w0 = 0xE7000000;
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xFA000000;
            g->words.w1 = alphaArr[n] | ~0xFF;
            texDPTextureX(&dl, (s32)((void **)*(void ***)(obj + 0x6C))[e[0xE]], 0x16, 0);
            g = D_800F2CC8_B17B8++;
            g->words.w0 = (((e[0xC] * 0xA) + 8) & 0xFFFF) | 0x04000000 | ((((e[0xC] * 8) | (((*(u32 *)e + 0x80000000U)) & 6)) & 0xFF) << 0x10);
            g->words.w1 = *(u32 *)e + 0x80000000U;
            g = D_800F2CC8_B17B8++;
            g->words.w0 = ((e[0xD] * 0x10) & 0xFFFF) | 0x05000000 | ((((e[0xD] - 1) * 0x10) | 1) & 0xFF) << 0x10;
            g->words.w1 = *(u32 *)(e + 4) + 0x80000000U;
        }
        camRestoreModelMtx(&dl);
        *arg0 = dl;
        *arg1 = mtx;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000C028.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDrawPlayerEffects(void **arg0, s32 arg1, void *arg2) {
    u8 *obj = (u8 *)arg2;
    u8 *model = (u8 *)((void **)*(void ***)(obj + 0x6C))[0];
    s16 order[4];
    f32 depth[4];
    u32 bases[4];
    void *parts[4];
    s16 kinds[4];
    s32 cnt = 0;
    s32 i;
    s32 j;
    s32 pass;
    s32 tmp;
    Gfx *g;

    for (i = 0; i < 4; i++) {
        if (obj[0x5AC + i] != 0) {
            void *part = *(void **)(obj + 0x598 + (i * 4));
            if (part != NULL) {
                u8 *vp;
                order[cnt] = cnt;
                vp = *(u8 **)(model + 0x68) + ((s8)obj[0x5B0 + i] * 0xC);
                depth[cnt] = camGetProjZ(*(f32 *)vp, *(f32 *)(vp + 4), *(f32 *)(vp + 8));
                parts[cnt] = part;
                bases[cnt] = (u32)(((s8)obj[0x5B4 + i] << 6) + *(u32 *)(model + (*(s8 *)(model + 0xB) * 4) + 0x10));
                kinds[cnt] = obj[0x5AC + i];
                cnt++;
            }
        }
    }

    if (cnt > 0) {
        /* bubble sort indices by depth */
        for (pass = cnt - 1; pass > 0; pass--) {
            for (j = 0; j < pass; j++) {
                if (depth[order[j + 1]] < depth[order[j]]) {
                    tmp = order[j];
                    order[j] = order[j + 1];
                    order[j + 1] = tmp;
                }
            }
        }

        for (i = 0; i < cnt; i++) {
            g = (Gfx *)*arg0;
            *arg0 = g + 1;
            g->words.w0 = 0x01810040;
            g->words.w1 = bases[order[i]] + 0x80000000U;
            fxDrawCone(arg0, (s32)parts[order[i]], 6, (u8)kinds[order[i]]);
        }
        g = (Gfx *)*arg0;
        *arg0 = g + 1;
        g->words.w1 = 0;
        g->words.w0 = 0xBC00000A;
    }

    if (*(s32 *)(obj + 0x550) != 0) {
        mantisSplitGfx(arg0, arg1, *(s32 *)(obj + 0x550), (*(s8 *)(obj + 1) * 6) + D_800A0C2C_A182C, obj + 0x544, obj + 0x78);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDrawPlayerEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objSetFlashPartColour(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    D_800A0C5C_A185C = arg0;
    D_800A0C60_A1860 = arg1;
    D_800A0C64_A1864 = arg2;
    D_800A0C68_A1868 = arg3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objSetFlashPartColour.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objClearFlashes(s32 arg0) {
    D_800A0C6C_A186C = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objClearFlashes.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000C964(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    s16 id = *(s16 *)(obj + 0x48);
    s16 fogA;
    s16 fogB;
    s16 fogC;
    s16 fogD;
    u8 fr;
    u8 fg;
    u8 fb;
    u8 *m;
    s32 bit;
    s8 t8;
    Gfx *g;

    trackGetFog(0, &fogA, &fogB, &fogC, &fr, &fg, &fb, &fogD);
    if (id == 0x18) {
        m = *(u8 **)(obj + 0x68);
        bit = 1 << arg1;
        if (*(u16 *)(m + 0xA4) & bit) {
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xF8000000;
            g->words.w1 = ((u8)D_800A0C5C_A185C << 0x18) | ((u8)D_800A0C60_A1860 << 0x10) | ((u8)D_800A0C64_A1864 << 8) | 0xFF;
            g = D_800F2CC8_B17B8++;
            g->words.w1 = 0x05000500;
            g->words.w0 = 0xBC000008;
            if ((u8)D_800A0C6C_A186C != 0) {
                *(u16 *)(m + 0xA4) = (u16)(*(u16 *)(m + 0xA4) & ~bit);
                t8 = (s8)((u8)D_800A0C68_A1868 - 1);
                if ((u8)D_800A0C68_A1868 != 0) {
                    D_800A0C68_A1868 = t8;
                    if ((t8 & 0xFF) == 0) {
                        D_800A0C5C_A185C = -1;
                        D_800A0C60_A1860 = 0x32;
                        D_800A0C64_A1864 = 0x32;
                    }
                }
            }
        } else {
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xF8000000;
            g->words.w1 = (fr << 0x18) | (fg << 0x10) | (fb << 8) | 0xFF;
            g = D_800F2CC8_B17B8++;
            g->words.w0 = 0xBC000008;
            g->words.w1 = ((0x1F400 / (fogB - fogA)) << 0x10) | ((((fogA * -0x100) + 0x1F400) / (fogB - fogA)) & 0xFFFF);
        }
    } else if (id == 0x82) {
        ShirukenPushMtx(&D_800F2CC8_B17B8, arg0, arg1, &D_800F2CC8_B17B8);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000C964.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Layout (asm-verified): obj+0x3A s8 model index, obj+0x40 objdef (+0x1F s8 frame count,
// +0xCC f32), obj+0x44 s32 (<- inst+4), obj+0x48 s16 behaviour id, obj+0x4C table ptr
// (+0x32 s16, +0x40 ptr to 0x34-byte entries), obj+0x54 s32 light word, obj+0x60, obj+0x68 racer
// ptr, obj+0x6C ptr to array of model-instance ptrs, obj+0x8C s32, obj+0x93/0x97/0x9B
// per-camera byte arrays (index camNo).
// Instance: +0x0 header ptr, +0x4 s32, +0xA s8 pending flag, +0xB s8 slot (0/1),
// +0x10 + slot*4 light word, +0x78 + slot*4 word.
// Header: +0x11 u8, +0x4E s8, +0x7C s32 count, +0x84 u32 offset array.
void objPrintModelObject(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *racer;
    u8 *inst;
    u8 *inst2;
    u8 *hdr;
    u8 *hdr2;
    u8 *camp;
    u8 *tgt;
    u8 *o4c;
    u8 *tumb;
    Gfx *g;
    s32 camNo;
    s32 camType;
    s32 type;
    s32 drewAnim;
    s32 lineFlag;
    s32 colA;
    s32 colB;
    s32 flag;
    s32 cnt;
    s32 sp100;
    s32 scrW;
    s32 scrH;
    s32 i;
    s32 ofs;
    s16 x;
    s16 y;
    s16 off;
    s16 off4;
    s16 d;
    s16 fogA;
    s16 fogB;
    s16 fogC;
    s16 fogD;
    u8 fr;
    u8 fg;
    u8 fb;
    u8 col1;
    u8 col2;
    f32 px;
    f32 py;
    f32 pz;
    f32 projX;
    f32 projY;

    camNo = camGetNo() & 3;
    racer = *(u8 **)(obj + 0x68);
    type = *(s16 *)(obj + 0x48);

    /* skip for type 1 when this camera is not the racer's and racer+0x10E > 0 */
    if (type == 1 && camNo != *(s8 *)racer && *(s16 *)(racer + 0x10E) > 0) {
        return;
    }

    inst = (*(u8 ***)(obj + 0x6C))[*(s8 *)(obj + 0x3A)];
    if (inst == NULL) {
        return;
    }

    hdr = *(u8 **)inst;
    drewAnim = 0;
    camp = obj + camNo;
    camType = camp[0x93];

    if (camType == 6) {
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0xF8000000;
        g->words.w1 = ((u32)racer[2] << 8) | ((u32)racer[0] << 24) | ((u32)racer[1] << 16) | 0xFF;
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0xBC000008;
        g->words.w1 = 0x05000500;
    } else if (camType != 0) {
        off = (s16)(camp[0x9B] * 2);
        tgt = NULL;
        if (type == 0x18) {
            tgt = racer;
        }
        if (camp[0x97] != 0xFF && camp[0x97] >= *(s16 *)(*(u8 **)(obj + 0x4C) + 0x32)) {
            camp[0x97] = 0xFF;
        }
        if (D_800A0C6C_A186C != 0) {
            if (camp[0x9B] < 8) {
                camp[0x9B] = camp[0x9B] + 1;
            }
        }

        if (camType != 5) {
            if (tgt != NULL) {
                u8 *p24 = *(u8 **)(tgt + 0x24);
                u8 *p68 = *(u8 **)(p24 + 0x68);
                if (squadsIsTribal(*(u16 *)(p68 + 0x2C), tgt)) {
                    colA = 0xFF;
                    colB = 0x32;
                } else {
                    colA = 0x32;
                    colB = 0xFF;
                }
            } else {
                colA = 0x32;
                colB = 0xFF;
            }

            if (camp[0x9B] & 1) {
                if (type != 0x6C && type != 0x82) {
                    g = D_800F2CC8_B17B8++;
                    g->words.w0 = 0xF8000000;
                    g->words.w1 = ((u32)colA << 24) | (((u32)colB & 0xFF) << 16) | 0x32FF;
                    g = D_800F2CC8_B17B8++;
                    g->words.w1 = 0x05000500;
                    g->words.w0 = 0xBC000008;
                }
            }

            if (camType != 1 && (tgt == NULL || *(s16 *)(tgt + 0xA6) > 0)) {
                o4c = *(u8 **)(obj + 0x4C);
                if (camp[0x97] == 0xFF) {
                    px = *(f32 *)(o4c + 0xC);
                    py = *(f32 *)(o4c + 0x10);
                    pz = *(f32 *)(o4c + 0x14);
                } else {
                    u8 *ent = *(u8 **)(o4c + 0x40) + camp[0x97] * 0x34;
                    px = *(f32 *)(ent + 0xC);
                    py = *(f32 *)(ent + 0x10);
                    pz = *(f32 *)(ent + 0x14);
                }

                if (camProjectPoint(px, py, pz, &projX, &projY, 1) != 0) {
                    lineFlag = (colA == 0xFF) ? 0x10 : 0;
                    viGetCurrentSize(&scrW, &scrH);
                    x = (s16)(s32)projX;
                    y = (s16)(s32)projY;
                    col1 = (u8)lineFlag;
                    col2 = (u8)((lineFlag & 0xFFF0) | 2);

                    if (camType == 3) {
                        fxDrawLine(0, y, (s16)(x - off), y, col1);
                        fxDrawLine((s16)(x + off), y, (s16)(scrW - 1), y, col1);
                        fxDrawLine(x, 0, x, (s16)(y - off), col1);
                        fxDrawLine(x, (s16)(y + off), x, (s16)(scrH - 1), col1);
                    }
                    if (camType == 2 || camType == 3) {
                        fxDrawLine((s16)(x - off), (s16)(y - off), (s16)(x + off), (s16)(y - off), col1);
                        fxDrawLine((s16)(x - off), (s16)(y + off), (s16)(x + off), (s16)(y + off), col1);
                        fxDrawLine((s16)(x - off), (s16)(y - off), (s16)(x - off), (s16)(y + off), col1);
                        fxDrawLine((s16)(x + off), (s16)(y - off), (s16)(x + off), (s16)(y + off), col1);
                    } else if (camType == 4) {
                        off4 = (s16)(camp[0x9B] * 2);
                        d = (s16)(s32)((f32)off4 * 0.41421357f);
                        fxDrawLine((s16)(x - d), (s16)(y - off4), (s16)(x + d), (s16)(y - off4), col1);
                        fxDrawLine((s16)(x - d), (s16)(y + off4), (s16)(x + d), (s16)(y + off4), col1);
                        fxDrawLine((s16)(x - off4), (s16)(y - d), (s16)(x - off4), (s16)(y + d), col1);
                        fxDrawLine((s16)(x + off4), (s16)(y - d), (s16)(x + off4), (s16)(y + d), col1);
                        fxDrawLine((s16)(x - off4), (s16)(y + d), (s16)(x - d), (s16)(y + off4), col2);
                        fxDrawLine((s16)(x - off4), (s16)(y - d), (s16)(x - d), (s16)(y - off4), col2);
                        fxDrawLine((s16)(x + off4), (s16)(y + d), (s16)(x + d), (s16)(y + off4), col2);
                        fxDrawLine((s16)(x + off4), (s16)(y - d), (s16)(x + d), (s16)(y - off4), col2);
                    }
                }
            }
        }
    }

    /* common section */
    flag = D_800A0A20_A1620;
    if (flag == 0 && *(f32 *)(*(u8 **)(obj + 0x40) + 0xCC) > 0.0f) {
        if (*(f32 *)(*(u8 **)(obj + 0x40) + 0xCC) <
            -camGetProjZ(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14))) {
            flag = 1;
        }
    }
    if (*(s8 *)(obj + 0x3A) + flag >= *(s8 *)(*(u8 **)(obj + 0x40) + 0x1F)) {
        flag = 0;
    }
    inst2 = (*(u8 ***)(obj + 0x6C))[*(s8 *)(obj + 0x3A) + flag];
    hdr2 = *(u8 **)inst2;

    tumb = NULL;
    if (type == 1) {
        tumb = racer;
        objDoPlayerTumble((Object *)obj);
    }

    *(s32 *)(obj + 0x44) = *(s32 *)(inst + 0x4);

    if (*(s8 *)(hdr + 0x4E) != 0) {
        if (*(s8 *)(inst + 0xA) != 0) {
            modGenAnimMatrices(inst, hdr, obj, D_800F2E98_B1988, 0.0f);
            lightObject(obj, inst, *(s32 *)(obj + 0x54), *(s32 *)(inst + 0x10 + *(s8 *)(inst + 0xB) * 4));
        }
    } else if (*(s8 *)(inst + 0xA) != 0) {
        if (*(u8 *)(hdr + 0x11) != 0) {
            *(s8 *)(inst + 0xB) = (s8)(*(s8 *)(inst + 0xB) ^ 1);
        }
        lightObject(obj, inst, *(s32 *)(obj + 0x54), *(s32 *)(inst + 0x10 + *(s8 *)(inst + 0xB) * 4));
    }
    if (inst2 != inst && *(s8 *)(inst2 + 0xA) != 0) {
        lightObject(obj, inst2, *(s32 *)(obj + 0x54), *(s32 *)(inst + 0x10 + *(s8 *)(inst + 0xB) * 4));
        *(s8 *)(inst2 + 0xA) = 0;
    }
    if (*(u8 *)(hdr + 0x11) != 0) {
        if (*(s8 *)(inst + 0xA) != 0) {
            objAnimTextures(obj, hdr, inst, *(s8 *)(inst + 0xA));
        }
        drewAnim = 1;
    }
    *(s8 *)(inst + 0xA) = 0;
    if (tumb != NULL) {
        objUndoPlayerTumble((Object *)obj);
    }

    if (obj[0x39] == 0xFF) {
        sp100 = *(s32 *)(hdr2 + 0x74);
    } else {
        sp100 = *(s32 *)(hdr2 + 0x78);
    }

    g = D_800F2CC8_B17B8++;
    if (type == 7) {
        u32 v = *(u32 *)(racer + 0x28) & 0xFF;
        g->words.w0 = 0xFA000000;
        g->words.w1 = (v << 24) | (v << 16) | (v << 8) | obj[0x39];
    } else {
        g->words.w0 = 0xFA000000;
        g->words.w1 = obj[0x39] | 0xFFFFFF00U;
    }

    if (*(s8 *)(hdr + 0x4E) == 0) {
        if (type == 0x99) {
            mizarHandBitPushMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, obj);
        } else if (type == 0x8A) {
            minePushMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, obj);
        } else if (type == 0xA6) {
            windowDrawBeams(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, obj);
        } else {
            camPushModelMtx(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, (ObjectTransform *)obj, D_800F2E98_B1988, 0.0f);
        }
    }

    g = D_800F2CC8_B17B8++;
    g->words.w0 = ((*(u32 *)(inst + 0x10 + *(s8 *)(inst + 0xB) * 4) + 0x80000000U) & 0xFFFFFF) | 0xBF000000U;
    g->words.w1 = *(u32 *)(inst2 + 0x4) + 0x80000000U;

    if (drewAnim != 0) {
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0x02000050;
        if (flag != 0) {
            g->words.w1 = (u32)D_A0838;
        } else {
            g->words.w1 = *(u32 *)(inst + 0x78 + *(s8 *)(inst + 0xB) * 4) + 0x80000000U;
        }
    }

    cnt = *(s32 *)(hdr + 0x7C);
    if (cnt != 0) {
        if (cnt + 1 > 0) {
            i = 0;
            ofs = 0;
            do {
                /* sig mismatch: func_8000C964 is defined with 2 params, asm passes 4 */
                ((void (*)(void *, s32, s32, s32))func_8000C964)(obj, i, ofs, (s32)0x80000000);
                if (drewAnim != 0) {
                    g = D_800F2CC8_B17B8++;
                    g->words.w0 = 0x02000050;
                    g->words.w1 = (u32)D_A0838;
                }
                g = D_800F2CC8_B17B8++;
                g->words.w0 = 0x06000000;
                i += 1;
                g->words.w1 = *(u32 *)(*(u8 **)(hdr + 0x84) + ofs) + 0x80000000U;
                ofs += 4;
            } while (*(s32 *)(hdr + 0x7C) >= i);
        }
    } else {
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0x06000000;
        g->words.w1 = sp100 + 0x80000000U;
    }

    g = D_800F2CC8_B17B8++;
    g->words.w1 = 0;
    g->words.w0 = 0xBF000000;
    camRestoreModelMtx(&D_800F2CC8_B17B8);
    texDPInit(&D_800F2CC8_B17B8);

    if (type == 1) {
        u8 *gc = (u8 *)mainGetGameCharacter(*(s8 *)racer, *(s8 *)(racer + 1));
        func_8000BDCC(obj, inst, hdr, gc[0x70], (s32)(racer + 0x78));
    } else if (type == 0x33) {
        if (*(s32 *)(obj + 0x60) != 0) {
            func_8000BDCC(obj, inst, hdr, *(s32 *)(obj + 0x8C), (s32)racer);
        }
    }

    if (camp[0x93] != 0 || cnt != 0) {
        trackGetFog(camGetNo(), &fogA, &fogB, &fogC, &fr, &fg, &fb, &fogD);
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0xF8000000;
        g->words.w1 = ((u32)fr << 24) | ((u32)fg << 16) | ((u32)fb << 8) | 0xFF;
        g = D_800F2CC8_B17B8++;
        g->words.w0 = 0xBC000008;
        g->words.w1 = ((u32)(0x1F400 / (fogB - fogA)) << 16) |
                      ((((fogA * -0x100) + 0x1F400) / (fogB - fogA)) & 0xFFFF);
    }

    g = D_800F2CC8_B17B8++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = -1U;
    g = D_800F2CC8_B17B8++;
    g->words.w1 = -1U;
    g->words.w0 = 0xFB000000;

    D_800A0A20_A1620 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objPrintModelObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objPrintObject(Gfx **arg0, MatrixS **arg1, s32 *arg2, void *arg3) {
    if (!(*(s16 *)((u8 *)arg3 + 6) & 0xC00)) {
        D_800F2CC8_B17B8 = *arg0;
        D_800F2CCC_B17BC = *arg1;
        D_800F2CD0_B17C0 = *arg2;
        func_8000DD1C(arg3);
        *arg0 = D_800F2CC8_B17B8;
        *arg1 = D_800F2CCC_B17BC;
        *arg2 = D_800F2CD0_B17C0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objPrintObject.s")
#endif

#if 0 /* old NON_EQUIVALENT attempt */
void objDoPlayerTumble(Object *this) {
    UNUSED s32 unused1;
    Object_Racer *sp_20;
    f32 sp_1c;
    f32 tmp_f0;
    if (this->behaviorId == 1) {
        sp_20 = this->racer;
        this->segment.trans.y_rotation += sp_20->y_rotation_offset;
        this->segment.trans.x_rotation += sp_20->x_rotation_offset;
        this->segment.trans.z_rotation += sp_20->z_rotation_offset;
        sp_1c = Cosf(sp_20->z_rotation_offset);
        tmp_f0 = Cosf(sp_20->x_rotation_offset - sp_20->unk146) * sp_1c;
        tmp_f0 = ((tmp_f0 < 0.0f) ? 0.0f : tmp_f0 * tmp_f0);
        tmp_f0 = ((1.0f - tmp_f0)) * 24.0f + sp_20->unk64;
        this->segment.trans.y_position += tmp_f0;
        D_800F3A20 = tmp_f0;
    }
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDoPlayerTumble(Object *this) {
    Object_Racer *racer;
    f32 cz;
    f32 tmp;
    f32 sq;

    if (this->behaviorId == 1) {
        racer = this->racer;
        this->segment.trans.y_rotation += racer->y_rotation_offset;
        this->segment.trans.x_rotation += racer->x_rotation_offset;
        this->segment.trans.z_rotation += racer->z_rotation_offset;
        cz = Cosf(racer->z_rotation_offset);
        tmp = Cosf(racer->x_rotation_offset - racer->unk146) * cz;
        sq = (tmp < 0.0f) ? 0.0f : tmp * tmp;
        tmp = ((1.0f - sq) * 24.0f) + racer->unk64;
        this->segment.trans.y_position += tmp;
        D_800F3A20 = tmp;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDoPlayerTumble.s")
#endif

void objUndoPlayerTumble(Object *obj) {
    if (obj->behaviorId == 1) {
        Object_Racer *racer = obj->racer;
        obj->segment.trans.y_rotation -= racer->y_rotation_offset;
        obj->segment.trans.x_rotation -= racer->x_rotation_offset;
        obj->segment.trans.z_rotation -= racer->z_rotation_offset;
        obj->segment.trans.y_position -= D_800F3A20;
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000DCE8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    f32 val = 1.0f;

    if (*(s16 *)(obj + 0x48) == 1) {
        u8 *p = *(u8 **)(obj + 0x68);
        val = *(f32 *)(p + 0x48);
        p[0x197] = 0x1E;
    }
    D_800F2E98_B1988 = val;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000DCE8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000DD1C(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s16 id = *(s16 *)(obj + 0x48);
    f32 saved;

    func_8000DCE8(arg0);
    if (id == 0x72) {
        glassDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0, arg0);
        return;
    }
    if (id == 0x4E) {
        blastdoorDraw(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, arg0, arg0);
        return;
    }
    if (id == 0x81) {
        treeInit(&D_800F2CC8_B17B8, &D_800F2CCC_B17BC, &D_800F2CD0_B17C0, arg0);
        return;
    }
    if (id == 7) {
        objDrawDoor(arg0);
        return;
    }
    if (id == 0x7A) {
        saved = *(f32 *)(obj + 0x10);
        *(f32 *)(obj + 0x10) = saved + 40.0f;
        objPrintModelObject(arg0);
        *(f32 *)(obj + 0x10) = saved;
        return;
    }
    switch (*(u8 *)(*(u8 **)(obj + 0x40) + 0x1E)) {
    case 0:
        objPrintModelObject(arg0);
        return;
    case 1:
        func_8000B3DC(arg0);
        return;
    case 4:
        objPrintCustomObject(arg0);
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000DD1C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objScrollTexture(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *info = *(u8 **)(obj + 0x40);
    s16 dx = (s16)(*(s8 *)(info + 0xA4) * arg1);
    s16 dy = (s16)(*(s8 *)(info + 0xA5) * arg1);
    u8 start = info[0xA3];
    u8 t0 = info[0xA2];
    s32 end;
    s32 i;
    s32 j;
    s32 ii;

    if (start == 0xFF || (s32)start < (s32)*(s8 *)(info + 0x1F)) {
        end = start + 1;
        if (start == 0xFF) {
            end = *(s8 *)(info + 0x1F);
            start = 0;
        }
        for (ii = start; ii < end; ii++) {
            u8 *tex = ((u8 **)*(u8 ***)(obj + 0x6C))[ii];
            u8 *hdr = *(u8 **)tex;
            u8 *ent;
            s32 cnt;

            if ((s32)t0 < (s32)*(u8 *)(hdr + 0x10)) {
                cnt = *(s16 *)(hdr + 0x16);
                ent = *(u8 **)(hdr + 0x24);
                for (i = 0; i < cnt; i++) {
                    if (t0 == ent[0]) {
                        for (j = *(s16 *)(ent + 8); j < *(s16 *)(ent + 0x18); j++) {
                            u8 *p = *(u8 **)(hdr + 0x20) + (j * 0x10);
                            if (dx != 0) {
                                s16 s3 = *(s16 *)(p + 4);
                                *(s16 *)(p + 4) = (s16)((s3 + dx) & ((s16)(*(u8 *)(*(u8 **)(hdr + 0x18) + (t0 * 8)) << 5) - 1));
                                *(s16 *)(p + 8) = (s16)(*(s16 *)(p + 4) + (*(s16 *)(p + 8) - s3));
                                *(s16 *)(p + 0xC) = (s16)(*(s16 *)(p + 4) + (*(s16 *)(p + 0xC) - s3));
                            }
                            if (dy != 0) {
                                s16 s3 = *(s16 *)(p + 6);
                                *(s16 *)(p + 6) = (s16)((s3 + dy) & ((s16)(*(u8 *)(*(u8 **)(hdr + 0x18) + (t0 * 8) + 1) << 5) - 1));
                                *(s16 *)(p + 0xA) = (s16)(*(s16 *)(p + 6) + (*(s16 *)(p + 0xA) - s3));
                                *(s16 *)(p + 0xE) = (s16)(*(s16 *)(p + 6) + (*(s16 *)(p + 0xE) - s3));
                            }
                        }
                    }
                    ent += 0x10;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objScrollTexture.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 objPartInv(s32 *arg0) {
    s32 lo;
    s32 hi;

    *arg0 = ObjListCount;
    if (D_800F38C2 != 0) {
        return D_800F38C2;
    }
    lo = D_800F38AC;
    hi = ObjListCount - 1;
    while (hi >= lo) {
        while (lo <= hi && (*(u16 *)((u8 *)ObjList[lo]->segment.header + 0x14) & 1)) {
            lo++;
        }
        while (hi >= lo && !(*(u16 *)((u8 *)ObjList[hi]->segment.header + 0x14) & 1)) {
            hi--;
        }
        if (lo < hi) {
            Object *tmp = ObjList[lo];
            ObjList[lo] = ObjList[hi];
            ObjList[hi] = tmp;
            lo++;
            hi--;
        }
    }
    D_800F38C2 = (s16)lo;
    return (s16)lo;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objPartInv.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objZsortGroup(s32 arg0, s32 arg1) {
    s32 n = arg1 - arg0;
    s32 i;
    s32 swapped;

    if (n > 0) {
        for (i = arg0; i <= arg1; i++) {
            Object *o = ObjList[i];
            if (o != NULL) {
                *(f32 *)((u8 *)o + 0x30) = -camGetProjZ(o->segment.trans.x_position, o->segment.trans.y_position, o->segment.trans.z_position);
            }
        }
        do {
            swapped = 0;
            for (i = arg0; i < arg1; i++) {
                if (*(f32 *)((u8 *)ObjList[i + 1] + 0x30) < *(f32 *)((u8 *)ObjList[i] + 0x30)) {
                    Object *tmp = ObjList[i];
                    ObjList[i] = ObjList[i + 1];
                    ObjList[i + 1] = tmp;
                    swapped = 1;
                }
            }
            n--;
        } while (swapped && n != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objZsortGroup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objGetPlayerlist(s32 *arg0) {
    *arg0 = D_800F3910;
    return playerlist;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetPlayerlist.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objAddAnimPlayer(s32 arg0) {
    animplayerlist[D_800F391C] = arg0;
    D_800F391C += 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objAddAnimPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 *objGetAnimPlayerlist(s32 *arg0) {
    *arg0 = D_800F391C;
    return animplayerlist;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetAnimPlayerlist.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objGetPlayerNo(s32 arg0) {
    if (D_800F3910 == 0) {
        return 0;
    }
    if (arg0 < 0 || arg0 >= D_800F3910) {
        return 0;
    }
    return ((s32 *)playerlist)[arg0];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objGetPlayerNo.s")
#endif

void setObjectViewNormal(f32 x, f32 y, f32 z) {
    f32 vecLength = sqrtf((x * x) + (y * y) + (z * z));
    f32 normalizedLength;
    if (vecLength != 0.0f) {
        normalizedLength = -8192.0f / vecLength;
        x *= normalizedLength;
        y *= normalizedLength;
        z *= normalizedLength;
    }
    gEnvmapPos.x = x;
    gEnvmapPos.y = y;
    gEnvmapPos.z = z;
}

/**
 * Returns a pointer to the asset in the misc. section. If index is out of range, then this
 * function just returns the pointer to Ftables.
 */
s32 *objGetTable(s32 index) {
    if (index < 0 || index >= Fmax) {
        return Ftables;
    }
    return (s32 *) &Ftables[Findex[index]];
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objSetAnimGroup(s32 arg0) {
    D_800F38C0 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objSetAnimGroup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8000E5F0(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    s16 temp_t7;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 var_v1;
    u8 *temp_v0_5;

    *(s32 *)(obj + 0x68) = arg1;
    temp_t7 = *(s16 *)(*(u8 **)(obj + 0x40) + 0x1C);
    var_v1 = 0;
    switch (temp_t7) {
    case 0x2:
        return 0xB8;
    case 0x1:
        return 0x5F4;
    case 0x7:
        return 0x50;
    case 0x43:
        return 0x14;
    case 0x3C:
        return 0x4;
    case 0x8:
        return 0x1C;
    case 0x22:
        return 0x10;
    case 0x2D:
        return 0x14;
    case 0x94:
        return 0x18;
    case 0x23:
        return 0x10;
    case 0x37:
        return ((((**(u8 ***)(*(s32 *)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4)))[0x2D] * 0x28) + 0x30) & ~3) + 4;
    case 0x16:
        temp_v0 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0);
        return ((temp_v0 + 0x118) & ~3) + 4;
    case 0x14:
        return 0x50;
    case 0x4D:
        return 0x14;
    case 0x12:
        return 0x54;
    case 0xA2:
        temp_v0_10 = arg1 & 7;
        if (temp_v0_10 != 0) {
            var_v1 = 8 - temp_v0_10;
        }
        *(s32 *)(obj + 0x68) = (s32) (arg1 + var_v1);
        return ((var_v1 + 0x88) & ~3) + 4;
    case 0x98:
        temp_v0_2 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0_2);
        return ((temp_v0_2 + 0xA88) & ~3) + 4;
    case 0x3F:
        return 0x4;
    case 0x45:
        return 0x8;
    case 0x9E:
        return 0x40;
    case 0x9F:
        return 0x1C;
    case 0xA0:
        return 0x1C;
    case 0x9B:
        return 0x14;
    case 0xA1:
        return 0x14;
    case 0x99:
        return 0x8C;
    case 0x87:
        return 0x8;
    case 0x9A:
        return 0x38;
    case 0x9D:
        return 0x9C;
    case 0x9C:
        return 0xC;
    case 0x17:
        return 0x98;
    case 0x18:
        return 0xD0;
    case 0x2C:
        return 0x8;
    case 0x95:
        return 0x10;
    case 0x1B:
        return 0x14;
    case 0x38:
        return 0x14;
    case 0x28:
        temp_v0_3 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0_3);
        return ((temp_v0_3 + 0x1DC) & ~3) + 4;
    case 0x29:
        temp_v0_4 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0_4);
        return ((temp_v0_4 + 0x700) & ~3) + 4;
    case 0x27:
        temp_v0_5 = *(u8 **)(obj + 0x3C);
        return ((temp_v0_5[0x31] + (temp_v0_5[0x32] * 2) + 0x30) & ~3) + 4;
    case 0x26:
        return 0x38;
    case 0x13:
        return 0x34;
    case 0x93:
        return 0x14;
    case 0x33:
        return 0x64;
    case 0x44:
        return 0xD4;
    case 0x24:
        return 0x30;
    case 0x25:
        return 0x28;
    case 0x40:
        return 0x24;
    case 0x46:
        return 0x5C;
    case 0x47:
        return 0xC;
    case 0x48:
        return 0x18;
    case 0x49:
        return 0x14;
    case 0x4B:
        return 0x14;
    case 0x4C:
        return 0x24;
    case 0x4E:
        temp_v0_11 = arg1 & 7;
        if (temp_v0_11 != 0) {
            var_v1 = 8 - temp_v0_11;
        }
        *(s32 *)(obj + 0x68) = (s32) (arg1 + var_v1);
        return ((var_v1 + 0x60) & ~3) + 4;
    case 0x42:
        return 0xC;
    case 0x8D:
        return 0x14;
    case 0x52:
        temp_v0_6 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0_6);
        return ((temp_v0_6 + 0x508) & ~3) + 4;
    case 0x58:
        temp_v0_7 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0_7);
        return ((temp_v0_7 + 0xFCC) & ~3) + 4;
    case 0xA3:
        return 0x20;
    case 0xA6:
    case 0xA7:
        return 0xB4;
    case 0x59:
        return 0x24;
    case 0x5A:
        return 0x3C;
    case 0x3D:
        return 0x1C;
    case 0x5C:
        return 0x20;
    case 0x5B:
        return 0x24;
    case 0x5D:
        return 0x24;
    case 0x5E:
        return 0x10;
    case 0x5F:
    case 0x96:
        return 0xC4;
    case 0x62:
        return 0x28;
    case 0x68:
        return 0x1C;
    case 0x64:
        return 0x1C;
    case 0x69:
        return 0x14;
    case 0x54:
    case 0xA8:
        return 0x14;
    case 0x6C:
        return 0xD0;
    case 0x6F:
        return 0x10;
    case 0x97:
        return 0x7C;
    case 0x71:
        return 0x8;
    case 0x72:
        return 0x10;
    case 0x76:
        return 0x24;
    case 0x77:
    case 0x78:
        return 0xC;
    case 0x79:
        return 0x44;
    case 0x7B:
        return 0xC;
    case 0x7C:
        return 0x24;
    case 0x7D:
        return 0x24;
    case 0x53:
        return 0x18;
    case 0x7F:
        return 0xC;
    case 0x80:
        return 0x14;
    case 0x81:
        return 0x1C;
    case 0x63:
        return 0x8;
    case 0x82:
        return 0xB4;
    case 0xA9:
        return 0x28;
    case 0xAA:
        return 0xC;
    case 0xAC:
        return 0xC;
    case 0xAB:
        return 0x1C;
    case 0x89:
        return 0x14;
    case 0x8A:
        return 0x18;
    case 0xAD:
        return 0xC;
    case 0x8B:
        return 0x20;
    case 0xAE:
        temp_v0_8 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0_8);
        return ((temp_v0_8 + 0x6E8) & ~3) + 4;
    case 0x8E:
        return 0x8;
    case 0x84:
        return 0x34;
    case 0x85:
        return 0x54;
    case 0x88:
        return 0x15C;
    case 0x8F:
        return 0x34;
    case 0x91:
        return 0x24;
    case 0x92:
        temp_v0_9 = 0x10 - (arg1 & 0xF);
        *(s32 *)(obj + 0x68) = (s32) (arg1 + temp_v0_9);
        return ((temp_v0_9 + 0x6C0) & ~3) + 4;
    case 0x3A:
        return 0x8;
    default:
        *(s32 *)(obj + 0x68) = 0;
        return 0x4;
    }
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000E5F0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objSetup(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s16 temp_t8;

    *(s16 *)(obj + 0x48) = *(s16 *)(*(u8 **)(obj + 0x40) + 0x1C);
    temp_t8 = *(s16 *)(obj + 0x48);
    switch (temp_t8) {
    case 0x2:
        sidekickInit(arg0);
        break;
    case 0x1:
        controlPlayerInit(arg0);
        break;
    case 0x3:
    case 0x4:
    case 0x5:
        fishInit(arg0);
        break;
    case 0x14:
        fishfoodInit(arg0);
        break;
    case 0x4D:
        exitInit(arg0);
        break;
    case 0x22:
        animInit(arg0);
        break;
    case 0x8:
        audioPointInit(arg0);
        break;
    case 0x2D:
        audioLineInit(arg0);
        break;
    case 0x94:
        staticcamInit(arg0);
        break;
    case 0x11:
        setupInit(arg0);
        break;
    case 0x6:
        doorInit(arg0);
        break;
    case 0x7:
        doorSwitchInit(arg0);
        break;
    case 0x43:
        keyInit(arg0);
        break;
    case 0x3C:
        fogInit(arg0);
        break;
    case 0x9:
        skyInit(arg0);
        break;
    case 0xA:
        texscrollInit(arg0);
        break;
    case 0x39:
    case 0x3E:
        spranimInit(arg0);
        break;
    case 0x3A:
        sprasjiInit(arg0);
        break;
    case 0x23:
        rgbalightInit(arg0);
        break;
    case 0x1E:
        buoyInit(arg0);
        break;
    case 0x10:
        weatherInit(arg0);
        break;
    case 0xB:
        lensflareInit(arg0);
        break;
    case 0xC:
        flareswitchInit(arg0);
        break;
    case 0xD:
        waveswellInit(arg0);
        break;
    case 0xE:
        butterflyInit(arg0);
        break;
    case 0x16:
        hitstaticInit(arg0);
        break;
    case 0x30:
    case 0x31:
        hitanimInit(arg0);
        break;
    case 0x36:
        hitBridgeInit(arg0);
        break;
    case 0x37:
        bubblerInit(arg0);
        break;
    case 0x20:
        frogInit(arg0);
        break;
    case 0x15:
        splinecamnodeInit(arg0);
        break;
    case 0x12:
        laserboltInit(arg0);
        break;
    case 0x27:
        explosionInit(arg0);
        break;
    case 0xA2:
        shrinkbeamInit(arg0);
        break;
    case 0x3F:
        muzzleFlashInit(arg0);
        break;
    case 0x98:
        trackbeamInit(arg0);
        break;
    case 0x45:
        missileInit(arg0);
        break;
    case 0x9E:
        CyborgMissileInit(arg0);
        break;
    case 0x9F:
        TwinkleInit(arg0);
        break;
    case 0xA0:
        grenadeInit(arg0);
        break;
    case 0x9B:
        zombieFlobInit(arg0);
        break;
    case 0xA1:
        ShirukenInit(arg0);
        break;
    case 0x99:
        MaggotBombInit(arg0);
        break;
    case 0x87:
        FlowerBoltInit(arg0);
        break;
    case 0x9A:
        LaserBeamInit(arg0);
        break;
    case 0x9D:
        SpiderSpitInit(arg0);
        break;
    case 0x9C:
        SquadronInit(arg0);
        break;
    case 0x17:
        SquaddieInit(arg0);
        break;
    case 0x18:
        AIPointInit(arg0);
        break;
    case 0x95:
        AIJunctionInit(arg0);
        break;
    case 0x1B:
        spinlightInit(arg0);
        break;
    case 0x38:
        FatBobShockWaveInit(arg0);
        break;
    case 0x28:
        shockwaveInit(arg0);
        break;
    case 0x29:
        overrideCInit(arg0);
        break;
    case 0x26:
        expspriteInit(arg0);
        break;
    case 0x13:
        weaponPickupInit(arg0);
        break;
    case 0x2B:
        healthPickupInit(arg0);
        break;
    case 0x3D:
        ammoPickupInit(arg0);
        break;
    case 0x42:
        beamInit(arg0);
        break;
    case 0x41:
        lightAdjustGlowingLight(arg0);
        break;
    case 0x44:
        shardClusterInit(arg0);
        break;
    case 0x24:
        electrocutionInit(arg0);
        break;
    case 0x25:
        menuCamInit(arg0);
        break;
    case 0x40:
        severedLimbInit(arg0);
        break;
    case 0x46:
        menuCamFocusInit(arg0);
        break;
    case 0x47:
        refuelInit(arg0);
        break;
    case 0x49:
        dropletInit(arg0);
        break;
    case 0x4A:
        splashInit(arg0);
        break;
    case 0x4B:
        waterbubbleInit(arg0);
        break;
    case 0x4C:
        glassInit(arg0);
        break;
    case 0x4E:
        invincibilityInit(arg0);
        break;
    case 0x50:
        invisibilityInit(arg0);
        break;
    case 0x51:
        invincibilityShieldInit(arg0);
        break;
    case 0x52:
        teleportEffectInit(arg0);
        break;
    case 0x58:
        fireExplosionInit(arg0);
        break;
    case 0x53:
        smokingfireInit(arg0);
        break;
    case 0x55:
        fireringInit(arg0);
        break;
    case 0x56:
        twisterInit(arg0);
        break;
    case 0xA3:
        grubInit(arg0);
        break;
    case 0x57:
        mineInit(arg0);
        break;
    case 0xA6:
    case 0xA7:
        hitfragmentInit(arg0);
        break;
    case 0x54:
    case 0xA8:
        flareInit(arg0);
        break;
    case 0x59:
        mrhintsInit(arg0);
        break;
    case 0x33:
        animplayerInit(arg0);
        break;
    case 0x93:
        animdroidInit(arg0);
        break;
    case 0x5A:
        multiCharArmInit(arg0);
        break;
    case 0x5C:
        damagecrateInit(arg0);
        break;
    case 0x5B:
        sidekickpadInit(arg0);
        break;
    case 0x5D:
        totemPoleInit(arg0);
        break;
    case 0x8D:
        floatingInit(arg0);
        break;
    case 0x5E:
        collectableInit(arg0);
        break;
    case 0x3B:
        animshipInit(arg0);
        break;
    case 0x5F:
    case 0x96:
        mainclusterInit(arg0);
        break;
    case 0xA4:
        smallclusterInit(arg0);
        break;
    case 0xA5:
        animswitchInit(arg0);
        break;
    case 0x60:
        chestInit(arg0);
        break;
    case 0x62:
        cutcameraInit(arg0);
        break;
    case 0x64:
        fireflyInit(arg0);
        break;
    case 0x63:
        robottargetInit(arg0);
        break;
    case 0x66:
        robotcollectableInit(arg0);
        break;
    case 0x67:
        robotcheckInit(arg0);
        break;
    case 0x68:
        dopplerPointInit(arg0);
        break;
    case 0x69:
        mizarAISetup(arg0);
        break;
    case 0x6B:
        mizarSetup(arg0);
        break;
    case 0x6A:
        rockstormInit(arg0);
        break;
    case 0x97:
        flyingdebrisInit(arg0);
        break;
    case 0x6E:
        targetswitchInit(arg0);
        break;
    case 0x6F:
        markerboxInit(arg0);
        break;
    case 0x70:
        craterInit(arg0);
        break;
    case 0x71:
        windowfxInit(arg0);
        break;
    case 0x72:
        flagtargetInit(arg0);
        break;
    case 0x74:
        flagtriggerInit(arg0);
        break;
    case 0x75:
        genericplayerInit(arg0);
        break;
    case 0x76:
        multitargetInit(arg0);
        break;
    case 0x77:
        multiptargetInit(arg0);
        break;
    case 0x78:
        racecheckInit(arg0);
        break;
    case 0x79:
        racepickupInit(arg0);
        break;
    case 0x7A:
        raceobstacleInit(arg0);
        break;
    case 0x7B:
        transformerInit(arg0);
        break;
    case 0x7C:
        terminalInit(arg0);
        break;
    case 0x7D:
        lightShowInit(arg0);
        break;
    case 0x7F:
        nightvisionpadInit(arg0);
        break;
    case 0x80:
        blastdoorInit(arg0);
        break;
    case 0x81:
        mantisInit(arg0);
        break;
    case 0x82:
        mantismissileInit(arg0);
        break;
    case 0xA9:
        mantisboltInit(arg0);
        break;
    case 0xAA:
        mantisrockInit(arg0);
        break;
    case 0xAC:
        mizarFireBallInit(arg0);
        break;
    case 0xAB:
        mizarWingBitInit(arg0);
        break;
    case 0x89:
        mizarHandBitInit(arg0);
        break;
    case 0x8A:
        mizarEyeBeamInit(arg0);
        break;
    case 0xAD:
        mizarImpactInit(arg0);
        break;
    case 0x8B:
        mizarElectroInit(arg0);
        break;
    case 0xAE:
        mizarMonolithInit(arg0);
        break;
    case 0x8E:
        spotlightInit(arg0);
        break;
    case 0x84:
        hoovertankInit(arg0);
        break;
    case 0x85:
        hoovergemInit(arg0);
        break;
    case 0x86:
        regionidInit(arg0);
        break;
    case 0x88:
        arcadeInit(arg0);
        break;
    case 0x8F:
        fireworkInit(arg0);
        break;
    case 0x91:
        mizarDeathInit(arg0);
        break;
    case 0x92:
        treeControl(arg0);
        break;
    }
    if (*(s32 *)(obj + 0x5C) != 0) {
        hitModelInit(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objSetup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8000F8E8(s32 arg0) {
    s32 ret = 0;
    switch (arg0) {
    case 0x1:
    case 0x2:
        return 0xF01;
    case 0x5:
        return 0x301;
    case 0x4:
        return 0xB01;
    case 0x6F:
        return 0x1800;
    case 0x43:
        return 0x1800;
    case 0x7:
        return 0x1805;
    case 0x30:
        return 0x1B01;
    case 0x31:
        return 0x1A00;
    case 0x36:
        return 0x1901;
    case 0x37:
        return 0x3806;
    case 0x2E:
    case 0x33:
    case 0x5F:
    case 0x93:
        return 0x301;
    case 0x96:
        return 0x1B01;
    case 0x2F:
        return 0x200;
    case 0x10:
        return 0x800;
    case 0x11:
    case 0x12:
    case 0x16:
    case 0x3C:
        return 0x200;
    case 0x15:
        return 0x301;
    case 0x2C:
    case 0x98:
    case 0x9D:
    case 0x9E:
    case 0x9F:
    case 0xA0:
    case 0xA2:
    case 0xA3:
        return 0x800;
    case 0xA1:
        return 0xB01;
    case 0x87:
    case 0x99:
    case 0x9A:
    case 0x9B:
    case 0x9C:
        return 0xA00;
    case 0x18:
        return 0xB01;
    case 0x1B:
        return 0x200;
    case 0x95:
        return 0x200;
    case 0x38:
        return 0x800;
    case 0x3D:
        return 0xA00;
    case 0x2B:
    case 0x40:
    case 0x42:
    case 0x50:
    case 0x51:
        return 0x200;
    case 0x4E:
        return 0x1800;
    case 0x57:
        return 0x901;
    case 0x59:
        return 0x101;
    case 0xA6:
        return 0x901;
    case 0xA7:
        return 0x901;
    case 0x54:
        return 0x101;
    case 0xA8:
        return 0x901;
    case 0x5A:
        return 0xB01;
    case 0x5B:
        return 0x1B01;
    case 0x5D:
        return 0x1800;
    case 0x5E:
        return 0x301;
    case 0x3B:
        return 0x301;
    case 0xA4:
        return 0xB01;
    case 0xA5:
        return 0xB01;
    case 0x60:
        return 0x901;
    case 0x62:
        return 0x1800;
    case 0x66:
        return 0x1A00;
    case 0x67:
        return 0x301;
    case 0x6C:
        return 0xB01;
    case 0x97:
        return 0x800;
    case 0x6D:
        return 0x301;
    case 0x6E:
        return 0x301;
    case 0x71:
        return 0x200;
    case 0x73:
        return 0x101;
    case 0x74:
        return 0x1A00;
    case 0x77:
        return 0x901;
    case 0x78:
    case 0x8D:
        return 0x1901;
    case 0x7A:
        return 0x101;
    case 0x7B:
        return 0x301;
    case 0x7D:
        return 0x1901;
    case 0x7E:
        return 0x101;
    case 0x4C:
        return 0x1901;
    case 0x7C:
        return 0x1901;
    case 0x80:
        return 0x1901;
    case 0x81:
        return 0x1800;
    case 0x82:
        return 0xB01;
    case 0xA9:
        return 0x101;
    case 0xAA:
    case 0xAC:
        return 0x901;
    case 0xAB:
        return 0x800;
    case 0x89:
        return 0x101;
    case 0x8A:
        return 0x101;
    case 0xAD:
        return 0x800;
    case 0xAE:
        return 0x800;
    case 0x8E:
        return 0x1901;
    case 0x84:
        return 0x1901;
    case 0x85:
        return 0x1901;
    case 0x86:
        return 0xA00;
    case 0x88:
        ret = 0x1800;
        /* fallthrough */
    default:
        return ret;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000F8E8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8000FB60(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    s16 temp_t3;

    D_800A333C_A3F3C = 3;
    D_800A3348_A3F48 = 1;
    D_800A3340_A3F40 = arg0;
    D_800A3344_A3F44 = (s32)(*(u8 **)(obj + 0x40) + 4);
    if (*(void **)(obj + 0x7C) != NULL) {
        func_80010430();
    }
    if (*(void **)(*(u8 **)(obj + 0x40) + 0xD4) != NULL) {
        func_80011200(arg0, arg1);
    }
    temp_t3 = *(s16 *)(obj + 0x48);
    switch (temp_t3) {
    case 0x2:
        sidekickControl(arg0, arg1);
        break;
    case 0x4:
        fishControl(arg0, arg1);
        break;
    case 0x14:
        fishfoodControl(arg0, arg1);
        break;
    case 0x4D:
        keyControl(arg0, arg1);
        break;
    case 0x22:
        animControl(arg0, arg1);
        break;
    case 0x8:
        exitControl(arg0, arg1);
        break;
    case 0x7:
        doorControl(arg0, arg1);
        break;
    case 0x43:
        doorSwitchControl(arg0, arg1);
        break;
    case 0x3C:
        buoyControl(arg0, arg1);
        break;
    case 0x9:
        trackChangeFog(arg0, arg1);
        break;
    case 0xA:
        skyControl(arg0, arg1);
        break;
    case 0x39:
        spranimControl(arg0, arg1);
        break;
    case 0x3E:
        spranimOnceControl(arg0, arg1);
        break;
    case 0x23:
        texscrollControl(arg0, arg1);
        break;
    case 0x10:
        weatherControl(arg0, arg1);
        break;
    case 0xB:
        animshipControl(arg0, arg1);
        break;
    case 0x33:
        animplayerControl(arg0, arg1);
        break;
    case 0x34:
        animtriggerControl(arg0, arg1);
        break;
    case 0x2E:
    case 0x2F:
    case 0x32:
        animobjControl(arg0, arg1);
        break;
    case 0x5F:
    case 0x96:
        butterflyControl(arg0, arg1);
        break;
    case 0x93:
        animdroidControl(arg0, arg1);
        break;
    case 0x16:
        hitBridgeControl(arg0, arg1);
        break;
    case 0x37:
        bubblerControl(arg0, arg1);
        break;
    case 0x1F:
        effectboxControl(arg0, arg1);
        break;
    case 0x20:
        frogControl(arg0, arg1);
        break;
    case 0x21:
        rangetriggerControl(arg0, arg1);
        break;
    case 0x15:
        laserboltControl(arg0, arg1);
        break;
    case 0x27:
        explosionControl(arg0, arg1);
        break;
    case 0xA2:
        shrinkbeamControl(arg0, arg1);
        break;
    case 0x98:
        trackbeamControl(arg0, arg1);
        break;
    case 0x45:
        missileControl(arg0, arg1);
        break;
    case 0x9E:
        CyborgMissileControl(arg0, arg1);
        break;
    case 0x9F:
        TwinkleControl(arg0, arg1);
        break;
    case 0xA0:
        grenadeControl(arg0, arg1);
        break;
    case 0x9B:
        zombieFlobControl(arg0, arg1);
        break;
    case 0xA1:
        ShirukenControl(arg0, arg1);
        break;
    case 0x99:
        MaggotBombControl(arg0, arg1);
        break;
    case 0x87:
        FlowerBoltControl(arg0, arg1);
        break;
    case 0x9A:
        LaserBeamControl(arg0, arg1);
        break;
    case 0x9D:
        SpiderSpitControl(arg0, arg1);
        break;
    case 0x9C:
        SquadronControl(arg0, arg1);
        break;
    case 0x17:
        SquaddieControl(arg0, arg1);
        break;
    case 0x18:
        AIJunctionControl(arg0, arg1);
        break;
    case 0x1B:
        AIPointControl(arg0, arg1);
        break;
    case 0x95:
        spinlightControl(arg0, arg1);
        break;
    case 0x38:
        FatBobShockWaveControl(arg0, arg1);
        break;
    case 0x28:
        shockwaveControl(arg0, arg1);
        break;
    case 0x29:
        weaponPickupControl(arg0, arg1);
        break;
    case 0x26:
        expspriteControl(arg0, arg1);
        break;
    case 0x2B:
        healthPickupControl(arg0, arg1);
        break;
    case 0x3D:
        ammoPickupControl(arg0, arg1);
        break;
    case 0x42:
        beamControl(arg0, arg1);
        break;
    case 0x44:
        shardClusterControl(arg0, arg1);
        break;
    case 0x24:
        electrocutionControl(arg0, arg1);
        break;
    case 0x25:
        menuCamControl(arg0, arg1);
        break;
    case 0x40:
        severedLimbControl(arg0, arg1);
        break;
    case 0x46:
        menuCamFocusControl(arg0, arg1);
        break;
    case 0x47:
        menuCamFacingTVControl(arg0, arg1);
        break;
    case 0x48:
        refuelControl(arg0, arg1);
        break;
    case 0x49:
        dropletControl(arg0, arg1);
        break;
    case 0x4A:
        splashControl(arg0, arg1);
        break;
    case 0x4B:
        waterbubbleControl(arg0, arg1);
        break;
    case 0x4C:
        glassControl(arg0, arg1);
        break;
    case 0x4E:
        invincibilityControl(arg0, arg1);
        break;
    case 0x50:
        invisibilityControl(arg0, arg1);
        break;
    case 0x51:
        invincibilityShieldControl(arg0, arg1);
        break;
    case 0x52:
        teleportEffectControl(arg0, arg1);
        break;
    case 0x58:
        fireExplosionControl(arg0, arg1);
        break;
    case 0x53:
        smokingfireControl(arg0, arg1);
        break;
    case 0x55:
        fireringControl(arg0, arg1);
        break;
    case 0x56:
        twisterControl(arg0, arg1);
        break;
    case 0xA3:
        grubControl(arg0, arg1);
        break;
    case 0x57:
        mineControl(arg0, arg1);
        break;
    case 0xA6:
    case 0xA7:
        hitfragmentControl(arg0, arg1);
        break;
    case 0x54:
    case 0xA8:
        flareControl(arg0, arg1);
        break;
    case 0x59:
        mrhintsControl(arg0, arg1);
        break;
    case 0x5A:
        multiCharArmControl(arg0, arg1);
        break;
    case 0x5C:
        damagecrateControl(arg0, arg1);
        break;
    case 0x5B:
        sidekickpadControl(arg0, arg1);
        break;
    case 0x5D:
        totemPoleControl(arg0, arg1);
        break;
    case 0x8D:
        floatingControl(arg0, arg1);
        break;
    case 0x5E:
        collectableControl(arg0, arg1);
        break;
    case 0x3B:
        mainclusterControl(arg0, arg1);
        break;
    case 0xA4:
        smallclusterControl(arg0, arg1);
        break;
    case 0xA5:
        animswitchControl(arg0, arg1);
        break;
    case 0x60:
        chestControl(arg0, arg1);
        break;
    case 0x62:
        cutcameraControl(arg0, arg1);
        break;
    case 0x64:
        fireflyControl(arg0, arg1);
        break;
    case 0x63:
        robottargetControl(arg0, arg1);
        break;
    case 0x66:
        robotcollectableControl(arg0, arg1);
        break;
    case 0x67:
        robotcheckControl(arg0, arg1);
        break;
    case 0x68:
        dopplerPointControl(arg0, arg1);
        break;
    case 0x69:
        mizarControl(arg0, arg1);
        break;
    case 0x6C:
        rockstormControl(arg0, arg1);
        break;
    case 0x97:
        robotTokenControl(arg0, arg1);
        break;
    case 0x6D:
        flyingdebrisControl(arg0, arg1);
        break;
    case 0x6E:
        targetswitchControl(arg0, arg1);
        break;
    case 0x6F:
        craterControl(arg0, arg1);
        break;
    case 0x71:
        windowfxControl(arg0, arg1);
        break;
    case 0x72:
        flagtargetControl(arg0, arg1);
        break;
    case 0x74:
        flagtriggerControl(arg0, arg1);
        break;
    case 0x75:
        multitargetControl(arg0, arg1);
        break;
    case 0x77:
        multiptargetControl(arg0, arg1);
        break;
    case 0x78:
        racepickupControl(arg0, arg1);
        break;
    case 0x7A:
        raceobstacleControl(arg0, arg1);
        break;
    case 0x7B:
        transformerControl(arg0, arg1);
        break;
    case 0x7C:
        terminalControl(arg0, arg1);
        break;
    case 0x7D:
        lightShowControl(arg0, arg1);
        break;
    case 0x7F:
        nightvisionpadControl(arg0, arg1);
        break;
    case 0x80:
        blastdoorControl(arg0, arg1);
        break;
    case 0x81:
        mantisControl(arg0, arg1);
        break;
    case 0x82:
        mantismissileControl(arg0, arg1);
        break;
    case 0xA9:
        mantisboltControl(arg0, arg1);
        break;
    case 0xAA:
        mantisrockControl(arg0, arg1);
        break;
    case 0xAC:
        mizarFireBallControl(arg0, arg1);
        break;
    case 0xAB:
        mizarWingBitControl(arg0, arg1);
        break;
    case 0x89:
    case 0x8A:
        mizarEyeBeamControl(arg0, arg1);
        break;
    case 0xAD:
        mizarImpactControl(arg0, arg1);
        break;
    case 0x8B:
        mizarElectroControl(arg0, arg1);
        break;
    case 0xAE:
        mizarMonolithControl(arg0, arg1);
        break;
    case 0x8E:
        spotlightControl(arg0, arg1);
        break;
    case 0x84:
        hoovertankControl(arg0, arg1);
        break;
    case 0x85:
        hoovergemControl(arg0, arg1);
        break;
    case 0x86:
        regionidControl(arg0, arg1);
        break;
    case 0x88:
        arcadeControl(arg0, arg1);
        break;
    case 0x8F:
        fireworkControl(arg0, arg1);
        break;
    case 0x91:
        mizarDeathControl(arg0, arg1);
        break;
    case 0x92:
        mrHintsEventHandler(arg0, arg1);
        break;
    }
    D_800A3348_A3F48 = 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_8000FB60.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-object physics/collision step. State block at obj+0x7C:
//   +0x00 u8 flags (0x1 = on ground, 0x2 = hit/active, 0x4 = riding platform, 0x8 = slide mode)
//   +0x02 s16 hit marker, +0x04/+0x08/+0x0C hit normal copy, +0x10 f32 surface height,
//   +0x14 f32 speed, +0x18 sound mask ptr, +0x1C platform / surface ptr, +0x20 s32 (trackMakePolylist arg)
void func_80010430(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st = *(u8 **)(obj + 0x7C);
    f32 *pos = (f32 *)(obj + 0xC);
    f32 *vel = (f32 *)(obj + 0x1C);
    f32 dt = (f32)arg1;
    f32 startPos[3];
    f32 endPos[3];
    f32 delta[3];
    f32 worldPos[3];
    struct {
        s16 *poly;       /* 0xB8: surface out-param of trackGetIntersect */
        f32 nx;          /* 0xBC: hit normal */
        f32 ny;          /* 0xC0 */
        f32 nz;          /* 0xC4 */
        u8 pad[0x14];    /* 0xC8..0xDB: rest of the hit record, not visible in this function */
        u8 surfMode;     /* 0xDC: compared against 3 */
        u8 surfFlags;    /* 0xDD: bit 0x80 blocks bouncing */
    } hit;

    *(s16 *)(st + 0x2) = 0;

    if (st[0] & 2) {
        /* riding a platform */
        if (st[0] & 4) {
            u8 *plat = *(u8 **)(st + 0x1C);
            u8 *pdata = *(u8 **)(plat + 0x5C);

            if (*(s16 *)(pdata + 0x12C) != 0) {
                mathMtxXFMF((f32 (*)[4])(pdata + ((pdata[0x12B] ^ 1) << 6)), pos[0], pos[1], pos[2],
                            &delta[0], &delta[1], &delta[2]);
                mathMtxXFMF((f32 (*)[4])(pdata + ((pdata[0x12B] << 6) + 0x80)), delta[0], delta[1], delta[2],
                            &worldPos[0], &worldPos[1], &worldPos[2]);
                delta[0] = worldPos[0] - pos[0];
                delta[1] = worldPos[1] - pos[1];
                delta[2] = worldPos[2] - pos[2];
                *(s16 *)(obj + 0x0) = *(s16 *)(obj + 0x0) + *(s16 *)plat - *(s16 *)(pdata + 0x128);
                objMoveXYZ(obj, delta[0], delta[1], delta[2]);
            }
        }
    } else {
        /* free flight */
        u8 *def = *(u8 **)(obj + 0x40);
        u8 *bnd = *(u8 **)(def + 0xD0);
        u8 *coll = *(u8 **)(def + 0x50);
        f32 accel;
        f32 maxSpeed;
        f32 radius;
        f32 groundClear;
        u16 collFlags;
        s32 hitResult;
        s32 v0 = 0;
        s32 v1 = 0;

        st[0] &= 0xFB;
        *(void **)(st + 0x1C) = NULL;

        if (st[0] & 8) {
            accel = 0.0f;
            maxSpeed = *(f32 *)(bnd + 0x4);
        } else if (st[0] & 1) {
            accel = -*(f32 *)(bnd + 0x8);
            maxSpeed = *(f32 *)(bnd + 0xC);
        } else {
            accel = -*(f32 *)(bnd + 0x0);
            maxSpeed = *(f32 *)(bnd + 0x4);
        }

        /* start = collision offset + pos; end = start + vel*dt (+ gravity term on Y) */
        startPos[0] = *(f32 *)(coll + 0x0) + pos[0];
        startPos[1] = *(f32 *)(coll + 0x4) + pos[1];
        startPos[2] = *(f32 *)(coll + 0x8) + pos[2];
        endPos[0] = startPos[0] + vel[0] * dt;
        endPos[1] = startPos[1] + (vel[1] * dt + 0.5f * accel * dt * dt);
        endPos[2] = startPos[2] + vel[2] * dt;
        radius = *(f32 *)(coll + 0xC);
        collFlags = coll[0x10];

        trackMakePolylist(dt, 1, startPos, endPos, &radius, 0xCE002000, 0, *(s32 *)(st + 0x20));
        hitResult = trackGetIntersect(obj, startPos, endPos, radius, collFlags, &hit.poly);

        delta[0] = endPos[0] - startPos[0];
        delta[1] = endPos[1] - startPos[1];
        delta[2] = endPos[2] - startPos[2];
        objMoveXYZ(obj, delta[0], delta[1], delta[2]);

        if (!(st[0] & 8)) {
            vel[1] = vel[1] + accel * dt;
        }

        *(f32 *)(st + 0x14) = sqrtf(vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2]);

        groundClear = endPos[1] - radius;
        if ((trackPolyHeight(pos[0], pos[2], st + 0x10, 0x2000) & 0x2000) &&
            (groundClear < *(f32 *)(st + 0x10))) {
            maxSpeed = *(f32 *)(bnd + 0xC);
            if (!(st[0] & 1)) {
                st[0] |= 1;
                v1 = 0;
                if (*(u16 *)(bnd + 0x1C) != 0) {
                    if (*(void **)(st + 0x18) == NULL) {
                        amSndPlayXYZ(*(u16 *)(bnd + 0x1C), pos[0], pos[1], pos[2], 4, st + 0x18);
                        v1 = 1;
                        if (*(void **)(st + 0x18) != NULL) {
                            f32 vol = *(f32 *)(st + 0x14) / *(f32 *)(bnd + 0x4);
                            s32 volI;

                            if (vol > 1.0f) {
                                vol = 1.0f;
                            }
                            volI = (s32)(127.0f * vol);
                            if (volI < 0) {
                                volI = -1;
                            }
                            amSndSetVolXYZ(*(SoundMask **)(st + 0x18), (u8)volI);
                        }
                    }
                }
                if (*(s32 *)(bnd + 0x10) != 0) {
                    s16 savedS2 = *(s16 *)(obj + 0x2);
                    s16 savedS4 = *(s16 *)(obj + 0x4);
                    s32 savedB84 = *(s32 *)(obj + 0x84);
                    f32 savedY = pos[1];

                    *(s16 *)(obj + 0x2) = 0;
                    *(s16 *)(obj + 0x4) = 0;
                    *(s32 *)(obj + 0x84) = *(s32 *)(bnd + 0x10);
                    pos[1] = *(f32 *)(st + 0x10);
                    partUpdateTriggers(obj, arg1);
                    pos[1] = savedY;
                    *(s16 *)(obj + 0x2) = savedS2;
                    v1 |= 4;
                    *(s16 *)(obj + 0x4) = savedS4;
                    *(s32 *)(obj + 0x84) = savedB84;
                }
                squadsAddInterestingEvent(obj, (s16)(s32)pos[0], (s16)(s32)pos[1], (s16)(s32)pos[2], v1, 1, 0x47);
            }
        } else {
            st[0] &= 0xFE;
        }

        /* drag when above the speed cap */
        if (maxSpeed < *(f32 *)(st + 0x14)) {
            f32 drag = Powerf(0.92f, arg1);

            vel[0] = vel[0] * drag;
            vel[1] = vel[1] * drag;
            vel[2] = vel[2] * drag;
            *(f32 *)(st + 0x14) = sqrtf(vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2]);
        }

        if (hitResult != 0) {
            f32 speed;
            f32 dot;
            f32 k;

            *(f32 *)(st + 0x4) = hit.nx;
            *(f32 *)(st + 0x8) = hit.ny;
            *(s16 *)(st + 0x2) = 1;
            *(f32 *)(st + 0xC) = hit.nz;

            speed = *(f32 *)(st + 0x14);
            if (*(f32 *)(bnd + 0x18) == 0.0f || (hit.surfFlags & 0x80) || speed == 0.0f) {
                vel[0] = 0.0f;
                vel[1] = 0.0f;
                vel[2] = 0.0f;
                v0 = 1;
                st[0] |= 2;
            } else {
                vel[0] = vel[0] / speed;
                vel[1] = vel[1] / speed;
                vel[2] = vel[2] / speed;
                *(f32 *)(st + 0x14) = speed * *(f32 *)(bnd + 0x18);

                /* reflect velocity about the surface normal */
                dot = (hit.nx * vel[0] + hit.ny * vel[1]) + hit.nz * vel[2];
                k = -dot;
                k = k + k;
                vel[0] = (vel[0] + hit.nx * k) * *(f32 *)(st + 0x14);
                vel[1] = (vel[1] + hit.ny * k) * *(f32 *)(st + 0x14);
                vel[2] = (vel[2] + hit.nz * k) * *(f32 *)(st + 0x14);

                if (sqrtf(vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2]) < 1.0f) {
                    if (hit.surfMode == 3) {
                        /* slide: tangent = cross(normal, helper), scaled to 8.0 */
                        f32 tn[3];
                        f32 tc[3];
                        f32 tlen;

                        tn[0] = hit.ny * hit.nz - 0.0f * hit.nz;
                        tn[1] = hit.nz * hit.nx - hit.nz * hit.nx;
                        tn[2] = 0.0f * hit.nx - hit.nx * hit.ny;
                        tc[0] = tn[1] * hit.nz - hit.ny * tn[2];
                        tc[1] = tn[2] * hit.nx - hit.nz * tn[0];
                        tc[2] = tn[0] * hit.ny - hit.nx * tn[1];
                        tlen = sqrtf(tc[0] * tc[0] + tc[1] * tc[1] + tc[2] * tc[2]);
                        vel[0] = (tc[0] / tlen) * 8.0f;
                        vel[1] = (tc[1] / tlen) * 8.0f;
                        vel[2] = (tc[2] / tlen) * 8.0f;
                        st[0] |= 8;
                    } else if (hit.ny < 0.707f) {
                        vel[0] = hit.nx;
                        vel[1] = hit.ny;
                        vel[2] = hit.nz;
                    } else {
                        vel[0] = 0.0f;
                        vel[1] = 0.0f;
                        vel[2] = 0.0f;
                        *(f32 *)(st + 0x14) = 0.0f;
                        st[0] &= 0xF7;
                        if (!(collFlags & 0x10)) {
                            st[0] = st[0] | 2;
                            if (hit.poly != NULL) {
                                st[0] |= 4;
                                *(s16 **)(st + 0x1C) = hit.poly;
                            }
                        }
                    }
                } else {
                    st[0] &= 0xF7;
                    v0 = 1;
                }
            }

            if (v0 != 0) {
                v1 = 0;
                if (*(u16 *)(bnd + 0x1E) != 0 && !(st[0] & 1) && *(void **)(st + 0x18) == NULL) {
                    amSndPlayXYZ(*(u16 *)(bnd + 0x1E), pos[0], pos[1], pos[2], 4, st + 0x18);
                    v1 = 1;
                    if (*(void **)(st + 0x18) != NULL) {
                        f32 vol = *(f32 *)(st + 0x14) / *(f32 *)(bnd + 0x4);
                        s32 volI;

                        if (vol > 1.0f) {
                            vol = 1.0f;
                        }
                        volI = (s32)(127.0f * vol);
                        if (volI < 0) {
                            volI = -1;
                        }
                        amSndSetVolXYZ(*(SoundMask **)(st + 0x18), (u8)volI);
                        v1 = 1;
                    }
                }
                squadsAddInterestingEvent(obj, (s16)(s32)pos[0], (s16)(s32)pos[1], (s16)(s32)pos[2], v1, 1, 0x47);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80010430.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80011200(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *s2 = *(u8 **)(*(u8 **)(obj + 0x40) + 0xD4);
    u8 *animdef = **(u8 ***)(*(s32 *)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
    u8 *ent;
    s32 sp40 = *(s16 *)(*(u8 **)(animdef + 0x5C) + (*(s8 *)(obj + 0x3B) * 2));
    s32 wrap;
    s32 var_s3;
    f32 var_f0;
    f32 var_f4;
    f32 var_f20 = *(f32 *)(obj + 0xAC);
    f32 var_f22 = *(f32 *)(obj + 0x28);
    u16 temp_t9;
    s16 temp_v0;
    s16 temp_v0_2;

    if (*(f32 *)(obj + 0xB0) < 0.0f) {
        var_f22 = 1.0f - var_f22;
        var_f20 = 1.0f - var_f20;
    }
    if (var_f22 < var_f20) {
        wrap = 1;
        var_f22 += 1.0f;
    } else {
        wrap = 0;
    }
    ent = s2 + 4;
    var_s3 = 0;
    if (*(s16 *)(s2 + 2) > 0) {
        do {
            if (sp40 == *(u16 *)(ent + 0)) {
                temp_t9 = *(u16 *)(ent + 2);
                var_f4 = (f32) temp_t9;
                var_f0 = var_f4 * 0.000015259022f;
                if ((wrap != 0) && (var_f0 <= var_f20)) {
                    var_f0 += 1.0f;
                }
                if ((var_f20 <= var_f0) && (var_f0 <= var_f22) && (var_f20 != var_f22)) {
                    temp_v0 = *(s16 *)(obj + 0x48);
                    if (temp_v0 == 0x18) {
                        FlopsyDogFoodGone(arg0, *(u16 *)(ent + 4));
                    } else if (temp_v0 == 0x33) {
                        temp_v0_2 = *(s16 *)(*(u8 **)(obj + 0x68) + 0x4C);
                        switch (temp_v0_2) {
                        case 0xC5:
                        case 0x118:
                            animGirlEventHandler(arg0, *(u16 *)(ent + 4));
                            break;
                        case 0xC6:
                        case 0x119:
                            animBoyEventHandler(arg0, *(u16 *)(ent + 4));
                            break;
                        case 0xC4:
                        case 0x11A:
                        case 0x1F6:
                        case 0x2AE:
                        case 0x2BA:
                            animDogEventHandler(arg0, *(u16 *)(ent + 4));
                            break;
                        }
                    } else if (temp_v0 == 0x5A) {
                        SquaddieAnimEventHandler(arg0, *(u16 *)(ent + 4));
                    }
                }
            }
            var_s3 += 1;
            ent += 6;
        } while (var_s3 < *(s16 *)(s2 + 2));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80011200.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objAnimDframe(void *arg0, f32 arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *inst = *(u8 **)(*(s32 *)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
    f32 temp_f0;
    f32 temp_f0_2;
    s32 var_v1 = 0;

    temp_f0 = *(f32 *)(obj + 0x28);
    *(f32 *)(obj + 0x28) = temp_f0 + (arg1 * arg2);
    *(f32 *)(obj + 0xAC) = temp_f0;
    temp_f0_2 = *(f32 *)(obj + 0x28);
    *(f32 *)(obj + 0xB0) = arg1;
    if (temp_f0_2 >= 1.0f) {
        if (*(s8 *)(inst + 0x08) != 0) {
            do {
                *(f32 *)(obj + 0x28) = *(f32 *)(obj + 0x28) - 1.0f;
            } while (*(f32 *)(obj + 0x28) >= 1.0f);
            return 1;
        }
        *(f32 *)(obj + 0x28) = 1.0f;
        return 1;
    }
    if (temp_f0_2 < 0.0f) {
        var_v1 = 1;
        if (*(s8 *)(inst + 0x08) != 0) {
            do {
                *(f32 *)(obj + 0x28) = *(f32 *)(obj + 0x28) + 1.0f;
            } while (*(f32 *)(obj + 0x28) < 0.0f);
        } else {
            *(f32 *)(obj + 0x28) = 0.0f;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objAnimDframe.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objAnimSetMove(void *arg0, s8 arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *inst;
    u8 *def;
    u8 *frame;
    u8 *keys;
    f32 var_f12 = arg2;
    s8 var_a2 = arg1;
    s8 temp_v0;
    s32 temp_t3;
    s32 temp_t5;
    s32 temp_a0_2;

    if (var_f12 > 1.0f) {
        var_f12 = 1.0f;
    } else if (var_f12 < 0.0f) {
        var_f12 = 0.0f;
    }
    *(f32 *)(obj + 0x28) = var_f12;
    inst = *(u8 **)(*(s32 *)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
    def = *(u8 **)(inst + 0x00);
    if (*(s8 *)(def + 0x4E) != 0) {
        *(u16 *)(inst + 0x26) = *(u16 *)(inst + 0x24);
        *(f32 *)(inst + 0x2C) = *(f32 *)(inst + 0x28);
        *(f32 *)(inst + 0x3C) = *(f32 *)(inst + 0x38);
        *(f32 *)(inst + 0x34) = *(f32 *)(inst + 0x30);
        *(f32 *)(inst + 0x44) = *(f32 *)(inst + 0x40);
        *(void **)(inst + 0x64) = *(void **)(inst + 0x60);
        *(s8 *)(inst + 0x09) = *(s8 *)(inst + 0x08);
        temp_v0 = *(s8 *)(def + 0x4E);
        if (var_a2 >= temp_v0) {
            var_a2 = temp_v0 - 1;
        }
        if (var_a2 < 0) {
            var_a2 = 0;
        }
        *(s8 *)(obj + 0x3B) = var_a2;
        *(u16 *)(inst + 0x24) = (u16) var_a2;
        if (*(s32 *)(def + 0x64) == 0) {
            frame = *(u8 **)(*(s32 *)(def + 0x50) + ((var_a2 & 0xFFFF) * 4));
            keys = frame + 8;
            *(u8 **)(inst + 0x60) = keys;
            *(s8 *)(inst + 0x08) = (s8) (*(s8 *)(frame + 1) & 0xF0);
            *(f32 *)(inst + 0x38) = (f32) keys[3];
            if (*(s8 *)(inst + 0x08) == 0) {
                *(f32 *)(inst + 0x38) = *(f32 *)(inst + 0x38) - 1.0f;
            }
            temp_t3 = *(s8 *)(frame + 1) & 0xF;
            if (temp_t3 != 0) {
                *(s16 *)(inst + 0x5E) = 0x3FF;
                *(s16 *)(inst + 0x5C) = (s16) (0x3FF / temp_t3);
            }
            *(f32 *)(inst + 0x28) = *(f32 *)(inst + 0x38) * var_f12;
        } else {
            temp_a0_2 = *(s32 *)(inst + 0x84);
            if (temp_a0_2 != 0) {
                modFreeAnim(var_f12, temp_a0_2, def, var_a2);
            }
            temp_t5 = *(s32 *)(inst + 0x80);
            *(s32 *)(inst + 0x80) = 0;
            *(s16 *)(inst + 0x8A) = *(s16 *)(inst + 0x88);
            *(s32 *)(inst + 0x84) = temp_t5;
        }
        *(f32 *)(inst + 0x30) = 0.0f;
        *(f32 *)(inst + 0x40) = 0.0f;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objAnimSetMove.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objAnimSetFrame(void *arg0, f32 arg1) {
    u8 *obj = (u8 *)arg0;
    f32 val;

    if (arg1 > 0.999f) {
        val = 0.999f;
    } else if (arg1 < 0.0f) {
        val = 0.0f;
    } else {
        val = arg1;
    }
    *(f32 *)(obj + 0x28) = val;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objAnimSetFrame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objCreateBonusItem(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    /* RomDefHeader-style buffer: s16 id @0, u8 size @2, u8 flag @3,
       s16 x @4, s16 y @6, s16 z @8, s8 sub @0xA, s8 @0xB */
    u8 romdef[0x0C] = { 0 };
    s32 temp_t6 = arg3 & 0xFF;
    s32 temp_t0;
    s32 var_a3;
    u8 *obj;
    u8 *flags;

    if (temp_t6 < 0x28) {
        if (temp_t6 >= 0x14) {
            if (temp_t6 == 0x17) {
                *(s16 *)(romdef + 0) = 0xE9;
                romdef[0xA] = 0;
            } else {
                *(s16 *)(romdef + 0) = 0xA9;
                romdef[0xA] = (u8) (temp_t6 - 0x14);
            }
            romdef[2] = 0xC;
            romdef[3] = 1;
            romdef[0xB] = 0;
            *(s16 *)(romdef + 4) = (s16)(s32) arg0;
            *(s16 *)(romdef + 6) = (s16)(s32) arg1;
            *(s16 *)(romdef + 8) = (s16)(s32) arg2;
            obj = objSetupObject((RomDefHeader *) romdef, 1);
            if (obj != NULL) {
                flags = *(u8 **)(obj + 0x7C);
                *(s32 *)(obj + 0x3C) = 0;
                if (flags != NULL) {
                    *(f32 *)(obj + 0x20) = 1.0f;
                    *flags &= 0xFFFD;
                }
            }
        } else if (temp_t6 > 0) {
            temp_t0 = (temp_t6 - 1) & 0xFF;
            var_a3 = temp_t0;
            if (temp_t0 >= 0x10) {
                var_a3 = 0xF;
            }
            *(s16 *)(romdef + 0) = weaponPowerUpObjects[var_a3];
            romdef[2] = 0xC;
            romdef[0xA] = 0;
            romdef[0xB] = 0;
            *(s16 *)(romdef + 4) = (s16)(s32) arg0;
            *(s16 *)(romdef + 6) = (s16)(s32) arg1;
            *(s16 *)(romdef + 8) = (s16)(s32) arg2;
            obj = objSetupObject((RomDefHeader *) romdef, 1);
            if (obj != NULL) {
                *(s32 *)(obj + 0x3C) = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objCreateBonusItem.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void GetRomlistInfo(u32 *arg0, u32 *arg1, s32 arg2) {
    *arg0 = D_800F2CD8_B17C8[arg2];
    *arg1 = D_800F2CE0_B17D0[arg2];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/GetRomlistInfo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objRegisterDependancy(void *arg0, void *arg1) {
    u8 *cur;
    u8 *next;

    if (arg1 == NULL) {
        return;
    }
    cur = (u8 *)arg1;
    while (cur != (u8 *)arg0) {
        cur = *(u8 **)(cur + 0xA8);
        if (cur == NULL) {
            *(void **)((u8 *)arg0 + 0xA4) = arg1;
            next = *(u8 **)((u8 *)arg1 + 0xA8);
            *(u8 **)((u8 *)arg0 + 0xA8) = next;
            if (next != NULL) {
                *(void **)(next + 0xA4) = arg0;
            }
            *(void **)((u8 *)arg1 + 0xA8) = arg0;
            return;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objRegisterDependancy.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objRemoveDependancy(void *arg0) {
    u8 *prev;
    u8 *next;

    next = *(u8 **)((u8 *)arg0 + 0xA8);
    if (next != NULL) {
        *(u8 **)(next + 0xA4) = *(u8 **)((u8 *)arg0 + 0xA4);
    }
    prev = *(u8 **)((u8 *)arg0 + 0xA4);
    if (prev != NULL) {
        *(u8 **)(prev + 0xA8) = *(u8 **)((u8 *)arg0 + 0xA8);
    }
    *(void **)((u8 *)arg0 + 0xA8) = NULL;
    *(void **)((u8 *)arg0 + 0xA4) = NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objRemoveDependancy.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80011AD4(Object *arg0) {
    Object *prev;
    Object *cur;
    Object *next;
    Object *parent;
    s32 prevIsNull;
    s32 removeIt;
    s32 behaviorId;
    u8 *racer;

    behaviorId = arg0->behaviorId;
    if (behaviorId == 1 || behaviorId == 0x18 || behaviorId == 0x4D || behaviorId == 0x40) {
        squadsCheckEnemyPointers(arg0);
        behaviorId = arg0->behaviorId;
    }
    if (behaviorId == 0x9B || behaviorId == 0xA1) {
        squadsCheckGrenades(arg0);
    }
    prev = *(Object **)((u8 *)arg0 + 0xA4);
    cur = *(Object **)((u8 *)arg0 + 0xA8);
    prevIsNull = (prev == NULL);
    if (prev != NULL) {
        *(Object **)((u8 *)prev + 0xA8) = cur;
    }
    if (cur != NULL) {
        *(Object **)((u8 *)cur + 0xA4) = prev;
    }
    *(void **)((u8 *)arg0 + 0xA4) = NULL;
    *(void **)((u8 *)arg0 + 0xA8) = NULL;

    while (cur != NULL) {
        removeIt = 0;
        racer = (u8 *)cur->racer;
        switch (cur->behaviorId) {
        case 0x99:
            if ((s32)arg0 == *(s32 *)(racer + 4)) {
                *(s32 *)(racer + 4) = 0;
                removeIt = 1;
            }
            break;
        case 0x9E:
            if ((s32)arg0 == *(s32 *)(racer + 0x24)) {
                *(s32 *)(racer + 0x24) = 0;
                removeIt = 1;
            }
            break;
        case 0x9B:
        case 0xA1:
            if (prevIsNull) {
                removeIt = 1;
                *(s16 *)(racer + 8) = 0;
                *(u8 *)(racer + 0xD) = 0;
            }
            break;
        case 0x25:
            removeIt = 1;
            *(u8 *)(racer + 0x23) = 1;
            break;
        case 0x18:
            parent = *(Object **)(racer + 0x24);
            if (*(u16 *)((u8 *)parent->racer + 0x2C) == 0x112) {
                mineRemove(cur, 0);
                removeIt = 1;
            } else if (*(u16 *)((u8 *)parent->racer + 0x2C) == 0xE1) {
                removeIt = 1;
                if (*(u8 *)(racer + 0x1A) == 0x14) {
                    *(u8 *)(racer + 0x1B) = 5;
                }
            }
            break;
        }
        prev = *(Object **)((u8 *)cur + 0xA4);
        next = *(Object **)((u8 *)cur + 0xA8);
        if (removeIt != 0) {
            *(void **)((u8 *)cur + 0xA4) = NULL;
            *(void **)((u8 *)cur + 0xA8) = NULL;
            if (prev != NULL) {
                *(Object **)((u8 *)prev + 0xA8) = next;
            }
            if (next != NULL) {
                *(Object **)((u8 *)next + 0xA4) = prev;
            }
            if (cur->behaviorId == 0x99) {
                D_800A0834_A1434 = (s32)arg0;
                /* sig mismatch: objGetClosestControlType takes 5 args here */
                *(s32 *)(racer + 4) = ((s32 (*)(f32, f32, s32, f32, s32))objGetClosestControlType)(
                    cur->segment.trans.x_position, cur->segment.trans.y_position, removeIt,
                    cur->segment.trans.z_position, 0x18);
                D_800A0834_A1434 = 0;
                if (*(s32 *)(racer + 4) != 0) {
                    objRegisterDependancy(cur, (void *)*(s32 *)(racer + 4));
                }
            }
        }
        cur = next;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80011AD4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 objCutCameraActive(void) {
    s32 i;

    for (i = 0; i < D_800F3910; i++) {
        Object *obj = (Object *)*(s32 *)(playerlist + (i * 4));

        if (*(s32 *)((u8 *)obj->racer + 0x5C0) != 0) {
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objCutCameraActive.s")
#endif

f32 GetRange(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_f0;
    f32 temp_f16;
    f32 temp_f2;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg1 - arg4;
    temp_f16 = arg2 - arg5;
    return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f16 * temp_f16));
}

f32 GetRangeSquared(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f2;

    temp_f2 = arg0 - arg3;
    temp_f16 = arg1 - arg4;
    temp_f18 = arg2 - arg5;
    return (temp_f2 * temp_f2) + (temp_f16 * temp_f16) + (temp_f18 * temp_f18);
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objAddMine(s32 arg0) {
    s32 i;

    if (D_800F3948 >= 8) {
        dropletUpdateAll(D_800F2D20_B1810[0], D_800F2D20_B1810, &D_800F3948);
        for (i = 0; i < 7; i++) {
            D_800F2D20_B1810[i] = D_800F2D20_B1810[i + 1];
        }
        D_800F3948 = 7;
    }
    D_800F2D20_B1810[D_800F3948] = arg0;
    D_800F3948 = D_800F3948 + 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objAddMine.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDeleteMine(s32 arg0) {
    s32 i;
    s32 count;
    s32 last;

    count = D_800F3948;
    i = 0;
    while (i < count && arg0 != D_800F2D20_B1810[i]) {
        i++;
    }
    if (i < count) {
        last = count - 1;
        while (i < last) {
            D_800F2D20_B1810[i] = D_800F2D20_B1810[i + 1];
            i++;
        }
        D_800F3948 = last;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/objDeleteMine.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80011E74_12A74(void) {
    u8 *cams;
    u8 *cam;
    s32 numCams;
    s32 start;
    s32 end;
    s32 first;
    s32 i;
    s32 k;
    Object **list;
    Object *best;
    Object *obj;
    f32 bestDist;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    best = NULL;
    bestDist = 1e10f;
    cams = (u8 *)camGetListPtr();
    numCams = mainGetNumberOfCameras();
    list = objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        obj = list[i];
        if (obj->behaviorId != 0xA7 || *(u8 *)((u8 *)obj->racer + 0x68 + 0x44) == 0) {
            continue;
        }
        if (numCams <= 0) {
            continue;
        }
        ox = obj->segment.trans.x_position;
        oy = obj->segment.trans.y_position;
        oz = obj->segment.trans.z_position;
        first = 0;
        if (numCams & 1) {
            /* odd camera count: camera 0 is checked on its own */
            dx = ox - *(f32 *)(cams + 0xC);
            dy = oy - *(f32 *)(cams + 0x10);
            dz = oz - *(f32 *)(cams + 0x14);
            d = (dx * dx) + (dy * dy) + (dz * dz);
            if (d < bestDist || best == NULL) {
                best = obj;
                bestDist = d;
            }
            first = 1;
        }
        /* remaining cameras are checked in pairs (k, k + 1), 0x4C bytes each */
        for (k = first; k < numCams; k += 2) {
            cam = cams + (k * 0x4C);
            dx = ox - *(f32 *)(cam + 0xC);
            dy = oy - *(f32 *)(cam + 0x10);
            dz = oz - *(f32 *)(cam + 0x14);
            d = (dx * dx) + (dy * dy) + (dz * dz);
            if (d < bestDist || best == NULL) {
                best = obj;
                bestDist = d;
            }
            dx = ox - *(f32 *)(cam + 0x58);
            dy = oy - *(f32 *)(cam + 0x5C);
            dz = oz - *(f32 *)(cam + 0x60);
            d = (dx * dx) + (dy * dy) + (dz * dz);
            if (d < bestDist || best == NULL) {
                best = obj;
                bestDist = d;
            }
        }
    }
    if (best != NULL) {
        if (D_800A089C_A149C == NULL) {
            amSndPlayXYZ(0xFB, best->segment.trans.x_position, best->segment.trans.y_position,
                         best->segment.trans.z_position, 1, &D_800A089C_A149C);
        } else {
            amSndSetXYZ(D_800A089C_A149C, best->segment.trans.x_position, best->segment.trans.y_position,
                        best->segment.trans.z_position);
        }
    } else if (D_800A089C_A149C != NULL) {
        amSndStopXYZ(D_800A089C_A149C);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/objects/func_80011E74_12A74.s")
#endif
#endif
