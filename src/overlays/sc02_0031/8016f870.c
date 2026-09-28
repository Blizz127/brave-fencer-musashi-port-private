/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F870,8016F8AC).
 * Offset 0x47718 at overlay base 80128158. SHA256(span)=eee3b5686734c122e9877bd365c242b6f834c53e143191d3163a7a8d57da68af.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f870.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F870 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_8016F8AC(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F870(u8 *a0) {
    func_801719A4((int)a0, 2);
    func_80171990(a0);
    func_8016F8AC(a0);
}
