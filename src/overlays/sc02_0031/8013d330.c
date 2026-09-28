/* SC02 resident retail span [8013D330,8013D3D4). Offset 0x151D8 at base 80128158.
 * SHA256(span)=d1a7bc2d0c36f1fa1d8c972c1ffe202ff956f43a3cb79e97f686a82a325c33d5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * retargeted for this member: D_801A5778->D_801B79A0; D_801A5799->D_801B79C1; D_801A579A->D_801B79C2; D_801A5854->D_801B7A7C; D_801A5858->D_801B7A80; D_801A5872->D_801B7A9A; D_801A58E6->D_801B7B0E.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801B7A9A;
extern u8 D_801B7B0E;
extern u8 D_801B79C2;
extern u8 D_801B7A7C;
extern u8 D_801B79A0;
extern u8 D_801B79C1;
extern s32 D_801B7A80;

void func_8013D330(void) {
    if ((D_801B7A9A & 0xff) != D_801B7B0E) {
        D_801B7A9A = ((D_801B7A9A & 0xff) < D_801B7B0E) ? (D_801B7A9A + 1) : (D_801B7A9A - 1);
    }
    if ((D_801B79C2 & 0xff) != D_801B7A7C) {
        D_801B79C2 = ((D_801B79C2 & 0xff) < D_801B7A7C) ? (D_801B79C2 + 1) : (D_801B79C2 - 1);
    }
    if ((D_801B79A0 & 0xff) != D_801B79C1) {
        D_801B79A0 = ((D_801B79A0 & 0xff) < D_801B79C1) ? (D_801B79A0 + 1) : (D_801B79A0 - 1);
    }
    D_801B7A80 = 1;
}
