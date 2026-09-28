/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E0C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017E358();
extern void (*D_80188944[])(int);
extern void func_80162D28(s32*);

void func_8017E0C0(int param_1)
    {
        func_8017E358();
        D_80188944[*(unsigned short *)(param_1 + 2)](param_1);
        if (*(s32 *)(param_1 + 0x20) != 0) {
            ((void (*)(int))func_80162D28)(param_1);
        }
    }
