/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012CE2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

s32 func_8012CE2C(s32 a0) {
    short a[4];
    short b[4];
    s32 pa, pb;
    a[0] = *(u16 *)(a0 + 0x6);
    a[1] = *(u16 *)(a0 + 0xA);
    a[2] = *(u16 *)(a0 + 0xE);
    pa = (s32)a;
    pb = (s32)b;
    __builtin_memcpy((void *)pb, (void *)pa, 8);
    b[1] += 8;
    func_80133784(1, a, pb);
    return a[1] == b[1];
}
