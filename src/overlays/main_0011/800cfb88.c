/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFB88 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800CFB88(void) {
    extern s32 D_800D4C90;
    extern void *D_800D32F8[];
    extern void func_8001534C(int, void *, int, int, int, int);
    func_8001534C(0x1C, D_800D32F8[D_800D4C90], 0x78, 0x82, 0, 0);
}
