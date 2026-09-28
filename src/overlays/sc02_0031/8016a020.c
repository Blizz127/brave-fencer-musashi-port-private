/* SC02 resident retail span [8016A020,8016A05C). Offset 0x41EC8 at base 80128158.
 * SHA256(span)=1c76286f846088cf432191f1a8ce5be87bacdfcd5d5e815fd2cdb4676ed94fd0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181498->D_80187D88.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A020 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187D88[])(void);

void func_8016A020(void *a0) {
    D_80187D88[*(u16 *)((s32)a0 + 0x2)]();
}
