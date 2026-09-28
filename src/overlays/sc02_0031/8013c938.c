/* SC02 resident retail span [8013C938,8013C964). Offset 0x147E0 at base 80128158.
 * SHA256(span)=1325bf4b9c2ec39cf1f89e47ad8bb94815c59379fe99552da692945104940727.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C10->D_801B7AA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013C938 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8013C938(void) {

    extern s32 D_801B7AA0;
    D_801B7AA0 = 1;
}
