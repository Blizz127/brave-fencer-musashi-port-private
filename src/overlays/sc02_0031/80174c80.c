/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174C80,80174CB0).
 * Offset 0x4CB28 at overlay base 80128158. SHA256(span)=4676fc7d5f9f937d902ae3e715d7f5d61302d658d0422950b26315d5c4b7dd26.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174c80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174C80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80174CB0();

void func_80174C80(s32 a0) {
    s32 v;
    v = (*(u16 *)(a0 + 0xA0) - 0x16) & 0xFFF;
    *(s16 *)(a0 + 0xA0) = v;
    func_80174CB0(a0, v);
}
