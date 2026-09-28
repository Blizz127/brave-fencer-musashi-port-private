/* SC02 resident retail span [80168D58,80168D94). Offset 0x40C00 at base 80128158.
 * SHA256(span)=6d909525d9095bf8b837993ce447400dbb4f18f31444c5b71a0c6f51d924a560.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018138C->D_80187C7C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168D58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C7C[])(void);

void func_80168D58(void *a0) {
    D_80187C7C[*(u16 *)((s32)a0 + 0x2)]();
}
