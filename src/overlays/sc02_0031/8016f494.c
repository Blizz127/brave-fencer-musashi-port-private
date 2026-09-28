/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F494,8016F4C4).
 * Offset 0x4733C at overlay base 80128158. SHA256(span)=117a1f082a7a48dc39ef418f78c73e9bedec16e49984f48ae6019f35571a54e4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f494.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F494 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80175414(s32 _arg0);
extern s32 func_8016F4C4(s32);
extern void func_8012A568(void (*a0)(void));

s32 func_8016F494(s32 a0) {
    func_80175414(a0);
    return func_8016F4C4(a0);
}
