/* Overlay range [80164ACC,80164BA0) from MAIN.CD member 0012.
 * SHA256(span)=5209c8dcca8b37c7c38baffa57ab4d0084c8bbe54cb5703716248c13d1ae5e0a.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80164ACC - 53 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_801202A0[];
extern u8 D_80126720[];
extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8014C3A4(void *a0, s32 a1, s32 a2, s32 a3);

void func_80164ACC(s32 a0) {
    u8 *p;
    s16 buf[4];
    p = D_801202A0;
    if (p < p + 0x6480) {
        do {
            if (func_8014C308(a0, (s32)p, 0xB, 2) != 0) {
                if (func_8014C278(a0, (s32)p, 0x50) != 0) {
                    func_80015978((s32)(p + 4), (s32 *)buf);
                    buf[3] = 0;
                    func_8014C3A4((void *)a0, (s32)p, 0xB, (s32)buf);
                    *(s16 *)(p + 0x60) = (s16)(*(s16 *)(p + 0x60)) / 2;
                }
            }
            p += 0x10C;
        } while (p < D_80126720);
    }
}
