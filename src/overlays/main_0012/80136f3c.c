/* Overlay range [80136F3C,80137030) from MAIN.CD member 0012.
 * SHA256(span)=e3a1941cf86c3eec6db1c67973ac28ac124e38c69c73c285dd324b14635cffb1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136F3C - byte-exact against retail at -O2 (tools/register_match.py). */
#define GsSortLine func_80051DC8
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void GsSortLine(void *a0, void *a1, s32 a2);

void func_80136F3C(s32 a0, s32 a1)
{
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
    register s16 x1    __asm__("$16");                
    register s16 x0    __asm__("$17");                
    register u8 *base  __asm__("$19") = D_800A6518;   
    register s16 white __asm__("$20");                
    s16 y0;
    s16 y1;
    y0 = a1 - 3;
    x1 = a0 + 3;
    __asm__("" : "=r"(x1) : "0"(x1));
    y1 = a1 + 3;
    white = 0xFF;
    x0 = a0 - 3;
    line.tag = 0;
    line.r = white;
    line.g = 0;
    line.b = 0;
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    GsSortLine(&line, &base[(u16)D_800B9A02 * 20], 0);
    line.tag = 0;
    line.r = white;
    line.g = 0;
    line.b = 0;
    line.x0 = x1;
    line.y0 = y0;
    line.x1 = x0;
    line.y1 = y1;
    GsSortLine(&line, &base[(u16)D_800B9A02 * 20], 0);
}
