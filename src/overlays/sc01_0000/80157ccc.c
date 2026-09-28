/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157CCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_801553A8(s32 *a0);

void func_80157CCC(s32 a0) {
    s32 s0 = a0;
    *(u8 *)(s0 + 0x223) = 0x10;
    *(s32 *)(s0 + 0x44) = *(s32 *)(s0 + 0x44) & ~2;
    func_80154A74(s0, 0x11);
    func_801553C0(s0);
    func_801553A8((s32 *)s0);
}
