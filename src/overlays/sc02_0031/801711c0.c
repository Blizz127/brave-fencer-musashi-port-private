/* SC02 resident retail span [801711C0,801711FC). Offset 0x49068 at base 80128158.
 * SHA256(span)=208107331ee2b55f90379e4f3402fd8c69d45268f86ac321414d9969f127cacf.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818E0->D_801881D0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801711C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881D0[])(void);

void func_801711C0(void *a0) {
    D_801881D0[*(u8 *)((s32)a0 + 0x216)]();
}
