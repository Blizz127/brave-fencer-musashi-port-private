/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F410 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016F44C(s32 a0);
extern void func_8016F470(s32 a0);
extern void func_8012A568(void (*a0)(void));

s32 func_8016F410(s32 a0) {
    if (func_8016F44C(a0) == 0) {
        return 0;
    }
    func_8016F470(a0);
    return 1;
}
