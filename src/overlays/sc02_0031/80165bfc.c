/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165BFC,80165C58).
 * Offset 0x3DAA4 at overlay base 80128158. SHA256(span)=2619bd2a8c94798365122ec3c81adec5061772228f5768340c25d2d5ff0cebcd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165bfc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165BFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161208();
extern void func_80165C58(s32 arg0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_80165BFC(void *a0) {
    if (func_80161208() == 0) {
        if (*(u16 *)((u8 *)a0 + 0xB8) & 0x8000) {
            func_80165C58((s32)a0);
            func_801599A4(a0);
            func_80159B3C(a0);
        }
    }
}
