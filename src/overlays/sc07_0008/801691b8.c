/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801691B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80169228(void);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();

void func_801691B8(void *a0) {
    if (*(s32 *)((s32)a0 + 0x1C) < 10) {
        func_80169228();
        func_800D22E4((s32)a0);
        *(s32 *)((s32)a0 + 0x14) += 0x10000;
        *(s32 *)((s32)a0 + 0x1C) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)a0);
    }
}
