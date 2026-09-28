/* SC02 resident retail span [80171260,8017129C). Offset 0x49108 at base 80128158.
 * SHA256(span)=2f0c752514b3ed30a530c6deedbf13e90713c0a3626b4d00f3f7aa8d678bb26d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818E8->D_801881D8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171260 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881D8[])(void);

void func_80171260(void *a0) {
    D_801881D8[*(u8 *)((s32)a0 + 0x216)]();
}
