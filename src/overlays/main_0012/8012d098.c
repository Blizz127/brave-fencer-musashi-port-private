/* Overlay range [8012D098,8012D38C) from MAIN.CD member 0012.
 * SHA256(span)=44ff3a5d0b53f8c2cc8cff4bab8afb3031e51c4c0902d08e4468f10a7824e799.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012D098 - 189 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012D3B4(s32 arg0, s32 arg1, s32 arg2);

void func_8012D098(u16 *param_1, u32 param_2)
{
    s32 bufA[2];
    s32 bufB[2];
    s32 bufC[2];
    s32 bufD[2];
    s32 bufE[2];
    s32 bufF[2];
    s32 bufG[2];
    s32 bufH[2];
    u16 scratch[3];
    if (param_1 != 0 && *param_1 != 0) {
        if (param_2 == 0) {
            if (*(u32 *)(param_1 + 0x2c) == 0) {
                return;
            }
            param_2 = (*(u32 *)(param_1 + 0x2c) & 0xfffffff) | 0x80000000;
        }
        scratch[0] = *(u16 *)(param_2 + 4);
        scratch[1] = *(u16 *)(param_2 + 8);
        scratch[2] = *(u16 *)(param_2 + 0xc);
        func_8012F214(param_1, scratch, bufA);
        scratch[0] = *(u16 *)(param_2 + 6);
        scratch[1] = *(u16 *)(param_2 + 8);
        scratch[2] = *(u16 *)(param_2 + 0xc);
        func_8012F214(param_1, scratch, bufB);
        scratch[0] = *(u16 *)(param_2 + 4);
        scratch[1] = *(u16 *)(param_2 + 0xa);
        scratch[2] = *(u16 *)(param_2 + 0xc);
        func_8012F214(param_1, scratch, bufC);
        scratch[0] = *(u16 *)(param_2 + 6);
        scratch[1] = *(u16 *)(param_2 + 0xa);
        scratch[2] = *(u16 *)(param_2 + 0xc);
        func_8012F214(param_1, scratch, bufD);
        scratch[0] = *(u16 *)(param_2 + 4);
        scratch[1] = *(u16 *)(param_2 + 8);
        scratch[2] = *(u16 *)(param_2 + 0xe);
        func_8012F214(param_1, scratch, bufE);
        scratch[0] = *(u16 *)(param_2 + 6);
        scratch[1] = *(u16 *)(param_2 + 8);
        scratch[2] = *(u16 *)(param_2 + 0xe);
        func_8012F214(param_1, scratch, bufF);
        scratch[0] = *(u16 *)(param_2 + 4);
        scratch[1] = *(u16 *)(param_2 + 0xa);
        scratch[2] = *(u16 *)(param_2 + 0xe);
        func_8012F214(param_1, scratch, bufG);
        scratch[0] = *(u16 *)(param_2 + 6);
        scratch[1] = *(u16 *)(param_2 + 0xa);
        scratch[2] = *(u16 *)(param_2 + 0xe);
        func_8012F214(param_1, scratch, bufH);
        func_8012D3B4(bufA, bufB, 0xffffff);
        func_8012D3B4(bufB, bufD, 0xffffff);
        func_8012D3B4(bufD, bufC, 0xffffff);
        func_8012D3B4(bufC, bufA, 0xffffff);
        func_8012D3B4(bufE, bufF, 0xffffff);
        func_8012D3B4(bufF, bufH, 0xffffff);
        func_8012D3B4(bufH, bufG, 0xffffff);
        func_8012D3B4(bufG, bufE, 0xffffff);
        func_8012D3B4(bufA, bufE, 0xffffff);
        func_8012D3B4(bufB, bufF, 0xffffff);
        func_8012D3B4(bufC, bufG, 0xffffff);
        func_8012D3B4(bufD, bufH, 0xffffff);
    }
    return;
}
