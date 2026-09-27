/* Overlay range [80154ED8,80154F9C) from MAIN.CD member 0012.
 * SHA256(span)=4bc3ebb62861f3b53d9e7a98a90b78d7194bb4a1e044ced2126e634e8b27ccb4.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80154ED8 - 49 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s16 D_80078E96;
extern u8 D_800D8D10[];
extern s16 D_80078E9E;
extern u16 D_80078EA6;
extern void func_801550FC(s32 a0);

void func_80154ED8(s32 a0, s32 a1) {
    *(s32 *)(a0 + 0xC8) = a1;
    if (D_80078E96 & 0x8000) {
        *(s32 *)(a0 + 0xC8) = a1 | 0x1000000;
        func_801550FC((s32)D_800D8D10);
        return;
    }
    if (D_80078E9E >= 0x10) {
        if (*(s16 *)&D_80078EA6 >= 0x10) {
            goto and_path;
        }
    }
    if ((*(s32 *)(a0 + 0x44) & 0xC0) != 0) {
        goto and_path;
    }
    *(s32 *)(a0 + 0xC8) = a1 | 0x1000000;
    func_801550FC(0x40000002);
    return;
and_path:
    *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) & 0xC0FFFFFF;
    func_801550FC(a1);
}
