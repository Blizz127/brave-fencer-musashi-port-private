/* SC02.CD FILE_031 / ov_SC02_031 retail span [801376C8,801376E8).
 * Offset 0xF570 at overlay base 80128158. SHA256(span)=a35bb8fbaf71748305c02966c811364a9d8d28f5402f554c57745e3d348dc8b8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801376c8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801376C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801376E8(int a0, int a1);

void func_801376C8(int a0) {
    func_801376E8(a0, 0);
}
