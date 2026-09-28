/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165958,80165978).
 * Offset 0x3D800 at overlay base 80128158. SHA256(span)=c4d394a16faf35fd83dad4d22caf9863e21e92e042173243366799d4acd63d1a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165958.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165958 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8012672C;

void func_80165958(void) {
    D_8012672C = D_8012672C + 1;
}
