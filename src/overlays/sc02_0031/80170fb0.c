/* SC02 resident retail span [80170FB0,80170FEC). Offset 0x48E58 at base 80128158.
 * SHA256(span)=745bf4fb51f5d4d5f16624bbfa54f17ec19d97c24d2919091e856f8c871e2839.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818C8->D_801881B8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170FB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881B8[])(void);

void func_80170FB0(void *a0) {
    D_801881B8[*(u8 *)((s32)a0 + 0x216)]();
}
