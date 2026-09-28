/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170718,80170748).
 * Offset 0x485C0 at overlay base 80128158. SHA256(span)=ab86cfd5044097f4657f0be89f38a5c45587077c6f919c09ea4e040b78667f9b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170718.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170718 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80129FF4(void);
extern void func_80171928(void *a0);

void func_80170718(void *a0) {
    func_80129FF4();
    func_80171928(a0);
}
