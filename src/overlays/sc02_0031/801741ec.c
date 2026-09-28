/* SC02.CD FILE_031 / ov_SC02_031 retail span [801741EC,80174274).
 * Offset 0x4C094 at overlay base 80128158. SHA256(span)=b94d480e0f1c0f382cab6c3c92b01652c64b71bd728ec25c3458b35cd0a32b30.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801741ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801741EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B3C;
extern s16 D_8011F9C8;

void func_801741EC(u8 *a0) {
    s32 v0;
    s32 s1;
    s32 t;
    v0 = *(s32 *)(a0 + 0x20);
    s1 = func_80012B04(*(s16 *)(v0 + 0x12), D_80126B3C, 4);
    if ((s16)s1 == 0) {
        D_8011F9C8 = 1;
        func_80171A1C(a0);
        func_80174650((s32)a0);
    }
    t = *(s32 *)(a0 + 0x20);
    *(u16 *)(t + 0x12) = (*(u16 *)(t + 0x12) + s1) & 0xFFF;
}
