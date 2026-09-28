/* Main-exec range [8001DA34,8001E094) from the SLUS executable.
 * SHA256(span)=e21ef1a64e3c389dc8178efe634bf1d1769feebb0e6b66f05052b9b0997f6255.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001DA34 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro nccs\n"
    "    cop2op 0x10, 0x1B, lm = 1\n"
    ".endm\n"
    ".macro mvmva sf, mx, v, cv, lm\n"
    "    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MtxDA34;
typedef struct { s16 vx, vy, vz, pad; } SVecDA34;
typedef struct { u8 r, g, b, cd; } CVecDA34;
typedef struct {
    u16 id;   /* 0x00 */
    u8  w;    /* 0x02 */
    u8  h;    /* 0x03 */
    s16 dx;   /* 0x04 */
    u16 dy;   /* 0x06 */
    u16 px;   /* 0x08 */
    u16 py;   /* 0x0A */
} RecDA34;
extern MtxDA34 D_800A63F0;
extern u16 D_800B9A02;
extern u8 D_800A6610[];
extern u8 *D_800A5E60;
extern void func_8004978C(s16 *a0, void *a1);
extern void func_8004917C();
void func_8001E094(s32 arg0);
void func_8001E378(s32 param_1);
s32 func_8001E668();
#define SETROT_DA34(r0) __asm__ volatile (               \
    "lw $12, 0( %0 );"                                   \
    "lw $13, 4( %0 );"                                   \
    "ctc2 $12, $0;"                                      \
    "ctc2 $13, $1;"                                      \
    "lw $12, 8( %0 );"                                   \
    "lw $13, 12( %0 );"                                  \
    "lw $14, 16( %0 );"                                  \
    "ctc2 $12, $2;"                                      \
    "ctc2 $13, $3;"                                      \
    "ctc2 $14, $4"                                       \
    : : "r"( r0 ) : "$12", "$13", "$14" )
#define LDCLMV_DA34(r0) __asm__ volatile (               \
    "lhu $12, 0( %0 );"                                  \
    "lhu $13, 6( %0 );"                                  \
    "lhu $14, 12( %0 );"                                 \
    "mtc2 $12, $9;"                                      \
    "mtc2 $13, $10;"                                     \
    "mtc2 $14, $11"                                      \
    : : "r"( r0 ) : "$12", "$13", "$14" )
#define RTIR_DA34() __asm__ volatile ("nop;nop;mvmva 1, 0, 3, 3, 0")
#define STCLMV_DA34(r0) __asm__ volatile (               \
    "mfc2 $12, $9;"                                      \
    "mfc2 $13, $10;"                                     \
    "mfc2 $14, $11;"                                     \
    "sh $12, 0( %0 );"                                   \
    "sh $13, 6( %0 );"                                   \
    "sh $14, 12( %0 )"                                   \
    : : "r"( r0 ) : "$12", "$13", "$14", "memory" )
#define LDV0_DA34(r0)  __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"( r0 ) : "memory")
#define LDRGB_DA34(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"( r0 ) : "memory")
#define NCCS_DA34()    __asm__ volatile ("nop;nop;nccs")
#define STRGB_DA34(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"( r0 ) : "memory")

