/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF64 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);

void func_800CAF64(s32 a0) {
    func_80146994(0x38, a0, 0x8000, 0);
}
