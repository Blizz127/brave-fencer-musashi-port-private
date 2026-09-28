/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80168430 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_80166F58(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern s32 func_80166F58(s32, s32, s32, s32);

void func_80168430(s32 param_1) {

    extern u8 D_801811E4[];
    extern u8 D_801811BC[];
    extern u8 D_801811BD[];
    s32 iVar1;

    *(s32 *)(param_1 + 0x30) = D_801811E4[*(s32 *)(param_1 + 0x2C)];
    iVar1 = (*(s32 *)(param_1 + 0x2C) << 0x11) >> 0x10;
    *(s16 *)(param_1 + 0x2A) = D_801811BC[iVar1];
    *(s32 *)(param_1 + 0x1C) = D_801811BD[iVar1];
    ((void (*)(s32, s32, s32, s32))func_80166F58)(param_1, 5, 0x3B, 2);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
