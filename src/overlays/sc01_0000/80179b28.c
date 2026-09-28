/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179B28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80139914(s32 a0);

void func_80179B28(s32 a0) {
    s32 v1;
    if (a0 == 0) return;
    if (*(s32 *)a0 == 0) return;
    v1 = *(s16 *)(a0 + 4);
    if (v1 == 0) return;
    if (v1 == 0xE) return;
    func_80139914(a0);
}
