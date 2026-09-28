/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016951C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80169584(s32 param_1);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();

void func_8016951C(int param_1)
{
    int iVar1;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = iVar1 + 1;
    if (iVar1 < 10) {
        ((void (*)(void))func_80169584)();
        func_800D22E4(param_1);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 0x8000;
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
    return;
}
