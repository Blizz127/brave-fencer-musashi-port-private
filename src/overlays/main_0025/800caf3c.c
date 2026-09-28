/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF3C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAF3C(void *a0) {
    extern s32 func_80146E98(s32 a0);
    if (func_80146E98((s32)a0) != 0) {
        *(u8 *)((s32)a0 + 0x197) += 1;
    }
}
