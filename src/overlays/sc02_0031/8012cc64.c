/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012CC64,8012CC88).
 * Offset 0x4B0C at overlay base 80128158. SHA256(span)=c0dd37207a1dbf716ec79c7c455a63ed3ee0017f4764ba81bb67f618a2bae2b6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012cc64.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012CC64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012CC88();

void func_8012CC64(s32 a0, s32 a1) {
    func_8012CC88(a0, 0x11, a1);
}
