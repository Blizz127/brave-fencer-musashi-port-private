/* Overlay range [801300F4,801301E8) from MAIN.CD member 0012.
 * SHA256(span)=8523ac67fe53bf90d67f317108684e1816607adda3afbb95dc9466913bf3f999.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801300F4 - 61 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80131A34(s32, s32);
extern s32 func_8012BCCC(s32);
extern s32 func_80131AC8(void *a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_801300F4(s32 a0) {
    s32 done = 0;
    s32 r;
    *(u8 *)(a0 + 0xC1) = 0xD;
    if ((*(u32 *)(a0 + 0xB4) & 0x2000) != 0) {
        *(u16 *)(a0 + 0x5C) = 0;
        *(s32 *)(a0 + 0x1C) = 0x1E;
        *(u16 *)(a0 + 0x98) = 0;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
        r = func_80131A34(a0, 0x27);
        if (r != 0) {
            *(u8 *)(a0 + 0xC3) = 1;
        } else {
            *(u8 *)(a0 + 0xC3) = 0;
        }
        r = func_8012BCCC(a0);
        if (r < 0x9000) {
            r = ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x30);
            done = 1;
            if (r != 0) goto skip;
            ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x31);
        } else {
            r = ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x31);
            done = 1;
            if (r != 0) goto skip;
            ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x30);
        }
        done = 1;
    }
skip:
    r = ((s32 (*)(s32, s32))func_80131CA8)(a0, 0x25);
    if (r != 0) {
        done = 1;
    }
    if (!done) {
        ((void (*)(s32, s32))func_80131E00)(a0, 6);
    }
}
