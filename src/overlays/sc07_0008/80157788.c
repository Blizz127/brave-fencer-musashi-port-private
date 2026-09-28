/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157788 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int D_80195468;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_801578C0(s32 a0);

void func_80157788(int param_1)
{
    D_80195468 = 300;
    ((void (*)(int, int))func_80147078)(param_1, 7);
    func_801578C0(param_1);
}
