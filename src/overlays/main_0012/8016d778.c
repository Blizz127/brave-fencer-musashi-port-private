/* Overlay range [8016D778,8016D848) from MAIN.CD member 0012.
 * SHA256(span)=c289cf7ca1079d8a17d90f42f621edd95b483cda0353924f874d8f3e99e9dadf.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8016D778 - 52 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80146C3C();
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern s32 D_80126B9C;

void func_8016D778(s32 a0) {
    s32 s0 = a0;
    s32 p;
    s16 sp[6];
    if (*(s16 *)(s0 + 0x28) == *(s16 *)(*(s32 *)(s0 + 0x30) + 0x36)) {
        if ((D_80126B9C & 0x20) != 0) {
            goto main;
        }
    }
    ((void (*)(s32))func_80146C3C)(s0);
    return;
main:
    p = *(s32 *)(s0 + 0x20);
    *(u16 *)(p + 0x18) = *(u16 *)(p + 0x18) ^ 0x400;
    *(u16 *)(p + 0x1A) = *(u16 *)(p + 0x1A) ^ 0x200;
    sp[0] = *(u16 *)(s0 + 0x12);
    sp[1] = *(u16 *)(s0 + 0x16);
    sp[2] = *(u16 *)(s0 + 0x1A);
    func_800D20C0(&sp[0], &sp[4], 6);
    *(u16 *)(s0 + 6) = sp[0];
    *(u16 *)(s0 + 0xA) = sp[1];
    *(u16 *)(s0 + 0xE) = sp[2];
}
