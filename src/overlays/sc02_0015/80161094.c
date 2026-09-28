/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161094 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80139914(s32 a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);
extern void func_80129248(s16 a0);
extern u16 D_801270C0;
extern u8 D_800B9A17;

void func_80161094(s32 a0) {
    if (func_801399F0(*(s32 *)(a0 + 0x198)) != 0) {
        func_80139914(*(s32 *)(a0 + 0x198));
        *(s32 *)(a0 + 0x198) = 0;
    }
    D_801270C0 = 1;
    func_80129248(1);
    D_800B9A17 = 1;
}
