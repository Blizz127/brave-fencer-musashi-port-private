/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130740 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80130740(void *a0, u16 *a1) {
    u16 *p = (u16 *)a0;
    func_80146A6C(0x10, a0,
                  (s16)(p[3] + a1[0]),
                  (s16)(p[5] + a1[1]),
                  (s16)(p[7] + a1[2]),
                  0, 0);
}
