/* SC02 resident retail span [8015EE08,8015EE44). Offset 0x36CB0 at base 80128158.
 * SHA256(span)=9684d8b232ae15749284206b2457401040ca218f6e40f137ae7dcf3227ee29a6.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D10->D_80187600.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015EE08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8015EE08(s32 a0) {

    extern void (*D_80187600[])(s32);
    D_80187600[*(u16 *)((s32)a0 + 0x2)](a0);
}
