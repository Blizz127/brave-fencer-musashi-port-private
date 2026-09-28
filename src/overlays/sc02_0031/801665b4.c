/* SC02.CD FILE_031 / ov_SC02_031 retail span [801665B4,80166618).
 * Offset 0x3E45C at overlay base 80128158. SHA256(span)=b4ba4d25da0be028ed48d7248a5c7b7c2a326ebcc4970cf0f234f2ab1e5c730e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801665b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801665B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);

void func_801665B4(s32 *a0)
{
    if (func_80128ED8((void *)a0[8], (void *)(a0 + 9))) {
        func_80146C3C((s32)a0);
    } else {
        func_800D22E4((s32)a0);
        a0[5] -= a0[5] >> 3;
    }
}
