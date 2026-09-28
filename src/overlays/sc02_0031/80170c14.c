/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170C14,80170C44).
 * Offset 0x48ABC at overlay base 80128158. SHA256(span)=3f4f1bedbeb41bfeafa265003951c4d4b3523215a3221bbc154e883ee75ba195.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170c14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170C14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80171990(u8 *a0);
extern void func_80170C44(u8 *a0);

void func_80170C14(u8 *a0) {
    func_80171990(a0);
    func_80170C44(a0);
}
