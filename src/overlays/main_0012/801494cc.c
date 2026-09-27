/* Overlay range [801494CC,80149544) from MAIN.CD member 0012.
 * SHA256(span)=ebe943cd289f70892de886918c5a0be347976fc7104f9817b81a42630f66867b.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801494CC - 30 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_8012F038(int param_1, short *param_2, short *param_3);

void func_801494CC(s32 a0, u16 *a1, u16 *a2) {
    u16 dst[3];
    u16 src[3];
    src[0] = a1[1];
    src[1] = a1[3];
    src[2] = a1[5];
    ((void (*)(s32, u16 *, u16 *))func_8012F038)(*(s32 *)(a0 + 0x20) + 0x34, src, dst);
    a2[1] = dst[0];
    a2[3] = dst[1];
    a2[5] = dst[2];
}
