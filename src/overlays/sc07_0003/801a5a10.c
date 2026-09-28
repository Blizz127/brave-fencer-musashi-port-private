/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5A10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801A7368[];
extern u8 D_801A7374[];

void func_801A5A10(s32 param_1)
{
    s32 p;

    *(u32 *)(*(s32 *)(param_1 + 0x20) + 0x20) = (u32)&D_801A7368;

    *(u32 *)(*(s32 *)(param_1 + 0x20) + 4) |= 0x50000000;

    *(u8 *)(*(s32 *)(param_1 + 0x20) + 0x27) = 0x5A;

    p = *(s32 *)(param_1 + 0x20);
    *(u16 *)(p + 0x1A) = 0x3000;
    *(u16 *)(p + 0x18) = 0x3000;

    func_80128EA8(*(u32 *)(param_1 + 0x20), param_1 + 0x24, (s32)&D_801A7374);

    *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
}
