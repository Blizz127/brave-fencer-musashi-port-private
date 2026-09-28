/* Exact retail overlay 0010 export [800D2294,800D22E4), offset 0x2349C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2294 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *func_801465C0(s32 arg0);
extern void func_8001CD9C(void *arg0, s32 arg1);

void *func_800D2294(s32 arg0, s32 arg1) {
    void *p = func_801465C0(arg0);
    if (p) {
        func_8001CD9C(p, arg1);
        return p;
    }
    return 0;
}
