/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015B7B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80149B54(s32 *a0);
extern void func_80156648(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 a0);
extern void func_80147300(u16 arg0);
extern u8 D_800D4F8C[];

s32 func_8015B7B4(s32 a0) {
    s32 s0 = a0;
    if (func_80149B54((s32 *)s0) != 0) {
        func_80156648((s32 *)s0);
        *(s8 *)(s0 + 0x1AA) = 0xC;
        *(s32 *)(s0 + 0x44) = *(s32 *)(s0 + 0x44) | 0x2;
        *(s32 *)(s0 + 0x23C) = *(s32 *)(s0 + 0xB4);
        *(s8 *)(s0 + 0x244) = *(u8 *)(s0 + 0xBC);
        func_80154274((s32 *)s0, (s32)D_800D4F8C);
        func_80154A74(s0, 0x22);
        *(s8 *)(s0 + 0xDA) = 0;
        func_80146994(5, s0, 5, 0);
        func_80147324(0x455);
        func_80147300(0x5F3);
        return 1;
    }
    return 0;
}
