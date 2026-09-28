/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CEED0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_800D3598[])(void);

void func_800CEED0(void) {
    register s32 idx __asm__("$2");
    __asm__ __volatile__("" : : "r"(idx));
    D_800D3598[idx]();
}
