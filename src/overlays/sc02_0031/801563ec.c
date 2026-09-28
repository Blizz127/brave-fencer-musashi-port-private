/* SC02 resident retail span [801563EC,8015640C). Offset 0x2E294 at base 80128158.
 * SHA256(span)=f7ffa480f6af6728d00a75b07040784866462f426b17556d44d88ba9ea4454ad.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801803E4->D_80186CD4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801563EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 a, b, c; } S801563EC;
extern S801563EC D_80186CD4[];

S801563EC *func_801563EC(u16 idx) {
    return &D_80186CD4[idx];
}
