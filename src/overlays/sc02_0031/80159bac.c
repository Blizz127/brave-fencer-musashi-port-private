/* SC02.CD FILE_031 / ov_SC02_031 retail span [80159BAC,80159BE4).
 * Offset 0x31A54 at overlay base 80128158. SHA256(span)=182dba0be6450c432b3f6facb840b5a4a1c6ff110035c3ef4544486f4ba18ecd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80159bac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159BAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_80159BE4(s32);

void func_80159BAC(s32 a0) {
    if (func_80161104() != 0) {
        func_80159BE4(a0);
    }
}
