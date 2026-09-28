/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158548 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();

void func_80158548(s32 param_1) {
    *(u32 *)(param_1 + 0x44) = *(u32 *)(param_1 + 0x44) | 2;
    if (*(u16 *)(param_1 + 0xb8) & 0x8000) {
        ((void (*)(void))func_801599A4)();
        ((void (*)(s32))func_80159B3C)(param_1);
    } else {
        ((void (*)(s32))func_80161208)(param_1);
    }
}
