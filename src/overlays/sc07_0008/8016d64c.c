/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D64C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern short func_8016CBC0(void);
extern void func_80146C3C();

void func_8016D64C(int param_1)
{
    if (func_8016CBC0() == 0) {
        ((void (*)(int))func_80146C3C)(param_1);
    }
    return;
}
