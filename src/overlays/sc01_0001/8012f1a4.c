/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F1A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012F1A4(s32 *a0, s32 a1, s32 *a2) {
    func_800484EC((s32)a0, a1, (s32)a2);
    a2[0] += a0[0x14 / 4] << 16;
    a2[1] += a0[0x18 / 4] << 16;
    a2[2] += a0[0x1C / 4] << 16;
}
