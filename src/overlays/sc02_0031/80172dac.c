/* SC02 resident retail span [80172DAC,80172DE8). Offset 0x4AC54 at base 80128158.
 * SHA256(span)=b4a4507bc9052895ee1f1af6cb287bdbdd616c28c88110358b94156c3fe06812.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181940->D_80188230.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172DAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80172DAC(void *a0) {

    extern void (*D_80188230[])(void *);
    D_80188230[*(u8 *)((s32)a0 + 0x214)](a0);
}
