/* SC02 resident image [8017F5B4,80180D50) at overlay base 0x80128158.
 * SHA256(span)=dcd3015741aa17209ece4a88cf6a7d7ceff9c28ea4a3865b481d2475813c309a.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F5B4 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro nclip\n"
    "    cop2op 0x14, 0x06, sf = 0\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

struct A {
    u16 unk00; u16 unk02; u16 unk04;   /* 0x10 0x12 0x14 */
    u16 unk06;                         /* 0x16 (gap) */
    u16 unk08; u16 unk0A; u16 unk0C;   /* 0x18 0x1A 0x1C */
    u16 unk0E;                         /* 0x1E (gap) */
    u8  unk10; u8 unk11; u8 unk12;     /* 0x20 0x21 0x22 */
    u8  unk13;                         /* 0x23 (gap) */
    u8  unk14; u8 unk15; u8 unk16;     /* 0x24 0x25 0x26 */
    u8  unk17;                         /* 0x27 (gap) */
    s32 unk18;                         /* 0x28 */
};
typedef struct {
    short v0;   /* 0x00 */
    short v1;   /* 0x02 */
    short v2;   /* 0x04 */
    short pad6; /* 0x06 */
    short w0;   /* 0x08 */
    short w1;   /* 0x0A */
    short w2;   /* 0x0C */
    short padE; /* 0x0E */
    unsigned char b10; /* 0x10 */
    unsigned char b11; /* 0x11 */
    unsigned char b12; /* 0x12 */
    unsigned char b13; /* 0x13 */
    unsigned char b14; /* 0x14 */
    unsigned char b15; /* 0x15 */
    unsigned char b16; /* 0x16 */
    unsigned char b17; /* 0x17 */
    int   w18; /* 0x18 */
} Prim;
typedef struct { s16 vx, vy; } DVECTOR2;
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX2;
typedef struct { u32 xx, yy, zz; u32 nprim; u32 *prim; } Part;
typedef struct { u32 tag, rgbc; s16 x0, y0; u32 uvc0; s16 x1, y1; u32 uvp1; s16 x2, y2; u16 uv2, p2; } PolyFT3;
typedef struct { u32 tag, rgbc; s16 x0, y0; u32 uvc0; s16 x1, y1; u32 uvp1; s16 x2, y2; u16 uv2, p2; s16 x3, y3; u16 uv3, p3; } PolyFT4;
typedef struct { s16 vx, vy, vz, pad; } SVECTOR2;
typedef void (*code)(unsigned short *);
typedef struct {
    u32 tag;
    u32 rgb0; s16 x0, y0; u32 uv0;
    u32 rgb1; s16 x1, y1; u32 uv1;
    u32 rgb2; s16 x2, y2; u16 uv2, p2;
} PolyGT3;
typedef struct {
    u32 tag;
    u32 rgb0; s16 x0, y0; u32 uv0;
    u32 rgb1; s16 x1, y1; u32 uv1;
    u32 rgb2; s16 x2, y2; u16 uv2, p2;
    u32 rgb3; s16 x3, y3; u16 uv3, p3;
} PolyGT4;
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
#define gte_ldv3c(r0) __asm__ volatile (         \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 );"                          \
    "lwc2 $2, 8( %0 );"                          \
    "lwc2 $3, 12( %0 );"                         \
    "lwc2 $4, 16( %0 );"                         \
    "lwc2 $5, 20( %0 )"                          \
    :                                            \
    : "r"( r0 ) )
#define gte_rtps() __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt() __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_stsxy(r0) __asm__ volatile (         \
    "swc2 $14, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsxy3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $12, 0( %0 );"                         \
    "swc2 $13, 0( %1 );"                         \
    "swc2 $14, 0( %2 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )            \
    : "memory" )
#define gte_stsxy3c(r0) __asm__ volatile (       \
    "swc2 $12, 0( %0 );"                         \
    "swc2 $13, 4( %0 );"                         \
    "swc2 $14, 8( %0 )"                          \
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
#define gte_stsz4(r0, r1, r2, r3) __asm__ volatile ( \
    "swc2 $16, 0( %0 );"                         \
    "swc2 $17, 0( %1 );"                         \
    "swc2 $18, 0( %2 );"                         \
    "swc2 $19, 0( %3 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ), "r"( r3 ) \
    : "memory" )
