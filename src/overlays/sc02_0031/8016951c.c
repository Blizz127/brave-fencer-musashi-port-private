/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016951C,80169584).
 * Offset 0x413C4 at overlay base 80128158. SHA256(span)=f7f5c86a1a1be2b64f35278b5a3fb0a7b44290adcad609814fa934c2e89ecb79.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016951c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016951C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80169584(s32 param_1);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();

void func_8016951C(int param_1)
{
    int iVar1;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = iVar1 + 1;
    if (iVar1 < 10) {
        ((void (*)(void))func_80169584)();
        func_800D22E4(param_1);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 0x8000;
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
    return;
}
