/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BCA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017B0E4(int, int);
extern s16 D_801A5674;
extern s16 D_801A5870;

void func_8017BCA0(int param_1) {
    func_8017B0E4(param_1, 0xC);
    D_801A5674 = D_801A5674 + 1;
    if (D_801A5674 >= 0x1F) {
        D_801A5870 = 2;
    }
}
