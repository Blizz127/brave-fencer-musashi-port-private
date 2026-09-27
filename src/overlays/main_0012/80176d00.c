/* Overlay range [80176D00,80176D94) from MAIN.CD member 0012.
 * SHA256(span)=9015ab0c7745c43f81ecd199a658c4649e4331c82c44fd6e2e68a9ddf6adbf0c.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80176D00 - 37 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80178004();
extern u8 D_8011F7B1;
extern u8 D_8011F7A8;
extern u16 D_80078EA6;
extern u16 D_8011F7B4;
extern u16 D_8011F7B6;
extern s16 D_8011F81E;

void func_80176D00(s32 a0) {
    u8 *arr = (u8 *)&D_8011F7A8;
    u8 *base;
    s32 tmp;
    s32 a1v, a2v;
    if (D_8011F7B1 != 0) {
        return;
    }
    base = arr + (s16)a0 * 4;
    tmp = *(s32 *)(base + 0x20) + 0x14;
    *(s32 *)(base + 0x38) = tmp;
    a1v = (s16)(D_8011F7B4 - 0x17);
    a2v = (s16)(D_8011F7B6 + 0x65);
    D_8011F81E = D_80078EA6;
    *(s32 *)(base + 0x40) = func_80178004(tmp, a1v, a2v) - 0x14;
}
