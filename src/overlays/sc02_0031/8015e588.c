/* SC02 resident retail span [8015E588,8015E5B0). Offset 0x36430 at base 80128158.
 * SHA256(span)=e68457f814ae5c87ae508d6fc7200934e685301c1eb3db2c7e064b4cde9f1e6e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180CF4->D_801875E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E588 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013C9C4(void *a0);
extern s32 D_801875E4;

void func_8015E588(void) {
    func_8013C9C4(&D_801875E4);
}
