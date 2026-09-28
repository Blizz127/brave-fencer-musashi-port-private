/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017435C,80174384).
 * Offset 0x4C204 at overlay base 80128158. SHA256(span)=fd9d460d33fe988a3e09694c6f798a9f069a1a54b5199c10a7512e71984245a5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017435c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017435C - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 func_80174384(void *a0);

void func_8017435C(void) {
    func_80174684((void *)func_80174384);
}
