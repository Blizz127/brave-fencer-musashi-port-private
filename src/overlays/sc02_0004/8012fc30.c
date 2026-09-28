/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012FC30 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
void func_8012B23C(s32 a0);
extern void func_80131B14();
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);

void func_8012FC30(s32 a0) {
    *(s8 *)(a0 + 0xC1) = 0xA;
    if (*(s32 *)(a0 + 0xB4) & 0x400) {
        func_80131B14();
        *(s8 *)(a0 + 0xC2) = 0;
        *(u16 *)(a0 + 0x98) = 0;
        func_8012B23C(a0);
        func_80131A34(a0, 8);
        func_8002D4C8(0xA74, 0);
    }
    func_80131CA8(a0, 0x1A);
}
