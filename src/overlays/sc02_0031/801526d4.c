/* SC02.CD FILE_031 / ov_SC02_031 retail span [801526D4,80152714).
 * Offset 0x2A57C at overlay base 80128158. SHA256(span)=23b72b2bdbcf555317bd630952bd67be1860d7b79b3b2fa144359fb61a5c3ae2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801526d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801526D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014E934(s32 a0);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_80152714(s32 a0);

void func_801526D4(s32 a0) {
    func_8014E934(a0);
    func_8014CC28(a0);
    func_8014F3E8(a0);
    func_80152714(a0);
}
