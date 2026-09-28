/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171854,80171884).
 * Offset 0x496FC at overlay base 80128158. SHA256(span)=865121c88d66b86941844e81297409f2154251a68e7a179631d5ede1741e1dee.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171854.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171854 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80175454(void);
extern void func_80171928(void *a0);

void func_80171854(void *a0) {
    func_80175454();
    func_80171928(a0);
}
