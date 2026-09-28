/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161B84,80161BE0).
 * Offset 0x39A2C at overlay base 80128158. SHA256(span)=e24f79471aa19733ffe1d8b9140fbc22ea0638bb98513674bdeecd838cf80922.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161b84.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161B84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80149884(void);
extern void func_801599A4(void *a0);
extern void func_801498C0(void);

s32 func_80161B84(void *a0) {
    if ((((s32 *)a0)[0x11] & 0x100) != 0) {
        if (func_80149884() != 0) {
            func_801599A4(a0);
            (*(void (*)(void *))func_801498C0)(a0);
            return 1;
        }
    }
    return 0;
}
