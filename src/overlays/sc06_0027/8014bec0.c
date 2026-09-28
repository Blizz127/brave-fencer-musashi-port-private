/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80029124(s32 a0, s32 a1);
extern u8 D_80078EC0;

void func_8014BEC0(void) {
    D_80078EC0 |= 1;
    func_80029124(0x80, 1);
}
