/* Main-exec range [8002528C,80025504) from the SLUS executable.
 * SHA256(span)=0019e3f17d90bbd67fd050aa90a1c3e1771aaa94a61ce0f280747dfa5ebd2100.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002528C - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro rtpt\n"
    "    cop2op 0x02, 0x30\n"
    ".endm\n"
    ".macro ncct\n"
    "    cop2op 0x11, 0x3F, lm = 1\n"
    ".endm\n"
    ".macro nclip\n"
    "    cop2op 0x14, 0x06, sf = 0\n"
    ".endm\n"
    ".macro avsz3\n"
    "    cop2op 0x15, 0x2D\n"
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
#define gte_ldrgb(r0) __asm__ volatile (         \
    "lwc2 $6, 0( %0 )"                           \
    :                                            \
    : "r"( r0 ) )
#define gte_rtpt()  __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_avsz3() __asm__ volatile ("nop;nop;avsz3")
#define gte_ncct()  __asm__ volatile ("nop;nop;ncct")
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
#define gte_stsz3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $17, 0( %0 );"                         \
    "swc2 $18, 0( %1 );"                         \
    "swc2 $19, 0( %2 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )            \
    : "memory" )
#define gte_stsxy3_g3(r0) __asm__ volatile (     \
    "swc2 $12, 8( %0 );"                         \
    "swc2 $13, 16( %0 );"                        \
    "swc2 $14, 24( %0 )"                         \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_strgb3_g3(r0) __asm__ volatile (     \
    "swc2 $20, 4( %0 );"                         \
    "swc2 $21, 12( %0 );"                        \
    "swc2 $22, 20( %0 )"                         \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
extern s32 D_80078D88[];
extern s32 D_800A2B78;
typedef struct { s16 vx, vy, vz, pad; } Vec8;
typedef struct {
    u32 unk0;
    u32 rgbc;
    u16 n0, v0, n1, v1, n2, v2;
} Prim;

u8 *func_8002528C(Prim *pr, Vec8 *vtx, Vec8 *nrm, void *arg3, s32 n, s32 shift, u32 *ot)
{
    struct { s32 flag, opz, sz1, sz2, sz3; } g;
    u8 *pk = (u8 *)arg3;
    u32 *otp;
    s32 z;

    if (n != 0) {
        do {
            gte_ldv3(&vtx[pr->v0], &vtx[pr->v1], &vtx[pr->v2]);
            gte_rtpt();
            gte_stflg(&g.flag);
            if (!(g.flag & ~0x1000)) {
                gte_nclip();
                gte_stopz(&g.opz);
                if (g.opz > 0) {
                    gte_stsxy3_g3(pk);
                    if (D_80078D88[0] & 0x8000) {
                        gte_stsz3(&g.sz1, &g.sz2, &g.sz3);
                        if (g.sz1 > g.sz2) {
                            z = g.sz1;
                            if (z < g.sz3) {
                                z = g.sz3;
                            }
                        } else {
                            z = g.sz2;
                            if (z < g.sz3) {
                                z = g.sz3;
                            }
                        }
                        g.opz = z >> 2;
                    } else {
                        gte_avsz3();
                        gte_stotz(&g.opz);
                    }
                    gte_ldrgb(&pr->rgbc);
                    gte_ldv3(&nrm[pr->n0], &nrm[pr->n1], &nrm[pr->n2]);
                    gte_ncct();
                    gte_strgb3_g3(pk);
                    otp = &ot[g.opz >> shift];
                    *(u32 *)pk = (*otp & 0xFFFFFF) | 0x6000000;
                    *otp = (u32)pk & 0xFFFFFF;
                    pk += 0x1C;
                    if (D_800A2B78 != 0 && (pk[-0x15] & 2)) {
                        otp = &ot[g.opz >> shift];
                        pk[3] = 1;
                        *(u32 *)(pk + 4) = 0xE100000A | ((D_800A2B78 & 3) << 5);
                        *(u32 *)pk = (*otp & 0xFFFFFF) | 0x1000000;
                        *otp = (u32)pk & 0xFFFFFF;
                        pk += 8;
                    }
                }
            }
            n--;
            pr++;
        } while (n != 0);
    }
    return pk;
}
