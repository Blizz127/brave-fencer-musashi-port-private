/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016629C,801662F4).
 * Offset 0x3E144 at overlay base 80128158. SHA256(span)=56b24e8bfc88ec68074c67cda7394884e6a66887e84300c17fb3fbf0bf354b24.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016629c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016629C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_8016629C(void *a0) {
    func_80146A6C(3, a0, *(s16 *)((s32)a0 + 6),
                  (s16)(*(u16 *)((s32)a0 + 0xA) - 0x10),
                  *(s16 *)((s32)a0 + 0xE), 0xF88FFF2, 0xE000C000);
}
