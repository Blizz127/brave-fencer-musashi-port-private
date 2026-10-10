/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013BCDC - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8013BCDC(void) {

    extern s32 D_80187270;
    s32 pad[4];
    if (D_80187270 != 0) {
        ((void (*)(void))D_80187270)();
    }
}
