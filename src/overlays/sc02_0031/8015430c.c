/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015430C,80154358).
 * Offset 0x2C1B4 at overlay base 80128158. SHA256(span)=59ca9b483b7cbcd8dde0a7db748e27abaaefcea56f6c83774dc22d8ce6019526.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015430c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015430C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801549F8(s32 a0, s32 a1, s32 a2);
extern void func_80154418(void *a0);

void func_8015430C(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0xB4) = arg1;
    *(s16 *)(arg0 + 0xBA) = 1;
    *(s16 *)(arg0 + 0xB8) = 1;
    *(s8 *)(arg0 + 0xBC) = arg2;
    *(s8 *)(arg0 + 0xBD) = arg2;
    *(s8 *)(arg0 + 0xDC) = func_801549F8((s32)arg0, arg1, arg2);
    func_80154418(arg0);
}
