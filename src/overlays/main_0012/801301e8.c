/* Overlay range [801301E8,80130278) from MAIN.CD member 0012.
 * SHA256(span)=8d8a795d5f7332022b7aad0d9d574979d5e53d4033655184dae8ac3b8f386a18.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801301E8 - 36 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_8012BEE8(s32 a0);
extern void func_80130D48(s32 a0);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);

void func_801301E8(u8 *a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x2000) {
        if (*(u8 *)(a0 + 0xC3) != 0) {
            if (*(u16 *)(a0 + 0x72) & 0x4000) {
                func_80130D48((s32)a0);
                func_801319E0((s32)a0);
            }
        } else if (func_8012BEE8((s32)a0) != 0) {
            func_80130D48((s32)a0);
            func_801319E0((s32)a0);
        }
    }
    func_80131CA8((int)a0, 0x26);
}
