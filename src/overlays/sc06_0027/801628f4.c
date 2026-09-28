/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801628F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80162968(s32 a0);

void func_801628F4(s32 *a0) {
    s16 *a2 = (s16 *)a0[0x4 / 4];
    s32 *a1 = (s32 *)a0[0x8 / 4];
    if (*(s16 *)((u8 *)a2 + 0x7E) != 0) {
        a1[0x4 / 4] |= 0x80000000;
    } else {
        a1[0x4 / 4] &= 0x7FFFFFFF;
    }
    a0[0x20 / 4] = *(s16 *)((u8 *)a2 + 0x78);
    a0[0x24 / 4] = *(s16 *)((u8 *)a2 + 0x7A);
    a0[0x28 / 4] = *(s16 *)((u8 *)a2 + 0x7C);
    func_80162968((s32)a0);
}
