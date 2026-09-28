/* Main-exec range [80025000,8002528C) from the SLUS executable.
 * SHA256(span)=854b09fc533e2299a33c5ab4714f0f70cd2aa990101e248319956b9d78a78e80.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80025000 - byte-exact against retail at -O2 (tools/register_match.py). */
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
#define gte_avsz4() __asm__ volatile ("nop;nop;avsz4")
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
#define gte_stotz(r0) __asm__ volatile (         \
    "swc2 $7, 0( %0 )"                           \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsxy(r0) __asm__ volatile (         \
    "swc2 $14, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsxy3_g4(r0) __asm__ volatile (     \
    "swc2 $12, 8( %0 );"                         \
    "swc2 $13, 16( %0 );"                        \
    "swc2 $14, 24( %0 )"                         \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_strgb(r0) __asm__ volatile (         \
    "swc2 $22, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
typedef struct { s16 vx, vy, vz, pad; } SVEC_80025000;
typedef struct { u8  r, g, b, code; }   RGBC;
typedef struct {            /* 0x20 — source quad description */
    u32  unk0;
    RGBC c0;
    RGBC c1;
    RGBC c2;
    RGBC c3;
    u16  n;
    u16  v0;
    u16  v1;
    u16  v2;
    u16  v3;
    u16  unk1E;
} SRCQ;
typedef struct {            /* 0x24 — POLY_G4 */
    u32  tag;
    RGBC c0;
    u32  xy0;
    RGBC c1;
    u32  xy1;
    RGBC c2;
    u32  xy2;
    RGBC c3;
    u32  xy3;
} PG4;
typedef struct { u32 tag; u32 code0; } DRM;
extern s32 D_800A2B78;

PG4 *func_80025000(SRCQ *p, SVEC_80025000 *verts, SVEC_80025000 *norms, PG4 *poly0, s32 n,
                   s32 shift, u32 *ot)
{
    struct { s32 flag; s32 z; } g;
    u32 *otp;
    PG4 *prim;
    PG4 *poly = poly0;
    

    while (n != 0) {
        gte_ldv3(&verts[p->v0], &verts[p->v1], &verts[p->v2]);
        gte_rtpt();
        gte_stflg(&g.flag);
        if ((g.flag & 0xFFFFEFFF) == 0) {
            gte_nclip();
            gte_stopz(&g.z);
            if (g.z > 0) {
                gte_stsxy3_g4(poly);
                gte_ldv0(&verts[p->v3]);
                gte_rtps();
                gte_stflg(&g.flag);
                if ((g.flag & 0xFFFFEFFF) == 0) {
                    gte_stsxy(&poly->xy3);
                    gte_avsz4();
                    gte_stotz(&g.z);

                    gte_ldv0(&norms[p->n]);
                    gte_ldrgb(&p->c0);
                    gte_nccs();
                    gte_strgb(&poly->c0);
                    gte_ldrgb(&p->c1);
                    gte_nccs();
                    gte_strgb(&poly->c1);
                    gte_ldrgb(&p->c2);
                    gte_nccs();
                    gte_strgb(&poly->c2);
                    gte_ldrgb(&p->c3);
                    gte_nccs();
                    gte_strgb(&poly->c3);

                    poly->c0.code = (poly->c0.code & 2) | 0x38;

                    otp = &ot[g.z >> shift];
                    poly->tag = (*otp & 0xFFFFFF) | 0x08000000;
                    *otp = (u32)poly & 0xFFFFFF;

                    prim = poly;
                    poly = (PG4 *)((u8 *)poly + 0x24);

                    if (D_800A2B78 != 0) {
                        if ((prim->c0.code & 2) != 0) {
                            otp = &ot[g.z >> shift];
                            ((u8 *)poly)[3] = 1;
                            ((DRM *)poly)->code0 =
                                0xE100000A | ((D_800A2B78 & 3) << 5);
                            ((DRM *)poly)->tag = (*otp & 0xFFFFFF) | 0x01000000;
                            *otp = (u32)poly & 0xFFFFFF;
                            poly = (PG4 *)((u8 *)poly + 8);
                        }
                    }
                }
            }
        }
        n--;
        p++;
    }
    return poly;
}
