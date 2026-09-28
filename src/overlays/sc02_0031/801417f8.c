/* SC02.CD FILE_031 / ov_SC02_031 retail span [801417F8,80141874).
 * Offset 0x196A0 at overlay base 80128158. SHA256(span)=16b19deba3e9754b853aac051c0018306638f9f311f6cced62497bab1fecb419.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801417f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801417F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D2624(void);
extern u8 D_800B9A15;
extern u8 D_800B9A16;
extern short D_800B9A02;
extern u16 D_80115114;
extern u16 D_80115112;

void func_801417F8(void) {
    if (D_800B9A15 == 0 || D_800B9A16 != 0) {
        if (D_80115114 == (u16)(D_800B9A02 ^ 1)) {
            func_800D2624();
        } else {
            D_80115112 += 1;
        }
    }
}
