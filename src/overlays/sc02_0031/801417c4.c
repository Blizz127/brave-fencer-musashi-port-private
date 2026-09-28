/* SC02.CD FILE_031 / ov_SC02_031 retail span [801417C4,801417F8).
 * Offset 0x1966C at overlay base 80128158. SHA256(span)=766e3c307fe13244613b48ec688e016d68bcc268bd1d1c5130e1bb38e985bf91.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801417c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801417C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001903C(void);
extern u16 D_80115112;

void func_801417C4(void) {
    u16 *p = &D_80115112;
    func_8001903C();
    *p = *p + 1;
}
