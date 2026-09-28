/* SC02 resident retail span [80165670,80165694). Offset 0x3D518 at base 80128158.
 * SHA256(span)=295a0328af340ed75e99f5417357f29598a2021268b03be85ea8d9ad129790f0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181080->D_80187970.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165670 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80187970[];
extern s32 D_80078EC8;

void func_80165670(s32 a0, s32 a1) {
    D_80078EC8 = D_80187970[a1 & 0x7F];
}
