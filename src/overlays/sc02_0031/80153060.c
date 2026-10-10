/* SC02 resident retail span [80153060,8015309C). Offset 0x2AF08 at base 80128158.
 * SHA256(span)=254995224d07b39036d68c0414b08f5ae55b0a86b63bbeccb48d984ddf65ba78.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180150->D_80186A40.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153060 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186A40[])(void *);

void func_80153060(void *a0) {
    D_80186A40[*(u16 *)((s32)a0 + 0x2)](a0);
}
