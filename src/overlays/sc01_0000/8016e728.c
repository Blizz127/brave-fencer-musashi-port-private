/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E728 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146C3C();
extern void func_8016E778();
extern void func_8012A568(void (*a0)(void));

void func_8016E728(u8 *a0) {
    s32 v0;
    s32 v1;
    v0 = (u16)*(u16 *)(a0 + 0x12) + 0x400;
    v1 = (u16)*(u16 *)(a0 + 0x16) - 8;
    *(u16 *)(a0 + 0x12) = v0;
    *(u16 *)(a0 + 0x16) = v1;
    if ((s16)v1 <= 0) {
        func_80146C3C();
    } else {
        func_8016E778();
    }
}
