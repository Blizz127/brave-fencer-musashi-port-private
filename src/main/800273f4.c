/* Main-exec range [800273F4,800275BC) from the SLUS executable.
 * SHA256(span)=f2e218cfed0ce012e3207535ffbdd5a608fa672bb2adcc9804080335aeffb995.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800273F4 - byte-exact against retail at -O2 (tools/register_match.py). */
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

typedef struct {
    u32 pad0;
    u32 rgb0;
    u32 rgb1;
    u32 rgb2;
    u16 n0;
    u16 v0;
    u16 v1;
    u16 v2;
} TmdG3;
#define gte_ldv3(r0, r1, r2) __asm__ volatile ( \
    "lwc2 $0, 0( %0 );"                         \
    "lwc2 $1, 4( %0 );"                         \
    "lwc2 $2, 0( %1 );"                         \
    "lwc2 $3, 4( %1 );"                         \
    "lwc2 $4, 0( %2 );"                         \
    "lwc2 $5, 4( %2 )"                          \
    :                                           \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_rtpt()  __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_avsz3() __asm__ volatile ("nop;nop;avsz3")
#define gte_stflg(r0) __asm__ volatile (        \
    "cfc2 $12, $31;"                            \
    "nop;"                                      \
    "sw   $12, 0( %0 )"                         \
    :                                           \
    : "r"( r0 )                                 \
    : "$12", "memory" )
#define gte_stopz(r0) __asm__ volatile (        \
    "swc2 $24, 0( %0 )"                         \
    :                                           \
    : "r"( r0 )                                 \
    : "memory" )
#define gte_stotz(r0) __asm__ volatile (        \
    "swc2 $7, 0( %0 )"                          \
    :                                           \
    : "r"( r0 )                                 \
    : "memory" )
#define gte_stsxy3_g3(r0) __asm__ volatile (    \
    "swc2 $12,  8( %0 );"                       \
    "swc2 $13, 16( %0 );"                       \
    "swc2 $14, 24( %0 )"                        \
    :                                           \
    : "r"( r0 )                                 \
    : "memory" )
extern s32 D_800A2B78;

u8 *func_800273F4(TmdG3 *f, u8 *vtx, u8 *nrm, u8 *pkt, s32 n, s32 shift, u32 *ot)
{
    s32 flag;
    s32 z;
    u32 *otp;

    if (n != 0) {
        __asm__("" : "=r"(pkt) : "0"(pkt));
        do {
            gte_ldv3(vtx + f->v0 * 8, vtx + f->v1 * 8, vtx + f->v2 * 8);
            gte_rtpt();
            gte_stflg(&flag);
            if ((flag & ~0x1000) == 0) {
                gte_nclip();
                gte_stopz(&z);
                if (z > 0) {
                    gte_stsxy3_g3(pkt);
                    gte_avsz3();
                    gte_stotz(&z);
                    *(u32 *)(pkt + 4) = f->rgb0;
                    *(u32 *)(pkt + 0xC) = f->rgb1;
                    *(u32 *)(pkt + 0x14) = f->rgb2;
                    pkt[7] = (pkt[7] & 2) | 0x30;
                    otp = ot + (z >> shift);
                    *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x6000000;
                    *otp = (u32)pkt & 0xFFFFFF;
                    pkt += 0x1C;
                    if (D_800A2B78 != 0) {
                        if (pkt[7 - 0x1C] & 2) {
                            otp = ot + (z >> shift);
                            pkt[3] = 1;
                            *(u32 *)(pkt + 4) = ((D_800A2B78 & 3) << 5) | 0xE100000A;
                            *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x1000000;
                            *otp = (u32)pkt & 0xFFFFFF;
                            pkt += 8;
                        }
                    }
                }
            }
            n--;
            f++;
        } while (n != 0);
    }
    return pkt;
}
