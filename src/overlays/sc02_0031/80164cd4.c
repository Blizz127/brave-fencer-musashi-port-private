/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164CD4,80164D4C).
 * Offset 0x3CB7C at overlay base 80128158. SHA256(span)=19ec0c7fbc687d37e3d7c026b3421899261f5deedb45338fbc5291bfcb34ac73.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164cd4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164CD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80164E40(void);
extern void func_80146CA0(void *a0);

void func_80164CD4(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x20);
    u16 v1;
    func_80164E40();
    v1 = *(u16 *)(a0 + 0x60) + *(u16 *)(a0 + 0x62);
    *(u16 *)(a0 + 0x60) = v1;
    *(u16 *)(s0 + 0x1A) = *(u16 *)(s0 + 0x1A) + v1;
    *(u16 *)(s0 + 0x18) = *(u16 *)(s0 + 0x1A);
    if (*(s16 *)(a0 + 0x60) < 0) {
        func_80146CA0(a0);
    }
}
