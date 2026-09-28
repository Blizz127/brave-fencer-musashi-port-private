/* SC02.CD FILE_031 / ov_SC02_031 retail span [801541D8,80154218).
 * Offset 0x2C080 at overlay base 80128158. SHA256(span)=c89e98ea8c985f7bf39f98384a379acea57107f42e2a5713ddb322652476659f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801541d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801541D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154218(u8 *a0, s32 a1, s32 a2);

void func_801541D8(u8 *a0, s32 a1, s32 a2) {
    if (*(s32 *)(a0 + 0xB4) != ((s32 *)*(s32 **)(a0 + 0xB0))[a1]) {
        func_80154218(a0, a1, a2);
    }
}
