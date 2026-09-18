/* Overlay range [80163950,80163A58) from MAIN.CD member 0012.
 * SHA256(span)=5bf50b3adfff3d1ae737b428d8795cc7ad3b20231008a2832c17e23f7d0ebc8d.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80163950 - 66 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_801202A0[];
extern u8 D_80126720[];
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern void func_80015954(s32 a0, s32 a1);

s32 func_80163950(s32 a0) {
    s32 sp10[2];
    s32 sp18[2];
    u8 *p;
    func_80015978(a0 + 4, sp10);
    func_80015978(a0 + 4, sp18);
    *(s16 *)((s32)sp10 + 0x2) = *(u16 *)((s32)sp10 + 0x2) - 0x20;
    *(s16 *)((s32)sp18 + 0x2) = *(u16 *)((s32)sp18 + 0x2) + 0x8;
    for (p = D_801202A0; p < D_801202A0 + 0x6480; p += 0x10C) {
        if (*(u16 *)p == 0) continue;
        if ((*(u16 *)(p + 0x5C) & 0x400) == 0) continue;
        if (*(s32 *)(p + 0x58) == 0) continue;
        if (func_80135A4C(*(s32 *)(p + 0x20), *(s32 *)(p + 0x58), sp10, (s32)sp18) != 0) {
            func_80015954((s32)sp18, a0 + 4);
            return 1;
        }
    }
    return 0;
}
