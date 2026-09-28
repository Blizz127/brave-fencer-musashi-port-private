/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015086C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8014B2F8(void);
extern void func_80147324(s32 arg0);

void func_8015086C(int param_1)
{
    ((void (*)(int, int, int, int))func_80146994)(0x48, param_1, 0, 0);
    ((void (*)(int))func_8014B2F8)(param_1);
    func_80147324(0xA1B);
    return;
}
