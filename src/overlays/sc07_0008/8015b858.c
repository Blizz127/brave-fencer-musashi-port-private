/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015B858 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800D4BE0[];
extern s32 D_8011F730;
extern s32 func_8014A51C();
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);

s32 func_8015B858(u8 *a0) {
    if (*(u8 *)(a0 + 0x1C6) != 0) return 0;
    if (*(s32 *)(a0 + 0x240) != 0) return 0;
    if (func_8014A51C() == 0) return 0;
    *(s32 *)(a0 + 0x23C) = *(s32 *)(a0 + 0xB4);
    *(u8 *)(a0 + 0x244) = *(u8 *)(a0 + 0xBC);
    func_801477E8((s32 *)a0, 0xFFF20000);
    func_80154274((s32 *)a0, (s32)D_800D4BE0);
    D_8011F730 |= 2;
    return 1;
}
