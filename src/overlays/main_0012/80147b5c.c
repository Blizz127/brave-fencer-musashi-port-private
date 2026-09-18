/* Overlay range [80147B5C,80147C30) from MAIN.CD member 0012.
 * SHA256(span)=0f6c41fa16716552d9a37b6282d157d9faff731657366a8a9d305c9bf1e20a92.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80147B5C - 53 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147B5C(s32 arg0, void *arg1) {
    if (*(s32 *)(arg0 + 0x44) & 0x400000) {
        D_80127090 = *(s32 *)(arg0 + 0x24);
    } else {
        D_80127090 = *(s32 *)arg1;
    }
    if (*(s32 *)(arg0 + 0x44) & 0x800000) {
        D_80127094 = *(s32 *)(arg0 + 0x28);
    } else {
        D_80127094 = *(s32 *)((u8 *)arg1 + 0x4);
    }
    if (*(s32 *)(arg0 + 0x44) & 0x1000000) {
        D_80127098 = *(s32 *)(arg0 + 0x2C);
    } else {
        D_80127098 = *(s32 *)((u8 *)arg1 + 0x8);
    }
    *(s32 *)(arg0 + 0x10) = D_80127090;
    *(s32 *)(arg0 + 0x14) = D_80127094;
    *(s32 *)(arg0 + 0x18) = D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
