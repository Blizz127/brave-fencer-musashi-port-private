/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154190 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154418(void *a0);

void func_80154190(u8 *a0, s32 a1) {
    s32 v1 = *(s32 *)((a1 << 2) + *(s32 *)(a0 + 0xB0));
    *(s16 *)(a0 + 0xBA) = 1;
    *(s16 *)(a0 + 0xB8) = 1;
    *(s8 *)(a0 + 0xBC) = 0;
    *(s8 *)(a0 + 0xBD) = 0;
    *(s8 *)(a0 + 0xDC) = 0;
    *(s32 *)(a0 + 0xB4) = v1;
    func_80154418((void *)a0);
}
