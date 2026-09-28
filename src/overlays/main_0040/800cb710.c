/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB710 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146E90(s32 *a0, s32 a1);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_800CB840(s32 param_1);
extern void func_800CB8A8(void*, s16);
extern s32 func_80146E98(s32 param_1);
extern void func_80146E90(s32 *param_1, s32 param_2);

void func_800CB710(s32 param_1) {
    s32 node;

    node = *(s32 *)(param_1 + 0x20);
    func_80128ED8(node, (s32 *)(param_1 + 0x24));
    *(u8 *)(node + 0x27) = *(u8 *)(param_1 + 0x28) - 0x70;
    func_800CB840(param_1);
    ((void (*)(s32, s32))func_800CB8A8)(param_1, 0x30);
    if (func_80146E98(param_1) != 0) {
        *(s32 *)(param_1 + 0x10) = *(s32 *)(param_1 + 0x10) >> 2;
        *(s32 *)(param_1 + 0x14) = *(s32 *)(param_1 + 0x14) >> 2;
        *(s32 *)(param_1 + 0x18) = *(s32 *)(param_1 + 0x18) >> 2;
        func_80146E90((s32 *)param_1, 8);
        *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
    }
}