#define gte_stszotz(r0) __asm__ volatile (       \
    "mfc2 $12, $19;"                             \
    "nop;"                                       \
    "sra $12, $12, 2;"                           \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
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
#define BOXTEST(F, X, Y, Z) \
    if (lo_x < (X) && (X) < hi_x && lo_y < (Y) && (Y) < hi_y && lo_z < (Z) && (Z) < hi_z) F = 1
#define ATTEN(A, X, Y, Z)                                       \
    A = 0;                                                      \
    d = (X) - cx;   if (d < 0) d = cx - (X);                    \
    if (d < r) { A = 0x80; if (d >= rlo) A = r - d; }           \
    d = (Z) - cz;   if (d < 0) d = cz - (Z);                    \
    if (r < d) A = 0;                                           \
    else if (rlo < d) A = (A * (r - d)) >> 7;                   \
    d = (Y) - cy;   if (d < 0) d = cy - (Y);                    \
    if (r < d) A = 0;                                           \
    else if (rlo < d) A = (A * (r - d)) >> 7;                   \
    A = A + amb;                                                \
    if (A > 0x80) A = 0x80
extern s32 D_801B79E8;
extern u16 D_801B79EC, D_801B79EE, D_801B79F0;
extern s32 D_801B79F4;
extern s32 D_801B7A00;

