/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E778 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E7C8(int param_1, short *p1, unsigned int *p2);

void func_8016E778(int param_1)
{
    short local_18[3];
    unsigned int local_10;
    unsigned short uVar1;
    int iVar2;
    uVar1 = *(unsigned short *)(param_1 + 0x12);
    local_18[2] = uVar1;
    local_18[1] = uVar1;
    local_18[0] = uVar1;
    iVar2 = *(short *)(param_1 + 0x16);
    local_10 = iVar2 | (iVar2 << 16 | iVar2 << 8);
    func_8016E7C8(param_1, local_18, &local_10);
}
