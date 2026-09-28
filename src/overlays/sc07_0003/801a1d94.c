/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1D94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A28AC(s32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B178(s32 a0, s32 a1);
extern u8 D_801F0798[];
extern u8 D_801F0840[];

void func_801A1D94(void *arg0) {
    s32 s0 = (s32)arg0;

    ((void (*)(void *))func_801A28AC)(arg0);
    if (*(u32 *)(s0 + 0xE0) & 1) {
        func_8012A828(s0, D_801F0798);
        *(u16 *)(s0 + 0x34) = 0;
    } else {
        func_8012A828(s0, D_801F0840);
        *(u16 *)(s0 + 0x34) = 1;
        func_8012B178(s0, 0x30000);
    }
    *(u16 *)(s0 + 2) = 0x16;
    *(s32 *)(s0 + 0xE4) = 0x30;
    *(s32 *)(s0 + 0xE0) = *(u32 *)(s0 + 0xE0) | 0x40;
    *(s32 *)(s0 + 0x1C) = 0x10;
}
