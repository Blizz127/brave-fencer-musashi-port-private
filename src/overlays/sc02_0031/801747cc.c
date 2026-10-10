/* SC02 resident retail span [801747CC,80174808). Offset 0x4C674 at base 80128158.
 * SHA256(span)=02a8c0420ed13980a9d15608306a1a9f31188cf782afd448d638bd5c525f9913.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819E4->D_801882D4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801747CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801747CC(void *a0) {

    extern void (*D_801882D4[])(void *);
    D_801882D4[*(u8 *)((s32)a0 + 0x214)](a0);
}
