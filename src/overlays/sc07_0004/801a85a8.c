/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A85A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

s32 func_801A85A8_body(s32 a0, s32 a1, s32 a2, s32 a3) __asm__("func_801A85A8");

s32 func_801A85A8_body(s32 a0, s32 a1, s32 a2, s32 a3) {
    extern s32 func_80132EF4(s32 a0, s32 a1);

    s32 ret;

    ret = func_80132EF4(a0, 0x30);
    if (ret != 0) {
        *(u16 *)(ret + 0x2E) = (a2 & 1) + 2;
        *(s32 *)(ret + 0x30) = a1;
        *(s32 *)(ret + 0x34) = a0;
        *(s16 *)(ret + 0x2C) = a3;
    }
    return ret;
}
