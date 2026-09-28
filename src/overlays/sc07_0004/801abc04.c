/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ABC04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801B03F4[];
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern int func_8005C49C(void);

void func_801ABC04(void *a0) {
    s32 t;
    u16 h;

    func_8001CC3C(*(s32 *)((s32)a0 + 0x20), (s32)D_801B03F4, 0x2F8, 0x1C0);

    *(u32 *)(*(s32 *)((s32)a0 + 0x20) + 4) |= 0x58000000;

    h = (func_8005C49C() & 0xF8) | 0x200;
    t = *(s32 *)((s32)a0 + 0x20);
    *(u16 *)(t + 0x1A) = h;
    *(u16 *)(t + 0x18) = h;

    *(u8 *)(*(s32 *)((s32)a0 + 0x20) + 0x27) = 0x55;

    *(u16 *)((s32)a0 + 2) += 1;
}
