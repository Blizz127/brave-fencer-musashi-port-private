/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F5B0,8016F5E0).
 * Offset 0x47458 at overlay base 80128158. SHA256(span)=a48ebe69ac0f98b2b87fc68bb66837911c678c56e0812bc2a0b1c1640f93942c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f5b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F5B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014706C(void *a0);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F5B0(void *a0) {
    func_8014706C(a0);
    func_80171928(a0);
}
