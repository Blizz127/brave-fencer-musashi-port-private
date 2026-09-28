/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801681FC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
s32 func_80166F58(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern s32 func_80166F58(s32, s32, s32, s32);

void func_801681FC(s32 param_1) {

    extern u8 D_801811D8[];
    extern u8 D_801811A8[];
    extern u8 D_801811A9[];
    s32 iVar3;
    s32 a3;

    *(s16 *)(param_1 + 0x28) = func_80029178(0x81) & 0xFF;
    *(s32 *)(param_1 + 0x30) = D_801811D8[*(s32 *)(param_1 + 0x2C)];
    iVar3 = (*(s32 *)(param_1 + 0x2C) << 0x11) >> 0x10;
    *(s16 *)(param_1 + 0x2A) = D_801811A8[iVar3];
    *(s32 *)(param_1 + 0x1C) = D_801811A9[iVar3];
    a3 = *(s32 *)(param_1 + 0x2C) & 1;
    *(s32 *)(param_1 + 0x2C) = a3;
    ((void (*)(s32, s32, s32, s32))func_80166F58)(param_1, 4, 4, a3);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
