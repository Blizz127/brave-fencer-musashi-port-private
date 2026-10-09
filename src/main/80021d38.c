/* Main-exec range [80021D38,800221A8) from the SLUS executable.
 * SHA256(span)=487f7b2d96a77a312df75ab8087de6f0ea97828c6e732d6d917bdaf861eb9016.
 * Word export for the native seam; the body below keeps its
 * own oracle match claim (registry-verified, untouched). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80021D38 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro mvmva sf, mx, v, cv, lm\n"
    "    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

typedef struct { u16 vx, vy; } DVec_80021D38;
typedef struct { s16 vx, vy, vz, pad; } SVec_80021D38;
typedef struct { s16 m[3][3]; s32 t[3]; } Mtx_80021D38;
typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u32 flags;
    /* 0x08 */ SVec_80021D38 pos;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u16 sx;
    /* 0x1A */ u16 sy;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 *pts;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u16 depth;
    /* 0x2E */ u16 unk2E;
} Obj_80021D38;
extern u8  D_800AF630[];
extern u8  D_800A6610[];
extern u16 D_800B9A02;
extern void func_800226C0(Obj_80021D38 *, u8 *, DVec_80021D38 *, u8 *);
#define gte_SetRotMatrix(r0) __asm__ volatile (   \
    "lw $12, 0( %0 );"                                  \
    "lw $13, 4( %0 );"                                  \
    "ctc2 $12, $0;"                                     \
    "ctc2 $13, $1;"                                     \
    "lw $12, 8( %0 );"                                  \
    "lw $13, 12( %0 );"                                 \
    "lw $14, 16( %0 );"                                 \
    "ctc2 $12, $2;"                                     \
    "ctc2 $13, $3;"                                     \
    "ctc2 $14, $4"                                      \
    :                                                   \
    : "r"( r0 )                                         \
    : "$12", "$13", "$14" )
#define gte_SetTransMatrix(r0) __asm__ volatile ( \
    "lw $12, 20( %0 );"                                 \
    "lw $13, 24( %0 );"                                 \
    "ctc2 $12, $5;"                                     \
    "lw $14, 28( %0 );"                                 \
    "ctc2 $13, $6;"                                     \
    "ctc2 $14, $7"                                      \
    :                                                   \
    : "r"( r0 )                                         \
    : "$12", "$13", "$14" )
#define gte_ldv0(r0) __asm__ volatile (           \
    "lwc2 $0, 0( %0 );"                                 \
    "lwc2 $1, 4( %0 )"                                  \
    :                                                   \
    : "r"( r0 ) )
#define gte_ldv3(r0, r1, r2) __asm__ volatile (   \
    "lwc2 $0, 0( %0 );"                                 \
    "lwc2 $1, 4( %0 );"                                 \
    "lwc2 $2, 0( %1 );"                                 \
    "lwc2 $3, 4( %1 );"                                 \
    "lwc2 $4, 0( %2 );"                                 \
    "lwc2 $5, 4( %2 )"                                  \
    :                                                   \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_rtps() __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt() __asm__ volatile ("nop;nop;rtpt")
#define gte_rt()   __asm__ volatile ("nop;nop;mvmva 1, 0, 0, 0, 0")
#define gte_stsxy(r0) __asm__ volatile (          \
    "swc2 $14, 0( %0 )"                                 \
    :                                                   \
    : "r"( r0 )                                         \
    : "memory" )
#define gte_stsxy3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $12, 0( %0 );"                                \
    "swc2 $13, 0( %1 );"                                \
    "swc2 $14, 0( %2 )"                                 \
    :                                                   \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )                   \
    : "memory" )
#define gte_stlvnl(r0) __asm__ volatile (         \
    "swc2 $25, 0( %0 );"                                \
    "swc2 $26, 4( %0 );"                                \
    "swc2 $27, 8( %0 )"                                 \
    :                                                   \
    : "r"( r0 )                                         \
    : "memory" )
#define gte_stflg(r0) __asm__ volatile (          \
    "cfc2 $12, $31;"                                    \
    "nop;"                                              \
    "sw $12, 0( %0 )"                                   \
    :                                                   \
    : "r"( r0 )                                         \
    : "$12", "memory" )
#define gte_stsz(r0) __asm__ volatile (           \
    "swc2 $19, 0( %0 )"                                 \
    :                                                   \
    : "r"( r0 )                                         \
    : "memory" )
