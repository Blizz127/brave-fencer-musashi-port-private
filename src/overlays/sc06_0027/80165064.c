/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165064 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146CA0(void *a0);
extern void func_80165124(void *a0);
extern void func_801651B8(void *a0);

void func_80165064(s32 *a0) {
    s16 v = *(u16 *)((s32)a0 + 0x62) + 0x10;
    *(u16 *)((s32)a0 + 0x62) = v;
    if (v >= 0x100) {
        *(u16 *)((s32)a0 + 0x62) = 0xFF;
        func_80146CA0(a0);
    }
    func_80165124(a0);
    func_801651B8(a0);
}
