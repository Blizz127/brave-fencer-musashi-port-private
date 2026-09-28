/* SC02.CD FILE_031 / ov_SC02_031 retail span [801743C0,801743F0).
 * Offset 0x4C268 at overlay base 80128158. SHA256(span)=32fea2311df77d6763b4ed9d9b8798ed24d384a96f19af8ec96a1909e6ff0d75.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801743c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801743C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern void func_801743F0(u8 *a0);

void func_801743C0(u8 *a0) {
    func_80171A1C(a0);
    func_801743F0(a0);
}
