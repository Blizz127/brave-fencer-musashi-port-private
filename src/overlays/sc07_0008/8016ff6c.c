/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FF6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_8016FFA8(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FF6C(u8 *a0) {
    func_801719A4((int)a0, 2);
    func_80171990(a0);
    func_8016FFA8(a0);
}
