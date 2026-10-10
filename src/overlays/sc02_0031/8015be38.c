/* SC02 resident retail span [8015BE38,8015BE74). Offset 0x33CE0 at base 80128158.
 * SHA256(span)=4a2df4d8a1282877c8f8151f0c8b219d6a2024975c21c7c3d2d4727e2a22cec4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B90->D_80187480.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BE38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char pad[0x12]; s16 field_0x12; } Obj;

void func_8015BE38(struct Obj *a0) {

    extern void (*D_80187480[])(struct Obj *);
    D_80187480[*(u16 *)((s32)a0 + 0x2)](a0);
}
