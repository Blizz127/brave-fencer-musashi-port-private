/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC3C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_801A9908(void *a0, s32 a1);
extern void func_801A9954(void *a0);
extern u16 D_801B070C[];

void func_801AC3C8(void *a0) {
    void *s1;
    s16 t;

    s1 = *(void **)((s32)a0 + 0xCC);
    if (func_80128ED8((s32)s1, (s32 *)((s32)a0 + 0xF0)) != 0) {
        func_801A9954(a0);
        return;
    }

    *(u8 *)((s32)s1 + 0x27) = (u8)D_801B070C[*(s16 *)((s32)a0 + 0xF4)];

    t = *(s16 *)((s32)a0 + 0xF4) * 14 + 0x30;
    if (*(s16 *)((s32)a0 + 0xFE) == 0) {
        t = t >> 1;
    }
    func_801A9908(a0, t);
}
