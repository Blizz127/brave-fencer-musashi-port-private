/* Main-exec range [8001EA14,8001EFE0) from the SLUS executable.
 * SHA256(span)=72eeb66887ade1d48f34c4ca51669a664d424c094c3a656484deb65d2a458d3c.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001EA14 - byte-exact against retail at -O2 (tools/register_match.py). */
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

#define gte_SetRotMatrix_EA14(r0) __asm__ volatile ( \
    "lw $12, 0( %0 );"                               \
    "lw $13, 4( %0 );"                               \
    "ctc2 $12, $0;"                                  \
    "ctc2 $13, $1;"                                  \
    "lw $12, 8( %0 );"                               \
    "lw $13, 12( %0 );"                              \
    "lw $14, 16( %0 );"                              \
    "ctc2 $12, $2;"                                  \
    "ctc2 $13, $3;"                                  \
    "ctc2 $14, $4"                                   \
    :                                                \
    : "r"( r0 )                                      \
    : "$12", "$13", "$14" )
#define gte_SetTransMatrix_EA14(r0) __asm__ volatile ( \
    "lw $12, 20( %0 );"                              \
    "lw $13, 24( %0 );"                              \
    "ctc2 $12, $5;"                                  \
    "lw $14, 28( %0 );"                              \
    "ctc2 $13, $6;"                                  \
    "ctc2 $14, $7"                                   \
    :                                                \
    : "r"( r0 )                                      \
    : "$12", "$13", "$14" )
#define gte_ldv0_EA14(r0) __asm__ volatile (         \
    "lwc2 $0, 0( %0 );"                              \
    "lwc2 $1, 4( %0 )"                               \
    :                                                \
    : "r"( r0 ) )
#define gte_ldv3_EA14(r0, r1) __asm__ volatile (     \
    "lwc2 $0, 0( %0 );"                              \
    "lwc2 $1, 4( %0 );"                              \
    "lwc2 $2, 0( %1 );"                              \
    "lwc2 $3, 4( %1 );"                              \
    "lwc2 $4, 0( %1 );"                              \
    "lwc2 $5, 4( %1 )"                               \
    :                                                \
    : "r"( r0 ), "r"( r1 ) )
#define gte_rtps_EA14() __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt_EA14() __asm__ volatile ("nop;nop;rtpt")
#define gte_stsxy_EA14(r0) __asm__ volatile (        \
    "swc2 $14, 0( %0 )"                              \
    :                                                \
    : "r"( r0 )                                      \
    : "memory" )
#define gte_stsxy0_EA14(r0) __asm__ volatile (       \
    "swc2 $12, 0( %0 )"                              \
    :                                                \
    : "r"( r0 )                                      \
    : "memory" )
#define gte_stsxy1_EA14(r0) __asm__ volatile (       \
    "swc2 $13, 0( %0 )"                              \
    :                                                \
    : "r"( r0 )                                      \
    : "memory" )
#define gte_stflg_EA14(r0) __asm__ volatile (        \
    "cfc2 $12, $31;"                                 \
    "nop;"                                           \
    "sw $12, 0( %0 )"                                \
    :                                                \
    : "r"( r0 )                                      \
    : "$12", "memory" )
#define gte_stsz_EA14(r0) __asm__ volatile (         \
    "swc2 $19, 0( %0 )"                              \
    :                                                \
    : "r"( r0 )                                      \
    : "memory" )
#define gte_stszotz_EA14(r0) __asm__ volatile (      \
    "mfc2 $12, $19;"                                 \
    "nop;"                                           \
    "sra $12, $12, 2;"                               \
    "sw $12, 0( %0 )"                                \
    :                                                \
    : "r"( r0 )                                      \
    : "$12", "memory" )
#define gte_rt_EA14(r1, r0) __asm__ volatile (       \
    "lwc2 $0, 0( %1 );"                              \
    "lwc2 $1, 4( %1 );"                              \
    "nop;"                                           \
    "nop;"                                           \
    "mvmva 1, 0, 0, 3, 0;"                           \
    "swc2 $25, 0( %0 );"                             \
    "swc2 $26, 4( %0 );"                             \
    "swc2 $27, 8( %0 )"                              \
    :                                                \
    : "r"( r1 ), "r"( r0 )                           \
    : "memory" )
typedef struct { u16 vx, vy, vz, pad; }  SV_EA14;
typedef struct { s32 vx, vy, vz, pad; }  VC_EA14;
typedef struct { s16 m[3][3]; s32 t[3]; } MT_EA14;
typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ SV_EA14 unk08;
    /* 0x10 */ u8 unk10[8];
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u8 unk1C[4];
    /* 0x20 */ u8 *unk20;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;
    /* 0x28 */ u16 unk28;
    /* 0x2A */ u16 unk2A;
    /* 0x2C */ u16 unk2C;
} Ent_EA14;
typedef struct {
    /* 0x00 */ u16 type;
    /* 0x02 */ u8  w;
    /* 0x03 */ u8  h;
    /* 0x04 */ s16 x;
    /* 0x06 */ u16 y;
    /* 0x08 */ u16 u;
    /* 0x0A */ u16 v;
} Cell_EA14;
extern u8  D_800AF648;
extern u16 D_800B9A02;
extern u8  D_800A6610[];
extern u8 *D_800A5E60;
extern void func_8001F730(s32, void *, void *);
#define B(o) (*(u8  *)(pk + (o)))
#define H(o) (*(u16 *)(pk + (o)))
#define W(o) (*(u32 *)(pk + (o)))

