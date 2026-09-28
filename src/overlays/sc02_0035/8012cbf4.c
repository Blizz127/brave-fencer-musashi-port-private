/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012CBF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012CC88();
extern u8 D_800D3918[];

void func_8012CBF4(s32 a0) {
    func_8012CC88(a0, 0x11, (s32)D_800D3918);
}
