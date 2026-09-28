/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170928,80170970).
 * Offset 0x487D0 at overlay base 80128158. SHA256(span)=0834dc9913fe01504f0f7aadb53ac080702dc3f89a4fea1f28e53bca2cb39a62.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170928.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170928 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_800D5A34[];
extern void *D_8011F738;
extern s32 D_80126B58;
extern void func_80170AD8(void *a0);
extern void func_80171904(s32 a0);
extern void func_80170B48(int a0);

void func_80170928(void) {
    D_8011F738 = D_800D5A34;
    func_80171904((s32)func_80170AD8);
    func_80170B48((int)&D_80126B58);
}
