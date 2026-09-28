/* Exact retail overlay 0010 export [800D222C,800D2294), offset 0x23434. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D222C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *func_801465C0(s32);
extern void func_8001CB6C(u8 *, s32, s32, s32);

u8 *func_800D222C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p = func_801465C0(arg0);
    if (p != 0) {
        func_8001CB6C(p, arg1, 0, 0);
        p[0x27] = arg2;
        return p;
    }
    return 0;
}
