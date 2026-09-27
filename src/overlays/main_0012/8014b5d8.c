/* Overlay range [8014B5D8,8014B6F0) from MAIN.CD member 0012.
 * SHA256(span)=89f6bbaae7e07b248c0ae0fffe56c216c3c47107d339882a8bf392f04e096554.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014B5D8 - 70 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_8016F1C4(void);
extern s32 func_80029178(s32 a0);
extern void func_8014BC80(s32 a0, s32 a1);
extern u8 D_80078E78[];

void func_8014B5D8(s32 s1) {
    s32 *s0 = (s32 *)D_80078E78;
    s32 v0;
    s32 a0;
    v0 = func_8016F1C4();
    if (v0) {
        return;
    }
    if (*(u16 *)(s1 + 0x0) == 0x1E) {
        return;
    }
    if (*(u16 *)(s1 + 0x0) == 0x1A) {
        return;
    }
    if (*(s32 *)(s1 + 0x44) & 0x10) {
        return;
    }
    if (*(s32 *)(s1 + 0x44) & 0x80) {
        if ((func_80029178(0x1B) & 0xFF) != 0) {
            a0 = 0x2D8;
        } else {
            a0 = 0x5B0;
        }
    } else {
        a0 = 0x16C;
    }
    if (*(u8 *)((s32)s0 + 0x49) == 0x12) {
        a0 = a0 << 1;
    }
    v0 = *(s32 *)((s32)s0 + 0x24) - a0;
    *(s32 *)((s32)s0 + 0x24) = v0;
    if (v0 < 0) {
        *(s32 *)((s32)s0 + 0x24) = 0;
        if (*(s32 *)(s1 + 0x44) & 0x80) {
            *(s32 *)((s32)s0 + 0x28) = *(s32 *)((s32)s0 + 0x28) + 0xAAA8;
        } else {
            *(s32 *)((s32)s0 + 0x28) = *(s32 *)((s32)s0 + 0x28) + 0x1555;
        }
        if (*(s16 *)((s32)s0 + 0x2A) < 0x3C) {
            return;
        }
        *(s32 *)((s32)s0 + 0x28) = 0;
        func_8014BC80(s1, 0x4);
    } else {
        *(s32 *)((s32)s0 + 0x28) = 0;
        *(s8 *)((s32)s0 + 0x43) = 0;
    }
}
