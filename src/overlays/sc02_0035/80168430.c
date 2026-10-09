/* SC02.CD member35 [80168430,801684B4): twin of main_0012 80168430 (src/overlays/main_0012/80168430.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80168430,801684B4) from MAIN.CD member 0012.
 * SHA256(span)=ea83104c2618feca29c99ae3fc2c45dcc8021f77f83c76ba108c422146db715f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80168430 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80166F58(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern void func_80166F58(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_80168430(s32 param_1) {

    extern u8 D_80187470[];
    extern u8 D_80187448[];
    extern u8 D_80187449[];
    s32 iVar1;

    *(s32 *)(param_1 + 0x30) = D_80187470[*(s32 *)(param_1 + 0x2C)];
    iVar1 = (*(s32 *)(param_1 + 0x2C) << 0x11) >> 0x10;
    *(s16 *)(param_1 + 0x2A) = D_80187448[iVar1];
    *(s32 *)(param_1 + 0x1C) = D_80187449[iVar1];
    func_80166F58(param_1, 5, 0x3B, 2);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
