/* SC02.CD FILE_031 / ov_SC02_031 retail span [80150F80,80150FB4).
 * Offset 0x28E28 at overlay base 80128158. SHA256(span)=3606cec6ba563fd077dcce7bebfd208986f08414ccb4013796c429349b48eae8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80150f80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150F80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80151184(s32 a0, s32 a1, s32 a2);
extern u8 D_80078EC1;

void func_80150F80(s32 a0) {
    if (D_80078EC1 != 0xC) {
        func_80151184(a0, 0xC007, 0x20);
    }
}
