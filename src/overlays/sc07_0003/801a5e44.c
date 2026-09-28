/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5E44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BEE8(s32 a0);
extern void func_80016450(s32 a0, s32 a1);

void func_801A5E44(s32 param_1)
{
    s32 state = *(u16 *)(param_1 + 0x34);

    switch (state) {
    case 0:
    {
        u8 v0 = *(u8 *)(param_1 + 0xFC) + 0x10;
        *(u8 *)(param_1 + 0xFC) = v0;
        if (v0 >= 0xF1) {
            *(u32 *)(*(s32 *)(param_1 + 0x20) + 4) |= 0x80000000;
            *(u32 *)(*(s32 *)(param_1 + 0xCC) + 4) |= 0x80000000;
            *(s32 *)(param_1 + 0x1C) = 8;
            *(u16 *)(param_1 + 0x34) += 1;
        }
        break;
    }
    case 1:
        if (func_8012BEE8(param_1) != 0) {
            *(s32 *)(param_1 + 0xE0) = state;
        }
        break;
    }

    func_80016450(*(u8 *)(param_1 + 0xFC), 0);
}
