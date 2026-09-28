/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012FF4C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);

void func_8012FF4C(s32 a0) {
    *(s8 *)(a0 + 0xC1) = 5;
    if (*(s32 *)(a0 + 0xB4) & 0x20) {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(s16 *)(a0 + 0x5C) = 0;
        *(s32 *)(a0 + 0x1C) = 0x1E;
        *(s16 *)(a0 + 0x98) = 0;
        *(s16 *)(v1 + 0x10) = 0;
    }
    func_80131CA8(a0, 0xF);
}
