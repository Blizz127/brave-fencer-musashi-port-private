/* SC02 resident retail span [80153320,8015335C). Offset 0x2B1C8 at base 80128158.
 * SHA256(span)=7d2b0b9899bda8eedaa6b9e07b441bf09b5f60653530d914bd0d638a38398bdd.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180164->D_80186A54.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153320 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186A54[])(void *);

void func_80153320(void *a0) {
    D_80186A54[*(u16 *)((s32)a0 + 0x2)](a0);
}
