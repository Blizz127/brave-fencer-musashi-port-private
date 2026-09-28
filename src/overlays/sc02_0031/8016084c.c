/* SC02 resident retail span [8016084C,80160888). Offset 0x386F4 at base 80128158.
 * SHA256(span)=55b9e2152d9f8246e5a01ff963e9169d6b06a300a9ae8dcc0e2487654c33631d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E0C->D_801876FC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016084C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8016084C(s32 *a0) {

    extern void (*D_801876FC[])(void);
    D_801876FC[*(u16 *)((s32)a0 + 0x2)]();
}
