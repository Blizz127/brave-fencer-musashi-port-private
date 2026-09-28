/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016D464,8016D4DC).
 * Offset 0x4530C at overlay base 80128158. SHA256(span)=1ea7898f3702a7b83904841e6e885e7902e1b476caf2342d4b44672d4a9bc2e6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016d464.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D464 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
extern void func_8012A568(void (*a0)(void));

void func_8016D464(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x34);
    s32 v0;
    func_800D22E4((s32)a0);
    func_8016CF04((s32)a0, 1);
    v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == -1 || *(u16 *)s1 != 1) {
        *(u16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
    }
}
