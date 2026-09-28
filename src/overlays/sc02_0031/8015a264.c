/* SC02 resident retail span [8015A264,8015A2A0). Offset 0x3210C at base 80128158.
 * SHA256(span)=8b69fc6d8a7d9950fc0bf8b205fb8d9617e3840474d7f615ee60c5df6bd4a7bf.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B6C->D_8018745C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015A264 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_8018745C[])(void);

void func_8015A264(void *a0) {
    D_8018745C[*(u16 *)((s32)a0 + 0x2)]();
}
