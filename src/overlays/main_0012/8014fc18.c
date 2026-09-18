/* Overlay range [8014FC18,8014FCFC) from MAIN.CD member 0012.
 * SHA256(span)=579ef747b61bb1ebb0cc3a76466bf8615e605a469d8a20fa0f87b24d1cc5b0a8.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014FC18 - 57 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

s32 func_8014FC18(u8 *self)
{
    s16 src[4];
    s16 dst[4];
    s32 ret;
    src[0] = *(u16 *)(self + 0x6);
    src[1] = *(u16 *)(self + 0xA);
    src[2] = *(u16 *)(self + 0xE);
    dst[0] = *(u16 *)(self + 0x6);
    dst[1] = *(u16 *)(self + 0xA) + 0x10;
    dst[2] = *(u16 *)(self + 0xE);
    ret = func_80133784(1, src, (s32)dst);
    if (ret != 0) {
        *(u16 *)(self + 0x6) = dst[0];
        *(u16 *)(self + 0xA) = dst[1];
        *(u16 *)(self + 0xE) = dst[2];
        if (*(u8 *)&dst[3] != 0) {
            *(s16 *)(self + 0x16C) = *(u8 *)&dst[3];
        }
        *(s16 *)(self + 0x16E) = (u16)dst[3] >> 13;
        return ret;
    }
    if (*(u8 *)&dst[3] != 0) {
        *(s16 *)(self + 0x16C) = *(u8 *)&dst[3];
    }
    return 0;
}
