/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170338,80170374).
 * Offset 0x481E0 at overlay base 80128158. SHA256(span)=d0f3258cf41790970e18abff059448525ee7205bf5aad7cbf98c018b13a88845.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170338.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170338 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_80170374(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_80170338(u8 *a0) {
    func_801719A4((int)a0, 1);
    func_80171990(a0);
    func_80170374(a0);
}
