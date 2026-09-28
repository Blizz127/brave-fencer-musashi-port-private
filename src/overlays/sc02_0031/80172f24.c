/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172F24,80172F4C).
 * Offset 0x4ADCC at overlay base 80128158. SHA256(span)=ec70693796b8f78bf77d38be7109a1cc702fcd42f1abe075352c66e27e5c216e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172f24.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172F24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017303C(void *);
extern u8 D_800D5934[];

void func_80172F24(void) {
    func_8017303C(D_800D5934);
}
