/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80029124(s32, s32);
extern u8 D_80078EC0;
extern void func_80029124(s32 a0, s32 a1);

void func_8014BEC0(void) {
    D_80078EC0 |= 1;
    func_80029124(0x80, 1);
}
