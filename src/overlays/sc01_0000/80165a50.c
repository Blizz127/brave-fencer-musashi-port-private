/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165A50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC1;
extern u8 D_80078EC2;
extern u8 D_80078EC3;
extern s8 D_80078EC4;

s32 func_80165A50(s32 _arg0)
{
    D_80078EC1 = 0;
    D_80078EC2 = 0;
    D_80078EC3 = 0;
    D_80078EC4 = 0;
}
