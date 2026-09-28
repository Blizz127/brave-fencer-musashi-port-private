/* Main-exec range [8001E668,8001E7E0) from the SLUS executable.
 * SHA256(span)=e970802f389a2b97bf1b79f07007bf89b187eb91f0a02cb84019226233f63972.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001E668 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro rtps\n"
    "    cop2op 0x01, 0x01\n"
    ".endm\n"
    ".macro rtpt\n"
    "    cop2op 0x02, 0x30\n"
    ".endm\n"
    ".macro avsz4\n"
    "    cop2op 0x16, 0x2E\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

#define gte_ldv3(r0, r1, r2) __asm__ volatile (  \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 );"                          \
    "lwc2 $2, 0( %1 );"                          \
    "lwc2 $3, 4( %1 );"                          \
    "lwc2 $4, 0( %2 );"                          \
    "lwc2 $5, 4( %2 )"                           \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_ldv0(r0) __asm__ volatile (          \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 )"                           \
    :                                            \
    : "r"( r0 ) )
#define gte_rtpt()  __asm__ volatile ("nop;nop;rtpt")
#define gte_rtps()  __asm__ volatile ("nop;nop;rtps")
#define gte_avsz4() __asm__ volatile ("nop;nop;avsz4")
#define gte_stsxy3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $12, 0( %0 );"                         \
    "swc2 $13, 0( %1 );"                         \
    "swc2 $14, 0( %2 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )            \
    : "memory" )
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
#define gte_stotz(r0) __asm__ volatile (         \
    "swc2 $7, 0( %0 )"                           \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
typedef struct {
    /* 0x0 */ s16 vx;
    /* 0x2 */ s16 vy;
    /* 0x4 */ s16 vz;
    /* 0x6 */ s16 pad;
} GTESVec;
typedef struct {
    /* 0x0 */ u32 xy;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 pad;
} GTEOutV;

s32 func_8001E668(s32 a0, s32 a1, GTEOutV *a2, s32 *a3)
{
    GTESVec v[4];
    s32 flag2;
    s32 otz;

    v[0].vx = *(u16 *)(a0 + 0x2E) + *(u16 *)(a1 + 0x8);
    v[0].vy = *(u16 *)(a0 + 0x30) + *(u16 *)(a1 + 0xA);
    v[1].vx = *(u16 *)(a0 + 0x2E) + *(u16 *)(a1 + 0x8) + *(u8 *)(a1 + 0x2);
    v[1].vy = *(u16 *)(a0 + 0x30) + *(u16 *)(a1 + 0xA);
    v[2].vx = *(u16 *)(a0 + 0x2E) + *(u16 *)(a1 + 0x8);
    v[2].vy = *(u16 *)(a0 + 0x30) + *(u16 *)(a1 + 0xA) + *(u8 *)(a1 + 0x3);
    v[3].vx = *(u16 *)(a0 + 0x2E) + *(u16 *)(a1 + 0x8) + *(u8 *)(a1 + 0x2);
    v[3].vy = *(u16 *)(a0 + 0x30) + *(u16 *)(a1 + 0xA) + *(u8 *)(a1 + 0x3);
    v[0].vz = v[1].vz = v[2].vz = v[3].vz = *(u16 *)(a0 + 0x32);

    gte_ldv3(&v[0], &v[1], &v[2]);
    gte_rtpt();
    gte_stflg(a3);
    gte_stsxy3(&a2[1].xy, &a2[2].xy, &a2[3].xy);

    gte_ldv0(&v[3]);
    gte_rtps();
    gte_stflg(&flag2);
    *a3 |= flag2;
    a2 += 4;
    gte_stsxy(&a2[0].xy);

    gte_avsz4();
    gte_stotz(&otz);

    return otz;
}
