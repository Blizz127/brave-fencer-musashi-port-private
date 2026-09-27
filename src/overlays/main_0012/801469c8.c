/* Overlay range [801469C8,80146A6C) from MAIN.CD member 0012.
 * SHA256(span)=c4836c177105a5204f60f31530f958e3537ff43bd3878b6156afe0abc41c4601.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801469C8 - 41 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 D_8011D030;

s32 func_801469C8(int a0, void *a1, int a2, int a3, u16 arg5, int arg6, int arg7, int arg8) {
    int count;
    int p;
    int end;
    count = 0;
    p = (int)&D_8011D030;
    end = p + 0xA50;
    if ((u32)p < (u32)end) {
        int key = a0 & 0xFFFF;
        do {
            if (*(u16 *)(p + 0x0) == key) {
                count++;
            }
            p += 0x58;
        } while ((u32)p < (u32)end);
    }
    if ((u32)count < (u32)arg8) {
        return func_80146A6C(a0 & 0xFFFF, a1, (s16)a2, (s16)a3, (s16)arg5, arg6, arg7);
    }
    return 0;
}
