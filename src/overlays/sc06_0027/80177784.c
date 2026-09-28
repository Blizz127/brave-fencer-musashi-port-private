/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80177784 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void *func_80177784(void *a0, s32 a1, s32 a2, s32 a3) {
    *(u32 *)((s32)a0 + 0x0) = (((s32)a0 - 0x14) & 0xFFFFFF) | 0x3000000;
    *(u32 *)((s32)a0 + 0x4) = 0x74808080;
    *(s32 *)((s32)a0 + 0x8) = a1;
    *(s32 *)((s32)a0 + 0xC) = a2;
    return (void *)((s32)a0 + 0x14);
}
