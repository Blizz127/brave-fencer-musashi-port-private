/* SC02 resident retail span [801727D0,8017280C). Offset 0x4A678 at base 80128158.
 * SHA256(span)=d1528de183bdd994c67d21c412d97e242c6a82b24c9361b5adc36f6dd323dfe7.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181900->D_801881F0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801727D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801727D0(void *a0) {

    extern void (*D_801881F0[])(void *);
    D_801881F0[*(u8 *)((s32)a0 + 0x214)](a0);
}
