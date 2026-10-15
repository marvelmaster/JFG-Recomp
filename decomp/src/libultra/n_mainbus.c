#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"
#define SYN_FIELD(p, off, type) (*(type *)((u8 *)(p) + (off)))
struct ALParam_s *__n_allocParam(void);
void _n_freePVoice(void *pvoice);
void n_alEnvmixerParam(void *pvoice, s32 mode, void *param);
s32 _n_timeToSamples(s32 micros);
extern u8 D_80105014_B1754[];
extern u8 D_80105016_B1756[];
void n_alFxInitlpfilter_mono(void *fx, f32 rate);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *n_alMainBusPull(s32 arg0, void *arg1) {
    u32 *cmd;
    void *fx;
    void *bus;
    void *(*handler)(s32, void *, s32);
    s32 i;
    u8 flagA;
    u8 flagB;

    cmd = (u32 *) arg1;
    cmd[0] = 0x020004E0;
    cmd[1] = 0x2E0;
    cmd += 2;
    for (i = 0; i < n_syn->maxAuxBusses; i++) {
        handler = (void *(*)(s32, void *, s32)) SYN_FIELD(n_syn->mainBus, 0x4, void *);
        cmd = (u32 *) handler(arg0, cmd, i);
        flagA = D_80105014_B1754[i];
        flagB = D_80105016_B1756[i];
        if (flagA != 0) {
            if (flagB != 0) {
                cmd[0] = 0x0C008000;
                cmd[1] = 0x07C004E0;
            } else {
                cmd[0] = 0x0C007FFF;
                cmd[1] = 0x07C00650;
            }
            cmd += 2;
        } else {
            if (flagB != 0) {
                cmd[0] = 0x0C008000;
                cmd[1] = 0x07C00650;
            } else {
                cmd[0] = 0x0C007FFF;
                cmd[1] = 0x07C00650;
            }
            cmd += 2;
            cmd[0] = 0x0C007FFF;
            cmd[1] = 0x07C004E0;
            cmd += 2;
        }
        bus = (u8 *) n_syn->auxBus + i * 0x48;
        fx = SYN_FIELD(bus, 0x44, void *);
        if (SYN_FIELD(fx, 0x2, s16) > 0) {
            if (SYN_FIELD(fx, 0x28, s32) != 0) {
                n_alFxInitlpfilter_mono(fx, (f32) n_syn->outputRate);
            }
            cmd[0] = 0x0B000020;
            cmd[1] = osVirtualToPhysical((u8 *) fx + 0x8);
            cmd += 2;
            cmd[0] = 0x0E0004E0;
            cmd[1] = osVirtualToPhysical(SYN_FIELD(fx, 0x2C, void *)) & 0xFFFFFF;
            cmd += 2;
            cmd[0] = 0x0E000650;
            cmd[1] = osVirtualToPhysical(SYN_FIELD(fx, 0x30, void *)) & 0xFFFFFF;
            cmd += 2;
            SYN_FIELD(fx, 0x28, s32) = 0;
        }
    }
    return cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_mainbus/n_alMainBusPull.s")
#endif
