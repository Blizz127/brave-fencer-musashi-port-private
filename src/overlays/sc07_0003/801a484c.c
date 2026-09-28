/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A484C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_8012C658(s32 arg0, s32 arg1, s32 arg2);

void func_801A484C(s32 a0, s32 a1) {
    s32 ent = func_8012C658(0x378, a1 & 0xFFFF, a0);
    if (ent != 0 && (a1 & 0xFFFF) < 7u) {
        func_801A484C(ent, (a1 + 1) & 0xFFFF);
    }
}
