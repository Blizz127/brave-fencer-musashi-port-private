/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013CB5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801953D0;
extern s32 D_801953D4;
extern s32 D_801953A8;
extern s32 D_801953A4;

void func_8013CB5C(void) {
    D_801953A8 = D_801953D0;
    D_801953A4 = D_801953D4;
}
