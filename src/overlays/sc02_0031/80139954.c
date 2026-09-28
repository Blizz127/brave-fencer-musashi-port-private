/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139954,801399A8).
 * Offset 0x117FC at overlay base 80128158. SHA256(span)=71fba54b2ca4a9b4fd87a66d54cc3995f4db44ef835879d582a91a4618773476.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139954.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139954 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A8B0(s32 *a0);
extern u16 D_80126A08;
extern s16 D_801269F4;
extern s32 D_801269F0;
extern s32 *D_80126A30;

void func_80139954(void) {
    u16 v = D_80126A08;
    D_801269F4 = 0;
    D_801269F0 = 0;
    if (v != 0) {
        if (D_80126A30 != 0) {
            func_8013A8B0(D_80126A30);
        }
    }
}
