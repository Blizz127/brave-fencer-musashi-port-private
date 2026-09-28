/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013CAE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801EC768;
extern s32 D_801EC76C;
extern s32 D_801EC770;
extern s32 D_801EC774;
extern s32 D_801EC778;

void func_8013CAE8(void) {
    D_801EC768 = 1;
    D_801EC774 = 0;
    D_801EC76C = 0;
    D_801EC770 = -1;
    D_801EC778 = 0;
}
