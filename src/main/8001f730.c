/* Main-exec range [8001F730,8001F974) from the SLUS executable.
 * SHA256(span)=086cd30f0199e186dfb345dcba1f1f138716251816a97ed3d494916fa7901c78.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001F730 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif
/* GTE instruction macros (vendor/bfm-decomp/include/gte_macros.inc) for GNU as. */
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro mvmva sf, mx, v, cv, lm\n"
    "    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

extern void func_80020DA4(s32 a0, s32 a1);
#define SRM_8001F730(r0) __asm__ volatile (              \
    "lw $12, 0( %0 );"                                   \
    "lw $13, 4( %0 );"                                   \
    "ctc2 $12, $0;"                                      \
    "ctc2 $13, $1;"                                      \
    "lw $12, 8( %0 );"                                   \
    "lw $13, 12( %0 );"                                  \
    "lw $14, 16( %0 );"                                  \
    "ctc2 $12, $2;"                                      \
    "ctc2 $13, $3;"                                      \
    "ctc2 $14, $4"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )
#define LDV0_8001F730(r0) __asm__ volatile (             \
    "lwc2 $0, 0( %0 );"                                  \
    "lwc2 $1, 4( %0 )"                                   \
    :                                                    \
    : "r"( r0 )                                          \
    : "memory" )
#define RTV0_8001F730() __asm__ volatile (               \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 0, 3, 0"                                \
    : : : "memory" )
#define STLVNL_8001F730(r0) __asm__ volatile (           \
    "swc2 $25, 0( %0 );"                                 \
    "swc2 $26, 4( %0 );"                                 \
    "swc2 $27, 8( %0 )"                                  \
    :                                                    \
    : "r"( r0 )                                          \
    : "memory" )

void func_8001F730(s32 a0, void *a1, void *a2)
{
    s32  matrix[8];   /* sp+0x10 */
    s16  sv[4][4];    /* sp+0x30 */
    s32  out[4][4];   /* sp+0x50 */
    u16 *c = (u16 *)a1;
    u8  *p = (u8 *)a2;

    func_80020DA4(a0, (s32)matrix);
    SRM_8001F730(matrix);

    sv[0][0] = *(u16 *)(p + 0x08) - c[0];
    sv[0][1] = *(u16 *)(p + 0x0A) - c[1];
    sv[0][2] = 0;
    sv[1][0] = *(u16 *)(p + 0x10) - c[0];
    sv[1][1] = *(u16 *)(p + 0x12) - c[1];
    sv[1][2] = 0;
    sv[2][0] = *(u16 *)(p + 0x18) - c[0];
    sv[2][1] = *(u16 *)(p + 0x1A) - c[1];
    sv[2][2] = 0;
    sv[3][0] = *(u16 *)(p + 0x20) - c[0];
    sv[3][1] = *(u16 *)(p + 0x22) - c[1];
    sv[3][2] = 0;

    LDV0_8001F730(sv[0]);
    RTV0_8001F730();
    STLVNL_8001F730(out[0]);

    LDV0_8001F730(sv[1]);
    RTV0_8001F730();
    STLVNL_8001F730(out[1]);

    LDV0_8001F730(sv[2]);
    RTV0_8001F730();
    STLVNL_8001F730(out[2]);

    LDV0_8001F730(sv[3]);
    RTV0_8001F730();
    STLVNL_8001F730(out[3]);

    *(u16 *)(p + 0x08) = c[0] + out[0][0];
    *(u16 *)(p + 0x0A) = c[1] + out[0][1];
    *(u16 *)(p + 0x10) = c[0] + out[1][0];
    *(u16 *)(p + 0x12) = c[1] + out[1][1];
    *(u16 *)(p + 0x18) = c[0] + out[2][0];
    *(u16 *)(p + 0x1A) = c[1] + out[2][1];
    *(u16 *)(p + 0x20) = c[0] + out[3][0];
    *(u16 *)(p + 0x22) = c[1] + out[3][1];
}
