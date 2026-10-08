/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157E00,80157E38).
 * Offset 0x2FCA8 at overlay base 80128158. SHA256(span)=65176389459e8e5d4f4c6c88d17779c101e200dc69fd46d60b87d99222d3e763.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157e00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157E00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104();
extern void func_80157E38(void *);

void func_80157E00(void *a0) {
    if (func_80161104(a0)) {
        func_80157E38(a0);
    }
}
