/* SC02 resident retail span [8015BFF4,8015C030). Offset 0x33E9C at base 80128158.
 * SHA256(span)=9005cbd2d4d4a11dbc536cef7e052487d7577263042e9ad378aca11caf88d1a5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B9C->D_8018748C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BFF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_8018748C[])(void *);

void func_8015BFF4(void *a0) {
    D_8018748C[*(u16 *)((s32)a0 + 0x2)](a0);
}
