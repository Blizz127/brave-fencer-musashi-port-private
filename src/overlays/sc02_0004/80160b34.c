/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80160B34 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80160B34(s32 a0) {

    extern void (*D_80180774[])(void);
    D_80180774[*(u16 *)((s32)a0 + 0x2)]();
}
