/* SC02 resident retail span [8016B9F8,8016BA48). Offset 0x438A0 at base 80128158.
 * SHA256(span)=9956e3a9812ad61867be8f27c9572f3c9b19c1b0deddc40860aece117de715ea.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801846B8->D_801B6870.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B9F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B6870;
extern void func_8012EFB8(s32 a0);
extern void func_80015954(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

s32 func_8016B9F8(s32 param_1)
{
    s32 buf[2];
    u32 v;

    v = ((u32 (*)(s32 *, s32 *))func_8012EFB8)(&D_801B6870, buf);
    ((void (*)(s32 *, s32 *))func_80015954)(buf, (s32 *)(param_1 + 4));
    return (v & 0xffffefff) != 0;
}
