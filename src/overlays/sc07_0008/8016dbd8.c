/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016DBD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149374(s32 a0, s32 a1);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

void func_8016DBD8(u8 *a0) {
    *(s32 *)(a0 + 0x4) = 0;
    *(s32 *)(a0 + 0x8) = 0;
    *(s32 *)(a0 + 0xC) = 0;
    func_80149374(*(s32 *)(a0 + 0x34), (s32)(a0 + 0x4));
    func_800D1FC8((s32)a0, 5);
}
