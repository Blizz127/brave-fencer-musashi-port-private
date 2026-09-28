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

extern s32 D_801A44E4;
extern s32 D_801A44E8;
extern s32 D_801A4510;
extern s32 D_801A4514;

void func_8013CB20(void)
{
    D_801A4510 = D_801A44E8;
    D_801A4514 = D_801A44E4;
    D_801A44E8 = 1;
    D_801A44E4 = 0;
}
