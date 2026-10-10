/* SC02 resident retail span [80159698,801596D4). Offset 0x31540 at base 80128158.
 * SHA256(span)=b93072b120c363dbb2881c301748a32c3f3b64dcbac5c678f2acb05406a9968f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018096C->D_8018725C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159698 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_8018725C[])(void *);

void func_80159698(void *a0) {
    D_8018725C[*(u8 *)((s32)a0 + 0x15)](a0);
}
