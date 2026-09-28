/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C6AC,8015C6E0).
 * Offset 0x34554 at overlay base 80128158. SHA256(span)=7d4fc243540b03020b29fb7cf89d0a4dd5da90047b456cc8a89cc57fa4e757d5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015c6ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015C6AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015C788(s32 a0);

void func_8015C6AC(s32 *a0) {
    func_80147078(a0, 0x9);
    func_8015C788(a0);
}
