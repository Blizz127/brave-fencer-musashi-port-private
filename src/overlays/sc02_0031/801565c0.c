/* SC02.CD FILE_031 / ov_SC02_031 retail span [801565C0,80156600).
 * Offset 0x2E468 at overlay base 80128158. SHA256(span)=f5aaa140f8a6f7105fa73592a2560d6211649ca71a1b18a552f54b52694acbe7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801565c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801565C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801151E0[];

s32 func_801565C0(void) {
    s32 result;
    u32 i;
    result = 0;
    for (i = 0; i < 3; i++) {
        if (D_801151E0[i] & 1) {
            result |= 1;
        }
    }
    return result;
}
