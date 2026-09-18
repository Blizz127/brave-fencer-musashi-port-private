/* Overlay range [8012F568,8012F5F4) from MAIN.CD member 0012.
 * SHA256(span)=d6fe3270eca1c5737b148e6710b23dac07a1e0288fbd7954a37dcdd7f566ba84.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012F568 - 35 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void *memcpy(void *, const void *, u32);
extern u8 D_80126C38;
extern u8 D_80126C40;
extern u16 D_80126B94;
extern u16 D_80126B96;
extern s16 D_80126B98;
extern s16 D_80126B9A;

void func_8012F568(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    memcpy(&D_80126C38, param_5, 8);
    memcpy(&D_80126C40, param_6, 8);
    __asm__ __volatile__("" ::: "memory");
    D_80126B96 = param_2;
    D_80126B9A = param_3;
    D_80126B98 = param_4;
    D_80126B94 = D_80126B94 | param_1;
}
