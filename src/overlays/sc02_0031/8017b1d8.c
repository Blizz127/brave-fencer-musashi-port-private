/* SC02 resident retail span [8017B1D8,8017B238). Offset 0x53080 at base 80128158.
 * SHA256(span)=3e2a6b78cfaeff14e6d67c8b1a0516e255f000dc4c52f5975943f66573891a5b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018534C->D_801B7504; D_801853CC->D_801B7584; D_801853CE->D_801B7586; D_801853D0->D_801B7588; D_80185C08->D_801B7A98.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B1D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126B5E;
extern u16 D_80126B66;
extern s16 D_801B7504;
extern u16 D_801B7584;
extern u16 D_801B7586;
extern u16 D_801B7588;
extern s16 D_801B7A98;

void func_8017B1D8(void) {
    /* [T51] scoped in from file scope: a file-scope decl of these symbols constrains every
       LATER function in this TU, which blocks a byte-true decl of a different type.
       Declaration-only move (cookbook §103); the whole-binary byte-gate is the arbiter. */
    extern u16 D_80126B62;
    func_8012A418();
    D_801B7A98 = 0;
    D_801B7504 = 0;
    D_801B7584 = D_80126B5E;
    D_801B7586 = D_80126B62;
    D_801B7588 = D_80126B66;
}
