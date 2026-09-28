/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160B70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_80160BB4(s32 *a0);

void func_80160B70(s32 a0) {
    if (func_80161104()) {
        func_80160BB4(a0);
    } else {
        *(s32 *)(a0 + 0x1AC) = 0;
    }
}
