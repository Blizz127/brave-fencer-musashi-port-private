/* Main-exec range [80041448,800414E4) from the SLUS executable.
 * SHA256(span)=9922420ca2929de3529aa1dbf318748aea600297c77e305987079796876414f8.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"

/* func_80041448 - 39 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_800C73D8[];
extern s16 D_800B9B36;
extern u8 D_800AE614;
extern s16 D_80079590[];
extern u8 D_80079592[];
extern s16 D_80079596[][26];
extern s16 D_80079598[];
extern s16 D_8007959A[];
extern s16 D_8007959C[];
extern s16 D_8007959E[];
extern u8 *D_800A6578;
extern u8 *D_800A6580;
extern s32 D_800A6584;
extern s16 D_800A6434;
extern s16 D_800B9B58[];
extern u8 D_800A4620[];
extern u8   D_800AE614;
extern s16  D_80079596[][26];
extern u16  D_800B9B3A;
extern void func_80040868(s32);

void func_80041448(s16 param_1)
{
    u8 i;

    for (i = 0; i < D_800AE614; i++) {
        if (D_80079596[i][0] == param_1) {
            D_800B9B3A = i;
            func_80040868(0);
        }
    }
}
