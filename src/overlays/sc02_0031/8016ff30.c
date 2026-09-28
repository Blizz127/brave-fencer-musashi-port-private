/* SC02 resident retail span [8016FF30,8016FF6C). Offset 0x47DD8 at base 80128158.
 * SHA256(span)=ddb56ea5b01207a79f6972846a292325ce8ca609dcc5e496eea2e355d99d0c73.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181830->D_80188120.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FF30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188120[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016FF30(void *a0) {
    D_80188120[*(u8 *)((s32)a0 + 0x216)]();
}
