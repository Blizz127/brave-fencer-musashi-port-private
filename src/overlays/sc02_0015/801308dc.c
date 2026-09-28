/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801308DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);

void func_801308DC(s32 a0) {
    *(u8 *)(a0 + 0xC1) = 0xE;
    if ((*(s32 *)(a0 + 0xB4) & 0x8000) != 0) {
        *(s32 *)(a0 + 0x1C) = 0x10;
        *(s16 *)(a0 + 0xAA) = 0;
        *(s16 *)(a0 + 0x5C) = 0;
        *(s16 *)(a0 + 0x98) = 0;
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) = 0x400;
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1C) = 0x400;
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = 0x200;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x2C) |= 0x10;
        func_8002D4C8(0x68A, 0);
    }
    func_80131CA8(a0, 0x2A);
}
