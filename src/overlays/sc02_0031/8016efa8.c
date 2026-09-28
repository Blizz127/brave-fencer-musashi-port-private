/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EFA8,8016EFC8).
 * Offset 0x46E50 at overlay base 80128158. SHA256(span)=d34eb8ab60f335b1fd3d6aa7730cbd6b3f40bcdc6fe697c96dd10ef1e6163a6c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016efa8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016EFC8();
extern void func_8012A568(void (*a0)(void));

s32 func_8016EFA8(s32 a0) {
    return func_8016EFC8(a0);
}
