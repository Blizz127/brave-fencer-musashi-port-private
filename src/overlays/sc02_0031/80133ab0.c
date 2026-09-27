/* SC02 resident retail span [80133AB0,80133CD4). Offset 0xB958 at base 80128158.
 * SHA256(span)=8955bf7cb0b7ca18a47d46a4fe8b92ae80f1c1658f9a6f4361ec8a0f1398497c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910); the C
 * is the Druthulu shared/ov func_80133AB0 shape (h_exact 49df14d8, pins as
 * published) with the map pointers retargeted to this member (D_80185204,
 * D_80185200, D_8018520C) and the counters D_801B62E8/D_801B62E4.
 * Oracle MATCH 137/137. Not MAIN10.
 */
#include "psx_types.h"

typedef struct {
    u16 ox, oy, w, h;
    s32 cells;
    s32 p0C;
    s32 p10;
    s32 p14;
    s32 p18;
    s32 p1C;
} Map_80133AB0;

extern u32 D_80185204;
extern u32 D_80185200;
extern u32 D_8018520C;
extern u16 D_801B62E8;
extern s16 D_801B62E4;
s32 func_80133CD4(s16, u8 *, void *, void *);

s32 func_80133AB0(s16 flag, s16 x, s16 y, s32 arg3)
{

    Map_80133AB0 *map = (Map_80133AB0 *)arg3;
    u16 *pA = (*(u16 * *)&D_80185204);
    u16 *pB = (*(u16 * *)&D_80185200);
    u16 *pC = (*(u16 * *)&D_8018520C);
    register int zr __asm__("$0");  // !FAKE: pin $0 — NEEDED DIFFERS (P36 rung B headers1)
    u32 X, Y, cell, Xc, Yc;
    u16 k, off;
    int cnt;
    u16 *cp, *lst;
    u8 *s0;
    u16 raw;
    u32 hib;
    register int harg __asm__("$4");  // !FAKE: pin $4 — NEEDED DIFFERS (P36 rung B headers1)
    s32 ret;
    void *p0C, *p10;
    u8 *p14, *p18, *p1C;
    u16 *cells;

    pC[0] = pA[0] - pB[0];
    pC[1] = pA[1] - pB[1];
    pC[2] = pA[2] - pB[2];

    X = ((((u16)x + 0x8000) >> 7) & 0x1ff) - map->ox;
    __asm__("addu %0,%1,$zero" : "=r"(Xc) : "r"(X));  // !FAKE: instruction addu — NEEDED DIFFERS (P36 rung B headers1)
    if (!((X & 0xffff) < map->w))
        return 0;
    Y = ((((u16)y + 0x8000) >> 7) & 0x1ff) - map->oy;
    __asm__("addu %0,%1,$zero" : "=r"(Yc) : "r"(Y));  // !FAKE: instruction addu — NEEDED DIFFERS (P36 rung B headers1)
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
                D_801B62E8 = *(u16 *)s0;
            return 1;
        }
        lst++;
        if (D_801B62E4 != 0) {
            D_801B62E8 = *(u16 *)s0;
            return 0;
        }
    }
    return 0;
}
