/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C08C,8015C0C4).
 * Offset 0x33F34 at overlay base 80128158. SHA256(span)=bd8a9dcfc6b17345c27db5168d38ecd346c5daa3b5f62ac206fb8806bb4fa555.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015c08c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015C08C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104();
extern void func_8015C0C4(s32);

void func_8015C08C(s32 a0) {
    if (func_80161104(a0) != 0) {
        func_8015C0C4(a0);
    }
}
