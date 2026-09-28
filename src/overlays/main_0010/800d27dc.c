/* Exact retail overlay 0010 export [800D27DC,800D29F8), offset 0x239E4. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D27DC - byte-exact against retail at -O2 (tools/register_match.py). */
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
} PTag_800D27DC;
typedef struct {
    u32 *ot;            /* 0x00 */
    u32 pad[4];         /* 0x04..0x13 */
} Env_800D27DC;
#define OT_800D27DC             (D_800AE7BC[*(volatile u16 *)&D_800B9A02].ot)
#define getaddr_800D27DC(t)     (((PTag_800D27DC *)(t))->addr)
#define setaddr_800D27DC(t, v)  (((PTag_800D27DC *)(t))->addr = (u32)(v))
#define addPrim_800D27DC(ot, p) (setaddr_800D27DC(p, getaddr_800D27DC(ot)), \
                                 setaddr_800D27DC(ot, p))

u8 *func_800D27DC(u32 flags, u8 *out, u16 *src, s16 count, u16 add)
{
    extern Env_800D27DC D_800AE7BC[];
    extern short D_800B9A02;

    s16 i;
    u32 c;
    int o;
    int x, y, w, h, u, v;
    int tw, th, k;
    int f2;

    o = add;
    c = 0x2C808080;
    if (flags & 1) {
        c = 0x2C585858;
    }
    for (i = 0; i < count; i++) {
        f2 = flags & 2;
        *(u32 *)(out + 0x00) = 0x09000000;      /* setlen(out, 9) */
        *(u32 *)(out + 0x04) = c;               /* r0,g0,b0,code = 0x2C */
        x = *src++ + o;
        *(s16 *)(out + 0x18) = x;               /* x2 */
        *(s16 *)(out + 0x08) = x;               /* x0 */
        y = *src++;
        *(s16 *)(out + 0x12) = y;               /* y1 */
        *(s16 *)(out + 0x0A) = y;               /* y0 */
        w = *src++;
        h = *src++;
        u = *src++;
        *(u8 *)(out + 0x0C) = *(u8 *)(out + 0x1C) = u;      /* u0 = u2 */
        v = *src++;
        *(u8 *)(out + 0x0D) = *(u8 *)(out + 0x15) = v;      /* v0 = v1 */
        if (f2 == 0) {
            th = 8;
            *(u16 *)(out + 0x0E) = 0x4056;      /* clut  */
            *(u16 *)(out + 0x16) = 0x15;        /* tpage */
            tw = 8;
            k = i & 7;
            if (k >= 4) {
                if (k < 6) {
                    tw = 7;
                } else if (k < 8) {
                    th = 7;
                }
            }
        } else {
            *(u16 *)(out + 0x0E) = *src++;      /* clut  */
            *(u16 *)(out + 0x16) = *src++;      /* tpage */
            tw = *src++;
            th = *src++;
        }
        *(s16 *)(out + 0x10) = *(s16 *)(out + 0x20) = x + w;    /* x1 = x3 */
        *(s16 *)(out + 0x1A) = *(s16 *)(out + 0x22) = y + h;    /* y2 = y3 */
        *(u8 *)(out + 0x14) = *(u8 *)(out + 0x24) = u + tw;     /* u1 = u3 */
        *(u8 *)(out + 0x1D) = *(u8 *)(out + 0x25) = v + th;     /* v2 = v3 */
        addPrim_800D27DC(&OT_800D27DC[2], out);
        out += 0x28;
    }
    return out;
}
