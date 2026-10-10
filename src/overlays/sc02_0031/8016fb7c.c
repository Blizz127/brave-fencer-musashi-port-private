/* SC02 resident retail span [8016FB7C,8016FBB8). Offset 0x47A24 at base 80128158.
 * SHA256(span)=f1320f4b7a2d43787d833b92ff22cdda104b7df565a73b2644bcd4d0b03fb18a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181808->D_801880F8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FB7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801880F8[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016FB7C(void *a0) {
    D_801880F8[*(u8 *)((s32)a0 + 0x216)](a0);
}
