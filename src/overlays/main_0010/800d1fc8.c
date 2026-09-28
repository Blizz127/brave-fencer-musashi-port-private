/* Exact overlay word export for [800D1FC8,800D20C0) from MAIN.CD member0010
 * (extracted/overlays/main/0010.bin offset 0x231D0, load base 800AEDF8).
 * SHA256(span)=36dce2225202cb4a90a690a132cf7e75af925702ab151133da29b4d483f63ea4.
 * Word export only: the native seam executes the member's own words. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1FC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800D1FC8(void *arg0, int arg1) {
    extern int D_801151D4;
    extern void func_80047E98(void *a0, void *a1);

    int *g;
    short v[4];
    int dx, dy, dz;
    int sh, t1, t2;

    g = (int *)D_801151D4;

    dx = *(int *)((char *)g + 0x5C) - *(unsigned short *)((char *)arg0 + 6);
    v[0] = dx;
    t1 = *(int *)((char *)g + 0x60);
    dy = t1 - *(unsigned short *)((char *)arg0 + 10);
    v[1] = dy;
    t2 = *(int *)((char *)g + 0x64);
    dz = t2 - *(unsigned short *)((char *)arg0 + 14);
    v[2] = dz;
    sh = arg1;

    if ((unsigned int)((dx + 0x3FFF) & 0xFFFF) >= 0x7FFF ||
        (unsigned int)((dy + 0x3FFF) & 0xFFFF) >= 0x7FFF ||
        (unsigned int)((dz + 0x3FFF) & 0xFFFF) >= 0x7FFF) {
        v[2] = 0;
        v[0] = 0;
        v[1] = -0xFFF;
    }

    func_80047E98(v, v);

    *(unsigned short *)((char *)arg0 + 6) += v[0] >> (sh & 0xFFFF);
    *(unsigned short *)((char *)arg0 + 10) += v[1] >> (sh & 0xFFFF);
    *(unsigned short *)((char *)arg0 + 14) += v[2] >> (sh & 0xFFFF);
}
