/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D060 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017D2F4(int);

void func_8017D060(int param_1)
{
    int iVar1;

    iVar1 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = iVar1 + 1;
    if (iVar1 < 0xc) {
        *(unsigned short *)(param_1 + 0x12) = *(unsigned short *)(param_1 + 0x12) + 0xe0;
    } else {
        *(int *)(param_1 + 0x1c) = 0;
        *(unsigned short *)(param_1 + 2) = *(unsigned short *)(param_1 + 2) + 1;
    }
    func_8017D2F4(param_1);
    return;
}
