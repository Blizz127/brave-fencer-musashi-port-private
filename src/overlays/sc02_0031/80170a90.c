/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170A90,80170AD8).
 * Offset 0x48938 at overlay base 80128158. SHA256(span)=8de90190502936ef320d3684a6fc8b26f757963a54a1db4b70acb1430382f196.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170a90.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170A90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_800D5DC0[];
extern void *D_8011F738;
extern s32 D_80126B58;
extern void func_80170AD8(void *a0);
extern void func_80171904(s32 a0);
extern void func_80170B48(int a0);

void func_80170A90(void) {
    D_8011F738 = D_800D5DC0;
    func_80171904((s32)func_80170AD8);
    func_80170B48((int)&D_80126B58);
}
