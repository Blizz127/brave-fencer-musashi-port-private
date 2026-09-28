/* SC02 resident retail span [80151944,80151980). Offset 0x297EC at base 80128158.
 * SHA256(span)=89c75a38b122571a4fa226f4e24a8bcd6054231ab5d4938ee4e99db1dbf1f4fe.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180090->D_80186980.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151944 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80151944(void *a0) {

    extern void (*D_80186980[])(void);
    D_80186980[*(u16 *)((s32)a0 + 0x2)]();
}
