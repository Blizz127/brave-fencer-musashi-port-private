/* SC02.CD FILE_031 / ov_SC02_031 retail span [801510EC,80151110).
 * Offset 0x28F94 at overlay base 80128158. SHA256(span)=6f5821b48b06d5524c08b2ab41089ec2e61d383e841db9adb3c28ff29600525b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801510ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801510EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_80151184(int arg, int a1, int a2);

int func_801510EC(int arg) {
    return func_80151184(arg, 0xE016, 0x10);
}
