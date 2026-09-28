/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F7B4 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_8012BEE8(s32 a0);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);

void func_8012F7B4(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 4) {
        func_8012BEE8(a0);
        if (*(s32 *)(a0 + 0x1C) == 1) {
            if (func_80131A34(a0, 8) == 0) {
                func_80131A34(a0, 0x20);
            }
        }
    }
    func_80131CA8(a0, 7);
}
