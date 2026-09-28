/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80130314 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131340(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);

void func_80130314(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x800) {
        func_80131340(a0);
    }
    func_80131CA8(a0, 0x2D);
}
