/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801478B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147948(s32 a0, s32 a1, s32 a2);
extern void func_801479BC(s32 a0, s32 a1, s32 a2);
extern void func_80147A30(s32 a0, s32 a1, s32 a2);

void func_801478B8(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_80147948(a0, a1, 0x7FFFFFFF);
    func_801479BC(a0, a2, 0x7FFFFFFF);
    func_80147A30(a0, a3, 0x7FFFFFFF);
}
