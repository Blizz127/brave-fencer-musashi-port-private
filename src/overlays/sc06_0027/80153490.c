/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153490 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern s32 func_801536DC(s32 a0);
extern void func_80146CA0(void *a0);

void func_80153490(s32 a0) {
    func_80149020((s32 *)a0);
    if (!func_801536DC(a0)) {
        *(s8 *)(a0 + 0xDE) = 1;
        *(s8 *)(a0 + 0xDF) = 0;
        func_80146CA0((void *)a0);
    }
}
