/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F7D4 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8015F7D4(s32 a0) {

    extern void (*D_801806B4[])(void);
    D_801806B4[*(u16 *)((s32)a0 + 0x2)]();
}
