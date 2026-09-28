/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F948 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015F948(s32 *param_1) {
    extern void func_80146C98(s32 *a0, s16 a1);
    extern void func_80147078(s32 *a0, s16 a1);
    extern void func_80154150(s32 a0, s32 a1);
    extern void func_80154A74(s32 a0, s32 a1);
    extern s32 func_80161104(void);
    func_80147078(param_1, 0x15);
    if (((s32 (*)(s32 *))func_80161104)(param_1) != 0) {
        func_80154150((s32)param_1, 0x22);
        func_80154A74((s32)param_1, 0x1A);
        func_80146C98(param_1, 2);
    }
}
