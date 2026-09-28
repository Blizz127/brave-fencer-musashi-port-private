/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FD7C,8016FDB4).
 * Offset 0x47C24 at overlay base 80128158. SHA256(span)=3983b0a72f63efb62372e5547c1a669659e019547f5ab019bd36c425f5a1a1a3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fd7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FD7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80172658(s32 *a0);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FD7C(s32 *a0) {
    if (func_80172658(a0)) {
        func_80171928(a0);
    }
}
