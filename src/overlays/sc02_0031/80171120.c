/* SC02 resident retail span [80171120,8017115C). Offset 0x48FC8 at base 80128158.
 * SHA256(span)=8881269f9ac98a6ba2f7a9dc6bc64af11965da4cca167e75c5984279d4dfc14e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818D8->D_801881C8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171120 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881C8[])(void *);

void func_80171120(void *a0) {
    D_801881C8[*(u8 *)((s32)a0 + 0x216)](a0);
}
