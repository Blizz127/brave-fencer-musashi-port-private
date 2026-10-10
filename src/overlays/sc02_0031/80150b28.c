/* SC02.CD member31 [80150B28,80150B9C); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150B28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80150B28(int param_1) {

    extern s32 D_800AE6B0;
    extern void (*D_801868EC[])(int);
    u32 idx;
    register u32 sub __asm__("$2");

    if ((D_800AE6B0 & 0x80FFFFFF) == 0) {
        idx = *(u16 *)(param_1 + 0x16C);
        if (idx != 0 && idx < 0x26) {
            sub = idx - 1;
            D_801868EC[sub](param_1);
        }
    }
    *(u16 *)(param_1 + 0x16C) = 0;
}
