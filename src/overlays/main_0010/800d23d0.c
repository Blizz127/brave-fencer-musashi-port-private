/* Exact overlay word export for [800D23D0,800D2460) from MAIN.CD member0010
 * (extracted/overlays/main/0010.bin offset 0x235D8, load base 800AEDF8).
 * SHA256(span)=77b9ecdf0153b961f96536d3d696f4a1e5889a1759ffcc54a0c6ab1cf4153b21.
 * Word export only: the native seam executes the member's own words. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D23D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80047D3C(s32 arg0);
extern s32 func_8004CFEC(s32 y, s32 x);

void func_800D23D0(s16 *p) {
    s32 fx = p[0];
    s32 fz = p[2];
    s32 fy = p[1];

    p[0] = -func_8004CFEC(fy, func_80047D3C(fx * fx + fz * fz));
    p[1] = func_8004CFEC(fx, fz);
    p[2] = 0;
}
