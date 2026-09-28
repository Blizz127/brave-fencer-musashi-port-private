/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178BB8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80178CBC(s32 a0, s32 a1);
extern s32 func_80178BF8();

void func_80178BB8(s32 a0, s32 a1) {
    func_80178BF8(a0, a1);
    func_80178CBC(a0, a1);
}