void func_8017F5B4(s32 arg0, s32 arg1, s32 arg2)
{
    typedef struct { u32 w0, w1, w2; } Prim;

    extern s32 func_800491EC(void);
    extern void func_800547D8(s32, MATRIX2 *);
    extern void func_80052E38(MATRIX2 *);
    extern u8 *D_800A5E60;
    extern u8 D_800A6610[];
    extern u8 D_800AF630[];

    DVECTOR2 tmpxy[4];
    SVECTOR2 box[8];
    SVECTOR2 sxy[8];
    MATRIX2 mtx;
    struct { long otz, flag, opz, sz0, sz1, sz2, sz3; } g;

    s32 lim;
    s32 j;
    u32 i;
    u8 *vd;
    u32 ot;
    u8 *pkt;
    s16 x3, z3, y3;
    Prim *prim;
    u32 nprim;
    u8 *vtx;
    s32 nparts;
    Part *part;
    s16 lo_x, hi_x, lo_y, hi_y, lo_z, hi_z;
    s16 cx, cy, cz;
    s32 r, rlo;
    u32 col;
    u8 *va, *vb, *vc;
    u32 w; s32 code;
    u32 vw, vzw;
    u32 wx, wy, wz;
    s32 xa32, xb32, t32;
    s32 xmn1, xmx1, xmn2, xmx2;
    s32 mnc, mxc;
    s16 my, mny, mx, mn;
    u8 *base;
    s32 f0;
    s16 x0, y0, z0, x1, y1, z1, x2, y2, z2;
    s32 d;
    s32 c0, c1, c2, c3;
    s32 za, zb;
    u32 *tp;
    u32 cb;
    u32 rgbw;
    u32 uvw;
    s32 amb;

    base = D_800AF630;

    if (*(s32 *)arg0 != 0) {
        return;
    }

    lim = func_800491EC() + *(s32 *)(arg0 + 0x64);
    func_800547D8(arg2, &mtx);
    func_80052E38(&mtx);

    if (D_801B79E8) {
        cx = D_801B79EC;
        cy = D_801B79EE;
        r = D_801B79F4;
        rlo = r - 0x80;
        amb = D_801B7A00;
        cz = D_801B79F0;
        if (amb < 0x60) {
            col = amb | 0x600000 | (amb << 8);
        } else {
            col = amb | (amb << 8) | (amb << 16);
        }
    } else {
        cz = 0x6000;
        cy = 0x6000;
        cx = 0x6000;
        r = 0x100;
        rlo = 0x80;
        amb = 0;
        col = 0;
    }

    lo_x = cx - r;  hi_x = cx + r;
    lo_y = cy - r;  hi_y = cy + r;
    lo_z = cz - r;  hi_z = cz + r;

    pkt = D_800A5E60;
    part = (Part *)(arg1 + 0x14);
    nparts = *(s32 *)(arg1 + 8);
    vtx = *(u8 **)(arg1 + 0x10);
    ot = (u32)&D_800A6610[(*(u16 *)(base + 0xA3D2)) << 14];

    for (j = 0; j < nparts; j++, part++) {
        wx = part->xx;
        mn = wx;
        mx = wx >> 16;
        wy = part->yy;
        mny = wy;
        my = wy >> 16;
        wz = part->zz;
        box[0].vx = mn; box[0].vy = mny;
        box[1].vx = mx; box[1].vy = mny;
        box[2].vx = mn; box[2].vy = mny;
        box[3].vx = mx; box[3].vy = mny;
        box[4].vx = mn; box[4].vy = my;
        box[5].vx = mx; box[5].vy = my;
        box[6].vx = mn; box[6].vy = my;
        box[7].vx = mx; box[7].vy = my;
        wy = wz >> 16;
        box[0].vz = wz;
        box[1].vz = wz;
        box[4].vz = wz;
        box[5].vz = wz;
        box[2].vz = wy;
        box[3].vz = wy;
        box[6].vz = wy;
        box[7].vz = wy;

        gte_ldv3c(&box[0]);
        gte_rtpt();
        gte_stsxy3(&sxy[0], &sxy[1], &sxy[2]);
        gte_ldv0(&box[3]);
        gte_rtps();
        gte_stsxy(&sxy[3]);
        gte_ldv3c(&box[4]);
        gte_rtpt();
        gte_stsxy3(&sxy[4], &sxy[5], &sxy[6]);
        gte_ldv0(&box[7]);
        gte_rtps();
        gte_stsxy(&sxy[7]);
        gte_stszotz(&g.otz);

        if (lim >= g.otz) {
            xa32 = sxy[0].vx;
            xb32 = sxy[1].vx;
            if (xb32 < xa32) { xmx1 = xa32; xmn1 = xb32; } else { xmn1 = xa32; xmx1 = xb32; }
            t32 = sxy[2].vx;
            if (xmx1 < t32) xmx1 = t32; else if (t32 < xmn1) xmn1 = t32;
            t32 = sxy[3].vx;
            if (xmx1 < t32) xmx1 = t32; else if (t32 < xmn1) xmn1 = t32;
            xa32 = sxy[4].vx;
            xb32 = sxy[5].vx;
            if (xb32 < xa32) { xmx2 = xa32; xmn2 = xb32; } else { xmn2 = xa32; xmx2 = xb32; }
            t32 = sxy[6].vx;
            if (xmx2 < t32) xmx2 = t32; else if (t32 < xmn2) xmn2 = t32;
            t32 = sxy[7].vx;
            if (xmx2 < t32) xmx2 = t32; else if (t32 < xmn2) xmn2 = t32;
            mnc = xmn1;
            if (xmn2 < xmn1) mnc = xmn2;
            mxc = xmx1;
            if (mxc < xmx2) mxc = xmx2;
            if ((s16)mxc >= -0xA0 && (s16)mnc < 0xA1) {
                xa32 = sxy[0].vy;
                xb32 = sxy[1].vy;
                if (xb32 < xa32) { xmx1 = xa32; xmn1 = xb32; } else { xmn1 = xa32; xmx1 = xb32; }
                t32 = sxy[2].vy;
                if (xmx1 < t32) xmx1 = t32; else if (t32 < xmn1) xmn1 = t32;
                t32 = sxy[3].vy;
                if (xmx1 < t32) xmx1 = t32; else if (t32 < xmn1) xmn1 = t32;
                xa32 = sxy[4].vy;
                xb32 = sxy[5].vy;
                if (xb32 < xa32) { xmx2 = xa32; xmn2 = xb32; } else { xmn2 = xa32; xmx2 = xb32; }
                t32 = sxy[6].vy;
                if (xmx2 < t32) xmx2 = t32; else if (t32 < xmn2) xmn2 = t32;
                t32 = sxy[7].vy;
                if (xmx2 < t32) xmx2 = t32; else if (t32 < xmn2) xmn2 = t32;
                mnc = xmn1;
                if (xmn2 < xmn1) mnc = xmn2;
                mxc = xmx1;
                if (mxc < xmx2) mxc = xmx2;
                if ((s16)mxc >= -0x6E && (s16)mnc < 0x6F) {
                    prim = (Prim *)part->prim;
                    nprim = part->nprim;
                    for (i = 0; i < nprim; i++, prim++) {
                        w = prim->w1;
                        va = vtx + (w & 0xFFFF);
                        vb = vtx + (w >> 16);
                        w = prim->w2;
                        vc = vtx + (w & 0xFFFF);
                        w = w >> 16;
                        gte_ldv3(va, vb, vc);
                        gte_rtpt();
                        gte_stflg(&g.flag);
                        if (!(g.flag & 0x7F85E000)) {
                            gte_nclip();
                            code = w & 7;
                            vd = vtx + (w & 0xFFF8);
                            gte_stopz(&g.opz);
                            if (g.opz > 0) {
                                switch (code) {
                                case 6:
                                case 7:
                                    /* ---------------- TRI (FT3 / GT3) ---------------- */
                                    gte_stsxy3c(&tmpxy[0]);
                                    gte_stsz3(&g.sz0, &g.sz1, &g.sz2);
                                    if (tmpxy[0].vx > tmpxy[1].vx) { mx = tmpxy[0].vx; mn = tmpxy[1].vx; }
                                    else { mn = tmpxy[0].vx; mx = tmpxy[1].vx; }
                                    if (tmpxy[2].vx > mx) mx = tmpxy[2].vx;
                                    else if (tmpxy[2].vx < mn) mn = tmpxy[2].vx;
                                    if (mx >= -0xA0 && mn < 0xA1) {
                                        if (tmpxy[0].vy > tmpxy[1].vy) { my = tmpxy[0].vy; mny = tmpxy[1].vy; }
                                        else { mny = tmpxy[0].vy; my = tmpxy[1].vy; }
                                        if (tmpxy[2].vy > my) my = tmpxy[2].vy;
                                        else if (tmpxy[2].vy < mny) mny = tmpxy[2].vy;
                                        if (my >= -0x6E && mny < 0x6F) {
                                            __asm__ __volatile__ ("" :: "r" (mny));
                                            if (g.sz0 > g.sz1) { za = g.sz0; if (za < g.sz2) za = g.sz2; }
                                            else { za = g.sz1; if (za < g.sz2) za = g.sz2; }
                                            g.opz = za;

                                            f0 = 0;

                                            vw = *(u32 *)va;
                                            vzw = *(u32 *)(va + 4);
                                            x0 = vw; y0 = vw >> 16; z0 = vzw;
                                            BOXTEST(f0, x0, y0, z0);
                                            vw = *(u32 *)vb;
                                            vzw = *(u32 *)(vb + 4);
                                            x1 = vw; y1 = vw >> 16; z1 = vzw;
                                            BOXTEST(f0, x1, y1, z1);
                                            vw = *(u32 *)vc;
                                            vzw = *(u32 *)(vc + 4);
                                            x2 = vw; y2 = vw >> 16; z2 = vzw;
                                            BOXTEST(f0, x2, y2, z2);

                                            if (f0) {
                                                u32 *otp;
                                                ATTEN(c0, x0, y0, z0);
                                                ATTEN(c1, x1, y1, z1);
                                                ATTEN(c2, x2, y2, z2);

                                                *(u32 *)&((PolyGT3 *)pkt)->x0 = *(u32 *)&tmpxy[0];
                                                *(u32 *)&((PolyGT3 *)pkt)->x1 = *(u32 *)&tmpxy[1];
                                                *(u32 *)&((PolyGT3 *)pkt)->x2 = *(u32 *)&tmpxy[2];
                                                tp = (u32 *)prim->w0;
                                                cb = (tp[0] & 0x2000000) | 0x34000000;
                                                rgbw = cb | c0 | (c0 << 8) | 0x800000;
                                                ((PolyGT3 *)pkt)->rgb0 = rgbw;
                                                rgbw = cb | c1 | (c1 << 8) | 0x800000;
                                                ((PolyGT3 *)pkt)->rgb1 = rgbw;
                                                rgbw = cb | c2 | (c2 << 8) | 0x800000;
                                                ((PolyGT3 *)pkt)->rgb2 = rgbw;
                                                ((PolyGT3 *)pkt)->uv0 = tp[1];
                                                ((PolyGT3 *)pkt)->uv1 = tp[2];
                                                ((PolyGT3 *)pkt)->uv2 = tp[3];
                                                otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                                *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x9000000;
                                                *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                                pkt += 0x28;
                                            } else {
                                                u32 *otp;
                                                *(u32 *)&((PolyFT3 *)pkt)->x0 = *(u32 *)&tmpxy[0];
                                                *(u32 *)&((PolyFT3 *)pkt)->x1 = *(u32 *)&tmpxy[1];
                                                *(u32 *)&((PolyFT3 *)pkt)->x2 = *(u32 *)&tmpxy[2];
                                                tp = (u32 *)prim->w0;
                                                cb = (tp[0] & 0xFF000000) | col;
                                                ((PolyFT3 *)pkt)->rgbc = cb;
                                                ((PolyFT3 *)pkt)->uvc0 = tp[1];
                                                ((PolyFT3 *)pkt)->uvp1 = tp[2];
                                                ((PolyFT3 *)pkt)->uv2 = tp[3];
                                                otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                                *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x7000000;
                                                *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                                pkt += 0x20;
                                            }
                                        }
                                    }
                                    break;
                                case 2:
                                case 3:
                                    /* ---------------- QUAD (FT4 / GT4) ---------------- */
                                    gte_stsxy3c(&tmpxy[0]);
                                    gte_ldv0(vd);
                                    gte_rtps();
                                    if (tmpxy[0].vx > tmpxy[1].vx) { mx = tmpxy[0].vx; mn = tmpxy[1].vx; }
                                    else { mn = tmpxy[0].vx; mx = tmpxy[1].vx; }
                                    if (tmpxy[2].vx > mx) mx = tmpxy[2].vx;
                                    else if (tmpxy[2].vx < mn) mn = tmpxy[2].vx;
                                    if (tmpxy[0].vy > tmpxy[1].vy) { my = tmpxy[0].vy; mny = tmpxy[1].vy; }
                                    else { mny = tmpxy[0].vy; my = tmpxy[1].vy; }
                                    if (tmpxy[2].vy > my) my = tmpxy[2].vy;
                                    else if (tmpxy[2].vy < mny) mny = tmpxy[2].vy;
                                    gte_stflg(&g.flag);
                                    if (!(g.flag & 0x7F85E000)) {
                                        gte_stsz4(&g.sz0, &g.sz1, &g.sz2, &g.sz3);
                                        gte_stsxy((long *)&((PolyFT4 *)pkt)->x3);
                                        if (((PolyFT4 *)pkt)->x3 < mn) mn = ((PolyFT4 *)pkt)->x3;
                                        else if (mx < ((PolyFT4 *)pkt)->x3) mx = ((PolyFT4 *)pkt)->x3;
                                        if (mx >= -0xA0 && mn < 0xA1) {
                                            if (((PolyFT4 *)pkt)->y3 < mny) mny = ((PolyFT4 *)pkt)->y3;
                                            else if (my < ((PolyFT4 *)pkt)->y3) my = ((PolyFT4 *)pkt)->y3;
                                            if (my >= -0x6E && mny < 0x6F) {
                                                zb = g.sz2;
                                                if (zb < g.sz3) zb = g.sz3;
                                                za = g.sz0;
                                                if (za < g.sz1) za = g.sz1;
                                                if (za < zb) za = zb;
                                                g.opz = za;

                                                f0 = 0;

                                                vw = *(u32 *)va;
                                                vzw = *(u32 *)(va + 4);
                                                x0 = vw; y0 = vw >> 16; z0 = vzw;
                                                BOXTEST(f0, x0, y0, z0);
                                                vw = *(u32 *)vb;
                                                vzw = *(u32 *)(vb + 4);
                                                x1 = vw; y1 = vw >> 16; z1 = vzw;
                                                BOXTEST(f0, x1, y1, z1);
                                                vw = *(u32 *)vc;
                                                vzw = *(u32 *)(vc + 4);
                                                x2 = vw; y2 = vw >> 16; z2 = vzw;
                                                BOXTEST(f0, x2, y2, z2);
                                                vw = *(u32 *)vd;
                                                vzw = *(u32 *)(vd + 4);
                                                x3 = vw; y3 = vw >> 16; z3 = vzw;
                                                BOXTEST(f0, x3, y3, z3);

                                                if (f0) {
                                                    u32 *otp;
                                                    ATTEN(c0, x0, y0, z0);
                                                    ATTEN(c1, x1, y1, z1);
                                                    ATTEN(c2, x2, y2, z2);
                                                    ATTEN(c3, x3, y3, z3);

                                                    *(u32 *)&((PolyGT4 *)pkt)->x0 = *(u32 *)&tmpxy[0];
                                                    *(u32 *)&((PolyGT4 *)pkt)->x1 = *(u32 *)&tmpxy[1];
                                                    *(u32 *)&((PolyGT4 *)pkt)->x2 = *(u32 *)&tmpxy[2];
                                                    gte_stsxy((long *)&((PolyGT4 *)pkt)->x3);
                                                    tp = (u32 *)prim->w0;
                                                    cb = (tp[0] & 0x2000000) | 0x3C000000;
                                                    rgbw = cb | c0 | (c0 << 8) | 0x800000;
                                                    ((PolyGT4 *)pkt)->rgb0 = rgbw;
                                                    rgbw = cb | c1 | (c1 << 8) | 0x800000;
                                                    ((PolyGT4 *)pkt)->rgb1 = rgbw;
                                                    rgbw = cb | c2 | (c2 << 8) | 0x800000;
                                                    ((PolyGT4 *)pkt)->rgb2 = rgbw;
                                                    rgbw = cb | c3 | (c3 << 8) | 0x800000;
                                                    ((PolyGT4 *)pkt)->rgb3 = rgbw;
                                                    ((PolyGT4 *)pkt)->uv0 = tp[1];
                                                    ((PolyGT4 *)pkt)->uv1 = tp[2];
                                                    uvw = tp[3];
                                                    ((PolyGT4 *)pkt)->uv2 = uvw;
                                                    ((PolyGT4 *)pkt)->uv3 = uvw >> 16;
                                                    otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                                    *(u32 *)pkt = (*otp & 0xFFFFFF) | 0xC000000;
                                                    *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                                    pkt += 0x34;
                                                } else {
                                                    u32 *otp;
                                                    *(u32 *)&((PolyFT4 *)pkt)->x0 = *(u32 *)&tmpxy[0];
                                                    *(u32 *)&((PolyFT4 *)pkt)->x1 = *(u32 *)&tmpxy[1];
                                                    *(u32 *)&((PolyFT4 *)pkt)->x2 = *(u32 *)&tmpxy[2];
                                                    tp = (u32 *)prim->w0;
                                                    cb = (tp[0] & 0xFF000000) | col;
                                                    ((PolyFT4 *)pkt)->rgbc = cb;
                                                    ((PolyFT4 *)pkt)->uvc0 = tp[1];
                                                    ((PolyFT4 *)pkt)->uvp1 = tp[2];
                                                    uvw = tp[3];
                                                    ((PolyFT4 *)pkt)->uv2 = uvw;
                                                    ((PolyFT4 *)pkt)->uv3 = uvw >> 16;
                                                    otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                                    *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x9000000;
                                                    *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                                    pkt += 0x28;
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    D_800A5E60 = pkt;
}
