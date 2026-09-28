/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016AE5C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800D22E4(s32 a0);
extern void func_8016B234();

void func_8016AE5C(s32 param_1) {
    s32 sp;

    sp = *(s32 *)(param_1 + 0x20);
    if (*(u32 *)(param_1 + 0x2C) < 6) {
        func_8016B234();
    }
    switch (*(u32 *)(param_1 + 0x2C)) {
    case 0:
        *(s16 *)(param_1 + 0xA) -= *(s32 *)(param_1 + 0x1C);
        *(s32 *)(param_1 + 0x1C) = *(s32 *)(param_1 + 0x1C) - 1;
        if (*(s32 *)(param_1 + 0x1C) != 0) {
            if ((*(s32 *)(param_1 + 0x1C) & 3) == 1) {
                *(s16 *)(param_1 + 0x26) += 1;
            }
            return;
        }
        *(s16 *)(param_1 + 0x24) = 0xFF;
        *(s32 *)(param_1 + 0x1C) = 8;
        *(s16 *)(param_1 + 2) += 1;
        return;
    case 1:
    case 5:
        func_800D22E4(param_1);
        *(s32 *)(param_1 + 0x14) += 0x18000;
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
        *(s16 *)(param_1 + 0xA) -= *(s32 *)(param_1 + 0x1C);
        *(s32 *)(param_1 + 0x1C) = *(s32 *)(param_1 + 0x1C) - 1;
        if (*(s32 *)(param_1 + 0x1C) == 0) {
            if (*(u32 *)(param_1 + 0x2C) < 6) {
                *(s16 *)(param_1 + 0x24) = 0xC0;
                *(s32 *)(param_1 + 0x1C) = 8;
            } else {
                *(u8 *)(sp + 0x26) = 0xC0;
                *(u8 *)(sp + 0x25) = 0xC0;
                *(u8 *)(sp + 0x24) = 0xC0;
                *(s32 *)(param_1 + 0x1C) = 0xC;
            }
            *(s16 *)(param_1 + 2) += 1;
        }
        break;
    }
}
