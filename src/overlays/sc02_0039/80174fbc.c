/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174FBC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80175014(u8 *a0, u8 *a1, s32 a2);

void func_80174FBC(u8 *a0) {
    u16 *p = (u16 *)(a0 + 0x38);
    if ((*p & 0x7FFF) != 0) {
        func_80175014(a0, *(u8 **)(a0 + 0x34), *p & 0x7FFF);
        *p = *p - 1;
    } else {
        *p = *p | 0x8000;
    }
}
