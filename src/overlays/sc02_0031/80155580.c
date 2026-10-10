/* SC02 resident retail span [80155580,801555BC). Offset 0x2D428 at base 80128158.
 * SHA256(span)=1ba33a6a0ad8c9f7947589078873f59a158ff6013d06f1438f530882b4c595b5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801801F0->D_80186AE0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155580 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186AE0[])(void *);

void func_80155580(void *a0) {
    D_80186AE0[*(u16 *)((s32)a0 + 0x2)](a0);
}
