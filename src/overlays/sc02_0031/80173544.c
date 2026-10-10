/* SC02 resident retail span [80173544,80173580). Offset 0x4B3EC at base 80128158.
 * SHA256(span)=6cec0a5b24c4910504edaa1f94c24a8027422c3d721af41ce48cd833a5f8f450.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181964->D_80188254.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173544 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188254[])(void *);

void func_80173544(void *a0) {
    D_80188254[*(u8 *)((s32)a0 + 0x214)](a0);
}
