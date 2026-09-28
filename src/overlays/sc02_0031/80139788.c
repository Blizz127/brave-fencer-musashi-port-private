/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139788,801397B0).
 * Offset 0x11630 at overlay base 80128158. SHA256(span)=488d676af2d3cf75aad9144117303cbe4086ef4d23b872ec68f637174ceaa2a4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139788.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139788 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001931C(void);
extern s16 D_8012752C;

void func_80139788(void) {
    func_8001931C();
    D_8012752C = 0;
}
