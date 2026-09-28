/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139634 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);

void func_80139634(void *a0) {
    s16 sp[4];
    sp[0] = *(u16 *)((u8 *)a0 + 0x38);
    sp[1] = *(u16 *)((u8 *)a0 + 0x3A);
    sp[2] = 0x38;
    sp[3] = 0x30;
    func_80059888(&sp[0], 0, 0, 0);
}
