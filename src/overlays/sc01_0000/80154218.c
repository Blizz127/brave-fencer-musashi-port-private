/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154218 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801549F8(s32 a0, s32 a1, s32 a2);
extern void func_80154418(void *a0);

void func_80154218(u8 *a0, s32 a1, s32 a2) {
    u8 *s0 = a0;
    s32 *base = *(s32 **)(s0 + 0xB0);
    s32 v1 = base[a1];
    *(u16 *)(s0 + 0xBA) = 1;
    *(u16 *)(s0 + 0xB8) = 1;
    *(s8 *)(s0 + 0xBC) = a2;
    *(s8 *)(s0 + 0xBD) = a2;
    *(s32 *)(s0 + 0xB4) = v1;
    s0[0xDC] = func_801549F8((s32)a0, (s32)&base[a1], a2);
    func_80154418(s0);
}
