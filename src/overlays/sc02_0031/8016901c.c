/* SC02 resident retail span [8016901C,80169058). Offset 0x40EC4 at base 80128158.
 * SHA256(span)=2963466a82555567a9bce1b5530176944ef1dd9314b66596c5a10337ad2002fb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181394->D_80187C84.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016901C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C84[])(void);

void func_8016901C(void *a0) {
    D_80187C84[*(u16 *)((s32)a0 + 0x2)]();
}
