/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E6E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E778();
extern void func_8012A568(void (*a0)(void));

void func_8016E6E4(s32 a0) {
    s32 v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == -1) {
        *(u16 *)(a0 + 2) = *(u16 *)(a0 + 2) + 1;
    }
    func_8016E778();
}
