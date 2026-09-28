/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B864 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012B864(s32 a0) {
    s32 dx = *(s16*)(a0 + 0xE) - D_80126CB8;
    s32 dy = D_80126CB4 - *(s16*)(a0 + 0x6);
    return (func_8004CFEC(dx, dy) - 0x400) & 0xFFF;
}
