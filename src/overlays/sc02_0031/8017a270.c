/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A270,8017A298).
 * Offset 0x52118 at overlay base 80128158. SHA256(span)=25fd0afaaa36965fc57ceda0487da720e098f94dc7d985acc448ef7b6cf2d289.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a270.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A270 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);

void func_8017A270(void) {
    s16 v = 0xD;
    func_80179B74(&v);
}
