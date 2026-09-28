/* SC02.CD FILE_031 / ov_SC02_031 retail span [801735EC,80173648).
 * Offset 0x4B494 at overlay base 80128158. SHA256(span)=b8d619da6480954f46b7f22568d0abc45af20086e5a9ff503d30f5c3c51287d9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801735ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801735EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B40;
extern s16 D_80126B32;

void func_801735EC(void *a0) {
    if (D_80126B40 != 0) {
        *(s32 *)((u8 *)a0 + 0x44) |= 0x40000;
    }
    func_801477E8((s32 *)a0, D_80126B32 << 16);
    func_80171A1C((u8 *)a0);
}
