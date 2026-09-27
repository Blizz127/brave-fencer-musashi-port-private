/* Overlay range [801716AC,801717A0) from MAIN.CD member 0012.
 * SHA256(span)=d7f37a0484206841f3c7ac584e212077f144e6e73626c97e30f3f8a99be5b9d4.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801716AC - 61 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80012FC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;

s32 func_801716AC(s32 a0, void * a1, s32 * a2)
{
    s32 d;
    s32 p;
    a0 = a0 * 0x10;
    p = a0 + (s32)a1;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xC), (&D_800A5E94)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xC) = *(u8 *)(p + 0xC) + d;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xD), (&D_800A5E95)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xD) = *(u8 *)(p + 0xD) + d;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xE), (&D_800A5E96)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xE) = *(u8 *)(p + 0xE) + d;
}
