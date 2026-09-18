/* Overlay range [8014BB24,8014BC0C) from MAIN.CD member 0012.
 * SHA256(span)=c5897073bde480e56521f69047990755701e63e5f452e11269e830f0a0724f5d.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014BB24 - 58 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80029178(s32 a0);
extern u8 D_80078E78[];
extern s16 D_80078EB4;

void func_8014BB24(s32 a0, s32 a1, s32 a2)
{
    u8 *base = D_80078E78;
    u16 cur;
    if (a2 != 0) {
        D_80078EB4 = (u16)D_80078EB4 + a1;
    } else {
        if ((func_80029178(0x1B) & 0xFF) != 0) {
            cur = D_80078EB4;
            if (cur < 0x3E7) {
                D_80078EB4 = cur + a1;
                if ((u16)(cur + a1) >= 0x3E8) {
                    D_80078EB4 = 0x3E7;
                }
            }
        } else {
            cur = D_80078EB4;
            if (cur < 0x1F4) {
                D_80078EB4 = cur + a1;
                if ((u16)(cur + a1) >= 0x1F5) {
                    D_80078EB4 = 0x1F4;
                }
            }
        }
    }
    if (*(u16 *)(base + 0x3A) < *(u16 *)(base + 0x3C)) {
        *(u16 *)(base + 0x3C) = *(u16 *)(base + 0x3A);
    }
}
