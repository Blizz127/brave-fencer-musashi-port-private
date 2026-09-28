/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801731D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_800D5AA0[];
extern void func_8014706C(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern void func_80173220(void *a0);

void func_801731D8(s32 *a0) {
    func_8014706C(a0);
    func_80154274(a0, (s32)D_800D5AA0);
    func_80171A1C((u8 *)a0);
    func_80173220(a0);
}
