/* Overlay range [8014ADE0,8014B00C) from MAIN.CD member 0012.
 * SHA256(span)=7e1847b170e00610a7cf94118042dfe92b2c91d0bd523d766a536f9add7bf279.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014ADE0 - 139 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_80078E78[];
extern s32 func_8016F1C4(void);
extern s32 func_8014B154(s32 *a0);
extern void func_8014BD24(s32 a0, s32 a1);
extern void func_8014BB24(s32 a0, s32 a1, s32 a2);
extern void func_8014BC80(s32 a0, s32 a1);
extern void func_8014BD60(s32 a0, s32 a1);
extern void func_8014B084(void);
extern s32 func_80029178(s32 a0);

void func_8014ADE0(s32 a0)
{
    /* BLOCK-scope extern: the s32 view of the accumulator. The only file-scope decl of
     * this symbol in the TU is `extern s16 D_80078E90;` from DEFINE_func_8014B034(),
     * instantiated at line 1166 — AFTER our slot at 1162 — so gcc-2.7.2 emits only
     * "warning: type mismatch with previous external decl" (probe-verified, exit 0, no
     * -Werror in the build) instead of a hard `conflicting types` error. Unlike
     * `*(s32*)&D_80078E90`, this keeps the symbol_ref INSIDE the mem so each access folds
     * to `lui %hi / lw %lo`; taking the address instead materializes it and CSE hoists it
     * into a reg across all 4 uses (§18 &sym trap) — measured, it shifts ~100 insns. */
    extern s32 D_80078E90;
    register u8 *p __asm__("$17") = D_80078E78;
    s32 temp_s2;
    s32 var_a1;
    if (func_8016F1C4() != 0) {
        return;
    }
    if ((*(u16 *)a0 == 0x1A) || (*(u16 *)a0 == 0x1E) || (*(s32 *)(a0 + 0x44) & 0x10)) {
        return;
    }
    temp_s2 = D_80078E90;
    if (func_8014B154((s32 *)a0) != 0) {
        D_80078E90 = D_80078E90 + 0xAAA8;
    } else {
        D_80078E90 = D_80078E90 + 0x1555;
    }
    if ((*(s16 *)(p + 0x1A) - (temp_s2 >> 16)) > 0) {
        if (p[0x49] == 3) {
            func_8014BD24(a0, 1);
        }
    }
    if (((s16)(*(s16 *)(p + 0x1A) / 60) - (s16)((s16)(temp_s2 >> 16) / 60)) > 0) {
        if (func_8014B154((s32 *)a0) == 0) {
            var_a1 = 4;
        } else if (func_80029178(0x1B) & 0xFF) {
            var_a1 = 0xA;
        } else {
            var_a1 = 4;
        }
        if (*(u16 *)(p + 0x40) != 0) {
            func_8014BB24(a0, var_a1, 0);
        } else if (*(u16 *)(p + 0x3C) != 0) {
            if (*(u16 *)(p + 0x3C) >= 5U) {
                func_8014BC80(a0, 4);
            } else {
                *(u16 *)(p + 0x3C) = 1;
            }
        }
        if (func_8014B154((s32 *)a0) != 0) {
            if (func_80029178(0x1B) & 0xFF) {
                func_8014BD24(a0, 8);
            } else {
                func_8014BD60(a0, 1);
            }
        } else {
            func_8014BD60(a0, 4);
        }
    }
    if (*(s16 *)(p + 0x1A) >= 0x5A0) {
        *(s32 *)(p + 0x18) = 0;
        func_8014B084();
    }
}
