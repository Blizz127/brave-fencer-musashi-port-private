/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165374 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801653F4(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80165580(s32 a0);

void func_80165374(s32 a0) {
    func_801653F4(a0);
    func_80147078((s32 *)a0, 0x17);
    *(u8 *)(a0 + 0x197) = 1;
    func_80165580(a0);
}
