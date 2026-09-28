/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142778,801427DC).
 * Offset 0x1A620 at overlay base 80128158. SHA256(span)=d3ebc319079cf3c27071417545c6581d69b2ba6145d5c6a0b72125628b2478de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142778.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142778 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012C218(void *a0);

void func_80142778(u8 *a1) {
    u8 *a0 = *(u8 **)(a1 + 0x20);
    *(u16 *)(a0 + 0x18) = *(u16 *)(a0 + 0x18) - 0x800;
    *(u16 *)(a0 + 0x1A) = *(u16 *)(a0 + 0x1A) - 0x800;
    *(u16 *)(a1 + 0xA) = *(u16 *)(a1 + 0xA) + 0x10;
    if (*(s16 *)(a0 + 0x18) <= 0) {
        func_8012C218(a1);
    }
}
