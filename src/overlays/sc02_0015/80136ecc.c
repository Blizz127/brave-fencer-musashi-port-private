/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136ECC - byte-exact against retail at -O2 (tools/register_match.py). */
#define GsSortLine func_80051DC8
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void GsSortLine(void *a0, void *a1, s32 a2);

void func_80136ECC(s16 a0, s16 a1, s16 a2, s16 a3, u8 r, u8 g, u8 b) {
    struct {
        u32 tag;
        s16 x0;
        s16 y0;
        s16 x1;
        s16 y1;
        u8 r;
        u8 g;
        u8 b;
    } line;
    line.x0 = a0;
    line.tag = 0;
    line.y0 = a1;
    line.x1 = a2;
    line.y1 = a3;
    line.r = r;
    line.g = g;
    line.b = b;
    GsSortLine(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
}
