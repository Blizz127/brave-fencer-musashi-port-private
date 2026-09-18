/* Overlay range [8014B944,8014BB0C) from MAIN.CD member 0012.
 * SHA256(span)=52641c4e5ddf6da66af09b88dd47eb697b9b96f1029adaeafa1fb3c7226566e3.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014B944 - 114 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80029178(s32 arg);
extern u8 D_80078E78[];
extern s32 D_80078EA4;
extern u16 D_80078EA6;

void func_8014B944(s32 a0, s32 a1, s32 a2)
{
    u8 *base = D_80078E78;
    if (a2 != 0) {
        D_80078EA4 += a1;
        __asm__ __volatile__("" ::: "memory");
        if ((s16)D_80078EA6 >= 0xA1) {
            D_80078EA4 = 0xA00000;
        }
    } else {
        if ((func_80029178(0x1B) & 0xFF) != 0) {
            D_80078EA4 += a1;
            __asm__ __volatile__("" ::: "memory");
            if ((s16)D_80078EA6 >= 0xA1) {
                D_80078EA4 = 0xA00000;
            }
        } else {
            if ((s16)D_80078EA6 < 0x80) {
                D_80078EA4 += a1;
                __asm__ __volatile__("" ::: "memory");
                if ((s16)D_80078EA6 >= 0x81) {
                    D_80078EA4 = 0x800000;
                }
            }
        }
    }
    if (a2 != 0) {
        *(s32 *)(base + 0x60) += a1;
        if (*(s16 *)(base + 0x62) >= 0xA1) {
            *(s32 *)(base + 0x60) = 0xA00000;
        }
    } else {
        if ((func_80029178(0x1B) & 0xFF) != 0) {
            *(s32 *)(base + 0x60) += a1;
            if (*(s16 *)(base + 0x62) >= 0xA1) {
                *(s32 *)(base + 0x60) = 0xA00000;
            }
        } else {
            if (*(s16 *)(base + 0x62) < 0x80) {
                *(s32 *)(base + 0x60) += a1;
                if (*(s16 *)(base + 0x62) >= 0x81) {
                    *(s32 *)(base + 0x60) = 0x800000;
                }
            }
        }
    }
}
