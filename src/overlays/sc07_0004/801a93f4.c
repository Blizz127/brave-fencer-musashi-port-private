/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A93F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
s32 aF801A93F4(void *a0) __asm__("func_801A93F4");

s32 aF801A93F4(void *a0) {
    s32 s0;

    s0 = func_80132EF4(a0, 0x2D);
    if (s0 != 0) {
        *(s32 *)(s0 + 0x14) = *(s32 *)(a0 + 0x14) >> 1;
        *(u16 *)(s0 + 0x2C) = func_8005C49C() & 1;
    }
    return s0;
}
