/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017509C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_8017509C(u8 *a0, s32 a1, u8 *a2, u8 *a3) {
    a1 = (s16)a1;
    a0 = a0 + a1 * 14;
    if (*(s16 *)(a0 + 0xC) == 0x7FFF) {
        return 1;
    }
    *(u16 *)(a2 + 0) = *(u16 *)(a0 + 0);
    *(u16 *)(a2 + 2) = *(u16 *)(a0 + 2);
    *(u16 *)(a2 + 4) = *(u16 *)(a0 + 4);
    *(u16 *)(a3 + 0) = *(u16 *)(a0 + 6);
    *(u16 *)(a3 + 2) = *(u16 *)(a0 + 8);
    *(u16 *)(a3 + 4) = *(u16 *)(a0 + 0xA);
    return 0;
}
