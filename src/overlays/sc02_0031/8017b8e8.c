/* SC02 resident retail span [8017B8E8,8017B940). Offset 0x53790 at base 80128158.
 * SHA256(span)=c70271f0aefe57b9c25576a0702f058eb9c77fd21ddfc9478b4ac7f7fc9b3e01.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801853BC->D_801B7574; D_801853C4->D_801B757C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B8E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { unsigned char b[8]; } S8_8017B8E8;
extern s16 D_801B757C;
extern s16 D_801B7574;

s32 func_8017B8E8(s32 src) {
    (*(S8_8017B8E8 *)&D_801B757C) = ((S8_8017B8E8 *)src)[0];
    (*(S8_8017B8E8 *)&D_801B7574) = ((S8_8017B8E8 *)src)[1];
}
