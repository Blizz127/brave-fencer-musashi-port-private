/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5A9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_801292C8(u8 *a0);
extern void func_8012931C(void *);

void func_801A5A9C(s32 a0) {
    s32 s0 = a0;
    func_8012931C((void *)a0);
    if (((s32 (*)(s32, void *))func_80128ED8)(*(s32 *)(s0 + 0x20), (void *)(s0 + 0x24)) != 0) {
        ((void (*)(s32))func_801292C8)(s0);
    }
}
