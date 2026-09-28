/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013CB20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801A2A34;
extern s32 D_801A2A38;
extern s32 D_801A2A60;
extern s32 D_801A2A64;

void func_8013CB20(void)
{
    D_801A2A60 = D_801A2A38;
    D_801A2A64 = D_801A2A34;
    D_801A2A38 = 1;
    D_801A2A34 = 0;
}
