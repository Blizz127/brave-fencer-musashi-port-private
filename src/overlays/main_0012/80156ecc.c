/* Overlay range [80156ECC,80156FA8) from MAIN.CD member 0012.
 * SHA256(span)=fdb4f31bc82bb5fe8e69e832e4b83286d396d71decdfaa2a5bcd80954216f881.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80156ECC - 55 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


void func_80156ECC(int param_1, int param_2, int param_3, int param_4, int param_5) {
    extern void func_80156FA8(s16 *param_1, s16 *param_2, s16 *param_3);
    extern void func_80147478(s32 a0);
    extern void func_80149350(s32 arg0);
    unsigned short uVar1;
    func_80156FA8(param_3, param_4, param_5);
    ((s32 (*)(s32))func_80147478)(param_1);
    ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_2, param_2);
    uVar1 = *(unsigned short *)(param_3 + 6);
    if (*(short *)(param_3 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_3, param_3);
        *(unsigned short *)(param_3 + 6) = uVar1;
    }
    uVar1 = *(unsigned short *)(param_4 + 6);
    if (*(short *)(param_4 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_4, param_4);
        *(unsigned short *)(param_4 + 6) = uVar1;
    }
    uVar1 = *(unsigned short *)(param_5 + 6);
    if (*(short *)(param_5 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_5, param_5);
        *(unsigned short *)(param_5 + 6) = uVar1;
    }
}
