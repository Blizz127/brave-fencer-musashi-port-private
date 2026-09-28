/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174158,80174188).
 * Offset 0x4C000 at overlay base 80128158. SHA256(span)=b62d10d688df04ff4f42a8838fd97c82bcf6a64b25c74eb2267a113244298b88.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174158.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174158 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80174188(s32 a0);
extern void func_801741A8(s32 a0);

void func_80174158(s32 a0) {
    func_80174188(a0);
    func_801741A8(a0);
}
