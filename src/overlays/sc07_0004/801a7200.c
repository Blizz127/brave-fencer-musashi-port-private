/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7200 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001CD9C(s32, s32);
extern u8 D_801F8744[];

void func_801A7200(s32 param_1)
{
    s32 s1;
    s32 s2;

    s1 = *(s32 *)(param_1 + 0x34);
    s2 = *(s32 *)(s1 + 0xCC);
    *(u16 *)(param_1 + 0x2C) = 0;
    func_8001CD9C(*(s32 *)(param_1 + 0x20), (s32)D_801F8744);
    *(u16 *)(param_1 + 6) = *(s32 *)(*(s32 *)(s1 + 0x20) + 0x48);
    *(u16 *)(param_1 + 0xA) = *(s32 *)(*(s32 *)(s1 + 0x20) + 0x4C);
    *(u16 *)(param_1 + 0xE) = *(s32 *)(*(s32 *)(s1 + 0x20) + 0x50);
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x18) = *(u16 *)(s2 + 0x18);
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x1A) = *(u16 *)(s2 + 0x1A);
    *(u32 *)(*(s32 *)(param_1 + 0x20) + 4) |= 0x50800000;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x2C) = 0xC020;
    *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
}
