/* SC02.CD FILE_031 / ov_SC02_031 retail span [80150FD8,80151014).
 * Offset 0x28E80 at overlay base 80128158. SHA256(span)=aeca55e70b6fc087bed8d9da9f0bca9ecafcdebc2fd3e09146e3be7efcb9825a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80150fd8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150FD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern u16 D_800B99DA;

void func_80150FD8(s32 a0) {
    if (D_800B99DA & 7) {
        func_80146994(0x34, a0, 0, 0);
    }
}
