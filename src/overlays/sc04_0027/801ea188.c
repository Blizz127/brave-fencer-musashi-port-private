/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EA188 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801EA188(s32 param_1) {
    extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
    extern void func_801EA470(void *a0);
    extern s32 D_801F249C;

    D_801F249C = 0;
    ((void (*)(void *, s32))func_8016EDEC)((void *)func_801EA470, 0x1000000);
    *(u8 *)(param_1 + 0x15) = *(u8 *)(param_1 + 0x15) + 1;
    *(s32 *)(param_1 + 0x28) = 0x10;
    return 0;
}
