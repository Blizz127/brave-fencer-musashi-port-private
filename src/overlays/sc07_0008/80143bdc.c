/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143BDC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80143BDC {
    s16 f0, f2, f4, f6, f8, fA, fC, fE;
    s32 f10;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012C51C(void *a0, s32 a1);

void func_80143BDC(u16 *a0) {
    struct S80143BDC sp;
    u16 t;
    sp.f0 = a0[0];
    sp.f2 = a0[1];
    t = a0[2];
    sp.f6 = 0x1C;
    sp.f8 = 1;
    sp.fA = 0;
    sp.f10 = 0;
    sp.fE = 0;
    sp.f4 = t;
    func_8012C51C(&sp, 0);
}
