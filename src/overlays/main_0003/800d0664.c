/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0664 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015310(void);
extern void func_800183E0(s32 a0);
extern void func_800118AC(void);
extern u8 D_800AF630[];
extern u8 D_800D93FC[];

void func_800D0664(void) {
    register u8 *base = D_800AF630;
    s32 loc[2];

    func_80015310();
    func_800183E0((s32)&D_800D93FC);
    func_800118AC();
}
