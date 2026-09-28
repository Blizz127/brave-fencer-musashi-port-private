/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5F18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);
extern void func_80016450(s32 a0, s32 a1);

void func_801A5F18(void *a0) {
    u32 v;
    u32 m;
    v = *(u8 *)((s32)a0 + 0xFC);
    v -= 3;
    m = v & 0xFF;
    *(u8 *)((s32)a0 + 0xFC) = v;
    if (m >= 9) {
        func_80016450(m, 0);
    } else {
        func_8012C218(a0);
    }
}
