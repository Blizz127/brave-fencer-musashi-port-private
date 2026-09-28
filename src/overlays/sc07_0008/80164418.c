/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164418 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80012ABC(s32 a0, s32 a1, s32 a2);
extern void func_801630C4(s32, s32, s32, s32);
extern void func_80162FC0(s32 *a0);
extern void func_80162D88(s32 *a0);

void func_80164418(s32 s0) {
    s16 v[6];
    s32 s1 = *(s32 *)(s0 + 0x20);
    s32 a1 = *(s32 *)(s0 + 0x4C);
    v[0] = *(u16 *)(a1 + 0x6) - *(u16 *)(s0 + 0x6);
    v[1] = *(u16 *)(a1 + 0xA) - (*(u16 *)(s0 + 0xA) + 0x1E);
    v[2] = *(u16 *)(a1 + 0xE) - *(u16 *)(s0 + 0xE);
    v[5] = func_8004CFEC(v[0], v[2]);
    if (v[2] < 0) {
        v[2] = -v[2];
    }
    if (v[2] == 0) {
        v[4] = 0;
    } else {
        v[4] = func_8004CFEC(-v[1], v[2]);
    }
    *(u16 *)(s1 + 0x14) = (*(u16 *)(s1 + 0x14) + 0x71) & 0xFFF;
    *(s16 *)(s1 + 0x10) = func_80012ABC(*(s16 *)(s1 + 0x10), v[4], 0x2);
    *(s16 *)(s1 + 0x12) = func_80012ABC(*(s16 *)(s1 + 0x12), v[5], 0x2);
    ((s32 (*)(s32, s32, s32, s32))func_801630C4)(s0, 0, 0, 0x8000);
    func_80162FC0((s32 *)s0);
    func_80162D88((s32 *)s0);
}
