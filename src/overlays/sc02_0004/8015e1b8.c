/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015E1B8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8015E1B8(s32 a0) {

    extern void (*D_80180630[])(void);
    D_80180630[*(u16 *)((s32)a0 + 0x2)]();
}
