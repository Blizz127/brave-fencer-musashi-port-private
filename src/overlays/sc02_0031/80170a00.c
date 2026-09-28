/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170A00,80170A48).
 * Offset 0x488A8 at overlay base 80128158. SHA256(span)=db08b5dee6a403d9547b8d27bbd9bafed2f781622a13df9b052846ad071550af.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170a00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170A00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_800D5934[];
extern void *D_8011F738;
extern s32 D_80126B58;
extern void func_80170AD8(void *a0);
extern void func_80171904(s32 a0);
extern void func_80170B48(int a0);

void func_80170A00(void) {
    D_8011F738 = D_800D5934;
    func_80171904((s32)func_80170AD8);
    func_80170B48((int)&D_80126B58);
}
