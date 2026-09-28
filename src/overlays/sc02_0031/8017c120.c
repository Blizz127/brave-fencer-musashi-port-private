/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017C120 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80146C3C(void);
extern void func_800D22E4(s32 a0);

void func_8017C120(void *a0)
{
    s32 val;

    val = *(s32 *)((s32)a0 + 0x1C);
    val--;
    *(s32 *)((s32)a0 + 0x1C) = val;

    if (val != -1) {
        func_800D22E4((s32)a0);
        *(s32 *)((s32)a0 + 0x14) += 0x1A000;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)a0);
    }
}
