/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EDC2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801EDC2C(void)
{
    extern s16 D_801F7C10;
    extern s16 D_801F7C12;
    extern void (*D_801F0F6C[])(void);

    D_801F0F6C[D_801F7C10]();
    return (u32)D_801F7C12 >> 31;
}
