/* SC02 resident retail span [801678B4,801678F0). Offset 0x3F75C at base 80128158.
 * SHA256(span)=985cb340bb0f64bf71a0666c8eaaf234dd3ab7d1fd86042b9579cc6fec48b34f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181350->D_80187C40.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801678B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C40[])(void);

void func_801678B4(void *a0) {
    D_80187C40[*(u16 *)((s32)a0 + 0x2)]();
}
