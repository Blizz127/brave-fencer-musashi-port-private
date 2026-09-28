/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152C40,80152C80).
 * Offset 0x2AAE8 at overlay base 80128158. SHA256(span)=a1217cbefb42b4e904a1c4bdc337c8496d1f843ea8e98d81522c13fdddc8c668.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152c40.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152C40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void func_80152C80(s32 *a0);
extern void func_80159B3C(void *a0);
extern void func_80165718(s32 a0);

void func_80152C40(s32 *a0) {
    func_80149020(a0);
    func_80152C80(a0);
    func_80159B3C(a0);
    func_80165718((s32)a0);
}
