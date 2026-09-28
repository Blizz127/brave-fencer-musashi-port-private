/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801612B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014E934(s32 a0);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);

s32 func_801612B8(void * a0, s32 a1)
{
    register s32 p __asm__("$17");
    register s32 v0 __asm__("$16");
    s32 v1;
    p = a0;
    if ((a1 & 1) == 0) {
        func_8014E934(p);
    }
    v0 = ((s32 (*)(s32))func_8014CC28)(p);
    __asm__ __volatile__("" : : "r"(v0));
    v1 = ((s32 (*)(s32))func_8014F3E8)(p);
    return v0 | v1;
}
