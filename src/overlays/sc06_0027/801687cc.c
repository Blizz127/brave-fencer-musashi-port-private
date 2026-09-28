/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801687CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80168828(void);
extern void func_80146C3C();

void func_801687CC(s32 param_1)
{
    if (*(int *)(param_1 + 0x1c) < 3) {
        func_80168828();
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
}
