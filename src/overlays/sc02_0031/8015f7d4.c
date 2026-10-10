/* SC02 resident retail span [8015F7D4,8015F810). Offset 0x3767C at base 80128158.
 * SHA256(span)=a1ac935eb0cc1fb31cf9503568a449829b3b47868c0f1e733a8aba01bc5ad36c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D58->D_80187648.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F7D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8015F7D4(s32 a0) {

    extern void (*D_80187648[])(s32);
    D_80187648[*(u16 *)((s32)a0 + 0x2)](a0);
}
