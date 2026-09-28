/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80138D58 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8013A9F8(s32 a0, s32 a1);

void func_80138D58(s32 a0, u16 a1) {
    if (*(s32 *)(a0 + 0x40) == 0) {
        return;
    }
    if ((u32)(*(u16 *)(a0 + 0x18) - 2) >= 5) {
        return;
    }
    if ((u32)(u16)(a1 - 2) >= 5) {
        return;
    }
    *(s16 *)(a0 + 0x18) = a1;
    func_8013A9F8(*(s32 *)(a0 + 0x40), a1);
}
