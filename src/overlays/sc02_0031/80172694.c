/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172694,801726A0).
 * Offset 0x4A53C at overlay base 80128158. SHA256(span)=fbbc42445346cb06f90c540756b29ef8502508417573af209162f5147dd28f25.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172694.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172694 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80172694(s32 *a0) {
    return *(s32*)((s32)a0 + 0x1F4) & 0x20;
}
