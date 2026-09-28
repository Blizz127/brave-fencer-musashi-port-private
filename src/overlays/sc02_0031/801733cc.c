/* SC02.CD FILE_031 / ov_SC02_031 retail span [801733CC,801733FC).
 * Offset 0x4B274 at overlay base 80128158. SHA256(span)=35d12ff224126d4b122e551b9407542b91f9df72a3dcaaf83e428ca725ada274.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801733cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801733CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016F30C(void);
extern s32 func_80174650(s32);

void func_801733CC(s32 a0) {
    func_8016F30C();
    func_80174650(a0);
}
