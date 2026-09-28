/* SC02 resident retail span [8015CC74,8015CCB0). Offset 0x34B1C at base 80128158.
 * SHA256(span)=f52ac737d558e60b591d639f5d833ef9d59ac58ba67d322879e97695f5ab3467.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180BB8->D_801874A8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CC74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015CC74(s32 *a0) {

    extern void (*D_801874A8[])(void);
    D_801874A8[*(u16 *)((s32)a0 + 0x2)]();
}
