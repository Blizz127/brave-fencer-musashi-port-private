/* SC02 resident retail span [801693CC,80169408). Offset 0x41274 at base 80128158.
 * SHA256(span)=19ec9f400bdc2ae74c0a1c7a81e96151bc2566ea79d8495c347e023ab579ea76.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018139C->D_80187C8C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801693CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C8C[])(void);

void func_801693CC(void *a0) {
    D_80187C8C[*(u16 *)((s32)a0 + 0x2)]();
}
