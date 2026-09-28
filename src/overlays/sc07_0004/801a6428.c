/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6428 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);

void func_801A6428(void *a0) {
    s32 *v1;

    v1 = (s32 *)func_80132EF4((s32)a0, 0x6A);
    if (v1 != NULL) {
        *(s32 *)((u8 *)v1 + 0x34) = (s32)a0;
        *(s32 *)((u8 *)v1 + 0x10) = -(*(s32 *)(*(s32 *)((u8 *)a0 + 0x64) + 0x10) >> 1);
        *(s32 *)((u8 *)v1 + 0x18) = -(*(s32 *)(*(s32 *)((u8 *)a0 + 0x64) + 0x18) >> 1);
    }
}
