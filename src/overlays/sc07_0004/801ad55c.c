/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD55C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801AD55C(void *a0) {
    void *a1;

    a1 = *(void **)((char *)a0 + 0x34);
    if (a1 != NULL) {
        *(u16 *)((char *)a0 + 0x6) = *(u16 *)((char *)a1 + 0x6) + *(u16 *)((char *)a1 + 0x50);
        *(u16 *)((char *)a0 + 0xA) = *(u16 *)((char *)a1 + 0xA) + *(u16 *)((char *)a1 + 0x52) - 0x40;
        *(u16 *)((char *)a0 + 0xE) = *(u16 *)((char *)a1 + 0xE) + *(u16 *)((char *)a1 + 0x54);
    }
}
