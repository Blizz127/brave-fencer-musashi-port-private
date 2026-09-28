/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131AC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80131CF4(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);

s32 func_80131AC8(void *a0) {
    s32 s0 = func_80131CF4(*(s32 *)((u8 *)a0 + 0xBC)) & 0xFFFF;
    if (s0 != 0) {
        func_8002D4C8(s0, 0);
        return s0;
    }
    return 0;
}
