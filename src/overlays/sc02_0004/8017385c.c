/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017385C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B30;

void func_8017385C(u8 *a0) {
    switch (D_80126B30) {
    case 0:
    default:
        *(u16 *)(a0 + 0xAC) |= 0x80;
        *(u16 *)(a0 + 0xAA) |= 0x80;
        break;
    case 1:
        *(u16 *)(a0 + 0xAC) |= 0x10;
        *(u16 *)(a0 + 0xAA) |= 0x10;
        break;
    }
    func_80171A1C(a0);
    func_80174650((s32)a0);
}
