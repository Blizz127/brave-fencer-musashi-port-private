/* SC02.CD FILE_031 / ov_SC02_031 retail span [801661CC,80166244).
 * Offset 0x3E074 at overlay base 80128158. SHA256(span)=166054c947dcf79babd614ef0fde332722ef229ee2516abcc77ed01ff140004f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801661cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801661CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801661CC(s32 param_1)
{
    extern s32 func_80128ED8(s32 param_1, s32 *param_2);
    extern void func_80146C3C();
    extern void func_800D22E4(s32 a0);
    if (((s32 (*)(s32, s32))func_80128ED8)(*(s32 *)(param_1 + 0x20), param_1 + 0x24) != 0) {
        ((void (*)(s32))func_80146C3C)(param_1);
    } else {
        func_800D22E4(param_1);
        *(s32 *)(param_1 + 0x10) = (*(s32 *)(param_1 + 0x10) >> 1) + (*(s32 *)(param_1 + 0x10) >> 2);
        *(s32 *)(param_1 + 0x18) = (*(s32 *)(param_1 + 0x18) >> 1) + (*(s32 *)(param_1 + 0x18) >> 2);
    }
}
