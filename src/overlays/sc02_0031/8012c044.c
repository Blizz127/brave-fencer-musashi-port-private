/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012C044,8012C098).
 * Offset 0x3EEC at overlay base 80128158. SHA256(span)=62e260aaaf377073e90ea01d4475a730db76546249f1fabca8793fbbd61bbe8c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012c044.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C044 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_801274D4;
extern s16 D_80126CAC;
extern s32 D_801274E0;
extern s32 func_80013478(s32 a0, s32 a1);

s32 func_8012C044(s32 a0) {
    s32 (*fp)(void) = (s32 (*)(void))D_801274D4;
    if (fp != 0) {
        return fp();
    }
    return func_80013478(a0 + 4, (s32)&D_80126CAC) >= D_801274E0;
}
