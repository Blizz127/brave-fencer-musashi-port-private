/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A03A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A4328(s32 a0);
extern void func_801A34C4(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 D_801EEEA0;

void func_801A03A4(s32 a0) {
    func_801A4328(2);
    *(u16 *)(a0 + 0x5C) &= 0xDFFF;
    func_801A34C4(a0);
    func_8012A828(a0, &D_801EEEA0);
    func_8012AD44((s32 *)a0, 2);
}
