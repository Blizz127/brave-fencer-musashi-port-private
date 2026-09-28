/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F410,8016F44C).
 * Offset 0x472B8 at overlay base 80128158. SHA256(span)=162741a744d792586e8df51e0ceb394bfee8e08aa4c34629ddc1b0242f1397fc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f410.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F410 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016F44C(s32 a0);
extern void func_8016F470(s32 a0);
extern void func_8012A568(void (*a0)(void));

s32 func_8016F410(s32 a0) {
    if (func_8016F44C(a0) == 0) {
        return 0;
    }
    func_8016F470(a0);
    return 1;
}
