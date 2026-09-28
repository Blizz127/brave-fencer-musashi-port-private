/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A758 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A7D4(void *a0, void *a1);
extern s16 func_8012A79C(s16 *a0, s16 *a1);

s16 func_8012A758(void) {
    s16 a[4];
    s16 b[4];
    func_8012A7D4(a, b);
    return func_8012A79C(a, b);
}
