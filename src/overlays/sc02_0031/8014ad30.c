/* Complete SC02 retail span [8014AD30,8014AD7C).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014AD30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S_8014AD30 {
    s16 h0;
    s16 h1;
    s16 h2;
    s16 h3;
    s32 w0;
    s32 w1;
    s32 w2;
};
extern void func_80146AFC(void *a0);

void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3) {
    struct S_8014AD30 sp;
    s16 b = a1[0];
    s16 c = a1[1];
    s16 d = a1[2];
    sp.h0 = 0x1D;
    sp.w0 = a0;
    sp.w1 = a2;
    sp.w2 = a3;
    sp.h1 = b;
    sp.h2 = c;
    sp.h3 = d;
    func_80146AFC(&sp);
}
