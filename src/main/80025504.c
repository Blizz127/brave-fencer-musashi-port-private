/* Main-exec range [80025504,80025818) from the SLUS executable.
 * SHA256(span)=e22f3a3deaaeb66554b33460b41e38580a507a5cc9864956feb4355c4b13d248.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80025504 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

#define gte_ldv0(r0)  __asm__ volatile("lwc2 $0, 0(%0);lwc2 $1, 4(%0)" : : "r"(r0))
#define gte_ldv3(r0, r1, r2) __asm__ volatile(                              \
    "lwc2 $0, 0(%0);lwc2 $1, 4(%0);"                                        \
    "lwc2 $2, 0(%1);lwc2 $3, 4(%1);"                                        \
    "lwc2 $4, 0(%2);lwc2 $5, 4(%2)" : : "r"(r0), "r"(r1), "r"(r2))
#define gte_ldrgb(r0) __asm__ volatile("lwc2 $6, 0(%0)" : : "r"(r0))
#define gte_rtpt()  __asm__ volatile("nop;nop;cop2 0x0280030")
#define gte_rtps()  __asm__ volatile("nop;nop;cop2 0x0180001")
#define gte_nclip() __asm__ volatile("nop;nop;cop2 0x1400006")
#define gte_avsz4() __asm__ volatile("nop;nop;cop2 0x168002e")
#define gte_ncct()  __asm__ volatile("nop;nop;cop2 0x118043f")
#define gte_nccs()  __asm__ volatile("nop;nop;cop2 0x108041b")
#define gte_stflg(r0) __asm__ volatile("cfc2 $12, $31;nop;sw $12, 0(%0)" : : "r"(r0) : "$12", "memory")
#define gte_stopz(r0) __asm__ volatile("swc2 $24, 0(%0)" : : "r"(r0) : "memory")
#define gte_stotz(r0) __asm__ volatile("swc2 $7, 0(%0)" : : "r"(r0) : "memory")
#define gte_stsxy2(r0) __asm__ volatile("swc2 $14, 0(%0)" : : "r"(r0) : "memory")
#define gte_strgb2(r0) __asm__ volatile("swc2 $22, 0(%0)" : : "r"(r0) : "memory")
#define gte_stsxy3_g4(r0) __asm__ volatile(                                 \
    "swc2 $12, 8(%0);swc2 $13, 16(%0);swc2 $14, 24(%0)" : : "r"(r0) : "memory")
#define gte_strgb3_g4(r0) __asm__ volatile(                                 \
    "swc2 $20, 4(%0);swc2 $21, 12(%0);swc2 $22, 20(%0)" : : "r"(r0) : "memory")
#define gte_stsz4(r0, r1, r2, r3) __asm__ volatile(                         \
    "swc2 $16, 0(%0);swc2 $17, 0(%1);swc2 $18, 0(%2);swc2 $19, 0(%3)"       \
    : : "r"(r0), "r"(r1), "r"(r2), "r"(r3) : "memory")
typedef struct {
    s16 vx, vy, vz, pad;
} GVec8;
typedef struct {
    s32 unk0;
    u32 rgb;
    u16 n0, v0;
    u16 n1, v1;
    u16 n2, v2;
    u16 n3, v3;
} GFace;
typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    u32 xy0;
    u32 rgb1;
    u32 xy1;
    u32 rgb2;
    u32 xy2;
    u32 rgb3;
    u32 xy3;
} GPolyG4;
typedef struct {
    u8 addr0, addr1, addr2, len;
    u32 code0;
} GDrMode;
extern s32 D_80078D88[];
extern s32 D_800A2B78;

void *func_80025504(GFace *prim, GVec8 *vtx, GVec8 *nrm, GPolyG4 *poly, s32 n, s32 shift,
                    u32 *ot)
{
    s32 flag;
    s32 p;
    s32 sz0, sz1, sz2, sz3;
    s32 zmax, ztmp;
    u32 *op;
    GDrMode *dm;
    GFace *fp;
    register GFace *p0 __asm__("$4") = prim;

    __asm__("" : "=r"(poly) : "0"(poly));
    fp = p0;
    for (; n != 0; n--, fp++) {
            gte_ldv3(&vtx[fp->v0], &vtx[fp->v1], &vtx[fp->v2]);
            gte_rtpt();
            gte_stflg(&flag);
            if (flag & 0xffffefff) {
                continue;
            }
            gte_nclip();
            gte_stopz(&p);
            if (p <= 0) {
                continue;
            }
            gte_stsxy3_g4(poly);
            gte_ldv0(&vtx[fp->v3]);
            gte_rtps();
            gte_stflg(&flag);
            if (flag & 0xffffefff) {
                continue;
            }
            gte_stsxy2(&poly->xy3);
            if (D_80078D88[0] & 0x8000) {
                gte_stsz4(&sz0, &sz1, &sz2, &sz3);
                zmax = sz2;
                if (zmax < sz3) {
                    zmax = sz3;
                }
                ztmp = sz0;
                if (ztmp < sz1) {
                    ztmp = sz1;
                }
                if (ztmp < zmax) {
                    ztmp = zmax;
                }
                p = ztmp >> 2;
            } else {
                gte_avsz4();
                gte_stotz(&p);
            }
            gte_ldrgb(&fp->rgb);
            gte_ldv3(&nrm[fp->n0], &nrm[fp->n1], &nrm[fp->n2]);
            gte_ncct();
            gte_strgb3_g4(poly);
            gte_ldv0(&nrm[fp->n3]);
            gte_nccs();
            gte_strgb2(&poly->rgb3);

            op = &ot[p >> shift];
            poly->tag = (*op & 0xffffff) | 0x08000000;
            *op = (u32)poly & 0xffffff;
            poly++;
            if (D_800A2B78 != 0) {
                if (poly[-1].code & 2) {
                    dm = (GDrMode *)poly;
                    op = &ot[p >> shift];
                    dm->len = 1;
                    dm->code0 = 0xe100000a | ((D_800A2B78 & 3) << 5);
                    *(u32 *)dm = (*op & 0xffffff) | 0x01000000;
                    *op = (u32)dm & 0xffffff;
                    poly = (GPolyG4 *)((u8 *)dm + 8);
                }
            }
    }
    return poly;
}
