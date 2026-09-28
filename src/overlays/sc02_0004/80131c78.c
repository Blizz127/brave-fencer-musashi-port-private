/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80131C78 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);

void func_80131C78(s32 a0) {
    s32 v0 = *(s32*)(a0 + 0x20);
    *(s8*)(a0 + 0xC1) = 0;
    *(s16*)(v0 + 0x10) = 0;
    *(s16*)(a0 + 0x5E) = 0;
    func_80131CA8(a0, 0xE);
}
