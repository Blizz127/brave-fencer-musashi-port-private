/* Overlay range [80166438,801665B4) from MAIN.CD member 0012.
 * SHA256(span)=63bdec445e71a25724399ecfb5c567df22bd158b1f4ad7311549163e63cad476.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80166438 - 95 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_800D387C[];
extern u8 D_800D3888[];
extern s32 func_800D21C4(s32 a0, void *a1, s32 a2);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_801665B4();
extern void func_80146C3C();

void func_80166438(u8 *a0) {
    u8 *s0;
    s32 v0;
    s32 v1;
    v0 = 0x9B;
    if ((*(s32 *)(a0 + 0x30) & 0x10000000) == 0) {
        v0 = 0x9C;
    }
    s0 = (u8 *)func_800D21C4((s32)a0, D_800D387C, v0);
    if (s0 == 0) goto tail;
    *(s32 *)(a0 + 0x20) = (s32)s0;
    {
        register s32 r asm("$2");
        r = *(s32 *)(a0 + 0x30) & 0x7FFF;
        *(u16 *)(s0 + 0x1A) = r;
        *(u16 *)(s0 + 0x18) = r;
    }
    if (*(s32 *)(a0 + 0x30) & 0x8000) {
        func_800D1FC8((s32)a0, 6);
    }
    v1 = *(s32 *)(a0 + 0x30);
    if (v1 < 0) {
        *(s32 *)(s0 + 4) = *(s32 *)(s0 + 4) | 0x50000000;
    } else {
        if (v1 & 0x8000000) {
            *(s32 *)(s0 + 4) = 0x60000000;
        }
    }
    if ((*(s32 *)(a0 + 0x30) & 0x40000000) == 0) {
        *(s32 *)(s0 + 4) = *(s32 *)(s0 + 4) | 0x40;
    } else {
        *(s32 *)(s0 + 4) = *(s32 *)(s0 + 4) & -0x41;
    }
    if (*(s32 *)(a0 + 0x30) & 0x20000000) {
        u32 h;
        *(s8 *)(s0 + 0x24) = ((u32)*(s32 *)(a0 + 0x2C) >> 20) & 0xF0;
        h = *(u16 *)(a0 + 0x2E);
        *(s8 *)(s0 + 0x25) = h & 0xF0;
        *(s8 *)(s0 + 0x26) = ((u32)*(s32 *)(a0 + 0x2C) >> 12) & 0xF0;
    }
    func_80128EA8((s32)s0, (s32)(a0 + 0x24), (s32)D_800D3888);
    {
        register s32 r asm("$2");
        r = *(u16 *)(a0 + 2) + 1;
        *(u16 *)(a0 + 0x16) = *(s32 *)(a0 + 0x2C);
        *(u16 *)(a0 + 2) = r;
    }
    func_801665B4((s32)a0);
    return;
tail:
    func_80146C3C((s32)a0);
}
