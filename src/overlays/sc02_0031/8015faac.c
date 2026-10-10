/* SC02 resident retail span [8015FAAC,8015FAE8). Offset 0x37954 at base 80128158.
 * SHA256(span)=059014aa0ada01cf7d59c319eaaf5d040119910d7ccaa5b64800b422f5c1adad.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D64->D_80187654.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015FAAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015FAAC(s32 *a0) {

    extern void (*D_80187654[])(s32 *);
    D_80187654[*(u16 *)((s32)a0 + 0x2)](a0);
}
