/* SC02 resident retail span [80160EA4,80160EE0). Offset 0x38D4C at base 80128158.
 * SHA256(span)=9eda212de7481ed18ac3ca1159f3ed41b7840ddb8597a6dc6509fc465631d490.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E28->D_80187718.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187718[])(void *);

void func_80160EA4(void *a0) {
    D_80187718[*(u16 *)((s32)a0 + 0x2)](a0);
}
