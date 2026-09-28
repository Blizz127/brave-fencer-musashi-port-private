/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173580,801735B8).
 * Offset 0x4B428 at overlay base 80128158. SHA256(span)=06d558c78be895d0f91a191feb6311a1c4164e6b913b18da08c24375a420e65f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173580.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173580 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_801735B8(u8 *a0);

void func_80173580(u8 *a0) {
    func_80147060(a0);
    func_80171A1C(a0);
    func_801735B8(a0);
}
