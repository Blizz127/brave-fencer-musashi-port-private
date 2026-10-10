/* SC02 resident retail span [801689D8,80168A14). Offset 0x40880 at base 80128158.
 * SHA256(span)=c193730bcd193a2471e649c43a16c786bd0c7b4f23c5e8b336004d93660cb1c8.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018137C->D_80187C6C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801689D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C6C[])(void *);

void func_801689D8(void *a0) {
    D_80187C6C[*(u16 *)((s32)a0 + 0x2)](a0);
}
