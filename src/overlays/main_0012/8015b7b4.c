/* Overlay range [8015B7B4,8015B858) from MAIN.CD member 0012.
 * SHA256(span)=abbde394e5a3048589168883bbd47d3b3c8cd1139af5b8ce9aa6825858262c17.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8015B7B4 - 41 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80149B54(s32 *a0);
extern void func_80156648(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 a0);
extern void func_80147300(u16 arg0);
extern u8 D_800D4F8C[];

s32 func_8015B7B4(s32 a0) {
    s32 s0 = a0;
    if (func_80149B54((s32 *)s0) != 0) {
        func_80156648((s32 *)s0);
        *(s8 *)(s0 + 0x1AA) = 0xC;
        *(s32 *)(s0 + 0x44) = *(s32 *)(s0 + 0x44) | 0x2;
        *(s32 *)(s0 + 0x23C) = *(s32 *)(s0 + 0xB4);
        *(s8 *)(s0 + 0x244) = *(u8 *)(s0 + 0xBC);
        func_80154274((s32 *)s0, (s32)D_800D4F8C);
        func_80154A74(s0, 0x22);
        *(s8 *)(s0 + 0xDA) = 0;
        func_80146994(5, s0, 5, 0);
        func_80147324(0x455);
        func_80147300(0x5F3);
        return 1;
    }
    return 0;
}