void func_8001EA14(Ent_EA14 *p)
{
    MT_EA14 m;      /* 0x10 */
    SV_EA14 sxy;    /* 0x30 */
    SV_EA14 v[2];   /* 0x38 */
    VC_EA14 vo;     /* 0x48 */
    s32 flag;       /* 0x58 */
    s32 sz;         /* 0x5C */
    s32 otz;        /* 0x60 */
    u32 sc0;        /* 0x64 */
    u32 sc1;        /* 0x68 */
    Cell_EA14 *e;
    u32 fl;
    s32 z;
    s32 rot;
    s32 shift;
    s32 fpv;
    u8 mode;
    s32 base;
    u8 *ob;
    u32 *ot;
    u8 *pk;
    u8 *mp;
    u32 sx, sy;
    u16 ux, uy;
    s32 cl;
    s32 xs;
    register s32 vv __asm__("$2");
    u32 uyx;
    u32 t;
    u8 c8;

    e = (Cell_EA14 *)p->unk20;
    fl = p->unk04;

    mp = &D_800AF648;
    gte_SetRotMatrix_EA14(mp);
    gte_SetTransMatrix_EA14(mp);
    gte_ldv0_EA14(&p->unk08);
    gte_rtps_EA14();
    gte_stsxy_EA14(&sxy);
    gte_stflg_EA14(&flag);
    gte_stsz_EA14(&sz);
    gte_stszotz_EA14(&otz);

    if ((flag & ~0x1000) != 0) {
        return;
    }

    z = otz + 1;
    ob = (D_800B9A02 << 14) + D_800A6610;
    if ((p->unk2C & 0xC000) != 0) {
        if ((p->unk2C & 0xC000) == 0xC000) {
            z -= (p->unk2C & 0xFFF);
            if (z < 0) {
                z = 0;
            }
        } else {
            z += (p->unk2C & 0xFFF);
        }
    }
    if ((u32)z >= 0x1000) {
        return;
    }

    m.m[0][0] = p->unk18;
    m.m[0][1] = 0;
    m.m[0][2] = 0;
    m.m[1][0] = 0;
    mode = (fl >> 28) & 3;
    m.m[1][1] = p->unk1A;
    m.m[1][2] = 0;
    m.m[2][0] = 0;
    m.m[2][1] = 0;
    m.m[2][2] = 0x1000;
    m.t[0] = m.t[1] = m.t[2] = 0;
    rot = (fl >> 24) & 3;
    shift = 2 - rot;

    gte_SetRotMatrix_EA14(&m);
    gte_SetTransMatrix_EA14(&m);

    fpv = rot << 7;
    base = fpv | 0x20;

    do {
        t = e->type;
        if (t != 8) {
            pk = D_800A5E60;
            xs = e->x >> shift;
            sx = p->unk28 + xs;
            ux = sx;
            sy = p->unk2A + e->y;
            uy = sy;
            D_800A5E60 = pk + 0x28;
            *(u8 *)(pk + 3) = 9;
            B(7) = 0x2C;
            if ((fl & 0x40000000) != 0) {
                B(7) = 0x2E;
                H(0x16) = (fpv | (mode << 5)) | ((sy & 0x100) >> 4) |
                              ((sx & 0x3C0) >> 6) | ((sy & 0x200) << 2);
            } else {
                H(0x16) = base | ((sy & 0x100) >> 4) |
                              ((sx & 0x3C0) >> 6) | ((sy & 0x200) << 2);
            }
            B(7) |= (fl & 0x40) >> 6;
            B(0xC) = (ux - ((H(0x16) & 0xF) << 6)) << shift;
            uyx = uy;
            vv = (H(0x16) & 0x10) ? (uyx - 0x100) : uyx;
            B(0xD) = vv;
            B(0x14) = B(0xC) + e->w - 1;
            B(0x15) = B(0xD);
            B(0x1C) = B(0xC);
            B(0x1D) = B(0xD) + e->h - 1;
            B(0x24) = B(0x14);
            B(0x25) = B(0x1D);
            cl = (p->unk27 + 0x100) << 6;
            H(0xE) = (p->unk27 < 0xE0) ? (cl | 0x16) : (cl | 0x10);
            B(4) = p->unk24;
            B(5) = p->unk25;
            B(6) = p->unk26;
            v[0].vx = e->u;
            v[0].vy = e->v;
            v[0].vz = sz;
            v[1].vx = e->w;
            v[1].vy = e->h;
            v[1].vz = sz;
            if (p->unk02 == 3) {
                gte_ldv3_EA14(&v[0], &v[1]);
                gte_rtpt_EA14();
                gte_stsxy0_EA14(&sc0);
                gte_stsxy1_EA14(&sc1);
                H(8) = sxy.vx + ((u16 *)&sc0)[0];
                H(0xA) = sxy.vy + ((u16 *)&sc0)[1];
                H(0x10) = H(8) + ((u16 *)&sc1)[0];
                H(0x1A) = H(0xA) + ((u16 *)&sc1)[1];
            } else {
                gte_rt_EA14(&vo, &v[0]);
                H(8) = sxy.vx + vo.vx;
                H(0xA) = sxy.vy + vo.vy;
                gte_rt_EA14(&vo, &v[1]);
                H(0x10) = H(8) + vo.vx;
                H(0x1A) = H(0xA) + vo.vy;
            }
            H(0x12) = H(0xA);
            H(0x18) = H(8);
            H(0x20) = H(0x10);
            H(0x22) = H(0x1A);
            if ((p->unk04 & 0x8000000) != 0) {
                func_8001F730((s32)p + 0x10, &sxy, pk);
            }
            ot = (u32 *)((z << 2) + (s32)ob);
            W(0) = (W(0) & 0xFF000000) | (*ot & 0xFFFFFF);
            *ot = (*ot & 0xFF000000) | ((u32)pk & 0xFFFFFF);
        }
        c8 = *(u8 *)e;
        e++;
    } while (c8 != 0xFF);
}
