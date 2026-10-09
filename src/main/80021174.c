/* Main-exec function func_80021174 from the SLUS executable (clean room, owner).
 * Screen-rectangle visibility test: `half` packs a half-width (low 16 bits)
 * and half-height (high 16 bits); 0x7FFF7FFF means "always visible". The
 * long vector `v` is perspective-transformed with the matrix at D_800AE688
 * (PsyQ gte_SetRotMatrix / gte_SetTransMatrix / gte_ldlv0 / gte_rtps /
 * gte_stsxy / gte_stflg / gte_stszotz); returns 0 when the GTE flags report
 * an error (bit 31) or the projected point lies outside
 * [-w, w] x [-h, h], else 1. The result lives in v0 from the bounds checks
 * on (pinned, as the retail allocation has it). */
#include "psx_types.h"

#define gte_SetRotMatrix(r0) __asm__ volatile (  \
    "lw $12, 0( %0 );"                           \
    "lw $13, 4( %0 );"                           \
    "ctc2 $12, $0;"                              \
    "ctc2 $13, $1;"                              \
    "lw $12, 8( %0 );"                           \
    "lw $13, 12( %0 );"                          \
    "lw $14, 16( %0 );"                          \
    "ctc2 $12, $2;"                              \
    "ctc2 $13, $3;"                              \
    "ctc2 $14, $4"                               \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "$13", "$14" )
#define gte_SetTransMatrix(r0) __asm__ volatile ( \
    "lw $12, 20( %0 );"                          \
    "lw $13, 24( %0 );"                          \
    "ctc2 $12, $5;"                              \
    "lw $14, 28( %0 );"                          \
    "ctc2 $13, $6;"                              \
    "ctc2 $14, $7"                               \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "$13", "$14" )
#define gte_ldlv0(r0) __asm__ volatile (         \
    "lhu $13, 4( %0 );"                          \
    "lhu $12, 0( %0 );"                          \
    "sll $13, $13, 16;"                          \
    "or $12, $12, $13;"                          \
    "mtc2 $12, $0;"                              \
    "lwc2 $1, 8( %0 )"                           \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "$13" )
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4A180001")
#define gte_stsxy(r0) __asm__ volatile (         \
    "swc2 $14, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
#define gte_stszotz(r0) __asm__ volatile (       \
    "mfc2 $12, $19;"                             \
    "nop;"                                       \
    "sra $12, $12, 2;"                           \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )

extern u8 D_800AE688[];

s32 func_80021174(s32 half, s32 *v)
{
    s32 buf[3];
    s32 w, h;
    register s32 ret __asm__("$2");

    if (half == 0x7FFF7FFF) {
        return 1;
    }
    gte_SetRotMatrix(D_800AE688);
    gte_SetTransMatrix(D_800AE688);
    gte_ldlv0(v);
    gte_rtps();
    gte_stsxy(&buf[0]);
    gte_stflg(&buf[1]);
    gte_stszotz(&buf[2]);
    if (buf[1] < 0) {
        return 0;
    }
    ret = 0;
    w = (s16)half;
    if (-w < ((s16 *)buf)[0]) {
        if (w < ((s16 *)buf)[0]) return ret;
        h = half >> 16;
        if (-h < ((s16 *)buf)[1]) {
            ret = h >= ((s16 *)buf)[1];
        }
    }
    return ret;
}
