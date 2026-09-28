/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164A74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80148534(s32 a0, s32 a1);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);

void func_80164A74(s32 *a0) {
    s32 sp10[2];
    s32 sp18[2];
    s32 s1 = a0[0x4C / 4];
    func_80148534((s32)sp10, (s32)sp18);
    func_80015954((s32)sp10, (s32)a0 + 4);
    func_80149374(s1, (s32)a0 + 4);
}
