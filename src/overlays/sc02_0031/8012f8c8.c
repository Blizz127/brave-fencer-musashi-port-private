/* SC02 resident retail span [8012F8C8,8012F91C). Offset 0x7770 at base 80128158.
 * SHA256(span)=23b035b8c5b9814bfa3e34acd228edfd76e3ca5443a4ce3d957e85dcac21977e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E6FC->D_80184FEC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F8C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131170(s32 a0, s32 a1, s32 a2);
extern void func_80131CA8(int a0, int a1);
extern u8 D_80184FEC[];

void func_8012F8C8(u8* arg0) {
    *(u8*)(arg0 + 0xC1) = 7;
    if (*(u32*)(arg0 + 0xB4) & 0x80) {
        ((void (*)(void*, void*, s32))func_80131170)(arg0, D_80184FEC, 0xB);
    }
    ((void (*)(void*, s32))func_80131CA8)(arg0, 0x16);
}
