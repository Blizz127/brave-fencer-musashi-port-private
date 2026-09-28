/* SC02 resident retail span [80178D18,80178D40). Offset 0x50BC0 at base 80128158.
 * SHA256(span)=b6fa4207fb98a8dc1c27f334aaed30e032d45f7bf812aabe5d17c9fcae55db97.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C7C->D_801B7B0C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178D18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern short D_801B7B0C;
extern void func_80174714(void);

void func_80178D18(void) {
    D_801B7B0C = 0;
    func_80174714();
}
