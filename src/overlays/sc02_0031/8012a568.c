/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A568,8012A598).
 * Offset 0x2410 at overlay base 80128158. SHA256(span)=12f5ecbc5e9af7e5951ed6335fae7c0e177acfb2cd1a05345cbbbfbc2f0c563d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a568.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A568 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A598(void *a0);

void func_8012A568(void (*a0)(void)) {
    func_8012A598(a0);
    a0();
}
