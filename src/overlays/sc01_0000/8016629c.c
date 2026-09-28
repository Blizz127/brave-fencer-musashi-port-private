/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016629C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_8016629C(void *a0) {
    func_80146A6C(3, a0, *(s16 *)((s32)a0 + 6),
                  (s16)(*(u16 *)((s32)a0 + 0xA) - 0x10),
                  *(s16 *)((s32)a0 + 0xE), 0xF88FFF2, 0xE000C000);
}
