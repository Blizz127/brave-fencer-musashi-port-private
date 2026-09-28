/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165694 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80078EC8;

void func_80165694(s32 arg0) {
    if (*(s32 *)((s32)arg0 + 0x1F8) & 0x80FFFFFF) {
        return;
    }
    if (D_80078EC8 != 0) {
        D_80078EC8 = D_80078EC8 - 1;
    }
}
