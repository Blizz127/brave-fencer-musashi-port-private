/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150F80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern s32 func_80151184(s32 a0, s32 a1, s32 a2);
extern int func_80151184(int arg, int a1, int a2);

void func_80150F80(s32 a0) {
    if (D_80078EC1 != 0xC) {
        func_80151184(a0, 0xC007, 0x20);
    }
}
