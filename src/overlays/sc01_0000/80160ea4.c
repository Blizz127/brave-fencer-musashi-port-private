/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801816B0[])(void *);

void func_80160EA4(void *a0) {
    D_801816B0[*(u16 *)((s32)a0 + 0x2)](a0);
}
