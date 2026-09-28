/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AEA40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801AEAAC(void);
extern void func_801AEB04(s32 a0, s16 a1, s32 a2, s32 a3);

s32 func_801AEA40(s32 a0, s32 a1, s32 a2) {
    s32 ret;
    ret = func_801AEAAC();
    if (ret != 0) {
        func_801AEB04(ret, (s16)a0, a1, a2);
    }
    return ret;
}
