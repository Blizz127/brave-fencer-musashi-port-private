/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014D438 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014D610(s32 a0, s32 a1, u16 *a2);
extern s32 func_8014D4C0(s32 a0, void *a1, void *a2);

void func_8014D438(s32 a0) {
    s16 buf1[4];
    s16 buf2[4];
    buf1[0] = *(u16 *)(a0 + 0x88);
    buf1[1] = *(u16 *)(a0 + 0x8A);
    buf1[2] = *(u16 *)(a0 + 0x8C);
    buf2[0] = *(u16 *)(a0 + 0x6);
    buf2[1] = *(u16 *)(a0 + 0xA);
    buf2[2] = *(u16 *)(a0 + 0xE);
    if (*(s32 *)(a0 + 0x174) == 0) {
        func_8014D610(a0, buf1, buf2);
    } else {
        func_8014D4C0(a0, buf1, buf2);
    }
}
