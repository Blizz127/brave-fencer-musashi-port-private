/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150FD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern u16 D_800B99DA;

void func_80150FD8(s32 a0) {
    if (D_800B99DA & 7) {
        func_80146994(0x34, a0, 0, 0);
    }
}
