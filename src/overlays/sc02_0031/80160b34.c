/* SC02 resident retail span [80160B34,80160B70). Offset 0x389DC at base 80128158.
 * SHA256(span)=4d44d1b0651f886d0ec4be29668c5c7ac7ee91ae8f8ec7a569d24fca7f2d187a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E18->D_80187708.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160B34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80160B34(s32 a0) {

    extern void (*D_80187708[])(void);
    D_80187708[*(u16 *)((s32)a0 + 0x2)]();
}
