/* Exact retail overlay 0010 export [800CEF04,800CEF34), offset 0x2010C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CEF04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800D0488(s32 arg0);
extern void func_80011A3C(void);

void func_800CEF04(void) {
    if (((s32 (*)())func_800D0488)(1)) {
        func_80011A3C();
    }
}
