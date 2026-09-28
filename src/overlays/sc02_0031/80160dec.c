/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160DEC,80160E3C).
 * Offset 0x38C94 at overlay base 80128158. SHA256(span)=efbfdbd2a1e7053691cb247ee1f3f851436e7e93cea1c37de1af5595982c8c01.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160dec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160DEC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_80160DEC(u8 *a0) {
    *(s32 *)(a0 + 0x1AC) = 0;
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
    func_801553C0((s32)a0);
    *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) & -0x181;
    func_80154A74((s32)a0, 0x11);
}
