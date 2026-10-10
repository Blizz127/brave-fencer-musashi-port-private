/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164744 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_8018180C[])(s32);
extern void func_80162D28(s32 *a0);

void func_80164744(s32 param_1)
{
    s32 iVar1;

    iVar1 = *(s32 *)(param_1 + 0x20);
    D_8018180C[*(u16 *)(param_1 + 2)](param_1);
    if (iVar1 != 0) {
        ((void (*)(s32))func_80162D28)(param_1);
    }
}
