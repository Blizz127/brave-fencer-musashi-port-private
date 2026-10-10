/* Exact retail overlay 0010 export [800D30C8,800D3104), offset 0x242D0. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D30C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_800D3A8C[])(void *);

void func_800D30C8(void *arg0) {
    D_800D3A8C[*(u8 *)((u8 *)arg0 + 0x15)](arg0);
}
