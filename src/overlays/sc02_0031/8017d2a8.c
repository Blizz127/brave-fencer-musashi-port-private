/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D2A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017D2F4(int);
extern void func_80146C3C(void);

void func_8017D2A8(int param_1)
{
    unsigned short uVar1;
    uVar1 = *(unsigned short *)(param_1 + 0x12) - 0x100;
    *(unsigned short *)(param_1 + 0x12) = uVar1;
    if ((short)uVar1 > 0) {
        func_8017D2F4(param_1);
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
}
