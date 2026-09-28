/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BADC,8016BBA4).
 * Offset 0x43984 at overlay base 80128158. SHA256(span)=3a86038bb6e4406a8b2f8d10fbb8e944481f2d9a83cd16877033e862bba3140b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016badc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016BADC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8012A568(void (*a0)(void));

void func_8016BADC(void *a0, s32 a1, s32 a2) {
    func_80146A6C(0x22, a0, 0, (s16)a1, 0, 0, a2);
    func_80146A6C(0x22, a0, 0, (s16)a1, 0, 1, a2);
    func_80146A6C(0x22, a0, 0, (s16)a1, 0, 2, a2);
    func_80146A6C(0x24, a0, 0, (s16)a1, 0, 0, 0);
}
