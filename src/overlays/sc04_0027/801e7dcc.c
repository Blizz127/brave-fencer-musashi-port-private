/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E7DCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801E7DCC(void)
{
    extern s16 D_801F1D88;
    extern s16 D_801F1D8A;
    extern void (*D_801EB0E4[])(void);
    D_801EB0E4[D_801F1D88]();
    return ((u32)D_801F1D8A) >> 31;
}
