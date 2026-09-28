/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
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
".macro avsz3\n"
"    cop2op 0x15, 0x2D\n"
".endm\n"
".macro avsz4\n"
"    cop2op 0x16, 0x2E\n"
".endm\n"
);
/* func_8017C59C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*code)(unsigned short *);
extern short D_800B9A02;
extern s16 D_800B9A02;
extern s32 func_800491EC(void);
void func_8017BEBC(void *a0, void *a1, s32 a2);
typedef struct { u32 w0, w1, w2; } Prim59C;
typedef struct { u8 *vtx; u32 f4; u32 xx, yy, zz; Prim59C *prim, *end; } Cell59C;
typedef struct { s16 vx, vy; } DVEC2_C59C;
typedef struct { s16 vx, vy, vz, pad; } SVEC2_C59C;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_C59C;
typedef struct { u32 tag, rgbc; s16 x0, y0, x1, y1, x2, y2; } PF3_C59C;
typedef struct { u32 tag, rgbc; s16 x0, y0, x1, y1, x2, y2, x3, y3; } PF4_C59C;
typedef struct { u32 tag, rgbc; s16 x0, y0; u32 uvc0; s16 x1, y1; u32 uvp1; s16 x2, y2; u16 uv2, p2; } PFT3_C59C;
typedef struct { u32 tag, rgbc; s16 x0, y0; u32 uvc0; s16 x1, y1; u32 uvp1; s16 x2, y2; u16 uv2, p2; s16 x3, y3; u16 uv3, p3; } PFT4_C59C;

void func_8017C59C(s32 arg0)
{
    extern s32 func_800491EC(void);
    extern void func_800547D8(s32, MTX_C59C *);
    extern void func_80052E38(MTX_C59C *);
    extern void func_8017BEBC(void *, void *, s32);
    extern u8 D_80196260[];
    extern u8 *D_800A5E60;
    extern u8 D_800A6610[];
    extern short D_800B9A02;

    s16 rect[4];
    DVEC2_C59C tmpxy[4];
    SVEC2_C59C box[8];
    SVEC2_C59C sxy[8];
    MTX_C59C mtx;
    struct { long flag, opz, sz0, sz1, sz2, sz3; } g;

    s32 cx0, cx1, cy0, cy1, y, col;
    Cell59C **rowptr;
    Cell59C **p;
    Cell59C *cell;
    Prim59C *prim;
    Prim59C *end;
    u8 *pkt;
    u32 ot;
    u8 *vtx;
    u8 *va, *vb, *vc, *vd;
    u32 w, code;
    u32 wx, wy, wz;
    u32 xlo, xhi, ylo, yhi, zlo, zhi;
    s32 xa32, xb32, t32;
    s32 xmn1, xmx1, xmn2, xmx2;
    s32 ymn1, ymx1, ymn2, ymx2;
    s32 my, mny, mx, mn;

    func_800491EC();
    func_800547D8(arg0 + 0x10, &mtx);
    func_80052E38(&mtx);
    func_8017BEBC(D_80196260, rect, *(s32 *)(arg0 + 0x60));

    pkt = D_800A5E60;
    ot = (u32)&D_800A6610[(*(u16 *)&D_800B9A02) << 14];

    cx0 = (rect[0] + 0x4000) / 512;
    cx1 = (rect[0] + rect[2] + 0x4000) / 512 + 2;
    cx0 = (cx0 < 0) ? 0 : ((cx0 > 0x3F) ? 0x3F : cx0);
    cx1 = (cx1 < 0) ? 0 : ((cx1 > 0x3F) ? 0x3F : cx1);
    cy0 = (rect[1] + 0x4000) / 512 - 1;
    cy1 = (rect[1] + rect[3] + 0x4000) / 512 + 2;
    cy0 = (cy0 < 0) ? 0 : ((cy0 > 0x3F) ? 0x3F : cy0);
    cy1 = (cy1 < 0) ? 0 : ((cy1 > 0x3F) ? 0x3F : cy1);

    rowptr = (Cell59C **)(*(s32 *)(arg0 + 0xC)) + (cy0 * 64 + cx0);

    for (y = cy0; y < cy1; y++, rowptr += 0x40) {
        for (col = cx0, p = rowptr; col < cx1; col++, p++) {
            cell = *p;
            if (cell == 0) continue;

            wx = cell->xx;
            xlo = wx & 0xFFFF;
            xhi = wx >> 16;
            wy = cell->yy;
            ylo = wy & 0xFFFF;
            yhi = wy >> 16;
            wz = cell->zz;
            zlo = wz & 0xFFFF;
            zhi = wz >> 16;

            box[0].vx = xlo; box[0].vy = ylo; box[0].vz = zlo;
            box[1].vx = xhi; box[1].vy = ylo; box[1].vz = zlo;
            box[2].vx = xlo; box[2].vy = ylo; box[2].vz = zhi;
            box[3].vx = xhi; box[3].vy = ylo; box[3].vz = zhi;
            box[4].vx = xlo; box[4].vy = yhi; box[4].vz = zlo;
            box[5].vx = xhi; box[5].vy = yhi; box[5].vz = zlo;
            box[6].vx = xlo; box[6].vy = yhi; box[6].vz = zhi;
            box[7].vx = xhi; box[7].vy = yhi; box[7].vz = zhi;

            __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 8( %0 );" "lwc2 $3, 12( %0 );" "lwc2 $4, 16( %0 );" "lwc2 $5, 20( %0 )" : : "r"(  &box[0]  ) ) ;
            __asm__ volatile ("nop;nop;rtpt") ;
            __asm__ volatile ( "swc2 $12, 0( %0 );" "swc2 $13, 0( %1 );" "swc2 $14, 0( %2 )" : : "r"(  &sxy[0]  ), "r"(   &sxy[1]  ), "r"(   &sxy[2]  ) : "memory" ) ;
            __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  &box[3]  ) ) ;
            __asm__ volatile ("nop;nop;rtps") ;
            __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  &sxy[3]  ) : "memory" ) ;
            __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 8( %0 );" "lwc2 $3, 12( %0 );" "lwc2 $4, 16( %0 );" "lwc2 $5, 20( %0 )" : : "r"(  &box[4]  ) ) ;
            __asm__ volatile ("nop;nop;rtpt") ;
            __asm__ volatile ( "swc2 $12, 0( %0 );" "swc2 $13, 0( %1 );" "swc2 $14, 0( %2 )" : : "r"(  &sxy[4]  ), "r"(   &sxy[5]  ), "r"(   &sxy[6]  ) : "memory" ) ;
            __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  &box[7]  ) ) ;
            __asm__ volatile ("nop;nop;rtps") ;
            __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  &sxy[7]  ) : "memory" ) ;

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
            mn = xmn1;
            if (xmn2 < mn) mn = xmn2;
            mx = xmx1;
            if (mx < xmx2) mx = xmx2;
            if (mx < -0xA0) continue;
            if (!(mn < 0xA1)) continue;

            xa32 = sxy[0].vy;
            xb32 = sxy[1].vy;
            if (xb32 < xa32) { ymx1 = xa32; ymn1 = xb32; } else { ymn1 = xa32; ymx1 = xb32; }
            t32 = sxy[2].vy;
            if (ymx1 < t32) ymx1 = t32; else if (t32 < ymn1) ymn1 = t32;
            t32 = sxy[3].vy;
            if (ymx1 < t32) ymx1 = t32; else if (t32 < ymn1) ymn1 = t32;
            xa32 = sxy[4].vy;
            xb32 = sxy[5].vy;
            if (xb32 < xa32) { ymx2 = xa32; ymn2 = xb32; } else { ymn2 = xa32; ymx2 = xb32; }
            t32 = sxy[6].vy;
            if (ymx2 < t32) ymx2 = t32; else if (t32 < ymn2) ymn2 = t32;
            t32 = sxy[7].vy;
            if (ymx2 < t32) ymx2 = t32; else if (t32 < ymn2) ymn2 = t32;
            mny = ymn1;
            if (ymn2 < mny) mny = ymn2;
            my = ymx1;
            if (my < ymx2) my = ymx2;
            if (my < -0x78) continue;
            if (!(mny < 0x79)) continue;

            prim = cell->prim;
            end = cell->end;
            vtx = cell->vtx;
            while (prim < end) {
                w = prim->w1;
                va = vtx + (w & 0xFFFF);
                vb = vtx + (w >> 16);
                w = prim->w2;
                vc = vtx + (w & 0xFFFF);
                w = w >> 16;
                __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"(  va  ), "r"(   vb  ), "r"(   vc  ) ) ;
                __asm__ volatile ("nop;nop;rtpt") ;
                __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &g.flag  ) : "$12", "memory" ) ;
                if (!(g.flag & 0x7F85E000)) {
                    __asm__ volatile ("nop;nop;nclip") ;
                    code = w & 0xF;
                    vd = vtx + ((w & 0xFFF0) >> 1);
                    __asm__ volatile ( "swc2 $24, 0( %0 )" : : "r"(  &g.opz  ) : "memory" ) ;
                    if (g.opz > 0) {
                        switch (code) {
                        case 4:
                        case 5:
                            __asm__ volatile ( "swc2 $12, 8( %0 );" "swc2 $13, 12( %0 );" "swc2 $14, 16( %0 )" : : "r"(  pkt  ) : "memory" ) ;
                            __asm__ volatile ( "swc2 $17, 0( %0 );" "swc2 $18, 0( %1 );" "swc2 $19, 0( %2 )" : : "r"(  &g.sz0  ), "r"(   &g.sz1  ), "r"(   &g.sz2  ) : "memory" ) ;
                            if (((PFT3_C59C *)pkt)->x0 > ((PFT3_C59C *)pkt)->x1) {
                                mx = ((PFT3_C59C *)pkt)->x0;
                                mn = ((PFT3_C59C *)pkt)->x1;
                            } else {
                                mn = ((PFT3_C59C *)pkt)->x0;
                                mx = ((PFT3_C59C *)pkt)->x1;
                            }
                            if (((PFT3_C59C *)pkt)->x2 > mx) mx = ((PFT3_C59C *)pkt)->x2;
                            else if (((PFT3_C59C *)pkt)->x2 < mn) mn = ((PFT3_C59C *)pkt)->x2;
                            if (mx >= -0xA0 && mn < 0xA1) {
                                if (((PFT3_C59C *)pkt)->y0 > ((PFT3_C59C *)pkt)->y1) {
                                    my = ((PFT3_C59C *)pkt)->y0;
                                    mny = ((PFT3_C59C *)pkt)->y1;
                                } else {
                                    mny = ((PFT3_C59C *)pkt)->y0;
                                    my = ((PFT3_C59C *)pkt)->y1;
                                }
                                if (((PFT3_C59C *)pkt)->y2 > my) my = ((PFT3_C59C *)pkt)->y2;
                                else if (((PFT3_C59C *)pkt)->y2 < mny) mny = ((PFT3_C59C *)pkt)->y2;
                                if (my >= -0x78 && mny < 0x79) {
                                    s32 za;
                                    u32 *otp;
                                    if (g.sz0 > g.sz1) {
                                        za = g.sz0;
                                        if (za < g.sz2) za = g.sz2;
                                    } else {
                                        za = g.sz1;
                                        if (za < g.sz2) za = g.sz2;
                                    }
                                    g.opz = za;
                                    if (code != 4) g.opz = za + 0x200;
                                    ((PF3_C59C *)pkt)->rgbc = prim->w0;
                                    otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                    *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x4000000;
                                    *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                    pkt += 0x14;
                                }
                            }
                            break;
                        case 6:
                        case 7:
                            __asm__ volatile ( "swc2 $12, 0( %0 );" "swc2 $13, 4( %0 );" "swc2 $14, 8( %0 )" : : "r"(  &tmpxy[0]  ) : "memory" ) ;
                            __asm__ volatile ( "swc2 $17, 0( %0 );" "swc2 $18, 0( %1 );" "swc2 $19, 0( %2 )" : : "r"(  &g.sz0  ), "r"(   &g.sz1  ), "r"(   &g.sz2  ) : "memory" ) ;
                            if (tmpxy[0].vx > tmpxy[1].vx) {
                                mx = tmpxy[0].vx;
                                mn = tmpxy[1].vx;
                            } else {
                                mn = tmpxy[0].vx;
                                mx = tmpxy[1].vx;
                            }
                            if (tmpxy[2].vx > mx) mx = tmpxy[2].vx;
                            else if (tmpxy[2].vx < mn) mn = tmpxy[2].vx;
                            if (mx >= -0xA0 && mn < 0xA1) {
                                if (tmpxy[0].vy > tmpxy[1].vy) {
                                    my = tmpxy[0].vy;
                                    mny = tmpxy[1].vy;
                                } else {
                                    mny = tmpxy[0].vy;
                                    my = tmpxy[1].vy;
                                }
                                if (tmpxy[2].vy > my) my = tmpxy[2].vy;
                                else if (tmpxy[2].vy < mny) mny = tmpxy[2].vy;
                                if (my >= -0x78 && mny < 0x79) {
                                    s32 za;
                                    u32 *otp;
                                    u32 *tp;
                                    __asm__ volatile ("nop;nop;avsz3") ;
                                    if (g.sz0 > g.sz1) {
                                        za = g.sz0;
                                        if (za < g.sz2) za = g.sz2;
                                    } else {
                                        za = g.sz1;
                                        if (za < g.sz2) za = g.sz2;
                                    }
                                    g.opz = za;
                                    if (code != 6) g.opz = za + 0x200;
                                    *(u32 *)&((PFT3_C59C *)pkt)->x0 = *(u32 *)&tmpxy[0];
                                    *(u32 *)&((PFT3_C59C *)pkt)->x1 = *(u32 *)&tmpxy[1];
                                    *(u32 *)&((PFT3_C59C *)pkt)->x2 = *(u32 *)&tmpxy[2];
                                    tp = (u32 *)prim->w0;
                                    ((PFT3_C59C *)pkt)->rgbc = tp[0];
                                    ((PFT3_C59C *)pkt)->uvc0 = tp[1];
                                    ((PFT3_C59C *)pkt)->uvp1 = tp[2];
                                    ((PFT3_C59C *)pkt)->uv2 = tp[3];
                                    otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                    *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x7000000;
                                    *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                    pkt += 0x20;
                                }
                            }
                            break;
                        case 0:
                        case 1:
                            __asm__ volatile ( "swc2 $12, 8( %0 );" "swc2 $13, 12( %0 );" "swc2 $14, 16( %0 )" : : "r"(  pkt  ) : "memory" ) ;
                            __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  vd  ) ) ;
                            __asm__ volatile ("nop;nop;rtps") ;
                            if (((PF4_C59C *)pkt)->x0 > ((PF4_C59C *)pkt)->x1) {
                                mx = ((PF4_C59C *)pkt)->x0;
                                mn = ((PF4_C59C *)pkt)->x1;
                            } else {
                                mn = ((PF4_C59C *)pkt)->x0;
                                mx = ((PF4_C59C *)pkt)->x1;
                            }
                            if (((PF4_C59C *)pkt)->x2 > mx) mx = ((PF4_C59C *)pkt)->x2;
                            else if (((PF4_C59C *)pkt)->x2 < mn) mn = ((PF4_C59C *)pkt)->x2;
                            if (((PF4_C59C *)pkt)->y0 > ((PF4_C59C *)pkt)->y1) {
                                my = ((PF4_C59C *)pkt)->y0;
                                mny = ((PF4_C59C *)pkt)->y1;
                            } else {
                                mny = ((PF4_C59C *)pkt)->y0;
                                my = ((PF4_C59C *)pkt)->y1;
                            }
                            if (((PF4_C59C *)pkt)->y2 > my) my = ((PF4_C59C *)pkt)->y2;
                            else if (((PF4_C59C *)pkt)->y2 < mny) mny = ((PF4_C59C *)pkt)->y2;
                            __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &g.flag  ) : "$12", "memory" ) ;
                            if (!(g.flag & 0x7F85E000)) {
                                __asm__ volatile ( "swc2 $16, 0( %0 );" "swc2 $17, 0( %1 );" "swc2 $18, 0( %2 );" "swc2 $19, 0( %3 )" : : "r"(  &g.sz0  ), "r"(   &g.sz1  ), "r"(   &g.sz2  ), "r"(   &g.sz3  ) : "memory" ) ;
                                __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  (long *)&((PF4_C59C *)pkt)->x3  ) : "memory" ) ;
                                if (((PF4_C59C *)pkt)->x3 < mn) mn = ((PF4_C59C *)pkt)->x3;
                                else if (mx < ((PF4_C59C *)pkt)->x3) mx = ((PF4_C59C *)pkt)->x3;
                                if (mx >= -0xA0 && mn < 0xA1) {
                                    if (((PF4_C59C *)pkt)->y3 < mny) mny = ((PF4_C59C *)pkt)->y3;
                                    else if (my < ((PF4_C59C *)pkt)->y3) my = ((PF4_C59C *)pkt)->y3;
                                    if (my >= -0x78 && mny < 0x79) {
                                        s32 za, zb;
                                        u32 *otp;
                                        zb = g.sz2;
                                        if (zb < g.sz3) zb = g.sz3;
                                        za = g.sz0;
                                        if (za < g.sz1) za = g.sz1;
                                        if (za < zb) za = zb;
                                        g.opz = za;
                                        if (code != 0) g.opz = za + 0x200;
                                        ((PF4_C59C *)pkt)->rgbc = prim->w0;
                                        otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                        *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x5000000;
                                        *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                        pkt += 0x18;
                                    }
                                }
                            }
                            break;
                        case 2:
                        case 3:
                            __asm__ volatile ( "swc2 $12, 0( %0 );" "swc2 $13, 4( %0 );" "swc2 $14, 8( %0 )" : : "r"(  &tmpxy[0]  ) : "memory" ) ;
                            __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  vd  ) ) ;
                            __asm__ volatile ("nop;nop;rtps") ;
                            __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &g.flag  ) : "$12", "memory" ) ;
                            if (!(g.flag & 0x7F85E000)) {
                                __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  &tmpxy[3]  ) : "memory" ) ;
                                __asm__ volatile ( "swc2 $16, 0( %0 );" "swc2 $17, 0( %1 );" "swc2 $18, 0( %2 );" "swc2 $19, 0( %3 )" : : "r"(  &g.sz0  ), "r"(   &g.sz1  ), "r"(   &g.sz2  ), "r"(   &g.sz3  ) : "memory" ) ;
                                if (tmpxy[0].vx > tmpxy[1].vx) {
                                    mx = tmpxy[0].vx;
                                    mn = tmpxy[1].vx;
                                } else {
                                    mn = tmpxy[0].vx;
                                    mx = tmpxy[1].vx;
                                }
                                if (tmpxy[2].vx > mx) mx = tmpxy[2].vx;
                                else if (tmpxy[2].vx < mn) mn = tmpxy[2].vx;
                                if (tmpxy[3].vx > mx) mx = tmpxy[3].vx;
                                else if (tmpxy[3].vx < mn) mn = tmpxy[3].vx;
                                if (mx >= -0xA0 && mn < 0xA1) {
                                    if (tmpxy[0].vy > tmpxy[1].vy) {
                                        my = tmpxy[0].vy;
                                        mny = tmpxy[1].vy;
                                    } else {
                                        mny = tmpxy[0].vy;
                                        my = tmpxy[1].vy;
                                    }
                                    if (tmpxy[2].vy > my) my = tmpxy[2].vy;
                                    else if (tmpxy[2].vy < mny) mny = tmpxy[2].vy;
                                    if (tmpxy[3].vx > my) my = tmpxy[3].vx;
                                    else if (tmpxy[3].vx < mny) mny = tmpxy[3].vx;
                                    if (my >= -0x78 && mny < 0x79) {
                                        s32 za, zb;
                                        u32 *otp;
                                        u32 *tp;
                                        u32 uvw;
                                        __asm__ volatile ("nop;nop;avsz4") ;
                                        zb = g.sz2;
                                        if (zb < g.sz3) zb = g.sz3;
                                        za = g.sz0;
                                        if (za < g.sz1) za = g.sz1;
                                        if (za < zb) za = zb;
                                        g.opz = za;
                                        if (code != 2) g.opz = za + 0x200;
                                        *(u32 *)&((PFT4_C59C *)pkt)->x0 = *(u32 *)&tmpxy[0];
                                        *(u32 *)&((PFT4_C59C *)pkt)->x1 = *(u32 *)&tmpxy[1];
                                        *(u32 *)&((PFT4_C59C *)pkt)->x2 = *(u32 *)&tmpxy[2];
                                        *(u32 *)&((PFT4_C59C *)pkt)->x3 = *(u32 *)&tmpxy[3];
                                        tp = (u32 *)prim->w0;
                                        ((PFT4_C59C *)pkt)->rgbc = tp[0];
                                        ((PFT4_C59C *)pkt)->uvc0 = tp[1];
                                        ((PFT4_C59C *)pkt)->uvp1 = tp[2];
                                        uvw = tp[3];
                                        ((PFT4_C59C *)pkt)->uv2 = uvw;
                                        ((PFT4_C59C *)pkt)->uv3 = uvw >> 16;
                                        otp = (u32 *)(((g.opz >> 2) << 2) + ot);
                                        *(u32 *)pkt = (*otp & 0xFFFFFF) | 0x9000000;
                                        *otp = (*otp & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                                        pkt += 0x28;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
                prim++;
            }
        }
    }
    D_800A5E60 = pkt;
}
