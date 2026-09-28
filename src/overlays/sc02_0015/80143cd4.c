/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80143CD4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);

void func_80143CD4(s32 a0) {
    func_8012C658(0x39, 0, a0);
    func_8012C658(0x39, 1, a0);
    func_8012C658(0x39, 2, a0);
}
