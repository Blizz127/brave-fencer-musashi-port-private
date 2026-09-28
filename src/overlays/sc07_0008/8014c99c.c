/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C99C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 arg);
extern s32 func_8016F1AC(void);
extern void func_80139914(s32 a0);
extern void func_80029124(s32, s32);

void func_8014C99C(u8 *a0) {
    if ((func_80029178(0x119) & 0xFF) != 0) {
        if (func_8016F1AC() != 0) {
            func_80139914(*(s32 *)(a0 + 0x198));
            *(s32 *)(a0 + 0x198) = 0;
            func_80029124(0x119, 0);
        }
    }
}
