/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143C98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_80180540[])(void *);

void func_80143C98(void *a0) {
    D_80180540[*(u16 *)((s32)a0 + 0x2)](a0);
}
