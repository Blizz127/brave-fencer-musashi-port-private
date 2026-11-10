/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013B7F4 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013B83C(s32 a0, s32 a1, s32 a2);

void func_8013B7F4(s32 a0, s32 a1) {

    extern s32 D_801C58AC;
    func_8013B83C(a0, a1, D_801C58AC);
}
