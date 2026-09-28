/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174438,80174474).
 * Offset 0x4C2E0 at overlay base 80128158. SHA256(span)=dc3ad0042a734c792934057e7152222b2c079b88fedc1b373cba92232e8d1282.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174438.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174438 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80174684(void *);
extern s32 func_80174474(void *a0);
extern s32 D_80127508;

void func_80174438(s32 a0) {
    func_80174684((void *)func_80174474);
    D_80127508 = a0;
}
