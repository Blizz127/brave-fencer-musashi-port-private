/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C31C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80120194[];

s32 func_8012C31C(void) {
    s32 a0;
    s32 v1;
    a0 = (s32)D_80120194;
    v1 = a0 + 0x6480;
    if (v1 != a0) {
        do {
            if (*(u16 *)v1 == 0) {
                return v1;
            }
            v1 -= 0x10C;
        } while (v1 != a0);
    }
    return 0;
}
