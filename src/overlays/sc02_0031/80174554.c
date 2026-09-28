/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174554,80174584).
 * Offset 0x4C3FC at overlay base 80128158. SHA256(span)=9ca1c6def6cf252c07b17ba5b284642da8d85e34e59da3d7e0880512cd9e4b5d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174554.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174554 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014706C(void *arg0);
extern s32 func_80174650(s32);

void func_80174554(s32 arg0) {
        ((void (*)(s32 *))func_8014706C)((s32 *)arg0);
        func_80174650(arg0);
    }
