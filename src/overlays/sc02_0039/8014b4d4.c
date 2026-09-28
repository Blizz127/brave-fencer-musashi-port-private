/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B4D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80078E98;
extern void func_80166244();

void func_8014B4D4(void *a0) {
    *(u16 *)((s32)a0 + 0x1C8) = 0;
    D_80078E98 = 0x80000000;
    func_80166244();
}
