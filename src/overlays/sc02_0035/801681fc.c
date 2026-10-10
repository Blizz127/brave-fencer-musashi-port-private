/* SC02.CD member35 [801681FC,8016829C): twin of main_0012 801681FC (src/overlays/main_0012/801681fc.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [801681FC,8016829C) from MAIN.CD member 0012.
 * SHA256(span)=59b5e8b8915e485b57e426322f2c04a78ce6ac63727f3f8fe9d0b2516672a3f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801681FC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
void func_80166F58(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern void func_80166F58(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_801681FC(s32 param_1) {

    extern u8 D_80187464[];
    extern u8 D_80187434[];
    extern u8 D_80187435[];
    s32 iVar3;
    s32 a3;

    *(s16 *)(param_1 + 0x28) = func_80029178(0x81) & 0xFF;
    *(s32 *)(param_1 + 0x30) = D_80187464[*(s32 *)(param_1 + 0x2C)];
    iVar3 = (*(s32 *)(param_1 + 0x2C) << 0x11) >> 0x10;
    *(s16 *)(param_1 + 0x2A) = D_80187434[iVar3];
    *(s32 *)(param_1 + 0x1C) = D_80187435[iVar3];
    a3 = *(s32 *)(param_1 + 0x2C) & 1;
    *(s32 *)(param_1 + 0x2C) = a3;
    func_80166F58(param_1, 4, 4, a3);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
