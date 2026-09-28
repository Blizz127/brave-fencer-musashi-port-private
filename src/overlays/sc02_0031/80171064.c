/* SC02 resident retail span [80171064,801710A0). Offset 0x48F0C at base 80128158.
 * SHA256(span)=9ad7a1a6008a55ffbe0e636a630c5502d51c946a98d47564947a8b74f0082ec4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818D0->D_801881C0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171064 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881C0[])(void);

void func_80171064(void *a0) {
    D_801881C0[*(u8 *)((s32)a0 + 0x216)]();
}
