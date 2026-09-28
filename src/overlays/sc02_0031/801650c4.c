/* SC02.CD FILE_031 / ov_SC02_031 retail span [801650C4,80165124).
 * Offset 0x3CF6C at overlay base 80128158. SHA256(span)=d8c2c623b42bece48eda3dcb7c80a4f6bcf62fad641dc2aa2c1f617f5b999df1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801650c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801650C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80162CCC();
extern void func_80165124(void *a0);
extern void func_801651B8(void *a0);

void func_801650C4(s32 *a0) {
    s16 v = *(u16 *)((s32)a0 + 0x62) - 0x10;
    *(u16 *)((s32)a0 + 0x62) = v;
    if (v < 0) {
        func_80162CCC();
    } else {
        func_80165124(a0);
        func_801651B8(a0);
    }
}
