/* Exact retail overlay 0010 export [800D29F8,800D2CA8), offset 0x23C00. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D29F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u32 addr : 24;      /* 0x00 tag */
    u32 len  : 8;
} PTag_800D29F8;
typedef struct {
    u32 c0;             /* 0x04 r0,g0,b0,code */
    s16 x0, y0;         /* 0x08 */
    u32 c1;             /* 0x0C */
    s16 x1, y1;         /* 0x10 */
    u32 c2;             /* 0x14 */
    s16 x2, y2;         /* 0x18 */
    u32 c3;             /* 0x1C */
    s16 x3, y3;         /* 0x20 */
} PolyG4_800D29F8;
typedef struct {
    u32 *ot;            /* 0x00 */
    u32 pad[4];         /* 0x04..0x13 */
} Env_800D29F8;
#define OT_800D29F8             (D_800AE7BC[*(volatile u16 *)&D_800B9A02].ot)
#define getaddr_800D29F8(t)     (((PTag_800D29F8 *)(t))->addr)
#define setaddr_800D29F8(t, v)  (((PTag_800D29F8 *)(t))->addr = (u32)(v))
#define addPrim_800D29F8(ot, p) (setaddr_800D29F8(p, getaddr_800D29F8(ot)), \
                                 setaddr_800D29F8(ot, p))

u32 *func_800D29F8(s16 hs, u32 *out, u16 *src, s16 n, u16 ofs)
{
    extern Env_800D29F8 D_800AE7BC[];
    extern short D_800B9A02;

    u32 *q;
    PolyG4_800D29F8 *p;
    s16 i;
    int code;
    u32 c, c2;
    int x, y, w, h;
    int o;

    o = ofs;
    q = out;
    p = (PolyG4_800D29F8 *)((u8 *)q + 4);
    ((u8 *)q)[3] = 1;                       /* setlen(q, 1) */
    p->c0 = 0xE1000000;                     /* GP0 draw-mode: dither off */
    addPrim_800D29F8(&OT_800D29F8[2], q);
    q += 2;

    for (i = 0; i < n; i++) {
        if ((i >> 1) == hs || i >= 8) {
            code = 0;
        } else if (i & 1) {
            code = 2;                       /* ABE: semi-transparent */
        } else {
            src += 8;                       /* skip this rung's 0x10-byte record */
            continue;
        }
        p = (PolyG4_800D29F8 *)((u8 *)q + 4);
        *q = 0x08000000;                    /* tag: len 8, addr 0 */
        c = ((code | 0x38) << 24) | *(u32 *)src;
        src += 2;
        p->c0 = c;
        p->c1 = c - 0x280000;
        c2 = *(u32 *)src;
        src += 2;
        p->c3 = c2;
        p->c2 = c2 + 0x280000;
        x = *src++ + o;
        p->x0 = p->x2 = x;
        y = *src++;
        p->y1 = y;
        p->y0 = y;
        w = *src++ + x;
        h = y + *src++;
        p->x1 = p->x3 = w;
        p->y2 = p->y3 = h;

        addPrim_800D29F8(&OT_800D29F8[2], q);
        q += 9;
    }

    p = (PolyG4_800D29F8 *)((u8 *)q + 4);
    ((u8 *)q)[3] = 1;
    p->c0 = 0xE1000200;                     /* GP0 draw-mode: dither on */
    addPrim_800D29F8(&OT_800D29F8[2], q);
    return q + 2;
}
