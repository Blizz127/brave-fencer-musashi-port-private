/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EAFE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F24A4;
extern s32 D_801F2624;
extern void func_80016714(s8*, s32);

void func_801EAFE4(void) {
    ((void (*)(void *, s32))func_80016714)(&D_801F24A4, 0x180);
    D_801F2624 = 0;
}
