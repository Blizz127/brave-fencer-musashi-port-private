/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170784,801707D4).
 * Offset 0x4862C at overlay base 80128158. SHA256(span)=d39054d3df36fdbdc98aed071e079c42bddc6b96f702afd23c0b6deae32daadc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170784.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170784 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_801707D4(void *a0);
extern void *D_8011F738;

void func_80170784(u8 *a0) {
    func_801719A4((int)a0, 1);
    (*(void (*)(void))D_8011F738)();
    func_80171990(a0);
    func_801707D4(a0);
}
