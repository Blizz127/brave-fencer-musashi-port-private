/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80138DE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80138ED0(u8 *param_1, u32 param_2, u8 *param_3);

s32 func_80138DE0(u8 *arg0, u8 arg1, s32 arg2) {
    extern s32 D_80127548[];
    extern u8 D_800D3AB4[];
    u16 *p;
    if (D_80127548[0] == 0) {
        return 0;
    }
    p = (u16 *)(arg0 + 0x44);
    if ((*(u32 *)(arg0 + 8) & 0x400) == 0) {
        p = (u16 *)(arg0 + 0x10);
        if (*(s16 *)(arg0 + 4) == 8) {
            p = (u16 *)(arg0 + 0x44);
        }
    }
    if (arg1 >= 0xE0) {
        arg2 = func_80138ED0(arg0, 0x1F, D_800D3AB4);
        if (arg2 != 0) {
            return 0;
        }
        *p = *p + 2;
    } else if (arg1 >= 0x20) {
        arg2 = func_80138ED0(arg0, (u16)(arg1 - 0x20), D_800D3AB4);
        if (arg2 != 0) {
            return 0;
        }
        *p = *p + 1;
    }
    if (arg2 != 0) {
        return 0;
    }
    D_80127548[0] = D_80127548[0] - 1;
    return D_80127548[0];
}
