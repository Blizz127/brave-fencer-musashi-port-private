/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5414 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A5414(s32 param_1) {
    extern void func_8012B178(s32 a0, s32 a1);
    extern void func_8012AD44(s32 *a0, s16 a1);
    extern void func_8002D4C8(s32 a0, s32 a1);

    *(s32 *)(param_1 + 0xF0) = -0xC0000;
    func_8012B178(param_1, -0xC0000);
    *(s32 *)(param_1 + 0x1C) = 0x18;
    *(s16 *)(param_1 + 0x100) = 1;
    func_8012AD44((s32 *)param_1, 2);
    func_8002D4C8(0xABB, 0);
}
