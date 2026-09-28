/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801511C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801511C4(u8 *a0) {
    *(u16 *)(a0 + 0xF0) = *(u16 *)(a0 + 0x3E);
    *(u16 *)(a0 + 0xF2) = *(u16 *)(a0 + 0x40);
    *(u16 *)(a0 + 0xF4) = *(u16 *)(a0 + 0x42);
}
