/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BFF4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8014BFF4(s32 a0, s32 a1) {
    if (*(u8 *)(a0 + 0x4E) == 0) {
        *(u8 *)(a0 + 0x4E) = a1;
    }
}
