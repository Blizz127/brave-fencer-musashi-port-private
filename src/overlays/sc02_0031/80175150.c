/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175150,80175184).
 * Offset 0x4CFF8 at overlay base 80128158. SHA256(span)=ed25fbaeefd73a601d4bdc88941c29d2cf548b733f043bf4774a0d1348343551.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80175184();

void func_80175150(s32 *a0) {
    func_80147078(a0, 0x8);
    func_80175184(a0);
}
