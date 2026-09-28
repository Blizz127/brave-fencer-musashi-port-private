/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F91C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131340(s32 a0);

void func_8012F91C(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x80) {
        func_80131340(a0);
    }
    func_80131CA8(a0, 0x17);
}
