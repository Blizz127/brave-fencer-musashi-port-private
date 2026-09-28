/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0E6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F832C;
extern s32 D_801F84AC;
extern void func_80016714(void *a0, s32 a1);

void func_801F0E6C(void) {
    func_80016714(&D_801F832C, 0x180);
    D_801F84AC = 0;
}
