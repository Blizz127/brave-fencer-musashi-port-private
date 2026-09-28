/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170584 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_801705C0(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_80170584(u8 *a0) {
    func_801719A4((int)a0, 1);
    func_80171990(a0);
    func_801705C0(a0);
}
