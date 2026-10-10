/* SC02 resident retail span [8016F798,8016F7D4). Offset 0x47640 at base 80128158.
 * SHA256(span)=99664a53d4d3483b4e072ba39bc0c497f91ce9dbd9eedb7af12579aeb5e62ddb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801817DC->D_801880CC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F798 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801880CC[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016F798(void *a0) {
    D_801880CC[*(u8 *)((s32)a0 + 0x216)](a0);
}
