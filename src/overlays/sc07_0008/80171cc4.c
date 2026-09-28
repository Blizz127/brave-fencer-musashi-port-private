/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171CC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80171D78(s32 a0, s32 a1);
extern int func_8017250C(short *a0, short *a1);
extern void func_80146D90(s32 a0);

s32 func_80171CC4(void * a0, void * a1)
{
    s32 ret;
    ret = func_80171D78(a0, a1);
    if (func_8017250C(a0, a1) != 0) {
        func_80146D90((s32)a0);
    }
    return ret;
}
