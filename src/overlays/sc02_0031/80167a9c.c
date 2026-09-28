/* SC02 resident retail span [80167A9C,80167AD8). Offset 0x3F944 at base 80128158.
 * SHA256(span)=70eb577d214e8e438fa8331571cd00a526851c01c365024f7d9af3930f337fa4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018135C->D_80187C4C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80167A9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C4C[])(void);

void func_80167A9C(void *a0) {
    D_80187C4C[*(u16 *)((s32)a0 + 0x2)]();
}
