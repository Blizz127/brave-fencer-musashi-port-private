/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017CF9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800167F0(s32 arg0);
extern void func_800CFBCC(s32 arg);

s32 func_8017CF9C(void) {
    if ((func_800167F0(4) & 0xFFFF) == 0) {
        return 0;
    }
    func_800CFBCC(0);
    return 1;
}
