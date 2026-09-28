/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801661CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801661CC(s32 param_1)
{
    extern s32 func_80128ED8(s32 param_1, s32 *param_2);
    extern void func_80146C3C();
    extern void func_800D22E4(s32 a0);
    if (((s32 (*)(s32, s32))func_80128ED8)(*(s32 *)(param_1 + 0x20), param_1 + 0x24) != 0) {
        ((void (*)(s32))func_80146C3C)(param_1);
    } else {
        func_800D22E4(param_1);
        *(s32 *)(param_1 + 0x10) = (*(s32 *)(param_1 + 0x10) >> 1) + (*(s32 *)(param_1 + 0x10) >> 2);
        *(s32 *)(param_1 + 0x18) = (*(s32 *)(param_1 + 0x18) >> 1) + (*(s32 *)(param_1 + 0x18) >> 2);
    }
}
