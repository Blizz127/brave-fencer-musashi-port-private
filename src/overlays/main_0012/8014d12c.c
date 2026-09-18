/* Overlay range [8014D12C,8014D2A0) from MAIN.CD member 0012.
 * SHA256(span)=26534d183f8d6ab363765cbee1b715d9dffacd30a59b7808532ebf6172493e58.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014D12C - 93 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_8014C918(s32 a0, s32 a1);

s32 func_8014D12C(s32 arg0, void *a1, void *a2)
{
    u16 *arg1 = (u16 *)a1;
    u16 *arg2 = (u16 *)a2;
    s32 e;
    arg1[1] -= 3;
    arg2[1] += 8;
    e = *(s32 *)(arg0 + 0x174);
    if ((*(u16 *)e == 0) || ((*(u16 *)(e + 0x5C) & 0x400) == 0) || (*(s32 *)(e + 0x58) == 0) ||
        (*(s16 *)(e + 0xA) < *(s16 *)(arg0 + 0xA))) {
        if (*(u16 *)e != 0) {
            *(u8 *)(e + 0x74) = 0;
        }
        *(s32 *)(arg0 + 0x174) = 0;
        return 0;
    }
    arg1[0] = *(u16 *)(arg0 + 0x98);
    arg1[1] = *(u16 *)(arg0 + 0x9A) - 3;
    arg1[2] = *(u16 *)(arg0 + 0x9C);
    if ((*(u16 *)(e + 0x5C) & 8) != 0) {
        arg2[1] = arg1[1] + 0x18;
    }
    if (func_80135A4C(*(s32 *)(e + 0x20), *(s32 *)(e + 0x58), (s32 *)arg1, (s32)arg2) != 0) {
        *(u16 *)(arg0 + 6) = arg2[0];
        *(u16 *)(arg0 + 0xA) = arg2[1];
        *(u16 *)(arg0 + 0xE) = arg2[2];
        *(u16 *)(arg0 + 0x16E) = func_8014C918(arg0, *(u8 *)(e + 0x75)) & 0xFF;
        return 1;
    }
    *(u8 *)(e + 0x74) = 0;
    *(s32 *)(arg0 + 0x174) = 0;
    return 0;
}
