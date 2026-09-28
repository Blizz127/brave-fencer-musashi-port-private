/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015430C - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_8015430C(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0xB4) = arg1;
    *(s16 *)(arg0 + 0xBA) = 1;
    *(s16 *)(arg0 + 0xB8) = 1;
    *(s8 *)(arg0 + 0xBC) = arg2;
    *(s8 *)(arg0 + 0xBD) = arg2;
    *(s8 *)(arg0 + 0xDC) = func_801549F8((s32)arg0, arg1, arg2);
    func_80154418(arg0);
}
