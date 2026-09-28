/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E6E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016E778();

void func_8016E6E4(s32 a0) {
    s32 v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == -1) {
        *(u16 *)(a0 + 2) = *(u16 *)(a0 + 2) + 1;
    }
    func_8016E778();
}