void func_8001DA34(s32 param_1)
{
    MtxDA34 mtx[3];
    CVecDA34 cin[2];
    CVecDA34 cout[2];
    SVecDA34 nrm;
    s32 flag;

    RecDA34 *rec;
    u8 *prim;
    MtxDA34 *src;
    s16 *pa;
    s16 *pb;
    u32 *ot;
    u32 attr;
    s32 mode, sh, tp7;
    u16 id;
    u32 x, y;
    register u32 pxv __asm__("$4");
    u16 sx, sy;
    s32 tpage;
    s32 tb;
    s32 tc;
    s32 dxv;
    s32 ua, ub;
    u32 *ott;
    u32 cc;
    s32 ct;
    s32 idx;
    u16 pp;
    register u32 m24 __asm__("$5");
    register u32 mFF __asm__("$6");

    rec = *(RecDA34 **)(param_1 + 0x20);
    attr = *(u32 *)(param_1 + 4);
    nrm.vx = nrm.vy = 0;
    nrm.vz = -0x1000;
    mode = (attr >> 24) & 3;
    sh = 2 - mode;
    ot = (u32 *)(D_800A6610 + ((u32)D_800B9A02 << 14));

    if (!(attr & 0x1040)) {
        src = *(MtxDA34 **)(param_1 + 0x34);
        if (src != 0) {
            mtx[1] = *src;
            pa = &mtx[1].m[0][0];
            SETROT_DA34(&D_800A63F0);
            LDCLMV_DA34(pa);     RTIR_DA34(); STCLMV_DA34(pa);
            LDCLMV_DA34(pa + 1); RTIR_DA34(); STCLMV_DA34(pa + 1);
            LDCLMV_DA34(pa + 2); RTIR_DA34(); STCLMV_DA34(pa + 2);
            func_8004917C(pa);
        } else {
            pb = &mtx[1].m[0][0];
            func_8004978C((s16 *)(param_1 + 0x10), pb);
            SETROT_DA34(&D_800A63F0);
            LDCLMV_DA34(pb);     RTIR_DA34(); STCLMV_DA34(pb);
            LDCLMV_DA34(pb + 1); RTIR_DA34(); STCLMV_DA34(pb + 1);
            LDCLMV_DA34(pb + 2); RTIR_DA34(); STCLMV_DA34(pb + 2);
            func_8004917C(pb);
        }
    }

    if (*(s32 *)(param_1 + 0x34) != 0)
        func_8001E094(param_1);
    else
        func_8001E378(param_1);

    tp7 = mode << 7;
    do {
        prim = D_800A5E60;
        id = rec->id;
        __asm__ __volatile__("");
        dxv = rec->dx;
        __asm__ __volatile__("");
        pxv = *(u16 *)(param_1 + 0x28);
        x = pxv + (dxv >> sh);
        sx = x;
        y = *(u16 *)(param_1 + 0x2A) + rec->dy;
        sy = y;
        D_800A5E60 = prim + 0x28;
        prim[3] = 9;
        prim[7] = 0x2C;
        if (attr & 0x40000000) {
            prim[7] = 0x2E;
            tpage = tp7 | (((attr >> 28) & 3) << 5) | ((y & 0x100) >> 4) |
                    ((x & 0x3C0) >> 6) | ((y & 0x200) << 2);
        } else {
            tb = ((y & 0x100) >> 4) | 0x20;
            tpage = tp7 | tb | ((x & 0x3C0) >> 6) | ((y & 0x200) << 2);
        }
        *(s16 *)(prim + 0x16) = tpage;
        prim[7] |= (attr & 0x40) >> 6;
        __asm__ __volatile__("");
        ua = ub = (sx - ((tpage & 0xF) << 6)) << sh;
        ub += rec->w;
        ub -= 1;
        if ((u16)ub >= 0x100) ub = 0xFF;
        if (id & 0x100) {
            prim[0x14] = prim[0x24] = ua;
            prim[0x0C] = prim[0x1C] = ub;
        } else {
            prim[0x0C] = prim[0x1C] = ua;
            prim[0x14] = prim[0x24] = ub;
        }

        tc = tpage & 0x10;
        __asm__ __volatile__("");
        ub = sy;
        if (tc) {
            ua = ub - 0x100;
        } else {
            __asm__ __volatile__("");
            ua = ub;
        }
        ub = ua + rec->h - 1;
        if ((u16)ub >= 0x100) ub = 0xFF;
        if (id & 0x200) {
            prim[0x1D] = prim[0x25] = ua;
            prim[0x0D] = prim[0x15] = ub;
        } else {
            prim[0x0D] = prim[0x15] = ua;
            prim[0x1D] = prim[0x25] = ub;
        }

        cc = *(u8 *)(param_1 + 0x27);
        ct = (cc + 0x100) << 6;
        *(s16 *)(prim + 0xE) = (cc < 0xE0) ? (ct | 0x16) : (ct | 0x10);

        if (attr & 0x1040) {
            prim[4] = *(u8 *)(param_1 + 0x24);
            prim[5] = *(u8 *)(param_1 + 0x25);
            prim[6] = *(u8 *)(param_1 + 0x26);
        } else {
            cin[0].r = *(u8 *)(param_1 + 0x24);
            cin[0].g = *(u8 *)(param_1 + 0x25);
            cin[0].b = *(u8 *)(param_1 + 0x26);
            LDV0_DA34(&nrm);
            LDRGB_DA34(&cin[0]);
            NCCS_DA34();
            STRGB_DA34(&cout[0]);
            prim[4] = cout[0].r;
            prim[5] = cout[0].g;
            prim[6] = cout[0].b;
        }

        idx = func_8001E668(param_1, (s32)rec, prim, &flag);
        if ((flag & ~0x1000) == 0) {
            idx = idx + 1;
            pp = *(u16 *)(param_1 + 0x2C);
            if (pp & 0xC000) {
                if ((pp & 0xC000) == 0xC000) {
                    idx -= pp & 0xFFF;
                    if (idx < 0) idx = 0;
                } else {
                    idx += pp & 0xFFF;
                }
            }
            if ((u32)idx >= 0x1000) return;
            m24 = 0xFFFFFF;
            ott = (u32 *)(idx * 4 + (s32)ot);
            __asm__ __volatile__("");
            mFF = 0xFF000000;
            *(u32 *)prim = (*(u32 *)prim & mFF) | (*ott & m24);
            *ott = (*ott & mFF) | ((u32)prim & m24);
        }
        rec++;
    } while ((id & 0xFF) != 0xFF);
}
