/* SC02.CD FILE_031 / ov_SC02_031 retail span [80169FE0,8016A020).
 * Offset 0x41E88 at overlay base 80128158. SHA256(span)=50c24680d5777a282834017a8c9c8bc83c5579d9eaedf5a6caf2b8ea79848e48.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80169fe0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80169FE0 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80169FE0(s32 a0) {
    if (func_80128ED8((void *)*(s32 *)(a0 + 0x20), (void *)(a0 + 0x24)) != 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
