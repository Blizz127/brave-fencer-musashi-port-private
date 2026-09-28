/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174384 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80174384(void *a0) {

    extern void (*D_80181890[])(void);
    D_80181890[*(u8 *)((s32)a0 + 0x214)]();
}
