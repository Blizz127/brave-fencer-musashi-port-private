/* SC02 resident retail span [801425CC,80142608). Offset 0x1A474 at base 80128158.
 * SHA256(span)=5e93bac7069eedd08b78192bfbaa2594134d58a3df5ef36511bab1f3eca2b087.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F7B4->D_801860A4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801425CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_801860A4[])(void);

void func_801425CC(void *a0) {
    D_801860A4[*(u16 *)((s32)a0 + 0x2)]();
}
