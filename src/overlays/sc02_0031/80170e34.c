/* SC02 resident retail span [80170E34,80170E70). Offset 0x48CDC at base 80128158.
 * SHA256(span)=b2ebe9bfe1e672b313f6bb511cf7bb023670b5d3b4b9e947aab2974688efe57c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818B8->D_801881A8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170E34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881A8[])(void);

void func_80170E34(void *a0) {
    D_801881A8[*(u8 *)((s32)a0 + 0x216)]();
}
