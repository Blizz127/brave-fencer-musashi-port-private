/* SC02 resident retail span [8013373C,80133784). Offset 0xB5E4 at base 80128158.
 * SHA256(span)=a597560631580f6fb21806d4ec562cb67163d685d6734362b2990546f6555f34.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184120->D_801B62D8; D_80184124->D_801B62DC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013373C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B62DC[];
extern s32 D_801B62D8;
extern void func_80136BC4(s32);

void func_8013373C(s16 arg0) {
    s32 temp = D_801B62DC[arg0];
    if (temp != 0) {
        D_801B62D8 = temp;
        func_80136BC4(temp);
    }
}
