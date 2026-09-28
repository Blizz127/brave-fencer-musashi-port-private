/* SC02 resident retail span [8015DAF8,8015DB34). Offset 0x359A0 at base 80128158.
 * SHA256(span)=b800de52aa06f02c9e5e05d21807f78905d004d2f6d25eb2563ab8871e28dd4f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180C94->D_80187584.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DAF8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015DAF8(s32 *a0) {

    extern void (*D_80187584[])(void);
    D_80187584[*(u16 *)((s32)a0 + 0x2)]();
}
