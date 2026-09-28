/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80143C74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);

void func_80143C74(s32 a0, s32 a1) {
    func_8012C658(0x205, a1, a0);
}
