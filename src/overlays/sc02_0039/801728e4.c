/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801728E4 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801728E4(void *a0) {

    extern void (*D_80182688[])(void);
    D_80182688[*(u8 *)((s32)a0 + 0x214)]();
}
