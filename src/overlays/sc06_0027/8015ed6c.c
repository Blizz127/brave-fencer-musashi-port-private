/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015ED6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EBF;
extern void func_80149048(s32 *a0);

void func_8015ED6C(s32 *a0) {
    D_80078EBF = 0;
    *(s32 *)((s32)a0 + 0x44) &= -2;
    func_80149048(a0);
}
