#include "recomp.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "jfg_animation.c"
#include "matrix_translate.inc"
gpr cop0_status_read(recomp_context *ctx) { return ctx->status_reg; }
void cop0_status_write(recomp_context *ctx, gpr value) {
    ctx->status_reg = (uint32_t)value;
    ctx->mips3_float_mode = (value & 0x04000000) != 0;
    ctx->f_odd = ctx->mips3_float_mode ? &ctx->f1.u32l : &ctx->f0.u32h;
}
static void test_animation_angles(uint8_t *rdram, recomp_context *c, int mode) {
    /* gen_anim_data.s sets t3=0xFFC and s6=0x1000. D_800A8754 in
       math_data_tables.s has 1025 floats: sin(i*pi/2048), i=0..1024.
       Its printed values differ from this formula by at most 3.39e-8.
       The helper returns product terms, not a complete quaternion. */
    const double pi = 3.14159265358979323846;
    static const int16_t cases[][3] = {
        {0, 0, 0}, {8192, 16384, 24576}, {-8192, -16384, -24576},
        {32767, -32768, 16384}, {-33, 63, -1025}, {31, -1, 32}
    };
    c->r16 = (gpr)(int32_t)0x80020000;
    c->r18 = (gpr)(int32_t)0x80030000;
    c->r22 = 0x1000; c->r11 = 0xFFC;
    for (int i=0; i<=1024; ++i)
        MEM_W(i*4,c->r18) = jfg_bits((float)sin(i*pi/2048.0));
    for (unsigned k=0; k<sizeof(cases)/sizeof(cases[0]); ++k) {
        double sn[3], cs[3];
        for (int axis=0; axis<3; ++axis) {
            MEM_H(axis*2,c->r16) = cases[k][axis];
            /* Angles encode one full turn in 65536 units. The helper uses
               half angles in [0,pi), so a negative signed input represents
               quadrant II (negative cosine, positive sine). */
            double theta = floor((uint16_t)cases[k][axis]/32.0)*pi/2048.0;
            sn[axis] = sin(theta); cs[axis] = cos(theta);
        }
        double expected[4] = {
            cs[0]*cs[1]*cs[2], sn[0]*sn[1]*sn[2],
            sn[0]*cs[1]*cs[2], cs[0]*sn[1]*sn[2]
        };
        *jfg_fpr(c,30) = jfg_bits(0);
        for (int reg=10; reg<=13; ++reg) *jfg_fpr(c,reg)=jfg_bits(1234);
        c->r31 = 0x12345678;
        const uint32_t status = c->status_reg;
        jfg_native_func_80074A68(rdram,c);
        for (int i=0; i<4; ++i) {
            float actual = jfg_float(*jfg_fpr(c,10+i));
            if (!(fabs(actual-expected[i]) < 3e-7)) {
                fprintf(stderr,"FR%d case %u f%d: %.9g, expected %.9g\n",
                        mode,k,10+i,(double)actual,expected[i]);
                abort();
            }
        }
        assert(c->r31 == 0x12345678);
        assert(c->status_reg == status);
        assert(c->mips3_float_mode == (mode!=0));
    }
}
int main(void) {
    uint8_t *rdram = calloc(1, 0x800000);
    recomp_context c = {0};
    for (int mode=0; mode<2; ++mode) {
        cop0_status_write(&c, mode ? 0x04000000 : 0);
        c.r7 = (gpr)(int32_t)0x80010000;
        for(int i=0; i<16; ++i) MEM_W(i*4,c.r7) = jfg_bits(i%5==0 ? 1.0f : 0.0f);
        MEM_W(48,c.r7)=jfg_bits(10.0f); MEM_W(52,c.r7)=jfg_bits(20.0f); MEM_W(56,c.r7)=jfg_bits(30.0f);
        c.f12.fl=2; c.f14.fl=3; c.r6=jfg_bits(4);
        matrixTranslate(rdram,&c);
        assert(jfg_float(MEM_W(48,c.r7))==12);
        assert(jfg_float(MEM_W(52,c.r7))==23);
        assert(jfg_float(MEM_W(56,c.r7))==34);
        assert(c.mips3_float_mode == (mode!=0));
        test_animation_angles(rdram,&c,mode);
    }
    puts("PASS: Rare matrixTranslate and signed/quantized animation product terms in FR=0/1; status/return preserved");
    free(rdram);
}

