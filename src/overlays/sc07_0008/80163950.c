/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80163950 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern void func_80015954(s32 a0, s32 a1);

s32 func_80163950(s32 a0) {
    s32 sp10[2];
    s32 sp18[2];
    u8 *p;
    func_80015978(a0 + 4, sp10);
    func_80015978(a0 + 4, sp18);
    *(s16 *)((s32)sp10 + 0x2) = *(u16 *)((s32)sp10 + 0x2) - 0x20;
    *(s16 *)((s32)sp18 + 0x2) = *(u16 *)((s32)sp18 + 0x2) + 0x8;
    for (p = D_801202A0; p < D_801202A0 + 0x6480; p += 0x10C) {
        if (*(u16 *)p == 0) continue;
        if ((*(u16 *)(p + 0x5C) & 0x400) == 0) continue;
        if (*(s32 *)(p + 0x58) == 0) continue;
        if (func_80135A4C(*(s32 *)(p + 0x20), *(s32 *)(p + 0x58), sp10, (s32)sp18) != 0) {
            func_80015954((s32)sp18, a0 + 4);
            return 1;
        }
    }
    return 0;
}
