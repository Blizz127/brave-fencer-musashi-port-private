/* SC02.CD FILE_031 / ov_SC02_031 retail span [801395D4,80139634).
 * Offset 0x1147C at overlay base 80128158. SHA256(span)=0c7ddc1e44be2fe417175ece8e98d9734a06e743e6b765f9d62d4fcb5626d967.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801395d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801395D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Stk801395D4;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);

void func_801395D4(void * a0)
{
    Stk801395D4 sp10;
    u16 mul;
    u16 base;
    sp10.f0 = *(u16 *)(a0 + 0x38);
    mul = *(u16 *)(a0 + 0x12);
    base = *(u16 *)(a0 + 0x3A);
    sp10.f4 = 0x38;
    sp10.f6 = 0xC;
    sp10.f2 = base + mul * 12;
    func_80059888(&sp10, 0, 0, 0);
}
