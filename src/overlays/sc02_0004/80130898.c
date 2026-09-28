/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80130898 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);

void func_80130898(u8 *a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x4000) {
        *(s16 *)(a0 + 0xAA) = 0x100;
        *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) & 0xFFFE;
    }
    func_80131CA8((int)a0, 0x28);
}
