/* Overlay range [80128DB4,80128EA8) from MAIN.CD member 0012.
 * SHA256(span)=2c87cf9648b559c0d31b06506e6fabdff950fbd802fbc4e717c03d3930462a1f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80128DB4 - 61 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80018450(s32 a0, s32 a1);
extern void func_800183E0(s32 a0);

s32 func_80128DB4(s32 a0, s32 *a1) {
    s32 base = a1[0];
    s16 cnt = *(s16 *)((u8 *)a1 + 6);
    if (cnt == 0) {
        return 1;
    }
    cnt = cnt - 1;
    *(s16 *)((u8 *)a1 + 6) = cnt;
    if (cnt > 0) {
        return 0;
    }
    {
        s16 idx = *(s16 *)((u8 *)a1 + 4);
        u32 flags = *(u32 *)(base + idx * 8 + 4);
        if ((flags & 0xC0) == 0xC0) {
            *(s16 *)((u8 *)a1 + 6) = 0;
            return 1;
        }
        if ((flags & 0x80) != 0) {
            *(s16 *)((u8 *)a1 + 4) = 0;
        } else {
            *(s16 *)((u8 *)a1 + 4) = idx + 1;
        }
        *(s16 *)((u8 *)a1 + 6) =
            *(u32 *)(base + *(s16 *)((u8 *)a1 + 4) * 8 + 4) & 0x3F;
        if (a0 != 0) {
            func_80018450(a0, *(s32 *)(base + *(s16 *)((u8 *)a1 + 4) * 8));
        } else {
            func_800183E0(*(s32 *)(base + *(s16 *)((u8 *)a1 + 4) * 8));
        }
        return 0;
    }
}
