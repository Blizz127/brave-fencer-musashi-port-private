/* SC02.CD FILE_031 / ov_SC02_031 retail span [801596D4,801596F0).
 * Offset 0x3157C at overlay base 80128158. SHA256(span)=0039a44c6adb1b45f8fd98846be375bd7418f703283f17800bdb5b7125efd47a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801596d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801596D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801596D4(void *a0) {
    *(s32 *)((s32)a0 + 0x28) = 0x10;
    *(u8 *)((s32)a0 + 0x15) = *(u8 *)((s32)a0 + 0x15) + 1;
    return 0;
}
