/* Main-exec range [80025EB8,80026128) from the SLUS executable.
 * SHA256(span)=106826793c043ffbaca49deb3a30db8fa4f9ce96583702109ad8aac560e3f53e.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80025EB8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro nccs\n"
    "    cop2op 0x10, 0x1B, lm = 1\n"
    ".endm\n"
    ".macro nclip\n"
    "    cop2op 0x14, 0x06, sf = 0\n"
    ".endm\n"
    ".macro avsz4\n"
    "    cop2op 0x16, 0x2E\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

#define gte_ldrgb(r0) __asm__ volatile (          \
    "lwc2 $6, 0( %0 )"                            \
    :                                             \
    : "r"( r0 ) )
#define gte_ldv0(r0) __asm__ volatile (           \
    "lwc2 $0, 0( %0 );"                           \
    "lwc2 $1, 4( %0 )"                            \
    :                                             \
    : "r"( r0 ) )
#define gte_ldv3(r0, r1, r2) __asm__ volatile (   \
    "lwc2 $0, 0( %0 );"                           \
    "lwc2 $1, 4( %0 );"                           \
    "lwc2 $2, 0( %1 );"                           \
    "lwc2 $3, 4( %1 );"                           \
    "lwc2 $4, 0( %2 );"                           \
    "lwc2 $5, 4( %2 )"                            \
    :                                             \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_rtps()  __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt()  __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_avsz4() __asm__ volatile ("nop;nop;avsz4")
#define gte_nccs()  __asm__ volatile ("nop;nop;nccs")
#define gte_stflg(r0) __asm__ volatile (          \
    "cfc2 $12, $31;"                              \
    "nop;"                                        \
    "sw $12, 0( %0 )"                             \
    :                                             \
    : "r"( r0 )                                   \
    : "$12", "memory" )
#define gte_stopz(r0) __asm__ volatile (          \
    "swc2 $24, 0( %0 )"                           \
    :                                             \
    : "r"( r0 )                                   \
    : "memory" )
#define gte_stotz(r0) __asm__ volatile (          \
    "swc2 $7, 0( %0 )"                            \
    :                                             \
    : "r"( r0 )                                   \
    : "memory" )
#define gte_stsxy(r0) __asm__ volatile (          \
    "swc2 $14, 0( %0 )"                           \
    :                                             \
    : "r"( r0 )                                   \
    : "memory" )
#define gte_stsxy3_ft4(r0) __asm__ volatile (     \
    "swc2 $12, 8( %0 );"                          \
    "swc2 $13, 16( %0 );"                         \
    "swc2 $14, 24( %0 )"                          \
    :                                             \
    : "r"( r0 )                                   \
    : "memory" )
#define gte_stsz4(r0, r1, r2, r3) __asm__ volatile ( \
    "swc2 $16, 0( %0 );"                          \
    "swc2 $17, 0( %1 );"                          \
    "swc2 $18, 0( %2 );"                          \
    "swc2 $19, 0( %3 )"                           \
    :                                             \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ), "r"( r3 ) )
#define gte_strgb(r0) __asm__ volatile (         \
    "swc2 $22, 0( %0 )"                           \
    :                                             \
    : "r"( r0 )                                   \
    : "memory" )
typedef struct { s16 vx, vy, vz, pad; } SVEC8_80025EB8;
typedef struct {
    u32 pad0;  /* 0x00 */
    u32 uv0;   /* 0x04 */
    u32 uv1;   /* 0x08 */
    u32 uv2;   /* 0x0C */
    u32 uv3;   /* 0x10 */
    u16 n0;    /* 0x14 */
    u16 v0;    /* 0x16 */
    u16 v1;    /* 0x18 */
    u16 v2;    /* 0x1A */
    u16 v3;    /* 0x1C */
    u16 pad1;  /* 0x1E */
} Prim20;
typedef struct {           /* libgpu POLY_FT4, 0x28 bytes */
    u32 tag;   /* 0x00 */
    u32 rgb;   /* 0x04 */
    u32 xy0;   /* 0x08 */
    u32 uv0;   /* 0x0C */
    u32 xy1;   /* 0x10 */
    u32 uv1;   /* 0x14 */
    u32 xy2;   /* 0x18 */
    u32 uv2;   /* 0x1C */
    u32 xy3;   /* 0x20 */
    u32 uv3;   /* 0x24 */
} Ft4;
extern u32 D_80063880;
extern s32 D_80078D88[];

u32 *func_80025EB8(Prim20 *prim, SVEC8_80025EB8 *verts, SVEC8_80025EB8 *norms, Ft4 *pkt0,
                   s32 n, s32 shift, u32 *ot)
{
    struct { long flag, otz, sz0, sz1, sz2, sz3; } g;
    s32 a, b;
    u32 *otp;
    Ft4 *pkt;

    pkt = pkt0;
    gte_ldrgb(&D_80063880);

    while (n != 0) {
        gte_ldv3(&verts[prim->v0], &verts[prim->v1], &verts[prim->v2]);
        gte_rtpt();
        pkt->uv0 = prim->uv0;
        pkt->uv1 = prim->uv1;
        pkt->uv2 = prim->uv2;
        gte_stflg(&g.flag);
        if (!(g.flag & 0xFFFFEFFF)) {
            gte_nclip();
            gte_stopz(&g.otz);
            if (g.otz > 0) {
                gte_stsxy3_ft4(pkt);
                gte_ldv0(&verts[prim->v3]);
                gte_rtps();
                gte_stflg(&g.flag);
                if (!(g.flag & 0xFFFFEFFF)) {
                    gte_stsxy(&pkt->xy3);
                    pkt->uv3 = prim->uv3;
                    if (D_80078D88[0] & 0x8000) {
                        gte_stsz4(&g.sz0, &g.sz1, &g.sz2, &g.sz3);
                        a = g.sz2;
                        if (a < g.sz3) a = g.sz3;
                        b = g.sz0;
                        if (b < g.sz1) b = g.sz1;
                        if (b < a) b = a;
                        g.otz = b >> 2;
                    } else {
                        gte_avsz4();
                        gte_stotz(&g.otz);
                    }
                    gte_ldv0(&norms[prim->n0]);
                    gte_nccs();
                    gte_strgb(&pkt->rgb);
                    otp = &ot[g.otz >> shift];
                    pkt->tag = (*otp & 0xFFFFFF) | 0x09000000;
                    *otp = (u32)pkt & 0xFFFFFF;
                    pkt++;
                }
            }
        }
        n--;
        prim++;
    }

    return (u32 *)pkt;
}
