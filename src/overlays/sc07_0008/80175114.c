/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175114 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80175184(s32 *a0);

void func_80175114(s32 *a0) {
    func_80147078(a0, 8);
    *(s16 *)((s32)a0 + 2) = 1;
    func_80175184(a0);
}
