/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012DF34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80126B58;
extern u8 D_801152A8[];
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

s32 func_8012DF34(s32 a0, s32 a1, s32 a2) {
    s32 s0 = a2;
    s32 *p = &D_80126B58;
    if (a0 != 0) {
        if (*(s16 *)(a0 + 0xAA) != 0) {
            return 0;
        }
    }
    if (func_80135888(*(s32 *)((s32)p + 0x20), *(s32 *)((s32)p + 0x38), a1, s0) != 0) {
        func_8012F568(1, 1, 0, 0xA, s0, (s32)D_801152A8);
        return 1;
    }
    return 0;
}
