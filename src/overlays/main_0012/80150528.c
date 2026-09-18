/* Overlay range [80150528,801505FC) from MAIN.CD member 0012.
 * SHA256(span)=ffcbf60abcad76d2e4ebb27f87f29a0b19b4b9f423f59193f08b58c72cee67a3.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80150528 - 53 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_801202A0[];
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);

s32 func_80150528(void *arg0, void *arg1, void *arg2)
{
    u8 *p = D_801202A0;
    /* Inline limit expression (NOT a cached `end` local): gcc hoists the
     * loop-invariant `D_801202A0 + 0x6480` into the preheader, landing it in a
     * callee-saved reg via a temp->saved copy (addu $s5,$v1,$zero) because it
     * is live across the jal. A cached `end` local instead keeps the limit in
     * one saved reg (52 ins, wrong regalloc). */
    if (p < D_801202A0 + 0x6480) {
        do {
            if (*(u16*)p != 0) {
                if ((*(u16*)(p + 0x5C) & 0x80) != 0) {
                    if (*(s32*)(p + 0x58) != 0) {
                        if (((s32 (*)(s32, s32, s32, s32))func_80135A4C)(
                                *(s32*)(p + 0x20), *(s32*)(p + 0x58),
                                (s32)arg1, (s32)arg2) != 0) {
                            *(s32*)((u8*)arg0 + 0x1A4) = (s32)p;
                            return 1;
                        }
                    }
                }
            }
            p += 0x10C;
        } while (p < D_801202A0 + 0x6480);
    }
    return 0;
}
