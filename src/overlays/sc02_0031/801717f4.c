/* SC02.CD FILE_031 / ov_SC02_031 retail span [801717F4,80171824).
 * Offset 0x4969C at overlay base 80128158. SHA256(span)=b9c210f446901cc3a48ddb2cc17f869a8affb42f446a0d4326afafa4a31a6018.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801717f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801717F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8013E588(void *a0);
extern void func_80171928(void *a0);

void func_801717F4(void *a0) {
    func_8013E588(a0);
    func_80171928(a0);
}
