/* SC02 resident retail span [8016F6E0,8016F71C). Offset 0x47588 at base 80128158.
 * SHA256(span)=8c1f4d378badbdce3ce4d5afa0ce9bd52671b00de47d736051fdcb40137b51b6.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801817D4->D_801880C4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F6E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801880C4[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016F6E0(void *a0) {
    D_801880C4[*(u8 *)((s32)a0 + 0x216)](a0);
}
