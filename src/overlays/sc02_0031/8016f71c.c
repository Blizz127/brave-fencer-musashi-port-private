/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F71C,8016F764).
 * Offset 0x475C4 at overlay base 80128158. SHA256(span)=fbcf63603c710ec4119d4e7fbc4431f842731a0b969a1e3b0010efbddd887bfc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f71c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F71C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *D_8011F738;
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_8016F764(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F71C(u8 *a0) {
    func_801719A4((int)a0, 1);
    *(void **)(a0 + 0x200) = D_8011F738;
    func_80171990(a0);
    func_8016F764((s32)a0);
}
