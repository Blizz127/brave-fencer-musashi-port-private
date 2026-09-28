/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801736FC - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801736FC(void *a0) {

    extern void (*D_801826F4[])(void);
    D_801826F4[*(u8 *)((s32)a0 + 0x214)]();
}
