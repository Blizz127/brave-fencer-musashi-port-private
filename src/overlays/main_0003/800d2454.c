/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2454 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D2AA0();
extern void func_800D2D44();
extern void func_80043088(s32 a0, s32 a1);
extern void func_80046ABC();
extern s32 D_800D946C;
extern void func_800D2A24();

void func_800D2454(s32 a0, s32 a1, s32 *a2) {
    func_800D2AA0(0);
    func_800D2D44(a1);
    func_80043088(D_800D946C, 0x20);
    func_80046ABC(a2[1], a2[2], -1, 0, 0);
    func_800D2A24(a0);
}
