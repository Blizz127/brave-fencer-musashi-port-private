/* SC02 resident retail span [801706AC,801706E8). Offset 0x48554 at base 80128158.
 * SHA256(span)=0d76a694088354e74fd7f9a13a486ad27b1e204554f2b1075554340829df9790.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181880->D_80188170.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801706AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188170[])(void);

void func_801706AC(void *a0) {
    D_80188170[*(u8 *)((s32)a0 + 0x216)]();
}
