/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015E8E8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8015E8E8(s32 *a0) {

    extern void (*D_80180664[])(void);
    D_80180664[*(u16 *)((s32)a0 + 0x2)]();
}
