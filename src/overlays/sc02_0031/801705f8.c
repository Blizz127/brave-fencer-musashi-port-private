/* SC02 resident retail span [801705F8,80170634). Offset 0x484A0 at base 80128158.
 * SHA256(span)=0b3def9becfb1ac93d78b361693b77454276102bf6bc4bc6f8b7559b5d478d0d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181878->D_80188168.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801705F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188168[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_801705F8(void *a0) {
    D_80188168[*(u8 *)((s32)a0 + 0x216)](a0);
}
