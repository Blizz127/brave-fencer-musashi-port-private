/* Overlay range [80133AB0,80133CD4) from MAIN.CD member 0012.
 * SHA256(span)=bdaeb7de108638b76d0027a0eb6c5b3db671198d7043857a3799b917f41e699d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80133AB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct Map_80133AB0 {
    u16 ox;       /* 0x00 */
    u16 oy;       /* 0x02 */
    u16 w;        /* 0x04 */
    u16 h;        /* 0x06 */
    u16 *cells;   /* 0x08 */
    void *p0C;    /* 0x0C */
    void *p10;    /* 0x10 */
    u8  *p14;     /* 0x14 */
    u8  *p18;     /* 0x18 */
    u8  *p1C;     /* 0x1C */
} Map_80133AB0;

s32 func_80133AB0(s16 flag, s16 x, s16 y, s32 arg3)
{
    extern u8 D_8018DAA0;
    extern u8 D_8018DA9C;
    extern u8 D_8018DAA8;
    extern u16 D_801ED3C0;
    extern s16 D_801ED3BC;
    extern s32 func_80133CD4();

    Map_80133AB0 *map = (Map_80133AB0 *)arg3;
    u16 *pA = (*(u16 * *)&D_8018DAA0);
    u16 *pB = (*(u16 * *)&D_8018DA9C);
    u16 *pC = (*(u16 * *)&D_8018DAA8);
    register int zr __asm__("$0");
    u32 X, Y, cell, Xc, Yc;
    u16 k, off;
    int cnt;
    u16 *cp, *lst;
    u8 *s0;
    u16 raw;
    u32 hib;
    register int harg __asm__("$4");
    s32 ret;
    void *p0C, *p10;
    u8 *p14, *p18, *p1C;
    u16 *cells;

    pC[0] = pA[0] - pB[0];
    pC[1] = pA[1] - pB[1];
    pC[2] = pA[2] - pB[2];

    X = ((((u16)x + 0x8000) >> 7) & 0x1ff) - map->ox;
    __asm__("addu %0,%1,$zero" : "=r"(Xc) : "r"(X));
    if (!((X & 0xffff) < map->w))
        return 0;
    Y = ((((u16)y + 0x8000) >> 7) & 0x1ff) - map->oy;
    __asm__("addu %0,%1,$zero" : "=r"(Yc) : "r"(Y));
    if (!((Y & 0xffff) < map->h))
        return 0;

    cell = (Yc & 0xffff) * map->w + (Xc & 0xffff);
    cells = map->cells;
    p14 = map->p14;
    p0C = map->p0C;
    p10 = map->p10;
    p18 = map->p18;
    p1C = map->p1C;
    k = cell * 2;
    cp = (u16 *)(k * 2 + (u32)cells);
    off = cp[0];
    cnt = cp[1];
    lst = (u16 *)(p14 + off);

    while (((cnt-- + zr) & 0xffff) != 0) {
        raw = *lst;
        hib = raw & 0x8000;
        harg = hib + zr;
        if (hib == 0) {
            s0 = p18 + raw * 18;
        } else {
            s0 = p1C + (raw & 0x7fff) * 22;
        }
        ret = (s16)func_80133CD4((s16)(harg | flag), s0, p10, p0C);
        if (ret != 0) {
            if (ret > 0)
                D_801ED3C0 = *(u16 *)s0;
            return 1;
        }
        lst++;
        if (D_801ED3BC != 0) {
            D_801ED3C0 = *(u16 *)s0;
            return 0;
        }
    }
    return 0;
}
