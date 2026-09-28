/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DFF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_80190618;

void func_8017DFF8(void) {
    if (D_80190618 == 0) {
        func_8002D4C8(0x1F, 0);
        D_80190618 = 1;
    }
}
