/* SC02.CD FILE_031 / ov_SC02_031 retail span [80131C78,80131CA8).
 * Offset 0x9B20 at overlay base 80128158. SHA256(span)=a63e16ce4d2fa57e0fc404bb0615fb96616230ea984551cb890e0423f4e78c7e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80131c78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131C78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131CA8(s32 a0, s32 a1);

void func_80131C78(s32 a0) {
    s32 v0 = *(s32*)(a0 + 0x20);
    *(s8*)(a0 + 0xC1) = 0;
    *(s16*)(v0 + 0x10) = 0;
    *(s16*)(a0 + 0x5E) = 0;
    func_80131CA8(a0, 0xE);
}
