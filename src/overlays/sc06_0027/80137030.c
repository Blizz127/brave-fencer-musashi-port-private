/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80137030 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);

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
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
    tx = a0 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = tx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
    ty = a1 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0xFF;
    line.b = 0;
    line.x0 = cx;
    line.y0 = ty;
    line.x1 = cx;
    line.y1 = cy;
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
}
