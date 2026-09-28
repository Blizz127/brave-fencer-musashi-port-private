/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E95C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8015E9B8(s32 *a0);
extern u8 D_80078EC0;

void func_8015E95C(s32 a0) {
    if ((D_80078EC0 & 0x80) == 0) {
        func_80146A6C(0x14, (void *)a0, 0, 0, 0, 0, 0);
    }
    func_8015E9B8(a0);
}
