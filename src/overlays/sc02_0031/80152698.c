/* SC02 resident retail span [80152698,801526D4). Offset 0x2A540 at base 80128158.
 * SHA256(span)=d9c707ae7071ada0c4d9e62955ae87e9eacd30015816ebe5650fc44f0aab7186.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801800F4->D_801869E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152698 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801869E4[])(void);

void func_80152698(void *a0) {
    D_801869E4[*(u16 *)((s32)a0 + 0x2)]();
}
