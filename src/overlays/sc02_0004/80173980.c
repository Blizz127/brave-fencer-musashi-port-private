/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173980 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B30;

void func_80173980(u8 *a0) {
    if (D_80126B30 == 0) {
        *(u16 *)(a0 + 0xAC) |= 0x80;
        *(u16 *)(a0 + 0xAA) |= 0x80;
    } else {
        *(u16 *)(a0 + 0xAC) |= 0x10;
    }
    func_80171A1C(a0);
}
