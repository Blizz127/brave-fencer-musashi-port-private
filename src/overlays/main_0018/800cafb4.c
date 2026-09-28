/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFB4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAFB4(void *arg) {
    extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
    func_80146994(0x23, (s32)arg, 0x8000, 0);
}
