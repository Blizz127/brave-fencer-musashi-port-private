/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015ED6C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149048(s32 *a0);
extern u8 D_80078EBF;

void func_8015ED6C(s32 *a0) {
    D_80078EBF = 0;
    *(s32 *)((s32)a0 + 0x44) &= -2;
    func_80149048(a0);
}
