/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016BFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016BFD0(s32 a0, s32 a1, s32 a2, s32 a3, void *a4);
extern s32 D_80195968;
extern void func_8012A568(void (*a0)(void));

void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_8016BFD0(a0, a1, a2, a3, &D_80195968);
}
