/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C51C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80126720[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_8012C51C(void *a0, s32 a1) {
    u8 *base = D_80126720;
    u8 *p;
    s32 ret;
    if (a1 == 0) {
        p = base - 0x6480;
    } else {
        p = (u8 *)(a1 + 0x10C);
    }
    if (p != base) {
        do {
            if (*(u16 *)p == 0) goto found;
            p += 0x10C;
        } while (p != base);
    }
    p = 0;
found:
    ret = 0;
    if (p != 0) {
        ret = func_8012C890((s32)a0, (s32)p, a1);
    }
    return ret;
}
