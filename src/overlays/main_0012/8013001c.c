/* Overlay range [8013001C,80130088) from MAIN.CD member 0012.
 * SHA256(span)=b61ee6990ed95195de8478fa14af5f92fe95aa953aa8d1f206edf177a110443c.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013001C - 27 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);

void func_8013001C(void *a0) {
    s32 v0 = func_8012BCCC((s32)a0);
    if (v0 <= 0x8FFF) {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x30)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x31);
    } else {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x31)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x30);
    }
}
