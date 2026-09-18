/* Overlay range [8014E98C,8014EA4C) from MAIN.CD member 0012.
 * SHA256(span)=10ad443f7a69d34cde9ecb18bf85d103d1caa6505aed446be46e954dbf94d5e0.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014E98C - 48 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_8014EA4C(void *a0, void *a1, void *a2, s32 a3);

s32 func_8014E98C(void *a0) {
    s16 buf1[3];
    s16 buf2[4];
    s32 acc;
    s32 i;
    acc = 0;
    i = 2;
    if ((*(s32 *)((u8 *)a0 + 0x44) & 0x80000) == 0) {
        if ((*(s32 *)((u8 *)a0 + 0x1F8) & 0x4000000) == 0) {
            do {
                buf1[0] = *(u16 *)((u8 *)a0 + 0x88);
                i -= 1;
                buf1[1] = *(u16 *)((u8 *)a0 + 0x8A) - 0x10;
                buf1[2] = *(u16 *)((u8 *)a0 + 0x8C);
                buf2[0] = *(u16 *)((u8 *)a0 + 0x6);
                buf2[1] = *(u16 *)((u8 *)a0 + 0xA) - 0x10;
                buf2[2] = *(u16 *)((u8 *)a0 + 0xE);
                acc = acc | func_8014EA4C(a0, buf1, buf2, i);
            } while (i != 0);
        }
    }
    return acc;
}
