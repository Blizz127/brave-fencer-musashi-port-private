/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801596D4 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801596D4(void *a0) {
    *(s32 *)((s32)a0 + 0x28) = 0x10;
    *(u8 *)((s32)a0 + 0x15) = *(u8 *)((s32)a0 + 0x15) + 1;
    return 0;
}
