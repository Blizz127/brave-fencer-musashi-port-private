/* SC02 resident retail span [80174888,801748C4). Offset 0x4C730 at base 80128158.
 * SHA256(span)=1ae62550dca5de8055182e101ab2c16c66aed927b4b4fb6f6390ec9bae1f31a0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819EC->D_801882DC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174888 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80174888(void *a0) {

    extern void (*D_801882DC[])(void);
    D_801882DC[*(u8 *)((s32)a0 + 0x214)]();
}
