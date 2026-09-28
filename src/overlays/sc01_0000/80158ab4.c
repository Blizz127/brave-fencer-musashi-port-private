/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158AB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80158AE4(void *a0);
extern void func_80146CA0(void *a0);

void func_80158AB4(void *a0) {
    func_80158AE4(a0);
    func_80146CA0(a0);
}
