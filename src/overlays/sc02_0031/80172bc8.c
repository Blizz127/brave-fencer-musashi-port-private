/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172BC8,80172C48).
 * Offset 0x4AA70 at overlay base 80128158. SHA256(span)=3a0fa987f6472d69001828bbcc2399dceb5e5f4360f7c93e0440cbe6cf18a717.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172bc8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172BC8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s16 D_80126B32;

void func_80172BC8(void *a0) {
    s32 v0p = *(s32 *)((s32)a0 + 0x20);
    s32 r = func_80012B04(*(s16 *)(v0p + 0x12), D_80126B32, 4);
    s32 v1;
    if (((r << 16) >> 16) == 0) {
        func_80171A1C((u8 *)a0);
        func_80174650((s32)a0);
    }
    v1 = *(s32 *)((s32)a0 + 0x20);
    *(s16 *)(v1 + 0x12) = (*(u16 *)(v1 + 0x12) + r) & 0xFFF;
}
