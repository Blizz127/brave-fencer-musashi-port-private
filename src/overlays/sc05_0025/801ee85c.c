/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE85C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EE85C(void *arg0) {

    extern s32 D_801F5200;
    extern s32 D_801F5204;
    register s32 p1 __asm__("$2");
    register s32 p2 __asm__("$4");

    p1 = *(s32 *)&D_801F5200;
    *(u16 *)((s32)arg0 + 0xFC) = 0;
    p2 = *(s32 *)&D_801F5204;
    *(u16 *)(p1 + 0xFC) = 2;
    *(u16 *)(p2 + 0xFC) = 0;
}
