/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801303A0 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_8012E364(s32 arg0_);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_8012E364();

void func_801303A0(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x2) {
        ((void (*)(s32))func_8012E364)(a0);
    }
    func_80131CA8(a0, 2);
}
