/* Overlay range [8014B350,8014B4C4) from MAIN.CD member 0012.
 * SHA256(span)=b8aec7402cdbd79c92f3eac17899cda4b55cb7e86143ba4ef3b5f862c4ab6a58.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014B350 - 93 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_80078E78[];
extern s16 D_80078E96;
extern s32 D_80078E94;
extern u8 D_80062BF4[];
extern s32 func_8016F1C4(void);
extern void func_8014BC80(s32 a0, s32 a1);
extern void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3);
extern void func_80019064(void *a0);

void func_8014B350(s32 a0) {
    s32 s0 = a0;
    s32 s1 = (s32)&D_80078E78;
    s32 v0;
    s32 v1;
    u16 buf[4];
    if (func_8016F1C4() != 0) {
        return;
    }
    v1 = *(u16 *)(s0 + 0x0);
    if (v1 == 0x1E || v1 == 0x1A) {
        return;
    }
    if (D_80078E96 & 0x8000) {
        if (*(s32 *)(s0 + 0x44) & 0x80) {
            D_80078E94 = D_80078E94 + 0xAAA8;
        } else {
            D_80078E94 = D_80078E94 + 0x1555;
        }
        v0 = *(u16 *)(s1 + 0x1E) & 0x7FFF;
        if (v0 < 0x3D) {
        } else {
            *(s32 *)(s1 + 0x1C) = 0x80000000;
            func_8014BC80(s0, 8);
            buf[0] = *(u16 *)(s0 + 0x6);
            buf[1] = *(u16 *)(s0 + 0xA) - 0x20;
            buf[2] = *(u16 *)(s0 + 0xE);
            func_8014AD30(s0, buf, 6, 0);
            func_80019064(&D_80062BF4);
        }
    }
    if (*(s16 *)(s1 + 0x56) & 0x8000) {
        if (*(s32 *)(s0 + 0x44) & 0x80) {
            *(s32 *)(s1 + 0x54) = *(s32 *)(s1 + 0x54) + 0xAAA8;
        } else {
            *(s32 *)(s1 + 0x54) = *(s32 *)(s1 + 0x54) + 0x1555;
        }
        v0 = *(u16 *)(s1 + 0x56) & 0x7FFF;
        if (v0 < 0x3D) {
        } else {
            *(s32 *)(s1 + 0x54) = 0x80000000;
        }
    }
}
