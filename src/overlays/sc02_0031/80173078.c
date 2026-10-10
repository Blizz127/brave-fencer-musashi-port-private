/* SC02 resident retail span [80173078,801730B4). Offset 0x4AF20 at base 80128158.
 * SHA256(span)=7480b0cf4cc6a299d061da0ee0506a0d8d1103055e8859eb262c38dec68e5caa.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018194C->D_8018823C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173078 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80173078(void *a0) {

    extern void (*D_8018823C[])(void *);
    D_8018823C[*(u8 *)((s32)a0 + 0x214)](a0);
}
