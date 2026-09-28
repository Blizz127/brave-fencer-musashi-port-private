/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157B74,80157BC8).
 * Offset 0x2FA1C at overlay base 80128158. SHA256(span)=bd58fa93d676cce3b5c5d32877df358e330426ec24dc9e82faece2d45f35190d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157b74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157B74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();

void func_80157B74(int param_1)
{
    if (*(unsigned short *)(param_1 + 0xB8) == 0x8000) {
        ((void (*)(void))func_801599A4)();
        ((void (*)(int))func_80159B3C)(param_1);
    } else {
        ((void (*)(int))func_80161208)(param_1);
    }
}
