/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174188,801741A8).
 * Offset 0x4C030 at overlay base 80128158. SHA256(span)=0aaa6bddafa1696aa62c3c92ef1518e1399f5859695258245ff9b8c85b734488.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174188.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174188 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8014BCEC(s32, s32);

s32 func_80174188(s32 a0) {
    return func_8014BCEC(a0, 0x19);
}
