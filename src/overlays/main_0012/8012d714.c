/* Overlay range [8012D714,8012DB84) from MAIN.CD member 0012.
 * SHA256(span)=4afd559939797e059da0514fdad025f17680179212008d90ce390760178e021c.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012D714 - 284 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);

s32 func_8012D714(s32 param_1, u32 param_2) {
    u16 a[3];
    u16 b[3];
    u32 base;
    base = (*(u32 *)(param_1 + 0x58) & 0xFFFFFFF) | 0x80000000;
    if (param_2 & 1) {
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 8);
        b[2] = *(u16 *)(base + 0xC);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 0xA);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xC);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xE);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 8);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 0xA);
        a[2] = *(u16 *)(base + 0xE);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
    }
    if (param_2 & 2) {
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 4);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xC);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xE);
        b[0] = *(u16 *)(base + 4);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 6);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xC);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 6);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xE);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
    }
    if (param_2 & 4) {
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 4);
        b[1] = *(u16 *)(base + 8);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 4);
        a[1] = *(u16 *)(base + 0xA);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 4);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 6);
        a[1] = *(u16 *)(base + 8);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 8);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
        a[0] = *(u16 *)(base + 6);
        a[1] = *(u16 *)(base + 0xA);
        a[2] = *(u16 *)(base + 0xC);
        b[0] = *(u16 *)(base + 6);
        b[1] = *(u16 *)(base + 0xA);
        b[2] = *(u16 *)(base + 0xE);
        if (((s32 (*)(s32, void *, void *))func_8012DEB8)(param_1, a, b) != 0) {
            return 1;
        }
    }
    return 0;
}
