/* Main-exec range [8001D8C4,8001DA34) from the SLUS executable.
 * SHA256(span)=ae7895e7417620cde0800f4bd491de57a44101a826025ecddb45a3765f7cc71c.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001D8C4 - byte-exact against retail at -O2 (tools/register_match.py). */
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

#define gte_ldv0(r0) __asm__ volatile (             \
    "lwc2 $0, 0( %0 );"                                  \
    "lwc2 $1, 4( %0 )"                                   \
    :                                                    \
    : "r"( r0 )                                          \
    : "memory" )
#define gte_rt() __asm__ volatile (              \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 0, 0, 0"                                \
    : : : "memory" )
#define gte_stlvnl(r0) __asm__ volatile (         \
    "swc2 $25, 0( %0 );"                                 \
    "swc2 $26, 4( %0 );"                                 \
    "swc2 $27, 8( %0 )"                                  \
    :                                                    \
    : "r"( r0 )                                          \
    : "memory" )

void func_8001D8C4(s32 a0, u8 * a1_p, u8 * a2_p) {
    s32 a1 = (s32)a1_p;
    s32 a2 = (s32)a2_p;
    s16 sv[4][4];   /* 4 SVECTORs: sp+0x00..0x1F */
    s32 out[4];     /* MAC1/2/3 scratch: sp+0x20..0x2F */
    s32 cx, cy, dx, dy, z;

    cx = *(u16 *)(a0 + 0x2E) + *(u16 *)(a1 + 0x08);
    cy = *(u16 *)(a0 + 0x30) + *(u16 *)(a1 + 0x0A);
    sv[0][0] = sv[2][0] = cx;
    sv[0][1] = sv[1][1] = cy;

    dx = *(u8 *)(a1 + 0x02) + cx;
    sv[3][0] = dx;
    sv[1][0] = dx;

    dy = *(u8 *)(a1 + 0x03) + cy;
    sv[3][1] = dy;
    sv[2][1] = dy;

    z = *(u16 *)(a0 + 0x32);
    sv[3][2] = z;
    sv[2][2] = z;
    sv[1][2] = z;
    sv[0][2] = z;

    gte_ldv0(sv[0]);
    gte_rt();
    gte_stlvnl(out);
    *(s16 *)(a2 + 0x08) = out[0];
    *(s16 *)(a2 + 0x0A) = out[1];

    gte_ldv0(sv[1]);
    gte_rt();
    gte_stlvnl(out);
    *(s16 *)(a2 + 0x10) = out[0];
    *(s16 *)(a2 + 0x12) = out[1];

    gte_ldv0(sv[2]);
    gte_rt();
    gte_stlvnl(out);
    *(s16 *)(a2 + 0x18) = out[0];
    *(s16 *)(a2 + 0x1A) = out[1];

    gte_ldv0(sv[3]);
    gte_rt();
    gte_stlvnl(out);
    *(s16 *)(a2 + 0x20) = out[0];
    *(s16 *)(a2 + 0x22) = out[1];
}
