/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172738,80172760).
 * Offset 0x4A5E0 at overlay base 80128158. SHA256(span)=4f7adbd0402895e1f5b001479885d0cb06c27ef268afcf5bf7072fb5594e7115.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172738.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172738 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80174684(void *);
extern s32 func_80172760(s32 a0);

void func_80172738(void) {
    func_80174684((void *)func_80172760);
}
