/* SC02 resident retail span [80170D68,80170DA4). Offset 0x48C10 at base 80128158.
 * SHA256(span)=173da5d77eee19b14195f74252de8644ba781d0a17b15d8a63d3fef785abac59.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818B0->D_801881A0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170D68 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881A0[])(void);

void func_80170D68(void *a0) {
    D_801881A0[*(u8 *)((s32)a0 + 0x216)]();
}
