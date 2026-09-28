/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE8C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EE8C4(s32 arg0) {
    extern s32 D_801F5200;
    extern s32 D_801F5204;
    register s32 p1 __asm__("$3") = D_801F5200;
    *(s16 *)(arg0 + 0xFC) = 1;
    arg0 = D_801F5204;
    {
        register s32 c __asm__("$2") = 3;
        *(s16 *)(p1 + 0xFC) = c;
        *(s16 *)(arg0 + 0xFC) = c;
    }
}
