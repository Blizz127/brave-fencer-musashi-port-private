/* SC02 resident retail span [80151D24,80151D60). Offset 0x29BCC at base 80128158.
 * SHA256(span)=d1a558c75cc3a8e87000c10c1cb3831d5dff14e6a7c1f24b822e8fce872cc3ce.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801800A0->D_80186990.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151D24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186990[])(void);

void func_80151D24(void *a0) {
    D_80186990[*(u16 *)((s32)a0 + 0x2)]();
}
