/* Overlay range [801539F8,80153B58) from MAIN.CD member 0012.
 * SHA256(span)=8b5ec0fc8b06bb2c6bb8b8ac2470e056d7630c60514cbe9e450abe90e52b6db5.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801539F8 - 88 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void *memcpy(void *dst, const void *src, u32 n);

s32 func_801539F8(s32 a0, void * a1)
{
    u8 buf1[8];
    u8 buf2[8];
    u8 buf3[8];
    s32 r1, r2, r3;
    memcpy(buf1, (void *)(a0 + 0xA0), 8);
    memcpy(buf2, a1, 8);
    *(s16 *)(buf1 + 2) -= 4;
    r1 = func_80133784(0, buf1, buf2);
    if (r1 != 0x2000) {
        return 1;
    }
    memcpy((void *)buf1, (void *)(s32)buf2, 8);
    *(s16 *)(buf2 + 2) += 8;
    r2 = func_80133784(0, buf1, buf2);
    if (r2 != r1) {
        return 1;
    }
    r3 = func_80133784(2, buf2, buf3);
    if (r3 != r2) {
        return 1;
    }
    *(s16 *)(a0 + 0x88) = *(s16 *)(buf2 + 0);
    *(s16 *)(a0 + 0x8A) = *(s16 *)(buf2 + 2);
    *(s16 *)(a0 + 0x8C) = *(s16 *)(buf2 + 4);
    memcpy((void *)(a0 + 0x90), (void *)(a0 + 0x88), 8);
    return 0;
}
