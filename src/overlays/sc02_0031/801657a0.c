/* SC02.CD FILE_031 / ov_SC02_031 retail span [801657A0,801657D8).
 * Offset 0x3D648 at overlay base 80128158. SHA256(span)=80adb47c21d8b5264212e26466aab9aaf1784ca845a0227c10c454ac57dc42d2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801657a0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801657A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801657D8(void);
extern u8 D_80078EC3;

void func_801657A0(void) {
    if (D_80078EC3 == 0) {
        D_80078EC3 = 1;
        func_801657D8();
    }
}
