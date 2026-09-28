/* SC02 resident retail span [801728E4,80172920). Offset 0x4A78C at base 80128158.
 * SHA256(span)=5d1196aa0f4e881c0b269ddcb06e97c6897cf081a84aa0465918c197f07da031.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018190C->D_801881FC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801728E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801728E4(void *a0) {

    extern void (*D_801881FC[])(void);
    D_801881FC[*(u8 *)((s32)a0 + 0x214)]();
}
