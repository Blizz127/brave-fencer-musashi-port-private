/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801840D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_8005C49C(void);

void func_801840D0(int param_1)
{
    s32 ptr;
    s16 r;

    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x14) = *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x14) + 0x100;
    if (*(s32 *)(param_1 + 0x1C) != 0) {
        *(s32 *)(param_1 + 0x1C) = *(s32 *)(param_1 + 0x1C) - 1;
    } else {
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x18) = *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x18) + 0x400;
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x1A) = *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x1A) + 0x400;
        ptr = *(s32 *)(param_1 + 0x20);
        r = *(s16 *)(param_1 + 0x34);
        if (r < *(s16 *)(ptr + 0x18)) {
            *(s16 *)(ptr + 0x1A) = r;
            *(s16 *)(ptr + 0x18) = r;
            *(s32 *)(param_1 + 0x1C) = func_8005C49C();
            *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
        }
    }
}
