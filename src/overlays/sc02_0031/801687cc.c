/* SC02.CD FILE_031 / ov_SC02_031 retail span [801687CC,80168828).
 * Offset 0x40674 at overlay base 80128158. SHA256(span)=128ff978787602976fddfd94cba6a0c4013766d76c0f64b881d7f2cb63c36286.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801687cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801687CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80168828(void);
extern void func_80146C3C();

void func_801687CC(s32 param_1)
{
    if (*(int *)(param_1 + 0x1c) < 3) {
        func_80168828();
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
}
