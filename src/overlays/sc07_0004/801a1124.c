/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1124 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C588(s32 a0, s32 a1);

void func_801A1124(s32 a0) {
    s32 v0;
    v0 = *(s32 *)(a0 + 0x1C);
    if ((v0 & 3) == 0) {
        func_8012C588(0x44, a0);
    }
}