#define gte_stszotz(r0) __asm__ volatile (        \
    "mfc2 $12, $19;"                                    \
    "nop;"                                              \
    "sra $12, $12, 2;"                                  \
    "sw $12, 0( %0 )"                                   \
    :                                                   \
    : "r"( r0 )                                         \
    : "$12", "memory" )

void func_80021D38(Obj_80021D38 *p)
{
    SVec_80021D38 sv[3];       /* sp+0x10 */
    DVec_80021D38 out[14];     /* sp+0x28 */
    Mtx_80021D38  mtx;         /* sp+0x60 */
    s32           vec[4];      /* sp+0x80 */
    s32           flag;        /* sp+0x90 */
    s32           otz;         /* sp+0x94 */
    s32           sz;          /* sp+0x98 */
    u8           *base;
    u8           *ot;
    u32           flags;
    u8           *pts;
    s32           i;
    s32           j;
    s32           k;
    s32           d;
    u32           t;

    base  = D_800AF630;
    ot    = D_800A6610 + (D_800B9A02 << 14);
    flags = p->flags;
    pts   = p->pts;

    if (flags & 0x40000) {
        out[0] = *(DVec_80021D38 *)&p->pos;
        otz = p->pos.vz;
        sz  = p->pos.vz << 2;
    } else {
        gte_SetRotMatrix(base + 0x18);
        gte_SetTransMatrix(base + 0x18);
        gte_ldv0(&p->pos);
        gte_rtps();
        gte_stsxy(&out[0]);
        gte_stflg(&flag);
        gte_stszotz(&otz);
        if (flag & ~0x1000) {
            return;
        }
        gte_stsz(&sz);
    }

    d = otz + 1;
    t = p->depth;
    if (t != 0) {
        if ((t & 0xC000) != 0) {
            if ((t & 0xC000) == 0xC000) {
                d -= (t & 0xFFF);
                if (d < 0) {
                    d = 0;
                }
            } else {
                d += (t & 0xFFF);
            }
        } else {
            d = t & 0xFFF;
        }
    }
    if ((u32)d >= 0x1000) {
        return;
    }

    mtx.m[0][0] = p->sx;
    mtx.m[0][1] = 0;
    mtx.m[0][2] = 0;
    mtx.m[1][0] = 0;
    mtx.m[1][1] = p->sy;
    mtx.m[1][2] = 0;
    mtx.m[2][0] = 0;
    mtx.m[2][1] = 0;
    mtx.m[2][2] = 0x1000;
    mtx.t[0] = mtx.t[1] = mtx.t[2] = 0;
    gte_SetRotMatrix(&mtx);
    gte_SetTransMatrix(&mtx);

    for (i = 0; i < 12; i += 3) {
        sv[0].vx = *(u16 *)(pts + (i << 2) + 0x10);
        sv[0].vy = *(u16 *)(pts + (i << 2) + 0x12);
        sv[0].vz = sz;
        j = i + 1;
        sv[1].vx = *(u16 *)(pts + (j << 2) + 0x10);
        sv[1].vy = *(u16 *)(pts + (j << 2) + 0x12);
        sv[1].vz = sz;
        k = i + 2;
        sv[2].vx = *(u16 *)(pts + (k << 2) + 0x10);
        sv[2].vy = *(u16 *)(pts + (k << 2) + 0x12);
        sv[2].vz = sz;

        if (flags & 0x40000) {
            gte_ldv0(&sv[0]);
            gte_rt();
            gte_stlvnl(vec);
            gte_stflg(&flag);
            out[j].vx = vec[0];
            out[j].vy = vec[1];

            gte_ldv0(&sv[1]);
            gte_rt();
            gte_stlvnl(vec);
            gte_stflg(&flag);
            out[k].vx = vec[0];
            out[k].vy = vec[1];

            gte_ldv0(&sv[2]);
            gte_rt();
            gte_stlvnl(vec);
            gte_stflg(&flag);
            out[i + 3].vx = vec[0];
            out[i + 3].vy = vec[1];
        } else {
            gte_ldv3(&sv[0], &sv[1], &sv[2]);
            gte_rtpt();
            gte_stsxy3(&out[i + 1], &out[i + 2], &out[i + 3]);
        }

        out[i + 1].vx += out[0].vx;
        out[i + 1].vy += out[0].vy;
        out[i + 2].vx += out[0].vx;
        out[i + 2].vy += out[0].vy;
        out[i + 3].vx += out[0].vx;
        out[i + 3].vy += out[0].vy;
    }

    func_800226C0(p, pts, out, ot + (d << 2));
}
