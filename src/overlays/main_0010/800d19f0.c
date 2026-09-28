/* MAIN10 resident retail span [800D19F0,800D1B10), offset 0x22BF8 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D19F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80126BA6;
extern s16 D_800B9A08;
extern s32 D_80114EA8;
extern s32 D_800AE6B0;
extern s32 D_800AE6A8;
extern void func_8001BE20(void);
extern s32 func_8001BE30(void);
extern void func_800CF8E4(void);
typedef struct {
    s32 (*f[3])(u8 *);
} FnTbl;
extern FnTbl D_801141C8;

s32 func_800D19F0(void) {
    FnTbl fns;
    u8 *s0 = (u8 *)&D_800AE6A8;
    s32 v1;

    fns = D_801141C8;

    if (D_80126BA6 != 0) {
        return 0;
    }
    if (D_800B9A08 != 0x3069) {
        v1 = D_80114EA8;
        if (v1 != 1) {
            if (v1 >= 2) {
                goto dispatch;
            }
            if (v1 != 0) {
                goto dispatch;
            }
            func_8001BE20();
            D_80114EA8 = D_80114EA8 + 1;
        }
        if (func_8001BE30() == 0) {
            return 0;
        }
        D_80114EA8 = D_80114EA8 + 1;
        if ((D_800AE6B0 & 0x1000000) == 0) {
            func_800CF8E4();
        }
    }
dispatch:
    return fns.f[s0[0x14]](s0);
}
