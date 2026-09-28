/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172CDC,80172D14).
 * Offset 0x4AB84 at overlay base 80128158. SHA256(span)=8cebc1f3a87d9f1543ceea76312b4758daf47f7d5eb50483a0ce05e137cbabfb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172cdc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172CDC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80172D14(u8 *a0);

void func_80172CDC(u8 *a0) {
    func_80147060(a0);
    func_80171A1C(a0);
    func_80172D14(a0);
}
