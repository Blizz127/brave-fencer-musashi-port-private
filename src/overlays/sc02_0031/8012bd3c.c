/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012BD3C,8012BDBC).
 * Offset 0x3BE4 at overlay base 80128158. SHA256(span)=f063951aa369f933e66706f1140f5969f2c0a77c872882de2b1206d46fb6db95.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012bd3c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BD3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80013478(s32 a0, s32 a1);
extern s32 func_8012BDBC(s32 a0, s32 a1);
extern s16 D_80126CBA;
extern s16 D_80126CB4;

s32 func_8012BD3C(s32 a0, s32 a1, s32 a2) {
    s32 v;
    s32 hp;
    hp = a1;
    if (D_80126CBA != 0) {
        v = 0x7FFFFFFF;
    } else {
        v = func_80013478(a0 + 4, (s32)&D_80126CB4);
    }
    if (a2 < v) {
        return 0;
    }
    return func_8012BDBC(a0, (s16)hp);
}
