/* SC02.CD FILE_031 / ov_SC02_031 retail span [801752BC,80175308).
 * Offset 0x4D164 at overlay base 80128158. SHA256(span)=bb858f465f697208551f6f3f2bad431df41f79f65f32166659ebaefe37d6f3de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801752bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801752BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_801752BC(s32 *a0) {
    *(s16 *)((u8 *)a0 + 0xF6) = 0x1000;
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    *(s32 *)((u8 *)a0 + 0x44) &= ~2;
}
