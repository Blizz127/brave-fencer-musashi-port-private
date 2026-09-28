/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F948,8015F9A4).
 * Offset 0x377F0 at overlay base 80128158. SHA256(span)=6a711df2fe1e3cb69be0986487b8f6d5d7d6dcd2bf180644c72839f2ade2db73.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f948.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
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
