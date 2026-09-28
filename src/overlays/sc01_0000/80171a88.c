/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171A88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80171A88(s32 a0) {
    s32 v0;
    v0 = *(s32*)(a0 + 0x200);
    if (!v0) goto ret1;
    *(s32*)(a0 + 0x200) = v0 - 1;
    return (u32)(v0 - 1) < 1;
ret1:
    return 1;
}
