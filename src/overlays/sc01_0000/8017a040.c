/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A040 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80179B74(u16 *p);

void func_8017A040(u16 *a0) {
    s16 sp[5];
    sp[0] = 0x1D;
    sp[1] = a0[0];
    sp[2] = a0[1];
    sp[3] = a0[2];
    sp[4] = a0[3];
    func_80179B74(sp);
}
