/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157A8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80161D20();
extern void func_8014C010(s32 a0, s32 a1);

void func_80157A8C(s32 a0) {
    func_80161D20(a0, *(u16 *)(a0 + 0x16E));
    func_8014C010(a0, 1);
}
