/* Complete SC02 retail span [80181EF0,80181F20); C recovery pending. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181EF0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EBA;
extern u8 D_80078EB1;

s32 func_80181EF0(void) {
    register s32 m __asm__("$4");
    register s32 c __asm__("$3");
    m = D_80078EBA;
    c = 4;
    if (m == c) {
        return (u32)(D_80078EB1 - 7) < 5;
    }
    return 0;
}
