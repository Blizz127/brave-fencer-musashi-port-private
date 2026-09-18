/* Overlay range [8014AA28,8014AB5C) from MAIN.CD member 0012.
 * SHA256(span)=d967c4d44570c995b032868cb32e6cb862f1916fb7873f4d683f9c7c9285c479.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014AA28 - 77 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_80126B58;
extern u8 D_80078EC1;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80165A20(s32 a0);
extern void func_8014AB7C();
extern void func_8014AC10();

void func_8014AA28(void) {
    s32 base = (s32)&D_80126B58;
    u16 v1 = *(u16 *)base;
    s32 s0 = D_80078EC1;
    if ((u32)(v1 - 0x19) >= 2 && (u32)(v1 - 0x1D) >= 2) {
        func_801599A4((void *)base);
        func_80159B3C((void *)base);
        if (s0 == 0xC || s0 == 0x18 || s0 == 0xA) {
            func_80165A20(base);
        }
    }
    *(s16 *)(base + 0x1C8) = 0;
    *(s16 *)(base + 0x1CA) = 0;
    *(s16 *)(base + 0x1CC) = 0;
    *(s16 *)(base + 0x1CE) = 0;
    *(s16 *)(base + 0x1D0) = 0;
    *(s32 *)(base + 0x1D4) = 0;
    *(s32 *)(base + 0x1D8) = 0;
    func_8014AB7C(5);
    func_8014AB7C(6);
    func_8014AB7C(7);
    func_8014AB7C(8);
    func_8014AB7C(9);
    func_8014AC10(0x26);
    func_8014AC10(0x27);
    func_8014AC10(0x39);
    func_8014AC10(0x3A);
    func_8014AB7C(0x10);
    func_8014AB7C(0x11);
    func_8014AB7C(0x12);
    func_8014AB7C(0x13);
    func_8014AB7C(0x14);
    func_8014AC10(0x3B);
    func_8014AC10(0x3C);
    *(u8 *)(base + 0x223) = 0x10;
}
