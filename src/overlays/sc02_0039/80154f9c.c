/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80154F9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8016F1AC(void);
extern u8 D_80078E78[];
extern s16 D_80078E96;
extern u16 D_80078EA6;
extern u8 D_800D8D10[];
extern s16 D_80078E9E;
extern void func_801550FC(s32 a0);

void func_80154F9C(s32 a0) {
    u8 *base = D_80078E78;
    if (*(s32 *)(a0 + 0xC8) & 0x1000000) {
        if ((D_80078E96 & 0x8000) || D_80078E9E < 0x10 || (s16)D_80078EA6 < 0x10) {
            if (func_8016F1AC() == 0) {
                return;
            }
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) & 0xC0FFFFFF;
        func_801550FC(*(s32 *)(a0 + 0xC8));
    } else {
        if ((D_80078E96 & 0x8000) && func_8016F1AC() == 0) {
            *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
            func_801550FC((s32)D_800D8D10);
            return;
        }
        if (!(*(s16 *)(base + 0x26) < 0x10) && !(*(s16 *)(base + 0x2E) < 0x10)) {
            return;
        }
        if (*(s32 *)(a0 + 0x44) & 0xC0) {
            return;
        }
        if (func_8016F1AC() != 0) {
            return;
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
        func_801550FC(0x40000002);
    }
}
