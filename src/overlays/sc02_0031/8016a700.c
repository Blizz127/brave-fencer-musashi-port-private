/* SC02 resident retail span [8016A700,8016A73C). Offset 0x425A8 at base 80128158.
 * SHA256(span)=3c6fb88030c28778a025abbf8891ea2de67c148632530d3687ea11760acaa3bc.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801814A4->D_80187D94.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A700 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187D94[])(void *);

void func_8016A700(void *a0) {
    D_80187D94[*(u16 *)((s32)a0 + 0x2)](a0);
}
