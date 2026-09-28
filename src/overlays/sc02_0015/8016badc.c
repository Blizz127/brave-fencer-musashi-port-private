/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BADC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_8016BADC(void *a0, s32 a1, s32 a2) {
    func_80146A6C(0x22, a0, 0, (s16)a1, 0, 0, a2);
    func_80146A6C(0x22, a0, 0, (s16)a1, 0, 1, a2);
    func_80146A6C(0x22, a0, 0, (s16)a1, 0, 2, a2);
    func_80146A6C(0x24, a0, 0, (s16)a1, 0, 0, 0);
}
