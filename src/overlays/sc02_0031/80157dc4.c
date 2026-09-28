/* SC02 resident retail span [80157DC4,80157E00). Offset 0x2FC6C at base 80128158.
 * SHA256(span)=5d22bf7d74aa91819a4e0aca923fd9c781a860dd5ee47a4a072fe09b1823fa44.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801806CC->D_80186FBC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157DC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186FBC[])(void);

void func_80157DC4(void *a0) {
    D_80186FBC[*(u16 *)((s32)a0 + 0x2)]();
}
