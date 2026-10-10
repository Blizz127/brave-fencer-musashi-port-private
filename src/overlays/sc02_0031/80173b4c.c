/* SC02 resident retail span [80173B4C,80173B88). Offset 0x4B9F4 at base 80128158.
 * SHA256(span)=40c9d44741621cc9da988bcb91027ae7abd047c6032f433724d6dd6cc6953e89.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819A0->D_80188290.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173B4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188290[])(void *);

void func_80173B4C(void *a0) {
    D_80188290[*(u8 *)((s32)a0 + 0x214)](a0);
}
