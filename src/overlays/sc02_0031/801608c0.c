/* SC02.CD FILE_031 / ov_SC02_031 retail span [801608C0,80160920).
 * Offset 0x38768 at overlay base 80128158. SHA256(span)=56152d9231e39a4adecc4c1d7b35cbe1a4b1bdc07fd53798512a0199ba189807.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801608c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801608C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553A8(s32 *a0);
extern void func_80155440(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_801608C0(s32 *a0) {
    *(s32 *)((s32)a0 + 0x44) |= 0x41;
    func_801553A8(a0);
    func_80155440(a0);
    func_80154150((s32)a0, 0x24);
    func_80154A74((s32)a0, 0x1D);
    func_80146CA0(a0);
}
