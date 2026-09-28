/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139F0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_80127524;
extern s16 func_80138DB8(s32 a0, u8 a1, s32 a2);
extern void func_80139B18(s32 a0);
s16 func_80138DB8(s32 a0, u8 a1, s32 a2);
void func_80139B18(s32 a0);

void func_80139F0C(s32 a0) {
    s32 s0 = a0;
    s32 a2;
    if (D_80127524 != s0 && (*(s32 *)(s0 + 8) & 0x2000) == 0) {
        *(s16 *)(s0 + 4) = 4;
        return;
    }
    if (*(s32 *)(s0 + 8) & 0x4000) {
        a2 = 0x70;
    } else {
        a2 = 0x60;
    }
    if (func_80138DB8(s0, 0, a2) != 0) {
        s32 v1;
        *(s16 *)(s0 + 4) = 2;
        v1 = *(s32 *)(s0 + 8);
        if ((v1 & 0x20000) == 0) {
            *(s32 *)(s0 + 8) = v1 & ~0x20;
        }
        func_8002D4C8(0x88D, 0);
    }
    func_80139B18(s0);
}
