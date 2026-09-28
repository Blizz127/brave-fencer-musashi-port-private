/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E1F4,8015E22C).
 * Offset 0x3609C at overlay base 80128158. SHA256(span)=9cb2c6e6a2837392d3186482fb57a027df29249dcdfe3c35562d0a8bf71dceab.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e1f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E1F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_8015E22C(s32);

void func_8015E1F4(s32 a0) {
    if (func_80161104() != 0) {
        func_8015E22C(a0);
    }
}
