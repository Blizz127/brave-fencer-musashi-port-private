/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172ACC,80172B0C).
 * Offset 0x4A974 at overlay base 80128158. SHA256(span)=0159aeb4f8c6aa2100a50f0b20b158e388364ccd5065e63d9b93b985aea77987.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172acc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172ACC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);

void func_80172ACC(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x20);
    u16 v = *(u16 *)(a0 + 0x132);
    *(s16 *)(a0 + 0x136) = 0;
    *(u16 *)(p + 0x12) = v;
    func_80171A1C(a0);
    func_80174650((s32)a0);
}
