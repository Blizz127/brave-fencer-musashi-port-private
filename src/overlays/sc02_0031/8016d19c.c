/* SC02 resident retail span [8016D19C,8016D1D8). Offset 0x45044 at base 80128158.
 * SHA256(span)=21a97d5447485e4cd584c2dd50f34e9f067c42fdcd71f55b0cd037782344f042.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018160C->D_80187EFC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D19C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187EFC[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016D19C(void *a0) {
    D_80187EFC[*(u16 *)((s32)a0 + 0x2)]();
}
