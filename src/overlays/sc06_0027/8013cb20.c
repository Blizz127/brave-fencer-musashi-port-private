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

extern s32 D_8019C084;
extern s32 D_8019C088;
extern s32 D_8019C0B0;
extern s32 D_8019C0B4;

void func_8013CB20(void)
{
    D_8019C0B0 = D_8019C088;
    D_8019C0B4 = D_8019C084;
    D_8019C088 = 1;
    D_8019C084 = 0;
}
