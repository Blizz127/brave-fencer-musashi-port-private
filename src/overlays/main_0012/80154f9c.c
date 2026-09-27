/* Overlay range [80154F9C,801550FC) from MAIN.CD member 0012.
 * SHA256(span)=7edb80a446de4725cb4ed27ae63a05f67fd518039e25f4daf1286646ebc00846.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80154F9C - 88 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_80078E78[];
extern s16 D_80078E96;
extern s16 D_80078E9E;
extern u16 D_80078EA6;
extern u8 D_800D8D10[];
extern s32 func_8016F1AC(void);
extern void func_801550FC(s32 a0);

void func_80154F9C(s32 a0) {
    u8 *base = D_80078E78;
    if (*(s32 *)(a0 + 0xC8) & 0x1000000) {
        if ((D_80078E96 & 0x8000) || D_80078E9E < 0x10 || (s16)D_80078EA6 < 0x10) {
            if (func_8016F1AC() == 0) {
                return;
            }
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) & 0xC0FFFFFF;
        func_801550FC(*(s32 *)(a0 + 0xC8));
    } else {
        if ((D_80078E96 & 0x8000) && func_8016F1AC() == 0) {
            *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
            func_801550FC((s32)D_800D8D10);
            return;
        }
        if (!(*(s16 *)(base + 0x26) < 0x10) && !(*(s16 *)(base + 0x2E) < 0x10)) {
            return;
        }
        if (*(s32 *)(a0 + 0x44) & 0xC0) {
            return;
        }
        if (func_8016F1AC() != 0) {
            return;
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
        func_801550FC(0x40000002);
    }
}
