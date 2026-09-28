/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172D14,80172D60).
 * Offset 0x4ABBC at overlay base 80128158. SHA256(span)=a8c7116186aada26e221796858ccfcb6d6c03e975ab73bd5037177c5500e5b3d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172d14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172D14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B30;

void func_80172D14(u8 * a0)
{
    if (func_80171AB0(a0, &D_80126B30) == 0) {
        func_80171A1C((u8 *)a0);
        func_80174650(a0);
    }
}
