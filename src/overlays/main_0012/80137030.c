/* Overlay range [80137030,80137178) from MAIN.CD member 0012.
 * SHA256(span)=a9794940e97da2c42f717f73b0357258cdccde43fab4a07115037848a2258377.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80137030 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define GsSortLine func_80051DC8

/* func_80137030 — shared body (overlay slot 0x80128158, h_exact 9b08c5e5). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void GsSortLine(void *a0, void *a1, s32 a2);
void func_80137030(s16 a0, s16 a1) {
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
    s16 cx;
    s16 cy;
    s16 tx;
    s16 ty;
    tx = a0 - 3;
    ty = a1 - 3;
    cx = a0;
    cy = a1;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = tx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    GsSortLine(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
    tx = a0 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = tx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    GsSortLine(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
    ty = a1 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = cx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    GsSortLine(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
}
