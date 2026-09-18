/* Overlay range [80146FC4,8014704C) from MAIN.CD member 0012.
 * SHA256(span)=1208dcc4ebc086ed5e41362066948abbd49685a7cdbb133cafc64dfc3ab4bbc8.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80146FC4 - 34 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_80126DB0[];
extern u16 D_80126DB6;
extern void func_80015954(s32 a0, s32 a1);
extern void *memcpy(void *dst, const void *src, u32 n);

void func_80146FC4(s32 a0) {
    s32 s1 = a0;
    s32 s0;
    if (*(s16 *)(s1 + 0xA) >= 0x401) {
        s0 = (s32)D_80126DB0;
        func_80015954(s0, s1 + 0x4);
        memcpy((void *)(s1 + 0x88), (void *)s0, 8);
        *(s16 *)(*(s32 *)(s1 + 0x20) + 0x12) = D_80126DB6;
    }
}
