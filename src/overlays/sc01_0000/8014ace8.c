/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014ACE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3);

void func_8014ACE8(void *a0, s32 a1, s32 a2) {
    u16 sp[4];
    sp[0] = *(u16 *)((s32)a0 + 0x6);
    sp[1] = *(u16 *)((s32)a0 + 0xA) - 0x20;
    sp[2] = *(u16 *)((s32)a0 + 0xE);
    func_8014AD30((s32)a0, sp, a1, a2);
}
