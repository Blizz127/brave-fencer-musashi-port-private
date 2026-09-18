/* Overlay range [80158E24,80158F00) from MAIN.CD member 0012.
 * SHA256(span)=fd56b88d4db935edbb47cb680fbeb93345a617e8761de8c992116ee0ee5dc11f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80158E24 - 55 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u16 func_801487F4(s32 *a0);
extern s32 func_80159434(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern M2C_UNK D_800D5904;

void func_80158E24(s32 *a0) {
    s32 n;
    s32 c;
    c = 0x4C000;
    n = 1;
    if (func_801487F4(a0) & 0xF0) {
        n = 4;
    }
    while (n > 0) {
        func_80159434((s32)a0, c);
        if (*(s16 *)(a0[0x20 / 4] + 0x10) < 0xC00) {
            *(s16 *)(a0[0x20 / 4] + 0x10) = 0xC00;
            func_80154274(a0, (s32)&D_800D5904);
            func_80154A74((s32)a0, 0x20);
            func_8002D4C8(0x2A, 0);
            func_8002D4C8(0x1C, 0);
            func_80146CA0(a0);
            n = 0;
        }
        n--;
    }
}
