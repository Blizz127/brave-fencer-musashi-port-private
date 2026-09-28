/* Main-exec range [80027F4C,80028200) from the SLUS executable.
 * SHA256(span)=bfcd80b067bb83dd6b3c86563f8e34347af6552f1698a2b4402e2aa8f167a0ef.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80027F4C - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro ncct\n"
    "    cop2op 0x11, 0x3F, lm = 1\n"
    ".endm\n"
    ".macro nclip\n"
    "    cop2op 0x14, 0x06, sf = 0\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

typedef struct { s16 vx, vy, vz, pad; } SVEC2;
typedef struct {                                     /* 0x18 */
    u32 w0;      /* 0x00 */
    u32 rgb;     /* 0x04 */
    u16 n0;      /* 0x08 */
    u16 v0;      /* 0x0A */
    u16 n1;      /* 0x0C */
    u16 v1;      /* 0x0E */
    u16 n2;      /* 0x10 */
    u16 v2;      /* 0x12 */
    u16 n3;      /* 0x14 */
    u16 v3;      /* 0x16 */
} Face3;
typedef struct {                                     /* 0x24 */
    u32 tag;     /* 0x00 */
    u32 rgb0;    /* 0x04 */
    s16 x0, y0;  /* 0x08 */
    u32 rgb1;    /* 0x0C */
    s16 x1, y1;  /* 0x10 */
    u32 rgb2;    /* 0x14 */
    s16 x2, y2;  /* 0x18 */
    u32 rgb3;    /* 0x1C */
    s16 x3, y3;  /* 0x20 */
} G4P;
#define gte_ldv0(r0) __asm__ volatile (          \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 )"                           \
    :                                            \
    : "r"( r0 ) )
#define gte_ldv3(r0, r1, r2) __asm__ volatile (  \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 );"                          \
    "lwc2 $2, 0( %1 );"                          \
    "lwc2 $3, 4( %1 );"                          \
    "lwc2 $4, 0( %2 );"                          \
    "lwc2 $5, 4( %2 )"                           \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_ldrgb(r0) __asm__ volatile (         \
    "lwc2 $6, 0( %0 )"                           \
    :                                            \
    : "r"( r0 ) )
#define gte_rtps()  __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt()  __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_ncct()  __asm__ volatile ("nop;nop;ncct")
#define gte_nccs()  __asm__ volatile ("nop;nop;nccs")
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
#define gte_stopz(r0) __asm__ volatile (         \
    "swc2 $24, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsxy(r0) __asm__ volatile (         \
    "swc2 $14, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_strgb(r0) __asm__ volatile (         \
    "swc2 $22, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsz4(r0, r1, r2, r3) __asm__ volatile ( \
    "swc2 $16, 0( %0 );"                         \
    "swc2 $17, 0( %1 );"                         \
    "swc2 $18, 0( %2 );"                         \
    "swc2 $19, 0( %3 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ), "r"( r3 ) \
    : "memory" )
#define gte_stsxy3_g4(r0) __asm__ volatile (     \
    "swc2 $12, 8( %0 );"                         \
    "swc2 $13, 16( %0 );"                        \
    "swc2 $14, 24( %0 )"                         \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_strgb3_g4(r0) __asm__ volatile (     \
    "swc2 $20, 4( %0 );"                         \
    "swc2 $21, 12( %0 );"                        \
    "swc2 $22, 20( %0 )"                         \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
extern s16 D_800C7C74;
extern void func_80028200(s32 a0, s32 a1, s32 a2, s32 a3, s32 stack_arg);

G4P *func_80027F4C(Face3 *f, SVEC2 *verts, SVEC2 *norms, G4P *prims,
                   s32 count, s32 shift, s32 ot)
{
    struct { s32 flag, opz, sz0, sz1, sz2, sz3; } g;
    G4P *prim;
    s32 z;
    s32 w;
    s32 i;

    prim = &prims[D_800C7C74];

    for (i = count; i != 0; i--, f++, prim += 2) {
        gte_ldv3(&verts[f->v0], &verts[f->v1], &verts[f->v2]);
        gte_rtpt();
        gte_stflg(&g.flag);
        if (!(g.flag & ~0x1000)) {
            gte_nclip();
            gte_stopz(&g.opz);
            if (g.opz > 0) {
                gte_stsxy3_g4(prim);
                gte_ldv0(&verts[f->v3]);
                gte_rtps();
                gte_stflg(&g.flag);
                if (!(g.flag & ~0x1000)) {
                    gte_stsxy(&prim->x3);
                    gte_stsz4(&g.sz0, &g.sz1, &g.sz2, &g.sz3);
                    w = g.sz2;
                    if (g.sz3 < w) { w = g.sz3; }
                    z = g.sz0;
                    if (g.sz1 < z) { z = g.sz1; }
                    if (w < z) { z = w; }
                    g.opz = (z >> 2) - 1;
                    if (g.opz < 0) {
                        g.opz = 0;
                    }
                    gte_ldrgb(&f->rgb);
                    gte_ldv3(&norms[f->n0], &norms[f->n1], &norms[f->n2]);
                    gte_ncct();
                    gte_strgb3_g4(prim);
                    gte_ldv0(&norms[f->n3]);
                    gte_nccs();
                    gte_strgb(&prim->rgb3);
                    func_80028200(ot, g.opz, shift, (s32)prim, 0x08000000);
                }
            }
        }
    }

    return prim;
}
