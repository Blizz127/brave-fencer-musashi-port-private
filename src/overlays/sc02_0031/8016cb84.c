/* SC02 resident retail span [8016CB84,8016CBC0). Offset 0x44A2C at base 80128158.
 * SHA256(span)=d6791d9e00608f284d8e92342932efbdf33b9a24522d7b4d2985f4ca3f3795eb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801815F0->D_80187EE0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016CB84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187EE0[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016CB84(void *a0) {
    D_80187EE0[*(u16 *)((s32)a0 + 0x2)]();
}
