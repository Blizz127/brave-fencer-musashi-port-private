/* Main-exec range [8003DC90,8003DF8C) from the SLUS executable.
 * SHA256(span)=6caa05a946ec7e7b44ec76e678ef3c125e1099cc7a2a0a9dcc3f62d6aee5b7fd.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"

/* func_8003DC90 - 191 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_800C73D8[];
extern void func_80040DE8(s16, u16, u16, s16);
extern s32 func_80041354(s16, u16 *, u16 *);

void func_8003DC90(s32 arg0, s32 arg1)
{
    register s32 zr __asm__("$0");
    u16 w;
    u16 h;
    s32 p;
    s32 n;
    s32 i;
    s32 j;
    s32 *q;
    s32 k;
    s32 t;
    s32 *base;

    i = arg0 + zr;
    j = arg1 + zr;
    t = arg0 << 16;
    base = D_800C73D8;
    q = &base[t >> 16];
    k = (s16)arg1 * 0xB0;
    p = *q + k;
    n = *(s32 *)(p + 0xA0) - 1;
    *(s32 *)(p + 0xA0) = n;
    if (n < 0) {
        *(s32 *)(k + *q + 0x98) &= ~0x10;
        goto tail;
    }
    if (*(s16 *)(p + 0x4C) > 0) {
        if (n % *(s16 *)(p + 0x4C) != 0) {
            goto tail;
        }
        *(s16 *)(p + 0x4A) -= 1;
        if (*(s16 *)(p + 0x4A) < 0) {
            goto reset;
        }
        func_80041354(arg0 | (arg1 << 8), &w, &h);
        if (w + 1 <= w + *(s16 *)(p + 0x4A)) {
            func_80040DE8(arg0 | (arg1 << 8), w + 1, h + 1, 1);
        }
    } else if (*(s16 *)(p + 0x4C) < 0) {
        *(s16 *)(p + 0x4A) += *(s16 *)(p + 0x4C);
        if (*(s16 *)(p + 0x4A) < 0) {
            goto reset;
        }
        func_80041354(arg0 | (arg1 << 8), &w, &h);
        if (w - *(s16 *)(p + 0x4C) >= 0x7F && h - *(s16 *)(p + 0x4C) >= 0x7F) {
            func_80040DE8(arg0 | (arg1 << 8), 0x7F, 0x7F, 1);
        }
        if ((*(s32 *)(p + 0x9C) - *(s32 *)(p + 0xA0)) * -*(s16 *)(p + 0x4C) < *(s16 *)(p + 0x48)) {
            func_80040DE8(i | (j << 8), w - *(s16 *)(p + 0x4C), h - *(s16 *)(p + 0x4C), 1);
        }
    } else {
        goto tail;
    }
    goto check;
reset:
    func_80040DE8(arg0 | (arg1 << 8), 0x7F, 0x7F, 1);
    *(s32 *)(k + *q + 0x98) &= ~0x10;
check:
    if (*(s32 *)(p + 0xA0) == 0 || *(s16 *)(p + 0x4A) == 0) {
        *(s32 *)(D_800C73D8[(s16)i] + (s16)j * 0xB0 + 0x98) &= ~0x10;
    }
tail:
    func_80041354(i | (j << 8), (u16 *)(p + 0x5C), (u16 *)(p + 0x5E));
}
