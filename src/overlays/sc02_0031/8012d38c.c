/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012D38C,8012D3AC).
 * Offset 0x5234 at overlay base 80128158. SHA256(span)=68a15da95bfe9300b256e189b6bd22d19c25a47b286d1eab6a8394d5d1d239c6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012d38c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012D38C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012D098();

void func_8012D38C(int a0) {
    func_8012D098(a0, 0);
}
