/* Main-exec range [80026128,800262D8) from the SLUS executable.
 * SHA256(span)=fd5506889376e956e3ca42c237c2232ff910b2a9d6621c895e40aa15f50b2d58.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80026128 - byte-exact against retail at -O2 (tools/register_match.py). */
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

typedef struct { s16 vx, vy, vz, pad; } SVEC8_80026128;
typedef struct {                                        /* 0x1C */
    u32 unk00;
    u32 uv0;
    u32 uv1;
    u32 uv2;
    u16 n0, v0;
    u16 n1, v1;
    u16 n2, v2;
} FaceGT3;
typedef struct {                                        /* 0x28 */
    u32 tag;
    u32 rgb0, xy0, uv0;
    u32 rgb1, xy1, uv1;
    u32 rgb2, xy2, uv2;
} PktGT3;
extern u32 D_80063884;
#define gte_ldrgb(r0) __asm__ volatile (          \
    "lwc2 $6, 0( %0 )"                            \
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
#define gte_rtpt()  __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_avsz3() __asm__ volatile ("nop;nop;avsz3")
#define gte_ncct()  __asm__ volatile ("nop;nop;ncct")
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
#define gte_strgb3_gt3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $20, 0( %0 );"                          \
    "swc2 $21, 0( %1 );"                          \
    "swc2 $22, 0( %2 )"                           \
    :                                             \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )             \
    : "memory" )

PktGT3 *func_80026128(FaceGT3 *face, SVEC8_80026128 *vtx, SVEC8_80026128 *nrm, PktGT3 *arg3,
                      s32 count, s32 shift, u32 *ot)
{
    long flag;
    long otz;
    u32 *otp;
    PktGT3 *pkt = arg3;

    gte_ldrgb(&D_80063884);

    while (count != 0) {
        gte_ldv3(&vtx[face->v0], &vtx[face->v1], &vtx[face->v2]);
        gte_rtpt();
        pkt->uv0 = face->uv0;
        pkt->uv1 = face->uv1;
        pkt->uv2 = face->uv2;
        gte_stflg(&flag);
        if (!(flag & ~0x1000)) {
            gte_nclip();
            gte_stopz(&otz);
            if (otz > 0) {
                __asm__ volatile (
                    "swc2 $12, 8( %0 );"
                    "swc2 $13, 20( %0 );"
                    "swc2 $14, 32( %0 )"
                    :
                    : "r"( pkt )
                    : "memory" );
                gte_avsz3();
                gte_stotz(&otz);
                gte_ldv3(&nrm[face->n0], &nrm[face->n1], &nrm[face->n2]);
                gte_ncct();
                otp = &ot[otz >> shift];
                pkt->tag = (*otp & 0x00FFFFFF) | 0x09000000;
                gte_strgb3_gt3(&pkt->rgb0, &pkt->rgb1, &pkt->rgb2);
                *otp = (u32)pkt & 0x00FFFFFF;
                pkt++;
            }
        }
        face++;
        count--;
    }
    return pkt;
}
