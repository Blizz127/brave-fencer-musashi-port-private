/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170A48,80170A90).
 * Offset 0x488F0 at overlay base 80128158. SHA256(span)=a58845b2004e5c37e6c1d23126fccc8cc08be9329bc9f1449d951615e73d7e3a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170a48.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170A48 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_800D5DA8;
extern void *D_8011F738;
extern s32 D_80126B58;
extern void func_80170AD8(void *a0);
extern void func_80171904(s32 a0);
extern void func_80170B48(int a0);

void func_80170A48(void) {
    D_8011F738 = &D_800D5DA8;
    func_80171904((s32)func_80170AD8);
    func_80170B48((int)&D_80126B58);
}
