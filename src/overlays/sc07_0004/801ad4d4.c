/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD4D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801AD4D4(void *a0) {
    extern void func_801AD55C(void *a0);
    extern void func_801AD700();
    extern void func_8002D4C8(s32 a0, s32 a1);

    func_801AD55C(a0);
    func_801AD700(a0);
    *(s32 *)((char *)a0 + 0x1c) = 0x10;
    *(s16 *)((char *)a0 + 0x2) = 0x2;
    func_8002D4C8(0xBA3, 0);
}
