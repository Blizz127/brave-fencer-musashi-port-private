/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EB3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80181FB8[];
extern void func_8016EC0C(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

void func_8016EB3C(s32 p) {
    u8 v;

    ((void (*)(s32, s32))func_8016EC0C)(p, D_80181FB8[*(u8 *)(p + 2) & 3]);

    v = *(u8 *)(p + 2);
    *(u8 *)(p + 2) = v + 0xFF;
    if (v == 0) {
        *(u8 *)(p + 2) = 5;
        *(u8 *)(p + 1) = *(u8 *)(p + 1) + 1;
    }
}
