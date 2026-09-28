/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175218 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_80078EC0;
extern void (*D_80181664[])(s32);
extern void func_80146CA0(void *a0);

s32 func_80175218(void * param_1)
{
    s32 i = D_80078EC0 - 1;

    D_80181664[i](param_1);
    ((void (*)(s32))func_80146CA0)(param_1);
}
