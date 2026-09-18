/* Main-exec range [8003DF8C,8003E248) from the SLUS executable.
 * SHA256(span)=fd52910c8df993e8d4073a1112e44d31fbcb7accc0cdeb7e68065a53ce9b18aa.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"

/* func_8003DF8C - 175 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_800C73D8[];
extern void func_80040DE8(s16, u16, u16, s16);
extern s32 func_80041354(s16, u16 *, u16 *);

void func_8003DF8C(s32 arg0, s32 arg1)
{
    register s32 zr __asm__("$0");
    u16 w;
    u16 h;
    s32 p;
    s32 n;
    s32 i;
    s32 j;

    i = arg0 + zr;
    j = arg1 + zr;
    p = D_800C73D8[(s16)arg0] + (s16)arg1 * 0xB0;
    n = *(s32 *)(p + 0xA0) - 1;
    *(s32 *)(p + 0xA0) = n;
    if (n < 0) {
        *(s32 *)((s16)arg1 * 0xB0 + D_800C73D8[(s16)arg0] + 0x98) &= ~0x20;
        goto tail;
    }
    if (*(s16 *)(p + 0x4C) > 0) {
        if (n % *(s16 *)(p + 0x4C) != 0) {
            goto tail;
        }
        *(s16 *)(p + 0x4A) -= 1;
        if (*(s16 *)(p + 0x4A) > 0) {
            func_80041354(arg0 | (arg1 << 8), &w, &h);
            if (w - *(s16 *)(p + 0x4A) > 0 && h - *(s16 *)(p + 0x4A) > 0 && w != 1) {
                func_80040DE8(arg0 | (arg1 << 8), w - 1, h - 1, 1);
            } else {
                func_80040DE8(i | (j << 8), 1, 1, 1);
            }
        } else {
            *(s32 *)((s16)arg1 * 0xB0 + D_800C73D8[(s16)arg0] + 0x98) &= ~0x20;
        }
    } else {
        *(s16 *)(p + 0x4A) += *(s16 *)(p + 0x4C);
        if (*(s16 *)(p + 0x4A) > 0) {
            func_80041354(arg0 | (arg1 << 8), &w, &h);
            if (*(s16 *)(p + 0x48) >= (*(s32 *)(p + 0x9C) - *(s32 *)(p + 0xA0)) * -*(s16 *)(p + 0x4C)
                && -*(s16 *)(p + 0x4C) < w) {
                func_80040DE8(arg0 | (arg1 << 8), w + *(s16 *)(p + 0x4C), h + *(s16 *)(p + 0x4C), 1);
            } else {
                func_80040DE8(i | (j << 8), 1, 1, 1);
            }
        } else {
            *(s32 *)((s16)arg1 * 0xB0 + D_800C73D8[(s16)arg0] + 0x98) &= ~0x20;
        }
    }
    if (*(s32 *)(p + 0xA0) == 0 || *(s16 *)(p + 0x4A) == 0) {
        *(s32 *)(D_800C73D8[(s16)i] + (s16)j * 0xB0 + 0x98) &= ~0x20;
    }
tail:
    func_80041354(i | (j << 8), (u16 *)(p + 0x5C), (u16 *)(p + 0x5E));
}
