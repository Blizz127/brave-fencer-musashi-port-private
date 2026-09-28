/* SC02 resident retail span [801702FC,80170338). Offset 0x481A4 at base 80128158.
 * SHA256(span)=524eb5744f8631d16a773ebf54e4740badb9acf7b0676cd95c5fc7e41740b0c0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181858->D_80188148.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801702FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188148[])(void);
extern void func_8012A568(void (*a0)(void));

void func_801702FC(void *a0) {
    D_80188148[*(u8 *)((s32)a0 + 0x216)]();
}
