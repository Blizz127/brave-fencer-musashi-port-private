/* SC02.CD FILE_031 / ov_SC02_031 retail span [801709B8,80170A00).
 * Offset 0x48860 at overlay base 80128158. SHA256(span)=8bff7fbada11dbcf95c79c908ea4bd2da77adc09c8ff1b22858c08f7be6922e1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801709b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801709B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_800D599C[];
extern void *D_8011F738;
extern s32 D_80126B58;
extern void func_80170AD8(void *a0);
extern void func_80171904(s32 a0);
extern void func_80170B48(int a0);

void func_801709B8(void) {
    D_8011F738 = D_800D599C;
    func_80171904((s32)func_80170AD8);
    func_80170B48((int)&D_80126B58);
}
